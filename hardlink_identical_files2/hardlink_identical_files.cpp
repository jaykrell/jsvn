/*
cl /MD /Z7 /GX hardlink_identical_files.cpp /link /incremental:no


usage:
    hardlink_identical_files <directory>
    
Enumerate the current working directory and the specified directory, recursively.
Any files that have the same contents, print commands to delete one and hardlink it to the other.
*/

#ifdef _MSC_VER
#if (_MSC_VER < 1020)
#error Visual C++ < 4.2 not supported here (std::string does not work)
#endif
#endif

#include "..\jk_prefix.h"

#include <stdio.h>
#include <windows.h>
#include <string.h>
#if (_MSC_VER >= 1020) || defined(__WATCOMC__)
#include <set>
#include <vector>
#include <string>
typedef  BASIC_STRING1(wchar_t) stringW;
#else
#include <set.h>
#include <vector.h>
#include <bstring.h>
#include <function.h>
typedef  BASIC_STRING1(wchar_t) stringW;
#endif

#include <assert.h>

#pragma hdrstop

stringW Quote(const stringW& a)
{
    size_t const Length = a.length();
    if (Length == 0)
        return a;
    if (a[0] == '"')
        return a;
    if (Length != 0 && a[Length - 1] == '"')
        return a;

    for (size_t i = 0 ; i != Length ; ++i)
    {
        if (a[i] == ' ')
        {
            return (L"\"" + a + L"\"");
        }
    }
    return a;
}

stringW
FileAttributesToString(
    DWORD dw
    )
{
    stringW s;
    PCWSTR e = L""; /* empty */
    s += ((dw & FILE_ATTRIBUTE_READONLY) ? L"readonly" : e);
    s += ((dw & FILE_ATTRIBUTE_HIDDEN) ? L"hidden" : e);
    s += ((dw & FILE_ATTRIBUTE_SYSTEM) ? L"system" : e);
    s += ((dw & FILE_ATTRIBUTE_DIRECTORY) ? L"directory" : e);
    s += ((dw & FILE_ATTRIBUTE_ARCHIVE) ? L"archive" : e);
    s += ((dw & FILE_ATTRIBUTE_NORMAL) ? L"normal" : e);
    s += ((dw & FILE_ATTRIBUTE_TEMPORARY) ? L"temporary" : e);
    s += ((dw & FILE_ATTRIBUTE_COMPRESSED) ? L"compressed" : e);
    //s += ((dw & FILE_ATTRIBUTE_OFFLINE) ? L"offline" : e);
    return s;
}

struct FileInfo_t
{
    FileInfo_t()
    {
        Size.QuadPart = 0;
        FileId.QuadPart = 0;
        Attributes = 0;
        FileHandle = 0;
        HasHandleInformation = 0;
        HasFirstChunk = 0;
    }

    FileInfo_t(const FileInfo_t& Other)
    {
        this->Size = Other.Size;
        this->Path = Other.Path;
        this->FileId = Other.FileId;
        this->Attributes = Other.Attributes;
        FileHandle = 0;
        HasHandleInformation = 0;
        HasFirstChunk = 0;
        assert(Other.FileHandle == 0);
        assert(Other.HasFirstChunk == 0);
        assert(Other.HasHandleInformation == 0);
    }

    ~FileInfo_t() { Close(); }

    void Close()
    {
        HANDLE const h = FileHandle;
        FileHandle = NULL;
        if ((h != NULL) && (h != INVALID_HANDLE_VALUE))
            CloseHandle(h);
    }

