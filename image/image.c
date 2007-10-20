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
#define _CRT_SECURE_NO_DEPRECATE /* compat with new headers */
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

// does not work (and not finished therefore)
//#define OMIT_DOS_HEADER

// works either way
//#define MAKE_DLL

// always seems ok either way, saves 2 bytes per import (could possibly reuse those)
//#define ZERO_HINTS 1

// kernel32 paths not maintained
//#define USE_TERMINATE_PROCESS 1
#define USE_EXIT 1

// This works very often.
// Saves 52 bytes.
#define OVERLAY_PE_AND_DOS_HEADER 1

// Costs around 48 bytes
// not necessarily maintained for all combinations
//#define RELOCATABLE 1

// saves 20 bytes, always works, simple
#define OPTIMIZE_NOT_BINDABLE 1 /* 1 or 0, works either way */

#define FILE_ALIGN 0x4 /* popular values are 0x1000 and 0x200 */
//#define FILE_ALIGN 0x100 /* popular values are 0x1000 and 0x200 */
//#define FILE_ALIGN 0x200 /* popular values are 0x1000 and 0x200 */
//#define FILE_ALIGN 0x1000 /* popular values are 0x1000 and 0x200 */
//#define FILE_ALIGN TARGET_PAGE_SIZE

// section align cannot be less than file align and will be increased to match */
//#define SECTION_ALIGN 0x1 /* can be any power of two but usually page size */
//#define SECTION_ALIGN 0x100 /* popular values are 0x1000 and 0x200 */
//#define SECTION_ALIGN 0x200 /* popular values are 0x1000 and 0x200 */
//#define SECTION_ALIGN 0x1000 /* can be any power of two but usually page size */
//#define SECTION_ALIGN TARGET_PAGE_SIZE
#define SECTION_ALIGN 0x4

// if section_align < pagesize, then section_align must equal file_align
// That is not enforced here currently.

// causes link /dump to fail but ok
// saves 20 or 22 bytes but not compatible with all options
// not compatible with many file/section align settings
#define OMIT_TRAILING_NULL_IMPORT_IMPORT_DESCRIPTOR

// requires relatively high alignment to work
// Can we get this to work?
//#define OMIT_TRAILING_ZEROS

//#define LINK_DUMP_COMPATIBLE

#ifdef LINK_DUMP_COMPATIBLE
#undef OMIT_TRAILING_NULL_IMPORT_IMPORT_DESCRIPTOR
#endif

// This is an aggressive multiple-independent-part tricky option that saves many bytes.
#define REUSE_HEADERS 1

#define CODE_IN_HEADERS

//#define OMIT_TRAILING_NULL_IMPORT_IMPORT_DESCRIPTOR

#if defined(OMIT_DOS_HEADER)
#define DOS_HEADER_SIZE 0
#elif defined(OVERLAY_PE_AND_DOS_HEADER)
#define DOS_HEADER_SIZE 0x4
#else
#define DOS_HEADER_SIZE sizeof(IMAGE_DOS_HEADER)
#endif

#if DOS_HEADER_SIZE == 4
// This size dos header leads to dos_header.e_lfanew overlaying SectionAlign.
C_ASSERT(SECTION_ALIGN == 4);
#endif

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

#ifdef CODE_IN_HEADERS
    struct
    {
        struct
        {
            IMAGE_IMPORT_DESCRIPTOR Msvcrt;
        } ImportDescriptors;
#ifdef RELOCATABLE
        struct
        {
            IMAGE_BASE_RELOCATION Header;
            USHORT Hello;
            USHORT puts;
            USHORT exit;
        } Relocs;
#endif
    } Data;
