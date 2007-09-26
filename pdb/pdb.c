/*

credits:

Sven Schreiber for pdb file format.
MSDN samples for cv*.h describing CV4
easily found .pdfs document CV4
CV5 documentation is on old MSDN CDs.
CV8 look at the yasm source
*/

#define CC_BIGINT 1 /* enable __int64 support */
#include "pdb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <memory.h>
#include "cvinfo.h"
#include "cvexefmt.h"
int __stdcall IsDebuggerPresent(void);
typedef int BOOL;
#pragma hdrstop

void
DumpCodeViewSymbols(
    BOOL HasSignature,
    unsigned char* p,
    size_t n
    );

void
DumpCodeViewTypes(
    BOOL HasSignature,
    unsigned char* p,
    size_t n
    );

typedef struct MY_FILE {
    unsigned char* Contents;
    size_t Size;
    const char* FileName;
} MY_FILE;

long
ReadEntireFileInMemory(
    const char* FileName,
    MY_FILE* OutFile
    )
{
    long Status = -1;
    FILE* StdioFile = 0;
    size_t BufferSize = 0;
    size_t BytesReadOnce = 0;
    size_t BytesReadTotal = 0;
    size_t BytesToRead = (1U << 8); /* start small */
    MY_FILE File = { 0 };
    void* NextBuffer;

    *OutFile = File;

    StdioFile = fopen(FileName, "rb");
    if (StdioFile == NULL)
        goto Exit;

    for (;;)
    {
        if ((BytesToRead + BytesReadTotal) > BufferSize)
        {
            /* read up to one meg at a time */
            if (BytesToRead < (1024UL * 1024UL))
                BytesToRead *= 2;
            BufferSize += BytesToRead;
            NextBuffer = realloc(File.Contents, BufferSize);
            if (!NextBuffer)
                goto Exit;
            File.Contents = (unsigned char*) NextBuffer;
        }
        BytesReadOnce = fread(&File.Contents[BytesReadTotal], 1, BytesToRead, StdioFile);
        if (BytesReadOnce == 0 && ferror(StdioFile))
            goto Exit;
        BytesReadTotal += BytesReadOnce;
        if (BytesReadOnce < BytesToRead)
            break;
    }

    NextBuffer = realloc(File.Contents, BytesReadTotal);
    if (!NextBuffer)
        goto Exit;

    File.Contents = (unsigned char*) NextBuffer;
    File.FileName = FileName;
    File.Size = BytesReadTotal;
    *OutFile = File;
    Status = 0;
Exit:
    if (StdioFile)
        fclose(StdioFile);
    if (Status < 0)
        free(File.Contents);
    return Status;
}

typedef struct STREAM {
    unsigned char*  Contents;
    size_t Size;
    size_t NumberOfPages;
} STREAM;

size_t
GetULEn(
    const void* v,
    size_t n
    )
/*
get an unsigned little endian integer of size n from address v 
*/
{
    size_t a = 0;
    if (n != 0)
    {
        const unsigned char* b = (const unsigned char*) v;
        size_t i;
        for (i = 0 ; i != n ; ++i)
        {
            a <<= 8;
            a |= b[n - i - 1];
        }
    }
    return a;
}

#define GetULE(x) (GetULEn(&x, sizeof(x)))

ptrdiff_t
GetSLEn(
    const void* v,
    size_t n
    )
/*
get a signed little endian integer of size n from address v 
*/
{
    ptrdiff_t a = 0;
    const unsigned char* b = (const unsigned char*) v;
    size_t i;
    if (n != 0)
    {
        if ((b[n - 1] & 0x80) != 0)
        {
            a = -1;
        }
        for (i = 0 ; i != n ; ++i)
        {
            a <<= 8;
            a |= b[n - i - 1];
        }
    }
    return a;
}

#define GetSLE(x) (GetSLEn(&x, sizeof(x)))

size_t
GetPage(
    PDB_HEADER* PdbHeader,
    unsigned char* Pages
    )
{
    return GetULEn(Pages, PdbHeader->PageIndexSize);
}

void
CopyStream(
    PDB_HEADER* PdbHeader,
    MY_FILE* File,
    STREAM* Stream,
    size_t StreamSize,
    unsigned char* Pages
    )
{
    unsigned char*   FileContents = 0;
    size_t  PageSize = 0;
    size_t  i = 0;
    size_t  NumberOfPages = 0;
    unsigned char*   Contents = 0;

    memset(Stream, 0, sizeof(*Stream));

    Contents = (unsigned char*) malloc(StreamSize);
    if (Contents == NULL)
        goto Exit;

    FileContents = File->Contents;
    PageSize = PdbHeader->PageSize;
    NumberOfPages = ((StreamSize + PageSize - 1) / PageSize);

    Stream->Size = StreamSize;
    Stream->NumberOfPages = NumberOfPages;
    Stream->Contents = Contents;

    for (i = 0; i != NumberOfPages ; ++i)
    {
        size_t BlockSize;
        size_t PageNumber;

        if (i == (NumberOfPages - 1))
            BlockSize = (StreamSize % PageSize);
        else
            BlockSize = PageSize;

        PageNumber = GetPage(PdbHeader, Pages);
        Pages +=  PdbHeader->PageIndexSize;
        memcpy(Contents + i * PageSize, FileContents + PageNumber * PageSize, BlockSize);
    }
Exit:
    return;
}

void
DumpBytes(
    const unsigned char* p,
    size_t Size
    )
{
    size_t i;

    for (i = 0 ; i < Size ; ++i)
    {
        if ((i != 0) && ((i % 16) == 0))
            printf("\n");
        if ((i % 16) == 0)
            printf("%06lx:", (unsigned long)i);
        if ((i % 8) == 0)
            printf(" ");
        printf("%02x ", p[i]);
        if ((((i + 1) % 16) == 0) || ((i + 1) == Size))
        {
            size_t j;
            while (((i + 1) % 16) != 0)
            {
                //if (Size > 16)
                {
                    if ((i % 8) == 0)
                        printf(" ");
                    printf("   ");
                }
                i += 1;
            }
            printf(" ");
            for (j = (i - 15) ; ((j <= i) && (j < Size)) ; ++j)
            {
                char c = p[j];
                if ((j % 8) == 0)
                    printf(" ");
                printf("%c", (c >= 32 && c < 127 && isprint(c)) ? c : '.');
            }
        }
    }
    printf("\n");
}

void
DumpStream(
    PDB_HEADER* PdbHeader,
    STREAM* Stream,
    size_t Index
    )
{
    size_t Size = 0;
    unsigned char* Contents = 0;
    size_t i = 0;

    Size = Stream->Size;
    Contents = Stream->Contents;

    printf("stream 0x%lx size 0x%lx:\n", (unsigned long)Index, (unsigned long)Stream->Size);

    DumpBytes(Contents, Size);

    if (Index < sizeof(PdbHeader->Streams)/sizeof(PdbHeader->Streams[0]))
    {
        if (PdbHeader->Streams[Index].Types)
        {
            DumpCodeViewTypes(FALSE, &Stream->Contents[0x10], Stream->Size - 0x10);
            //DumpCodeViewTypes(FALSE, Stream->Contents, Stream->Size);
        }
        else if (PdbHeader->Streams[Index].Symbols)
        {
            DumpCodeViewSymbols(PdbHeader->Streams[Index].SymbolsSignature, Stream->Contents, Stream->Size);
            //DumpCodeViewTypes(FALSE, &Stream->Contents[PdbHeader->OffsetToTypes], Stream->Size - PdbHeader->OffsetToTypes);
        }
    }
}

