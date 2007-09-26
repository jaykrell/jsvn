//+---------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (C) Microsoft Corporation, 1992-1996.
//
//  File:       OLE2.h
//  Contents:   Main OLE2 header; Defines Linking and Emmebbeding interfaces, and API's.
//              Also includes .h files for the compobj, and oleauto  subcomponents.
//
//----------------------------------------------------------------------------
#if !defined( _OLE2_H_ )
#define _OLE2_H_

// Set packing to 8
#include <pshpack8.h>

// Make 100% sure WIN32 is defined
#ifndef WIN32
#define WIN32    100  // 100 == NT version 1.0
#endif


// SET to remove _export from interface definitions


#include <winerror.h>

#include <objbase.h>
#include <oleauto.h>

// View OBJECT Error Codes

#define E_DRAW                  VIEW_E_DRAW

// IDataObject Error Codes
#define DATA_E_FORMATETC        DV_E_FORMATETC





// Common stuff gleamed from OLE.2,

/* verbs */
#define OLEIVERB_PRIMARY            (0L)
#define OLEIVERB_SHOW               (-1L)
#define OLEIVERB_OPEN               (-2L)
#define OLEIVERB_HIDE               (-3L)
#define OLEIVERB_UIACTIVATE         (-4L)
#define OLEIVERB_INPLACEACTIVATE    (-5L)
#define OLEIVERB_DISCARDUNDOSTATE   (-6L)

// for OleCreateEmbeddingHelper flags; roles in low word; options in high word
#define EMBDHLP_INPROC_HANDLER   0x0000L
#define EMBDHLP_INPROC_SERVER    0x0001L
#define EMBDHLP_CREATENOW    0x00000000L
#define EMBDHLP_DELAYCREATE  0x00010000L

/* extended create function flags */
#define OLECREATE_LEAVERUNNING	0x00000001

/* pull in the MIDL generated header */

#include <oleidl.h>






/****** DV APIs ***********************************************************/


WINOLEAPI CreateDataAdviseHolder(LPDATAADVISEHOLDER * ppDAHolder);







/****** OLE API Prototypes ************************************************/

WINOLEAPI_(unsigned long) OleBuildVersion( VOID );

/* helper functions */
WINOLEAPI ReadClassStg(LPSTORAGE pStg, CLSID * pclsid);
WINOLEAPI WriteClassStg(LPSTORAGE pStg, REFCLSID rclsid);
WINOLEAPI ReadClassStm(LPSTREAM pStm, CLSID * pclsid);
WINOLEAPI WriteClassStm(LPSTREAM pStm, REFCLSID rclsid);
WINOLEAPI WriteFmtUserTypeStg (LPSTORAGE pstg, CLIPFORMAT cf, LPOLESTR lpszUserType);
WINOLEAPI ReadFmtUserTypeStg (LPSTORAGE pstg, CLIPFORMAT * pcf, LPOLESTR * lplpszUserType);


/* init/term */

WINOLEAPI OleInitialize(void* pvReserved);
WINOLEAPI_(void) OleUninitialize(void);


/* APIs to query whether (Embedded/Linked) object can be created from
   the data object */

WINOLEAPI  OleQueryLinkFromData(LPDATAOBJECT pSrcDataObject);
WINOLEAPI  OleQueryCreateFromData(LPDATAOBJECT pSrcDataObject);


/* Object creation APIs */

WINOLEAPI  OleCreate(REFCLSID rclsid, REFIID riid, unsigned long renderopt,
                LPFORMATETC pFormatEtc, LPOLECLIENTSITE pClientSite,
                LPSTORAGE pStg, void* * ppvObj);

WINOLEAPI  OleCreateEx(REFCLSID rclsid, REFIID riid, unsigned long dwFlags,
                unsigned long renderopt, unsigned long cFormats, unsigned long* rgAdvf,
                LPFORMATETC rgFormatEtc, IAdviseSink * lpAdviseSink,
                unsigned long * rgdwConnection, LPOLECLIENTSITE pClientSite,
                LPSTORAGE pStg, void* * ppvObj);

