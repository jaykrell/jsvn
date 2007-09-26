/**************************************************************************
*                                                                         *
* wingdi.h -- GDI procedure declarations, constant definitions and macros *
*                                                                         *
* Copyright (c) 1985-1996, Microsoft Corp. All rights reserved.           *
*                                                                         *
**************************************************************************/

#ifndef _WINGDI_
#define _WINGDI_


//
// Define API decoration for direct importing of DLL references.
//

#if !defined(_GDI32_)
#define WINGDIAPI DECLSPEC_IMPORT
#else
#define WINGDIAPI
#endif

//
// Define API decoration for direct importing of DLL references.
//

#if !defined(_SPOOL32_)
#define WINSPOOLAPI DECLSPEC_IMPORT
#else
#define WINSPOOLAPI
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef WINVER
#define WINVER 0x0400   // version 4.0
#endif /* WINVER */

#ifndef NOGDI

#ifndef NORASTEROPS

/* Binary raster ops */
#define R2_BLACK            1   /*  0       */
#define R2_NOTMERGEPEN      2   /* DPon     */
#define R2_MASKNOTPEN       3   /* DPna     */
#define R2_NOTCOPYPEN       4   /* PN       */
#define R2_MASKPENNOT       5   /* PDna     */
#define R2_NOT              6   /* Dn       */
#define R2_XORPEN           7   /* DPx      */
#define R2_NOTMASKPEN       8   /* DPan     */
#define R2_MASKPEN          9   /* DPa      */
#define R2_NOTXORPEN        10  /* DPxn     */
#define R2_NOP              11  /* D        */
#define R2_MERGENOTPEN      12  /* DPno     */
#define R2_COPYPEN          13  /* P        */
#define R2_MERGEPENNOT      14  /* PDno     */
#define R2_MERGEPEN         15  /* DPo      */
#define R2_WHITE            16  /*  1       */
#define R2_LAST             16

/* Ternary raster operations */
#define SRCCOPY             (unsigned long)0x00CC0020 /* dest = source                   */
#define SRCPAINT            (unsigned long)0x00EE0086 /* dest = source OR dest           */
#define SRCAND              (unsigned long)0x008800C6 /* dest = source AND dest          */
#define SRCINVERT           (unsigned long)0x00660046 /* dest = source XOR dest          */
#define SRCERASE            (unsigned long)0x00440328 /* dest = source AND (NOT dest )   */
#define NOTSRCCOPY          (unsigned long)0x00330008 /* dest = (NOT source)             */
#define NOTSRCERASE         (unsigned long)0x001100A6 /* dest = (NOT src) AND (NOT dest) */
#define MERGECOPY           (unsigned long)0x00C000CA /* dest = (source AND pattern)     */
#define MERGEPAINT          (unsigned long)0x00BB0226 /* dest = (NOT source) OR dest     */
#define PATCOPY             (unsigned long)0x00F00021 /* dest = pattern                  */
#define PATPAINT            (unsigned long)0x00FB0A09 /* dest = DPSnoo                   */
#define PATINVERT           (unsigned long)0x005A0049 /* dest = pattern XOR dest         */
#define DSTINVERT           (unsigned long)0x00550009 /* dest = (NOT dest)               */
#define BLACKNESS           (unsigned long)0x00000042 /* dest = BLACK                    */
#define WHITENESS           (unsigned long)0x00FF0062 /* dest = WHITE                    */

/* Quaternary raster codes */
#define MAKEROP4(fore,back) (unsigned long)((((back) << 8) & 0xFF000000) | (fore))

#endif /* NORASTEROPS */

#define GDI_ERROR (0xFFFFFFFFL)
#define HGDI_ERROR ((HANDLE)(0xFFFFFFFFL))

/* Region Flags */
#define ERROR               0
#define NULLREGION          1
#define SIMPLEREGION        2
#define COMPLEXREGION       3
#define RGN_ERROR ERROR

/* CombineRgn() Styles */
#define RGN_AND             1
#define RGN_OR              2
#define RGN_XOR             3
#define RGN_DIFF            4
#define RGN_COPY            5
#define RGN_MIN             RGN_AND
#define RGN_MAX             RGN_COPY

/* StretchBlt() Modes */
#define BLACKONWHITE                 1
#define WHITEONBLACK                 2
#define COLORONCOLOR                 3
#define HALFTONE                     4
#define MAXSTRETCHBLTMODE            4

#if(WINVER >= 0x0400)
/* New StretchBlt() Modes */
#define STRETCH_ANDSCANS    BLACKONWHITE
#define STRETCH_ORSCANS     WHITEONBLACK
#define STRETCH_DELETESCANS COLORONCOLOR
#define STRETCH_HALFTONE    HALFTONE
#endif /* WINVER >= 0x0400 */

/* PolyFill() Modes */
#define ALTERNATE                    1
#define WINDING                      2
#define POLYFILL_LAST                2

/* Text Alignment Options */
#define TA_NOUPDATECP                0
#define TA_UPDATECP                  1

#define TA_LEFT                      0
#define TA_RIGHT                     2
#define TA_CENTER                    6

#define TA_TOP                       0
#define TA_BOTTOM                    8
#define TA_BASELINE                  24
#if (WINVER >= 0x0400)
#define TA_RTLREADING                256
#define TA_MASK       (TA_BASELINE+TA_CENTER+TA_UPDATECP+TA_RTLREADING)
#else
#define TA_MASK       (TA_BASELINE+TA_CENTER+TA_UPDATECP)
#endif

#define VTA_BASELINE TA_BASELINE
#define VTA_LEFT     TA_BOTTOM
#define VTA_RIGHT    TA_TOP
#define VTA_CENTER   TA_CENTER
#define VTA_BOTTOM   TA_RIGHT
#define VTA_TOP      TA_LEFT

#define ETO_OPAQUE                   0x0002
#define ETO_CLIPPED                  0x0004
#if(WINVER >= 0x0400)
#define ETO_GLYPH_INDEX              0x0010
#define ETO_RTLREADING               0x0080
#define ETO_IGNORELANGUAGE           0x1000
#endif /* WINVER >= 0x0400 */

#define ASPECT_FILTERING             0x0001

/* Bounds Accumulation APIs */

#define DCB_RESET       0x0001
#define DCB_ACCUMULATE  0x0002
#define DCB_DIRTY       DCB_ACCUMULATE
#define DCB_SET         (DCB_RESET | DCB_ACCUMULATE)
#define DCB_ENABLE      0x0004
#define DCB_DISABLE     0x0008

#ifndef NOMETAFILE

/* Metafile Functions */
#define META_SETBKCOLOR              0x0201
#define META_SETBKMODE               0x0102
#define META_SETMAPMODE              0x0103
#define META_SETROP2                 0x0104
#define META_SETRELABS               0x0105
#define META_SETPOLYFILLMODE         0x0106
#define META_SETSTRETCHBLTMODE       0x0107
#define META_SETTEXTCHAREXTRA        0x0108
#define META_SETTEXTCOLOR            0x0209
#define META_SETTEXTJUSTIFICATION    0x020A
#define META_SETWINDOWORG            0x020B
#define META_SETWINDOWEXT            0x020C
#define META_SETVIEWPORTORG          0x020D
#define META_SETVIEWPORTEXT          0x020E
#define META_OFFSETWINDOWORG         0x020F
#define META_SCALEWINDOWEXT          0x0410
#define META_OFFSETVIEWPORTORG       0x0211
#define META_SCALEVIEWPORTEXT        0x0412
#define META_LINETO                  0x0213
#define META_MOVETO                  0x0214
#define META_EXCLUDECLIPRECT         0x0415
#define META_INTERSECTCLIPRECT       0x0416
#define META_ARC                     0x0817
#define META_ELLIPSE                 0x0418
#define META_FLOODFILL               0x0419
#define META_PIE                     0x081A
#define META_RECTANGLE               0x041B
#define META_ROUNDRECT               0x061C
#define META_PATBLT                  0x061D
#define META_SAVEDC                  0x001E
#define META_SETPIXEL                0x041F
#define META_OFFSETCLIPRGN           0x0220
#define META_TEXTOUT                 0x0521
#define META_BITBLT                  0x0922
#define META_STRETCHBLT              0x0B23
#define META_POLYGON                 0x0324
#define META_POLYLINE                0x0325
#define META_ESCAPE                  0x0626
#define META_RESTOREDC               0x0127
#define META_FILLREGION              0x0228
#define META_FRAMEREGION             0x0429
#define META_INVERTREGION            0x012A
#define META_PAINTREGION             0x012B
#define META_SELECTCLIPREGION        0x012C
#define META_SELECTOBJECT            0x012D
#define META_SETTEXTALIGN            0x012E
#define META_CHORD                   0x0830
#define META_SETMAPPERFLAGS          0x0231
#define META_EXTTEXTOUT              0x0a32
#define META_SETDIBTODEV             0x0d33
#define META_SELECTPALETTE           0x0234
#define META_REALIZEPALETTE          0x0035
#define META_ANIMATEPALETTE          0x0436
#define META_SETPALENTRIES           0x0037
#define META_POLYPOLYGON             0x0538
#define META_RESIZEPALETTE           0x0139
#define META_DIBBITBLT               0x0940
#define META_DIBSTRETCHBLT           0x0b41
#define META_DIBCREATEPATTERNBRUSH   0x0142
#define META_STRETCHDIB              0x0f43
#define META_EXTFLOODFILL            0x0548
#define META_DELETEOBJECT            0x01f0
#define META_CREATEPALETTE           0x00f7
#define META_CREATEPATTERNBRUSH      0x01F9
#define META_CREATEPENINDIRECT       0x02FA
#define META_CREATEFONTINDIRECT      0x02FB
#define META_CREATEBRUSHINDIRECT     0x02FC
#define META_CREATEREGION            0x06FF

#endif /* NOMETAFILE */

/* GDI Escapes */
#define NEWFRAME                     1
#define ABORTDOC                     2
#define NEXTBAND                     3
#define SETCOLORTABLE                4
#define GETCOLORTABLE                5
#define FLUSHOUTPUT                  6
#define DRAFTMODE                    7
#define QUERYESCSUPPORT              8
#define SETABORTPROC                 9
#define STARTDOC                     10
#define ENDDOC                       11
#define GETPHYSPAGESIZE              12
#define GETPRINTINGOFFSET            13
#define GETSCALINGFACTOR             14
#define MFCOMMENT                    15
#define GETPENWIDTH                  16
#define SETCOPYCOUNT                 17
#define SELECTPAPERSOURCE            18
#define DEVICEDATA                   19
#define PASSTHROUGH                  19
#define GETTECHNOLGY                 20
#define GETTECHNOLOGY                20
#define SETLINECAP                   21
#define SETLINEJOIN                  22
#define SETMITERLIMIT                23
#define BANDINFO                     24
#define DRAWPATTERNRECT              25
#define GETVECTORPENSIZE             26
#define GETVECTORBRUSHSIZE           27
#define ENABLEDUPLEX                 28
#define GETSETPAPERBINS              29
#define GETSETPRINTORIENT            30
#define ENUMPAPERBINS                31
#define SETDIBSCALING                32
#define EPSPRINTING                  33
#define ENUMPAPERMETRICS             34
#define GETSETPAPERMETRICS           35
#define POSTSCRIPT_DATA              37
#define POSTSCRIPT_IGNORE            38
#define MOUSETRAILS                  39
#define GETDEVICEUNITS               42

#define GETEXTENDEDTEXTMETRICS       256
#define GETEXTENTTABLE               257
#define GETPAIRKERNTABLE             258
#define GETTRACKKERNTABLE            259
#define EXTTEXTOUT                   512
#define GETFACENAME                  513
#define DOWNLOADFACE                 514
#define ENABLERELATIVEWIDTHS         768
#define ENABLEPAIRKERNING            769
#define SETKERNTRACK                 770
#define SETALLJUSTVALUES             771
#define SETCHARSET                   772

#define STRETCHBLT                   2048
#define GETSETSCREENPARAMS           3072
#define QUERYDIBSUPPORT              3073
#define BEGIN_PATH                   4096
#define CLIP_TO_PATH                 4097
#define END_PATH                     4098
#define EXT_DEVICE_CAPS              4099
#define RESTORE_CTM                  4100
#define SAVE_CTM                     4101
#define SET_ARC_DIRECTION            4102
#define SET_BACKGROUND_COLOR         4103
#define SET_POLY_MODE                4104
#define SET_SCREEN_ANGLE             4105
#define SET_SPREAD                   4106
#define TRANSFORM_CTM                4107
#define SET_CLIP_BOX                 4108
#define SET_BOUNDS                   4109
#define SET_MIRROR_MODE              4110
#define OPENCHANNEL                  4110
#define DOWNLOADHEADER               4111
#define CLOSECHANNEL                 4112
#define POSTSCRIPT_PASSTHROUGH       4115
#define ENCAPSULATED_POSTSCRIPT      4116

/* Flag returned from QUERYDIBSUPPORT */
#define QDI_SETDIBITS                1
#define QDI_GETDIBITS                2
#define QDI_DIBTOSCREEN              4
#define QDI_STRETCHDIB               8

/* Spooler Error Codes */
#define SP_NOTREPORTED               0x4000
#define SP_ERROR                     (-1)
#define SP_APPABORT                  (-2)
#define SP_USERABORT                 (-3)
#define SP_OUTOFDISK                 (-4)
#define SP_OUTOFMEMORY               (-5)

#define PR_JOBSTATUS                 0x0000

/* Object Definitions for EnumObjects() */
#define OBJ_PEN             1
#define OBJ_BRUSH           2
#define OBJ_DC              3
#define OBJ_METADC          4
#define OBJ_PAL             5
#define OBJ_FONT            6
#define OBJ_BITMAP          7
#define OBJ_REGION          8
#define OBJ_METAFILE        9
#define OBJ_MEMDC           10
#define OBJ_EXTPEN          11
#define OBJ_ENHMETADC       12
#define OBJ_ENHMETAFILE     13

/* xform stuff */
#define MWT_IDENTITY        1
#define MWT_LEFTMULTIPLY    2
#define MWT_RIGHTMULTIPLY   3

#define MWT_MIN             MWT_IDENTITY
#define MWT_MAX             MWT_RIGHTMULTIPLY

#define _XFORM_
typedef struct  tagXFORM
  {
    float   eM11;
    float   eM12;
    float   eM21;
    float   eM22;
    float   eDx;
    float   eDy;
  } XFORM, *PXFORM,  *LPXFORM;

/* Bitmap Header Definition */
typedef struct tagBITMAP
  {
    long        bmType;
    long        bmWidth;
    long        bmHeight;
    long        bmWidthBytes;
    WORD        bmPlanes;
    WORD        bmBitsPixel;
    void*      bmBits;
  } BITMAP, *PBITMAP,  *NPBITMAP,  *LPBITMAP;

#include <pshpack1.h>
typedef struct tagRGBTRIPLE {
        BYTE    rgbtBlue;
        BYTE    rgbtGreen;
        BYTE    rgbtRed;
} RGBTRIPLE;
#include <poppack.h>

typedef struct tagRGBQUAD {
        BYTE    rgbBlue;
        BYTE    rgbGreen;
        BYTE    rgbRed;
        BYTE    rgbReserved;
} RGBQUAD;
typedef RGBQUAD * LPRGBQUAD;

#if(WINVER >= 0x0400)

/* Image Color Matching color definitions */

typedef long   LCSCSTYPE;
#define LCS_CALIBRATED_RGB              0x00000000L
#define LCS_DEVICE_RGB                  0x00000001L
#define LCS_DEVICE_CMYK                 0x00000002L

typedef long    LCSGAMUTMATCH;
#define LCS_GM_BUSINESS                 0x00000001L
#define LCS_GM_GRAPHICS                 0x00000002L
#define LCS_GM_IMAGES                   0x00000004L

/* ICM Defines for results from CheckColorInGamut() */
#define CM_OUT_OF_GAMUT         255
#define CM_IN_GAMUT                     0

/* Macros to retrieve CMYK values from a COLORREF */
#define GetKValue(cmyk)      ((BYTE)(cmyk))
#define GetYValue(cmyk)      ((BYTE)((cmyk)>> 8))
#define GetMValue(cmyk)      ((BYTE)((cmyk)>>16))
#define GetCValue(cmyk)      ((BYTE)((cmyk)>>24))

#define CMYK(c,m,y,k)       ((COLORREF)((((BYTE)(k)|((WORD)((BYTE)(y))<<8))|(((unsigned long)(BYTE)(m))<<16))|(((unsigned long)(BYTE)(c))<<24)))

typedef long            FXPT16DOT16,  *LPFXPT16DOT16;
typedef long            FXPT2DOT30,  *LPFXPT2DOT30;

/* ICM Color Definitions */
// The following two structures are used for defining RGB's in terms of
// CIEXYZ. The values are fixed point 16.16.

typedef struct tagCIEXYZ
{
        FXPT2DOT30 ciexyzX;
        FXPT2DOT30 ciexyzY;
        FXPT2DOT30 ciexyzZ;
} CIEXYZ;
typedef CIEXYZ   *LPCIEXYZ;

typedef struct tagICEXYZTRIPLE
{
        CIEXYZ  ciexyzRed;
        CIEXYZ  ciexyzGreen;
        CIEXYZ  ciexyzBlue;
} CIEXYZTRIPLE;
typedef CIEXYZTRIPLE     *LPCIEXYZTRIPLE;

// The next structures the logical color space. Unlike pens and brushes,
// but like palettes, there is only one way to create a LogColorSpace.
// A pointer to it must be passed, its elements can't be pushed as
// arguments.

typedef struct tagLOGCOLORSPACEA {
    unsigned long lcsSignature;
    unsigned long lcsVersion;
    unsigned long lcsSize;
    LCSCSTYPE lcsCSType;
    LCSGAMUTMATCH lcsIntent;
    CIEXYZTRIPLE lcsEndpoints;
    unsigned long lcsGammaRed;
    unsigned long lcsGammaGreen;
    unsigned long lcsGammaBlue;
    CHAR   lcsFilename[MAX_PATH];
} LOGCOLORSPACEA, *LPLOGCOLORSPACEA;
typedef struct tagLOGCOLORSPACEW {
    unsigned long lcsSignature;
    unsigned long lcsVersion;
    unsigned long lcsSize;
    LCSCSTYPE lcsCSType;
    LCSGAMUTMATCH lcsIntent;
    CIEXYZTRIPLE lcsEndpoints;
    unsigned long lcsGammaRed;
    unsigned long lcsGammaGreen;
    unsigned long lcsGammaBlue;
    WCHAR  lcsFilename[MAX_PATH];
} LOGCOLORSPACEW, *LPLOGCOLORSPACEW;
#ifdef UNICODE
typedef LOGCOLORSPACEW LOGCOLORSPACE;
typedef LPLOGCOLORSPACEW LPLOGCOLORSPACE;
#else
typedef LOGCOLORSPACEA LOGCOLORSPACE;
typedef LPLOGCOLORSPACEA LPLOGCOLORSPACE;
#endif // UNICODE

#endif /* WINVER >= 0x0400 */


/* structures for defining DIBs */
typedef struct tagBITMAPCOREHEADER {
        unsigned long   bcSize;                 /* used to get to color table */
        WORD    bcWidth;
        WORD    bcHeight;
        WORD    bcPlanes;
        WORD    bcBitCount;
} BITMAPCOREHEADER,  *LPBITMAPCOREHEADER, *PBITMAPCOREHEADER;


typedef struct tagBITMAPINFOHEADER{
        unsigned long      biSize;
        long       biWidth;
        long       biHeight;
        WORD       biPlanes;
        WORD       biBitCount;
        unsigned long      biCompression;
        unsigned long      biSizeImage;
        long       biXPelsPerMeter;
        long       biYPelsPerMeter;
        unsigned long      biClrUsed;
        unsigned long      biClrImportant;
} BITMAPINFOHEADER,  *LPBITMAPINFOHEADER, *PBITMAPINFOHEADER;


#if(WINVER >= 0x0400)
typedef struct {
        unsigned long        bV4Size;
        long         bV4Width;
        long         bV4Height;
        WORD         bV4Planes;
        WORD         bV4BitCount;
        unsigned long        bV4V4Compression;
        unsigned long        bV4SizeImage;
        long         bV4XPelsPerMeter;
        long         bV4YPelsPerMeter;
        unsigned long        bV4ClrUsed;
        unsigned long        bV4ClrImportant;
        unsigned long        bV4RedMask;
        unsigned long        bV4GreenMask;
        unsigned long        bV4BlueMask;
        unsigned long        bV4AlphaMask;
        unsigned long        bV4CSType;
        CIEXYZTRIPLE bV4Endpoints;
        unsigned long        bV4GammaRed;
        unsigned long        bV4GammaGreen;
        unsigned long        bV4GammaBlue;
} BITMAPV4HEADER,  *LPBITMAPV4HEADER, *PBITMAPV4HEADER;
#endif /* WINVER >= 0x0400 */

/* constants for the biCompression field */
#define BI_RGB        0L
#define BI_RLE8       1L
#define BI_RLE4       2L
#define BI_BITFIELDS  3L

typedef struct tagBITMAPINFO {
    BITMAPINFOHEADER    bmiHeader;
    RGBQUAD             bmiColors[1];
} BITMAPINFO,  *LPBITMAPINFO, *PBITMAPINFO;

typedef struct tagBITMAPCOREINFO {
    BITMAPCOREHEADER    bmciHeader;
    RGBTRIPLE           bmciColors[1];
} BITMAPCOREINFO,  *LPBITMAPCOREINFO, *PBITMAPCOREINFO;

#include <pshpack2.h>
typedef struct tagBITMAPFILEHEADER {
        WORD    bfType;
        unsigned long   bfSize;
        WORD    bfReserved1;
        WORD    bfReserved2;
        unsigned long   bfOffBits;
} BITMAPFILEHEADER,  *LPBITMAPFILEHEADER, *PBITMAPFILEHEADER;
#include <poppack.h>

#define MAKEPOINTS(l)       (*((POINTS  *)&(l)))

#if(WINVER >= 0x0400)
#ifndef NOFONTSIG
typedef struct tagFONTSIGNATURE
{
    unsigned long fsUsb[4];
    unsigned long fsCsb[2];
} FONTSIGNATURE, *PFONTSIGNATURE, *LPFONTSIGNATURE;

typedef struct tagCHARSETINFO
{
    unsigned ciCharset;
    unsigned ciACP;
    FONTSIGNATURE fs;
} CHARSETINFO, *PCHARSETINFO,  *NPCHARSETINFO,  *LPCHARSETINFO;

#define TCI_SRCCHARSET  1
#define TCI_SRCCODEPAGE 2
#define TCI_SRCFONTSIG  3

typedef struct tagLOCALESIGNATURE
{
    unsigned long lsUsb[4];
    unsigned long lsCsbDefault[2];
    unsigned long lsCsbSupported[2];
} LOCALESIGNATURE, *PLOCALESIGNATURE, *LPLOCALESIGNATURE;

#endif
#endif /* WINVER >= 0x0400 */
#ifndef NOMETAFILE

/* Clipboard Metafile Picture Structure */
typedef struct tagHANDLETABLE
  {
    HGDIOBJ     objectHandle[1];
  } HANDLETABLE, *PHANDLETABLE,  *LPHANDLETABLE;

typedef struct tagMETARECORD
  {
    unsigned long       rdSize;
    WORD        rdFunction;
    WORD        rdParm[1];
  } METARECORD;
typedef struct tagMETARECORD UNALIGNED *PMETARECORD;
typedef struct tagMETARECORD UNALIGNED  *LPMETARECORD;

typedef struct tagMETAFILEPICT
  {
    long        mm;
    long        xExt;
    long        yExt;
    HMETAFILE   hMF;
  } METAFILEPICT,  *LPMETAFILEPICT;

