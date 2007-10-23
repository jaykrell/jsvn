#define _WIN32_WINNT ~0u
#define _CRT_SECURE_NO_DEPRECATE
#define Reserved1 Win32VersionValue /* compat with older headers */
#ifndef __GNUC__
#if (_MSC_VER < 1000)
#pragma warning(disable:4244 4057 4115)
#pragma warning(disable:4226) /* nonstandard extension: __export */
#pragma warning(disable:4201) /* nonstandard extension: nameless struct/union */
#pragma warning(disable:4214) /* nonstandard extension: bitfields other than int */
#pragma warning(disable:4209) /* nonstandard extension: benign retypedef */
#pragma warning(disable:4514) /* unused inline function removed */
#endif
#endif
#include <stdio.h>
#include <windows.h>
#include <stddef.h>
#include <errno.h>
#define C_ASSERT(e) typedef char __C_ASSERT__[(e)?1:-1] /* compat with older headers */
#define OriginalFirstThunk Characteristics /* compat with older headers */
#ifndef __GNUC__
#pragma warning(disable:4001)
#endif

/* every option works, but not every option in combination or
 every value for every option */

#define TARGET_PAGE_SIZE 0x1000

#ifndef BASE

#define BASE 0x00900000
//#define BASE 0x00400000 // for reloc

#endif

// works either way
//#define MAKE_DLL

// Costs around 48 bytes
// not necessarily maintained for all combinations
//#define RELOCATABLE 1

#define FILE_ALIGN 0x1 /* popular values are 0x1000 and 0x200 */
//#define FILE_ALIGN 0x4 /* popular values are 0x1000 and 0x200 */
//#define FILE_ALIGN 0x100 /* popular values are 0x1000 and 0x200 */
//#define FILE_ALIGN 0x200 /* popular values are 0x1000 and 0x200 */
//#define FILE_ALIGN 0x1000 /* popular values are 0x1000 and 0x200 */
//#define FILE_ALIGN TARGET_PAGE_SIZE

// section align cannot be less than file align and will be increased to match */
#define SECTION_ALIGN 0x1 /* can be any power of two but usually page size */
//#define SECTION_ALIGN 0x100 /* popular values are 0x1000 and 0x200 */
//#define SECTION_ALIGN 0x200 /* popular values are 0x1000 and 0x200 */
//#define SECTION_ALIGN 0x1000 /* can be any power of two but usually page size */
//#define SECTION_ALIGN TARGET_PAGE_SIZE
//#define SECTION_ALIGN 0x4

#define DOS_HEADER_SIZE sizeof(IMAGE_DOS_HEADER)

// failed (and not second-order pruned -- this turns off other optimizations
// while we just tried to make this work)
//#define OVERLAY_IMPORT_DESCRIPTOR_ON_OPTIONAL_HEADER

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
#pragma pack(1) // TBD get the same size but without this; where is the padding?
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
        BYTE PushExitCode;
        BYTE ExitCode;
        BYTE Call_exit[2];
        BYTE exit[4];
        struct
        {
            BYTE Msvcrt[sizeof("msvcrt")];
            BYTE Kernel32[sizeof("Kernel32")];
            BYTE Hello[sizeof("Hello")];
            BYTE hint_puts[2];
            BYTE puts[sizeof("puts")];
            BYTE hint_exit[2];
            BYTE exit[sizeof("exit")];
        } String;
        struct
        {
            IMAGE_BASE_RELOCATION Header;
            USHORT Hello;
            USHORT puts;
            USHORT exit;
        } Relocs;
        struct
        {
            struct
            {
                ULONG puts;
                ULONG exit;
                ULONG Null;
            } Msvcrt;
        }
        ImportNames, ImportAddresses;
        struct
        {
            IMAGE_IMPORT_DESCRIPTOR Msvcrt;
            IMAGE_IMPORT_DESCRIPTOR Null;
        } ImportDescriptors;
    } Data;