#else
    struct
    {
#ifdef TAIL_CALL_AND_NO_RETURN
        union
        {
            BYTE PushExitCode;
            BYTE FirstInstruction;
        } uFirstInstruction;
        BYTE ExitCode;
        BYTE Push_exit[2];
        BYTE exit[4];
        BYTE PushHello;
#else
        union
        {
            BYTE PushHello;
            BYTE FirstInstruction;
        } uFirstInstruction;
#endif
        BYTE Hello[4];

#ifdef TAIL_CALL_AND_NO_RETURN
        BYTE Jump_puts[2];
#else
        BYTE Call_puts[2];
#endif
        BYTE puts[4];
#ifndef TAIL_CALL_AND_NO_RETURN

#if defined(USE_TERMINATE_PROCESS) || defined(USE_EXIT)
        BYTE PushExitCode;
        BYTE ExitCode;
#ifdef USE_TERMINATE_PROCESS
        BYTE CallGetCurrentProcess[2];
        BYTE GetCurrentProcess[4];
        BYTE PushEax;
        BYTE CallTerminateProcess[2];
        BYTE TerminateProcess[4];
#endif
#ifdef USE_EXIT
        BYTE Call_exit[2];
        BYTE exit[4];
#endif
#endif

#if !defined(USE_TERMINATE_PROCESS) && !defined(USE_EXIT)
        BYTE PopEax; // strip stack and for .dll return non-zero
#ifdef MAKE_DLL
        BYTE RetC[3];
#else
        BYTE Ret;
#endif
#endif
#endif

#if !defined(REUSE_HEADERS) || defined(USE_TERMINATE_PROCESS) || defined(OVERLAY_IMPORT_DESCRIPTOR_ON_OPTIONAL_HEADER)
        struct
        {
            BYTE Msvcrt[sizeof("msvcrt")];
            BYTE Kernel32[sizeof("Kernel32")];
            BYTE Hello[sizeof("Hello")];
#if !defined(REUSE_HEADERS) || defined(OVERLAY_IMPORT_DESCRIPTOR_ON_OPTIONAL_HEADER)
#ifdef ZERO_HINTS
            BYTE hint_puts[2];
#endif
            BYTE puts[sizeof("puts")];

#ifdef USE_EXIT
#ifdef ZERO_HINTS
            BYTE hint_exit[2];
#endif
            BYTE exit[sizeof("exit")];
#endif

#endif

#ifdef USE_TERMINATE_PROCESS
#ifdef ZERO_HINTS
            BYTE hint_TerminateProcess[2];
#endif
            BYTE TerminateProcess[sizeof("TerminateProcess")];
#ifdef ZERO_HINTS
            BYTE hint_GetCurrentProcess[2];
#endif
            BYTE GetCurrentProcess[sizeof("GetCurrentProcess")];
#endif
        } String;
#else
#endif

#ifdef RELOCATABLE
        struct
        {
            IMAGE_BASE_RELOCATION Header;
            USHORT Hello;
            USHORT puts;
#ifdef USE_TERMINATE_PROCESS
            USHORT GetCurrentProcess;
            USHORT TerminateProcess;
#endif
#ifdef USE_EXIT
            USHORT exit;
#endif
        } Relocs;
#endif

#if !defined(REUSE_HEADERS) || defined(USE_TERMINATE_PROCESS) || defined(OVERLAY_IMPORT_DESCRIPTOR_ON_OPTIONAL_HEADER)
        struct
        {
#if !defined(REUSE_HEADERS) || defined(OVERLAY_IMPORT_DESCRIPTOR_ON_OPTIONAL_HEADER)
            struct
            {
                ULONG puts;
#ifdef USE_EXIT
                ULONG exit;
#endif
                ULONG Null;
            } Msvcrt;
#else
/* section header: PointerToRelocations, PointerToLinenumbers, NumberOfRelocations, NumberOfLinenumbers */
#endif

#ifdef USE_TERMINATE_PROCESS
            struct
            {
                ULONG TerminateProcess;
                ULONG GetCurrentProcess;
                ULONG Null;
            } Kernel32;
#endif
        }
#ifdef OPTIMIZE_NOT_BINDABLE
        ImportAddresses;
#else
        ImportNames, ImportAddresses;
#endif
#endif

#ifndef OVERLAY_IMPORT_DESCRIPTOR_ON_OPTIONAL_HEADER
        struct
        {
            IMAGE_IMPORT_DESCRIPTOR Msvcrt;
#ifdef USE_TERMINATE_PROCESS
            IMAGE_IMPORT_DESCRIPTOR Kernel32;
#endif
#ifndef OMIT_TRAILING_NULL_IMPORT_IMPORT_DESCRIPTOR // save 20 bytes
            IMAGE_IMPORT_DESCRIPTOR Null; // this is at the very end of the image so we can optimize it off disk,
                                          // it seems perhaps optional anyway
#endif
        } ImportDescriptors;
#endif
    } Data;
#endif
/* This is for the first section specifically. */
#ifdef OVERLAY_PE_AND_DOS_HEADER
#if 0 // SECTION_ALIGN != TARGET_PAGE_SIZE
/* This isn't completely understood. */
#define RVA(x) ((ULONG) (((size_t) &x) - (size_t) &Data) + Section->VirtualAddress - 0x34)
#else
#define RVA(x) ((ULONG) (((size_t) &x) - (size_t) &Data) + Section->VirtualAddress)
#endif
#else
#define RVA(x) ((ULONG) (((size_t) &x) - (size_t) &Data) + Section->VirtualAddress)
#endif
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
    IMAGE_SECTION_HEADER* LastSection = { 0 };
    size_t i = { 0 };
    size_t j = { 0 };
    PBYTE p = { 0 };
    DWORD* FirstThunk = { 0 }; /* for compat with old headers */ 
    DWORD SizeOfImage = { 0 };
