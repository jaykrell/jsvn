/*

credits:

Sven Schreiber for pdb file format.
MSDN samples for cv*.h describing CV4
easily found .pdfs document CV4
CV5 documentation is on old MSDN CDs.
CV8 I will look at the yasm source
*/

#define CC_BIGINT 1
#include "pdb.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <memory.h>
#include "cvinfo.h"
#include "cvexefmt.h"
int __stdcall IsDebuggerPresent(void);
#pragma hdrstop

void
DumpCodeViewSymbols(
    BOOL HasSignature,
    BYTE* p,
    size_t n
    );

void
DumpCodeViewTypes(
    BOOL HasSignature,
    BYTE* p,
    size_t n
    );

typedef struct MY_FILE {
    BYTE* Contents;
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

    while (1)
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
            File.Contents = (BYTE*) NextBuffer;
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

    File.Contents = (BYTE*) NextBuffer;
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
    BYTE*  Contents;
    size_t Size;
    size_t NumberOfPages;
} STREAM;

UINT32
Get16(
    void* v
    )
{
    BYTE* b = (BYTE*) v;
    UINT16 a = b[1];
    a <<= 8; a |= b[0];
    return a;
}

UINT32
Get32(
    void* v
    )
{
    BYTE* b = (BYTE*) v;
    UINT32 a = b[3];
    a <<= 8; a |= b[2];
    a <<= 8; a |= b[1];
    a <<= 8; a |= b[0];
    return a;
}

UINT32
GetInteger(
    void* v,
    size_t n
    )
{
    if (n == 4)
        return Get32(v);
    else if (n == 2)
        return Get16(v);
    else
        return 0;
}


size_t
GetPage(
    PDB_HEADER* PdbHeader,
    BYTE* Pages
    )
{
    if (PdbHeader->PageIndexSize == 2)
    {
        return Get16(Pages);
    }
    else if (PdbHeader->PageIndexSize == 4)
    {
        return Get32(Pages);
    }
    return 0;
}

