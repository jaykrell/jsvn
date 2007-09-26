

class lib2obj
{

vector<BYTE> LibContents;
vector<BYTE> ObjContents;
std::vector<PIMAGE_FILE_HEADER> LibObjects;
std::vector<PIMAGE_SECTION_HEADER> LibSections;
PIMAGE_FILE_HEADER    LibFileHeader;
PIMAGE_FILE_HEADER    ObjFileHeader;
PIMAGE_SECTION_HEADER LibSectionHeaders;
PIMAGE_SECTION_HEADER ObjSectionHeaders;
size_t				  ObjPosition;

void
OpenFile(
	PCWSTR FilePath,
	DWORD FileAccess,
	vector<BYTE>* Contents
	)
{
	HANDLE FileHandle = CreateFileW(FilePath, FileAccess, FILE_SHARE_READ | FILE_SHARE_DELETE,
		NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (FileHandle == INVALID_HANDLE_VALUE)
		throw GetLastError();
}

void
GetFileHeader(
	vector<BYTE>& LibContents
	)
{
}

void
CreateSectionHeaders(
	)
{
}

int main(int argc, char** argv)
{
	vector<BYTE> LibContents;
	vector<BYTE> ObjContents;

	ObjPosition = 0;

	PCWSTR Path = argv[1];

	OpenFile(Path, GENERIC_READ, &LibContents);

	ObjContents.resize(LibContents.size());

	CreateSectionHeaders();
	CreateSectionData();
	CreateSymbolTable();
	CreateStringTable();
}
};

int main()
{
	lib2obj x;

	return x.main();
}