    void Open()
    {
        HANDLE h = this->FileHandle;
        if ((h == NULL) || (h == INVALID_HANDLE_VALUE))
        {
            h = CreateFileW(this->Path.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            this->FileHandle = h;
            if (h != INVALID_HANDLE_VALUE)
            {
                if (!this->HasFirstChunk)
                {
                    DWORD BytesRead = 0;
                    if (ReadFile(h, &this->FirstChunk[0], sizeof(this->FirstChunk), &BytesRead, NULL))
                    {
                        this->HasFirstChunk = BytesRead;
                    }
                }
            }
        }
    }

    ULARGE_INTEGER Size;
    ULARGE_INTEGER FileId;
    DWORD Attributes;
    stringW Path;
    HANDLE FileHandle;
    BYTE FirstChunk[64];
    unsigned HasHandleInformation : 1;
    unsigned HasFirstChunk : 6; 
};

void
CollectHandleInformation(
    FileInfo_t& FileInfo
    )
{
    if (FileInfo.HasHandleInformation)
        return;

    FileInfo.Open();
    if (FileInfo.FileHandle == INVALID_HANDLE_VALUE)
    {
        wprintf(L"rem open %ls failed\n", FileInfo.Path.c_str());
    }
    else
    {
        BY_HANDLE_FILE_INFORMATION ByHandleFileInformation = { 0 };
        if (!GetFileInformationByHandle(FileInfo.FileHandle, &ByHandleFileInformation))
        {
            wprintf(L"rem GetFileInformationByHandle %ls failed\n", FileInfo.Path.c_str());
        }
        else
        {
            FileInfo.Size.HighPart = ByHandleFileInformation.nFileSizeHigh;
            FileInfo.Size.LowPart = ByHandleFileInformation.nFileSizeLow;
            FileInfo.Attributes = ByHandleFileInformation.dwFileAttributes;
            FileInfo.FileId.LowPart = ByHandleFileInformation.nFileIndexLow;
            FileInfo.FileId.HighPart = ByHandleFileInformation.nFileIndexHigh;
            // wprintf(L"rem %u %ls\n", __LINE__, FindData.cFileName);
            FileInfo.HasHandleInformation = TRUE;
        }
        FileInfo.Close();
    }
}

bool operator<(const FileInfo_t& a, const FileInfo_t& b)
{
    return (a.Path < b.Path);
}

void
CollectFiles(
    stringW Directory,
    SET1(FileInfo_t)& Files
    )
{
    WIN32_FIND_DATAW FindData = { 0 };
    Directory += L"\\";

    // wprintf(L"rem %u %c %ls %ls\n", __LINE__, (char) Directory[0], Directory.c_str(), FindData.cFileName);

    HANDLE FindHandle = FindFirstFileW((Directory + stringW(L"*")).c_str(), &FindData);
    // wprintf(L"rem %u %ls %ls %ls %p\n", __LINE__, Directory.c_str(), (Directory + stringW(L"*")).c_str(), FindData.cFileName, FindHandle);
    if (FindHandle != INVALID_HANDLE_VALUE)
    {
        // wprintf(L"rem %u %ls\n", __LINE__, FindData.cFileName);
        do
        {
            // wprintf(L"rem %u %ls\n", __LINE__, FindData.cFileName);
            if ((FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0)
            {
                if ((wcscmp(FindData.cFileName, L".") == 0)
                    || (wcscmp(FindData.cFileName, L"..") == 0))
                {
                    continue;
                }
                CollectFiles(Directory + FindData.cFileName, Files);
            }
            else
            {
                FileInfo_t FileInfo;
                FileInfo.Path = (Directory + FindData.cFileName);
                FileInfo.Size.HighPart = FindData.nFileSizeHigh;
                FileInfo.Size.LowPart = FindData.nFileSizeLow;
                FileInfo.Attributes = FindData.dwFileAttributes;
                Files.insert(Files.end(), FileInfo);
            }
        } while (FindNextFileW(FindHandle, &FindData));
        FindClose(FindHandle);
    }
}

void
HandleFilePair(
    FileInfo_t& File1,
    FileInfo_t& File2
    )
{
    if (0)
    {
Exit:
        File1.Close();
        File2.Close();
        return;
    }

    if (File1.Size.QuadPart != File2.Size.QuadPart)
    {
        // wprintf(L"rem %u %ls\n", __LINE__, File1.Path.c_str());
        goto Exit;
    }

    if (File1.Size.QuadPart == 0)
    {
        // wprintf(L"rem %u %ls\n", __LINE__, File1.Path.c_str());
        goto Exit;
    }

    UINT BufferSize = 0;

    if (sizeof(UINT) == 2)
    {
        BufferSize = (8 * 1024);
    }
    else
    {
        BufferSize = (1024 * 1024);
    }

    // wprintf(L"rem %u %ls %ls\n", __LINE__, File1.Path.c_str(), File2.Path.c_str());

    CollectHandleInformation(File1);
    CollectHandleInformation(File2);

    if (   (!File1.HasHandleInformation)
        || (!File2.HasHandleInformation)
        )
    {
        wprintf(L"rem ERROR\n");
        goto Exit;
    }

    if (File1.Path == File2.Path)
    {
        // wprintf(L"rem %u %ls\n", __LINE__, File1.Path.c_str());
        goto Exit;
    }

    if (File1.FileId.QuadPart == File2.FileId.QuadPart)
    {
        if (_wcsicmp(File1.Path.c_str(), File2.Path.c_str()) != 0)
        {
            stringW const QFile1 = Quote(File1.Path);
            stringW const QFile2 = Quote(File2.Path);
            wprintf(L"rem %ls %ls already linked\n", QFile1.c_str(), QFile2.c_str());
            wprintf(L"hardlink %ls %ls\n", QFile1.c_str(), QFile2.c_str());
        }
        goto Exit;
    }

    if (File1.HasFirstChunk && File2.HasFirstChunk)
    {
        if (File1.HasFirstChunk != File2.HasFirstChunk)
            goto Exit;
        if (memcmp(File1.FirstChunk, File2.FirstChunk, File1.HasFirstChunk) != 0)
            goto Exit;
    }

    File1.Open();
    File2.Open();

    HANDLE const FileHandle1 = File1.FileHandle;
    HANDLE const FileHandle2 = File2.FileHandle;

    if (   (!FileHandle1)
        || (!FileHandle2)
        || (SetFilePointer(FileHandle1, 0, NULL, FILE_BEGIN) == -1)
        || (SetFilePointer(FileHandle2, 0, NULL, FILE_BEGIN) == -1)
        )
    {
        wprintf(L"rem ERROR\n");
        goto Exit;
    }

    UINT64 BytesRemaining = File1.Size.QuadPart;

    if (BytesRemaining < BufferSize)
        BufferSize = (UINT) File1.Size.QuadPart;

    VECTOR1(BYTE) Buffer1;
    VECTOR1(BYTE) Buffer2;

    Buffer1 = VECTOR1(BYTE)(BufferSize);
    Buffer2 = VECTOR1(BYTE)(BufferSize);

    //wprintf(L"rem fc %ls %ls\n", File1.Path.c_str(), File2.Path.c_str());
    
    while (true)
    {
        ULONG BytesRead1 = 0;
        ULONG BytesRead2 = 0;

        if (BytesRemaining < BufferSize)
            BufferSize = (UINT) BytesRemaining;

        if (!ReadFile(FileHandle1, &Buffer1[0], BufferSize, &BytesRead1, NULL))
        {
            if (GetLastError() == ERROR_HANDLE_EOF)
                goto Exit;
        }
        if (!ReadFile(FileHandle2, &Buffer2[0], BufferSize, &BytesRead2, NULL))
        {
            if (GetLastError() == ERROR_HANDLE_EOF)
                goto Exit;
        }
        if (BytesRead1 != BytesRead2)
            goto Exit;
        if (memcmp(&Buffer1[0], &Buffer2[0], BytesRead1) != 0)
            goto Exit;
        if (BytesRead1 == 0)
            break;
    }

    stringW const QFile1 = Quote(File1.Path);
    stringW const QFile2 = Quote(File2.Path);

    if ((File1.Attributes & ~FILE_ATTRIBUTE_ARCHIVE) != (File2.Attributes & ~FILE_ATTRIBUTE_ARCHIVE))
    {
        wprintf(
            L"rem %ls and %ls the same except for attributes (0x%lx vs. 0x%lx, difference is 0x%lx) (%ls vs. %ls, difference is %ls)\n",
            QFile1.c_str(), 
            QFile2.c_str(),
            File1.Attributes,
            File2.Attributes,
            (File1.Attributes ^ File2.Attributes),
            FileAttributesToString(File1.Attributes).c_str(),
            FileAttributesToString(File2.Attributes).c_str(),
            FileAttributesToString((File1.Attributes ^ File2.Attributes)).c_str()
            );
        goto Exit;
    }
    
    //wprintf(L"fsutil hardlink create %ls %ls\n", File2.Path.c_str(), File1.Path.c_str());
    wprintf(L"hardlink %ls %ls\n", QFile1.c_str(), QFile2.c_str());
}

void
Main(
    int argc,
    wchar_t** argv
    )
{

    typedef SET1(FileInfo_t) Files_t;
    Files_t Files;
    size_t i = 1;

    while (argv[i])
    {
        CollectFiles(argv[i], Files);
        i += 1;
    }

    // wprintf(L"rem %u %u\n", __LINE__, (UINT) Files.size());

    for (Files_t::iterator i1 = Files.begin() ; i1 != Files.end() ; ++i1)
    {
        for (Files_t::iterator i2 = i1 ; i2 != Files.end() ; ++i2)
        {
            if (i1 != i2)
            {
                // working around const bugs in older STL here
                HandleFilePair((FileInfo_t&) *&*i1, (FileInfo_t&) *&*i2);
            }
        }
    }
}

extern "C"
int
__cdecl
wmain(
    int argc,
    wchar_t** argv
    )
{
    Main(argc, argv);
    return 0;
}