#ifndef OVERLAY_IMPORT_DESCRIPTOR_ON_OPTIONAL_HEADER
    IMAGE_IMPORT_DESCRIPTOR* ImportDescriptors = &Data.ImportDescriptors.Msvcrt;
#else
    // we have to waste space for extra directories, whose values may or may cause a crash, so tried here
    // also tried on fields but both failed
    IMAGE_IMPORT_DESCRIPTOR* ImportDescriptors = (IMAGE_IMPORT_DESCRIPTOR*) &OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_RESOURCE];
#endif
    size_t FileAlignPadSize = { 0 };
#if !defined(CODE_IN_HEADERS) && !defined(LINK_DUMP_COMPATIBLE)
    size_t CodeSizeBeforeSection = { 0 };
#endif

    SetErrorMode(SEM_FAILCRITICALERRORS);

    ZeroMemory(&Header, sizeof(Header));
    ZeroMemory(&Data, sizeof(Data));

    //OptionalHeader->SizeOfStackReserve = 1;
    //OptionalHeader->SizeOfStackCommit = 2;
    //OptionalHeader->SizeOfHeapReserve = 3;
    //OptionalHeader->SizeOfHeapCommit = 4;
    //OptionalHeader->CheckSum = 5;

    OptionalHeader->SectionAlignment = ((SECTION_ALIGN < FILE_ALIGN) ? FILE_ALIGN : SECTION_ALIGN);
    OptionalHeader->FileAlignment = FILE_ALIGN;
    OptionalHeader->ImageBase = BASE;

    //
    // since we have to waste between 8 and 12 bytes here for the .exe, and
    // certain non-zero data crashes ntdll.dll, let's try to put the import descriptor here
    // We also have the first eight bytes of the section header to use -- the name
    //
#ifndef RELOCATABLE
#ifdef MAKE_DLL
    OptionalHeader->NumberOfRvaAndSizes = (IMAGE_DIRECTORY_ENTRY_IMPORT + 1);
#else
    // otherwise crash in the loader..
    // this number depends, on something and sometimes 2 works
    // perhaps we can reuse these 16 bytes
    // currently we are lucky and the crash is avoided
    OptionalHeader->NumberOfRvaAndSizes = (IMAGE_DIRECTORY_ENTRY_IMPORT + 1);
    //OptionalHeader->NumberOfRvaAndSizes = (IMAGE_DIRECTORY_ENTRY_IMPORT + 2);
    //OptionalHeader->NumberOfRvaAndSizes = (IMAGE_DIRECTORY_ENTRY_IMPORT + 3);
#endif
#else
    OptionalHeader->NumberOfRvaAndSizes = (IMAGE_DIRECTORY_ENTRY_BASERELOC + 1);
#endif
#ifdef LINK_DUMP_COMPATIBLE
    OptionalHeader->NumberOfRvaAndSizes = (IMAGE_NUMBEROF_DIRECTORY_ENTRIES - 3);
    //OptionalHeader->NumberOfRvaAndSizes = IMAGE_NUMBEROF_DIRECTORY_ENTRIES;
#endif

#if defined(CODE_IN_HEADERS)
    //
    // Besides the first field being the name, the second field is the size,
    // and the section only contains the import descriptor, and the import size
    // is the last field in the optional header, so we can overlap it too for
    // a further 4 byte savings.
    //
#ifndef RELOCATABLE
    Section = (IMAGE_SECTION_HEADER*) &OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT - 1].Size;
#else
    Section = (IMAGE_SECTION_HEADER*) &OptionalHeader->DataDirectory[OptionalHeader->NumberOfRvaAndSizes - 1];
#endif

#else

#ifndef OVERLAY_IMPORT_DESCRIPTOR_ON_OPTIONAL_HEADER
    // overlap section header and optional header for 8 byte savings
    // the first field is the name and it has no meaning
    //Section = (IMAGE_SECTION_HEADER*) &OptionalHeader->DataDirectory[OptionalHeader->NumberOfRvaAndSizes];
    Section = (IMAGE_SECTION_HEADER*) &OptionalHeader->DataDirectory[OptionalHeader->NumberOfRvaAndSizes - 1];
#else
    //Section = (IMAGE_SECTION_HEADER*) (((PBYTE) ImportDescriptors) + sizeof(*ImportDescriptors) * 2);
    //OptionalHeader->NumberOfRvaAndSizes = 5;
#endif
#endif

    FileHeader->SizeOfOptionalHeader = (ULONG) (((size_t) Section) - (size_t) OptionalHeader);
    OptionalHeader->SizeOfHeaders = (DOS_HEADER_SIZE + 4 + sizeof(IMAGE_FILE_HEADER) + FileHeader->SizeOfOptionalHeader + sizeof(IMAGE_SECTION_HEADER));

    Section->Misc.VirtualSize = sizeof(Data);
    //Section->Misc.VirtualSize = 0x2000;
    Section->SizeOfRawData = sizeof(Data);
    // not always needed, nets us more space to reuse maybe (a terminal nul for a string)