#include <pshpack2.h>
typedef struct tagMETAHEADER
{
    WORD        mtType;
    WORD        mtHeaderSize;
    WORD        mtVersion;
    unsigned long       mtSize;
    WORD        mtNoObjects;
    unsigned long       mtMaxRecord;
    WORD        mtNoParameters;
} METAHEADER;
typedef struct tagMETAHEADER UNALIGNED *PMETAHEADER;
typedef struct tagMETAHEADER UNALIGNED  *LPMETAHEADER;

#include <poppack.h>

/* Enhanced Metafile structures */
typedef struct tagENHMETARECORD
{
    unsigned long   iType;              // Record type EMR_XXX
    unsigned long   nSize;              // Record size in bytes
    unsigned long   dParm[1];           // Parameters
} ENHMETARECORD, *PENHMETARECORD, *LPENHMETARECORD;

typedef struct tagENHMETAHEADER
{
    unsigned long   iType;              // Record type EMR_HEADER
    unsigned long   nSize;              // Record size in bytes.  This may be greater
                                // than the sizeof(ENHMETAHEADER).
    RECTL   rclBounds;          // Inclusive-inclusive bounds in device units
    RECTL   rclFrame;           // Inclusive-inclusive Picture Frame of metafile in .01 mm units
    unsigned long   dSignature;         // Signature.  Must be ENHMETA_SIGNATURE.
    unsigned long   nVersion;           // Version number
    unsigned long   nBytes;             // Size of the metafile in bytes
    unsigned long   nRecords;           // Number of records in the metafile
    WORD    nHandles;           // Number of handles in the handle table
                                // Handle index zero is reserved.
    WORD    sReserved;          // Reserved.  Must be zero.
    unsigned long   nDescription;       // Number of chars in the unicode description string
                                // This is 0 if there is no description string
    unsigned long   offDescription;     // Offset to the metafile description record.
                                // This is 0 if there is no description string
    unsigned long   nPalEntries;        // Number of entries in the metafile palette.
    SIZEL   szlDevice;          // Size of the reference device in pels
    SIZEL   szlMillimeters;     // Size of the reference device in millimeters
    unsigned long   cbPixelFormat;      // Size of PIXELFORMATDESCRIPTOR information
                                // This is 0 if no pixel format is set
    unsigned long   offPixelFormat;     // Offset to PIXELFORMATDESCRIPTOR
                                // This is 0 if no pixel format is set
    unsigned long   bOpenGL;            // TRUE if OpenGL commands are present in
                                // the metafile, otherwise FALSE
} ENHMETAHEADER, *PENHMETAHEADER, *LPENHMETAHEADER;

#endif /* NOMETAFILE */

#ifndef NOTEXTMETRIC

/* tmPitchAndFamily flags */
#define TMPF_FIXED_PITCH    0x01
#define TMPF_VECTOR             0x02
#define TMPF_DEVICE             0x08
#define TMPF_TRUETYPE       0x04

//
// BCHAR definition for APPs
//
#ifdef UNICODE
    typedef WCHAR BCHAR;
#else
    typedef BYTE BCHAR;
#endif


typedef struct tagTEXTMETRICA
{
    long        tmHeight;
    long        tmAscent;
    long        tmDescent;
    long        tmInternalLeading;
    long        tmExternalLeading;
    long        tmAveCharWidth;
    long        tmMaxCharWidth;
    long        tmWeight;
    long        tmOverhang;
    long        tmDigitizedAspectX;
    long        tmDigitizedAspectY;
    BYTE        tmFirstChar;
    BYTE        tmLastChar;
    BYTE        tmDefaultChar;
    BYTE        tmBreakChar;
    BYTE        tmItalic;
    BYTE        tmUnderlined;
    BYTE        tmStruckOut;
    BYTE        tmPitchAndFamily;
    BYTE        tmCharSet;
} TEXTMETRICA, *PTEXTMETRICA,  *NPTEXTMETRICA,  *LPTEXTMETRICA;
typedef struct tagTEXTMETRICW
{
    long        tmHeight;
    long        tmAscent;
    long        tmDescent;
    long        tmInternalLeading;
    long        tmExternalLeading;
    long        tmAveCharWidth;
    long        tmMaxCharWidth;
    long        tmWeight;
    long        tmOverhang;
    long        tmDigitizedAspectX;
    long        tmDigitizedAspectY;
    WCHAR       tmFirstChar;
    WCHAR       tmLastChar;
    WCHAR       tmDefaultChar;
    WCHAR       tmBreakChar;
    BYTE        tmItalic;
    BYTE        tmUnderlined;
    BYTE        tmStruckOut;
    BYTE        tmPitchAndFamily;
    BYTE        tmCharSet;
} TEXTMETRICW, *PTEXTMETRICW,  *NPTEXTMETRICW,  *LPTEXTMETRICW;
#ifdef UNICODE
typedef TEXTMETRICW TEXTMETRIC;
typedef PTEXTMETRICW PTEXTMETRIC;
typedef NPTEXTMETRICW NPTEXTMETRIC;
typedef LPTEXTMETRICW LPTEXTMETRIC;
#else
typedef TEXTMETRICA TEXTMETRIC;
typedef PTEXTMETRICA PTEXTMETRIC;
typedef NPTEXTMETRICA NPTEXTMETRIC;
typedef LPTEXTMETRICA LPTEXTMETRIC;
#endif // UNICODE

/* ntmFlags field flags */
#define NTM_REGULAR     0x00000040L
#define NTM_BOLD        0x00000020L
#define NTM_ITALIC      0x00000001L

#include <pshpack4.h>
typedef struct tagNEWTEXTMETRICA
{
    long        tmHeight;
    long        tmAscent;
    long        tmDescent;
    long        tmInternalLeading;
    long        tmExternalLeading;
    long        tmAveCharWidth;
    long        tmMaxCharWidth;
    long        tmWeight;
    long        tmOverhang;
    long        tmDigitizedAspectX;
    long        tmDigitizedAspectY;
    BYTE        tmFirstChar;
    BYTE        tmLastChar;
    BYTE        tmDefaultChar;
    BYTE        tmBreakChar;
    BYTE        tmItalic;
    BYTE        tmUnderlined;
    BYTE        tmStruckOut;
    BYTE        tmPitchAndFamily;
    BYTE        tmCharSet;
    unsigned long   ntmFlags;
    unsigned    ntmSizeEM;
    unsigned    ntmCellHeight;
    unsigned    ntmAvgWidth;
} NEWTEXTMETRICA, *PNEWTEXTMETRICA,  *NPNEWTEXTMETRICA,  *LPNEWTEXTMETRICA;
typedef struct tagNEWTEXTMETRICW
{
    long        tmHeight;
    long        tmAscent;
    long        tmDescent;
    long        tmInternalLeading;
    long        tmExternalLeading;
    long        tmAveCharWidth;
    long        tmMaxCharWidth;
    long        tmWeight;
    long        tmOverhang;
    long        tmDigitizedAspectX;
    long        tmDigitizedAspectY;
    WCHAR       tmFirstChar;
    WCHAR       tmLastChar;
    WCHAR       tmDefaultChar;
    WCHAR       tmBreakChar;
    BYTE        tmItalic;
    BYTE        tmUnderlined;
    BYTE        tmStruckOut;
    BYTE        tmPitchAndFamily;
    BYTE        tmCharSet;
    unsigned long   ntmFlags;
    unsigned    ntmSizeEM;
    unsigned    ntmCellHeight;
    unsigned    ntmAvgWidth;
} NEWTEXTMETRICW, *PNEWTEXTMETRICW,  *NPNEWTEXTMETRICW,  *LPNEWTEXTMETRICW;
#ifdef UNICODE
typedef NEWTEXTMETRICW NEWTEXTMETRIC;
typedef PNEWTEXTMETRICW PNEWTEXTMETRIC;
typedef NPNEWTEXTMETRICW NPNEWTEXTMETRIC;
typedef LPNEWTEXTMETRICW LPNEWTEXTMETRIC;
#else
typedef NEWTEXTMETRICA NEWTEXTMETRIC;
typedef PNEWTEXTMETRICA PNEWTEXTMETRIC;
typedef NPNEWTEXTMETRICA NPNEWTEXTMETRIC;
typedef LPNEWTEXTMETRICA LPNEWTEXTMETRIC;
#endif // UNICODE
#include <poppack.h>

#if(WINVER >= 0x0400)
typedef struct tagNEWTEXTMETRICEXA
{
    NEWTEXTMETRICA  ntmTm;
    FONTSIGNATURE   ntmFontSig;
}NEWTEXTMETRICEXA;
typedef struct tagNEWTEXTMETRICEXW
{
    NEWTEXTMETRICW  ntmTm;
    FONTSIGNATURE   ntmFontSig;
}NEWTEXTMETRICEXW;
#ifdef UNICODE
typedef NEWTEXTMETRICEXW NEWTEXTMETRICEX;
#else
typedef NEWTEXTMETRICEXA NEWTEXTMETRICEX;
#endif // UNICODE
#endif /* WINVER >= 0x0400 */

#endif /* NOTEXTMETRIC */
/* GDI Logical Objects: */

/* Pel Array */
typedef struct tagPELARRAY
  {
    long        paXCount;
    long        paYCount;
    long        paXExt;
    long        paYExt;
    BYTE        paRGBs;
  } PELARRAY, *PPELARRAY,  *NPPELARRAY,  *LPPELARRAY;

/* Logical Brush (or Pattern) */
typedef struct tagLOGBRUSH
  {
    unsigned        lbStyle;
    COLORREF    lbColor;
    long        lbHatch;
  } LOGBRUSH, *PLOGBRUSH,  *NPLOGBRUSH,  *LPLOGBRUSH;

typedef LOGBRUSH            PATTERN;
typedef PATTERN             *PPATTERN;
typedef PATTERN         *NPPATTERN;
typedef PATTERN          *LPPATTERN;

/* Logical Pen */
typedef struct tagLOGPEN
  {
    unsigned        lopnStyle;
    POINT       lopnWidth;
    COLORREF    lopnColor;
  } LOGPEN, *PLOGPEN,  *NPLOGPEN,  *LPLOGPEN;

typedef struct tagEXTLOGPEN {
    unsigned long       elpPenStyle;
    unsigned long       elpWidth;
    unsigned        elpBrushStyle;
    COLORREF    elpColor;
    long        elpHatch;
    unsigned long       elpNumEntries;
    unsigned long       elpStyleEntry[1];
} EXTLOGPEN, *PEXTLOGPEN,  *NPEXTLOGPEN,  *LPEXTLOGPEN;

typedef struct tagPALETTEENTRY {
    BYTE        peRed;
    BYTE        peGreen;
    BYTE        peBlue;
    BYTE        peFlags;
} PALETTEENTRY, *PPALETTEENTRY,  *LPPALETTEENTRY;

/* Logical Palette */
typedef struct tagLOGPALETTE {
    WORD        palVersion;
    WORD        palNumEntries;
    PALETTEENTRY        palPalEntry[1];
} LOGPALETTE, *PLOGPALETTE,  *NPLOGPALETTE,  *LPLOGPALETTE;


/* Logical Font */
#define LF_FACESIZE         32

typedef struct tagLOGFONTA
{
    long      lfHeight;
    long      lfWidth;
    long      lfEscapement;
    long      lfOrientation;
    long      lfWeight;
    BYTE      lfItalic;
    BYTE      lfUnderline;
    BYTE      lfStrikeOut;
    BYTE      lfCharSet;
    BYTE      lfOutPrecision;
    BYTE      lfClipPrecision;
    BYTE      lfQuality;
    BYTE      lfPitchAndFamily;
    CHAR      lfFaceName[LF_FACESIZE];
} LOGFONTA, *PLOGFONTA,  *NPLOGFONTA,  *LPLOGFONTA;
typedef struct tagLOGFONTW
{
    long      lfHeight;
    long      lfWidth;
    long      lfEscapement;
    long      lfOrientation;
    long      lfWeight;
    BYTE      lfItalic;
    BYTE      lfUnderline;
    BYTE      lfStrikeOut;
    BYTE      lfCharSet;
    BYTE      lfOutPrecision;
    BYTE      lfClipPrecision;
    BYTE      lfQuality;
    BYTE      lfPitchAndFamily;
    WCHAR     lfFaceName[LF_FACESIZE];
} LOGFONTW, *PLOGFONTW,  *NPLOGFONTW,  *LPLOGFONTW;
#ifdef UNICODE
typedef LOGFONTW LOGFONT;
typedef PLOGFONTW PLOGFONT;
typedef NPLOGFONTW NPLOGFONT;
typedef LPLOGFONTW LPLOGFONT;
#else
typedef LOGFONTA LOGFONT;
typedef PLOGFONTA PLOGFONT;
typedef NPLOGFONTA NPLOGFONT;
typedef LPLOGFONTA LPLOGFONT;
#endif // UNICODE

#define LF_FULLFACESIZE     64

/* Structure passed to FONTENUMPROC */
typedef struct tagENUMLOGFONTA
{
    LOGFONTA elfLogFont;
    BYTE     elfFullName[LF_FULLFACESIZE];
    BYTE     elfStyle[LF_FACESIZE];
} ENUMLOGFONTA, * LPENUMLOGFONTA;
/* Structure passed to FONTENUMPROC */
typedef struct tagENUMLOGFONTW
{
    LOGFONTW elfLogFont;
    WCHAR    elfFullName[LF_FULLFACESIZE];
    WCHAR    elfStyle[LF_FACESIZE];
} ENUMLOGFONTW, * LPENUMLOGFONTW;
#ifdef UNICODE
typedef ENUMLOGFONTW ENUMLOGFONT;
typedef LPENUMLOGFONTW LPENUMLOGFONT;
#else
typedef ENUMLOGFONTA ENUMLOGFONT;
typedef LPENUMLOGFONTA LPENUMLOGFONT;
#endif // UNICODE

#if(WINVER >= 0x0400)
typedef struct tagENUMLOGFONTEXA
{
    LOGFONTA    elfLogFont;
    BYTE        elfFullName[LF_FULLFACESIZE];
    BYTE        elfStyle[LF_FACESIZE];
    BYTE        elfScript[LF_FACESIZE];
} ENUMLOGFONTEXA,  *LPENUMLOGFONTEXA;
typedef struct tagENUMLOGFONTEXW
{
    LOGFONTW    elfLogFont;
    WCHAR       elfFullName[LF_FULLFACESIZE];
    WCHAR       elfStyle[LF_FACESIZE];
    WCHAR       elfScript[LF_FACESIZE];
} ENUMLOGFONTEXW,  *LPENUMLOGFONTEXW;
#ifdef UNICODE
typedef ENUMLOGFONTEXW ENUMLOGFONTEX;
typedef LPENUMLOGFONTEXW LPENUMLOGFONTEX;
#else
typedef ENUMLOGFONTEXA ENUMLOGFONTEX;
typedef LPENUMLOGFONTEXA LPENUMLOGFONTEX;
#endif // UNICODE
#endif /* WINVER >= 0x0400 */

#define OUT_DEFAULT_PRECIS          0
#define OUT_STRING_PRECIS           1
#define OUT_CHARACTER_PRECIS        2
#define OUT_STROKE_PRECIS           3
#define OUT_TT_PRECIS               4
#define OUT_DEVICE_PRECIS           5
#define OUT_RASTER_PRECIS           6
#define OUT_TT_ONLY_PRECIS          7
#define OUT_OUTLINE_PRECIS          8
#define OUT_SCREEN_OUTLINE_PRECIS   9

#define CLIP_DEFAULT_PRECIS     0
#define CLIP_CHARACTER_PRECIS   1
#define CLIP_STROKE_PRECIS      2
#define CLIP_MASK               0xf
#define CLIP_LH_ANGLES          (1<<4)
#define CLIP_TT_ALWAYS          (2<<4)
#define CLIP_EMBEDDED           (8<<4)

#define DEFAULT_QUALITY         0
#define DRAFT_QUALITY           1
#define PROOF_QUALITY           2
#if(WINVER >= 0x0400)
#define NONANTIALIASED_QUALITY  3
#define ANTIALIASED_QUALITY     4
#endif /* WINVER >= 0x0400 */

#define DEFAULT_PITCH           0
#define FIXED_PITCH             1
#define VARIABLE_PITCH          2
#if(WINVER >= 0x0400)
#define MONO_FONT               8
#endif /* WINVER >= 0x0400 */

#define ANSI_CHARSET            0
#define DEFAULT_CHARSET         1
#define SYMBOL_CHARSET          2
#define SHIFTJIS_CHARSET        128
#define HANGEUL_CHARSET         129
#define GB2312_CHARSET          134
#define CHINESEBIG5_CHARSET     136
#define OEM_CHARSET             255
#if(WINVER >= 0x0400)
#define JOHAB_CHARSET           130
#define HEBREW_CHARSET          177
#define ARABIC_CHARSET          178
#define GREEK_CHARSET           161
#define TURKISH_CHARSET         162
#define VIETNAMESE_CHARSET      163
#define THAI_CHARSET            222
#define EASTEUROPE_CHARSET      238
#define RUSSIAN_CHARSET         204

#define MAC_CHARSET             77
#define BALTIC_CHARSET          186

#define FS_LATIN1               0x00000001L
#define FS_LATIN2               0x00000002L
#define FS_CYRILLIC             0x00000004L
#define FS_GREEK                0x00000008L
#define FS_TURKISH              0x00000010L
#define FS_HEBREW               0x00000020L
#define FS_ARABIC               0x00000040L
#define FS_BALTIC               0x00000080L
#define FS_VIETNAMESE           0x00000100L
#define FS_THAI                 0x00010000L
#define FS_JISJAPAN             0x00020000L
#define FS_CHINESESIMP          0x00040000L
#define FS_WANSUNG              0x00080000L
#define FS_CHINESETRAD          0x00100000L
#define FS_JOHAB                0x00200000L
#define FS_SYMBOL               0x80000000L
#endif /* WINVER >= 0x0400 */

/* Font Families */
#define FF_DONTCARE         (0<<4)  /* Don't care or don't know. */
#define FF_ROMAN            (1<<4)  /* Variable stroke width, serifed. */
                                    /* Times Roman, Century Schoolbook, etc. */
#define FF_SWISS            (2<<4)  /* Variable stroke width, sans-serifed. */
                                    /* Helvetica, Swiss, etc. */
#define FF_MODERN           (3<<4)  /* Constant stroke width, serifed or sans-serifed. */
                                    /* Pica, Elite, Courier, etc. */
#define FF_SCRIPT           (4<<4)  /* Cursive, etc. */
#define FF_DECORATIVE       (5<<4)  /* Old English, etc. */

/* Font Weights */
#define FW_DONTCARE         0
#define FW_THIN             100
#define FW_EXTRALIGHT       200
#define FW_LIGHT            300
#define FW_NORMAL           400
#define FW_MEDIUM           500
#define FW_SEMIBOLD         600
#define FW_BOLD             700
#define FW_EXTRABOLD        800
#define FW_HEAVY            900

#define FW_ULTRALIGHT       FW_EXTRALIGHT
#define FW_REGULAR          FW_NORMAL
#define FW_DEMIBOLD         FW_SEMIBOLD
#define FW_ULTRABOLD        FW_EXTRABOLD
#define FW_BLACK            FW_HEAVY

#define PANOSE_COUNT               10
#define PAN_FAMILYTYPE_INDEX        0
#define PAN_SERIFSTYLE_INDEX        1
#define PAN_WEIGHT_INDEX            2
#define PAN_PROPORTION_INDEX        3
#define PAN_CONTRAST_INDEX          4
#define PAN_STROKEVARIATION_INDEX   5
#define PAN_ARMSTYLE_INDEX          6
#define PAN_LETTERFORM_INDEX        7
#define PAN_MIDLINE_INDEX           8
#define PAN_XHEIGHT_INDEX           9

#define PAN_CULTURE_LATIN           0

typedef struct tagPANOSE
{
    BYTE    bFamilyType;
    BYTE    bSerifStyle;
    BYTE    bWeight;
    BYTE    bProportion;
    BYTE    bContrast;
    BYTE    bStrokeVariation;
    BYTE    bArmStyle;
    BYTE    bLetterform;
    BYTE    bMidline;
    BYTE    bXHeight;
} PANOSE, * LPPANOSE;

#define PAN_ANY                         0 /* Any                            */
#define PAN_NO_FIT                      1 /* No Fit                         */

#define PAN_FAMILY_TEXT_DISPLAY         2 /* Text and Display               */
#define PAN_FAMILY_SCRIPT               3 /* Script                         */
#define PAN_FAMILY_DECORATIVE           4 /* Decorative                     */
#define PAN_FAMILY_PICTORIAL            5 /* Pictorial                      */

#define PAN_SERIF_COVE                  2 /* Cove                           */
#define PAN_SERIF_OBTUSE_COVE           3 /* Obtuse Cove                    */
#define PAN_SERIF_SQUARE_COVE           4 /* Square Cove                    */
#define PAN_SERIF_OBTUSE_SQUARE_COVE    5 /* Obtuse Square Cove             */
#define PAN_SERIF_SQUARE                6 /* Square                         */
#define PAN_SERIF_THIN                  7 /* Thin                           */
#define PAN_SERIF_BONE                  8 /* Bone                           */
#define PAN_SERIF_EXAGGERATED           9 /* Exaggerated                    */
#define PAN_SERIF_TRIANGLE             10 /* Triangle                       */
#define PAN_SERIF_NORMAL_SANS          11 /* Normal Sans                    */
#define PAN_SERIF_OBTUSE_SANS          12 /* Obtuse Sans                    */
#define PAN_SERIF_PERP_SANS            13 /* Prep Sans                      */
#define PAN_SERIF_FLARED               14 /* Flared                         */
#define PAN_SERIF_ROUNDED              15 /* Rounded                        */

#define PAN_WEIGHT_VERY_LIGHT           2 /* Very Light                     */
#define PAN_WEIGHT_LIGHT                3 /* Light                          */
#define PAN_WEIGHT_THIN                 4 /* Thin                           */
#define PAN_WEIGHT_BOOK                 5 /* Book                           */
#define PAN_WEIGHT_MEDIUM               6 /* Medium                         */
#define PAN_WEIGHT_DEMI                 7 /* Demi                           */
#define PAN_WEIGHT_BOLD                 8 /* Bold                           */
#define PAN_WEIGHT_HEAVY                9 /* Heavy                          */
#define PAN_WEIGHT_BLACK               10 /* Black                          */
#define PAN_WEIGHT_NORD                11 /* Nord                           */

#define PAN_PROP_OLD_STYLE              2 /* Old Style                      */
#define PAN_PROP_MODERN                 3 /* Modern                         */
#define PAN_PROP_EVEN_WIDTH             4 /* Even Width                     */
#define PAN_PROP_EXPANDED               5 /* Expanded                       */
#define PAN_PROP_CONDENSED              6 /* Condensed                      */
#define PAN_PROP_VERY_EXPANDED          7 /* Very Expanded                  */
#define PAN_PROP_VERY_CONDENSED         8 /* Very Condensed                 */
#define PAN_PROP_MONOSPACED             9 /* Monospaced                     */

#define PAN_CONTRAST_NONE               2 /* None                           */
#define PAN_CONTRAST_VERY_LOW           3 /* Very Low                       */
#define PAN_CONTRAST_LOW                4 /* Low                            */
#define PAN_CONTRAST_MEDIUM_LOW         5 /* Medium Low                     */
#define PAN_CONTRAST_MEDIUM             6 /* Medium                         */
#define PAN_CONTRAST_MEDIUM_HIGH        7 /* Mediim High                    */
#define PAN_CONTRAST_HIGH               8 /* High                           */
#define PAN_CONTRAST_VERY_HIGH          9 /* Very High                      */

