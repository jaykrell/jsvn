/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Wed Jun 26 18:29:25 1996
 */
/* Compiler settings for hlink.idl:
    Oi (OptLev=i0), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __hlink_h__
#define __hlink_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IHlink_FWD_DEFINED__
#define __IHlink_FWD_DEFINED__
typedef interface IHlink IHlink;
#endif 	/* __IHlink_FWD_DEFINED__ */


#ifndef __IHlinkSite_FWD_DEFINED__
#define __IHlinkSite_FWD_DEFINED__
typedef interface IHlinkSite IHlinkSite;
#endif 	/* __IHlinkSite_FWD_DEFINED__ */


#ifndef __IHlinkTarget_FWD_DEFINED__
#define __IHlinkTarget_FWD_DEFINED__
typedef interface IHlinkTarget IHlinkTarget;
#endif 	/* __IHlinkTarget_FWD_DEFINED__ */


#ifndef __IHlinkFrame_FWD_DEFINED__
#define __IHlinkFrame_FWD_DEFINED__
typedef interface IHlinkFrame IHlinkFrame;
#endif 	/* __IHlinkFrame_FWD_DEFINED__ */


#ifndef __IEnumHLITEM_FWD_DEFINED__
#define __IEnumHLITEM_FWD_DEFINED__
typedef interface IEnumHLITEM IEnumHLITEM;
#endif 	/* __IEnumHLITEM_FWD_DEFINED__ */


#ifndef __IHlinkBrowseContext_FWD_DEFINED__
#define __IHlinkBrowseContext_FWD_DEFINED__
typedef interface IHlinkBrowseContext IHlinkBrowseContext;
#endif 	/* __IHlinkBrowseContext_FWD_DEFINED__ */


/* header files for imported files */
#include "urlmon.h"

void  * __stdcall MIDL_user_allocate(size_t);
void __stdcall MIDL_user_free( void  * ); 

/****************************************
 * Generated header for interface: __MIDL__intf_0000
 * at Wed Jun 26 18:29:25 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


//=--------------------------------------------------------------------------=
// HLInk.h
//=--------------------------------------------------------------------------=
// (C) Copyright 1995-1996 Microsoft Corporation.  All Rights Reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//=--------------------------------------------------------------------------=

#pragma comment(lib,"uuid.lib")

//--------------------------------------------------------------------------
// OLE Hyperlinking Interfaces.

#ifndef HLINK_H
#define HLINK_H






// We temporarily support the old 'source' names
#define SID_SHlinkFrame IID_IHlinkFrame
#define IID_IHlinkSource IID_IHlinkTarget
#define IHlinkSource IHlinkTarget
#define IHlinkSourceVtbl IHlinkTargetVtbl
#define LPHLINKSOURCE LPHLINKTARGET

/****************************************************************************/
/**** Error codes                                                        ****/
/****************************************************************************/
#ifndef _HLINK_ERRORS_DEFINED
#define _HLINK_ERRORS_DEFINED
#define HLINK_E_FIRST                    (OLE_E_LAST+1)
#define HLINK_S_FIRST                    (OLE_S_LAST+1)
#define HLINK_S_DONTHIDE                 (HLINK_S_FIRST)
#endif //_HLINK_ERRORS_DEFINED


/****************************************************************************/
/**** Hyperlink APIs                                                     ****/
/****************************************************************************/

#if MAC || defined(_MAC)
#define  cfHyperlink   'HLNK'
#else
#define CFSTR_HYPERLINK         (TEXT("Hyperlink"))
#endif


STDAPI HlinkCreateFromMoniker(
             IMoniker * pimkTrgt,
             const wchar_t* pwzLocation,
             const wchar_t* pwzFriendlyName,
             IHlinkSite * pihlsite,
             unsigned long dwSiteData,
             IUnknown * piunkOuter,
             REFIID riid,
             void ** ppvObj);

STDAPI HlinkCreateFromString(
             const wchar_t* pwzTarget,
             const wchar_t* pwzLocation,
             const wchar_t* pwzFriendlyName,
             IHlinkSite * pihlsite,
             unsigned long dwSiteData,
             IUnknown * piunkOuter,
             REFIID riid,
             void ** ppvObj);

STDAPI HlinkCreateFromData(
             IDataObject *piDataObj,
             IHlinkSite * pihlsite,
             unsigned long dwSiteData,
             IUnknown * piunkOuter,
             REFIID riid,
             void ** ppvObj);

STDAPI HlinkQueryCreateFromData(IDataObject *piDataObj);

STDAPI HlinkClone(
             IHlink * pihl,
             REFIID riid,
             IHlinkSite * pihlsiteForClone,
             unsigned long dwSiteData,
             void ** ppvObj);

STDAPI HlinkCreateBrowseContext(
             IUnknown * piunkOuter,
             REFIID riid,
             void ** ppvObj);

STDAPI HlinkNavigateToStringReference(
             const wchar_t* pwzTarget,
             const wchar_t* pwzLocation,
             IHlinkSite * pihlsite,
             unsigned long dwSiteData,
             IHlinkFrame *pihlframe,
             unsigned long grfHLNF,
             LPBC pibc,
             IBindStatusCallback * pibsc,
             IHlinkBrowseContext *pihlbc);

STDAPI HlinkNavigate(
             IHlink * pihl,
             IHlinkFrame * pihlframe,
             unsigned long grfHLNF,
             LPBC pbc,
             IBindStatusCallback * pibsc,
             IHlinkBrowseContext *pihlbc);

STDAPI HlinkOnNavigate(
             IHlinkFrame * pihlframe,
             IHlinkBrowseContext * pihlbc,
             unsigned long grfHLNF,
             IMoniker * pimkTarget,
             const wchar_t* pwzLocation,
             const wchar_t* pwzFriendlyName,
             unsigned long * puHLID);

STDAPI HlinkUpdateStackItem(
             IHlinkFrame * pihlframe,
             IHlinkBrowseContext * pihlbc,
             unsigned long uHLID,
             IMoniker * pimkTrgt,
             const wchar_t* pwzLocation,
             const wchar_t* pwzFriendlyName);

STDAPI HlinkResolveMonikerForData(
             LPMONIKER pimkReference,
             unsigned long reserved,
             LPBC pibc,
             unsigned long cFmtetc,
             FORMATETC * rgFmtetc,
             IBindStatusCallback * pibsc,
             LPMONIKER pimkBase);

STDAPI HlinkResolveStringForData(
             const wchar_t* pwzReference,
             unsigned long reserved,
             LPBC pibc,
             unsigned long cFmtetc,
             FORMATETC * rgFmtetc,
             IBindStatusCallback * pibsc,
             LPMONIKER pimkBase);

STDAPI HlinkParseDisplayName(
             LPBC pibc,
             const wchar_t* pwzDisplayName,
             BOOL fNoForceAbs,
             unsigned long * pcchEaten,
             IMoniker ** ppimk);

STDAPI HlinkCreateExtensionServices(
             const wchar_t* pwzAdditionalHeaders,
             HWND phwnd,
             const wchar_t* pszUsername,
             const wchar_t* pszPassword,
             IUnknown * piunkOuter,
             REFIID riid,
             void ** ppvObj);

STDAPI OleSaveToStreamEx(
             IUnknown * piunk,
             IStream * pistm,
             BOOL fClearDirty);

typedef 
enum _HLSR
    {	HLSR_HOME	= 0,
	HLSR_SEARCHPAGE	= 1,
	HLSR_HISTORYFOLDER	= 2
    }	HLSR;


STDAPI HlinkSetSpecialReference(
             unsigned long uReference,
             const wchar_t* pwzReference);

