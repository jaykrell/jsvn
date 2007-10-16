#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <windows.h>
#include <stddef.h>

#define BASE 0x400000

#define RELOCATABLE 1

#define OPTIMIZE_NOT_BINDABLE 1 /* 1 or 0, works either way */

#define FILE_ALIGN 0x1 /* popular values are 0x1000 and 0x200 */
//#define FILE_ALIGN 0x200 /* popular values are 0x1000 and 0x200 */
//#define FILE_ALIGN 0x1000 /* popular values are 0x1000 and 0x200 */

// section align cannot be less than file align and will be increased to match */
#define SECTION_ALIGN 0x1 /* can be any power of two but usually page size */
//#define SECTION_ALIGN 0x1000 /* can be any power of two but usually page size */

// if section_align < pagesize, then section_align must equal file_align
// That is not enforced here currently.

// causes link /dump to fail but ok
#define OMIT_TRAILING_NULL_IMPORT_DESCRIPTOR

#define LINK_DUMP_COMATIBLE

#ifdef LINK_DUMP_COMATIBLE
#undef OMIT_TRAILING_NULL_IMPORT_DESCRIPTOR
#endif

void __stdcall RemoveTrailingCharacters(PWSTR s, PCWSTR CharsToRemove)
{
    PWSTR t;
    for (t = (s + wcslen(s)) ; ((t != s) && wcschr(CharsToRemove, t[-1])) ; --t)
    {
        t[-1] = 0;
    }
}

void RemoveTrailingWhitespace(PWSTR s) { RemoveTrailingCharacters(s, L" \t\r\n"); }

PWSTR GetErrorString(int Error)
{
    PWSTR Buffer = { 0 };

    FormatMessageW(
        (FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER),
        NULL, Error, 0, (PWSTR) &Buffer, 0, NULL);
    RemoveTrailingWhitespace(Buffer);

    return Buffer;
}

size_t RoundUp(size_t a, size_t b)
{
    a += (b - 1);
    return (a - (a % b));
}

