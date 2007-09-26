
#include <stdio.h>

#if defined(_WIN32) || defined(WIN32)

#include <windows.h>
#include <winioctl.h>

int main(int argc, char** argv)
{
	unsigned __int64 Size1 = 0;
	unsigned __int64 Size2 = 0;
	unsigned __int64 Size3 = 0;
	unsigned __int64 Size4 = 0;

	if (argc != 2 || !argv[1])
	{
		fprintf(stderr, "invalid command line\n");
		exit(1);
	}

	{
		WIN32_FIND_DATA FindData = { 0 };
		HANDLE FindHandle = INVALID_HANDLE_VALUE;
		FindHandle = FindFirstFile(argv[1], &FindData);
		if (FindHandle == INVALID_HANDLE_VALUE)
		{
			printf("FindFirstFile failed with error %lu\n", GetLastError());
		}
		else
		{
			Size1 = ((((unsigned __int64)FindData.nFileSizeHigh) << 32) | FindData.nFileSizeLow);
			FindClose(FindHandle);
		}
	}

	{
		WIN32_FILE_ATTRIBUTE_DATA FileAttributeData = { 0 };
		if (!GetFileAttributesEx(argv[1], GetFileExInfoStandard, &FileAttributeData))
		{
			printf("GetFileAttributesEx failed with error %lu\n", GetLastError());
		}
		else
		{
			Size2 = ((((unsigned __int64)FileAttributeData.nFileSizeHigh) << 32) | FileAttributeData.nFileSizeLow);
		}
	}

	{
		HANDLE FileHandle = INVALID_HANDLE_VALUE;

		FileHandle = CreateFile(argv[1], GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		if (FileHandle == INVALID_HANDLE_VALUE)
		{
			printf("CreateFile failed with error %lu\n", GetLastError());
		}
		else
		{
			DWORD FileSizeHigh = 0;
			DWORD FileSizeLow = GetFileSize(FileHandle, &FileSizeHigh);
			if ((FileSizeLow == 0xFFFFffff) && (GetLastError() != NO_ERROR))
			{
				printf("GetFileSize failed with error %lu\n", GetLastError());
			}
			else
			{
				Size3 = ((((unsigned __int64)FileSizeHigh) << 32) | FileSizeLow);
			}

			{
				GET_LENGTH_INFORMATION LengthInfo = { 0 };
				DWORD BytesReturned = 0;

				if (!DeviceIoControl(FileHandle, IOCTL_DISK_GET_LENGTH_INFO, NULL, 0, &LengthInfo, sizeof(LengthInfo), &BytesReturned, NULL)
					|| (BytesReturned < sizeof(LengthInfo)))
				{
					printf("DeviceIoControl failed with error %lu\n", GetLastError());
				}
				else
				{
					Size4 = LengthInfo.Length.QuadPart;
				}
			}
			CloseHandle(FileHandle);
		}
	}

	printf("0x%I64x (%I64u)\n", Size1, Size1);
	printf("0x%I64x (%I64u)\n", Size2, Size2);
	printf("0x%I64x (%I64u)\n", Size3, Size3);
	printf("0x%I64x (%I64u)\n", Size4, Size4);

	return 0;
}

#else

#include <stdio.h>

int main(int argc, char** argv)
{
	unsigned long Size = 0;

	printf(
		"0x%08lx (%lu)\n",
		Size,
		Size
		);

	return 0;
}

#endif