#define RVA(x) ((ULONG) (((size_t) &x) - (size_t) &Data) + Section->VirtualAddress)
#define VA(x) ((va = (RVA(x) + OptionalHeader->ImageBase)), &va)
    ULONG va;
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
    size_t i = { 0 };
    size_t j = { 0 };
    PBYTE p = { 0 };
    DWORD* FirstThunk = { 0 }; /* for compat with old headers */ 
    DWORD SizeOfImage = { 0 };
    IMAGE_IMPORT_DESCRIPTOR* ImportDescriptors = &Data.ImportDescriptors.Msvcrt;
    size_t FileAlignPadSize = { 0 };

    HANDLE Win32FileHandle = { 0 };
    HANDLE FileMappingHandle = { 0 };
    PVOID MappedBase = { 0 };

    USHORT SizeOfOptionalHeader = { 0 };
    USHORT SizeOfHeaders = { 0 };

    SetErrorMode(SEM_FAILCRITICALERRORS);

    //OptionalHeader->SizeOfStackReserve = 1;
    //OptionalHeader->SizeOfStackCommit = 2;
    //OptionalHeader->SizeOfHeapReserve = 3;
    //OptionalHeader->SizeOfHeapCommit = 4;
    //OptionalHeader->CheckSum = 5;

    for (SizeOfOptionalHeader = 0  ; SizeOfOptionalHeader <= sizeof(IMAGE_OPTIONAL_HEADER) ; ++SizeOfOptionalHeader)
    {
        ZeroMemory(&Header, sizeof(Header));
        ZeroMemory(&Data, sizeof(Data));

        SizeOfHeaders = (DOS_HEADER_SIZE + 4 + sizeof(IMAGE_FILE_HEADER) + sizeof(IMAGE_OPTIONAL_HEADER) + sizeof(IMAGE_SECTION_HEADER));

        Section = (IMAGE_SECTION_HEADER*) (SizeOfOptionalHeader + (PBYTE) OptionalHeader);
        Section->Misc.VirtualSize = sizeof(Data);
        Section->SizeOfRawData = sizeof(Data);
        Section->VirtualAddress = RoundUp(SizeOfHeaders, SECTION_ALIGN);
        Section->PointerToRawData = RoundUp(SizeOfHeaders, FILE_ALIGN);

        FileHeader->SizeOfOptionalHeader = SizeOfOptionalHeader;
        OptionalHeader->SizeOfHeaders = SizeOfHeaders;
        OptionalHeader->NumberOfRvaAndSizes = IMAGE_NUMBEROF_DIRECTORY_ENTRIES;
        OptionalHeader->SectionAlignment = ((SECTION_ALIGN < FILE_ALIGN) ? FILE_ALIGN : SECTION_ALIGN);
        OptionalHeader->FileAlignment = FILE_ALIGN;
        OptionalHeader->ImageBase = BASE;

        Dos->e_magic = IMAGE_DOS_SIGNATURE;
        Dos->e_lfanew = DOS_HEADER_SIZE;
        FileHeader->Machine = IMAGE_FILE_MACHINE_I386;
        FileHeader->NumberOfSections = 1;

        Section = (Section + FileHeader->NumberOfSections - 1);

        FileHeader->Characteristics = (IMAGE_FILE_EXECUTABLE_IMAGE | IMAGE_FILE_32BIT_MACHINE);
#ifdef MAKE_DLL
        FileHeader->Characteristics |= IMAGE_FILE_DLL;
#endif
        FileHeader->Characteristics |= IMAGE_FILE_RELOCS_STRIPPED;
        Nt->Signature = IMAGE_NT_SIGNATURE;

        OptionalHeader->Magic = IMAGE_NT_OPTIONAL_HDR_MAGIC;
        OptionalHeader->AddressOfEntryPoint = 0; //RVA(Data);

        // when overlaying import_descriptor onto optional_header, this is the name of the second descriptor and must be 0.?
        OptionalHeader->MajorOperatingSystemVersion = 0;
        OptionalHeader->MajorSubsystemVersion = 3;
        OptionalHeader->MinorSubsystemVersion = 10;
        //OptionalHeader->DllCharacteristics = 0x400;
        OptionalHeader->Subsystem = IMAGE_SUBSYSTEM_WINDOWS_CUI;
        // not always/ever needed
        OptionalHeader->SizeOfImage = RoundUp(Section->VirtualAddress + Section->Misc.VirtualSize, SECTION_ALIGN);

        OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress = RVA(Data.ImportDescriptors);
        OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size = sizeof(IMAGE_IMPORT_DESCRIPTOR);

        OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress = RVA(Data.Relocs);
        OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].Size = sizeof(Data.Relocs);

        Data.uFirstInstruction.PushHello = 0x68;

        memcpy(Data.Hello, VA(Data.String.Hello), sizeof(ULONG));

        Data.Call_puts[0] = 0xFF;
        Data.Call_puts[1] = 0x15;

        memcpy(Data.puts, VA(Data.ImportAddresses.Msvcrt.puts), sizeof(ULONG));

        Data.PushExitCode = 0x6A;
        Data.ExitCode = 42;
        Data.Call_exit[0] = 0xFF;
        Data.Call_exit[1] = 0x15;
        memcpy(Data.exit, VA(Data.ImportAddresses.Msvcrt.exit), sizeof(ULONG));

        // import ImportDescriptors

        ImportDescriptors[0].Name = RVA(Data.String.Msvcrt);
        FirstThunk = (DWORD*) &ImportDescriptors[0].FirstThunk;
        *FirstThunk = RVA(Data.ImportAddresses.Msvcrt);

        // ImportAddresseses, subtract 2 to leave room for an arbitrary and not necessarily aligned hint

        Data.ImportAddresses.Msvcrt.exit = (RVA(Data.String.exit) - 2);
        Data.ImportAddresses.Msvcrt.puts = (RVA(Data.String.puts) - 2);

        // names

        ImportDescriptors[0].OriginalFirstThunk = (DWORD) ImportDescriptors[0].FirstThunk;
        ImportDescriptors[0].OriginalFirstThunk = RVA(Data.ImportNames.Msvcrt);
        Data.ImportNames = Data.ImportAddresses;

        // strings

        memcpy(Data.String.exit, "exit", sizeof("exit")); // 5 bytes
        memcpy(Data.String.Msvcrt, "msvcrt", sizeof("msvcrt")); // 7 bytes

        memcpy(Data.String.puts, "puts", sizeof("puts")); // 5 bytes
        memcpy(Data.String.Hello, "Hello", sizeof("Hello"));
 
        // relocs

        //
        // This depends on their being less than 4k of code.
        //
        Data.Relocs.Header.SizeOfBlock = sizeof(Data.Relocs);
        Data.Relocs.Header.VirtualAddress = RVA(Data.uFirstInstruction.FirstInstruction);
        Data.Relocs.Hello = ((IMAGE_REL_BASED_HIGHLOW << 12) | (Data.Hello - &Data.uFirstInstruction.FirstInstruction));
        Data.Relocs.puts = ((IMAGE_REL_BASED_HIGHLOW << 12) | (Data.puts - &Data.uFirstInstruction.FirstInstruction));
        Data.Relocs.exit = ((IMAGE_REL_BASED_HIGHLOW << 12) | (Data.exit - &Data.uFirstInstruction.FirstInstruction));

        // version resource?


        //Section->SizeOfRawData -= 4;
        //Section->Misc.VirtualSize -= 4;
        //Section->PointerToRawData = 32;
        //OptionalHeader->SizeOfHeaders -= 4;
        //Section->VirtualAddress -= 4;
        //Nt->FileHeader.SizeOfOptionalHeader -= 4;