STDAPI HlinkGetSpecialReference(
             unsigned long uReference,
             wchar_t* *ppwzReference);

typedef 
enum _HLSHORTCUTF
    {	HLSHORTCUTF_DEFAULT	= 0,
	HLSHORTCUTF_DONTACTUALLYCREATE	= 0x1
    }	HLSHORTCUTF;


STDAPI HlinkCreateShortcut(
             unsigned long grfHLSHORTCUTF,
             IHlink *pihl,
             const wchar_t* pwzDir,
             const wchar_t* pwzFileName,
             wchar_t* *ppwzShortcutFile,
             unsigned long dwReserved);

STDAPI HlinkCreateShortcutFromMoniker(
             unsigned long grfHLSHORTCUTF,
             IMoniker *pimkTarget,
             const wchar_t* pwzLocation,
             const wchar_t* pwzDir,
             const wchar_t* pwzFileName,
             wchar_t* *ppwzShortcutFile,
             unsigned long dwReserved);

STDAPI HlinkCreateShortcutFromString(
             unsigned long grfHLSHORTCUTF,
             const wchar_t* pwzTarget,
             const wchar_t* pwzLocation,
             const wchar_t* pwzDir,
             const wchar_t* pwzFileName,
             wchar_t* *ppwzShortcutFile,
             unsigned long dwReserved);

STDAPI HlinkResolveShortcut(
             const wchar_t* pwzShortcutFileName,
             IHlinkSite * pihlsite,
             unsigned long dwSiteData,
             IUnknown * piunkOuter,
             REFIID riid,
             void ** ppvObj);

STDAPI HlinkResolveShortcutToMoniker(
             const wchar_t* pwzShortcutFileName,
             IMoniker **ppimkTarget,
             wchar_t* *ppwzLocation);

STDAPI HlinkResolveShortcutToString(
             const wchar_t* pwzShortcutFileName,
             wchar_t* *ppwzTarget,
             wchar_t* *ppwzLocation);


 STDAPI HlinkIsShortcut(const wchar_t* pwzFileName);


STDAPI HlinkGetValueFromParams(
             const wchar_t* pwzParams,
             const wchar_t* pwzName,
             wchar_t* *ppwzValue);


typedef 
enum _HLTRANSLATEF
    {	HLTRANSLATEF_DEFAULT	= 0,
	HLTRANSLATEF_DONTAPPLYDEFAULTPREFIX	= 0x1
    }	HLTRANSLATEF;


STDAPI HlinkTranslateURL(
             const wchar_t* pwzURL,
             unsigned long grfFlags,
             wchar_t* *ppwzTranslatedURL);



/****************************************************************************/
/**** Hyperlink interface definitions                                    ****/
/****************************************************************************/

#ifndef _LPHLINK_DEFINED
#define _LPHLINK_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_s_ifspec;

#ifndef __IHlink_INTERFACE_DEFINED__
#define __IHlink_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IHlink
 * at Wed Jun 26 18:29:25 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IHlink  *LPHLINK;

typedef /* [public] */ 
enum __MIDL_IHlink_0001
    {	HLNF_INTERNALJUMP	= 0x1,
	HLNF_OPENINNEWWINDOW	= 0x2,
	HLNF_NAVIGATINGBACK	= 0x4,
	HLNF_NAVIGATINGFORWARD	= 0x8,
	HLNF_NAVIGATINGTOSTACKITEM	= 0x10,
	HLNF_CREATENOHISTORY	= 0x20,
	HLNF_HIDENONWEBTOOLBARS	= 0x40,
	HLNF_DONTMERGEUI	= 0x80
    }	HLNF;

typedef /* [public] */ 
enum __MIDL_IHlink_0002
    {	HLINKGETREF_DEFAULT	= 0,
	HLINKGETREF_ABSOLUTE	= 1,
	HLINKGETREF_RELATIVE	= 2
    }	HLINKGETREF;

typedef /* [public] */ 
enum __MIDL_IHlink_0003
    {	HLFNAMEF_DEFAULT	= 0,
	HLFNAMEF_TRYCACHE	= 0x1,
	HLFNAMEF_TRYPRETTYTARGET	= 0x2,
	HLFNAMEF_TRYFULLTARGET	= 0x4,
	HLFNAMEF_TRYWIN95SHORTCUT	= 0x8
    }	HLFNAMEF;

typedef /* [public] */ 
enum __MIDL_IHlink_0004
    {	HLINKMISC_RELATIVE	= 0x1
    }	HLINKMISC;

typedef /* [public] */ 
enum __MIDL_IHlink_0005
    {	HLINKSETF_TARGET	= 1,
	HLINKSETF_LOCATION	= 2
    }	HLINKSETF;


