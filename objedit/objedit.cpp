/*

  objedit

  Jay Krell
  March 2006

  This tool edits .obj files in place in limited ways.
    It adds alias symbols to them.
	It adds associativity of symbols within an obj.
	The input is an .obj file and a directive file.
	The directive file has a very inflexible format.
	It consists of lines like:
	   <directive> <symbol1> <symbol2>

	where directive is one of alias or associate.

	The .obj file is edited in-place.
*/
#include <string>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <limits.h>
#include <stdarg.h>
#include <vector>
using namespace std;
#pragma warning(disable:4786)
#pragma hdrstop

void Abort(PCSTR a, ...)
{
	va_list Args;
	va_start(Args, a);
	vfprintf(stderr, a, Args);
	va_end(Args);
	fflush(stderr);
	exit(EXIT_FAILURE);
}

void IntegerOverflow()
{
	//if (IsDebuggerPresent()) DebugBreak();
	Abort("integer overflow (possibly malformed file)\n");
}

DWORD Dword(size_t x)
{
	DWORD i = (DWORD)x;
	if (i != x)
	{
		IntegerOverflow();
	}
	return i;
}

int Int(size_t x)
{
	int i = (int)x;
	if (i < 0 || i != x)
	{
		IntegerOverflow();
	}
	return i;
}

size_t Add(size_t i, size_t j)
{
	size_t k = (i + j);
	if (k < i || k < j)
	{
		IntegerOverflow();
	}
	return k;
}

size_t Multiply(size_t i, size_t j)
{
	const size_t bits = (CHAR_BIT * sizeof(size_t) / 2);
	const size_t lo_mask = ((~(size_t)0) >> bits);
	const size_t hi_mask = ((~(size_t)0) << bits);
	size_t i_hi = (i >> bits);
	size_t i_lo = (i & lo_mask);
	size_t j_hi = (j >> bits);
	size_t j_lo = (j & lo_mask);
	size_t a = (i_hi * j_lo);
	size_t b = (i_lo * j_hi);
	size_t c = (i_lo * j_lo);

	if (i_hi != 0 || j_hi != 0 || (a & hi_mask) != 0 || (b & hi_mask) != 0)
	{
		IntegerOverflow();
	}

	return Add(Add((a << bits), (b << bits)), c);
}