const char*
GetCodeViewSymbolTagString(
    size_t n
    )
{
    const char* Result = "<unknown>";
#define X(x) case x: Result = #x; break;
    switch (n)
    {
    X(S_REGISTER_16t);
    X(S_CONSTANT_16t);
    X(S_UDT_16t);
    X(S_MANYREG_16t);
    X(S_BPREL16);
    X(S_LDATA16);
    X(S_GDATA16);
    X(S_PUB16);
    X(S_LPROC16);
    X(S_GPROC16);
    X(S_THUNK16);
    X(S_BLOCK16);
    X(S_WITH16);
    X(S_LABEL16);
    X(S_CEXMODEL16);
    X(S_VFTABLE16);
    X(S_REGREL16);
    X(S_BPREL32_16t);
    X(S_LDATA32_16t);
    X(S_GDATA32_16t);
    X(S_PUB32_16t);
    X(S_LPROC32_16t);
    X(S_GPROC32_16t);
    X(S_VFTABLE32_16t);
    X(S_REGREL32_16t);
    X(S_LTHREAD32_16t);
    X(S_GTHREAD32_16t);
    X(S_SLINK32);
    X(S_LPROCMIPS_16t);
    X(S_GPROCMIPS_16t);
    X(S_LPROCREF);

    X(S_COMPILE);
    X(S_SSEARCH);
    X(S_END);
    X(S_SKIP);
    X(S_CVRESERVE);
    X(S_OBJNAME);
    X(S_ENDARG);
    X(S_COBOLUDT_16t);
    X(S_RETURN);
    X(S_ENTRYTHIS);
    X(S_REGISTER);
    X(S_CONSTANT);
    X(S_UDT);
    X(S_COBOLUDT);
    X(S_MANYREG);
    X(S_BPREL32);
    X(S_LDATA32);
    X(S_GDATA32);
    X(S_PUB32);
    X(S_LPROC32);
    X(S_GPROC32);
    X(S_THUNK32);
    X(S_BLOCK32);
    X(S_WITH32);
    X(S_LABEL32);
    X(S_CEXMODEL32);
    X(S_VFTABLE32);
    X(S_REGREL32);
    X(S_LTHREAD32);
    X(S_GTHREAD32);
    X(S_LPROCMIPS);
    X(S_GPROCMIPS);
    X(S_PROCREF);
    X(S_DATAREF);
    X(S_ALIGN);

    X(S_OBJNAME2);
    X(S_COMPILE2);
    X(S_SOURCE_FILE_INFO_STRING_TABLE);
    X(S_SOURCE_FILE_INFO);
    X(S_LINE_NUMBERS);
    X(S_SYMBOLS);
    X(S_LABEL2);
    X(S_LDATA2);
    X(S_GDATA2);
    X(S_GPROC2);
    X(S_BPREL2);

    X(S_UNKNOWN_00F5);
    X(S_UNKNOWN_1012);
    X(S_UNKNOWN_1108);
    X(S_UNKNOWN_1515);

    }
    return Result;
}

const char*
GetCodeViewLeafTagString(
    size_t n
    )
{
#define X(x) case x: Result = #x; break;
    const char* Result = "<unknown>";
    switch (n)
    {
    X(LF_MODIFIER_16t)
    X(LF_POINTER_16t)
    X(LF_ARRAY_16t)
    X(LF_CLASS_16t)
    X(LF_STRUCTURE_16t)
    X(LF_UNION_16t)
    X(LF_ENUM_16t)
    X(LF_PROCEDURE_16t)
    X(LF_MFUNCTION_16t)
    X(LF_COBOL0_16t)
    X(LF_BARRAY_16t)
    X(LF_DIMARRAY_16t)
    X(LF_VFTPATH_16t)
    X(LF_PRECOMP_16t)
    X(LF_OEM_16t)
    X(LF_SKIP_16t)
    X(LF_ARGLIST_16t)
    X(LF_DEFARG_16t)
    X(LF_LIST)
    X(LF_FIELDLIST_16t)
    X(LF_DERIVED_16t)
    X(LF_BITFIELD_16t)
    X(LF_METHODLIST_16t)
    X(LF_DIMCONU_16t)
    X(LF_DIMCONLU_16t)
    X(LF_DIMVARU_16t)
    X(LF_DIMVARLU_16t)
    X(LF_BCLASS_16t)
    X(LF_VBCLASS_16t)
    X(LF_IVBCLASS_16t)
    X(LF_FRIENDFCN_16t)
    X(LF_INDEX_16t)
    X(LF_MEMBER_16t)
    X(LF_STMEMBER_16t)
    X(LF_METHOD_16t)
    X(LF_NESTTYPE_16t)
    X(LF_VFUNCTAB_16t)
    X(LF_FRIENDCLS_16t)
    X(LF_ONEMETHOD_16t)
    X(LF_VFUNCOFF_16t)
    X(LF_MODIFIER)
    X(LF_POINTER)
    X(LF_ARRAY)
    X(LF_CLASS)
    X(LF_STRUCTURE)
    X(LF_UNION)
    X(LF_ENUM)
    X(LF_PROCEDURE)
    X(LF_MFUNCTION)
    X(LF_VTSHAPE)
    X(LF_COBOL0)
    X(LF_COBOL1)
    X(LF_BARRAY)
    X(LF_LABEL)
    X(LF_NULL)
    X(LF_NOTTRAN)
    X(LF_DIMARRAY)
    X(LF_VFTPATH)
    X(LF_PRECOMP)
    X(LF_ENDPRECOMP)
    X(LF_OEM)
    X(LF_TYPESERVER)
    X(LF_SKIP)
    X(LF_ARGLIST)
    X(LF_DEFARG)
    X(LF_FIELDLIST)
    X(LF_DERIVED)
    X(LF_BITFIELD)
    X(LF_METHODLIST)
    X(LF_DIMCONU)
    X(LF_DIMCONLU)
    X(LF_DIMVARU)
    X(LF_DIMVARLU)
    X(LF_REFSYM)
    X(LF_BCLASS)
    X(LF_VBCLASS)
    X(LF_IVBCLASS)
    X(LF_ENUMERATE)
    X(LF_FRIENDFCN)
    X(LF_INDEX)
    X(LF_MEMBER)
    X(LF_STMEMBER)
    X(LF_METHOD)
    X(LF_NESTTYPE)
    X(LF_VFUNCTAB)
    X(LF_FRIENDCLS)
    X(LF_ONEMETHOD)
    X(LF_VFUNCOFF)
    X(LF_NESTTYPEEX)
    X(LF_MEMBERMODIFY)
    X(LF_CHAR)
    X(LF_SHORT)
    X(LF_USHORT)
    X(LF_LONG)
    X(LF_ULONG)
    X(LF_REAL32)
    X(LF_REAL64)
    X(LF_REAL80)
    X(LF_REAL128)
    X(LF_QUADWORD)
    X(LF_UQUADWORD)
    X(LF_REAL48)
    X(LF_COMPLEX32)
    X(LF_COMPLEX64)
    X(LF_COMPLEX80)
    X(LF_COMPLEX128)
    X(LF_VARSTRING)
    X(LF_OCTWORD)
    X(LF_UOCTWORD)
    X(LF_PAD0)
    X(LF_PAD1)
    X(LF_PAD2)
    X(LF_PAD3)
    X(LF_PAD4)
    X(LF_PAD5)
    X(LF_PAD6)
    X(LF_PAD7)
    X(LF_PAD8)
    X(LF_PAD9)
    X(LF_PAD10)
    X(LF_PAD11)
    X(LF_PAD12)
    X(LF_PAD13)
    X(LF_PAD14)
    X(LF_PAD15)
    }
    return Result;
#undef X
}

