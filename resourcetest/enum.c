/*
cl /W4 /WX /Zi enum.c
*/
#define UNICODE
#define _UNICODE
struct _CRYPT_PROVIDER_DATA;
struct _CRYPT_PROVIDER_DEFUSAGE;
struct _CRYPT_PROVIDER_PRIVDATA;
struct _CRYPT_PROVIDER_SGNR;
struct _RPC_ASYNC_STATE;
struct IRpcStubBuffer;
#define _CRT_SECURE_NO_DEPRECATE
#ifdef _MSC_VER
#pragma warning(disable:4100 4201)
#if (_MSC_VER <= 1100)
#pragma warning(disable:4057 4214 4514)
#endif
#if (_MSC_VER == 900)
#pragma warning(disable:4001 4209 4226 4705)
#endif
#endif
#include <windows.h>
#if (_MSC_VER == 900)
#pragma warning(disable:4001)
#endif
#include <imagehlp.h>
#include <stdio.h>
#ifndef __GNUC__
#pragma comment(lib, "imagehlp.lib")
#endif
#include <limits.h>
#define C_ASSERT(e) typedef char __C_ASSERT__[(e)?1:-1] /* compat with other headers */
#define MAXUSHORT ((USHORT) ~ (USHORT) 0)
#define NUMBER_OF(a) (sizeof(a) / sizeof((a)[0]))

#define INDENT (2)

PCWSTR
GetSpaces(
    size_t Count
    )
{
    static const WCHAR Spaces[] = {
L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',
L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',
L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',
L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',L' ',
        0
    };
    C_ASSERT(NUMBER_OF(Spaces) == 65);
    if (Count > (NUMBER_OF(Spaces) - 1))
        Count = (NUMBER_OF(Spaces) - 1);
    return (Spaces + NUMBER_OF(Spaces) - 1 - Count);
}

void
DumpResourceDirectory(
    BYTE* MappedFile,
    size_t Depth,
    IMAGE_RESOURCE_DIRECTORY* TopDirectory,
    IMAGE_RESOURCE_DIRECTORY* Directory
    );

void
DumpResourceDirectoryEntry(
    BYTE* MappedFile,
    size_t Depth,
    IMAGE_RESOURCE_DIRECTORY* TopDirectory,
    IMAGE_RESOURCE_DIRECTORY* ContainingDirectory,
    IMAGE_RESOURCE_DIRECTORY_ENTRY* Entry,
    size_t Index
    );

PWSTR
Uppercase(
    PCWSTR Id
    )
{
    size_t Length;
    PWSTR Dup;
    if (((size_t) Id) <= MAXUSHORT)
    {
        return (PWSTR) Id;
    }
    Length = ((wcslen(Id) + 1) * sizeof(WCHAR));
    Dup = (PWSTR) malloc(Length);
    CopyMemory(Dup, Id, Length);
#if 0 // try this either way -- no luck
    _wcsupr(Dup);
#endif
    return Dup;
}

PCWSTR
IdToString(
    PCWSTR Id,
    WCHAR Buffer[],
    size_t BufferSize
    )
{
    //wprintf(L"id:%p\n", Id);
    if (((size_t) Id) <= MAXUSHORT)
    {
        _snwprintf(Buffer, BufferSize, L"#%hx", (USHORT) (size_t) Id);
        Id = Buffer;
    }
    return Id;
}

BOOL
CALLBACK
EnumLangProc(
    HMODULE Module,
    PCWSTR Type,
    PCWSTR Name,
    WORD   Language,
    LONG   Param
    )
{
    WCHAR TypeBuffer[20];
    WCHAR NameBuffer[20];
    wprintf(
        L"module:%p type:%ls name:%ls lang:%x\n",
        Module,
        IdToString(Type, TypeBuffer, NUMBER_OF(TypeBuffer)),
        IdToString(Name, NameBuffer, NUMBER_OF(NameBuffer)),
        Language);
    return TRUE;
}

BOOL
CALLBACK
EnumNamesProc(
    HMODULE Module,
    PCWSTR Type,
    PWSTR Name,
    LONG Param
    )
{
    if (!EnumResourceLanguagesW(Module, Uppercase(Type), Uppercase(Name), EnumLangProc, 0))
    {
        DWORD Error = GetLastError();
        wprintf(L"EnumResourceLanguages failed %x\n", Error);
    }
    return TRUE;
}

BOOL
CALLBACK
EnumTypesProc(
    HMODULE Module,
    PWSTR Type,
    LONG Param
    )
{
    if (!EnumResourceNamesW(Module, Type = Uppercase(Type), EnumNamesProc, 0))
    {
        WCHAR Buffer[20];
        DWORD Error = GetLastError();
        wprintf(L"EnumResourceNames(%p, %x %ls) failed %x\n", Module, Type, IdToString(Type, Buffer, NUMBER_OF(Buffer)), Error);
    }
    return TRUE;
}

