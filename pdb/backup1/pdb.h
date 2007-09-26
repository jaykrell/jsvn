/*
http://www.awprofessional.com/articles/article.asp?p=22685&rl=1
*/

#define PDB_STREAM_DIRECTORY 0
#define PDB_STREAM_PDB       1
#define PDB_STREAM_PUBSYM    7

#include <limits.h>

typedef unsigned char UCHAR;
typedef unsigned short USHORT;
typedef unsigned int UINT;
typedef unsigned long ULONG;

#if ((UCHAR_MAX == 0xFFUL) && (CHAR_BIT == 8))
typedef unsigned char UINT8;
typedef unsigned char BYTE;
#else
#error no 8 bit integer type
#endif

#if (USHRT_MAX == 0xFFFFUL)
typedef unsigned short UINT16;
#elif (UINT_MAX == 0xFFFFUL)
typedef unsigned int UINT16;
#elif (UCHAR_MAX == 0xFFFFUL)
typedef unsigned char UINT16;
#else
#error no 16 bit integer type
#endif

#if (UINT_MAX == 0xFFFFFFFFUL)
typedef unsigned int UINT32;
#elif (ULONG_MAX == 0xFFFFFFFFUL)
typedef unsigned long UINT32;
#elif (USHRT_MAX == 0xFFFFFFFFUL)
typedef unsigned short UINT32;
#elif (UCHAR_MAX == 0xFFFFFFFFUL)
typedef unsigned char UINT32;
#else
#error no 32 bit integer type
#endif

typedef BYTE* PBYTE;

/* ------------------------------------------------------------------*/

#define PDB_SIGNATURE1 \
    "Microsoft C/C++ program database 2.00\r\n\x1A" "JG\0"

#define PDB_SIGNATURE2 \
    "Microsoft C/C++ MSF 7.00\r\n\x1A" "DS\0"

/* ----------------------------------------------------------------- */

#define PDB_STREAM_FREE (-1)

/* ----------------------------------------------------------------- */

#define PDB_PAGE_SIZE_1K  (0x0400)  /* bytes per page */
#define PDB_PAGE_SIZE_2K  (0x0800)
#define PDB_PAGE_SIZE_4K  (0x1000)

#define PDB_PAGE_SHIFT_1K (10)  /* log2 (PDB_PAGE_SIZE_*) */
#define PDB_PAGE_SHIFT_2K (11)
#define PDB_PAGE_SHIFT_4K (12)

#define PDB_PAGE_COUNT_1K (0xFFFF)  /* page number < PDB_PAGE_COUNT_* */
#define PDB_PAGE_COUNT_2K (0xFFFF)
#define PDB_PAGE_COUNT_4K (0x7FFF)

/* ----------------------------------------------------------------- */

typedef struct _PDB_HEADER1
{
    BYTE        Signture[0x2C];
    UINT32      PageSize;     /* 0x0400, 0x0800, 0x1000 */
    UINT16      StartPage;    /* 0x0009, 0x0005, 0x0002 */
    UINT16      FilePages;    /* file size / PageSize */
    UINT32      RootStreamSize; /* stream directory */
    UINT32      Reserved;
    BYTE        RootStreamPages[1]; /* array of page numbers */
} PDB_HEADER1;

typedef struct _PDB_HEADER2 { /* attempt to deal with newer formats -- doesn't work yet */
    BYTE        Signture[0x20];
    UINT32      PageSize;     /* 0x0400, 0x0800, 0x1000 */
    UINT32      StartPage;    /* 0x0009, 0x0005, 0x0002 */
    UINT32      FilePages;    /* file size / PageSize */
    UINT32      RootStreamSize; /* stream directory */
    UINT32      Reserved;
    BYTE        RootStreamPages[1]; /* array of page numbers */
} PDB_HEADER2;

typedef struct _PDB_HEADER {
    UCHAR   PagingLevels;  /* attempt to deal with newer formats -- doesn't work yet */
    UCHAR   OffsetToTypes; /* attempt to deal with newer formats -- doesn't work yet */
    UINT    PageSize;      /* 0x0400, 0x0800, 0x1000 */
    ULONG   StartPage;    /* 0x0009, 0x0005, 0x0002 */
    ULONG   FilePages;    /* file size / PageSize */
    ULONG   RootStreamSize; /* stream directory */
    ULONG   PageIndexSize;  /* attempt to deal with newer formats -- doesn't work yet */
    ULONG   StreamCountSize;/* attempt to deal with newer formats -- doesn't work yet */
    BYTE*   RootStreamPages; /* array of page numbers */
} PDB_HEADER;

/* ----------------------------------------------------------------- */
