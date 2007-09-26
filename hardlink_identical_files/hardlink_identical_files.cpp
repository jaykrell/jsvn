/*
cl /MD /Z7 /GX hardlink_identical_files.cpp /link /incremental:no


usage:
	hardlink_identical_files <directory>
	
Enumerate the current working directory and the specified directory, not recursively.
Any files that have the same contents, print commands to delete one and hardlink it to the other.
*/

#include "..\jk_prefix.h"
#include <stdio.h>
#include <windows.h>
#include <string.h>
#if (_MSC_VER >= 1020) || defined(__WATCOMC__)
#include <set>
#include <vector>
#include <string>
typedef  BASIC_STRING1(wchar_t) stringW;
#ifdef UNICODE
typedef  BASIC_STRING1(wchar_t) stringT;
#else
typedef  BASIC_STRING1(TCHAR) stringT;
#endif
#else
#include <set.h>
#include <vector.h>
#include <bstring.h>
#include <function.h>
typedef  BASIC_STRING1(wchar_t) stringW;
typedef  basic_string<TCHAR> stringT;
#endif
typedef const TCHAR* PCTSTR;

#pragma hdrstop

stringT
FileAttributesToString(
	DWORD dw
	)
{
	stringT s;
	PCTSTR e = TEXT(""); /* empty */
	s += ((dw & FILE_ATTRIBUTE_READONLY) ? TEXT("readonly") : e);
	s += ((dw & FILE_ATTRIBUTE_HIDDEN) ? TEXT("hidden") : e);
	s += ((dw & FILE_ATTRIBUTE_SYSTEM) ? TEXT("system") : e);
	s += ((dw & FILE_ATTRIBUTE_DIRECTORY) ? TEXT("directory") : e);
	s += ((dw & FILE_ATTRIBUTE_ARCHIVE) ? TEXT("archive") : e);
	s += ((dw & FILE_ATTRIBUTE_NORMAL) ? TEXT("normal") : e);
	s += ((dw & FILE_ATTRIBUTE_TEMPORARY) ? TEXT("temporary") : e);
	s += ((dw & FILE_ATTRIBUTE_COMPRESSED) ? TEXT("compressed") : e);
	//s += ((dw & FILE_ATTRIBUTE_OFFLINE) ? TEXT("offline") : e);
	return s;
}

struct FileInfo_t
{
	ULARGE_INTEGER Size;
	ULARGE_INTEGER FileId;
    DWORD          Attributes;
	stringW Path;
};

bool operator<(const FileInfo_t& a, const FileInfo_t& b)
{
	return (a.Path < b.Path);
}

void
Lowercase(
    PWSTR s
    )
{
    WCHAR ch;
    while ((ch = *s) != 0)
    {
        if (ch >= L'A' && ch <= L'Z')
        {
            ch = (WCHAR) (ch - L'A' + L'a');
            *s = ch;
        }
        s += 1;
    }
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
			if ((FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0)
			{
				stringW FilePath = (Directory + FindData.cFileName);
				HANDLE FileHandle = CreateFileW(FilePath.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
				if (FileHandle == INVALID_HANDLE_VALUE)
				{
					wprintf(L"rem open %ls failed\n", FilePath.c_str());
				}
				else
				{
					BY_HANDLE_FILE_INFORMATION ByHandleFileInformation = { 0 };
					if (!GetFileInformationByHandle(FileHandle, &ByHandleFileInformation))
					{
						wprintf(L"rem GetFileInformationByHandle %ls failed\n", FilePath.c_str());
					}
					else
					{
						FileInfo_t FileInfo;

						CloseHandle(FileHandle);

						FileInfo.Size.HighPart = ByHandleFileInformation.nFileSizeHigh;
						FileInfo.Size.LowPart = ByHandleFileInformation.nFileSizeLow;
						if (FileInfo.Size.QuadPart != 0)
						{
                            FileInfo.Attributes = ByHandleFileInformation.dwFileAttributes;
							FileInfo.Path = FilePath;
							FileInfo.FileId.LowPart = ByHandleFileInformation.nFileIndexLow;
							FileInfo.FileId.HighPart = ByHandleFileInformation.nFileIndexHigh;
							Files.insert(Files.end(), FileInfo);
							// wprintf(L"rem %u %ls\n", __LINE__, FindData.cFileName);
						}
					}
				}
			}
		} while (FindNextFileW(FindHandle, &FindData));
		FindClose(FindHandle);
	}
}