#ifndef CODE_IN_HEADERS // def LINK_DUMP_COMPATIBLE The code flag makes link /dump /disasm work.
    Section->Characteristics = (IMAGE_SCN_CNT_CODE | IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_MEM_READ | IMAGE_SCN_CNT_INITIALIZED_DATA);
#endif
    // sometimes needed (not)
    //Section->Characteristics |= IMAGE_SCN_CNT_UNINITIALIZED_DATA;
    Section->VirtualAddress = RoundUp(OptionalHeader->SizeOfHeaders, OptionalHeader->SectionAlignment);
    Section->PointerToRawData = RoundUp(OptionalHeader->SizeOfHeaders, OptionalHeader->FileAlignment);
    //Section->PointerToRawData = RoundUp((DOS_HEADER_SIZE + 4 + sizeof(IMAGE_FILE_HEADER)), OptionalHeader->FileAlignment);

    Dos->e_magic = IMAGE_DOS_SIGNATURE;
    Dos->e_lfanew = DOS_HEADER_SIZE;
    FileHeader->Machine = IMAGE_FILE_MACHINE_I386;
    FileHeader->NumberOfSections = 1;

    LastSection = (Section + FileHeader->NumberOfSections - 1);

    FileHeader->Characteristics = (IMAGE_FILE_EXECUTABLE_IMAGE | IMAGE_FILE_32BIT_MACHINE);
#ifdef MAKE_DLL
    FileHeader->Characteristics |= IMAGE_FILE_DLL;
#endif
#ifndef RELOCATABLE
    FileHeader->Characteristics |= IMAGE_FILE_RELOCS_STRIPPED;
#endif
    Nt->Signature = IMAGE_NT_SIGNATURE;

    OptionalHeader->Magic = IMAGE_NT_OPTIONAL_HDR_MAGIC;
    OptionalHeader->AddressOfEntryPoint = RVA(Data);

    // when overlaying import_descriptor onto optional_header, this is the name of the second descriptor and must be 0.?
    OptionalHeader->MajorOperatingSystemVersion = 4;
    OptionalHeader->MajorSubsystemVersion = 4;
    //OptionalHeader->MinorSubsystemVersion = 10;
    //OptionalHeader->DllCharacteristics = 0x400;
    OptionalHeader->Subsystem = IMAGE_SUBSYSTEM_WINDOWS_CUI;
    // not always/ever needed
#if 0
    OptionalHeader->BaseOfCode = OptionalHeader->SectionAlignment;
    OptionalHeader->BaseOfData = OptionalHeader->BaseOfCode;
    OptionalHeader->SizeOfCode = sizeof(Data);
    OptionalHeader->SizeOfInitializedData = sizeof(Data);
#endif
    OptionalHeader->SizeOfImage = RoundUp(LastSection->VirtualAddress + LastSection->Misc.VirtualSize, OptionalHeader->SectionAlignment);

    //OptionalHeader->SizeOfImage |= 0x12345678;
    //OptionalHeader->SizeOfImage |= 0x12345678;

#ifdef OVERLAY_IMPORT_DESCRIPTOR_ON_OPTIONAL_HEADER
    OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress = (DOS_HEADER_SIZE + 4 + sizeof(IMAGE_FILE_HEADER) + offsetof(IMAGE_OPTIONAL_HEADER, DataDirectory[IMAGE_DIRECTORY_ENTRY_RESOURCE]));
#else
    OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress = RVA(Data.ImportDescriptors);
#endif
    // size is redundant with the terminal null
    OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size = sizeof(IMAGE_IMPORT_DESCRIPTOR);
    //OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size = 1;

#ifdef RELOCATABLE
    OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress = RVA(Data.Relocs);
    OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].Size = sizeof(Data.Relocs);
#endif

