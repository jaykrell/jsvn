/*
Jay Krell 2007
for the nth time, a hex dump program
*/

#define _CRT_SECURE_NO_DEPRECATE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ToHex(unsigned char ch, char* s)
{
    s[0] = (ch / 16)["0123456789abcdef"];
    s[1] = (ch % 16)["0123456789abcdef"];
}

char ToPrint(unsigned char ch)
{
    ch = (ch & 0x7f);
    if (ch >= 'a' && ch <= 'z')
        return ch;
    if (ch >= 'A' && ch <= 'Z')
        return ch;
    if (ch >= '0' && ch <= '9')
        return ch;
    switch (ch)
    {
        case ' ': case '!': case '@': case '#': case '$': case '%': case '^': case '&': case '*':
        case '(': case ')': case '{': case '}': case ';': case ':': case '[': case ']': case '"':
        case '<': case '>': case '?': case ',': case '.': case '/': case '|': case '`': case '~':
        case '_': case '-': case '+': case '=': case '\'': case '\\':
        return ch;
    }
    return '.';
}

void*
AllocateLargeBuffer(
    unsigned long SuggestedSize,
    unsigned long* ActualSize
    )
{
    void* p;

    *ActualSize = 0;

    while (SuggestedSize != (size_t) SuggestedSize)
        SuggestedSize /= 2;

    while ((SuggestedSize != 0) && !(p = malloc(SuggestedSize)))
        SuggestedSize /= 2;

    *ActualSize = SuggestedSize;
    return p;
}

int main(int argc, char** argv)
{
    typedef char Line_t[sizeof(unsigned long) * 8 + 4 * 16 + 7];
    Line_t Lines[2];
    unsigned LineIndex = 0;
    FILE* FileHandle = 0;
    unsigned char* InputBuffer = 0;
    unsigned long Offset = 0;
    unsigned long InputBufferSize;
    unsigned long BytesRead = 0;
    int ExitCode = EXIT_FAILURE;
    char* PreviousLine = 0;
    unsigned Skipping = 0;

    if (!argv[1])
    {
        goto Exit;
    }

    InputBuffer = AllocateLargeBuffer(1024UL * 1024UL * 64, &InputBufferSize);
    if (InputBuffer == NULL)
    {
        printf("insufficient memory\n");
        goto Exit;
    }

    FileHandle = fopen(argv[1], "rb");
    if (FileHandle == NULL)
    {
        goto Exit;
    }
    while (BytesRead = fread(InputBuffer, 1, InputBufferSize, FileHandle))
    {
        unsigned long a = 0;
        unsigned long b = 0;
        unsigned long c = 0;
        for (a = 0 ; a < BytesRead ; a += 16)
        {
            size_t StartOfHex = 0;
            char* CurrentLine = Lines[LineIndex ^= 1];
            sprintf(CurrentLine, "%08lx: ", Offset);
            StartOfHex = strlen(CurrentLine);
            c = StartOfHex;
            for (b = 0 ; b != 16 ; ++b)
            {
                if ((a + b) < BytesRead)
                    ToHex(InputBuffer[a + b], &CurrentLine[(c += 2) - 2]);
                else
                {
                    CurrentLine[c++] = ' ';
                    CurrentLine[c++] = ' ';
                }
                CurrentLine[c++] = ' ';
                if (b == 7 || b == 15)
                    CurrentLine[c++] = ' ';
            }
            for (b = 0 ; b != 16 ; ++b)
            {
                if ((a + b) < BytesRead)
                    CurrentLine[c++] = ToPrint(InputBuffer[a + b]);
                if (b == 7)
                    CurrentLine[c++] = ' ';
            }
            CurrentLine[c++] = '\n';
            CurrentLine[c++] = 0;
            if (PreviousLine == 0 || memcmp(&CurrentLine[StartOfHex], &PreviousLine[StartOfHex], 3 * 16 + 1) != 0)
            {
                fputs(CurrentLine, stdout);
                Skipping = 0;
            }
            else
            {
                if (!Skipping)
                    fputs("*\n", stdout);
                Skipping = 1;
            }
            Offset += 16;
            PreviousLine = CurrentLine;
        }
    }
    ExitCode = EXIT_SUCCESS;
Exit:
    free(InputBuffer);
    return ExitCode;
}