WINOLEAPI  OleCreateFromData(LPDATAOBJECT pSrcDataObj, REFIID riid,
                unsigned long renderopt, LPFORMATETC pFormatEtc,
                LPOLECLIENTSITE pClientSite, LPSTORAGE pStg,
                void* * ppvObj);

WINOLEAPI  OleCreateFromDataEx(LPDATAOBJECT pSrcDataObj, REFIID riid,
                unsigned long dwFlags, unsigned long renderopt, unsigned long cFormats, unsigned long* rgAdvf,
                LPFORMATETC rgFormatEtc, IAdviseSink * lpAdviseSink,
                unsigned long * rgdwConnection, LPOLECLIENTSITE pClientSite,
                LPSTORAGE pStg, void* * ppvObj);

WINOLEAPI  OleCreateLinkFromData(LPDATAOBJECT pSrcDataObj, REFIID riid,
                unsigned long renderopt, LPFORMATETC pFormatEtc,
                LPOLECLIENTSITE pClientSite, LPSTORAGE pStg,
                void* * ppvObj);

WINOLEAPI  OleCreateLinkFromDataEx(LPDATAOBJECT pSrcDataObj, REFIID riid,
                unsigned long dwFlags, unsigned long renderopt, unsigned long cFormats, unsigned long* rgAdvf,
                LPFORMATETC rgFormatEtc, IAdviseSink * lpAdviseSink,
                unsigned long * rgdwConnection, LPOLECLIENTSITE pClientSite,
                LPSTORAGE pStg, void* * ppvObj);

WINOLEAPI  OleCreateStaticFromData(LPDATAOBJECT pSrcDataObj, REFIID iid,
                unsigned long renderopt, LPFORMATETC pFormatEtc,
                LPOLECLIENTSITE pClientSite, LPSTORAGE pStg,
                void* * ppvObj);


WINOLEAPI  OleCreateLink(LPMONIKER pmkLinkSrc, REFIID riid,
            unsigned long renderopt, LPFORMATETC lpFormatEtc,
            LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, void* * ppvObj);

WINOLEAPI  OleCreateLinkEx(LPMONIKER pmkLinkSrc, REFIID riid,
            unsigned long dwFlags, unsigned long renderopt, unsigned long cFormats, unsigned long* rgAdvf,
            LPFORMATETC rgFormatEtc, IAdviseSink * lpAdviseSink,
            unsigned long * rgdwConnection, LPOLECLIENTSITE pClientSite,
            LPSTORAGE pStg, void* * ppvObj);

WINOLEAPI  OleCreateLinkToFile(LPCOLESTR lpszFileName, REFIID riid,
            unsigned long renderopt, LPFORMATETC lpFormatEtc,
            LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, void* * ppvObj);

WINOLEAPI  OleCreateLinkToFileEx(LPCOLESTR lpszFileName, REFIID riid,
            unsigned long dwFlags, unsigned long renderopt, unsigned long cFormats, unsigned long* rgAdvf,
            LPFORMATETC rgFormatEtc, IAdviseSink * lpAdviseSink,
            unsigned long * rgdwConnection, LPOLECLIENTSITE pClientSite,
            LPSTORAGE pStg, void* * ppvObj);

WINOLEAPI  OleCreateFromFile(REFCLSID rclsid, LPCOLESTR lpszFileName, REFIID riid,
            unsigned long renderopt, LPFORMATETC lpFormatEtc,
            LPOLECLIENTSITE pClientSite, LPSTORAGE pStg, void* * ppvObj);

WINOLEAPI  OleCreateFromFileEx(REFCLSID rclsid, LPCOLESTR lpszFileName, REFIID riid,
            unsigned long dwFlags, unsigned long renderopt, unsigned long cFormats, unsigned long* rgAdvf,
            LPFORMATETC rgFormatEtc, IAdviseSink * lpAdviseSink,
            unsigned long * rgdwConnection, LPOLECLIENTSITE pClientSite,
            LPSTORAGE pStg, void* * ppvObj);

WINOLEAPI  OleLoad(LPSTORAGE pStg, REFIID riid, LPOLECLIENTSITE pClientSite,
            void* * ppvObj);