#ifdef CODE_IN_HEADERS

    // we have 12 bytes here and then SizeOfOptionalHeader

    p = (PBYTE) &FileHeader->TimeDateStamp;

    // push hello

    *p++ = 0x68;
    va = (OptionalHeader->ImageBase + DOS_HEADER_SIZE + 4 + sizeof(IMAGE_FILE_HEADER) + offsetof(IMAGE_OPTIONAL_HEADER, BaseOfCode));
    memcpy(p, &va, sizeof(ULONG));    
    p += sizeof(ULONG);

    // mov eax, &__imp__puts

    *p++ = 0xB8;
    va = (OptionalHeader->ImageBase + DOS_HEADER_SIZE + 4 + sizeof(IMAGE_FILE_HEADER) + Header.Nt.FileHeader.SizeOfOptionalHeader + offsetof(IMAGE_SECTION_HEADER, PointerToRelocations));
    memcpy(p, &va, sizeof(ULONG));
    p += sizeof(ULONG);

    // near jmp into optional header

    *p++ = 0xEB; // jump
    OptionalHeader->AddressOfEntryPoint = (DOS_HEADER_SIZE + 4 + offsetof(IMAGE_FILE_HEADER, TimeDateStamp));
    va = (DOS_HEADER_SIZE + 4 + sizeof(IMAGE_FILE_HEADER) + offsetof(IMAGE_OPTIONAL_HEADER, Win32VersionValue) - OptionalHeader->AddressOfEntryPoint - 10 - 2);
    if (va > 128)
    {
        printf("near jump too far\n");
    }
    *p++ = (BYTE) va;

    //OptionalHeader->CheckSum = 0x9090;
    //OptionalHeader->Win32VersionValue = 0x9090;

    p = (PBYTE) &OptionalHeader->Win32VersionValue;

    // 16 bytes until subsystem
    // no constraints on Win32VersionValue, CheckSum
    // some constraints on SizeOfImage, SizeOfHeaders

    SizeOfImage = OptionalHeader->SizeOfImage;

    // call dword ptr [eax] (puts)

    *p++ = 0xFF;
    *p++ = 0x10;

    // push exit code (42)

    *p++ = 0x6A;
    *p++ = 42;

    // call exit

    *p++ = 0xFF;
    *p++ = 0x15;

    va = (OptionalHeader->ImageBase + DOS_HEADER_SIZE + 4 + sizeof(IMAGE_FILE_HEADER) + Header.Nt.FileHeader.SizeOfOptionalHeader + offsetof(IMAGE_SECTION_HEADER, PointerToLinenumbers));
    memcpy(p, &va, sizeof(ULONG));
    
    //
    // We overwrite SizeOfImage here and that is ok.
    // If we were to make it too small and the code doesn't occupy the high bits, we could
    // poke them bigger, possibly even with a branch to more code, but we are ok and done.
    //

    if (SizeOfImage > OptionalHeader->SizeOfImage)
    {
        printf("SizeOfImage error %lx vs. %lx\n", SizeOfImage, OptionalHeader->SizeOfImage);
    }

#else

#ifdef TAIL_CALL_AND_NO_RETURN
    Data.PushHello = 0x68;
#else
    Data.uFirstInstruction.PushHello = 0x68;
#endif

#ifndef REUSE_HEADERS
    memcpy(Data.Hello, VA(Data.String.Hello), sizeof(ULONG));
#else
    // hello is the section name
    va = (OptionalHeader->ImageBase + DOS_HEADER_SIZE + 4 + sizeof(IMAGE_FILE_HEADER) + Header.Nt.FileHeader.SizeOfOptionalHeader);
    memcpy(Data.Hello, &va, sizeof(ULONG));
#endif

#ifdef TAIL_CALL_AND_NO_RETURN
    Data.Jump_puts[0] = 0xFF;
    Data.Jump_puts[1] = 0x25;
#else
    Data.Call_puts[0] = 0xFF;
    Data.Call_puts[1] = 0x15;
#endif

#if !defined(REUSE_HEADERS) || defined(OVERLAY_IMPORT_DESCRIPTOR_ON_OPTIONAL_HEADER)
    memcpy(Data.puts, VA(Data.ImportAddresses.Msvcrt.puts), sizeof(ULONG));
#else
    // puts is in the in section header (msvcrt IAT)
    va = (OptionalHeader->ImageBase + DOS_HEADER_SIZE + 4 + sizeof(IMAGE_FILE_HEADER) + Header.Nt.FileHeader.SizeOfOptionalHeader + offsetof(IMAGE_SECTION_HEADER, PointerToRelocations));
    memcpy(Data.puts, &va, sizeof(ULONG));
#endif
#if defined(USE_TERMINATE_PROCESS) || defined(USE_EXIT)
#ifdef TAIL_CALL_AND_NO_RETURN
    Data.uFirstInstruction.PushExitCode = 0x6A;
#else
    Data.PushExitCode = 0x6A;
#endif
    Data.ExitCode = 42;
#ifdef USE_TERMINATE_PROCESS
    Data.CallGetCurrentProcess[0] = 0xFF;
    Data.CallGetCurrentProcess[1] = 0x15;
    memcpy(Data.GetCurrentProcess, VA(Data.ImportAddresses.Kernel32.GetCurrentProcess), sizeof(ULONG));
    Data.PushEax = 0x50;
    Data.CallTerminateProcess[0] = 0xFF;
    Data.CallTerminateProcess[1] = 0x15;
    memcpy(Data.TerminateProcess, VA(Data.ImportAddresses.Kernel32.TerminateProcess), sizeof(ULONG));
