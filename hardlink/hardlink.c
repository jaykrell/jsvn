#include "..\jk_prefix.h"
#include <windows.h>

/* for use with older kernel32.lib, use LoadLibrary/GetProcAddress */
#ifndef DYNAMIC_LINK_CREATEHARDLINK
#define DYNAMIC_LINK_CREATEHARDLINK 0
#endif

#if DYNAMIC_LINK_CREATEHARDLINK
typedef BOOL (__stdcall * PFNCreateHardLinkW)(PCWSTR NewLink, PCWSTR ExistingFile, void* reserved);
#endif

long sizet_add(size_t a, size_t b, size_t* c)
{
    size_t result;
    long er = 0;

    result = (a + b);
    if ((result < a) || (result < b))
        result = er = -1;
    *c = result;
    return er;
}

long sizet_mult(size_t a, size_t b, size_t* c)
{
    size_t result;
    long er = 0;

    result = (a * b);

    if ((a >= 2) && (b >= 2))
    {
        if ((result < a) || (result < b))
            result = er = -1;
    }
    *c = result;
    return er;
}

PWSTR Quote(PWSTR a)
{
    size_t i;
    size_t Length;
    long er = 0;

    Length = wcslen(a);
    if (Length == 0)
        return a;
    if (a[0] == '"')
        return a;
    if (Length != 0 && a[Length - 1] == '"')
        return a;

    for (i = 0 ; i != Length ; ++i)
    {
        if (a[i] == ' ')
        {
            size_t AllocLength;
            size_t QuoteAllocLength;
            PWSTR b;

            AllocLength = ((Length + 1) * sizeof(WCHAR)); /* guaranteed no overflow */
            er = sizet_add(AllocLength, (2 * sizeof(WCHAR)), &QuoteAllocLength);
            if (er < 0)
                return 0;

            b = (PWSTR) malloc(QuoteAllocLength);
            if (b == NULL)
                return 0;

            memcpy(b + 1, a, (Length * sizeof(WCHAR)));
            b[0] = '"';
            b[Length + 1] = '"';
            b[Length + 2] = 0;
            return b;
        }
    }
    return a;
}

void
JGetWinGetVolumeInformation(
    PCWSTR RootPath,
    WinVolumeInformation_t* Info
    )
{
    BOOL Success;
    Success = GetVolumeInformationW(RootPath, Info->Name, JK_NUMBER_OF(Info->Name), &Info->SerialNumber,
        &Info->MaximumComponentLength, &Info->Flags, Info->FileSystemName, JK_NUMBER_OF(Info->FileSystemName));
    Info->Success = Success;
    if (Success)
        Info->Error = NO_ERROR;
    else
        Info->Error = GetLastError();
}

BOOL
JVolumeInformationEqual(
    const WinVolumeInformation_t* a
    const WinVolumeInformation_t* b
    )
{
    return ((a->Flags == b->Flags)
        && (a->SerialNumber == b->SerialNumber)
        && (a->MaximumComponentLength == b->MaximumComponentLength)
        && (wcscmp(a->Name, b->Name) == 0)
        && (wcscmp(a->FileSystemName, b->FileSystemName) == 0));
}