void
DumpResourceDirectoryEntry(
    BYTE* MappedFile,
    size_t Depth,
    IMAGE_RESOURCE_DIRECTORY* TopDirectory,
    IMAGE_RESOURCE_DIRECTORY* ContainingDirectory,
    IMAGE_RESOURCE_DIRECTORY_ENTRY* Entry,
    size_t Index
    )
{
    WCHAR Buffer[20];
    IMAGE_RESOURCE_DIR_STRING_U* String = { 0 };
    size_t Length = { 0 };
    PCWSTR Chars = { 0 };
    ULONG OffsetToDirectory = { 0 };
    ULONG DataIsDirectory = { 0 };

    if (Entry->Name > INT_MAX)
    {
        String = (IMAGE_RESOURCE_DIR_STRING_U*) ((Entry->Name & INT_MAX) + (BYTE*) TopDirectory);
        Chars = String->NameString;
        Length = String->Length;
    }
    else
    {
        Length = _snwprintf(Buffer, NUMBER_OF(Buffer), L"#%hx", Entry->Name);
        Chars = Buffer;
    }
    if (Length > INT_MAX)
        Length = INT_MAX;

    DataIsDirectory = (Entry->OffsetToData > INT_MAX);
    OffsetToDirectory = (Entry->OffsetToData & INT_MAX);

#if 0 // more verbose
    wprintf(
        L"%ls[%lx]:%p:%.*ls IsDirectory:%lx Offset:%lx\n",
        ((Depth != 0) ? GetSpaces(Depth * INDENT) : L"\n"),
        ((ULONG) Index),
        Entry,
        ((int) Length),
        Chars,
        (!! DataIsDirectory),
        OffsetToDirectory
        );
#else
    wprintf(
        L"%ls%.*ls\n",
        GetSpaces(Depth * INDENT),
        ((int) Length),
        Chars
        );
#endif
    if (DataIsDirectory)
    {
        DumpResourceDirectory(
            MappedFile,
            (Depth + 1),
            TopDirectory,
            (IMAGE_RESOURCE_DIRECTORY*) (OffsetToDirectory + (BYTE*) TopDirectory)
            );
    }
}

void
DumpResourceDirectory(
    BYTE* MappedFile,
    size_t Depth,
    IMAGE_RESOURCE_DIRECTORY* TopDirectory,
    IMAGE_RESOURCE_DIRECTORY* Directory
    )
{
    size_t const NumberOfNamedEntries = Directory->NumberOfNamedEntries;
    size_t const NumberOfIdEntries = Directory->NumberOfIdEntries;
    IMAGE_RESOURCE_DIRECTORY_ENTRY* Entries = (IMAGE_RESOURCE_DIRECTORY_ENTRY*) (1 + Directory);
    size_t i = { 0 };

    if (Directory->Characteristics
        | Directory->TimeDateStamp
        | (Directory->MajorVersion & ~4)
        | Directory->MinorVersion)
    { // more verbose
        wprintf(
            L"%lsDirectory:%p Characteristics:%x TimeDateStamp:%x MajorVersion:%x MinorVersion:%x Names:%x Ids:%x\n",
            GetSpaces(Depth * INDENT),
            Directory,
            Directory->Characteristics,
            Directory->TimeDateStamp,
            Directory->MajorVersion,
            Directory->MinorVersion,
            Directory->NumberOfNamedEntries,
            Directory->NumberOfIdEntries
            );
    }
    else
    {
#if 0 // more verbose
        wprintf(
            L"%lsDirectory:%p Names:%x Ids:%x\n",
            GetSpaces(Depth * INDENT),
            Directory,
            Directory->NumberOfNamedEntries,
            Directory->NumberOfIdEntries
            );
#endif
    }
    //Depth += 1;
    if (NumberOfNamedEntries != 0)
    {
#if 0 // more verbose
        if (NumberOfIdEntries != 0)
            wprintf(L"%lsNames\n", GetSpaces(Depth * INDENT));
#endif
        for (i = 0 ; i != NumberOfNamedEntries ; ++i)
        {
            DumpResourceDirectoryEntry(MappedFile, Depth, TopDirectory, Directory, &Entries[i], i);
        }
    }
    if (NumberOfIdEntries != 0)
    {
#if 0 // more verbose
        if (NumberOfNamedEntries != 0)
            wprintf(L"%lsIds\n", GetSpaces(Depth * INDENT));
#endif
        for (i = 0 ; i != NumberOfIdEntries ; ++i)
        {
            DumpResourceDirectoryEntry(MappedFile, Depth, TopDirectory, Directory, &Entries[i + NumberOfNamedEntries], i);
        }
    }
}

