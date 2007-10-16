#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <windows.h>
#include <stddef.h>

#define BASE 0x4000000

// This works often.
// Saves 52 bytes.
#define OVERLAY_PE_AND_DOS_HEADER 1

// Costs around 48 bytes
//#define RELOCATABLE 1

// saves 20 bytes
#define OPTIMIZE_NOT_BINDABLE 1 /* 1 or 0, works either way */

#define FILE_ALIGN 0x1 /* popular values are 0x1000 and 0x200 */
//#define FILE_ALIGN 0x100 /* popular values are 0x1000 and 0x200 */
//#define FILE_ALIGN 0x200 /* popular values are 0x1000 and 0x200 */
//#define FILE_ALIGN 0x1000 /* popular values are 0x1000 and 0x200 */

// section align cannot be less than file align and will be increased to match */
#define SECTION_ALIGN 0x1 /* can be any power of two but usually page size */
//#define SECTION_ALIGN 0x1000 /* can be any power of two but usually page size */

// if section_align < pagesize, then section_align must equal file_align
// That is not enforced here currently.

// causes link /dump to fail but ok
// saves 20 or 22 bytes but not compatible with all options
//#define OMIT_TRAILING_NULL_IMPORT_DESCRIPTOR

//#define LINK_DUMP_COMATIBLE

#ifdef LINK_DUMP_COMATIBLE
#undef OMIT_TRAILING_NULL_IMPORT_DESCRIPTOR
#endif

// much potential here, not yet implemented
#define REUSE_HEADERS 1

//#define OMIT_TRAILING_NULL_IMPORT_DESCRIPTOR

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
    struct
    {
        IMAGE_DOS_HEADER Dos;
        IMAGE_NT_HEADERS Nt;
        IMAGE_SECTION_HEADER Section;
    } Header;
    BYTE FileAlign[FILE_ALIGN];
    struct
    {
        union
        {
            BYTE PushHello;
            BYTE FirstInstruction;
        } uFirstInstruction;
        BYTE Hello[4];
        BYTE Call_puts[2];
        BYTE puts[4];
#if 0 // not necessary since we don't return
        BYTE AddEsp4[3];
#endif
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
#ifndef REUSE_HEADERS
            BYTE puts[sizeof("puts")];
#endif
            BYTE TerminateProcess[sizeof("TerminateProcess")];
            BYTE GetCurrentProcess[sizeof("GetCurrentProcess")];
            BYTE Msvcrt[sizeof("Msvcrt.dll")];
#ifndef REUSE_HEADERS
            BYTE Kernel32[sizeof("Kernel32.dll")];
            BYTE Hello[sizeof("Hello")];
#endif
        } String;
#ifdef RELOCATABLE
        struct
        {
            IMAGE_BASE_RELOCATION Header;
            USHORT Hello;
            USHORT puts;
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
                    ULONG puts;
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
#if 1 // save 20 bytes
                IMAGE_IMPORT_DESCRIPTOR Null; // this is at the very end of the image so we can optimize it off disk,
                                              // it seems perhaps optional anyway
#endif
            } Descriptor;
        } Imports;
    } Data;
/* This is for the first section specifically. */
#ifdef OVERLAY_PE_AND_DOS_HEADER
#define RVA(x) ((ULONG) (((size_t) &x) - (size_t) &Data) + Section->VirtualAddress - 0x34)
#else
#define RVA(x) ((ULONG) (((size_t) &x) - (size_t) &Data) + Section->VirtualAddress)
#endif
#define VA(x) ((va = (RVA(x) + OptionalHeader->ImageBase)), &va)
    ULONG va;
    ULONG rva;
    FILE* FileHandle = { 0 };
    HMODULE DllHandle = { 0 };
    DWORD Error = { 0 };
    PWSTR ErrorString = { 0 };
    int Result = 1;
    IMAGE_DOS_HEADER* Dos = &Header.Dos;
    IMAGE_NT_HEADERS* Nt = &Header.Nt;
    IMAGE_OPTIONAL_HEADER* OptionalHeader = &Header.Nt.OptionalHeader;
    IMAGE_FILE_HEADER* FileHeader = &Header.Nt.FileHeader;
    IMAGE_SECTION_HEADER* Section = { 0 };
    IMAGE_SECTION_HEADER* LastSection = { 0 };
    size_t i = { 0 };
    size_t j = { 0 };

    SetErrorMode(SEM_FAILCRITICALERRORS);

    ZeroMemory(&Header, sizeof(Header));
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
    //OptionalHeader->NumberOfRvaAndSizes = IMAGE_NUMBEROF_DIRECTORY_ENTRIES;