int Main(int argc, wchar_t** argv)
{
    DWORD Win32Error;
    BOOL Success;
    DWORD FileAttributes1 = { 0 };
    DWORD FileAttributes2 = { 0 };
    HANDLE FileHandle1 = { 0 };
    HANDLE FileHandle2 = { 0 };
    BOOL Exists1 = { 0 };
    BOOL Exists2 = { 0 };
    JWinVolumeInformation_t VolumeInfo1 = { 0 };
    JWinVolumeInformation_t VolumeInfo2 = { 0 };
#if DYNAMIC_LINK_CREATEHARDLINK
    HMODULE Kernel32;
    PFNCreateHardLinkW pfnCreateHardLinkW;
#else
    PFNCreateHardLinkW pfnCreateHardLinkW = CreateHardLinkW;
#endif
    BY_HANDLE_FILE_INFORMATION ByHandleFileInformation1 = { 0 };
    BY_HANDLE_FILE_INFORMATION ByHandleFileInformation2 = { 0 };
    PWSTR Qargv1 = { 0 };
    PWSTR Qargv2 = { 0 };
    
    if (argc != 3)
    {
        wprintf(L"usage: %l <existing file> <link>\n", argv[0]);
        return 1;
    }

#if DYNAMIC_LINK_CREATEHARDLINK
    Kernel32 = LoadLibraryW(L"Kernel32.dll");
    if (Kernel32 == NULL)
    {
        Win32Error = GetLastError();
        wprintf(L"failed LoadLibraryW(Kernel32.dll):%lu\n", Win32Error);
        return 1;
    }
    pfnCreateHardLinkW = (PFNCreateHardLinkW) GetProcAddress(Kernel32, "CreateHardLinkW");
    if (pfnCreateHardLinkW == NULL)
    {
        Win32Error = GetLastError();
        wprintf(L"failed GetProcAddress(CreateHardLinkW):%lu\n", Win32Error);
        return 1;
    }
#endif

    Qargv1 = Quote(argv[1]);
    Qargv2 = Quote(argv[2]);

    FileAttributes1 = GetFileAttributesW(argv[1]);
    if (FileAttributes1 != 0xFFFFffff)
    {
        if ((FileAttributes1 & FILE_ATTRIBUTE_DIRECTORY) != 0)
        {
            wprintf(L"ERROR: %ls is directory\n", Qargv1);
            return 1;
        }
        FileHandle1 = CreateFileW(argv[1], GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        if (FileHandle1 != INVALID_HANDLE_VALUE)
        {
            if (!GetFileInformationByHandle(FileHandle1, &ByHandleFileInformation1))
            {
                wprintf(L"ERROR: GetFileInformationByHandle %ls failed\n", Qargv1);
                return 1;
            }
            CloseHandle(FileHandle1);
            Exists1 = TRUE;
        }
    }

    FileAttributes2 = GetFileAttributesW(argv[2]);
    if (FileAttributes2 != 0xFFFFffff)
    {
        if ((FileAttributes2 & FILE_ATTRIBUTE_DIRECTORY) != 0)
        {
            wprintf(L"ERROR: %ls is directory\n", Qargv2);
            return 1;
        }
        FileHandle2 = CreateFileW(argv[2], GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        if (FileHandle2 != INVALID_HANDLE_VALUE)
        {
            if (!GetFileInformationByHandle(FileHandle2, &ByHandleFileInformation2))
            {
                wprintf(L"ERROR: GetFileInformationByHandle %ls failed\n", Qargv2);
                return 1;
            }
            CloseHandle(FileHandle2);
            Exists2 = TRUE;
        }
    }

    if ((!Exists1) && (!Exists2))
    {
        wprintf(L"ERROR: neither %ls nor %ls exists\n", Qargv1, Qargv2);
        return 1;
    }

    if ((FileHandle1 == INVALID_HANDLE_VALUE) && (FileHandle2 == INVALID_HANDLE_VALUE))
    {
        wprintf(L"ERROR: unable to open %ls nor %ls\n", Qargv1, Qargv2);
        return 1;
    }

    if (Exists1 && Exists2)
    {
        if ((ByHandleFileInformation1.nFileIndexLow == ByHandleFileInformation2.nFileIndexLow)
            && ByHandleFileInformation1.nFileIndexHigh == ByHandleFileInformation2.nFileIndexHigh)
        {
            wprintf(L"already linked: %ls %ls\n", Qargv1, Qargv2);
            return 0;
        }
        if ((ByHandleFileInformation1.nNumberOfLinks != 1)
            && (ByHandleFileInformation2.nNumberOfLinks != 1))
        {
            wprintf(L"ERROR: %ls %ls both exist and have multiple links\n", Qargv1, Qargv2);
            return 1;
        }
        if (ByHandleFileInformation1.dwVolumeSerialNumber != ByHandleFileInformation2.dwVolumeSerialNumber)
        {
            wprintf(L"ERROR: %ls %ls both exist and are on different volumes\n", Qargv1, Qargv2);
            return 1;
        }
    }

    JWinGetVolumeInformation(argv[1], &VolumeInfo1);
    JWinGetVolumeInformation(argv[2], &VolumeInfo2);

    if (!VolumeInfo1.Success)
    {
        wprintf(L"ERROR: GetVolumeInformation(%ls) failed with %lu\n", Qargv1, VolumeInfo1.Error);
        return 1;
    }

    if (!VolumeInfo2.Success)
    {
        wprintf(L"ERROR: GetVolumeInformation(%ls) failed with %lu\n", Qargv2, VolumeInfo2.Error);
        return 1;
    }

    if ((!Exists1) && Exists2)
    {
        PWSTR t;

        t = argv[2];
        argv[2] = argv[1];
        argv[1] = t;

        t = Qargv2;
        Qargv2 = Qargv1;
        Qargv1 = t;
    }
    else if (Exists1 && Exists2)
    {
        SetFileAttributesW(argv[2], 0);
        DeleteFileW(argv[2]);
        wprintf("del /f /a %ls\n", Qargv2);
    }

    Success = pfnCreateHardLinkW(argv[2], argv[1], 0);
    if (!Success)
    {
        Win32Error = GetLastError();
        wprintf(L"ERROR: failed CreateHardLink(%s, %s):%lu\n", Qargv2, Qargv1, Win32Error);
        return (Win32Error ? Win32Error : 1);
    }
    return 0;
}

void Entry()
{
    int argc;
    PWSTR* argv;
    int ExitCode;

    argv = CommandLineToArgvW(GetCommandLineW(), &argc);
    ExitCode = Main(argc, argv);
    LocalFree(argv);
    ExitProcess(ExitCode);
}
