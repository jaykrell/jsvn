/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun Jul 07 10:43:37 1996
 */
/* Compiler settings for docobj.idl:
    Oic (OptLev=i1), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __docobj_h__
#define __docobj_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IOleDocument_FWD_DEFINED__
#define __IOleDocument_FWD_DEFINED__
typedef interface IOleDocument IOleDocument;
#endif 	/* __IOleDocument_FWD_DEFINED__ */


#ifndef __IOleDocumentSite_FWD_DEFINED__
#define __IOleDocumentSite_FWD_DEFINED__
typedef interface IOleDocumentSite IOleDocumentSite;
#endif 	/* __IOleDocumentSite_FWD_DEFINED__ */


#ifndef __IOleDocumentView_FWD_DEFINED__
#define __IOleDocumentView_FWD_DEFINED__
typedef interface IOleDocumentView IOleDocumentView;
#endif 	/* __IOleDocumentView_FWD_DEFINED__ */


#ifndef __IEnumOleDocumentViews_FWD_DEFINED__
#define __IEnumOleDocumentViews_FWD_DEFINED__
typedef interface IEnumOleDocumentViews IEnumOleDocumentViews;
#endif 	/* __IEnumOleDocumentViews_FWD_DEFINED__ */


#ifndef __IContinueCallback_FWD_DEFINED__
#define __IContinueCallback_FWD_DEFINED__
typedef interface IContinueCallback IContinueCallback;
#endif 	/* __IContinueCallback_FWD_DEFINED__ */


#ifndef __IPrint_FWD_DEFINED__
#define __IPrint_FWD_DEFINED__
typedef interface IPrint IPrint;
#endif 	/* __IPrint_FWD_DEFINED__ */


#ifndef __IOleCommandTarget_FWD_DEFINED__
#define __IOleCommandTarget_FWD_DEFINED__
typedef interface IOleCommandTarget IOleCommandTarget;
#endif 	/* __IOleCommandTarget_FWD_DEFINED__ */


/* header files for imported files */
#include "ocidl.h"
#include "servprov.h"

void  * __stdcall MIDL_user_allocate(size_t);
void __stdcall MIDL_user_free( void  * ); 

/****************************************
 * Generated header for interface: __MIDL__intf_0000
 * at Sun Jul 07 10:43:37 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


//=--------------------------------------------------------------------------=
// DocObj.h
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
// OLE Document Object Interfaces.








////////////////////////////////////////////////////////////////////////////
//  Interface Definitions
#ifndef _LPOLEDOCUMENT_DEFINED
#define _LPOLEDOCUMENT_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_s_ifspec;

#ifndef __IOleDocument_INTERFACE_DEFINED__
#define __IOleDocument_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOleDocument
 * at Sun Jul 07 10:43:37 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IOleDocument  *LPOLEDOCUMENT;

typedef /* [public] */ 
enum __MIDL_IOleDocument_0001
    {	DOCMISC_CANCREATEMULTIPLEVIEWS	= 1,
	DOCMISC_SUPPORTCOMPLEXRECTANGLES	= 2,
	DOCMISC_CANTOPENEDIT	= 4,
	DOCMISC_NOFILESUPPORT	= 8
    }	DOCMISC;