#endif
#ifdef USE_EXIT
#ifdef TAIL_CALL_AND_NO_RETURN
    Data.Push_exit[0] = 0xFF;
    Data.Push_exit[1] = 0x35;
#else
    Data.Call_exit[0] = 0xFF;
    Data.Call_exit[1] = 0x15;
#endif
#if !defined(REUSE_HEADERS) || defined(OVERLAY_IMPORT_DESCRIPTOR_ON_OPTIONAL_HEADER)
    memcpy(Data.exit, VA(Data.ImportAddresses.Msvcrt.exit), sizeof(ULONG));
#else
    // address in section header
    va = (OptionalHeader->ImageBase + DOS_HEADER_SIZE + 4 + sizeof(IMAGE_FILE_HEADER) + Header.Nt.FileHeader.SizeOfOptionalHeader + offsetof(IMAGE_SECTION_HEADER, PointerToLinenumbers));
    memcpy(Data.exit, &va, sizeof(ULONG));
#endif
#endif
#endif

#if !defined(USE_TERMINATE_PROCESS) && !defined(USE_EXIT)
    Data.PopEax = 0x58; // strip stack and for .dll return non-zero
#ifdef MAKE_DLL
    Data.RetC[0] = 0xc2;
    Data.RetC[1] = 0xc;
    Data.RetC[2] = 0;
#else
    Data.Ret = 0xc3;
#endif
#endif

#endif

    // import ImportDescriptors

#if !defined(REUSE_HEADERS) || defined(OVERLAY_IMPORT_DESCRIPTOR_ON_OPTIONAL_HEADER)
    ImportDescriptors[0].Name = RVA(Data.String.Msvcrt);
#else
    ImportDescriptors[0].Name = (DOS_HEADER_SIZE + 4 + sizeof(IMAGE_FILE_HEADER) + offsetof(IMAGE_OPTIONAL_HEADER, MajorLinkerVersion));
#endif

    FirstThunk = (DWORD*) &ImportDescriptors[0].FirstThunk;
#if !defined(REUSE_HEADERS) || defined(OVERLAY_IMPORT_DESCRIPTOR_ON_OPTIONAL_HEADER)
    *FirstThunk = RVA(Data.ImportAddresses.Msvcrt);
#else
    *FirstThunk = (DOS_HEADER_SIZE + 4 + sizeof(IMAGE_FILE_HEADER) + Header.Nt.FileHeader.SizeOfOptionalHeader + offsetof(IMAGE_SECTION_HEADER, PointerToRelocations));
#endif

#ifdef USE_TERMINATE_PROCESS
    FirstThunk = (DWORD*) &ImportDescriptors[1].FirstThunk;
    *FirstThunk = RVA(Data.ImportAddresses.Kernel32);

#ifndef REUSE_HEADERS
    ImportDescriptors[1].ImportNames = RVA(Data.String.Kernel32);
#else
    ImportDescriptors[1].ImportNames = (DOS_HEADER_SIZE + 4 + sizeof(IMAGE_FILE_HEADER) + offsetof(IMAGE_OPTIONAL_HEADER, SizeOfStackReserve));
#endif

#endif

    // ImportAddresseses, subtract 2 to leave room for an arbitrary and not necessarily aligned hint

#ifdef USE_EXIT
#if !defined(REUSE_HEADERS) || defined(OVERLAY_IMPORT_DESCRIPTOR_ON_OPTIONAL_HEADER)
    Data.ImportAddresses.Msvcrt.exit = (RVA(Data.String.exit) - 2);
    Data.ImportAddresses.Msvcrt.puts = (RVA(Data.String.puts) - 2);
#else
#if 0
    Data.ImportAddresses.Msvcrt.exit = (DOS_HEADER_SIZE + 4 + sizeof(IMAGE_FILE_HEADER) + offsetof(IMAGE_OPTIONAL_HEADER, MajorOperatingSystemVersion) - 2);
    // puts is at the start of the image, after mz, allowing two garbage bytes for the into, and avoid being 0
#if DOS_HEADER_SIZE >= 8
    Data.ImportAddresses.Msvcrt.puts = 1;
#else
    Data.ImportAddresses.Msvcrt.puts = (DOS_HEADER_SIZE + 4 + sizeof(IMAGE_FILE_HEADER) + offsetof(IMAGE_OPTIONAL_HEADER, MajorLinkerVersion) + sizeof("msvcrt") - 2);
#endif
#else
    Section->PointerToLinenumbers = (DOS_HEADER_SIZE + 4 + sizeof(IMAGE_FILE_HEADER) + offsetof(IMAGE_OPTIONAL_HEADER, MajorOperatingSystemVersion) - 2);
    // puts is at the start of the image, after mz, allowing two garbage bytes for the into, and avoid being 0
#if DOS_HEADER_SIZE >= 8
    Section->PointerToRelocations = 1;