WINOLEAPI  OleSave(LPPERSISTSTORAGE pPS, LPSTORAGE pStg, BOOL fSameAsLoad);

WINOLEAPI  OleLoadFromStream( LPSTREAM pStm, REFIID iidInterface, void* * ppvObj);
WINOLEAPI  OleSaveToStream( LPPERSISTSTREAM pPStm, LPSTREAM pStm );


WINOLEAPI  OleSetContainedObject(LPUNKNOWN pUnknown, BOOL fContained);
WINOLEAPI  OleNoteObjectVisible(LPUNKNOWN pUnknown, BOOL fVisible);


/* Drag/Drop APIs */

WINOLEAPI  RegisterDragDrop(HWND hwnd, LPDROPTARGET pDropTarget);
WINOLEAPI  RevokeDragDrop(HWND hwnd);
WINOLEAPI  DoDragDrop(LPDATAOBJECT pDataObj, LPDROPSOURCE pDropSource,
            unsigned long dwOKEffects, LPDWORD pdwEffect);

/* Clipboard APIs */

WINOLEAPI  OleSetClipboard(LPDATAOBJECT pDataObj);
WINOLEAPI  OleGetClipboard(LPDATAOBJECT * ppDataObj);
WINOLEAPI  OleFlushClipboard(void);
WINOLEAPI  OleIsCurrentClipboard(LPDATAOBJECT pDataObj);


/* InPlace Editing APIs */

WINOLEAPI_(HOLEMENU)   OleCreateMenuDescriptor (HMENU hmenuCombined,
                                LPOLEMENUGROUPWIDTHS lpMenuWidths);
WINOLEAPI              OleSetMenuDescriptor (HOLEMENU holemenu, HWND hwndFrame,
                                HWND hwndActiveObject,
                                LPOLEINPLACEFRAME lpFrame,
                                LPOLEINPLACEACTIVEOBJECT lpActiveObj);
WINOLEAPI              OleDestroyMenuDescriptor (HOLEMENU holemenu);

WINOLEAPI              OleTranslateAccelerator (LPOLEINPLACEFRAME lpFrame,
                            LPOLEINPLACEFRAMEINFO lpFrameInfo, LPMSG lpmsg);


/* Helper APIs */
WINOLEAPI_(HANDLE) OleDuplicateData (HANDLE hSrc, CLIPFORMAT cfFormat,
                        UINT uiFlags);

WINOLEAPI          OleDraw (LPUNKNOWN pUnknown, unsigned long dwAspect, HDC hdcDraw,
                    LPCRECT lprcBounds);

WINOLEAPI          OleRun(LPUNKNOWN pUnknown);
WINOLEAPI_(BOOL)   OleIsRunning(LPOLEOBJECT pObject);
WINOLEAPI          OleLockRunning(LPUNKNOWN pUnknown, BOOL fLock, BOOL fLastUnlockCloses);
WINOLEAPI_(void)   ReleaseStgMedium(LPSTGMEDIUM);
WINOLEAPI          CreateOleAdviseHolder(LPOLEADVISEHOLDER * ppOAHolder);

WINOLEAPI          OleCreateDefaultHandler(REFCLSID clsid, LPUNKNOWN pUnkOuter,
                    REFIID riid, void* * lplpObj);

WINOLEAPI          OleCreateEmbeddingHelper(REFCLSID clsid, LPUNKNOWN pUnkOuter,
                    unsigned long flags, LPCLASSFACTORY pCF,
                                        REFIID riid, void* * lplpObj);

WINOLEAPI_(BOOL)   IsAccelerator(HACCEL hAccel, int cAccelEntries, LPMSG lpMsg,
                                        WORD * lpwCmd);
/* Icon extraction Helper APIs */

WINOLEAPI_(HGLOBAL) OleGetIconOfFile(LPOLESTR lpszPath, BOOL fUseFileAsLabel);

WINOLEAPI_(HGLOBAL) OleGetIconOfClass(REFCLSID rclsid,     LPOLESTR lpszLabel,
                                        BOOL fUseTypeAsLabel);