const char*
GetSubsectionName(
    unsigned SubsectionIndex
    )
{
#define X(x) case x: Result = #x; break;

    const char* Result = "<unknown>";
    switch (SubsectionIndex)
    {
    X(sstModule)
    X(sstTypes)
    X(sstPublic)
    X(sstPublicSym)     // publics as symbol (waiting for link)
    X(sstSymbols)
    X(sstAlignSym)
    X(sstSrcLnSeg)      // because link doesn't emit SrcModule
    X(sstSrcModule)
    X(sstLibraries)
    X(sstGlobalSym)
    X(sstGlobalPub)
    X(sstGlobalTypes)
    X(sstMPC)
    X(sstSegMap)
    X(sstSegName)
    X(sstPreComp)       // precompiled types
    X(sstPreCompMap)    // map precompiled types in global types
    X(sstOffsetMap16)
    X(sstOffsetMap32)
    X(sstFileIndex)     // Index of file names
    X(sstStaticSym)
    }
    return Result;
#undef X
}

void
DumpCVProcFlags(
    const char* Tag,
    size_t bAll
    )
{
    CV_PROCFLAGS Flags;

    printf("%s flags 0x%08lx\n", Tag, (unsigned long) bAll);
    if (bAll != 0)
    {
        Flags.u.bAll = (unsigned char) bAll;
        if (Flags.u.s.CV_PFLAG_FPO)
            printf("   frame pointer omitted\n");
        if (Flags.u.s.CV_PFLAG_INT)
            printf("   interrupt return\n");
        if (Flags.u.s.CV_PFLAG_FAR)
            printf("   far return\n");
        if (Flags.u.s.CV_PFLAG_NEVER)
            printf("   never returns\n");
        if (Flags.u.s.unused)
            printf("   unused flags set\n");
    }
}