#define PAN_STROKE_GRADUAL_DIAG         2 /* Gradual/Diagonal               */
#define PAN_STROKE_GRADUAL_TRAN         3 /* Gradual/Transitional           */
#define PAN_STROKE_GRADUAL_VERT         4 /* Gradual/Vertical               */
#define PAN_STROKE_GRADUAL_HORZ         5 /* Gradual/Horizontal             */
#define PAN_STROKE_RAPID_VERT           6 /* Rapid/Vertical                 */
#define PAN_STROKE_RAPID_HORZ           7 /* Rapid/Horizontal               */
#define PAN_STROKE_INSTANT_VERT         8 /* Instant/Vertical               */

#define PAN_STRAIGHT_ARMS_HORZ          2 /* Straight Arms/Horizontal       */
#define PAN_STRAIGHT_ARMS_WEDGE         3 /* Straight Arms/Wedge            */
#define PAN_STRAIGHT_ARMS_VERT          4 /* Straight Arms/Vertical         */
#define PAN_STRAIGHT_ARMS_SINGLE_SERIF  5 /* Straight Arms/Single-Serif     */
#define PAN_STRAIGHT_ARMS_DOUBLE_SERIF  6 /* Straight Arms/Double-Serif     */
#define PAN_BENT_ARMS_HORZ              7 /* Non-Straight Arms/Horizontal   */
#define PAN_BENT_ARMS_WEDGE             8 /* Non-Straight Arms/Wedge        */
#define PAN_BENT_ARMS_VERT              9 /* Non-Straight Arms/Vertical     */
#define PAN_BENT_ARMS_SINGLE_SERIF     10 /* Non-Straight Arms/Single-Serif */
#define PAN_BENT_ARMS_DOUBLE_SERIF     11 /* Non-Straight Arms/Double-Serif */

#define PAN_LETT_NORMAL_CONTACT         2 /* Normal/Contact                 */
#define PAN_LETT_NORMAL_WEIGHTED        3 /* Normal/Weighted                */
#define PAN_LETT_NORMAL_BOXED           4 /* Normal/Boxed                   */
#define PAN_LETT_NORMAL_FLATTENED       5 /* Normal/Flattened               */
#define PAN_LETT_NORMAL_ROUNDED         6 /* Normal/Rounded                 */
#define PAN_LETT_NORMAL_OFF_CENTER      7 /* Normal/Off Center              */
#define PAN_LETT_NORMAL_SQUARE          8 /* Normal/Square                  */
#define PAN_LETT_OBLIQUE_CONTACT        9 /* Oblique/Contact                */
#define PAN_LETT_OBLIQUE_WEIGHTED      10 /* Oblique/Weighted               */
#define PAN_LETT_OBLIQUE_BOXED         11 /* Oblique/Boxed                  */
#define PAN_LETT_OBLIQUE_FLATTENED     12 /* Oblique/Flattened              */
#define PAN_LETT_OBLIQUE_ROUNDED       13 /* Oblique/Rounded                */
#define PAN_LETT_OBLIQUE_OFF_CENTER    14 /* Oblique/Off Center             */
#define PAN_LETT_OBLIQUE_SQUARE        15 /* Oblique/Square                 */

#define PAN_MIDLINE_STANDARD_TRIMMED    2 /* Standard/Trimmed               */
#define PAN_MIDLINE_STANDARD_POINTED    3 /* Standard/Pointed               */
#define PAN_MIDLINE_STANDARD_SERIFED    4 /* Standard/Serifed               */
#define PAN_MIDLINE_HIGH_TRIMMED        5 /* High/Trimmed                   */
#define PAN_MIDLINE_HIGH_POINTED        6 /* High/Pointed                   */
#define PAN_MIDLINE_HIGH_SERIFED        7 /* High/Serifed                   */
#define PAN_MIDLINE_CONSTANT_TRIMMED    8 /* Constant/Trimmed               */
#define PAN_MIDLINE_CONSTANT_POINTED    9 /* Constant/Pointed               */
#define PAN_MIDLINE_CONSTANT_SERIFED   10 /* Constant/Serifed               */
#define PAN_MIDLINE_LOW_TRIMMED        11 /* Low/Trimmed                    */
#define PAN_MIDLINE_LOW_POINTED        12 /* Low/Pointed                    */
#define PAN_MIDLINE_LOW_SERIFED        13 /* Low/Serifed                    */

#define PAN_XHEIGHT_CONSTANT_SMALL      2 /* Constant/Small                 */
#define PAN_XHEIGHT_CONSTANT_STD        3 /* Constant/Standard              */
#define PAN_XHEIGHT_CONSTANT_LARGE      4 /* Constant/Large                 */
#define PAN_XHEIGHT_DUCKING_SMALL       5 /* Ducking/Small                  */
#define PAN_XHEIGHT_DUCKING_STD         6 /* Ducking/Standard               */
#define PAN_XHEIGHT_DUCKING_LARGE       7 /* Ducking/Large                  */


#define ELF_VENDOR_SIZE     4

/* The extended logical font       */
/* An extension of the ENUMLOGFONT */

typedef struct tagEXTLOGFONTA {
    LOGFONTA    elfLogFont;
    BYTE        elfFullName[LF_FULLFACESIZE];
    BYTE        elfStyle[LF_FACESIZE];
    unsigned long       elfVersion;     /* 0 for the first release of NT */
    unsigned long       elfStyleSize;
    unsigned long       elfMatch;
    unsigned long       elfReserved;
    BYTE        elfVendorId[ELF_VENDOR_SIZE];
    unsigned long       elfCulture;     /* 0 for Latin                   */
    PANOSE      elfPanose;
} EXTLOGFONTA, *PEXTLOGFONTA,  *NPEXTLOGFONTA,  *LPEXTLOGFONTA;
typedef struct tagEXTLOGFONTW {
    LOGFONTW    elfLogFont;
    WCHAR       elfFullName[LF_FULLFACESIZE];
    WCHAR       elfStyle[LF_FACESIZE];
    unsigned long       elfVersion;     /* 0 for the first release of NT */
    unsigned long       elfStyleSize;
    unsigned long       elfMatch;
    unsigned long       elfReserved;
    BYTE        elfVendorId[ELF_VENDOR_SIZE];
    unsigned long       elfCulture;     /* 0 for Latin                   */
    PANOSE      elfPanose;
} EXTLOGFONTW, *PEXTLOGFONTW,  *NPEXTLOGFONTW,  *LPEXTLOGFONTW;
#ifdef UNICODE
typedef EXTLOGFONTW EXTLOGFONT;
typedef PEXTLOGFONTW PEXTLOGFONT;
typedef NPEXTLOGFONTW NPEXTLOGFONT;
typedef LPEXTLOGFONTW LPEXTLOGFONT;
#else
typedef EXTLOGFONTA EXTLOGFONT;
typedef PEXTLOGFONTA PEXTLOGFONT;
typedef NPEXTLOGFONTA NPEXTLOGFONT;
typedef LPEXTLOGFONTA LPEXTLOGFONT;
#endif // UNICODE


#define ELF_VERSION         0
#define ELF_CULTURE_LATIN   0

/* EnumFonts Masks */
#define RASTER_FONTTYPE     0x0001
#define DEVICE_FONTTYPE     0x002
#define TRUETYPE_FONTTYPE   0x004

#define RGB(r,g,b)          ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((unsigned long)(BYTE)(b))<<16)))
#define PALETTERGB(r,g,b)   (0x02000000 | RGB(r,g,b))
#define PALETTEINDEX(i)     ((COLORREF)(0x01000000 | (unsigned long)(WORD)(i)))

/* palette entry flags */

#define PC_RESERVED     0x01    /* palette index used for animation */
#define PC_EXPLICIT     0x02    /* palette index is explicit to device */
#define PC_NOCOLLAPSE   0x04    /* do not match color to system palette */

#define GetRValue(rgb)      ((BYTE)(rgb))
#define GetGValue(rgb)      ((BYTE)(((WORD)(rgb)) >> 8))
#define GetBValue(rgb)      ((BYTE)((rgb)>>16))

/* Background Modes */
#define TRANSPARENT         1
#define OPAQUE              2
#define BKMODE_LAST         2

/* Graphics Modes */

#define GM_COMPATIBLE       1
#define GM_ADVANCED         2
#define GM_LAST             2

/* PolyDraw and GetPath point types */
#define PT_CLOSEFIGURE      0x01
#define PT_LINETO           0x02
#define PT_BEZIERTO         0x04
#define PT_MOVETO           0x06

/* Mapping Modes */
#define MM_TEXT             1
#define MM_LOMETRIC         2
#define MM_HIMETRIC         3
#define MM_LOENGLISH        4
#define MM_HIENGLISH        5
#define MM_TWIPS            6
#define MM_ISOTROPIC        7
#define MM_ANISOTROPIC      8

/* Min and Max Mapping Mode values */
#define MM_MIN              MM_TEXT
#define MM_MAX              MM_ANISOTROPIC
#define MM_MAX_FIXEDSCALE   MM_TWIPS

/* Coordinate Modes */
#define ABSOLUTE            1
#define RELATIVE            2

/* Stock Logical Objects */
#define WHITE_BRUSH         0
#define LTGRAY_BRUSH        1
#define GRAY_BRUSH          2
#define DKGRAY_BRUSH        3
#define BLACK_BRUSH         4
#define NULL_BRUSH          5
#define HOLLOW_BRUSH        NULL_BRUSH
#define WHITE_PEN           6
#define BLACK_PEN           7
#define NULL_PEN            8
#define OEM_FIXED_FONT      10
#define ANSI_FIXED_FONT     11
#define ANSI_VAR_FONT       12
#define SYSTEM_FONT         13
#define DEVICE_DEFAULT_FONT 14
#define DEFAULT_PALETTE     15
#define SYSTEM_FIXED_FONT   16
#if(WINVER >= 0x0400)
#define DEFAULT_GUI_FONT    17
#endif /* WINVER >= 0x0400 */

#if (WINVER >= 0x0400)
#define STOCK_LAST          17
#else
#define STOCK_LAST          16
#endif

#define CLR_INVALID     0xFFFFFFFF

/* Brush Styles */
#define BS_SOLID            0
#define BS_NULL             1
#define BS_HOLLOW           BS_NULL
#define BS_HATCHED          2
#define BS_PATTERN          3
#define BS_INDEXED          4
#define BS_DIBPATTERN       5
#define BS_DIBPATTERNPT     6
#define BS_PATTERN8X8       7
#define BS_DIBPATTERN8X8    8
#define BS_MONOPATTERN      9

/* Hatch Styles */
#define HS_HORIZONTAL       0       /* ----- */
#define HS_VERTICAL         1       /* ||||| */
#define HS_FDIAGONAL        2       /* \\\\\ */
#define HS_BDIAGONAL        3       /* ///// */
#define HS_CROSS            4       /* +++++ */
#define HS_DIAGCROSS        5       /* xxxxx */

/* Pen Styles */
#define PS_SOLID            0
#define PS_DASH             1       /* -------  */
#define PS_DOT              2       /* .......  */
#define PS_DASHDOT          3       /* _._._._  */
#define PS_DASHDOTDOT       4       /* _.._.._  */
#define PS_NULL             5
#define PS_INSIDEFRAME      6
#define PS_USERSTYLE        7
#define PS_ALTERNATE        8
#define PS_STYLE_MASK       0x0000000F

#define PS_ENDCAP_ROUND     0x00000000
#define PS_ENDCAP_SQUARE    0x00000100
#define PS_ENDCAP_FLAT      0x00000200
#define PS_ENDCAP_MASK      0x00000F00

#define PS_JOIN_ROUND       0x00000000
#define PS_JOIN_BEVEL       0x00001000
#define PS_JOIN_MITER       0x00002000
#define PS_JOIN_MASK        0x0000F000

#define PS_COSMETIC         0x00000000
#define PS_GEOMETRIC        0x00010000
#define PS_TYPE_MASK        0x000F0000

#define AD_COUNTERCLOCKWISE 1
#define AD_CLOCKWISE        2

/* Device Parameters for GetDeviceCaps() */
#define DRIVERVERSION 0     /* Device driver version                    */
#define TECHNOLOGY    2     /* Device classification                    */
#define HORZSIZE      4     /* Horizontal size in millimeters           */
#define VERTSIZE      6     /* Vertical size in millimeters             */
#define HORZRES       8     /* Horizontal width in pixels               */
#define VERTRES       10    /* Vertical height in pixels                */
#define BITSPIXEL     12    /* Number of bits per pixel                 */
#define PLANES        14    /* Number of planes                         */
#define NUMBRUSHES    16    /* Number of brushes the device has         */
#define NUMPENS       18    /* Number of pens the device has            */
#define NUMMARKERS    20    /* Number of markers the device has         */
#define NUMFONTS      22    /* Number of fonts the device has           */
#define NUMCOLORS     24    /* Number of colors the device supports     */
#define PDEVICESIZE   26    /* Size required for device descriptor      */
#define CURVECAPS     28    /* Curve capabilities                       */
#define LINECAPS      30    /* Line capabilities                        */
#define POLYGONALCAPS 32    /* Polygonal capabilities                   */
#define TEXTCAPS      34    /* Text capabilities                        */
#define CLIPCAPS      36    /* Clipping capabilities                    */
#define RASTERCAPS    38    /* Bitblt capabilities                      */
#define ASPECTX       40    /* Length of the X leg                      */
#define ASPECTY       42    /* Length of the Y leg                      */
#define ASPECTXY      44    /* Length of the hypotenuse                 */

#define LOGPIXELSX    88    /* Logical pixels/inch in X                 */
#define LOGPIXELSY    90    /* Logical pixels/inch in Y                 */

#define SIZEPALETTE  104    /* Number of entries in physical palette    */
#define NUMRESERVED  106    /* Number of reserved entries in palette    */
#define COLORRES     108    /* Actual color resolution                  */


// Printing related DeviceCaps. These replace the appropriate Escapes

#define PHYSICALWIDTH   110 /* Physical Width in device units           */
#define PHYSICALHEIGHT  111 /* Physical Height in device units          */
#define PHYSICALOFFSETX 112 /* Physical Printable Area x margin         */
#define PHYSICALOFFSETY 113 /* Physical Printable Area y margin         */
#define SCALINGFACTORX  114 /* Scaling factor x                         */
#define SCALINGFACTORY  115 /* Scaling factor y                         */

// Display driver specific

#define VREFRESH        116  /* Current vertical refresh rate of the    */
                             /* display device (for displays only) in Hz*/
#define DESKTOPVERTRES  117  /* Horizontal width of entire desktop in   */
                             /* pixels                                  */
#define DESKTOPHORZRES  118  /* Vertical height of entire desktop in    */
                             /* pixels                                  */
#define BLTALIGNMENT    119  /* Preferred blt alignment                 */

#ifndef NOGDICAPMASKS

/* Device Capability Masks: */

/* Device Technologies */
#define DT_PLOTTER          0   /* Vector plotter                   */
#define DT_RASDISPLAY       1   /* Raster display                   */
#define DT_RASPRINTER       2   /* Raster printer                   */
#define DT_RASCAMERA        3   /* Raster camera                    */
#define DT_CHARSTREAM       4   /* Character-stream, PLP            */
#define DT_METAFILE         5   /* Metafile, VDM                    */
#define DT_DISPFILE         6   /* Display-file                     */

/* Curve Capabilities */
#define CC_NONE             0   /* Curves not supported             */
#define CC_CIRCLES          1   /* Can do circles                   */
#define CC_PIE              2   /* Can do pie wedges                */
#define CC_CHORD            4   /* Can do chord arcs                */
#define CC_ELLIPSES         8   /* Can do ellipese                  */
#define CC_WIDE             16  /* Can do wide lines                */
#define CC_STYLED           32  /* Can do styled lines              */
#define CC_WIDESTYLED       64  /* Can do wide styled lines         */
#define CC_INTERIORS        128 /* Can do interiors                 */
#define CC_ROUNDRECT        256 /*                                  */

/* Line Capabilities */
#define LC_NONE             0   /* Lines not supported              */
#define LC_POLYLINE         2   /* Can do polylines                 */
#define LC_MARKER           4   /* Can do markers                   */
#define LC_POLYMARKER       8   /* Can do polymarkers               */
#define LC_WIDE             16  /* Can do wide lines                */
#define LC_STYLED           32  /* Can do styled lines              */
#define LC_WIDESTYLED       64  /* Can do wide styled lines         */
#define LC_INTERIORS        128 /* Can do interiors                 */

/* Polygonal Capabilities */
#define PC_NONE             0   /* Polygonals not supported         */
#define PC_POLYGON          1   /* Can do polygons                  */
#define PC_RECTANGLE        2   /* Can do rectangles                */
#define PC_WINDPOLYGON      4   /* Can do winding polygons          */
#define PC_TRAPEZOID        4   /* Can do trapezoids                */
#define PC_SCANLINE         8   /* Can do scanlines                 */
#define PC_WIDE             16  /* Can do wide borders              */
#define PC_STYLED           32  /* Can do styled borders            */
#define PC_WIDESTYLED       64  /* Can do wide styled borders       */
#define PC_INTERIORS        128 /* Can do interiors                 */
#define PC_POLYPOLYGON      256 /* Can do polypolygons              */
#define PC_PATHS            512 /* Can do paths                     */

/* Clipping Capabilities */
#define CP_NONE             0   /* No clipping of output            */
#define CP_RECTANGLE        1   /* Output clipped to rects          */
#define CP_REGION           2   /* obsolete                         */

/* Text Capabilities */
#define TC_OP_CHARACTER     0x00000001  /* Can do OutputPrecision   CHARACTER      */
#define TC_OP_STROKE        0x00000002  /* Can do OutputPrecision   STROKE         */
#define TC_CP_STROKE        0x00000004  /* Can do ClipPrecision     STROKE         */
#define TC_CR_90            0x00000008  /* Can do CharRotAbility    90             */
#define TC_CR_ANY           0x00000010  /* Can do CharRotAbility    ANY            */
#define TC_SF_X_YINDEP      0x00000020  /* Can do ScaleFreedom      X_YINDEPENDENT */
#define TC_SA_DOUBLE        0x00000040  /* Can do ScaleAbility      DOUBLE         */
#define TC_SA_INTEGER       0x00000080  /* Can do ScaleAbility      INTEGER        */
#define TC_SA_CONTIN        0x00000100  /* Can do ScaleAbility      CONTINUOUS     */
#define TC_EA_DOUBLE        0x00000200  /* Can do EmboldenAbility   DOUBLE         */
#define TC_IA_ABLE          0x00000400  /* Can do ItalisizeAbility  ABLE           */
#define TC_UA_ABLE          0x00000800  /* Can do UnderlineAbility  ABLE           */
#define TC_SO_ABLE          0x00001000  /* Can do StrikeOutAbility  ABLE           */
#define TC_RA_ABLE          0x00002000  /* Can do RasterFontAble    ABLE           */
#define TC_VA_ABLE          0x00004000  /* Can do VectorFontAble    ABLE           */
#define TC_RESERVED         0x00008000
#define TC_SCROLLBLT        0x00010000  /* Don't do text scroll with blt           */

#endif /* NOGDICAPMASKS */

/* Raster Capabilities */
#define RC_NONE
#define RC_BITBLT           1       /* Can do standard BLT.             */
#define RC_BANDING          2       /* Device requires banding support  */
#define RC_SCALING          4       /* Device requires scaling support  */
#define RC_BITMAP64         8       /* Device can support >64K bitmap   */
#define RC_GDI20_OUTPUT     0x0010      /* has 2.0 output calls         */
#define RC_GDI20_STATE      0x0020
#define RC_SAVEBITMAP       0x0040
#define RC_DI_BITMAP        0x0080      /* supports DIB to memory       */
#define RC_PALETTE          0x0100      /* supports a palette           */
#define RC_DIBTODEV         0x0200      /* supports DIBitsToDevice      */
#define RC_BIGFONT          0x0400      /* supports >64K fonts          */
#define RC_STRETCHBLT       0x0800      /* supports StretchBlt          */
#define RC_FLOODFILL        0x1000      /* supports FloodFill           */
#define RC_STRETCHDIB       0x2000      /* supports StretchDIBits       */
#define RC_OP_DX_OUTPUT     0x4000
#define RC_DEVBITS          0x8000


/* DIB color table identifiers */

#define DIB_RGB_COLORS      0 /* color table in RGBs */
#define DIB_PAL_COLORS      1 /* color table in palette indices */

/* constants for Get/SetSystemPaletteUse() */

#define SYSPAL_ERROR    0
#define SYSPAL_STATIC   1
#define SYSPAL_NOSTATIC 2

/* constants for CreateDIBitmap */
#define CBM_INIT        0x04L   /* initialize bitmap */

/* ExtFloodFill style flags */
#define  FLOODFILLBORDER   0
#define  FLOODFILLSURFACE  1

/* size of a device name string */
#define CCHDEVICENAME 32

/* size of a form name string */
#define CCHFORMNAME 32

typedef struct _devicemodeA {
    BYTE   dmDeviceName[CCHDEVICENAME];
    WORD dmSpecVersion;
    WORD dmDriverVersion;
    WORD dmSize;
    WORD dmDriverExtra;
    unsigned long dmFields;
    short dmOrientation;
    short dmPaperSize;
    short dmPaperLength;
    short dmPaperWidth;
    short dmScale;
    short dmCopies;
    short dmDefaultSource;
    short dmPrintQuality;
    short dmColor;
    short dmDuplex;
    short dmYResolution;
    short dmTTOption;
    short dmCollate;
    BYTE   dmFormName[CCHFORMNAME];
    WORD   dmLogPixels;
    unsigned long  dmBitsPerPel;
    unsigned long  dmPelsWidth;
    unsigned long  dmPelsHeight;
    unsigned long  dmDisplayFlags;
    unsigned long  dmDisplayFrequency;
    unsigned long  dmICMMethod;
    unsigned long  dmICMIntent;
    unsigned long  dmMediaType;
    unsigned long  dmDitherType;
    unsigned long  dmICCManufacturer;
    unsigned long  dmICCModel;
    unsigned long  dmPanningWidth;
    unsigned long  dmPanningHeight;
} DEVMODEA, *PDEVMODEA, *NPDEVMODEA, *LPDEVMODEA;
typedef struct _devicemodeW {
    WCHAR  dmDeviceName[CCHDEVICENAME];
    WORD dmSpecVersion;
    WORD dmDriverVersion;
    WORD dmSize;
    WORD dmDriverExtra;
    unsigned long dmFields;
    short dmOrientation;
    short dmPaperSize;
    short dmPaperLength;
    short dmPaperWidth;
    short dmScale;
    short dmCopies;
    short dmDefaultSource;
    short dmPrintQuality;
    short dmColor;
    short dmDuplex;
    short dmYResolution;
    short dmTTOption;
    short dmCollate;
    WCHAR  dmFormName[CCHFORMNAME];
    WORD   dmLogPixels;
    unsigned long  dmBitsPerPel;
    unsigned long  dmPelsWidth;
    unsigned long  dmPelsHeight;
    unsigned long  dmDisplayFlags;
    unsigned long  dmDisplayFrequency;
    unsigned long  dmICMMethod;
    unsigned long  dmICMIntent;
    unsigned long  dmMediaType;
    unsigned long  dmDitherType;
    unsigned long  dmICCManufacturer;
    unsigned long  dmICCModel;
    unsigned long  dmPanningWidth;
    unsigned long  dmPanningHeight;
} DEVMODEW, *PDEVMODEW, *NPDEVMODEW, *LPDEVMODEW;
#ifdef UNICODE
typedef DEVMODEW DEVMODE;
typedef PDEVMODEW PDEVMODE;
typedef NPDEVMODEW NPDEVMODE;
typedef LPDEVMODEW LPDEVMODE;
#else
typedef DEVMODEA DEVMODE;
typedef PDEVMODEA PDEVMODE;
typedef NPDEVMODEA NPDEVMODE;
typedef LPDEVMODEA LPDEVMODE;
#endif // UNICODE

