/*
http://www.awprofessional.com/articles/article.asp?p=22685&rl=1
*/

#if defined(_WIN32) && !defined(WIN32)
#define WIN32
#endif

#define _CRT_SECURE_NO_DEPRECATE

#define PDB_STREAM_DIRECTORY 0
#define PDB_STREAM_PDB       1
#define PDB_STREAM_PUBSYM    7

#include <limits.h>

#if ((UCHAR_MAX == 0xFFUL) && (CHAR_BIT == 8))
typedef unsigned char BYTE;
#else
#error no 8 bit integer type
#endif

/* ------------------------------------------------------------------*/

#define PDB_SIGNATURE1 \
    "Microsoft C/C++ program database 2.00\r\n\x1A" "JG\0"

#define PDB_SIGNATURE2 \
    "Microsoft C/C++ MSF 7.00\r\n\x1A" "DS\0"

/* ----------------------------------------------------------------- */

typedef struct _PDB_HEADER1
{
    unsigned char Signture[0x2C];
    unsigned char PageSize[4];      /* 0x0400, 0x0800, 0x1000 */
    unsigned char StartPage[2];     /* 0x0009, 0x0005, 0x0002 */
    unsigned char FilePages[2];     /* file size / PageSize */
    unsigned char RootStreamSize[4]; /* stream directory */
    unsigned char Reserved[4];
    unsigned char RootStreamPages[1]; /* array of page numbers */
}
PDB_HEADER1;

typedef struct _PDB_HEADER2         /* attempt to deal with newer formats -- doesn't work yet */
{
    unsigned char Signture[0x20];
    unsigned char PageSize[4];     /* 0x0400, 0x0800, 0x1000 */
    unsigned char StartPage[4];    /* 0x0009, 0x0005, 0x0002 */
    unsigned char FilePages[4];    /* file size / PageSize */
    unsigned char RootStreamSize[4]; /* stream directory */
    unsigned char Reserved[4];
    unsigned char RootStreamPages[1]; /* array of page numbers */
}
PDB_HEADER2;

typedef struct _PDB_HEADER
{
    unsigned char  PagingLevels;    /* attempt to deal with newer formats -- doesn't work yet */
    unsigned char  OffsetToTypes;   /* attempt to deal with newer formats -- doesn't work yet */
    unsigned long  PageSize;        /* 0x0400, 0x0800, 0x1000 */
    unsigned long  StartPage;       /* 0x0009, 0x0005, 0x0002 */
    unsigned long  FilePages;       /* file size / PageSize */
    unsigned long  RootStreamSize;  /* stream directory */
    unsigned long  PageIndexSize;   /* attempt to deal with newer formats -- doesn't work yet */
    unsigned long  StreamCountSize; /* attempt to deal with newer formats -- doesn't work yet */
    struct {
        unsigned Types : 1;
        unsigned Symbols : 1;
        unsigned SymbolsSignature : 1;
    } Streams[10];
    unsigned char* RootStreamPages; /* array of page numbers */
}
PDB_HEADER;

/* ----------------------------------------------------------------- */
