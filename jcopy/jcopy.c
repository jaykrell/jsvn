/*
Jay Krell 2007
for the nth time, a copy file program that accepts any paths and therefore devices
*/

#if defined(WIN32) && !defined(_WIN32)
#define _WIN32 1
#endif
#if defined(_WIN32) && !defined(WIN32)
#define WIN32 1
#endif

#if defined(_WIN32)
#define UNICODE 1
#define _UNICODE 1
#include <windows.h>
#include <tchar.h>
#else
#define _tmain main
#define _tremove remove
#define _tprintf printf
#define _tfopen fopen
#define TEXT(a) a
typedef char TCHAR;
#endif

#pragma warning(disable:4616) /* old compiler : warning number '4996' out of range, must be between '4001' and '4799' */
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_DEPRECATE
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <limits.h>
#include <dos.h>
#ifdef _WIN32
#define USE_WIN32_OPEN 1
#define USE_WIN32_READ 1
#include <io.h>
#include <fcntl.h>
#include <winioctl.h>
#define INVALID_SET_FILE_POINTER ((DWORD)-1)
#define FSCTL_ALLOW_EXTENDED_DASD_IO CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 32, METHOD_NEITHER,  FILE_ANY_ACCESS)
#endif
#if _MSC_VER
#pragma hdrstop
#endif

#ifdef _WIN32

#define FILE_SHARE_DELETE 0x00000004 /* old headers */

#if !defined(IOCTL_DISK_GET_LENGTH_INFO)

typedef struct _GET_LENGTH_INFORMATION {
    LARGE_INTEGER   Length;
} GET_LENGTH_INFORMATION, *PGET_LENGTH_INFORMATION;

#define IOCTL_DISK_GET_LENGTH_INFO CTL_CODE(IOCTL_DISK_BASE, 0x0017, METHOD_BUFFERED, FILE_READ_ACCESS)

#endif

typedef LPCTSTR PCTSTR;

typedef struct _JK_WIN32_FILE_SIZES
{
	unsigned __int64 Sizes[4];
} JK_WIN32_FILE_SIZES;

#ifdef _WIN32
PCTSTR
FormatWin32Error(
    DWORD Win32Error
    )
{
    static TCHAR Buffer[1024];
    size_t i;
    TCHAR ch;
    
    ZeroMemory(Buffer, sizeof(Buffer));
    FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL, Win32Error, 0, Buffer, 1024, NULL);
    i = _tcslen(Buffer);
    while (i != 0 && (((ch = Buffer[i - 1]) == ' ') || (ch == '\r') || (ch == '\n') || (ch == '\t')))
    {
        i -= 1;
    }
    Buffer[i] = 0;
    return Buffer;
}
#endif