#define DM_SPECVERSION 0x0401

/* field selection bits */
#define DM_ORIENTATION      0x00000001L
#define DM_PAPERSIZE        0x00000002L
#define DM_PAPERLENGTH      0x00000004L
#define DM_PAPERWIDTH       0x00000008L
#define DM_SCALE            0x00000010L
#define DM_COPIES           0x00000100L
#define DM_DEFAULTSOURCE    0x00000200L
#define DM_PRINTQUALITY     0x00000400L
#define DM_COLOR            0x00000800L
#define DM_DUPLEX           0x00001000L
#define DM_YRESOLUTION      0x00002000L
#define DM_TTOPTION         0x00004000L
#define DM_COLLATE          0x00008000L
#define DM_FORMNAME         0x00010000L
#define DM_LOGPIXELS        0x00020000L
#define DM_BITSPERPEL       0x00040000L
#define DM_PELSWIDTH        0x00080000L
#define DM_PELSHEIGHT       0x00100000L
#define DM_DISPLAYFLAGS     0x00200000L
#define DM_DISPLAYFREQUENCY 0x00400000L
#define DM_PANNINGWIDTH     0x00800000L
#define DM_PANNINGHEIGHT    0x01000000L
#define DM_ICMMETHOD        0x02000000L
#define DM_ICMINTENT        0x04000000L
#define DM_MEDIATYPE        0x08000000L
#define DM_DITHERTYPE       0x10000000L
#define DM_ICCMANUFACTURER  0x20000000L
#define DM_ICCMODEL         0x40000000L

/* orientation selections */
#define DMORIENT_PORTRAIT   1
#define DMORIENT_LANDSCAPE  2

/* paper selections */
#define DMPAPER_FIRST                DMPAPER_LETTER
#define DMPAPER_LETTER               1  /* Letter 8 1/2 x 11 in               */
#define DMPAPER_LETTERSMALL          2  /* Letter Small 8 1/2 x 11 in         */
#define DMPAPER_TABLOID              3  /* Tabloid 11 x 17 in                 */
#define DMPAPER_LEDGER               4  /* Ledger 17 x 11 in                  */
#define DMPAPER_LEGAL                5  /* Legal 8 1/2 x 14 in                */
#define DMPAPER_STATEMENT            6  /* Statement 5 1/2 x 8 1/2 in         */
#define DMPAPER_EXECUTIVE            7  /* Executive 7 1/4 x 10 1/2 in        */
#define DMPAPER_A3                   8  /* A3 297 x 420 mm                    */
#define DMPAPER_A4                   9  /* A4 210 x 297 mm                    */
#define DMPAPER_A4SMALL             10  /* A4 Small 210 x 297 mm              */
#define DMPAPER_A5                  11  /* A5 148 x 210 mm                    */
#define DMPAPER_B4                  12  /* B4 (JIS) 250 x 354                 */
#define DMPAPER_B5                  13  /* B5 (JIS) 182 x 257 mm              */
#define DMPAPER_FOLIO               14  /* Folio 8 1/2 x 13 in                */
#define DMPAPER_QUARTO              15  /* Quarto 215 x 275 mm                */
#define DMPAPER_10X14               16  /* 10x14 in                           */
#define DMPAPER_11X17               17  /* 11x17 in                           */
#define DMPAPER_NOTE                18  /* Note 8 1/2 x 11 in                 */
#define DMPAPER_ENV_9               19  /* Envelope #9 3 7/8 x 8 7/8          */
#define DMPAPER_ENV_10              20  /* Envelope #10 4 1/8 x 9 1/2         */
#define DMPAPER_ENV_11              21  /* Envelope #11 4 1/2 x 10 3/8        */
#define DMPAPER_ENV_12              22  /* Envelope #12 4 \276 x 11           */
#define DMPAPER_ENV_14              23  /* Envelope #14 5 x 11 1/2            */
#define DMPAPER_CSHEET              24  /* C size sheet                       */
#define DMPAPER_DSHEET              25  /* D size sheet                       */
#define DMPAPER_ESHEET              26  /* E size sheet                       */
#define DMPAPER_ENV_DL              27  /* Envelope DL 110 x 220mm            */
#define DMPAPER_ENV_C5              28  /* Envelope C5 162 x 229 mm           */
#define DMPAPER_ENV_C3              29  /* Envelope C3  324 x 458 mm          */
#define DMPAPER_ENV_C4              30  /* Envelope C4  229 x 324 mm          */
#define DMPAPER_ENV_C6              31  /* Envelope C6  114 x 162 mm          */
#define DMPAPER_ENV_C65             32  /* Envelope C65 114 x 229 mm          */
#define DMPAPER_ENV_B4              33  /* Envelope B4  250 x 353 mm          */
#define DMPAPER_ENV_B5              34  /* Envelope B5  176 x 250 mm          */
#define DMPAPER_ENV_B6              35  /* Envelope B6  176 x 125 mm          */
#define DMPAPER_ENV_ITALY           36  /* Envelope 110 x 230 mm              */
#define DMPAPER_ENV_MONARCH         37  /* Envelope Monarch 3.875 x 7.5 in    */
#define DMPAPER_ENV_PERSONAL        38  /* 6 3/4 Envelope 3 5/8 x 6 1/2 in    */
#define DMPAPER_FANFOLD_US          39  /* US Std Fanfold 14 7/8 x 11 in      */
#define DMPAPER_FANFOLD_STD_GERMAN  40  /* German Std Fanfold 8 1/2 x 12 in   */
#define DMPAPER_FANFOLD_LGL_GERMAN  41  /* German Legal Fanfold 8 1/2 x 13 in */
#if(WINVER >= 0x0400)
#define DMPAPER_ISO_B4              42  /* B4 (ISO) 250 x 353 mm              */
#define DMPAPER_JAPANESE_POSTCARD   43  /* Japanese Postcard 100 x 148 mm     */
#define DMPAPER_9X11                44  /* 9 x 11 in                          */
#define DMPAPER_10X11               45  /* 10 x 11 in                         */
#define DMPAPER_15X11               46  /* 15 x 11 in                         */
#define DMPAPER_ENV_INVITE          47  /* Envelope Invite 220 x 220 mm       */
#define DMPAPER_RESERVED_48         48  /* RESERVED--DO NOT USE               */
#define DMPAPER_RESERVED_49         49  /* RESERVED--DO NOT USE               */
#define DMPAPER_LETTER_EXTRA        50  /* Letter Extra 9 \275 x 12 in        */
#define DMPAPER_LEGAL_EXTRA         51  /* Legal Extra 9 \275 x 15 in         */
#define DMPAPER_TABLOID_EXTRA       52  /* Tabloid Extra 11.69 x 18 in        */
#define DMPAPER_A4_EXTRA            53  /* A4 Extra 9.27 x 12.69 in           */
#define DMPAPER_LETTER_TRANSVERSE   54  /* Letter Transverse 8 \275 x 11 in   */
#define DMPAPER_A4_TRANSVERSE       55  /* A4 Transverse 210 x 297 mm         */
#define DMPAPER_LETTER_EXTRA_TRANSVERSE 56 /* Letter Extra Transverse 9\275 x 12 in */
#define DMPAPER_A_PLUS              57  /* SuperA/SuperA/A4 227 x 356 mm      */
#define DMPAPER_B_PLUS              58  /* SuperB/SuperB/A3 305 x 487 mm      */
#define DMPAPER_LETTER_PLUS         59  /* Letter Plus 8.5 x 12.69 in         */
#define DMPAPER_A4_PLUS             60  /* A4 Plus 210 x 330 mm               */
#define DMPAPER_A5_TRANSVERSE       61  /* A5 Transverse 148 x 210 mm         */
#define DMPAPER_B5_TRANSVERSE       62  /* B5 (JIS) Transverse 182 x 257 mm   */
#define DMPAPER_A3_EXTRA            63  /* A3 Extra 322 x 445 mm              */
#define DMPAPER_A5_EXTRA            64  /* A5 Extra 174 x 235 mm              */
#define DMPAPER_B5_EXTRA            65  /* B5 (ISO) Extra 201 x 276 mm        */
#define DMPAPER_A2                  66  /* A2 420 x 594 mm                    */
#define DMPAPER_A3_TRANSVERSE       67  /* A3 Transverse 297 x 420 mm         */
#define DMPAPER_A3_EXTRA_TRANSVERSE 68  /* A3 Extra Transverse 322 x 445 mm   */
#endif /* WINVER >= 0x0400 */

#if (WINVER >= 0x0400)
#define DMPAPER_LAST                DMPAPER_A3_EXTRA_TRANSVERSE
#else
#define DMPAPER_LAST                DMPAPER_FANFOLD_LGL_GERMAN
#endif

#define DMPAPER_USER                256

/* bin selections */
#define DMBIN_FIRST         DMBIN_UPPER
#define DMBIN_UPPER         1
#define DMBIN_ONLYONE       1
#define DMBIN_LOWER         2
#define DMBIN_MIDDLE        3
#define DMBIN_MANUAL        4
#define DMBIN_ENVELOPE      5
#define DMBIN_ENVMANUAL     6
#define DMBIN_AUTO          7
#define DMBIN_TRACTOR       8
#define DMBIN_SMALLFMT      9
#define DMBIN_LARGEFMT      10
#define DMBIN_LARGECAPACITY 11
#define DMBIN_CASSETTE      14
#define DMBIN_FORMSOURCE    15
#define DMBIN_LAST          DMBIN_FORMSOURCE

#define DMBIN_USER          256     /* device specific bins start here */

/* print qualities */
#define DMRES_DRAFT         (-1)
#define DMRES_LOW           (-2)
#define DMRES_MEDIUM        (-3)
#define DMRES_HIGH          (-4)

/* color enable/disable for color printers */
#define DMCOLOR_MONOCHROME  1
#define DMCOLOR_COLOR       2

/* duplex enable */
#define DMDUP_SIMPLEX    1
#define DMDUP_VERTICAL   2
#define DMDUP_HORIZONTAL 3

/* TrueType options */
#define DMTT_BITMAP     1       /* print TT fonts as graphics */
#define DMTT_DOWNLOAD   2       /* download TT fonts as soft fonts */
#define DMTT_SUBDEV     3       /* substitute device fonts for TT fonts */
#if(WINVER >= 0x0400)
#define DMTT_DOWNLOAD_OUTLINE 4 /* download TT fonts as outline soft fonts */
#endif /* WINVER >= 0x0400 */

/* Collation selections */
#define DMCOLLATE_FALSE  0
#define DMCOLLATE_TRUE   1

/* DEVMODE dmDisplayFlags flags */

//#define DM_GRAYSCALE    0x00000001 /* This flag is no longer valid */
//#define DM_INTERLACED   0x00000002 /* This flag is no longer valid */
#define DMDISPLAYFLAGS_TEXTMODE 0x00000004

#if(WINVER >= 0x0400)
/* ICM methods */
#define DMICMMETHOD_NONE    1   /* ICM disabled */
#define DMICMMETHOD_SYSTEM  2   /* ICM handled by system */
#define DMICMMETHOD_DRIVER  3   /* ICM handled by driver */
#define DMICMMETHOD_DEVICE  4   /* ICM handled by device */

#define DMICMMETHOD_USER  256   /* Device-specific methods start here */

/* ICM Intents */
#define DMICM_SATURATE      1   /* Maximize color saturation */
#define DMICM_CONTRAST      2   /* Maximize color contrast */
#define DMICM_COLORMETRIC   3   /* Use specific color metric */

#define DMICM_USER        256   /* Device-specific intents start here */

/* Media types */

#define DMMEDIA_STANDARD      1   /* Standard paper */
#define DMMEDIA_TRANSPARENCY  2   /* Transparency */
#define DMMEDIA_GLOSSY        3   /* Glossy paper */

#define DMMEDIA_USER        256   /* Device-specific media start here */

/* Dither types */
#define DMDITHER_NONE       1   /* No dithering */
#define DMDITHER_COARSE     2   /* Dither with a coarse brush */
#define DMDITHER_FINE       3   /* Dither with a fine brush */
#define DMDITHER_LINEART    4   /* LineArt dithering */
#define DMDITHER_GRAYSCALE  5   /* Device does grayscaling */

#define DMDITHER_USER     256   /* Device-specific dithers start here */
#endif /* WINVER >= 0x0400 */

/* GetRegionData/ExtCreateRegion */

#define RDH_RECTANGLES  1

typedef struct _RGNDATAHEADER {
    unsigned long   dwSize;
    unsigned long   iType;
    unsigned long   nCount;
    unsigned long   nRgnSize;
    RECT    rcBound;
} RGNDATAHEADER, *PRGNDATAHEADER;

typedef struct _RGNDATA {
    RGNDATAHEADER   rdh;
    char            Buffer[1];
} RGNDATA, *PRGNDATA,  *NPRGNDATA,  *LPRGNDATA;


typedef struct _ABC {
    int     abcA;
    unsigned    abcB;
    int     abcC;
} ABC, *PABC,  *NPABC,  *LPABC;

typedef struct _ABCFLOAT {
    float   abcfA;
    float   abcfB;
    float   abcfC;
} ABCFLOAT, *PABCFLOAT,  *NPABCFLOAT,  *LPABCFLOAT;

#ifndef NOTEXTMETRIC

typedef struct _OUTLINETEXTMETRICA {
    unsigned    otmSize;
    TEXTMETRICA otmTextMetrics;
    BYTE    otmFiller;
    PANOSE  otmPanoseNumber;
    unsigned    otmfsSelection;
    unsigned    otmfsType;
     int    otmsCharSlopeRise;
     int    otmsCharSlopeRun;
     int    otmItalicAngle;
    unsigned    otmEMSquare;
     int    otmAscent;
     int    otmDescent;
    unsigned    otmLineGap;
    unsigned    otmsCapEmHeight;
    unsigned    otmsXHeight;
    RECT    otmrcFontBox;
     int    otmMacAscent;
     int    otmMacDescent;
    unsigned    otmMacLineGap;
    unsigned    otmusMinimumPPEM;
    POINT   otmptSubscriptSize;
    POINT   otmptSubscriptOffset;
    POINT   otmptSuperscriptSize;
    POINT   otmptSuperscriptOffset;
    unsigned    otmsStrikeoutSize;
     int    otmsStrikeoutPosition;
     int    otmsUnderscoreSize;
     int    otmsUnderscorePosition;
    char*    otmpFamilyName;
    char*    otmpFaceName;
    char*    otmpStyleName;
    char*    otmpFullName;
} OUTLINETEXTMETRICA, *POUTLINETEXTMETRICA,  *NPOUTLINETEXTMETRICA,  *LPOUTLINETEXTMETRICA;
typedef struct _OUTLINETEXTMETRICW {
    unsigned    otmSize;
    TEXTMETRICW otmTextMetrics;
    BYTE    otmFiller;
    PANOSE  otmPanoseNumber;
    unsigned    otmfsSelection;
    unsigned    otmfsType;
     int    otmsCharSlopeRise;
     int    otmsCharSlopeRun;
     int    otmItalicAngle;
    unsigned    otmEMSquare;
     int    otmAscent;
     int    otmDescent;
    unsigned    otmLineGap;
    unsigned    otmsCapEmHeight;
    unsigned    otmsXHeight;
    RECT    otmrcFontBox;
     int    otmMacAscent;
     int    otmMacDescent;
    unsigned    otmMacLineGap;
    unsigned    otmusMinimumPPEM;
    POINT   otmptSubscriptSize;
    POINT   otmptSubscriptOffset;
    POINT   otmptSuperscriptSize;
    POINT   otmptSuperscriptOffset;
    unsigned    otmsStrikeoutSize;
     int    otmsStrikeoutPosition;
     int    otmsUnderscoreSize;
     int    otmsUnderscorePosition;
    char*    otmpFamilyName;
    char*    otmpFaceName;
    char*    otmpStyleName;
    char*    otmpFullName;
} OUTLINETEXTMETRICW, *POUTLINETEXTMETRICW,  *NPOUTLINETEXTMETRICW,  *LPOUTLINETEXTMETRICW;
#ifdef UNICODE
typedef OUTLINETEXTMETRICW OUTLINETEXTMETRIC;
typedef POUTLINETEXTMETRICW POUTLINETEXTMETRIC;
typedef NPOUTLINETEXTMETRICW NPOUTLINETEXTMETRIC;
typedef LPOUTLINETEXTMETRICW LPOUTLINETEXTMETRIC;
#else
typedef OUTLINETEXTMETRICA OUTLINETEXTMETRIC;
typedef POUTLINETEXTMETRICA POUTLINETEXTMETRIC;
typedef NPOUTLINETEXTMETRICA NPOUTLINETEXTMETRIC;
typedef LPOUTLINETEXTMETRICA LPOUTLINETEXTMETRIC;
#endif // UNICODE

#endif /* NOTEXTMETRIC */


typedef struct tagPOLYTEXTA
{
    int       x;
    int       y;
    unsigned      n;
    const char*    lpstr;
    unsigned      uiFlags;
    RECT      rcl;
    int      *pdx;
} POLYTEXTA, *PPOLYTEXTA,  *NPPOLYTEXTA,  *LPPOLYTEXTA;
typedef struct tagPOLYTEXTW
{
    int       x;
    int       y;
    unsigned      n;
    const wchar_t*   lpstr;
    unsigned      uiFlags;
    RECT      rcl;
    int      *pdx;
} POLYTEXTW, *PPOLYTEXTW,  *NPPOLYTEXTW,  *LPPOLYTEXTW;
#ifdef UNICODE
typedef POLYTEXTW POLYTEXT;
typedef PPOLYTEXTW PPOLYTEXT;
typedef NPPOLYTEXTW NPPOLYTEXT;
typedef LPPOLYTEXTW LPPOLYTEXT;
#else
typedef POLYTEXTA POLYTEXT;
typedef PPOLYTEXTA PPOLYTEXT;
typedef NPPOLYTEXTA NPPOLYTEXT;
typedef LPPOLYTEXTA LPPOLYTEXT;
#endif // UNICODE

typedef struct _FIXED {
    WORD    fract;
    short   value;
} FIXED;


typedef struct _MAT2 {
     FIXED  eM11;
     FIXED  eM12;
     FIXED  eM21;
     FIXED  eM22;
} MAT2,  *LPMAT2;



typedef struct _GLYPHMETRICS {
    unsigned    gmBlackBoxX;
    unsigned    gmBlackBoxY;
    POINT   gmptGlyphOrigin;
    short   gmCellIncX;
    short   gmCellIncY;
} GLYPHMETRICS,  *LPGLYPHMETRICS;

//  GetGlyphOutline constants

#define GGO_METRICS        0
#define GGO_BITMAP         1
#define GGO_NATIVE         2

#if(WINVER >= 0x0400)
#define  GGO_GRAY2_BITMAP   4
#define  GGO_GRAY4_BITMAP   5
#define  GGO_GRAY8_BITMAP   6
#define  GGO_GLYPH_INDEX    0x0080
#endif /* WINVER >= 0x0400 */

#define TT_POLYGON_TYPE   24

#define TT_PRIM_LINE       1
#define TT_PRIM_QSPLINE    2

typedef struct tagPOINTFX
{
    FIXED x;
    FIXED y;
} POINTFX, * LPPOINTFX;

typedef struct tagTTPOLYCURVE
{
    WORD    wType;
    WORD    cpfx;
    POINTFX apfx[1];
} TTPOLYCURVE, * LPTTPOLYCURVE;

typedef struct tagTTPOLYGONHEADER
{
    unsigned long   cb;
    unsigned long   dwType;
    POINTFX pfxStart;
} TTPOLYGONHEADER, * LPTTPOLYGONHEADER;


#if(WINVER >= 0x0400)
#define GCP_DBCS           0x0001
#define GCP_REORDER        0x0002
#define GCP_USEKERNING     0x0008
#define GCP_GLYPHSHAPE     0x0010
#define GCP_LIGATE         0x0020
////#define GCP_GLYPHINDEXING  0x0080
#define GCP_DIACRITIC      0x0100
#define GCP_KASHIDA        0x0400
#define GCP_ERROR          0x8000
#define FLI_MASK           0x103B

#define GCP_JUSTIFY        0x00010000L
////#define GCP_NODIACRITICS   0x00020000L
#define FLI_GLYPHS         0x00040000L
#define GCP_CLASSIN        0x00080000L
#define GCP_MAXEXTENT      0x00100000L
#define GCP_JUSTIFYIN      0x00200000L
#define GCP_DISPLAYZWG      0x00400000L
#define GCP_SYMSWAPOFF      0x00800000L
#define GCP_NUMERICOVERRIDE 0x01000000L
#define GCP_NEUTRALOVERRIDE 0x02000000L
#define GCP_NUMERICSLATIN   0x04000000L
#define GCP_NUMERICSLOCAL   0x08000000L

#define GCPCLASS_LATIN                  1
#define GCPCLASS_HEBREW                 2
#define GCPCLASS_ARABIC                 2
#define GCPCLASS_NEUTRAL                3
#define GCPCLASS_LOCALNUMBER            4
#define GCPCLASS_LATINNUMBER            5
#define GCPCLASS_LATINNUMERICTERMINATOR 6
#define GCPCLASS_LATINNUMERICSEPARATOR  7
#define GCPCLASS_NUMERICSEPARATOR       8
#define GCPCLASS_PREBOUNDLTR         0x80
#define GCPCLASS_PREBOUNDRTL         0x40
#define GCPCLASS_POSTBOUNDLTR        0x20
#define GCPCLASS_POSTBOUNDRTL        0x10

#define GCPGLYPH_LINKBEFORE          0x8000
#define GCPGLYPH_LINKAFTER           0x4000


typedef struct tagGCP_RESULTSA
    {
    unsigned long   lStructSize;
    char*     lpOutString;
    unsigned  *lpOrder;
    int   *lpDx;
    int   *lpCaretPos;
    char*   lpClass;
    wchar_t*  lpGlyphs;
    unsigned    nGlyphs;
    int     nMaxFit;
    } GCP_RESULTSA, * LPGCP_RESULTSA;
typedef struct tagGCP_RESULTSW
    {
    unsigned long   lStructSize;
    wchar_t*    lpOutString;
    unsigned  *lpOrder;
    int   *lpDx;
    int   *lpCaretPos;
    char*   lpClass;
    wchar_t*  lpGlyphs;
    unsigned    nGlyphs;
    int     nMaxFit;
    } GCP_RESULTSW, * LPGCP_RESULTSW;
#ifdef UNICODE
typedef GCP_RESULTSW GCP_RESULTS;
typedef LPGCP_RESULTSW LPGCP_RESULTS;
#else
typedef GCP_RESULTSA GCP_RESULTS;
typedef LPGCP_RESULTSA LPGCP_RESULTS;
#endif // UNICODE
#endif /* WINVER >= 0x0400 */

typedef struct _RASTERIZER_STATUS {
    short   nSize;
    short   wFlags;
    short   nLanguageID;
} RASTERIZER_STATUS,  *LPRASTERIZER_STATUS;

/* bits defined in wFlags of RASTERIZER_STATUS */
#define TT_AVAILABLE    0x0001
#define TT_ENABLED      0x0002

