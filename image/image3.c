#pragma warning(disable:4201) /* nonstandard extension: nameless struct/union */
#define _WIN32_WINNT ~0u
#define _CRT_SECURE_NO_DEPRECATE
#define Reserved1 Win32VersionValue /* compat with older headers */
#ifndef __GNUC__
#if (_MSC_VER < 1000)
#pragma warning(disable:4244 4057 4115)
#pragma warning(disable:4226) /* nonstandard extension: __export */
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

#ifndef BASE

#define BASE 0x00900000
//#define BASE 0x00400000 // for reloc

#endif

// works either way
//#define MAKE_DLL

#define FILE_ALIGN 0x4
#define SECTION_ALIGN 0x4
#define DOS_HEADER_SIZE 0x4

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

int
__cdecl
wmain()
{
#pragma pack(1) // TBD get the same size but without this; where is the padding?
    struct
    {
        WORD    e_magic; // MZ
        WORD    DosPad; // unused
        DWORD   PeSignature; // PE00
        struct
        {
            WORD    Machine; // x86
            WORD    NumberOfSections; // 1
            DWORD   TimeDateStamp; // iat puts
            DWORD   PointerToSymbolTable; // iat exit
            DWORD   NumberOfSymbols; // iat terminal zero
            WORD    SizeOfOptionalHeader;
            WORD    Characteristics; // unused
        } FileHeader;
        union
        {
            struct
            {
                WORD    Magic;
                BYTE    MajorLinkerVersion; // code
                BYTE    MinorLinkerVersion; // code
                DWORD   SizeOfCode; // code
                DWORD   SizeOfInitializedData; // code
                DWORD   SizeOfUninitializedData; // code
                DWORD   AddressOfEntryPoint;
                DWORD   BaseOfCode; // code
                DWORD   BaseOfData; // code, 2 bytes unused
                DWORD   ImageBase;
                DWORD   SectionAlignment;
                DWORD   FileAlignment;
                WORD    MajorOperatingSystemVersion; // section name "msvcrt"
                WORD    MinorOperatingSystemVersion; // section name "msvcrt"
                WORD    MajorImageVersion; // section name "msvcrt"
                WORD    MinorImageVersion; // section name "msvcrt" 1 byte unused
                // subsystemversion is very constrained for .exes but for .dlls
                // merely major or minor must be non-zero, therefore these 4 bytes are available
                // for use in the .dll
                WORD    MajorSubsystemVersion; // section virtualsize
                WORD    MinorSubsystemVersion; // section virtualsize
                DWORD   Win32VersionValue; // section virtualaddress
                DWORD   SizeOfImage; // section sizeofrawdata, semi-unused (some constraints on the value)
                DWORD   SizeOfHeaders; // section pointer to relocs, semi-unused (some constraints on the value)
                DWORD   CheckSum; // section number of relocs, number of line numbers, "hello" in .dll, unused in .exe
                WORD    Subsystem; // section characteristics, "hello" in .dll
                WORD    DllCharacteristics; // "puts"
                DWORD   SizeOfStackReserve; // "puts" "exit"
                DWORD   SizeOfStackCommit; // "exit"
                DWORD   SizeOfHeapReserve; // section data import descriptor
                DWORD   SizeOfHeapCommit;  // section data import descriptor
                DWORD   LoaderFlags;       // section data import descriptor
                DWORD   NumberOfRvaAndSizes; // section data import descriptor
                IMAGE_DATA_DIRECTORY ExportDirectory; // section data import descriptor four bytes unused
                IMAGE_DATA_DIRECTORY ImportDirectory;
            } OptionalHeader;
            struct
            {
                //
                // Experimentation with an otherwise well formed image shows 0x28 to be the
                // smallest acceptable value for SizeOfOptionalHeader.
                // Experimentation shows that the import descriptor must be after the headers.
                //
                BYTE    OptionalHeaderPad[0x28]; // up to MajorOperatingSystemVersion
                BYTE    Name[8]; // MajorOperatingSystemVersion
                DWORD   VirtualSize; // OptionalHeader_MajorSubsystemVersion, OptionalHeader_MinorSubsystemVersion
                DWORD   VirtualAddress; // OptionalHeader_Win32VersionValue
                DWORD   SizeOfRawData; // OptionalHeader_SizeOfImage
                DWORD   PointerToRawData; // OptionalHeader_SizeOfHeaders
                DWORD   PointerToRelocations; // OptionalHeader_CheckSum
                DWORD   PointerToLinenumbers; // OptionalHeader_Subsystem, OptionalHeader_DllCharacteristics
                WORD    NumberOfRelocations; // OptionalHeader_SizeOfStackReserve
                WORD    NumberOfLinenumbers; // OptionalHeader_SizeOfStackReserve
                DWORD   Characteristics; // OptionalHeader_SizeOfStackCommit
            } Section;
        };
#ifndef MAKE_DLL
        BYTE Zero[4];
        BYTE Hello[5];
#endif
    } Image;
#define RVA(x) ((ULONG) (((size_t) &x) - (size_t) &Image))
#define VA(x) (RVA(x) + BASE)
    ULONG va;
    FILE* FileHandle = { 0 };
    HMODULE DllHandle = { 0 };
    DWORD Error = { 0 };
    PWSTR ErrorString = { 0 };
    int Result = 1;
    IMAGE_DOS_HEADER* const Dos = (IMAGE_DOS_HEADER*) &Image;
    IMAGE_NT_HEADERS* const Nt = (IMAGE_NT_HEADERS*) &Image.PeSignature;
    IMAGE_OPTIONAL_HEADER* const OptionalHeader = (IMAGE_OPTIONAL_HEADER*) &Image.OptionalHeader;
    IMAGE_FILE_HEADER* const FileHeader = (IMAGE_FILE_HEADER*) &Image.FileHeader;
    IMAGE_SECTION_HEADER* const Section = (IMAGE_SECTION_HEADER*) &Image.Section.Name;
    PBYTE p = { 0 };
    IMAGE_IMPORT_DESCRIPTOR* const ImportDescriptors = (IMAGE_IMPORT_DESCRIPTOR*) &OptionalHeader->SizeOfHeapReserve;
    USHORT const SizeOfOptionalHeader = sizeof(Image.Section.OptionalHeaderPad);
    USHORT const SizeOfHeaders = (DOS_HEADER_SIZE + 4 + sizeof(IMAGE_FILE_HEADER) + SizeOfOptionalHeader + sizeof(IMAGE_SECTION_HEADER));
    PDWORD const IAT = (PDWORD) &Image.FileHeader.TimeDateStamp;

    SetErrorMode(SEM_FAILCRITICALERRORS);

    ZeroMemory(&Image, sizeof(Image));

    Dos->e_magic = IMAGE_DOS_SIGNATURE;
    Dos->e_lfanew = DOS_HEADER_SIZE; // this overlaps with FileAlignment or SectionAlignment
    Nt->Signature = IMAGE_NT_SIGNATURE;
    OptionalHeader->SectionAlignment = SECTION_ALIGN;
    OptionalHeader->FileAlignment = FILE_ALIGN;
    OptionalHeader->ImageBase = BASE;
    Section->VirtualAddress = SizeOfHeaders;
    Section->PointerToRawData = SizeOfHeaders;
    FileHeader->SizeOfOptionalHeader = SizeOfOptionalHeader;
    FileHeader->Machine = IMAGE_FILE_MACHINE_I386;
    FileHeader->NumberOfSections = 1;

    FileHeader->Characteristics = (IMAGE_FILE_EXECUTABLE_IMAGE | IMAGE_FILE_32BIT_MACHINE);
#ifdef MAKE_DLL
    FileHeader->Characteristics |= IMAGE_FILE_DLL;
#endif
    FileHeader->Characteristics |= IMAGE_FILE_RELOCS_STRIPPED;

    OptionalHeader->Magic = IMAGE_NT_OPTIONAL_HDR_MAGIC;
    OptionalHeader->AddressOfEntryPoint = RVA(OptionalHeader->MajorLinkerVersion);

#ifdef MAKE_DLL
    OptionalHeader->MajorSubsystemVersion = 1;
#else
    OptionalHeader->MajorSubsystemVersion = 3;
    OptionalHeader->MinorSubsystemVersion = 10;
#endif
    OptionalHeader->Subsystem = IMAGE_SUBSYSTEM_WINDOWS_CUI;
    OptionalHeader->SizeOfImage = (Section->VirtualAddress + Section->Misc.VirtualSize);

    p = (PBYTE) &OptionalHeader->MajorLinkerVersion;

    // push hello

    *p++ = 0x68;
#ifndef MAKE_DLL
    va = VA(Image.Hello);
#else
    va = VA(Section->PointerToRelocations);
#endif
    memcpy(p, &va, sizeof(ULONG));    
    p += sizeof(ULONG);

    // call puts

    *p++ = 0xFF;
    *p++ = 0x15;

    va = (OptionalHeader->ImageBase + RVA(IAT[0]));
    memcpy(p, &va, sizeof(ULONG));
    p += sizeof(ULONG);

    // push exit code (42)

    *p++ = 0x6A;
    *p++ = 42;

    // mov eax entry point (skip)

    *p++ = 0xB9;
    p += 4;

    // call exit

    *p++ = 0xFF;
    *p++ = 0x15;

    va = (OptionalHeader->ImageBase + RVA(IAT[1]));
    memcpy(p, &va, sizeof(ULONG));
    
#ifndef MAKE_DLL
    memcpy(&Image.Hello, "Hello", sizeof("Hello") - 1);
#else
    // This overwrites Subsystem which we have to leave alone for an .exe.
    memcpy(&Section->PointerToRelocations, "Hello", sizeof("Hello") - 1);
#endif
    memcpy(&Image.OptionalHeader.DllCharacteristics, "puts", sizeof("puts"));
    memcpy(&Image.OptionalHeader.MajorOperatingSystemVersion, "msvcrt", sizeof("msvcrt"));
    memcpy((3 + ((PBYTE) &Image.OptionalHeader.SizeOfStackReserve)), "exit", sizeof("exit"));

    IAT[0] = (RVA(Image.OptionalHeader.DllCharacteristics) - 2);
    IAT[1] = (RVA(Image.OptionalHeader.SizeOfStackReserve) + 3 - 2);
    IAT[2] = 0;

    ImportDescriptors[0].Name = RVA(Image.OptionalHeader.MajorOperatingSystemVersion);
    ImportDescriptors[0].FirstThunk = RVA(Image.FileHeader.TimeDateStamp);
    ImportDescriptors[0].OriginalFirstThunk = ImportDescriptors[0].FirstThunk;

    OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress = RVA(*ImportDescriptors);
    OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size = sizeof(IMAGE_IMPORT_DESCRIPTOR);
    //printf("OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress %x\n", OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress);
    //printf("ImportDescriptors %p\n", ImportDescriptors);
    //printf("Image %p\n", &Image);

#ifdef MAKE_DLL
    DeleteFileW(L"1.dll");
    FileHandle = fopen("1.dll", "wb");
#else
    DeleteFileW(L"1.exe");
    FileHandle = fopen("1.exe", "wb");
#endif
    if (FileHandle == NULL)
    {
        Result = errno;
        wprintf(L"fopen error %d %hs\n", Result, strerror(Result));
        goto Exit;
    }

    // last three bytes are zero and don't have to be written

#ifdef MAKE_DLL
    fwrite(&Image, (sizeof(Image) - 3), 1, FileHandle);
#else
    fwrite(&Image, sizeof(Image), 1, FileHandle);
#endif
    fclose(FileHandle);

#ifdef MAKE_DLL
    DllHandle = LoadLibraryW(L"1.dll");
    if (DllHandle)
        SetLastError(0);
    Error = GetLastError();
    ErrorString = GetErrorString(Error);
    wprintf(L"LoadLibrary: %p 0x%lx %ls\n", DllHandle, Error, ErrorString);
#endif

    Result = Error;

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