void
JkGetWin32FileSizes(
	PCTSTR FilePath,
	JK_WIN32_FILE_SIZES* Sizes
	)
{
	const static char Function[] = "JkGetWin32FileSizes";
    DWORD Win32Error = NO_ERROR;

	ZeroMemory(Sizes, sizeof(*Sizes));

	{
		WIN32_FIND_DATA FindData = { 0 };
		HANDLE FindHandle = INVALID_HANDLE_VALUE;
		FindHandle = FindFirstFile(FilePath, &FindData);
		if (FindHandle == INVALID_HANDLE_VALUE)
		{
			Win32Error = GetLastError();
			_tprintf(TEXT("FindFirstFile(%s) failed with error %lu (%s)\n"), FilePath, Win32Error, FormatWin32Error(Win32Error));
		}
		else
		{
			Sizes->Sizes[0] = ((((unsigned __int64)FindData.nFileSizeHigh) << 32) | FindData.nFileSizeLow);
			FindClose(FindHandle);
		}
	}

#ifdef GetFileAttributesEx
	{
		WIN32_FILE_ATTRIBUTE_DATA FileAttributeData = { 0 };
		if (!GetFileAttributesEx(FilePath, GetFileExInfoStandard, &FileAttributeData))
		{
			Win32Error = GetLastError();
			_tprintf(TEXT("GetFileAttributesEx(%s) failed with error %lu (%s)\n"), FilePath, Win32Error, FormatWin32Error(Win32Error));
		}
		else
		{
			Sizes->Sizes[1] = ((((unsigned __int64)FileAttributeData.nFileSizeHigh) << 32) | FileAttributeData.nFileSizeLow);
		}
	}
#endif

	{
		HANDLE FileHandle = INVALID_HANDLE_VALUE;

		FileHandle = CreateFile(FilePath, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		if (FileHandle == INVALID_HANDLE_VALUE)
		{
			Win32Error = GetLastError();
			_tprintf(TEXT("CreateFile(%s) failed with error %lu (%s)\n"), FilePath, Win32Error, FormatWin32Error(Win32Error));
		}
		else
		{
			DWORD FileSizeHigh = 0;
			DWORD FileSizeLow = GetFileSize(FileHandle, &FileSizeHigh);
			if ((FileSizeLow == 0xFFFFffff) && (GetLastError() != NO_ERROR))
			{
			    Win32Error = GetLastError();
				_tprintf(TEXT("GetFileSize failed with error %lu (%s)\n"), Win32Error, FormatWin32Error(Win32Error));
			}
			else
			{
				Sizes->Sizes[2] = ((((unsigned __int64)FileSizeHigh) << 32) | FileSizeLow);
			}

			{
				GET_LENGTH_INFORMATION LengthInfo = { 0 };
				DWORD BytesReturned = 0;

				if (!DeviceIoControl(FileHandle, IOCTL_DISK_GET_LENGTH_INFO, NULL, 0, &LengthInfo, sizeof(LengthInfo), &BytesReturned, NULL)
					|| (BytesReturned < sizeof(LengthInfo)))
				{
			        Win32Error = GetLastError();
					_tprintf(TEXT("DeviceIoControl(IOCTL_DISK_GET_LENGTH_INFO) failed with error %lu (%s)\n"), Win32Error, FormatWin32Error(Win32Error));
				}
				else
				{
					Sizes->Sizes[3] = LengthInfo.Length.QuadPart;
				}
			}
			CloseHandle(FileHandle);
		}
	}

	_tprintf(TEXT("%hs: 0x%I64x (%I64u)\n"), Function, Sizes->Sizes[0], Sizes->Sizes[0]);
	_tprintf(TEXT("%hs: 0x%I64x (%I64u)\n"), Function, Sizes->Sizes[1], Sizes->Sizes[1]);
	_tprintf(TEXT("%hs: 0x%I64x (%I64u)\n"), Function, Sizes->Sizes[2], Sizes->Sizes[2]);
	_tprintf(TEXT("%hs: 0x%I64x (%I64u)\n"), Function, Sizes->Sizes[3], Sizes->Sizes[3]);
}

#endif

void
AllocateLargeBuffers(
    size_t SuggestedSize,
	size_t NumberOfBuffers,
    size_t* ActualSize,
	void** Buffers
    )
{
    void* p = 0;
	size_t i = 0;

    *ActualSize = 0;
	for (i = 0 ; i != NumberOfBuffers ; ++i)
	{
		Buffers[i] = NULL;
	}

	/* shrink until it fits in a size_t */

    while ((SuggestedSize * NumberOfBuffers) != (size_t) (SuggestedSize * NumberOfBuffers))
        SuggestedSize /= 2;

	/* shrink until we can get that much memory */

#if 1 && defined(_WIN32)
    while ((SuggestedSize != 0) && !(p = VirtualAlloc(0, (SuggestedSize * NumberOfBuffers), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE)))
        SuggestedSize /= 2;
#else
    while ((SuggestedSize != 0) && !(p = malloc(SuggestedSize * NumberOfBuffers)))
        SuggestedSize /= 2;
#endif

	if (p != NULL)
	{
		for (i = 0 ; i != NumberOfBuffers ; ++i)
		{
			Buffers[i] = (void*) (((size_t) p) + (i * SuggestedSize));
			_tprintf(TEXT("AllocateLargeBuffers:%p\n"), Buffers[i]);
		}
		_tprintf(TEXT("AllocateLargeBuffers:size = 0x%lx (%lu)\n"), (unsigned long) SuggestedSize, (unsigned long) SuggestedSize);
		*ActualSize = SuggestedSize;
	}
}

size_t j_select_sizet(unsigned short a, unsigned long b)
{
    if (sizeof(size_t) == sizeof(unsigned short))
        return a;
    return b;
}

void j_sleep(unsigned a)
{
#ifdef _WIN32
    Sleep(a);
#else
    sleep(a / 10);
#endif
}

int _tmain(int argc, TCHAR** argv)
{
    FILE* FileHandle1 = 0;
    FILE* FileHandle2 = 0;
    /* rotate through buffers to try to isolate problem */
    void* Buffers[3] = { 0 };
    size_t NumberOfBuffers = (sizeof(Buffers)/sizeof(Buffers[0]));
    unsigned long Offset = 0;
    size_t BufferSize = 0;
    size_t NumberOfErrors = 0;
    int ExitCode = EXIT_FAILURE;
    size_t i = 0;
    int a = -1, b = -2, c = -3, d = -4, e = -5;
#ifdef _WIN32
	HANDLE ProcessHeap = NULL;
	DWORD BytesReturned = 0;
	HANDLE Win32FileHandle1 = INVALID_HANDLE_VALUE;
	HANDLE Win32FileHandle2 = INVALID_HANDLE_VALUE;
	int UnixFileHandle1 = -1;
    DWORD BytesRead = 0;
	DWORD dwBytesWritten = 0;
    DWORD BytesRead2 = 0;
    DWORD BytesRead3 = 0;
    BOOL ReadFileResult = FALSE;
	SYSTEM_INFO SystemInfo = { 0 };
	DWORD Win32Error = 0;
#else
    size_t BytesRead = 0;
    size_t BytesRead2 = 0;
    size_t BytesRead3 = 0;
#endif
	int Done = 0;
    size_t BytesWritten = 0;

    _tprintf(TEXT("sizeof(size_t) is %u\n"), (unsigned) sizeof(size_t));
    //BufferSize = j_select_sizet(32 * 1024, 1UL << 31);
    BufferSize = j_select_sizet(32 * 1024, 1024UL * 1024UL * 32);
    //BufferSize = j_select_sizet(32 * 1024, 64UL * 1024UL);
    //BufferSize = 512;
    errno = 0;

    if (!argv[1])
    {
        e = -__LINE__;
        goto Exit;
    }
    if (!argv[2])
    {
        e = -__LINE__;
        goto Exit;
    }

#ifdef _WIN32
	/* attempt to do one ReadFile and one WriteFile -- for files smaller than 4gig that fit in memory
	any error here falls back to older code
	*/
	{
		JK_WIN32_FILE_SIZES Sizes = { 0 };
		DWORD Size = 0;
		DWORD ResidualSize = 0;
		HANDLE Win32FileMapping = 0;
		PVOID Win32MappedView = 0;

		GetSystemInfo(&SystemInfo);
		_tprintf(TEXT("dwAllocationGranularity 0x%lx\n"), SystemInfo.dwAllocationGranularity);

		Win32FileHandle1 = CreateFile(argv[1], GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		if (Win32FileHandle1 == INVALID_HANDLE_VALUE)
		{
			Win32Error = GetLastError();
			_tprintf(TEXT("CreateFile(%s) failed with %lu (%s)\n"), argv[1], Win32Error, FormatWin32Error(Win32Error));
			goto Fallback;
		}
		_tprintf(TEXT("got CreateFile(%s) (1)\n"), argv[1]);
		Win32FileHandle2 = CreateFile(argv[2], GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		if (Win32FileHandle2 == INVALID_HANDLE_VALUE)
		{
			Win32Error = GetLastError();
			_tprintf(TEXT("CreateFile(%s) failed with %lu (%s)\n"), argv[2], Win32Error, FormatWin32Error(Win32Error));
			goto Fallback;
		}
		_tprintf(TEXT("got CreateFile(%s) (2)\n"), argv[2]);

		if (!SetEndOfFile(Win32FileHandle2))
		{
			Win32Error = GetLastError();
			_tprintf(TEXT("SetEndOfFile(%s) failed with %lu (%s)\n"), argv[2], Win32Error, FormatWin32Error(Win32Error));
			goto Fallback;
		}
	
		/* measure the file size in multiple ways, only proceed if they are the same (or zero) */

		JkGetWin32FileSizes(argv[1], &Sizes);

		for (i = 0 ; i != sizeof(Sizes.Sizes) / sizeof(Sizes.Sizes[0]) ; ++i)
		{
			if (Sizes.Sizes[i] != 0)
			{
				if (Size == 0)
				{
					if (((Sizes.Sizes[i] != (DWORD) Sizes.Sizes[i])) || (Sizes.Sizes[i] > ~ (DWORD) 0))
					{
						_tprintf(TEXT("larger than DWORD %s\n"), argv[1]);
						goto Fallback;
					}
					Size = Sizes.Sizes[i];
					_tprintf(TEXT("got size 0x%lx\n"), Size);
				}
				else
				{
					if (Size != Sizes.Sizes[i])
					{
						_tprintf(TEXT("varying sizes for %s\n"), argv[1]);
						goto Fallback;
					}
				}
			}
		}
		if (Size == 0)
		{
			_tprintf(TEXT("got no size %s\n"), argv[1]);
			goto Fallback;
		}

		Win32FileMapping = CreateFileMapping(Win32FileHandle1, NULL, PAGE_READONLY, 0, 0, NULL);
		if (Win32FileMapping == NULL)
		{
			Win32Error = GetLastError();
			_tprintf(TEXT("CreateFileMapping failed with error %lu (%s) (ok)\n"), Win32Error, FormatWin32Error(Win32Error));
			goto BufferedIo;
		}
		else
		{
			Win32MappedView = MapViewOfFile(Win32FileMapping, FILE_MAP_READ, 0, 0, 0);
		}

BufferedIo:
		if (Win32FileMapping != NULL)
			CloseHandle(Win32FileMapping);

		if (Win32MappedView != NULL)
			UnmapViewOfFile(Win32MappedView);

		Win32FileMapping = NULL;
		Win32MappedView = NULL;

#if 1 && defined(_WIN32)
		Buffers[0] = VirtualAlloc(0, Size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#else
		Buffers[0] = malloc(Size);
#endif
		if (Buffers[0] == NULL)
		{
			_tprintf(TEXT("too big for memory %s\n"), argv[1]);
			goto Fallback;
		}
		_tprintf(TEXT("got VirtualAlloc\n"));
		ResidualSize = (Size & 0xFFFFFFF);
		Size &= ~ (DWORD) 0xFFFFFFF;

		if (!ReadFile(Win32FileHandle1, Buffers[0], Size, &BytesRead, NULL))
		{
			Win32Error = GetLastError();
			_tprintf(TEXT("ReadFile(0x%lx (%lu)) failed with %lu (%s)\n"), Size, Size, Win32Error, FormatWin32Error(Win32Error));
			goto Fallback;
		}
		Win32Error = GetLastError();
		_tprintf(TEXT("got ReadFile (1)\n"));
		if (Size != BytesRead)
		{
			Win32Error = GetLastError();
			_tprintf(TEXT("ReadFile failed to read all the bytes %lu (%s)\n"), Win32Error, FormatWin32Error(Win32Error));
			goto Fallback;
		}
		_tprintf(TEXT("got ReadFile (2)\n"));
		if (!WriteFile(Win32FileHandle2, Buffers[0], Size, &dwBytesWritten, NULL))
		{
			Win32Error = GetLastError();
			_tprintf(TEXT("WriteFile failed with %lu (%s)\n"), Win32Error, FormatWin32Error(Win32Error));
			goto Fallback;
		}
		_tprintf(TEXT("got WriteFle (1)\n"));
		if (Size != dwBytesWritten)
		{
			Win32Error = GetLastError();
			_tprintf(TEXT("WriteFile failed to read all the bytes (%lu %s)\n"), Win32Error, FormatWin32Error(Win32Error));
			goto Fallback;
		}

		if (ResidualSize != 0)
		{
			if (!ReadFile(Win32FileHandle1, Buffers[0], ResidualSize, &BytesRead, NULL))
			{
				Win32Error = GetLastError();
				_tprintf(TEXT("ReadFile failed with %lu (%s)\n"), Win32Error, FormatWin32Error(Win32Error));
				goto Fallback;
			}
			_tprintf(TEXT("got ReadFile (3)\n"));
			if (ResidualSize != BytesRead)
			{
				Win32Error = GetLastError();
				_tprintf(TEXT("ReadFile failed to read all the bytes (%lu %s)\n"), Win32Error, FormatWin32Error(Win32Error));
				goto Fallback;
			}
			_tprintf(TEXT("got ReadFile (4)\n"));
			if (!WriteFile(Win32FileHandle2, Buffers[0], ResidualSize, &dwBytesWritten, NULL))
			{
				Win32Error = GetLastError();
				_tprintf(TEXT("WriteFile failed with %lu (%s)\n"), Win32Error, FormatWin32Error(Win32Error));
				goto Fallback;
			}
			_tprintf(TEXT("got WriteFle (2)\n"));
			if (ResidualSize != dwBytesWritten)
			{
				Win32Error = GetLastError();
				_tprintf(TEXT("WriteFile failed to read all the bytes (0x%lx %s)\n"), Win32Error, FormatWin32Error(Win32Error));
				goto Fallback;
			}
		}

		Size += ResidualSize;
		_tprintf(TEXT("Successfully copied 0x%lx (%lu) bytes\n"), Size, Size);
		goto Exit;
	}

Fallback:
	if (Buffers[0] != NULL)
	{
#if 1 && defined(_WIN32)
		VirtualFree(Buffers[0], 0, MEM_RELEASE);
#else
		free(Buffers[0]);
#endif
		Buffers[0] = NULL;
	}
	if (Win32FileHandle1 != INVALID_HANDLE_VALUE)
	{
		CloseHandle(Win32FileHandle1);
		Win32FileHandle1 = INVALID_HANDLE_VALUE;
	}
	if (Win32FileHandle2 != INVALID_HANDLE_VALUE)
	{
		CloseHandle(Win32FileHandle2);
		Win32FileHandle2 = INVALID_HANDLE_VALUE;
	}

#endif

#if USE_WIN32_OPEN
	Win32FileHandle1 = CreateFile(argv[1], GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (Win32FileHandle1 == INVALID_HANDLE_VALUE)
    {
        e = -__LINE__;
        _tprintf(TEXT("failed to open %s (%d, %hs)\n"), argv[1], errno, strerror(errno));
        goto Exit;
    }
	DeviceIoControl(Win32FileHandle1, FSCTL_ALLOW_EXTENDED_DASD_IO, NULL, 0, NULL, 0, &BytesReturned, NULL);
#if !USE_WIN32_READ
	UnixFileHandle1 = _open_osfhandle((size_t) Win32FileHandle1, _O_RDONLY | _O_BINARY);
	if (UnixFileHandle1 == -1)
    {
        e = -__LINE__;
        _tprintf(TEXT("failed to open %s (%d, %hs)\n"), argv[1], errno, strerror(errno));
		goto Exit;
    }
	Win32FileHandle1 = INVALID_HANDLE_VALUE;
    FileHandle1 = _fdopen(UnixFileHandle1, "rb");
    if (FileHandle1 == NULL)
    {
        e = -__LINE__;
        _tprintf(TEXT("failed to open %s (%d, %hs)\n"), argv[1], errno, strerror(errno));
		goto Exit;
    }
	UnixFileHandle1 = -1;
#endif
#else
    FileHandle1 = _tfopen(argv[1], TEXT("rb"));
    if (FileHandle1 == NULL)
    {
        e = -__LINE__;
        _tprintf(TEXT("failed to open %s (%d, %hs)\n"), argv[1], errno, strerror(errno));
		goto Exit;
    }
#endif

    _tremove(argv[2]);

    FileHandle2 = _tfopen(argv[2], TEXT("w+b"));
    if (FileHandle2 == NULL)
    {
        FileHandle2 = _tfopen(argv[2], TEXT("r+b"));
    }
    if (FileHandle2 == NULL)
    {
        e = -__LINE__;
        _tprintf(TEXT("failed to open %s (%d, %hs)\n"), argv[2], errno, strerror(errno));
        goto Exit;
    }

#ifdef _WIN32
#if !USE_WIN32_OPEN
	DeviceIoControl((HANDLE) _get_osfhandle(_fileno(FileHandle1)), FSCTL_ALLOW_EXTENDED_DASD_IO, NULL, 0, NULL, 0, &BytesReturned, NULL);
#endif
    DeviceIoControl((HANDLE) _get_osfhandle(_fileno(FileHandle2)), FSCTL_ALLOW_EXTENDED_DASD_IO, NULL, 0, NULL, 0, &BytesReturned, NULL);
#endif
	AllocateLargeBuffers(BufferSize, NumberOfBuffers, &BufferSize, Buffers);
    if (Buffers[0] == NULL)
    {
        _tprintf(TEXT("insufficient memory\n"));
        goto Exit;
    }
    i = 0;
Retry2:
#if USE_WIN32_READ
    while (1)
#else
    while ((BytesRead = fread(Buffers[i % NumberOfBuffers], 1, BufferSize, FileHandle1)) > 0)
#endif
	{
#if USE_WIN32_READ
		Win32Error = NO_ERROR;
		while (1)
		{
			BytesRead = 0;
			if (BufferSize == 0)
			{
				_tprintf(TEXT("%hs(%u) (break)\n"), __FILE__, ((unsigned) __LINE__));
				break;
			}
	        Win32Error = NO_ERROR;
			if (ReadFile(Win32FileHandle1, Buffers[i % NumberOfBuffers], (DWORD) BufferSize, &BytesRead, NULL))
			{
				_tprintf(TEXT("asked for 0x%lx (%lu) bytes, got 0x%lx (%lu)\n"), BufferSize, BufferSize, BytesRead, BytesRead);

				if (BytesRead < BufferSize)
				{
					Done = 1;
				}
				if (BytesRead != 0)
				{
					_tprintf(TEXT("%hs(%u) (break)\n"), __FILE__, ((unsigned) __LINE__));
					break;
				}
			}
			else
			{
				Win32Error = GetLastError();
			    _tprintf(TEXT("error ReadFile(FileHandle %p, Buffer %p, BytesToRead 0x%lx) => BytesRead 0x%lx, Error %lu %s\n"),
			        Win32FileHandle1, Buffers[i % NumberOfBuffers], (DWORD) BufferSize, BytesRead, Win32Error, FormatWin32Error(Win32Error));
				if (Win32Error == ERROR_NO_SYSTEM_RESOURCES)
				{
					Sleep(0);
					BufferSize /= 2;
					_tprintf(TEXT("ERROR_NO_SYSTEM_RESOURCES\n"));
					_tprintf(TEXT("BufferSize => 0x%lx\n"), BufferSize);
				}
				else if (Win32Error == ERROR_HANDLE_EOF)
				{
					BufferSize /= 2;
					_tprintf(TEXT("ERROR_HANDLE_EOF\n"));
					_tprintf(TEXT("BufferSize => 0x%lx\n"), BufferSize);
				}
				else if (Win32Error == ERROR_SECTOR_NOT_FOUND)
				{
				    if (BufferSize > 0x160000) // size of a 1.44meg disk - 32k
				        BufferSize = 0x160000;
				    else if (BufferSize > 0x100000)
				        BufferSize = 0x100000;
				    else if (BufferSize > 0x60000)
				        BufferSize = 0x60000;
				    else if (BufferSize > 0x20000)
				        BufferSize = 0x20000;
				    else if (BufferSize > 0x10000)
				        BufferSize = 0x10000;
				    else if (BufferSize > 0x8000)
				        BufferSize = 0x8000;
				    else if (BufferSize > 0x1000)
				        BufferSize = 0x1000;
				    else if (BufferSize > 0x200)
				        BufferSize = 0x200;
                    else
    					BufferSize /= 2;
					_tprintf(TEXT("ERROR_SECTOR_NOT_FOUND\n"));
					_tprintf(TEXT("BufferSize => 0x%lx\n"), BufferSize);
				}
				else
				{
				    Win32Error = GetLastError();
					_tprintf(TEXT("ReadFile failed with %lu (%s)\n"), Win32Error, FormatWin32Error(Win32Error));
					_tprintf(TEXT("%hs(%u) (break)\n"), __FILE__, ((unsigned) __LINE__));
					break;
				}
			}
		}
		if ((Win32Error != NO_ERROR) && (Win32Error != ERROR_HANDLE_EOF) && (Win32Error != ERROR_NO_SYSTEM_RESOURCES))
		{
			_tprintf(TEXT("%hs(%u) (break)\n"), __FILE__, ((unsigned) __LINE__));
			break;
		}
		if (BytesRead == 0 && BufferSize == 0)
		{
			_tprintf(TEXT("%hs(%u) (break)\n"), __FILE__, ((unsigned) __LINE__));
			break;
		}
#endif
        //j_sleep(500 * (i % NumberOfBuffers)); /* go easy on the disks */
        //j_sleep(10 * (i % NumberOfBuffers)); /* go easy on the disks */
        BytesWritten = fwrite(Buffers[(i % NumberOfBuffers)], 1, BytesRead, FileHandle2);
        Offset += BytesWritten;

        if (BytesWritten != BytesRead)
        {
            _tprintf(TEXT("%hs(%u): i/o error at offset 0x%08lx\n"), __FILE__, ((unsigned) __LINE__), ((unsigned long) Offset));
            goto Retry1;
        }

        fflush(FileHandle2);
#if USE_WIN32_READ
		if ((SetFilePointer(Win32FileHandle1, - (long) BytesRead, NULL, FILE_CURRENT) == INVALID_SET_FILE_POINTER)
			&& (GetLastError() != NO_ERROR))
		{
            _tprintf(TEXT("%hs(%u): i/o error at offset 0x%08lx\n"), __FILE__, ((unsigned) __LINE__), ((unsigned long) Offset));
            goto Retry1;
		}
#else
        fseek(FileHandle1, Offset, SEEK_SET);
#endif
		fseek(FileHandle2, Offset, SEEK_SET);

        //j_sleep(500 * (i % NumberOfBuffers)); /* go easy on the disks */

#if USE_WIN32_READ
		BytesRead2 = 0;
        ReadFile(Win32FileHandle1, Buffers[((i + 1) % NumberOfBuffers)], (DWORD) BufferSize, &BytesRead2, NULL);
#else
        BytesRead2 = fread(Buffers[((i + 1) % NumberOfBuffers)], 1, BytesRead, FileHandle1);
#endif
        BytesRead3 = fread(Buffers[((i + 2) % NumberOfBuffers)], 1, BytesRead, FileHandle2);

        fseek(FileHandle2, 0, SEEK_CUR);
        fflush(FileHandle2);

        if (BytesRead2 != BytesRead)
        {
            _tprintf(TEXT("%hs(%u): i/o error at offset 0x%08lx\n"), __FILE__, ((unsigned) __LINE__), ((unsigned long) Offset));
            goto Retry1;
        }
        if (BytesRead3 != BytesRead)
        {
            _tprintf(TEXT("%hs(%u): i/o error at offset 0x%08lx\n"), __FILE__, ((unsigned) __LINE__), ((unsigned long) Offset));
            goto Retry1;
        }

        if (memcmp(Buffers[(i % NumberOfBuffers)], Buffers[((i + 1) % NumberOfBuffers)], BytesRead) != 0)
        {
            _tprintf(TEXT("%hs(%u): i/o error at offset 0x%08lx\n"), __FILE__, ((unsigned) __LINE__), ((unsigned long) Offset));
            goto Retry1;
        }

        if (memcmp(Buffers[(i % NumberOfBuffers)], Buffers[((i + 2) % NumberOfBuffers)], BytesRead) != 0)
        {
            _tprintf(TEXT("%hs(%u): i/o error at offset 0x%08lx\n"), __FILE__, ((unsigned) __LINE__), ((unsigned long) Offset));
            goto Retry1;
        }
        i += 1;
        Offset += BytesRead;
		BytesRead = 0;
		if (Done)
		    break;
    }
    if (0)
    {
Retry1:
		_tprintf(TEXT("%hs(%u) (Retry1)\n"), __FILE__, ((unsigned) __LINE__));
		BytesRead = 0;
        i += 1;
        NumberOfErrors += 1;
#if USE_WIN32_READ
		SetFilePointer(Win32FileHandle1, Offset, NULL, FILE_BEGIN);
#else
        fseek(FileHandle1, Offset, SEEK_SET);
#endif
        fseek(FileHandle2, Offset, SEEK_SET);
        if (NumberOfErrors < 10)
        {
            _tprintf(TEXT("retrying..\n"));
            goto Retry2;
        }
        else
        {
            _tprintf(TEXT("giving up..\n"));
            goto Exit;
        }
    }
    if (BytesRead != BufferSize)
    {
#ifdef _WIN32
#else
        a = !! feof(FileHandle1);
        b = !! ferror(FileHandle1);
#endif
        c = !! feof(FileHandle2);
        d = !! ferror(FileHandle2);
        _tprintf(TEXT("%hs(%u): file1=%p file2=%p eof1=%d err1=%d eof2=%d err2=%d errno=%d\n"), __FILE__, ((unsigned) __LINE__), FileHandle1, FileHandle2, a, b, c, d, e);
    }
    _tprintf(TEXT("0x%08lx (%lu) bytes copied\n"), Offset, Offset);
    ExitCode = EXIT_SUCCESS;
Exit:
    e = errno;
#ifdef _WIN32
	if (Win32FileHandle1 != INVALID_HANDLE_VALUE)
	{
		CloseHandle(Win32FileHandle1);
	}
	if (Win32FileHandle2 != INVALID_HANDLE_VALUE)
	{
		CloseHandle(Win32FileHandle2);
	}
	if (UnixFileHandle1 != -1)
	{
		_close(UnixFileHandle1);
	}
#endif
    if (FileHandle1 != NULL)
    {
        a = !! feof(FileHandle1);
        b = !! ferror(FileHandle1);
        fclose(FileHandle1);
    }
    if (FileHandle2 != NULL)
    {
        c = !! feof(FileHandle2);
        d = !! ferror(FileHandle2);
        fflush(FileHandle2);
        fclose(FileHandle2);
    }
    _tprintf(TEXT("%hs(%u): file1=%p file2=%p eof1=%d err1=%d eof2=%d err2=%d errno=%d\n"), __FILE__, ((unsigned) __LINE__), FileHandle1, FileHandle2, a, b, c, d, e);
    if (Buffers[0] != NULL)
    {
#if 1 && defined(_WIN32)
        VirtualFree(Buffers[0], 0, MEM_RELEASE);
#else
        free(Buffers[0]);
#endif
    }
    return ExitCode;
}