WINOLEAPI_(HGLOBAL) OleMetafilePictFromIconAndLabel(HICON hIcon, LPOLESTR lpszLabel,
                                        LPOLESTR lpszSourceFile, UINT iIconIndex);



/* Registration Database Helper APIs */

WINOLEAPI                  OleRegGetUserType (REFCLSID clsid, unsigned long dwFormOfType,
                                        LPOLESTR * pszUserType);

WINOLEAPI                  OleRegGetMiscStatus     (REFCLSID clsid, unsigned long dwAspect,
                                        unsigned long * pdwStatus);

WINOLEAPI                  OleRegEnumFormatEtc     (REFCLSID clsid, unsigned long dwDirection,
                                        LPENUMFORMATETC * ppenum);

WINOLEAPI                  OleRegEnumVerbs (REFCLSID clsid, LPENUMOLEVERB * ppenum);





/* OLE 1.0 conversion APIS */

/***** OLE 1.0 OLESTREAM declarations *************************************/

typedef struct _OLESTREAM *  LPOLESTREAM;

typedef struct _OLESTREAMVTBL
{
    unsigned long (__stdcall* Get)(LPOLESTREAM, void *, unsigned long);
    unsigned long (__stdcall* Put)(LPOLESTREAM, const void *, unsigned long);
} OLESTREAMVTBL;
typedef  OLESTREAMVTBL *  LPOLESTREAMVTBL;

typedef struct _OLESTREAM
{
    LPOLESTREAMVTBL lpstbl;
} OLESTREAM;


WINOLEAPI OleConvertOLESTREAMToIStorage
    (LPOLESTREAM                lpolestream,
    LPSTORAGE                   pstg,
    const DVTARGETDEVICE *   ptd);

WINOLEAPI OleConvertIStorageToOLESTREAM
    (LPSTORAGE      pstg,
    LPOLESTREAM     lpolestream);


/* Storage Utility APIs */
WINOLEAPI GetHGlobalFromILockBytes (LPLOCKBYTES plkbyt, HGLOBAL * phglobal);
WINOLEAPI CreateILockBytesOnHGlobal (HGLOBAL hGlobal, BOOL fDeleteOnRelease,
                                    LPLOCKBYTES * pplkbyt);

WINOLEAPI GetHGlobalFromStream (LPSTREAM pstm, HGLOBAL * phglobal);
WINOLEAPI CreateStreamOnHGlobal (HGLOBAL hGlobal, BOOL fDeleteOnRelease,
                                LPSTREAM * ppstm);


/* ConvertTo APIS */

WINOLEAPI OleDoAutoConvert(LPSTORAGE pStg, LPCLSID pClsidNew);
WINOLEAPI OleGetAutoConvert(REFCLSID clsidOld, LPCLSID pClsidNew);
WINOLEAPI OleSetAutoConvert(REFCLSID clsidOld, REFCLSID clsidNew);
WINOLEAPI GetConvertStg(LPSTORAGE pStg);
WINOLEAPI SetConvertStg(LPSTORAGE pStg, BOOL fConvert);


WINOLEAPI OleConvertIStorageToOLESTREAMEx
    (LPSTORAGE          pstg,
                                    // Presentation data to OLESTREAM
     CLIPFORMAT         cfFormat,   //      format
     LONG               lWidth,     //      width
     LONG               lHeight,    //      height
     unsigned long              dwSize,     //      size in bytes
     LPSTGMEDIUM        pmedium,    //      bits
     LPOLESTREAM        polestm);

WINOLEAPI OleConvertOLESTREAMToIStorageEx
    (LPOLESTREAM        polestm,
     LPSTORAGE          pstg,
                                    // Presentation data from OLESTREAM
     CLIPFORMAT *    pcfFormat,  //      format
     LONG *          plwWidth,   //      width
     LONG *          plHeight,   //      height
     unsigned long *         pdwSize,    //      size in bytes
     LPSTGMEDIUM        pmedium);   //      bits

#ifndef RC_INVOKED
#include <poppack.h>
#endif // RC_INVOKED

#endif     // __OLE2_H__

#pragma once 