unsigned char*
DumpCodeViewSymbolRecord(
    unsigned long Signature,
    unsigned char* p
    )
{
    unsigned char* q = p;
    size_t version;
    size_t i;
    char* key;
    size_t Size;
    size_t TagInteger;
    unsigned char* End;
    const char* Tag;
    union {
        THUNKSYM32*     ThunkSym32;
        PUBSYM32_16t*   PubSym32_16t;
        PUBSYM32*       PubSym32;
        DATASYM32_16t*  DataSym32_16t;
        DATASYM32*      DataSym32;
        DATASYM2*       DataSym2;
        REFSYM*         RefSym;
        OBJNAMESYM*     ObjNameSym;
        OBJNAMESYM2*    ObjNameSym2;
        CFLAGSYM*       CFlagSym;
        CFLAGSYM2*      CFlagSym2;
        BPRELSYM32_16t* BPRelSym32_16t;
        BPRELSYM32*     BPRelSym32;
        BPRELSYM2*      BPRelSym2;
        PROCSYM32_16t*  ProcSym32_16t;
        PROCSYM32*      ProcSym32;
        PROCSYM2*       ProcSym2;
        LABELSYM32*     LabelSym32;
        LABELSYM2*      LabelSym2;
        BLOCKSYM32*     BlockSym32;
        UDTSYM_16t*     UdtSym_16t;
        UDTSYM*         UdtSym;
        UNKNOWN_00F5_SYM* Unknown00F5;
        UNKNOWN_1012_SYM* Unknown1012;
        UNKNOWN_1108_SYM* Unknown1108;
        UNKNOWN_1515_SYM* Unknown1515;
        unsigned char* p;
    } u;
    
    u.p = p;
    if (Signature == 4)
    {
        TagInteger = GetULEn(p, 4);
        Size = GetULEn(p + 4, 4);
        p += (Size + 8);
        //p += ((Size + 3) & ~3);
    }
    else
    {
        Size = GetULEn(p, 2);
        p += 2;
        TagInteger = GetULEn(p, 2);
        p += Size;
    }

    Tag = GetCodeViewSymbolTagString(TagInteger);

    printf("%s reclen 0x%08lx\n", Tag, (unsigned long) Size);
    printf("%s rectyp 0x%08lx\n", Tag, (unsigned long) TagInteger);

    switch (TagInteger)
    {
    default:
        break;

    case S_END:
        break;

    case S_SYMBOLS: /* F1 */
        End = p;
        p = (u.p + 8);
        while (p < End)
        {
            p = DumpCodeViewSymbolRecord(1, p);
        }
        break;

    case S_SOURCE_FILE_INFO_STRING_TABLE: /* 0xF3 */
        break;

    case S_SOURCE_FILE_INFO: /* 0xF4 */
        break;

    case S_LINE_NUMBERS: /* 0xF2 */
        break;

    case S_UNKNOWN_1108:
        printf("%s name %s\n", Tag, u.Unknown1108->name);
    case S_UNKNOWN_00F5:
    case S_UNKNOWN_1012:
    case S_UNKNOWN_1515:
        DumpBytes(q, Size + 2);
        break;

    case S_LDATA32_16t:
    case S_GDATA32_16t:
    case S_PUB32_16t:
        printf("%s off 0x%08lx\n", Tag, (unsigned long) GetULE(u.DataSym32_16t->off));
        printf("%s seg 0x%08lx\n", Tag, (unsigned long) GetULE(u.DataSym32_16t->seg));
        printf("%s typind 0x%08lx\n", Tag, (unsigned long) GetULE(u.DataSym32_16t->typind));
        printf("%s name %.*s\n", Tag, u.DataSym32_16t->name[0], &u.DataSym32_16t->name[1]);
        break;
    case S_LDATA32:
    case S_GDATA32:
    case S_PUB32:
        printf("%s off 0x%08lx\n", Tag, (unsigned long) GetULE(u.DataSym32->off));
        printf("%s seg 0x%08lx\n", Tag, (unsigned long) GetULE(u.DataSym32->seg));
        printf("%s typind 0x%08lx\n", Tag, (unsigned long) GetULE(u.DataSym32->typind));
        printf("%s name %.*s\n", Tag, u.DataSym32->name[0], &u.DataSym32->name[1]);
        break;
    case S_LDATA2: /* 0x110C */
    case S_GDATA2: /* 0x110D */
        printf("%s typind 0x%08lx\n", Tag, (unsigned long) GetULE(u.DataSym2->typind));
        printf("%s off 0x%08lx\n", Tag, (unsigned long) GetULE(u.DataSym2->off));
        printf("%s seg 0x%08lx\n", Tag, (unsigned long) GetULE(u.DataSym2->seg));
        printf("%s name %s\n", Tag, u.DataSym2->name);
        break;
    case S_UDT_16t:
    case S_COBOLUDT_16t:
        printf("%s typind 0x%08lx\n", Tag, (unsigned long) GetULE(u.UdtSym_16t->typind));
        printf("%s name %.*s\n", Tag, u.UdtSym_16t->name[0], &u.UdtSym_16t->name[1]);
        break;
    case S_UDT:
    case S_COBOLUDT:
        printf("%s typind 0x%08lx\n", Tag, (unsigned long) GetULE(u.UdtSym->typind));
        printf("%s name %.*s\n", Tag, u.UdtSym->name[0], &u.UdtSym->name[1]);
        break;
    case S_BLOCK32:
        printf("%s pParent 0x%08lx\n", Tag, (unsigned long) GetULE(u.BlockSym32->pParent));
        printf("%s pEnd 0x%08lx\n", Tag, (unsigned long) GetULE(u.BlockSym32->pEnd));
        printf("%s len 0x%08lx\n", Tag, (unsigned long) GetULE(u.BlockSym32->len));
        printf("%s off 0x%08lx\n", Tag, (unsigned long) GetULE(u.BlockSym32->off));
        printf("%s seg 0x%08lx\n", Tag, (unsigned long) GetULE(u.BlockSym32->seg));
        printf("%s name %.*s\n", Tag, u.BlockSym32->name[0], &u.BlockSym32->name[1]);
        break;
    case S_LABEL2: /* 0x1105 */
        printf("%s off 0x%08lx\n", Tag, (unsigned long) GetULE(u.LabelSym2->off));
        printf("%s seg 0x%08lx\n", Tag, (unsigned long) GetULE(u.LabelSym2->seg));
        DumpCVProcFlags(Tag, GetULE(u.LabelSym2->flags));
        printf("%s name 0x%s\n", Tag, u.LabelSym2->name);
        break;
    case S_LABEL32:
        printf("%s off 0x%08lx\n", Tag, (unsigned long) GetULE(u.LabelSym32->off));
        printf("%s seg 0x%08lx\n", Tag, u.LabelSym32->seg);
        DumpCVProcFlags(Tag, GetULE(u.LabelSym32->flags.u.bAll));
        printf("%s name %.*s\n", Tag, u.LabelSym32->name[0], &u.LabelSym32->name[1]);
        break;
    case S_OBJNAME:
        printf("%s signature 0x%08lx\n", Tag, (unsigned long) GetULE(u.ObjNameSym->signature));
        printf("%s name %.*s\n", Tag, u.ObjNameSym->name[0], &u.ObjNameSym->name[1]);
        break;
    case S_OBJNAME2:/* 0x1101 */
        printf("%s signature 0x%08lx\n", Tag, (unsigned long) GetULE(u.ObjNameSym2->signature));
        printf("%s name %s\n", Tag, u.ObjNameSym->name);
        break;
    case S_COMPILE:
        printf("%s machine 0x%08lx\n", Tag, (unsigned long) GetULE(u.CFlagSym->machine));
        printf("%s language 0x%08lx\n", Tag, (unsigned long) u.CFlagSym->flags.language);
        printf("%s pcode 0x%08lx\n", Tag, (unsigned long) u.CFlagSym->flags.pcode);
        printf("%s floatprec 0x%08lx\n", Tag, (unsigned long) u.CFlagSym->flags.floatprec);
        printf("%s floatpkg 0x%08lx\n", Tag, (unsigned long) u.CFlagSym->flags.floatpkg);
        printf("%s ambdata 0x%08lx\n", Tag, (unsigned long) u.CFlagSym->flags.ambdata);
        printf("%s ambcode 0x%08lx\n", Tag, (unsigned long) u.CFlagSym->flags.ambcode);
        printf("%s mode32 0x%08lx\n", Tag, (unsigned long) u.CFlagSym->flags.mode32);
        printf("%s ver: %.*s\n", Tag, u.CFlagSym->ver[0], &u.CFlagSym->ver[1]);
        //p += (4 - ((p - q) % 4));
        break;
    case S_COMPILE2:/* 0x1116 */
        version = GetULE(u.CFlagSym2->version);
        printf(
            "%s language 0x%08lx\n"
            "%s machine 0x%08lx\n"
            "%s flags 0x%08lx\n"
            "%s unknown 0x%08lx\n"
            "%s version 0x%08lx (%lu)\n"
            "%s creater %s\n",
            Tag, ((unsigned long) GetULE(u.CFlagSym2->language)),
            Tag, ((unsigned long) GetULE(u.CFlagSym2->machine)),
            Tag, ((unsigned long) GetULE(u.CFlagSym2->flags)),
            Tag, ((unsigned long) GetULE(u.CFlagSym2->unknown)),
            Tag, ((unsigned long) version), ((unsigned long) version),
            Tag, u.CFlagSym2->creater
            );
        key = (u.CFlagSym2->creater + strlen(u.CFlagSym2->creater) + 1);
        i = 0;
        while (*key)
        {
            char* value = (key + strlen(key) + 1);
            printf("%s data[0x%08lx] %s=%s\n", Tag, (unsigned long) i, key, value);
            key = (value + strlen(value) + 1);
            i += 1;
        }
        //if (IsDebuggerPresent()) DebugBreak();
        key += 2;
        p = (unsigned char*) key;
        p += (4 - ((p - q) % 4));
        break;
    case S_BPREL32_16t:
        printf("%s off 0x%08lx\n", Tag, (unsigned long) GetULE(u.BPRelSym32_16t->off));
        printf("%s typeind 0x%08lx\n", Tag, (unsigned long) GetULE(u.BPRelSym32_16t->typind));
        printf("%s name %.*s\n", Tag, u.BPRelSym32_16t->name[0], &u.BPRelSym32_16t->name[1]);
        break;
    case S_BPREL32:
        printf("%s off 0x%08lx\n", Tag, (unsigned long) GetULE(u.BPRelSym32->off));
        printf("%s typeind 0x%08lx\n", Tag, (unsigned long) GetULE(u.BPRelSym32->typind));
        printf("%s name %.*s\n", Tag, u.BPRelSym32->name[0], &u.BPRelSym32->name[1]);
        break;
    case S_BPREL2:
        printf("%s off 0x%08lx\n", Tag, (unsigned long) GetULE(u.BPRelSym2->off));
        printf("%s typeind 0x%08lx\n", Tag, (unsigned long) GetULE(u.BPRelSym2->typind));
        printf("%s name %s\n", Tag, u.BPRelSym2->name);
        break;
    case S_GPROC32_16t:
    case S_LPROC32_16t:
        printf("%s pParent 0x%08lx\n", Tag, (unsigned long) GetULE(u.ProcSym32_16t->pParent));
        printf("%s pEnd 0x%08lx\n", Tag, (unsigned long) GetULE(u.ProcSym32_16t->pEnd));
        printf("%s pNext 0x%08lx\n", Tag, (unsigned long) GetULE(u.ProcSym32_16t->pNext));
        printf("%s len 0x%08lx\n", Tag, (unsigned long) GetULE(u.ProcSym32_16t->len));
        printf("%s DbgStart 0x%08lx\n", Tag, (unsigned long) GetULE(u.ProcSym32_16t->DbgStart));
        printf("%s DbgEnd 0x%08lx\n", Tag, (unsigned long) GetULE(u.ProcSym32_16t->DbgEnd));
        printf("%s off 0x%08lx\n", Tag, (unsigned long) GetULE(u.ProcSym32_16t->off));
        printf("%s seg 0x%08lx\n", Tag, (unsigned long) GetULE(u.ProcSym32_16t->seg));
        printf("%s typeind 0x%08lx\n", Tag, (unsigned long) GetULE(u.ProcSym32_16t->typind));
        DumpCVProcFlags(Tag, GetULE(u.ProcSym32_16t->flags.u.bAll));
        printf("%s name %.*s\n", Tag, u.ProcSym32_16t->name[0], &u.ProcSym32_16t->name[1]);
        break;
    case S_GPROC32:
    case S_LPROC32:
        printf("%s pParent 0x%08lx\n", Tag, (unsigned long) GetULE(u.ProcSym32->pParent));
        printf("%s pEnd 0x%08lx\n", Tag, (unsigned long) GetULE(u.ProcSym32->pEnd));
        printf("%s pNext 0x%08lx\n", Tag, (unsigned long) GetULE(u.ProcSym32->pNext));
        printf("%s len 0x%08lx\n", Tag, (unsigned long) GetULE(u.ProcSym32->len));
        printf("%s DbgStart 0x%08lx\n", Tag, (unsigned long) GetULE(u.ProcSym32->DbgStart));
        printf("%s DbgEnd 0x%08lx\n", Tag, (unsigned long) GetULE(u.ProcSym32->DbgEnd));
        printf("%s typeind 0x%08lx\n", Tag, (unsigned long) GetULE(u.ProcSym32->typind));
        printf("%s off 0x%08lx\n", Tag, (unsigned long) GetULE(u.ProcSym32->off));
        printf("%s seg 0x%08lx\n", Tag, (unsigned long) GetULE(u.ProcSym32->seg));
        DumpCVProcFlags(Tag, GetULE(u.ProcSym32->flags.u.bAll));
        printf("%s name %.*s\n", Tag, u.ProcSym32->name[0], &u.ProcSym32->name[1]);
        break;
    case S_GPROC2: /* 0x1110 */
        printf("%s pParent 0x%08lx\n", Tag, (unsigned long) GetULE(u.ProcSym2->pParent));
        printf("%s pEnd 0x%08lx\n", Tag, (unsigned long) GetULE(u.ProcSym2->pEnd));
        printf("%s pNext 0x%08lx\n", Tag, (unsigned long) GetULE(u.ProcSym2->pNext));
        printf("%s len 0x%08lx\n", Tag, (unsigned long) GetULE(u.ProcSym2->len));
        printf("%s DbgStart 0x%08lx\n", Tag, (unsigned long) GetULE(u.ProcSym2->DbgStart));
        printf("%s DbgEnd 0x%08lx\n", Tag, (unsigned long) GetULE(u.ProcSym2->DbgEnd));
        printf("%s off 0x%08lx\n", Tag, (unsigned long) GetULE(u.ProcSym2->off));
        printf("%s seg 0x%08lx\n", Tag, (unsigned long) GetULE(u.ProcSym2->seg));
        printf("%s typeind 0x%08lx\n", Tag, (unsigned long) GetULE(u.ProcSym2->typind));
        DumpCVProcFlags(Tag, GetULE(u.ProcSym2->flags));
        printf("%s name %s\n", Tag, u.ProcSym2->name);
        break;
    case S_PROCREF:
        printf("%s sumName 0x%08lx\n", Tag, (unsigned long) GetULE(u.RefSym->sumName));
        printf("%s ibSym 0x%08lx\n", Tag, (unsigned long) GetULE(u.RefSym->ibSym));
        printf("%s imod 0x%08lx\n", Tag, (unsigned long) GetULE(u.RefSym->imod));
        p  = (unsigned char*) (1 + u.RefSym);
        printf("%s name %.*s\n", Tag, p[0], (p + 1));
        p += 1 + p[0];
        p = (unsigned char*) ((((size_t)p) + 3) & ~3);
        break;
    case S_THUNK32:
        printf("%s name %.*s\n", Tag, u.ThunkSym32->name[0], &u.ThunkSym32->name[1]);
        break;
    }

    return p;
}

