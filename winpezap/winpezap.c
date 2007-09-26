/*
This program "zaps" Windows PE files.
That is, it makes them not valid PEs.
This is so that the MS-DOS stub will run.
"Zapping" is merely setting the high bit of the offset to the PE signature, to make it invalid.
The intent was to see if Visual C++ 1.0 would work, but it does not.
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <string.h>

#if defined(_MSC_VER)
#define USE_FSEEK64
#endif

unsigned long
UnpackLE4U(
	const unsigned char* a
	)
{
	unsigned long b = a[3];
	b <<= 8; b |= a[2];
	b <<= 8; b |= a[1];
	b <<= 8; b |= a[0];
	return b;
}

int main(int argc, char** argv)
{
    int ExitCode = EXIT_FAILURE;
	FILE* File = 0;
    unsigned char MZBuffer[64] = { 0 };
    unsigned char PEBuffer1[4] = { 0 };
    unsigned char PEBuffer2[4] = { 0 };
    size_t i = 0;
    unsigned long OffsetToPE = 0;
    unsigned Zapped = 0;
    unsigned ZappedAndValid = 0;

#if defined(_MSC_VER)
    printf("_MSC_VER is %lu\n", (unsigned long) _MSC_VER);
#endif

    if (!argv[1])
    {
        printf("%s(%u): invalid command line\n", __FILE__, ((unsigned) __LINE__));
        goto Exit;
    }

    File = fopen(argv[1], "rb+");
    if (File == NULL)
    {
        printf("unable to open %s, %s\n", argv[1], strerror(errno));
        goto Exit;
    }
    i = fread(MZBuffer, 1, 64, File);
    if (i != 64)
    {
        printf("unable to read 64 bytes from %s, %s\n", argv[1], strerror(errno));
        goto Exit;
    }

    if (MZBuffer[0] != 'M' || MZBuffer[1] != 'Z')
    {
        printf("no MZ signature in %s\n", argv[1]);
        goto Exit;
    }

    OffsetToPE = UnpackLE4U(&MZBuffer[60]);
    Zapped = ((OffsetToPE & 0x80000000) != 0);
    OffsetToPE &= ~0x80000000;

    if (fseek(File, OffsetToPE, SEEK_SET) == -1)
    {
        printf("unable to seek in %s, %s", argv[1], strerror(errno));
        goto Exit;
    }

    i = fread(PEBuffer1, 1, 4, File);
    if (i != 4)
    {
        printf("unable to read 4 bytes from %s at offset 0x%08lx, %s\n", argv[1], OffsetToPE, strerror(errno));
        goto Exit;
    }

    // if the high bit was set, see if there is a PE signature there
    // this is unlikely

    if (Zapped)
    {
#ifdef USE_FSEEK64
        if (_fseeki64(File, OffsetToPE | 0x80000000, SEEK_SET) != -1)
#elif 1 // this fails for Microsoft Visual C++ 8.0, works for Open Watcom 1.6
        if (fseek(File, 0x40000000, SEEK_SET) != -1)
        if (fseek(File, 0x40000000, SEEK_CUR) != -1)
        if (fseek(File, OffsetToPE, SEEK_CUR) != -1)
#else // This fails for both.
        if (fseek(File, OffsetToPE | 0x80000000, SEEK_SET) == -1)
#endif
        {
            i = fread(PEBuffer2, 1, 4, File);
            if (i == 4)
            {
                if (PEBuffer2[0] == 'P' && PEBuffer2[1] == 'E' && PEBuffer2[2] == 0 && PEBuffer2[3] == 0)
                {
                    printf("%s has large valid PE00 offset, surprising, unable to zap, exiting\n", argv[1]);
                    goto Exit;
                }
            }
        }
    }

    if (PEBuffer1[0] != 'P' || PEBuffer1[1] != 'E' || PEBuffer1[2] != 0 || PEBuffer1[3] != 0)
    {
        printf("no PE00 signature in %s\n", argv[1]);
        goto Exit;
    }

    if (Zapped)
    {
        printf("%s already zapped\n", argv[1]);
        goto Exit;
    }

    printf("will zap %s\n", argv[1]);
    MZBuffer[63] |= 0x80;
    if (fseek(File, 63, SEEK_SET) == -1)
    {
        printf("unable to seek in %s, %s", argv[1], strerror(errno));
        goto Exit;
    }
    i = fwrite(&MZBuffer[63], 1, 1, File);
    if (i != 1)
    {
        printf("fwrite to %s failed %s\n", argv[1], strerror(errno));
        goto Exit;
    }
    printf("zapped %s\n", argv[1]);

    ExitCode = EXIT_SUCCESS;
Exit:
    if (File) fclose(File);
    return ExitCode;
}
