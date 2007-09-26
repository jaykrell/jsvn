/*
Jay Krell 2007
*/

#if (_MSC_VER > 800)
#pragma warning(disable:4996)
#endif
#define _CRT_SECURE_NO_DEPRECATE
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <dos.h> /* guard this, but how? */
#if defined(_WIN32)
#include <windows.h>
#endif
#include <limits.h>
#include <string.h>

size_t j_select_sizet(unsigned short a, unsigned long b)
{
    if ((sizeof(size_t) == 2) && (USHRT_MAX != ULONG_MAX))
        return a;
    return b;
}

void j_sleep(unsigned a)
{
#if 0
#if defined(_WIN32)
    Sleep(a);
#else
    sleep(a);
#endif
#endif
}

int main(int argc, char** argv)
{
    FILE* FileHandle1 = 0;
    FILE* FileHandle2 = 0;
    unsigned char* Buffers[2] = { 0 };
    const size_t NumberOfBuffers = (sizeof(Buffers)/sizeof(Buffers[0]));
    unsigned long Offset = 0;
    size_t BufferSize;
    size_t BytesRead1 = 0;
    size_t BytesRead2 = 0;
    int ExitCode = EXIT_FAILURE;
    size_t i = 0;
    errno = 0;

    printf("sizeof(size_t) is %u\n", (unsigned) sizeof(size_t));
    printf("sizeof(void*) is %u\n", (unsigned) sizeof(void*));
    printf("USHRT_MAX is %lu\n", (unsigned long) USHRT_MAX);
    printf("UINT_MAX is %lu\n", (unsigned long) UINT_MAX);
    printf("ULONG_MAX is %lu\n", (unsigned long) ULONG_MAX);

    BufferSize = j_select_sizet(1024 * 24, 1024UL * 1024UL);

    printf("BufferSize is is 0x%08lx\n", (unsigned long) BufferSize);

    if (!argv[1])
    {
        printf("%s(%u): invalid command line\n", __FILE__, ((unsigned) __LINE__));
        goto Exit;
    }
    if (!argv[2])
    {
        printf("%s(%u): invalid command line\n", __FILE__, ((unsigned) __LINE__));
        goto Exit;
    }

    FileHandle1 = fopen(argv[1], "rb");
    if (FileHandle1 == NULL)
    {
        printf("%s(%u): unable to open file %s\n", __FILE__, ((unsigned) __LINE__), argv[1]);
        goto Exit;
    }
    FileHandle2 = fopen(argv[2], "rb");
    if (FileHandle2 == NULL)
    {
        printf("%s(%u): unable to open file %s\n", __FILE__, ((unsigned) __LINE__), argv[2]);
        goto Exit;
    }

    for (i = 0 ; i != NumberOfBuffers ; ++i)
    {
        Buffers[i] = (unsigned char*) malloc(BufferSize);
        if (Buffers[i] == NULL)
        {
            printf("insufficient memory\n");
            goto Exit;
        }
    }
    while ((BytesRead1 = fread(Buffers[0], 1, BufferSize, FileHandle1)) > 0)
    {
        j_sleep(1); /* go easy on the disks */
        BytesRead2 = fread(Buffers[1], 1, BufferSize, FileHandle2);

#define j_min(a,b) (((a)<(b))?(a):(b))

        if (memcmp(Buffers[0], Buffers[1], j_min(BytesRead1, BytesRead2)) != 0)
        {
            for (i = 0 ; i != j_min(BytesRead1, BytesRead2) ; ++i)
            {
                if (Buffers[0][i] != Buffers[1][i])
                {
                    printf("%s(%u): different at offset 0x%08lx\n", __FILE__, ((unsigned) __LINE__), (Offset + i));
                    goto Exit;
                }
            }
            printf("%s(%u): different at offset 0%08lx + ?\n", __FILE__, ((unsigned) __LINE__), Offset);
            goto Exit;
        }
        if (BytesRead1 != BytesRead2)
        {
            printf("%s(%u): files %s %s are identical to 0x%08lx bytes but %s is longer\n",
                __FILE__, ((unsigned) __LINE__), argv[1], argv[2], Offset + j_min(BytesRead1, BytesRead2),
                ((BytesRead1 < BytesRead2) ? argv[2] : argv[1]));
            goto Exit;
        }
        Offset += BytesRead1;
    }
    if (fread(Buffers[1], 1, 1, FileHandle2) == 1)
    {
        printf("%s(%u): files %s %s are identical to 0x%08lx bytes but %s is longer\n", __FILE__, ((unsigned) __LINE__), argv[1], argv[2], Offset, argv[2]);
    }
    else
    {
        printf("%s(%u): files %s %s are identical to 0x%08lx bytes (they are the same size)\n", __FILE__, ((unsigned) __LINE__), argv[1], argv[2], Offset);
    }
    ExitCode = EXIT_SUCCESS;
Exit:
    if (FileHandle1)
    {
        fclose(FileHandle1);
    }
    if (FileHandle2)
    {
        fclose(FileHandle2);
    }
    for (i = 0 ; i != NumberOfBuffers ; ++i)
    {
        if (Buffers[i] != NULL)
        {
            free(Buffers[i]);
        }
    }
    return ExitCode;
}
