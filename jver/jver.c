/*
This program is meant to assist in writing \autoexec.bat.
The version that used command.com more did not work in DosBox due to limitations of the "if" command.

"jver" is a directory under \dos to add to the path, since DOS utilities are so finicky about version,
 we have to put the right version in the path.
*/

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <io.h>
#include <memory.h>
#include <stdlib.h>

const  struct
{
    const char* Ver;
    const char* JVer;
} Data[] =
{
    { "MS-DOS Version 6.22", "622", },
    { "Windows 95. [Version 4.00.950]", "95", },
    { "Windows 95. [Version 4.00.1111]", "95B", },
    { "Windows 98 [Version 4.10.2222]", "98B", },
    { "DOSBox version 0.70. Reported DOS version 5.0.", "DOSBOX", },
    { "Microsoft Windows XP [Version 5.1.2600]", "XP", },


    /* This needs to be checked against other versions of NT and perhaps renamed "ntdos". */
    { "MS-DOS Version 5.00.500", "XP", },
};

char* TrimVerticalSpacesFromStartAndEnd(char* s)
{
    char ch;
    size_t length = strlen(s);
    if (((ch = s[0]) == '\r') || (s[0] == '\n'))
    {
        char* t = s;
        while ((length != 0) && (((ch = s[0]) == '\r') || (ch == '\n')))
        {
            s += 1;
            length -= 1;
        }
        memmove(t, s, length);
        t[length] = 0;
        s = t;
    }
    while ((length != 0) && (((ch = s[length - 1]) == '\r') || (ch == '\n')))
    {
        length -= 1;
    }
    s[length] = 0;
    return s;
}

char* ReadEntireFile(const char* FilePath)
{
    FILE *File = { 0 };
    char* Buffer = { 0 };
    size_t ChunkSize = 64;
    size_t Size = ChunkSize;
    size_t BytesRead = { 0 };
    char* NextBuffer = { 0 };
    int Success = { 0 };

    Buffer = (char*) calloc(1, Size);
    if (Buffer == NULL)
        goto Exit;

    File = fopen(FilePath, "rb");
    if (File == NULL)
        goto Exit;

    while ((BytesRead = fread((Buffer + Size - ChunkSize), 1, ChunkSize, File)) == ChunkSize)
    {
        Size += ChunkSize;
        NextBuffer = realloc(Buffer, Size);
        if (NextBuffer == NULL)
            goto Exit;
        Buffer = NextBuffer;
        memset(Buffer + Size - ChunkSize, 0, ChunkSize);
    }
    Success = 1;
Exit:
    if (File != NULL)
        fclose(File);
    if (!Success)
    {
        free(Buffer);
        return NULL;
    }
    return Buffer;

}

int main()
{
    /* We cannot fit a guid a in a dos 8.3 file name -- only around 55 bits; we cannot even fit a 64 bit time. */

    time_t t;
    char s1[64];
    char s2[64];
    char* FileContents = { 0 };
    const char* JVer = { 0 };
    size_t i;

    time(&t);
    sprintf(s1, "\\%lx.jvr", (0xffffFFFFUL & (unsigned long) t));
    sprintf(s2, "ver > %s", s1);
    unlink(s1);
    system(s2);
    FileContents = ReadEntireFile(s1);
    unlink(s1);

    TrimVerticalSpacesFromStartAndEnd(FileContents);

    JVer = "unknown";
    for (i = 0 ; i != sizeof(Data) / sizeof(Data[0]) ; ++i)
    {
        if (strcmp(FileContents, Data[i].Ver) == 0)
        {
            JVer = Data[i].JVer;
            break;
        }
    }
    printf("set jver=%s\n", FileContents);
    free(FileContents);
    printf("set jver=%s\n", JVer);

    return 0;
}