#else
    Section->PointerToRelocations = (DOS_HEADER_SIZE + 4 + sizeof(IMAGE_FILE_HEADER) + offsetof(IMAGE_OPTIONAL_HEADER, MajorLinkerVersion) + sizeof("msvcrt") - 2);
#endif
#endif
#endif
#endif

#ifdef USE_TERMINATE_PROCESS
    Data.ImportAddresses.Kernel32.TerminateProcess = (RVA(Data.String.TerminateProcess) - 2);
    Data.ImportAddresses.Kernel32.GetCurrentProcess = (RVA(Data.String.GetCurrentProcess) - 2);
#endif

    // names

#ifdef OPTIMIZE_NOT_BINDABLE
    ImportDescriptors[0].OriginalFirstThunk = (DWORD) ImportDescriptors[0].FirstThunk;
#ifdef USE_TERMINATE_PROCESS
    ImportDescriptors[1].OriginalFirstThunk = (DWORD) ImportDescriptors[1].FirstThunk;
#endif
#else
    ImportDescriptors[0].OriginalFirstThunk = RVA(Data.ImportNames.Msvcrt);
#ifdef USE_TERMINATE_PROCESS
    ImportDescriptors[1].OriginalFirstThunk = RVA(Data.ImportNames.Kernel32);
#endif
    Data.ImportNames = Data.ImportAddresses;
#endif

    // strings

#ifdef USE_EXIT
#if !defined(REUSE_HEADERS) || defined(OVERLAY_IMPORT_DESCRIPTOR_ON_OPTIONAL_HEADER)
    memcpy(Data.String.exit, "exit", sizeof("exit")); // 5 bytes
#else
    memcpy(&OptionalHeader->MajorOperatingSystemVersion, "exit", sizeof("exit")); // 5 bytes
#endif
#endif

#if !defined(REUSE_HEADERS) || defined(OVERLAY_IMPORT_DESCRIPTOR_ON_OPTIONAL_HEADER)
    memcpy(Data.String.Msvcrt, "msvcrt", sizeof("msvcrt")); // 7 bytes
#else
    memcpy(&OptionalHeader->MajorLinkerVersion, "msvcrt", sizeof("msvcrt")); // 7 bytes
#endif

#ifdef USE_TERMINATE_PROCESS
    memcpy(Data.String.GetCurrentProcess, "GetCurrentProcess", sizeof("GetCurrentProcess")); // 18 bytes (plus 2 byte hint)
    memcpy(Data.String.TerminateProcess, "TerminateProcess", sizeof("TerminateProcess")); // 17 bytes (plus 2 byte hint)
#endif

#if !defined(REUSE_HEADERS) || defined(OVERLAY_IMPORT_DESCRIPTOR_ON_OPTIONAL_HEADER)

    memcpy(Data.String.puts, "puts", sizeof("puts")); // 5 bytes
#ifdef USE_TERMINATE_PROCESS
    memcpy(Data.String.Kernel32, "Kernel32", sizeof("Kernel32")); // 9 bytes
#endif
    memcpy(Data.String.Hello, "Hello", sizeof("Hello"));
 
#else

    memcpy(&OptionalHeader->BaseOfCode, "Hello", sizeof("Hello"));
#if DOS_HEADER_SIZE >= 8
    // puts is in the dos header (preceded by 2 byte hint, and not zero
    // budget here is 10 bytes when dos header was 0xc bytes, puts + hint + null is 7.
    memcpy((((PBYTE) Dos) + 3), "puts", sizeof("puts"));
#else // after msvcrt
    memcpy((((PBYTE) &OptionalHeader->MajorLinkerVersion) + sizeof("msvcrt")), "puts", sizeof("puts"));
#endif
#ifdef USE_TERMINATE_PROCESS
    memcpy(&OptionalHeader->SizeOfStackReserve, "Kernel32", sizeof("Kernel32")); // 9 bytes, 16 available
#endif
#endif

#ifdef USE_TERMINATE_PROCESS
    memcpy(Data.String.GetCurrentProcess, "GetCurrentProcess", sizeof("GetCurrentProcess")); // 18 bytes (plus 2 byte hint)
    memcpy(Data.String.TerminateProcess, "TerminateProcess", sizeof("TerminateProcess")); // 17 bytes (plus 2 byte hint)
#endif

    // relocs

#ifdef RELOCATABLE
    //
    // This depends on their being less than 4k of code.
    //
    Data.Relocs.Header.SizeOfBlock = sizeof(Data.Relocs);