#ifdef MAKE_DLL
        DeleteFileW(L"2.dll");
        FileHandle = fopen("2.dll", "wb");
#else
        DeleteFileW(L"1.exe");
        FileHandle = fopen("2.exe", "wb");
#endif
        if (FileHandle == NULL)
        {
            Result = errno;
            wprintf(L"fopen error %d %hs\n", Result, strerror(Result));
            goto Exit;
        }

        i = (Dos->e_lfanew + 4 + sizeof(IMAGE_FILE_HEADER) + sizeof(IMAGE_OPTIONAL_HEADER) + sizeof(IMAGE_SECTION_HEADER));

        //
        // section header ends with 4 ignored bytes and is followed by he code
        // move the code back 4 bytes to save them; this breaks disassembly
        //
        if (FILE_ALIGN != 1)
        {
            FileAlignPadSize = (i % FILE_ALIGN);
            if (FileAlignPadSize != 0)
            {
                FileAlignPadSize = (FILE_ALIGN - FileAlignPadSize);
                // nops in case we are moving code
                // into section header, but really should put code here, duh
                //. This turns out to be empty anyway in our smaller cases
                //printf("%u bytes of padding for alignment\n", (unsigned) FileAlignPadSize);
                //memset(FileAlign, 0x90, FileAlignPadSize);
            }
        }


        i = 0;
        j = sizeof(*Dos);
        fwrite(Dos, j, 1, FileHandle);
        i = Dos->e_lfanew;
        j = (4 + sizeof(IMAGE_FILE_HEADER) + sizeof(IMAGE_OPTIONAL_HEADER));
        i += j;
        fwrite(Nt, j, 1, FileHandle);
        j = sizeof(*Section);
        fwrite(Section, j, 1, FileHandle);
        i += j;
        fwrite(&FileAlign, FileAlignPadSize, 1, FileHandle);
        fwrite(&Data, Section->SizeOfRawData, 1, FileHandle);

        fclose(FileHandle);

#ifdef MAKE_DLL
        SetLastError(0);
#if 0
        Win32FileHandle = CreateFileW(L"2.dll", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        FileMappingHandle = CreateFileMappingW(Win32FileHandle, NULL, SEC_IMAGE, 0, 0, NULL);
        MappedBase = MapViewOfFile(FileMappingHandle, 0, 0, 0, 0);
        Error = GetLastError();
        ErrorString = GetErrorString(Error);
        wprintf(
            L"FileHeader->SizeOfOptionalHeader: %u, success: %u, error: %u %ls\n",
            ((UINT) FileHeader->SizeOfOptionalHeader),
            ((UINT) (MappedBase != NULL)),
            ((UINT) Error),
            ErrorString
            );
        LocalFree(ErrorString);
        ErrorString = NULL;
        UnmapViewOfFile(MappedBase);
        CloseHandle(FileMappingHandle);
        CloseHandle(Win32FileHandle);
#endif
        FreeLibrary(Win32FileHandle = LoadLibraryW(L"2.dll"));
        if (Win32FileHandle != NULL)
        {
            printf("SizeOfOptionalHeader: 0x%x LoadLibrary:%p\n", SizeOfOptionalHeader, Win32FileHandle);
            fflush(stdout);
            //exit(0);
        }
#endif

        Result = Error;
    }

Exit:
    LocalFree(ErrorString);
    if (DllHandle != NULL)
        FreeLibrary(DllHandle);
    return Result;
}

#ifdef __GNUC__
int main()
{
    return wmain();
}
#endif