/* Pixel format descriptor */
typedef struct tagPIXELFORMATDESCRIPTOR
{
    WORD  nSize;
    WORD  nVersion;
    unsigned long dwFlags;
    BYTE  iPixelType;
    BYTE  cColorBits;
    BYTE  cRedBits;
    BYTE  cRedShift;
    BYTE  cGreenBits;
    BYTE  cGreenShift;
    BYTE  cBlueBits;
    BYTE  cBlueShift;
    BYTE  cAlphaBits;
    BYTE  cAlphaShift;
    BYTE  cAccumBits;
    BYTE  cAccumRedBits;
    BYTE  cAccumGreenBits;
    BYTE  cAccumBlueBits;
    BYTE  cAccumAlphaBits;
    BYTE  cDepthBits;
    BYTE  cStencilBits;
    BYTE  cAuxBuffers;
    BYTE  iLayerType;
    BYTE  bReserved;
    unsigned long dwLayerMask;
    unsigned long dwVisibleMask;
    unsigned long dwDamageMask;
} PIXELFORMATDESCRIPTOR, *PPIXELFORMATDESCRIPTOR,  *LPPIXELFORMATDESCRIPTOR;

/* pixel types */
#define PFD_TYPE_RGBA        0
#define PFD_TYPE_COLORINDEX  1

/* layer types */
#define PFD_MAIN_PLANE       0
#define PFD_OVERLAY_PLANE    1
#define PFD_UNDERLAY_PLANE   (-1)

/* PIXELFORMATDESCRIPTOR flags */
#define PFD_DOUBLEBUFFER            0x00000001
#define PFD_STEREO                  0x00000002
#define PFD_DRAW_TO_WINDOW          0x00000004
#define PFD_DRAW_TO_BITMAP          0x00000008
#define PFD_SUPPORT_GDI             0x00000010
#define PFD_SUPPORT_OPENGL          0x00000020
#define PFD_GENERIC_FORMAT          0x00000040
#define PFD_NEED_PALETTE            0x00000080
#define PFD_NEED_SYSTEM_PALETTE     0x00000100
#define PFD_SWAP_EXCHANGE           0x00000200
#define PFD_SWAP_COPY               0x00000400
#define PFD_SWAP_LAYER_BUFFERS      0x00000800
#define PFD_GENERIC_ACCELERATED     0x00001000

/* PIXELFORMATDESCRIPTOR flags for use in ChoosePixelFormat only */
#define PFD_DEPTH_DONTCARE          0x20000000
#define PFD_DOUBLEBUFFER_DONTCARE   0x40000000
#define PFD_STEREO_DONTCARE         0x80000000

#ifdef STRICT
#if !defined(NOTEXTMETRIC)
typedef int (__stdcall* OLDFONTENUMPROCA)(const LOGFONTA *, const TEXTMETRICA *, unsigned long, LPARAM);
typedef int (__stdcall* OLDFONTENUMPROCW)(const LOGFONTW *, const TEXTMETRICW *, unsigned long, LPARAM);
#ifdef UNICODE
#define OLDFONTENUMPROC  OLDFONTENUMPROCW
#else
#define OLDFONTENUMPROC  OLDFONTENUMPROCA
#endif // !UNICODE
#else
typedef int (__stdcall* OLDFONTENUMPROCA)(const LOGFONTA * ,const void *, unsigned long, LPARAM);
typedef int (__stdcall* OLDFONTENUMPROCW)(const LOGFONTW * ,const void *, unsigned long, LPARAM);
#ifdef UNICODE
#define OLDFONTENUMPROC  OLDFONTENUMPROCW
#else
#define OLDFONTENUMPROC  OLDFONTENUMPROCA
#endif // !UNICODE
#endif

typedef OLDFONTENUMPROCA    FONTENUMPROCA;
typedef OLDFONTENUMPROCW    FONTENUMPROCW;
#ifdef UNICODE
typedef FONTENUMPROCW FONTENUMPROC;
#else
typedef FONTENUMPROCA FONTENUMPROC;
#endif // UNICODE

typedef int (__stdcall* GOBJENUMPROC)(void*, LPARAM);
typedef void (__stdcall* LINEDDAPROC)(int, int, LPARAM);
#else
typedef FARPROC OLDFONTENUMPROC;
typedef FARPROC FONTENUMPROCA;
typedef FARPROC FONTENUMPROCW;
#ifdef UNICODE
typedef FONTENUMPROCW FONTENUMPROC;
#else
typedef FONTENUMPROCA FONTENUMPROC;
#endif // UNICODE
typedef FARPROC GOBJENUMPROC;
typedef FARPROC LINEDDAPROC;
#endif

/*WINGDIAPI*/ int __stdcall AddFontResourceA(const char*);
/*WINGDIAPI*/ int __stdcall AddFontResourceW(const wchar_t*);
#ifdef UNICODE
#define AddFontResource  AddFontResourceW
#else
#define AddFontResource  AddFontResourceA
#endif // !UNICODE

/*WINGDIAPI*/ BOOL  __stdcall AnimatePalette(HPALETTE, unsigned, unsigned, const PALETTEENTRY *);
/*WINGDIAPI*/ BOOL  __stdcall Arc(HDC, int, int, int, int, int, int, int, int);
/*WINGDIAPI*/ BOOL  __stdcall BitBlt(HDC, int, int, int, int, HDC, int, int, unsigned long);
/*WINGDIAPI*/ BOOL  __stdcall CancelDC(HDC);
/*WINGDIAPI*/ BOOL  __stdcall Chord(HDC, int, int, int, int, int, int, int, int);
/*WINGDIAPI*/ int   __stdcall ChoosePixelFormat(HDC, const PIXELFORMATDESCRIPTOR *);
/*WINGDIAPI*/ HMETAFILE  __stdcall CloseMetaFile(HDC);
/*WINGDIAPI*/ int     __stdcall CombineRgn(HRGN, HRGN, HRGN, int);
/*WINGDIAPI*/ HMETAFILE __stdcall CopyMetaFileA(HMETAFILE, const char*);
/*WINGDIAPI*/ HMETAFILE __stdcall CopyMetaFileW(HMETAFILE, const wchar_t*);
#ifdef UNICODE
#define CopyMetaFile  CopyMetaFileW
#else
#define CopyMetaFile  CopyMetaFileA
#endif // !UNICODE
/*WINGDIAPI*/ HBITMAP __stdcall CreateBitmap(int, int, unsigned, unsigned, const void *);
/*WINGDIAPI*/ HBITMAP __stdcall CreateBitmapIndirect(const BITMAP *);
/*WINGDIAPI*/ HBRUSH  __stdcall CreateBrushIndirect(const LOGBRUSH *);
/*WINGDIAPI*/ HBITMAP __stdcall CreateCompatibleBitmap(HDC, int, int);
/*WINGDIAPI*/ HBITMAP __stdcall CreateDiscardableBitmap(HDC, int, int);
/*WINGDIAPI*/ HDC     __stdcall CreateCompatibleDC(HDC);
/*WINGDIAPI*/ HDC     __stdcall CreateDCA(const char*, const char* , const char* , const DEVMODEA *);
/*WINGDIAPI*/ HDC     __stdcall CreateDCW(const wchar_t*, const wchar_t* , const wchar_t* , const DEVMODEW *);
#ifdef UNICODE
#define CreateDC  CreateDCW
#else
#define CreateDC  CreateDCA
#endif // !UNICODE
/*WINGDIAPI*/ HBITMAP __stdcall CreateDIBitmap(HDC, const BITMAPINFOHEADER *, unsigned long, const void *, const BITMAPINFO *, unsigned);
/*WINGDIAPI*/ HBRUSH  __stdcall CreateDIBPatternBrush(HGLOBAL, unsigned);
/*WINGDIAPI*/ HBRUSH  __stdcall CreateDIBPatternBrushPt(const void *, unsigned);
/*WINGDIAPI*/ HRGN    __stdcall CreateEllipticRgn(int, int, int, int);
/*WINGDIAPI*/ HRGN    __stdcall CreateEllipticRgnIndirect(const RECT *);
/*WINGDIAPI*/ HFONT   __stdcall CreateFontIndirectA(const LOGFONTA *);
/*WINGDIAPI*/ HFONT   __stdcall CreateFontIndirectW(const LOGFONTW *);
#ifdef UNICODE
#define CreateFontIndirect  CreateFontIndirectW
#else
#define CreateFontIndirect  CreateFontIndirectA
#endif // !UNICODE
/*WINGDIAPI*/ HFONT   __stdcall CreateFontA(int, int, int, int, int, unsigned long,
                             unsigned long, unsigned long, unsigned long, unsigned long, unsigned long,
                             unsigned long, unsigned long, const char*);
/*WINGDIAPI*/ HFONT   __stdcall CreateFontW(int, int, int, int, int, unsigned long,
                             unsigned long, unsigned long, unsigned long, unsigned long, unsigned long,
                             unsigned long, unsigned long, const wchar_t*);
#ifdef UNICODE
#define CreateFont  CreateFontW
#else
#define CreateFont  CreateFontA
#endif // !UNICODE

/*WINGDIAPI*/ HBRUSH  __stdcall CreateHatchBrush(int, COLORREF);
/*WINGDIAPI*/ HDC     __stdcall CreateICA(const char*, const char* , const char* , const DEVMODEA *);
/*WINGDIAPI*/ HDC     __stdcall CreateICW(const wchar_t*, const wchar_t* , const wchar_t* , const DEVMODEW *);
#ifdef UNICODE
#define CreateIC  CreateICW
#else
#define CreateIC  CreateICA
#endif // !UNICODE
/*WINGDIAPI*/ HDC     __stdcall CreateMetaFileA(const char*);
/*WINGDIAPI*/ HDC     __stdcall CreateMetaFileW(const wchar_t*);
#ifdef UNICODE
#define CreateMetaFile  CreateMetaFileW
#else
#define CreateMetaFile  CreateMetaFileA
#endif // !UNICODE
/*WINGDIAPI*/ HPALETTE __stdcall CreatePalette(const LOGPALETTE *);
/*WINGDIAPI*/ HPEN    __stdcall CreatePen(int, int, COLORREF);
/*WINGDIAPI*/ HPEN    __stdcall CreatePenIndirect(const LOGPEN *);
/*WINGDIAPI*/ HRGN    __stdcall CreatePolyPolygonRgn(const POINT *, const INT *, int, int);
/*WINGDIAPI*/ HBRUSH  __stdcall CreatePatternBrush(HBITMAP);
/*WINGDIAPI*/ HRGN    __stdcall CreateRectRgn(int, int, int, int);
/*WINGDIAPI*/ HRGN    __stdcall CreateRectRgnIndirect(const RECT *);
/*WINGDIAPI*/ HRGN    __stdcall CreateRoundRectRgn(int, int, int, int, int, int);
/*WINGDIAPI*/ BOOL    __stdcall CreateScalableFontResourceA(unsigned long, const char*, const char*, const char*);
/*WINGDIAPI*/ BOOL    __stdcall CreateScalableFontResourceW(unsigned long, const wchar_t*, const wchar_t*, const wchar_t*);
#ifdef UNICODE
#define CreateScalableFontResource  CreateScalableFontResourceW
#else
#define CreateScalableFontResource  CreateScalableFontResourceA
#endif // !UNICODE
/*WINGDIAPI*/ HBRUSH  __stdcall CreateSolidBrush(COLORREF);

/*WINGDIAPI*/ BOOL __stdcall DeleteDC(HDC);
/*WINGDIAPI*/ BOOL __stdcall DeleteMetaFile(HMETAFILE);
/*WINGDIAPI*/ BOOL __stdcall DeleteObject(HGDIOBJ);
/*WINGDIAPI*/ int  __stdcall DescribePixelFormat(HDC, int, unsigned, LPPIXELFORMATDESCRIPTOR);

/* define types of pointers to ExtDeviceMode() and DeviceCapabilities()
 * functions for Win 3.1 compatibility
 */

typedef unsigned   (__stdcall* LPFNDEVMODE)(HWND, HMODULE, LPDEVMODE, char*, char*, LPDEVMODE, char*, unsigned);

typedef unsigned long  (__stdcall* LPFNDEVCAPS)(char*, char*, unsigned, char*, LPDEVMODE);

/* mode selections for the device mode function */
#define DM_UPDATE           1
#define DM_COPY             2
#define DM_PROMPT           4
#define DM_MODIFY           8

#define DM_IN_BUFFER        DM_MODIFY
#define DM_IN_PROMPT        DM_PROMPT
#define DM_OUT_BUFFER       DM_COPY
#define DM_OUT_DEFAULT      DM_UPDATE

/* device capabilities indices */
#define DC_FIELDS           1
#define DC_PAPERS           2
#define DC_PAPERSIZE        3
#define DC_MINEXTENT        4
#define DC_MAXEXTENT        5
#define DC_BINS             6
#define DC_DUPLEX           7
#define DC_SIZE             8
#define DC_EXTRA            9
#define DC_VERSION          10
#define DC_DRIVER           11
#define DC_BINNAMES         12
#define DC_ENUMRESOLUTIONS  13
#define DC_FILEDEPENDENCIES 14
#define DC_TRUETYPE         15
#define DC_PAPERNAMES       16
#define DC_ORIENTATION      17
#define DC_COPIES           18
#if(WINVER >= 0x0400)
#define DC_BINADJUST            19
#define DC_EMF_COMPLIANT        20
#define DC_DATATYPE_PRODUCED    21
#define DC_COLLATE              22
#endif /* WINVER >= 0x0400 */

/* bit fields of the return value (unsigned long) for DC_TRUETYPE */
#define DCTT_BITMAP             0x0000001L
#define DCTT_DOWNLOAD           0x0000002L
#define DCTT_SUBDEV             0x0000004L
#if(WINVER >= 0x0400)
#define DCTT_DOWNLOAD_OUTLINE   0x0000008L

/* return values for DC_BINADJUST */
#define DCBA_FACEUPNONE       0x0000
#define DCBA_FACEUPCENTER     0x0001
#define DCBA_FACEUPLEFT       0x0002
#define DCBA_FACEUPRIGHT      0x0003
#define DCBA_FACEDOWNNONE     0x0100
#define DCBA_FACEDOWNCENTER   0x0101
#define DCBA_FACEDOWNLEFT     0x0102
#define DCBA_FACEDOWNRIGHT    0x0103
#endif /* WINVER >= 0x0400 */

WINSPOOLAPI int  __stdcall DeviceCapabilitiesA(const char*, const char*, WORD,
                                char*, const DEVMODEA *);
WINSPOOLAPI int  __stdcall DeviceCapabilitiesW(const wchar_t*, const wchar_t*, WORD,
                                wchar_t*, const DEVMODEW *);
#ifdef UNICODE
#define DeviceCapabilities  DeviceCapabilitiesW
#else
#define DeviceCapabilities  DeviceCapabilitiesA
#endif // !UNICODE

/*WINGDIAPI*/ int  __stdcall DrawEscape(HDC, int, int, const char*);
/*WINGDIAPI*/ BOOL __stdcall Ellipse(HDC, int, int, int, int);

#if(WINVER >= 0x0400)
/*WINGDIAPI*/ int  __stdcall EnumFontFamiliesExA(HDC, LPLOGFONTA,FONTENUMPROCA, LPARAM,unsigned long);
/*WINGDIAPI*/ int  __stdcall EnumFontFamiliesExW(HDC, LPLOGFONTW,FONTENUMPROCW, LPARAM,unsigned long);
#ifdef UNICODE
#define EnumFontFamiliesEx  EnumFontFamiliesExW
#else
#define EnumFontFamiliesEx  EnumFontFamiliesExA
#endif // !UNICODE
#endif /* WINVER >= 0x0400 */

/*WINGDIAPI*/ int  __stdcall EnumFontFamiliesA(HDC, const char*, FONTENUMPROCA, LPARAM);
/*WINGDIAPI*/ int  __stdcall EnumFontFamiliesW(HDC, const wchar_t*, FONTENUMPROCW, LPARAM);
#ifdef UNICODE
#define EnumFontFamilies  EnumFontFamiliesW
#else
#define EnumFontFamilies  EnumFontFamiliesA
#endif // !UNICODE
/*WINGDIAPI*/ int  __stdcall EnumFontsA(HDC, const char*,  FONTENUMPROCA, LPARAM);
/*WINGDIAPI*/ int  __stdcall EnumFontsW(HDC, const wchar_t*,  FONTENUMPROCW, LPARAM);
#ifdef UNICODE
#define EnumFonts  EnumFontsW
#else
#define EnumFonts  EnumFontsA
#endif // !UNICODE

#ifdef STRICT
/*WINGDIAPI*/ int  __stdcall EnumObjects(HDC, int, GOBJENUMPROC, LPARAM);
#else
/*WINGDIAPI*/ int  __stdcall EnumObjects(HDC, int, GOBJENUMPROC, void*);
#endif


/*WINGDIAPI*/ BOOL __stdcall EqualRgn(HRGN, HRGN);
/*WINGDIAPI*/ int  __stdcall Escape(HDC, int, int, const char*, void*);
/*WINGDIAPI*/ int  __stdcall ExtEscape(HDC, int, int, const char*, int, char*);
/*WINGDIAPI*/ int  __stdcall ExcludeClipRect(HDC, int, int, int, int);
/*WINGDIAPI*/ HRGN __stdcall ExtCreateRegion(const XFORM *, unsigned long, const RGNDATA *);
/*WINGDIAPI*/ BOOL  __stdcall ExtFloodFill(HDC, int, int, COLORREF, unsigned);
/*WINGDIAPI*/ BOOL   __stdcall FillRgn(HDC, HRGN, HBRUSH);
/*WINGDIAPI*/ BOOL   __stdcall FloodFill(HDC, int, int, COLORREF);
/*WINGDIAPI*/ BOOL   __stdcall FrameRgn(HDC, HRGN, HBRUSH, int, int);
/*WINGDIAPI*/ int   __stdcall GetROP2(HDC);
/*WINGDIAPI*/ BOOL  __stdcall GetAspectRatioFilterEx(HDC, LPSIZE);
/*WINGDIAPI*/ COLORREF __stdcall GetBkColor(HDC);
/*WINGDIAPI*/ int   __stdcall GetBkMode(HDC);
/*WINGDIAPI*/ long  __stdcall GetBitmapBits(HBITMAP, long, void*);
/*WINGDIAPI*/ BOOL  __stdcall GetBitmapDimensionEx(HBITMAP, LPSIZE);
/*WINGDIAPI*/ unsigned  __stdcall GetBoundsRect(HDC, LPRECT, unsigned);

/*WINGDIAPI*/ BOOL  __stdcall GetBrushOrgEx(HDC, LPPOINT);

/*WINGDIAPI*/ BOOL  __stdcall GetCharWidthA(HDC, unsigned, unsigned, LPINT);
/*WINGDIAPI*/ BOOL  __stdcall GetCharWidthW(HDC, unsigned, unsigned, LPINT);
#ifdef UNICODE
#define GetCharWidth  GetCharWidthW
#else
#define GetCharWidth  GetCharWidthA
#endif // !UNICODE
/*WINGDIAPI*/ BOOL  __stdcall GetCharWidth32A(HDC, unsigned, unsigned, LPINT);
/*WINGDIAPI*/ BOOL  __stdcall GetCharWidth32W(HDC, unsigned, unsigned, LPINT);
#ifdef UNICODE
#define GetCharWidth32  GetCharWidth32W
#else
#define GetCharWidth32  GetCharWidth32A
#endif // !UNICODE
/*WINGDIAPI*/ BOOL  __stdcall GetCharWidthFloatA(HDC, unsigned, unsigned, float*);
/*WINGDIAPI*/ BOOL  __stdcall GetCharWidthFloatW(HDC, unsigned, unsigned, float*);
#ifdef UNICODE
#define GetCharWidthFloat  GetCharWidthFloatW
#else
#define GetCharWidthFloat  GetCharWidthFloatA
#endif // !UNICODE

/*WINGDIAPI*/ BOOL  __stdcall GetCharABCWidthsA(HDC, unsigned, unsigned, LPABC);
/*WINGDIAPI*/ BOOL  __stdcall GetCharABCWidthsW(HDC, unsigned, unsigned, LPABC);
#ifdef UNICODE
#define GetCharABCWidths  GetCharABCWidthsW
#else
#define GetCharABCWidths  GetCharABCWidthsA
#endif // !UNICODE
/*WINGDIAPI*/ BOOL  __stdcall GetCharABCWidthsFloatA(HDC, unsigned, unsigned, LPABCFLOAT);
/*WINGDIAPI*/ BOOL  __stdcall GetCharABCWidthsFloatW(HDC, unsigned, unsigned, LPABCFLOAT);
#ifdef UNICODE
#define GetCharABCWidthsFloat  GetCharABCWidthsFloatW
#else
#define GetCharABCWidthsFloat  GetCharABCWidthsFloatA
#endif // !UNICODE

/*WINGDIAPI*/ int   __stdcall GetClipBox(HDC, LPRECT);
/*WINGDIAPI*/ int   __stdcall GetClipRgn(HDC, HRGN);
/*WINGDIAPI*/ int   __stdcall GetMetaRgn(HDC, HRGN);
/*WINGDIAPI*/ HGDIOBJ __stdcall GetCurrentObject(HDC, unsigned);
/*WINGDIAPI*/ BOOL  __stdcall GetCurrentPositionEx(HDC, LPPOINT);
/*WINGDIAPI*/ int   __stdcall GetDeviceCaps(HDC, int);
/*WINGDIAPI*/ int   __stdcall GetDIBits(HDC, HBITMAP, unsigned, unsigned, void*, LPBITMAPINFO, unsigned);
/*WINGDIAPI*/ unsigned long __stdcall GetFontData(HDC, unsigned long, unsigned long, void*, unsigned long);
/*WINGDIAPI*/ unsigned long __stdcall GetGlyphOutlineA(HDC, unsigned, unsigned, LPGLYPHMETRICS, unsigned long, void*, const MAT2 *);
/*WINGDIAPI*/ unsigned long __stdcall GetGlyphOutlineW(HDC, unsigned, unsigned, LPGLYPHMETRICS, unsigned long, void*, const MAT2 *);
#ifdef UNICODE
#define GetGlyphOutline  GetGlyphOutlineW
#else
#define GetGlyphOutline  GetGlyphOutlineA
#endif // !UNICODE
/*WINGDIAPI*/ int   __stdcall GetGraphicsMode(HDC);
/*WINGDIAPI*/ int   __stdcall GetMapMode(HDC);
/*WINGDIAPI*/ unsigned  __stdcall GetMetaFileBitsEx(HMETAFILE, unsigned, void*);
/*WINGDIAPI*/ HMETAFILE   __stdcall GetMetaFileA(const char*);
/*WINGDIAPI*/ HMETAFILE   __stdcall GetMetaFileW(const wchar_t*);
#ifdef UNICODE
#define GetMetaFile  GetMetaFileW
#else
#define GetMetaFile  GetMetaFileA
#endif // !UNICODE
/*WINGDIAPI*/ COLORREF __stdcall GetNearestColor(HDC, COLORREF);
/*WINGDIAPI*/ unsigned  __stdcall GetNearestPaletteIndex(HPALETTE, COLORREF);
/*WINGDIAPI*/ unsigned long __stdcall GetObjectType(HGDIOBJ h);

#ifndef NOTEXTMETRIC

/*WINGDIAPI*/ unsigned __stdcall GetOutlineTextMetricsA(HDC, unsigned, LPOUTLINETEXTMETRICA);
/*WINGDIAPI*/ unsigned __stdcall GetOutlineTextMetricsW(HDC, unsigned, LPOUTLINETEXTMETRICW);
#ifdef UNICODE
#define GetOutlineTextMetrics  GetOutlineTextMetricsW
#else
#define GetOutlineTextMetrics  GetOutlineTextMetricsA
#endif // !UNICODE

#endif /* NOTEXTMETRIC */