EXTERN_C const IID IID_IOleDocument;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IOleDocument : public IUnknown
    {
    public:
        virtual HRESULT __stdcall CreateView( 
            /* [unique][in] */ IOleInPlaceSite  *pIPSite,
            /* [unique][in] */ IStream  *pstm,
            /* [in] */ unsigned long dwReserved,
            /* [out] */ IOleDocumentView  * *ppView) = 0;
        
        virtual HRESULT __stdcall GetDocMiscStatus( 
            /* [out] */ unsigned long  *pdwStatus) = 0;
        
        virtual HRESULT __stdcall EnumViews( 
            /* [out] */ IEnumOleDocumentViews  * *ppEnum,
            /* [out] */ IOleDocumentView  * *ppView) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOleDocumentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IOleDocument  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IOleDocument  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IOleDocument  * This);
        
        HRESULT ( __stdcall  *CreateView )( 
            IOleDocument  * This,
            /* [unique][in] */ IOleInPlaceSite  *pIPSite,
            /* [unique][in] */ IStream  *pstm,
            /* [in] */ unsigned long dwReserved,
            /* [out] */ IOleDocumentView  * *ppView);
        
        HRESULT ( __stdcall  *GetDocMiscStatus )( 
            IOleDocument  * This,
            /* [out] */ unsigned long  *pdwStatus);
        
        HRESULT ( __stdcall  *EnumViews )( 
            IOleDocument  * This,
            /* [out] */ IEnumOleDocumentViews  * *ppEnum,
            /* [out] */ IOleDocumentView  * *ppView);
        
        END_INTERFACE
    } IOleDocumentVtbl;

    interface IOleDocument
    {
        CONST_VTBL struct IOleDocumentVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleDocument_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOleDocument_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOleDocument_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOleDocument_CreateView(This,pIPSite,pstm,dwReserved,ppView)	\
    (This)->lpVtbl -> CreateView(This,pIPSite,pstm,dwReserved,ppView)

#define IOleDocument_GetDocMiscStatus(This,pdwStatus)	\
    (This)->lpVtbl -> GetDocMiscStatus(This,pdwStatus)

#define IOleDocument_EnumViews(This,ppEnum,ppView)	\
    (This)->lpVtbl -> EnumViews(This,ppEnum,ppView)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IOleDocument_CreateView_Proxy( 
    IOleDocument  * This,
    /* [unique][in] */ IOleInPlaceSite  *pIPSite,
    /* [unique][in] */ IStream  *pstm,
    /* [in] */ unsigned long dwReserved,
    /* [out] */ IOleDocumentView  * *ppView);


void __stdcall IOleDocument_CreateView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleDocument_GetDocMiscStatus_Proxy( 
    IOleDocument  * This,
    /* [out] */ unsigned long  *pdwStatus);


void __stdcall IOleDocument_GetDocMiscStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleDocument_EnumViews_Proxy( 
    IOleDocument  * This,
    /* [out] */ IEnumOleDocumentViews  * *ppEnum,
    /* [out] */ IOleDocumentView  * *ppView);


void __stdcall IOleDocument_EnumViews_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IOleDocument_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0142
 * at Sun Jul 07 10:43:37 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif
#ifndef _LPOLEDOCUMENTSITE_DEFINED
#define _LPOLEDOCUMENTSITE_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0142_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0142_v0_0_s_ifspec;

#ifndef __IOleDocumentSite_INTERFACE_DEFINED__
#define __IOleDocumentSite_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOleDocumentSite
 * at Sun Jul 07 10:43:37 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IOleDocumentSite  *LPOLEDOCUMENTSITE;


EXTERN_C const IID IID_IOleDocumentSite;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IOleDocumentSite : public IUnknown
    {
    public:
        virtual HRESULT __stdcall ActivateMe( 
            /* [in] */ IOleDocumentView  *pViewToActivate) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOleDocumentSiteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IOleDocumentSite  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IOleDocumentSite  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IOleDocumentSite  * This);
        
        HRESULT ( __stdcall  *ActivateMe )( 
            IOleDocumentSite  * This,
            /* [in] */ IOleDocumentView  *pViewToActivate);
        
        END_INTERFACE
    } IOleDocumentSiteVtbl;

    interface IOleDocumentSite
    {
        CONST_VTBL struct IOleDocumentSiteVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleDocumentSite_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOleDocumentSite_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOleDocumentSite_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOleDocumentSite_ActivateMe(This,pViewToActivate)	\
    (This)->lpVtbl -> ActivateMe(This,pViewToActivate)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IOleDocumentSite_ActivateMe_Proxy( 
    IOleDocumentSite  * This,
    /* [in] */ IOleDocumentView  *pViewToActivate);


void __stdcall IOleDocumentSite_ActivateMe_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IOleDocumentSite_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0143
 * at Sun Jul 07 10:43:37 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif
#ifndef _LPOLEDOCUMENTVIEW_DEFINED
#define _LPOLEDOCUMENTVIEW_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0143_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0143_v0_0_s_ifspec;

#ifndef __IOleDocumentView_INTERFACE_DEFINED__
#define __IOleDocumentView_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOleDocumentView
 * at Sun Jul 07 10:43:37 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IOleDocumentView  *LPOLEDOCUMENTVIEW;


EXTERN_C const IID IID_IOleDocumentView;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IOleDocumentView : public IUnknown
    {
    public:
        virtual HRESULT __stdcall SetInPlaceSite( 
            /* [unique][in] */ IOleInPlaceSite  *pIPSite) = 0;
        
        virtual HRESULT __stdcall GetInPlaceSite( 
            /* [out] */ IOleInPlaceSite  * *ppIPSite) = 0;
        
        virtual HRESULT __stdcall GetDocument( 
            /* [out] */ IUnknown  * *ppunk) = 0;
        
        virtual /* [input_sync] */ HRESULT __stdcall SetRect( 
            /* [in] */ LPRECT prcView) = 0;
        
        virtual HRESULT __stdcall GetRect( 
            /* [out] */ LPRECT prcView) = 0;
        
        virtual /* [input_sync] */ HRESULT __stdcall SetRectComplex( 
            /* [unique][in] */ LPRECT prcView,
            /* [unique][in] */ LPRECT prcHScroll,
            /* [unique][in] */ LPRECT prcVScroll,
            /* [unique][in] */ LPRECT prcSizeBox) = 0;
        
        virtual HRESULT __stdcall Show( 
            /* [in] */ BOOL fShow) = 0;
        
        virtual HRESULT __stdcall UIActivate( 
            /* [in] */ BOOL fUIActivate) = 0;
        
        virtual HRESULT __stdcall Open( void) = 0;
        
        virtual HRESULT __stdcall CloseView( 
            unsigned long dwReserved) = 0;
        
        virtual HRESULT __stdcall SaveViewState( 
            /* [in] */ LPSTREAM pstm) = 0;
        
        virtual HRESULT __stdcall ApplyViewState( 
            /* [in] */ LPSTREAM pstm) = 0;
        
        virtual HRESULT __stdcall Clone( 
            /* [in] */ IOleInPlaceSite  *pIPSiteNew,
            /* [out] */ IOleDocumentView  * *ppViewNew) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOleDocumentViewVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IOleDocumentView  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IOleDocumentView  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IOleDocumentView  * This);
        
        HRESULT ( __stdcall  *SetInPlaceSite )( 
            IOleDocumentView  * This,
            /* [unique][in] */ IOleInPlaceSite  *pIPSite);
        
        HRESULT ( __stdcall  *GetInPlaceSite )( 
            IOleDocumentView  * This,
            /* [out] */ IOleInPlaceSite  * *ppIPSite);
        
        HRESULT ( __stdcall  *GetDocument )( 
            IOleDocumentView  * This,
            /* [out] */ IUnknown  * *ppunk);
        
        /* [input_sync] */ HRESULT ( __stdcall  *SetRect )( 
            IOleDocumentView  * This,
            /* [in] */ LPRECT prcView);
        
        HRESULT ( __stdcall  *GetRect )( 
            IOleDocumentView  * This,
            /* [out] */ LPRECT prcView);
        
        /* [input_sync] */ HRESULT ( __stdcall  *SetRectComplex )( 
            IOleDocumentView  * This,
            /* [unique][in] */ LPRECT prcView,
            /* [unique][in] */ LPRECT prcHScroll,
            /* [unique][in] */ LPRECT prcVScroll,
            /* [unique][in] */ LPRECT prcSizeBox);
        
        HRESULT ( __stdcall  *Show )( 
            IOleDocumentView  * This,
            /* [in] */ BOOL fShow);
        
        HRESULT ( __stdcall  *UIActivate )( 
            IOleDocumentView  * This,
            /* [in] */ BOOL fUIActivate);
        
        HRESULT ( __stdcall  *Open )( 
            IOleDocumentView  * This);
        
        HRESULT ( __stdcall  *CloseView )( 
            IOleDocumentView  * This,
            unsigned long dwReserved);
        
        HRESULT ( __stdcall  *SaveViewState )( 
            IOleDocumentView  * This,
            /* [in] */ LPSTREAM pstm);
        
        HRESULT ( __stdcall  *ApplyViewState )( 
            IOleDocumentView  * This,
            /* [in] */ LPSTREAM pstm);
        
        HRESULT ( __stdcall  *Clone )( 
            IOleDocumentView  * This,
            /* [in] */ IOleInPlaceSite  *pIPSiteNew,
            /* [out] */ IOleDocumentView  * *ppViewNew);
        
        END_INTERFACE
    } IOleDocumentViewVtbl;

    interface IOleDocumentView
    {
        CONST_VTBL struct IOleDocumentViewVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleDocumentView_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOleDocumentView_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOleDocumentView_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOleDocumentView_SetInPlaceSite(This,pIPSite)	\
    (This)->lpVtbl -> SetInPlaceSite(This,pIPSite)

#define IOleDocumentView_GetInPlaceSite(This,ppIPSite)	\
    (This)->lpVtbl -> GetInPlaceSite(This,ppIPSite)

#define IOleDocumentView_GetDocument(This,ppunk)	\
    (This)->lpVtbl -> GetDocument(This,ppunk)

#define IOleDocumentView_SetRect(This,prcView)	\
    (This)->lpVtbl -> SetRect(This,prcView)

#define IOleDocumentView_GetRect(This,prcView)	\
    (This)->lpVtbl -> GetRect(This,prcView)

#define IOleDocumentView_SetRectComplex(This,prcView,prcHScroll,prcVScroll,prcSizeBox)	\
    (This)->lpVtbl -> SetRectComplex(This,prcView,prcHScroll,prcVScroll,prcSizeBox)

#define IOleDocumentView_Show(This,fShow)	\
    (This)->lpVtbl -> Show(This,fShow)

#define IOleDocumentView_UIActivate(This,fUIActivate)	\
    (This)->lpVtbl -> UIActivate(This,fUIActivate)

#define IOleDocumentView_Open(This)	\
    (This)->lpVtbl -> Open(This)

#define IOleDocumentView_CloseView(This,dwReserved)	\
    (This)->lpVtbl -> CloseView(This,dwReserved)

#define IOleDocumentView_SaveViewState(This,pstm)	\
    (This)->lpVtbl -> SaveViewState(This,pstm)

#define IOleDocumentView_ApplyViewState(This,pstm)	\
    (This)->lpVtbl -> ApplyViewState(This,pstm)

#define IOleDocumentView_Clone(This,pIPSiteNew,ppViewNew)	\
    (This)->lpVtbl -> Clone(This,pIPSiteNew,ppViewNew)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IOleDocumentView_SetInPlaceSite_Proxy( 
    IOleDocumentView  * This,
    /* [unique][in] */ IOleInPlaceSite  *pIPSite);


void __stdcall IOleDocumentView_SetInPlaceSite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleDocumentView_GetInPlaceSite_Proxy( 
    IOleDocumentView  * This,
    /* [out] */ IOleInPlaceSite  * *ppIPSite);


void __stdcall IOleDocumentView_GetInPlaceSite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleDocumentView_GetDocument_Proxy( 
    IOleDocumentView  * This,
    /* [out] */ IUnknown  * *ppunk);


void __stdcall IOleDocumentView_GetDocument_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [input_sync] */ HRESULT __stdcall IOleDocumentView_SetRect_Proxy( 
    IOleDocumentView  * This,
    /* [in] */ LPRECT prcView);


void __stdcall IOleDocumentView_SetRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleDocumentView_GetRect_Proxy( 
    IOleDocumentView  * This,
    /* [out] */ LPRECT prcView);


void __stdcall IOleDocumentView_GetRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [input_sync] */ HRESULT __stdcall IOleDocumentView_SetRectComplex_Proxy( 
    IOleDocumentView  * This,
    /* [unique][in] */ LPRECT prcView,
    /* [unique][in] */ LPRECT prcHScroll,
    /* [unique][in] */ LPRECT prcVScroll,
    /* [unique][in] */ LPRECT prcSizeBox);


void __stdcall IOleDocumentView_SetRectComplex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleDocumentView_Show_Proxy( 
    IOleDocumentView  * This,
    /* [in] */ BOOL fShow);


void __stdcall IOleDocumentView_Show_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleDocumentView_UIActivate_Proxy( 
    IOleDocumentView  * This,
    /* [in] */ BOOL fUIActivate);


void __stdcall IOleDocumentView_UIActivate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleDocumentView_Open_Proxy( 
    IOleDocumentView  * This);


void __stdcall IOleDocumentView_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleDocumentView_CloseView_Proxy( 
    IOleDocumentView  * This,
    unsigned long dwReserved);


void __stdcall IOleDocumentView_CloseView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleDocumentView_SaveViewState_Proxy( 
    IOleDocumentView  * This,
    /* [in] */ LPSTREAM pstm);


void __stdcall IOleDocumentView_SaveViewState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleDocumentView_ApplyViewState_Proxy( 
    IOleDocumentView  * This,
    /* [in] */ LPSTREAM pstm);


void __stdcall IOleDocumentView_ApplyViewState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleDocumentView_Clone_Proxy( 
    IOleDocumentView  * This,
    /* [in] */ IOleInPlaceSite  *pIPSiteNew,
    /* [out] */ IOleDocumentView  * *ppViewNew);


void __stdcall IOleDocumentView_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IOleDocumentView_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0144
 * at Sun Jul 07 10:43:37 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif
#ifndef _LPENUMOLEDOCUMENTVIEWS_DEFINED
#define _LPENUMOLEDOCUMENTVIEWS_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0144_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0144_v0_0_s_ifspec;

#ifndef __IEnumOleDocumentViews_INTERFACE_DEFINED__
#define __IEnumOleDocumentViews_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumOleDocumentViews
 * at Sun Jul 07 10:43:37 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IEnumOleDocumentViews  *LPENUMOLEDOCUMENTVIEWS;


EXTERN_C const IID IID_IEnumOleDocumentViews;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IEnumOleDocumentViews : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT __stdcall Next( 
            /* [in] */ unsigned long cViews,
            /* [out] */ IOleDocumentView  * *rgpView,
            /* [out] */ unsigned long  *pcFetched) = 0;
        
        virtual HRESULT __stdcall Skip( 
            /* [in] */ unsigned long cViews) = 0;
        
        virtual HRESULT __stdcall Reset( void) = 0;
        
        virtual HRESULT __stdcall Clone( 
            /* [out] */ IEnumOleDocumentViews  * *ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumOleDocumentViewsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IEnumOleDocumentViews  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IEnumOleDocumentViews  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IEnumOleDocumentViews  * This);
        
        /* [local] */ HRESULT ( __stdcall  *Next )( 
            IEnumOleDocumentViews  * This,
            /* [in] */ unsigned long cViews,
            /* [out] */ IOleDocumentView  * *rgpView,
            /* [out] */ unsigned long  *pcFetched);
        
        HRESULT ( __stdcall  *Skip )( 
            IEnumOleDocumentViews  * This,
            /* [in] */ unsigned long cViews);
        
        HRESULT ( __stdcall  *Reset )( 
            IEnumOleDocumentViews  * This);
        
        HRESULT ( __stdcall  *Clone )( 
            IEnumOleDocumentViews  * This,
            /* [out] */ IEnumOleDocumentViews  * *ppEnum);
        
        END_INTERFACE
    } IEnumOleDocumentViewsVtbl;

    interface IEnumOleDocumentViews
    {
        CONST_VTBL struct IEnumOleDocumentViewsVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumOleDocumentViews_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumOleDocumentViews_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumOleDocumentViews_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumOleDocumentViews_Next(This,cViews,rgpView,pcFetched)	\
    (This)->lpVtbl -> Next(This,cViews,rgpView,pcFetched)

#define IEnumOleDocumentViews_Skip(This,cViews)	\
    (This)->lpVtbl -> Skip(This,cViews)

#define IEnumOleDocumentViews_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumOleDocumentViews_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall IEnumOleDocumentViews_RemoteNext_Proxy( 
    IEnumOleDocumentViews  * This,
    /* [in] */ unsigned long cViews,
    /* [length_is][size_is][out] */ IOleDocumentView  * *rgpView,
    /* [out] */ unsigned long  *pcFetched);


