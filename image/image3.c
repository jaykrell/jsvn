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

// no savings  (and not finished therefore)
//#define TAIL_CALL_AND_NO_RETURN

#ifndef BASE

#define BASE 0x00900000
//#define BASE 0x00400000 // for reloc

#endif

// works either way
//#define MAKE_DLL

#define USE_EXIT 1
#define FILE_ALIGN 0x4 /* popular values are 0x1000 and 0x200 */
#define SECTION_ALIGN 0x4
#define DOS_HEADER_SIZE 0x4

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
//#pragma pack(1) // TBD get the same size but without this; where is the padding?
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
                WORD    MajorSubsystemVersion; // section virtualsize
                WORD    MinorSubsystemVersion; // section virtualsize
                DWORD   Win32VersionValue; // section virtualaddress
                DWORD   SizeOfImage; // section sizeofrawdata
                DWORD   SizeOfHeaders; // section pointer to relocs unused
                DWORD   CheckSum; // section number of relocs, number of line numbers (unused)
                WORD    Subsystem; // section characteristics
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
#define VA(x) (RVA(x) + OptionalHeader->ImageBase)
    ULONG va;
    FILE* FileHandle = { 0 };
    HMODULE DllHandle = { 0 };
    DWORD Error = { 0 };
    PWSTR ErrorString = { 0 };
    int Result = 1;
    IMAGE_DOS_HEADER* Dos = (IMAGE_DOS_HEADER*) &Image;
    IMAGE_NT_HEADERS* Nt = (IMAGE_NT_HEADERS*) &Image.PeSignature;
    IMAGE_OPTIONAL_HEADER* OptionalHeader = (IMAGE_OPTIONAL_HEADER*) &Image.OptionalHeader;
    IMAGE_FILE_HEADER* FileHeader = (IMAGE_FILE_HEADER*) &Image.FileHeader;
    IMAGE_SECTION_HEADER* Section = (IMAGE_SECTION_HEADER*) &Image.Section.Name;
    size_t i = { 0 };
    size_t j = { 0 };
    PBYTE p = { 0 };
    DWORD* FirstThunk = { 0 }; /* for compat with old headers */ 
    IMAGE_IMPORT_DESCRIPTOR* ImportDescriptors = (IMAGE_IMPORT_DESCRIPTOR*) &OptionalHeader->SizeOfHeapReserve;
    USHORT SizeOfOptionalHeader = { 0 };
    USHORT SizeOfHeaders = { 0 };
    USHORT SizeOfRawData = { 0 };
    USHORT SectionAlignment = { 0 };
    PDWORD IAT = (PDWORD) &Image.FileHeader.TimeDateStamp;

    SetErrorMode(SEM_FAILCRITICALERRORS);

    ZeroMemory(&Image, sizeof(Image));

    SectionAlignment = ((SECTION_ALIGN < FILE_ALIGN) ? FILE_ALIGN : SECTION_ALIGN);
    OptionalHeader->SectionAlignment = SectionAlignment;
    OptionalHeader->FileAlignment = FILE_ALIGN;
    OptionalHeader->ImageBase = BASE;

#ifndef RELOCATABLE
    OptionalHeader->NumberOfRvaAndSizes = (IMAGE_DIRECTORY_ENTRY_IMPORT + 1);
#else
    OptionalHeader->NumberOfRvaAndSizes = (IMAGE_DIRECTORY_ENTRY_BASERELOC + 1);
#endif

    SizeOfOptionalHeader = sizeof(Image.Section.OptionalHeaderPad);
    Section = (IMAGE_SECTION_HEADER*) (SizeOfOptionalHeader + (PBYTE) OptionalHeader);
    SizeOfHeaders = (DOS_HEADER_SIZE + 4 + sizeof(IMAGE_FILE_HEADER) + SizeOfOptionalHeader + sizeof(IMAGE_SECTION_HEADER));

    Section->Misc.VirtualSize = 0x1000;
    SizeOfRawData = 0x1000;
    Section->SizeOfRawData = SizeOfRawData;
    Section->VirtualAddress = RoundUp(SizeOfHeaders, SectionAlignment);
    Section->PointerToRawData = RoundUp(SizeOfHeaders, FILE_ALIGN);

    FileHeader->SizeOfOptionalHeader = SizeOfOptionalHeader;
    OptionalHeader->SizeOfHeaders = SizeOfHeaders;

    Dos->e_magic = IMAGE_DOS_SIGNATURE;
    Dos->e_lfanew = DOS_HEADER_SIZE;
    FileHeader->Machine = IMAGE_FILE_MACHINE_I386;
    FileHeader->NumberOfSections = 1;

    FileHeader->Characteristics = (IMAGE_FILE_EXECUTABLE_IMAGE | IMAGE_FILE_32BIT_MACHINE);
#ifdef MAKE_DLL
    FileHeader->Characteristics |= IMAGE_FILE_DLL;
#endif
#ifndef RELOCATABLE
    FileHeader->Characteristics |= IMAGE_FILE_RELOCS_STRIPPED;
#endif
    Nt->Signature = IMAGE_NT_SIGNATURE;

    OptionalHeader->Magic = IMAGE_NT_OPTIONAL_HDR_MAGIC;
    OptionalHeader->AddressOfEntryPoint = RVA(OptionalHeader->MajorLinkerVersion);

    // when overlaying import_descriptor onto optional_header, this is the name of the second descriptor and must be 0.?
    OptionalHeader->MajorSubsystemVersion = 3;
    OptionalHeader->MinorSubsystemVersion = 10;
    OptionalHeader->Subsystem = IMAGE_SUBSYSTEM_WINDOWS_CUI;
    OptionalHeader->SizeOfImage = RoundUp(Section->VirtualAddress + Section->Misc.VirtualSize, SectionAlignment);

#ifdef RELOCATABLE
    OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress = RVA(Image.Data.Relocs);
    OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].Size = sizeof(Image.Data.Relocs);
#endif

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

    fwrite(&Image, sizeof(Image) - 3, 1, FileHandle);
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