/*WINGDIAPI*/ unsigned  __stdcall GetPaletteEntries(HPALETTE, unsigned, unsigned, LPPALETTEENTRY);
/*WINGDIAPI*/ COLORREF __stdcall GetPixel(HDC, int, int);
/*WINGDIAPI*/ int   __stdcall GetPixelFormat(HDC);
/*WINGDIAPI*/ int   __stdcall GetPolyFillMode(HDC);
/*WINGDIAPI*/ BOOL  __stdcall GetRasterizerCaps(LPRASTERIZER_STATUS, unsigned);
/*WINGDIAPI*/ unsigned long __stdcall GetRegionData(HRGN, unsigned long, LPRGNDATA);
/*WINGDIAPI*/ int   __stdcall GetRgnBox(HRGN, LPRECT);
/*WINGDIAPI*/ HGDIOBJ __stdcall GetStockObject(int);
/*WINGDIAPI*/ int   __stdcall GetStretchBltMode(HDC);
/*WINGDIAPI*/ unsigned  __stdcall GetSystemPaletteEntries(HDC, unsigned, unsigned, LPPALETTEENTRY);
/*WINGDIAPI*/ unsigned  __stdcall GetSystemPaletteUse(HDC);
/*WINGDIAPI*/ int   __stdcall GetTextCharacterExtra(HDC);
/*WINGDIAPI*/ unsigned  __stdcall GetTextAlign(HDC);
/*WINGDIAPI*/ COLORREF __stdcall GetTextColor(HDC);

/*WINGDIAPI*/ BOOL  __stdcall GetTextExtentPointA(
                    HDC,
                    const char*,
                    int,
                    LPSIZE
                    );
/*WINGDIAPI*/ BOOL  __stdcall GetTextExtentPointW(
                    HDC,
                    const wchar_t*,
                    int,
                    LPSIZE
                    );
#ifdef UNICODE
#define GetTextExtentPoint  GetTextExtentPointW
#else
#define GetTextExtentPoint  GetTextExtentPointA
#endif // !UNICODE

/*WINGDIAPI*/ BOOL  __stdcall GetTextExtentPoint32A(
                    HDC,
                    const char*,
                    int,
                    LPSIZE
                    );
/*WINGDIAPI*/ BOOL  __stdcall GetTextExtentPoint32W(
                    HDC,
                    const wchar_t*,
                    int,
                    LPSIZE
                    );
#ifdef UNICODE
#define GetTextExtentPoint32  GetTextExtentPoint32W
#else
#define GetTextExtentPoint32  GetTextExtentPoint32A
#endif // !UNICODE

/*WINGDIAPI*/ BOOL  __stdcall GetTextExtentExPointA(
                    HDC,
                    const char*,
                    int,
                    int,
                    LPINT,
                    LPINT,
                    LPSIZE
                    );
/*WINGDIAPI*/ BOOL  __stdcall GetTextExtentExPointW(
                    HDC,
                    const wchar_t*,
                    int,
                    int,
                    LPINT,
                    LPINT,
                    LPSIZE
                    );
#ifdef UNICODE
#define GetTextExtentExPoint  GetTextExtentExPointW
#else
#define GetTextExtentExPoint  GetTextExtentExPointA
#endif // !UNICODE

#if(WINVER >= 0x0400)
/*WINGDIAPI*/ int __stdcall GetTextCharset(HDC hdc);
/*WINGDIAPI*/ int __stdcall GetTextCharsetInfo(HDC hdc, LPFONTSIGNATURE lpSig, unsigned long dwFlags);
/*WINGDIAPI*/ BOOL __stdcall TranslateCharsetInfo( unsigned long  *lpSrc, LPCHARSETINFO lpCs, unsigned long dwFlags);
/*WINGDIAPI*/ unsigned long __stdcall GetFontLanguageInfo( HDC );
/*WINGDIAPI*/ unsigned long __stdcall GetCharacterPlacementA(HDC, const char*, int, int, LPGCP_RESULTSA, unsigned long);
/*WINGDIAPI*/ unsigned long __stdcall GetCharacterPlacementW(HDC, const wchar_t*, int, int, LPGCP_RESULTSW, unsigned long);
#ifdef UNICODE
#define GetCharacterPlacement  GetCharacterPlacementW
#else
#define GetCharacterPlacement  GetCharacterPlacementA
#endif // !UNICODE
#endif /* WINVER >= 0x0400 */

/*WINGDIAPI*/ BOOL  __stdcall GetViewportExtEx(HDC, LPSIZE);
/*WINGDIAPI*/ BOOL  __stdcall GetViewportOrgEx(HDC, LPPOINT);
/*WINGDIAPI*/ BOOL  __stdcall GetWindowExtEx(HDC, LPSIZE);
/*WINGDIAPI*/ BOOL  __stdcall GetWindowOrgEx(HDC, LPPOINT);

/*WINGDIAPI*/ int  __stdcall IntersectClipRect(HDC, int, int, int, int);
/*WINGDIAPI*/ BOOL __stdcall InvertRgn(HDC, HRGN);
/*WINGDIAPI*/ BOOL __stdcall LineDDA(int, int, int, int, LINEDDAPROC, LPARAM);
/*WINGDIAPI*/ BOOL __stdcall LineTo(HDC, int, int);
/*WINGDIAPI*/ BOOL __stdcall MaskBlt(HDC, int, int, int, int,
              HDC, int, int, HBITMAP, int, int, unsigned long);
/*WINGDIAPI*/ BOOL __stdcall PlgBlt(HDC, const POINT *, HDC, int, int, int,
                     int, HBITMAP, int, int);

/*WINGDIAPI*/ int  __stdcall OffsetClipRgn(HDC, int, int);
/*WINGDIAPI*/ int  __stdcall OffsetRgn(HRGN, int, int);
/*WINGDIAPI*/ BOOL __stdcall PatBlt(HDC, int, int, int, int, unsigned long);
/*WINGDIAPI*/ BOOL __stdcall Pie(HDC, int, int, int, int, int, int, int, int);
/*WINGDIAPI*/ BOOL __stdcall PlayMetaFile(HDC, HMETAFILE);
/*WINGDIAPI*/ BOOL __stdcall PaintRgn(HDC, HRGN);
/*WINGDIAPI*/ BOOL __stdcall PolyPolygon(HDC, const POINT *, const INT *, int);
/*WINGDIAPI*/ BOOL __stdcall PtInRegion(HRGN, int, int);
/*WINGDIAPI*/ BOOL __stdcall PtVisible(HDC, int, int);
/*WINGDIAPI*/ BOOL __stdcall RectInRegion(HRGN, const RECT *);
/*WINGDIAPI*/ BOOL __stdcall RectVisible(HDC, const RECT *);
/*WINGDIAPI*/ BOOL __stdcall Rectangle(HDC, int, int, int, int);
/*WINGDIAPI*/ BOOL __stdcall RestoreDC(HDC, int);
/*WINGDIAPI*/ HDC  __stdcall ResetDCA(HDC, const DEVMODEA *);
/*WINGDIAPI*/ HDC  __stdcall ResetDCW(HDC, const DEVMODEW *);
#ifdef UNICODE
#define ResetDC  ResetDCW
#else
#define ResetDC  ResetDCA
#endif // !UNICODE
/*WINGDIAPI*/ unsigned __stdcall RealizePalette(HDC);
/*WINGDIAPI*/ BOOL __stdcall RemoveFontResourceA(const char*);
/*WINGDIAPI*/ BOOL __stdcall RemoveFontResourceW(const wchar_t*);
#ifdef UNICODE
#define RemoveFontResource  RemoveFontResourceW
#else
#define RemoveFontResource  RemoveFontResourceA
#endif // !UNICODE
/*WINGDIAPI*/ BOOL  __stdcall RoundRect(HDC, int, int, int, int, int, int);
/*WINGDIAPI*/ BOOL __stdcall ResizePalette(HPALETTE, unsigned);

/*WINGDIAPI*/ int  __stdcall SaveDC(HDC);
/*WINGDIAPI*/ int  __stdcall SelectClipRgn(HDC, HRGN);
/*WINGDIAPI*/ int  __stdcall ExtSelectClipRgn(HDC, HRGN, int);
/*WINGDIAPI*/ int  __stdcall SetMetaRgn(HDC);
/*WINGDIAPI*/ HGDIOBJ __stdcall SelectObject(HDC, HGDIOBJ);
/*WINGDIAPI*/ HPALETTE __stdcall SelectPalette(HDC, HPALETTE, BOOL);
/*WINGDIAPI*/ COLORREF __stdcall SetBkColor(HDC, COLORREF);
/*WINGDIAPI*/ int   __stdcall SetBkMode(HDC, int);
/*WINGDIAPI*/ long  __stdcall SetBitmapBits(HBITMAP, unsigned long, const void *);

/*WINGDIAPI*/ unsigned  __stdcall SetBoundsRect(HDC, const RECT *, unsigned);
/*WINGDIAPI*/ int   __stdcall SetDIBits(HDC, HBITMAP, unsigned, unsigned, const void *, const BITMAPINFO *, unsigned);
/*WINGDIAPI*/ int   __stdcall SetDIBitsToDevice(HDC, int, int, unsigned long, unsigned long, int,
        int, unsigned, unsigned, const void *, const BITMAPINFO *, unsigned);
/*WINGDIAPI*/ unsigned long __stdcall SetMapperFlags(HDC, unsigned long);
/*WINGDIAPI*/ int   __stdcall SetGraphicsMode(HDC hdc, int iMode);
/*WINGDIAPI*/ int   __stdcall SetMapMode(HDC, int);
/*WINGDIAPI*/ HMETAFILE   __stdcall SetMetaFileBitsEx(unsigned, const BYTE *);
/*WINGDIAPI*/ unsigned  __stdcall SetPaletteEntries(HPALETTE, unsigned, unsigned, const PALETTEENTRY *);
/*WINGDIAPI*/ COLORREF __stdcall SetPixel(HDC, int, int, COLORREF);
/*WINGDIAPI*/ BOOL   __stdcall SetPixelV(HDC, int, int, COLORREF);
/*WINGDIAPI*/ BOOL  __stdcall SetPixelFormat(HDC, int, const PIXELFORMATDESCRIPTOR *);
/*WINGDIAPI*/ int   __stdcall SetPolyFillMode(HDC, int);
/*WINGDIAPI*/ BOOL   __stdcall StretchBlt(HDC, int, int, int, int, HDC, int, int, int, int, unsigned long);
/*WINGDIAPI*/ BOOL   __stdcall SetRectRgn(HRGN, int, int, int, int);
/*WINGDIAPI*/ int   __stdcall StretchDIBits(HDC, int, int, int, int, int, int, int, int, const
        void *, const BITMAPINFO *, unsigned, unsigned long);
/*WINGDIAPI*/ int   __stdcall SetROP2(HDC, int);
/*WINGDIAPI*/ int   __stdcall SetStretchBltMode(HDC, int);
/*WINGDIAPI*/ unsigned  __stdcall SetSystemPaletteUse(HDC, unsigned);
/*WINGDIAPI*/ int   __stdcall SetTextCharacterExtra(HDC, int);
/*WINGDIAPI*/ COLORREF __stdcall SetTextColor(HDC, COLORREF);
/*WINGDIAPI*/ unsigned  __stdcall SetTextAlign(HDC, unsigned);
/*WINGDIAPI*/ BOOL  __stdcall SetTextJustification(HDC, int, int);
/*WINGDIAPI*/ BOOL  __stdcall UpdateColors(HDC);

#ifndef NOMETAFILE

/*WINGDIAPI*/ BOOL  __stdcall PlayMetaFileRecord(HDC, LPHANDLETABLE, LPMETARECORD, unsigned);
typedef int (__stdcall* MFENUMPROC)(HDC, HANDLETABLE *, METARECORD *, int, LPARAM);
/*WINGDIAPI*/ BOOL  __stdcall EnumMetaFile(HDC, HMETAFILE, MFENUMPROC, LPARAM);

typedef int (__stdcall* ENHMFENUMPROC)(HDC, HANDLETABLE *, const ENHMETARECORD *, int, LPARAM);

// Enhanced Metafile Function Declarations

/*WINGDIAPI*/ HENHMETAFILE __stdcall CloseEnhMetaFile(HDC);
/*WINGDIAPI*/ HENHMETAFILE __stdcall CopyEnhMetaFileA(HENHMETAFILE, const char*);
/*WINGDIAPI*/ HENHMETAFILE __stdcall CopyEnhMetaFileW(HENHMETAFILE, const wchar_t*);
#ifdef UNICODE
#define CopyEnhMetaFile  CopyEnhMetaFileW
#else
#define CopyEnhMetaFile  CopyEnhMetaFileA
#endif // !UNICODE
/*WINGDIAPI*/ HDC   __stdcall CreateEnhMetaFileA(HDC, const char*, const RECT *, const char*);
/*WINGDIAPI*/ HDC   __stdcall CreateEnhMetaFileW(HDC, const wchar_t*, const RECT *, const wchar_t*);
#ifdef UNICODE
#define CreateEnhMetaFile  CreateEnhMetaFileW
#else
#define CreateEnhMetaFile  CreateEnhMetaFileA
#endif // !UNICODE
/*WINGDIAPI*/ BOOL  __stdcall DeleteEnhMetaFile(HENHMETAFILE);
/*WINGDIAPI*/ BOOL  __stdcall EnumEnhMetaFile(HDC, HENHMETAFILE, ENHMFENUMPROC,
        void*, const RECT *);
/*WINGDIAPI*/ HENHMETAFILE  __stdcall GetEnhMetaFileA(const char*);
/*WINGDIAPI*/ HENHMETAFILE  __stdcall GetEnhMetaFileW(const wchar_t*);
#ifdef UNICODE
#define GetEnhMetaFile  GetEnhMetaFileW
#else
#define GetEnhMetaFile  GetEnhMetaFileA
#endif // !UNICODE
/*WINGDIAPI*/ unsigned  __stdcall GetEnhMetaFileBits(HENHMETAFILE, unsigned, BYTE*);
/*WINGDIAPI*/ unsigned  __stdcall GetEnhMetaFileDescriptionA(HENHMETAFILE, unsigned, char* );
/*WINGDIAPI*/ unsigned  __stdcall GetEnhMetaFileDescriptionW(HENHMETAFILE, unsigned, wchar_t* );
#ifdef UNICODE
#define GetEnhMetaFileDescription  GetEnhMetaFileDescriptionW
#else
#define GetEnhMetaFileDescription  GetEnhMetaFileDescriptionA
#endif // !UNICODE
/*WINGDIAPI*/ unsigned  __stdcall GetEnhMetaFileHeader(HENHMETAFILE, unsigned, LPENHMETAHEADER );
/*WINGDIAPI*/ unsigned  __stdcall GetEnhMetaFilePaletteEntries(HENHMETAFILE, unsigned, LPPALETTEENTRY );
/*WINGDIAPI*/ unsigned  __stdcall GetEnhMetaFilePixelFormat(HENHMETAFILE, unsigned,
                                                 PIXELFORMATDESCRIPTOR *);
/*WINGDIAPI*/ unsigned  __stdcall GetWinMetaFileBits(HENHMETAFILE, unsigned, BYTE*, INT, HDC);
/*WINGDIAPI*/ BOOL  __stdcall PlayEnhMetaFile(HDC, HENHMETAFILE, const RECT *);
/*WINGDIAPI*/ BOOL  __stdcall PlayEnhMetaFileRecord(HDC, LPHANDLETABLE, const ENHMETARECORD *, unsigned);
/*WINGDIAPI*/ HENHMETAFILE  __stdcall SetEnhMetaFileBits(unsigned, const BYTE *);
/*WINGDIAPI*/ HENHMETAFILE  __stdcall SetWinMetaFileBits(unsigned, const BYTE *, HDC, const METAFILEPICT *);
/*WINGDIAPI*/ BOOL  __stdcall GdiComment(HDC, unsigned, const BYTE *);

#endif  /* NOMETAFILE */

#ifndef NOTEXTMETRIC

/*WINGDIAPI*/ BOOL __stdcall GetTextMetricsA(HDC, LPTEXTMETRICA);
/*WINGDIAPI*/ BOOL __stdcall GetTextMetricsW(HDC, LPTEXTMETRICW);
#ifdef UNICODE
#define GetTextMetrics  GetTextMetricsW
#else
#define GetTextMetrics  GetTextMetricsA
#endif // !UNICODE

#endif

/* new GDI */

typedef struct tagDIBSECTION {
    BITMAP              dsBm;
    BITMAPINFOHEADER    dsBmih;
    unsigned long               dsBitfields[3];
    HANDLE              dshSection;
    unsigned long               dsOffset;
} DIBSECTION,  *LPDIBSECTION, *PDIBSECTION;

/*WINGDIAPI*/ BOOL __stdcall AngleArc(HDC, int, int, unsigned long, float, float);
/*WINGDIAPI*/ BOOL __stdcall PolyPolyline(HDC, const POINT *, const unsigned long *, unsigned long);
/*WINGDIAPI*/ BOOL __stdcall GetWorldTransform(HDC, LPXFORM);
/*WINGDIAPI*/ BOOL __stdcall SetWorldTransform(HDC, const XFORM *);
/*WINGDIAPI*/ BOOL __stdcall ModifyWorldTransform(HDC, const XFORM *, unsigned long);
/*WINGDIAPI*/ BOOL __stdcall CombineTransform(LPXFORM, const XFORM *, const XFORM *);
/*WINGDIAPI*/ HBITMAP __stdcall CreateDIBSection(HDC, const BITMAPINFO *, unsigned, void **, HANDLE, unsigned long);
/*WINGDIAPI*/ unsigned __stdcall GetDIBColorTable(HDC, unsigned, unsigned, RGBQUAD *);
/*WINGDIAPI*/ unsigned __stdcall SetDIBColorTable(HDC, unsigned, unsigned, const RGBQUAD *);

/* Flags value for COLORADJUSTMENT */
#define CA_NEGATIVE                 0x0001
#define CA_LOG_FILTER               0x0002

/* IlluminantIndex values */
#define ILLUMINANT_DEVICE_DEFAULT   0
#define ILLUMINANT_A                1
#define ILLUMINANT_B                2
#define ILLUMINANT_C                3
#define ILLUMINANT_D50              4
#define ILLUMINANT_D55              5
#define ILLUMINANT_D65              6
#define ILLUMINANT_D75              7
#define ILLUMINANT_F2               8
#define ILLUMINANT_MAX_INDEX        ILLUMINANT_F2

#define ILLUMINANT_TUNGSTEN         ILLUMINANT_A
#define ILLUMINANT_DAYLIGHT         ILLUMINANT_C
#define ILLUMINANT_FLUORESCENT      ILLUMINANT_F2
#define ILLUMINANT_NTSC             ILLUMINANT_C

/* Min and max for RedGamma, GreenGamma, BlueGamma */
#define RGB_GAMMA_MIN               (WORD)02500
#define RGB_GAMMA_MAX               (WORD)65000

/* Min and max for ReferenceBlack and ReferenceWhite */
#define REFERENCE_WHITE_MIN         (WORD)6000
#define REFERENCE_WHITE_MAX         (WORD)10000
#define REFERENCE_BLACK_MIN         (WORD)0
#define REFERENCE_BLACK_MAX         (WORD)4000

/* Min and max for Contrast, Brightness, Colorfulness, RedGreenTint */
#define COLOR_ADJ_MIN               (short)-100
#define COLOR_ADJ_MAX               (short)100

typedef struct  tagCOLORADJUSTMENT {
    WORD   caSize;
    WORD   caFlags;
    WORD   caIlluminantIndex;
    WORD   caRedGamma;
    WORD   caGreenGamma;
    WORD   caBlueGamma;
    WORD   caReferenceBlack;
    WORD   caReferenceWhite;
    short  caContrast;
    short  caBrightness;
    short  caColorfulness;
    short  caRedGreenTint;
} COLORADJUSTMENT, *PCOLORADJUSTMENT,  *LPCOLORADJUSTMENT;

/*WINGDIAPI*/ BOOL __stdcall SetColorAdjustment(HDC, const COLORADJUSTMENT *);
/*WINGDIAPI*/ BOOL __stdcall GetColorAdjustment(HDC, LPCOLORADJUSTMENT);
/*WINGDIAPI*/ HPALETTE __stdcall CreateHalftonePalette(HDC);

#ifdef STRICT
typedef BOOL (__stdcall* ABORTPROC)(HDC, int);
#else
typedef FARPROC ABORTPROC;
#endif

typedef struct _DOCINFOA {
    int     cbSize;
    const char*   lpszDocName;
    const char*   lpszOutput;
#if (WINVER >= 0x0400)
    const char*   lpszDatatype;
    unsigned long    fwType;
#endif /* WINVER */
} DOCINFOA, *LPDOCINFOA;
typedef struct _DOCINFOW {
    int     cbSize;
    const wchar_t*  lpszDocName;
    const wchar_t*  lpszOutput;
#if (WINVER >= 0x0400)
    const wchar_t*  lpszDatatype;
    unsigned long    fwType;
#endif /* WINVER */
} DOCINFOW, *LPDOCINFOW;
#ifdef UNICODE
typedef DOCINFOW DOCINFO;
typedef LPDOCINFOW LPDOCINFO;
#else
typedef DOCINFOA DOCINFO;
typedef LPDOCINFOA LPDOCINFO;
#endif // UNICODE

#if(WINVER >= 0x0400)
#define DI_APPBANDING   0x0001
#endif /* WINVER >= 0x0400 */

/*WINGDIAPI*/ int __stdcall StartDocA(HDC, const DOCINFOA *);
/*WINGDIAPI*/ int __stdcall StartDocW(HDC, const DOCINFOW *);
#ifdef UNICODE
#define StartDoc  StartDocW
#else
#define StartDoc  StartDocA
#endif // !UNICODE
/*WINGDIAPI*/ int __stdcall EndDoc(HDC);
/*WINGDIAPI*/ int __stdcall StartPage(HDC);
/*WINGDIAPI*/ int __stdcall EndPage(HDC);
/*WINGDIAPI*/ int __stdcall AbortDoc(HDC);
/*WINGDIAPI*/ int __stdcall SetAbortProc(HDC, ABORTPROC);

/*WINGDIAPI*/ BOOL __stdcall AbortPath(HDC);
/*WINGDIAPI*/ BOOL __stdcall ArcTo(HDC, int, int, int, int, int, int,int, int);
/*WINGDIAPI*/ BOOL __stdcall BeginPath(HDC);
/*WINGDIAPI*/ BOOL __stdcall CloseFigure(HDC);
/*WINGDIAPI*/ BOOL __stdcall EndPath(HDC);
/*WINGDIAPI*/ BOOL __stdcall FillPath(HDC);
/*WINGDIAPI*/ BOOL __stdcall FlattenPath(HDC);
/*WINGDIAPI*/ int  __stdcall GetPath(HDC, LPPOINT, BYTE*, int);
/*WINGDIAPI*/ HRGN __stdcall PathToRegion(HDC);
/*WINGDIAPI*/ BOOL __stdcall PolyDraw(HDC, const POINT *, const BYTE *, int);
/*WINGDIAPI*/ BOOL __stdcall SelectClipPath(HDC, int);
/*WINGDIAPI*/ int  __stdcall SetArcDirection(HDC, int);
/*WINGDIAPI*/ BOOL __stdcall SetMiterLimit(HDC, float, float*);
/*WINGDIAPI*/ BOOL __stdcall StrokeAndFillPath(HDC);
/*WINGDIAPI*/ BOOL __stdcall StrokePath(HDC);
/*WINGDIAPI*/ BOOL __stdcall WidenPath(HDC);
/*WINGDIAPI*/ HPEN __stdcall ExtCreatePen(unsigned long, unsigned long, const LOGBRUSH *, unsigned long, const unsigned long *);
/*WINGDIAPI*/ BOOL __stdcall GetMiterLimit(HDC, float*);
/*WINGDIAPI*/ int  __stdcall GetArcDirection(HDC);