void __stdcall IEnumOleDocumentViews_RemoteNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumOleDocumentViews_Skip_Proxy( 
    IEnumOleDocumentViews  * This,
    /* [in] */ unsigned long cViews);


void __stdcall IEnumOleDocumentViews_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumOleDocumentViews_Reset_Proxy( 
    IEnumOleDocumentViews  * This);


void __stdcall IEnumOleDocumentViews_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumOleDocumentViews_Clone_Proxy( 
    IEnumOleDocumentViews  * This,
    /* [out] */ IEnumOleDocumentViews  * *ppEnum);


void __stdcall IEnumOleDocumentViews_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IEnumOleDocumentViews_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0145
 * at Sun Jul 07 10:43:37 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif
#ifndef _LPCONTINUECALLBACK_DEFINED
#define _LPCONTINUECALLBACK_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0145_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0145_v0_0_s_ifspec;

#ifndef __IContinueCallback_INTERFACE_DEFINED__
#define __IContinueCallback_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IContinueCallback
 * at Sun Jul 07 10:43:37 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IContinueCallback  *LPCONTINUECALLBACK;


EXTERN_C const IID IID_IContinueCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IContinueCallback : public IUnknown
    {
    public:
        virtual HRESULT __stdcall FContinue( void) = 0;
        
        virtual HRESULT __stdcall FContinuePrinting( 
            /* [in] */ long nCntPrinted,
            /* [in] */ long nCurPage,
            /* [unique][in] */ wchar_t  *pwszPrintStatus) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IContinueCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IContinueCallback  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IContinueCallback  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IContinueCallback  * This);
        
        HRESULT ( __stdcall  *FContinue )( 
            IContinueCallback  * This);
        
        HRESULT ( __stdcall  *FContinuePrinting )( 
            IContinueCallback  * This,
            /* [in] */ long nCntPrinted,
            /* [in] */ long nCurPage,
            /* [unique][in] */ wchar_t  *pwszPrintStatus);
        
        END_INTERFACE
    } IContinueCallbackVtbl;

    interface IContinueCallback
    {
        CONST_VTBL struct IContinueCallbackVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IContinueCallback_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IContinueCallback_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IContinueCallback_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IContinueCallback_FContinue(This)	\
    (This)->lpVtbl -> FContinue(This)

#define IContinueCallback_FContinuePrinting(This,nCntPrinted,nCurPage,pwszPrintStatus)	\
    (This)->lpVtbl -> FContinuePrinting(This,nCntPrinted,nCurPage,pwszPrintStatus)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IContinueCallback_FContinue_Proxy( 
    IContinueCallback  * This);


void __stdcall IContinueCallback_FContinue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IContinueCallback_FContinuePrinting_Proxy( 
    IContinueCallback  * This,
    /* [in] */ long nCntPrinted,
    /* [in] */ long nCurPage,
    /* [unique][in] */ wchar_t  *pwszPrintStatus);


void __stdcall IContinueCallback_FContinuePrinting_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IContinueCallback_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0146
 * at Sun Jul 07 10:43:37 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif
#ifndef _LPPRINT_DEFINED
#define _LPPRINT_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0146_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0146_v0_0_s_ifspec;

#ifndef __IPrint_INTERFACE_DEFINED__
#define __IPrint_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPrint
 * at Sun Jul 07 10:43:37 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IPrint  *LPPRINT;

typedef /* [public] */ 
enum __MIDL_IPrint_0001
    {	PRINTFLAG_MAYBOTHERUSER	= 1,
	PRINTFLAG_PROMPTUSER	= 2,
	PRINTFLAG_USERMAYCHANGEPRINTER	= 4,
	PRINTFLAG_RECOMPOSETODEVICE	= 8,
	PRINTFLAG_DONTACTUALLYPRINT	= 16,
	PRINTFLAG_FORCEPROPERTIES	= 32,
	PRINTFLAG_PRINTTOFILE	= 64
    }	PRINTFLAG;

typedef struct  tagPAGERANGE
    {
    long nFromPage;
    long nToPage;
    }	PAGERANGE;

typedef struct  tagPAGESET
    {
    unsigned long cbStruct;
    BOOL fOddPages;
    BOOL fEvenPages;
    unsigned long cPageRange;
    /* [size_is] */ PAGERANGE rgPages[ 1 ];
    }	PAGESET;

#define PAGESET_TOLASTPAGE   ((WORD)(-1L))

EXTERN_C const IID IID_IPrint;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IPrint : public IUnknown
    {
    public:
        virtual HRESULT __stdcall SetInitialPageNum( 
            /* [in] */ long nFirstPage) = 0;
        
        virtual HRESULT __stdcall GetPageInfo( 
            /* [out] */ long  *pnFirstPage,
            /* [out] */ long  *pcPages) = 0;
        
        virtual /* [local] */ HRESULT __stdcall Print( 
            /* [in] */ unsigned long grfFlags,
            /* [out][in] */ DVTARGETDEVICE  * *pptd,
            /* [out][in] */ PAGESET  * *ppPageSet,
            /* [unique][out][in] */ STGMEDIUM  *pstgmOptions,
            /* [in] */ IContinueCallback  *pcallback,
            /* [in] */ long nFirstPage,
            /* [out] */ long  *pcPagesPrinted,
            /* [out] */ long  *pnLastPage) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPrintVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IPrint  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IPrint  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IPrint  * This);
        
        HRESULT ( __stdcall  *SetInitialPageNum )( 
            IPrint  * This,
            /* [in] */ long nFirstPage);
        
        HRESULT ( __stdcall  *GetPageInfo )( 
            IPrint  * This,
            /* [out] */ long  *pnFirstPage,
            /* [out] */ long  *pcPages);
        
        /* [local] */ HRESULT ( __stdcall  *Print )( 
            IPrint  * This,
            /* [in] */ unsigned long grfFlags,
            /* [out][in] */ DVTARGETDEVICE  * *pptd,
            /* [out][in] */ PAGESET  * *ppPageSet,
            /* [unique][out][in] */ STGMEDIUM  *pstgmOptions,
            /* [in] */ IContinueCallback  *pcallback,
            /* [in] */ long nFirstPage,
            /* [out] */ long  *pcPagesPrinted,
            /* [out] */ long  *pnLastPage);
        
        END_INTERFACE
    } IPrintVtbl;

    interface IPrint
    {
        CONST_VTBL struct IPrintVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPrint_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPrint_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPrint_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPrint_SetInitialPageNum(This,nFirstPage)	\
    (This)->lpVtbl -> SetInitialPageNum(This,nFirstPage)

#define IPrint_GetPageInfo(This,pnFirstPage,pcPages)	\
    (This)->lpVtbl -> GetPageInfo(This,pnFirstPage,pcPages)

#define IPrint_Print(This,grfFlags,pptd,ppPageSet,pstgmOptions,pcallback,nFirstPage,pcPagesPrinted,pnLastPage)	\
    (This)->lpVtbl -> Print(This,grfFlags,pptd,ppPageSet,pstgmOptions,pcallback,nFirstPage,pcPagesPrinted,pnLastPage)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPrint_SetInitialPageNum_Proxy( 
    IPrint  * This,
    /* [in] */ long nFirstPage);


void __stdcall IPrint_SetInitialPageNum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPrint_GetPageInfo_Proxy( 
    IPrint  * This,
    /* [out] */ long  *pnFirstPage,
    /* [out] */ long  *pcPages);


void __stdcall IPrint_GetPageInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall IPrint_RemotePrint_Proxy( 
    IPrint  * This,
    /* [in] */ unsigned long grfFlags,
    /* [out][in] */ DVTARGETDEVICE  * *pptd,
    /* [out][in] */ PAGESET  * *pppageset,
    /* [unique][out][in] */ RemSTGMEDIUM  *pstgmOptions,
    /* [in] */ IContinueCallback  *pcallback,
    /* [in] */ long nFirstPage,
    /* [out] */ long  *pcPagesPrinted,
    /* [out] */ long  *pnLastPage);


void __stdcall IPrint_RemotePrint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IPrint_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0147
 * at Sun Jul 07 10:43:37 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif
#ifndef _LPOLECOMMANDTARGET_DEFINED
#define _LPOLECOMMANDTARGET_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0147_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0147_v0_0_s_ifspec;

#ifndef __IOleCommandTarget_INTERFACE_DEFINED__
#define __IOleCommandTarget_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOleCommandTarget
 * at Sun Jul 07 10:43:37 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IOleCommandTarget  *LPOLECOMMANDTARGET;

typedef /* [public] */ 
enum __MIDL_IOleCommandTarget_0001
    {	OLECMDF_SUPPORTED	= 0x1,
	OLECMDF_ENABLED	= 0x2,
	OLECMDF_LATCHED	= 0x4,
	OLECMDF_NINCHED	= 0x8
    }	OLECMDF;

typedef struct  _tagOLECMD
    {
    unsigned long cmdID;
    unsigned long cmdf;
    }	OLECMD;

typedef struct  _tagOLECMDTEXT
    {
    unsigned long cmdtextf;
    unsigned long cwActual;
    unsigned long cwBuf;
    /* [size_is] */ wchar_t rgwz[ 1 ];
    }	OLECMDTEXT;

typedef /* [public] */ 
enum __MIDL_IOleCommandTarget_0002
    {	OLECMDTEXTF_NONE	= 0,
	OLECMDTEXTF_NAME	= 1,
	OLECMDTEXTF_STATUS	= 2
    }	OLECMDTEXTF;

typedef /* [public] */ 
enum __MIDL_IOleCommandTarget_0003
    {	OLECMDEXECOPT_DODEFAULT	= 0,
	OLECMDEXECOPT_PROMPTUSER	= 1,
	OLECMDEXECOPT_DONTPROMPTUSER	= 2,
	OLECMDEXECOPT_SHOWHELP	= 3
    }	OLECMDEXECOPT;

/* OLECMDID_STOPDOWNLOAD is supported for QueryStatus Only */
typedef /* [public] */ 
enum __MIDL_IOleCommandTarget_0004
    {	OLECMDID_OPEN	= 1,
	OLECMDID_NEW	= 2,
	OLECMDID_SAVE	= 3,
	OLECMDID_SAVEAS	= 4,
	OLECMDID_SAVECOPYAS	= 5,
	OLECMDID_PRINT	= 6,
	OLECMDID_PRINTPREVIEW	= 7,
	OLECMDID_PAGESETUP	= 8,
	OLECMDID_SPELL	= 9,
	OLECMDID_PROPERTIES	= 10,
	OLECMDID_CUT	= 11,
	OLECMDID_COPY	= 12,
	OLECMDID_PASTE	= 13,
	OLECMDID_PASTESPECIAL	= 14,
	OLECMDID_UNDO	= 15,
	OLECMDID_REDO	= 16,
	OLECMDID_SELECTALL	= 17,
	OLECMDID_CLEARSELECTION	= 18,
	OLECMDID_ZOOM	= 19,
	OLECMDID_GETZOOMRANGE	= 20,
	OLECMDID_UPDATECOMMANDS	= 21,
	OLECMDID_REFRESH	= 22,
	OLECMDID_STOP	= 23,
	OLECMDID_HIDETOOLBARS	= 24,
	OLECMDID_SETPROGRESSMAX	= 25,
	OLECMDID_SETPROGRESSPOS	= 26,
	OLECMDID_SETPROGRESSTEXT	= 27,
	OLECMDID_SETTITLE	= 28,
	OLECMDID_SETDOWNLOADSTATE	= 29,
	OLECMDID_STOPDOWNLOAD	= 30
    }	OLECMDID;

#define OLECMDERR_E_FIRST            (OLE_E_LAST+1)
#define OLECMDERR_E_NOTSUPPORTED (OLECMDERR_E_FIRST)
#define OLECMDERR_E_DISABLED         (OLECMDERR_E_FIRST+1)
#define OLECMDERR_E_NOHELP           (OLECMDERR_E_FIRST+2)
#define OLECMDERR_E_CANCELED         (OLECMDERR_E_FIRST+3)
#define OLECMDERR_E_UNKNOWNGROUP     (OLECMDERR_E_FIRST+4)
#define MSOCMDERR_E_FIRST OLECMDERR_E_FIRST
#define MSOCMDERR_E_NOTSUPPORTED OLECMDERR_E_NOTSUPPORTED
#define MSOCMDERR_E_DISABLED OLECMDERR_E_DISABLED
#define MSOCMDERR_E_NOHELP OLECMDERR_E_NOHELP
#define MSOCMDERR_E_CANCELED OLECMDERR_E_CANCELED
#define MSOCMDERR_E_UNKNOWNGROUP OLECMDERR_E_UNKNOWNGROUP

EXTERN_C const IID IID_IOleCommandTarget;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IOleCommandTarget : public IUnknown
    {
    public:
        virtual /* [input_sync] */ HRESULT __stdcall QueryStatus( 
            /* [unique][in] */ const GUID  *pguidCmdGroup,
            /* [in] */ unsigned long cCmds,
            /* [out][in][size_is] */ OLECMD  prgCmds[  ],
            /* [unique][out][in] */ OLECMDTEXT  *pCmdText) = 0;
        
        virtual HRESULT __stdcall Exec( 
            /* [unique][in] */ const GUID  *pguidCmdGroup,
            /* [in] */ unsigned long nCmdID,
            /* [in] */ unsigned long nCmdexecopt,
            /* [unique][in] */ VARIANT  *pvaIn,
            /* [unique][out][in] */ VARIANT  *pvaOut) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOleCommandTargetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IOleCommandTarget  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IOleCommandTarget  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IOleCommandTarget  * This);
        
        /* [input_sync] */ HRESULT ( __stdcall  *QueryStatus )( 
            IOleCommandTarget  * This,
            /* [unique][in] */ const GUID  *pguidCmdGroup,
            /* [in] */ unsigned long cCmds,
            /* [out][in][size_is] */ OLECMD  prgCmds[  ],
            /* [unique][out][in] */ OLECMDTEXT  *pCmdText);
        
        HRESULT ( __stdcall  *Exec )( 
            IOleCommandTarget  * This,
            /* [unique][in] */ const GUID  *pguidCmdGroup,
            /* [in] */ unsigned long nCmdID,
            /* [in] */ unsigned long nCmdexecopt,
            /* [unique][in] */ VARIANT  *pvaIn,
            /* [unique][out][in] */ VARIANT  *pvaOut);
        
        END_INTERFACE
    } IOleCommandTargetVtbl;

    interface IOleCommandTarget
    {
        CONST_VTBL struct IOleCommandTargetVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleCommandTarget_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOleCommandTarget_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOleCommandTarget_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOleCommandTarget_QueryStatus(This,pguidCmdGroup,cCmds,prgCmds,pCmdText)	\
    (This)->lpVtbl -> QueryStatus(This,pguidCmdGroup,cCmds,prgCmds,pCmdText)

#define IOleCommandTarget_Exec(This,pguidCmdGroup,nCmdID,nCmdexecopt,pvaIn,pvaOut)	\
    (This)->lpVtbl -> Exec(This,pguidCmdGroup,nCmdID,nCmdexecopt,pvaIn,pvaOut)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [input_sync] */ HRESULT __stdcall IOleCommandTarget_QueryStatus_Proxy( 
    IOleCommandTarget  * This,
    /* [unique][in] */ const GUID  *pguidCmdGroup,
    /* [in] */ unsigned long cCmds,
    /* [out][in][size_is] */ OLECMD  prgCmds[  ],
    /* [unique][out][in] */ OLECMDTEXT  *pCmdText);


void __stdcall IOleCommandTarget_QueryStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleCommandTarget_Exec_Proxy( 
    IOleCommandTarget  * This,
    /* [unique][in] */ const GUID  *pguidCmdGroup,
    /* [in] */ unsigned long nCmdID,
    /* [in] */ unsigned long nCmdexecopt,
    /* [unique][in] */ VARIANT  *pvaIn,
    /* [unique][out][in] */ VARIANT  *pvaOut);


void __stdcall IOleCommandTarget_Exec_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IOleCommandTarget_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0148
 * at Sun Jul 07 10:43:37 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif
typedef enum
{
      OLECMDIDF_REFRESH_NORMAL     = 0,
      OLECMDIDF_REFRESH_IFEXPIRED  = 1,
      OLECMDIDF_REFRESH_CONTINUE   = 2,
      OLECMDIDF_REFRESH_COMPLETELY = 3,
} OLECMDID_REFRESHFLAG;

////////////////////////////////////////////////////////////////////////////
//  Aliases to original office-compatible names
#define IMsoDocument             IOleDocument
#define IMsoDocumentSite         IOleDocumentSite
#define IMsoView                 IOleDocumentView
#define IEnumMsoView             IEnumOleDocumentViews
#define IMsoCommandTarget        IOleCommandTarget
#define LPMSODOCUMENT            LPOLEDOCUMENT
#define LPMSODOCUMENTSITE        LPOLEDOCUMENTSITE
#define LPMSOVIEW                LPOLEDOCUMENTVIEW
#define LPENUMMSOVIEW            LPENUMOLEDOCUMENTVIEWS
#define LPMSOCOMMANDTARGET       LPOLECOMMANDTARGET
#define MSOCMD                   OLECMD
#define MSOCMDTEXT               OLECMDTEXT
#define IID_IMsoDocument         IID_IOleDocument
#define IID_IMsoDocumentSite     IID_IOleDocumentSite
#define IID_IMsoView             IID_IOleDocumentView
#define IID_IEnumMsoView         IID_IEnumOleDocumentViews
#define IID_IMsoCommandTarget    IID_IOleCommandTarget
#define MSOCMDF_SUPPORTED OLECMDF_SUPPORTED
#define MSOCMDF_ENABLED OLECMDF_ENABLED
#define MSOCMDF_LATCHED OLECMDF_LATCHED
#define MSOCMDF_NINCHED OLECMDF_NINCHED
#define MSOCMDTEXTF_NONE OLECMDTEXTF_NONE
#define MSOCMDTEXTF_NAME OLECMDTEXTF_NAME
#define MSOCMDTEXTF_STATUS OLECMDTEXTF_STATUS
#define MSOCMDEXECOPT_DODEFAULT OLECMDEXECOPT_DODEFAULT
#define MSOCMDEXECOPT_PROMPTUSER OLECMDEXECOPT_PROMPTUSER
#define MSOCMDEXECOPT_DONTPROMPTUSER OLECMDEXECOPT_DONTPROMPTUSER
#define MSOCMDEXECOPT_SHOWHELP OLECMDEXECOPT_SHOWHELP
#define MSOCMDID_OPEN OLECMDID_OPEN
#define MSOCMDID_NEW OLECMDID_NEW
#define MSOCMDID_SAVE OLECMDID_SAVE
#define MSOCMDID_SAVEAS OLECMDID_SAVEAS
#define MSOCMDID_SAVECOPYAS OLECMDID_SAVECOPYAS
#define MSOCMDID_PRINT OLECMDID_PRINT
#define MSOCMDID_PRINTPREVIEW OLECMDID_PRINTPREVIEW
#define MSOCMDID_PAGESETUP OLECMDID_PAGESETUP
#define MSOCMDID_SPELL OLECMDID_SPELL
#define MSOCMDID_PROPERTIES OLECMDID_PROPERTIES
#define MSOCMDID_CUT OLECMDID_CUT
#define MSOCMDID_COPY OLECMDID_COPY
#define MSOCMDID_PASTE OLECMDID_PASTE
#define MSOCMDID_PASTESPECIAL OLECMDID_PASTESPECIAL
#define MSOCMDID_UNDO OLECMDID_UNDO
#define MSOCMDID_REDO OLECMDID_REDO
#define MSOCMDID_SELECTALL OLECMDID_SELECTALL
#define MSOCMDID_CLEARSELECTION OLECMDID_CLEARSELECTION
#define MSOCMDID_ZOOM OLECMDID_ZOOM
#define MSOCMDID_GETZOOMRANGE OLECMDID_GETZOOMRANGE
EXTERN_C const GUID SID_SContainerDispatch;


extern RPC_IF_HANDLE __MIDL__intf_0148_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0148_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */


void __stdcall UserVARIANT_from_local( VARIANT  *, UserVARIANT  *  * );
void __stdcall UserVARIANT_to_local( UserVARIANT  *, VARIANT  * );
 void __stdcall UserVARIANT_free_inst( UserVARIANT  * );
void __stdcall UserVARIANT_free_local( VARIANT  * );

/* [local] */ HRESULT __stdcall IEnumOleDocumentViews_Next_Proxy( 
    IEnumOleDocumentViews  * This,
    /* [in] */ unsigned long cViews,
    /* [out] */ IOleDocumentView  * *rgpView,
    /* [out] */ unsigned long  *pcFetched);


/* [call_as] */ HRESULT __stdcall IEnumOleDocumentViews_Next_Stub( 
    IEnumOleDocumentViews  * This,
    /* [in] */ unsigned long cViews,
    /* [length_is][size_is][out] */ IOleDocumentView  * *rgpView,
    /* [out] */ unsigned long  *pcFetched);

/* [local] */ HRESULT __stdcall IPrint_Print_Proxy( 
    IPrint  * This,
    /* [in] */ unsigned long grfFlags,
    /* [out][in] */ DVTARGETDEVICE  * *pptd,
    /* [out][in] */ PAGESET  * *ppPageSet,
    /* [unique][out][in] */ STGMEDIUM  *pstgmOptions,
    /* [in] */ IContinueCallback  *pcallback,
    /* [in] */ long nFirstPage,
    /* [out] */ long  *pcPagesPrinted,
    /* [out] */ long  *pnLastPage);


/* [call_as] */ HRESULT __stdcall IPrint_Print_Stub( 
    IPrint  * This,
    /* [in] */ unsigned long grfFlags,
    /* [out][in] */ DVTARGETDEVICE  * *pptd,
    /* [out][in] */ PAGESET  * *pppageset,
    /* [unique][out][in] */ RemSTGMEDIUM  *pstgmOptions,
    /* [in] */ IContinueCallback  *pcallback,
    /* [in] */ long nFirstPage,
    /* [out] */ long  *pcPagesPrinted,
    /* [out] */ long  *pnLastPage);



/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
#pragma once 
