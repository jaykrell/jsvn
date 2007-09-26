#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <string.h>

void
PackLE4U(
	unsigned char* a,
    unsigned long b
	)
{
    a[0] = (b & 0xff);
    a[1] = ((b >> 8) & 0xff);
    a[2] = ((b >> 16) & 0xff);
    a[3] = ((b >> 24) & 0xff);
}

int main(int argc, char** argv)
{
    void* Buffer = 0;
    size_t i = 0;
    unsigned char OffsetToPE[4] = { 0 };
    size_t FileSize = 0;
    size_t BytesWritten = 0;
    size_t BufferSize = 0;
    unsigned long Line = __LINE__;
    const static unsigned char Tests[] =
    {
        // tests are delimited by 0xff

        // zero sized file
        0xff,

        // one byte file, no MZ signature
        0,0xff,

        // two byte file, just MZ
        'M','Z',0xff,

        // 64 bytes, no MZ
        'X','Z',2,3,4,5,6,7,8,9,
        10,11,12,13,14,15,16,17,18,19,
        20,21,22,23,24,25,26,27,28,29,
        30,31,32,33,34,35,36,37,38,39,
        40,41,42,43,44,45,46,47,48,49,
        50,51,52,53,54,55,56,57,58,59,
        0,0,0,0,0xff,

        // 64 bytes, MZ, invalid PE offset -- not to PE00
        'M','Z',2,3,4,5,6,7,8,9,
        10,11,12,13,14,15,16,17,18,19,
        20,21,22,23,24,25,26,27,28,29,
        30,31,32,33,34,35,36,37,38,39,
        40,41,42,43,44,45,46,47,48,49,
        50,51,52,53,54,55,56,57,58,59,
        0,0,0,0,0xff,

        // MZ, invalid PE offset -- out of bounds
        'M','Z',2,3,4,5,6,7,8,9,
        10,11,12,13,14,15,16,17,18,19,
        20,21,22,23,24,25,26,27,28,29,
        30,31,32,33,34,35,36,37,38,39,
        40,41,42,43,44,45,46,47,48,49,
        50,51,52,53,54,55,56,57,58,59,
        0x7f,0x7f,0x7f,0x7f,0xff,

        // MZ, valid PE, zappable
        'M','Z',2,3,4,5,6,7,8,9,
        10,11,12,13,14,15,16,17,18,19,
        20,21,22,23,24,25,26,27,28,29,
        30,31,32,33,34,35,36,37,38,39,
        40,41,42,43,44,45,46,47,48,49,
        50,51,52,53,54,55,56,57,58,59,
        64,0,0,0,'P','E',0,0,0xff,

        // MZ, valid PE, already zapped
        'M','Z',2,3,4,5,6,7,8,9,
        10,11,12,13,14,15,16,17,18,19,
        20,21,22,23,24,25,26,27,28,29,
        30,31,32,33,34,35,36,37,38,39,
        40,41,42,43,44,45,46,47,48,49,
        50,51,52,53,54,55,56,57,58,59,
        64,0,0,0x80,'P','E',0,0,0xff,

        // the end
        0xff
    };

    int ExitCode = EXIT_FAILURE;
	FILE* File = 0;
    unsigned Length = 0;
    unsigned TestNumber = 0;
    char TestName[64] = { 0 };
    unsigned Offset = 0;

    if (0xFFFFffffUL != (size_t) 0xFFFFffffUL)
    {
        printf("invalid memory model -- size_t is smaller than 32 bits\n");
        goto Exit;
    }

    Line = __LINE__;
    while (1)
    {
        Length = 0;
        while (Tests[Offset + Length] != 0xff)
            Length += 1;
        if (Length == 0 && Offset != 0)
            break;
        sprintf(TestName, "%u", TestNumber);
        File = fopen(TestName, "wb");
        if (File == NULL)
        {
            Line = __LINE__;
            goto Exit;
        }
        fwrite(&Tests[Offset], 1, Length, File);
        fclose(File);
        File = 0;
        Offset += (Length + 1);
        TestNumber += 1;
    }

    Line = __LINE__;
    sprintf(TestName, "%u", TestNumber);
    File = fopen(TestName, "wb");
    if (File == NULL)
        goto Exit;
    BufferSize = (1024 * 1024 * 4);
    Buffer = calloc(1, BufferSize); // 4 meg
    FileSize = 0x80000000 + BufferSize;
    Line = __LINE__;
    for (BytesWritten = 0; BytesWritten < FileSize ; BytesWritten += BufferSize)
    {
        if (fwrite(Buffer, 1, BufferSize, File) != BufferSize)
            goto Exit;
    }
    free(Buffer);
    Buffer = 0;
    Line = __LINE__;
    if (fseek(File, 0, SEEK_SET) == -1)
        goto Exit;
    Line = __LINE__;
    if (fwrite("MZ", 1, 2, File) != 2)
        goto Exit;
    Line = __LINE__;
    if (fseek(File, 60, SEEK_SET) == -1)
        goto Exit;
    Line = __LINE__;
    PackLE4U(OffsetToPE, (FileSize - 4));
    Line = __LINE__;
    if (fwrite(OffsetToPE, 1, 4, File) != 4)
        goto Exit;
    Line = __LINE__;
#if 0 // This fails, probably a sign problem.
    if (fseek(File, (FileSize - 4), SEEK_SET) == -1)
        goto Exit;
#else
    if (fseek(File, -4, SEEK_END) == -1)
        goto Exit;
#endif
    Line = __LINE__;
    if (fwrite("PE\0\0", 1, 4, File) != 4)
        goto Exit;
    fclose(File);
    File = 0;

    ExitCode = EXIT_SUCCESS;
Exit:
    if (File) fclose(File);
    free(Buffer);
    if (ExitCode != EXIT_SUCCESS)
    {
        printf("failed at line %lu\n", (unsigned long) Line);
    }
    return ExitCode;
}