int
__cdecl
wmain()
{
    union
    {
        struct
        {
            IMAGE_DOS_HEADER Dos;
            IMAGE_NT_HEADERS Nt;
            IMAGE_SECTION_HEADER Section;
        } Header;
        BYTE PadAlign[FILE_ALIGN];
    } uHeader;
    struct
    {
        union
        {
            BYTE PushHello;
            BYTE FirstInstruction;
        } uFirstInstruction;
        BYTE Hello[4];
        BYTE Call_wprintf[2];
        BYTE wprintf[4];
        BYTE AddEsp4[3];
        BYTE PushExitCode;
        BYTE ExitCode;
        BYTE CallGetCurrentProcess[2];
        BYTE GetCurrentProcess[4];
        BYTE PushEax;
        BYTE CallTerminateProcess[2];
        BYTE TerminateProcess[4];
#if 0 // not reached
        BYTE RetC[3];
#endif
        struct
        {
            BYTE wprintf[sizeof("wprintf")];
            BYTE TerminateProcess[sizeof("TerminateProcess")];
            BYTE GetCurrentProcess[sizeof("GetCurrentProcess")];
            BYTE Msvcrt[sizeof("Msvcrt.dll")];
            BYTE Kernel32[sizeof("Kernel32.dll")];
            WCHAR Hello[sizeof("Hello\n")];
        } String;
#ifdef RELOCATABLE
        struct
        {
            IMAGE_BASE_RELOCATION Header;
            USHORT Hello;
            USHORT wprintf;
            USHORT GetCurrentProcess;
            USHORT TerminateProcess;
        } Relocs;
#endif
        struct
        {
            struct
            {
                struct
                {
                    ULONG wprintf;
                    ULONG Null;
                } Msvcrt;
                struct
                {
                    ULONG TerminateProcess;
                    ULONG GetCurrentProcess;
                    ULONG Null;
                } Kernel32;
            }
#ifdef OPTIMIZE_NOT_BINDABLE
            Address;
#else
            Name, Address;
#endif
            struct
            {
                IMAGE_IMPORT_DESCRIPTOR Msvcrt;
                IMAGE_IMPORT_DESCRIPTOR Kernel32;
                IMAGE_IMPORT_DESCRIPTOR Null; // this is at the very end of the image so we can optimize it off disk,
                                              // it seems perhaps optional anyway
            } Descriptor;
        } Imports;
    } Data;
/* This is for the first section specifically. */
#define RVA(x) ((ULONG) (((size_t) &x) - (size_t) &Data) + Section->VirtualAddress)
#define VA(x) ((va = (RVA(x) + OptionalHeader->ImageBase)), &va)
    ULONG va;
    FILE* FileHandle = { 0 };
    HMODULE DllHandle = { 0 };
    DWORD Error = { 0 };
    PWSTR ErrorString = { 0 };
    int Result = 1;
    IMAGE_DOS_HEADER* Dos = &uHeader.Header.Dos;
    IMAGE_NT_HEADERS* Nt = &uHeader.Header.Nt;
    IMAGE_OPTIONAL_HEADER* OptionalHeader = &uHeader.Header.Nt.OptionalHeader;
    IMAGE_FILE_HEADER* FileHeader = &uHeader.Header.Nt.FileHeader;
    IMAGE_SECTION_HEADER* Section = { 0 };
    IMAGE_SECTION_HEADER* LastSection = { 0 };
    size_t i = { 0 };

    SetErrorMode(SEM_FAILCRITICALERRORS);

    ZeroMemory(&uHeader, sizeof(uHeader));
    ZeroMemory(&Data, sizeof(Data));

    OptionalHeader->SectionAlignment = ((SECTION_ALIGN < FILE_ALIGN) ? FILE_ALIGN : SECTION_ALIGN);
    OptionalHeader->FileAlignment = FILE_ALIGN;
    OptionalHeader->ImageBase = BASE;

#ifndef RELOCATABLE
    OptionalHeader->NumberOfRvaAndSizes = (IMAGE_DIRECTORY_ENTRY_IMPORT + 1);
#else
    OptionalHeader->NumberOfRvaAndSizes = (IMAGE_DIRECTORY_ENTRY_BASERELOC + 1);
#endif
#ifdef LINK_DUMP_COMATIBLE
    OptionalHeader->NumberOfRvaAndSizes = (IMAGE_NUMBEROF_DIRECTORY_ENTRIES - 3);
#endif

    Section = (IMAGE_SECTION_HEADER*) &OptionalHeader->DataDirectory[OptionalHeader->NumberOfRvaAndSizes];
    OptionalHeader->SizeOfHeaders = (ULONG) (((size_t) (Section + 1)) - (size_t) &uHeader);

    Section->Misc.VirtualSize = sizeof(Data);
    Section->SizeOfRawData = sizeof(Data);
    Section->Characteristics = (IMAGE_SCN_CNT_CODE | IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_MEM_READ | IMAGE_SCN_CNT_INITIALIZED_DATA | IMAGE_SCN_CNT_UNINITIALIZED_DATA);
    Section->VirtualAddress = RoundUp(OptionalHeader->SizeOfHeaders, OptionalHeader->SectionAlignment);
    Section->PointerToRawData = RoundUp(OptionalHeader->SizeOfHeaders, OptionalHeader->FileAlignment);

    Dos->e_magic = IMAGE_DOS_SIGNATURE;
    Dos->e_lfanew = sizeof(*Dos);
    FileHeader->Machine = IMAGE_FILE_MACHINE_I386;
    FileHeader->NumberOfSections = 1;

    LastSection = (Section + FileHeader->NumberOfSections - 1);

    FileHeader->SizeOfOptionalHeader = (ULONG) (((size_t) Section) - (size_t) OptionalHeader);

    FileHeader->Characteristics = (IMAGE_FILE_EXECUTABLE_IMAGE | IMAGE_FILE_32BIT_MACHINE | IMAGE_FILE_DLL);
#ifndef RELOCATABLE
    FileHeader->Characteristics |= IMAGE_FILE_RELOCS_STRIPPED;
#endif
    Nt->Signature = IMAGE_NT_SIGNATURE;

    OptionalHeader->Magic = IMAGE_NT_OPTIONAL_HDR_MAGIC;
    OptionalHeader->AddressOfEntryPoint = RVA(Data);
    OptionalHeader->MajorOperatingSystemVersion = 4;
    OptionalHeader->MajorSubsystemVersion = 4;
    OptionalHeader->Subsystem = IMAGE_SUBSYSTEM_WINDOWS_CUI;
    // not needed
    //OptionalHeader->BaseOfCode = OptionalHeader->SectionAlignment;
    //OptionalHeader->BaseOfData = OptionalHeader->BaseOfCode;
    //OptionalHeader->SizeOfCode = sizeof(Data);
    //OptionalHeader->SizeOfInitializedData = sizeof(Data);
    OptionalHeader->SizeOfImage = RoundUp(LastSection->VirtualAddress + LastSection->Misc.VirtualSize, OptionalHeader->SectionAlignment);

    OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress = RVA(Data.Imports.Descriptor);
    // size is redundant with the terminal null
    OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size = sizeof(Data.Imports.Descriptor);
    //OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size = 1;

#ifdef RELOCATABLE
    OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress = RVA(Data.Relocs);
    OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].Size = sizeof(Data.Relocs);
#endif

    Data.uFirstInstruction.PushHello = 0x68;
    memcpy(Data.Hello, VA(Data.String.Hello), sizeof(ULONG));
    Data.Call_wprintf[0] = 0xFF;
    Data.Call_wprintf[1] = 0x15;
    memcpy(Data.wprintf, VA(Data.Imports.Address.Msvcrt.wprintf), sizeof(ULONG));
    Data.AddEsp4[0] = 0x83;
    Data.AddEsp4[1] = 0xC4;
    Data.AddEsp4[2] = 0x04;

    Data.PushExitCode = 0x6A;
    Data.ExitCode = 42;
    Data.CallGetCurrentProcess[0] = 0xFF;
    Data.CallGetCurrentProcess[1] = 0x15;
    memcpy(Data.GetCurrentProcess, VA(Data.Imports.Address.Kernel32.GetCurrentProcess), sizeof(ULONG));
    Data.PushEax = 0x50;
    Data.CallTerminateProcess[0] = 0xFF;
    Data.CallTerminateProcess[1] = 0x15;
    memcpy(Data.TerminateProcess, VA(Data.Imports.Address.Kernel32.TerminateProcess), sizeof(ULONG));