void
CopyStream(
    PDB_HEADER* PdbHeader,
    MY_FILE* File,
    STREAM* Stream,
    size_t StreamSize,
    BYTE* Pages
    )
{
    BYTE*   FileContents;
    size_t  PageSize;
    size_t  i;
    size_t  NumberOfPages;
    BYTE*   Contents;

    memset(Stream, 0, sizeof(*Stream));

    Contents = (BYTE*) malloc(StreamSize);
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
DumpStream(
    PDB_HEADER* PdbHeader,
    STREAM* Stream,
    size_t Index
    )
{
    size_t Size;
    BYTE* Contents;
    size_t i;

    Size = Stream->Size;
    Contents = Stream->Contents;

    printf("stream 0x%lx size 0x%lx:\n", (unsigned long)Index, (unsigned long)Stream->Size);
    for (i = 0 ; i != Size ; ++i)
    {
        if ((i != 0) && ((i % 16) == 0))
            printf("\n");
        if ((i % 16) == 0)
            printf("%06lx:", (unsigned long)i);
        if ((i % 8) == 0)
            printf(" ");
        printf("%02x ", Contents[i]);
        if (((i + 1) % 16) == 0)
        {
            size_t j;
            printf(" ");
            for (j = (i - 15) ; j <= i ; ++j)
            {
                char c = Contents[j];
                printf("%c", (c >= 32 && c < 127 && isprint(c)) ? c : '.');
            }
        }
    }
    printf("\n");
    if (Index == 2)
    {
        DumpCodeViewTypes(FALSE, &Stream->Contents[0x38], Stream->Size - 0x38);
    }
    else if (Index == 4 || Index == 5)
    {
        DumpCodeViewSymbols(TRUE, Stream->Contents, Stream->Size);
    }
    else if (Index == 9)
    {
        DumpCodeViewSymbols(FALSE, Stream->Contents, Stream->Size);
        //DumpCodeViewTypes(FALSE, &Stream->Contents[PdbHeader->OffsetToTypes], Stream->Size - PdbHeader->OffsetToTypes);
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
    X(S_VFTABLE32);
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
    X(S_VFTTABLE32);
    X(S_REGREL32);
    X(S_LTHREAD32);
    X(S_GTHREAD32);
    X(S_LPROCMIPS);
    X(S_GPROCMIPS);
    X(S_PROCREF);
    X(S_DATAREF);
    X(S_ALIGN);
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


BYTE*
DumpCodeViewSymbolRecord(
    BYTE* p
    )
{
    size_t Size;
    size_t Tag;
    const char* TagString;
    union {
        THUNKSYM32*     ThunkSym32;
        PUBSYM32_16t*   PubSym32_16t;
        PUBSYM32*       PubSym32;
        DATASYM32_16t*  DataSym32_16t;
        DATASYM32*      DataSym32;
        REFSYM*         RefSym;
        OBJNAMESYM*     ObjNameSym;
        CFLAGSYM*       CFlagSym;
        BPRELSYM32_16t* BPRelSym32_16t;
        BPRELSYM32*     BPRelSym32;
        PROCSYM32_16t*  ProcSym32_16t;
        PROCSYM32*      ProcSym32;
        LABELSYM32*     LabelSym32;
        BLOCKSYM32*     BlockSym32;
        UDTSYM_16t*     UdtSym_16t;
        UDTSYM*         UdtSym;
        void* p;
    } u;

    u.p = p;
    Size = Get16(p);
    p += 2;
    Tag = Get16(p);
    p += Size;

    TagString = GetCodeViewSymbolTagString(Tag);

    switch (Tag)
    {
    default:
        printf("Size 0x%08lx (%s)\n", Size, GetCodeViewSymbolTagString(Tag));
        printf("Tag 0x%08lx (%s)\n", Tag, GetCodeViewSymbolTagString(Tag));
        break;
    case S_END:
        printf("%s reclen 0x%08lx\n", TagString, Size);
        printf("%s rectyp 0x%08lx\n", TagString, Tag);
        break;
    case S_UDT_16t:
    case S_COBOLUDT_16t:
        printf("%s reclen 0x%08lx\n", TagString, u.UdtSym_16t->reclen);
        printf("%s rectyp 0x%08lx\n", TagString, u.UdtSym_16t->rectyp);
        printf("%s typind 0x%08lx\n", TagString, u.UdtSym_16t->typind);
        printf("%s name %.*s\n", TagString, u.UdtSym_16t->name[0], &u.UdtSym_16t->name[1]);
        break;
    case S_UDT:
    case S_COBOLUDT:
        printf("%s %p reclen 0x%08lx\n", TagString, &u.UdtSym->reclen, u.UdtSym->reclen);
        printf("%s %p rectyp 0x%08lx\n", TagString, &u.UdtSym->rectyp, u.UdtSym->rectyp);
        printf("%s %p typind 0x%08lx\n", TagString, &u.UdtSym->typind, u.UdtSym->typind);
        printf("%s %p name %.*s\n", TagString, u.UdtSym->name, u.UdtSym->name[0], &u.UdtSym->name[1]);
        break;
    case S_BLOCK32:
        printf("%s reclen 0x%08lx\n", TagString, u.BlockSym32->reclen);
        printf("%s rectyp 0x%08lx\n", TagString, u.BlockSym32->rectyp);
        printf("%s pParent 0x%08lx\n", TagString, u.BlockSym32->pParent);
        printf("%s pEnd 0x%08lx\n", TagString, u.BlockSym32->pEnd);
        printf("%s len 0x%08lx\n", TagString, u.BlockSym32->len);
        printf("%s off 0x%08lx\n", TagString, u.BlockSym32->off);
        printf("%s seg 0x%08lx\n", TagString, u.BlockSym32->seg);
        printf("%s name %.*s\n", TagString, u.BlockSym32->name[0], &u.BlockSym32->name[1]);
        break;
    case S_LABEL32:
        printf("%s reclen 0x%08lx\n", TagString, u.LabelSym32->reclen);
        printf("%s rectyp 0x%08lx\n", TagString, u.LabelSym32->rectyp);
        printf("%s off 0x%08lx\n", TagString, u.LabelSym32->off);
        printf("%s seg 0x%08lx\n", TagString, u.LabelSym32->seg);
        printf("%s flags 0x%08lx\n", TagString, u.LabelSym32->flags);
        printf("%s name %.*s\n", TagString, u.LabelSym32->name[0], &u.LabelSym32->name[1]);
        break;
    case S_OBJNAME:
        printf("%s reclen 0x%08lx\n", TagString, u.ObjNameSym->reclen);
        printf("%s rectyp 0x%08lx\n", TagString, u.ObjNameSym->rectyp);
        printf("%s signature 0x%08lx\n", TagString, u.ObjNameSym->signature);
        printf("%s name %.*s\n", TagString, u.ObjNameSym->name[0], &u.ObjNameSym->name[1]);
        break;
    case S_COMPILE:
        printf("%s reclen 0x%08lx\n", TagString, u.CFlagSym->reclen);
        printf("%s rectyp 0x%08lx\n", TagString, u.CFlagSym->rectyp);
        printf("%s machine 0x%08lx\n", TagString, u.CFlagSym->machine);
        printf("%s language 0x%08lx\n", TagString, u.CFlagSym->flags.language);
        printf("%s pcode 0x%08lx\n", TagString, u.CFlagSym->flags.pcode);
        printf("%s floatprec 0x%08lx\n", TagString, u.CFlagSym->flags.floatprec);
        printf("%s floatpkg 0x%08lx\n", TagString, u.CFlagSym->flags.floatpkg);
        printf("%s ambdata 0x%08lx\n", TagString, u.CFlagSym->flags.ambdata);
        printf("%s ambcode 0x%08lx\n", TagString, u.CFlagSym->flags.ambcode);
        printf("%s mode32 0x%08lx\n", TagString, u.CFlagSym->flags.mode32);
        printf("%s ver: %.*s\n", TagString, u.CFlagSym->ver[0], &u.CFlagSym->ver[1]);
        break;
    case S_BPREL32_16t:
        printf("%s reclen 0x%08lx\n", TagString, u.BPRelSym32_16t->reclen);
        printf("%s rectyp 0x%08lx\n", TagString, u.BPRelSym32_16t->rectyp);
        printf("%s off 0x%08lx\n", TagString, u.BPRelSym32_16t->off);
        printf("%s typeind 0x%08lx\n", TagString, u.BPRelSym32_16t->typind);
        printf("%s name %.*s\n", TagString, u.BPRelSym32_16t->name[0], &u.BPRelSym32_16t->name[1]);
        break;
    case S_BPREL32:
        printf("%s reclen 0x%08lx\n", TagString, u.BPRelSym32->reclen);
        printf("%s rectyp 0x%08lx\n", TagString, u.BPRelSym32->rectyp);
        printf("%s off 0x%08lx\n", TagString, u.BPRelSym32->off);
        printf("%s typeind 0x%08lx\n", TagString, u.BPRelSym32->typind);
        printf("%s name %.*s\n", TagString, u.BPRelSym32->name[0], &u.BPRelSym32->name[1]);
        break;
    case S_GPROC32_16t:
    case S_LPROC32_16t:
        printf("%s reclen 0x%08lx\n", TagString, u.ProcSym32_16t->reclen);
        printf("%s rectyp 0x%08lx\n", TagString, u.ProcSym32_16t->rectyp);
        printf("%s pParent 0x%08lx\n", TagString, u.ProcSym32_16t->pParent);
        printf("%s pEnd 0x%08lx\n", TagString, u.ProcSym32_16t->pEnd);
        printf("%s pNext 0x%08lx\n", TagString, u.ProcSym32_16t->pNext);
        printf("%s len 0x%08lx\n", TagString, u.ProcSym32_16t->len);
        printf("%s DbgStart 0x%08lx\n", TagString, u.ProcSym32_16t->DbgStart);
        printf("%s DbgEnd 0x%08lx\n", TagString, u.ProcSym32_16t->DbgEnd);
        printf("%s off 0x%08lx\n", TagString, u.ProcSym32_16t->off);
        printf("%s seg 0x%08lx\n", TagString, u.ProcSym32_16t->seg);
        printf("%s typeind 0x%08lx\n", TagString, u.ProcSym32_16t->typind);
        printf("%s flags 0x%08lx\n", TagString, u.ProcSym32_16t->flags.bAll);
        printf("%s name %.*s\n", TagString, u.ProcSym32_16t->name[0], &u.ProcSym32_16t->name[1]);
        break;
    case S_GPROC32:
    case S_LPROC32:
        printf("%s reclen 0x%08lx\n", TagString, u.ProcSym32->reclen);
        printf("%s rectyp 0x%08lx\n", TagString, u.ProcSym32->rectyp);
        printf("%s pParent 0x%08lx\n", TagString, u.ProcSym32->pParent);
        printf("%s pEnd 0x%08lx\n", TagString, u.ProcSym32->pEnd);
        printf("%s pNext 0x%08lx\n", TagString, u.ProcSym32->pNext);
        printf("%s len 0x%08lx\n", TagString, u.ProcSym32->len);
        printf("%s DbgStart 0x%08lx\n", TagString, u.ProcSym32->DbgStart);
        printf("%s DbgEnd 0x%08lx\n", TagString, u.ProcSym32->DbgEnd);
        printf("%s off 0x%08lx\n", TagString, u.ProcSym32->off);
        printf("%s seg 0x%08lx\n", TagString, u.ProcSym32->seg);
        printf("%s typeind 0x%08lx\n", TagString, u.ProcSym32->typind);
        printf("%s flags 0x%08lx\n", TagString, u.ProcSym32->flags.bAll);
        printf("%s name %.*s\n", TagString, u.ProcSym32->name[0], &u.ProcSym32->name[1]);
        break;
    case S_PROCREF:
        printf("%s reclen 0x%08lx\n", TagString, u.RefSym->reclen);
        printf("%s rectyp 0x%08lx\n", TagString, u.RefSym->rectyp);
        printf("%s sumName 0x%08lx\n", TagString, u.RefSym->sumName);
        printf("%s ibSym 0x%08lx\n", TagString, u.RefSym->ibSym);
        printf("%s imod 0x%08lx\n", TagString, u.RefSym->imod);
        p  = (BYTE*) (1 + u.RefSym);
        printf("%s name %.*s\n", TagString, p[0], (p + 1));
        p += 1 + p[0];
        p = (BYTE*) ((((size_t)p) + 3) & ~3);
        break;
    case S_PUB32_16t:
        printf("%s name %.*s\n", TagString, u.PubSym32_16t->name[0], &u.PubSym32_16t->name[1]);
        break;
    case S_PUB32:
        printf("%s name %.*s\n", TagString, u.PubSym32->name[0], &u.PubSym32->name[1]);
        break;
    case S_THUNK32:
        printf("%s name %.*s\n", TagString, u.ThunkSym32->name[0], &u.ThunkSym32->name[1]);
        break;
    }

    return p;
}

BYTE*
CodeViewGetStructSize(
    BYTE* p,
    size_t* Size
    )
{
    size_t SizeTag;

    SizeTag = Get16(p);
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
            *Size = Get32(p);
            p += 4;
            break;
        default:
            *Size = 0;
            break;
        }
    }
    return p;
}

BYTE*
DumpCodeViewTypeRecord(
    BYTE* p
    )
{
    BYTE* q;
    size_t Size;
    size_t Tag;
    size_t StructSize;
    size_t StructNameLength;
    const char* StructName;
    const char* TagString;
    union {
        lfUnion_16t* Union_16t;
        lfUnion*     Union;
        lfStructure* Structure;
        lfStructure_16t* Structure_16t;
        void* p;
    } u;

    Size = Get16(p);
    p += 2;
    u.p = p;
    Tag = Get16(p);
    p += Size;

    TagString = GetCodeViewLeafTagString(Tag);

    printf("Size 0x%08lx (%s)\n", Size, TagString);
    printf("Tag 0x%08lx (%s)\n", Tag, TagString);

    switch (Tag)
    {
    default:
        printf("Size 0x%08lx (%s)\n", Size, TagString);
        printf("Tag 0x%08lx (%s)\n", Tag, TagString);
        break;

    case LF_UNION_16t:
        printf("%s %p leaf 0x%08lx\n", TagString, &u.Union_16t->leaf, u.Union_16t->leaf);
        printf("%s %p count 0x%08lx\n", TagString, &u.Union_16t->count, u.Union_16t->count);
        printf("%s %p property 0x%08lx\n", TagString, &u.Union_16t->property, u.Union_16t->property);
        q = CodeViewGetStructSize(u.Union_16t->data, &StructSize);
        printf("%s %p size 0x%08lx\n", TagString, &u.Union_16t->data, StructSize);
        printf("%s %p name %.*s\n", TagString, q, *q, (q + 1));
        break;

    case LF_UNION:
        printf("%s %p leaf 0x%08lx\n", TagString, &u.Union->leaf, u.Union->leaf);
        printf("%s %p count 0x%08lx\n", TagString, &u.Union->count, u.Union->count);
        printf("%s %p property 0x%08lx\n", TagString, &u.Union->property, u.Union->property);
        q = CodeViewGetStructSize(u.Union->data, &StructSize);
        printf("%s %p size 0x%08lx\n", TagString, &u.Union->data, StructSize);
        printf("%s %p name %.*s\n", TagString, q, *q, (q + 1));
        break;
    
    case LF_CLASS:
    case LF_STRUCTURE:
        printf("%s %p leaf 0x%08lx\n", TagString, &u.Structure->leaf, u.Structure->leaf);
        printf("%s %p count 0x%08lx\n", TagString, &u.Structure->count, u.Structure->count);
        printf("%s %p field 0x%08lx\n", TagString, &u.Structure->field, u.Structure->field);
        printf("%s %p property 0x%08lx\n", TagString, &u.Structure->property, u.Structure->property);
        printf("%s %p derived 0x%08lx\n", TagString, &u.Structure->derived, u.Structure->derived);
        printf("%s %p vshape 0x%08lx\n", TagString, &u.Structure->vshape, u.Structure->vshape);
        q = CodeViewGetStructSize(u.Structure->data, &StructSize);
        printf("%s %p size 0x%08lx\n", TagString, &u.Structure->data, StructSize);
        printf("%s %p name %.*s\n", TagString, q, *q, (q + 1));
        break;
    case LF_CLASS_16t:
    case LF_STRUCTURE_16t:
        printf("%s %p leaf 0x%08lx\n", TagString, &u.Structure_16t->leaf, u.Structure_16t->leaf);
        printf("%s %p count 0x%08lx\n", TagString, &u.Structure_16t->count, u.Structure_16t->count);
        printf("%s %p field 0x%08lx\n", TagString, &u.Structure_16t->field, u.Structure_16t->field);
        printf("%s %p property 0x%08lx\n", TagString, &u.Structure_16t->property, u.Structure_16t->property);
        printf("%s %p derived 0x%08lx\n", TagString, &u.Structure_16t->derived, u.Structure_16t->derived);
        printf("%s %p vshape 0x%08lx\n", TagString, &u.Structure_16t->vshape, u.Structure_16t->vshape);
        q = CodeViewGetStructSize(u.Structure_16t->data, &StructSize);
        printf("%s %p size 0x%08lx\n", TagString, &u.Structure_16t->data, StructSize);
        printf("%s %p name %.*s\n", TagString, q, *q, (q + 1));
        break;
    }

    return p;
}

void
DumpCodeViewSymbols(
    BOOL HasSignature,
    BYTE* p,
    size_t n
    )
{
    BYTE* End;
    size_t Signature;

    End = (p + n);
    if (HasSignature)
    {
        Signature = Get32(p);
        p += 4;
        printf("Signature 0x%08lx\n", Signature);
    }
    //if (Signature == 1 || Signature == 2)
    {
        while (p < End)
        {
            p = DumpCodeViewSymbolRecord(p);
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
    BYTE* p,
    size_t n
    )
{
    BYTE* End;
    size_t Signature;

    End = (p + n);
    if (HasSignature)
    {
        Signature = Get32(p);
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
    BYTE* lfaBase,
    OMFDirEntry* Entry,
    ULONG i
    )
{
    union {
        void* p;
        OMFModule* Module;
        OMFLibrary* Library;
    } u;
    BYTE* p;
    size_t j;
    size_t cSeg;
    size_t cb;
    unsigned lfo;
    unsigned SubsectionIndex;
    const char* SubsectionName;

    SubsectionIndex = Get16(&Entry->SubSection);
    SubsectionName = GetSubsectionName(SubsectionIndex);
    lfo = Get16(&Entry->lfo);
    cb = Get32(&Entry->cb);
    
    printf("\n");
    printf("OMFDirEntry[0x%08lx] %s %p SubSection 0x%08lx\n", i, SubsectionName, &Entry->SubSection, SubsectionIndex);
    printf("OMFDirEntry[0x%08lx] %s %p iMod 0x%08lx\n", i, SubsectionName, &Entry->iMod, Get16(&Entry->iMod));
    printf("OMFDirEntry[0x%08lx] %s %p lfo 0x%08lx\n", i, SubsectionName, &Entry->lfo, lfo);
    printf("OMFDirEntry[0x%08lx] %s %p cb 0x%08lx\n", i, SubsectionName, &Entry->cb, cb);

    u.p = (lfaBase + lfo);
    switch (SubsectionIndex)
    {
    case sstModule:
        cSeg = Get16(&u.Module->cSeg);
        printf("OMFDirEntry[0x%08lx] sstModule %p ovlNumber 0x%08lx\n", i, &u.Module->ovlNumber, Get16(&u.Module->ovlNumber));
        printf("OMFDirEntry[0x%08lx] sstModule %p iLib 0x%08lx\n", i, &u.Module->iLib, Get16(&u.Module->iLib));
        printf("OMFDirEntry[0x%08lx] sstModule %p cSeg 0x%08lx\n", i, &u.Module->cSeg, cSeg);
        printf("OMFDirEntry[0x%08lx] sstModule %p Style %.02s\n", i, &u.Module->Style, &u.Module->Style);
        for (j = 0 ; j != cSeg ; ++j)
        {
            printf("OMFDirEntry[0x%08lx] sstModule OMFSegDesc[0x%08lx] %p Seg 0x%08lx\n", i, j, &u.Module->SegInfo[j].Seg, Get16(&u.Module->SegInfo[j].Seg));
            printf("OMFDirEntry[0x%08lx] sstModule OMFSegDesc[0x%08lx] %p Off 0x%08lx\n", i, j, &u.Module->SegInfo[j].Off, Get32(&u.Module->SegInfo[j].Off));
            printf("OMFDirEntry[0x%08lx] sstModule OMFSegDesc[0x%08lx] %p cbSeg 0x%08lx\n", i, j, &u.Module->SegInfo[j].cbSeg, Get32(&u.Module->SegInfo[j].cbSeg));
        }
        p = (BYTE*) &u.Module->SegInfo[cSeg];
        //printf("OMFDirEntry[0x%08lx] sstModule %p NameLength 0x%08lx\n", i, p, p[0]);
        printf("OMFDirEntry[0x%08lx] sstModule %p Name %.*s\n", i, (p + 1), p[0], (p + 1));
        break;

    case sstTypes:
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
        p = (BYTE*) u.Library;
        for (j = 0 ; j < cb ; ++j)
        {
            BYTE Length = p[0];
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
    PDB_HEADER1* PdbHeader1 = 0;
    PDB_HEADER2* PdbHeader2 = 0;
    PDB_HEADER PdbHeader = { 0 };
    STREAM Stream = { 0 };
    STREAM* Streams = 0;
    size_t PageSize = 0;
    size_t i = 0;
    size_t j = 0;
    size_t StreamCount = 0;
    BYTE* Pages = 0;
    UINT32* Sizes = 0;
    PIMAGE_FILE_HEADER ObjHeader = 0;
    PIMAGE_SECTION_HEADER SectionHeader = 0;
    size_t NumberOfSections = 0;

    if (!argv[1])
        goto Exit;

    Status = ReadEntireFileInMemory(argv[1], &File);
    if (Status < 0)
        goto Exit;

    if (strstr(argv[1], ".obj"))
    {
        //
        // Dump sections named .debug$S (symbols) and .debug$T (types)
        //
        ObjHeader = (PIMAGE_FILE_HEADER) File.Contents;
        NumberOfSections = ObjHeader->NumberOfSections;
        SectionHeader = (PIMAGE_SECTION_HEADER) (1 + ObjHeader);
        for (i = 0 ; i != NumberOfSections ; ++i)
        {
            if (memcmp((const char*) SectionHeader->Name, ".debug$S", 8) == 0)
            {
                printf("%.8s\n", SectionHeader->Name);
                DumpCodeViewSymbols(TRUE, File.Contents + SectionHeader->PointerToRawData, SectionHeader->SizeOfRawData);
            }
            else if (memcmp((const char*) SectionHeader->Name, ".debug$T", 8) == 0)
            {
                printf("%.8s\n", SectionHeader->Name);
                DumpCodeViewTypes(TRUE, File.Contents + SectionHeader->PointerToRawData, SectionHeader->SizeOfRawData);
            }
            SectionHeader += 1;
        }
    }
    else if ((strstr(argv[1], ".exe") || strstr(argv[1], ".dll"))
        && (File.Size > 8)
        && ((memcmp(File.Contents + File.Size - 8, "NB09", 4) == 0)
            || (memcmp(File.Contents + File.Size - 8, "NB11", 4) == 0))
        )
    {
        //
        // CodeView data in an .exe/.dll
        // Note: We should probably look at the PE debug directory to handle signed binaries?
        //
        BYTE* lfaBase = (File.Contents + File.Size - Get32(File.Contents + File.Size - 4));
        if ((memcmp(lfaBase, "NB09", 4) == 0) || (memcmp(lfaBase, "NB11", 4) == 0))
        {
            OMFDirEntry* Entry;
            OMFDirHeader* Header = (OMFDirHeader*) (lfaBase + Get32(lfaBase + 4));
            size_t i;
            size_t cDir = Get32(&Header->cDir);
            size_t cbDirEntry = Get16(&Header->cbDirEntry);
            size_t cbDirHeader = Get16(&Header->cbDirHeader);

            printf("OMFDirHeader %p cbDirHeader 0x%08lx\n", &Header->cbDirHeader, cbDirHeader);
            printf("OMFDirHeader %p cbDirEntry 0x%08lx\n", &Header->cbDirEntry, Get16(&Header->cbDirEntry));
            printf("OMFDirHeader %p cDir 0x%08lx\n", &Header->cDir, cDir);
            printf("OMFDirHeader %p lfoNextDir 0x%08lx\n", &Header->lfoNextDir, Get32(&Header->lfoNextDir));
            printf("OMFDirHeader %p flags 0x%08lx\n", &Header->flags, Get32(&Header->flags));

            Entry = (OMFDirEntry*) (cbDirHeader + (BYTE*) Header);
            for (i = 0 ; i != cDir ; ++i)
            {
                DumpOMFDirEntry(lfaBase, Entry, (ULONG) i);
                Entry = (OMFDirEntry*) (cbDirEntry + (BYTE*) Entry);
            }
        }
    }
    else if (strstr(argv[1], ".pdb"))
    {
        size_t SignatureLength;

        if (memcmp(File.Contents, PDB_SIGNATURE1, sizeof(PDB_SIGNATURE1)) == 0)
        {
            PdbHeader1 = (PDB_HEADER1*) File.Contents;
            SignatureLength = (sizeof(PDB_SIGNATURE1) - 7);
            PdbHeader.PageSize = PdbHeader1->PageSize;
            PdbHeader.StartPage = PdbHeader1->StartPage;
            PdbHeader.FilePages = PdbHeader1->FilePages;
            PdbHeader.RootStreamSize = PdbHeader1->RootStreamSize;
            PdbHeader.RootStreamPages = PdbHeader1->RootStreamPages;
            PdbHeader.PageIndexSize = 2;
            PdbHeader.StreamCountSize = 2;
            PdbHeader.PagingLevels = 1;
            PdbHeader.OffsetToTypes = 0x10;
        }
        else if (memcmp(File.Contents, PDB_SIGNATURE2, sizeof(PDB_SIGNATURE2)) == 0)
        {
            PdbHeader2 = (PDB_HEADER2*) File.Contents;
            SignatureLength = (sizeof(PDB_SIGNATURE2) - 7);
            PdbHeader.PageSize = PdbHeader2->PageSize;
            PdbHeader.StartPage = PdbHeader2->StartPage;
            PdbHeader.FilePages = PdbHeader2->FilePages;
            PdbHeader.RootStreamSize = PdbHeader2->RootStreamSize;
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
            (unsigned long) * (UINT16*) PdbHeader.RootStreamPages
            );

        fflush(stdout);

        CopyStream(&PdbHeader, &File, &Stream, Get32(&PdbHeader.RootStreamSize), PdbHeader.RootStreamPages);
        DumpStream(&PdbHeader, &Stream, 0);

        /*
        root stream is
            uint16 StreamCount
            uint16 Reserved
            array {
                uint32 Size
                uint32 Reserved
            }[StreamCount]
            uint16 Pages[]
        */
        StreamCount = GetInteger(Stream.Contents, PdbHeader.StreamCountSize);
        printf("StreamCount 0x%lx\n", (unsigned long) StreamCount);
        Sizes = (UINT32*) (Stream.Contents + 4);
        Pages = (BYTE*) (Sizes + PdbHeader.StreamCountSize * StreamCount);

        Streams = (STREAM*) calloc(StreamCount, sizeof(STREAM));

        for (i = 0; i != StreamCount ; ++i)
        {
            size_t StreamSize = Get32(&Sizes[i * 2]);
            CopyStream(&PdbHeader, &File, &Streams[i], StreamSize, Pages);
            Pages += (Streams[i].NumberOfPages * PdbHeader.PageIndexSize);
            DumpStream(&PdbHeader, &Streams[i], i);
        }
        printf("\n");
    }

    ExitCode = 0;
Exit:
    free(File.Contents);
    printf("ExitCode:%d\n", ExitCode);
    return ExitCode;
}