void
HandleFilePair(
	const FileInfo_t& File1,
	const FileInfo_t& File2
	)
{
	HANDLE FileHandle1 = INVALID_HANDLE_VALUE;
	HANDLE FileHandle2 = INVALID_HANDLE_VALUE;
	VECTOR1(BYTE) Buffer1;
	VECTOR1(BYTE) Buffer2;
	unsigned BufferSize = 0;
	ULONG BytesRead1 = 0;
	ULONG BytesRead2 = 0;

    if (sizeof(unsigned) == 2)
    {
        BufferSize = (4 * 1024);
    }
    else
    {
        BufferSize = (256 * 1024);
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

	if (File1.Path == File2.Path)
	{
		// wprintf(L"rem %u %ls\n", __LINE__, File1.Path.c_str());
		goto Exit;
	}

	// wprintf(L"rem %u %ls %ls\n", __LINE__, File1.Path.c_str(), File2.Path.c_str());

	if (File1.FileId.QuadPart == File2.FileId.QuadPart)
	{
		wprintf(L"rem %ls %ls already linked\n", File1.Path.c_str(), File2.Path.c_str());
		goto Exit;
	}

	FileHandle1 = CreateFileW(File1.Path.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (FileHandle1 == INVALID_HANDLE_VALUE)
	{
		wprintf(L"rem open %ls failed\n", File1.Path.c_str());
		goto Exit;
	}

	FileHandle2 = CreateFileW(File2.Path.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (FileHandle2 == INVALID_HANDLE_VALUE)
	{
		wprintf(L"rem open %ls failed\n", File2.Path.c_str());
		goto Exit;
	}

	Buffer1 = VECTOR1(BYTE)(BufferSize);
	Buffer2 = VECTOR1(BYTE)(BufferSize);
	
	while (true)
	{
		if (!ReadFile(FileHandle1, &Buffer1[0], BufferSize, &BytesRead1, NULL))
			if (GetLastError() == ERROR_HANDLE_EOF)
				goto Exit;
		if (!ReadFile(FileHandle2, &Buffer2[0], BufferSize, &BytesRead2, NULL))
			if (GetLastError() == ERROR_HANDLE_EOF)
				goto Exit;
		if (BytesRead1 != BytesRead2)
			goto Exit;
		if (memcmp(&Buffer1[0], &Buffer2[0], BytesRead1) != 0)
			goto Exit;
		if (BytesRead1 == 0)
			break;
	}

    if (File1.Attributes != File2.Attributes)
    {
	    wprintf(
			L"rem %ls and %ls the same except for attributes (0x%lx vs. 0x%lx) (%ls vs. %ls)\n",
			File1.Path.c_str(), 
			File2.Path.c_str(),
			File1.Attributes,
			File2.Attributes,
			FileAttributesToString(File1.Attributes).c_str(),
			FileAttributesToString(File2.Attributes).c_str()
			);
        goto Exit;
    }
	
    wprintf(L"del /f /a \"%ls\"\n", File2.Path.c_str());
    //wprintf(L"fsutil hardlink create %ls %ls\n", File2.Path.c_str(), File1.Path.c_str());
    wprintf(L"hardlink \"%ls\" \"%ls\"\n", File1.Path.c_str(), File2.Path.c_str());

Exit:
	if (FileHandle1 != INVALID_HANDLE_VALUE)
		CloseHandle(FileHandle1);
	if (FileHandle2 != INVALID_HANDLE_VALUE)
		CloseHandle(FileHandle2);
}

void
Main(
	int argc,
	wchar_t** argv
	)
{

	typedef SET1(FileInfo_t) Files_t;
	Files_t Files;
		
	ULONG Length = GetCurrentDirectoryW(0, NULL);
	if (Length < 2)
		exit(-__LINE__);
	VECTOR1(WCHAR) CurrentDirectory(Length);
	// wprintf(L"rem %u %u\n", __LINE__, (unsigned) CurrentDirectory.size());
	Length = GetCurrentDirectoryW(Length, &CurrentDirectory[0]);
	if (Length != (CurrentDirectory.size() - 1))
		exit(-__LINE__);

	// wprintf(L"rem %u %ls\n", __LINE__, &CurrentDirectory[0]);
	Lowercase(&CurrentDirectory[0]);
	// wprintf(L"rem %u %ls\n", __LINE__, &CurrentDirectory[0]);
	//stringW s;
	//s.assign(&CurrentDirectory[0]);
	// wprintf(L"rem %u %ls\n", __LINE__, s.c_str());
	CollectFiles(&CurrentDirectory[0], Files);

	if (argc == 2)
	{
		Lowercase(argv[1]);
		stringW arg1 = argv[1];
		if (arg1 != L"." && arg1 != &CurrentDirectory[0])
		{
			CollectFiles(stringW(&arg1[0]), Files);
		}
	}

	// wprintf(L"rem %u %u\n", __LINE__, (unsigned) Files.size());

	for (Files_t::const_iterator i1 = Files.begin() ; i1 != Files.end() ; ++i1)
	{
		for (Files_t::const_iterator i2 = i1 ; i2 != Files.end() ; ++i2)
		{
			if (i1 != i2)
				HandleFilePair(*i1, *i2);
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
