/*
cl /MD /Z7 /GX symlink_to_hardlink.cpp /link /incremental:no

cd \cygwin\bin
symlnk_to_hardlink > 1.cmd
1.cmd


Discover Cygwin symlinks in the current working directory, delete them, and replace them with hard links to their target.
Take into account the default Cygwin mount points.

*/

#define NOMINMAX
#include <stdio.h>
#include <windows.h>
#include <vector>
using namespace std;
#pragma hdrstop

void
Main(
	void
	)
{
	DWORD BytesRead = 0;
	DWORD BytesToRead = 0;
	WIN32_FIND_DATAW FindData = { 0 };
	HANDLE FindHandle = 0;
	HANDLE FileHandle = 0;
	const char static Marker[] = {'!','<','s','y','m','l','i','n','k','>'}; // "!<symlink>"
	bool Bin = 0;
	ULONG Length = 0;
	vector<WCHAR> CurrentDirectory;
	char MarkerBuffer[sizeof(Marker)] = { 0 };
	vector<char> Target;

	Length = GetCurrentDirectoryW(0, NULL);
	if (Length > 5)
	{
		CurrentDirectory.resize(Length);
		Length = GetCurrentDirectoryW(Length, &CurrentDirectory[0]);
		if (Length == (CurrentDirectory.size() - 1))
		{
			Bin = (wcscmp(&CurrentDirectory[Length - 4], L"\\bin") == 0);
			if (Bin)
				;//wprintf(L"rem in bin directory\n");
		}
	}

	FindHandle = FindFirstFileW(L"*", &FindData);
	if (FindHandle != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (((FindData.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM) != 0)
				&& ((FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0)
				&& (FindData.nFileSizeHigh == 0)
				&& (FindData.nFileSizeLow > sizeof(Marker))
				)
			{
				FileHandle = CreateFileW(FindData.cFileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
				if (FileHandle != INVALID_HANDLE_VALUE)
				{
					BytesToRead = sizeof(Marker);
					if (ReadFile(FileHandle, &MarkerBuffer, BytesToRead, &BytesRead, NULL) && (BytesRead == BytesToRead))
					{
						if (memcmp(&MarkerBuffer, Marker, BytesRead) == 0)
						{
							BytesToRead = (FindData.nFileSizeLow - sizeof(Marker));
							Target.resize(BytesToRead);
							if (ReadFile(FileHandle, &Target[0], BytesToRead, &BytesRead, NULL) && (BytesRead == BytesToRead))
							{
								size_t i = 0;
								for ( i = 0 ; i != BytesRead ; ++i)
								{
									if (Target[i] == '/')
										Target[i] = '\\';
								}
								Target.push_back(0);
								FindData.dwFileAttributes = GetFileAttributesA(&Target[0]);
								if (FindData.dwFileAttributes == 0xFFFFffff)
								{
									if (Bin && (BytesRead > 3) && (memcmp(&Target[0], "..\\", 3) == 0))
									{
										const static char usr[] = {'u','s','r','\\'}; // "usr\\"
										Target.insert(Target.begin() + 3, usr, usr + sizeof(usr));
										FindData.dwFileAttributes = GetFileAttributesA(&Target[0]);
									}
								}
								if (FindData.dwFileAttributes != 0xFFFFffff)
								{
									if ((FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0)
									{
										wprintf(L"del /f /a /q %ls\n", FindData.cFileName);
										wprintf(L"fsutil hardlink create %ls %hs\n", FindData.cFileName, &Target[0]);
									}
								}
							}
						}
					}
					CloseHandle(FileHandle);
				}
			}
		} while(FindNextFileW(FindHandle, &FindData));
		FindClose(FindHandle);
	}
}

//
// We must have two functions here, an extern "C" and a non-extern "C", to workaround a compiler bug in Visual C++.
// Otherwise: c:\msdev50\VC\INCLUDE\vector(230) : error C2733: second C linkage of overloaded.
//
extern "C"
int
__cdecl
wmain(
	)
{
	Main();
	return 0;
}