unsigned char*
CodeViewGetStructSize(
    unsigned char* p,
    size_t* Size
    )
{
    size_t SizeTag = 0;

    SizeTag = GetULEn(p, 2);
    p += 2;
    if (SizeTag < LF_NUMERIC)
    {
        *Size = SizeTag;
    }
    else
    {
        switch (SizeTag)
        {
        case LF_ULONG:
            *Size = GetULEn(p, 4);
            p += 4;
            break;
        default:
            *Size = 0;
            break;
        }
    }
    return p;
}

void
DumpCodeViewPointerAttributes(
    const char* Tag,
    lfPointerAttr attr
    )
{
    printf("%s attr.ptrtype 0x%08lx\n", Tag, (unsigned long) attr.ptrtype);
    printf("%s attr.ptrmode 0x%08lx\n", Tag, (unsigned long) attr.ptrmode);
    printf("%s attr.isflat32 0x%08lx\n", Tag, (unsigned long) attr.isflat32);
    printf("%s attr.isvolatile 0x%08lx\n", Tag, (unsigned long) attr.isvolatile);
    printf("%s attr.isconst 0x%08lx\n", Tag, (unsigned long) attr.isconst);
    printf("%s attr.isunaligned 0x%08lx\n", Tag, (unsigned long) attr.isunaligned);
    printf("%s attr.unused 0x%08lx\n", Tag, (unsigned long) attr.unused);
}

void
DumpCodeViewProperty(
    const char* Tag,
    CV_prop_t Property
    )
{
    printf("%s property.packed 0x%08lx\n", Tag, (unsigned long) Property.packed);
    printf("%s property.ctor 0x%08lx\n", Tag, (unsigned long) Property.ctor);
    printf("%s property.ovlops 0x%08lx\n", Tag, (unsigned long) Property.ovlops);
    printf("%s property.isnested 0x%08lx\n", Tag, (unsigned long) Property.isnested);
    printf("%s property.cnested 0x%08lx\n", Tag, (unsigned long) Property.cnested);
    printf("%s property.opassign 0x%08lx\n", Tag, (unsigned long) Property.opassign);
    printf("%s property.opcast 0x%08lx\n", Tag, (unsigned long) Property.opcast);
    printf("%s property.fwdref 0x%08lx\n", Tag, (unsigned long) Property.fwdref);
    printf("%s property.scoped 0x%08lx\n", Tag, (unsigned long) Property.scoped);
    printf("%s property.reserved 0x%08lx\n", Tag, (unsigned long) Property.reserved);
}