/*WINGDIAPI*/ int   __stdcall GetObjectA(HGDIOBJ, int, void*);
/*WINGDIAPI*/ int   __stdcall GetObjectW(HGDIOBJ, int, void*);
#ifdef UNICODE
#define GetObject  GetObjectW
#else
#define GetObject  GetObjectA
#endif // !UNICODE
/*WINGDIAPI*/ BOOL  __stdcall MoveToEx(HDC, int, int, LPPOINT);
/*WINGDIAPI*/ BOOL  __stdcall TextOutA(HDC, int, int, const char*, int);
/*WINGDIAPI*/ BOOL  __stdcall TextOutW(HDC, int, int, const wchar_t*, int);
#ifdef UNICODE
#define TextOut  TextOutW
#else
#define TextOut  TextOutA
#endif // !UNICODE
/*WINGDIAPI*/ BOOL  __stdcall ExtTextOutA(HDC, int, int, unsigned, const RECT *,const char*, unsigned, const INT *);
/*WINGDIAPI*/ BOOL  __stdcall ExtTextOutW(HDC, int, int, unsigned, const RECT *,const wchar_t*, unsigned, const INT *);
#ifdef UNICODE
#define ExtTextOut  ExtTextOutW
#else
#define ExtTextOut  ExtTextOutA
#endif // !UNICODE
/*WINGDIAPI*/ BOOL  __stdcall PolyTextOutA(HDC, const POLYTEXTA *, int);
/*WINGDIAPI*/ BOOL  __stdcall PolyTextOutW(HDC, const POLYTEXTW *, int);
#ifdef UNICODE
#define PolyTextOut  PolyTextOutW
#else
#define PolyTextOut  PolyTextOutA
#endif // !UNICODE

/*WINGDIAPI*/ HRGN  __stdcall CreatePolygonRgn(const POINT *, int, int);
/*WINGDIAPI*/ BOOL  __stdcall DPtoLP(HDC, LPPOINT, int);
/*WINGDIAPI*/ BOOL  __stdcall LPtoDP(HDC, LPPOINT, int);
/*WINGDIAPI*/ BOOL  __stdcall Polygon(HDC, const POINT *, int);
/*WINGDIAPI*/ BOOL  __stdcall Polyline(HDC, const POINT *, int);

/*WINGDIAPI*/ BOOL  __stdcall PolyBezier(HDC, const POINT *, unsigned long);
/*WINGDIAPI*/ BOOL  __stdcall PolyBezierTo(HDC, const POINT *, unsigned long);
/*WINGDIAPI*/ BOOL  __stdcall PolylineTo(HDC, const POINT *, unsigned long);

/*WINGDIAPI*/ BOOL  __stdcall SetViewportExtEx(HDC, int, int, LPSIZE);
/*WINGDIAPI*/ BOOL  __stdcall SetViewportOrgEx(HDC, int, int, LPPOINT);
/*WINGDIAPI*/ BOOL  __stdcall SetWindowExtEx(HDC, int, int, LPSIZE);
/*WINGDIAPI*/ BOOL  __stdcall SetWindowOrgEx(HDC, int, int, LPPOINT);

/*WINGDIAPI*/ BOOL  __stdcall OffsetViewportOrgEx(HDC, int, int, LPPOINT);
/*WINGDIAPI*/ BOOL  __stdcall OffsetWindowOrgEx(HDC, int, int, LPPOINT);
/*WINGDIAPI*/ BOOL  __stdcall ScaleViewportExtEx(HDC, int, int, int, int, LPSIZE);
/*WINGDIAPI*/ BOOL  __stdcall ScaleWindowExtEx(HDC, int, int, int, int, LPSIZE);
/*WINGDIAPI*/ BOOL  __stdcall SetBitmapDimensionEx(HBITMAP, int, int, LPSIZE);
/*WINGDIAPI*/ BOOL  __stdcall SetBrushOrgEx(HDC, int, int, LPPOINT);

/*WINGDIAPI*/ int   __stdcall GetTextFaceA(HDC, int, char*);
/*WINGDIAPI*/ int   __stdcall GetTextFaceW(HDC, int, wchar_t*);
#ifdef UNICODE
#define GetTextFace  GetTextFaceW
#else
#define GetTextFace  GetTextFaceA
#endif // !UNICODE

#define FONTMAPPER_MAX 10

typedef struct tagKERNINGPAIR {
   WORD wFirst;
   WORD wSecond;
   int  iKernAmount;
} KERNINGPAIR, *LPKERNINGPAIR;

/*WINGDIAPI*/ unsigned long __stdcall GetKerningPairsA(HDC, unsigned long, LPKERNINGPAIR);
/*WINGDIAPI*/ unsigned long __stdcall GetKerningPairsW(HDC, unsigned long, LPKERNINGPAIR);
#ifdef UNICODE
#define GetKerningPairs  GetKerningPairsW
#else
#define GetKerningPairs  GetKerningPairsA
#endif // !UNICODE

/*WINGDIAPI*/ BOOL  __stdcall GetDCOrgEx(HDC,LPPOINT);
/*WINGDIAPI*/ BOOL  __stdcall FixBrushOrgEx(HDC,int,int,LPPOINT);
/*WINGDIAPI*/ BOOL  __stdcall UnrealizeObject(HGDIOBJ);

/*WINGDIAPI*/ BOOL  __stdcall GdiFlush();
/*WINGDIAPI*/ unsigned long __stdcall GdiSetBatchLimit(unsigned long);
/*WINGDIAPI*/ unsigned long __stdcall GdiGetBatchLimit();

#if(WINVER >= 0x0400)

#define ICM_OFF   1
#define ICM_ON    2
#define ICM_QUERY 3

int __stdcall SetICMMode(HDC, int);
BOOL __stdcall CheckColorsInGamut(HDC,void*,void*,unsigned long);
HANDLE __stdcall GetColorSpace(HDC);
BOOL __stdcall GetLogColorSpaceA(HCOLORSPACE,LPLOGCOLORSPACEA,unsigned long);
BOOL __stdcall GetLogColorSpaceW(HCOLORSPACE,LPLOGCOLORSPACEW,unsigned long);
#ifdef UNICODE
#define GetLogColorSpace  GetLogColorSpaceW
#else
#define GetLogColorSpace  GetLogColorSpaceA
#endif // !UNICODE
HCOLORSPACE __stdcall CreateColorSpaceA(LPLOGCOLORSPACEA);
HCOLORSPACE __stdcall CreateColorSpaceW(LPLOGCOLORSPACEW);
#ifdef UNICODE
#define CreateColorSpace  CreateColorSpaceW
#else
#define CreateColorSpace  CreateColorSpaceA
#endif // !UNICODE
BOOL __stdcall SetColorSpace(HDC,HCOLORSPACE);
BOOL __stdcall DeleteColorSpace(HCOLORSPACE);
BOOL __stdcall GetICMProfileA(HDC,LPDWORD,char*);
BOOL __stdcall GetICMProfileW(HDC,LPDWORD,wchar_t*);
#ifdef UNICODE
#define GetICMProfile  GetICMProfileW
#else
#define GetICMProfile  GetICMProfileA
#endif // !UNICODE
BOOL __stdcall SetICMProfileA(HDC,char*);
BOOL __stdcall SetICMProfileW(HDC,wchar_t*);
#ifdef UNICODE
#define SetICMProfile  SetICMProfileW
#else
#define SetICMProfile  SetICMProfileA
#endif // !UNICODE
BOOL __stdcall GetDeviceGammaRamp(HDC,void*);
BOOL __stdcall SetDeviceGammaRamp(HDC,void*);
BOOL __stdcall ColorMatchToTarget(HDC,HDC,unsigned long);
typedef int (__stdcall* ICMENUMPROCA)(char*, LPARAM);
typedef int (__stdcall* ICMENUMPROCW)(wchar_t*, LPARAM);
#ifdef UNICODE
#define ICMENUMPROC  ICMENUMPROCW
#else
#define ICMENUMPROC  ICMENUMPROCA
#endif // !UNICODE
int __stdcall EnumICMProfilesA(HDC,ICMENUMPROCA,LPARAM);
int __stdcall EnumICMProfilesW(HDC,ICMENUMPROCW,LPARAM);
#ifdef UNICODE
#define EnumICMProfiles  EnumICMProfilesW
#else
#define EnumICMProfiles  EnumICMProfilesA
#endif // !UNICODE

#endif /* WINVER >= 0x0400 */
#ifndef NOMETAFILE

// Enhanced metafile constants.

#define ENHMETA_SIGNATURE       0x464D4520

// Stock object flag used in the object handle index in the enhanced
// metafile records.
// E.g. The object handle index (META_STOCK_OBJECT | BLACK_BRUSH)
// represents the stock object BLACK_BRUSH.

#define ENHMETA_STOCK_OBJECT    0x80000000

// Enhanced metafile record types.

#define EMR_HEADER                      1
#define EMR_POLYBEZIER                  2
#define EMR_POLYGON                     3
#define EMR_POLYLINE                    4
#define EMR_POLYBEZIERTO                5
#define EMR_POLYLINETO                  6
#define EMR_POLYPOLYLINE                7
#define EMR_POLYPOLYGON                 8
#define EMR_SETWINDOWEXTEX              9
#define EMR_SETWINDOWORGEX              10
#define EMR_SETVIEWPORTEXTEX            11
#define EMR_SETVIEWPORTORGEX            12
#define EMR_SETBRUSHORGEX               13
#define EMR_EOF                         14
#define EMR_SETPIXELV                   15
#define EMR_SETMAPPERFLAGS              16
#define EMR_SETMAPMODE                  17
#define EMR_SETBKMODE                   18
#define EMR_SETPOLYFILLMODE             19
#define EMR_SETROP2                     20
#define EMR_SETSTRETCHBLTMODE           21
#define EMR_SETTEXTALIGN                22
#define EMR_SETCOLORADJUSTMENT          23
#define EMR_SETTEXTCOLOR                24
#define EMR_SETBKCOLOR                  25
#define EMR_OFFSETCLIPRGN               26
#define EMR_MOVETOEX                    27
#define EMR_SETMETARGN                  28
#define EMR_EXCLUDECLIPRECT             29
#define EMR_INTERSECTCLIPRECT           30
#define EMR_SCALEVIEWPORTEXTEX          31
#define EMR_SCALEWINDOWEXTEX            32
#define EMR_SAVEDC                      33
#define EMR_RESTOREDC                   34
#define EMR_SETWORLDTRANSFORM           35
#define EMR_MODIFYWORLDTRANSFORM        36
#define EMR_SELECTOBJECT                37
#define EMR_CREATEPEN                   38
#define EMR_CREATEBRUSHINDIRECT         39
#define EMR_DELETEOBJECT                40
#define EMR_ANGLEARC                    41
#define EMR_ELLIPSE                     42
#define EMR_RECTANGLE                   43
#define EMR_ROUNDRECT                   44
#define EMR_ARC                         45
#define EMR_CHORD                       46
#define EMR_PIE                         47
#define EMR_SELECTPALETTE               48
#define EMR_CREATEPALETTE               49
#define EMR_SETPALETTEENTRIES           50
#define EMR_RESIZEPALETTE               51
#define EMR_REALIZEPALETTE              52
#define EMR_EXTFLOODFILL                53
#define EMR_LINETO                      54
#define EMR_ARCTO                       55
#define EMR_POLYDRAW                    56
#define EMR_SETARCDIRECTION             57
#define EMR_SETMITERLIMIT               58
#define EMR_BEGINPATH                   59
#define EMR_ENDPATH                     60
#define EMR_CLOSEFIGURE                 61
#define EMR_FILLPATH                    62
#define EMR_STROKEANDFILLPATH           63
#define EMR_STROKEPATH                  64
#define EMR_FLATTENPATH                 65
#define EMR_WIDENPATH                   66
#define EMR_SELECTCLIPPATH              67
#define EMR_ABORTPATH                   68

#define EMR_GDICOMMENT                  70
#define EMR_FILLRGN                     71
#define EMR_FRAMERGN                    72
#define EMR_INVERTRGN                   73
#define EMR_PAINTRGN                    74
#define EMR_EXTSELECTCLIPRGN            75
#define EMR_BITBLT                      76
#define EMR_STRETCHBLT                  77
#define EMR_MASKBLT                     78
#define EMR_PLGBLT                      79
#define EMR_SETDIBITSTODEVICE           80
#define EMR_STRETCHDIBITS               81
#define EMR_EXTCREATEFONTINDIRECTW      82
#define EMR_EXTTEXTOUTA                 83
#define EMR_EXTTEXTOUTW                 84
#define EMR_POLYBEZIER16                85
#define EMR_POLYGON16                   86
#define EMR_POLYLINE16                  87
#define EMR_POLYBEZIERTO16              88
#define EMR_POLYLINETO16                89
#define EMR_POLYPOLYLINE16              90
#define EMR_POLYPOLYGON16               91
#define EMR_POLYDRAW16                  92
#define EMR_CREATEMONOBRUSH             93
#define EMR_CREATEDIBPATTERNBRUSHPT     94
#define EMR_EXTCREATEPEN                95
#define EMR_POLYTEXTOUTA                96
#define EMR_POLYTEXTOUTW                97
#if(WINVER >= 0x0400)
#define EMR_SETICMMODE                  98
#define EMR_CREATECOLORSPACE            99
#define EMR_SETCOLORSPACE              100
#define EMR_DELETECOLORSPACE           101
#define EMR_GLSRECORD                  102
#define EMR_GLSBOUNDEDRECORD           103
#define EMR_PIXELFORMAT                104
#endif /* WINVER >= 0x0400 */

#define EMR_MIN                         1

#if (WINVER >= 0x0400)
#define EMR_MAX                        104
#else
#define EMR_MAX                         97
#endif

// Base record type for the enhanced metafile.

typedef struct tagEMR
{
    unsigned long   iType;              // Enhanced metafile record type
    unsigned long   nSize;              // Length of the record in bytes.
                                // This must be a multiple of 4.
} EMR, *PEMR;

// Base text record type for the enhanced metafile.

typedef struct tagEMRTEXT
{
    POINTL  ptlReference;
    unsigned long   nChars;
    unsigned long   offString;          // Offset to the string
    unsigned long   fOptions;
    RECTL   rcl;
    unsigned long   offDx;              // Offset to the inter-character spacing array.
                                // This is always given.
} EMRTEXT, *PEMRTEXT;

// Record structures for the enhanced metafile.

typedef struct tagABORTPATH
{
    EMR     emr;
} EMRABORTPATH,      *PEMRABORTPATH,
  EMRBEGINPATH,      *PEMRBEGINPATH,
  EMRENDPATH,        *PEMRENDPATH,
  EMRCLOSEFIGURE,    *PEMRCLOSEFIGURE,
  EMRFLATTENPATH,    *PEMRFLATTENPATH,
  EMRWIDENPATH,      *PEMRWIDENPATH,
  EMRSETMETARGN,     *PEMRSETMETARGN,
  EMRSAVEDC,         *PEMRSAVEDC,
  EMRREALIZEPALETTE, *PEMRREALIZEPALETTE;

typedef struct tagEMRSELECTCLIPPATH
{
    EMR     emr;
    unsigned long   iMode;
} EMRSELECTCLIPPATH,    *PEMRSELECTCLIPPATH,
  EMRSETBKMODE,         *PEMRSETBKMODE,
  EMRSETMAPMODE,        *PEMRSETMAPMODE,
  EMRSETPOLYFILLMODE,   *PEMRSETPOLYFILLMODE,
  EMRSETROP2,           *PEMRSETROP2,
  EMRSETSTRETCHBLTMODE, *PEMRSETSTRETCHBLTMODE,
  EMRSETICMMODE,        *PEMRSETICMMODE,
  EMRSETTEXTALIGN,      *PEMRSETTEXTALIGN;

typedef struct tagEMRSETMITERLIMIT
{
    EMR     emr;
    float   eMiterLimit;
} EMRSETMITERLIMIT, *PEMRSETMITERLIMIT;

typedef struct tagEMRRESTOREDC
{
    EMR     emr;
    long    iRelative;          // Specifies a relative instance
} EMRRESTOREDC, *PEMRRESTOREDC;

typedef struct tagEMRSETARCDIRECTION
{
    EMR     emr;
    unsigned long   iArcDirection;      // Specifies the arc direction in the
                                // advanced graphics mode.
} EMRSETARCDIRECTION, *PEMRSETARCDIRECTION;

typedef struct tagEMRSETMAPPERFLAGS
{
    EMR     emr;
    unsigned long   dwFlags;
} EMRSETMAPPERFLAGS, *PEMRSETMAPPERFLAGS;

typedef struct tagEMRSETTEXTCOLOR
{
    EMR     emr;
    COLORREF crColor;
} EMRSETBKCOLOR,   *PEMRSETBKCOLOR,
  EMRSETTEXTCOLOR, *PEMRSETTEXTCOLOR;

typedef struct tagEMRSELECTOBJECT
{
    EMR     emr;
    unsigned long   ihObject;           // Object handle index
} EMRSELECTOBJECT, *PEMRSELECTOBJECT,
  EMRDELETEOBJECT, *PEMRDELETEOBJECT;

#if(WINVER >= 0x0400)
typedef struct tagEMRSELECTCOLORSPACE
{
    EMR     emr;
    unsigned long   ihCS;               // ColorSpace handle index
} EMRSELECTCOLORSPACE, *PEMRSELECTCOLORSPACE,
  EMRDELETECOLORSPACE, *PEMRDELETECOLORSPACE;
#endif /* WINVER >= 0x0400 */

typedef struct tagEMRSELECTPALETTE
{
    EMR     emr;
    unsigned long   ihPal;              // Palette handle index, background mode only
} EMRSELECTPALETTE, *PEMRSELECTPALETTE;

typedef struct tagEMRRESIZEPALETTE
{
    EMR     emr;
    unsigned long   ihPal;              // Palette handle index
    unsigned long   cEntries;
} EMRRESIZEPALETTE, *PEMRRESIZEPALETTE;

typedef struct tagEMRSETPALETTEENTRIES
{
    EMR     emr;
    unsigned long   ihPal;              // Palette handle index
    unsigned long   iStart;
    unsigned long   cEntries;
    PALETTEENTRY aPalEntries[1];// The peFlags fields do not contain any flags
} EMRSETPALETTEENTRIES, *PEMRSETPALETTEENTRIES;

typedef struct tagEMRSETCOLORADJUSTMENT
{
    EMR     emr;
    COLORADJUSTMENT ColorAdjustment;
} EMRSETCOLORADJUSTMENT, *PEMRSETCOLORADJUSTMENT;

typedef struct tagEMRGDICOMMENT
{
    EMR     emr;
    unsigned long   cbData;             // Size of data in bytes
    BYTE    Data[1];
} EMRGDICOMMENT, *PEMRGDICOMMENT;

typedef struct tagEMREOF
{
    EMR     emr;
    unsigned long   nPalEntries;        // Number of palette entries
    unsigned long   offPalEntries;      // Offset to the palette entries
    unsigned long   nSizeLast;          // Same as nSize and must be the last unsigned long
                                // of the record.  The palette entries,
                                // if exist, precede this field.
} EMREOF, *PEMREOF;

typedef struct tagEMRLINETO
{
    EMR     emr;
    POINTL  ptl;
} EMRLINETO,   *PEMRLINETO,
  EMRMOVETOEX, *PEMRMOVETOEX;

typedef struct tagEMROFFSETCLIPRGN
{
    EMR     emr;
    POINTL  ptlOffset;
} EMROFFSETCLIPRGN, *PEMROFFSETCLIPRGN;

typedef struct tagEMRFILLPATH
{
    EMR     emr;
    RECTL   rclBounds;          // Inclusive-inclusive bounds in device units
} EMRFILLPATH,          *PEMRFILLPATH,
  EMRSTROKEANDFILLPATH, *PEMRSTROKEANDFILLPATH,
  EMRSTROKEPATH,        *PEMRSTROKEPATH;

typedef struct tagEMREXCLUDECLIPRECT
{
    EMR     emr;
    RECTL   rclClip;
} EMREXCLUDECLIPRECT,   *PEMREXCLUDECLIPRECT,
  EMRINTERSECTCLIPRECT, *PEMRINTERSECTCLIPRECT;

typedef struct tagEMRSETVIEWPORTORGEX
{
    EMR     emr;
    POINTL  ptlOrigin;
} EMRSETVIEWPORTORGEX, *PEMRSETVIEWPORTORGEX,
  EMRSETWINDOWORGEX,   *PEMRSETWINDOWORGEX,
  EMRSETBRUSHORGEX,    *PEMRSETBRUSHORGEX;

typedef struct tagEMRSETVIEWPORTEXTEX
{
    EMR     emr;
    SIZEL   szlExtent;
} EMRSETVIEWPORTEXTEX, *PEMRSETVIEWPORTEXTEX,
  EMRSETWINDOWEXTEX,   *PEMRSETWINDOWEXTEX;

typedef struct tagEMRSCALEVIEWPORTEXTEX
{
    EMR     emr;
    long    xNum;
    long    xDenom;
    long    yNum;
    long    yDenom;
} EMRSCALEVIEWPORTEXTEX, *PEMRSCALEVIEWPORTEXTEX,
  EMRSCALEWINDOWEXTEX,   *PEMRSCALEWINDOWEXTEX;

typedef struct tagEMRSETWORLDTRANSFORM
{
    EMR     emr;
    XFORM   xform;
} EMRSETWORLDTRANSFORM, *PEMRSETWORLDTRANSFORM;

typedef struct tagEMRMODIFYWORLDTRANSFORM
{
    EMR     emr;
    XFORM   xform;
    unsigned long   iMode;
} EMRMODIFYWORLDTRANSFORM, *PEMRMODIFYWORLDTRANSFORM;

typedef struct tagEMRSETPIXELV
{
    EMR     emr;
    POINTL  ptlPixel;
    COLORREF crColor;
} EMRSETPIXELV, *PEMRSETPIXELV;

typedef struct tagEMREXTFLOODFILL
{
    EMR     emr;
    POINTL  ptlStart;
    COLORREF crColor;
    unsigned long   iMode;
} EMREXTFLOODFILL, *PEMREXTFLOODFILL;

typedef struct tagEMRELLIPSE
{
    EMR     emr;
    RECTL   rclBox;             // Inclusive-inclusive bounding rectangle
} EMRELLIPSE,  *PEMRELLIPSE,
  EMRRECTANGLE, *PEMRRECTANGLE;

typedef struct tagEMRROUNDRECT
{
    EMR     emr;
    RECTL   rclBox;             // Inclusive-inclusive bounding rectangle
    SIZEL   szlCorner;
} EMRROUNDRECT, *PEMRROUNDRECT;

typedef struct tagEMRARC
{
    EMR     emr;
    RECTL   rclBox;             // Inclusive-inclusive bounding rectangle
    POINTL  ptlStart;
    POINTL  ptlEnd;
} EMRARC,   *PEMRARC,
  EMRARCTO, *PEMRARCTO,
  EMRCHORD, *PEMRCHORD,
  EMRPIE,   *PEMRPIE;

typedef struct tagEMRANGLEARC
{
    EMR     emr;
    POINTL  ptlCenter;
    unsigned long   nRadius;
    float   eStartAngle;
    float   eSweepAngle;
} EMRANGLEARC, *PEMRANGLEARC;

typedef struct tagEMRPOLYLINE
{
    EMR     emr;
    RECTL   rclBounds;          // Inclusive-inclusive bounds in device units
    unsigned long   cptl;
    POINTL  aptl[1];
} EMRPOLYLINE,     *PEMRPOLYLINE,
  EMRPOLYBEZIER,   *PEMRPOLYBEZIER,
  EMRPOLYGON,      *PEMRPOLYGON,
  EMRPOLYBEZIERTO, *PEMRPOLYBEZIERTO,
  EMRPOLYLINETO,   *PEMRPOLYLINETO;