int wmain()
{
    HMODULE Module;
    HANDLE File = { 0 };
    BYTE* MappedFile = { 0 };
    BYTE* MappedFile_End = { 0 };
    HANDLE FileMapping = { 0 };
    ULARGE_INTEGER FileSize;
    DWORD Error = { 0 };
    IMAGE_NT_HEADERS* NtHeaders = { 0 };
    IMAGE_DOS_HEADER* DosHeader = { 0 };
    size_t OffsetToPE = { 0 };
    IMAGE_RESOURCE_DIRECTORY* TopDirectory = { 0 };
    ULONG ResourcesSize = { 0 };

    Module = LoadLibraryW(L".\\notepad.exe");
    if (!EnumResourceTypesW(Module, EnumTypesProc, 0))
    {
        DWORD Error = GetLastError();
        wprintf(L"EnumResourceTypes failed %x\n", Error);
    }
    FreeLibrary(Module);

    File = CreateFileW(L".\\notepad.exe", GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
    if (INVALID_HANDLE_VALUE == File)
    {
        Error = GetLastError();
        wprintf(L"CreateFile fails with error: %u", Error);
        goto Exit;
    }

    FileSize.LowPart = GetFileSize(File, &FileSize.HighPart);
    if ((FileSize.LowPart == -1) && ((Error = GetLastError()) != 0))
    {
        wprintf(L"GetFileSize failed with error %u\n", Error);
        goto Exit;
    }
    if (FileSize.HighPart != 0)
    {
        wprintf(L"file too large\n");
        goto Exit;
    }
    if (FileSize.QuadPart <= (sizeof(IMAGE_DOS_HEADER) + sizeof(IMAGE_NT_HEADERS)))
    {
        wprintf(L"file too small\n");
        goto Exit;
    }
    
    FileMapping = CreateFileMappingW(File, NULL, PAGE_READONLY, 0, 0, NULL);
    if (FileMapping == NULL)
    {
        Error = GetLastError();
        wprintf(L"CreateFileMapping fails with error: %u", Error);
        goto Exit;
    }

    MappedFile = (BYTE*) MapViewOfFile(FileMapping, FILE_MAP_READ, 0, 0, 0);
    if (MappedFile == NULL)
        goto Exit;

    wprintf(L"MappedFile:%p\n", MappedFile);
    MappedFile_End = (MappedFile + FileSize.QuadPart);
    DosHeader = (IMAGE_DOS_HEADER*) MappedFile;
    if (DosHeader->e_magic != IMAGE_DOS_SIGNATURE)
    {
        wprintf(L"invalid file");
        goto Exit;
    }

    OffsetToPE = DosHeader->e_lfanew;
    if (OffsetToPE >= FileSize.QuadPart)
    {
        wprintf(L"invalid file");
        goto Exit;
    }
    if ((OffsetToPE + sizeof(IMAGE_NT_HEADERS)) >= FileSize.QuadPart)
    {
        wprintf(L"invalid file");
        goto Exit;
    }
    NtHeaders = (IMAGE_NT_HEADERS*) (MappedFile + OffsetToPE);
    if (NtHeaders->Signature != IMAGE_NT_SIGNATURE)
    {
        wprintf(L"invalid file");
        goto Exit;
    }
    if (NtHeaders->OptionalHeader.Magic != IMAGE_NT_OPTIONAL_HDR_MAGIC)
    {
        wprintf(L"invalid file");
        goto Exit;
    }
    if (NtHeaders->OptionalHeader.NumberOfRvaAndSizes < IMAGE_DIRECTORY_ENTRY_RESOURCE)
    {
        wprintf(L"no resources");
        goto Exit;
    }
    if (NtHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_RESOURCE].VirtualAddress == 0)
    {
        wprintf(L"no resources");
        goto Exit;
    }
    if (NtHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_RESOURCE].Size == 0)
    {
        wprintf(L"no resources");
        goto Exit;
    }

    TopDirectory = (IMAGE_RESOURCE_DIRECTORY*) ImageDirectoryEntryToData(MappedFile, FALSE, IMAGE_DIRECTORY_ENTRY_RESOURCE, &ResourcesSize);
    if (TopDirectory == NULL)
    {
        wprintf(L"no resources");
        goto Exit;
    }
    DumpResourceDirectory(MappedFile, 0, TopDirectory, TopDirectory);
 
Exit:
    if (MappedFile != NULL)
        UnmapViewOfFile(MappedFile);

    if (FileMapping != NULL)
        CloseHandle(FileMapping);

    if ((File != NULL) && (File != INVALID_HANDLE_VALUE))
        CloseHandle(File);

    return 0;
}

#ifdef __GNUC__
int main()
{
    return wmain();
}
#endif