#ifdef CODE_IN_HEADERS
    Data.Relocs.Header.VirtualAddress = (DOS_HEADER_SIZE + 4);
    Data.Relocs.Hello = ((IMAGE_REL_BASED_HIGHLOW << 12) | (offsetof(IMAGE_FILE_HEADER, TimeDateStamp) + 1));
    Data.Relocs.puts = ((IMAGE_REL_BASED_HIGHLOW << 12) | (offsetof(IMAGE_FILE_HEADER, TimeDateStamp) + 6));
    Data.Relocs.exit = ((IMAGE_REL_BASED_HIGHLOW << 12) | (sizeof(IMAGE_FILE_HEADER) + offsetof(IMAGE_OPTIONAL_HEADER, Win32VersionValue) + 6));
#else
    Data.Relocs.Header.VirtualAddress = RVA(Data.uFirstInstruction.FirstInstruction);
    Data.Relocs.Hello = ((IMAGE_REL_BASED_HIGHLOW << 12) | (Data.Hello - &Data.uFirstInstruction.FirstInstruction));
    Data.Relocs.puts = ((IMAGE_REL_BASED_HIGHLOW << 12) | (Data.puts - &Data.uFirstInstruction.FirstInstruction));
#ifdef USE_EXIT
    Data.Relocs.exit = ((IMAGE_REL_BASED_HIGHLOW << 12) | (Data.exit - &Data.uFirstInstruction.FirstInstruction));
#endif
#ifdef USE_TERMINATE_PROCESS
    Data.Relocs.GetCurrentProcess = ((IMAGE_REL_BASED_HIGHLOW << 12) | (Data.GetCurrentProcess - &Data.uFirstInstruction.FirstInstruction));
    Data.Relocs.TerminateProcess = ((IMAGE_REL_BASED_HIGHLOW << 12) | (Data.TerminateProcess - &Data.uFirstInstruction.FirstInstruction));
#endif
#endif
#endif

    // version resource?

#ifdef OMIT_TRAILING_ZEROS
    // link /dump doesn't like this but the loader is ok
    // this doesn't work small alignment unfortunately, so we currently bother storing 3 trailing zeros
    while ((Section->SizeOfRawData != 0) && (((PBYTE) &Data)[Section->SizeOfRawData - 1] == 0))
    {
        Section->SizeOfRawData -= 1;
    }
#endif

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

    //
    // section header ends with 4 ignored bytes and is followed by he code
    // move the code back 4 bytes to save them; this breaks disassembly
    //
    if (OptionalHeader->FileAlignment != 1)
    {
        FileAlignPadSize = (i % OptionalHeader->FileAlignment);
        if (FileAlignPadSize != 0)
        {
            FileAlignPadSize = (RoundUp(FileAlignPadSize, OptionalHeader->FileAlignment) - i);
            // nops in case we are moving code
            // into section header, but really should put code here, duh
            //. This turns out to be empty anyway in our smaller cases
            printf("%u bytes of padding for alignment\n", (unsigned) FileAlignPadSize);
            //memset(FileAlign, 0x90, FileAlignPadSize);
        }
    }

#ifndef CODE_IN_HEADERS

#ifndef LINK_DUMP_COMPATIBLE
    //
    // use the last, ignored, 4 byte field in the section header for code
    // and the padding, if there is any
    //
    CodeSizeBeforeSection = (FileAlignPadSize + sizeof(ULONG));
    memmove(&Section->Characteristics, &Data, sizeof(ULONG));
    memmove(FileAlign, (((PBYTE) &Data) + sizeof(ULONG)), FileAlignPadSize);
    memmove(&Data, (((PBYTE) &Data) + CodeSizeBeforeSection), (sizeof(Data) - CodeSizeBeforeSection));
    Section->SizeOfRawData -= CodeSizeBeforeSection;
    Section->Misc.VirtualSize -= CodeSizeBeforeSection;
    OptionalHeader->AddressOfEntryPoint -= CodeSizeBeforeSection;
    OptionalHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress -= CodeSizeBeforeSection;
#endif

#endif

#if 0
    fwrite(&Header, RoundUp(OptionalHeader->SizeOfHeaders, OptionalHeader->FileAlignment), 1, FileHandle);
#else
    i = 0;
#ifndef OMIT_DOS_HEADER
    j = sizeof(*Dos);
    fwrite(Dos, j, 1, FileHandle);
#ifdef OVERLAY_PE_AND_DOS_HEADER
    ((ULONG*)Nt)[14] = Dos->e_lfanew;
    fseek(FileHandle, Dos->e_lfanew, SEEK_SET);
#endif
#endif
    i = Dos->e_lfanew;
    j = (4 + sizeof(IMAGE_FILE_HEADER) + Header.Nt.FileHeader.SizeOfOptionalHeader);
    i += j;
    fwrite(Nt, j, 1, FileHandle);
    j = sizeof(*Section);
    fwrite(Section, j, 1, FileHandle);
    i += j;
    fwrite(&FileAlign, FileAlignPadSize, 1, FileHandle);
#endif

    fwrite(&Data, Section->SizeOfRawData, 1, FileHandle);

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
