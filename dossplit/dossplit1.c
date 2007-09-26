#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <string.h>

typedef struct MsdosHeader_t
{
	unsigned char Pad[60];
	unsigned char OffsetToPE[4];
} MsdosHeader_t;

typedef struct Mswin_PeFileHeader_t
{
	unsigned char Machine[2];
	unsigned char NumberOfSections[2];
	unsigned char TimeDateStamp[4];
	unsigned char FileOffsetToSymbols[4];
	unsigned char NumberOfSymbols[4];
	unsigned char SizeOfOptionalHeader[2];
	unsigned char Characteristics[2];
} Mswin_PeFileHeader_t;

typedef struct Mswin_PeSectionHeader_t
{
	char Name[8];
	unsigned char VirtualSize[4];
	unsigned char VirtualAddress[4];
	unsigned char SizeOfRawData[4];
	unsigned char FileOffsetToRawData[4];
	unsigned char FileOffsetToRelocations[4];
	unsigned char FileOffsetToLineNumbers[4];
	unsigned char NumberOfRelocations[2];
	unsigned char NumberOfLineNumbers[2];
	unsigned char Characteristics[4];
} Mswin_PeSectionHeader_t;

typedef struct File_t
{
	int Valid;
	const char* Path;
	FILE* Stdio;
	unsigned long Size;
    unsigned char* Contents;
} File_t;

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

unsigned
UnpackLE2U(
	const unsigned char* a
	)
{
	unsigned b = a[1];
	b <<= 8; b |= a[0];
	return b;
}

unsigned long
UnpackLE(
	const unsigned char* a,
    unsigned Size
	)
{
    if (Size == 2)
        return UnpackLE2U(a);
    else if (Size == 4)
        return UnpackLE4U(a);
    else
        return 0;
}

void
ReadFileIntoMemory(
	const char* FilePath,
	File_t* OutFile
	)
{
    const static char Function[] = "ReadFileIntoMemory";
	int Success = 0;
	long Size = 0;
	File_t File = { 0 };
    size_t FreadResult = 0;
    size_t FreadCount = 0;
    unsigned Line = __LINE__;

	File.Path = FilePath;
    Line = __LINE__;
	if (!(File.Stdio = fopen(FilePath, "rb")))
		goto Exit;

    Line = __LINE__;
	if (fseek(File.Stdio, 0, SEEK_END))
		goto Exit;

    Line = __LINE__;
	if ((Size = ftell(File.Stdio)) < 0)
		goto Exit;

	File.Size = (unsigned long) Size;

    printf("file size is 0x%08lx\n", (unsigned long) Size);

    Line = __LINE__;
	if (fseek(File.Stdio, 0, SEEK_SET))
		goto Exit;

    Line = __LINE__;
    if (!(File.Contents = malloc(File.Size)))
		goto Exit;

    Line = __LINE__;
    FreadCount = (size_t) File.Size;
	if (FreadCount != File.Size)
		goto Exit;

    Line = __LINE__;
    FreadResult = fread(File.Contents, 1, File.Size, File.Stdio);
	if (FreadResult != FreadCount)
		goto Exit;

    *OutFile = File;
    Success = 1;

Exit:
	if (!Success)
	{
        printf("%s failed at line %u, errno=%d (%s)\n", Function, Line, errno, strerror(errno));
		if (!File.Stdio)
			fclose(File.Stdio);
		free(File.Contents);
	}
}

int main(int argc, char** argv)
{
    int ExitCode = EXIT_FAILURE;
	File_t File = { 0 };

    printf("sizeof(size_t) is %u\n", (unsigned) sizeof(size_t));
    printf("sizeof(void*) is %u\n", (unsigned) sizeof(void*));
    printf("USHRT_MAX is %lu\n", (unsigned long) USHRT_MAX);
    printf("UINT_MAX is %lu\n", (unsigned long) UINT_MAX);
    printf("ULONG_MAX is %lu\n", (unsigned long) ULONG_MAX);

    if (0xFFFFffffUL != (size_t) 0xFFFFffffUL)
    {
        printf("invalid memory model -- size_t is smaller than 32 bits\n");
        goto Exit;
    }

    if (!argv[1])
    {
        printf("%s(%u): invalid command line\n", __FILE__, ((unsigned) __LINE__));
        goto Exit;
    }

	ReadFileIntoMemory(argv[1], &File);

    ExitCode = EXIT_SUCCESS;
Exit:
    return ExitCode;
}