EXTERN_C const IID IID_IHlink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IHlink : public IUnknown
    {
    public:
        virtual HRESULT __stdcall SetHlinkSite( 
            /* [unique][in] */ IHlinkSite  *pihlSite,
            /* [in] */ unsigned long dwSiteData) = 0;
        
        virtual HRESULT __stdcall GetHlinkSite( 
            /* [out] */ IHlinkSite  * *ppihlSite,
            /* [out] */ unsigned long  *pdwSiteData) = 0;
        
        virtual HRESULT __stdcall SetMonikerReference( 
            /* [in] */ unsigned long grfHLSETF,
            /* [unique][in] */ IMoniker  *pimkTarget,
            /* [unique][in] */ const wchar_t* pwzLocation) = 0;
        
        virtual HRESULT __stdcall GetMonikerReference( 
            /* [in] */ unsigned long dwWhichRef,
            /* [out] */ IMoniker  * *ppimkTarget,
            /* [out] */ wchar_t*  *ppwzLocation) = 0;
        
        virtual HRESULT __stdcall SetStringReference( 
            /* [in] */ unsigned long grfHLSETF,
            /* [unique][in] */ const wchar_t* pwzTarget,
            /* [unique][in] */ const wchar_t* pwzLocation) = 0;
        
        virtual HRESULT __stdcall GetStringReference( 
            /* [in] */ unsigned long dwWhichRef,
            /* [out] */ wchar_t*  *ppwzTarget,
            /* [out] */ wchar_t*  *ppwzLocation) = 0;
        
        virtual HRESULT __stdcall SetFriendlyName( 
            /* [unique][in] */ const wchar_t* pwzFriendlyName) = 0;
        
        virtual HRESULT __stdcall GetFriendlyName( 
            /* [in] */ unsigned long grfHLFNAMEF,
            /* [out] */ wchar_t*  *ppwzFriendlyName) = 0;
        
        virtual HRESULT __stdcall SetTargetFrameName( 
            /* [unique][in] */ const wchar_t* pwzTargetFrameName) = 0;
        
        virtual HRESULT __stdcall GetTargetFrameName( 
            /* [out] */ wchar_t*  *ppwzTargetFrameName) = 0;
        
        virtual HRESULT __stdcall GetMiscStatus( 
            /* [out] */ unsigned long  *pdwStatus) = 0;
        
        virtual HRESULT __stdcall Navigate( 
            /* [in] */ unsigned long grfHLNF,
            /* [unique][in] */ LPBC pibc,
            /* [unique][in] */ IBindStatusCallback  *pibsc,
            /* [unique][in] */ IHlinkBrowseContext  *pihlbc) = 0;
        
        virtual HRESULT __stdcall SetAdditionalParams( 
            /* [unique][in] */ const wchar_t* pwzAdditionalParams) = 0;
        
        virtual HRESULT __stdcall GetAdditionalParams( 
            /* [out] */ wchar_t*  *ppwzAdditionalParams) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHlinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IHlink  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IHlink  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IHlink  * This);
        
        HRESULT ( __stdcall  *SetHlinkSite )( 
            IHlink  * This,
            /* [unique][in] */ IHlinkSite  *pihlSite,
            /* [in] */ unsigned long dwSiteData);
        
        HRESULT ( __stdcall  *GetHlinkSite )( 
            IHlink  * This,
            /* [out] */ IHlinkSite  * *ppihlSite,
            /* [out] */ unsigned long  *pdwSiteData);
        
        HRESULT ( __stdcall  *SetMonikerReference )( 
            IHlink  * This,
            /* [in] */ unsigned long grfHLSETF,
            /* [unique][in] */ IMoniker  *pimkTarget,
            /* [unique][in] */ const wchar_t* pwzLocation);
        
        HRESULT ( __stdcall  *GetMonikerReference )( 
            IHlink  * This,
            /* [in] */ unsigned long dwWhichRef,
            /* [out] */ IMoniker  * *ppimkTarget,
            /* [out] */ wchar_t*  *ppwzLocation);
        
        HRESULT ( __stdcall  *SetStringReference )( 
            IHlink  * This,
            /* [in] */ unsigned long grfHLSETF,
            /* [unique][in] */ const wchar_t* pwzTarget,
            /* [unique][in] */ const wchar_t* pwzLocation);
        
        HRESULT ( __stdcall  *GetStringReference )( 
            IHlink  * This,
            /* [in] */ unsigned long dwWhichRef,
            /* [out] */ wchar_t*  *ppwzTarget,
            /* [out] */ wchar_t*  *ppwzLocation);
        
        HRESULT ( __stdcall  *SetFriendlyName )( 
            IHlink  * This,
            /* [unique][in] */ const wchar_t* pwzFriendlyName);
        
        HRESULT ( __stdcall  *GetFriendlyName )( 
            IHlink  * This,
            /* [in] */ unsigned long grfHLFNAMEF,
            /* [out] */ wchar_t*  *ppwzFriendlyName);
        
        HRESULT ( __stdcall  *SetTargetFrameName )( 
            IHlink  * This,
            /* [unique][in] */ const wchar_t* pwzTargetFrameName);
        
        HRESULT ( __stdcall  *GetTargetFrameName )( 
            IHlink  * This,
            /* [out] */ wchar_t*  *ppwzTargetFrameName);
        
        HRESULT ( __stdcall  *GetMiscStatus )( 
            IHlink  * This,
            /* [out] */ unsigned long  *pdwStatus);
        
        HRESULT ( __stdcall  *Navigate )( 
            IHlink  * This,
            /* [in] */ unsigned long grfHLNF,
            /* [unique][in] */ LPBC pibc,
            /* [unique][in] */ IBindStatusCallback  *pibsc,
            /* [unique][in] */ IHlinkBrowseContext  *pihlbc);
        
        HRESULT ( __stdcall  *SetAdditionalParams )( 
            IHlink  * This,
            /* [unique][in] */ const wchar_t* pwzAdditionalParams);
        
        HRESULT ( __stdcall  *GetAdditionalParams )( 
            IHlink  * This,
            /* [out] */ wchar_t*  *ppwzAdditionalParams);
        
        END_INTERFACE
    } IHlinkVtbl;

    interface IHlink
    {
        CONST_VTBL struct IHlinkVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHlink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHlink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHlink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHlink_SetHlinkSite(This,pihlSite,dwSiteData)	\
    (This)->lpVtbl -> SetHlinkSite(This,pihlSite,dwSiteData)

#define IHlink_GetHlinkSite(This,ppihlSite,pdwSiteData)	\
    (This)->lpVtbl -> GetHlinkSite(This,ppihlSite,pdwSiteData)

#define IHlink_SetMonikerReference(This,grfHLSETF,pimkTarget,pwzLocation)	\
    (This)->lpVtbl -> SetMonikerReference(This,grfHLSETF,pimkTarget,pwzLocation)

#define IHlink_GetMonikerReference(This,dwWhichRef,ppimkTarget,ppwzLocation)	\
    (This)->lpVtbl -> GetMonikerReference(This,dwWhichRef,ppimkTarget,ppwzLocation)

#define IHlink_SetStringReference(This,grfHLSETF,pwzTarget,pwzLocation)	\
    (This)->lpVtbl -> SetStringReference(This,grfHLSETF,pwzTarget,pwzLocation)

#define IHlink_GetStringReference(This,dwWhichRef,ppwzTarget,ppwzLocation)	\
    (This)->lpVtbl -> GetStringReference(This,dwWhichRef,ppwzTarget,ppwzLocation)

#define IHlink_SetFriendlyName(This,pwzFriendlyName)	\
    (This)->lpVtbl -> SetFriendlyName(This,pwzFriendlyName)

#define IHlink_GetFriendlyName(This,grfHLFNAMEF,ppwzFriendlyName)	\
    (This)->lpVtbl -> GetFriendlyName(This,grfHLFNAMEF,ppwzFriendlyName)

#define IHlink_SetTargetFrameName(This,pwzTargetFrameName)	\
    (This)->lpVtbl -> SetTargetFrameName(This,pwzTargetFrameName)

#define IHlink_GetTargetFrameName(This,ppwzTargetFrameName)	\
    (This)->lpVtbl -> GetTargetFrameName(This,ppwzTargetFrameName)

#define IHlink_GetMiscStatus(This,pdwStatus)	\
    (This)->lpVtbl -> GetMiscStatus(This,pdwStatus)

#define IHlink_Navigate(This,grfHLNF,pibc,pibsc,pihlbc)	\
    (This)->lpVtbl -> Navigate(This,grfHLNF,pibc,pibsc,pihlbc)

#define IHlink_SetAdditionalParams(This,pwzAdditionalParams)	\
    (This)->lpVtbl -> SetAdditionalParams(This,pwzAdditionalParams)

#define IHlink_GetAdditionalParams(This,ppwzAdditionalParams)	\
    (This)->lpVtbl -> GetAdditionalParams(This,ppwzAdditionalParams)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IHlink_SetHlinkSite_Proxy( 
    IHlink  * This,
    /* [unique][in] */ IHlinkSite  *pihlSite,
    /* [in] */ unsigned long dwSiteData);


void __stdcall IHlink_SetHlinkSite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlink_GetHlinkSite_Proxy( 
    IHlink  * This,
    /* [out] */ IHlinkSite  * *ppihlSite,
    /* [out] */ unsigned long  *pdwSiteData);


void __stdcall IHlink_GetHlinkSite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlink_SetMonikerReference_Proxy( 
    IHlink  * This,
    /* [in] */ unsigned long grfHLSETF,
    /* [unique][in] */ IMoniker  *pimkTarget,
    /* [unique][in] */ const wchar_t* pwzLocation);


void __stdcall IHlink_SetMonikerReference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlink_GetMonikerReference_Proxy( 
    IHlink  * This,
    /* [in] */ unsigned long dwWhichRef,
    /* [out] */ IMoniker  * *ppimkTarget,
    /* [out] */ wchar_t*  *ppwzLocation);


void __stdcall IHlink_GetMonikerReference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlink_SetStringReference_Proxy( 
    IHlink  * This,
    /* [in] */ unsigned long grfHLSETF,
    /* [unique][in] */ const wchar_t* pwzTarget,
    /* [unique][in] */ const wchar_t* pwzLocation);


void __stdcall IHlink_SetStringReference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlink_GetStringReference_Proxy( 
    IHlink  * This,
    /* [in] */ unsigned long dwWhichRef,
    /* [out] */ wchar_t*  *ppwzTarget,
    /* [out] */ wchar_t*  *ppwzLocation);


void __stdcall IHlink_GetStringReference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlink_SetFriendlyName_Proxy( 
    IHlink  * This,
    /* [unique][in] */ const wchar_t* pwzFriendlyName);


void __stdcall IHlink_SetFriendlyName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlink_GetFriendlyName_Proxy( 
    IHlink  * This,
    /* [in] */ unsigned long grfHLFNAMEF,
    /* [out] */ wchar_t*  *ppwzFriendlyName);


void __stdcall IHlink_GetFriendlyName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlink_SetTargetFrameName_Proxy( 
    IHlink  * This,
    /* [unique][in] */ const wchar_t* pwzTargetFrameName);


void __stdcall IHlink_SetTargetFrameName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlink_GetTargetFrameName_Proxy( 
    IHlink  * This,
    /* [out] */ wchar_t*  *ppwzTargetFrameName);


void __stdcall IHlink_GetTargetFrameName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlink_GetMiscStatus_Proxy( 
    IHlink  * This,
    /* [out] */ unsigned long  *pdwStatus);


void __stdcall IHlink_GetMiscStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlink_Navigate_Proxy( 
    IHlink  * This,
    /* [in] */ unsigned long grfHLNF,
    /* [unique][in] */ LPBC pibc,
    /* [unique][in] */ IBindStatusCallback  *pibsc,
    /* [unique][in] */ IHlinkBrowseContext  *pihlbc);


void __stdcall IHlink_Navigate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlink_SetAdditionalParams_Proxy( 
    IHlink  * This,
    /* [unique][in] */ const wchar_t* pwzAdditionalParams);


void __stdcall IHlink_SetAdditionalParams_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlink_GetAdditionalParams_Proxy( 
    IHlink  * This,
    /* [out] */ wchar_t*  *ppwzAdditionalParams);


void __stdcall IHlink_GetAdditionalParams_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IHlink_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0096
 * at Wed Jun 26 18:29:25 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif
#ifndef _LPHLINKSITE_DEFINED
#define _LPHLINKSITE_DEFINED
EXTERN_C const GUID SID_SContainer;


extern RPC_IF_HANDLE __MIDL__intf_0096_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0096_v0_0_s_ifspec;

#ifndef __IHlinkSite_INTERFACE_DEFINED__
#define __IHlinkSite_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IHlinkSite
 * at Wed Jun 26 18:29:25 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IHlinkSite  *LPHLINKSITE;

typedef /* [public] */ 
enum __MIDL_IHlinkSite_0001
    {	HLINKWHICHMK_CONTAINER	= 1,
	HLINKWHICHMK_BASE	= 2
    }	HLINKWHICHMK;


EXTERN_C const IID IID_IHlinkSite;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IHlinkSite : public IUnknown
    {
    public:
        virtual HRESULT __stdcall QueryService( 
            /* [in] */ unsigned long dwSiteData,
            /* [in] */ REFGUID guidService,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown  * *ppiunk) = 0;
        
        virtual HRESULT __stdcall GetMoniker( 
            /* [in] */ unsigned long dwSiteData,
            /* [in] */ unsigned long dwAssign,
            /* [in] */ unsigned long dwWhich,
            /* [out] */ IMoniker  * *ppimk) = 0;
        
        virtual HRESULT __stdcall ReadyToNavigate( 
            /* [in] */ unsigned long dwSiteData,
            /* [in] */ unsigned long dwReserved) = 0;
        
        virtual HRESULT __stdcall OnNavigationComplete( 
            /* [in] */ unsigned long dwSiteData,
            /* [in] */ unsigned long dwreserved,
            /* [in] */ HRESULT hrError,
            /* [in] */ const wchar_t* pwzError) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHlinkSiteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IHlinkSite  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IHlinkSite  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IHlinkSite  * This);
        
        HRESULT ( __stdcall  *QueryService )( 
            IHlinkSite  * This,
            /* [in] */ unsigned long dwSiteData,
            /* [in] */ REFGUID guidService,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown  * *ppiunk);
        
        HRESULT ( __stdcall  *GetMoniker )( 
            IHlinkSite  * This,
            /* [in] */ unsigned long dwSiteData,
            /* [in] */ unsigned long dwAssign,
            /* [in] */ unsigned long dwWhich,
            /* [out] */ IMoniker  * *ppimk);
        
        HRESULT ( __stdcall  *ReadyToNavigate )( 
            IHlinkSite  * This,
            /* [in] */ unsigned long dwSiteData,
            /* [in] */ unsigned long dwReserved);
        
        HRESULT ( __stdcall  *OnNavigationComplete )( 
            IHlinkSite  * This,
            /* [in] */ unsigned long dwSiteData,
            /* [in] */ unsigned long dwreserved,
            /* [in] */ HRESULT hrError,
            /* [in] */ const wchar_t* pwzError);
        
        END_INTERFACE
    } IHlinkSiteVtbl;

    interface IHlinkSite
    {
        CONST_VTBL struct IHlinkSiteVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHlinkSite_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHlinkSite_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHlinkSite_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHlinkSite_QueryService(This,dwSiteData,guidService,riid,ppiunk)	\
    (This)->lpVtbl -> QueryService(This,dwSiteData,guidService,riid,ppiunk)

#define IHlinkSite_GetMoniker(This,dwSiteData,dwAssign,dwWhich,ppimk)	\
    (This)->lpVtbl -> GetMoniker(This,dwSiteData,dwAssign,dwWhich,ppimk)

#define IHlinkSite_ReadyToNavigate(This,dwSiteData,dwReserved)	\
    (This)->lpVtbl -> ReadyToNavigate(This,dwSiteData,dwReserved)

#define IHlinkSite_OnNavigationComplete(This,dwSiteData,dwreserved,hrError,pwzError)	\
    (This)->lpVtbl -> OnNavigationComplete(This,dwSiteData,dwreserved,hrError,pwzError)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IHlinkSite_QueryService_Proxy( 
    IHlinkSite  * This,
    /* [in] */ unsigned long dwSiteData,
    /* [in] */ REFGUID guidService,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown  * *ppiunk);


void __stdcall IHlinkSite_QueryService_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlinkSite_GetMoniker_Proxy( 
    IHlinkSite  * This,
    /* [in] */ unsigned long dwSiteData,
    /* [in] */ unsigned long dwAssign,
    /* [in] */ unsigned long dwWhich,
    /* [out] */ IMoniker  * *ppimk);


void __stdcall IHlinkSite_GetMoniker_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlinkSite_ReadyToNavigate_Proxy( 
    IHlinkSite  * This,
    /* [in] */ unsigned long dwSiteData,
    /* [in] */ unsigned long dwReserved);


void __stdcall IHlinkSite_ReadyToNavigate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlinkSite_OnNavigationComplete_Proxy( 
    IHlinkSite  * This,
    /* [in] */ unsigned long dwSiteData,
    /* [in] */ unsigned long dwreserved,
    /* [in] */ HRESULT hrError,
    /* [in] */ const wchar_t* pwzError);


void __stdcall IHlinkSite_OnNavigationComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IHlinkSite_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0097
 * at Wed Jun 26 18:29:25 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif
#ifndef _LPHLINKTARGET_DEFINED
#define _LPHLINKTARGET_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0097_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0097_v0_0_s_ifspec;

#ifndef __IHlinkTarget_INTERFACE_DEFINED__
#define __IHlinkTarget_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IHlinkTarget
 * at Wed Jun 26 18:29:25 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IHlinkTarget  *LPHLINKTARGET;


EXTERN_C const IID IID_IHlinkTarget;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IHlinkTarget : public IUnknown
    {
    public:
        virtual HRESULT __stdcall SetBrowseContext( 
            /* [unique][in] */ IHlinkBrowseContext  *pihlbc) = 0;
        
        virtual HRESULT __stdcall GetBrowseContext( 
            /* [out] */ IHlinkBrowseContext  * *ppihlbc) = 0;
        
        virtual HRESULT __stdcall Navigate( 
            /* [in] */ unsigned long grfHLNF,
            /* [unique][in] */ const wchar_t* pwzJumpLocation) = 0;
        
        virtual HRESULT __stdcall GetMoniker( 
            /* [unique][in] */ const wchar_t* pwzLocation,
            /* [in] */ unsigned long dwAssign,
            /* [out] */ IMoniker  * *ppimkLocation) = 0;
        
        virtual HRESULT __stdcall GetFriendlyName( 
            /* [unique][in] */ const wchar_t* pwzLocation,
            /* [out] */ wchar_t*  *ppwzFriendlyName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHlinkTargetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IHlinkTarget  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IHlinkTarget  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IHlinkTarget  * This);
        
        HRESULT ( __stdcall  *SetBrowseContext )( 
            IHlinkTarget  * This,
            /* [unique][in] */ IHlinkBrowseContext  *pihlbc);
        
        HRESULT ( __stdcall  *GetBrowseContext )( 
            IHlinkTarget  * This,
            /* [out] */ IHlinkBrowseContext  * *ppihlbc);
        
        HRESULT ( __stdcall  *Navigate )( 
            IHlinkTarget  * This,
            /* [in] */ unsigned long grfHLNF,
            /* [unique][in] */ const wchar_t* pwzJumpLocation);
        
        HRESULT ( __stdcall  *GetMoniker )( 
            IHlinkTarget  * This,
            /* [unique][in] */ const wchar_t* pwzLocation,
            /* [in] */ unsigned long dwAssign,
            /* [out] */ IMoniker  * *ppimkLocation);
        
        HRESULT ( __stdcall  *GetFriendlyName )( 
            IHlinkTarget  * This,
            /* [unique][in] */ const wchar_t* pwzLocation,
            /* [out] */ wchar_t*  *ppwzFriendlyName);
        
        END_INTERFACE
    } IHlinkTargetVtbl;

    interface IHlinkTarget
    {
        CONST_VTBL struct IHlinkTargetVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHlinkTarget_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHlinkTarget_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHlinkTarget_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHlinkTarget_SetBrowseContext(This,pihlbc)	\
    (This)->lpVtbl -> SetBrowseContext(This,pihlbc)

#define IHlinkTarget_GetBrowseContext(This,ppihlbc)	\
    (This)->lpVtbl -> GetBrowseContext(This,ppihlbc)

#define IHlinkTarget_Navigate(This,grfHLNF,pwzJumpLocation)	\
    (This)->lpVtbl -> Navigate(This,grfHLNF,pwzJumpLocation)

#define IHlinkTarget_GetMoniker(This,pwzLocation,dwAssign,ppimkLocation)	\
    (This)->lpVtbl -> GetMoniker(This,pwzLocation,dwAssign,ppimkLocation)

#define IHlinkTarget_GetFriendlyName(This,pwzLocation,ppwzFriendlyName)	\
    (This)->lpVtbl -> GetFriendlyName(This,pwzLocation,ppwzFriendlyName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IHlinkTarget_SetBrowseContext_Proxy( 
    IHlinkTarget  * This,
    /* [unique][in] */ IHlinkBrowseContext  *pihlbc);


void __stdcall IHlinkTarget_SetBrowseContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlinkTarget_GetBrowseContext_Proxy( 
    IHlinkTarget  * This,
    /* [out] */ IHlinkBrowseContext  * *ppihlbc);


void __stdcall IHlinkTarget_GetBrowseContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlinkTarget_Navigate_Proxy( 
    IHlinkTarget  * This,
    /* [in] */ unsigned long grfHLNF,
    /* [unique][in] */ const wchar_t* pwzJumpLocation);


void __stdcall IHlinkTarget_Navigate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlinkTarget_GetMoniker_Proxy( 
    IHlinkTarget  * This,
    /* [unique][in] */ const wchar_t* pwzLocation,
    /* [in] */ unsigned long dwAssign,
    /* [out] */ IMoniker  * *ppimkLocation);


void __stdcall IHlinkTarget_GetMoniker_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlinkTarget_GetFriendlyName_Proxy( 
    IHlinkTarget  * This,
    /* [unique][in] */ const wchar_t* pwzLocation,
    /* [out] */ wchar_t*  *ppwzFriendlyName);


void __stdcall IHlinkTarget_GetFriendlyName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IHlinkTarget_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0098
 * at Wed Jun 26 18:29:25 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif
#ifndef _LPHLINKFRAME_DEFINED
#define _LPHLINKFRAME_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0098_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0098_v0_0_s_ifspec;

#ifndef __IHlinkFrame_INTERFACE_DEFINED__
#define __IHlinkFrame_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IHlinkFrame
 * at Wed Jun 26 18:29:25 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IHlinkFrame  *LPHLINKFRAME;


EXTERN_C const IID IID_IHlinkFrame;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IHlinkFrame : public IUnknown
    {
    public:
        virtual HRESULT __stdcall SetBrowseContext( 
            /* [unique][in] */ IHlinkBrowseContext  *pihlbc) = 0;
        
        virtual HRESULT __stdcall GetBrowseContext( 
            /* [out] */ IHlinkBrowseContext  * *ppihlbc) = 0;
        
        virtual HRESULT __stdcall Navigate( 
            /* [in] */ unsigned long grfHLNF,
            /* [unique][in] */ LPBC pbc,
            /* [unique][in] */ IBindStatusCallback  *pibsc,
            /* [unique][in] */ IHlink  *pihlNavigate) = 0;
        
        virtual HRESULT __stdcall OnNavigate( 
            /* [in] */ unsigned long grfHLNF,
            /* [unique][in] */ IMoniker  *pimkTarget,
            /* [unique][in] */ const wchar_t* pwzLocation,
            /* [unique][in] */ const wchar_t* pwzFriendlyName,
            /* [in] */ unsigned long dwreserved) = 0;
        
        virtual HRESULT __stdcall UpdateHlink( 
            /* [in] */ unsigned long uHLID,
            /* [unique][in] */ IMoniker  *pimkTarget,
            /* [unique][in] */ const wchar_t* pwzLocation,
            /* [unique][in] */ const wchar_t* pwzFriendlyName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHlinkFrameVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IHlinkFrame  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IHlinkFrame  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IHlinkFrame  * This);
        
        HRESULT ( __stdcall  *SetBrowseContext )( 
            IHlinkFrame  * This,
            /* [unique][in] */ IHlinkBrowseContext  *pihlbc);
        
        HRESULT ( __stdcall  *GetBrowseContext )( 
            IHlinkFrame  * This,
            /* [out] */ IHlinkBrowseContext  * *ppihlbc);
        
        HRESULT ( __stdcall  *Navigate )( 
            IHlinkFrame  * This,
            /* [in] */ unsigned long grfHLNF,
            /* [unique][in] */ LPBC pbc,
            /* [unique][in] */ IBindStatusCallback  *pibsc,
            /* [unique][in] */ IHlink  *pihlNavigate);
        
        HRESULT ( __stdcall  *OnNavigate )( 
            IHlinkFrame  * This,
            /* [in] */ unsigned long grfHLNF,
            /* [unique][in] */ IMoniker  *pimkTarget,
            /* [unique][in] */ const wchar_t* pwzLocation,
            /* [unique][in] */ const wchar_t* pwzFriendlyName,
            /* [in] */ unsigned long dwreserved);
        
        HRESULT ( __stdcall  *UpdateHlink )( 
            IHlinkFrame  * This,
            /* [in] */ unsigned long uHLID,
            /* [unique][in] */ IMoniker  *pimkTarget,
            /* [unique][in] */ const wchar_t* pwzLocation,
            /* [unique][in] */ const wchar_t* pwzFriendlyName);
        
        END_INTERFACE
    } IHlinkFrameVtbl;

    interface IHlinkFrame
    {
        CONST_VTBL struct IHlinkFrameVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHlinkFrame_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHlinkFrame_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHlinkFrame_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHlinkFrame_SetBrowseContext(This,pihlbc)	\
    (This)->lpVtbl -> SetBrowseContext(This,pihlbc)

#define IHlinkFrame_GetBrowseContext(This,ppihlbc)	\
    (This)->lpVtbl -> GetBrowseContext(This,ppihlbc)

#define IHlinkFrame_Navigate(This,grfHLNF,pbc,pibsc,pihlNavigate)	\
    (This)->lpVtbl -> Navigate(This,grfHLNF,pbc,pibsc,pihlNavigate)

#define IHlinkFrame_OnNavigate(This,grfHLNF,pimkTarget,pwzLocation,pwzFriendlyName,dwreserved)	\
    (This)->lpVtbl -> OnNavigate(This,grfHLNF,pimkTarget,pwzLocation,pwzFriendlyName,dwreserved)

#define IHlinkFrame_UpdateHlink(This,uHLID,pimkTarget,pwzLocation,pwzFriendlyName)	\
    (This)->lpVtbl -> UpdateHlink(This,uHLID,pimkTarget,pwzLocation,pwzFriendlyName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IHlinkFrame_SetBrowseContext_Proxy( 
    IHlinkFrame  * This,
    /* [unique][in] */ IHlinkBrowseContext  *pihlbc);


void __stdcall IHlinkFrame_SetBrowseContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlinkFrame_GetBrowseContext_Proxy( 
    IHlinkFrame  * This,
    /* [out] */ IHlinkBrowseContext  * *ppihlbc);


void __stdcall IHlinkFrame_GetBrowseContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlinkFrame_Navigate_Proxy( 
    IHlinkFrame  * This,
    /* [in] */ unsigned long grfHLNF,
    /* [unique][in] */ LPBC pbc,
    /* [unique][in] */ IBindStatusCallback  *pibsc,
    /* [unique][in] */ IHlink  *pihlNavigate);


void __stdcall IHlinkFrame_Navigate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlinkFrame_OnNavigate_Proxy( 
    IHlinkFrame  * This,
    /* [in] */ unsigned long grfHLNF,
    /* [unique][in] */ IMoniker  *pimkTarget,
    /* [unique][in] */ const wchar_t* pwzLocation,
    /* [unique][in] */ const wchar_t* pwzFriendlyName,
    /* [in] */ unsigned long dwreserved);


void __stdcall IHlinkFrame_OnNavigate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlinkFrame_UpdateHlink_Proxy( 
    IHlinkFrame  * This,
    /* [in] */ unsigned long uHLID,
    /* [unique][in] */ IMoniker  *pimkTarget,
    /* [unique][in] */ const wchar_t* pwzLocation,
    /* [unique][in] */ const wchar_t* pwzFriendlyName);


void __stdcall IHlinkFrame_UpdateHlink_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IHlinkFrame_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0099
 * at Wed Jun 26 18:29:25 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif
#ifndef _LPENUMHLITEM_DEFINED
#define _LPENUMHLITEM_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0099_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0099_v0_0_s_ifspec;

#ifndef __IEnumHLITEM_INTERFACE_DEFINED__
#define __IEnumHLITEM_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumHLITEM
 * at Wed Jun 26 18:29:25 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef /* [unique] */ IEnumHLITEM  *LPENUMHLITEM;

typedef struct  tagHLITEM
    {
    unsigned long uHLID;
    wchar_t* pwzFriendlyName;
    }	HLITEM;

typedef /* [unique] */ HLITEM  *LPHLITEM;


EXTERN_C const IID IID_IEnumHLITEM;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IEnumHLITEM : public IUnknown
    {
    public:
        virtual HRESULT __stdcall Next( 
            /* [in] */ unsigned long celt,
            /* [out] */ HLITEM  *rgelt,
            /* [out] */ unsigned long  *pceltFetched) = 0;
        
        virtual HRESULT __stdcall Skip( 
            /* [in] */ unsigned long celt) = 0;
        
        virtual HRESULT __stdcall Reset( void) = 0;
        
        virtual HRESULT __stdcall Clone( 
            /* [out] */ IEnumHLITEM  * *ppienumhlitem) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumHLITEMVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IEnumHLITEM  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IEnumHLITEM  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IEnumHLITEM  * This);
        
        HRESULT ( __stdcall  *Next )( 
            IEnumHLITEM  * This,
            /* [in] */ unsigned long celt,
            /* [out] */ HLITEM  *rgelt,
            /* [out] */ unsigned long  *pceltFetched);
        
        HRESULT ( __stdcall  *Skip )( 
            IEnumHLITEM  * This,
            /* [in] */ unsigned long celt);
        
        HRESULT ( __stdcall  *Reset )( 
            IEnumHLITEM  * This);
        
        HRESULT ( __stdcall  *Clone )( 
            IEnumHLITEM  * This,
            /* [out] */ IEnumHLITEM  * *ppienumhlitem);
        
        END_INTERFACE
    } IEnumHLITEMVtbl;

    interface IEnumHLITEM
    {
        CONST_VTBL struct IEnumHLITEMVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumHLITEM_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumHLITEM_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumHLITEM_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumHLITEM_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumHLITEM_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumHLITEM_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumHLITEM_Clone(This,ppienumhlitem)	\
    (This)->lpVtbl -> Clone(This,ppienumhlitem)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IEnumHLITEM_Next_Proxy( 
    IEnumHLITEM  * This,
    /* [in] */ unsigned long celt,
    /* [out] */ HLITEM  *rgelt,
    /* [out] */ unsigned long  *pceltFetched);


void __stdcall IEnumHLITEM_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumHLITEM_Skip_Proxy( 
    IEnumHLITEM  * This,
    /* [in] */ unsigned long celt);


void __stdcall IEnumHLITEM_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumHLITEM_Reset_Proxy( 
    IEnumHLITEM  * This);


void __stdcall IEnumHLITEM_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumHLITEM_Clone_Proxy( 
    IEnumHLITEM  * This,
    /* [out] */ IEnumHLITEM  * *ppienumhlitem);


void __stdcall IEnumHLITEM_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IEnumHLITEM_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0100
 * at Wed Jun 26 18:29:25 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif
#ifndef _LPHLINKBROWSECONTEXT_DEFINED
#define _LPHLINKBROWSECONTEXT_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0100_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0100_v0_0_s_ifspec;

#ifndef __IHlinkBrowseContext_INTERFACE_DEFINED__
#define __IHlinkBrowseContext_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IHlinkBrowseContext
 * at Wed Jun 26 18:29:25 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef /* [unique] */ IHlinkBrowseContext  *LPHLINKBROWSECONTEXT;


enum __MIDL_IHlinkBrowseContext_0001
    {	HLTB_DOCKEDLEFT	= 0,
	HLTB_DOCKEDTOP	= 1,
	HLTB_DOCKEDRIGHT	= 2,
	HLTB_DOCKEDBOTTOM	= 3,
	HLTB_FLOATING	= 4
    };
typedef struct  _tagHLTBINFO
    {
    unsigned long uDockType;
    RECT rcTbPos;
    }	HLTBINFO;


enum __MIDL_IHlinkBrowseContext_0002
    {	HLBWIF_HASFRAMEWNDINFO	= 0x1,
	HLBWIF_HASDOCWNDINFO	= 0x2,
	HLBWIF_FRAMEWNDMAXIMIZED	= 0x4,
	HLBWIF_DOCWNDMAXIMIZED	= 0x8,
	HLBWIF_HASWEBTOOLBARINFO	= 0x10
    };
typedef struct  _tagHLBWINFO
    {
    unsigned long cbSize;
    unsigned long grfHLBWIF;
    RECT rcFramePos;
    RECT rcDocPos;
    HLTBINFO hltbinfo;
    }	HLBWINFO;

typedef /* [unique] */ HLBWINFO  *LPHLBWINFO;


enum __MIDL_IHlinkBrowseContext_0003
    {	HLID_INVALID	= 0,
	HLID_PREVIOUS	= 0xffffffff,
	HLID_NEXT	= 0xfffffffe,
	HLID_CURRENT	= 0xfffffffd,
	HLID_STACKBOTTOM	= 0xfffffffc,
	HLID_STACKTOP	= 0xfffffffb
    };

enum __MIDL_IHlinkBrowseContext_0004
    {	HLQF_ISVALID	= 0x1,
	HLQF_ISCURRENT	= 0x2
    };

EXTERN_C const IID IID_IHlinkBrowseContext;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IHlinkBrowseContext : public IUnknown
    {
    public:
        virtual HRESULT __stdcall Register( 
            /* [in] */ unsigned long reserved,
            /* [unique][in] */ IUnknown  *piunk,
            /* [unique][in] */ IMoniker  *pimk,
            /* [out] */ unsigned long  *pdwRegister) = 0;
        
        virtual HRESULT __stdcall GetObject( 
            /* [unique][in] */ IMoniker  *pimk,
            /* [in] */ BOOL fBindIfRootRegistered,
            /* [out] */ IUnknown  * *ppiunk) = 0;
        
        virtual HRESULT __stdcall Revoke( 
            /* [in] */ unsigned long dwRegister) = 0;
        
        virtual HRESULT __stdcall SetBrowseWindowInfo( 
            /* [unique][in] */ HLBWINFO  *phlbwi) = 0;
        
        virtual HRESULT __stdcall GetBrowseWindowInfo( 
            /* [out] */ HLBWINFO  *phlbwi) = 0;
        
        virtual HRESULT __stdcall SetInitialHlink( 
            /* [unique][in] */ IMoniker  *pimkTarget,
            /* [unique][in] */ const wchar_t* pwzLocation,
            /* [unique][in] */ const wchar_t* pwzFriendlyName) = 0;
        
        virtual HRESULT __stdcall OnNavigateHlink( 
            /* [in] */ unsigned long grfHLNF,
            /* [unique][in] */ IMoniker  *pimkTarget,
            /* [unique][in] */ const wchar_t* pwzLocation,
            /* [unique][in] */ const wchar_t* pwzFriendlyName,
            /* [out] */ unsigned long  *puHLID) = 0;
        
        virtual HRESULT __stdcall UpdateHlink( 
            /* [in] */ unsigned long uHLID,
            /* [unique][in] */ IMoniker  *pimkTarget,
            /* [unique][in] */ const wchar_t* pwzLocation,
            /* [unique][in] */ const wchar_t* pwzFriendlyName) = 0;
        
        virtual HRESULT __stdcall EnumNavigationStack( 
            /* [in] */ unsigned long dwReserved,
            /* [in] */ unsigned long grfHLFNAMEF,
            /* [out] */ IEnumHLITEM  * *ppienumhlitem) = 0;
        
        virtual HRESULT __stdcall QueryHlink( 
            /* [in] */ unsigned long grfHLQF,
            /* [in] */ unsigned long uHLID) = 0;
        
        virtual HRESULT __stdcall GetHlink( 
            /* [in] */ unsigned long uHLID,
            /* [out] */ IHlink  * *ppihl) = 0;
        
        virtual HRESULT __stdcall SetCurrentHlink( 
            /* [in] */ unsigned long uHLID) = 0;
        
        virtual HRESULT __stdcall Clone( 
            /* [unique][in] */ IUnknown  *piunkOuter,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown  * *ppiunkObj) = 0;
        
        virtual HRESULT __stdcall Close( 
            /* [in] */ unsigned long reserved) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHlinkBrowseContextVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IHlinkBrowseContext  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IHlinkBrowseContext  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IHlinkBrowseContext  * This);
        
        HRESULT ( __stdcall  *Register )( 
            IHlinkBrowseContext  * This,
            /* [in] */ unsigned long reserved,
            /* [unique][in] */ IUnknown  *piunk,
            /* [unique][in] */ IMoniker  *pimk,
            /* [out] */ unsigned long  *pdwRegister);
        
        HRESULT ( __stdcall  *GetObject )( 
            IHlinkBrowseContext  * This,
            /* [unique][in] */ IMoniker  *pimk,
            /* [in] */ BOOL fBindIfRootRegistered,
            /* [out] */ IUnknown  * *ppiunk);
        
        HRESULT ( __stdcall  *Revoke )( 
            IHlinkBrowseContext  * This,
            /* [in] */ unsigned long dwRegister);
        
        HRESULT ( __stdcall  *SetBrowseWindowInfo )( 
            IHlinkBrowseContext  * This,
            /* [unique][in] */ HLBWINFO  *phlbwi);
        
        HRESULT ( __stdcall  *GetBrowseWindowInfo )( 
            IHlinkBrowseContext  * This,
            /* [out] */ HLBWINFO  *phlbwi);
        
        HRESULT ( __stdcall  *SetInitialHlink )( 
            IHlinkBrowseContext  * This,
            /* [unique][in] */ IMoniker  *pimkTarget,
            /* [unique][in] */ const wchar_t* pwzLocation,
            /* [unique][in] */ const wchar_t* pwzFriendlyName);
        
        HRESULT ( __stdcall  *OnNavigateHlink )( 
            IHlinkBrowseContext  * This,
            /* [in] */ unsigned long grfHLNF,
            /* [unique][in] */ IMoniker  *pimkTarget,
            /* [unique][in] */ const wchar_t* pwzLocation,
            /* [unique][in] */ const wchar_t* pwzFriendlyName,
            /* [out] */ unsigned long  *puHLID);
        
        HRESULT ( __stdcall  *UpdateHlink )( 
            IHlinkBrowseContext  * This,
            /* [in] */ unsigned long uHLID,
            /* [unique][in] */ IMoniker  *pimkTarget,
            /* [unique][in] */ const wchar_t* pwzLocation,
            /* [unique][in] */ const wchar_t* pwzFriendlyName);
        
        HRESULT ( __stdcall  *EnumNavigationStack )( 
            IHlinkBrowseContext  * This,
            /* [in] */ unsigned long dwReserved,
            /* [in] */ unsigned long grfHLFNAMEF,
            /* [out] */ IEnumHLITEM  * *ppienumhlitem);
        
        HRESULT ( __stdcall  *QueryHlink )( 
            IHlinkBrowseContext  * This,
            /* [in] */ unsigned long grfHLQF,
            /* [in] */ unsigned long uHLID);
        
        HRESULT ( __stdcall  *GetHlink )( 
            IHlinkBrowseContext  * This,
            /* [in] */ unsigned long uHLID,
            /* [out] */ IHlink  * *ppihl);
        
        HRESULT ( __stdcall  *SetCurrentHlink )( 
            IHlinkBrowseContext  * This,
            /* [in] */ unsigned long uHLID);
        
        HRESULT ( __stdcall  *Clone )( 
            IHlinkBrowseContext  * This,
            /* [unique][in] */ IUnknown  *piunkOuter,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ IUnknown  * *ppiunkObj);
        
        HRESULT ( __stdcall  *Close )( 
            IHlinkBrowseContext  * This,
            /* [in] */ unsigned long reserved);
        
        END_INTERFACE
    } IHlinkBrowseContextVtbl;

    interface IHlinkBrowseContext
    {
        CONST_VTBL struct IHlinkBrowseContextVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHlinkBrowseContext_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHlinkBrowseContext_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHlinkBrowseContext_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHlinkBrowseContext_Register(This,reserved,piunk,pimk,pdwRegister)	\
    (This)->lpVtbl -> Register(This,reserved,piunk,pimk,pdwRegister)

#define IHlinkBrowseContext_GetObject(This,pimk,fBindIfRootRegistered,ppiunk)	\
    (This)->lpVtbl -> GetObject(This,pimk,fBindIfRootRegistered,ppiunk)

#define IHlinkBrowseContext_Revoke(This,dwRegister)	\
    (This)->lpVtbl -> Revoke(This,dwRegister)

#define IHlinkBrowseContext_SetBrowseWindowInfo(This,phlbwi)	\
    (This)->lpVtbl -> SetBrowseWindowInfo(This,phlbwi)

#define IHlinkBrowseContext_GetBrowseWindowInfo(This,phlbwi)	\
    (This)->lpVtbl -> GetBrowseWindowInfo(This,phlbwi)

#define IHlinkBrowseContext_SetInitialHlink(This,pimkTarget,pwzLocation,pwzFriendlyName)	\
    (This)->lpVtbl -> SetInitialHlink(This,pimkTarget,pwzLocation,pwzFriendlyName)

#define IHlinkBrowseContext_OnNavigateHlink(This,grfHLNF,pimkTarget,pwzLocation,pwzFriendlyName,puHLID)	\
    (This)->lpVtbl -> OnNavigateHlink(This,grfHLNF,pimkTarget,pwzLocation,pwzFriendlyName,puHLID)

#define IHlinkBrowseContext_UpdateHlink(This,uHLID,pimkTarget,pwzLocation,pwzFriendlyName)	\
    (This)->lpVtbl -> UpdateHlink(This,uHLID,pimkTarget,pwzLocation,pwzFriendlyName)

#define IHlinkBrowseContext_EnumNavigationStack(This,dwReserved,grfHLFNAMEF,ppienumhlitem)	\
    (This)->lpVtbl -> EnumNavigationStack(This,dwReserved,grfHLFNAMEF,ppienumhlitem)

#define IHlinkBrowseContext_QueryHlink(This,grfHLQF,uHLID)	\
    (This)->lpVtbl -> QueryHlink(This,grfHLQF,uHLID)

#define IHlinkBrowseContext_GetHlink(This,uHLID,ppihl)	\
    (This)->lpVtbl -> GetHlink(This,uHLID,ppihl)

#define IHlinkBrowseContext_SetCurrentHlink(This,uHLID)	\
    (This)->lpVtbl -> SetCurrentHlink(This,uHLID)

#define IHlinkBrowseContext_Clone(This,piunkOuter,riid,ppiunkObj)	\
    (This)->lpVtbl -> Clone(This,piunkOuter,riid,ppiunkObj)

#define IHlinkBrowseContext_Close(This,reserved)	\
    (This)->lpVtbl -> Close(This,reserved)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IHlinkBrowseContext_Register_Proxy( 
    IHlinkBrowseContext  * This,
    /* [in] */ unsigned long reserved,
    /* [unique][in] */ IUnknown  *piunk,
    /* [unique][in] */ IMoniker  *pimk,
    /* [out] */ unsigned long  *pdwRegister);


void __stdcall IHlinkBrowseContext_Register_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlinkBrowseContext_GetObject_Proxy( 
    IHlinkBrowseContext  * This,
    /* [unique][in] */ IMoniker  *pimk,
    /* [in] */ BOOL fBindIfRootRegistered,
    /* [out] */ IUnknown  * *ppiunk);


void __stdcall IHlinkBrowseContext_GetObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlinkBrowseContext_Revoke_Proxy( 
    IHlinkBrowseContext  * This,
    /* [in] */ unsigned long dwRegister);


void __stdcall IHlinkBrowseContext_Revoke_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlinkBrowseContext_SetBrowseWindowInfo_Proxy( 
    IHlinkBrowseContext  * This,
    /* [unique][in] */ HLBWINFO  *phlbwi);


void __stdcall IHlinkBrowseContext_SetBrowseWindowInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlinkBrowseContext_GetBrowseWindowInfo_Proxy( 
    IHlinkBrowseContext  * This,
    /* [out] */ HLBWINFO  *phlbwi);


void __stdcall IHlinkBrowseContext_GetBrowseWindowInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlinkBrowseContext_SetInitialHlink_Proxy( 
    IHlinkBrowseContext  * This,
    /* [unique][in] */ IMoniker  *pimkTarget,
    /* [unique][in] */ const wchar_t* pwzLocation,
    /* [unique][in] */ const wchar_t* pwzFriendlyName);


void __stdcall IHlinkBrowseContext_SetInitialHlink_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlinkBrowseContext_OnNavigateHlink_Proxy( 
    IHlinkBrowseContext  * This,
    /* [in] */ unsigned long grfHLNF,
    /* [unique][in] */ IMoniker  *pimkTarget,
    /* [unique][in] */ const wchar_t* pwzLocation,
    /* [unique][in] */ const wchar_t* pwzFriendlyName,
    /* [out] */ unsigned long  *puHLID);


void __stdcall IHlinkBrowseContext_OnNavigateHlink_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlinkBrowseContext_UpdateHlink_Proxy( 
    IHlinkBrowseContext  * This,
    /* [in] */ unsigned long uHLID,
    /* [unique][in] */ IMoniker  *pimkTarget,
    /* [unique][in] */ const wchar_t* pwzLocation,
    /* [unique][in] */ const wchar_t* pwzFriendlyName);


void __stdcall IHlinkBrowseContext_UpdateHlink_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlinkBrowseContext_EnumNavigationStack_Proxy( 
    IHlinkBrowseContext  * This,
    /* [in] */ unsigned long dwReserved,
    /* [in] */ unsigned long grfHLFNAMEF,
    /* [out] */ IEnumHLITEM  * *ppienumhlitem);


void __stdcall IHlinkBrowseContext_EnumNavigationStack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlinkBrowseContext_QueryHlink_Proxy( 
    IHlinkBrowseContext  * This,
    /* [in] */ unsigned long grfHLQF,
    /* [in] */ unsigned long uHLID);


void __stdcall IHlinkBrowseContext_QueryHlink_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlinkBrowseContext_GetHlink_Proxy( 
    IHlinkBrowseContext  * This,
    /* [in] */ unsigned long uHLID,
    /* [out] */ IHlink  * *ppihl);


void __stdcall IHlinkBrowseContext_GetHlink_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlinkBrowseContext_SetCurrentHlink_Proxy( 
    IHlinkBrowseContext  * This,
    /* [in] */ unsigned long uHLID);


void __stdcall IHlinkBrowseContext_SetCurrentHlink_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlinkBrowseContext_Clone_Proxy( 
    IHlinkBrowseContext  * This,
    /* [unique][in] */ IUnknown  *piunkOuter,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown  * *ppiunkObj);


void __stdcall IHlinkBrowseContext_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHlinkBrowseContext_Close_Proxy( 
    IHlinkBrowseContext  * This,
    /* [in] */ unsigned long reserved);


void __stdcall IHlinkBrowseContext_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IHlinkBrowseContext_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0101
 * at Wed Jun 26 18:29:25 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif

#endif // !HLINK_H


extern RPC_IF_HANDLE __MIDL__intf_0101_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0101_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
#pragma once 