#endif

    Section = (IMAGE_SECTION_HEADER*) &OptionalHeader->DataDirectory[OptionalHeader->NumberOfRvaAndSizes];
    OptionalHeader->SizeOfHeaders = (ULONG) (((size_t) (Section + 1)) - (size_t) &Header);

#ifdef REUSE_HEADERS
    strcpy(Section->Name, "Hello");
#endif
    Section->Misc.VirtualSize = sizeof(Data);
    Section->SizeOfRawData = sizeof(Data);
    // not needed, nets us more space to reuse maybe (a terminal nul for a string)
    //Section->Characteristics = (IMAGE_SCN_CNT_CODE | IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_MEM_READ | IMAGE_SCN_CNT_INITIALIZED_DATA);
    // sometimes needed (not)
    //Section->Characteristics |= IMAGE_SCN_CNT_UNINITIALIZED_DATA;
    Section->VirtualAddress = RoundUp(OptionalHeader->SizeOfHeaders, OptionalHeader->SectionAlignment);
    Section->PointerToRawData = RoundUp(OptionalHeader->SizeOfHeaders, OptionalHeader->FileAlignment);

    Dos->e_magic = IMAGE_DOS_SIGNATURE;
    Dos->e_lfanew = sizeof(*Dos);
#ifdef OVERLAY_PE_AND_DOS_HEADER
    Dos->e_lfanew = 0xC;
#endif
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

#ifndef REUSE_HEADERS
    memcpy(Data.Hello, VA(Data.String.Hello), sizeof(ULONG));
#else
    // hello is the section name
    va = (OptionalHeader->ImageBase + (4 + sizeof(IMAGE_FILE_HEADER) + Header.Nt.FileHeader.SizeOfOptionalHeader));
#ifdef OVERLAY_PE_AND_DOS_HEADER
    va += 0xC;
#else
    va += sizeof(IMAGE_DOS_HEADER);
#endif
    memcpy(Data.Hello, &va, sizeof(ULONG));
#endif
    Data.Call_puts[0] = 0xFF;
    Data.Call_puts[1] = 0x15;
    memcpy(Data.puts, VA(Data.Imports.Address.Msvcrt.puts), sizeof(ULONG));
#if 0 // not necessary since we don't return
    Data.AddEsp4[0] = 0x83;
    Data.AddEsp4[1] = 0xC4;
    Data.AddEsp4[2] = 0x04;
#endif
    Data.PushExitCode = 0x6A;
    Data.ExitCode = 42;
    Data.CallGetCurrentProcess[0] = 0xFF;
    Data.CallGetCurrentProcess[1] = 0x15;
#if 1 // ndef REUSE_HEADERS
    memcpy(Data.GetCurrentProcess, VA(Data.Imports.Address.Kernel32.GetCurrentProcess), sizeof(ULONG));
#else
    rva = (4 + offsetof(IMAGE_FILE_HEADER, TimeDateStamp));
#ifdef OVERLAY_PE_AND_DOS_HEADER
    rva += 0xC;
#else
    rva += sizeof(IMAGE_DOS_HEADER);
#endif
    va = (rva + OptionalHeader->ImageBase);
    memcpy(Data.GetCurrentProcess, &va, sizeof(ULONG));
#endif
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
#ifndef REUSE_HEADERS
    Data.Imports.Descriptor.Kernel32.Name = RVA(Data.String.Kernel32);
#else
    rva = (4 + sizeof(IMAGE_FILE_HEADER) + offsetof(IMAGE_OPTIONAL_HEADER, SizeOfStackReserve));
#ifdef OVERLAY_PE_AND_DOS_HEADER
    rva += 0xC;
#else
    rva += sizeof(IMAGE_DOS_HEADER);
#endif
    Data.Imports.Descriptor.Kernel32.Name = rva;
#endif

    // addresses, subtract 2 to leave room for an arbitrary and not necessarily aligned hint

#ifndef REUSE_HEADERS
    Data.Imports.Address.Msvcrt.puts = (RVA(Data.String.puts) - 2);
