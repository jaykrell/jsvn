/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Fri Jul 12 18:09:28 1996
 */
/* Compiler settings for oleidl.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __oleidl_h__
#define __oleidl_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IOleAdviseHolder_FWD_DEFINED__
#define __IOleAdviseHolder_FWD_DEFINED__
typedef interface IOleAdviseHolder IOleAdviseHolder;
#endif 	/* __IOleAdviseHolder_FWD_DEFINED__ */


#ifndef __IOleCache_FWD_DEFINED__
#define __IOleCache_FWD_DEFINED__
typedef interface IOleCache IOleCache;
#endif 	/* __IOleCache_FWD_DEFINED__ */


#ifndef __IOleCache2_FWD_DEFINED__
#define __IOleCache2_FWD_DEFINED__
typedef interface IOleCache2 IOleCache2;
#endif 	/* __IOleCache2_FWD_DEFINED__ */


#ifndef __IOleCacheControl_FWD_DEFINED__
#define __IOleCacheControl_FWD_DEFINED__
typedef interface IOleCacheControl IOleCacheControl;
#endif 	/* __IOleCacheControl_FWD_DEFINED__ */


#ifndef __IParseDisplayName_FWD_DEFINED__
#define __IParseDisplayName_FWD_DEFINED__
typedef interface IParseDisplayName IParseDisplayName;
#endif 	/* __IParseDisplayName_FWD_DEFINED__ */


#ifndef __IOleContainer_FWD_DEFINED__
#define __IOleContainer_FWD_DEFINED__
typedef interface IOleContainer IOleContainer;
#endif 	/* __IOleContainer_FWD_DEFINED__ */


#ifndef __IOleClientSite_FWD_DEFINED__
#define __IOleClientSite_FWD_DEFINED__
typedef interface IOleClientSite IOleClientSite;
#endif 	/* __IOleClientSite_FWD_DEFINED__ */


#ifndef __IOleObject_FWD_DEFINED__
#define __IOleObject_FWD_DEFINED__
typedef interface IOleObject IOleObject;
#endif 	/* __IOleObject_FWD_DEFINED__ */


#ifndef __IOleWindow_FWD_DEFINED__
#define __IOleWindow_FWD_DEFINED__
typedef interface IOleWindow IOleWindow;
#endif 	/* __IOleWindow_FWD_DEFINED__ */


#ifndef __IOleLink_FWD_DEFINED__
#define __IOleLink_FWD_DEFINED__
typedef interface IOleLink IOleLink;
#endif 	/* __IOleLink_FWD_DEFINED__ */


#ifndef __IOleItemContainer_FWD_DEFINED__
#define __IOleItemContainer_FWD_DEFINED__
typedef interface IOleItemContainer IOleItemContainer;
#endif 	/* __IOleItemContainer_FWD_DEFINED__ */


#ifndef __IOleInPlaceUIWindow_FWD_DEFINED__
#define __IOleInPlaceUIWindow_FWD_DEFINED__
typedef interface IOleInPlaceUIWindow IOleInPlaceUIWindow;
#endif 	/* __IOleInPlaceUIWindow_FWD_DEFINED__ */


#ifndef __IOleInPlaceActiveObject_FWD_DEFINED__
#define __IOleInPlaceActiveObject_FWD_DEFINED__
typedef interface IOleInPlaceActiveObject IOleInPlaceActiveObject;
#endif 	/* __IOleInPlaceActiveObject_FWD_DEFINED__ */


#ifndef __IOleInPlaceFrame_FWD_DEFINED__
#define __IOleInPlaceFrame_FWD_DEFINED__
typedef interface IOleInPlaceFrame IOleInPlaceFrame;
#endif 	/* __IOleInPlaceFrame_FWD_DEFINED__ */


#ifndef __IOleInPlaceObject_FWD_DEFINED__
#define __IOleInPlaceObject_FWD_DEFINED__
typedef interface IOleInPlaceObject IOleInPlaceObject;
#endif 	/* __IOleInPlaceObject_FWD_DEFINED__ */


#ifndef __IOleInPlaceSite_FWD_DEFINED__
#define __IOleInPlaceSite_FWD_DEFINED__
typedef interface IOleInPlaceSite IOleInPlaceSite;
#endif 	/* __IOleInPlaceSite_FWD_DEFINED__ */


#ifndef __IContinue_FWD_DEFINED__
#define __IContinue_FWD_DEFINED__
typedef interface IContinue IContinue;
#endif 	/* __IContinue_FWD_DEFINED__ */


#ifndef __IViewObject_FWD_DEFINED__
#define __IViewObject_FWD_DEFINED__
typedef interface IViewObject IViewObject;
#endif 	/* __IViewObject_FWD_DEFINED__ */


#ifndef __IViewObject2_FWD_DEFINED__
#define __IViewObject2_FWD_DEFINED__
typedef interface IViewObject2 IViewObject2;
#endif 	/* __IViewObject2_FWD_DEFINED__ */


#ifndef __IDropSource_FWD_DEFINED__
#define __IDropSource_FWD_DEFINED__
typedef interface IDropSource IDropSource;
#endif 	/* __IDropSource_FWD_DEFINED__ */


#ifndef __IDropTarget_FWD_DEFINED__
#define __IDropTarget_FWD_DEFINED__
typedef interface IDropTarget IDropTarget;
#endif 	/* __IDropTarget_FWD_DEFINED__ */


#ifndef __IEnumOLEVERB_FWD_DEFINED__
#define __IEnumOLEVERB_FWD_DEFINED__
typedef interface IEnumOLEVERB IEnumOLEVERB;
#endif 	/* __IEnumOLEVERB_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"

void  * __stdcall MIDL_user_allocate(size_t);
void __stdcall MIDL_user_free( void  * ); 

/****************************************
 * Generated header for interface: __MIDL__intf_0000
 * at Fri Jul 12 18:09:28 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


//+-------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (C) Microsoft Corporation, 1992 - 1996.
//
//--------------------------------------------------------------------------




extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_s_ifspec;

#ifndef __IOleAdviseHolder_INTERFACE_DEFINED__
#define __IOleAdviseHolder_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOleAdviseHolder
 * at Fri Jul 12 18:09:28 1996
 * using MIDL 3.00.44
 ****************************************/
/* [uuid][object][local] */ 


typedef /* [unique] */ IOleAdviseHolder  *LPOLEADVISEHOLDER;