unsigned char*
DumpCodeViewTypeRecord(
    unsigned char* p
    )
{
    unsigned char* q = p;
    size_t i;
    size_t Size;
    size_t TagInteger;
    size_t StructSize;
    const char* Tag;
    size_t count;
    union {
        lfUnion*     Union;
        lfUnion_16t* Union16;
        lfStructure* Structure;
        lfStructure_16t* Structure16;
        lfPointer* Pointer;
        lfPointer_16t* Pointer16;
        lfFieldList* FieldList;
        lfTypeServer* TypeServer;
        lfProc* Proc;
        lfProc_16t* Proc16;
        lfArgList* ArgList;
        lfArgList_16t* ArgList16;
        void* p;
    } u;

    Size = GetULEn(p, 2);
    p += 2;
    u.p = p;
    TagInteger = GetULEn(p, 2);
    p += Size;

    Tag = GetCodeViewLeafTagString(TagInteger);

    printf("%s size 0x%08lx\n", Tag, (unsigned long) Size);
    printf("%s leaf 0x%08lx\n", Tag, (unsigned long) TagInteger);

    switch (TagInteger)
    {
    default:
        DumpBytes(q, Size + 2);
        break;

    case LF_ARGLIST_16t:
        count = GetULE(u.ArgList16->count);
        printf("%s count 0x%08lx\n", Tag, (unsigned long) count);
        for (i = 0 ; i != count ; ++i)
        {
            printf("%s arg[0x%08lx] 0x%08lx\n", Tag, (unsigned long) i, GetULE(u.ArgList16->arg[i]));
        }
        break;

    case LF_ARGLIST:
        count = GetULE(u.ArgList->count);
        printf("%s count 0x%08lx\n", Tag, (unsigned long) count);
        for (i = 0 ; i != count ; ++i)
        {
            printf("%s arg[0x%08lx] 0x%08lx\n", Tag, (unsigned long) i, GetULE(u.ArgList->arg[i]));
        }
        break;

    case LF_PROCEDURE:
        printf("%s rvtype 0x%08lx\n", Tag, (unsigned long) GetULE(u.Proc->rvtype));
        printf("%s calltype 0x%08lx\n", Tag, (unsigned long) GetULE(u.Proc->calltype));
        printf("%s reserved 0x%08lx\n", Tag, (unsigned long) GetULE(u.Proc->reserved));
        printf("%s parmcount 0x%08lx\n", Tag, (unsigned long) GetULE(u.Proc->parmcount));
        printf("%s arglist 0x%08lx\n", Tag, (unsigned long) GetULE(u.Proc->arglist));
        break;

    case LF_PROCEDURE_16t:
        printf("%s rvtype 0x%08lx\n", Tag, (unsigned long) GetULE(u.Proc16->rvtype));
        printf("%s calltype 0x%08lx\n", Tag, (unsigned long) GetULE(u.Proc16->calltype));
        printf("%s reserved 0x%08lx\n", Tag, (unsigned long) GetULE(u.Proc16->reserved));
        printf("%s parmcount 0x%08lx\n", Tag, (unsigned long) GetULE(u.Proc16->parmcount));
        printf("%s arglist 0x%08lx\n", Tag, (unsigned long) GetULE(u.Proc16->arglist));
        break;

    case LF_TYPESERVER:
        printf("%s signature 0x%08lx\n", Tag, (unsigned long) GetULE(u.TypeServer->signature));
        printf("%s age 0x%08lx\n", Tag, (unsigned long) GetULE(u.TypeServer->age));
        printf("%s signature 0x%08lx\n", Tag, (unsigned long) GetULE(u.TypeServer->signature));
        printf("%s name %.*s\n", Tag, u.TypeServer->name[0], &u.TypeServer->name[1]);
        break;

    case LF_FIELDLIST:
    case LF_FIELDLIST_16t:
        q = CodeViewGetStructSize(u.FieldList->data, &StructSize);
        printf("%s size 0x%08lx\n", Tag, (unsigned long) StructSize);
        break;

    case LF_POINTER_16t:
        DumpCodeViewPointerAttributes(Tag, u.Pointer16->attr);
        printf("%s utype 0x%08lx\n", Tag, (unsigned long) GetULE(u.Pointer16->utype));
        break;

    case LF_POINTER:
        DumpCodeViewPointerAttributes(Tag, u.Pointer->attr);
        printf("%s utype 0x%08lx\n", Tag, (unsigned long) GetULE(u.Pointer->utype));
        break;

    case LF_UNION_16t:
        printf("%s count 0x%08lx\n", Tag, (unsigned long) GetULE(u.Union16->count));
        DumpCodeViewProperty(Tag, u.Union16->property);
        q = CodeViewGetStructSize(u.Union16->data, &StructSize);
        printf("%s size 0x%08lx\n", Tag, (unsigned long) StructSize);
        printf("%s name %.*s\n", Tag, *q, (q + 1));
        break;

    case LF_UNION:
        printf("%s count 0x%08lx\n", Tag, (unsigned long) GetULE(u.Union->count));
        DumpCodeViewProperty(Tag, u.Union16->property);
        q = CodeViewGetStructSize(u.Union->data, &StructSize);
        printf("%s size 0x%08lx\n", Tag, (unsigned long) StructSize);
        printf("%s name %.*s\n", Tag, *q, (q + 1));
        break;
    
    case LF_CLASS:
    case LF_STRUCTURE:
        printf("%s count 0x%08lx\n", Tag, (unsigned long) GetULE(u.Structure->count));
        printf("%s field 0x%08lx\n", Tag, (unsigned long) GetULE(u.Structure->field));
        DumpCodeViewProperty(Tag, u.Union16->property);
        printf("%s derived 0x%08lx\n", Tag, (unsigned long) GetULE(u.Structure->derived));
        printf("%s vshape 0x%08lx\n", Tag, (unsigned long) GetULE(u.Structure->vshape));
        q = CodeViewGetStructSize(u.Structure->data, &StructSize);
        printf("%s size 0x%08lx\n", Tag, (unsigned long) StructSize);
        printf("%s name %.*s\n", Tag, *q, (q + 1));
        break;
    case LF_CLASS_16t:
    case LF_STRUCTURE_16t:
        printf("%s count 0x%08lx\n", Tag, (unsigned long) GetULE(u.Structure16->count));
        printf("%s field 0x%08lx\n", Tag, (unsigned long) GetULE(u.Structure16->field));
        DumpCodeViewProperty(Tag, u.Union16->property);
        printf("%s derived 0x%08lx\n", Tag, (unsigned long) GetULE(u.Structure16->derived));
        printf("%s vshape 0x%08lx\n", Tag, (unsigned long) GetULE(u.Structure16->vshape));
        q = CodeViewGetStructSize(u.Structure16->data, &StructSize);
        printf("%s size 0x%08lx\n", Tag, (unsigned long) StructSize);
        printf("%s name %.*s\n", Tag, *q, (q + 1));
        break;
    }

    return p;
}

void
DumpCodeViewSymbols(
    BOOL HasSignature,
    unsigned char* p,
    size_t n
    )
{
    unsigned char* End = 0;
    size_t Signature = 0;

    End = (p + n);
    if (HasSignature)
    {
        Signature = GetULEn(p, 4);
        p += 4;
        printf("Signature 0x%08lx\n", (unsigned long) Signature);
    }
    //if (Signature == 1 || Signature == 2)
    {
        while (p < End)
        {
            p = DumpCodeViewSymbolRecord(Signature, p);
        }
    }
    //else
    {
        //printf("This format is not understood.\n");
    }
}

void
DumpCodeViewTypes(
    BOOL HasSignature,
    unsigned char* p,
    size_t n
    )
{
    unsigned char* End = 0;
    size_t Signature = 0;

    End = (p + n);
    if (HasSignature)
    {
        Signature = GetULEn(p, 4);
        p += 4;
        printf("Signature 0x%08lx\n", Signature);
    }
    //if (Signature == 1 || Signature == 2)
    {
        while (p < End)
        {
            p = DumpCodeViewTypeRecord(p);
        }
    }
    //else
    {
        //printf("This format is not understood.\n");
    }
}

void
DumpOMFDirEntry(
    unsigned char* CodeViewBase,
    OMFDirEntry* Entry,
    size_t k
    )
{
    unsigned long i;
    union {
        void* p;
        OMFModule* Module;
        OMFLibrary* Library;
    } u;
    unsigned char* p;
    size_t j;
    size_t cSeg;
    size_t cb;
    unsigned lfo;
    unsigned SubsectionIndex;
    const char* SubsectionName;

    i = (unsigned long) k;
    SubsectionIndex = GetULE(Entry->SubSection);
    SubsectionName = GetSubsectionName(SubsectionIndex);
    lfo = GetULE(Entry->lfo);
    cb = GetULE(Entry->cb);
    
    printf("\n");
    printf("OMFDirEntry[0x%08lx] %s SubSection 0x%08lx\n", i, SubsectionName, SubsectionIndex);
    printf("OMFDirEntry[0x%08lx] %s iMod 0x%08lx\n", i, SubsectionName, GetULE(Entry->iMod));
    printf("OMFDirEntry[0x%08lx] %s lfo 0x%08lx\n", i, SubsectionName, lfo);
    printf("OMFDirEntry[0x%08lx] %s cb 0x%08lx\n", i, SubsectionName, cb);

    u.p = (CodeViewBase + lfo);
    switch (SubsectionIndex)
    {
    case sstModule:
        cSeg = GetULEn(&u.Module->cSeg, 2);
        printf("OMFDirEntry[0x%08lx] sstModule ovlNumber 0x%08lx\n", i, (unsigned long) GetULE(u.Module->ovlNumber));
        printf("OMFDirEntry[0x%08lx] sstModule iLib 0x%08lx\n", i, (unsigned long) GetULE(u.Module->iLib));
        printf("OMFDirEntry[0x%08lx] sstModule cSeg 0x%08lx\n", i, (unsigned long) cSeg);
        printf("OMFDirEntry[0x%08lx] sstModule Style %.02s\n", i, &u.Module->Style);
        for (j = 0 ; j != cSeg ; ++j)
        {
            printf("OMFDirEntry[0x%08lx] sstModule OMFSegDesc[0x%08lx] Seg 0x%08lx\n", i, j, (unsigned long) GetULE(u.Module->SegInfo[j].Seg));
            printf("OMFDirEntry[0x%08lx] sstModule OMFSegDesc[0x%08lx] Off 0x%08lx\n", i, j, (unsigned long) GetULE(u.Module->SegInfo[j].Off));
            printf("OMFDirEntry[0x%08lx] sstModule OMFSegDesc[0x%08lx] cbSeg 0x%08lx\n", i, j, (unsigned long) GetULE(u.Module->SegInfo[j].cbSeg));
        }
        p = (unsigned char*) &u.Module->SegInfo[cSeg];
        //printf("OMFDirEntry[0x%08lx] sstModule NameLength 0x%08lx\n", i, p, p[0]);
        printf("OMFDirEntry[0x%08lx] sstModule Name %.*s\n", i, p[0], (p + 1));
        break;

    case sstTypes:
        printf("OMFDirEntry[0x%08lx] sstType %p\n", i, GetULE(u.Module->ovlNumber));
        break;
    case sstPublic:
        break;
    case sstPublicSym:
        break;
    case sstSymbols:
        break;
    case sstAlignSym:
        break;
    case sstSrcLnSeg:
        break;
    case sstSrcModule:
        break;

    case sstLibraries:
        p = (unsigned char*) u.Library;
        for (j = 0 ; j < cb ; ++j)
        {
            unsigned char Length = p[0];
            printf("OMFDirEntry[0x%08lx] sstLibraries [0x%08lx] %p Name %.*s\n", i, j, p, Length, (p + 1));
            p += 1 + Length;
            j += 1 + Length;
        }
        break;

    case sstGlobalSym:
        break;
    case sstGlobalPub:
        break;
    case sstGlobalTypes:
        break;
    case sstMPC:
        break;
    case sstSegMap:
        break;
    case sstSegName:
        break;
    case sstPreComp:
        break;
    case sstPreCompMap:
        break;
    case sstOffsetMap16:
        break;
    case sstOffsetMap32:
        break;
    case sstFileIndex:
        break;
    case sstStaticSym:
        break;
    case SSTMODULE:
    case SSTPUBLIC:
    case SSTTYPES:
    case SSTSYMBOLS:
    case SSTSRCLINES:
    case SSTLIBRARIES:
    case SSTIMPORTS:
    case SSTCOMPACTED:
    case SSTSRCLNSEG:
        printf("old stuff\n");
        break;
    }
}