#else
    Data.Imports.Address.Msvcrt.puts = 1;
#endif
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

#ifndef REUSE_HEADERS
    memcpy(Data.String.puts, "puts", sizeof("puts")); // 5 bytes
#else
    // puts is in the dos header (preceded by 2 byte hint, and not zero
    // budget here is 10 bytes, puts + hint + null is 7.
    memcpy((((PBYTE) Dos) + 3), "puts", sizeof("puts"));
#endif
    memcpy(Data.String.TerminateProcess, "TerminateProcess", sizeof("TerminateProcess")); // 17 bytes (plus 2 byte hint)
    memcpy(Data.String.GetCurrentProcess, "GetCurrentProcess", sizeof("GetCurrentProcess")); // 18 bytes (plus 2 byte hint)
    memcpy(Data.String.Msvcrt, "Msvcrt.dll", sizeof("Msvcrt.dll")); // 11 bytes
#ifndef REUSE_HEADERS
    memcpy(Data.String.Kernel32, "Kernel32.dll", sizeof("Kernel32.dll")); // 13 bytes
#else
    memcpy(&OptionalHeader->SizeOfStackReserve, "Kernel32.dll", sizeof("Kernel32.dll")); // 13 bytes, 16 available
#endif
#ifndef REUSE_HEADERS
    memcpy(Data.String.Hello, "Hello", sizeof("Hello"));
#endif

    // relocs

#ifdef RELOCATABLE
    //
    // This depends on their being less than 4k of code.
    //
    Data.Relocs.Header.SizeOfBlock = sizeof(Data.Relocs);
    Data.Relocs.Header.VirtualAddress = RVA(Data.uFirstInstruction.FirstInstruction);
    Data.Relocs.Hello = ((IMAGE_REL_BASED_HIGHLOW << 12) | (Data.Hello - &Data.uFirstInstruction.FirstInstruction));
    Data.Relocs.puts = ((IMAGE_REL_BASED_HIGHLOW << 12) | (Data.puts - &Data.uFirstInstruction.FirstInstruction));
    Data.Relocs.GetCurrentProcess = ((IMAGE_REL_BASED_HIGHLOW << 12) | (Data.GetCurrentProcess - &Data.uFirstInstruction.FirstInstruction));
    Data.Relocs.TerminateProcess = ((IMAGE_REL_BASED_HIGHLOW << 12) | (Data.TerminateProcess - &Data.uFirstInstruction.FirstInstruction));

#endif

    // version resource?

#ifdef OMIT_TRAILING_NULL_IMPORT_DESCRIPTOR
    // link /dump doesn't like this but the loader is ok
    while ((Section->SizeOfRawData != 0) && (((PBYTE) &Data)[Section->SizeOfRawData - 1] == 0))
    {
        Section->SizeOfRawData -= 1;
    }
#endif

#ifdef REUSE_HEADERS
/*
    DWORD   SizeOfStackReserve;
    DWORD   SizeOfStackCommit;
    DWORD   SizeOfHeapReserve;
    DWORD   SizeOfHeapCommit;
*/
#endif

    FileHandle = _wfopen(L"1.dll", L"wb");
    if (FileHandle == NULL)
    {
        Result = errno;
        wprintf(L"fopen error %d %ls\n", Result, _wcserror(Result));
        goto Exit;
    }
#if 0
    fwrite(&Header, RoundUp(OptionalHeader->SizeOfHeaders, OptionalHeader->FileAlignment), 1, FileHandle);
#else
    i = 0;
    j = sizeof(*Dos);
    fwrite(Dos, j, 1, FileHandle);
#ifdef OVERLAY_PE_AND_DOS_HEADER
    ((USHORT*)Nt)[24] = Dos->e_lfanew;
    fseek(FileHandle, Dos->e_lfanew, SEEK_SET);
#endif
    i = Dos->e_lfanew;
    j = (4 + sizeof(IMAGE_FILE_HEADER) + Header.Nt.FileHeader.SizeOfOptionalHeader);
    i += j;
    fwrite(Nt, j, 1, FileHandle);
    j = sizeof(*Section);
    fwrite(Section, j, 1, FileHandle);
    i += j;
    fwrite(&FileAlign, (RoundUp(i, OptionalHeader->FileAlignment) - i), 1, FileHandle);
#endif

    fwrite(&Data, Section->SizeOfRawData, 1, FileHandle);

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
