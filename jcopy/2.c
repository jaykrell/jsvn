/*
Jay Krell 2007
for the nth time, a copy file program that accepts any paths and therefore devices
*/

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_DEPRECATE
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char** argv)
{
    FILE* FileHandle1 = 0;
    FILE* FileHandle2 = 0;
    unsigned char* Buffers[3] = { 0 };
    unsigned long Offset = 0;
    unsigned long BufferSize = (1024UL * 1024UL);
    unsigned long BytesRead = 0;
    unsigned long BytesRead2= 0;
    unsigned long BytesRead3= 0;
    unsigned long BytesWritten;
    unsigned NumberOfErrors = 0;
    int ExitCode = EXIT_FAILURE;
    unsigned i = 0;
    int a = -1, b = -2, c = -3, d = -4, e = -5;

    FileHandle1 = fopen(argv[1], "rb");
    a = feof(FileHandle1);
    b = ferror(FileHandle1);
    fclose(FileHandle1);
}