long
GetBytesFromFile(
    MY_FILE* File,
    size_t Offset,
    size_t Size,
    void* Buffer
    )
{
    if (Offset > File->Size)
    {
        return -1;
    }
    if ((Offset + Size) < Offset)
    {
        return -1;
    }
    if ((Offset + Size) > File->Size)
    {
        return -1;
    }
    memcpy(Buffer, File->Contents + Offset, Size);
    return 0;
}

long
GetLESizeTFromFile(
    MY_FILE* File,
    size_t Offset,
    size_t Size,
    size_t* Out
    )
{
    if (Offset > File->Size)
    {
        return -1;
    }
    if ((Offset + Size) < Offset)
    {
        return -1;
    }
    if ((Offset + Size) > File->Size)
    {
        return -1;
    }

    *Out = GetULEn(File->Contents + Offset, Size);
    return 0;
}

void
Lowercase(
    char* a
    )
{
    char b;
    while ((b = *a) != 0)
    {
        if (b >= 'A' && b <= 'Z')
        {
            *a = ('b' - 'A' + 'a');
        }
        a += 1;
    }
}

int
__cdecl
main(
    int argc,
    char** argv
    )
{
    int ExitCode = 1;
    long Status = -1;
    MY_FILE File = { 0 };
    PDB_HEADER PdbHeader = { 0 };
    STREAM Stream = { 0 };
    STREAM* Streams = 0;
    size_t PageSize = 0;
    size_t i = 0;
    size_t StreamCount = 0;
    unsigned char* Pages = 0;
    unsigned char* Sizes = 0;
    IMAGE_FILE_HEADER ObjHeader = { 0 };
    IMAGE_SECTION_HEADER SectionHeader = { 0 };
    char* Extension = 0;
    size_t TotalStreamsSize = 0;

    if (argc != 2)
        goto Exit;

    if (!argv[1])
        goto Exit;

    Status = ReadEntireFileInMemory(argv[1], &File);
    if (Status < 0)
        goto Exit;

    Extension = strchr(argv[1], '.');
    if (Extension == NULL)
        Extension = "";
    else
        Extension += 1;

    Lowercase(Extension);

    if (strcmp(Extension, "obj") == 0)
    {
        //
        // Dump sections named .debug$S (symbols) and .debug$T (types)
        //
        size_t PointerToRawData;
        size_t SizeOfRawData;
        size_t NumberOfSections ;

        GetBytesFromFile(&File, 0, sizeof(ObjHeader), &ObjHeader);
        NumberOfSections = GetULE(ObjHeader.NumberOfSections);
        for (i = 0 ; i != NumberOfSections ; ++i)
        {
            GetBytesFromFile(&File, sizeof(ObjHeader) + i * sizeof(SectionHeader), sizeof(SectionHeader), &SectionHeader);
            if (memcmp(SectionHeader.Name, ".debug$S", 8) == 0)
            {
                printf("%.8s\n", SectionHeader.Name);
                PointerToRawData = GetULE(SectionHeader.PointerToRawData);
                SizeOfRawData = GetULE(SectionHeader.SizeOfRawData);
                DumpCodeViewSymbols(TRUE, File.Contents + PointerToRawData, SizeOfRawData);
            }
            else if (memcmp(SectionHeader.Name, ".debug$T", 8) == 0)
            {
                printf("%.8s\n", SectionHeader.Name);
                PointerToRawData = GetULE(SectionHeader.PointerToRawData);
                SizeOfRawData = GetULE(SectionHeader.SizeOfRawData);
                DumpCodeViewTypes(TRUE, File.Contents + PointerToRawData, SectionHeader.SizeOfRawData);
            }
        }
    }
    else if ((strcmp(Extension, "exe") == 0) || (strcmp(Extension, "dll") == 0))
    {
        //
        // CodeView data in an .exe/.dll
        // Note: We should probably look at the PE debug directory to handle signed binaries?
        //
        size_t NegativeOffsetToCodeViewBase = 0;
        size_t CodeViewBase = 0;
        unsigned char Sig1[4] = { 0 };
        unsigned char Sig2[4] = { 0 };
        size_t OffsetToOMDirHeader = 0;
        OMFDirHeader Header = { 0 };
        OMFDirEntry Entry = { 0 };
        size_t i = 0;
        size_t cDir = 0;
        size_t cbDirEntry = 0;
        size_t cbDirHeader = 0;
        size_t OffsetToOMFDirEntry = 0;

        if (File.Size <= 8)
        {
            printf(".exe/.dll too small to have symbols\n");
            return -1;
        }
        Status = GetBytesFromFile(&File, (File.Size - 8), sizeof(Sig1), &Sig1);
        if (Status < 0)
        {
            printf("file corrupt\n");
            return Status;
        }
        Status = GetLESizeTFromFile(&File, (File.Size - 4), 4, &NegativeOffsetToCodeViewBase);
        if (Status < 0)
        {
            printf("file corrupt\n");
            return Status;
        }

        if (memcmp(Sig1, "NB09", 4) == 0)
        {
            printf("CodeView version <=4 embedded in .exe/.dll\n");
        }
        else if (memcmp(Sig1, "NB11", 4) == 0)
        {
            printf("CodeView version >=5 embedded in .exe/.dll\n");
        }
        else
        {
            printf("no symbols in .exe/.dll\n");
            return -1;
        }
        if (NegativeOffsetToCodeViewBase >= (File.Size - 8))
        {
            printf("file corrupt/too small\n");
            return -1;
        }
        CodeViewBase = (File.Size - NegativeOffsetToCodeViewBase);
        Status = GetBytesFromFile(&File, CodeViewBase, sizeof(Sig2), &Sig2);
        if (Status < 0)
            return Status;
        if (memcmp(Sig1, Sig2, 4) != 0)
        {
            printf("file corrupt\n");
            return -1;
        }
        Status = GetLESizeTFromFile(&File, (CodeViewBase + 4), 4, &OffsetToOMDirHeader);
        if (Status < 0)
        {
            printf("file corrupt\n");
            return Status;
        }
        if (OffsetToOMDirHeader >= File.Size)
        {
            printf("file corrupt\n");
            return -1;
        }

        Status = GetBytesFromFile(&File, (CodeViewBase + OffsetToOMDirHeader), sizeof(Header), &Header);
        if (Status < 0)
        {
            printf("file corrupt\n");
            return Status;
        }

        cDir = GetULE(Header.cDir);
        cbDirEntry = GetULE(Header.cbDirEntry);
        cbDirHeader = GetULE(Header.cbDirHeader);

        printf("OMFDirHeader cbDirHeader 0x%08lx\n", &Header.cbDirHeader, cbDirHeader);
        printf("OMFDirHeader cbDirEntry 0x%08lx\n", &Header.cbDirEntry, GetULE(Header.cbDirEntry));
        printf("OMFDirHeader cDir 0x%08lx\n", &Header.cDir, cDir);
        printf("OMFDirHeader lfoNextDir 0x%08lx\n", &Header.lfoNextDir, GetULE(Header.lfoNextDir));
        printf("OMFDirHeader flags 0x%08lx\n", &Header.flags, GetULE(Header.flags));

        OffsetToOMFDirEntry = (CodeViewBase + OffsetToOMDirHeader + cbDirHeader);

        for (i = 0 ; i != cDir ; ++i)
        {
            Status = GetBytesFromFile(&File, OffsetToOMFDirEntry, sizeof(Entry), &Entry);
            if (Status < 0)
            {
                printf("file corrupt\n");
                return Status;
            }
            DumpOMFDirEntry(File.Contents + CodeViewBase, &Entry, i);
            OffsetToOMFDirEntry += cbDirEntry;
        }
    }
    else if (strcmp(Extension, "pdb") == 0)
    {
        size_t SignatureLength = 0;

        if (memcmp(File.Contents, PDB_SIGNATURE1, sizeof(PDB_SIGNATURE1)) == 0)
        {
            PDB_HEADER1* PdbHeader1 = (PDB_HEADER1*) File.Contents;
            SignatureLength = (sizeof(PDB_SIGNATURE1) - 7);
            PdbHeader.PageSize = GetULE(PdbHeader1->PageSize);
            PdbHeader.StartPage = GetULE(PdbHeader1->StartPage);
            PdbHeader.FilePages = GetULE(PdbHeader1->FilePages);
            PdbHeader.RootStreamSize = GetULE(PdbHeader1->RootStreamSize);
            PdbHeader.RootStreamPages = PdbHeader1->RootStreamPages;
            PdbHeader.PageIndexSize = 2;
            PdbHeader.StreamCountSize = 2;
            PdbHeader.PagingLevels = 1;
            PdbHeader.OffsetToTypes = 0x10;

            PdbHeader.Streams[2].Types = TRUE;
            PdbHeader.Streams[4].Symbols = TRUE;
            PdbHeader.Streams[4].SymbolsSignature = TRUE;
            PdbHeader.Streams[7].Symbols = TRUE;
            PdbHeader.Streams[7].SymbolsSignature = TRUE;
        }
        else if (memcmp(File.Contents, PDB_SIGNATURE2, sizeof(PDB_SIGNATURE2)) == 0)
        {
            PDB_HEADER2* PdbHeader2 = (PDB_HEADER2*) File.Contents;
            SignatureLength = (sizeof(PDB_SIGNATURE2) - 7);
            PdbHeader.PageSize = GetULE(PdbHeader2->PageSize);
            PdbHeader.StartPage = GetULE(PdbHeader2->StartPage);
            PdbHeader.FilePages = GetULE(PdbHeader2->FilePages);
            PdbHeader.RootStreamSize = GetULE(PdbHeader2->RootStreamSize);
            PdbHeader.RootStreamPages = PdbHeader2->RootStreamPages;
            PdbHeader.PageIndexSize = 4;
            PdbHeader.StreamCountSize = 4;
            PdbHeader.PagingLevels = 2;
            PdbHeader.OffsetToTypes = 0x34;
        }

        PageSize = PdbHeader.PageSize;
        printf(
            "Signature: %.*s\n"
            "PageSize 0x%lx\n"
            "StartPage 0x%lx\n"
            "FilePages 0x%lx\n"
            "RootStream.StreamSize 0x%lx\n"
            "RootStream.StreamPages[0] 0x%lx\n",
            SignatureLength,
            File.Contents,
            (unsigned long)PdbHeader.PageSize,
            (unsigned long)PdbHeader.StartPage,
            (unsigned long)PdbHeader.FilePages,
            (unsigned long)PdbHeader.RootStreamSize,
            (unsigned long) GetULEn(PdbHeader.RootStreamPages, 2)
            );

        fflush(stdout);

        CopyStream(&PdbHeader, &File, &Stream, PdbHeader.RootStreamSize, PdbHeader.RootStreamPages);
        DumpStream(&PdbHeader, &Stream, 0);

        /*
        root stream is
            UINT16 StreamCount
            UINT16 Reserved
            array {
                UINT32 Size
                UINT32 Unknown
            }[StreamCount]
            UINT16 Pages[]
        */
        StreamCount = GetULEn(Stream.Contents, PdbHeader.StreamCountSize);
        printf("StreamCount 0x%lx\n", (unsigned long) StreamCount);
        Sizes = (Stream.Contents + 4);
        Pages = (unsigned char*) (Sizes + PdbHeader.StreamCountSize * StreamCount * 4);

        TotalStreamsSize  = 0;
        Streams = (STREAM*) calloc(StreamCount, sizeof(STREAM));

        for (i = 0; i != StreamCount ; ++i)
        {
            size_t StreamSize = GetULEn(&Sizes[i * 2 * 4], 4);
            TotalStreamsSize += StreamSize;
            CopyStream(&PdbHeader, &File, &Streams[i], StreamSize, Pages);
            printf(
                "stream 0x%08lx size 0x%08lx first page 0x%08lx\n",
                (unsigned long) i,
                (unsigned long) Sizes[i * 2 * 4],
                (unsigned long) GetULEn(Pages, PdbHeader.PageIndexSize)
                );
            Pages += (Streams[i].NumberOfPages * PdbHeader.PageIndexSize);
        }

        for (i = 0; i != StreamCount ; ++i)
        {
            DumpStream(&PdbHeader, &Streams[i], i);
        }
        printf("TotalStreamsSize 0x%08lx (%lu)\n", (unsigned long) TotalStreamsSize, (unsigned long) TotalStreamsSize);
        printf("FileSize 0x%08lx (%lu)\n", (unsigned long) File.Size, (unsigned long) File.Size);

#if 0
        printf("..OR..\n");

        TotalStreamsSize  = 0;
        Stream = Streams[0];
        StreamCount = GetULEn(Stream.Contents, PdbHeader.StreamCountSize);
        printf("StreamCount 0x%lx\n", (unsigned long) StreamCount);
        Sizes = (Stream.Contents + 4);
        Pages = (unsigned char*) (Sizes + PdbHeader.StreamCountSize * StreamCount * 4);

        for (i = 0; i != StreamCount ; ++i)
        {
            size_t StreamSize = GetULEn(&Sizes[i * 2 * 4], 4);
            TotalStreamsSize += StreamSize;
            CopyStream(&PdbHeader, &File, &Streams[i], StreamSize, Pages);
            printf(
                "stream 0x%08lx size 0x%08lx first page 0x%08lx\n",
                (unsigned long) i,
                (unsigned long) Sizes[i * 2 * 4],
                (unsigned long) GetULEn(Pages, PdbHeader.PageIndexSize)
                );
            Pages += (Streams[i].NumberOfPages * PdbHeader.PageIndexSize);
        }
#endif

        printf("\n");
    }

    ExitCode = 0;
Exit:
    free(File.Contents);
    printf("ExitCode:%d\n", ExitCode);
    return ExitCode;
}
