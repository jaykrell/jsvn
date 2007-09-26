/*******************************************************************
 *
 *      FILE:           dciddi.h
 *
 *      DESCRIPTION:    definitions for MS/Intel-defined DCI interface
 *
 *      Copyright (C) 1994 Intel/Microsoft Corporation.  All Rights Reserved.
 *
 *******************************************************************/

#ifndef _INC_DCIDDI
#define _INC_DCIDDI

#ifdef __cplusplus
extern "C" {
#endif

/* DCI Command Escapes */
#define DCICOMMAND                      3075
#define DCI_VERSION                     0x0100

#define DCICREATEPRIMARYSURFACE         1
#define DCICREATEOFFSCREENSURFACE       2
#define DCICREATEOVERLAYSURFACE         3
#define DCIENUMSURFACE                  4
#define DCIESCAPE                       5

/* DCI-Defined error codes */
#define DCI_OK                                  0 /* success */

/* Hard errors -- DCI will be unavailable */
#define DCI_FAIL_GENERIC                     -1
#define DCI_FAIL_UNSUPPORTEDVERSION          -2
#define DCI_FAIL_INVALIDSURFACE              -3
#define DCI_FAIL_UNSUPPORTED                 -4

/* Soft errors -- DCI may be available later */
#define DCI_ERR_CURRENTLYNOTAVAIL           -5
#define DCI_ERR_INVALIDRECT                 -6
#define DCI_ERR_UNSUPPORTEDFORMAT           -7
#define DCI_ERR_UNSUPPORTEDMASK             -8
#define DCI_ERR_TOOBIGHEIGHT                -9
#define DCI_ERR_TOOBIGWIDTH                 -10
#define DCI_ERR_TOOBIGSIZE                  -11
#define DCI_ERR_OUTOFMEMORY                 -12
#define DCI_ERR_INVALIDPOSITION             -13
#define DCI_ERR_INVALIDSTRETCH              -14
#define DCI_ERR_INVALIDCLIPLIST             -15
#define DCI_ERR_SURFACEISOBSCURED           -16
#define DCI_ERR_XALIGN                      -17
#define DCI_ERR_YALIGN                      -18
#define DCI_ERR_XYALIGN                     -19
#define DCI_ERR_WIDTHALIGN                  -20
#define DCI_ERR_HEIGHTALIGN                 -21

/* success messages -- DCI call succeeded, but specified item changed */
#define DCI_STATUS_POINTERCHANGED           1
#define DCI_STATUS_STRIDECHANGED            2
#define DCI_STATUS_FORMATCHANGED            4
#define DCI_STATUS_SURFACEINFOCHANGED       8
#define DCI_STATUS_CHROMAKEYCHANGED        16
#define DCI_STATUS_WASSTILLDRAWING         32

#define DCI_SUCCESS(error)  (((DCIRVAL)error) >= 0)

/* DCI Capability Flags */
#define DCI_SURFACE_TYPE                        0x0000000F
#define DCI_PRIMARY                             0x00000000
#define DCI_OFFSCREEN                           0x00000001
#define DCI_OVERLAY                             0x00000002

#define DCI_VISIBLE                             0x00000010
#define DCI_CHROMAKEY                           0x00000020
#define DCI_1632_ACCESS                         0x00000040
#define DCI_DWORDSIZE                           0x00000080
#define DCI_DWORDALIGN                          0x00000100
#define DCI_WRITEONLY                           0x00000200
#define DCI_ASYNC                               0x00000400

#define DCI_CAN_STRETCHX                        0x00001000
#define DCI_CAN_STRETCHY                        0x00002000
#define DCI_CAN_STRETCHXY                       (DCI_CAN_STRETCHX | DCI_CAN_STRETCHY)

#define DCI_CAN_STRETCHXN                       0x00004000
#define DCI_CAN_STRETCHYN                       0x00008000
#define DCI_CAN_STRETCHXYN                      (DCI_CAN_STRETCHXN | DCI_CAN_STRETCHYN)


#define DCI_CANOVERLAY                          0x00010000

/*
 * Win32 RGNDATA structure.  This will be used for  cliplist info. passing.
 */
#if (WINVER < 0x0400)

#ifndef RDH_RECTANGLES

typedef struct tagRECTL
{
   long     left;
   long     top;
   long     right;
   long     bottom;
} RECTL;
typedef RECTL*       PRECTL;
typedef RECTL NEAR*  NPRECTL;
typedef RECTL *   LPRECTL;
typedef const RECTL * LPCRECTL;

#define RDH_RECTANGLES  0

typedef struct tagRGNDATAHEADER {
   unsigned long   dwSize;                              /* size of structure             */
   unsigned long   iType;                               /* Will be RDH_RECTANGLES        */
   unsigned long   nCount;                              /* # of clipping rectangles      */
   unsigned long   nRgnSize;                            /* size of buffer -- can be zero */
   RECTL   rcBound;                             /* bounding  rectangle for region*/
} RGNDATAHEADER;
typedef RGNDATAHEADER*       PRGNDATAHEADER;
typedef RGNDATAHEADER NEAR*  NPRGNDATAHEADER;
typedef RGNDATAHEADER *   LPRGNDATAHEADER;
typedef const RGNDATAHEADER * LPCRGNDATAHEADER;

typedef struct tagRGNDATA {
   RGNDATAHEADER   rdh;
   char            Buffer[1];
} RGNDATA;
typedef RGNDATA*       PRGNDATA;
typedef RGNDATA NEAR*  NPRGNDATA;
typedef RGNDATA *   LPRGNDATA;
typedef const RGNDATA * LPCRGNDATA;

#endif
#endif

typedef int     DCIRVAL;                /* return for callbacks */

/**************************************************************************
 *      input structures
 **************************************************************************/

/*
 * Used by a DCI client to provide input parameters for the
 * DCICREATEPRIMARYSURFACE escape.
 */
typedef struct _DCICMD {
        unsigned long   dwCommand;
        unsigned long   dwParam1;
        unsigned long   dwParam2;
        unsigned long   dwVersion;
        unsigned long   dwReserved;
} DCICMD;

/*
 * This structure is used by a DCI client to provide input parameters for
 * the DCICREATE... calls.  The fields that are actually relevant differ for
 * each of the three calls.  Details are in the DCI Spec chapter providing
 * the function specifications.
 */
typedef struct _DCICREATEINPUT {
        DCICMD  cmd;                                                    /* common header structure */
        unsigned long   dwCompression;                          /* format of surface to be created                      */
        unsigned long   dwMask[3];                      /* for  nonstandard RGB (e.g. 5-6-5, RGB32) */
        unsigned long   dwWidth;                        /* height of the surface to be created          */
        unsigned long   dwHeight;                       /* width of input surfaces                                      */
        unsigned long   dwDCICaps;                                              /* capabilities of surface wanted */
        unsigned long   dwBitCount;                                     /* bit depth of format to be created */
        void*  lpSurface;                      /* pointer to an associated surface             */
} DCICREATEINPUT,  *LPDCICREATEINPUT;


/**************************************************************************
 *      surface info. structures
 **************************************************************************/

/*
 * This structure is used to return information about available support
 * during a DCIEnumSurface call.  It is also used to create a primary
 * surface, and as a member of the larger structures returned by the
 * offscreen and overlay calls.
 */
 typedef struct _DCISURFACEINFO {
        unsigned long   dwSize;                         /* size of structure                                            */
        unsigned long   dwDCICaps;                  /* capability flags (stretch, etc.)             */
        unsigned long   dwCompression;                  /* format of surface to be created                      */
        unsigned long   dwMask[3];                  /* for BI_BITMASK surfaces                                      */

        unsigned long   dwWidth;                    /* width of surface                                             */
        unsigned long   dwHeight;                   /* height of surface                                            */
        long    lStride;                    /* distance in bytes betw. one pixel            */
                                                                                /* and the pixel directly below it                      */
        unsigned long   dwBitCount;                 /* Bits per pixel for this dwCompression    */
        unsigned long   dwOffSurface;               /* offset of surface pointer                            */
        WORD    wSelSurface;                /* selector of surface pointer                          */
        WORD    wReserved;

        unsigned long   dwReserved1;                /* reserved for provider */
        unsigned long   dwReserved2;                /* reserved for DCIMAN */
        unsigned long   dwReserved3;                /* reserved for future */
        DCIRVAL (__stdcall *BeginAccess) (void*, LPRECT);    /* BeginAccess callback         */
        void (__stdcall *EndAccess) (void*);                   /* EndAcess callback            */
        void (__stdcall *DestroySurface) (void*);               /* Destroy surface callback     */
} DCISURFACEINFO,  *LPDCISURFACEINFO;


/*
 * This structure is used by a DCI client to provide input parameters for the
 * DCIEnumSurface call.
 */

typedef
void
(*ENUM_CALLBACK) (
    LPDCISURFACEINFO lpSurfaceInfo,
    void* lpContext
    );

typedef struct _DCIENUMINPUT {
        DCICMD  cmd;                                                    /* common header structure */
        RECT    rSrc;                           /* source rect. for stretch  */
        RECT    rDst;                           /* dest. rect. for stretch       */
        void    (__stdcall *EnumCallback)(LPDCISURFACEINFO, void*);        /* callback for supported formats */
        void*  lpContext;
} DCIENUMINPUT,  *LPDCIENUMINPUT;


/*
 * This structure must be allocated and returned by the DCI provider in
 * response to a DCICREATEPRIMARYSURFACE call.
 */
 typedef DCISURFACEINFO DCIPRIMARY,  *LPDCIPRIMARY;

/*
 * This structure must be allocated and returned by the DCI provider in
 * response to a DCICREATEOFFSCREENSURFACE call.
 */
 typedef struct _DCIOFFSCREEN {

        DCISURFACEINFO  dciInfo;                                                           /* surface info                  */
        DCIRVAL (__stdcall *Draw) (void*);                                            /* copy to onscreen buffer   */
        DCIRVAL (__stdcall *SetClipList) (void*, LPRGNDATA);          /* SetCliplist callback              */
        DCIRVAL (__stdcall *SetDestination) (void*, LPRECT, LPRECT);  /* SetDestination callback       */
} DCIOFFSCREEN,  *LPDCIOFFSCREEN;


/*
 * This structure must be allocated and returned by the DCI provider in response
 * to a DCICREATEOVERLAYSURFACE call.
 */
 typedef struct _DCIOVERLAY{

        DCISURFACEINFO  dciInfo;                                                /* surface info                  */
        unsigned long   dwChromakeyValue;                                               /* chromakey color value                 */
        unsigned long   dwChromakeyMask;                                                /* specifies valid bits of value */
} DCIOVERLAY,  *LPDCIOVERLAY;


/* DCI FOURCC def.s for extended DIB formats */

#ifndef YVU9
#define YVU9                        mmioFOURCC('Y','V','U','9')
#endif
#ifndef Y411
#define Y411                        mmioFOURCC('Y','4','1','1')
#endif
#ifndef YUY2
#define YUY2                        mmioFOURCC('Y','U','Y','2')
#endif
#ifndef YVYU
#define YVYU                        mmioFOURCC('Y','V','Y','U')
#endif
#ifndef UYVY
#define UYVY                        mmioFOURCC('U','Y','V','Y')
#endif
#ifndef Y211
#define Y211                        mmioFOURCC('Y','2','1','1')
#endif

#ifdef __cplusplus
}
#endif

#endif // _INC_DCIDDI