#if 0 // not reached
    Data.RetC[0] = 0xc2;
    Data.RetC[1] = 0xc;
    Data.RetC[2] = 0;
#endif

    // import descriptors

    Data.Imports.Descriptor.Msvcrt.FirstThunk = RVA(Data.Imports.Address.Msvcrt);
    Data.Imports.Descriptor.Msvcrt.Name = RVA(Data.String.Msvcrt);

    Data.Imports.Descriptor.Kernel32.FirstThunk = RVA(Data.Imports.Address.Kernel32);
    Data.Imports.Descriptor.Kernel32.Name = RVA(Data.String.Kernel32);

    // addresses, subtract 2 to leave room for an arbitrary and not necessarily aligned hint

    Data.Imports.Address.Msvcrt.wprintf = (RVA(Data.String.wprintf) - 2);
    Data.Imports.Address.Kernel32.TerminateProcess = (RVA(Data.String.TerminateProcess) - 2);
    Data.Imports.Address.Kernel32.GetCurrentProcess = (RVA(Data.String.GetCurrentProcess) - 2);

    // names

#ifdef OPTIMIZE_NOT_BINDABLE
    Data.Imports.Descriptor.Msvcrt.OriginalFirstThunk = RVA(Data.Imports.Address.Msvcrt);
    Data.Imports.Descriptor.Kernel32.OriginalFirstThunk = RVA(Data.Imports.Address.Kernel32);
#else
    Data.Imports.Descriptor.Msvcrt.OriginalFirstThunk = RVA(Data.Imports.Name.Msvcrt);
    Data.Imports.Descriptor.Kernel32.OriginalFirstThunk = RVA(Data.Imports.Name.Kernel32);
    Data.Imports.Name = Data.Imports.Address;
#endif

    // strings

    memcpy(Data.String.wprintf, "wprintf", sizeof("wprintf"));
    memcpy(Data.String.TerminateProcess, "TerminateProcess", sizeof("TerminateProcess"));
    memcpy(Data.String.GetCurrentProcess, "GetCurrentProcess", sizeof("GetCurrentProcess"));
    memcpy(Data.String.Msvcrt, "Msvcrt.dll", sizeof("Msvcrt.dll"));
    memcpy(Data.String.Kernel32, "Kernel32.dll", sizeof("Kernel32.dll"));
    memcpy(Data.String.Hello, L"Hello\n", sizeof(L"Hello\n"));

    // relocs

#ifdef RELOCATABLE
    //
    // This depends on their being less than 4k of code.
    //
    Data.Relocs.Header.SizeOfBlock = sizeof(Data.Relocs);
    Data.Relocs.Header.VirtualAddress = RVA(Data.uFirstInstruction.FirstInstruction);
    Data.Relocs.Hello = ((IMAGE_REL_BASED_HIGHLOW << 12) | (Data.Hello - &Data.uFirstInstruction.FirstInstruction));
    Data.Relocs.wprintf = ((IMAGE_REL_BASED_HIGHLOW << 12) | (Data.wprintf - &Data.uFirstInstruction.FirstInstruction));
    Data.Relocs.GetCurrentProcess = ((IMAGE_REL_BASED_HIGHLOW << 12) | (Data.GetCurrentProcess - &Data.uFirstInstruction.FirstInstruction));
    Data.Relocs.TerminateProcess = ((IMAGE_REL_BASED_HIGHLOW << 12) | (Data.TerminateProcess - &Data.uFirstInstruction.FirstInstruction));

#endif

    // version resource?

    FileHandle = _wfopen(L"1.dll", L"wb");
    if (FileHandle == NULL)
    {
        Result = errno;
        wprintf(L"fopen error %d %ls\n", Result, _wcserror(Result));
        goto Exit;
    }
    fwrite(&uHeader, RoundUp(OptionalHeader->SizeOfHeaders, OptionalHeader->FileAlignment), 1, FileHandle);

    i = sizeof(Data);
#ifdef OMIT_TRAILING_NULL_IMPORT_DESCRIPTOR
    // link /dump doesn't like this but the loader is ok
    while ((i != 0) && (((PBYTE) &Data)[i - 1] == 0))
    {
        i -= 1;
        Section->SizeOfRawData -= 1;
    }
#endif
    fwrite(&Data, i, 1, FileHandle);
    fclose(FileHandle);

    DllHandle = LoadLibraryW(L"1.dll");
    if (DllHandle)
        SetLastError(0);
    Error = GetLastError();
    ErrorString = GetErrorString(Error);
    wprintf(L"LoadLibrary: %p 0x%lx %ls\n", DllHandle, Error, ErrorString);

    Result = Error;

Exit:
    LocalFree(ErrorString);
    if (DllHandle != NULL)
        FreeLibrary(DllHandle);
    return Result;
}