typedef struct tagEMRPOLYLINE16
{
    EMR     emr;
    RECTL   rclBounds;          // Inclusive-inclusive bounds in device units
    unsigned long   cpts;
    POINTS  apts[1];
} EMRPOLYLINE16,     *PEMRPOLYLINE16,
  EMRPOLYBEZIER16,   *PEMRPOLYBEZIER16,
  EMRPOLYGON16,      *PEMRPOLYGON16,
  EMRPOLYBEZIERTO16, *PEMRPOLYBEZIERTO16,
  EMRPOLYLINETO16,   *PEMRPOLYLINETO16;

typedef struct tagEMRPOLYDRAW
{
    EMR     emr;
    RECTL   rclBounds;          // Inclusive-inclusive bounds in device units
    unsigned long   cptl;               // Number of points
    POINTL  aptl[1];            // Array of points
    BYTE    abTypes[1];         // Array of point types
} EMRPOLYDRAW, *PEMRPOLYDRAW;

typedef struct tagEMRPOLYDRAW16
{
    EMR     emr;
    RECTL   rclBounds;          // Inclusive-inclusive bounds in device units
    unsigned long   cpts;               // Number of points
    POINTS  apts[1];            // Array of points
    BYTE    abTypes[1];         // Array of point types
} EMRPOLYDRAW16, *PEMRPOLYDRAW16;

typedef struct tagEMRPOLYPOLYLINE
{
    EMR     emr;
    RECTL   rclBounds;          // Inclusive-inclusive bounds in device units
    unsigned long   nPolys;             // Number of polys
    unsigned long   cptl;               // Total number of points in all polys
    unsigned long   aPolyCounts[1];     // Array of point counts for each poly
    POINTL  aptl[1];            // Array of points
} EMRPOLYPOLYLINE, *PEMRPOLYPOLYLINE,
  EMRPOLYPOLYGON,  *PEMRPOLYPOLYGON;

typedef struct tagEMRPOLYPOLYLINE16
{
    EMR     emr;
    RECTL   rclBounds;          // Inclusive-inclusive bounds in device units
    unsigned long   nPolys;             // Number of polys
    unsigned long   cpts;               // Total number of points in all polys
    unsigned long   aPolyCounts[1];     // Array of point counts for each poly
    POINTS  apts[1];            // Array of points
} EMRPOLYPOLYLINE16, *PEMRPOLYPOLYLINE16,
  EMRPOLYPOLYGON16,  *PEMRPOLYPOLYGON16;

typedef struct tagEMRINVERTRGN
{
    EMR     emr;
    RECTL   rclBounds;          // Inclusive-inclusive bounds in device units
    unsigned long   cbRgnData;          // Size of region data in bytes
    BYTE    RgnData[1];
} EMRINVERTRGN, *PEMRINVERTRGN,
  EMRPAINTRGN,  *PEMRPAINTRGN;

typedef struct tagEMRFILLRGN
{
    EMR     emr;
    RECTL   rclBounds;          // Inclusive-inclusive bounds in device units
    unsigned long   cbRgnData;          // Size of region data in bytes
    unsigned long   ihBrush;            // Brush handle index
    BYTE    RgnData[1];
} EMRFILLRGN, *PEMRFILLRGN;

typedef struct tagEMRFRAMERGN
{
    EMR     emr;
    RECTL   rclBounds;          // Inclusive-inclusive bounds in device units
    unsigned long   cbRgnData;          // Size of region data in bytes
    unsigned long   ihBrush;            // Brush handle index
    SIZEL   szlStroke;
    BYTE    RgnData[1];
} EMRFRAMERGN, *PEMRFRAMERGN;

typedef struct tagEMREXTSELECTCLIPRGN
{
    EMR     emr;
    unsigned long   cbRgnData;          // Size of region data in bytes
    unsigned long   iMode;
    BYTE    RgnData[1];
} EMREXTSELECTCLIPRGN, *PEMREXTSELECTCLIPRGN;

typedef struct tagEMREXTTEXTOUTA
{
    EMR     emr;
    RECTL   rclBounds;          // Inclusive-inclusive bounds in device units
    unsigned long   iGraphicsMode;      // Current graphics mode
    float   exScale;            // X and Y scales from Page units to .01mm units
    float   eyScale;            //   if graphics mode is GM_COMPATIBLE.
    EMRTEXT emrtext;            // This is followed by the string and spacing
                                // array
} EMREXTTEXTOUTA, *PEMREXTTEXTOUTA,
  EMREXTTEXTOUTW, *PEMREXTTEXTOUTW;

typedef struct tagEMRPOLYTEXTOUTA
{
    EMR     emr;
    RECTL   rclBounds;          // Inclusive-inclusive bounds in device units
    unsigned long   iGraphicsMode;      // Current graphics mode
    float   exScale;            // X and Y scales from Page units to .01mm units
    float   eyScale;            //   if graphics mode is GM_COMPATIBLE.
    long    cStrings;
    EMRTEXT aemrtext[1];        // Array of EMRTEXT structures.  This is
                                // followed by the strings and spacing arrays.
} EMRPOLYTEXTOUTA, *PEMRPOLYTEXTOUTA,
  EMRPOLYTEXTOUTW, *PEMRPOLYTEXTOUTW;

typedef struct tagEMRBITBLT
{
    EMR     emr;
    RECTL   rclBounds;          // Inclusive-inclusive bounds in device units
    long    xDest;
    long    yDest;
    long    cxDest;
    long    cyDest;
    unsigned long   dwRop;
    long    xSrc;
    long    ySrc;
    XFORM   xformSrc;           // Source DC transform
    COLORREF crBkColorSrc;      // Source DC BkColor in RGB
    unsigned long   iUsageSrc;          // Source bitmap info color table usage
                                // (DIB_RGB_COLORS)
    unsigned long   offBmiSrc;          // Offset to the source BITMAPINFO structure
    unsigned long   cbBmiSrc;           // Size of the source BITMAPINFO structure
    unsigned long   offBitsSrc;         // Offset to the source bitmap bits
    unsigned long   cbBitsSrc;          // Size of the source bitmap bits
} EMRBITBLT, *PEMRBITBLT;

typedef struct tagEMRSTRETCHBLT
{
    EMR     emr;
    RECTL   rclBounds;          // Inclusive-inclusive bounds in device units
    long    xDest;
    long    yDest;
    long    cxDest;
    long    cyDest;
    unsigned long   dwRop;
    long    xSrc;
    long    ySrc;
    XFORM   xformSrc;           // Source DC transform
    COLORREF crBkColorSrc;      // Source DC BkColor in RGB
    unsigned long   iUsageSrc;          // Source bitmap info color table usage
                                // (DIB_RGB_COLORS)
    unsigned long   offBmiSrc;          // Offset to the source BITMAPINFO structure
    unsigned long   cbBmiSrc;           // Size of the source BITMAPINFO structure
    unsigned long   offBitsSrc;         // Offset to the source bitmap bits
    unsigned long   cbBitsSrc;          // Size of the source bitmap bits
    long    cxSrc;
    long    cySrc;
} EMRSTRETCHBLT, *PEMRSTRETCHBLT;

typedef struct tagEMRMASKBLT
{
    EMR     emr;
    RECTL   rclBounds;          // Inclusive-inclusive bounds in device units
    long    xDest;
    long    yDest;
    long    cxDest;
    long    cyDest;
    unsigned long   dwRop;
    long    xSrc;
    long    ySrc;
    XFORM   xformSrc;           // Source DC transform
    COLORREF crBkColorSrc;      // Source DC BkColor in RGB
    unsigned long   iUsageSrc;          // Source bitmap info color table usage
                                // (DIB_RGB_COLORS)
    unsigned long   offBmiSrc;          // Offset to the source BITMAPINFO structure
    unsigned long   cbBmiSrc;           // Size of the source BITMAPINFO structure
    unsigned long   offBitsSrc;         // Offset to the source bitmap bits
    unsigned long   cbBitsSrc;          // Size of the source bitmap bits
    long    xMask;
    long    yMask;
    unsigned long   iUsageMask;         // Mask bitmap info color table usage
    unsigned long   offBmiMask;         // Offset to the mask BITMAPINFO structure if any
    unsigned long   cbBmiMask;          // Size of the mask BITMAPINFO structure if any
    unsigned long   offBitsMask;        // Offset to the mask bitmap bits if any
    unsigned long   cbBitsMask;         // Size of the mask bitmap bits if any
} EMRMASKBLT, *PEMRMASKBLT;

typedef struct tagEMRPLGBLT
{
    EMR     emr;
    RECTL   rclBounds;          // Inclusive-inclusive bounds in device units
    POINTL  aptlDest[3];
    long    xSrc;
    long    ySrc;
    long    cxSrc;
    long    cySrc;
    XFORM   xformSrc;           // Source DC transform
    COLORREF crBkColorSrc;      // Source DC BkColor in RGB
    unsigned long   iUsageSrc;          // Source bitmap info color table usage
                                // (DIB_RGB_COLORS)
    unsigned long   offBmiSrc;          // Offset to the source BITMAPINFO structure
    unsigned long   cbBmiSrc;           // Size of the source BITMAPINFO structure
    unsigned long   offBitsSrc;         // Offset to the source bitmap bits
    unsigned long   cbBitsSrc;          // Size of the source bitmap bits
    long    xMask;
    long    yMask;
    unsigned long   iUsageMask;         // Mask bitmap info color table usage
    unsigned long   offBmiMask;         // Offset to the mask BITMAPINFO structure if any
    unsigned long   cbBmiMask;          // Size of the mask BITMAPINFO structure if any
    unsigned long   offBitsMask;        // Offset to the mask bitmap bits if any
    unsigned long   cbBitsMask;         // Size of the mask bitmap bits if any
} EMRPLGBLT, *PEMRPLGBLT;

typedef struct tagEMRSETDIBITSTODEVICE
{
    EMR     emr;
    RECTL   rclBounds;          // Inclusive-inclusive bounds in device units
    long    xDest;
    long    yDest;
    long    xSrc;
    long    ySrc;
    long    cxSrc;
    long    cySrc;
    unsigned long   offBmiSrc;          // Offset to the source BITMAPINFO structure
    unsigned long   cbBmiSrc;           // Size of the source BITMAPINFO structure
    unsigned long   offBitsSrc;         // Offset to the source bitmap bits
    unsigned long   cbBitsSrc;          // Size of the source bitmap bits
    unsigned long   iUsageSrc;          // Source bitmap info color table usage
    unsigned long   iStartScan;
    unsigned long   cScans;
} EMRSETDIBITSTODEVICE, *PEMRSETDIBITSTODEVICE;

typedef struct tagEMRSTRETCHDIBITS
{
    EMR     emr;
    RECTL   rclBounds;          // Inclusive-inclusive bounds in device units
    long    xDest;
    long    yDest;
    long    xSrc;
    long    ySrc;
    long    cxSrc;
    long    cySrc;
    unsigned long   offBmiSrc;          // Offset to the source BITMAPINFO structure
    unsigned long   cbBmiSrc;           // Size of the source BITMAPINFO structure
    unsigned long   offBitsSrc;         // Offset to the source bitmap bits
    unsigned long   cbBitsSrc;          // Size of the source bitmap bits
    unsigned long   iUsageSrc;          // Source bitmap info color table usage
    unsigned long   dwRop;
    long    cxDest;
    long    cyDest;
} EMRSTRETCHDIBITS, *PEMRSTRETCHDIBITS;

typedef struct tagEMREXTCREATEFONTINDIRECTW
{
    EMR     emr;
    unsigned long   ihFont;             // Font handle index
    EXTLOGFONTW elfw;
} EMREXTCREATEFONTINDIRECTW, *PEMREXTCREATEFONTINDIRECTW;

typedef struct tagEMRCREATEPALETTE
{
    EMR     emr;
    unsigned long   ihPal;              // Palette handle index
    LOGPALETTE lgpl;            // The peFlags fields in the palette entries
                                // do not contain any flags
} EMRCREATEPALETTE, *PEMRCREATEPALETTE;

#if(WINVER >= 0x0400)

typedef struct tagEMRCREATECOLORSPACE
{
    EMR             emr;
    unsigned long           ihCS;       // ColorSpace handle index
    LOGCOLORSPACEW  lcs;
} EMRCREATECOLORSPACE, *PEMRCREATECOLORSPACE;

#endif /* WINVER >= 0x0400 */

typedef struct tagEMRCREATEPEN
{
    EMR     emr;
    unsigned long   ihPen;              // Pen handle index
    LOGPEN  lopn;
} EMRCREATEPEN, *PEMRCREATEPEN;

typedef struct tagEMREXTCREATEPEN
{
    EMR     emr;
    unsigned long   ihPen;              // Pen handle index
    unsigned long   offBmi;             // Offset to the BITMAPINFO structure if any
    unsigned long   cbBmi;              // Size of the BITMAPINFO structure if any
                                // The bitmap info is followed by the bitmap
                                // bits to form a packed DIB.
    unsigned long   offBits;            // Offset to the brush bitmap bits if any
    unsigned long   cbBits;             // Size of the brush bitmap bits if any
    EXTLOGPEN elp;              // The extended pen with the style array.
} EMREXTCREATEPEN, *PEMREXTCREATEPEN;

typedef struct tagEMRCREATEBRUSHINDIRECT
{
    EMR     emr;
    unsigned long   ihBrush;            // Brush handle index
    LOGBRUSH lb;                // The style must be BS_SOLID, BS_HOLLOW,
                                // BS_NULL or BS_HATCHED.
} EMRCREATEBRUSHINDIRECT, *PEMRCREATEBRUSHINDIRECT;

typedef struct tagEMRCREATEMONOBRUSH
{
    EMR     emr;
    unsigned long   ihBrush;            // Brush handle index
    unsigned long   iUsage;             // Bitmap info color table usage
    unsigned long   offBmi;             // Offset to the BITMAPINFO structure
    unsigned long   cbBmi;              // Size of the BITMAPINFO structure
    unsigned long   offBits;            // Offset to the bitmap bits
    unsigned long   cbBits;             // Size of the bitmap bits
} EMRCREATEMONOBRUSH, *PEMRCREATEMONOBRUSH;

typedef struct tagEMRCREATEDIBPATTERNBRUSHPT
{
    EMR     emr;
    unsigned long   ihBrush;            // Brush handle index
    unsigned long   iUsage;             // Bitmap info color table usage
    unsigned long   offBmi;             // Offset to the BITMAPINFO structure
    unsigned long   cbBmi;              // Size of the BITMAPINFO structure
                                // The bitmap info is followed by the bitmap
                                // bits to form a packed DIB.
    unsigned long   offBits;            // Offset to the bitmap bits
    unsigned long   cbBits;             // Size of the bitmap bits
} EMRCREATEDIBPATTERNBRUSHPT, *PEMRCREATEDIBPATTERNBRUSHPT;

typedef struct tagEMRFORMAT
{
    unsigned long   dSignature;         // Format signature, e.g. ENHMETA_SIGNATURE.
    unsigned long   nVersion;           // Format version number.
    unsigned long   cbData;             // Size of data in bytes.
    unsigned long   offData;            // Offset to data from GDICOMMENT_IDENTIFIER.
                                // It must begin at a unsigned long offset.
} EMRFORMAT, *PEMRFORMAT;

typedef struct tagEMRGLSRECORD
{
    EMR     emr;
    unsigned long   cbData;             // Size of data in bytes
    BYTE    Data[1];
} EMRGLSRECORD, *PEMRGLSRECORD;

typedef struct tagEMRGLSBOUNDEDRECORD
{
    EMR     emr;
    RECTL   rclBounds;          // Bounds in recording coordinates
    unsigned long   cbData;             // Size of data in bytes
    BYTE    Data[1];
} EMRGLSBOUNDEDRECORD, *PEMRGLSBOUNDEDRECORD;

typedef struct tagEMRPIXELFORMAT
{
    EMR     emr;
    PIXELFORMATDESCRIPTOR pfd;
} EMRPIXELFORMAT, *PEMRPIXELFORMAT;

#define GDICOMMENT_IDENTIFIER           0x43494447
#define GDICOMMENT_WINDOWS_METAFILE     0x80000001
#define GDICOMMENT_BEGINGROUP           0x00000002
#define GDICOMMENT_ENDGROUP             0x00000003
#define GDICOMMENT_MULTIFORMATS         0x40000004
#define EPS_SIGNATURE                   0x46535045

#endif  /* NOMETAFILE */


// OpenGL wgl prototypes

/*WINGDIAPI*/ BOOL  __stdcall wglCopyContext(HGLRC, HGLRC, unsigned);
/*WINGDIAPI*/ HGLRC __stdcall wglCreateContext(HDC);
/*WINGDIAPI*/ HGLRC __stdcall wglCreateLayerContext(HDC, int);
/*WINGDIAPI*/ BOOL  __stdcall wglDeleteContext(HGLRC);
/*WINGDIAPI*/ HGLRC __stdcall wglGetCurrentContext(void);
/*WINGDIAPI*/ HDC   __stdcall wglGetCurrentDC(void);
/*WINGDIAPI*/ PROC  __stdcall wglGetProcAddress(const char*);
/*WINGDIAPI*/ BOOL  __stdcall wglMakeCurrent(HDC, HGLRC);
/*WINGDIAPI*/ BOOL  __stdcall wglShareLists(HGLRC, HGLRC);
/*WINGDIAPI*/ BOOL  __stdcall wglUseFontBitmapsA(HDC, unsigned long, unsigned long, unsigned long);
/*WINGDIAPI*/ BOOL  __stdcall wglUseFontBitmapsW(HDC, unsigned long, unsigned long, unsigned long);
#ifdef UNICODE
#define wglUseFontBitmaps  wglUseFontBitmapsW
#else
#define wglUseFontBitmaps  wglUseFontBitmapsA
#endif // !UNICODE
/*WINGDIAPI*/ BOOL  __stdcall SwapBuffers(HDC);

typedef struct _POINTFLOAT {
    float   x;
    float   y;
} POINTFLOAT, *PPOINTFLOAT;

typedef struct _GLYPHMETRICSFLOAT {
    float       gmfBlackBoxX;
    float       gmfBlackBoxY;
    POINTFLOAT  gmfptGlyphOrigin;
    float       gmfCellIncX;
    float       gmfCellIncY;
} GLYPHMETRICSFLOAT, *PGLYPHMETRICSFLOAT,  *LPGLYPHMETRICSFLOAT;

#define WGL_FONT_LINES      0
#define WGL_FONT_POLYGONS   1
/*WINGDIAPI*/ BOOL  __stdcall wglUseFontOutlinesA(HDC, unsigned long, unsigned long, unsigned long, float,
                                           float, int, LPGLYPHMETRICSFLOAT);
/*WINGDIAPI*/ BOOL  __stdcall wglUseFontOutlinesW(HDC, unsigned long, unsigned long, unsigned long, float,
                                           float, int, LPGLYPHMETRICSFLOAT);
#ifdef UNICODE
#define wglUseFontOutlines  wglUseFontOutlinesW
#else
#define wglUseFontOutlines  wglUseFontOutlinesA
#endif // !UNICODE

/* Layer plane descriptor */
typedef struct tagLAYERPLANEDESCRIPTOR { // lpd
    WORD  nSize;
    WORD  nVersion;
    unsigned long dwFlags;
    BYTE  iPixelType;
    BYTE  cColorBits;
    BYTE  cRedBits;
    BYTE  cRedShift;
    BYTE  cGreenBits;
    BYTE  cGreenShift;
    BYTE  cBlueBits;
    BYTE  cBlueShift;
    BYTE  cAlphaBits;
    BYTE  cAlphaShift;
    BYTE  cAccumBits;
    BYTE  cAccumRedBits;
    BYTE  cAccumGreenBits;
    BYTE  cAccumBlueBits;
    BYTE  cAccumAlphaBits;
    BYTE  cDepthBits;
    BYTE  cStencilBits;
    BYTE  cAuxBuffers;
    BYTE  iLayerPlane;
    BYTE  bReserved;
    COLORREF crTransparent;
} LAYERPLANEDESCRIPTOR, *PLAYERPLANEDESCRIPTOR,  *LPLAYERPLANEDESCRIPTOR;

/* LAYERPLANEDESCRIPTOR flags */
#define LPD_DOUBLEBUFFER        0x00000001
#define LPD_STEREO              0x00000002
#define LPD_SUPPORT_GDI         0x00000010
#define LPD_SUPPORT_OPENGL      0x00000020
#define LPD_SHARE_DEPTH         0x00000040
#define LPD_SHARE_STENCIL       0x00000080
#define LPD_SHARE_ACCUM         0x00000100
#define LPD_SWAP_EXCHANGE       0x00000200
#define LPD_SWAP_COPY           0x00000400
#define LPD_TRANSPARENT         0x00001000

#define LPD_TYPE_RGBA        0
#define LPD_TYPE_COLORINDEX  1

/* wglSwapLayerBuffers flags */
#define WGL_SWAP_MAIN_PLANE     0x00000001
#define WGL_SWAP_OVERLAY1       0x00000002
#define WGL_SWAP_OVERLAY2       0x00000004
#define WGL_SWAP_OVERLAY3       0x00000008
#define WGL_SWAP_OVERLAY4       0x00000010
#define WGL_SWAP_OVERLAY5       0x00000020
#define WGL_SWAP_OVERLAY6       0x00000040
#define WGL_SWAP_OVERLAY7       0x00000080
#define WGL_SWAP_OVERLAY8       0x00000100
#define WGL_SWAP_OVERLAY9       0x00000200
#define WGL_SWAP_OVERLAY10      0x00000400
#define WGL_SWAP_OVERLAY11      0x00000800
#define WGL_SWAP_OVERLAY12      0x00001000
#define WGL_SWAP_OVERLAY13      0x00002000
#define WGL_SWAP_OVERLAY14      0x00004000
#define WGL_SWAP_OVERLAY15      0x00008000
#define WGL_SWAP_UNDERLAY1      0x00010000
#define WGL_SWAP_UNDERLAY2      0x00020000
#define WGL_SWAP_UNDERLAY3      0x00040000
#define WGL_SWAP_UNDERLAY4      0x00080000
#define WGL_SWAP_UNDERLAY5      0x00100000
#define WGL_SWAP_UNDERLAY6      0x00200000
#define WGL_SWAP_UNDERLAY7      0x00400000
#define WGL_SWAP_UNDERLAY8      0x00800000
#define WGL_SWAP_UNDERLAY9      0x01000000
#define WGL_SWAP_UNDERLAY10     0x02000000
#define WGL_SWAP_UNDERLAY11     0x04000000
#define WGL_SWAP_UNDERLAY12     0x08000000
#define WGL_SWAP_UNDERLAY13     0x10000000
#define WGL_SWAP_UNDERLAY14     0x20000000
#define WGL_SWAP_UNDERLAY15     0x40000000

/*WINGDIAPI*/ BOOL __stdcall wglDescribeLayerPlane(HDC, int, int, unsigned,
                                            LPLAYERPLANEDESCRIPTOR);
/*WINGDIAPI*/ int  __stdcall wglSetLayerPaletteEntries(HDC, int, int, int,
                                                const COLORREF *);
/*WINGDIAPI*/ int  __stdcall wglGetLayerPaletteEntries(HDC, int, int, int,
                                                COLORREF *);
/*WINGDIAPI*/ BOOL __stdcall wglRealizeLayerPalette(HDC, int, BOOL);
/*WINGDIAPI*/ BOOL __stdcall wglSwapLayerBuffers(HDC, unsigned);

#endif /* NOGDI */

#ifdef __cplusplus
}
#endif




#endif /* _WINGDI_ */
#pragma once 
