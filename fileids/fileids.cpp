/*
cl /MD /Z7 /GX fileids.cpp /link /incremental:no

In the current working directory, print the fileids and number of links of each file.
*/

#include <stdio.h>
#include <windows.h>
#pragma hdrstop

extern "C"
int
__cdecl
wmain(
	)
{
	BY_HANDLE_FILE_INFORMATION ByHandleFileInformation = { 0 };
	WIN32_FIND_DATAW FindData = { 0 };
	HANDLE FindHandle = 0;
	HANDLE FileHandle = 0;

	FindHandle = FindFirstFileW(L"*", &FindData);
	if (FindHandle != INVALID_HANDLE_VALUE)
	{
		do
		{
			FileHandle = CreateFileW(FindData.cFileName, FILE_READ_ATTRIBUTES, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
			if (FileHandle != INVALID_HANDLE_VALUE)
			{
				if (GetFileInformationByHandle(FileHandle, &ByHandleFileInformation))
				{
					wprintf(
						L"%ls FileId=0x%08lx%08lx NumberOfLinks=0x%08lx\n",
						FindData.cFileName,
						ByHandleFileInformation.nFileIndexHigh,
						ByHandleFileInformation.nFileIndexLow,
						ByHandleFileInformation.nNumberOfLinks
						);
				}
				CloseHandle(FileHandle);
			}
		} while(FindNextFileW(FindHandle, &FindData));
		FindClose(FindHandle);
	}
	return 0;
}
