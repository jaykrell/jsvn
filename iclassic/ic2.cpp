//#include "precompiled_header.h"#include <CodeFragments.h>//#include <Carbon/Carbon.h>//#include <CoreServices/CoreServices.h>#include "ic2.h" CMacError::CMacError(long Error) : m_Error(Error) { }void ThrowMacError(long Error){	if (Error != 0)	{#if 0		if (IsDebuggerPresent())			DebugBreak();#endif		throw CMacError(Error);	}}voidJkMacPefHandlerLoaderSection(	MacPEFContainer* /*PEF*/,	size_t /*Section*/	){}void iclassic1(const wchar_t* Path){	Ptr Main = NULL;	CFragConnectionID Connection = 0;	OSErr Error = 0;	unsigned long FileSize = 0;	MacPEFContainer PEF;	std::vector<BYTE>& FileContents = PEF.FileContents;	size_t i = 0;	size_t j = 0;	Str255 ErrorMessage = { 0 };	printf("--- %ls ---\n", Path);		CMacFilePath MacPath(Path);	CMacUseResFile MacResFile;	MacResFile.Save();	//CMacResLoad ResLoad(false);	CMacResourceFileHandle ResourceFork;	ResourceFork.OpenReadDenyWrite(MacPath);	MacResFile.Set(ResourceFork);	CMacFileHandle DataFork;	DataFork.OpenDataForkReadDenyWrite(MacPath);	CFragResourceHandle FragHandle = (CFragResourceHandle)Get1Resource(kCFragResourceType, kCFragResourceID);		if (FragHandle == NULL)		goto Exit;			HLock((Handle)FragHandle);	CFragResourcePtr FragHeader = *FragHandle;	CFragResourceMemberPtr FragMember = &FragHeader->firstMember;	printf("memberCount: %x\n", FragHeader->memberCount);	printf("extensionCount: %x\n", FragMember->extensionCount);	printf("usage: %x\n", (unsigned) FragMember->usage);	printf("where: %x\n", (unsigned) FragMember->where);	printf("length: %x\n", (unsigned) FragMember->length);	printf("offset: %x\n", (unsigned) FragMember->offset);		if (FragMember->where != kDataForkCFragLocator		|| FragMember->where != kApplicationCFrag		|| FragMember->length != 0		|| FragMember->offset != 0		)	{		goto Exit;	}		printf("ok\n");	FileSize = GetFileSize(DataFork);	if (FileSize < sizeof(MacPEFContainerHeader_Packed))	{		PrintError(L"File too small %ls", Path);		goto Exit;	}	try	{		FileContents.resize(FileSize);	}	catch (...)	{		PrintError(L"File to large / out of memory (%ls)", Path);		goto Exit;	}	ReadFileAtOffset(DataFork, 0, FileSize, &FileContents[0]);		UnpackMacPEFContainerHeader(		(const MacPEFContainerHeader_Packed*)&FileContents[0],		&PEF.Header		);	printf("Tag1: %.4s\n", PEF.Header.Tag1);	printf("Tag2: %.4s\n", PEF.Header.Tag2);	printf("Architecture: %.4s\n", PEF.Header.Architecture);	printf("FormatVersion: %lx\n", PEF.Header.FormatVersion);	printf("DateTimeStamp: %lx\n", PEF.Header.DateTimeStamp);	printf("OldDefVersion: %lx\n", PEF.Header.OldDefVersion);	printf("OldImpVersion: %lx\n", PEF.Header.OldImpVersion);	printf("CurrentVersion: %lx\n", PEF.Header.CurrentVersion);	printf("SectionCount: %x\n", PEF.Header.SectionCount);	printf("InstSectionCount: %x\n", PEF.Header.InstSectionCount);	printf("ReservedA: %lx\n", PEF.Header.ReservedA);		Error = jk_multiply_sizet(PEF.Header.SectionCount, sizeof(MacPEFSectionHeader_Packed), &i);	if (Error != 0)	{		printf("Malformed PEF file (%ls) (too many section?) (line %lu)\n", Path, (unsigned long) __LINE__);		goto Exit;	}	Error = jk_add_sizet(i, sizeof(MacPEFContainerHeader_Packed), &j);	if (Error != 0)	{		printf("Malformed PEF file (%ls) (too many sections?) (line %lu)\n", Path, (unsigned long) __LINE__);		goto Exit;	}		if (j > FileSize)	{		printf("Malformed PEF file (%ls)\n", Path);		goto Exit;	}		PEF.SectionNameTableOffset = j;	PEF.SectionNameTablePointer = (char*) (j + &FileContents[0]);		PEF.Sections.resize(PEF.Header.SectionCount);	j = sizeof(MacPEFContainerHeader_Packed);	for (i = 0 ; i != PEF.Header.SectionCount ; ++i)	{		UnpackMacPEFSectionHeader(			(const MacPEFSectionHeader_Packed*)&FileContents[j],			&PEF.Sections[i].Header			);		j += sizeof(MacPEFSectionHeader_Packed);	}	PEF.NumberOfLoaderSections = 0;	for (i = 0 ; i != PEF.Header.SectionCount ; ++i)	{		PEF.NumberOfLoaderSections += (PEF.Sections[i].Header.SectionKind == MAC_PEF_SECTION_KIND_LOADER);	}	PEF.LoaderSections.reserve(PEF.NumberOfLoaderSections);	for (i = 0 ; i != PEF.Header.SectionCount ; ++i)	{		if (PEF.Sections[i].Header.SectionKind == MAC_PEF_SECTION_KIND_LOADER)		{			PEF.LoaderSections.push_back(i);		}	}	for (i = 0 ; i != PEF.NumberOfLoaderSections ; ++i)	{		JkMacPefHandlerLoaderSection(&PEF, PEF.LoaderSections[i]);	}	for (i = 0 ; i != PEF.Header.SectionCount ; ++i)	{		if (PEF.Sections[i].Header.NameOffset == 0xFFFFFFFF)		{			printf(				"Section 0x%08lx, kind 0x%08lx (%ls), name table offset 0x%08lx (no name)\n",				i,				(unsigned long) PEF.Sections[i].Header.SectionKind,				MacPEFSectionKindString(PEF.Sections[i].Header.SectionKind),				(unsigned long) PEF.Sections[i].Header.NameOffset				);			continue;		}						size_t NameOffset;		Error = jk_add_sizet(PEF.SectionNameTableOffset, PEF.Sections[i].Header.NameOffset, &NameOffset);		if (Error != 0 || NameOffset >= FileSize)		{			printf("Malformed PEF file (%ls) (line %lu)\n", Path, (unsigned long) __LINE__);			goto Exit;		}		size_t k;		for (k = NameOffset ; k != FileSize && FileContents[k] != 0 ; ++k)		{					}		if (k == FileSize)		{			printf("Malformed PEF file (%ls) (line %lu)\n", Path, (unsigned long) __LINE__);			goto Exit;		}		printf(			"Section 0x%08lx, kind 0x%08lx (%ls), name %s (name table offset 0x%08lx, file offset %0x%08lx)\n",			i,			(unsigned long) PEF.Sections[i].Header.SectionKind,			MacPEFSectionKindString(PEF.Sections[i].Header.SectionKind),			&FileContents[NameOffset],			(unsigned long) PEF.Sections[i].Header.NameOffset,			(unsigned long) NameOffset			);	}	Main = NULL;	Connection = 0;	Error = GetDiskFragment(MacPath, 0, 0, NULL, kLoadCFrag, &Connection, &Main, ErrorMessage);Exit:	printf("OSErr: %s\n", p2cstr(ErrorMessage));	printf("OSErr: %d\n", (int)Error);	printf("Main: %p\n", (void*)Main);	printf("CFragConnectionID: %p\n", (void*)Connection);	printf("CodeFragmentResource: %p\n", (void*)FragHandle);	printf("DataForkHandle: %d\n", (int)DataFork.GetMacFileHandle());	printf("ResourceForkHandle: %d\n", (int)ResourceFork.GetMacFileHandle());}voidUnpackMacResourceForkHeader(	const MacResourceForkHeader_Packed* Packed,	MacResourceForkHeader* Unpacked	){	Unpacked->OffsetToResorceData = UnpackUBE4(Packed->OffsetToResorceData);	Unpacked->OffsetToResourceMap = UnpackUBE4(Packed->OffsetToResourceMap);	Unpacked->LengthOfResourceData = UnpackUBE4(Packed->LengthOfResourceData);	Unpacked->LengthOfRresourceMap = UnpackUBE4(Packed->LengthOfRresourceMap);}voidUnpackMacPEFContainerHeader(	const MacPEFContainerHeader_Packed* Packed,	MacPEFContainerHeader* Unpacked	){	/* 40 bytes */	const unsigned char* p = (const unsigned char*)&Packed->FormatVersion;	memmove(Unpacked->Tag1, Packed->Tag1, 4);	memmove(Unpacked->Tag2, Packed->Tag2, 4);	memmove(Unpacked->Architecture, Packed->Architecture, 4);	Unpacked->FormatVersion = GetUBE4(&p);	Unpacked->DateTimeStamp = GetUBE4(&p);	Unpacked->OldDefVersion = GetUBE4(&p);	Unpacked->OldImpVersion = GetUBE4(&p);	Unpacked->CurrentVersion = GetUBE4(&p);	Unpacked->SectionCount = GetUBE2(&p);	Unpacked->InstSectionCount = GetUBE2(&p);	Unpacked->ReservedA = GetUBE4(&p);}voidUnpackMacPEFSectionHeader(	const MacPEFSectionHeader_Packed* Packed,	MacPEFSectionHeader* Unpacked	){	/* 28 bytes */	const unsigned char* p = (const unsigned char*)Packed;	Unpacked->NameOffset = GetUBE4(&p);	Unpacked->DefaultAddress = GetUBE4(&p);	Unpacked->TotalSize = GetUBE4(&p);	Unpacked->UnpackedSize = GetUBE4(&p);	Unpacked->PackedSize = GetUBE4(&p);	Unpacked->ContainerOffset = GetUBE4(&p);	Unpacked->SectionKind = Packed->SectionKind;	Unpacked->ShareKind = Packed->ShareKind;	Unpacked->Alignment = Packed->Alignment;	Unpacked->ReservedA = Packed->ReservedA;}voidUnpackMacPEFLoaderInfoHeader(	const MacPEFLoaderInfoHeader_Packed* Packed,	MacPEFLoaderInfoHeader* Unpacked	){	/* 56 bytes */	const unsigned char* p = (const unsigned char*)Packed;	Unpacked->MainSection = GetUBE4(&p);	Unpacked->MainOffset = GetUBE4(&p);	Unpacked->InitSection = GetUBE4(&p);	Unpacked->InitOffset = GetUBE4(&p);	Unpacked->TermSection = GetUBE4(&p);	Unpacked->TermOffset = GetUBE4(&p);	Unpacked->ImportedLibraryCount = GetUBE4(&p);	Unpacked->TotalmportedSymbolCount = GetUBE4(&p);	Unpacked->RelocSectionCount = GetUBE4(&p);	Unpacked->RelocInstrSectionCount = GetUBE4(&p);	Unpacked->LoaderStringOffset = GetUBE4(&p);	Unpacked->ExportHashOffset = GetUBE4(&p);	Unpacked->ExportHashTablePower = GetUBE4(&p);	Unpacked->ExportedSymbolCount = GetUBE4(&p);}voidUnpackMacPEFImportedLibrary(	const MacPEFImportedLibrary_Packed* Packed,	MacPEFImportedLibrary* Unpacked	){	/* 24 bytes */	const unsigned char* p = (const unsigned char*)Packed;	Unpacked->NameOffset = GetUBE4(&p);	Unpacked->OldImpVersion = GetUBE4(&p);	Unpacked->CurrentVersion = GetUBE4(&p);	Unpacked->ImportedSymbolCount = GetUBE4(&p);	Unpacked->FirstImportedSymbol = GetUBE4(&p);	Unpacked->Options = Packed->Options;	Unpacked->ReservedA = Packed->ReservedA;	Unpacked->ReservedB = UnpackUBE2(Packed->ReservedB);}size_tMacPEFConvertHashWordToIndex(	size_t HashWord,	size_t HashTablePower	){	return ((HashWord ^ (HashWord >> HashTablePower)) & ((1 << HashTablePower) - 1));}#define MAC_PEF_HASH_LENGTH_SHIFT (16)#define MAC_PEF_HASH_VALUE_MASK   (0x0000FFFF)size_tMacPEFComputeHashWord(	const unsigned char* Name,	size_t Length	){	LONG32 HashValue = 0;	unsigned char Byte;	size_t i;	size_t Result;#define PseudoRotate(x) (((x) << 1) - ((x) >> 16))	for (i = 0; ((Byte = Name[i]) != 0) && (i != Length); ++i)	{		HashValue = (PseudoRotate(HashValue) ^ Byte);	}	Result =		(i << MAC_PEF_HASH_LENGTH_SHIFT)		| ((unsigned short) ((HashValue ^ (HashValue >> 16)) & MAC_PEF_HASH_VALUE_MASK));	return Result;}unsigned shortUnpackUBE2( /* unsigned big endian 2 bytes */	const unsigned char* Bytes	){	unsigned short Result = 0;	Result <<= 8; Result |= Bytes[0];	Result <<= 8; Result |= Bytes[1];	return Result;}unsigned longUnpackUBE4( /* unsigned big endian 4 bytes */	const unsigned char* Bytes	){	unsigned long Result = 0;	Result <<= 8; Result |= Bytes[0];	Result <<= 8; Result |= Bytes[1];	Result <<= 8; Result |= Bytes[2];	Result <<= 8; Result |= Bytes[3];	return Result;}unsigned longGetUBE2( /* unsigned big endian 2 bytes */	unsigned char const** ppBytes	){	unsigned long Result = 0;	unsigned char const * Bytes = *ppBytes;	Result <<= 8; Result |= Bytes[0];	*ppBytes = (Bytes + 2);	Result <<= 8; Result |= Bytes[1];	return Result;}unsigned longGetUBE4( /* unsigned big endian 4 bytes */	unsigned char const** ppBytes	){	unsigned long Result = 0;	unsigned char const * Bytes = *ppBytes;	Result <<= 8; Result |= Bytes[0];	Result <<= 8; Result |= Bytes[1];	*ppBytes = (Bytes + 4);	Result <<= 8; Result |= Bytes[2];	Result <<= 8; Result |= Bytes[3];	return Result;}unsigned longUnpack(	const unsigned char* Bytes,	unsigned Size,	unsigned BigEndian,	unsigned Signed	){	unsigned long Result = 0;	if (Size == 0)		return 0;	if (Signed && (Bytes[BigEndian ? 0 : (Size - 1)] & 0x80) != 0)		Result = -1;	if (BigEndian)	{		while (Size--)		{			Result <<= 8;			Result |= *Bytes++;		}	}	else	{		while (Size)		{			Result <<= 8;			Result |= Bytes[--Size];		}				}	return Result;}voidPrintError(	const wchar_t* Format,	...	){	va_list Args;		va_start(Args, Format);	vfwprintf(stderr, Format, Args);	va_end(Args);}unsigned longGetFileSize(	HANDLE FileHandle	){	SInt64 FileSize = 0;	ThrowMacError(FSGetForkSize((short) (size_t) FileHandle, &FileSize));	return (unsigned long) FileSize;}voidReadFileAtOffset(	HANDLE FileHandle,	size_t offset,	size_t count,	PVOID buffer	){	ParamBlockRec pb;		pb.ioParam.ioRefNum     = (short) (size_t) FileHandle;	pb.ioParam.ioBuffer     = (Ptr) buffer;	pb.ioParam.ioReqCount   = count;	pb.ioParam.ioPosMode    = fsFromStart;	pb.ioParam.ioPosOffset  = offset;		ThrowMacError(PBReadSync(&pb));}void iclassic2(){	iclassic1(L"z:Development:MPW:MPW Shell");	iclassic1(L"z:Prince of Persia 2:Prince of Persia 2");}int main(){	iclassic2();	return 0;}