#define _WIN32_WINNT ~0u
#define _CRT_SECURE_NO_DEPRECATE
#ifndef __GNUC__
#pragma warning(disable:4201) /* nonstandard extension: nameless struct/union */
#if (_MSC_VER <= 1200)
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
#define OriginalFirstThunk Characteristics /* compat with older headers */
#ifndef __GNUC__
#if (_MSC_VER <= 1200)
#pragma warning(disable:4001)
#pragma warning(disable:4201) /* nonstandard extension: nameless struct/union */
#endif
#endif

#ifndef BASE

#define BASE 0x00900000
//#define BASE 0x00400000 // for reloc

#endif

#define FILE_ALIGN 0x4
#define SECTION_ALIGN 0x4
#define DOS_HEADER_SIZE 0x4

int
__cdecl
wmain()
{
    struct
    {
        WORD    e_magic; // MZ
        WORD    DosPad; // unused
        DWORD   PeSignature; // PE00
        struct
        {
            WORD    Machine; // x86
            WORD    NumberOfSections; // 1
            DWORD   TimeDateStamp; // unused
            DWORD   PointerToSymbolTable; // unused
            DWORD   NumberOfSymbols; // unused
            WORD    SizeOfOptionalHeader;
            WORD    Characteristics; // unused
        } FileHeader;
        struct
        {
            WORD    Magic;
            BYTE    MajorLinkerVersion; // code
            BYTE    MinorLinkerVersion; // code
            DWORD   SizeOfCode; // code
            DWORD   SizeOfInitializedData; // unused
            DWORD   SizeOfUninitializedData; // unused
            DWORD   AddressOfEntryPoint;
            DWORD   BaseOfCode; // unused
            DWORD   BaseOfData; // unused
            DWORD   ImageBase;
            DWORD   SectionAlignment;
            DWORD   FileAlignment;
        } OptionalHeader;
        struct
        {
            BYTE    Name[8];
            DWORD   VirtualSize;
            DWORD   VirtualAddress;
            DWORD   SizeOfRawData;
            DWORD   PointerToRawData;
            DWORD   PointerToRelocations;
            DWORD   PointerToLinenumbers;
        } Section;
    } Image;
#define RVA(x) ((ULONG) (((size_t) &x) - (size_t) &Image))
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
    USHORT const SizeOfOptionalHeader = sizeof(Image.OptionalHeader);
    USHORT const SizeOfHeaders = (DOS_HEADER_SIZE + 4 + sizeof(IMAGE_FILE_HEADER) + SizeOfOptionalHeader + sizeof(IMAGE_SECTION_HEADER));

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
    FileHeader->Characteristics |= IMAGE_FILE_RELOCS_STRIPPED;

    OptionalHeader->Magic = IMAGE_NT_OPTIONAL_HDR_MAGIC;
    OptionalHeader->AddressOfEntryPoint = RVA(OptionalHeader->MajorLinkerVersion);

    OptionalHeader->MajorSubsystemVersion = 3;
    OptionalHeader->MinorSubsystemVersion = 10;
    OptionalHeader->Subsystem = IMAGE_SUBSYSTEM_WINDOWS_CUI;
    OptionalHeader->SizeOfImage = (Section->VirtualAddress + Section->Misc.VirtualSize);

    p = (PBYTE) &OptionalHeader->MajorLinkerVersion;

    // mov eax, 42

    *p++ = 0xB8;
    *p++ = 42;
    *p++ = 0;
    *p++ = 0;
    *p++ = 0;

    // ret
    *p++ = 0xc3;

    DeleteFileW(L"1.exe");
    FileHandle = fopen("1.exe", "wb");
    if (FileHandle == NULL)
    {
        Result = errno;
        wprintf(L"fopen error %d %hs\n", Result, strerror(Result));
        goto Exit;
    }

    // last three bytes are zero and don't have to be written

    fwrite(&Image, (sizeof(Image) - 3), 1, FileHandle);
    fclose(FileHandle);
    Result = Error;

Exit:
    LocalFree(ErrorString);
    if (DllHandle != NULL)
        FreeLibrary(DllHandle);
    return Result;
}

#if defined(__GNUC__) || defined(__MWERKS__)
int main()
{
    return wmain();
}
#endif