EXTERN_C const IID IID_IOleAdviseHolder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IOleAdviseHolder : public IUnknown
    {
    public:
        virtual HRESULT __stdcall Advise( 
            /* [unique][in] */ IAdviseSink  *pAdvise,
            /* [out] */ unsigned long  *pdwConnection) = 0;
        
        virtual HRESULT __stdcall Unadvise( 
            /* [in] */ unsigned long dwConnection) = 0;
        
        virtual HRESULT __stdcall EnumAdvise( 
            /* [out] */ IEnumSTATDATA  * *ppenumAdvise) = 0;
        
        virtual HRESULT __stdcall SendOnRename( 
            /* [unique][in] */ IMoniker  *pmk) = 0;
        
        virtual HRESULT __stdcall SendOnSave( void) = 0;
        
        virtual HRESULT __stdcall SendOnClose( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOleAdviseHolderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IOleAdviseHolder  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IOleAdviseHolder  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IOleAdviseHolder  * This);
        
        HRESULT ( __stdcall  *Advise )( 
            IOleAdviseHolder  * This,
            /* [unique][in] */ IAdviseSink  *pAdvise,
            /* [out] */ unsigned long  *pdwConnection);
        
        HRESULT ( __stdcall  *Unadvise )( 
            IOleAdviseHolder  * This,
            /* [in] */ unsigned long dwConnection);
        
        HRESULT ( __stdcall  *EnumAdvise )( 
            IOleAdviseHolder  * This,
            /* [out] */ IEnumSTATDATA  * *ppenumAdvise);
        
        HRESULT ( __stdcall  *SendOnRename )( 
            IOleAdviseHolder  * This,
            /* [unique][in] */ IMoniker  *pmk);
        
        HRESULT ( __stdcall  *SendOnSave )( 
            IOleAdviseHolder  * This);
        
        HRESULT ( __stdcall  *SendOnClose )( 
            IOleAdviseHolder  * This);
        
        END_INTERFACE
    } IOleAdviseHolderVtbl;

    interface IOleAdviseHolder
    {
        CONST_VTBL struct IOleAdviseHolderVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleAdviseHolder_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOleAdviseHolder_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOleAdviseHolder_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOleAdviseHolder_Advise(This,pAdvise,pdwConnection)	\
    (This)->lpVtbl -> Advise(This,pAdvise,pdwConnection)

#define IOleAdviseHolder_Unadvise(This,dwConnection)	\
    (This)->lpVtbl -> Unadvise(This,dwConnection)

#define IOleAdviseHolder_EnumAdvise(This,ppenumAdvise)	\
    (This)->lpVtbl -> EnumAdvise(This,ppenumAdvise)

#define IOleAdviseHolder_SendOnRename(This,pmk)	\
    (This)->lpVtbl -> SendOnRename(This,pmk)

#define IOleAdviseHolder_SendOnSave(This)	\
    (This)->lpVtbl -> SendOnSave(This)

#define IOleAdviseHolder_SendOnClose(This)	\
    (This)->lpVtbl -> SendOnClose(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IOleAdviseHolder_Advise_Proxy( 
    IOleAdviseHolder  * This,
    /* [unique][in] */ IAdviseSink  *pAdvise,
    /* [out] */ unsigned long  *pdwConnection);


void __stdcall IOleAdviseHolder_Advise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleAdviseHolder_Unadvise_Proxy( 
    IOleAdviseHolder  * This,
    /* [in] */ unsigned long dwConnection);


void __stdcall IOleAdviseHolder_Unadvise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleAdviseHolder_EnumAdvise_Proxy( 
    IOleAdviseHolder  * This,
    /* [out] */ IEnumSTATDATA  * *ppenumAdvise);


void __stdcall IOleAdviseHolder_EnumAdvise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleAdviseHolder_SendOnRename_Proxy( 
    IOleAdviseHolder  * This,
    /* [unique][in] */ IMoniker  *pmk);


void __stdcall IOleAdviseHolder_SendOnRename_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleAdviseHolder_SendOnSave_Proxy( 
    IOleAdviseHolder  * This);


void __stdcall IOleAdviseHolder_SendOnSave_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleAdviseHolder_SendOnClose_Proxy( 
    IOleAdviseHolder  * This);


void __stdcall IOleAdviseHolder_SendOnClose_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IOleAdviseHolder_INTERFACE_DEFINED__ */


#ifndef __IOleCache_INTERFACE_DEFINED__
#define __IOleCache_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOleCache
 * at Fri Jul 12 18:09:28 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IOleCache  *LPOLECACHE;


EXTERN_C const IID IID_IOleCache;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IOleCache : public IUnknown
    {
    public:
        virtual HRESULT __stdcall Cache( 
            /* [unique][in] */ FORMATETC  *pformatetc,
            /* [in] */ unsigned long advf,
            /* [out] */ unsigned long  *pdwConnection) = 0;
        
        virtual HRESULT __stdcall Uncache( 
            /* [in] */ unsigned long dwConnection) = 0;
        
        virtual HRESULT __stdcall EnumCache( 
            /* [out] */ IEnumSTATDATA  * *ppenumSTATDATA) = 0;
        
        virtual HRESULT __stdcall InitCache( 
            /* [unique][in] */ IDataObject  *pDataObject) = 0;
        
        virtual HRESULT __stdcall SetData( 
            /* [unique][in] */ FORMATETC  *pformatetc,
            /* [unique][in] */ STGMEDIUM  *pmedium,
            /* [in] */ BOOL fRelease) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOleCacheVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IOleCache  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IOleCache  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IOleCache  * This);
        
        HRESULT ( __stdcall  *Cache )( 
            IOleCache  * This,
            /* [unique][in] */ FORMATETC  *pformatetc,
            /* [in] */ unsigned long advf,
            /* [out] */ unsigned long  *pdwConnection);
        
        HRESULT ( __stdcall  *Uncache )( 
            IOleCache  * This,
            /* [in] */ unsigned long dwConnection);
        
        HRESULT ( __stdcall  *EnumCache )( 
            IOleCache  * This,
            /* [out] */ IEnumSTATDATA  * *ppenumSTATDATA);
        
        HRESULT ( __stdcall  *InitCache )( 
            IOleCache  * This,
            /* [unique][in] */ IDataObject  *pDataObject);
        
        HRESULT ( __stdcall  *SetData )( 
            IOleCache  * This,
            /* [unique][in] */ FORMATETC  *pformatetc,
            /* [unique][in] */ STGMEDIUM  *pmedium,
            /* [in] */ BOOL fRelease);
        
        END_INTERFACE
    } IOleCacheVtbl;

    interface IOleCache
    {
        CONST_VTBL struct IOleCacheVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleCache_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOleCache_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOleCache_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOleCache_Cache(This,pformatetc,advf,pdwConnection)	\
    (This)->lpVtbl -> Cache(This,pformatetc,advf,pdwConnection)

#define IOleCache_Uncache(This,dwConnection)	\
    (This)->lpVtbl -> Uncache(This,dwConnection)

#define IOleCache_EnumCache(This,ppenumSTATDATA)	\
    (This)->lpVtbl -> EnumCache(This,ppenumSTATDATA)

#define IOleCache_InitCache(This,pDataObject)	\
    (This)->lpVtbl -> InitCache(This,pDataObject)

#define IOleCache_SetData(This,pformatetc,pmedium,fRelease)	\
    (This)->lpVtbl -> SetData(This,pformatetc,pmedium,fRelease)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IOleCache_Cache_Proxy( 
    IOleCache  * This,
    /* [unique][in] */ FORMATETC  *pformatetc,
    /* [in] */ unsigned long advf,
    /* [out] */ unsigned long  *pdwConnection);


void __stdcall IOleCache_Cache_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleCache_Uncache_Proxy( 
    IOleCache  * This,
    /* [in] */ unsigned long dwConnection);


void __stdcall IOleCache_Uncache_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleCache_EnumCache_Proxy( 
    IOleCache  * This,
    /* [out] */ IEnumSTATDATA  * *ppenumSTATDATA);


void __stdcall IOleCache_EnumCache_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleCache_InitCache_Proxy( 
    IOleCache  * This,
    /* [unique][in] */ IDataObject  *pDataObject);


void __stdcall IOleCache_InitCache_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleCache_SetData_Proxy( 
    IOleCache  * This,
    /* [unique][in] */ FORMATETC  *pformatetc,
    /* [unique][in] */ STGMEDIUM  *pmedium,
    /* [in] */ BOOL fRelease);


void __stdcall IOleCache_SetData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IOleCache_INTERFACE_DEFINED__ */


#ifndef __IOleCache2_INTERFACE_DEFINED__
#define __IOleCache2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOleCache2
 * at Fri Jul 12 18:09:28 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IOleCache2  *LPOLECACHE2;

#define	UPDFCACHE_NODATACACHE	( 0x1 )

#define	UPDFCACHE_ONSAVECACHE	( 0x2 )

#define	UPDFCACHE_ONSTOPCACHE	( 0x4 )

#define	UPDFCACHE_NORMALCACHE	( 0x8 )

#define	UPDFCACHE_IFBLANK	( 0x10 )

#define	UPDFCACHE_ONLYIFBLANK	( 0x80000000 )

#define	UPDFCACHE_IFBLANKORONSAVECACHE	( UPDFCACHE_IFBLANK | UPDFCACHE_ONSAVECACHE )

#define	UPDFCACHE_ALL	( ( unsigned long  )~UPDFCACHE_ONLYIFBLANK )

#define	UPDFCACHE_ALLBUTNODATACACHE	( UPDFCACHE_ALL & ( unsigned long  )~UPDFCACHE_NODATACACHE )

typedef /* [v1_enum] */ 
enum tagDISCARDCACHE
    {	DISCARDCACHE_SAVEIFDIRTY	= 0,
	DISCARDCACHE_NOSAVE	= 1
    }	DISCARDCACHE;


EXTERN_C const IID IID_IOleCache2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IOleCache2 : public IOleCache
    {
    public:
        virtual /* [local] */ HRESULT __stdcall UpdateCache( 
            /* [in] */ LPDATAOBJECT pDataObject,
            /* [in] */ unsigned long grfUpdf,
            /* [in] */ void* pReserved) = 0;
        
        virtual HRESULT __stdcall DiscardCache( 
            /* [in] */ unsigned long dwDiscardOptions) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOleCache2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IOleCache2  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IOleCache2  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IOleCache2  * This);
        
        HRESULT ( __stdcall  *Cache )( 
            IOleCache2  * This,
            /* [unique][in] */ FORMATETC  *pformatetc,
            /* [in] */ unsigned long advf,
            /* [out] */ unsigned long  *pdwConnection);
        
        HRESULT ( __stdcall  *Uncache )( 
            IOleCache2  * This,
            /* [in] */ unsigned long dwConnection);
        
        HRESULT ( __stdcall  *EnumCache )( 
            IOleCache2  * This,
            /* [out] */ IEnumSTATDATA  * *ppenumSTATDATA);
        
        HRESULT ( __stdcall  *InitCache )( 
            IOleCache2  * This,
            /* [unique][in] */ IDataObject  *pDataObject);
        
        HRESULT ( __stdcall  *SetData )( 
            IOleCache2  * This,
            /* [unique][in] */ FORMATETC  *pformatetc,
            /* [unique][in] */ STGMEDIUM  *pmedium,
            /* [in] */ BOOL fRelease);
        
        /* [local] */ HRESULT ( __stdcall  *UpdateCache )( 
            IOleCache2  * This,
            /* [in] */ LPDATAOBJECT pDataObject,
            /* [in] */ unsigned long grfUpdf,
            /* [in] */ void* pReserved);
        
        HRESULT ( __stdcall  *DiscardCache )( 
            IOleCache2  * This,
            /* [in] */ unsigned long dwDiscardOptions);
        
        END_INTERFACE
    } IOleCache2Vtbl;

    interface IOleCache2
    {
        CONST_VTBL struct IOleCache2Vtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleCache2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOleCache2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOleCache2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOleCache2_Cache(This,pformatetc,advf,pdwConnection)	\
    (This)->lpVtbl -> Cache(This,pformatetc,advf,pdwConnection)

#define IOleCache2_Uncache(This,dwConnection)	\
    (This)->lpVtbl -> Uncache(This,dwConnection)

#define IOleCache2_EnumCache(This,ppenumSTATDATA)	\
    (This)->lpVtbl -> EnumCache(This,ppenumSTATDATA)

#define IOleCache2_InitCache(This,pDataObject)	\
    (This)->lpVtbl -> InitCache(This,pDataObject)

#define IOleCache2_SetData(This,pformatetc,pmedium,fRelease)	\
    (This)->lpVtbl -> SetData(This,pformatetc,pmedium,fRelease)


#define IOleCache2_UpdateCache(This,pDataObject,grfUpdf,pReserved)	\
    (This)->lpVtbl -> UpdateCache(This,pDataObject,grfUpdf,pReserved)

#define IOleCache2_DiscardCache(This,dwDiscardOptions)	\
    (This)->lpVtbl -> DiscardCache(This,dwDiscardOptions)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall IOleCache2_RemoteUpdateCache_Proxy( 
    IOleCache2  * This,
    /* [in] */ LPDATAOBJECT pDataObject,
    /* [in] */ unsigned long grfUpdf,
    /* [in] */ unsigned long pReserved);


void __stdcall IOleCache2_RemoteUpdateCache_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleCache2_DiscardCache_Proxy( 
    IOleCache2  * This,
    /* [in] */ unsigned long dwDiscardOptions);


void __stdcall IOleCache2_DiscardCache_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IOleCache2_INTERFACE_DEFINED__ */


#ifndef __IOleCacheControl_INTERFACE_DEFINED__
#define __IOleCacheControl_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOleCacheControl
 * at Fri Jul 12 18:09:28 1996
 * using MIDL 3.00.44
 ****************************************/
/* [uuid][object] */ 


typedef /* [unique] */ IOleCacheControl  *LPOLECACHECONTROL;


EXTERN_C const IID IID_IOleCacheControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IOleCacheControl : public IUnknown
    {
    public:
        virtual HRESULT __stdcall OnRun( 
            LPDATAOBJECT pDataObject) = 0;
        
        virtual HRESULT __stdcall OnStop( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOleCacheControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IOleCacheControl  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IOleCacheControl  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IOleCacheControl  * This);
        
        HRESULT ( __stdcall  *OnRun )( 
            IOleCacheControl  * This,
            LPDATAOBJECT pDataObject);
        
        HRESULT ( __stdcall  *OnStop )( 
            IOleCacheControl  * This);
        
        END_INTERFACE
    } IOleCacheControlVtbl;

    interface IOleCacheControl
    {
        CONST_VTBL struct IOleCacheControlVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleCacheControl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOleCacheControl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOleCacheControl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOleCacheControl_OnRun(This,pDataObject)	\
    (This)->lpVtbl -> OnRun(This,pDataObject)

#define IOleCacheControl_OnStop(This)	\
    (This)->lpVtbl -> OnStop(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IOleCacheControl_OnRun_Proxy( 
    IOleCacheControl  * This,
    LPDATAOBJECT pDataObject);


void __stdcall IOleCacheControl_OnRun_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleCacheControl_OnStop_Proxy( 
    IOleCacheControl  * This);


void __stdcall IOleCacheControl_OnStop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IOleCacheControl_INTERFACE_DEFINED__ */


#ifndef __IParseDisplayName_INTERFACE_DEFINED__
#define __IParseDisplayName_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IParseDisplayName
 * at Fri Jul 12 18:09:28 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IParseDisplayName  *LPPARSEDISPLAYNAME;


EXTERN_C const IID IID_IParseDisplayName;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IParseDisplayName : public IUnknown
    {
    public:
        virtual HRESULT __stdcall ParseDisplayName( 
            /* [unique][in] */ IBindCtx  *pbc,
            /* [in] */ LPOLESTR pszDisplayName,
            /* [out] */ unsigned long  *pchEaten,
            /* [out] */ IMoniker  * *ppmkOut) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IParseDisplayNameVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IParseDisplayName  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IParseDisplayName  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IParseDisplayName  * This);
        
        HRESULT ( __stdcall  *ParseDisplayName )( 
            IParseDisplayName  * This,
            /* [unique][in] */ IBindCtx  *pbc,
            /* [in] */ LPOLESTR pszDisplayName,
            /* [out] */ unsigned long  *pchEaten,
            /* [out] */ IMoniker  * *ppmkOut);
        
        END_INTERFACE
    } IParseDisplayNameVtbl;

    interface IParseDisplayName
    {
        CONST_VTBL struct IParseDisplayNameVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IParseDisplayName_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IParseDisplayName_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IParseDisplayName_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IParseDisplayName_ParseDisplayName(This,pbc,pszDisplayName,pchEaten,ppmkOut)	\
    (This)->lpVtbl -> ParseDisplayName(This,pbc,pszDisplayName,pchEaten,ppmkOut)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IParseDisplayName_ParseDisplayName_Proxy( 
    IParseDisplayName  * This,
    /* [unique][in] */ IBindCtx  *pbc,
    /* [in] */ LPOLESTR pszDisplayName,
    /* [out] */ unsigned long  *pchEaten,
    /* [out] */ IMoniker  * *ppmkOut);


void __stdcall IParseDisplayName_ParseDisplayName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IParseDisplayName_INTERFACE_DEFINED__ */


#ifndef __IOleContainer_INTERFACE_DEFINED__
#define __IOleContainer_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOleContainer
 * at Fri Jul 12 18:09:28 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IOleContainer  *LPOLECONTAINER;


EXTERN_C const IID IID_IOleContainer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IOleContainer : public IParseDisplayName
    {
    public:
        virtual HRESULT __stdcall EnumObjects( 
            /* [in] */ unsigned long grfFlags,
            /* [out] */ IEnumUnknown  * *ppenum) = 0;
        
        virtual HRESULT __stdcall LockContainer( 
            /* [in] */ BOOL fLock) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOleContainerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IOleContainer  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IOleContainer  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IOleContainer  * This);
        
        HRESULT ( __stdcall  *ParseDisplayName )( 
            IOleContainer  * This,
            /* [unique][in] */ IBindCtx  *pbc,
            /* [in] */ LPOLESTR pszDisplayName,
            /* [out] */ unsigned long  *pchEaten,
            /* [out] */ IMoniker  * *ppmkOut);
        
        HRESULT ( __stdcall  *EnumObjects )( 
            IOleContainer  * This,
            /* [in] */ unsigned long grfFlags,
            /* [out] */ IEnumUnknown  * *ppenum);
        
        HRESULT ( __stdcall  *LockContainer )( 
            IOleContainer  * This,
            /* [in] */ BOOL fLock);
        
        END_INTERFACE
    } IOleContainerVtbl;

    interface IOleContainer
    {
        CONST_VTBL struct IOleContainerVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleContainer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOleContainer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOleContainer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOleContainer_ParseDisplayName(This,pbc,pszDisplayName,pchEaten,ppmkOut)	\
    (This)->lpVtbl -> ParseDisplayName(This,pbc,pszDisplayName,pchEaten,ppmkOut)


#define IOleContainer_EnumObjects(This,grfFlags,ppenum)	\
    (This)->lpVtbl -> EnumObjects(This,grfFlags,ppenum)

#define IOleContainer_LockContainer(This,fLock)	\
    (This)->lpVtbl -> LockContainer(This,fLock)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IOleContainer_EnumObjects_Proxy( 
    IOleContainer  * This,
    /* [in] */ unsigned long grfFlags,
    /* [out] */ IEnumUnknown  * *ppenum);


void __stdcall IOleContainer_EnumObjects_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleContainer_LockContainer_Proxy( 
    IOleContainer  * This,
    /* [in] */ BOOL fLock);


void __stdcall IOleContainer_LockContainer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IOleContainer_INTERFACE_DEFINED__ */


#ifndef __IOleClientSite_INTERFACE_DEFINED__
#define __IOleClientSite_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOleClientSite
 * at Fri Jul 12 18:09:28 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IOleClientSite  *LPOLECLIENTSITE;


EXTERN_C const IID IID_IOleClientSite;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IOleClientSite : public IUnknown
    {
    public:
        virtual HRESULT __stdcall SaveObject( void) = 0;
        
        virtual HRESULT __stdcall GetMoniker( 
            /* [in] */ unsigned long dwAssign,
            /* [in] */ unsigned long dwWhichMoniker,
            /* [out] */ IMoniker  * *ppmk) = 0;
        
        virtual HRESULT __stdcall GetContainer( 
            /* [out] */ IOleContainer  * *ppContainer) = 0;
        
        virtual HRESULT __stdcall ShowObject( void) = 0;
        
        virtual HRESULT __stdcall OnShowWindow( 
            /* [in] */ BOOL fShow) = 0;
        
        virtual HRESULT __stdcall RequestNewObjectLayout( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOleClientSiteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IOleClientSite  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IOleClientSite  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IOleClientSite  * This);
        
        HRESULT ( __stdcall  *SaveObject )( 
            IOleClientSite  * This);
        
        HRESULT ( __stdcall  *GetMoniker )( 
            IOleClientSite  * This,
            /* [in] */ unsigned long dwAssign,
            /* [in] */ unsigned long dwWhichMoniker,
            /* [out] */ IMoniker  * *ppmk);
        
        HRESULT ( __stdcall  *GetContainer )( 
            IOleClientSite  * This,
            /* [out] */ IOleContainer  * *ppContainer);
        
        HRESULT ( __stdcall  *ShowObject )( 
            IOleClientSite  * This);
        
        HRESULT ( __stdcall  *OnShowWindow )( 
            IOleClientSite  * This,
            /* [in] */ BOOL fShow);
        
        HRESULT ( __stdcall  *RequestNewObjectLayout )( 
            IOleClientSite  * This);
        
        END_INTERFACE
    } IOleClientSiteVtbl;

    interface IOleClientSite
    {
        CONST_VTBL struct IOleClientSiteVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleClientSite_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOleClientSite_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOleClientSite_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOleClientSite_SaveObject(This)	\
    (This)->lpVtbl -> SaveObject(This)

#define IOleClientSite_GetMoniker(This,dwAssign,dwWhichMoniker,ppmk)	\
    (This)->lpVtbl -> GetMoniker(This,dwAssign,dwWhichMoniker,ppmk)

#define IOleClientSite_GetContainer(This,ppContainer)	\
    (This)->lpVtbl -> GetContainer(This,ppContainer)

#define IOleClientSite_ShowObject(This)	\
    (This)->lpVtbl -> ShowObject(This)

#define IOleClientSite_OnShowWindow(This,fShow)	\
    (This)->lpVtbl -> OnShowWindow(This,fShow)

#define IOleClientSite_RequestNewObjectLayout(This)	\
    (This)->lpVtbl -> RequestNewObjectLayout(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IOleClientSite_SaveObject_Proxy( 
    IOleClientSite  * This);


void __stdcall IOleClientSite_SaveObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleClientSite_GetMoniker_Proxy( 
    IOleClientSite  * This,
    /* [in] */ unsigned long dwAssign,
    /* [in] */ unsigned long dwWhichMoniker,
    /* [out] */ IMoniker  * *ppmk);


void __stdcall IOleClientSite_GetMoniker_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleClientSite_GetContainer_Proxy( 
    IOleClientSite  * This,
    /* [out] */ IOleContainer  * *ppContainer);


void __stdcall IOleClientSite_GetContainer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleClientSite_ShowObject_Proxy( 
    IOleClientSite  * This);


void __stdcall IOleClientSite_ShowObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleClientSite_OnShowWindow_Proxy( 
    IOleClientSite  * This,
    /* [in] */ BOOL fShow);


void __stdcall IOleClientSite_OnShowWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleClientSite_RequestNewObjectLayout_Proxy( 
    IOleClientSite  * This);


void __stdcall IOleClientSite_RequestNewObjectLayout_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IOleClientSite_INTERFACE_DEFINED__ */


#ifndef __IOleObject_INTERFACE_DEFINED__
#define __IOleObject_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOleObject
 * at Fri Jul 12 18:09:28 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IOleObject  *LPOLEOBJECT;

typedef 
enum tagOLEGETMONIKER
    {	OLEGETMONIKER_ONLYIFTHERE	= 1,
	OLEGETMONIKER_FORCEASSIGN	= 2,
	OLEGETMONIKER_UNASSIGN	= 3,
	OLEGETMONIKER_TEMPFORUSER	= 4
    }	OLEGETMONIKER;

typedef 
enum tagOLEWHICHMK
    {	OLEWHICHMK_CONTAINER	= 1,
	OLEWHICHMK_OBJREL	= 2,
	OLEWHICHMK_OBJFULL	= 3
    }	OLEWHICHMK;

typedef 
enum tagUSERCLASSTYPE
    {	USERCLASSTYPE_FULL	= 1,
	USERCLASSTYPE_SHORT	= 2,
	USERCLASSTYPE_APPNAME	= 3
    }	USERCLASSTYPE;

typedef 
enum tagOLEMISC
    {	OLEMISC_RECOMPOSEONRESIZE	= 0x1,
	OLEMISC_ONLYICONIC	= 0x2,
	OLEMISC_INSERTNOTREPLACE	= 0x4,
	OLEMISC_STATIC	= 0x8,
	OLEMISC_CANTLINKINSIDE	= 0x10,
	OLEMISC_CANLINKBYOLE1	= 0x20,
	OLEMISC_ISLINKOBJECT	= 0x40,
	OLEMISC_INSIDEOUT	= 0x80,
	OLEMISC_ACTIVATEWHENVISIBLE	= 0x100,
	OLEMISC_RENDERINGISDEVICEINDEPENDENT	= 0x200,
	OLEMISC_INVISIBLEATRUNTIME	= 0x400,
	OLEMISC_ALWAYSRUN	= 0x800,
	OLEMISC_ACTSLIKEBUTTON	= 0x1000,
	OLEMISC_ACTSLIKELABEL	= 0x2000,
	OLEMISC_NOUIACTIVATE	= 0x4000,
	OLEMISC_ALIGNABLE	= 0x8000,
	OLEMISC_SIMPLEFRAME	= 0x10000,
	OLEMISC_SETCLIENTSITEFIRST	= 0x20000,
	OLEMISC_IMEMODE	= 0x40000,
	OLEMISC_IGNOREACTIVATEWHENVISIBLE	= 0x80000,
	OLEMISC_WANTSTOMENUMERGE	= 0x100000,
	OLEMISC_SUPPORTSMULTILEVELUNDO	= 0x200000
    }	OLEMISC;

typedef 
enum tagOLECLOSE
    {	OLECLOSE_SAVEIFDIRTY	= 0,
	OLECLOSE_NOSAVE	= 1,
	OLECLOSE_PROMPTSAVE	= 2
    }	OLECLOSE;


EXTERN_C const IID IID_IOleObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IOleObject : public IUnknown
    {
    public:
        virtual HRESULT __stdcall SetClientSite( 
            /* [unique][in] */ IOleClientSite  *pClientSite) = 0;
        
        virtual HRESULT __stdcall GetClientSite( 
            /* [out] */ IOleClientSite  * *ppClientSite) = 0;
        
        virtual HRESULT __stdcall SetHostNames( 
            /* [in] */ LPCOLESTR szContainerApp,
            /* [unique][in] */ LPCOLESTR szContainerObj) = 0;
        
        virtual HRESULT __stdcall Close( 
            /* [in] */ unsigned long dwSaveOption) = 0;
        
        virtual HRESULT __stdcall SetMoniker( 
            /* [in] */ unsigned long dwWhichMoniker,
            /* [unique][in] */ IMoniker  *pmk) = 0;
        
        virtual HRESULT __stdcall GetMoniker( 
            /* [in] */ unsigned long dwAssign,
            /* [in] */ unsigned long dwWhichMoniker,
            /* [out] */ IMoniker  * *ppmk) = 0;
        
        virtual HRESULT __stdcall InitFromData( 
            /* [unique][in] */ IDataObject  *pDataObject,
            /* [in] */ BOOL fCreation,
            /* [in] */ unsigned long dwReserved) = 0;
        
        virtual HRESULT __stdcall GetClipboardData( 
            /* [in] */ unsigned long dwReserved,
            /* [out] */ IDataObject  * *ppDataObject) = 0;
        
        virtual HRESULT __stdcall DoVerb( 
            /* [in] */ LONG iVerb,
            /* [unique][in] */ LPMSG lpmsg,
            /* [unique][in] */ IOleClientSite  *pActiveSite,
            /* [in] */ LONG lindex,
            /* [in] */ HWND hwndParent,
            /* [unique][in] */ LPCRECT lprcPosRect) = 0;
        
        virtual HRESULT __stdcall EnumVerbs( 
            /* [out] */ IEnumOLEVERB  * *ppEnumOleVerb) = 0;
        
        virtual HRESULT __stdcall Update( void) = 0;
        
        virtual HRESULT __stdcall IsUpToDate( void) = 0;
        
        virtual HRESULT __stdcall GetUserClassID( 
            /* [out] */ CLSID  *pClsid) = 0;
        
        virtual HRESULT __stdcall GetUserType( 
            /* [in] */ unsigned long dwFormOfType,
            /* [out] */ LPOLESTR  *pszUserType) = 0;
        
        virtual HRESULT __stdcall SetExtent( 
            /* [in] */ unsigned long dwDrawAspect,
            /* [in] */ SIZEL  *psizel) = 0;
        
        virtual HRESULT __stdcall GetExtent( 
            /* [in] */ unsigned long dwDrawAspect,
            /* [out] */ SIZEL  *psizel) = 0;
        
        virtual HRESULT __stdcall Advise( 
            /* [unique][in] */ IAdviseSink  *pAdvSink,
            /* [out] */ unsigned long  *pdwConnection) = 0;
        
        virtual HRESULT __stdcall Unadvise( 
            /* [in] */ unsigned long dwConnection) = 0;
        
        virtual HRESULT __stdcall EnumAdvise( 
            /* [out] */ IEnumSTATDATA  * *ppenumAdvise) = 0;
        
        virtual HRESULT __stdcall GetMiscStatus( 
            /* [in] */ unsigned long dwAspect,
            /* [out] */ unsigned long  *pdwStatus) = 0;
        
        virtual HRESULT __stdcall SetColorScheme( 
            /* [in] */ LOGPALETTE  *pLogpal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOleObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IOleObject  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IOleObject  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IOleObject  * This);
        
        HRESULT ( __stdcall  *SetClientSite )( 
            IOleObject  * This,
            /* [unique][in] */ IOleClientSite  *pClientSite);
        
        HRESULT ( __stdcall  *GetClientSite )( 
            IOleObject  * This,
            /* [out] */ IOleClientSite  * *ppClientSite);
        
        HRESULT ( __stdcall  *SetHostNames )( 
            IOleObject  * This,
            /* [in] */ LPCOLESTR szContainerApp,
            /* [unique][in] */ LPCOLESTR szContainerObj);
        
        HRESULT ( __stdcall  *Close )( 
            IOleObject  * This,
            /* [in] */ unsigned long dwSaveOption);
        
        HRESULT ( __stdcall  *SetMoniker )( 
            IOleObject  * This,
            /* [in] */ unsigned long dwWhichMoniker,
            /* [unique][in] */ IMoniker  *pmk);
        
        HRESULT ( __stdcall  *GetMoniker )( 
            IOleObject  * This,
            /* [in] */ unsigned long dwAssign,
            /* [in] */ unsigned long dwWhichMoniker,
            /* [out] */ IMoniker  * *ppmk);
        
        HRESULT ( __stdcall  *InitFromData )( 
            IOleObject  * This,
            /* [unique][in] */ IDataObject  *pDataObject,
            /* [in] */ BOOL fCreation,
            /* [in] */ unsigned long dwReserved);
        
        HRESULT ( __stdcall  *GetClipboardData )( 
            IOleObject  * This,
            /* [in] */ unsigned long dwReserved,
            /* [out] */ IDataObject  * *ppDataObject);
        
        HRESULT ( __stdcall  *DoVerb )( 
            IOleObject  * This,
            /* [in] */ LONG iVerb,
            /* [unique][in] */ LPMSG lpmsg,
            /* [unique][in] */ IOleClientSite  *pActiveSite,
            /* [in] */ LONG lindex,
            /* [in] */ HWND hwndParent,
            /* [unique][in] */ LPCRECT lprcPosRect);
        
        HRESULT ( __stdcall  *EnumVerbs )( 
            IOleObject  * This,
            /* [out] */ IEnumOLEVERB  * *ppEnumOleVerb);
        
        HRESULT ( __stdcall  *Update )( 
            IOleObject  * This);
        
        HRESULT ( __stdcall  *IsUpToDate )( 
            IOleObject  * This);
        
        HRESULT ( __stdcall  *GetUserClassID )( 
            IOleObject  * This,
            /* [out] */ CLSID  *pClsid);
        
        HRESULT ( __stdcall  *GetUserType )( 
            IOleObject  * This,
            /* [in] */ unsigned long dwFormOfType,
            /* [out] */ LPOLESTR  *pszUserType);
        
        HRESULT ( __stdcall  *SetExtent )( 
            IOleObject  * This,
            /* [in] */ unsigned long dwDrawAspect,
            /* [in] */ SIZEL  *psizel);
        
        HRESULT ( __stdcall  *GetExtent )( 
            IOleObject  * This,
            /* [in] */ unsigned long dwDrawAspect,
            /* [out] */ SIZEL  *psizel);
        
        HRESULT ( __stdcall  *Advise )( 
            IOleObject  * This,
            /* [unique][in] */ IAdviseSink  *pAdvSink,
            /* [out] */ unsigned long  *pdwConnection);
        
        HRESULT ( __stdcall  *Unadvise )( 
            IOleObject  * This,
            /* [in] */ unsigned long dwConnection);
        
        HRESULT ( __stdcall  *EnumAdvise )( 
            IOleObject  * This,
            /* [out] */ IEnumSTATDATA  * *ppenumAdvise);
        
        HRESULT ( __stdcall  *GetMiscStatus )( 
            IOleObject  * This,
            /* [in] */ unsigned long dwAspect,
            /* [out] */ unsigned long  *pdwStatus);
        
        HRESULT ( __stdcall  *SetColorScheme )( 
            IOleObject  * This,
            /* [in] */ LOGPALETTE  *pLogpal);
        
        END_INTERFACE
    } IOleObjectVtbl;

    interface IOleObject
    {
        CONST_VTBL struct IOleObjectVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOleObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOleObject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOleObject_SetClientSite(This,pClientSite)	\
    (This)->lpVtbl -> SetClientSite(This,pClientSite)

#define IOleObject_GetClientSite(This,ppClientSite)	\
    (This)->lpVtbl -> GetClientSite(This,ppClientSite)

#define IOleObject_SetHostNames(This,szContainerApp,szContainerObj)	\
    (This)->lpVtbl -> SetHostNames(This,szContainerApp,szContainerObj)

#define IOleObject_Close(This,dwSaveOption)	\
    (This)->lpVtbl -> Close(This,dwSaveOption)

#define IOleObject_SetMoniker(This,dwWhichMoniker,pmk)	\
    (This)->lpVtbl -> SetMoniker(This,dwWhichMoniker,pmk)

#define IOleObject_GetMoniker(This,dwAssign,dwWhichMoniker,ppmk)	\
    (This)->lpVtbl -> GetMoniker(This,dwAssign,dwWhichMoniker,ppmk)

#define IOleObject_InitFromData(This,pDataObject,fCreation,dwReserved)	\
    (This)->lpVtbl -> InitFromData(This,pDataObject,fCreation,dwReserved)

#define IOleObject_GetClipboardData(This,dwReserved,ppDataObject)	\
    (This)->lpVtbl -> GetClipboardData(This,dwReserved,ppDataObject)

#define IOleObject_DoVerb(This,iVerb,lpmsg,pActiveSite,lindex,hwndParent,lprcPosRect)	\
    (This)->lpVtbl -> DoVerb(This,iVerb,lpmsg,pActiveSite,lindex,hwndParent,lprcPosRect)

#define IOleObject_EnumVerbs(This,ppEnumOleVerb)	\
    (This)->lpVtbl -> EnumVerbs(This,ppEnumOleVerb)

#define IOleObject_Update(This)	\
    (This)->lpVtbl -> Update(This)

#define IOleObject_IsUpToDate(This)	\
    (This)->lpVtbl -> IsUpToDate(This)

#define IOleObject_GetUserClassID(This,pClsid)	\
    (This)->lpVtbl -> GetUserClassID(This,pClsid)

#define IOleObject_GetUserType(This,dwFormOfType,pszUserType)	\
    (This)->lpVtbl -> GetUserType(This,dwFormOfType,pszUserType)

#define IOleObject_SetExtent(This,dwDrawAspect,psizel)	\
    (This)->lpVtbl -> SetExtent(This,dwDrawAspect,psizel)

#define IOleObject_GetExtent(This,dwDrawAspect,psizel)	\
    (This)->lpVtbl -> GetExtent(This,dwDrawAspect,psizel)

#define IOleObject_Advise(This,pAdvSink,pdwConnection)	\
    (This)->lpVtbl -> Advise(This,pAdvSink,pdwConnection)

#define IOleObject_Unadvise(This,dwConnection)	\
    (This)->lpVtbl -> Unadvise(This,dwConnection)

#define IOleObject_EnumAdvise(This,ppenumAdvise)	\
    (This)->lpVtbl -> EnumAdvise(This,ppenumAdvise)

#define IOleObject_GetMiscStatus(This,dwAspect,pdwStatus)	\
    (This)->lpVtbl -> GetMiscStatus(This,dwAspect,pdwStatus)

#define IOleObject_SetColorScheme(This,pLogpal)	\
    (This)->lpVtbl -> SetColorScheme(This,pLogpal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IOleObject_SetClientSite_Proxy( 
    IOleObject  * This,
    /* [unique][in] */ IOleClientSite  *pClientSite);


void __stdcall IOleObject_SetClientSite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleObject_GetClientSite_Proxy( 
    IOleObject  * This,
    /* [out] */ IOleClientSite  * *ppClientSite);


void __stdcall IOleObject_GetClientSite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleObject_SetHostNames_Proxy( 
    IOleObject  * This,
    /* [in] */ LPCOLESTR szContainerApp,
    /* [unique][in] */ LPCOLESTR szContainerObj);


void __stdcall IOleObject_SetHostNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleObject_Close_Proxy( 
    IOleObject  * This,
    /* [in] */ unsigned long dwSaveOption);


void __stdcall IOleObject_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleObject_SetMoniker_Proxy( 
    IOleObject  * This,
    /* [in] */ unsigned long dwWhichMoniker,
    /* [unique][in] */ IMoniker  *pmk);


void __stdcall IOleObject_SetMoniker_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleObject_GetMoniker_Proxy( 
    IOleObject  * This,
    /* [in] */ unsigned long dwAssign,
    /* [in] */ unsigned long dwWhichMoniker,
    /* [out] */ IMoniker  * *ppmk);


void __stdcall IOleObject_GetMoniker_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleObject_InitFromData_Proxy( 
    IOleObject  * This,
    /* [unique][in] */ IDataObject  *pDataObject,
    /* [in] */ BOOL fCreation,
    /* [in] */ unsigned long dwReserved);


void __stdcall IOleObject_InitFromData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleObject_GetClipboardData_Proxy( 
    IOleObject  * This,
    /* [in] */ unsigned long dwReserved,
    /* [out] */ IDataObject  * *ppDataObject);


void __stdcall IOleObject_GetClipboardData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleObject_DoVerb_Proxy( 
    IOleObject  * This,
    /* [in] */ LONG iVerb,
    /* [unique][in] */ LPMSG lpmsg,
    /* [unique][in] */ IOleClientSite  *pActiveSite,
    /* [in] */ LONG lindex,
    /* [in] */ HWND hwndParent,
    /* [unique][in] */ LPCRECT lprcPosRect);


void __stdcall IOleObject_DoVerb_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleObject_EnumVerbs_Proxy( 
    IOleObject  * This,
    /* [out] */ IEnumOLEVERB  * *ppEnumOleVerb);


void __stdcall IOleObject_EnumVerbs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleObject_Update_Proxy( 
    IOleObject  * This);


void __stdcall IOleObject_Update_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleObject_IsUpToDate_Proxy( 
    IOleObject  * This);


void __stdcall IOleObject_IsUpToDate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleObject_GetUserClassID_Proxy( 
    IOleObject  * This,
    /* [out] */ CLSID  *pClsid);


void __stdcall IOleObject_GetUserClassID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleObject_GetUserType_Proxy( 
    IOleObject  * This,
    /* [in] */ unsigned long dwFormOfType,
    /* [out] */ LPOLESTR  *pszUserType);


void __stdcall IOleObject_GetUserType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleObject_SetExtent_Proxy( 
    IOleObject  * This,
    /* [in] */ unsigned long dwDrawAspect,
    /* [in] */ SIZEL  *psizel);


void __stdcall IOleObject_SetExtent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleObject_GetExtent_Proxy( 
    IOleObject  * This,
    /* [in] */ unsigned long dwDrawAspect,
    /* [out] */ SIZEL  *psizel);


void __stdcall IOleObject_GetExtent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleObject_Advise_Proxy( 
    IOleObject  * This,
    /* [unique][in] */ IAdviseSink  *pAdvSink,
    /* [out] */ unsigned long  *pdwConnection);


void __stdcall IOleObject_Advise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleObject_Unadvise_Proxy( 
    IOleObject  * This,
    /* [in] */ unsigned long dwConnection);


void __stdcall IOleObject_Unadvise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleObject_EnumAdvise_Proxy( 
    IOleObject  * This,
    /* [out] */ IEnumSTATDATA  * *ppenumAdvise);


void __stdcall IOleObject_EnumAdvise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleObject_GetMiscStatus_Proxy( 
    IOleObject  * This,
    /* [in] */ unsigned long dwAspect,
    /* [out] */ unsigned long  *pdwStatus);


void __stdcall IOleObject_GetMiscStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleObject_SetColorScheme_Proxy( 
    IOleObject  * This,
    /* [in] */ LOGPALETTE  *pLogpal);


void __stdcall IOleObject_SetColorScheme_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IOleObject_INTERFACE_DEFINED__ */


#ifndef __IOLETypes_INTERFACE_DEFINED__
#define __IOLETypes_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOLETypes
 * at Fri Jul 12 18:09:28 1996
 * using MIDL 3.00.44
 ****************************************/
/* [auto_handle][uuid] */ 


typedef 
enum tagOLERENDER
    {	OLERENDER_NONE	= 0,
	OLERENDER_DRAW	= 1,
	OLERENDER_FORMAT	= 2,
	OLERENDER_ASIS	= 3
    }	OLERENDER;

typedef OLERENDER  *LPOLERENDER;

typedef struct  tagOBJECTDESCRIPTOR
    {
    unsigned long cbSize;
    CLSID clsid;
    unsigned long dwDrawAspect;
    SIZEL sizel;
    POINTL pointl;
    unsigned long dwStatus;
    unsigned long dwFullUserTypeName;
    unsigned long dwSrcOfCopy;
    }	OBJECTDESCRIPTOR;

typedef struct tagOBJECTDESCRIPTOR  *POBJECTDESCRIPTOR;

typedef struct tagOBJECTDESCRIPTOR  *LPOBJECTDESCRIPTOR;

typedef struct tagOBJECTDESCRIPTOR LINKSRCDESCRIPTOR;

typedef struct tagOBJECTDESCRIPTOR  *PLINKSRCDESCRIPTOR;

typedef struct tagOBJECTDESCRIPTOR  *LPLINKSRCDESCRIPTOR;



extern RPC_IF_HANDLE IOLETypes_v0_0_c_ifspec;
extern RPC_IF_HANDLE IOLETypes_v0_0_s_ifspec;
#endif /* __IOLETypes_INTERFACE_DEFINED__ */

#ifndef __IOleWindow_INTERFACE_DEFINED__
#define __IOleWindow_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOleWindow
 * at Fri Jul 12 18:09:28 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IOleWindow  *LPOLEWINDOW;


EXTERN_C const IID IID_IOleWindow;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IOleWindow : public IUnknown
    {
    public:
        virtual /* [input_sync] */ HRESULT __stdcall GetWindow( 
            /* [out] */ HWND  *phwnd) = 0;
        
        virtual HRESULT __stdcall ContextSensitiveHelp( 
            /* [in] */ BOOL fEnterMode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOleWindowVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IOleWindow  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IOleWindow  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IOleWindow  * This);
        
        /* [input_sync] */ HRESULT ( __stdcall  *GetWindow )( 
            IOleWindow  * This,
            /* [out] */ HWND  *phwnd);
        
        HRESULT ( __stdcall  *ContextSensitiveHelp )( 
            IOleWindow  * This,
            /* [in] */ BOOL fEnterMode);
        
        END_INTERFACE
    } IOleWindowVtbl;

    interface IOleWindow
    {
        CONST_VTBL struct IOleWindowVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleWindow_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOleWindow_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOleWindow_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOleWindow_GetWindow(This,phwnd)	\
    (This)->lpVtbl -> GetWindow(This,phwnd)

#define IOleWindow_ContextSensitiveHelp(This,fEnterMode)	\
    (This)->lpVtbl -> ContextSensitiveHelp(This,fEnterMode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [input_sync] */ HRESULT __stdcall IOleWindow_GetWindow_Proxy( 
    IOleWindow  * This,
    /* [out] */ HWND  *phwnd);


void __stdcall IOleWindow_GetWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleWindow_ContextSensitiveHelp_Proxy( 
    IOleWindow  * This,
    /* [in] */ BOOL fEnterMode);


void __stdcall IOleWindow_ContextSensitiveHelp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IOleWindow_INTERFACE_DEFINED__ */


#ifndef __IOleLink_INTERFACE_DEFINED__
#define __IOleLink_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOleLink
 * at Fri Jul 12 18:09:28 1996
 * using MIDL 3.00.44
 ****************************************/
/* [uuid][object] */ 


typedef /* [unique] */ IOleLink  *LPOLELINK;

typedef 
enum tagOLEUPDATE
    {	OLEUPDATE_ALWAYS	= 1,
	OLEUPDATE_ONCALL	= 3
    }	OLEUPDATE;

typedef OLEUPDATE  *LPOLEUPDATE;

typedef OLEUPDATE  *POLEUPDATE;

typedef 
enum tagOLELINKBIND
    {	OLELINKBIND_EVENIFCLASSDIFF	= 1
    }	OLELINKBIND;


EXTERN_C const IID IID_IOleLink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IOleLink : public IUnknown
    {
    public:
        virtual HRESULT __stdcall SetUpdateOptions( 
            /* [in] */ unsigned long dwUpdateOpt) = 0;
        
        virtual HRESULT __stdcall GetUpdateOptions( 
            /* [out] */ unsigned long  *pdwUpdateOpt) = 0;
        
        virtual HRESULT __stdcall SetSourceMoniker( 
            /* [unique][in] */ IMoniker  *pmk,
            /* [in] */ REFCLSID rclsid) = 0;
        
        virtual HRESULT __stdcall GetSourceMoniker( 
            /* [out] */ IMoniker  * *ppmk) = 0;
        
        virtual HRESULT __stdcall SetSourceDisplayName( 
            /* [in] */ LPCOLESTR pszStatusText) = 0;
        
        virtual HRESULT __stdcall GetSourceDisplayName( 
            /* [out] */ LPOLESTR  *ppszDisplayName) = 0;
        
        virtual HRESULT __stdcall BindToSource( 
            /* [in] */ unsigned long bindflags,
            /* [unique][in] */ IBindCtx  *pbc) = 0;
        
        virtual HRESULT __stdcall BindIfRunning( void) = 0;
        
        virtual HRESULT __stdcall GetBoundSource( 
            /* [out] */ IUnknown  * *ppunk) = 0;
        
        virtual HRESULT __stdcall UnbindSource( void) = 0;
        
        virtual HRESULT __stdcall Update( 
            /* [unique][in] */ IBindCtx  *pbc) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOleLinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IOleLink  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IOleLink  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IOleLink  * This);
        
        HRESULT ( __stdcall  *SetUpdateOptions )( 
            IOleLink  * This,
            /* [in] */ unsigned long dwUpdateOpt);
        
        HRESULT ( __stdcall  *GetUpdateOptions )( 
            IOleLink  * This,
            /* [out] */ unsigned long  *pdwUpdateOpt);
        
        HRESULT ( __stdcall  *SetSourceMoniker )( 
            IOleLink  * This,
            /* [unique][in] */ IMoniker  *pmk,
            /* [in] */ REFCLSID rclsid);
        
        HRESULT ( __stdcall  *GetSourceMoniker )( 
            IOleLink  * This,
            /* [out] */ IMoniker  * *ppmk);
        
        HRESULT ( __stdcall  *SetSourceDisplayName )( 
            IOleLink  * This,
            /* [in] */ LPCOLESTR pszStatusText);
        
        HRESULT ( __stdcall  *GetSourceDisplayName )( 
            IOleLink  * This,
            /* [out] */ LPOLESTR  *ppszDisplayName);
        
        HRESULT ( __stdcall  *BindToSource )( 
            IOleLink  * This,
            /* [in] */ unsigned long bindflags,
            /* [unique][in] */ IBindCtx  *pbc);
        
        HRESULT ( __stdcall  *BindIfRunning )( 
            IOleLink  * This);
        
        HRESULT ( __stdcall  *GetBoundSource )( 
            IOleLink  * This,
            /* [out] */ IUnknown  * *ppunk);
        
        HRESULT ( __stdcall  *UnbindSource )( 
            IOleLink  * This);
        
        HRESULT ( __stdcall  *Update )( 
            IOleLink  * This,
            /* [unique][in] */ IBindCtx  *pbc);
        
        END_INTERFACE
    } IOleLinkVtbl;

    interface IOleLink
    {
        CONST_VTBL struct IOleLinkVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleLink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOleLink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOleLink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOleLink_SetUpdateOptions(This,dwUpdateOpt)	\
    (This)->lpVtbl -> SetUpdateOptions(This,dwUpdateOpt)

#define IOleLink_GetUpdateOptions(This,pdwUpdateOpt)	\
    (This)->lpVtbl -> GetUpdateOptions(This,pdwUpdateOpt)

#define IOleLink_SetSourceMoniker(This,pmk,rclsid)	\
    (This)->lpVtbl -> SetSourceMoniker(This,pmk,rclsid)

#define IOleLink_GetSourceMoniker(This,ppmk)	\
    (This)->lpVtbl -> GetSourceMoniker(This,ppmk)

#define IOleLink_SetSourceDisplayName(This,pszStatusText)	\
    (This)->lpVtbl -> SetSourceDisplayName(This,pszStatusText)

#define IOleLink_GetSourceDisplayName(This,ppszDisplayName)	\
    (This)->lpVtbl -> GetSourceDisplayName(This,ppszDisplayName)

#define IOleLink_BindToSource(This,bindflags,pbc)	\
    (This)->lpVtbl -> BindToSource(This,bindflags,pbc)

#define IOleLink_BindIfRunning(This)	\
    (This)->lpVtbl -> BindIfRunning(This)

#define IOleLink_GetBoundSource(This,ppunk)	\
    (This)->lpVtbl -> GetBoundSource(This,ppunk)

#define IOleLink_UnbindSource(This)	\
    (This)->lpVtbl -> UnbindSource(This)

#define IOleLink_Update(This,pbc)	\
    (This)->lpVtbl -> Update(This,pbc)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IOleLink_SetUpdateOptions_Proxy( 
    IOleLink  * This,
    /* [in] */ unsigned long dwUpdateOpt);


void __stdcall IOleLink_SetUpdateOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleLink_GetUpdateOptions_Proxy( 
    IOleLink  * This,
    /* [out] */ unsigned long  *pdwUpdateOpt);


void __stdcall IOleLink_GetUpdateOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleLink_SetSourceMoniker_Proxy( 
    IOleLink  * This,
    /* [unique][in] */ IMoniker  *pmk,
    /* [in] */ REFCLSID rclsid);


void __stdcall IOleLink_SetSourceMoniker_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleLink_GetSourceMoniker_Proxy( 
    IOleLink  * This,
    /* [out] */ IMoniker  * *ppmk);


void __stdcall IOleLink_GetSourceMoniker_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleLink_SetSourceDisplayName_Proxy( 
    IOleLink  * This,
    /* [in] */ LPCOLESTR pszStatusText);


void __stdcall IOleLink_SetSourceDisplayName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleLink_GetSourceDisplayName_Proxy( 
    IOleLink  * This,
    /* [out] */ LPOLESTR  *ppszDisplayName);


void __stdcall IOleLink_GetSourceDisplayName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleLink_BindToSource_Proxy( 
    IOleLink  * This,
    /* [in] */ unsigned long bindflags,
    /* [unique][in] */ IBindCtx  *pbc);


void __stdcall IOleLink_BindToSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleLink_BindIfRunning_Proxy( 
    IOleLink  * This);


void __stdcall IOleLink_BindIfRunning_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleLink_GetBoundSource_Proxy( 
    IOleLink  * This,
    /* [out] */ IUnknown  * *ppunk);


void __stdcall IOleLink_GetBoundSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleLink_UnbindSource_Proxy( 
    IOleLink  * This);


void __stdcall IOleLink_UnbindSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleLink_Update_Proxy( 
    IOleLink  * This,
    /* [unique][in] */ IBindCtx  *pbc);


void __stdcall IOleLink_Update_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IOleLink_INTERFACE_DEFINED__ */


#ifndef __IOleItemContainer_INTERFACE_DEFINED__
#define __IOleItemContainer_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOleItemContainer
 * at Fri Jul 12 18:09:28 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IOleItemContainer  *LPOLEITEMCONTAINER;

typedef 
enum tagBINDSPEED
    {	BINDSPEED_INDEFINITE	= 1,
	BINDSPEED_MODERATE	= 2,
	BINDSPEED_IMMEDIATE	= 3
    }	BINDSPEED;

typedef /* [v1_enum] */ 
enum tagOLECONTF
    {	OLECONTF_EMBEDDINGS	= 1,
	OLECONTF_LINKS	= 2,
	OLECONTF_OTHERS	= 4,
	OLECONTF_ONLYUSER	= 8,
	OLECONTF_ONLYIFRUNNING	= 16
    }	OLECONTF;


EXTERN_C const IID IID_IOleItemContainer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IOleItemContainer : public IOleContainer
    {
    public:
        virtual /* [local] */ HRESULT __stdcall GetObject( 
            /* [in] */ LPOLESTR pszItem,
            /* [in] */ unsigned long dwSpeedNeeded,
            /* [unique][in] */ IBindCtx  *pbc,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject) = 0;
        
        virtual /* [local] */ HRESULT __stdcall GetObjectStorage( 
            /* [in] */ LPOLESTR pszItem,
            /* [unique][in] */ IBindCtx  *pbc,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvStorage) = 0;
        
        virtual HRESULT __stdcall IsRunning( 
            /* [in] */ LPOLESTR pszItem) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOleItemContainerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IOleItemContainer  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IOleItemContainer  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IOleItemContainer  * This);
        
        HRESULT ( __stdcall  *ParseDisplayName )( 
            IOleItemContainer  * This,
            /* [unique][in] */ IBindCtx  *pbc,
            /* [in] */ LPOLESTR pszDisplayName,
            /* [out] */ unsigned long  *pchEaten,
            /* [out] */ IMoniker  * *ppmkOut);
        
        HRESULT ( __stdcall  *EnumObjects )( 
            IOleItemContainer  * This,
            /* [in] */ unsigned long grfFlags,
            /* [out] */ IEnumUnknown  * *ppenum);
        
        HRESULT ( __stdcall  *LockContainer )( 
            IOleItemContainer  * This,
            /* [in] */ BOOL fLock);
        
        /* [local] */ HRESULT ( __stdcall  *GetObject )( 
            IOleItemContainer  * This,
            /* [in] */ LPOLESTR pszItem,
            /* [in] */ unsigned long dwSpeedNeeded,
            /* [unique][in] */ IBindCtx  *pbc,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        /* [local] */ HRESULT ( __stdcall  *GetObjectStorage )( 
            IOleItemContainer  * This,
            /* [in] */ LPOLESTR pszItem,
            /* [unique][in] */ IBindCtx  *pbc,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvStorage);
        
        HRESULT ( __stdcall  *IsRunning )( 
            IOleItemContainer  * This,
            /* [in] */ LPOLESTR pszItem);
        
        END_INTERFACE
    } IOleItemContainerVtbl;

    interface IOleItemContainer
    {
        CONST_VTBL struct IOleItemContainerVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleItemContainer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOleItemContainer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOleItemContainer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOleItemContainer_ParseDisplayName(This,pbc,pszDisplayName,pchEaten,ppmkOut)	\
    (This)->lpVtbl -> ParseDisplayName(This,pbc,pszDisplayName,pchEaten,ppmkOut)


#define IOleItemContainer_EnumObjects(This,grfFlags,ppenum)	\
    (This)->lpVtbl -> EnumObjects(This,grfFlags,ppenum)

#define IOleItemContainer_LockContainer(This,fLock)	\
    (This)->lpVtbl -> LockContainer(This,fLock)


#define IOleItemContainer_GetObject(This,pszItem,dwSpeedNeeded,pbc,riid,ppvObject)	\
    (This)->lpVtbl -> GetObject(This,pszItem,dwSpeedNeeded,pbc,riid,ppvObject)

#define IOleItemContainer_GetObjectStorage(This,pszItem,pbc,riid,ppvStorage)	\
    (This)->lpVtbl -> GetObjectStorage(This,pszItem,pbc,riid,ppvStorage)

#define IOleItemContainer_IsRunning(This,pszItem)	\
    (This)->lpVtbl -> IsRunning(This,pszItem)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall IOleItemContainer_RemoteGetObject_Proxy( 
    IOleItemContainer  * This,
    /* [in] */ LPOLESTR pszItem,
    /* [in] */ unsigned long dwSpeedNeeded,
    /* [unique][in] */ IBindCtx  *pbc,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown  * *ppvObject);


void __stdcall IOleItemContainer_RemoteGetObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall IOleItemContainer_RemoteGetObjectStorage_Proxy( 
    IOleItemContainer  * This,
    /* [in] */ LPOLESTR pszItem,
    /* [unique][in] */ IBindCtx  *pbc,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown  * *ppvStorage);


void __stdcall IOleItemContainer_RemoteGetObjectStorage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleItemContainer_IsRunning_Proxy( 
    IOleItemContainer  * This,
    /* [in] */ LPOLESTR pszItem);


void __stdcall IOleItemContainer_IsRunning_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IOleItemContainer_INTERFACE_DEFINED__ */


#ifndef __IOleInPlaceUIWindow_INTERFACE_DEFINED__
#define __IOleInPlaceUIWindow_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOleInPlaceUIWindow
 * at Fri Jul 12 18:09:28 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IOleInPlaceUIWindow  *LPOLEINPLACEUIWINDOW;

typedef RECT BORDERWIDTHS;

typedef LPRECT LPBORDERWIDTHS;

typedef LPCRECT LPCBORDERWIDTHS;


EXTERN_C const IID IID_IOleInPlaceUIWindow;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IOleInPlaceUIWindow : public IOleWindow
    {
    public:
        virtual /* [input_sync] */ HRESULT __stdcall GetBorder( 
            /* [out] */ LPRECT lprectBorder) = 0;
        
        virtual /* [input_sync] */ HRESULT __stdcall RequestBorderSpace( 
            /* [unique][in] */ LPCBORDERWIDTHS pborderwidths) = 0;
        
        virtual /* [input_sync] */ HRESULT __stdcall SetBorderSpace( 
            /* [unique][in] */ LPCBORDERWIDTHS pborderwidths) = 0;
        
        virtual HRESULT __stdcall SetActiveObject( 
            /* [unique][in] */ IOleInPlaceActiveObject  *pActiveObject,
            /* [unique][string][in] */ LPCOLESTR pszObjName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOleInPlaceUIWindowVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IOleInPlaceUIWindow  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IOleInPlaceUIWindow  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IOleInPlaceUIWindow  * This);
        
        /* [input_sync] */ HRESULT ( __stdcall  *GetWindow )( 
            IOleInPlaceUIWindow  * This,
            /* [out] */ HWND  *phwnd);
        
        HRESULT ( __stdcall  *ContextSensitiveHelp )( 
            IOleInPlaceUIWindow  * This,
            /* [in] */ BOOL fEnterMode);
        
        /* [input_sync] */ HRESULT ( __stdcall  *GetBorder )( 
            IOleInPlaceUIWindow  * This,
            /* [out] */ LPRECT lprectBorder);
        
        /* [input_sync] */ HRESULT ( __stdcall  *RequestBorderSpace )( 
            IOleInPlaceUIWindow  * This,
            /* [unique][in] */ LPCBORDERWIDTHS pborderwidths);
        
        /* [input_sync] */ HRESULT ( __stdcall  *SetBorderSpace )( 
            IOleInPlaceUIWindow  * This,
            /* [unique][in] */ LPCBORDERWIDTHS pborderwidths);
        
        HRESULT ( __stdcall  *SetActiveObject )( 
            IOleInPlaceUIWindow  * This,
            /* [unique][in] */ IOleInPlaceActiveObject  *pActiveObject,
            /* [unique][string][in] */ LPCOLESTR pszObjName);
        
        END_INTERFACE
    } IOleInPlaceUIWindowVtbl;

    interface IOleInPlaceUIWindow
    {
        CONST_VTBL struct IOleInPlaceUIWindowVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleInPlaceUIWindow_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOleInPlaceUIWindow_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOleInPlaceUIWindow_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOleInPlaceUIWindow_GetWindow(This,phwnd)	\
    (This)->lpVtbl -> GetWindow(This,phwnd)

#define IOleInPlaceUIWindow_ContextSensitiveHelp(This,fEnterMode)	\
    (This)->lpVtbl -> ContextSensitiveHelp(This,fEnterMode)


#define IOleInPlaceUIWindow_GetBorder(This,lprectBorder)	\
    (This)->lpVtbl -> GetBorder(This,lprectBorder)

#define IOleInPlaceUIWindow_RequestBorderSpace(This,pborderwidths)	\
    (This)->lpVtbl -> RequestBorderSpace(This,pborderwidths)

#define IOleInPlaceUIWindow_SetBorderSpace(This,pborderwidths)	\
    (This)->lpVtbl -> SetBorderSpace(This,pborderwidths)

#define IOleInPlaceUIWindow_SetActiveObject(This,pActiveObject,pszObjName)	\
    (This)->lpVtbl -> SetActiveObject(This,pActiveObject,pszObjName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [input_sync] */ HRESULT __stdcall IOleInPlaceUIWindow_GetBorder_Proxy( 
    IOleInPlaceUIWindow  * This,
    /* [out] */ LPRECT lprectBorder);


void __stdcall IOleInPlaceUIWindow_GetBorder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [input_sync] */ HRESULT __stdcall IOleInPlaceUIWindow_RequestBorderSpace_Proxy( 
    IOleInPlaceUIWindow  * This,
    /* [unique][in] */ LPCBORDERWIDTHS pborderwidths);


void __stdcall IOleInPlaceUIWindow_RequestBorderSpace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [input_sync] */ HRESULT __stdcall IOleInPlaceUIWindow_SetBorderSpace_Proxy( 
    IOleInPlaceUIWindow  * This,
    /* [unique][in] */ LPCBORDERWIDTHS pborderwidths);


void __stdcall IOleInPlaceUIWindow_SetBorderSpace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceUIWindow_SetActiveObject_Proxy( 
    IOleInPlaceUIWindow  * This,
    /* [unique][in] */ IOleInPlaceActiveObject  *pActiveObject,
    /* [unique][string][in] */ LPCOLESTR pszObjName);


void __stdcall IOleInPlaceUIWindow_SetActiveObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IOleInPlaceUIWindow_INTERFACE_DEFINED__ */


#ifndef __IOleInPlaceActiveObject_INTERFACE_DEFINED__
#define __IOleInPlaceActiveObject_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOleInPlaceActiveObject
 * at Fri Jul 12 18:09:28 1996
 * using MIDL 3.00.44
 ****************************************/
/* [uuid][object] */ 


typedef /* [unique] */ IOleInPlaceActiveObject  *LPOLEINPLACEACTIVEOBJECT;


EXTERN_C const IID IID_IOleInPlaceActiveObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IOleInPlaceActiveObject : public IOleWindow
    {
    public:
        virtual /* [local] */ HRESULT __stdcall TranslateAccelerator( 
            /* [in] */ LPMSG lpmsg) = 0;
        
        virtual /* [input_sync] */ HRESULT __stdcall OnFrameWindowActivate( 
            /* [in] */ BOOL fActivate) = 0;
        
        virtual /* [input_sync] */ HRESULT __stdcall OnDocWindowActivate( 
            /* [in] */ BOOL fActivate) = 0;
        
        virtual /* [local] */ HRESULT __stdcall ResizeBorder( 
            /* [in] */ LPCRECT prcBorder,
            /* [unique][in] */ IOleInPlaceUIWindow  *pUIWindow,
            /* [in] */ BOOL fFrameWindow) = 0;
        
        virtual HRESULT __stdcall EnableModeless( 
            /* [in] */ BOOL fEnable) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOleInPlaceActiveObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IOleInPlaceActiveObject  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IOleInPlaceActiveObject  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IOleInPlaceActiveObject  * This);
        
        /* [input_sync] */ HRESULT ( __stdcall  *GetWindow )( 
            IOleInPlaceActiveObject  * This,
            /* [out] */ HWND  *phwnd);
        
        HRESULT ( __stdcall  *ContextSensitiveHelp )( 
            IOleInPlaceActiveObject  * This,
            /* [in] */ BOOL fEnterMode);
        
        /* [local] */ HRESULT ( __stdcall  *TranslateAccelerator )( 
            IOleInPlaceActiveObject  * This,
            /* [in] */ LPMSG lpmsg);
        
        /* [input_sync] */ HRESULT ( __stdcall  *OnFrameWindowActivate )( 
            IOleInPlaceActiveObject  * This,
            /* [in] */ BOOL fActivate);
        
        /* [input_sync] */ HRESULT ( __stdcall  *OnDocWindowActivate )( 
            IOleInPlaceActiveObject  * This,
            /* [in] */ BOOL fActivate);
        
        /* [local] */ HRESULT ( __stdcall  *ResizeBorder )( 
            IOleInPlaceActiveObject  * This,
            /* [in] */ LPCRECT prcBorder,
            /* [unique][in] */ IOleInPlaceUIWindow  *pUIWindow,
            /* [in] */ BOOL fFrameWindow);
        
        HRESULT ( __stdcall  *EnableModeless )( 
            IOleInPlaceActiveObject  * This,
            /* [in] */ BOOL fEnable);
        
        END_INTERFACE
    } IOleInPlaceActiveObjectVtbl;

    interface IOleInPlaceActiveObject
    {
        CONST_VTBL struct IOleInPlaceActiveObjectVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleInPlaceActiveObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOleInPlaceActiveObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOleInPlaceActiveObject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOleInPlaceActiveObject_GetWindow(This,phwnd)	\
    (This)->lpVtbl -> GetWindow(This,phwnd)

#define IOleInPlaceActiveObject_ContextSensitiveHelp(This,fEnterMode)	\
    (This)->lpVtbl -> ContextSensitiveHelp(This,fEnterMode)


#define IOleInPlaceActiveObject_TranslateAccelerator(This,lpmsg)	\
    (This)->lpVtbl -> TranslateAccelerator(This,lpmsg)

#define IOleInPlaceActiveObject_OnFrameWindowActivate(This,fActivate)	\
    (This)->lpVtbl -> OnFrameWindowActivate(This,fActivate)

#define IOleInPlaceActiveObject_OnDocWindowActivate(This,fActivate)	\
    (This)->lpVtbl -> OnDocWindowActivate(This,fActivate)

#define IOleInPlaceActiveObject_ResizeBorder(This,prcBorder,pUIWindow,fFrameWindow)	\
    (This)->lpVtbl -> ResizeBorder(This,prcBorder,pUIWindow,fFrameWindow)

#define IOleInPlaceActiveObject_EnableModeless(This,fEnable)	\
    (This)->lpVtbl -> EnableModeless(This,fEnable)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall IOleInPlaceActiveObject_RemoteTranslateAccelerator_Proxy( 
    IOleInPlaceActiveObject  * This);


void __stdcall IOleInPlaceActiveObject_RemoteTranslateAccelerator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [input_sync] */ HRESULT __stdcall IOleInPlaceActiveObject_OnFrameWindowActivate_Proxy( 
    IOleInPlaceActiveObject  * This,
    /* [in] */ BOOL fActivate);


void __stdcall IOleInPlaceActiveObject_OnFrameWindowActivate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [input_sync] */ HRESULT __stdcall IOleInPlaceActiveObject_OnDocWindowActivate_Proxy( 
    IOleInPlaceActiveObject  * This,
    /* [in] */ BOOL fActivate);


void __stdcall IOleInPlaceActiveObject_OnDocWindowActivate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [input_sync][call_as] */ HRESULT __stdcall IOleInPlaceActiveObject_RemoteResizeBorder_Proxy( 
    IOleInPlaceActiveObject  * This,
    /* [in] */ LPCRECT prcBorder,
    /* [in] */ REFIID riid,
    /* [iid_is][unique][in] */ IOleInPlaceUIWindow  *pUIWindow,
    /* [in] */ BOOL fFrameWindow);


void __stdcall IOleInPlaceActiveObject_RemoteResizeBorder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceActiveObject_EnableModeless_Proxy( 
    IOleInPlaceActiveObject  * This,
    /* [in] */ BOOL fEnable);


void __stdcall IOleInPlaceActiveObject_EnableModeless_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IOleInPlaceActiveObject_INTERFACE_DEFINED__ */


#ifndef __IOleInPlaceFrame_INTERFACE_DEFINED__
#define __IOleInPlaceFrame_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOleInPlaceFrame
 * at Fri Jul 12 18:09:28 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IOleInPlaceFrame  *LPOLEINPLACEFRAME;

typedef struct  tagOIFI
    {
    UINT cb;
    BOOL fMDIApp;
    HWND hwndFrame;
    HACCEL haccel;
    UINT cAccelEntries;
    }	OLEINPLACEFRAMEINFO;

typedef struct tagOIFI  *LPOLEINPLACEFRAMEINFO;

typedef struct  tagOleMenuGroupWidths
    {
    LONG width[ 6 ];
    }	OLEMENUGROUPWIDTHS;

typedef struct tagOleMenuGroupWidths  *LPOLEMENUGROUPWIDTHS;

typedef HGLOBAL HOLEMENU;


EXTERN_C const IID IID_IOleInPlaceFrame;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IOleInPlaceFrame : public IOleInPlaceUIWindow
    {
    public:
        virtual HRESULT __stdcall InsertMenus( 
            /* [in] */ HMENU hmenuShared,
            /* [out][in] */ LPOLEMENUGROUPWIDTHS lpMenuWidths) = 0;
        
        virtual /* [input_sync] */ HRESULT __stdcall SetMenu( 
            /* [in] */ HMENU hmenuShared,
            /* [in] */ HOLEMENU holemenu,
            /* [in] */ HWND hwndActiveObject) = 0;
        
        virtual HRESULT __stdcall RemoveMenus( 
            /* [in] */ HMENU hmenuShared) = 0;
        
        virtual /* [input_sync] */ HRESULT __stdcall SetStatusText( 
            /* [in] */ LPCOLESTR pszStatusText) = 0;
        
        virtual HRESULT __stdcall EnableModeless( 
            /* [in] */ BOOL fEnable) = 0;
        
        virtual HRESULT __stdcall TranslateAccelerator( 
            /* [in] */ LPMSG lpmsg,
            /* [in] */ WORD wID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOleInPlaceFrameVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IOleInPlaceFrame  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IOleInPlaceFrame  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IOleInPlaceFrame  * This);
        
        /* [input_sync] */ HRESULT ( __stdcall  *GetWindow )( 
            IOleInPlaceFrame  * This,
            /* [out] */ HWND  *phwnd);
        
        HRESULT ( __stdcall  *ContextSensitiveHelp )( 
            IOleInPlaceFrame  * This,
            /* [in] */ BOOL fEnterMode);
        
        /* [input_sync] */ HRESULT ( __stdcall  *GetBorder )( 
            IOleInPlaceFrame  * This,
            /* [out] */ LPRECT lprectBorder);
        
        /* [input_sync] */ HRESULT ( __stdcall  *RequestBorderSpace )( 
            IOleInPlaceFrame  * This,
            /* [unique][in] */ LPCBORDERWIDTHS pborderwidths);
        
        /* [input_sync] */ HRESULT ( __stdcall  *SetBorderSpace )( 
            IOleInPlaceFrame  * This,
            /* [unique][in] */ LPCBORDERWIDTHS pborderwidths);
        
        HRESULT ( __stdcall  *SetActiveObject )( 
            IOleInPlaceFrame  * This,
            /* [unique][in] */ IOleInPlaceActiveObject  *pActiveObject,
            /* [unique][string][in] */ LPCOLESTR pszObjName);
        
        HRESULT ( __stdcall  *InsertMenus )( 
            IOleInPlaceFrame  * This,
            /* [in] */ HMENU hmenuShared,
            /* [out][in] */ LPOLEMENUGROUPWIDTHS lpMenuWidths);
        
        /* [input_sync] */ HRESULT ( __stdcall  *SetMenu )( 
            IOleInPlaceFrame  * This,
            /* [in] */ HMENU hmenuShared,
            /* [in] */ HOLEMENU holemenu,
            /* [in] */ HWND hwndActiveObject);
        
        HRESULT ( __stdcall  *RemoveMenus )( 
            IOleInPlaceFrame  * This,
            /* [in] */ HMENU hmenuShared);
        
        /* [input_sync] */ HRESULT ( __stdcall  *SetStatusText )( 
            IOleInPlaceFrame  * This,
            /* [in] */ LPCOLESTR pszStatusText);
        
        HRESULT ( __stdcall  *EnableModeless )( 
            IOleInPlaceFrame  * This,
            /* [in] */ BOOL fEnable);
        
        HRESULT ( __stdcall  *TranslateAccelerator )( 
            IOleInPlaceFrame  * This,
            /* [in] */ LPMSG lpmsg,
            /* [in] */ WORD wID);
        
        END_INTERFACE
    } IOleInPlaceFrameVtbl;

    interface IOleInPlaceFrame
    {
        CONST_VTBL struct IOleInPlaceFrameVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleInPlaceFrame_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOleInPlaceFrame_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOleInPlaceFrame_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOleInPlaceFrame_GetWindow(This,phwnd)	\
    (This)->lpVtbl -> GetWindow(This,phwnd)

#define IOleInPlaceFrame_ContextSensitiveHelp(This,fEnterMode)	\
    (This)->lpVtbl -> ContextSensitiveHelp(This,fEnterMode)


#define IOleInPlaceFrame_GetBorder(This,lprectBorder)	\
    (This)->lpVtbl -> GetBorder(This,lprectBorder)

#define IOleInPlaceFrame_RequestBorderSpace(This,pborderwidths)	\
    (This)->lpVtbl -> RequestBorderSpace(This,pborderwidths)

#define IOleInPlaceFrame_SetBorderSpace(This,pborderwidths)	\
    (This)->lpVtbl -> SetBorderSpace(This,pborderwidths)

#define IOleInPlaceFrame_SetActiveObject(This,pActiveObject,pszObjName)	\
    (This)->lpVtbl -> SetActiveObject(This,pActiveObject,pszObjName)


#define IOleInPlaceFrame_InsertMenus(This,hmenuShared,lpMenuWidths)	\
    (This)->lpVtbl -> InsertMenus(This,hmenuShared,lpMenuWidths)

#define IOleInPlaceFrame_SetMenu(This,hmenuShared,holemenu,hwndActiveObject)	\
    (This)->lpVtbl -> SetMenu(This,hmenuShared,holemenu,hwndActiveObject)

#define IOleInPlaceFrame_RemoveMenus(This,hmenuShared)	\
    (This)->lpVtbl -> RemoveMenus(This,hmenuShared)

#define IOleInPlaceFrame_SetStatusText(This,pszStatusText)	\
    (This)->lpVtbl -> SetStatusText(This,pszStatusText)

#define IOleInPlaceFrame_EnableModeless(This,fEnable)	\
    (This)->lpVtbl -> EnableModeless(This,fEnable)

#define IOleInPlaceFrame_TranslateAccelerator(This,lpmsg,wID)	\
    (This)->lpVtbl -> TranslateAccelerator(This,lpmsg,wID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IOleInPlaceFrame_InsertMenus_Proxy( 
    IOleInPlaceFrame  * This,
    /* [in] */ HMENU hmenuShared,
    /* [out][in] */ LPOLEMENUGROUPWIDTHS lpMenuWidths);


void __stdcall IOleInPlaceFrame_InsertMenus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [input_sync] */ HRESULT __stdcall IOleInPlaceFrame_SetMenu_Proxy( 
    IOleInPlaceFrame  * This,
    /* [in] */ HMENU hmenuShared,
    /* [in] */ HOLEMENU holemenu,
    /* [in] */ HWND hwndActiveObject);


void __stdcall IOleInPlaceFrame_SetMenu_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceFrame_RemoveMenus_Proxy( 
    IOleInPlaceFrame  * This,
    /* [in] */ HMENU hmenuShared);


void __stdcall IOleInPlaceFrame_RemoveMenus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [input_sync] */ HRESULT __stdcall IOleInPlaceFrame_SetStatusText_Proxy( 
    IOleInPlaceFrame  * This,
    /* [in] */ LPCOLESTR pszStatusText);


void __stdcall IOleInPlaceFrame_SetStatusText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceFrame_EnableModeless_Proxy( 
    IOleInPlaceFrame  * This,
    /* [in] */ BOOL fEnable);


void __stdcall IOleInPlaceFrame_EnableModeless_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceFrame_TranslateAccelerator_Proxy( 
    IOleInPlaceFrame  * This,
    /* [in] */ LPMSG lpmsg,
    /* [in] */ WORD wID);


void __stdcall IOleInPlaceFrame_TranslateAccelerator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IOleInPlaceFrame_INTERFACE_DEFINED__ */


#ifndef __IOleInPlaceObject_INTERFACE_DEFINED__
#define __IOleInPlaceObject_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOleInPlaceObject
 * at Fri Jul 12 18:09:28 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IOleInPlaceObject  *LPOLEINPLACEOBJECT;


EXTERN_C const IID IID_IOleInPlaceObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IOleInPlaceObject : public IOleWindow
    {
    public:
        virtual HRESULT __stdcall InPlaceDeactivate( void) = 0;
        
        virtual HRESULT __stdcall UIDeactivate( void) = 0;
        
        virtual /* [input_sync] */ HRESULT __stdcall SetObjectRects( 
            /* [in] */ LPCRECT lprcPosRect,
            /* [in] */ LPCRECT lprcClipRect) = 0;
        
        virtual HRESULT __stdcall ReactivateAndUndo( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOleInPlaceObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IOleInPlaceObject  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IOleInPlaceObject  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IOleInPlaceObject  * This);
        
        /* [input_sync] */ HRESULT ( __stdcall  *GetWindow )( 
            IOleInPlaceObject  * This,
            /* [out] */ HWND  *phwnd);
        
        HRESULT ( __stdcall  *ContextSensitiveHelp )( 
            IOleInPlaceObject  * This,
            /* [in] */ BOOL fEnterMode);
        
        HRESULT ( __stdcall  *InPlaceDeactivate )( 
            IOleInPlaceObject  * This);
        
        HRESULT ( __stdcall  *UIDeactivate )( 
            IOleInPlaceObject  * This);
        
        /* [input_sync] */ HRESULT ( __stdcall  *SetObjectRects )( 
            IOleInPlaceObject  * This,
            /* [in] */ LPCRECT lprcPosRect,
            /* [in] */ LPCRECT lprcClipRect);
        
        HRESULT ( __stdcall  *ReactivateAndUndo )( 
            IOleInPlaceObject  * This);
        
        END_INTERFACE
    } IOleInPlaceObjectVtbl;

    interface IOleInPlaceObject
    {
        CONST_VTBL struct IOleInPlaceObjectVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleInPlaceObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOleInPlaceObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOleInPlaceObject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOleInPlaceObject_GetWindow(This,phwnd)	\
    (This)->lpVtbl -> GetWindow(This,phwnd)

#define IOleInPlaceObject_ContextSensitiveHelp(This,fEnterMode)	\
    (This)->lpVtbl -> ContextSensitiveHelp(This,fEnterMode)


#define IOleInPlaceObject_InPlaceDeactivate(This)	\
    (This)->lpVtbl -> InPlaceDeactivate(This)

#define IOleInPlaceObject_UIDeactivate(This)	\
    (This)->lpVtbl -> UIDeactivate(This)

#define IOleInPlaceObject_SetObjectRects(This,lprcPosRect,lprcClipRect)	\
    (This)->lpVtbl -> SetObjectRects(This,lprcPosRect,lprcClipRect)

#define IOleInPlaceObject_ReactivateAndUndo(This)	\
    (This)->lpVtbl -> ReactivateAndUndo(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IOleInPlaceObject_InPlaceDeactivate_Proxy( 
    IOleInPlaceObject  * This);


void __stdcall IOleInPlaceObject_InPlaceDeactivate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceObject_UIDeactivate_Proxy( 
    IOleInPlaceObject  * This);


void __stdcall IOleInPlaceObject_UIDeactivate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [input_sync] */ HRESULT __stdcall IOleInPlaceObject_SetObjectRects_Proxy( 
    IOleInPlaceObject  * This,
    /* [in] */ LPCRECT lprcPosRect,
    /* [in] */ LPCRECT lprcClipRect);


void __stdcall IOleInPlaceObject_SetObjectRects_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceObject_ReactivateAndUndo_Proxy( 
    IOleInPlaceObject  * This);


void __stdcall IOleInPlaceObject_ReactivateAndUndo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IOleInPlaceObject_INTERFACE_DEFINED__ */


#ifndef __IOleInPlaceSite_INTERFACE_DEFINED__
#define __IOleInPlaceSite_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOleInPlaceSite
 * at Fri Jul 12 18:09:28 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IOleInPlaceSite  *LPOLEINPLACESITE;


EXTERN_C const IID IID_IOleInPlaceSite;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IOleInPlaceSite : public IOleWindow
    {
    public:
        virtual HRESULT __stdcall CanInPlaceActivate( void) = 0;
        
        virtual HRESULT __stdcall OnInPlaceActivate( void) = 0;
        
        virtual HRESULT __stdcall OnUIActivate( void) = 0;
        
        virtual HRESULT __stdcall GetWindowContext( 
            /* [out] */ IOleInPlaceFrame  * *ppFrame,
            /* [out] */ IOleInPlaceUIWindow  * *ppDoc,
            /* [out] */ LPRECT lprcPosRect,
            /* [out] */ LPRECT lprcClipRect,
            /* [out][in] */ LPOLEINPLACEFRAMEINFO lpFrameInfo) = 0;
        
        virtual HRESULT __stdcall Scroll( 
            /* [in] */ SIZE scrollExtant) = 0;
        
        virtual HRESULT __stdcall OnUIDeactivate( 
            /* [in] */ BOOL fUndoable) = 0;
        
        virtual HRESULT __stdcall OnInPlaceDeactivate( void) = 0;
        
        virtual HRESULT __stdcall DiscardUndoState( void) = 0;
        
        virtual HRESULT __stdcall DeactivateAndUndo( void) = 0;
        
        virtual HRESULT __stdcall OnPosRectChange( 
            /* [in] */ LPCRECT lprcPosRect) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOleInPlaceSiteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IOleInPlaceSite  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IOleInPlaceSite  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IOleInPlaceSite  * This);
        
        /* [input_sync] */ HRESULT ( __stdcall  *GetWindow )( 
            IOleInPlaceSite  * This,
            /* [out] */ HWND  *phwnd);
        
        HRESULT ( __stdcall  *ContextSensitiveHelp )( 
            IOleInPlaceSite  * This,
            /* [in] */ BOOL fEnterMode);
        
        HRESULT ( __stdcall  *CanInPlaceActivate )( 
            IOleInPlaceSite  * This);
        
        HRESULT ( __stdcall  *OnInPlaceActivate )( 
            IOleInPlaceSite  * This);
        
        HRESULT ( __stdcall  *OnUIActivate )( 
            IOleInPlaceSite  * This);
        
        HRESULT ( __stdcall  *GetWindowContext )( 
            IOleInPlaceSite  * This,
            /* [out] */ IOleInPlaceFrame  * *ppFrame,
            /* [out] */ IOleInPlaceUIWindow  * *ppDoc,
            /* [out] */ LPRECT lprcPosRect,
            /* [out] */ LPRECT lprcClipRect,
            /* [out][in] */ LPOLEINPLACEFRAMEINFO lpFrameInfo);
        
        HRESULT ( __stdcall  *Scroll )( 
            IOleInPlaceSite  * This,
            /* [in] */ SIZE scrollExtant);
        
        HRESULT ( __stdcall  *OnUIDeactivate )( 
            IOleInPlaceSite  * This,
            /* [in] */ BOOL fUndoable);
        
        HRESULT ( __stdcall  *OnInPlaceDeactivate )( 
            IOleInPlaceSite  * This);
        
        HRESULT ( __stdcall  *DiscardUndoState )( 
            IOleInPlaceSite  * This);
        
        HRESULT ( __stdcall  *DeactivateAndUndo )( 
            IOleInPlaceSite  * This);
        
        HRESULT ( __stdcall  *OnPosRectChange )( 
            IOleInPlaceSite  * This,
            /* [in] */ LPCRECT lprcPosRect);
        
        END_INTERFACE
    } IOleInPlaceSiteVtbl;

    interface IOleInPlaceSite
    {
        CONST_VTBL struct IOleInPlaceSiteVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleInPlaceSite_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOleInPlaceSite_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOleInPlaceSite_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOleInPlaceSite_GetWindow(This,phwnd)	\
    (This)->lpVtbl -> GetWindow(This,phwnd)

#define IOleInPlaceSite_ContextSensitiveHelp(This,fEnterMode)	\
    (This)->lpVtbl -> ContextSensitiveHelp(This,fEnterMode)


#define IOleInPlaceSite_CanInPlaceActivate(This)	\
    (This)->lpVtbl -> CanInPlaceActivate(This)

#define IOleInPlaceSite_OnInPlaceActivate(This)	\
    (This)->lpVtbl -> OnInPlaceActivate(This)

#define IOleInPlaceSite_OnUIActivate(This)	\
    (This)->lpVtbl -> OnUIActivate(This)

#define IOleInPlaceSite_GetWindowContext(This,ppFrame,ppDoc,lprcPosRect,lprcClipRect,lpFrameInfo)	\
    (This)->lpVtbl -> GetWindowContext(This,ppFrame,ppDoc,lprcPosRect,lprcClipRect,lpFrameInfo)

#define IOleInPlaceSite_Scroll(This,scrollExtant)	\
    (This)->lpVtbl -> Scroll(This,scrollExtant)

#define IOleInPlaceSite_OnUIDeactivate(This,fUndoable)	\
    (This)->lpVtbl -> OnUIDeactivate(This,fUndoable)

#define IOleInPlaceSite_OnInPlaceDeactivate(This)	\
    (This)->lpVtbl -> OnInPlaceDeactivate(This)

#define IOleInPlaceSite_DiscardUndoState(This)	\
    (This)->lpVtbl -> DiscardUndoState(This)

#define IOleInPlaceSite_DeactivateAndUndo(This)	\
    (This)->lpVtbl -> DeactivateAndUndo(This)

#define IOleInPlaceSite_OnPosRectChange(This,lprcPosRect)	\
    (This)->lpVtbl -> OnPosRectChange(This,lprcPosRect)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IOleInPlaceSite_CanInPlaceActivate_Proxy( 
    IOleInPlaceSite  * This);


void __stdcall IOleInPlaceSite_CanInPlaceActivate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceSite_OnInPlaceActivate_Proxy( 
    IOleInPlaceSite  * This);


void __stdcall IOleInPlaceSite_OnInPlaceActivate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceSite_OnUIActivate_Proxy( 
    IOleInPlaceSite  * This);


void __stdcall IOleInPlaceSite_OnUIActivate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceSite_GetWindowContext_Proxy( 
    IOleInPlaceSite  * This,
    /* [out] */ IOleInPlaceFrame  * *ppFrame,
    /* [out] */ IOleInPlaceUIWindow  * *ppDoc,
    /* [out] */ LPRECT lprcPosRect,
    /* [out] */ LPRECT lprcClipRect,
    /* [out][in] */ LPOLEINPLACEFRAMEINFO lpFrameInfo);


void __stdcall IOleInPlaceSite_GetWindowContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceSite_Scroll_Proxy( 
    IOleInPlaceSite  * This,
    /* [in] */ SIZE scrollExtant);


void __stdcall IOleInPlaceSite_Scroll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceSite_OnUIDeactivate_Proxy( 
    IOleInPlaceSite  * This,
    /* [in] */ BOOL fUndoable);


void __stdcall IOleInPlaceSite_OnUIDeactivate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceSite_OnInPlaceDeactivate_Proxy( 
    IOleInPlaceSite  * This);


void __stdcall IOleInPlaceSite_OnInPlaceDeactivate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceSite_DiscardUndoState_Proxy( 
    IOleInPlaceSite  * This);


void __stdcall IOleInPlaceSite_DiscardUndoState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceSite_DeactivateAndUndo_Proxy( 
    IOleInPlaceSite  * This);


void __stdcall IOleInPlaceSite_DeactivateAndUndo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceSite_OnPosRectChange_Proxy( 
    IOleInPlaceSite  * This,
    /* [in] */ LPCRECT lprcPosRect);


void __stdcall IOleInPlaceSite_OnPosRectChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IOleInPlaceSite_INTERFACE_DEFINED__ */


#ifndef __IContinue_INTERFACE_DEFINED__
#define __IContinue_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IContinue
 * at Fri Jul 12 18:09:28 1996
 * using MIDL 3.00.44
 ****************************************/
/* [uuid][object] */ 



EXTERN_C const IID IID_IContinue;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IContinue : public IUnknown
    {
    public:
        virtual HRESULT __stdcall FContinue( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IContinueVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IContinue  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IContinue  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IContinue  * This);
        
        HRESULT ( __stdcall  *FContinue )( 
            IContinue  * This);
        
        END_INTERFACE
    } IContinueVtbl;

    interface IContinue
    {
        CONST_VTBL struct IContinueVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IContinue_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IContinue_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IContinue_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IContinue_FContinue(This)	\
    (This)->lpVtbl -> FContinue(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IContinue_FContinue_Proxy( 
    IContinue  * This);


void __stdcall IContinue_FContinue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IContinue_INTERFACE_DEFINED__ */


#ifndef __IViewObject_INTERFACE_DEFINED__
#define __IViewObject_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IViewObject
 * at Fri Jul 12 18:09:28 1996
 * using MIDL 3.00.44
 ****************************************/
/* [uuid][object] */ 


typedef /* [unique] */ IViewObject  *LPVIEWOBJECT;


EXTERN_C const IID IID_IViewObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IViewObject : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT __stdcall Draw( 
            /* [in] */ unsigned long dwDrawAspect,
            /* [in] */ LONG lindex,
            /* [unique][in] */ void  *pvAspect,
            /* [unique][in] */ DVTARGETDEVICE  *ptd,
            /* [in] */ HDC hdcTargetDev,
            /* [in] */ HDC hdcDraw,
            /* [in] */ LPCRECTL lprcBounds,
            /* [unique][in] */ LPCRECTL lprcWBounds,
            /* [in] */ BOOL ( __stdcall  *pfnContinue )( 
                unsigned long dwContinue),
            /* [in] */ unsigned long dwContinue) = 0;
        
        virtual /* [local] */ HRESULT __stdcall GetColorSet( 
            /* [in] */ unsigned long dwDrawAspect,
            /* [in] */ LONG lindex,
            /* [unique][in] */ void  *pvAspect,
            /* [unique][in] */ DVTARGETDEVICE  *ptd,
            /* [in] */ HDC hicTargetDev,
            /* [out] */ LOGPALETTE  * *ppColorSet) = 0;
        
        virtual /* [local] */ HRESULT __stdcall Freeze( 
            /* [in] */ unsigned long dwDrawAspect,
            /* [in] */ LONG lindex,
            /* [unique][in] */ void  *pvAspect,
            /* [out] */ unsigned long  *pdwFreeze) = 0;
        
        virtual HRESULT __stdcall Unfreeze( 
            /* [in] */ unsigned long dwFreeze) = 0;
        
        virtual HRESULT __stdcall SetAdvise( 
            /* [in] */ unsigned long aspects,
            /* [in] */ unsigned long advf,
            /* [unique][in] */ IAdviseSink  *pAdvSink) = 0;
        
        virtual HRESULT __stdcall GetAdvise( 
            /* [out] */ unsigned long  *pAspects,
            /* [out] */ unsigned long  *pAdvf,
            /* [out] */ IAdviseSink  * *ppAdvSink) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IViewObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IViewObject  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IViewObject  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IViewObject  * This);
        
        /* [local] */ HRESULT ( __stdcall  *Draw )( 
            IViewObject  * This,
            /* [in] */ unsigned long dwDrawAspect,
            /* [in] */ LONG lindex,
            /* [unique][in] */ void  *pvAspect,
            /* [unique][in] */ DVTARGETDEVICE  *ptd,
            /* [in] */ HDC hdcTargetDev,
            /* [in] */ HDC hdcDraw,
            /* [in] */ LPCRECTL lprcBounds,
            /* [unique][in] */ LPCRECTL lprcWBounds,
            /* [in] */ BOOL ( __stdcall  *pfnContinue )( 
                unsigned long dwContinue),
            /* [in] */ unsigned long dwContinue);
        
        /* [local] */ HRESULT ( __stdcall  *GetColorSet )( 
            IViewObject  * This,
            /* [in] */ unsigned long dwDrawAspect,
            /* [in] */ LONG lindex,
            /* [unique][in] */ void  *pvAspect,
            /* [unique][in] */ DVTARGETDEVICE  *ptd,
            /* [in] */ HDC hicTargetDev,
            /* [out] */ LOGPALETTE  * *ppColorSet);
        
        /* [local] */ HRESULT ( __stdcall  *Freeze )( 
            IViewObject  * This,
            /* [in] */ unsigned long dwDrawAspect,
            /* [in] */ LONG lindex,
            /* [unique][in] */ void  *pvAspect,
            /* [out] */ unsigned long  *pdwFreeze);
        
        HRESULT ( __stdcall  *Unfreeze )( 
            IViewObject  * This,
            /* [in] */ unsigned long dwFreeze);
        
        HRESULT ( __stdcall  *SetAdvise )( 
            IViewObject  * This,
            /* [in] */ unsigned long aspects,
            /* [in] */ unsigned long advf,
            /* [unique][in] */ IAdviseSink  *pAdvSink);
        
        HRESULT ( __stdcall  *GetAdvise )( 
            IViewObject  * This,
            /* [out] */ unsigned long  *pAspects,
            /* [out] */ unsigned long  *pAdvf,
            /* [out] */ IAdviseSink  * *ppAdvSink);
        
        END_INTERFACE
    } IViewObjectVtbl;

    interface IViewObject
    {
        CONST_VTBL struct IViewObjectVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IViewObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IViewObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IViewObject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IViewObject_Draw(This,dwDrawAspect,lindex,pvAspect,ptd,hdcTargetDev,hdcDraw,lprcBounds,lprcWBounds,pfnContinue,dwContinue)	\
    (This)->lpVtbl -> Draw(This,dwDrawAspect,lindex,pvAspect,ptd,hdcTargetDev,hdcDraw,lprcBounds,lprcWBounds,pfnContinue,dwContinue)

#define IViewObject_GetColorSet(This,dwDrawAspect,lindex,pvAspect,ptd,hicTargetDev,ppColorSet)	\
    (This)->lpVtbl -> GetColorSet(This,dwDrawAspect,lindex,pvAspect,ptd,hicTargetDev,ppColorSet)

#define IViewObject_Freeze(This,dwDrawAspect,lindex,pvAspect,pdwFreeze)	\
    (This)->lpVtbl -> Freeze(This,dwDrawAspect,lindex,pvAspect,pdwFreeze)

#define IViewObject_Unfreeze(This,dwFreeze)	\
    (This)->lpVtbl -> Unfreeze(This,dwFreeze)

#define IViewObject_SetAdvise(This,aspects,advf,pAdvSink)	\
    (This)->lpVtbl -> SetAdvise(This,aspects,advf,pAdvSink)

#define IViewObject_GetAdvise(This,pAspects,pAdvf,ppAdvSink)	\
    (This)->lpVtbl -> GetAdvise(This,pAspects,pAdvf,ppAdvSink)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall IViewObject_RemoteDraw_Proxy( 
    IViewObject  * This,
    /* [in] */ unsigned long dwDrawAspect,
    /* [in] */ LONG lindex,
    /* [in] */ unsigned long pvAspect,
    /* [unique][in] */ DVTARGETDEVICE  *ptd,
    /* [in] */ unsigned long hdcTargetDev,
    /* [in] */ unsigned long hdcDraw,
    /* [in] */ LPCRECTL lprcBounds,
    /* [unique][in] */ LPCRECTL lprcWBounds,
    /* [in] */ IContinue  *pContinue);


void __stdcall IViewObject_RemoteDraw_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall IViewObject_RemoteGetColorSet_Proxy( 
    IViewObject  * This,
    /* [in] */ unsigned long dwDrawAspect,
    /* [in] */ LONG lindex,
    /* [in] */ unsigned long pvAspect,
    /* [unique][in] */ DVTARGETDEVICE  *ptd,
    /* [in] */ unsigned long hicTargetDev,
    /* [out] */ LOGPALETTE  * *ppColorSet);


void __stdcall IViewObject_RemoteGetColorSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall IViewObject_RemoteFreeze_Proxy( 
    IViewObject  * This,
    /* [in] */ unsigned long dwDrawAspect,
    /* [in] */ LONG lindex,
    /* [in] */ unsigned long pvAspect,
    /* [out] */ unsigned long  *pdwFreeze);


void __stdcall IViewObject_RemoteFreeze_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IViewObject_Unfreeze_Proxy( 
    IViewObject  * This,
    /* [in] */ unsigned long dwFreeze);


void __stdcall IViewObject_Unfreeze_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IViewObject_SetAdvise_Proxy( 
    IViewObject  * This,
    /* [in] */ unsigned long aspects,
    /* [in] */ unsigned long advf,
    /* [unique][in] */ IAdviseSink  *pAdvSink);


void __stdcall IViewObject_SetAdvise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IViewObject_GetAdvise_Proxy( 
    IViewObject  * This,
    /* [out] */ unsigned long  *pAspects,
    /* [out] */ unsigned long  *pAdvf,
    /* [out] */ IAdviseSink  * *ppAdvSink);


void __stdcall IViewObject_GetAdvise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IViewObject_INTERFACE_DEFINED__ */


#ifndef __IViewObject2_INTERFACE_DEFINED__
#define __IViewObject2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IViewObject2
 * at Fri Jul 12 18:09:28 1996
 * using MIDL 3.00.44
 ****************************************/
/* [uuid][object] */ 


typedef /* [unique] */ IViewObject2  *LPVIEWOBJECT2;


EXTERN_C const IID IID_IViewObject2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IViewObject2 : public IViewObject
    {
    public:
        virtual HRESULT __stdcall GetExtent( 
            /* [in] */ unsigned long dwDrawAspect,
            /* [in] */ LONG lindex,
            /* [unique][in] */ DVTARGETDEVICE  *ptd,
            /* [out] */ LPSIZEL lpsizel) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IViewObject2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IViewObject2  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IViewObject2  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IViewObject2  * This);
        
        /* [local] */ HRESULT ( __stdcall  *Draw )( 
            IViewObject2  * This,
            /* [in] */ unsigned long dwDrawAspect,
            /* [in] */ LONG lindex,
            /* [unique][in] */ void  *pvAspect,
            /* [unique][in] */ DVTARGETDEVICE  *ptd,
            /* [in] */ HDC hdcTargetDev,
            /* [in] */ HDC hdcDraw,
            /* [in] */ LPCRECTL lprcBounds,
            /* [unique][in] */ LPCRECTL lprcWBounds,
            /* [in] */ BOOL ( __stdcall  *pfnContinue )( 
                unsigned long dwContinue),
            /* [in] */ unsigned long dwContinue);
        
        /* [local] */ HRESULT ( __stdcall  *GetColorSet )( 
            IViewObject2  * This,
            /* [in] */ unsigned long dwDrawAspect,
            /* [in] */ LONG lindex,
            /* [unique][in] */ void  *pvAspect,
            /* [unique][in] */ DVTARGETDEVICE  *ptd,
            /* [in] */ HDC hicTargetDev,
            /* [out] */ LOGPALETTE  * *ppColorSet);
        
        /* [local] */ HRESULT ( __stdcall  *Freeze )( 
            IViewObject2  * This,
            /* [in] */ unsigned long dwDrawAspect,
            /* [in] */ LONG lindex,
            /* [unique][in] */ void  *pvAspect,
            /* [out] */ unsigned long  *pdwFreeze);
        
        HRESULT ( __stdcall  *Unfreeze )( 
            IViewObject2  * This,
            /* [in] */ unsigned long dwFreeze);
        
        HRESULT ( __stdcall  *SetAdvise )( 
            IViewObject2  * This,
            /* [in] */ unsigned long aspects,
            /* [in] */ unsigned long advf,
            /* [unique][in] */ IAdviseSink  *pAdvSink);
        
        HRESULT ( __stdcall  *GetAdvise )( 
            IViewObject2  * This,
            /* [out] */ unsigned long  *pAspects,
            /* [out] */ unsigned long  *pAdvf,
            /* [out] */ IAdviseSink  * *ppAdvSink);
        
        HRESULT ( __stdcall  *GetExtent )( 
            IViewObject2  * This,
            /* [in] */ unsigned long dwDrawAspect,
            /* [in] */ LONG lindex,
            /* [unique][in] */ DVTARGETDEVICE  *ptd,
            /* [out] */ LPSIZEL lpsizel);
        
        END_INTERFACE
    } IViewObject2Vtbl;

    interface IViewObject2
    {
        CONST_VTBL struct IViewObject2Vtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IViewObject2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IViewObject2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IViewObject2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IViewObject2_Draw(This,dwDrawAspect,lindex,pvAspect,ptd,hdcTargetDev,hdcDraw,lprcBounds,lprcWBounds,pfnContinue,dwContinue)	\
    (This)->lpVtbl -> Draw(This,dwDrawAspect,lindex,pvAspect,ptd,hdcTargetDev,hdcDraw,lprcBounds,lprcWBounds,pfnContinue,dwContinue)

#define IViewObject2_GetColorSet(This,dwDrawAspect,lindex,pvAspect,ptd,hicTargetDev,ppColorSet)	\
    (This)->lpVtbl -> GetColorSet(This,dwDrawAspect,lindex,pvAspect,ptd,hicTargetDev,ppColorSet)

#define IViewObject2_Freeze(This,dwDrawAspect,lindex,pvAspect,pdwFreeze)	\
    (This)->lpVtbl -> Freeze(This,dwDrawAspect,lindex,pvAspect,pdwFreeze)

#define IViewObject2_Unfreeze(This,dwFreeze)	\
    (This)->lpVtbl -> Unfreeze(This,dwFreeze)

#define IViewObject2_SetAdvise(This,aspects,advf,pAdvSink)	\
    (This)->lpVtbl -> SetAdvise(This,aspects,advf,pAdvSink)

#define IViewObject2_GetAdvise(This,pAspects,pAdvf,ppAdvSink)	\
    (This)->lpVtbl -> GetAdvise(This,pAspects,pAdvf,ppAdvSink)


#define IViewObject2_GetExtent(This,dwDrawAspect,lindex,ptd,lpsizel)	\
    (This)->lpVtbl -> GetExtent(This,dwDrawAspect,lindex,ptd,lpsizel)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IViewObject2_GetExtent_Proxy( 
    IViewObject2  * This,
    /* [in] */ unsigned long dwDrawAspect,
    /* [in] */ LONG lindex,
    /* [unique][in] */ DVTARGETDEVICE  *ptd,
    /* [out] */ LPSIZEL lpsizel);


void __stdcall IViewObject2_GetExtent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IViewObject2_INTERFACE_DEFINED__ */


#ifndef __IDropSource_INTERFACE_DEFINED__
#define __IDropSource_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IDropSource
 * at Fri Jul 12 18:09:28 1996
 * using MIDL 3.00.44
 ****************************************/
/* [uuid][object][local] */ 


typedef /* [unique] */ IDropSource  *LPDROPSOURCE;


EXTERN_C const IID IID_IDropSource;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IDropSource : public IUnknown
    {
    public:
        virtual HRESULT __stdcall QueryContinueDrag( 
            /* [in] */ BOOL fEscapePressed,
            /* [in] */ unsigned long grfKeyState) = 0;
        
        virtual HRESULT __stdcall GiveFeedback( 
            /* [in] */ unsigned long dwEffect) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDropSourceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IDropSource  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IDropSource  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IDropSource  * This);
        
        HRESULT ( __stdcall  *QueryContinueDrag )( 
            IDropSource  * This,
            /* [in] */ BOOL fEscapePressed,
            /* [in] */ unsigned long grfKeyState);
        
        HRESULT ( __stdcall  *GiveFeedback )( 
            IDropSource  * This,
            /* [in] */ unsigned long dwEffect);
        
        END_INTERFACE
    } IDropSourceVtbl;

    interface IDropSource
    {
        CONST_VTBL struct IDropSourceVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDropSource_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDropSource_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDropSource_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDropSource_QueryContinueDrag(This,fEscapePressed,grfKeyState)	\
    (This)->lpVtbl -> QueryContinueDrag(This,fEscapePressed,grfKeyState)

#define IDropSource_GiveFeedback(This,dwEffect)	\
    (This)->lpVtbl -> GiveFeedback(This,dwEffect)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IDropSource_QueryContinueDrag_Proxy( 
    IDropSource  * This,
    /* [in] */ BOOL fEscapePressed,
    /* [in] */ unsigned long grfKeyState);


void __stdcall IDropSource_QueryContinueDrag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IDropSource_GiveFeedback_Proxy( 
    IDropSource  * This,
    /* [in] */ unsigned long dwEffect);


void __stdcall IDropSource_GiveFeedback_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IDropSource_INTERFACE_DEFINED__ */


#ifndef __IDropTarget_INTERFACE_DEFINED__
#define __IDropTarget_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IDropTarget
 * at Fri Jul 12 18:09:28 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IDropTarget  *LPDROPTARGET;

#define	MK_ALT	( 0x20 )

#define	DROPEFFECT_NONE	( 0 )

#define	DROPEFFECT_COPY	( 1 )

#define	DROPEFFECT_MOVE	( 2 )

#define	DROPEFFECT_LINK	( 4 )

#define	DROPEFFECT_SCROLL	( 0x80000000 )

// default inset-width of the hot zone, in pixels
//   typical use: GetProfileInt("windows","DragScrollInset",DD_DEFSCROLLINSET)
#define	DD_DEFSCROLLINSET	( 11 )

// default delay before scrolling, in milliseconds
//   typical use: GetProfileInt("windows","DragScrollDelay",DD_DEFSCROLLDELAY)
#define	DD_DEFSCROLLDELAY	( 50 )

// default scroll interval, in milliseconds
//   typical use: GetProfileInt("windows","DragScrollInterval", DD_DEFSCROLLINTERVAL)
#define	DD_DEFSCROLLINTERVAL	( 50 )

// default delay before dragging should start, in milliseconds
//   typical use: GetProfileInt("windows", "DragDelay", DD_DEFDRAGDELAY)
#define	DD_DEFDRAGDELAY	( 200 )

// default minimum distance (radius) before dragging should start, in pixels
//   typical use: GetProfileInt("windows", "DragMinDist", DD_DEFDRAGMINDIST)
#define	DD_DEFDRAGMINDIST	( 2 )


EXTERN_C const IID IID_IDropTarget;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IDropTarget : public IUnknown
    {
    public:
        virtual HRESULT __stdcall DragEnter( 
            /* [unique][in] */ IDataObject  *pDataObj,
            /* [in] */ unsigned long grfKeyState,
            /* [in] */ POINTL pt,
            /* [out][in] */ unsigned long  *pdwEffect) = 0;
        
        virtual HRESULT __stdcall DragOver( 
            /* [in] */ unsigned long grfKeyState,
            /* [in] */ POINTL pt,
            /* [out][in] */ unsigned long  *pdwEffect) = 0;
        
        virtual HRESULT __stdcall DragLeave( void) = 0;
        
        virtual HRESULT __stdcall Drop( 
            /* [unique][in] */ IDataObject  *pDataObj,
            /* [in] */ unsigned long grfKeyState,
            /* [in] */ POINTL pt,
            /* [out][in] */ unsigned long  *pdwEffect) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDropTargetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IDropTarget  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IDropTarget  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IDropTarget  * This);
        
        HRESULT ( __stdcall  *DragEnter )( 
            IDropTarget  * This,
            /* [unique][in] */ IDataObject  *pDataObj,
            /* [in] */ unsigned long grfKeyState,
            /* [in] */ POINTL pt,
            /* [out][in] */ unsigned long  *pdwEffect);
        
        HRESULT ( __stdcall  *DragOver )( 
            IDropTarget  * This,
            /* [in] */ unsigned long grfKeyState,
            /* [in] */ POINTL pt,
            /* [out][in] */ unsigned long  *pdwEffect);
        
        HRESULT ( __stdcall  *DragLeave )( 
            IDropTarget  * This);
        
        HRESULT ( __stdcall  *Drop )( 
            IDropTarget  * This,
            /* [unique][in] */ IDataObject  *pDataObj,
            /* [in] */ unsigned long grfKeyState,
            /* [in] */ POINTL pt,
            /* [out][in] */ unsigned long  *pdwEffect);
        
        END_INTERFACE
    } IDropTargetVtbl;

    interface IDropTarget
    {
        CONST_VTBL struct IDropTargetVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDropTarget_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDropTarget_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDropTarget_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDropTarget_DragEnter(This,pDataObj,grfKeyState,pt,pdwEffect)	\
    (This)->lpVtbl -> DragEnter(This,pDataObj,grfKeyState,pt,pdwEffect)

#define IDropTarget_DragOver(This,grfKeyState,pt,pdwEffect)	\
    (This)->lpVtbl -> DragOver(This,grfKeyState,pt,pdwEffect)

#define IDropTarget_DragLeave(This)	\
    (This)->lpVtbl -> DragLeave(This)

#define IDropTarget_Drop(This,pDataObj,grfKeyState,pt,pdwEffect)	\
    (This)->lpVtbl -> Drop(This,pDataObj,grfKeyState,pt,pdwEffect)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IDropTarget_DragEnter_Proxy( 
    IDropTarget  * This,
    /* [unique][in] */ IDataObject  *pDataObj,
    /* [in] */ unsigned long grfKeyState,
    /* [in] */ POINTL pt,
    /* [out][in] */ unsigned long  *pdwEffect);


void __stdcall IDropTarget_DragEnter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IDropTarget_DragOver_Proxy( 
    IDropTarget  * This,
    /* [in] */ unsigned long grfKeyState,
    /* [in] */ POINTL pt,
    /* [out][in] */ unsigned long  *pdwEffect);


void __stdcall IDropTarget_DragOver_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IDropTarget_DragLeave_Proxy( 
    IDropTarget  * This);


void __stdcall IDropTarget_DragLeave_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IDropTarget_Drop_Proxy( 
    IDropTarget  * This,
    /* [unique][in] */ IDataObject  *pDataObj,
    /* [in] */ unsigned long grfKeyState,
    /* [in] */ POINTL pt,
    /* [out][in] */ unsigned long  *pdwEffect);


void __stdcall IDropTarget_Drop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IDropTarget_INTERFACE_DEFINED__ */


#ifndef __IEnumOLEVERB_INTERFACE_DEFINED__
#define __IEnumOLEVERB_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumOLEVERB
 * at Fri Jul 12 18:09:28 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IEnumOLEVERB  *LPENUMOLEVERB;

typedef struct  tagOLEVERB
    {
    LONG lVerb;
    LPOLESTR lpszVerbName;
    unsigned long fuFlags;
    unsigned long grfAttribs;
    }	OLEVERB;

typedef struct tagOLEVERB  *LPOLEVERB;

typedef /* [v1_enum] */ 
enum tagOLEVERBATTRIB
    {	OLEVERBATTRIB_NEVERDIRTIES	= 1,
	OLEVERBATTRIB_ONCONTAINERMENU	= 2
    }	OLEVERBATTRIB;


EXTERN_C const IID IID_IEnumOLEVERB;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IEnumOLEVERB : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT __stdcall Next( 
            /* [in] */ unsigned long celt,
            /* [length_is][size_is][out] */ LPOLEVERB rgelt,
            /* [out] */ unsigned long  *pceltFetched) = 0;
        
        virtual HRESULT __stdcall Skip( 
            /* [in] */ unsigned long celt) = 0;
        
        virtual HRESULT __stdcall Reset( void) = 0;
        
        virtual HRESULT __stdcall Clone( 
            /* [out] */ IEnumOLEVERB  * *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumOLEVERBVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IEnumOLEVERB  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IEnumOLEVERB  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IEnumOLEVERB  * This);
        
        /* [local] */ HRESULT ( __stdcall  *Next )( 
            IEnumOLEVERB  * This,
            /* [in] */ unsigned long celt,
            /* [length_is][size_is][out] */ LPOLEVERB rgelt,
            /* [out] */ unsigned long  *pceltFetched);
        
        HRESULT ( __stdcall  *Skip )( 
            IEnumOLEVERB  * This,
            /* [in] */ unsigned long celt);
        
        HRESULT ( __stdcall  *Reset )( 
            IEnumOLEVERB  * This);
        
        HRESULT ( __stdcall  *Clone )( 
            IEnumOLEVERB  * This,
            /* [out] */ IEnumOLEVERB  * *ppenum);
        
        END_INTERFACE
    } IEnumOLEVERBVtbl;

    interface IEnumOLEVERB
    {
        CONST_VTBL struct IEnumOLEVERBVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumOLEVERB_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumOLEVERB_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumOLEVERB_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumOLEVERB_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumOLEVERB_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumOLEVERB_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumOLEVERB_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall IEnumOLEVERB_RemoteNext_Proxy( 
    IEnumOLEVERB  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ LPOLEVERB rgelt,
    /* [out] */ unsigned long  *pceltFetched);


void __stdcall IEnumOLEVERB_RemoteNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumOLEVERB_Skip_Proxy( 
    IEnumOLEVERB  * This,
    /* [in] */ unsigned long celt);


void __stdcall IEnumOLEVERB_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumOLEVERB_Reset_Proxy( 
    IEnumOLEVERB  * This);


void __stdcall IEnumOLEVERB_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumOLEVERB_Clone_Proxy( 
    IEnumOLEVERB  * This,
    /* [out] */ IEnumOLEVERB  * *ppenum);


void __stdcall IEnumOLEVERB_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IEnumOLEVERB_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __stdcall  CLIPFORMAT_UserSize(     unsigned long  *, unsigned long            , CLIPFORMAT  * ); 
unsigned char  * __stdcall  CLIPFORMAT_UserMarshal(  unsigned long  *, unsigned char  *, CLIPFORMAT  * ); 
unsigned char  * __stdcall  CLIPFORMAT_UserUnmarshal(unsigned long  *, unsigned char  *, CLIPFORMAT  * ); 
void                      __stdcall  CLIPFORMAT_UserFree(     unsigned long  *, CLIPFORMAT  * ); 

unsigned long             __stdcall  HACCEL_UserSize(     unsigned long  *, unsigned long            , HACCEL  * ); 
unsigned char  * __stdcall  HACCEL_UserMarshal(  unsigned long  *, unsigned char  *, HACCEL  * ); 
unsigned char  * __stdcall  HACCEL_UserUnmarshal(unsigned long  *, unsigned char  *, HACCEL  * ); 
void                      __stdcall  HACCEL_UserFree(     unsigned long  *, HACCEL  * ); 

unsigned long             __stdcall  HGLOBAL_UserSize(     unsigned long  *, unsigned long            , HGLOBAL  * ); 
unsigned char  * __stdcall  HGLOBAL_UserMarshal(  unsigned long  *, unsigned char  *, HGLOBAL  * ); 
unsigned char  * __stdcall  HGLOBAL_UserUnmarshal(unsigned long  *, unsigned char  *, HGLOBAL  * ); 
void                      __stdcall  HGLOBAL_UserFree(     unsigned long  *, HGLOBAL  * ); 

unsigned long             __stdcall  HMENU_UserSize(     unsigned long  *, unsigned long            , HMENU  * ); 
unsigned char  * __stdcall  HMENU_UserMarshal(  unsigned long  *, unsigned char  *, HMENU  * ); 
unsigned char  * __stdcall  HMENU_UserUnmarshal(unsigned long  *, unsigned char  *, HMENU  * ); 
void                      __stdcall  HMENU_UserFree(     unsigned long  *, HMENU  * ); 

unsigned long             __stdcall  HWND_UserSize(     unsigned long  *, unsigned long            , HWND  * ); 
unsigned char  * __stdcall  HWND_UserMarshal(  unsigned long  *, unsigned char  *, HWND  * ); 
unsigned char  * __stdcall  HWND_UserUnmarshal(unsigned long  *, unsigned char  *, HWND  * ); 
void                      __stdcall  HWND_UserFree(     unsigned long  *, HWND  * ); 

unsigned long             __stdcall  STGMEDIUM_UserSize(     unsigned long  *, unsigned long            , STGMEDIUM  * ); 
unsigned char  * __stdcall  STGMEDIUM_UserMarshal(  unsigned long  *, unsigned char  *, STGMEDIUM  * ); 
unsigned char  * __stdcall  STGMEDIUM_UserUnmarshal(unsigned long  *, unsigned char  *, STGMEDIUM  * ); 
void                      __stdcall  STGMEDIUM_UserFree(     unsigned long  *, STGMEDIUM  * ); 

/* [local] */ HRESULT __stdcall IOleCache2_UpdateCache_Proxy( 
    IOleCache2  * This,
    /* [in] */ LPDATAOBJECT pDataObject,
    /* [in] */ unsigned long grfUpdf,
    /* [in] */ void* pReserved);


/* [call_as] */ HRESULT __stdcall IOleCache2_UpdateCache_Stub( 
    IOleCache2  * This,
    /* [in] */ LPDATAOBJECT pDataObject,
    /* [in] */ unsigned long grfUpdf,
    /* [in] */ unsigned long pReserved);

/* [local] */ HRESULT __stdcall IOleItemContainer_GetObject_Proxy( 
    IOleItemContainer  * This,
    /* [in] */ LPOLESTR pszItem,
    /* [in] */ unsigned long dwSpeedNeeded,
    /* [unique][in] */ IBindCtx  *pbc,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void  * *ppvObject);


/* [call_as] */ HRESULT __stdcall IOleItemContainer_GetObject_Stub( 
    IOleItemContainer  * This,
    /* [in] */ LPOLESTR pszItem,
    /* [in] */ unsigned long dwSpeedNeeded,
    /* [unique][in] */ IBindCtx  *pbc,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown  * *ppvObject);

/* [local] */ HRESULT __stdcall IOleItemContainer_GetObjectStorage_Proxy( 
    IOleItemContainer  * This,
    /* [in] */ LPOLESTR pszItem,
    /* [unique][in] */ IBindCtx  *pbc,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void  * *ppvStorage);


/* [call_as] */ HRESULT __stdcall IOleItemContainer_GetObjectStorage_Stub( 
    IOleItemContainer  * This,
    /* [in] */ LPOLESTR pszItem,
    /* [unique][in] */ IBindCtx  *pbc,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown  * *ppvStorage);

/* [local] */ HRESULT __stdcall IOleInPlaceActiveObject_TranslateAccelerator_Proxy( 
    IOleInPlaceActiveObject  * This,
    /* [in] */ LPMSG lpmsg);


/* [call_as] */ HRESULT __stdcall IOleInPlaceActiveObject_TranslateAccelerator_Stub( 
    IOleInPlaceActiveObject  * This);

/* [local] */ HRESULT __stdcall IOleInPlaceActiveObject_ResizeBorder_Proxy( 
    IOleInPlaceActiveObject  * This,
    /* [in] */ LPCRECT prcBorder,
    /* [unique][in] */ IOleInPlaceUIWindow  *pUIWindow,
    /* [in] */ BOOL fFrameWindow);


/* [input_sync][call_as] */ HRESULT __stdcall IOleInPlaceActiveObject_ResizeBorder_Stub( 
    IOleInPlaceActiveObject  * This,
    /* [in] */ LPCRECT prcBorder,
    /* [in] */ REFIID riid,
    /* [iid_is][unique][in] */ IOleInPlaceUIWindow  *pUIWindow,
    /* [in] */ BOOL fFrameWindow);

/* [local] */ HRESULT __stdcall IViewObject_Draw_Proxy( 
    IViewObject  * This,
    /* [in] */ unsigned long dwDrawAspect,
    /* [in] */ LONG lindex,
    /* [unique][in] */ void  *pvAspect,
    /* [unique][in] */ DVTARGETDEVICE  *ptd,
    /* [in] */ HDC hdcTargetDev,
    /* [in] */ HDC hdcDraw,
    /* [in] */ LPCRECTL lprcBounds,
    /* [unique][in] */ LPCRECTL lprcWBounds,
    /* [in] */ BOOL ( __stdcall  *pfnContinue )( 
        unsigned long dwContinue),
    /* [in] */ unsigned long dwContinue);


/* [call_as] */ HRESULT __stdcall IViewObject_Draw_Stub( 
    IViewObject  * This,
    /* [in] */ unsigned long dwDrawAspect,
    /* [in] */ LONG lindex,
    /* [in] */ unsigned long pvAspect,
    /* [unique][in] */ DVTARGETDEVICE  *ptd,
    /* [in] */ unsigned long hdcTargetDev,
    /* [in] */ unsigned long hdcDraw,
    /* [in] */ LPCRECTL lprcBounds,
    /* [unique][in] */ LPCRECTL lprcWBounds,
    /* [in] */ IContinue  *pContinue);

/* [local] */ HRESULT __stdcall IViewObject_GetColorSet_Proxy( 
    IViewObject  * This,
    /* [in] */ unsigned long dwDrawAspect,
    /* [in] */ LONG lindex,
    /* [unique][in] */ void  *pvAspect,
    /* [unique][in] */ DVTARGETDEVICE  *ptd,
    /* [in] */ HDC hicTargetDev,
    /* [out] */ LOGPALETTE  * *ppColorSet);


/* [call_as] */ HRESULT __stdcall IViewObject_GetColorSet_Stub( 
    IViewObject  * This,
    /* [in] */ unsigned long dwDrawAspect,
    /* [in] */ LONG lindex,
    /* [in] */ unsigned long pvAspect,
    /* [unique][in] */ DVTARGETDEVICE  *ptd,
    /* [in] */ unsigned long hicTargetDev,
    /* [out] */ LOGPALETTE  * *ppColorSet);

/* [local] */ HRESULT __stdcall IViewObject_Freeze_Proxy( 
    IViewObject  * This,
    /* [in] */ unsigned long dwDrawAspect,
    /* [in] */ LONG lindex,
    /* [unique][in] */ void  *pvAspect,
    /* [out] */ unsigned long  *pdwFreeze);


/* [call_as] */ HRESULT __stdcall IViewObject_Freeze_Stub( 
    IViewObject  * This,
    /* [in] */ unsigned long dwDrawAspect,
    /* [in] */ LONG lindex,
    /* [in] */ unsigned long pvAspect,
    /* [out] */ unsigned long  *pdwFreeze);

/* [local] */ HRESULT __stdcall IEnumOLEVERB_Next_Proxy( 
    IEnumOLEVERB  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ LPOLEVERB rgelt,
    /* [out] */ unsigned long  *pceltFetched);


/* [call_as] */ HRESULT __stdcall IEnumOLEVERB_Next_Stub( 
    IEnumOLEVERB  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ LPOLEVERB rgelt,
    /* [out] */ unsigned long  *pceltFetched);



/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