void
OpenFile(
	PCWSTR Path,
	ULONG  Access,
	HANDLE* InOutHandle,
	vector<BYTE>* Contents
	)
{
	if (InOutHandle != NULL)
		*InOutHandle = INVALID_HANDLE_VALUE;
	HANDLE Handle = CreateFileW(Path, Access, FILE_SHARE_DELETE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	if (Handle == INVALID_HANDLE_VALUE)
	{
		Abort("CreateFile %ls failed %u\n", Path, GetLastError());
	}
	ULARGE_INTEGER uliSize;
	uliSize.LowPart = GetFileSize(Handle, &uliSize.HighPart);
	if (uliSize.LowPart == (DWORD)-1 && GetLastError() != NO_ERROR)
	{
		Abort("GetFileSize %ls failed %u\n", Path, GetLastError());
	}
	size_t Size = (size_t)uliSize.QuadPart;
	if (Size != uliSize.QuadPart)
	{
		Abort("file %ls too big\n", Path);
	}
	if (uliSize.HighPart != 0) // UNDONE ReadFile64
	{
		Abort("file %ls too big\n", Path);
	}
	Contents->resize(Size);
	DWORD NumberOfBytesRead;
	if (!ReadFile(Handle, &(*Contents)[0], (DWORD)Size, &NumberOfBytesRead, NULL)) // UNDONE ReadFile64
	{
		Abort("ReadFile %ls failed %u\n", Path, GetLastError());
	}
	if (NumberOfBytesRead != Size)
	{
		Abort("ReadFile %ls failed\n", Path);
	}
	if (InOutHandle != NULL)
		*InOutHandle = Handle;
	else
		CloseHandle(Handle);
}

string
GetSectionName(
	PIMAGE_SECTION_HEADER Section,
	PCSTR StringTable
	)
{
	char Buffer[9] = { 0 };
	memcpy(Buffer, Section->Name, 8);
	if (Buffer[0] == '/'
		&& strspn(&Buffer[1], "0123456789") == strlen(&Buffer[1]))
	{
		return (StringTable + strtoul(&Buffer[1], NULL, 10));
	}
	else
	{
		return Buffer;
	}
}

string
GetSymbol(
	PIMAGE_SYMBOL Symbol,
	PCSTR StringTable
	)
{
	if (Symbol->N.Name.Short == 0)
	{
		return (StringTable + Symbol->N.Name.Long);
	}
	else
	{
		char Buffer[9] = { 0 };
		memcpy(Buffer, Symbol->N.ShortName, 8);
		return Buffer;
	}
}

extern "C"
int
wmain(
	int argc,
	wchar_t** argv
	)
{
	if (argc != 3)
	{
		Abort("usage: objedit objfile directivefile");
	}

	vector<BYTE> Contents;
	vector<BYTE> DirectiveFileContents;
	HANDLE Handle = { 0 };

	PCWSTR Path = argv[1];
	PCWSTR DirectiveFilePath = argv[2];

	OpenFile(Path, GENERIC_READ | GENERIC_WRITE, &Handle, &Contents);
	OpenFile(DirectiveFilePath, GENERIC_READ, NULL, &DirectiveFileContents);

	const size_t OldFileSize = Contents.size();
	PIMAGE_FILE_HEADER FileHeader;

	if (OldFileSize < (sizeof(*FileHeader) + 4))
	{
		Abort("file too small\n");
	}

	FileHeader = (PIMAGE_FILE_HEADER)&Contents[0];

	if (FileHeader->SizeOfOptionalHeader != 0)
	{
		Abort("file %ls malformed (%u)\n", Path, __LINE__);
	}

	const size_t NumberOfSections = FileHeader->NumberOfSections;
	const size_t OffsetToSymbolTable = FileHeader->PointerToSymbolTable;
	const size_t OldNumberOfSymbols = FileHeader->NumberOfSymbols;

	const size_t OldSizeofSymbolTable = Multiply(OldNumberOfSymbols, sizeof(IMAGE_SYMBOL));
	const size_t OldOffsetToStringTable = Add(OffsetToSymbolTable, OldSizeofSymbolTable);
	if (OldOffsetToStringTable > OldFileSize)
	{
		Abort("file %ls malformed (%u)\n", Path, __LINE__);
	}
	Add(OldOffsetToStringTable, 4);
	const PCSTR StringTable = (PCSTR) &Contents[OldOffsetToStringTable];
	const size_t OldSizeofStringTable = *(UNALIGNED DWORD*) StringTable;
	if (OldSizeofStringTable < 4)
	{
		Abort("file %ls malformed (%u)\n", Path, __LINE__);
	}
	const size_t EndOfStringTable = Add(OldOffsetToStringTable, OldSizeofStringTable);
	if (EndOfStringTable != OldFileSize)
	{
		Abort("string table not at end of file, cannot edit\n");
	}

	PIMAGE_SYMBOL Symbols = (PIMAGE_SYMBOL) &Contents[OffsetToSymbolTable];
	PIMAGE_SECTION_HEADER Sections = (PIMAGE_SECTION_HEADER) &Contents[sizeof(IMAGE_FILE_HEADER)];

	if (DirectiveFileContents.size() == 0)
	{
		return EXIT_SUCCESS;
	}

	vector<pair<PCSTR, PCSTR> > Aliases;
	vector<pair<PCSTR, PCSTR> > Associations;

	DirectiveFileContents.push_back(0);
	PSTR div[3];
	div[0] = (PSTR)&DirectiveFileContents[0];

	size_t NumberOfAddedSymbols = 0;
	size_t NumberOfAddedStrings = 0;
	size_t NumberOfAddedStringBytes = 0;

	while (div[0] && div[0][0])
	{
		bool newline = false;
		while (div[0][0] == '\r' || div[0][0] == '\n')
			div[0] += 1;
		if (div[0][0] == 0)
			break;
		div[1] = strchr(div[0], ' ');
		if (div[1] == NULL)
		{
			Abort("file %ls malformed (%u)\n", DirectiveFilePath, __LINE__);
		}
		div[2] = strchr(div[1] + 1, ' ');
		if (div[2] == NULL)
		{
			Abort("file %ls malformed (%u)\n", DirectiveFilePath, __LINE__);
		}
		div[3] = strchr(div[2] + 1, '\r');
		if (div[3] != NULL)
		{
			newline = true;
			while (div[3][0] != '\r' && div[3][0] != '\n')
			{
				div[3][0] = 0;
				div[3] += 1;
			}
		}
		else
		{
			div[3] = div[2] + strlen(div[2]);
		}
		div[1][0] = 0;
		div[2][0] = 0;
		div[3][0] = 0;
		PCSTR Command = (div[0]);
		PCSTR Param1 = (div[1] + 1);
		PCSTR Param2 = (div[2] + 1);

		printf("command = '%s', param1 = '%s', param2 = '%s'\n", Command, Param1, Param2);
		if (strcmp(Command, "alias") == 0)
		{
			Aliases.push_back(make_pair(Param1, Param2));
			NumberOfAddedSymbols = Add(NumberOfAddedSymbols, 3);
			NumberOfAddedStrings = Add(NumberOfAddedStrings, 2);
			NumberOfAddedStringBytes = Add(NumberOfAddedStringBytes, strlen(Param1) + 1);
			NumberOfAddedStringBytes = Add(NumberOfAddedStringBytes, strlen(Param2) + 1);
		}
		else if (strcmp(Command, "associate") == 0)
		{
			Associations.push_back(make_pair(Param1, Param2));
		}
		else
		{
			Abort("file %ls malformed (%u)\n", DirectiveFilePath, __LINE__);
		}
		div[0] = div[3];
		div[0] += newline;
	}

	PIMAGE_SYMBOL Symbol = NULL;
	PIMAGE_AUX_SYMBOL AuxSymbol = NULL;
	size_t i = 0;

	//
	// optionally find the section symbols
	//
	typedef map<string, size_t> SymbolNameToSectionSymbolIndex_t;
	SymbolNameToSectionSymbolIndex_t SymbolNameToSectionSymbolIndex;
	//if (Associations.size() != 0)
	{
		PIMAGE_SECTION_HEADER Section = NULL;
		size_t SectionNumber = 1;
		string SectionName;
		for (i = 0 ; i != OldNumberOfSymbols ; ++i)
		{
			Symbol = &Symbols[i];
			size_t NumberOfAuxSymbols = Symbol->NumberOfAuxSymbols;
			if (Symbol->Value == 0
				&& Symbol->SectionNumber >= SectionNumber
				&& Symbol->Type == IMAGE_SYM_TYPE_NULL
				&& Symbol->StorageClass == IMAGE_SYM_CLASS_STATIC
				&& Symbol->NumberOfAuxSymbols == 1
				&& Symbol->SectionNumber < NumberOfSections
				&& (Section = &Sections[Symbol->SectionNumber - 1])
				&& (Section->Characteristics & IMAGE_SCN_LNK_COMDAT) != 0
				&& (SectionName = GetSectionName(Section, StringTable)) == GetSymbol(Symbol, StringTable)
				)
			{
				//
				// This is not clear -- the next symbol provides the name?
				//
				if ((i + 1) != OldNumberOfSymbols
					&& (i + 2) != OldNumberOfSymbols
					&& Symbols[i + 2].SectionNumber == Symbol->SectionNumber
					&& Symbols[i + 2].NumberOfAuxSymbols == 0
					)
				{
					i += 2;
					NumberOfAuxSymbols = 0; // we took care of incrementing, don't do it again
					Symbol = &Symbols[i];
					string SymbolString = GetSymbol(Symbol, StringTable);
					printf(
						"found section symbol 0x%x for section '%s' (0x%x) name = '%s'\n",
						(unsigned)i,
						SectionName.c_str(),
						(unsigned)Symbol->SectionNumber,
						SymbolString.c_str()
						);
					SymbolNameToSectionSymbolIndex[SymbolString] = (i - 2);
				}
				else
				{
					//
					// This does not happen, unless you ignore the comdat flag.
					// If you ignore the comdat flag the .drective, .data, probably .rdata hit it.
					//
					printf(
						"found section symbol 0x%x for section '%s' (0x%x) but no name\n",
						(unsigned)i,
						SectionName.c_str(),
						(unsigned)Symbol->SectionNumber
						);
				}
				SectionNumber = Symbol->SectionNumber + 1;
			}
			i += NumberOfAuxSymbols;
		}
	}

	const size_t NumberOfAddedSymbolBytes = Multiply(NumberOfAddedSymbols, sizeof(IMAGE_SYMBOL));
	const size_t NumberOfAddedBytes = Add(NumberOfAddedSymbolBytes, NumberOfAddedStringBytes);
	const size_t NewSize = Add(Contents.size(), NumberOfAddedBytes);
	const size_t NewNumberOfSymbols = Add(OldNumberOfSymbols, NumberOfAddedSymbols);

	const size_t NewSizeofStringTable = Add(OldSizeofStringTable, NumberOfAddedStringBytes);

	Contents.resize(NewSize);

	// zero new bytes

	ZeroMemory(&Contents[OldFileSize], NumberOfAddedBytes);

	// reset pointers

	FileHeader = (PIMAGE_FILE_HEADER)&Contents[0];
	Symbols = (PIMAGE_SYMBOL) &Contents[OffsetToSymbolTable];
	Sections = (PIMAGE_SECTION_HEADER) &Contents[sizeof(IMAGE_FILE_HEADER)];

	const size_t NewOffsetToStringTable = (OldOffsetToStringTable + NumberOfAddedSymbolBytes);

	//
	// move strings down
	//
	memmove(
		&Contents[NewOffsetToStringTable],
		&Contents[OldOffsetToStringTable],
		OldSizeofStringTable
		);

	size_t Length = 0;
	PIMAGE_SYMBOL NewSymbol = (PIMAGE_SYMBOL)&Contents[OldOffsetToStringTable];
	size_t NewSymbolIndex = OldNumberOfSymbols;
	AuxSymbol = NULL;
	size_t StringOffset = OldSizeofStringTable;
	PSTR StringPointer = (PSTR)&Contents[NewOffsetToStringTable + OldSizeofStringTable];
	for (i = 0 ; i != Aliases.size() ; ++i)
	{
		NewSymbol->N.Name.Short = 0;
		NewSymbol->N.Name.Long = StringOffset;
		NewSymbol->Value = 0;
		NewSymbol->SectionNumber = IMAGE_SYM_UNDEFINED;
		NewSymbol->Type = IMAGE_SYM_TYPE_NULL;
		NewSymbol->StorageClass = IMAGE_SYM_CLASS_WEAK_EXTERNAL;
		NewSymbol->NumberOfAuxSymbols = 1;

		Length = strlen(Aliases[i].first);
		memcpy(StringPointer, Aliases[i].first, Length);
		StringPointer[Length] = 0;
		StringPointer += (Length + 1);
		StringOffset += (Length + 1);

		NewSymbol += 1;
		NewSymbolIndex += 1;
		AuxSymbol = (PIMAGE_AUX_SYMBOL)NewSymbol;

		AuxSymbol->Sym.TagIndex = Dword(Add(NewSymbolIndex, 1));
		AuxSymbol->Sym.Misc.TotalSize = IMAGE_WEAK_EXTERN_SEARCH_ALIAS; // aka Characteristics

		NewSymbol += 1;
		NewSymbolIndex += 1;

		NewSymbol->N.Name.Short = 0;
		NewSymbol->N.Name.Long = StringOffset;
		NewSymbol->Value = 0;
		NewSymbol->SectionNumber = IMAGE_SYM_UNDEFINED;
		NewSymbol->Type = IMAGE_SYM_TYPE_NULL;
		NewSymbol->StorageClass = IMAGE_SYM_CLASS_EXTERNAL;
		NewSymbol->NumberOfAuxSymbols = 0;

		Length = strlen(Aliases[i].second);
		memcpy(StringPointer, Aliases[i].second, Length);
		StringPointer[Length] = 0;
		StringPointer += (Length + 1);
		StringOffset += (Length + 1);	

		NewSymbol += 1;
		NewSymbolIndex += 1;
	}
	for (i = 0 ; i != Associations.size() ; ++i)
	{
		SymbolNameToSectionSymbolIndex_t::const_iterator it1 = SymbolNameToSectionSymbolIndex.find(Associations[i].first);
		SymbolNameToSectionSymbolIndex_t::const_iterator it2 = SymbolNameToSectionSymbolIndex.find(Associations[i].second);
		if (it1 == SymbolNameToSectionSymbolIndex.end())
		{
			printf("'%s' not found\n", Associations[i].first);
			continue;
		}
		if (it2 == SymbolNameToSectionSymbolIndex.end())
		{
			printf("'%s' not found\n", Associations[i].second);
			continue;
		}

		Symbol = &Symbols[it1->second];
		AuxSymbol = (PIMAGE_AUX_SYMBOL)(Symbol + 1);
		AuxSymbol->Section.Selection = IMAGE_COMDAT_SELECT_ASSOCIATIVE;
		AuxSymbol->Section.Number = Symbols[it2->second].SectionNumber;
	}

	FileHeader->NumberOfSymbols = Dword(NewNumberOfSymbols);
	*(UNALIGNED DWORD*)&Contents[NewOffsetToStringTable] = NewSizeofStringTable;

	SetFilePointer(Handle, 0, NULL, FILE_BEGIN);
	DWORD NumberOfBytesWritten;
	if (!WriteFile(Handle, &Contents[0], (DWORD)NewSize, &NumberOfBytesWritten, NULL)) // UNDONE WriteFile64
	{
		Abort("WriteFile %ls failed %u\n", Path, GetLastError());
	}
	return EXIT_SUCCESS;
}
