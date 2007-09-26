/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Fri Jul 12 18:09:27 1996
 */
/* Compiler settings for objidl.idl:
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

#ifndef __objidl_h__
#define __objidl_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IMarshal_FWD_DEFINED__
#define __IMarshal_FWD_DEFINED__
typedef interface IMarshal IMarshal;
#endif 	/* __IMarshal_FWD_DEFINED__ */


#ifndef __IMalloc_FWD_DEFINED__
#define __IMalloc_FWD_DEFINED__
typedef interface IMalloc IMalloc;
#endif 	/* __IMalloc_FWD_DEFINED__ */


#ifndef __IMallocSpy_FWD_DEFINED__
#define __IMallocSpy_FWD_DEFINED__
typedef interface IMallocSpy IMallocSpy;
#endif 	/* __IMallocSpy_FWD_DEFINED__ */


#ifndef __IStdMarshalInfo_FWD_DEFINED__
#define __IStdMarshalInfo_FWD_DEFINED__
typedef interface IStdMarshalInfo IStdMarshalInfo;
#endif 	/* __IStdMarshalInfo_FWD_DEFINED__ */


#ifndef __IExternalConnection_FWD_DEFINED__
#define __IExternalConnection_FWD_DEFINED__
typedef interface IExternalConnection IExternalConnection;
#endif 	/* __IExternalConnection_FWD_DEFINED__ */


#ifndef __IMultiQI_FWD_DEFINED__
#define __IMultiQI_FWD_DEFINED__
typedef interface IMultiQI IMultiQI;
#endif 	/* __IMultiQI_FWD_DEFINED__ */


#ifndef __IEnumUnknown_FWD_DEFINED__
#define __IEnumUnknown_FWD_DEFINED__
typedef interface IEnumUnknown IEnumUnknown;
#endif 	/* __IEnumUnknown_FWD_DEFINED__ */


#ifndef __IBindCtx_FWD_DEFINED__
#define __IBindCtx_FWD_DEFINED__
typedef interface IBindCtx IBindCtx;
#endif 	/* __IBindCtx_FWD_DEFINED__ */


#ifndef __IEnumMoniker_FWD_DEFINED__
#define __IEnumMoniker_FWD_DEFINED__
typedef interface IEnumMoniker IEnumMoniker;
#endif 	/* __IEnumMoniker_FWD_DEFINED__ */


#ifndef __IRunnableObject_FWD_DEFINED__
#define __IRunnableObject_FWD_DEFINED__
typedef interface IRunnableObject IRunnableObject;
#endif 	/* __IRunnableObject_FWD_DEFINED__ */


#ifndef __IRunningObjectTable_FWD_DEFINED__
#define __IRunningObjectTable_FWD_DEFINED__
typedef interface IRunningObjectTable IRunningObjectTable;
#endif 	/* __IRunningObjectTable_FWD_DEFINED__ */


#ifndef __IPersist_FWD_DEFINED__
#define __IPersist_FWD_DEFINED__
typedef interface IPersist IPersist;
#endif 	/* __IPersist_FWD_DEFINED__ */


#ifndef __IPersistStream_FWD_DEFINED__
#define __IPersistStream_FWD_DEFINED__
typedef interface IPersistStream IPersistStream;
#endif 	/* __IPersistStream_FWD_DEFINED__ */


#ifndef __IMoniker_FWD_DEFINED__
#define __IMoniker_FWD_DEFINED__
typedef interface IMoniker IMoniker;
#endif 	/* __IMoniker_FWD_DEFINED__ */


#ifndef __IROTData_FWD_DEFINED__
#define __IROTData_FWD_DEFINED__
typedef interface IROTData IROTData;
#endif 	/* __IROTData_FWD_DEFINED__ */


#ifndef __IEnumString_FWD_DEFINED__
#define __IEnumString_FWD_DEFINED__
typedef interface IEnumString IEnumString;
#endif 	/* __IEnumString_FWD_DEFINED__ */


#ifndef __ISequentialStream_FWD_DEFINED__
#define __ISequentialStream_FWD_DEFINED__
typedef interface ISequentialStream ISequentialStream;
#endif 	/* __ISequentialStream_FWD_DEFINED__ */


#ifndef __IStream_FWD_DEFINED__
#define __IStream_FWD_DEFINED__
typedef interface IStream IStream;
#endif 	/* __IStream_FWD_DEFINED__ */


#ifndef __IEnumSTATSTG_FWD_DEFINED__
#define __IEnumSTATSTG_FWD_DEFINED__
typedef interface IEnumSTATSTG IEnumSTATSTG;
#endif 	/* __IEnumSTATSTG_FWD_DEFINED__ */


#ifndef __IStorage_FWD_DEFINED__
#define __IStorage_FWD_DEFINED__
typedef interface IStorage IStorage;
#endif 	/* __IStorage_FWD_DEFINED__ */


#ifndef __IPersistFile_FWD_DEFINED__
#define __IPersistFile_FWD_DEFINED__
typedef interface IPersistFile IPersistFile;
#endif 	/* __IPersistFile_FWD_DEFINED__ */


#ifndef __IPersistStorage_FWD_DEFINED__
#define __IPersistStorage_FWD_DEFINED__
typedef interface IPersistStorage IPersistStorage;
#endif 	/* __IPersistStorage_FWD_DEFINED__ */


#ifndef __ILockBytes_FWD_DEFINED__
#define __ILockBytes_FWD_DEFINED__
typedef interface ILockBytes ILockBytes;
#endif 	/* __ILockBytes_FWD_DEFINED__ */


#ifndef __IEnumFORMATETC_FWD_DEFINED__
#define __IEnumFORMATETC_FWD_DEFINED__
typedef interface IEnumFORMATETC IEnumFORMATETC;
#endif 	/* __IEnumFORMATETC_FWD_DEFINED__ */


#ifndef __IEnumSTATDATA_FWD_DEFINED__
#define __IEnumSTATDATA_FWD_DEFINED__
typedef interface IEnumSTATDATA IEnumSTATDATA;
#endif 	/* __IEnumSTATDATA_FWD_DEFINED__ */


#ifndef __IRootStorage_FWD_DEFINED__
#define __IRootStorage_FWD_DEFINED__
typedef interface IRootStorage IRootStorage;
#endif 	/* __IRootStorage_FWD_DEFINED__ */


#ifndef __IAdviseSink_FWD_DEFINED__
#define __IAdviseSink_FWD_DEFINED__
typedef interface IAdviseSink IAdviseSink;
#endif 	/* __IAdviseSink_FWD_DEFINED__ */


#ifndef __IAdviseSink2_FWD_DEFINED__
#define __IAdviseSink2_FWD_DEFINED__
typedef interface IAdviseSink2 IAdviseSink2;
#endif 	/* __IAdviseSink2_FWD_DEFINED__ */


#ifndef __IDataObject_FWD_DEFINED__
#define __IDataObject_FWD_DEFINED__
typedef interface IDataObject IDataObject;
#endif 	/* __IDataObject_FWD_DEFINED__ */


#ifndef __IDataAdviseHolder_FWD_DEFINED__
#define __IDataAdviseHolder_FWD_DEFINED__
typedef interface IDataAdviseHolder IDataAdviseHolder;
#endif 	/* __IDataAdviseHolder_FWD_DEFINED__ */


#ifndef __IMessageFilter_FWD_DEFINED__
#define __IMessageFilter_FWD_DEFINED__
typedef interface IMessageFilter IMessageFilter;
#endif 	/* __IMessageFilter_FWD_DEFINED__ */


#ifndef __IRpcChannelBuffer_FWD_DEFINED__
#define __IRpcChannelBuffer_FWD_DEFINED__
typedef interface IRpcChannelBuffer IRpcChannelBuffer;
#endif 	/* __IRpcChannelBuffer_FWD_DEFINED__ */


#ifndef __IRpcProxyBuffer_FWD_DEFINED__
#define __IRpcProxyBuffer_FWD_DEFINED__
typedef interface IRpcProxyBuffer IRpcProxyBuffer;
#endif 	/* __IRpcProxyBuffer_FWD_DEFINED__ */


#ifndef __IRpcStubBuffer_FWD_DEFINED__
#define __IRpcStubBuffer_FWD_DEFINED__
typedef interface IRpcStubBuffer IRpcStubBuffer;
#endif 	/* __IRpcStubBuffer_FWD_DEFINED__ */


#ifndef __IPSFactoryBuffer_FWD_DEFINED__
#define __IPSFactoryBuffer_FWD_DEFINED__
typedef interface IPSFactoryBuffer IPSFactoryBuffer;
#endif 	/* __IPSFactoryBuffer_FWD_DEFINED__ */


#ifndef __IChannelHook_FWD_DEFINED__
#define __IChannelHook_FWD_DEFINED__
typedef interface IChannelHook IChannelHook;
#endif 	/* __IChannelHook_FWD_DEFINED__ */


#ifndef __IPropertyStorage_FWD_DEFINED__
#define __IPropertyStorage_FWD_DEFINED__
typedef interface IPropertyStorage IPropertyStorage;
#endif 	/* __IPropertyStorage_FWD_DEFINED__ */


#ifndef __IPropertySetStorage_FWD_DEFINED__
#define __IPropertySetStorage_FWD_DEFINED__
typedef interface IPropertySetStorage IPropertySetStorage;
#endif 	/* __IPropertySetStorage_FWD_DEFINED__ */


#ifndef __IEnumSTATPROPSTG_FWD_DEFINED__
#define __IEnumSTATPROPSTG_FWD_DEFINED__
typedef interface IEnumSTATPROPSTG IEnumSTATPROPSTG;
#endif 	/* __IEnumSTATPROPSTG_FWD_DEFINED__ */


#ifndef __IEnumSTATPROPSETSTG_FWD_DEFINED__
#define __IEnumSTATPROPSETSTG_FWD_DEFINED__
typedef interface IEnumSTATPROPSETSTG IEnumSTATPROPSETSTG;
#endif 	/* __IEnumSTATPROPSETSTG_FWD_DEFINED__ */


#ifndef __IClientSecurity_FWD_DEFINED__
#define __IClientSecurity_FWD_DEFINED__
typedef interface IClientSecurity IClientSecurity;
#endif 	/* __IClientSecurity_FWD_DEFINED__ */


#ifndef __IServerSecurity_FWD_DEFINED__
#define __IServerSecurity_FWD_DEFINED__
typedef interface IServerSecurity IServerSecurity;
#endif 	/* __IServerSecurity_FWD_DEFINED__ */


#ifndef __IClassActivator_FWD_DEFINED__
#define __IClassActivator_FWD_DEFINED__
typedef interface IClassActivator IClassActivator;
#endif 	/* __IClassActivator_FWD_DEFINED__ */


#ifndef __IFillLockBytes_FWD_DEFINED__
#define __IFillLockBytes_FWD_DEFINED__
typedef interface IFillLockBytes IFillLockBytes;
#endif 	/* __IFillLockBytes_FWD_DEFINED__ */


#ifndef __IProgressNotify_FWD_DEFINED__
#define __IProgressNotify_FWD_DEFINED__
typedef interface IProgressNotify IProgressNotify;
#endif 	/* __IProgressNotify_FWD_DEFINED__ */


#ifndef __ILayoutStorage_FWD_DEFINED__
#define __ILayoutStorage_FWD_DEFINED__
typedef interface ILayoutStorage ILayoutStorage;
#endif 	/* __ILayoutStorage_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

void  * __stdcall MIDL_user_allocate(size_t);
void __stdcall MIDL_user_free( void  * ); 

/****************************************
 * Generated header for interface: __MIDL__intf_0000
 * at Fri Jul 12 18:09:27 1996
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

#ifndef __IMarshal_INTERFACE_DEFINED__
#define __IMarshal_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IMarshal
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [uuid][object][local] */ 


typedef /* [unique] */ IMarshal  *LPMARSHAL;


EXTERN_C const IID IID_IMarshal;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IMarshal : public IUnknown
    {
    public:
        virtual HRESULT __stdcall GetUnmarshalClass( 
            /* [in] */ REFIID riid,
            /* [unique][in] */ void  *pv,
            /* [in] */ unsigned long dwDestContext,
            /* [unique][in] */ void  *pvDestContext,
            /* [in] */ unsigned long mshlflags,
            /* [out] */ CLSID  *pCid) = 0;
        
        virtual HRESULT __stdcall GetMarshalSizeMax( 
            /* [in] */ REFIID riid,
            /* [unique][in] */ void  *pv,
            /* [in] */ unsigned long dwDestContext,
            /* [unique][in] */ void  *pvDestContext,
            /* [in] */ unsigned long mshlflags,
            /* [out] */ unsigned long  *pSize) = 0;
        
        virtual HRESULT __stdcall MarshalInterface( 
            /* [unique][in] */ IStream  *pStm,
            /* [in] */ REFIID riid,
            /* [unique][in] */ void  *pv,
            /* [in] */ unsigned long dwDestContext,
            /* [unique][in] */ void  *pvDestContext,
            /* [in] */ unsigned long mshlflags) = 0;
        
        virtual HRESULT __stdcall UnmarshalInterface( 
            /* [unique][in] */ IStream  *pStm,
            /* [in] */ REFIID riid,
            /* [out] */ void  * *ppv) = 0;
        
        virtual HRESULT __stdcall ReleaseMarshalData( 
            /* [unique][in] */ IStream  *pStm) = 0;
        
        virtual HRESULT __stdcall DisconnectObject( 
            /* [in] */ unsigned long dwReserved) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMarshalVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IMarshal  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IMarshal  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IMarshal  * This);
        
        HRESULT ( __stdcall  *GetUnmarshalClass )( 
            IMarshal  * This,
            /* [in] */ REFIID riid,
            /* [unique][in] */ void  *pv,
            /* [in] */ unsigned long dwDestContext,
            /* [unique][in] */ void  *pvDestContext,
            /* [in] */ unsigned long mshlflags,
            /* [out] */ CLSID  *pCid);
        
        HRESULT ( __stdcall  *GetMarshalSizeMax )( 
            IMarshal  * This,
            /* [in] */ REFIID riid,
            /* [unique][in] */ void  *pv,
            /* [in] */ unsigned long dwDestContext,
            /* [unique][in] */ void  *pvDestContext,
            /* [in] */ unsigned long mshlflags,
            /* [out] */ unsigned long  *pSize);
        
        HRESULT ( __stdcall  *MarshalInterface )( 
            IMarshal  * This,
            /* [unique][in] */ IStream  *pStm,
            /* [in] */ REFIID riid,
            /* [unique][in] */ void  *pv,
            /* [in] */ unsigned long dwDestContext,
            /* [unique][in] */ void  *pvDestContext,
            /* [in] */ unsigned long mshlflags);
        
        HRESULT ( __stdcall  *UnmarshalInterface )( 
            IMarshal  * This,
            /* [unique][in] */ IStream  *pStm,
            /* [in] */ REFIID riid,
            /* [out] */ void  * *ppv);
        
        HRESULT ( __stdcall  *ReleaseMarshalData )( 
            IMarshal  * This,
            /* [unique][in] */ IStream  *pStm);
        
        HRESULT ( __stdcall  *DisconnectObject )( 
            IMarshal  * This,
            /* [in] */ unsigned long dwReserved);
        
        END_INTERFACE
    } IMarshalVtbl;

    interface IMarshal
    {
        CONST_VTBL struct IMarshalVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMarshal_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMarshal_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMarshal_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMarshal_GetUnmarshalClass(This,riid,pv,dwDestContext,pvDestContext,mshlflags,pCid)	\
    (This)->lpVtbl -> GetUnmarshalClass(This,riid,pv,dwDestContext,pvDestContext,mshlflags,pCid)

#define IMarshal_GetMarshalSizeMax(This,riid,pv,dwDestContext,pvDestContext,mshlflags,pSize)	\
    (This)->lpVtbl -> GetMarshalSizeMax(This,riid,pv,dwDestContext,pvDestContext,mshlflags,pSize)

#define IMarshal_MarshalInterface(This,pStm,riid,pv,dwDestContext,pvDestContext,mshlflags)	\
    (This)->lpVtbl -> MarshalInterface(This,pStm,riid,pv,dwDestContext,pvDestContext,mshlflags)

#define IMarshal_UnmarshalInterface(This,pStm,riid,ppv)	\
    (This)->lpVtbl -> UnmarshalInterface(This,pStm,riid,ppv)

#define IMarshal_ReleaseMarshalData(This,pStm)	\
    (This)->lpVtbl -> ReleaseMarshalData(This,pStm)

#define IMarshal_DisconnectObject(This,dwReserved)	\
    (This)->lpVtbl -> DisconnectObject(This,dwReserved)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IMarshal_GetUnmarshalClass_Proxy( 
    IMarshal  * This,
    /* [in] */ REFIID riid,
    /* [unique][in] */ void  *pv,
    /* [in] */ unsigned long dwDestContext,
    /* [unique][in] */ void  *pvDestContext,
    /* [in] */ unsigned long mshlflags,
    /* [out] */ CLSID  *pCid);


void __stdcall IMarshal_GetUnmarshalClass_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IMarshal_GetMarshalSizeMax_Proxy( 
    IMarshal  * This,
    /* [in] */ REFIID riid,
    /* [unique][in] */ void  *pv,
    /* [in] */ unsigned long dwDestContext,
    /* [unique][in] */ void  *pvDestContext,
    /* [in] */ unsigned long mshlflags,
    /* [out] */ unsigned long  *pSize);


void __stdcall IMarshal_GetMarshalSizeMax_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IMarshal_MarshalInterface_Proxy( 
    IMarshal  * This,
    /* [unique][in] */ IStream  *pStm,
    /* [in] */ REFIID riid,
    /* [unique][in] */ void  *pv,
    /* [in] */ unsigned long dwDestContext,
    /* [unique][in] */ void  *pvDestContext,
    /* [in] */ unsigned long mshlflags);


void __stdcall IMarshal_MarshalInterface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IMarshal_UnmarshalInterface_Proxy( 
    IMarshal  * This,
    /* [unique][in] */ IStream  *pStm,
    /* [in] */ REFIID riid,
    /* [out] */ void  * *ppv);


void __stdcall IMarshal_UnmarshalInterface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IMarshal_ReleaseMarshalData_Proxy( 
    IMarshal  * This,
    /* [unique][in] */ IStream  *pStm);


void __stdcall IMarshal_ReleaseMarshalData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IMarshal_DisconnectObject_Proxy( 
    IMarshal  * This,
    /* [in] */ unsigned long dwReserved);


void __stdcall IMarshal_DisconnectObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IMarshal_INTERFACE_DEFINED__ */


#ifndef __IMalloc_INTERFACE_DEFINED__
#define __IMalloc_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IMalloc
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [uuid][object][local] */ 


typedef /* [unique] */ IMalloc  *LPMALLOC;


EXTERN_C const IID IID_IMalloc;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IMalloc : public IUnknown
    {
    public:
        virtual void  *__stdcall Alloc( 
            /* [in] */ unsigned long cb) = 0;
        
        virtual void  *__stdcall Realloc( 
            /* [in] */ void  *pv,
            /* [in] */ unsigned long cb) = 0;
        
        virtual void __stdcall Free( 
            /* [in] */ void  *pv) = 0;
        
        virtual unsigned long __stdcall GetSize( 
            /* [in] */ void  *pv) = 0;
        
        virtual int __stdcall DidAlloc( 
            void  *pv) = 0;
        
        virtual void __stdcall HeapMinimize( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMallocVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IMalloc  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IMalloc  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IMalloc  * This);
        
        void  *( __stdcall  *Alloc )( 
            IMalloc  * This,
            /* [in] */ unsigned long cb);
        
        void  *( __stdcall  *Realloc )( 
            IMalloc  * This,
            /* [in] */ void  *pv,
            /* [in] */ unsigned long cb);
        
        void ( __stdcall  *Free )( 
            IMalloc  * This,
            /* [in] */ void  *pv);
        
        unsigned long ( __stdcall  *GetSize )( 
            IMalloc  * This,
            /* [in] */ void  *pv);
        
        int ( __stdcall  *DidAlloc )( 
            IMalloc  * This,
            void  *pv);
        
        void ( __stdcall  *HeapMinimize )( 
            IMalloc  * This);
        
        END_INTERFACE
    } IMallocVtbl;

    interface IMalloc
    {
        CONST_VTBL struct IMallocVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMalloc_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMalloc_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMalloc_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMalloc_Alloc(This,cb)	\
    (This)->lpVtbl -> Alloc(This,cb)

#define IMalloc_Realloc(This,pv,cb)	\
    (This)->lpVtbl -> Realloc(This,pv,cb)

#define IMalloc_Free(This,pv)	\
    (This)->lpVtbl -> Free(This,pv)

#define IMalloc_GetSize(This,pv)	\
    (This)->lpVtbl -> GetSize(This,pv)

#define IMalloc_DidAlloc(This,pv)	\
    (This)->lpVtbl -> DidAlloc(This,pv)

#define IMalloc_HeapMinimize(This)	\
    (This)->lpVtbl -> HeapMinimize(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



void  *__stdcall IMalloc_Alloc_Proxy( 
    IMalloc  * This,
    /* [in] */ unsigned long cb);


void __stdcall IMalloc_Alloc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


void  *__stdcall IMalloc_Realloc_Proxy( 
    IMalloc  * This,
    /* [in] */ void  *pv,
    /* [in] */ unsigned long cb);


void __stdcall IMalloc_Realloc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


void __stdcall IMalloc_Free_Proxy( 
    IMalloc  * This,
    /* [in] */ void  *pv);


void __stdcall IMalloc_Free_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


unsigned long __stdcall IMalloc_GetSize_Proxy( 
    IMalloc  * This,
    /* [in] */ void  *pv);


void __stdcall IMalloc_GetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


int __stdcall IMalloc_DidAlloc_Proxy( 
    IMalloc  * This,
    void  *pv);


void __stdcall IMalloc_DidAlloc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


void __stdcall IMalloc_HeapMinimize_Proxy( 
    IMalloc  * This);


void __stdcall IMalloc_HeapMinimize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IMalloc_INTERFACE_DEFINED__ */


#ifndef __IMallocSpy_INTERFACE_DEFINED__
#define __IMallocSpy_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IMallocSpy
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [uuid][object][local] */ 


typedef /* [unique] */ IMallocSpy  *LPMALLOCSPY;


EXTERN_C const IID IID_IMallocSpy;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IMallocSpy : public IUnknown
    {
    public:
        virtual unsigned long __stdcall PreAlloc( 
            /* [in] */ unsigned long cbRequest) = 0;
        
        virtual void  *__stdcall PostAlloc( 
            /* [in] */ void  *pActual) = 0;
        
        virtual void  *__stdcall PreFree( 
            /* [in] */ void  *pRequest,
            /* [in] */ BOOL fSpyed) = 0;
        
        virtual void __stdcall PostFree( 
            /* [in] */ BOOL fSpyed) = 0;
        
        virtual unsigned long __stdcall PreRealloc( 
            /* [in] */ void  *pRequest,
            /* [in] */ unsigned long cbRequest,
            /* [out] */ void  * *ppNewRequest,
            /* [in] */ BOOL fSpyed) = 0;
        
        virtual void  *__stdcall PostRealloc( 
            /* [in] */ void  *pActual,
            /* [in] */ BOOL fSpyed) = 0;
        
        virtual void  *__stdcall PreGetSize( 
            /* [in] */ void  *pRequest,
            /* [in] */ BOOL fSpyed) = 0;
        
        virtual unsigned long __stdcall PostGetSize( 
            /* [in] */ unsigned long cbActual,
            /* [in] */ BOOL fSpyed) = 0;
        
        virtual void  *__stdcall PreDidAlloc( 
            /* [in] */ void  *pRequest,
            /* [in] */ BOOL fSpyed) = 0;
        
        virtual int __stdcall PostDidAlloc( 
            /* [in] */ void  *pRequest,
            /* [in] */ BOOL fSpyed,
            /* [in] */ int fActual) = 0;
        
        virtual void __stdcall PreHeapMinimize( void) = 0;
        
        virtual void __stdcall PostHeapMinimize( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMallocSpyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IMallocSpy  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IMallocSpy  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IMallocSpy  * This);
        
        unsigned long ( __stdcall  *PreAlloc )( 
            IMallocSpy  * This,
            /* [in] */ unsigned long cbRequest);
        
        void  *( __stdcall  *PostAlloc )( 
            IMallocSpy  * This,
            /* [in] */ void  *pActual);
        
        void  *( __stdcall  *PreFree )( 
            IMallocSpy  * This,
            /* [in] */ void  *pRequest,
            /* [in] */ BOOL fSpyed);
        
        void ( __stdcall  *PostFree )( 
            IMallocSpy  * This,
            /* [in] */ BOOL fSpyed);
        
        unsigned long ( __stdcall  *PreRealloc )( 
            IMallocSpy  * This,
            /* [in] */ void  *pRequest,
            /* [in] */ unsigned long cbRequest,
            /* [out] */ void  * *ppNewRequest,
            /* [in] */ BOOL fSpyed);
        
        void  *( __stdcall  *PostRealloc )( 
            IMallocSpy  * This,
            /* [in] */ void  *pActual,
            /* [in] */ BOOL fSpyed);
        
        void  *( __stdcall  *PreGetSize )( 
            IMallocSpy  * This,
            /* [in] */ void  *pRequest,
            /* [in] */ BOOL fSpyed);
        
        unsigned long ( __stdcall  *PostGetSize )( 
            IMallocSpy  * This,
            /* [in] */ unsigned long cbActual,
            /* [in] */ BOOL fSpyed);
        
        void  *( __stdcall  *PreDidAlloc )( 
            IMallocSpy  * This,
            /* [in] */ void  *pRequest,
            /* [in] */ BOOL fSpyed);
        
        int ( __stdcall  *PostDidAlloc )( 
            IMallocSpy  * This,
            /* [in] */ void  *pRequest,
            /* [in] */ BOOL fSpyed,
            /* [in] */ int fActual);
        
        void ( __stdcall  *PreHeapMinimize )( 
            IMallocSpy  * This);
        
        void ( __stdcall  *PostHeapMinimize )( 
            IMallocSpy  * This);
        
        END_INTERFACE
    } IMallocSpyVtbl;

    interface IMallocSpy
    {
        CONST_VTBL struct IMallocSpyVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMallocSpy_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMallocSpy_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMallocSpy_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMallocSpy_PreAlloc(This,cbRequest)	\
    (This)->lpVtbl -> PreAlloc(This,cbRequest)

#define IMallocSpy_PostAlloc(This,pActual)	\
    (This)->lpVtbl -> PostAlloc(This,pActual)

#define IMallocSpy_PreFree(This,pRequest,fSpyed)	\
    (This)->lpVtbl -> PreFree(This,pRequest,fSpyed)

#define IMallocSpy_PostFree(This,fSpyed)	\
    (This)->lpVtbl -> PostFree(This,fSpyed)

#define IMallocSpy_PreRealloc(This,pRequest,cbRequest,ppNewRequest,fSpyed)	\
    (This)->lpVtbl -> PreRealloc(This,pRequest,cbRequest,ppNewRequest,fSpyed)

#define IMallocSpy_PostRealloc(This,pActual,fSpyed)	\
    (This)->lpVtbl -> PostRealloc(This,pActual,fSpyed)

#define IMallocSpy_PreGetSize(This,pRequest,fSpyed)	\
    (This)->lpVtbl -> PreGetSize(This,pRequest,fSpyed)

#define IMallocSpy_PostGetSize(This,cbActual,fSpyed)	\
    (This)->lpVtbl -> PostGetSize(This,cbActual,fSpyed)

#define IMallocSpy_PreDidAlloc(This,pRequest,fSpyed)	\
    (This)->lpVtbl -> PreDidAlloc(This,pRequest,fSpyed)

#define IMallocSpy_PostDidAlloc(This,pRequest,fSpyed,fActual)	\
    (This)->lpVtbl -> PostDidAlloc(This,pRequest,fSpyed,fActual)

#define IMallocSpy_PreHeapMinimize(This)	\
    (This)->lpVtbl -> PreHeapMinimize(This)

#define IMallocSpy_PostHeapMinimize(This)	\
    (This)->lpVtbl -> PostHeapMinimize(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



unsigned long __stdcall IMallocSpy_PreAlloc_Proxy( 
    IMallocSpy  * This,
    /* [in] */ unsigned long cbRequest);


void __stdcall IMallocSpy_PreAlloc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


void  *__stdcall IMallocSpy_PostAlloc_Proxy( 
    IMallocSpy  * This,
    /* [in] */ void  *pActual);


void __stdcall IMallocSpy_PostAlloc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


void  *__stdcall IMallocSpy_PreFree_Proxy( 
    IMallocSpy  * This,
    /* [in] */ void  *pRequest,
    /* [in] */ BOOL fSpyed);


void __stdcall IMallocSpy_PreFree_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


void __stdcall IMallocSpy_PostFree_Proxy( 
    IMallocSpy  * This,
    /* [in] */ BOOL fSpyed);


void __stdcall IMallocSpy_PostFree_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


unsigned long __stdcall IMallocSpy_PreRealloc_Proxy( 
    IMallocSpy  * This,
    /* [in] */ void  *pRequest,
    /* [in] */ unsigned long cbRequest,
    /* [out] */ void  * *ppNewRequest,
    /* [in] */ BOOL fSpyed);


void __stdcall IMallocSpy_PreRealloc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


void  *__stdcall IMallocSpy_PostRealloc_Proxy( 
    IMallocSpy  * This,
    /* [in] */ void  *pActual,
    /* [in] */ BOOL fSpyed);


void __stdcall IMallocSpy_PostRealloc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


void  *__stdcall IMallocSpy_PreGetSize_Proxy( 
    IMallocSpy  * This,
    /* [in] */ void  *pRequest,
    /* [in] */ BOOL fSpyed);


void __stdcall IMallocSpy_PreGetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


unsigned long __stdcall IMallocSpy_PostGetSize_Proxy( 
    IMallocSpy  * This,
    /* [in] */ unsigned long cbActual,
    /* [in] */ BOOL fSpyed);


void __stdcall IMallocSpy_PostGetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


void  *__stdcall IMallocSpy_PreDidAlloc_Proxy( 
    IMallocSpy  * This,
    /* [in] */ void  *pRequest,
    /* [in] */ BOOL fSpyed);


void __stdcall IMallocSpy_PreDidAlloc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


int __stdcall IMallocSpy_PostDidAlloc_Proxy( 
    IMallocSpy  * This,
    /* [in] */ void  *pRequest,
    /* [in] */ BOOL fSpyed,
    /* [in] */ int fActual);


void __stdcall IMallocSpy_PostDidAlloc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


void __stdcall IMallocSpy_PreHeapMinimize_Proxy( 
    IMallocSpy  * This);


void __stdcall IMallocSpy_PreHeapMinimize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


void __stdcall IMallocSpy_PostHeapMinimize_Proxy( 
    IMallocSpy  * This);


void __stdcall IMallocSpy_PostHeapMinimize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IMallocSpy_INTERFACE_DEFINED__ */


#ifndef __IStdMarshalInfo_INTERFACE_DEFINED__
#define __IStdMarshalInfo_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IStdMarshalInfo
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [uuid][object][local] */ 


typedef /* [unique] */ IStdMarshalInfo  *LPSTDMARSHALINFO;


EXTERN_C const IID IID_IStdMarshalInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IStdMarshalInfo : public IUnknown
    {
    public:
        virtual HRESULT __stdcall GetClassForHandler( 
            /* [in] */ unsigned long dwDestContext,
            /* [unique][in] */ void  *pvDestContext,
            /* [out] */ CLSID  *pClsid) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IStdMarshalInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IStdMarshalInfo  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IStdMarshalInfo  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IStdMarshalInfo  * This);
        
        HRESULT ( __stdcall  *GetClassForHandler )( 
            IStdMarshalInfo  * This,
            /* [in] */ unsigned long dwDestContext,
            /* [unique][in] */ void  *pvDestContext,
            /* [out] */ CLSID  *pClsid);
        
        END_INTERFACE
    } IStdMarshalInfoVtbl;

    interface IStdMarshalInfo
    {
        CONST_VTBL struct IStdMarshalInfoVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStdMarshalInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IStdMarshalInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IStdMarshalInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IStdMarshalInfo_GetClassForHandler(This,dwDestContext,pvDestContext,pClsid)	\
    (This)->lpVtbl -> GetClassForHandler(This,dwDestContext,pvDestContext,pClsid)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IStdMarshalInfo_GetClassForHandler_Proxy( 
    IStdMarshalInfo  * This,
    /* [in] */ unsigned long dwDestContext,
    /* [unique][in] */ void  *pvDestContext,
    /* [out] */ CLSID  *pClsid);


void __stdcall IStdMarshalInfo_GetClassForHandler_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IStdMarshalInfo_INTERFACE_DEFINED__ */


#ifndef __IExternalConnection_INTERFACE_DEFINED__
#define __IExternalConnection_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IExternalConnection
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [uuid][local][object] */ 


typedef /* [unique] */ IExternalConnection  *LPEXTERNALCONNECTION;

typedef 
enum tagEXTCONN
    {	EXTCONN_STRONG	= 0x1,
	EXTCONN_WEAK	= 0x2,
	EXTCONN_CALLABLE	= 0x4
    }	EXTCONN;


EXTERN_C const IID IID_IExternalConnection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IExternalConnection : public IUnknown
    {
    public:
        virtual unsigned long __stdcall AddConnection( 
            /* [in] */ unsigned long extconn,
            /* [in] */ unsigned long reserved) = 0;
        
        virtual unsigned long __stdcall ReleaseConnection( 
            /* [in] */ unsigned long extconn,
            /* [in] */ unsigned long reserved,
            /* [in] */ BOOL fLastReleaseCloses) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IExternalConnectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IExternalConnection  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IExternalConnection  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IExternalConnection  * This);
        
        unsigned long ( __stdcall  *AddConnection )( 
            IExternalConnection  * This,
            /* [in] */ unsigned long extconn,
            /* [in] */ unsigned long reserved);
        
        unsigned long ( __stdcall  *ReleaseConnection )( 
            IExternalConnection  * This,
            /* [in] */ unsigned long extconn,
            /* [in] */ unsigned long reserved,
            /* [in] */ BOOL fLastReleaseCloses);
        
        END_INTERFACE
    } IExternalConnectionVtbl;

    interface IExternalConnection
    {
        CONST_VTBL struct IExternalConnectionVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExternalConnection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IExternalConnection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IExternalConnection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IExternalConnection_AddConnection(This,extconn,reserved)	\
    (This)->lpVtbl -> AddConnection(This,extconn,reserved)

#define IExternalConnection_ReleaseConnection(This,extconn,reserved,fLastReleaseCloses)	\
    (This)->lpVtbl -> ReleaseConnection(This,extconn,reserved,fLastReleaseCloses)

#endif /* COBJMACROS */


#endif 	/* C style interface */



unsigned long __stdcall IExternalConnection_AddConnection_Proxy( 
    IExternalConnection  * This,
    /* [in] */ unsigned long extconn,
    /* [in] */ unsigned long reserved);


void __stdcall IExternalConnection_AddConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


unsigned long __stdcall IExternalConnection_ReleaseConnection_Proxy( 
    IExternalConnection  * This,
    /* [in] */ unsigned long extconn,
    /* [in] */ unsigned long reserved,
    /* [in] */ BOOL fLastReleaseCloses);


void __stdcall IExternalConnection_ReleaseConnection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IExternalConnection_INTERFACE_DEFINED__ */


#ifndef __IMultiQI_INTERFACE_DEFINED__
#define __IMultiQI_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IMultiQI
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [uuid][local][object] */ 


typedef /* [unique] */ IMultiQI  *LPMULTIQI;

typedef struct  tagMULTI_QI
    {
    const IID  *pIID;
    IUnknown  *pItf;
    HRESULT hr;
    }	MULTI_QI;


EXTERN_C const IID IID_IMultiQI;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IMultiQI : public IUnknown
    {
    public:
        virtual HRESULT __stdcall QueryMultipleInterfaces( 
            /* [in] */ unsigned long cMQIs,
            /* [out][in] */ MULTI_QI  *pMQIs) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMultiQIVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IMultiQI  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IMultiQI  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IMultiQI  * This);
        
        HRESULT ( __stdcall  *QueryMultipleInterfaces )( 
            IMultiQI  * This,
            /* [in] */ unsigned long cMQIs,
            /* [out][in] */ MULTI_QI  *pMQIs);
        
        END_INTERFACE
    } IMultiQIVtbl;

    interface IMultiQI
    {
        CONST_VTBL struct IMultiQIVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMultiQI_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMultiQI_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMultiQI_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMultiQI_QueryMultipleInterfaces(This,cMQIs,pMQIs)	\
    (This)->lpVtbl -> QueryMultipleInterfaces(This,cMQIs,pMQIs)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IMultiQI_QueryMultipleInterfaces_Proxy( 
    IMultiQI  * This,
    /* [in] */ unsigned long cMQIs,
    /* [out][in] */ MULTI_QI  *pMQIs);


void __stdcall IMultiQI_QueryMultipleInterfaces_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IMultiQI_INTERFACE_DEFINED__ */


#ifndef __IEnumUnknown_INTERFACE_DEFINED__
#define __IEnumUnknown_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumUnknown
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IEnumUnknown  *LPENUMUNKNOWN;


EXTERN_C const IID IID_IEnumUnknown;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IEnumUnknown : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT __stdcall Next( 
            /* [in] */ unsigned long celt,
            /* [out] */ IUnknown  * *rgelt,
            /* [out] */ unsigned long  *pceltFetched) = 0;
        
        virtual HRESULT __stdcall Skip( 
            /* [in] */ unsigned long celt) = 0;
        
        virtual HRESULT __stdcall Reset( void) = 0;
        
        virtual HRESULT __stdcall Clone( 
            /* [out] */ IEnumUnknown  * *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumUnknownVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IEnumUnknown  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IEnumUnknown  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IEnumUnknown  * This);
        
        /* [local] */ HRESULT ( __stdcall  *Next )( 
            IEnumUnknown  * This,
            /* [in] */ unsigned long celt,
            /* [out] */ IUnknown  * *rgelt,
            /* [out] */ unsigned long  *pceltFetched);
        
        HRESULT ( __stdcall  *Skip )( 
            IEnumUnknown  * This,
            /* [in] */ unsigned long celt);
        
        HRESULT ( __stdcall  *Reset )( 
            IEnumUnknown  * This);
        
        HRESULT ( __stdcall  *Clone )( 
            IEnumUnknown  * This,
            /* [out] */ IEnumUnknown  * *ppenum);
        
        END_INTERFACE
    } IEnumUnknownVtbl;

    interface IEnumUnknown
    {
        CONST_VTBL struct IEnumUnknownVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumUnknown_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumUnknown_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumUnknown_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumUnknown_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumUnknown_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumUnknown_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumUnknown_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall IEnumUnknown_RemoteNext_Proxy( 
    IEnumUnknown  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ IUnknown  * *rgelt,
    /* [out] */ unsigned long  *pceltFetched);


void __stdcall IEnumUnknown_RemoteNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumUnknown_Skip_Proxy( 
    IEnumUnknown  * This,
    /* [in] */ unsigned long celt);


void __stdcall IEnumUnknown_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumUnknown_Reset_Proxy( 
    IEnumUnknown  * This);


void __stdcall IEnumUnknown_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumUnknown_Clone_Proxy( 
    IEnumUnknown  * This,
    /* [out] */ IEnumUnknown  * *ppenum);


void __stdcall IEnumUnknown_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IEnumUnknown_INTERFACE_DEFINED__ */


#ifndef __IBindCtx_INTERFACE_DEFINED__
#define __IBindCtx_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IBindCtx
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IBindCtx  *LPBC;

typedef /* [unique] */ IBindCtx  *LPBINDCTX;

typedef struct  tagBIND_OPTS
    {
    unsigned long cbStruct;
    unsigned long grfFlags;
    unsigned long grfMode;
    unsigned long dwTickCountDeadline;
    }	BIND_OPTS;

typedef struct tagBIND_OPTS  *LPBIND_OPTS;

#if defined(__cplusplus)
    typedef struct tagBIND_OPTS2 : tagBIND_OPTS{
    unsigned long           dwTrackFlags;
    unsigned long           dwClassContext;
    LCID            locale;
    COSERVERINFO *  pServerInfo;
    } BIND_OPTS2, * LPBIND_OPTS2;
#else
typedef struct  tagBIND_OPTS2
    {
    unsigned long cbStruct;
    unsigned long grfFlags;
    unsigned long grfMode;
    unsigned long dwTickCountDeadline;
    unsigned long dwTrackFlags;
    unsigned long dwClassContext;
    LCID locale;
    COSERVERINFO  *pServerInfo;
    }	BIND_OPTS2;

typedef struct tagBIND_OPTS2  *LPBIND_OPTS2;

#endif
typedef 
enum tagBIND_FLAGS
    {	BIND_MAYBOTHERUSER	= 1,
	BIND_JUSTTESTEXISTENCE	= 2
    }	BIND_FLAGS;


EXTERN_C const IID IID_IBindCtx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IBindCtx : public IUnknown
    {
    public:
        virtual HRESULT __stdcall RegisterObjectBound( 
            /* [unique][in] */ IUnknown  *punk) = 0;
        
        virtual HRESULT __stdcall RevokeObjectBound( 
            /* [unique][in] */ IUnknown  *punk) = 0;
        
        virtual HRESULT __stdcall ReleaseBoundObjects( void) = 0;
        
        virtual /* [local] */ HRESULT __stdcall SetBindOptions( 
            /* [in] */ BIND_OPTS  *pbindopts) = 0;
        
        virtual /* [local] */ HRESULT __stdcall GetBindOptions( 
            /* [out][in] */ BIND_OPTS  *pbindopts) = 0;
        
        virtual HRESULT __stdcall GetRunningObjectTable( 
            /* [out] */ IRunningObjectTable  * *pprot) = 0;
        
        virtual HRESULT __stdcall RegisterObjectParam( 
            /* [in] */ LPOLESTR pszKey,
            /* [unique][in] */ IUnknown  *punk) = 0;
        
        virtual HRESULT __stdcall GetObjectParam( 
            /* [in] */ LPOLESTR pszKey,
            /* [out] */ IUnknown  * *ppunk) = 0;
        
        virtual HRESULT __stdcall EnumObjectParam( 
            /* [out] */ IEnumString  * *ppenum) = 0;
        
        virtual HRESULT __stdcall RevokeObjectParam( 
            /* [in] */ LPOLESTR pszKey) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBindCtxVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IBindCtx  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IBindCtx  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IBindCtx  * This);
        
        HRESULT ( __stdcall  *RegisterObjectBound )( 
            IBindCtx  * This,
            /* [unique][in] */ IUnknown  *punk);
        
        HRESULT ( __stdcall  *RevokeObjectBound )( 
            IBindCtx  * This,
            /* [unique][in] */ IUnknown  *punk);
        
        HRESULT ( __stdcall  *ReleaseBoundObjects )( 
            IBindCtx  * This);
        
        /* [local] */ HRESULT ( __stdcall  *SetBindOptions )( 
            IBindCtx  * This,
            /* [in] */ BIND_OPTS  *pbindopts);
        
        /* [local] */ HRESULT ( __stdcall  *GetBindOptions )( 
            IBindCtx  * This,
            /* [out][in] */ BIND_OPTS  *pbindopts);
        
        HRESULT ( __stdcall  *GetRunningObjectTable )( 
            IBindCtx  * This,
            /* [out] */ IRunningObjectTable  * *pprot);
        
        HRESULT ( __stdcall  *RegisterObjectParam )( 
            IBindCtx  * This,
            /* [in] */ LPOLESTR pszKey,
            /* [unique][in] */ IUnknown  *punk);
        
        HRESULT ( __stdcall  *GetObjectParam )( 
            IBindCtx  * This,
            /* [in] */ LPOLESTR pszKey,
            /* [out] */ IUnknown  * *ppunk);
        
        HRESULT ( __stdcall  *EnumObjectParam )( 
            IBindCtx  * This,
            /* [out] */ IEnumString  * *ppenum);
        
        HRESULT ( __stdcall  *RevokeObjectParam )( 
            IBindCtx  * This,
            /* [in] */ LPOLESTR pszKey);
        
        END_INTERFACE
    } IBindCtxVtbl;

    interface IBindCtx
    {
        CONST_VTBL struct IBindCtxVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBindCtx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBindCtx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBindCtx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBindCtx_RegisterObjectBound(This,punk)	\
    (This)->lpVtbl -> RegisterObjectBound(This,punk)

#define IBindCtx_RevokeObjectBound(This,punk)	\
    (This)->lpVtbl -> RevokeObjectBound(This,punk)

#define IBindCtx_ReleaseBoundObjects(This)	\
    (This)->lpVtbl -> ReleaseBoundObjects(This)

#define IBindCtx_SetBindOptions(This,pbindopts)	\
    (This)->lpVtbl -> SetBindOptions(This,pbindopts)

#define IBindCtx_GetBindOptions(This,pbindopts)	\
    (This)->lpVtbl -> GetBindOptions(This,pbindopts)

#define IBindCtx_GetRunningObjectTable(This,pprot)	\
    (This)->lpVtbl -> GetRunningObjectTable(This,pprot)

#define IBindCtx_RegisterObjectParam(This,pszKey,punk)	\
    (This)->lpVtbl -> RegisterObjectParam(This,pszKey,punk)

#define IBindCtx_GetObjectParam(This,pszKey,ppunk)	\
    (This)->lpVtbl -> GetObjectParam(This,pszKey,ppunk)

#define IBindCtx_EnumObjectParam(This,ppenum)	\
    (This)->lpVtbl -> EnumObjectParam(This,ppenum)

#define IBindCtx_RevokeObjectParam(This,pszKey)	\
    (This)->lpVtbl -> RevokeObjectParam(This,pszKey)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IBindCtx_RegisterObjectBound_Proxy( 
    IBindCtx  * This,
    /* [unique][in] */ IUnknown  *punk);


void __stdcall IBindCtx_RegisterObjectBound_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IBindCtx_RevokeObjectBound_Proxy( 
    IBindCtx  * This,
    /* [unique][in] */ IUnknown  *punk);


void __stdcall IBindCtx_RevokeObjectBound_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IBindCtx_ReleaseBoundObjects_Proxy( 
    IBindCtx  * This);


void __stdcall IBindCtx_ReleaseBoundObjects_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall IBindCtx_RemoteSetBindOptions_Proxy( 
    IBindCtx  * This,
    /* [in] */ BIND_OPTS2  *pbindopts);


void __stdcall IBindCtx_RemoteSetBindOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall IBindCtx_RemoteGetBindOptions_Proxy( 
    IBindCtx  * This,
    /* [out][in] */ BIND_OPTS2  *pbindopts);


void __stdcall IBindCtx_RemoteGetBindOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IBindCtx_GetRunningObjectTable_Proxy( 
    IBindCtx  * This,
    /* [out] */ IRunningObjectTable  * *pprot);


void __stdcall IBindCtx_GetRunningObjectTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IBindCtx_RegisterObjectParam_Proxy( 
    IBindCtx  * This,
    /* [in] */ LPOLESTR pszKey,
    /* [unique][in] */ IUnknown  *punk);


void __stdcall IBindCtx_RegisterObjectParam_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IBindCtx_GetObjectParam_Proxy( 
    IBindCtx  * This,
    /* [in] */ LPOLESTR pszKey,
    /* [out] */ IUnknown  * *ppunk);


void __stdcall IBindCtx_GetObjectParam_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IBindCtx_EnumObjectParam_Proxy( 
    IBindCtx  * This,
    /* [out] */ IEnumString  * *ppenum);


void __stdcall IBindCtx_EnumObjectParam_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IBindCtx_RevokeObjectParam_Proxy( 
    IBindCtx  * This,
    /* [in] */ LPOLESTR pszKey);


void __stdcall IBindCtx_RevokeObjectParam_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IBindCtx_INTERFACE_DEFINED__ */


#ifndef __IEnumMoniker_INTERFACE_DEFINED__
#define __IEnumMoniker_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumMoniker
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IEnumMoniker  *LPENUMMONIKER;


EXTERN_C const IID IID_IEnumMoniker;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IEnumMoniker : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT __stdcall Next( 
            /* [in] */ unsigned long celt,
            /* [length_is][size_is][out] */ IMoniker  * *rgelt,
            /* [out] */ unsigned long  *pceltFetched) = 0;
        
        virtual HRESULT __stdcall Skip( 
            /* [in] */ unsigned long celt) = 0;
        
        virtual HRESULT __stdcall Reset( void) = 0;
        
        virtual HRESULT __stdcall Clone( 
            /* [out] */ IEnumMoniker  * *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumMonikerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IEnumMoniker  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IEnumMoniker  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IEnumMoniker  * This);
        
        /* [local] */ HRESULT ( __stdcall  *Next )( 
            IEnumMoniker  * This,
            /* [in] */ unsigned long celt,
            /* [length_is][size_is][out] */ IMoniker  * *rgelt,
            /* [out] */ unsigned long  *pceltFetched);
        
        HRESULT ( __stdcall  *Skip )( 
            IEnumMoniker  * This,
            /* [in] */ unsigned long celt);
        
        HRESULT ( __stdcall  *Reset )( 
            IEnumMoniker  * This);
        
        HRESULT ( __stdcall  *Clone )( 
            IEnumMoniker  * This,
            /* [out] */ IEnumMoniker  * *ppenum);
        
        END_INTERFACE
    } IEnumMonikerVtbl;

    interface IEnumMoniker
    {
        CONST_VTBL struct IEnumMonikerVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumMoniker_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumMoniker_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumMoniker_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumMoniker_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumMoniker_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumMoniker_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumMoniker_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall IEnumMoniker_RemoteNext_Proxy( 
    IEnumMoniker  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ IMoniker  * *rgelt,
    /* [out] */ unsigned long  *pceltFetched);


void __stdcall IEnumMoniker_RemoteNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumMoniker_Skip_Proxy( 
    IEnumMoniker  * This,
    /* [in] */ unsigned long celt);


void __stdcall IEnumMoniker_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumMoniker_Reset_Proxy( 
    IEnumMoniker  * This);


void __stdcall IEnumMoniker_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumMoniker_Clone_Proxy( 
    IEnumMoniker  * This,
    /* [out] */ IEnumMoniker  * *ppenum);


void __stdcall IEnumMoniker_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IEnumMoniker_INTERFACE_DEFINED__ */


#ifndef __IRunnableObject_INTERFACE_DEFINED__
#define __IRunnableObject_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IRunnableObject
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [uuid][object] */ 


typedef /* [unique] */ IRunnableObject  *LPRUNNABLEOBJECT;


EXTERN_C const IID IID_IRunnableObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IRunnableObject : public IUnknown
    {
    public:
        virtual HRESULT __stdcall GetRunningClass( 
            /* [out] */ LPCLSID lpClsid) = 0;
        
        virtual HRESULT __stdcall Run( 
            /* [in] */ LPBINDCTX pbc) = 0;
        
        virtual /* [local] */ BOOL __stdcall IsRunning( void) = 0;
        
        virtual HRESULT __stdcall LockRunning( 
            /* [in] */ BOOL fLock,
            /* [in] */ BOOL fLastUnlockCloses) = 0;
        
        virtual HRESULT __stdcall SetContainedObject( 
            /* [in] */ BOOL fContained) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRunnableObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IRunnableObject  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IRunnableObject  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IRunnableObject  * This);
        
        HRESULT ( __stdcall  *GetRunningClass )( 
            IRunnableObject  * This,
            /* [out] */ LPCLSID lpClsid);
        
        HRESULT ( __stdcall  *Run )( 
            IRunnableObject  * This,
            /* [in] */ LPBINDCTX pbc);
        
        /* [local] */ BOOL ( __stdcall  *IsRunning )( 
            IRunnableObject  * This);
        
        HRESULT ( __stdcall  *LockRunning )( 
            IRunnableObject  * This,
            /* [in] */ BOOL fLock,
            /* [in] */ BOOL fLastUnlockCloses);
        
        HRESULT ( __stdcall  *SetContainedObject )( 
            IRunnableObject  * This,
            /* [in] */ BOOL fContained);
        
        END_INTERFACE
    } IRunnableObjectVtbl;

    interface IRunnableObject
    {
        CONST_VTBL struct IRunnableObjectVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRunnableObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRunnableObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRunnableObject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRunnableObject_GetRunningClass(This,lpClsid)	\
    (This)->lpVtbl -> GetRunningClass(This,lpClsid)

#define IRunnableObject_Run(This,pbc)	\
    (This)->lpVtbl -> Run(This,pbc)

#define IRunnableObject_IsRunning(This)	\
    (This)->lpVtbl -> IsRunning(This)

#define IRunnableObject_LockRunning(This,fLock,fLastUnlockCloses)	\
    (This)->lpVtbl -> LockRunning(This,fLock,fLastUnlockCloses)

#define IRunnableObject_SetContainedObject(This,fContained)	\
    (This)->lpVtbl -> SetContainedObject(This,fContained)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IRunnableObject_GetRunningClass_Proxy( 
    IRunnableObject  * This,
    /* [out] */ LPCLSID lpClsid);


void __stdcall IRunnableObject_GetRunningClass_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IRunnableObject_Run_Proxy( 
    IRunnableObject  * This,
    /* [in] */ LPBINDCTX pbc);


void __stdcall IRunnableObject_Run_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall IRunnableObject_RemoteIsRunning_Proxy( 
    IRunnableObject  * This);


void __stdcall IRunnableObject_RemoteIsRunning_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IRunnableObject_LockRunning_Proxy( 
    IRunnableObject  * This,
    /* [in] */ BOOL fLock,
    /* [in] */ BOOL fLastUnlockCloses);


void __stdcall IRunnableObject_LockRunning_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IRunnableObject_SetContainedObject_Proxy( 
    IRunnableObject  * This,
    /* [in] */ BOOL fContained);


void __stdcall IRunnableObject_SetContainedObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IRunnableObject_INTERFACE_DEFINED__ */


#ifndef __IRunningObjectTable_INTERFACE_DEFINED__
#define __IRunningObjectTable_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IRunningObjectTable
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [uuid][object] */ 


typedef /* [unique] */ IRunningObjectTable  *LPRUNNINGOBJECTTABLE;


EXTERN_C const IID IID_IRunningObjectTable;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IRunningObjectTable : public IUnknown
    {
    public:
        virtual HRESULT __stdcall Register( 
            /* [in] */ unsigned long grfFlags,
            /* [unique][in] */ IUnknown  *punkObject,
            /* [unique][in] */ IMoniker  *pmkObjectName,
            /* [out] */ unsigned long  *pdwRegister) = 0;
        
        virtual HRESULT __stdcall Revoke( 
            /* [in] */ unsigned long dwRegister) = 0;
        
        virtual HRESULT __stdcall IsRunning( 
            /* [unique][in] */ IMoniker  *pmkObjectName) = 0;
        
        virtual HRESULT __stdcall GetObject( 
            /* [unique][in] */ IMoniker  *pmkObjectName,
            /* [out] */ IUnknown  * *ppunkObject) = 0;
        
        virtual HRESULT __stdcall NoteChangeTime( 
            /* [in] */ unsigned long dwRegister,
            /* [in] */ FILETIME  *pfiletime) = 0;
        
        virtual HRESULT __stdcall GetTimeOfLastChange( 
            /* [unique][in] */ IMoniker  *pmkObjectName,
            /* [out] */ FILETIME  *pfiletime) = 0;
        
        virtual HRESULT __stdcall EnumRunning( 
            /* [out] */ IEnumMoniker  * *ppenumMoniker) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRunningObjectTableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IRunningObjectTable  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IRunningObjectTable  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IRunningObjectTable  * This);
        
        HRESULT ( __stdcall  *Register )( 
            IRunningObjectTable  * This,
            /* [in] */ unsigned long grfFlags,
            /* [unique][in] */ IUnknown  *punkObject,
            /* [unique][in] */ IMoniker  *pmkObjectName,
            /* [out] */ unsigned long  *pdwRegister);
        
        HRESULT ( __stdcall  *Revoke )( 
            IRunningObjectTable  * This,
            /* [in] */ unsigned long dwRegister);
        
        HRESULT ( __stdcall  *IsRunning )( 
            IRunningObjectTable  * This,
            /* [unique][in] */ IMoniker  *pmkObjectName);
        
        HRESULT ( __stdcall  *GetObject )( 
            IRunningObjectTable  * This,
            /* [unique][in] */ IMoniker  *pmkObjectName,
            /* [out] */ IUnknown  * *ppunkObject);
        
        HRESULT ( __stdcall  *NoteChangeTime )( 
            IRunningObjectTable  * This,
            /* [in] */ unsigned long dwRegister,
            /* [in] */ FILETIME  *pfiletime);
        
        HRESULT ( __stdcall  *GetTimeOfLastChange )( 
            IRunningObjectTable  * This,
            /* [unique][in] */ IMoniker  *pmkObjectName,
            /* [out] */ FILETIME  *pfiletime);
        
        HRESULT ( __stdcall  *EnumRunning )( 
            IRunningObjectTable  * This,
            /* [out] */ IEnumMoniker  * *ppenumMoniker);
        
        END_INTERFACE
    } IRunningObjectTableVtbl;

    interface IRunningObjectTable
    {
        CONST_VTBL struct IRunningObjectTableVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRunningObjectTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRunningObjectTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRunningObjectTable_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRunningObjectTable_Register(This,grfFlags,punkObject,pmkObjectName,pdwRegister)	\
    (This)->lpVtbl -> Register(This,grfFlags,punkObject,pmkObjectName,pdwRegister)

#define IRunningObjectTable_Revoke(This,dwRegister)	\
    (This)->lpVtbl -> Revoke(This,dwRegister)

#define IRunningObjectTable_IsRunning(This,pmkObjectName)	\
    (This)->lpVtbl -> IsRunning(This,pmkObjectName)

#define IRunningObjectTable_GetObject(This,pmkObjectName,ppunkObject)	\
    (This)->lpVtbl -> GetObject(This,pmkObjectName,ppunkObject)

#define IRunningObjectTable_NoteChangeTime(This,dwRegister,pfiletime)	\
    (This)->lpVtbl -> NoteChangeTime(This,dwRegister,pfiletime)

#define IRunningObjectTable_GetTimeOfLastChange(This,pmkObjectName,pfiletime)	\
    (This)->lpVtbl -> GetTimeOfLastChange(This,pmkObjectName,pfiletime)

#define IRunningObjectTable_EnumRunning(This,ppenumMoniker)	\
    (This)->lpVtbl -> EnumRunning(This,ppenumMoniker)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IRunningObjectTable_Register_Proxy( 
    IRunningObjectTable  * This,
    /* [in] */ unsigned long grfFlags,
    /* [unique][in] */ IUnknown  *punkObject,
    /* [unique][in] */ IMoniker  *pmkObjectName,
    /* [out] */ unsigned long  *pdwRegister);


void __stdcall IRunningObjectTable_Register_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IRunningObjectTable_Revoke_Proxy( 
    IRunningObjectTable  * This,
    /* [in] */ unsigned long dwRegister);


void __stdcall IRunningObjectTable_Revoke_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IRunningObjectTable_IsRunning_Proxy( 
    IRunningObjectTable  * This,
    /* [unique][in] */ IMoniker  *pmkObjectName);


void __stdcall IRunningObjectTable_IsRunning_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IRunningObjectTable_GetObject_Proxy( 
    IRunningObjectTable  * This,
    /* [unique][in] */ IMoniker  *pmkObjectName,
    /* [out] */ IUnknown  * *ppunkObject);


void __stdcall IRunningObjectTable_GetObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IRunningObjectTable_NoteChangeTime_Proxy( 
    IRunningObjectTable  * This,
    /* [in] */ unsigned long dwRegister,
    /* [in] */ FILETIME  *pfiletime);


void __stdcall IRunningObjectTable_NoteChangeTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IRunningObjectTable_GetTimeOfLastChange_Proxy( 
    IRunningObjectTable  * This,
    /* [unique][in] */ IMoniker  *pmkObjectName,
    /* [out] */ FILETIME  *pfiletime);


void __stdcall IRunningObjectTable_GetTimeOfLastChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IRunningObjectTable_EnumRunning_Proxy( 
    IRunningObjectTable  * This,
    /* [out] */ IEnumMoniker  * *ppenumMoniker);


void __stdcall IRunningObjectTable_EnumRunning_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IRunningObjectTable_INTERFACE_DEFINED__ */


#ifndef __IPersist_INTERFACE_DEFINED__
#define __IPersist_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPersist
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [uuid][object] */ 


typedef /* [unique] */ IPersist  *LPPERSIST;


EXTERN_C const IID IID_IPersist;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IPersist : public IUnknown
    {
    public:
        virtual HRESULT __stdcall GetClassID( 
            /* [out] */ CLSID  *pClassID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPersistVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IPersist  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IPersist  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IPersist  * This);
        
        HRESULT ( __stdcall  *GetClassID )( 
            IPersist  * This,
            /* [out] */ CLSID  *pClassID);
        
        END_INTERFACE
    } IPersistVtbl;

    interface IPersist
    {
        CONST_VTBL struct IPersistVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPersist_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPersist_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPersist_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPersist_GetClassID(This,pClassID)	\
    (This)->lpVtbl -> GetClassID(This,pClassID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPersist_GetClassID_Proxy( 
    IPersist  * This,
    /* [out] */ CLSID  *pClassID);


void __stdcall IPersist_GetClassID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IPersist_INTERFACE_DEFINED__ */


#ifndef __IPersistStream_INTERFACE_DEFINED__
#define __IPersistStream_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPersistStream
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IPersistStream  *LPPERSISTSTREAM;


EXTERN_C const IID IID_IPersistStream;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IPersistStream : public IPersist
    {
    public:
        virtual HRESULT __stdcall IsDirty( void) = 0;
        
        virtual HRESULT __stdcall Load( 
            /* [unique][in] */ IStream  *pStm) = 0;
        
        virtual HRESULT __stdcall Save( 
            /* [unique][in] */ IStream  *pStm,
            /* [in] */ BOOL fClearDirty) = 0;
        
        virtual HRESULT __stdcall GetSizeMax( 
            /* [out] */ ULARGE_INTEGER  *pcbSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPersistStreamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IPersistStream  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IPersistStream  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IPersistStream  * This);
        
        HRESULT ( __stdcall  *GetClassID )( 
            IPersistStream  * This,
            /* [out] */ CLSID  *pClassID);
        
        HRESULT ( __stdcall  *IsDirty )( 
            IPersistStream  * This);
        
        HRESULT ( __stdcall  *Load )( 
            IPersistStream  * This,
            /* [unique][in] */ IStream  *pStm);
        
        HRESULT ( __stdcall  *Save )( 
            IPersistStream  * This,
            /* [unique][in] */ IStream  *pStm,
            /* [in] */ BOOL fClearDirty);
        
        HRESULT ( __stdcall  *GetSizeMax )( 
            IPersistStream  * This,
            /* [out] */ ULARGE_INTEGER  *pcbSize);
        
        END_INTERFACE
    } IPersistStreamVtbl;

    interface IPersistStream
    {
        CONST_VTBL struct IPersistStreamVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPersistStream_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPersistStream_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPersistStream_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPersistStream_GetClassID(This,pClassID)	\
    (This)->lpVtbl -> GetClassID(This,pClassID)


#define IPersistStream_IsDirty(This)	\
    (This)->lpVtbl -> IsDirty(This)

#define IPersistStream_Load(This,pStm)	\
    (This)->lpVtbl -> Load(This,pStm)

#define IPersistStream_Save(This,pStm,fClearDirty)	\
    (This)->lpVtbl -> Save(This,pStm,fClearDirty)

#define IPersistStream_GetSizeMax(This,pcbSize)	\
    (This)->lpVtbl -> GetSizeMax(This,pcbSize)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPersistStream_IsDirty_Proxy( 
    IPersistStream  * This);


void __stdcall IPersistStream_IsDirty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPersistStream_Load_Proxy( 
    IPersistStream  * This,
    /* [unique][in] */ IStream  *pStm);


void __stdcall IPersistStream_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPersistStream_Save_Proxy( 
    IPersistStream  * This,
    /* [unique][in] */ IStream  *pStm,
    /* [in] */ BOOL fClearDirty);


void __stdcall IPersistStream_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPersistStream_GetSizeMax_Proxy( 
    IPersistStream  * This,
    /* [out] */ ULARGE_INTEGER  *pcbSize);


void __stdcall IPersistStream_GetSizeMax_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IPersistStream_INTERFACE_DEFINED__ */


#ifndef __IMoniker_INTERFACE_DEFINED__
#define __IMoniker_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IMoniker
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IMoniker  *LPMONIKER;

typedef 
enum tagMKSYS
    {	MKSYS_NONE	= 0,
	MKSYS_GENERICCOMPOSITE	= 1,
	MKSYS_FILEMONIKER	= 2,
	MKSYS_ANTIMONIKER	= 3,
	MKSYS_ITEMMONIKER	= 4,
	MKSYS_POINTERMONIKER	= 5,
	MKSYS_CLASSMONIKER	= 7
    }	MKSYS;

typedef /* [v1_enum] */ 
enum tagMKREDUCE
    {	MKRREDUCE_ONE	= 3 << 16,
	MKRREDUCE_TOUSER	= 2 << 16,
	MKRREDUCE_THROUGHUSER	= 1 << 16,
	MKRREDUCE_ALL	= 0
    }	MKRREDUCE;


EXTERN_C const IID IID_IMoniker;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IMoniker : public IPersistStream
    {
    public:
        virtual /* [local] */ HRESULT __stdcall BindToObject( 
            /* [unique][in] */ IBindCtx  *pbc,
            /* [unique][in] */ IMoniker  *pmkToLeft,
            /* [in] */ REFIID riidResult,
            /* [iid_is][out] */ void  * *ppvResult) = 0;
        
        virtual /* [local] */ HRESULT __stdcall BindToStorage( 
            /* [unique][in] */ IBindCtx  *pbc,
            /* [unique][in] */ IMoniker  *pmkToLeft,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObj) = 0;
        
        virtual HRESULT __stdcall Reduce( 
            /* [unique][in] */ IBindCtx  *pbc,
            /* [in] */ unsigned long dwReduceHowFar,
            /* [unique][out][in] */ IMoniker  * *ppmkToLeft,
            /* [out] */ IMoniker  * *ppmkReduced) = 0;
        
        virtual HRESULT __stdcall ComposeWith( 
            /* [unique][in] */ IMoniker  *pmkRight,
            /* [in] */ BOOL fOnlyIfNotGeneric,
            /* [out] */ IMoniker  * *ppmkComposite) = 0;
        
        virtual HRESULT __stdcall Enum( 
            /* [in] */ BOOL fForward,
            /* [out] */ IEnumMoniker  * *ppenumMoniker) = 0;
        
        virtual HRESULT __stdcall IsEqual( 
            /* [unique][in] */ IMoniker  *pmkOtherMoniker) = 0;
        
        virtual HRESULT __stdcall Hash( 
            /* [out] */ unsigned long  *pdwHash) = 0;
        
        virtual HRESULT __stdcall IsRunning( 
            /* [unique][in] */ IBindCtx  *pbc,
            /* [unique][in] */ IMoniker  *pmkToLeft,
            /* [unique][in] */ IMoniker  *pmkNewlyRunning) = 0;
        
        virtual HRESULT __stdcall GetTimeOfLastChange( 
            /* [unique][in] */ IBindCtx  *pbc,
            /* [unique][in] */ IMoniker  *pmkToLeft,
            /* [out] */ FILETIME  *pFileTime) = 0;
        
        virtual HRESULT __stdcall Inverse( 
            /* [out] */ IMoniker  * *ppmk) = 0;
        
        virtual HRESULT __stdcall CommonPrefixWith( 
            /* [unique][in] */ IMoniker  *pmkOther,
            /* [out] */ IMoniker  * *ppmkPrefix) = 0;
        
        virtual HRESULT __stdcall RelativePathTo( 
            /* [unique][in] */ IMoniker  *pmkOther,
            /* [out] */ IMoniker  * *ppmkRelPath) = 0;
        
        virtual HRESULT __stdcall GetDisplayName( 
            /* [unique][in] */ IBindCtx  *pbc,
            /* [unique][in] */ IMoniker  *pmkToLeft,
            /* [out] */ LPOLESTR  *ppszDisplayName) = 0;
        
        virtual HRESULT __stdcall ParseDisplayName( 
            /* [unique][in] */ IBindCtx  *pbc,
            /* [unique][in] */ IMoniker  *pmkToLeft,
            /* [in] */ LPOLESTR pszDisplayName,
            /* [out] */ unsigned long  *pchEaten,
            /* [out] */ IMoniker  * *ppmkOut) = 0;
        
        virtual HRESULT __stdcall IsSystemMoniker( 
            /* [out] */ unsigned long  *pdwMksys) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMonikerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IMoniker  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IMoniker  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IMoniker  * This);
        
        HRESULT ( __stdcall  *GetClassID )( 
            IMoniker  * This,
            /* [out] */ CLSID  *pClassID);
        
        HRESULT ( __stdcall  *IsDirty )( 
            IMoniker  * This);
        
        HRESULT ( __stdcall  *Load )( 
            IMoniker  * This,
            /* [unique][in] */ IStream  *pStm);
        
        HRESULT ( __stdcall  *Save )( 
            IMoniker  * This,
            /* [unique][in] */ IStream  *pStm,
            /* [in] */ BOOL fClearDirty);
        
        HRESULT ( __stdcall  *GetSizeMax )( 
            IMoniker  * This,
            /* [out] */ ULARGE_INTEGER  *pcbSize);
        
        /* [local] */ HRESULT ( __stdcall  *BindToObject )( 
            IMoniker  * This,
            /* [unique][in] */ IBindCtx  *pbc,
            /* [unique][in] */ IMoniker  *pmkToLeft,
            /* [in] */ REFIID riidResult,
            /* [iid_is][out] */ void  * *ppvResult);
        
        /* [local] */ HRESULT ( __stdcall  *BindToStorage )( 
            IMoniker  * This,
            /* [unique][in] */ IBindCtx  *pbc,
            /* [unique][in] */ IMoniker  *pmkToLeft,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObj);
        
        HRESULT ( __stdcall  *Reduce )( 
            IMoniker  * This,
            /* [unique][in] */ IBindCtx  *pbc,
            /* [in] */ unsigned long dwReduceHowFar,
            /* [unique][out][in] */ IMoniker  * *ppmkToLeft,
            /* [out] */ IMoniker  * *ppmkReduced);
        
        HRESULT ( __stdcall  *ComposeWith )( 
            IMoniker  * This,
            /* [unique][in] */ IMoniker  *pmkRight,
            /* [in] */ BOOL fOnlyIfNotGeneric,
            /* [out] */ IMoniker  * *ppmkComposite);
        
        HRESULT ( __stdcall  *Enum )( 
            IMoniker  * This,
            /* [in] */ BOOL fForward,
            /* [out] */ IEnumMoniker  * *ppenumMoniker);
        
        HRESULT ( __stdcall  *IsEqual )( 
            IMoniker  * This,
            /* [unique][in] */ IMoniker  *pmkOtherMoniker);
        
        HRESULT ( __stdcall  *Hash )( 
            IMoniker  * This,
            /* [out] */ unsigned long  *pdwHash);
        
        HRESULT ( __stdcall  *IsRunning )( 
            IMoniker  * This,
            /* [unique][in] */ IBindCtx  *pbc,
            /* [unique][in] */ IMoniker  *pmkToLeft,
            /* [unique][in] */ IMoniker  *pmkNewlyRunning);
        
        HRESULT ( __stdcall  *GetTimeOfLastChange )( 
            IMoniker  * This,
            /* [unique][in] */ IBindCtx  *pbc,
            /* [unique][in] */ IMoniker  *pmkToLeft,
            /* [out] */ FILETIME  *pFileTime);
        
        HRESULT ( __stdcall  *Inverse )( 
            IMoniker  * This,
            /* [out] */ IMoniker  * *ppmk);
        
        HRESULT ( __stdcall  *CommonPrefixWith )( 
            IMoniker  * This,
            /* [unique][in] */ IMoniker  *pmkOther,
            /* [out] */ IMoniker  * *ppmkPrefix);
        
        HRESULT ( __stdcall  *RelativePathTo )( 
            IMoniker  * This,
            /* [unique][in] */ IMoniker  *pmkOther,
            /* [out] */ IMoniker  * *ppmkRelPath);
        
        HRESULT ( __stdcall  *GetDisplayName )( 
            IMoniker  * This,
            /* [unique][in] */ IBindCtx  *pbc,
            /* [unique][in] */ IMoniker  *pmkToLeft,
            /* [out] */ LPOLESTR  *ppszDisplayName);
        
        HRESULT ( __stdcall  *ParseDisplayName )( 
            IMoniker  * This,
            /* [unique][in] */ IBindCtx  *pbc,
            /* [unique][in] */ IMoniker  *pmkToLeft,
            /* [in] */ LPOLESTR pszDisplayName,
            /* [out] */ unsigned long  *pchEaten,
            /* [out] */ IMoniker  * *ppmkOut);
        
        HRESULT ( __stdcall  *IsSystemMoniker )( 
            IMoniker  * This,
            /* [out] */ unsigned long  *pdwMksys);
        
        END_INTERFACE
    } IMonikerVtbl;

    interface IMoniker
    {
        CONST_VTBL struct IMonikerVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMoniker_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMoniker_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMoniker_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMoniker_GetClassID(This,pClassID)	\
    (This)->lpVtbl -> GetClassID(This,pClassID)


#define IMoniker_IsDirty(This)	\
    (This)->lpVtbl -> IsDirty(This)

#define IMoniker_Load(This,pStm)	\
    (This)->lpVtbl -> Load(This,pStm)

#define IMoniker_Save(This,pStm,fClearDirty)	\
    (This)->lpVtbl -> Save(This,pStm,fClearDirty)

#define IMoniker_GetSizeMax(This,pcbSize)	\
    (This)->lpVtbl -> GetSizeMax(This,pcbSize)


#define IMoniker_BindToObject(This,pbc,pmkToLeft,riidResult,ppvResult)	\
    (This)->lpVtbl -> BindToObject(This,pbc,pmkToLeft,riidResult,ppvResult)

#define IMoniker_BindToStorage(This,pbc,pmkToLeft,riid,ppvObj)	\
    (This)->lpVtbl -> BindToStorage(This,pbc,pmkToLeft,riid,ppvObj)

#define IMoniker_Reduce(This,pbc,dwReduceHowFar,ppmkToLeft,ppmkReduced)	\
    (This)->lpVtbl -> Reduce(This,pbc,dwReduceHowFar,ppmkToLeft,ppmkReduced)

#define IMoniker_ComposeWith(This,pmkRight,fOnlyIfNotGeneric,ppmkComposite)	\
    (This)->lpVtbl -> ComposeWith(This,pmkRight,fOnlyIfNotGeneric,ppmkComposite)

#define IMoniker_Enum(This,fForward,ppenumMoniker)	\
    (This)->lpVtbl -> Enum(This,fForward,ppenumMoniker)

#define IMoniker_IsEqual(This,pmkOtherMoniker)	\
    (This)->lpVtbl -> IsEqual(This,pmkOtherMoniker)

#define IMoniker_Hash(This,pdwHash)	\
    (This)->lpVtbl -> Hash(This,pdwHash)

#define IMoniker_IsRunning(This,pbc,pmkToLeft,pmkNewlyRunning)	\
    (This)->lpVtbl -> IsRunning(This,pbc,pmkToLeft,pmkNewlyRunning)

#define IMoniker_GetTimeOfLastChange(This,pbc,pmkToLeft,pFileTime)	\
    (This)->lpVtbl -> GetTimeOfLastChange(This,pbc,pmkToLeft,pFileTime)

#define IMoniker_Inverse(This,ppmk)	\
    (This)->lpVtbl -> Inverse(This,ppmk)

#define IMoniker_CommonPrefixWith(This,pmkOther,ppmkPrefix)	\
    (This)->lpVtbl -> CommonPrefixWith(This,pmkOther,ppmkPrefix)

#define IMoniker_RelativePathTo(This,pmkOther,ppmkRelPath)	\
    (This)->lpVtbl -> RelativePathTo(This,pmkOther,ppmkRelPath)

#define IMoniker_GetDisplayName(This,pbc,pmkToLeft,ppszDisplayName)	\
    (This)->lpVtbl -> GetDisplayName(This,pbc,pmkToLeft,ppszDisplayName)

#define IMoniker_ParseDisplayName(This,pbc,pmkToLeft,pszDisplayName,pchEaten,ppmkOut)	\
    (This)->lpVtbl -> ParseDisplayName(This,pbc,pmkToLeft,pszDisplayName,pchEaten,ppmkOut)

#define IMoniker_IsSystemMoniker(This,pdwMksys)	\
    (This)->lpVtbl -> IsSystemMoniker(This,pdwMksys)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall IMoniker_RemoteBindToObject_Proxy( 
    IMoniker  * This,
    /* [unique][in] */ IBindCtx  *pbc,
    /* [unique][in] */ IMoniker  *pmkToLeft,
    /* [in] */ REFIID riidResult,
    /* [iid_is][out] */ IUnknown  * *ppvResult);


void __stdcall IMoniker_RemoteBindToObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall IMoniker_RemoteBindToStorage_Proxy( 
    IMoniker  * This,
    /* [unique][in] */ IBindCtx  *pbc,
    /* [unique][in] */ IMoniker  *pmkToLeft,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown  * *ppvObj);


void __stdcall IMoniker_RemoteBindToStorage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IMoniker_Reduce_Proxy( 
    IMoniker  * This,
    /* [unique][in] */ IBindCtx  *pbc,
    /* [in] */ unsigned long dwReduceHowFar,
    /* [unique][out][in] */ IMoniker  * *ppmkToLeft,
    /* [out] */ IMoniker  * *ppmkReduced);


void __stdcall IMoniker_Reduce_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IMoniker_ComposeWith_Proxy( 
    IMoniker  * This,
    /* [unique][in] */ IMoniker  *pmkRight,
    /* [in] */ BOOL fOnlyIfNotGeneric,
    /* [out] */ IMoniker  * *ppmkComposite);


void __stdcall IMoniker_ComposeWith_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IMoniker_Enum_Proxy( 
    IMoniker  * This,
    /* [in] */ BOOL fForward,
    /* [out] */ IEnumMoniker  * *ppenumMoniker);


void __stdcall IMoniker_Enum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IMoniker_IsEqual_Proxy( 
    IMoniker  * This,
    /* [unique][in] */ IMoniker  *pmkOtherMoniker);


void __stdcall IMoniker_IsEqual_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IMoniker_Hash_Proxy( 
    IMoniker  * This,
    /* [out] */ unsigned long  *pdwHash);


void __stdcall IMoniker_Hash_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IMoniker_IsRunning_Proxy( 
    IMoniker  * This,
    /* [unique][in] */ IBindCtx  *pbc,
    /* [unique][in] */ IMoniker  *pmkToLeft,
    /* [unique][in] */ IMoniker  *pmkNewlyRunning);


void __stdcall IMoniker_IsRunning_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IMoniker_GetTimeOfLastChange_Proxy( 
    IMoniker  * This,
    /* [unique][in] */ IBindCtx  *pbc,
    /* [unique][in] */ IMoniker  *pmkToLeft,
    /* [out] */ FILETIME  *pFileTime);


void __stdcall IMoniker_GetTimeOfLastChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IMoniker_Inverse_Proxy( 
    IMoniker  * This,
    /* [out] */ IMoniker  * *ppmk);


void __stdcall IMoniker_Inverse_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IMoniker_CommonPrefixWith_Proxy( 
    IMoniker  * This,
    /* [unique][in] */ IMoniker  *pmkOther,
    /* [out] */ IMoniker  * *ppmkPrefix);


void __stdcall IMoniker_CommonPrefixWith_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IMoniker_RelativePathTo_Proxy( 
    IMoniker  * This,
    /* [unique][in] */ IMoniker  *pmkOther,
    /* [out] */ IMoniker  * *ppmkRelPath);


void __stdcall IMoniker_RelativePathTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IMoniker_GetDisplayName_Proxy( 
    IMoniker  * This,
    /* [unique][in] */ IBindCtx  *pbc,
    /* [unique][in] */ IMoniker  *pmkToLeft,
    /* [out] */ LPOLESTR  *ppszDisplayName);


void __stdcall IMoniker_GetDisplayName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IMoniker_ParseDisplayName_Proxy( 
    IMoniker  * This,
    /* [unique][in] */ IBindCtx  *pbc,
    /* [unique][in] */ IMoniker  *pmkToLeft,
    /* [in] */ LPOLESTR pszDisplayName,
    /* [out] */ unsigned long  *pchEaten,
    /* [out] */ IMoniker  * *ppmkOut);


void __stdcall IMoniker_ParseDisplayName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IMoniker_IsSystemMoniker_Proxy( 
    IMoniker  * This,
    /* [out] */ unsigned long  *pdwMksys);


void __stdcall IMoniker_IsSystemMoniker_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IMoniker_INTERFACE_DEFINED__ */


#ifndef __IROTData_INTERFACE_DEFINED__
#define __IROTData_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IROTData
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 



EXTERN_C const IID IID_IROTData;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IROTData : public IUnknown
    {
    public:
        virtual HRESULT __stdcall GetComparisonData( 
            /* [size_is][out] */ byte  *pbData,
            /* [in] */ unsigned long cbMax,
            /* [out] */ unsigned long  *pcbData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IROTDataVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IROTData  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IROTData  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IROTData  * This);
        
        HRESULT ( __stdcall  *GetComparisonData )( 
            IROTData  * This,
            /* [size_is][out] */ byte  *pbData,
            /* [in] */ unsigned long cbMax,
            /* [out] */ unsigned long  *pcbData);
        
        END_INTERFACE
    } IROTDataVtbl;

    interface IROTData
    {
        CONST_VTBL struct IROTDataVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IROTData_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IROTData_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IROTData_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IROTData_GetComparisonData(This,pbData,cbMax,pcbData)	\
    (This)->lpVtbl -> GetComparisonData(This,pbData,cbMax,pcbData)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IROTData_GetComparisonData_Proxy( 
    IROTData  * This,
    /* [size_is][out] */ byte  *pbData,
    /* [in] */ unsigned long cbMax,
    /* [out] */ unsigned long  *pcbData);


void __stdcall IROTData_GetComparisonData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IROTData_INTERFACE_DEFINED__ */


#ifndef __IEnumString_INTERFACE_DEFINED__
#define __IEnumString_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumString
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IEnumString  *LPENUMSTRING;


EXTERN_C const IID IID_IEnumString;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IEnumString : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT __stdcall Next( 
            /* [in] */ unsigned long celt,
            /* [length_is][size_is][out] */ LPOLESTR  *rgelt,
            /* [out] */ unsigned long  *pceltFetched) = 0;
        
        virtual HRESULT __stdcall Skip( 
            /* [in] */ unsigned long celt) = 0;
        
        virtual HRESULT __stdcall Reset( void) = 0;
        
        virtual HRESULT __stdcall Clone( 
            /* [out] */ IEnumString  * *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumStringVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IEnumString  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IEnumString  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IEnumString  * This);
        
        /* [local] */ HRESULT ( __stdcall  *Next )( 
            IEnumString  * This,
            /* [in] */ unsigned long celt,
            /* [length_is][size_is][out] */ LPOLESTR  *rgelt,
            /* [out] */ unsigned long  *pceltFetched);
        
        HRESULT ( __stdcall  *Skip )( 
            IEnumString  * This,
            /* [in] */ unsigned long celt);
        
        HRESULT ( __stdcall  *Reset )( 
            IEnumString  * This);
        
        HRESULT ( __stdcall  *Clone )( 
            IEnumString  * This,
            /* [out] */ IEnumString  * *ppenum);
        
        END_INTERFACE
    } IEnumStringVtbl;

    interface IEnumString
    {
        CONST_VTBL struct IEnumStringVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumString_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumString_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumString_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumString_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumString_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumString_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumString_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall IEnumString_RemoteNext_Proxy( 
    IEnumString  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ LPOLESTR  *rgelt,
    /* [out] */ unsigned long  *pceltFetched);


void __stdcall IEnumString_RemoteNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumString_Skip_Proxy( 
    IEnumString  * This,
    /* [in] */ unsigned long celt);


void __stdcall IEnumString_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumString_Reset_Proxy( 
    IEnumString  * This);


void __stdcall IEnumString_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumString_Clone_Proxy( 
    IEnumString  * This,
    /* [out] */ IEnumString  * *ppenum);


void __stdcall IEnumString_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IEnumString_INTERFACE_DEFINED__ */


#ifndef __ISequentialStream_INTERFACE_DEFINED__
#define __ISequentialStream_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ISequentialStream
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 



EXTERN_C const IID IID_ISequentialStream;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ISequentialStream : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT __stdcall Read( 
            /* [length_is][size_is][out] */ void  *pv,
            /* [in] */ unsigned long cb,
            /* [out] */ unsigned long  *pcbRead) = 0;
        
        virtual /* [local] */ HRESULT __stdcall Write( 
            /* [size_is][in] */ const void  *pv,
            /* [in] */ unsigned long cb,
            /* [out] */ unsigned long  *pcbWritten) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISequentialStreamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            ISequentialStream  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            ISequentialStream  * This);
        
        unsigned long ( __stdcall  *Release )( 
            ISequentialStream  * This);
        
        /* [local] */ HRESULT ( __stdcall  *Read )( 
            ISequentialStream  * This,
            /* [length_is][size_is][out] */ void  *pv,
            /* [in] */ unsigned long cb,
            /* [out] */ unsigned long  *pcbRead);
        
        /* [local] */ HRESULT ( __stdcall  *Write )( 
            ISequentialStream  * This,
            /* [size_is][in] */ const void  *pv,
            /* [in] */ unsigned long cb,
            /* [out] */ unsigned long  *pcbWritten);
        
        END_INTERFACE
    } ISequentialStreamVtbl;

    interface ISequentialStream
    {
        CONST_VTBL struct ISequentialStreamVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISequentialStream_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISequentialStream_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISequentialStream_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISequentialStream_Read(This,pv,cb,pcbRead)	\
    (This)->lpVtbl -> Read(This,pv,cb,pcbRead)

#define ISequentialStream_Write(This,pv,cb,pcbWritten)	\
    (This)->lpVtbl -> Write(This,pv,cb,pcbWritten)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall ISequentialStream_RemoteRead_Proxy( 
    ISequentialStream  * This,
    /* [length_is][size_is][out] */ byte  *pv,
    /* [in] */ unsigned long cb,
    /* [out] */ unsigned long  *pcbRead);


void __stdcall ISequentialStream_RemoteRead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall ISequentialStream_RemoteWrite_Proxy( 
    ISequentialStream  * This,
    /* [size_is][in] */ const byte  *pv,
    /* [in] */ unsigned long cb,
    /* [out] */ unsigned long  *pcbWritten);


void __stdcall ISequentialStream_RemoteWrite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __ISequentialStream_INTERFACE_DEFINED__ */


#ifndef __IStream_INTERFACE_DEFINED__
#define __IStream_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IStream
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IStream  *LPSTREAM;

typedef struct  tagSTATSTG
    {
    LPOLESTR pwcsName;
    unsigned long type;
    ULARGE_INTEGER cbSize;
    FILETIME mtime;
    FILETIME ctime;
    FILETIME atime;
    unsigned long grfMode;
    unsigned long grfLocksSupported;
    CLSID clsid;
    unsigned long grfStateBits;
    unsigned long reserved;
    }	STATSTG;

typedef 
enum tagSTGTY
    {	STGTY_STORAGE	= 1,
	STGTY_STREAM	= 2,
	STGTY_LOCKBYTES	= 3,
	STGTY_PROPERTY	= 4
    }	STGTY;

typedef 
enum tagSTREAM_SEEK
    {	STREAM_SEEK_SET	= 0,
	STREAM_SEEK_CUR	= 1,
	STREAM_SEEK_END	= 2
    }	STREAM_SEEK;

typedef 
enum tagLOCKTYPE
    {	LOCK_WRITE	= 1,
	LOCK_EXCLUSIVE	= 2,
	LOCK_ONLYONCE	= 4
    }	LOCKTYPE;


EXTERN_C const IID IID_IStream;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IStream : public ISequentialStream
    {
    public:
        virtual /* [local] */ HRESULT __stdcall Seek( 
            /* [in] */ LARGE_INTEGER dlibMove,
            /* [in] */ unsigned long dwOrigin,
            /* [out] */ ULARGE_INTEGER  *plibNewPosition) = 0;
        
        virtual HRESULT __stdcall SetSize( 
            /* [in] */ ULARGE_INTEGER libNewSize) = 0;
        
        virtual /* [local] */ HRESULT __stdcall CopyTo( 
            /* [unique][in] */ IStream  *pstm,
            /* [in] */ ULARGE_INTEGER cb,
            /* [out] */ ULARGE_INTEGER  *pcbRead,
            /* [out] */ ULARGE_INTEGER  *pcbWritten) = 0;
        
        virtual HRESULT __stdcall Commit( 
            /* [in] */ unsigned long grfCommitFlags) = 0;
        
        virtual HRESULT __stdcall Revert( void) = 0;
        
        virtual HRESULT __stdcall LockRegion( 
            /* [in] */ ULARGE_INTEGER libOffset,
            /* [in] */ ULARGE_INTEGER cb,
            /* [in] */ unsigned long dwLockType) = 0;
        
        virtual HRESULT __stdcall UnlockRegion( 
            /* [in] */ ULARGE_INTEGER libOffset,
            /* [in] */ ULARGE_INTEGER cb,
            /* [in] */ unsigned long dwLockType) = 0;
        
        virtual HRESULT __stdcall Stat( 
            /* [out] */ STATSTG  *pstatstg,
            /* [in] */ unsigned long grfStatFlag) = 0;
        
        virtual HRESULT __stdcall Clone( 
            /* [out] */ IStream  * *ppstm) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IStreamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IStream  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IStream  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IStream  * This);
        
        /* [local] */ HRESULT ( __stdcall  *Read )( 
            IStream  * This,
            /* [length_is][size_is][out] */ void  *pv,
            /* [in] */ unsigned long cb,
            /* [out] */ unsigned long  *pcbRead);
        
        /* [local] */ HRESULT ( __stdcall  *Write )( 
            IStream  * This,
            /* [size_is][in] */ const void  *pv,
            /* [in] */ unsigned long cb,
            /* [out] */ unsigned long  *pcbWritten);
        
        /* [local] */ HRESULT ( __stdcall  *Seek )( 
            IStream  * This,
            /* [in] */ LARGE_INTEGER dlibMove,
            /* [in] */ unsigned long dwOrigin,
            /* [out] */ ULARGE_INTEGER  *plibNewPosition);
        
        HRESULT ( __stdcall  *SetSize )( 
            IStream  * This,
            /* [in] */ ULARGE_INTEGER libNewSize);
        
        /* [local] */ HRESULT ( __stdcall  *CopyTo )( 
            IStream  * This,
            /* [unique][in] */ IStream  *pstm,
            /* [in] */ ULARGE_INTEGER cb,
            /* [out] */ ULARGE_INTEGER  *pcbRead,
            /* [out] */ ULARGE_INTEGER  *pcbWritten);
        
        HRESULT ( __stdcall  *Commit )( 
            IStream  * This,
            /* [in] */ unsigned long grfCommitFlags);
        
        HRESULT ( __stdcall  *Revert )( 
            IStream  * This);
        
        HRESULT ( __stdcall  *LockRegion )( 
            IStream  * This,
            /* [in] */ ULARGE_INTEGER libOffset,
            /* [in] */ ULARGE_INTEGER cb,
            /* [in] */ unsigned long dwLockType);
        
        HRESULT ( __stdcall  *UnlockRegion )( 
            IStream  * This,
            /* [in] */ ULARGE_INTEGER libOffset,
            /* [in] */ ULARGE_INTEGER cb,
            /* [in] */ unsigned long dwLockType);
        
        HRESULT ( __stdcall  *Stat )( 
            IStream  * This,
            /* [out] */ STATSTG  *pstatstg,
            /* [in] */ unsigned long grfStatFlag);
        
        HRESULT ( __stdcall  *Clone )( 
            IStream  * This,
            /* [out] */ IStream  * *ppstm);
        
        END_INTERFACE
    } IStreamVtbl;

    interface IStream
    {
        CONST_VTBL struct IStreamVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStream_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IStream_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IStream_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IStream_Read(This,pv,cb,pcbRead)	\
    (This)->lpVtbl -> Read(This,pv,cb,pcbRead)

#define IStream_Write(This,pv,cb,pcbWritten)	\
    (This)->lpVtbl -> Write(This,pv,cb,pcbWritten)


#define IStream_Seek(This,dlibMove,dwOrigin,plibNewPosition)	\
    (This)->lpVtbl -> Seek(This,dlibMove,dwOrigin,plibNewPosition)

#define IStream_SetSize(This,libNewSize)	\
    (This)->lpVtbl -> SetSize(This,libNewSize)

#define IStream_CopyTo(This,pstm,cb,pcbRead,pcbWritten)	\
    (This)->lpVtbl -> CopyTo(This,pstm,cb,pcbRead,pcbWritten)

#define IStream_Commit(This,grfCommitFlags)	\
    (This)->lpVtbl -> Commit(This,grfCommitFlags)

#define IStream_Revert(This)	\
    (This)->lpVtbl -> Revert(This)

#define IStream_LockRegion(This,libOffset,cb,dwLockType)	\
    (This)->lpVtbl -> LockRegion(This,libOffset,cb,dwLockType)

#define IStream_UnlockRegion(This,libOffset,cb,dwLockType)	\
    (This)->lpVtbl -> UnlockRegion(This,libOffset,cb,dwLockType)

#define IStream_Stat(This,pstatstg,grfStatFlag)	\
    (This)->lpVtbl -> Stat(This,pstatstg,grfStatFlag)

#define IStream_Clone(This,ppstm)	\
    (This)->lpVtbl -> Clone(This,ppstm)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall IStream_RemoteSeek_Proxy( 
    IStream  * This,
    /* [in] */ LARGE_INTEGER dlibMove,
    /* [in] */ unsigned long dwOrigin,
    /* [out] */ ULARGE_INTEGER  *plibNewPosition);


void __stdcall IStream_RemoteSeek_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IStream_SetSize_Proxy( 
    IStream  * This,
    /* [in] */ ULARGE_INTEGER libNewSize);


void __stdcall IStream_SetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall IStream_RemoteCopyTo_Proxy( 
    IStream  * This,
    /* [unique][in] */ IStream  *pstm,
    /* [in] */ ULARGE_INTEGER cb,
    /* [out] */ ULARGE_INTEGER  *pcbRead,
    /* [out] */ ULARGE_INTEGER  *pcbWritten);


void __stdcall IStream_RemoteCopyTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IStream_Commit_Proxy( 
    IStream  * This,
    /* [in] */ unsigned long grfCommitFlags);


void __stdcall IStream_Commit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IStream_Revert_Proxy( 
    IStream  * This);


void __stdcall IStream_Revert_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IStream_LockRegion_Proxy( 
    IStream  * This,
    /* [in] */ ULARGE_INTEGER libOffset,
    /* [in] */ ULARGE_INTEGER cb,
    /* [in] */ unsigned long dwLockType);


void __stdcall IStream_LockRegion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IStream_UnlockRegion_Proxy( 
    IStream  * This,
    /* [in] */ ULARGE_INTEGER libOffset,
    /* [in] */ ULARGE_INTEGER cb,
    /* [in] */ unsigned long dwLockType);


void __stdcall IStream_UnlockRegion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IStream_Stat_Proxy( 
    IStream  * This,
    /* [out] */ STATSTG  *pstatstg,
    /* [in] */ unsigned long grfStatFlag);


void __stdcall IStream_Stat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IStream_Clone_Proxy( 
    IStream  * This,
    /* [out] */ IStream  * *ppstm);


void __stdcall IStream_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IStream_INTERFACE_DEFINED__ */


#ifndef __IEnumSTATSTG_INTERFACE_DEFINED__
#define __IEnumSTATSTG_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumSTATSTG
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IEnumSTATSTG  *LPENUMSTATSTG;


EXTERN_C const IID IID_IEnumSTATSTG;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IEnumSTATSTG : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT __stdcall Next( 
            /* [in] */ unsigned long celt,
            /* [length_is][size_is][out] */ STATSTG  *rgelt,
            /* [out] */ unsigned long  *pceltFetched) = 0;
        
        virtual HRESULT __stdcall Skip( 
            /* [in] */ unsigned long celt) = 0;
        
        virtual HRESULT __stdcall Reset( void) = 0;
        
        virtual HRESULT __stdcall Clone( 
            /* [out] */ IEnumSTATSTG  * *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumSTATSTGVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IEnumSTATSTG  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IEnumSTATSTG  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IEnumSTATSTG  * This);
        
        /* [local] */ HRESULT ( __stdcall  *Next )( 
            IEnumSTATSTG  * This,
            /* [in] */ unsigned long celt,
            /* [length_is][size_is][out] */ STATSTG  *rgelt,
            /* [out] */ unsigned long  *pceltFetched);
        
        HRESULT ( __stdcall  *Skip )( 
            IEnumSTATSTG  * This,
            /* [in] */ unsigned long celt);
        
        HRESULT ( __stdcall  *Reset )( 
            IEnumSTATSTG  * This);
        
        HRESULT ( __stdcall  *Clone )( 
            IEnumSTATSTG  * This,
            /* [out] */ IEnumSTATSTG  * *ppenum);
        
        END_INTERFACE
    } IEnumSTATSTGVtbl;

    interface IEnumSTATSTG
    {
        CONST_VTBL struct IEnumSTATSTGVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumSTATSTG_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumSTATSTG_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumSTATSTG_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumSTATSTG_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumSTATSTG_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumSTATSTG_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumSTATSTG_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall IEnumSTATSTG_RemoteNext_Proxy( 
    IEnumSTATSTG  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ STATSTG  *rgelt,
    /* [out] */ unsigned long  *pceltFetched);


void __stdcall IEnumSTATSTG_RemoteNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumSTATSTG_Skip_Proxy( 
    IEnumSTATSTG  * This,
    /* [in] */ unsigned long celt);


void __stdcall IEnumSTATSTG_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumSTATSTG_Reset_Proxy( 
    IEnumSTATSTG  * This);


void __stdcall IEnumSTATSTG_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumSTATSTG_Clone_Proxy( 
    IEnumSTATSTG  * This,
    /* [out] */ IEnumSTATSTG  * *ppenum);


void __stdcall IEnumSTATSTG_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IEnumSTATSTG_INTERFACE_DEFINED__ */


#ifndef __IStorage_INTERFACE_DEFINED__
#define __IStorage_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IStorage
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IStorage  *LPSTORAGE;

typedef struct  tagRemSNB
    {
    unsigned long ulCntStr;
    unsigned long ulCntChar;
    /* [size_is] */ OLECHAR rgString[ 1 ];
    }	RemSNB;

typedef /* [unique] */ RemSNB  *wireSNB;

typedef /* [wire_marshal] */ OLECHAR  * *SNB;


EXTERN_C const IID IID_IStorage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IStorage : public IUnknown
    {
    public:
        virtual HRESULT __stdcall CreateStream( 
            /* [string][in] */ const OLECHAR  *pwcsName,
            /* [in] */ unsigned long grfMode,
            /* [in] */ unsigned long reserved1,
            /* [in] */ unsigned long reserved2,
            /* [out] */ IStream  * *ppstm) = 0;
        
        virtual /* [local] */ HRESULT __stdcall OpenStream( 
            /* [string][in] */ const OLECHAR  *pwcsName,
            /* [unique][in] */ void  *reserved1,
            /* [in] */ unsigned long grfMode,
            /* [in] */ unsigned long reserved2,
            /* [out] */ IStream  * *ppstm) = 0;
        
        virtual HRESULT __stdcall CreateStorage( 
            /* [string][in] */ const OLECHAR  *pwcsName,
            /* [in] */ unsigned long grfMode,
            /* [in] */ unsigned long dwStgFmt,
            /* [in] */ unsigned long reserved2,
            /* [out] */ IStorage  * *ppstg) = 0;
        
        virtual HRESULT __stdcall OpenStorage( 
            /* [string][unique][in] */ const OLECHAR  *pwcsName,
            /* [unique][in] */ IStorage  *pstgPriority,
            /* [in] */ unsigned long grfMode,
            /* [unique][in] */ SNB snbExclude,
            /* [in] */ unsigned long reserved,
            /* [out] */ IStorage  * *ppstg) = 0;
        
        virtual HRESULT __stdcall CopyTo( 
            /* [in] */ unsigned long ciidExclude,
            /* [size_is][unique][in] */ const IID  *rgiidExclude,
            /* [unique][in] */ SNB snbExclude,
            /* [unique][in] */ IStorage  *pstgDest) = 0;
        
        virtual HRESULT __stdcall MoveElementTo( 
            /* [string][in] */ const OLECHAR  *pwcsName,
            /* [unique][in] */ IStorage  *pstgDest,
            /* [string][in] */ const OLECHAR  *pwcsNewName,
            /* [in] */ unsigned long grfFlags) = 0;
        
        virtual HRESULT __stdcall Commit( 
            /* [in] */ unsigned long grfCommitFlags) = 0;
        
        virtual HRESULT __stdcall Revert( void) = 0;
        
        virtual /* [local] */ HRESULT __stdcall EnumElements( 
            /* [in] */ unsigned long reserved1,
            /* [size_is][unique][in] */ void  *reserved2,
            /* [in] */ unsigned long reserved3,
            /* [out] */ IEnumSTATSTG  * *ppenum) = 0;
        
        virtual HRESULT __stdcall DestroyElement( 
            /* [string][in] */ const OLECHAR  *pwcsName) = 0;
        
        virtual HRESULT __stdcall RenameElement( 
            /* [string][in] */ const OLECHAR  *pwcsOldName,
            /* [string][in] */ const OLECHAR  *pwcsNewName) = 0;
        
        virtual HRESULT __stdcall SetElementTimes( 
            /* [string][in] */ const OLECHAR  *pwcsName,
            /* [in] */ const FILETIME  *pctime,
            /* [in] */ const FILETIME  *patime,
            /* [in] */ const FILETIME  *pmtime) = 0;
        
        virtual HRESULT __stdcall SetClass( 
            /* [in] */ REFCLSID clsid) = 0;
        
        virtual HRESULT __stdcall SetStateBits( 
            /* [in] */ unsigned long grfStateBits,
            /* [in] */ unsigned long grfMask) = 0;
        
        virtual HRESULT __stdcall Stat( 
            /* [out] */ STATSTG  *pstatstg,
            /* [in] */ unsigned long grfStatFlag) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IStorageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IStorage  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IStorage  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IStorage  * This);
        
        HRESULT ( __stdcall  *CreateStream )( 
            IStorage  * This,
            /* [string][in] */ const OLECHAR  *pwcsName,
            /* [in] */ unsigned long grfMode,
            /* [in] */ unsigned long reserved1,
            /* [in] */ unsigned long reserved2,
            /* [out] */ IStream  * *ppstm);
        
        /* [local] */ HRESULT ( __stdcall  *OpenStream )( 
            IStorage  * This,
            /* [string][in] */ const OLECHAR  *pwcsName,
            /* [unique][in] */ void  *reserved1,
            /* [in] */ unsigned long grfMode,
            /* [in] */ unsigned long reserved2,
            /* [out] */ IStream  * *ppstm);
        
        HRESULT ( __stdcall  *CreateStorage )( 
            IStorage  * This,
            /* [string][in] */ const OLECHAR  *pwcsName,
            /* [in] */ unsigned long grfMode,
            /* [in] */ unsigned long dwStgFmt,
            /* [in] */ unsigned long reserved2,
            /* [out] */ IStorage  * *ppstg);
        
        HRESULT ( __stdcall  *OpenStorage )( 
            IStorage  * This,
            /* [string][unique][in] */ const OLECHAR  *pwcsName,
            /* [unique][in] */ IStorage  *pstgPriority,
            /* [in] */ unsigned long grfMode,
            /* [unique][in] */ SNB snbExclude,
            /* [in] */ unsigned long reserved,
            /* [out] */ IStorage  * *ppstg);
        
        HRESULT ( __stdcall  *CopyTo )( 
            IStorage  * This,
            /* [in] */ unsigned long ciidExclude,
            /* [size_is][unique][in] */ const IID  *rgiidExclude,
            /* [unique][in] */ SNB snbExclude,
            /* [unique][in] */ IStorage  *pstgDest);
        
        HRESULT ( __stdcall  *MoveElementTo )( 
            IStorage  * This,
            /* [string][in] */ const OLECHAR  *pwcsName,
            /* [unique][in] */ IStorage  *pstgDest,
            /* [string][in] */ const OLECHAR  *pwcsNewName,
            /* [in] */ unsigned long grfFlags);
        
        HRESULT ( __stdcall  *Commit )( 
            IStorage  * This,
            /* [in] */ unsigned long grfCommitFlags);
        
        HRESULT ( __stdcall  *Revert )( 
            IStorage  * This);
        
        /* [local] */ HRESULT ( __stdcall  *EnumElements )( 
            IStorage  * This,
            /* [in] */ unsigned long reserved1,
            /* [size_is][unique][in] */ void  *reserved2,
            /* [in] */ unsigned long reserved3,
            /* [out] */ IEnumSTATSTG  * *ppenum);
        
        HRESULT ( __stdcall  *DestroyElement )( 
            IStorage  * This,
            /* [string][in] */ const OLECHAR  *pwcsName);
        
        HRESULT ( __stdcall  *RenameElement )( 
            IStorage  * This,
            /* [string][in] */ const OLECHAR  *pwcsOldName,
            /* [string][in] */ const OLECHAR  *pwcsNewName);
        
        HRESULT ( __stdcall  *SetElementTimes )( 
            IStorage  * This,
            /* [string][in] */ const OLECHAR  *pwcsName,
            /* [in] */ const FILETIME  *pctime,
            /* [in] */ const FILETIME  *patime,
            /* [in] */ const FILETIME  *pmtime);
        
        HRESULT ( __stdcall  *SetClass )( 
            IStorage  * This,
            /* [in] */ REFCLSID clsid);
        
        HRESULT ( __stdcall  *SetStateBits )( 
            IStorage  * This,
            /* [in] */ unsigned long grfStateBits,
            /* [in] */ unsigned long grfMask);
        
        HRESULT ( __stdcall  *Stat )( 
            IStorage  * This,
            /* [out] */ STATSTG  *pstatstg,
            /* [in] */ unsigned long grfStatFlag);
        
        END_INTERFACE
    } IStorageVtbl;

    interface IStorage
    {
        CONST_VTBL struct IStorageVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IStorage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IStorage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IStorage_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IStorage_CreateStream(This,pwcsName,grfMode,reserved1,reserved2,ppstm)	\
    (This)->lpVtbl -> CreateStream(This,pwcsName,grfMode,reserved1,reserved2,ppstm)

#define IStorage_OpenStream(This,pwcsName,reserved1,grfMode,reserved2,ppstm)	\
    (This)->lpVtbl -> OpenStream(This,pwcsName,reserved1,grfMode,reserved2,ppstm)

#define IStorage_CreateStorage(This,pwcsName,grfMode,dwStgFmt,reserved2,ppstg)	\
    (This)->lpVtbl -> CreateStorage(This,pwcsName,grfMode,dwStgFmt,reserved2,ppstg)

#define IStorage_OpenStorage(This,pwcsName,pstgPriority,grfMode,snbExclude,reserved,ppstg)	\
    (This)->lpVtbl -> OpenStorage(This,pwcsName,pstgPriority,grfMode,snbExclude,reserved,ppstg)

#define IStorage_CopyTo(This,ciidExclude,rgiidExclude,snbExclude,pstgDest)	\
    (This)->lpVtbl -> CopyTo(This,ciidExclude,rgiidExclude,snbExclude,pstgDest)

#define IStorage_MoveElementTo(This,pwcsName,pstgDest,pwcsNewName,grfFlags)	\
    (This)->lpVtbl -> MoveElementTo(This,pwcsName,pstgDest,pwcsNewName,grfFlags)

#define IStorage_Commit(This,grfCommitFlags)	\
    (This)->lpVtbl -> Commit(This,grfCommitFlags)

#define IStorage_Revert(This)	\
    (This)->lpVtbl -> Revert(This)

#define IStorage_EnumElements(This,reserved1,reserved2,reserved3,ppenum)	\
    (This)->lpVtbl -> EnumElements(This,reserved1,reserved2,reserved3,ppenum)

#define IStorage_DestroyElement(This,pwcsName)	\
    (This)->lpVtbl -> DestroyElement(This,pwcsName)

#define IStorage_RenameElement(This,pwcsOldName,pwcsNewName)	\
    (This)->lpVtbl -> RenameElement(This,pwcsOldName,pwcsNewName)

#define IStorage_SetElementTimes(This,pwcsName,pctime,patime,pmtime)	\
    (This)->lpVtbl -> SetElementTimes(This,pwcsName,pctime,patime,pmtime)

#define IStorage_SetClass(This,clsid)	\
    (This)->lpVtbl -> SetClass(This,clsid)

#define IStorage_SetStateBits(This,grfStateBits,grfMask)	\
    (This)->lpVtbl -> SetStateBits(This,grfStateBits,grfMask)

#define IStorage_Stat(This,pstatstg,grfStatFlag)	\
    (This)->lpVtbl -> Stat(This,pstatstg,grfStatFlag)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IStorage_CreateStream_Proxy( 
    IStorage  * This,
    /* [string][in] */ const OLECHAR  *pwcsName,
    /* [in] */ unsigned long grfMode,
    /* [in] */ unsigned long reserved1,
    /* [in] */ unsigned long reserved2,
    /* [out] */ IStream  * *ppstm);


void __stdcall IStorage_CreateStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall IStorage_RemoteOpenStream_Proxy( 
    IStorage  * This,
    /* [string][in] */ const OLECHAR  *pwcsName,
    /* [in] */ unsigned long cbReserved1,
    /* [size_is][unique][in] */ byte  *reserved1,
    /* [in] */ unsigned long grfMode,
    /* [in] */ unsigned long reserved2,
    /* [out] */ IStream  * *ppstm);


void __stdcall IStorage_RemoteOpenStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IStorage_CreateStorage_Proxy( 
    IStorage  * This,
    /* [string][in] */ const OLECHAR  *pwcsName,
    /* [in] */ unsigned long grfMode,
    /* [in] */ unsigned long dwStgFmt,
    /* [in] */ unsigned long reserved2,
    /* [out] */ IStorage  * *ppstg);


void __stdcall IStorage_CreateStorage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IStorage_OpenStorage_Proxy( 
    IStorage  * This,
    /* [string][unique][in] */ const OLECHAR  *pwcsName,
    /* [unique][in] */ IStorage  *pstgPriority,
    /* [in] */ unsigned long grfMode,
    /* [unique][in] */ SNB snbExclude,
    /* [in] */ unsigned long reserved,
    /* [out] */ IStorage  * *ppstg);


void __stdcall IStorage_OpenStorage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IStorage_CopyTo_Proxy( 
    IStorage  * This,
    /* [in] */ unsigned long ciidExclude,
    /* [size_is][unique][in] */ const IID  *rgiidExclude,
    /* [unique][in] */ SNB snbExclude,
    /* [unique][in] */ IStorage  *pstgDest);


void __stdcall IStorage_CopyTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IStorage_MoveElementTo_Proxy( 
    IStorage  * This,
    /* [string][in] */ const OLECHAR  *pwcsName,
    /* [unique][in] */ IStorage  *pstgDest,
    /* [string][in] */ const OLECHAR  *pwcsNewName,
    /* [in] */ unsigned long grfFlags);


void __stdcall IStorage_MoveElementTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IStorage_Commit_Proxy( 
    IStorage  * This,
    /* [in] */ unsigned long grfCommitFlags);


void __stdcall IStorage_Commit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IStorage_Revert_Proxy( 
    IStorage  * This);


void __stdcall IStorage_Revert_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall IStorage_RemoteEnumElements_Proxy( 
    IStorage  * This,
    /* [in] */ unsigned long reserved1,
    /* [in] */ unsigned long cbReserved2,
    /* [size_is][unique][in] */ byte  *reserved2,
    /* [in] */ unsigned long reserved3,
    /* [out] */ IEnumSTATSTG  * *ppenum);


void __stdcall IStorage_RemoteEnumElements_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IStorage_DestroyElement_Proxy( 
    IStorage  * This,
    /* [string][in] */ const OLECHAR  *pwcsName);


void __stdcall IStorage_DestroyElement_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IStorage_RenameElement_Proxy( 
    IStorage  * This,
    /* [string][in] */ const OLECHAR  *pwcsOldName,
    /* [string][in] */ const OLECHAR  *pwcsNewName);


void __stdcall IStorage_RenameElement_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IStorage_SetElementTimes_Proxy( 
    IStorage  * This,
    /* [string][in] */ const OLECHAR  *pwcsName,
    /* [in] */ const FILETIME  *pctime,
    /* [in] */ const FILETIME  *patime,
    /* [in] */ const FILETIME  *pmtime);


void __stdcall IStorage_SetElementTimes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IStorage_SetClass_Proxy( 
    IStorage  * This,
    /* [in] */ REFCLSID clsid);


void __stdcall IStorage_SetClass_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IStorage_SetStateBits_Proxy( 
    IStorage  * This,
    /* [in] */ unsigned long grfStateBits,
    /* [in] */ unsigned long grfMask);


void __stdcall IStorage_SetStateBits_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IStorage_Stat_Proxy( 
    IStorage  * This,
    /* [out] */ STATSTG  *pstatstg,
    /* [in] */ unsigned long grfStatFlag);


void __stdcall IStorage_Stat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IStorage_INTERFACE_DEFINED__ */


#ifndef __IPersistFile_INTERFACE_DEFINED__
#define __IPersistFile_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPersistFile
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IPersistFile  *LPPERSISTFILE;


EXTERN_C const IID IID_IPersistFile;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IPersistFile : public IPersist
    {
    public:
        virtual HRESULT __stdcall IsDirty( void) = 0;
        
        virtual HRESULT __stdcall Load( 
            /* [in] */ LPCOLESTR pszFileName,
            /* [in] */ unsigned long dwMode) = 0;
        
        virtual HRESULT __stdcall Save( 
            /* [unique][in] */ LPCOLESTR pszFileName,
            /* [in] */ BOOL fRemember) = 0;
        
        virtual HRESULT __stdcall SaveCompleted( 
            /* [unique][in] */ LPCOLESTR pszFileName) = 0;
        
        virtual HRESULT __stdcall GetCurFile( 
            /* [out] */ LPOLESTR  *ppszFileName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPersistFileVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IPersistFile  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IPersistFile  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IPersistFile  * This);
        
        HRESULT ( __stdcall  *GetClassID )( 
            IPersistFile  * This,
            /* [out] */ CLSID  *pClassID);
        
        HRESULT ( __stdcall  *IsDirty )( 
            IPersistFile  * This);
        
        HRESULT ( __stdcall  *Load )( 
            IPersistFile  * This,
            /* [in] */ LPCOLESTR pszFileName,
            /* [in] */ unsigned long dwMode);
        
        HRESULT ( __stdcall  *Save )( 
            IPersistFile  * This,
            /* [unique][in] */ LPCOLESTR pszFileName,
            /* [in] */ BOOL fRemember);
        
        HRESULT ( __stdcall  *SaveCompleted )( 
            IPersistFile  * This,
            /* [unique][in] */ LPCOLESTR pszFileName);
        
        HRESULT ( __stdcall  *GetCurFile )( 
            IPersistFile  * This,
            /* [out] */ LPOLESTR  *ppszFileName);
        
        END_INTERFACE
    } IPersistFileVtbl;

    interface IPersistFile
    {
        CONST_VTBL struct IPersistFileVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPersistFile_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPersistFile_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPersistFile_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPersistFile_GetClassID(This,pClassID)	\
    (This)->lpVtbl -> GetClassID(This,pClassID)


#define IPersistFile_IsDirty(This)	\
    (This)->lpVtbl -> IsDirty(This)

#define IPersistFile_Load(This,pszFileName,dwMode)	\
    (This)->lpVtbl -> Load(This,pszFileName,dwMode)

#define IPersistFile_Save(This,pszFileName,fRemember)	\
    (This)->lpVtbl -> Save(This,pszFileName,fRemember)

#define IPersistFile_SaveCompleted(This,pszFileName)	\
    (This)->lpVtbl -> SaveCompleted(This,pszFileName)

#define IPersistFile_GetCurFile(This,ppszFileName)	\
    (This)->lpVtbl -> GetCurFile(This,ppszFileName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPersistFile_IsDirty_Proxy( 
    IPersistFile  * This);


void __stdcall IPersistFile_IsDirty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPersistFile_Load_Proxy( 
    IPersistFile  * This,
    /* [in] */ LPCOLESTR pszFileName,
    /* [in] */ unsigned long dwMode);


void __stdcall IPersistFile_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPersistFile_Save_Proxy( 
    IPersistFile  * This,
    /* [unique][in] */ LPCOLESTR pszFileName,
    /* [in] */ BOOL fRemember);


void __stdcall IPersistFile_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPersistFile_SaveCompleted_Proxy( 
    IPersistFile  * This,
    /* [unique][in] */ LPCOLESTR pszFileName);


void __stdcall IPersistFile_SaveCompleted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPersistFile_GetCurFile_Proxy( 
    IPersistFile  * This,
    /* [out] */ LPOLESTR  *ppszFileName);


void __stdcall IPersistFile_GetCurFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IPersistFile_INTERFACE_DEFINED__ */


#ifndef __IPersistStorage_INTERFACE_DEFINED__
#define __IPersistStorage_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPersistStorage
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IPersistStorage  *LPPERSISTSTORAGE;


EXTERN_C const IID IID_IPersistStorage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IPersistStorage : public IPersist
    {
    public:
        virtual HRESULT __stdcall IsDirty( void) = 0;
        
        virtual HRESULT __stdcall InitNew( 
            /* [unique][in] */ IStorage  *pStg) = 0;
        
        virtual HRESULT __stdcall Load( 
            /* [unique][in] */ IStorage  *pStg) = 0;
        
        virtual HRESULT __stdcall Save( 
            /* [unique][in] */ IStorage  *pStgSave,
            /* [in] */ BOOL fSameAsLoad) = 0;
        
        virtual HRESULT __stdcall SaveCompleted( 
            /* [unique][in] */ IStorage  *pStgNew) = 0;
        
        virtual HRESULT __stdcall HandsOffStorage( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPersistStorageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IPersistStorage  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IPersistStorage  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IPersistStorage  * This);
        
        HRESULT ( __stdcall  *GetClassID )( 
            IPersistStorage  * This,
            /* [out] */ CLSID  *pClassID);
        
        HRESULT ( __stdcall  *IsDirty )( 
            IPersistStorage  * This);
        
        HRESULT ( __stdcall  *InitNew )( 
            IPersistStorage  * This,
            /* [unique][in] */ IStorage  *pStg);
        
        HRESULT ( __stdcall  *Load )( 
            IPersistStorage  * This,
            /* [unique][in] */ IStorage  *pStg);
        
        HRESULT ( __stdcall  *Save )( 
            IPersistStorage  * This,
            /* [unique][in] */ IStorage  *pStgSave,
            /* [in] */ BOOL fSameAsLoad);
        
        HRESULT ( __stdcall  *SaveCompleted )( 
            IPersistStorage  * This,
            /* [unique][in] */ IStorage  *pStgNew);
        
        HRESULT ( __stdcall  *HandsOffStorage )( 
            IPersistStorage  * This);
        
        END_INTERFACE
    } IPersistStorageVtbl;

    interface IPersistStorage
    {
        CONST_VTBL struct IPersistStorageVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPersistStorage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPersistStorage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPersistStorage_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPersistStorage_GetClassID(This,pClassID)	\
    (This)->lpVtbl -> GetClassID(This,pClassID)


#define IPersistStorage_IsDirty(This)	\
    (This)->lpVtbl -> IsDirty(This)

#define IPersistStorage_InitNew(This,pStg)	\
    (This)->lpVtbl -> InitNew(This,pStg)

#define IPersistStorage_Load(This,pStg)	\
    (This)->lpVtbl -> Load(This,pStg)

#define IPersistStorage_Save(This,pStgSave,fSameAsLoad)	\
    (This)->lpVtbl -> Save(This,pStgSave,fSameAsLoad)

#define IPersistStorage_SaveCompleted(This,pStgNew)	\
    (This)->lpVtbl -> SaveCompleted(This,pStgNew)

#define IPersistStorage_HandsOffStorage(This)	\
    (This)->lpVtbl -> HandsOffStorage(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPersistStorage_IsDirty_Proxy( 
    IPersistStorage  * This);


void __stdcall IPersistStorage_IsDirty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPersistStorage_InitNew_Proxy( 
    IPersistStorage  * This,
    /* [unique][in] */ IStorage  *pStg);


void __stdcall IPersistStorage_InitNew_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPersistStorage_Load_Proxy( 
    IPersistStorage  * This,
    /* [unique][in] */ IStorage  *pStg);


void __stdcall IPersistStorage_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPersistStorage_Save_Proxy( 
    IPersistStorage  * This,
    /* [unique][in] */ IStorage  *pStgSave,
    /* [in] */ BOOL fSameAsLoad);


void __stdcall IPersistStorage_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPersistStorage_SaveCompleted_Proxy( 
    IPersistStorage  * This,
    /* [unique][in] */ IStorage  *pStgNew);


void __stdcall IPersistStorage_SaveCompleted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPersistStorage_HandsOffStorage_Proxy( 
    IPersistStorage  * This);


void __stdcall IPersistStorage_HandsOffStorage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IPersistStorage_INTERFACE_DEFINED__ */


#ifndef __ILockBytes_INTERFACE_DEFINED__
#define __ILockBytes_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ILockBytes
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ ILockBytes  *LPLOCKBYTES;


EXTERN_C const IID IID_ILockBytes;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ILockBytes : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT __stdcall ReadAt( 
            /* [in] */ ULARGE_INTEGER ulOffset,
            /* [length_is][size_is][out] */ void  *pv,
            /* [in] */ unsigned long cb,
            /* [out] */ unsigned long  *pcbRead) = 0;
        
        virtual /* [local] */ HRESULT __stdcall WriteAt( 
            /* [in] */ ULARGE_INTEGER ulOffset,
            /* [size_is][in] */ const void  *pv,
            /* [in] */ unsigned long cb,
            /* [out] */ unsigned long  *pcbWritten) = 0;
        
        virtual HRESULT __stdcall Flush( void) = 0;
        
        virtual HRESULT __stdcall SetSize( 
            /* [in] */ ULARGE_INTEGER cb) = 0;
        
        virtual HRESULT __stdcall LockRegion( 
            /* [in] */ ULARGE_INTEGER libOffset,
            /* [in] */ ULARGE_INTEGER cb,
            /* [in] */ unsigned long dwLockType) = 0;
        
        virtual HRESULT __stdcall UnlockRegion( 
            /* [in] */ ULARGE_INTEGER libOffset,
            /* [in] */ ULARGE_INTEGER cb,
            /* [in] */ unsigned long dwLockType) = 0;
        
        virtual HRESULT __stdcall Stat( 
            /* [out] */ STATSTG  *pstatstg,
            /* [in] */ unsigned long grfStatFlag) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILockBytesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            ILockBytes  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            ILockBytes  * This);
        
        unsigned long ( __stdcall  *Release )( 
            ILockBytes  * This);
        
        /* [local] */ HRESULT ( __stdcall  *ReadAt )( 
            ILockBytes  * This,
            /* [in] */ ULARGE_INTEGER ulOffset,
            /* [length_is][size_is][out] */ void  *pv,
            /* [in] */ unsigned long cb,
            /* [out] */ unsigned long  *pcbRead);
        
        /* [local] */ HRESULT ( __stdcall  *WriteAt )( 
            ILockBytes  * This,
            /* [in] */ ULARGE_INTEGER ulOffset,
            /* [size_is][in] */ const void  *pv,
            /* [in] */ unsigned long cb,
            /* [out] */ unsigned long  *pcbWritten);
        
        HRESULT ( __stdcall  *Flush )( 
            ILockBytes  * This);
        
        HRESULT ( __stdcall  *SetSize )( 
            ILockBytes  * This,
            /* [in] */ ULARGE_INTEGER cb);
        
        HRESULT ( __stdcall  *LockRegion )( 
            ILockBytes  * This,
            /* [in] */ ULARGE_INTEGER libOffset,
            /* [in] */ ULARGE_INTEGER cb,
            /* [in] */ unsigned long dwLockType);
        
        HRESULT ( __stdcall  *UnlockRegion )( 
            ILockBytes  * This,
            /* [in] */ ULARGE_INTEGER libOffset,
            /* [in] */ ULARGE_INTEGER cb,
            /* [in] */ unsigned long dwLockType);
        
        HRESULT ( __stdcall  *Stat )( 
            ILockBytes  * This,
            /* [out] */ STATSTG  *pstatstg,
            /* [in] */ unsigned long grfStatFlag);
        
        END_INTERFACE
    } ILockBytesVtbl;

    interface ILockBytes
    {
        CONST_VTBL struct ILockBytesVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILockBytes_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ILockBytes_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ILockBytes_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ILockBytes_ReadAt(This,ulOffset,pv,cb,pcbRead)	\
    (This)->lpVtbl -> ReadAt(This,ulOffset,pv,cb,pcbRead)

#define ILockBytes_WriteAt(This,ulOffset,pv,cb,pcbWritten)	\
    (This)->lpVtbl -> WriteAt(This,ulOffset,pv,cb,pcbWritten)

#define ILockBytes_Flush(This)	\
    (This)->lpVtbl -> Flush(This)

#define ILockBytes_SetSize(This,cb)	\
    (This)->lpVtbl -> SetSize(This,cb)

#define ILockBytes_LockRegion(This,libOffset,cb,dwLockType)	\
    (This)->lpVtbl -> LockRegion(This,libOffset,cb,dwLockType)

#define ILockBytes_UnlockRegion(This,libOffset,cb,dwLockType)	\
    (This)->lpVtbl -> UnlockRegion(This,libOffset,cb,dwLockType)

#define ILockBytes_Stat(This,pstatstg,grfStatFlag)	\
    (This)->lpVtbl -> Stat(This,pstatstg,grfStatFlag)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall ILockBytes_RemoteReadAt_Proxy( 
    ILockBytes  * This,
    /* [in] */ ULARGE_INTEGER ulOffset,
    /* [length_is][size_is][out] */ byte  *pv,
    /* [in] */ unsigned long cb,
    /* [out] */ unsigned long  *pcbRead);


void __stdcall ILockBytes_RemoteReadAt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall ILockBytes_RemoteWriteAt_Proxy( 
    ILockBytes  * This,
    /* [in] */ ULARGE_INTEGER ulOffset,
    /* [size_is][in] */ const byte  *pv,
    /* [in] */ unsigned long cb,
    /* [out] */ unsigned long  *pcbWritten);


void __stdcall ILockBytes_RemoteWriteAt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ILockBytes_Flush_Proxy( 
    ILockBytes  * This);


void __stdcall ILockBytes_Flush_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ILockBytes_SetSize_Proxy( 
    ILockBytes  * This,
    /* [in] */ ULARGE_INTEGER cb);


void __stdcall ILockBytes_SetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ILockBytes_LockRegion_Proxy( 
    ILockBytes  * This,
    /* [in] */ ULARGE_INTEGER libOffset,
    /* [in] */ ULARGE_INTEGER cb,
    /* [in] */ unsigned long dwLockType);


void __stdcall ILockBytes_LockRegion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ILockBytes_UnlockRegion_Proxy( 
    ILockBytes  * This,
    /* [in] */ ULARGE_INTEGER libOffset,
    /* [in] */ ULARGE_INTEGER cb,
    /* [in] */ unsigned long dwLockType);


void __stdcall ILockBytes_UnlockRegion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ILockBytes_Stat_Proxy( 
    ILockBytes  * This,
    /* [out] */ STATSTG  *pstatstg,
    /* [in] */ unsigned long grfStatFlag);


void __stdcall ILockBytes_Stat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __ILockBytes_INTERFACE_DEFINED__ */


#ifndef __IEnumFORMATETC_INTERFACE_DEFINED__
#define __IEnumFORMATETC_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumFORMATETC
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IEnumFORMATETC  *LPENUMFORMATETC;

typedef struct  tagDVTARGETDEVICE
    {
    unsigned long tdSize;
    WORD tdDriverNameOffset;
    WORD tdDeviceNameOffset;
    WORD tdPortNameOffset;
    WORD tdExtDevmodeOffset;
    /* [size_is] */ BYTE tdData[ 1 ];
    }	DVTARGETDEVICE;

typedef CLIPFORMAT  *LPCLIPFORMAT;

typedef struct  tagFORMATETC
    {
    CLIPFORMAT cfFormat;
    /* [unique] */ DVTARGETDEVICE  *ptd;
    unsigned long dwAspect;
    LONG lindex;
    unsigned long tymed;
    }	FORMATETC;

typedef struct tagFORMATETC  *LPFORMATETC;


EXTERN_C const IID IID_IEnumFORMATETC;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IEnumFORMATETC : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT __stdcall Next( 
            /* [in] */ unsigned long celt,
            /* [length_is][size_is][out] */ FORMATETC  *rgelt,
            /* [out] */ unsigned long  *pceltFetched) = 0;
        
        virtual HRESULT __stdcall Skip( 
            /* [in] */ unsigned long celt) = 0;
        
        virtual HRESULT __stdcall Reset( void) = 0;
        
        virtual HRESULT __stdcall Clone( 
            /* [out] */ IEnumFORMATETC  * *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumFORMATETCVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IEnumFORMATETC  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IEnumFORMATETC  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IEnumFORMATETC  * This);
        
        /* [local] */ HRESULT ( __stdcall  *Next )( 
            IEnumFORMATETC  * This,
            /* [in] */ unsigned long celt,
            /* [length_is][size_is][out] */ FORMATETC  *rgelt,
            /* [out] */ unsigned long  *pceltFetched);
        
        HRESULT ( __stdcall  *Skip )( 
            IEnumFORMATETC  * This,
            /* [in] */ unsigned long celt);
        
        HRESULT ( __stdcall  *Reset )( 
            IEnumFORMATETC  * This);
        
        HRESULT ( __stdcall  *Clone )( 
            IEnumFORMATETC  * This,
            /* [out] */ IEnumFORMATETC  * *ppenum);
        
        END_INTERFACE
    } IEnumFORMATETCVtbl;

    interface IEnumFORMATETC
    {
        CONST_VTBL struct IEnumFORMATETCVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumFORMATETC_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumFORMATETC_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumFORMATETC_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumFORMATETC_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumFORMATETC_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumFORMATETC_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumFORMATETC_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall IEnumFORMATETC_RemoteNext_Proxy( 
    IEnumFORMATETC  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ FORMATETC  *rgelt,
    /* [out] */ unsigned long  *pceltFetched);


void __stdcall IEnumFORMATETC_RemoteNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumFORMATETC_Skip_Proxy( 
    IEnumFORMATETC  * This,
    /* [in] */ unsigned long celt);


void __stdcall IEnumFORMATETC_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumFORMATETC_Reset_Proxy( 
    IEnumFORMATETC  * This);


void __stdcall IEnumFORMATETC_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumFORMATETC_Clone_Proxy( 
    IEnumFORMATETC  * This,
    /* [out] */ IEnumFORMATETC  * *ppenum);


void __stdcall IEnumFORMATETC_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IEnumFORMATETC_INTERFACE_DEFINED__ */


#ifndef __IEnumSTATDATA_INTERFACE_DEFINED__
#define __IEnumSTATDATA_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumSTATDATA
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IEnumSTATDATA  *LPENUMSTATDATA;

typedef 
enum tagADVF
    {	ADVF_NODATA	= 1,
	ADVF_PRIMEFIRST	= 2,
	ADVF_ONLYONCE	= 4,
	ADVF_DATAONSTOP	= 64,
	ADVFCACHE_NOHANDLER	= 8,
	ADVFCACHE_FORCEBUILTIN	= 16,
	ADVFCACHE_ONSAVE	= 32
    }	ADVF;

typedef struct  tagSTATDATA
    {
    FORMATETC formatetc;
    unsigned long advf;
    /* [unique] */ IAdviseSink  *pAdvSink;
    unsigned long dwConnection;
    }	STATDATA;

typedef STATDATA  *LPSTATDATA;


EXTERN_C const IID IID_IEnumSTATDATA;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IEnumSTATDATA : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT __stdcall Next( 
            /* [in] */ unsigned long celt,
            /* [length_is][size_is][out] */ STATDATA  *rgelt,
            /* [out] */ unsigned long  *pceltFetched) = 0;
        
        virtual HRESULT __stdcall Skip( 
            /* [in] */ unsigned long celt) = 0;
        
        virtual HRESULT __stdcall Reset( void) = 0;
        
        virtual HRESULT __stdcall Clone( 
            /* [out] */ IEnumSTATDATA  * *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumSTATDATAVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IEnumSTATDATA  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IEnumSTATDATA  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IEnumSTATDATA  * This);
        
        /* [local] */ HRESULT ( __stdcall  *Next )( 
            IEnumSTATDATA  * This,
            /* [in] */ unsigned long celt,
            /* [length_is][size_is][out] */ STATDATA  *rgelt,
            /* [out] */ unsigned long  *pceltFetched);
        
        HRESULT ( __stdcall  *Skip )( 
            IEnumSTATDATA  * This,
            /* [in] */ unsigned long celt);
        
        HRESULT ( __stdcall  *Reset )( 
            IEnumSTATDATA  * This);
        
        HRESULT ( __stdcall  *Clone )( 
            IEnumSTATDATA  * This,
            /* [out] */ IEnumSTATDATA  * *ppenum);
        
        END_INTERFACE
    } IEnumSTATDATAVtbl;

    interface IEnumSTATDATA
    {
        CONST_VTBL struct IEnumSTATDATAVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumSTATDATA_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumSTATDATA_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumSTATDATA_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumSTATDATA_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumSTATDATA_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumSTATDATA_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumSTATDATA_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall IEnumSTATDATA_RemoteNext_Proxy( 
    IEnumSTATDATA  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ STATDATA  *rgelt,
    /* [out] */ unsigned long  *pceltFetched);


void __stdcall IEnumSTATDATA_RemoteNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumSTATDATA_Skip_Proxy( 
    IEnumSTATDATA  * This,
    /* [in] */ unsigned long celt);


void __stdcall IEnumSTATDATA_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumSTATDATA_Reset_Proxy( 
    IEnumSTATDATA  * This);


void __stdcall IEnumSTATDATA_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumSTATDATA_Clone_Proxy( 
    IEnumSTATDATA  * This,
    /* [out] */ IEnumSTATDATA  * *ppenum);


void __stdcall IEnumSTATDATA_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IEnumSTATDATA_INTERFACE_DEFINED__ */


#ifndef __IRootStorage_INTERFACE_DEFINED__
#define __IRootStorage_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IRootStorage
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IRootStorage  *LPROOTSTORAGE;


EXTERN_C const IID IID_IRootStorage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IRootStorage : public IUnknown
    {
    public:
        virtual HRESULT __stdcall SwitchToFile( 
            /* [in] */ LPOLESTR pszFile) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRootStorageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IRootStorage  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IRootStorage  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IRootStorage  * This);
        
        HRESULT ( __stdcall  *SwitchToFile )( 
            IRootStorage  * This,
            /* [in] */ LPOLESTR pszFile);
        
        END_INTERFACE
    } IRootStorageVtbl;

    interface IRootStorage
    {
        CONST_VTBL struct IRootStorageVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRootStorage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRootStorage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRootStorage_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRootStorage_SwitchToFile(This,pszFile)	\
    (This)->lpVtbl -> SwitchToFile(This,pszFile)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IRootStorage_SwitchToFile_Proxy( 
    IRootStorage  * This,
    /* [in] */ LPOLESTR pszFile);


void __stdcall IRootStorage_SwitchToFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IRootStorage_INTERFACE_DEFINED__ */


#ifndef __IAdviseSink_INTERFACE_DEFINED__
#define __IAdviseSink_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAdviseSink
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef IAdviseSink  *LPADVISESINK;

typedef /* [v1_enum] */ 
enum tagTYMED
    {	TYMED_HGLOBAL	= 1,
	TYMED_FILE	= 2,
	TYMED_ISTREAM	= 4,
	TYMED_ISTORAGE	= 8,
	TYMED_GDI	= 16,
	TYMED_MFPICT	= 32,
	TYMED_ENHMF	= 64,
	TYMED_NULL	= 0
    }	TYMED;

#ifndef RC_INVOKED
#pragma warning(disable:4200)
#endif
typedef struct  tagRemSTGMEDIUM
    {
    unsigned long tymed;
    unsigned long dwHandleType;
    unsigned long pData;
    unsigned long pUnkForRelease;
    unsigned long cbData;
    /* [size_is] */ byte data[ 1 ];
    }	RemSTGMEDIUM;

#ifndef RC_INVOKED
#pragma warning(default:4200)
#endif
#ifdef NONAMELESSUNION
typedef struct tagSTGMEDIUM {
    unsigned long tymed;
    union {
        HBITMAP hBitmap;
        HMETAFILEPICT hMetaFilePict;
        HENHMETAFILE hEnhMetaFile;
        HGLOBAL hGlobal;
        LPOLESTR lpszFileName;
        IStream *pstm;
        IStorage *pstg;
        } u;
    IUnknown *pUnkForRelease;
}uSTGMEDIUM;
#else
typedef struct  tagSTGMEDIUM
    {
    unsigned long tymed;
    /* [switch_is][switch_type] */ union 
        {
        /* [case()] */ HBITMAP hBitmap;
        /* [case()] */ HMETAFILEPICT hMetaFilePict;
        /* [case()] */ HENHMETAFILE hEnhMetaFile;
        /* [case()] */ HGLOBAL hGlobal;
        /* [case()] */ LPOLESTR lpszFileName;
        /* [case()] */ IStream  *pstm;
        /* [case()] */ IStorage  *pstg;
        /* [default] */  /* Empty union arm */ 
        }	;
    /* [unique] */ IUnknown  *pUnkForRelease;
    }	uSTGMEDIUM;

#endif /* !NONAMELESSUNION */
typedef struct  _GDI_OBJECT
    {
    unsigned long ObjectType;
    /* [switch_is] */ /* [switch_type] */ union __MIDL_IAdviseSink_0002
        {
        /* [case()] */ wireHBITMAP hBitmap;
        /* [case()] */ wireHPALETTE hPalette;
        /* [default] */ wireHGLOBAL hGeneric;
        }	u;
    }	GDI_OBJECT;

typedef struct  _userSTGMEDIUM
    {
    struct  _STGMEDIUM_UNION
        {
        unsigned long tymed;
        /* [switch_is] */ /* [switch_type] */ union __MIDL_IAdviseSink_0003
            {
            /* [case()] */  /* Empty union arm */ 
            /* [case()] */ wireHMETAFILEPICT hMetaFilePict;
            /* [case()] */ wireHENHMETAFILE hHEnhMetaFile;
            /* [case()] */ GDI_OBJECT  *hGdiHandle;
            /* [case()] */ wireHGLOBAL hGlobal;
            /* [case()] */ LPOLESTR lpszFileName;
            /* [case()] */ BYTE_BLOB  *pstm;
            /* [case()] */ BYTE_BLOB  *pstg;
            }	u;
        }	;
    IUnknown  *pUnkForRelease;
    }	userSTGMEDIUM;

typedef /* [unique] */ userSTGMEDIUM  *wireSTGMEDIUM;

typedef /* [wire_marshal] */ uSTGMEDIUM STGMEDIUM;

typedef /* [unique] */ userSTGMEDIUM  *wireASYNC_STGMEDIUM;

typedef /* [wire_marshal] */ STGMEDIUM ASYNC_STGMEDIUM;

typedef STGMEDIUM  *LPSTGMEDIUM;

typedef struct  _userFLAG_STGMEDIUM
    {
    long ContextFlags;
    long fPassOwnership;
    userSTGMEDIUM Stgmed;
    }	userFLAG_STGMEDIUM;

typedef /* [unique] */ userFLAG_STGMEDIUM  *wireFLAG_STGMEDIUM;

typedef /* [wire_marshal] */ struct  _FLAG_STGMEDIUM
    {
    long ContextFlags;
    long fPassOwnership;
    STGMEDIUM Stgmed;
    }	FLAG_STGMEDIUM;


EXTERN_C const IID IID_IAdviseSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IAdviseSink : public IUnknown
    {
    public:
        virtual /* [local] */ void __stdcall OnDataChange( 
            /* [unique][in] */ FORMATETC  *pFormatetc,
            /* [unique][in] */ STGMEDIUM  *pStgmed) = 0;
        
        virtual /* [local] */ void __stdcall OnViewChange( 
            /* [in] */ unsigned long dwAspect,
            /* [in] */ LONG lindex) = 0;
        
        virtual /* [local] */ void __stdcall OnRename( 
            /* [in] */ IMoniker  *pmk) = 0;
        
        virtual /* [local] */ void __stdcall OnSave( void) = 0;
        
        virtual /* [local] */ void __stdcall OnClose( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAdviseSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IAdviseSink  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IAdviseSink  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IAdviseSink  * This);
        
        /* [local] */ void ( __stdcall  *OnDataChange )( 
            IAdviseSink  * This,
            /* [unique][in] */ FORMATETC  *pFormatetc,
            /* [unique][in] */ STGMEDIUM  *pStgmed);
        
        /* [local] */ void ( __stdcall  *OnViewChange )( 
            IAdviseSink  * This,
            /* [in] */ unsigned long dwAspect,
            /* [in] */ LONG lindex);
        
        /* [local] */ void ( __stdcall  *OnRename )( 
            IAdviseSink  * This,
            /* [in] */ IMoniker  *pmk);
        
        /* [local] */ void ( __stdcall  *OnSave )( 
            IAdviseSink  * This);
        
        /* [local] */ void ( __stdcall  *OnClose )( 
            IAdviseSink  * This);
        
        END_INTERFACE
    } IAdviseSinkVtbl;

    interface IAdviseSink
    {
        CONST_VTBL struct IAdviseSinkVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAdviseSink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAdviseSink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAdviseSink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAdviseSink_OnDataChange(This,pFormatetc,pStgmed)	\
    (This)->lpVtbl -> OnDataChange(This,pFormatetc,pStgmed)

#define IAdviseSink_OnViewChange(This,dwAspect,lindex)	\
    (This)->lpVtbl -> OnViewChange(This,dwAspect,lindex)

#define IAdviseSink_OnRename(This,pmk)	\
    (This)->lpVtbl -> OnRename(This,pmk)

#define IAdviseSink_OnSave(This)	\
    (This)->lpVtbl -> OnSave(This)

#define IAdviseSink_OnClose(This)	\
    (This)->lpVtbl -> OnClose(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [async][call_as] */ void __stdcall IAdviseSink_RemoteOnDataChange_Proxy( 
    IAdviseSink  * This,
    /* [unique][in] */ FORMATETC  *pFormatetc,
    /* [unique][in] */ ASYNC_STGMEDIUM  *pStgmed);


void __stdcall IAdviseSink_RemoteOnDataChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [async][call_as] */ void __stdcall IAdviseSink_RemoteOnViewChange_Proxy( 
    IAdviseSink  * This,
    /* [in] */ unsigned long dwAspect,
    /* [in] */ LONG lindex);


void __stdcall IAdviseSink_RemoteOnViewChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [async][call_as] */ void __stdcall IAdviseSink_RemoteOnRename_Proxy( 
    IAdviseSink  * This,
    /* [in] */ IMoniker  *pmk);


void __stdcall IAdviseSink_RemoteOnRename_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [async][call_as] */ void __stdcall IAdviseSink_RemoteOnSave_Proxy( 
    IAdviseSink  * This);


void __stdcall IAdviseSink_RemoteOnSave_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall IAdviseSink_RemoteOnClose_Proxy( 
    IAdviseSink  * This);


void __stdcall IAdviseSink_RemoteOnClose_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IAdviseSink_INTERFACE_DEFINED__ */


#ifndef __IAdviseSink2_INTERFACE_DEFINED__
#define __IAdviseSink2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAdviseSink2
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IAdviseSink2  *LPADVISESINK2;


EXTERN_C const IID IID_IAdviseSink2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IAdviseSink2 : public IAdviseSink
    {
    public:
        virtual /* [local] */ void __stdcall OnLinkSrcChange( 
            /* [unique][in] */ IMoniker  *pmk) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAdviseSink2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IAdviseSink2  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IAdviseSink2  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IAdviseSink2  * This);
        
        /* [local] */ void ( __stdcall  *OnDataChange )( 
            IAdviseSink2  * This,
            /* [unique][in] */ FORMATETC  *pFormatetc,
            /* [unique][in] */ STGMEDIUM  *pStgmed);
        
        /* [local] */ void ( __stdcall  *OnViewChange )( 
            IAdviseSink2  * This,
            /* [in] */ unsigned long dwAspect,
            /* [in] */ LONG lindex);
        
        /* [local] */ void ( __stdcall  *OnRename )( 
            IAdviseSink2  * This,
            /* [in] */ IMoniker  *pmk);
        
        /* [local] */ void ( __stdcall  *OnSave )( 
            IAdviseSink2  * This);
        
        /* [local] */ void ( __stdcall  *OnClose )( 
            IAdviseSink2  * This);
        
        /* [local] */ void ( __stdcall  *OnLinkSrcChange )( 
            IAdviseSink2  * This,
            /* [unique][in] */ IMoniker  *pmk);
        
        END_INTERFACE
    } IAdviseSink2Vtbl;

    interface IAdviseSink2
    {
        CONST_VTBL struct IAdviseSink2Vtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAdviseSink2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAdviseSink2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAdviseSink2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAdviseSink2_OnDataChange(This,pFormatetc,pStgmed)	\
    (This)->lpVtbl -> OnDataChange(This,pFormatetc,pStgmed)

#define IAdviseSink2_OnViewChange(This,dwAspect,lindex)	\
    (This)->lpVtbl -> OnViewChange(This,dwAspect,lindex)

#define IAdviseSink2_OnRename(This,pmk)	\
    (This)->lpVtbl -> OnRename(This,pmk)

#define IAdviseSink2_OnSave(This)	\
    (This)->lpVtbl -> OnSave(This)

#define IAdviseSink2_OnClose(This)	\
    (This)->lpVtbl -> OnClose(This)


#define IAdviseSink2_OnLinkSrcChange(This,pmk)	\
    (This)->lpVtbl -> OnLinkSrcChange(This,pmk)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [async][call_as] */ void __stdcall IAdviseSink2_RemoteOnLinkSrcChange_Proxy( 
    IAdviseSink2  * This,
    /* [unique][in] */ IMoniker  *pmk);


void __stdcall IAdviseSink2_RemoteOnLinkSrcChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IAdviseSink2_INTERFACE_DEFINED__ */


#ifndef __IDataObject_INTERFACE_DEFINED__
#define __IDataObject_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IDataObject
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IDataObject  *LPDATAOBJECT;

typedef 
enum tagDATADIR
    {	DATADIR_GET	= 1,
	DATADIR_SET	= 2
    }	DATADIR;


EXTERN_C const IID IID_IDataObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IDataObject : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT __stdcall GetData( 
            /* [unique][in] */ FORMATETC  *pformatetcIn,
            /* [out] */ STGMEDIUM  *pmedium) = 0;
        
        virtual /* [local] */ HRESULT __stdcall GetDataHere( 
            /* [unique][in] */ FORMATETC  *pformatetc,
            /* [out][in] */ STGMEDIUM  *pmedium) = 0;
        
        virtual HRESULT __stdcall QueryGetData( 
            /* [unique][in] */ FORMATETC  *pformatetc) = 0;
        
        virtual HRESULT __stdcall GetCanonicalFormatEtc( 
            /* [unique][in] */ FORMATETC  *pformatectIn,
            /* [out] */ FORMATETC  *pformatetcOut) = 0;
        
        virtual /* [local] */ HRESULT __stdcall SetData( 
            /* [unique][in] */ FORMATETC  *pformatetc,
            /* [unique][in] */ STGMEDIUM  *pmedium,
            /* [in] */ BOOL fRelease) = 0;
        
        virtual HRESULT __stdcall EnumFormatEtc( 
            /* [in] */ unsigned long dwDirection,
            /* [out] */ IEnumFORMATETC  * *ppenumFormatEtc) = 0;
        
        virtual HRESULT __stdcall DAdvise( 
            /* [in] */ FORMATETC  *pformatetc,
            /* [in] */ unsigned long advf,
            /* [unique][in] */ IAdviseSink  *pAdvSink,
            /* [out] */ unsigned long  *pdwConnection) = 0;
        
        virtual HRESULT __stdcall DUnadvise( 
            /* [in] */ unsigned long dwConnection) = 0;
        
        virtual HRESULT __stdcall EnumDAdvise( 
            /* [out] */ IEnumSTATDATA  * *ppenumAdvise) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDataObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IDataObject  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IDataObject  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IDataObject  * This);
        
        /* [local] */ HRESULT ( __stdcall  *GetData )( 
            IDataObject  * This,
            /* [unique][in] */ FORMATETC  *pformatetcIn,
            /* [out] */ STGMEDIUM  *pmedium);
        
        /* [local] */ HRESULT ( __stdcall  *GetDataHere )( 
            IDataObject  * This,
            /* [unique][in] */ FORMATETC  *pformatetc,
            /* [out][in] */ STGMEDIUM  *pmedium);
        
        HRESULT ( __stdcall  *QueryGetData )( 
            IDataObject  * This,
            /* [unique][in] */ FORMATETC  *pformatetc);
        
        HRESULT ( __stdcall  *GetCanonicalFormatEtc )( 
            IDataObject  * This,
            /* [unique][in] */ FORMATETC  *pformatectIn,
            /* [out] */ FORMATETC  *pformatetcOut);
        
        /* [local] */ HRESULT ( __stdcall  *SetData )( 
            IDataObject  * This,
            /* [unique][in] */ FORMATETC  *pformatetc,
            /* [unique][in] */ STGMEDIUM  *pmedium,
            /* [in] */ BOOL fRelease);
        
        HRESULT ( __stdcall  *EnumFormatEtc )( 
            IDataObject  * This,
            /* [in] */ unsigned long dwDirection,
            /* [out] */ IEnumFORMATETC  * *ppenumFormatEtc);
        
        HRESULT ( __stdcall  *DAdvise )( 
            IDataObject  * This,
            /* [in] */ FORMATETC  *pformatetc,
            /* [in] */ unsigned long advf,
            /* [unique][in] */ IAdviseSink  *pAdvSink,
            /* [out] */ unsigned long  *pdwConnection);
        
        HRESULT ( __stdcall  *DUnadvise )( 
            IDataObject  * This,
            /* [in] */ unsigned long dwConnection);
        
        HRESULT ( __stdcall  *EnumDAdvise )( 
            IDataObject  * This,
            /* [out] */ IEnumSTATDATA  * *ppenumAdvise);
        
        END_INTERFACE
    } IDataObjectVtbl;

    interface IDataObject
    {
        CONST_VTBL struct IDataObjectVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDataObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDataObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDataObject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDataObject_GetData(This,pformatetcIn,pmedium)	\
    (This)->lpVtbl -> GetData(This,pformatetcIn,pmedium)

#define IDataObject_GetDataHere(This,pformatetc,pmedium)	\
    (This)->lpVtbl -> GetDataHere(This,pformatetc,pmedium)

#define IDataObject_QueryGetData(This,pformatetc)	\
    (This)->lpVtbl -> QueryGetData(This,pformatetc)

#define IDataObject_GetCanonicalFormatEtc(This,pformatectIn,pformatetcOut)	\
    (This)->lpVtbl -> GetCanonicalFormatEtc(This,pformatectIn,pformatetcOut)

#define IDataObject_SetData(This,pformatetc,pmedium,fRelease)	\
    (This)->lpVtbl -> SetData(This,pformatetc,pmedium,fRelease)

#define IDataObject_EnumFormatEtc(This,dwDirection,ppenumFormatEtc)	\
    (This)->lpVtbl -> EnumFormatEtc(This,dwDirection,ppenumFormatEtc)

#define IDataObject_DAdvise(This,pformatetc,advf,pAdvSink,pdwConnection)	\
    (This)->lpVtbl -> DAdvise(This,pformatetc,advf,pAdvSink,pdwConnection)

#define IDataObject_DUnadvise(This,dwConnection)	\
    (This)->lpVtbl -> DUnadvise(This,dwConnection)

#define IDataObject_EnumDAdvise(This,ppenumAdvise)	\
    (This)->lpVtbl -> EnumDAdvise(This,ppenumAdvise)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall IDataObject_RemoteGetData_Proxy( 
    IDataObject  * This,
    /* [unique][in] */ FORMATETC  *pformatetcIn,
    /* [out] */ STGMEDIUM  *pRemoteMedium);


void __stdcall IDataObject_RemoteGetData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall IDataObject_RemoteGetDataHere_Proxy( 
    IDataObject  * This,
    /* [unique][in] */ FORMATETC  *pformatetc,
    /* [out][in] */ STGMEDIUM  *pRemoteMedium);


void __stdcall IDataObject_RemoteGetDataHere_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IDataObject_QueryGetData_Proxy( 
    IDataObject  * This,
    /* [unique][in] */ FORMATETC  *pformatetc);


void __stdcall IDataObject_QueryGetData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IDataObject_GetCanonicalFormatEtc_Proxy( 
    IDataObject  * This,
    /* [unique][in] */ FORMATETC  *pformatectIn,
    /* [out] */ FORMATETC  *pformatetcOut);


void __stdcall IDataObject_GetCanonicalFormatEtc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall IDataObject_RemoteSetData_Proxy( 
    IDataObject  * This,
    /* [unique][in] */ FORMATETC  *pformatetc,
    /* [unique][in] */ FLAG_STGMEDIUM  *pmedium,
    /* [in] */ BOOL fRelease);


void __stdcall IDataObject_RemoteSetData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IDataObject_EnumFormatEtc_Proxy( 
    IDataObject  * This,
    /* [in] */ unsigned long dwDirection,
    /* [out] */ IEnumFORMATETC  * *ppenumFormatEtc);


void __stdcall IDataObject_EnumFormatEtc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IDataObject_DAdvise_Proxy( 
    IDataObject  * This,
    /* [in] */ FORMATETC  *pformatetc,
    /* [in] */ unsigned long advf,
    /* [unique][in] */ IAdviseSink  *pAdvSink,
    /* [out] */ unsigned long  *pdwConnection);


void __stdcall IDataObject_DAdvise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IDataObject_DUnadvise_Proxy( 
    IDataObject  * This,
    /* [in] */ unsigned long dwConnection);


void __stdcall IDataObject_DUnadvise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IDataObject_EnumDAdvise_Proxy( 
    IDataObject  * This,
    /* [out] */ IEnumSTATDATA  * *ppenumAdvise);


void __stdcall IDataObject_EnumDAdvise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IDataObject_INTERFACE_DEFINED__ */


#ifndef __IDataAdviseHolder_INTERFACE_DEFINED__
#define __IDataAdviseHolder_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IDataAdviseHolder
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [uuid][object][local] */ 


typedef /* [unique] */ IDataAdviseHolder  *LPDATAADVISEHOLDER;


EXTERN_C const IID IID_IDataAdviseHolder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IDataAdviseHolder : public IUnknown
    {
    public:
        virtual HRESULT __stdcall Advise( 
            /* [unique][in] */ IDataObject  *pDataObject,
            /* [unique][in] */ FORMATETC  *pFetc,
            /* [in] */ unsigned long advf,
            /* [unique][in] */ IAdviseSink  *pAdvise,
            /* [out] */ unsigned long  *pdwConnection) = 0;
        
        virtual HRESULT __stdcall Unadvise( 
            /* [in] */ unsigned long dwConnection) = 0;
        
        virtual HRESULT __stdcall EnumAdvise( 
            /* [out] */ IEnumSTATDATA  * *ppenumAdvise) = 0;
        
        virtual HRESULT __stdcall SendOnDataChange( 
            /* [unique][in] */ IDataObject  *pDataObject,
            /* [in] */ unsigned long dwReserved,
            /* [in] */ unsigned long advf) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDataAdviseHolderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IDataAdviseHolder  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IDataAdviseHolder  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IDataAdviseHolder  * This);
        
        HRESULT ( __stdcall  *Advise )( 
            IDataAdviseHolder  * This,
            /* [unique][in] */ IDataObject  *pDataObject,
            /* [unique][in] */ FORMATETC  *pFetc,
            /* [in] */ unsigned long advf,
            /* [unique][in] */ IAdviseSink  *pAdvise,
            /* [out] */ unsigned long  *pdwConnection);
        
        HRESULT ( __stdcall  *Unadvise )( 
            IDataAdviseHolder  * This,
            /* [in] */ unsigned long dwConnection);
        
        HRESULT ( __stdcall  *EnumAdvise )( 
            IDataAdviseHolder  * This,
            /* [out] */ IEnumSTATDATA  * *ppenumAdvise);
        
        HRESULT ( __stdcall  *SendOnDataChange )( 
            IDataAdviseHolder  * This,
            /* [unique][in] */ IDataObject  *pDataObject,
            /* [in] */ unsigned long dwReserved,
            /* [in] */ unsigned long advf);
        
        END_INTERFACE
    } IDataAdviseHolderVtbl;

    interface IDataAdviseHolder
    {
        CONST_VTBL struct IDataAdviseHolderVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDataAdviseHolder_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDataAdviseHolder_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDataAdviseHolder_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDataAdviseHolder_Advise(This,pDataObject,pFetc,advf,pAdvise,pdwConnection)	\
    (This)->lpVtbl -> Advise(This,pDataObject,pFetc,advf,pAdvise,pdwConnection)

#define IDataAdviseHolder_Unadvise(This,dwConnection)	\
    (This)->lpVtbl -> Unadvise(This,dwConnection)

#define IDataAdviseHolder_EnumAdvise(This,ppenumAdvise)	\
    (This)->lpVtbl -> EnumAdvise(This,ppenumAdvise)

#define IDataAdviseHolder_SendOnDataChange(This,pDataObject,dwReserved,advf)	\
    (This)->lpVtbl -> SendOnDataChange(This,pDataObject,dwReserved,advf)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IDataAdviseHolder_Advise_Proxy( 
    IDataAdviseHolder  * This,
    /* [unique][in] */ IDataObject  *pDataObject,
    /* [unique][in] */ FORMATETC  *pFetc,
    /* [in] */ unsigned long advf,
    /* [unique][in] */ IAdviseSink  *pAdvise,
    /* [out] */ unsigned long  *pdwConnection);


void __stdcall IDataAdviseHolder_Advise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IDataAdviseHolder_Unadvise_Proxy( 
    IDataAdviseHolder  * This,
    /* [in] */ unsigned long dwConnection);


void __stdcall IDataAdviseHolder_Unadvise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IDataAdviseHolder_EnumAdvise_Proxy( 
    IDataAdviseHolder  * This,
    /* [out] */ IEnumSTATDATA  * *ppenumAdvise);


void __stdcall IDataAdviseHolder_EnumAdvise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IDataAdviseHolder_SendOnDataChange_Proxy( 
    IDataAdviseHolder  * This,
    /* [unique][in] */ IDataObject  *pDataObject,
    /* [in] */ unsigned long dwReserved,
    /* [in] */ unsigned long advf);


void __stdcall IDataAdviseHolder_SendOnDataChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IDataAdviseHolder_INTERFACE_DEFINED__ */


#ifndef __IMessageFilter_INTERFACE_DEFINED__
#define __IMessageFilter_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IMessageFilter
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [uuid][object][local] */ 


typedef /* [unique] */ IMessageFilter  *LPMESSAGEFILTER;

typedef 
enum tagCALLTYPE
    {	CALLTYPE_TOPLEVEL	= 1,
	CALLTYPE_NESTED	= 2,
	CALLTYPE_ASYNC	= 3,
	CALLTYPE_TOPLEVEL_CALLPENDING	= 4,
	CALLTYPE_ASYNC_CALLPENDING	= 5
    }	CALLTYPE;

typedef 
enum tagSERVERCALL
    {	SERVERCALL_ISHANDLED	= 0,
	SERVERCALL_REJECTED	= 1,
	SERVERCALL_RETRYLATER	= 2
    }	SERVERCALL;

typedef 
enum tagPENDINGTYPE
    {	PENDINGTYPE_TOPLEVEL	= 1,
	PENDINGTYPE_NESTED	= 2
    }	PENDINGTYPE;

typedef 
enum tagPENDINGMSG
    {	PENDINGMSG_CANCELCALL	= 0,
	PENDINGMSG_WAITNOPROCESS	= 1,
	PENDINGMSG_WAITDEFPROCESS	= 2
    }	PENDINGMSG;

typedef struct  tagINTERFACEINFO
    {
    IUnknown  *pUnk;
    IID iid;
    WORD wMethod;
    }	INTERFACEINFO;

typedef struct tagINTERFACEINFO  *LPINTERFACEINFO;


EXTERN_C const IID IID_IMessageFilter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IMessageFilter : public IUnknown
    {
    public:
        virtual unsigned long __stdcall HandleInComingCall( 
            /* [in] */ unsigned long dwCallType,
            /* [in] */ HTASK htaskCaller,
            /* [in] */ unsigned long dwTickCount,
            /* [in] */ LPINTERFACEINFO lpInterfaceInfo) = 0;
        
        virtual unsigned long __stdcall RetryRejectedCall( 
            /* [in] */ HTASK htaskCallee,
            /* [in] */ unsigned long dwTickCount,
            /* [in] */ unsigned long dwRejectType) = 0;
        
        virtual unsigned long __stdcall MessagePending( 
            /* [in] */ HTASK htaskCallee,
            /* [in] */ unsigned long dwTickCount,
            /* [in] */ unsigned long dwPendingType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMessageFilterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IMessageFilter  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IMessageFilter  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IMessageFilter  * This);
        
        unsigned long ( __stdcall  *HandleInComingCall )( 
            IMessageFilter  * This,
            /* [in] */ unsigned long dwCallType,
            /* [in] */ HTASK htaskCaller,
            /* [in] */ unsigned long dwTickCount,
            /* [in] */ LPINTERFACEINFO lpInterfaceInfo);
        
        unsigned long ( __stdcall  *RetryRejectedCall )( 
            IMessageFilter  * This,
            /* [in] */ HTASK htaskCallee,
            /* [in] */ unsigned long dwTickCount,
            /* [in] */ unsigned long dwRejectType);
        
        unsigned long ( __stdcall  *MessagePending )( 
            IMessageFilter  * This,
            /* [in] */ HTASK htaskCallee,
            /* [in] */ unsigned long dwTickCount,
            /* [in] */ unsigned long dwPendingType);
        
        END_INTERFACE
    } IMessageFilterVtbl;

    interface IMessageFilter
    {
        CONST_VTBL struct IMessageFilterVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMessageFilter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMessageFilter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMessageFilter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMessageFilter_HandleInComingCall(This,dwCallType,htaskCaller,dwTickCount,lpInterfaceInfo)	\
    (This)->lpVtbl -> HandleInComingCall(This,dwCallType,htaskCaller,dwTickCount,lpInterfaceInfo)

#define IMessageFilter_RetryRejectedCall(This,htaskCallee,dwTickCount,dwRejectType)	\
    (This)->lpVtbl -> RetryRejectedCall(This,htaskCallee,dwTickCount,dwRejectType)

#define IMessageFilter_MessagePending(This,htaskCallee,dwTickCount,dwPendingType)	\
    (This)->lpVtbl -> MessagePending(This,htaskCallee,dwTickCount,dwPendingType)

#endif /* COBJMACROS */


#endif 	/* C style interface */



unsigned long __stdcall IMessageFilter_HandleInComingCall_Proxy( 
    IMessageFilter  * This,
    /* [in] */ unsigned long dwCallType,
    /* [in] */ HTASK htaskCaller,
    /* [in] */ unsigned long dwTickCount,
    /* [in] */ LPINTERFACEINFO lpInterfaceInfo);


void __stdcall IMessageFilter_HandleInComingCall_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


unsigned long __stdcall IMessageFilter_RetryRejectedCall_Proxy( 
    IMessageFilter  * This,
    /* [in] */ HTASK htaskCallee,
    /* [in] */ unsigned long dwTickCount,
    /* [in] */ unsigned long dwRejectType);


void __stdcall IMessageFilter_RetryRejectedCall_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


unsigned long __stdcall IMessageFilter_MessagePending_Proxy( 
    IMessageFilter  * This,
    /* [in] */ HTASK htaskCallee,
    /* [in] */ unsigned long dwTickCount,
    /* [in] */ unsigned long dwPendingType);


void __stdcall IMessageFilter_MessagePending_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IMessageFilter_INTERFACE_DEFINED__ */


#ifndef __IRpcChannelBuffer_INTERFACE_DEFINED__
#define __IRpcChannelBuffer_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IRpcChannelBuffer
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [uuid][object][local] */ 


typedef unsigned long RPCOLEDATAREP;

typedef struct  tagRPCOLEMESSAGE
    {
    void  *reserved1;
    RPCOLEDATAREP dataRepresentation;
    void  *Buffer;
    unsigned long cbBuffer;
    unsigned long iMethod;
    void  *reserved2[ 5 ];
    unsigned long rpcFlags;
    }	RPCOLEMESSAGE;

typedef RPCOLEMESSAGE  *PRPCOLEMESSAGE;


EXTERN_C const IID IID_IRpcChannelBuffer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IRpcChannelBuffer : public IUnknown
    {
    public:
        virtual HRESULT __stdcall GetBuffer( 
            /* [in] */ RPCOLEMESSAGE  *pMessage,
            /* [in] */ REFIID riid) = 0;
        
        virtual HRESULT __stdcall SendReceive( 
            /* [out][in] */ RPCOLEMESSAGE  *pMessage,
            /* [out] */ unsigned long  *pStatus) = 0;
        
        virtual HRESULT __stdcall FreeBuffer( 
            /* [in] */ RPCOLEMESSAGE  *pMessage) = 0;
        
        virtual HRESULT __stdcall GetDestCtx( 
            /* [out] */ unsigned long  *pdwDestContext,
            /* [out] */ void  * *ppvDestContext) = 0;
        
        virtual HRESULT __stdcall IsConnected( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRpcChannelBufferVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IRpcChannelBuffer  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IRpcChannelBuffer  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IRpcChannelBuffer  * This);
        
        HRESULT ( __stdcall  *GetBuffer )( 
            IRpcChannelBuffer  * This,
            /* [in] */ RPCOLEMESSAGE  *pMessage,
            /* [in] */ REFIID riid);
        
        HRESULT ( __stdcall  *SendReceive )( 
            IRpcChannelBuffer  * This,
            /* [out][in] */ RPCOLEMESSAGE  *pMessage,
            /* [out] */ unsigned long  *pStatus);
        
        HRESULT ( __stdcall  *FreeBuffer )( 
            IRpcChannelBuffer  * This,
            /* [in] */ RPCOLEMESSAGE  *pMessage);
        
        HRESULT ( __stdcall  *GetDestCtx )( 
            IRpcChannelBuffer  * This,
            /* [out] */ unsigned long  *pdwDestContext,
            /* [out] */ void  * *ppvDestContext);
        
        HRESULT ( __stdcall  *IsConnected )( 
            IRpcChannelBuffer  * This);
        
        END_INTERFACE
    } IRpcChannelBufferVtbl;

    interface IRpcChannelBuffer
    {
        CONST_VTBL struct IRpcChannelBufferVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRpcChannelBuffer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRpcChannelBuffer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRpcChannelBuffer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRpcChannelBuffer_GetBuffer(This,pMessage,riid)	\
    (This)->lpVtbl -> GetBuffer(This,pMessage,riid)

#define IRpcChannelBuffer_SendReceive(This,pMessage,pStatus)	\
    (This)->lpVtbl -> SendReceive(This,pMessage,pStatus)

#define IRpcChannelBuffer_FreeBuffer(This,pMessage)	\
    (This)->lpVtbl -> FreeBuffer(This,pMessage)

#define IRpcChannelBuffer_GetDestCtx(This,pdwDestContext,ppvDestContext)	\
    (This)->lpVtbl -> GetDestCtx(This,pdwDestContext,ppvDestContext)

#define IRpcChannelBuffer_IsConnected(This)	\
    (This)->lpVtbl -> IsConnected(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IRpcChannelBuffer_GetBuffer_Proxy( 
    IRpcChannelBuffer  * This,
    /* [in] */ RPCOLEMESSAGE  *pMessage,
    /* [in] */ REFIID riid);


void __stdcall IRpcChannelBuffer_GetBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IRpcChannelBuffer_SendReceive_Proxy( 
    IRpcChannelBuffer  * This,
    /* [out][in] */ RPCOLEMESSAGE  *pMessage,
    /* [out] */ unsigned long  *pStatus);


void __stdcall IRpcChannelBuffer_SendReceive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IRpcChannelBuffer_FreeBuffer_Proxy( 
    IRpcChannelBuffer  * This,
    /* [in] */ RPCOLEMESSAGE  *pMessage);


void __stdcall IRpcChannelBuffer_FreeBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IRpcChannelBuffer_GetDestCtx_Proxy( 
    IRpcChannelBuffer  * This,
    /* [out] */ unsigned long  *pdwDestContext,
    /* [out] */ void  * *ppvDestContext);


void __stdcall IRpcChannelBuffer_GetDestCtx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IRpcChannelBuffer_IsConnected_Proxy( 
    IRpcChannelBuffer  * This);


void __stdcall IRpcChannelBuffer_IsConnected_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IRpcChannelBuffer_INTERFACE_DEFINED__ */


#ifndef __IRpcProxyBuffer_INTERFACE_DEFINED__
#define __IRpcProxyBuffer_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IRpcProxyBuffer
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IRpcProxyBuffer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IRpcProxyBuffer : public IUnknown
    {
    public:
        virtual HRESULT __stdcall Connect( 
            /* [unique][in] */ IRpcChannelBuffer  *pRpcChannelBuffer) = 0;
        
        virtual void __stdcall Disconnect( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRpcProxyBufferVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IRpcProxyBuffer  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IRpcProxyBuffer  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IRpcProxyBuffer  * This);
        
        HRESULT ( __stdcall  *Connect )( 
            IRpcProxyBuffer  * This,
            /* [unique][in] */ IRpcChannelBuffer  *pRpcChannelBuffer);
        
        void ( __stdcall  *Disconnect )( 
            IRpcProxyBuffer  * This);
        
        END_INTERFACE
    } IRpcProxyBufferVtbl;

    interface IRpcProxyBuffer
    {
        CONST_VTBL struct IRpcProxyBufferVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRpcProxyBuffer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRpcProxyBuffer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRpcProxyBuffer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRpcProxyBuffer_Connect(This,pRpcChannelBuffer)	\
    (This)->lpVtbl -> Connect(This,pRpcChannelBuffer)

#define IRpcProxyBuffer_Disconnect(This)	\
    (This)->lpVtbl -> Disconnect(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IRpcProxyBuffer_Connect_Proxy( 
    IRpcProxyBuffer  * This,
    /* [unique][in] */ IRpcChannelBuffer  *pRpcChannelBuffer);


void __stdcall IRpcProxyBuffer_Connect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


void __stdcall IRpcProxyBuffer_Disconnect_Proxy( 
    IRpcProxyBuffer  * This);


void __stdcall IRpcProxyBuffer_Disconnect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IRpcProxyBuffer_INTERFACE_DEFINED__ */


#ifndef __IRpcStubBuffer_INTERFACE_DEFINED__
#define __IRpcStubBuffer_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IRpcStubBuffer
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IRpcStubBuffer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IRpcStubBuffer : public IUnknown
    {
    public:
        virtual HRESULT __stdcall Connect( 
            /* [in] */ IUnknown  *pUnkServer) = 0;
        
        virtual void __stdcall Disconnect( void) = 0;
        
        virtual HRESULT __stdcall Invoke( 
            /* [in] */ RPCOLEMESSAGE  *_prpcmsg,
            /* [in] */ IRpcChannelBuffer  *_pRpcChannelBuffer) = 0;
        
        virtual IRpcStubBuffer  *__stdcall IsIIDSupported( 
            /* [in] */ REFIID riid) = 0;
        
        virtual unsigned long __stdcall CountRefs( void) = 0;
        
        virtual HRESULT __stdcall DebugServerQueryInterface( 
            void  * *ppv) = 0;
        
        virtual void __stdcall DebugServerRelease( 
            void  *pv) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRpcStubBufferVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IRpcStubBuffer  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IRpcStubBuffer  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IRpcStubBuffer  * This);
        
        HRESULT ( __stdcall  *Connect )( 
            IRpcStubBuffer  * This,
            /* [in] */ IUnknown  *pUnkServer);
        
        void ( __stdcall  *Disconnect )( 
            IRpcStubBuffer  * This);
        
        HRESULT ( __stdcall  *Invoke )( 
            IRpcStubBuffer  * This,
            /* [in] */ RPCOLEMESSAGE  *_prpcmsg,
            /* [in] */ IRpcChannelBuffer  *_pRpcChannelBuffer);
        
        IRpcStubBuffer  *( __stdcall  *IsIIDSupported )( 
            IRpcStubBuffer  * This,
            /* [in] */ REFIID riid);
        
        unsigned long ( __stdcall  *CountRefs )( 
            IRpcStubBuffer  * This);
        
        HRESULT ( __stdcall  *DebugServerQueryInterface )( 
            IRpcStubBuffer  * This,
            void  * *ppv);
        
        void ( __stdcall  *DebugServerRelease )( 
            IRpcStubBuffer  * This,
            void  *pv);
        
        END_INTERFACE
    } IRpcStubBufferVtbl;

    interface IRpcStubBuffer
    {
        CONST_VTBL struct IRpcStubBufferVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRpcStubBuffer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRpcStubBuffer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRpcStubBuffer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRpcStubBuffer_Connect(This,pUnkServer)	\
    (This)->lpVtbl -> Connect(This,pUnkServer)

#define IRpcStubBuffer_Disconnect(This)	\
    (This)->lpVtbl -> Disconnect(This)

#define IRpcStubBuffer_Invoke(This,_prpcmsg,_pRpcChannelBuffer)	\
    (This)->lpVtbl -> Invoke(This,_prpcmsg,_pRpcChannelBuffer)

#define IRpcStubBuffer_IsIIDSupported(This,riid)	\
    (This)->lpVtbl -> IsIIDSupported(This,riid)

#define IRpcStubBuffer_CountRefs(This)	\
    (This)->lpVtbl -> CountRefs(This)

#define IRpcStubBuffer_DebugServerQueryInterface(This,ppv)	\
    (This)->lpVtbl -> DebugServerQueryInterface(This,ppv)

#define IRpcStubBuffer_DebugServerRelease(This,pv)	\
    (This)->lpVtbl -> DebugServerRelease(This,pv)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IRpcStubBuffer_Connect_Proxy( 
    IRpcStubBuffer  * This,
    /* [in] */ IUnknown  *pUnkServer);


void __stdcall IRpcStubBuffer_Connect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


void __stdcall IRpcStubBuffer_Disconnect_Proxy( 
    IRpcStubBuffer  * This);


void __stdcall IRpcStubBuffer_Disconnect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IRpcStubBuffer_Invoke_Proxy( 
    IRpcStubBuffer  * This,
    /* [in] */ RPCOLEMESSAGE  *_prpcmsg,
    /* [in] */ IRpcChannelBuffer  *_pRpcChannelBuffer);


void __stdcall IRpcStubBuffer_Invoke_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


IRpcStubBuffer  *__stdcall IRpcStubBuffer_IsIIDSupported_Proxy( 
    IRpcStubBuffer  * This,
    /* [in] */ REFIID riid);


void __stdcall IRpcStubBuffer_IsIIDSupported_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


unsigned long __stdcall IRpcStubBuffer_CountRefs_Proxy( 
    IRpcStubBuffer  * This);


void __stdcall IRpcStubBuffer_CountRefs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IRpcStubBuffer_DebugServerQueryInterface_Proxy( 
    IRpcStubBuffer  * This,
    void  * *ppv);


void __stdcall IRpcStubBuffer_DebugServerQueryInterface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


void __stdcall IRpcStubBuffer_DebugServerRelease_Proxy( 
    IRpcStubBuffer  * This,
    void  *pv);


void __stdcall IRpcStubBuffer_DebugServerRelease_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IRpcStubBuffer_INTERFACE_DEFINED__ */


#ifndef __IPSFactoryBuffer_INTERFACE_DEFINED__
#define __IPSFactoryBuffer_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPSFactoryBuffer
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IPSFactoryBuffer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IPSFactoryBuffer : public IUnknown
    {
    public:
        virtual HRESULT __stdcall CreateProxy( 
            /* [in] */ IUnknown  *pUnkOuter,
            /* [in] */ REFIID riid,
            /* [out] */ IRpcProxyBuffer  * *ppProxy,
            /* [out] */ void  * *ppv) = 0;
        
        virtual HRESULT __stdcall CreateStub( 
            /* [in] */ REFIID riid,
            /* [unique][in] */ IUnknown  *pUnkServer,
            /* [out] */ IRpcStubBuffer  * *ppStub) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPSFactoryBufferVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IPSFactoryBuffer  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IPSFactoryBuffer  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IPSFactoryBuffer  * This);
        
        HRESULT ( __stdcall  *CreateProxy )( 
            IPSFactoryBuffer  * This,
            /* [in] */ IUnknown  *pUnkOuter,
            /* [in] */ REFIID riid,
            /* [out] */ IRpcProxyBuffer  * *ppProxy,
            /* [out] */ void  * *ppv);
        
        HRESULT ( __stdcall  *CreateStub )( 
            IPSFactoryBuffer  * This,
            /* [in] */ REFIID riid,
            /* [unique][in] */ IUnknown  *pUnkServer,
            /* [out] */ IRpcStubBuffer  * *ppStub);
        
        END_INTERFACE
    } IPSFactoryBufferVtbl;

    interface IPSFactoryBuffer
    {
        CONST_VTBL struct IPSFactoryBufferVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPSFactoryBuffer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPSFactoryBuffer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPSFactoryBuffer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPSFactoryBuffer_CreateProxy(This,pUnkOuter,riid,ppProxy,ppv)	\
    (This)->lpVtbl -> CreateProxy(This,pUnkOuter,riid,ppProxy,ppv)

#define IPSFactoryBuffer_CreateStub(This,riid,pUnkServer,ppStub)	\
    (This)->lpVtbl -> CreateStub(This,riid,pUnkServer,ppStub)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPSFactoryBuffer_CreateProxy_Proxy( 
    IPSFactoryBuffer  * This,
    /* [in] */ IUnknown  *pUnkOuter,
    /* [in] */ REFIID riid,
    /* [out] */ IRpcProxyBuffer  * *ppProxy,
    /* [out] */ void  * *ppv);


void __stdcall IPSFactoryBuffer_CreateProxy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPSFactoryBuffer_CreateStub_Proxy( 
    IPSFactoryBuffer  * This,
    /* [in] */ REFIID riid,
    /* [unique][in] */ IUnknown  *pUnkServer,
    /* [out] */ IRpcStubBuffer  * *ppStub);


void __stdcall IPSFactoryBuffer_CreateStub_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IPSFactoryBuffer_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0041
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#if  (_WIN32_WINNT >= 0x0400 ) || defined(_WIN32_DCOM) // DCOM
// This interface is only valid on Windows NT 4.0


extern RPC_IF_HANDLE __MIDL__intf_0041_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0041_v0_0_s_ifspec;

#ifndef __IChannelHook_INTERFACE_DEFINED__
#define __IChannelHook_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IChannelHook
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IChannelHook;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IChannelHook : public IUnknown
    {
    public:
        virtual void __stdcall ClientGetSize( 
            /* [in] */ REFGUID uExtent,
            /* [in] */ REFIID riid,
            /* [out] */ unsigned long  *pDataSize) = 0;
        
        virtual void __stdcall ClientFillBuffer( 
            /* [in] */ REFGUID uExtent,
            /* [in] */ REFIID riid,
            /* [out][in] */ unsigned long  *pDataSize,
            /* [in] */ void  *pDataBuffer) = 0;
        
        virtual void __stdcall ClientNotify( 
            /* [in] */ REFGUID uExtent,
            /* [in] */ REFIID riid,
            /* [in] */ unsigned long cbDataSize,
            /* [in] */ void  *pDataBuffer,
            /* [in] */ unsigned long lDataRep,
            /* [in] */ HRESULT hrFault) = 0;
        
        virtual void __stdcall ServerNotify( 
            /* [in] */ REFGUID uExtent,
            /* [in] */ REFIID riid,
            /* [in] */ unsigned long cbDataSize,
            /* [in] */ void  *pDataBuffer,
            /* [in] */ unsigned long lDataRep) = 0;
        
        virtual void __stdcall ServerGetSize( 
            /* [in] */ REFGUID uExtent,
            /* [in] */ REFIID riid,
            /* [in] */ HRESULT hrFault,
            /* [out] */ unsigned long  *pDataSize) = 0;
        
        virtual void __stdcall ServerFillBuffer( 
            /* [in] */ REFGUID uExtent,
            /* [in] */ REFIID riid,
            /* [out][in] */ unsigned long  *pDataSize,
            /* [in] */ void  *pDataBuffer,
            /* [in] */ HRESULT hrFault) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IChannelHookVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IChannelHook  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IChannelHook  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IChannelHook  * This);
        
        void ( __stdcall  *ClientGetSize )( 
            IChannelHook  * This,
            /* [in] */ REFGUID uExtent,
            /* [in] */ REFIID riid,
            /* [out] */ unsigned long  *pDataSize);
        
        void ( __stdcall  *ClientFillBuffer )( 
            IChannelHook  * This,
            /* [in] */ REFGUID uExtent,
            /* [in] */ REFIID riid,
            /* [out][in] */ unsigned long  *pDataSize,
            /* [in] */ void  *pDataBuffer);
        
        void ( __stdcall  *ClientNotify )( 
            IChannelHook  * This,
            /* [in] */ REFGUID uExtent,
            /* [in] */ REFIID riid,
            /* [in] */ unsigned long cbDataSize,
            /* [in] */ void  *pDataBuffer,
            /* [in] */ unsigned long lDataRep,
            /* [in] */ HRESULT hrFault);
        
        void ( __stdcall  *ServerNotify )( 
            IChannelHook  * This,
            /* [in] */ REFGUID uExtent,
            /* [in] */ REFIID riid,
            /* [in] */ unsigned long cbDataSize,
            /* [in] */ void  *pDataBuffer,
            /* [in] */ unsigned long lDataRep);
        
        void ( __stdcall  *ServerGetSize )( 
            IChannelHook  * This,
            /* [in] */ REFGUID uExtent,
            /* [in] */ REFIID riid,
            /* [in] */ HRESULT hrFault,
            /* [out] */ unsigned long  *pDataSize);
        
        void ( __stdcall  *ServerFillBuffer )( 
            IChannelHook  * This,
            /* [in] */ REFGUID uExtent,
            /* [in] */ REFIID riid,
            /* [out][in] */ unsigned long  *pDataSize,
            /* [in] */ void  *pDataBuffer,
            /* [in] */ HRESULT hrFault);
        
        END_INTERFACE
    } IChannelHookVtbl;

    interface IChannelHook
    {
        CONST_VTBL struct IChannelHookVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IChannelHook_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IChannelHook_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IChannelHook_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IChannelHook_ClientGetSize(This,uExtent,riid,pDataSize)	\
    (This)->lpVtbl -> ClientGetSize(This,uExtent,riid,pDataSize)

#define IChannelHook_ClientFillBuffer(This,uExtent,riid,pDataSize,pDataBuffer)	\
    (This)->lpVtbl -> ClientFillBuffer(This,uExtent,riid,pDataSize,pDataBuffer)

#define IChannelHook_ClientNotify(This,uExtent,riid,cbDataSize,pDataBuffer,lDataRep,hrFault)	\
    (This)->lpVtbl -> ClientNotify(This,uExtent,riid,cbDataSize,pDataBuffer,lDataRep,hrFault)

#define IChannelHook_ServerNotify(This,uExtent,riid,cbDataSize,pDataBuffer,lDataRep)	\
    (This)->lpVtbl -> ServerNotify(This,uExtent,riid,cbDataSize,pDataBuffer,lDataRep)

#define IChannelHook_ServerGetSize(This,uExtent,riid,hrFault,pDataSize)	\
    (This)->lpVtbl -> ServerGetSize(This,uExtent,riid,hrFault,pDataSize)

#define IChannelHook_ServerFillBuffer(This,uExtent,riid,pDataSize,pDataBuffer,hrFault)	\
    (This)->lpVtbl -> ServerFillBuffer(This,uExtent,riid,pDataSize,pDataBuffer,hrFault)

#endif /* COBJMACROS */


#endif 	/* C style interface */



void __stdcall IChannelHook_ClientGetSize_Proxy( 
    IChannelHook  * This,
    /* [in] */ REFGUID uExtent,
    /* [in] */ REFIID riid,
    /* [out] */ unsigned long  *pDataSize);


void __stdcall IChannelHook_ClientGetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


void __stdcall IChannelHook_ClientFillBuffer_Proxy( 
    IChannelHook  * This,
    /* [in] */ REFGUID uExtent,
    /* [in] */ REFIID riid,
    /* [out][in] */ unsigned long  *pDataSize,
    /* [in] */ void  *pDataBuffer);


void __stdcall IChannelHook_ClientFillBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


void __stdcall IChannelHook_ClientNotify_Proxy( 
    IChannelHook  * This,
    /* [in] */ REFGUID uExtent,
    /* [in] */ REFIID riid,
    /* [in] */ unsigned long cbDataSize,
    /* [in] */ void  *pDataBuffer,
    /* [in] */ unsigned long lDataRep,
    /* [in] */ HRESULT hrFault);


void __stdcall IChannelHook_ClientNotify_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


void __stdcall IChannelHook_ServerNotify_Proxy( 
    IChannelHook  * This,
    /* [in] */ REFGUID uExtent,
    /* [in] */ REFIID riid,
    /* [in] */ unsigned long cbDataSize,
    /* [in] */ void  *pDataBuffer,
    /* [in] */ unsigned long lDataRep);


void __stdcall IChannelHook_ServerNotify_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


void __stdcall IChannelHook_ServerGetSize_Proxy( 
    IChannelHook  * This,
    /* [in] */ REFGUID uExtent,
    /* [in] */ REFIID riid,
    /* [in] */ HRESULT hrFault,
    /* [out] */ unsigned long  *pDataSize);


void __stdcall IChannelHook_ServerGetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


void __stdcall IChannelHook_ServerFillBuffer_Proxy( 
    IChannelHook  * This,
    /* [in] */ REFGUID uExtent,
    /* [in] */ REFIID riid,
    /* [out][in] */ unsigned long  *pDataSize,
    /* [in] */ void  *pDataBuffer,
    /* [in] */ HRESULT hrFault);


void __stdcall IChannelHook_ServerFillBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IChannelHook_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0042
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif //DCOM




extern RPC_IF_HANDLE __MIDL__intf_0042_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0042_v0_0_s_ifspec;

#ifndef __IPropertyStorage_INTERFACE_DEFINED__
#define __IPropertyStorage_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPropertyStorage
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 



// Well-known Property Set Format IDs
extern const FMTID FMTID_SummaryInformation;

extern const FMTID FMTID_DocSummaryInformation;

extern const FMTID FMTID_UserDefinedProperties;


// Flags for IPropertySetStorage::Create
#define	PROPSETFLAG_DEFAULT	( 0 )

#define	PROPSETFLAG_NONSIMPLE	( 1 )

#define	PROPSETFLAG_ANSI	( 2 )

typedef /* [unique] */ IPropertyStorage  *LPPROPERTYSTORAGE;

typedef struct tagPROPVARIANT PROPVARIANT;

typedef struct  tagCAUB
    {
    unsigned long cElems;
    /* [size_is] */ unsigned char  *pElems;
    }	CAUB;

typedef struct  tagCAI
    {
    unsigned long cElems;
    /* [size_is] */ short  *pElems;
    }	CAI;

typedef struct  tagCAUI
    {
    unsigned long cElems;
    /* [size_is] */ USHORT  *pElems;
    }	CAUI;

typedef struct  tagCAL
    {
    unsigned long cElems;
    /* [size_is] */ long  *pElems;
    }	CAL;

typedef struct  tagCAUL
    {
    unsigned long cElems;
    /* [size_is] */ unsigned long  *pElems;
    }	CAUL;

typedef struct  tagCAFLT
    {
    unsigned long cElems;
    /* [size_is] */ float  *pElems;
    }	CAFLT;

typedef struct  tagCADBL
    {
    unsigned long cElems;
    /* [size_is] */ double  *pElems;
    }	CADBL;

typedef struct  tagCACY
    {
    unsigned long cElems;
    /* [size_is] */ CY  *pElems;
    }	CACY;

typedef struct  tagCADATE
    {
    unsigned long cElems;
    /* [size_is] */ DATE  *pElems;
    }	CADATE;

typedef struct  tagCABSTR
    {
    unsigned long cElems;
    /* [size_is] */ BSTR  *pElems;
    }	CABSTR;

typedef struct  tagCABOOL
    {
    unsigned long cElems;
    /* [size_is] */ VARIANT_BOOL  *pElems;
    }	CABOOL;

typedef struct  tagCASCODE
    {
    unsigned long cElems;
    /* [size_is] */ SCODE  *pElems;
    }	CASCODE;

typedef struct  tagCAPROPVARIANT
    {
    unsigned long cElems;
    /* [size_is] */ PROPVARIANT  *pElems;
    }	CAPROPVARIANT;

typedef struct  tagCAH
    {
    unsigned long cElems;
    /* [size_is] */ LARGE_INTEGER  *pElems;
    }	CAH;

typedef struct  tagCAUH
    {
    unsigned long cElems;
    /* [size_is] */ ULARGE_INTEGER  *pElems;
    }	CAUH;

typedef struct  tagCALPSTR
    {
    unsigned long cElems;
    /* [size_is] */ LPSTR  *pElems;
    }	CALPSTR;

typedef struct  tagCALPWSTR
    {
    unsigned long cElems;
    /* [size_is] */ LPWSTR  *pElems;
    }	CALPWSTR;

typedef struct  tagCAFILETIME
    {
    unsigned long cElems;
    /* [size_is] */ FILETIME  *pElems;
    }	CAFILETIME;

typedef struct  tagCACLIPDATA
    {
    unsigned long cElems;
    /* [size_is] */ CLIPDATA  *pElems;
    }	CACLIPDATA;

typedef struct  tagCACLSID
    {
    unsigned long cElems;
    /* [size_is] */ CLSID  *pElems;
    }	CACLSID;

// Disable the warning about the obsolete member named 'bool'
// 'bool', 'true', 'false', 'mutable', 'explicit', & 'typename'
// are reserved keywords
#pragma warning(disable:4237)
struct  tagPROPVARIANT
    {
    VARTYPE vt;
    WORD wReserved1;
    WORD wReserved2;
    WORD wReserved3;
    /* [switch_is] */ /* [switch_type] */ union 
        {
        /* [case()] */  /* Empty union arm */ 
        /* [case()] */ UCHAR bVal;
        /* [case()] */ short iVal;
        /* [case()] */ USHORT uiVal;
        /* [case()] */ VARIANT_BOOL boolVal;
        /* [case()] */ _VARIANT_BOOL bool;
        /* [case()] */ long lVal;
        /* [case()] */ unsigned long ulVal;
        /* [case()] */ float fltVal;
        /* [case()] */ SCODE scode;
        /* [case()] */ LARGE_INTEGER hVal;
        /* [case()] */ ULARGE_INTEGER uhVal;
        /* [case()] */ double dblVal;
        /* [case()] */ CY cyVal;
        /* [case()] */ DATE date;
        /* [case()] */ FILETIME filetime;
        /* [case()] */ CLSID  *puuid;
        /* [case()] */ BLOB blob;
        /* [case()] */ CLIPDATA  *pclipdata;
        /* [case()] */ IStream  *pStream;
        /* [case()] */ IStorage  *pStorage;
        /* [case()] */ BSTR bstrVal;
        /* [case()] */ LPSTR pszVal;
        /* [case()] */ LPWSTR pwszVal;
        /* [case()] */ CAUB caub;
        /* [case()] */ CAI cai;
        /* [case()] */ CAUI caui;
        /* [case()] */ CABOOL cabool;
        /* [case()] */ CAL cal;
        /* [case()] */ CAUL caul;
        /* [case()] */ CAFLT caflt;
        /* [case()] */ CASCODE cascode;
        /* [case()] */ CAH cah;
        /* [case()] */ CAUH cauh;
        /* [case()] */ CADBL cadbl;
        /* [case()] */ CACY cacy;
        /* [case()] */ CADATE cadate;
        /* [case()] */ CAFILETIME cafiletime;
        /* [case()] */ CACLSID cauuid;
        /* [case()] */ CACLIPDATA caclipdata;
        /* [case()] */ CABSTR cabstr;
        /* [case()] */ CALPSTR calpstr;
        /* [case()] */ CALPWSTR calpwstr;
        /* [case()] */ CAPROPVARIANT capropvar;
        }	;
    };
typedef struct tagPROPVARIANT  *LPPROPVARIANT;

// Reserved global Property IDs
#define	PID_DICTIONARY	( 0 )

#define	PID_CODEPAGE	( 0x1 )

#define	PID_FIRST_USABLE	( 0x2 )

#define	PID_FIRST_NAME_DEFAULT	( 0xfff )

#define	PID_LOCALE	( 0x80000000 )

#define	PID_MODIFY_TIME	( 0x80000001 )

#define	PID_SECURITY	( 0x80000002 )

#define	PID_ILLEGAL	( 0xffffffff )

// Property IDs for the SummaryInformation Property Set

#define PIDSI_TITLE               0x00000002L  // VT_LPSTR
#define PIDSI_SUBJECT             0x00000003L  // VT_LPSTR
#define PIDSI_AUTHOR              0x00000004L  // VT_LPSTR
#define PIDSI_KEYWORDS            0x00000005L  // VT_LPSTR
#define PIDSI_COMMENTS            0x00000006L  // VT_LPSTR
#define PIDSI_TEMPLATE            0x00000007L  // VT_LPSTR
#define PIDSI_LASTAUTHOR          0x00000008L  // VT_LPSTR
#define PIDSI_REVNUMBER           0x00000009L  // VT_LPSTR
#define PIDSI_EDITTIME            0x0000000aL  // VT_FILETIME (UTC)
#define PIDSI_LASTPRINTED         0x0000000bL  // VT_FILETIME (UTC)
#define PIDSI_CREATE_DTM          0x0000000cL  // VT_FILETIME (UTC)
#define PIDSI_LASTSAVE_DTM        0x0000000dL  // VT_FILETIME (UTC)
#define PIDSI_PAGECOUNT           0x0000000eL  // VT_I4
#define PIDSI_WORDCOUNT           0x0000000fL  // VT_I4
#define PIDSI_CHARCOUNT           0x00000010L  // VT_I4
#define PIDSI_THUMBNAIL           0x00000011L  // VT_CF
#define PIDSI_APPNAME             0x00000012L  // VT_LPSTR
#define PIDSI_DOC_SECURITY        0x00000013L  // VT_I4
#define	PRSPEC_INVALID	( 0xffffffff )

#define	PRSPEC_LPWSTR	( 0 )

#define	PRSPEC_PROPID	( 1 )

typedef struct  tagPROPSPEC
    {
    unsigned long ulKind;
    /* [switch_is] */ /* [switch_type] */ union 
        {
        /* [case()] */ PROPID propid;
        /* [case()] */ LPOLESTR lpwstr;
        /* [default] */  /* Empty union arm */ 
        }	;
    }	PROPSPEC;

typedef struct  tagSTATPROPSTG
    {
    LPOLESTR lpwstrName;
    PROPID propid;
    VARTYPE vt;
    }	STATPROPSTG;

// Macros for parsing the OS Version of the Property Set Header
#define PROPSETHDR_OSVER_KIND(dwOSVer)      HIWORD( (dwOSVer) )
#define PROPSETHDR_OSVER_MAJOR(dwOSVer)     LOBYTE(LOWORD( (dwOSVer) ))
#define PROPSETHDR_OSVER_MINOR(dwOSVer)     HIBYTE(LOWORD( (dwOSVer) ))
#define PROPSETHDR_OSVERSION_UNKNOWN        0xFFFFFFFF
typedef struct  tagSTATPROPSETSTG
    {
    FMTID fmtid;
    CLSID clsid;
    unsigned long grfFlags;
    FILETIME mtime;
    FILETIME ctime;
    FILETIME atime;
    unsigned long dwOSVersion;
    }	STATPROPSETSTG;


EXTERN_C const IID IID_IPropertyStorage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IPropertyStorage : public IUnknown
    {
    public:
        virtual HRESULT __stdcall ReadMultiple( 
            /* [in] */ unsigned long cpspec,
            /* [size_is][in] */ const PROPSPEC  rgpspec[  ],
            /* [size_is][out] */ PROPVARIANT  rgpropvar[  ]) = 0;
        
        virtual HRESULT __stdcall WriteMultiple( 
            /* [in] */ unsigned long cpspec,
            /* [size_is][in] */ const PROPSPEC  rgpspec[  ],
            /* [size_is][in] */ const PROPVARIANT  rgpropvar[  ],
            /* [in] */ PROPID propidNameFirst) = 0;
        
        virtual HRESULT __stdcall DeleteMultiple( 
            /* [in] */ unsigned long cpspec,
            /* [size_is][in] */ const PROPSPEC  rgpspec[  ]) = 0;
        
        virtual HRESULT __stdcall ReadPropertyNames( 
            /* [in] */ unsigned long cpropid,
            /* [size_is][in] */ const PROPID  rgpropid[  ],
            /* [size_is][out] */ LPOLESTR  rglpwstrName[  ]) = 0;
        
        virtual HRESULT __stdcall WritePropertyNames( 
            /* [in] */ unsigned long cpropid,
            /* [size_is][in] */ const PROPID  rgpropid[  ],
            /* [size_is][in] */ const LPOLESTR  rglpwstrName[  ]) = 0;
        
        virtual HRESULT __stdcall DeletePropertyNames( 
            /* [in] */ unsigned long cpropid,
            /* [size_is][in] */ const PROPID  rgpropid[  ]) = 0;
        
        virtual HRESULT __stdcall Commit( 
            /* [in] */ unsigned long grfCommitFlags) = 0;
        
        virtual HRESULT __stdcall Revert( void) = 0;
        
        virtual HRESULT __stdcall Enum( 
            /* [out] */ IEnumSTATPROPSTG  * *ppenum) = 0;
        
        virtual HRESULT __stdcall SetTimes( 
            /* [in] */ const FILETIME  *pctime,
            /* [in] */ const FILETIME  *patime,
            /* [in] */ const FILETIME  *pmtime) = 0;
        
        virtual HRESULT __stdcall SetClass( 
            /* [in] */ REFCLSID clsid) = 0;
        
        virtual HRESULT __stdcall Stat( 
            /* [out] */ STATPROPSETSTG  *pstatpsstg) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPropertyStorageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IPropertyStorage  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IPropertyStorage  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IPropertyStorage  * This);
        
        HRESULT ( __stdcall  *ReadMultiple )( 
            IPropertyStorage  * This,
            /* [in] */ unsigned long cpspec,
            /* [size_is][in] */ const PROPSPEC  rgpspec[  ],
            /* [size_is][out] */ PROPVARIANT  rgpropvar[  ]);
        
        HRESULT ( __stdcall  *WriteMultiple )( 
            IPropertyStorage  * This,
            /* [in] */ unsigned long cpspec,
            /* [size_is][in] */ const PROPSPEC  rgpspec[  ],
            /* [size_is][in] */ const PROPVARIANT  rgpropvar[  ],
            /* [in] */ PROPID propidNameFirst);
        
        HRESULT ( __stdcall  *DeleteMultiple )( 
            IPropertyStorage  * This,
            /* [in] */ unsigned long cpspec,
            /* [size_is][in] */ const PROPSPEC  rgpspec[  ]);
        
        HRESULT ( __stdcall  *ReadPropertyNames )( 
            IPropertyStorage  * This,
            /* [in] */ unsigned long cpropid,
            /* [size_is][in] */ const PROPID  rgpropid[  ],
            /* [size_is][out] */ LPOLESTR  rglpwstrName[  ]);
        
        HRESULT ( __stdcall  *WritePropertyNames )( 
            IPropertyStorage  * This,
            /* [in] */ unsigned long cpropid,
            /* [size_is][in] */ const PROPID  rgpropid[  ],
            /* [size_is][in] */ const LPOLESTR  rglpwstrName[  ]);
        
        HRESULT ( __stdcall  *DeletePropertyNames )( 
            IPropertyStorage  * This,
            /* [in] */ unsigned long cpropid,
            /* [size_is][in] */ const PROPID  rgpropid[  ]);
        
        HRESULT ( __stdcall  *Commit )( 
            IPropertyStorage  * This,
            /* [in] */ unsigned long grfCommitFlags);
        
        HRESULT ( __stdcall  *Revert )( 
            IPropertyStorage  * This);
        
        HRESULT ( __stdcall  *Enum )( 
            IPropertyStorage  * This,
            /* [out] */ IEnumSTATPROPSTG  * *ppenum);
        
        HRESULT ( __stdcall  *SetTimes )( 
            IPropertyStorage  * This,
            /* [in] */ const FILETIME  *pctime,
            /* [in] */ const FILETIME  *patime,
            /* [in] */ const FILETIME  *pmtime);
        
        HRESULT ( __stdcall  *SetClass )( 
            IPropertyStorage  * This,
            /* [in] */ REFCLSID clsid);
        
        HRESULT ( __stdcall  *Stat )( 
            IPropertyStorage  * This,
            /* [out] */ STATPROPSETSTG  *pstatpsstg);
        
        END_INTERFACE
    } IPropertyStorageVtbl;

    interface IPropertyStorage
    {
        CONST_VTBL struct IPropertyStorageVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPropertyStorage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPropertyStorage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPropertyStorage_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPropertyStorage_ReadMultiple(This,cpspec,rgpspec,rgpropvar)	\
    (This)->lpVtbl -> ReadMultiple(This,cpspec,rgpspec,rgpropvar)

#define IPropertyStorage_WriteMultiple(This,cpspec,rgpspec,rgpropvar,propidNameFirst)	\
    (This)->lpVtbl -> WriteMultiple(This,cpspec,rgpspec,rgpropvar,propidNameFirst)

#define IPropertyStorage_DeleteMultiple(This,cpspec,rgpspec)	\
    (This)->lpVtbl -> DeleteMultiple(This,cpspec,rgpspec)

#define IPropertyStorage_ReadPropertyNames(This,cpropid,rgpropid,rglpwstrName)	\
    (This)->lpVtbl -> ReadPropertyNames(This,cpropid,rgpropid,rglpwstrName)

#define IPropertyStorage_WritePropertyNames(This,cpropid,rgpropid,rglpwstrName)	\
    (This)->lpVtbl -> WritePropertyNames(This,cpropid,rgpropid,rglpwstrName)

#define IPropertyStorage_DeletePropertyNames(This,cpropid,rgpropid)	\
    (This)->lpVtbl -> DeletePropertyNames(This,cpropid,rgpropid)

#define IPropertyStorage_Commit(This,grfCommitFlags)	\
    (This)->lpVtbl -> Commit(This,grfCommitFlags)

#define IPropertyStorage_Revert(This)	\
    (This)->lpVtbl -> Revert(This)

#define IPropertyStorage_Enum(This,ppenum)	\
    (This)->lpVtbl -> Enum(This,ppenum)

#define IPropertyStorage_SetTimes(This,pctime,patime,pmtime)	\
    (This)->lpVtbl -> SetTimes(This,pctime,patime,pmtime)

#define IPropertyStorage_SetClass(This,clsid)	\
    (This)->lpVtbl -> SetClass(This,clsid)

#define IPropertyStorage_Stat(This,pstatpsstg)	\
    (This)->lpVtbl -> Stat(This,pstatpsstg)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPropertyStorage_ReadMultiple_Proxy( 
    IPropertyStorage  * This,
    /* [in] */ unsigned long cpspec,
    /* [size_is][in] */ const PROPSPEC  rgpspec[  ],
    /* [size_is][out] */ PROPVARIANT  rgpropvar[  ]);


void __stdcall IPropertyStorage_ReadMultiple_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPropertyStorage_WriteMultiple_Proxy( 
    IPropertyStorage  * This,
    /* [in] */ unsigned long cpspec,
    /* [size_is][in] */ const PROPSPEC  rgpspec[  ],
    /* [size_is][in] */ const PROPVARIANT  rgpropvar[  ],
    /* [in] */ PROPID propidNameFirst);


void __stdcall IPropertyStorage_WriteMultiple_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPropertyStorage_DeleteMultiple_Proxy( 
    IPropertyStorage  * This,
    /* [in] */ unsigned long cpspec,
    /* [size_is][in] */ const PROPSPEC  rgpspec[  ]);


void __stdcall IPropertyStorage_DeleteMultiple_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPropertyStorage_ReadPropertyNames_Proxy( 
    IPropertyStorage  * This,
    /* [in] */ unsigned long cpropid,
    /* [size_is][in] */ const PROPID  rgpropid[  ],
    /* [size_is][out] */ LPOLESTR  rglpwstrName[  ]);


void __stdcall IPropertyStorage_ReadPropertyNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPropertyStorage_WritePropertyNames_Proxy( 
    IPropertyStorage  * This,
    /* [in] */ unsigned long cpropid,
    /* [size_is][in] */ const PROPID  rgpropid[  ],
    /* [size_is][in] */ const LPOLESTR  rglpwstrName[  ]);


void __stdcall IPropertyStorage_WritePropertyNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPropertyStorage_DeletePropertyNames_Proxy( 
    IPropertyStorage  * This,
    /* [in] */ unsigned long cpropid,
    /* [size_is][in] */ const PROPID  rgpropid[  ]);


void __stdcall IPropertyStorage_DeletePropertyNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPropertyStorage_Commit_Proxy( 
    IPropertyStorage  * This,
    /* [in] */ unsigned long grfCommitFlags);


void __stdcall IPropertyStorage_Commit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPropertyStorage_Revert_Proxy( 
    IPropertyStorage  * This);


void __stdcall IPropertyStorage_Revert_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPropertyStorage_Enum_Proxy( 
    IPropertyStorage  * This,
    /* [out] */ IEnumSTATPROPSTG  * *ppenum);


void __stdcall IPropertyStorage_Enum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPropertyStorage_SetTimes_Proxy( 
    IPropertyStorage  * This,
    /* [in] */ const FILETIME  *pctime,
    /* [in] */ const FILETIME  *patime,
    /* [in] */ const FILETIME  *pmtime);


void __stdcall IPropertyStorage_SetTimes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPropertyStorage_SetClass_Proxy( 
    IPropertyStorage  * This,
    /* [in] */ REFCLSID clsid);


void __stdcall IPropertyStorage_SetClass_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPropertyStorage_Stat_Proxy( 
    IPropertyStorage  * This,
    /* [out] */ STATPROPSETSTG  *pstatpsstg);


void __stdcall IPropertyStorage_Stat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IPropertyStorage_INTERFACE_DEFINED__ */


#ifndef __IPropertySetStorage_INTERFACE_DEFINED__
#define __IPropertySetStorage_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPropertySetStorage
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IPropertySetStorage  *LPPROPERTYSETSTORAGE;


EXTERN_C const IID IID_IPropertySetStorage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IPropertySetStorage : public IUnknown
    {
    public:
        virtual HRESULT __stdcall Create( 
            /* [in] */ REFFMTID rfmtid,
            /* [unique][in] */ const CLSID  *pclsid,
            /* [in] */ unsigned long grfFlags,
            /* [in] */ unsigned long grfMode,
            /* [out] */ IPropertyStorage  * *ppprstg) = 0;
        
        virtual HRESULT __stdcall Open( 
            /* [in] */ REFFMTID rfmtid,
            /* [in] */ unsigned long grfMode,
            /* [out] */ IPropertyStorage  * *ppprstg) = 0;
        
        virtual HRESULT __stdcall Delete( 
            /* [in] */ REFFMTID rfmtid) = 0;
        
        virtual HRESULT __stdcall Enum( 
            /* [out] */ IEnumSTATPROPSETSTG  * *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPropertySetStorageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IPropertySetStorage  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IPropertySetStorage  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IPropertySetStorage  * This);
        
        HRESULT ( __stdcall  *Create )( 
            IPropertySetStorage  * This,
            /* [in] */ REFFMTID rfmtid,
            /* [unique][in] */ const CLSID  *pclsid,
            /* [in] */ unsigned long grfFlags,
            /* [in] */ unsigned long grfMode,
            /* [out] */ IPropertyStorage  * *ppprstg);
        
        HRESULT ( __stdcall  *Open )( 
            IPropertySetStorage  * This,
            /* [in] */ REFFMTID rfmtid,
            /* [in] */ unsigned long grfMode,
            /* [out] */ IPropertyStorage  * *ppprstg);
        
        HRESULT ( __stdcall  *Delete )( 
            IPropertySetStorage  * This,
            /* [in] */ REFFMTID rfmtid);
        
        HRESULT ( __stdcall  *Enum )( 
            IPropertySetStorage  * This,
            /* [out] */ IEnumSTATPROPSETSTG  * *ppenum);
        
        END_INTERFACE
    } IPropertySetStorageVtbl;

    interface IPropertySetStorage
    {
        CONST_VTBL struct IPropertySetStorageVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPropertySetStorage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPropertySetStorage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPropertySetStorage_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPropertySetStorage_Create(This,rfmtid,pclsid,grfFlags,grfMode,ppprstg)	\
    (This)->lpVtbl -> Create(This,rfmtid,pclsid,grfFlags,grfMode,ppprstg)

#define IPropertySetStorage_Open(This,rfmtid,grfMode,ppprstg)	\
    (This)->lpVtbl -> Open(This,rfmtid,grfMode,ppprstg)

#define IPropertySetStorage_Delete(This,rfmtid)	\
    (This)->lpVtbl -> Delete(This,rfmtid)

#define IPropertySetStorage_Enum(This,ppenum)	\
    (This)->lpVtbl -> Enum(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPropertySetStorage_Create_Proxy( 
    IPropertySetStorage  * This,
    /* [in] */ REFFMTID rfmtid,
    /* [unique][in] */ const CLSID  *pclsid,
    /* [in] */ unsigned long grfFlags,
    /* [in] */ unsigned long grfMode,
    /* [out] */ IPropertyStorage  * *ppprstg);


void __stdcall IPropertySetStorage_Create_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPropertySetStorage_Open_Proxy( 
    IPropertySetStorage  * This,
    /* [in] */ REFFMTID rfmtid,
    /* [in] */ unsigned long grfMode,
    /* [out] */ IPropertyStorage  * *ppprstg);


void __stdcall IPropertySetStorage_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPropertySetStorage_Delete_Proxy( 
    IPropertySetStorage  * This,
    /* [in] */ REFFMTID rfmtid);


void __stdcall IPropertySetStorage_Delete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPropertySetStorage_Enum_Proxy( 
    IPropertySetStorage  * This,
    /* [out] */ IEnumSTATPROPSETSTG  * *ppenum);


void __stdcall IPropertySetStorage_Enum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IPropertySetStorage_INTERFACE_DEFINED__ */


#ifndef __IEnumSTATPROPSTG_INTERFACE_DEFINED__
#define __IEnumSTATPROPSTG_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumSTATPROPSTG
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IEnumSTATPROPSTG  *LPENUMSTATPROPSTG;


EXTERN_C const IID IID_IEnumSTATPROPSTG;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IEnumSTATPROPSTG : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT __stdcall Next( 
            /* [in] */ unsigned long celt,
            /* [length_is][size_is][out] */ STATPROPSTG  *rgelt,
            /* [out] */ unsigned long  *pceltFetched) = 0;
        
        virtual HRESULT __stdcall Skip( 
            /* [in] */ unsigned long celt) = 0;
        
        virtual HRESULT __stdcall Reset( void) = 0;
        
        virtual HRESULT __stdcall Clone( 
            /* [out] */ IEnumSTATPROPSTG  * *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumSTATPROPSTGVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IEnumSTATPROPSTG  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IEnumSTATPROPSTG  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IEnumSTATPROPSTG  * This);
        
        /* [local] */ HRESULT ( __stdcall  *Next )( 
            IEnumSTATPROPSTG  * This,
            /* [in] */ unsigned long celt,
            /* [length_is][size_is][out] */ STATPROPSTG  *rgelt,
            /* [out] */ unsigned long  *pceltFetched);
        
        HRESULT ( __stdcall  *Skip )( 
            IEnumSTATPROPSTG  * This,
            /* [in] */ unsigned long celt);
        
        HRESULT ( __stdcall  *Reset )( 
            IEnumSTATPROPSTG  * This);
        
        HRESULT ( __stdcall  *Clone )( 
            IEnumSTATPROPSTG  * This,
            /* [out] */ IEnumSTATPROPSTG  * *ppenum);
        
        END_INTERFACE
    } IEnumSTATPROPSTGVtbl;

    interface IEnumSTATPROPSTG
    {
        CONST_VTBL struct IEnumSTATPROPSTGVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumSTATPROPSTG_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumSTATPROPSTG_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumSTATPROPSTG_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumSTATPROPSTG_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumSTATPROPSTG_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumSTATPROPSTG_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumSTATPROPSTG_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall IEnumSTATPROPSTG_RemoteNext_Proxy( 
    IEnumSTATPROPSTG  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ STATPROPSTG  *rgelt,
    /* [out] */ unsigned long  *pceltFetched);


void __stdcall IEnumSTATPROPSTG_RemoteNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumSTATPROPSTG_Skip_Proxy( 
    IEnumSTATPROPSTG  * This,
    /* [in] */ unsigned long celt);


void __stdcall IEnumSTATPROPSTG_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumSTATPROPSTG_Reset_Proxy( 
    IEnumSTATPROPSTG  * This);


void __stdcall IEnumSTATPROPSTG_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumSTATPROPSTG_Clone_Proxy( 
    IEnumSTATPROPSTG  * This,
    /* [out] */ IEnumSTATPROPSTG  * *ppenum);


void __stdcall IEnumSTATPROPSTG_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IEnumSTATPROPSTG_INTERFACE_DEFINED__ */


#ifndef __IEnumSTATPROPSETSTG_INTERFACE_DEFINED__
#define __IEnumSTATPROPSETSTG_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumSTATPROPSETSTG
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IEnumSTATPROPSETSTG  *LPENUMSTATPROPSETSTG;


EXTERN_C const IID IID_IEnumSTATPROPSETSTG;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IEnumSTATPROPSETSTG : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT __stdcall Next( 
            /* [in] */ unsigned long celt,
            /* [length_is][size_is][out] */ STATPROPSETSTG  *rgelt,
            /* [out] */ unsigned long  *pceltFetched) = 0;
        
        virtual HRESULT __stdcall Skip( 
            /* [in] */ unsigned long celt) = 0;
        
        virtual HRESULT __stdcall Reset( void) = 0;
        
        virtual HRESULT __stdcall Clone( 
            /* [out] */ IEnumSTATPROPSETSTG  * *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumSTATPROPSETSTGVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IEnumSTATPROPSETSTG  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IEnumSTATPROPSETSTG  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IEnumSTATPROPSETSTG  * This);
        
        /* [local] */ HRESULT ( __stdcall  *Next )( 
            IEnumSTATPROPSETSTG  * This,
            /* [in] */ unsigned long celt,
            /* [length_is][size_is][out] */ STATPROPSETSTG  *rgelt,
            /* [out] */ unsigned long  *pceltFetched);
        
        HRESULT ( __stdcall  *Skip )( 
            IEnumSTATPROPSETSTG  * This,
            /* [in] */ unsigned long celt);
        
        HRESULT ( __stdcall  *Reset )( 
            IEnumSTATPROPSETSTG  * This);
        
        HRESULT ( __stdcall  *Clone )( 
            IEnumSTATPROPSETSTG  * This,
            /* [out] */ IEnumSTATPROPSETSTG  * *ppenum);
        
        END_INTERFACE
    } IEnumSTATPROPSETSTGVtbl;

    interface IEnumSTATPROPSETSTG
    {
        CONST_VTBL struct IEnumSTATPROPSETSTGVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumSTATPROPSETSTG_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumSTATPROPSETSTG_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumSTATPROPSETSTG_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumSTATPROPSETSTG_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumSTATPROPSETSTG_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumSTATPROPSETSTG_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumSTATPROPSETSTG_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall IEnumSTATPROPSETSTG_RemoteNext_Proxy( 
    IEnumSTATPROPSETSTG  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ STATPROPSETSTG  *rgelt,
    /* [out] */ unsigned long  *pceltFetched);


void __stdcall IEnumSTATPROPSETSTG_RemoteNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumSTATPROPSETSTG_Skip_Proxy( 
    IEnumSTATPROPSETSTG  * This,
    /* [in] */ unsigned long celt);


void __stdcall IEnumSTATPROPSETSTG_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumSTATPROPSETSTG_Reset_Proxy( 
    IEnumSTATPROPSETSTG  * This);


void __stdcall IEnumSTATPROPSETSTG_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumSTATPROPSETSTG_Clone_Proxy( 
    IEnumSTATPROPSETSTG  * This,
    /* [out] */ IEnumSTATPROPSETSTG  * *ppenum);


void __stdcall IEnumSTATPROPSETSTG_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IEnumSTATPROPSETSTG_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0046
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


WINOLEAPI PropVariantCopy ( PROPVARIANT * pvarDest, const PROPVARIANT * pvarSrc );
WINOLEAPI PropVariantClear ( PROPVARIANT * pvar );
#   ifdef __cplusplus
inline void PropVariantInit ( PROPVARIANT * pvar )
{
    memset ( pvar, 0, sizeof(PROPVARIANT) );
}
#   else
#   define PropVariantInit(pvar) memset ( pvar, 0, sizeof(PROPVARIANT) )
#   endif
WINOLEAPI FreePropVariantArray ( unsigned long cVariants, PROPVARIANT * rgvars );
#if  (_WIN32_WINNT >= 0x0400 ) || defined(_WIN32_DCOM) // DCOM
// This interface is only valid on Windows NT 4.0


extern RPC_IF_HANDLE __MIDL__intf_0046_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0046_v0_0_s_ifspec;

#ifndef __IClientSecurity_INTERFACE_DEFINED__
#define __IClientSecurity_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IClientSecurity
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [uuid][object][local] */ 


typedef struct  tagSOLE_AUTHENTICATION_SERVICE
    {
    unsigned long dwAuthnSvc;
    unsigned long dwAuthzSvc;
    OLECHAR  *pPrincipalName;
    HRESULT hr;
    }	SOLE_AUTHENTICATION_SERVICE;

typedef SOLE_AUTHENTICATION_SERVICE  *PSOLE_AUTHENTICATION_SERVICE;

typedef 
enum tagEOLE_AUTHENTICATION_CAPABILITIES
    {	EOAC_NONE	= 0,
	EOAC_MUTUAL_AUTH	= 0x1,
	EOAC_SECURE_REFS	= 0x2,
	EOAC_ACCESS_CONTROL	= 0x4
    }	EOLE_AUTHENTICATION_CAPABILITIES;


EXTERN_C const IID IID_IClientSecurity;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IClientSecurity : public IUnknown
    {
    public:
        virtual HRESULT __stdcall QueryBlanket( 
            /* [in] */ IUnknown  *pProxy,
            /* [out] */ unsigned long  *pAuthnSvc,
            /* [out] */ unsigned long  *pAuthzSvc,
            /* [out] */ OLECHAR  * *pServerPrincName,
            /* [out] */ unsigned long  *pAuthnLevel,
            /* [out] */ unsigned long  *pImpLevel,
            /* [out] */ void  * *pAuthInfo,
            /* [out] */ unsigned long  *pCapabilites) = 0;
        
        virtual HRESULT __stdcall SetBlanket( 
            /* [in] */ IUnknown  *pProxy,
            /* [in] */ unsigned long AuthnSvc,
            /* [in] */ unsigned long AuthzSvc,
            /* [in] */ OLECHAR  *pServerPrincName,
            /* [in] */ unsigned long AuthnLevel,
            /* [in] */ unsigned long ImpLevel,
            /* [in] */ void  *pAuthInfo,
            /* [in] */ unsigned long Capabilities) = 0;
        
        virtual HRESULT __stdcall CopyProxy( 
            /* [in] */ IUnknown  *pProxy,
            /* [out] */ IUnknown  * *ppCopy) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClientSecurityVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IClientSecurity  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IClientSecurity  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IClientSecurity  * This);
        
        HRESULT ( __stdcall  *QueryBlanket )( 
            IClientSecurity  * This,
            /* [in] */ IUnknown  *pProxy,
            /* [out] */ unsigned long  *pAuthnSvc,
            /* [out] */ unsigned long  *pAuthzSvc,
            /* [out] */ OLECHAR  * *pServerPrincName,
            /* [out] */ unsigned long  *pAuthnLevel,
            /* [out] */ unsigned long  *pImpLevel,
            /* [out] */ void  * *pAuthInfo,
            /* [out] */ unsigned long  *pCapabilites);
        
        HRESULT ( __stdcall  *SetBlanket )( 
            IClientSecurity  * This,
            /* [in] */ IUnknown  *pProxy,
            /* [in] */ unsigned long AuthnSvc,
            /* [in] */ unsigned long AuthzSvc,
            /* [in] */ OLECHAR  *pServerPrincName,
            /* [in] */ unsigned long AuthnLevel,
            /* [in] */ unsigned long ImpLevel,
            /* [in] */ void  *pAuthInfo,
            /* [in] */ unsigned long Capabilities);
        
        HRESULT ( __stdcall  *CopyProxy )( 
            IClientSecurity  * This,
            /* [in] */ IUnknown  *pProxy,
            /* [out] */ IUnknown  * *ppCopy);
        
        END_INTERFACE
    } IClientSecurityVtbl;

    interface IClientSecurity
    {
        CONST_VTBL struct IClientSecurityVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClientSecurity_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClientSecurity_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClientSecurity_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClientSecurity_QueryBlanket(This,pProxy,pAuthnSvc,pAuthzSvc,pServerPrincName,pAuthnLevel,pImpLevel,pAuthInfo,pCapabilites)	\
    (This)->lpVtbl -> QueryBlanket(This,pProxy,pAuthnSvc,pAuthzSvc,pServerPrincName,pAuthnLevel,pImpLevel,pAuthInfo,pCapabilites)

#define IClientSecurity_SetBlanket(This,pProxy,AuthnSvc,AuthzSvc,pServerPrincName,AuthnLevel,ImpLevel,pAuthInfo,Capabilities)	\
    (This)->lpVtbl -> SetBlanket(This,pProxy,AuthnSvc,AuthzSvc,pServerPrincName,AuthnLevel,ImpLevel,pAuthInfo,Capabilities)

#define IClientSecurity_CopyProxy(This,pProxy,ppCopy)	\
    (This)->lpVtbl -> CopyProxy(This,pProxy,ppCopy)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IClientSecurity_QueryBlanket_Proxy( 
    IClientSecurity  * This,
    /* [in] */ IUnknown  *pProxy,
    /* [out] */ unsigned long  *pAuthnSvc,
    /* [out] */ unsigned long  *pAuthzSvc,
    /* [out] */ OLECHAR  * *pServerPrincName,
    /* [out] */ unsigned long  *pAuthnLevel,
    /* [out] */ unsigned long  *pImpLevel,
    /* [out] */ void  * *pAuthInfo,
    /* [out] */ unsigned long  *pCapabilites);


void __stdcall IClientSecurity_QueryBlanket_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IClientSecurity_SetBlanket_Proxy( 
    IClientSecurity  * This,
    /* [in] */ IUnknown  *pProxy,
    /* [in] */ unsigned long AuthnSvc,
    /* [in] */ unsigned long AuthzSvc,
    /* [in] */ OLECHAR  *pServerPrincName,
    /* [in] */ unsigned long AuthnLevel,
    /* [in] */ unsigned long ImpLevel,
    /* [in] */ void  *pAuthInfo,
    /* [in] */ unsigned long Capabilities);


void __stdcall IClientSecurity_SetBlanket_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IClientSecurity_CopyProxy_Proxy( 
    IClientSecurity  * This,
    /* [in] */ IUnknown  *pProxy,
    /* [out] */ IUnknown  * *ppCopy);


void __stdcall IClientSecurity_CopyProxy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IClientSecurity_INTERFACE_DEFINED__ */


#ifndef __IServerSecurity_INTERFACE_DEFINED__
#define __IServerSecurity_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IServerSecurity
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [uuid][object][local] */ 



EXTERN_C const IID IID_IServerSecurity;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IServerSecurity : public IUnknown
    {
    public:
        virtual HRESULT __stdcall QueryBlanket( 
            /* [out] */ unsigned long  *pAuthnSvc,
            /* [out] */ unsigned long  *pAuthzSvc,
            /* [out] */ OLECHAR  * *pServerPrincName,
            /* [out] */ unsigned long  *pAuthnLevel,
            /* [out] */ unsigned long  *pImpLevel,
            /* [out] */ void  * *pPrivs,
            /* [out] */ unsigned long  *pCapabilities) = 0;
        
        virtual HRESULT __stdcall ImpersonateClient( void) = 0;
        
        virtual HRESULT __stdcall RevertToSelf( void) = 0;
        
        virtual BOOL __stdcall IsImpersonating( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IServerSecurityVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IServerSecurity  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IServerSecurity  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IServerSecurity  * This);
        
        HRESULT ( __stdcall  *QueryBlanket )( 
            IServerSecurity  * This,
            /* [out] */ unsigned long  *pAuthnSvc,
            /* [out] */ unsigned long  *pAuthzSvc,
            /* [out] */ OLECHAR  * *pServerPrincName,
            /* [out] */ unsigned long  *pAuthnLevel,
            /* [out] */ unsigned long  *pImpLevel,
            /* [out] */ void  * *pPrivs,
            /* [out] */ unsigned long  *pCapabilities);
        
        HRESULT ( __stdcall  *ImpersonateClient )( 
            IServerSecurity  * This);
        
        HRESULT ( __stdcall  *RevertToSelf )( 
            IServerSecurity  * This);
        
        BOOL ( __stdcall  *IsImpersonating )( 
            IServerSecurity  * This);
        
        END_INTERFACE
    } IServerSecurityVtbl;

    interface IServerSecurity
    {
        CONST_VTBL struct IServerSecurityVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IServerSecurity_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IServerSecurity_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IServerSecurity_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IServerSecurity_QueryBlanket(This,pAuthnSvc,pAuthzSvc,pServerPrincName,pAuthnLevel,pImpLevel,pPrivs,pCapabilities)	\
    (This)->lpVtbl -> QueryBlanket(This,pAuthnSvc,pAuthzSvc,pServerPrincName,pAuthnLevel,pImpLevel,pPrivs,pCapabilities)

#define IServerSecurity_ImpersonateClient(This)	\
    (This)->lpVtbl -> ImpersonateClient(This)

#define IServerSecurity_RevertToSelf(This)	\
    (This)->lpVtbl -> RevertToSelf(This)

#define IServerSecurity_IsImpersonating(This)	\
    (This)->lpVtbl -> IsImpersonating(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IServerSecurity_QueryBlanket_Proxy( 
    IServerSecurity  * This,
    /* [out] */ unsigned long  *pAuthnSvc,
    /* [out] */ unsigned long  *pAuthzSvc,
    /* [out] */ OLECHAR  * *pServerPrincName,
    /* [out] */ unsigned long  *pAuthnLevel,
    /* [out] */ unsigned long  *pImpLevel,
    /* [out] */ void  * *pPrivs,
    /* [out] */ unsigned long  *pCapabilities);


void __stdcall IServerSecurity_QueryBlanket_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IServerSecurity_ImpersonateClient_Proxy( 
    IServerSecurity  * This);


void __stdcall IServerSecurity_ImpersonateClient_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IServerSecurity_RevertToSelf_Proxy( 
    IServerSecurity  * This);


void __stdcall IServerSecurity_RevertToSelf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


BOOL __stdcall IServerSecurity_IsImpersonating_Proxy( 
    IServerSecurity  * This);


void __stdcall IServerSecurity_IsImpersonating_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IServerSecurity_INTERFACE_DEFINED__ */


#ifndef __IClassActivator_INTERFACE_DEFINED__
#define __IClassActivator_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IClassActivator
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [uuid][object] */ 



EXTERN_C const IID IID_IClassActivator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IClassActivator : public IUnknown
    {
    public:
        virtual HRESULT __stdcall GetClassObject( 
            /* [in] */ REFCLSID rclsid,
            /* [in] */ unsigned long dwClassContext,
            /* [in] */ LCID locale,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppv) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClassActivatorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IClassActivator  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IClassActivator  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IClassActivator  * This);
        
        HRESULT ( __stdcall  *GetClassObject )( 
            IClassActivator  * This,
            /* [in] */ REFCLSID rclsid,
            /* [in] */ unsigned long dwClassContext,
            /* [in] */ LCID locale,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppv);
        
        END_INTERFACE
    } IClassActivatorVtbl;

    interface IClassActivator
    {
        CONST_VTBL struct IClassActivatorVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClassActivator_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClassActivator_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClassActivator_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClassActivator_GetClassObject(This,rclsid,dwClassContext,locale,riid,ppv)	\
    (This)->lpVtbl -> GetClassObject(This,rclsid,dwClassContext,locale,riid,ppv)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IClassActivator_GetClassObject_Proxy( 
    IClassActivator  * This,
    /* [in] */ REFCLSID rclsid,
    /* [in] */ unsigned long dwClassContext,
    /* [in] */ LCID locale,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void  * *ppv);


void __stdcall IClassActivator_GetClassObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IClassActivator_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0049
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif //DCOM


extern RPC_IF_HANDLE __MIDL__intf_0049_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0049_v0_0_s_ifspec;

#ifndef __IFillLockBytes_INTERFACE_DEFINED__
#define __IFillLockBytes_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IFillLockBytes
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 



EXTERN_C const IID IID_IFillLockBytes;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IFillLockBytes : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT __stdcall FillAppend( 
            /* [size_is][in] */ const void  *pv,
            /* [in] */ unsigned long cb,
            /* [out] */ unsigned long  *pcbWritten) = 0;
        
        virtual /* [local] */ HRESULT __stdcall FillAt( 
            /* [in] */ ULARGE_INTEGER ulOffset,
            /* [size_is][in] */ const void  *pv,
            /* [in] */ unsigned long cb,
            /* [out] */ unsigned long  *pcbWritten) = 0;
        
        virtual HRESULT __stdcall SetFillSize( 
            /* [in] */ ULARGE_INTEGER ulSize) = 0;
        
        virtual HRESULT __stdcall Terminate( 
            /* [in] */ BOOL bCanceled) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFillLockBytesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IFillLockBytes  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IFillLockBytes  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IFillLockBytes  * This);
        
        /* [local] */ HRESULT ( __stdcall  *FillAppend )( 
            IFillLockBytes  * This,
            /* [size_is][in] */ const void  *pv,
            /* [in] */ unsigned long cb,
            /* [out] */ unsigned long  *pcbWritten);
        
        /* [local] */ HRESULT ( __stdcall  *FillAt )( 
            IFillLockBytes  * This,
            /* [in] */ ULARGE_INTEGER ulOffset,
            /* [size_is][in] */ const void  *pv,
            /* [in] */ unsigned long cb,
            /* [out] */ unsigned long  *pcbWritten);
        
        HRESULT ( __stdcall  *SetFillSize )( 
            IFillLockBytes  * This,
            /* [in] */ ULARGE_INTEGER ulSize);
        
        HRESULT ( __stdcall  *Terminate )( 
            IFillLockBytes  * This,
            /* [in] */ BOOL bCanceled);
        
        END_INTERFACE
    } IFillLockBytesVtbl;

    interface IFillLockBytes
    {
        CONST_VTBL struct IFillLockBytesVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFillLockBytes_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFillLockBytes_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFillLockBytes_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFillLockBytes_FillAppend(This,pv,cb,pcbWritten)	\
    (This)->lpVtbl -> FillAppend(This,pv,cb,pcbWritten)

#define IFillLockBytes_FillAt(This,ulOffset,pv,cb,pcbWritten)	\
    (This)->lpVtbl -> FillAt(This,ulOffset,pv,cb,pcbWritten)

#define IFillLockBytes_SetFillSize(This,ulSize)	\
    (This)->lpVtbl -> SetFillSize(This,ulSize)

#define IFillLockBytes_Terminate(This,bCanceled)	\
    (This)->lpVtbl -> Terminate(This,bCanceled)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall IFillLockBytes_RemoteFillAppend_Proxy( 
    IFillLockBytes  * This,
    /* [size_is][in] */ const byte  *pv,
    /* [in] */ unsigned long cb,
    /* [out] */ unsigned long  *pcbWritten);


void __stdcall IFillLockBytes_RemoteFillAppend_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall IFillLockBytes_RemoteFillAt_Proxy( 
    IFillLockBytes  * This,
    /* [in] */ ULARGE_INTEGER ulOffset,
    /* [size_is][in] */ const byte  *pv,
    /* [in] */ unsigned long cb,
    /* [out] */ unsigned long  *pcbWritten);


void __stdcall IFillLockBytes_RemoteFillAt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IFillLockBytes_SetFillSize_Proxy( 
    IFillLockBytes  * This,
    /* [in] */ ULARGE_INTEGER ulSize);


void __stdcall IFillLockBytes_SetFillSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IFillLockBytes_Terminate_Proxy( 
    IFillLockBytes  * This,
    /* [in] */ BOOL bCanceled);


void __stdcall IFillLockBytes_Terminate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IFillLockBytes_INTERFACE_DEFINED__ */


#ifndef __IProgressNotify_INTERFACE_DEFINED__
#define __IProgressNotify_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IProgressNotify
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 



EXTERN_C const IID IID_IProgressNotify;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IProgressNotify : public IUnknown
    {
    public:
        virtual HRESULT __stdcall OnProgress( 
            /* [in] */ unsigned long dwProgressCurrent,
            /* [in] */ unsigned long dwProgressMaximum,
            /* [in] */ BOOL fAccurate,
            /* [in] */ BOOL fOwner) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IProgressNotifyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IProgressNotify  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IProgressNotify  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IProgressNotify  * This);
        
        HRESULT ( __stdcall  *OnProgress )( 
            IProgressNotify  * This,
            /* [in] */ unsigned long dwProgressCurrent,
            /* [in] */ unsigned long dwProgressMaximum,
            /* [in] */ BOOL fAccurate,
            /* [in] */ BOOL fOwner);
        
        END_INTERFACE
    } IProgressNotifyVtbl;

    interface IProgressNotify
    {
        CONST_VTBL struct IProgressNotifyVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IProgressNotify_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IProgressNotify_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IProgressNotify_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IProgressNotify_OnProgress(This,dwProgressCurrent,dwProgressMaximum,fAccurate,fOwner)	\
    (This)->lpVtbl -> OnProgress(This,dwProgressCurrent,dwProgressMaximum,fAccurate,fOwner)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IProgressNotify_OnProgress_Proxy( 
    IProgressNotify  * This,
    /* [in] */ unsigned long dwProgressCurrent,
    /* [in] */ unsigned long dwProgressMaximum,
    /* [in] */ BOOL fAccurate,
    /* [in] */ BOOL fOwner);


void __stdcall IProgressNotify_OnProgress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IProgressNotify_INTERFACE_DEFINED__ */


#ifndef __ILayoutStorage_INTERFACE_DEFINED__
#define __ILayoutStorage_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ILayoutStorage
 * at Fri Jul 12 18:09:27 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef struct  tagStorageLayout
    {
    unsigned long LayoutType;
    OLECHAR  *pwcsElementName;
    LARGE_INTEGER cOffset;
    LARGE_INTEGER cBytes;
    }	StorageLayout;


EXTERN_C const IID IID_ILayoutStorage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ILayoutStorage : public IUnknown
    {
    public:
        virtual HRESULT __stdcall LayoutScript( 
            /* [in] */ StorageLayout  *pStorageLayout,
            /* [in] */ unsigned long nEntries,
            /* [in] */ unsigned long glfInterleavedFlag) = 0;
        
        virtual HRESULT __stdcall BeginMonitor( void) = 0;
        
        virtual HRESULT __stdcall EndMonitor( void) = 0;
        
        virtual HRESULT __stdcall ReLayoutDocfile( 
            /* [in] */ OLECHAR  *pwcsNewDfName) = 0;
        
        virtual HRESULT __stdcall ReLayoutDocfileOnILockBytes( 
            /* [in] */ ILockBytes  *pILockBytes) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILayoutStorageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            ILayoutStorage  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            ILayoutStorage  * This);
        
        unsigned long ( __stdcall  *Release )( 
            ILayoutStorage  * This);
        
        HRESULT ( __stdcall  *LayoutScript )( 
            ILayoutStorage  * This,
            /* [in] */ StorageLayout  *pStorageLayout,
            /* [in] */ unsigned long nEntries,
            /* [in] */ unsigned long glfInterleavedFlag);
        
        HRESULT ( __stdcall  *BeginMonitor )( 
            ILayoutStorage  * This);
        
        HRESULT ( __stdcall  *EndMonitor )( 
            ILayoutStorage  * This);
        
        HRESULT ( __stdcall  *ReLayoutDocfile )( 
            ILayoutStorage  * This,
            /* [in] */ OLECHAR  *pwcsNewDfName);
        
        HRESULT ( __stdcall  *ReLayoutDocfileOnILockBytes )( 
            ILayoutStorage  * This,
            /* [in] */ ILockBytes  *pILockBytes);
        
        END_INTERFACE
    } ILayoutStorageVtbl;

    interface ILayoutStorage
    {
        CONST_VTBL struct ILayoutStorageVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILayoutStorage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ILayoutStorage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ILayoutStorage_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ILayoutStorage_LayoutScript(This,pStorageLayout,nEntries,glfInterleavedFlag)	\
    (This)->lpVtbl -> LayoutScript(This,pStorageLayout,nEntries,glfInterleavedFlag)

#define ILayoutStorage_BeginMonitor(This)	\
    (This)->lpVtbl -> BeginMonitor(This)

#define ILayoutStorage_EndMonitor(This)	\
    (This)->lpVtbl -> EndMonitor(This)

#define ILayoutStorage_ReLayoutDocfile(This,pwcsNewDfName)	\
    (This)->lpVtbl -> ReLayoutDocfile(This,pwcsNewDfName)

#define ILayoutStorage_ReLayoutDocfileOnILockBytes(This,pILockBytes)	\
    (This)->lpVtbl -> ReLayoutDocfileOnILockBytes(This,pILockBytes)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall ILayoutStorage_LayoutScript_Proxy( 
    ILayoutStorage  * This,
    /* [in] */ StorageLayout  *pStorageLayout,
    /* [in] */ unsigned long nEntries,
    /* [in] */ unsigned long glfInterleavedFlag);


void __stdcall ILayoutStorage_LayoutScript_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ILayoutStorage_BeginMonitor_Proxy( 
    ILayoutStorage  * This);


void __stdcall ILayoutStorage_BeginMonitor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ILayoutStorage_EndMonitor_Proxy( 
    ILayoutStorage  * This);


void __stdcall ILayoutStorage_EndMonitor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ILayoutStorage_ReLayoutDocfile_Proxy( 
    ILayoutStorage  * This,
    /* [in] */ OLECHAR  *pwcsNewDfName);


void __stdcall ILayoutStorage_ReLayoutDocfile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ILayoutStorage_ReLayoutDocfileOnILockBytes_Proxy( 
    ILayoutStorage  * This,
    /* [in] */ ILockBytes  *pILockBytes);


void __stdcall ILayoutStorage_ReLayoutDocfileOnILockBytes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __ILayoutStorage_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __stdcall  ASYNC_STGMEDIUM_UserSize(     unsigned long  *, unsigned long            , ASYNC_STGMEDIUM  * ); 
unsigned char  * __stdcall  ASYNC_STGMEDIUM_UserMarshal(  unsigned long  *, unsigned char  *, ASYNC_STGMEDIUM  * ); 
unsigned char  * __stdcall  ASYNC_STGMEDIUM_UserUnmarshal(unsigned long  *, unsigned char  *, ASYNC_STGMEDIUM  * ); 
void                      __stdcall  ASYNC_STGMEDIUM_UserFree(     unsigned long  *, ASYNC_STGMEDIUM  * ); 

unsigned long             __stdcall  BSTR_UserSize(     unsigned long  *, unsigned long            , BSTR  * ); 
unsigned char  * __stdcall  BSTR_UserMarshal(  unsigned long  *, unsigned char  *, BSTR  * ); 
unsigned char  * __stdcall  BSTR_UserUnmarshal(unsigned long  *, unsigned char  *, BSTR  * ); 
void                      __stdcall  BSTR_UserFree(     unsigned long  *, BSTR  * ); 

unsigned long             __stdcall  CLIPFORMAT_UserSize(     unsigned long  *, unsigned long            , CLIPFORMAT  * ); 
unsigned char  * __stdcall  CLIPFORMAT_UserMarshal(  unsigned long  *, unsigned char  *, CLIPFORMAT  * ); 
unsigned char  * __stdcall  CLIPFORMAT_UserUnmarshal(unsigned long  *, unsigned char  *, CLIPFORMAT  * ); 
void                      __stdcall  CLIPFORMAT_UserFree(     unsigned long  *, CLIPFORMAT  * ); 

unsigned long             __stdcall  FLAG_STGMEDIUM_UserSize(     unsigned long  *, unsigned long            , FLAG_STGMEDIUM  * ); 
unsigned char  * __stdcall  FLAG_STGMEDIUM_UserMarshal(  unsigned long  *, unsigned char  *, FLAG_STGMEDIUM  * ); 
unsigned char  * __stdcall  FLAG_STGMEDIUM_UserUnmarshal(unsigned long  *, unsigned char  *, FLAG_STGMEDIUM  * ); 
void                      __stdcall  FLAG_STGMEDIUM_UserFree(     unsigned long  *, FLAG_STGMEDIUM  * ); 

unsigned long             __stdcall  SNB_UserSize(     unsigned long  *, unsigned long            , SNB  * ); 
unsigned char  * __stdcall  SNB_UserMarshal(  unsigned long  *, unsigned char  *, SNB  * ); 
unsigned char  * __stdcall  SNB_UserUnmarshal(unsigned long  *, unsigned char  *, SNB  * ); 
void                      __stdcall  SNB_UserFree(     unsigned long  *, SNB  * ); 

unsigned long             __stdcall  STGMEDIUM_UserSize(     unsigned long  *, unsigned long            , STGMEDIUM  * ); 
unsigned char  * __stdcall  STGMEDIUM_UserMarshal(  unsigned long  *, unsigned char  *, STGMEDIUM  * ); 
unsigned char  * __stdcall  STGMEDIUM_UserUnmarshal(unsigned long  *, unsigned char  *, STGMEDIUM  * ); 
void                      __stdcall  STGMEDIUM_UserFree(     unsigned long  *, STGMEDIUM  * ); 

/* [local] */ HRESULT __stdcall IEnumUnknown_Next_Proxy( 
    IEnumUnknown  * This,
    /* [in] */ unsigned long celt,
    /* [out] */ IUnknown  * *rgelt,
    /* [out] */ unsigned long  *pceltFetched);


/* [call_as] */ HRESULT __stdcall IEnumUnknown_Next_Stub( 
    IEnumUnknown  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ IUnknown  * *rgelt,
    /* [out] */ unsigned long  *pceltFetched);

/* [local] */ HRESULT __stdcall IBindCtx_SetBindOptions_Proxy( 
    IBindCtx  * This,
    /* [in] */ BIND_OPTS  *pbindopts);


/* [call_as] */ HRESULT __stdcall IBindCtx_SetBindOptions_Stub( 
    IBindCtx  * This,
    /* [in] */ BIND_OPTS2  *pbindopts);

/* [local] */ HRESULT __stdcall IBindCtx_GetBindOptions_Proxy( 
    IBindCtx  * This,
    /* [out][in] */ BIND_OPTS  *pbindopts);


/* [call_as] */ HRESULT __stdcall IBindCtx_GetBindOptions_Stub( 
    IBindCtx  * This,
    /* [out][in] */ BIND_OPTS2  *pbindopts);

/* [local] */ HRESULT __stdcall IEnumMoniker_Next_Proxy( 
    IEnumMoniker  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ IMoniker  * *rgelt,
    /* [out] */ unsigned long  *pceltFetched);


/* [call_as] */ HRESULT __stdcall IEnumMoniker_Next_Stub( 
    IEnumMoniker  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ IMoniker  * *rgelt,
    /* [out] */ unsigned long  *pceltFetched);

/* [local] */ BOOL __stdcall IRunnableObject_IsRunning_Proxy( 
    IRunnableObject  * This);


/* [call_as] */ HRESULT __stdcall IRunnableObject_IsRunning_Stub( 
    IRunnableObject  * This);

/* [local] */ HRESULT __stdcall IMoniker_BindToObject_Proxy( 
    IMoniker  * This,
    /* [unique][in] */ IBindCtx  *pbc,
    /* [unique][in] */ IMoniker  *pmkToLeft,
    /* [in] */ REFIID riidResult,
    /* [iid_is][out] */ void  * *ppvResult);


/* [call_as] */ HRESULT __stdcall IMoniker_BindToObject_Stub( 
    IMoniker  * This,
    /* [unique][in] */ IBindCtx  *pbc,
    /* [unique][in] */ IMoniker  *pmkToLeft,
    /* [in] */ REFIID riidResult,
    /* [iid_is][out] */ IUnknown  * *ppvResult);

/* [local] */ HRESULT __stdcall IMoniker_BindToStorage_Proxy( 
    IMoniker  * This,
    /* [unique][in] */ IBindCtx  *pbc,
    /* [unique][in] */ IMoniker  *pmkToLeft,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void  * *ppvObj);


/* [call_as] */ HRESULT __stdcall IMoniker_BindToStorage_Stub( 
    IMoniker  * This,
    /* [unique][in] */ IBindCtx  *pbc,
    /* [unique][in] */ IMoniker  *pmkToLeft,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown  * *ppvObj);

/* [local] */ HRESULT __stdcall IEnumString_Next_Proxy( 
    IEnumString  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ LPOLESTR  *rgelt,
    /* [out] */ unsigned long  *pceltFetched);


/* [call_as] */ HRESULT __stdcall IEnumString_Next_Stub( 
    IEnumString  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ LPOLESTR  *rgelt,
    /* [out] */ unsigned long  *pceltFetched);

/* [local] */ HRESULT __stdcall ISequentialStream_Read_Proxy( 
    ISequentialStream  * This,
    /* [length_is][size_is][out] */ void  *pv,
    /* [in] */ unsigned long cb,
    /* [out] */ unsigned long  *pcbRead);


/* [call_as] */ HRESULT __stdcall ISequentialStream_Read_Stub( 
    ISequentialStream  * This,
    /* [length_is][size_is][out] */ byte  *pv,
    /* [in] */ unsigned long cb,
    /* [out] */ unsigned long  *pcbRead);

/* [local] */ HRESULT __stdcall ISequentialStream_Write_Proxy( 
    ISequentialStream  * This,
    /* [size_is][in] */ const void  *pv,
    /* [in] */ unsigned long cb,
    /* [out] */ unsigned long  *pcbWritten);


/* [call_as] */ HRESULT __stdcall ISequentialStream_Write_Stub( 
    ISequentialStream  * This,
    /* [size_is][in] */ const byte  *pv,
    /* [in] */ unsigned long cb,
    /* [out] */ unsigned long  *pcbWritten);

/* [local] */ HRESULT __stdcall IStream_Seek_Proxy( 
    IStream  * This,
    /* [in] */ LARGE_INTEGER dlibMove,
    /* [in] */ unsigned long dwOrigin,
    /* [out] */ ULARGE_INTEGER  *plibNewPosition);


/* [call_as] */ HRESULT __stdcall IStream_Seek_Stub( 
    IStream  * This,
    /* [in] */ LARGE_INTEGER dlibMove,
    /* [in] */ unsigned long dwOrigin,
    /* [out] */ ULARGE_INTEGER  *plibNewPosition);

/* [local] */ HRESULT __stdcall IStream_CopyTo_Proxy( 
    IStream  * This,
    /* [unique][in] */ IStream  *pstm,
    /* [in] */ ULARGE_INTEGER cb,
    /* [out] */ ULARGE_INTEGER  *pcbRead,
    /* [out] */ ULARGE_INTEGER  *pcbWritten);


/* [call_as] */ HRESULT __stdcall IStream_CopyTo_Stub( 
    IStream  * This,
    /* [unique][in] */ IStream  *pstm,
    /* [in] */ ULARGE_INTEGER cb,
    /* [out] */ ULARGE_INTEGER  *pcbRead,
    /* [out] */ ULARGE_INTEGER  *pcbWritten);

/* [local] */ HRESULT __stdcall IEnumSTATSTG_Next_Proxy( 
    IEnumSTATSTG  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ STATSTG  *rgelt,
    /* [out] */ unsigned long  *pceltFetched);


/* [call_as] */ HRESULT __stdcall IEnumSTATSTG_Next_Stub( 
    IEnumSTATSTG  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ STATSTG  *rgelt,
    /* [out] */ unsigned long  *pceltFetched);

/* [local] */ HRESULT __stdcall IStorage_OpenStream_Proxy( 
    IStorage  * This,
    /* [string][in] */ const OLECHAR  *pwcsName,
    /* [unique][in] */ void  *reserved1,
    /* [in] */ unsigned long grfMode,
    /* [in] */ unsigned long reserved2,
    /* [out] */ IStream  * *ppstm);


/* [call_as] */ HRESULT __stdcall IStorage_OpenStream_Stub( 
    IStorage  * This,
    /* [string][in] */ const OLECHAR  *pwcsName,
    /* [in] */ unsigned long cbReserved1,
    /* [size_is][unique][in] */ byte  *reserved1,
    /* [in] */ unsigned long grfMode,
    /* [in] */ unsigned long reserved2,
    /* [out] */ IStream  * *ppstm);

/* [local] */ HRESULT __stdcall IStorage_EnumElements_Proxy( 
    IStorage  * This,
    /* [in] */ unsigned long reserved1,
    /* [size_is][unique][in] */ void  *reserved2,
    /* [in] */ unsigned long reserved3,
    /* [out] */ IEnumSTATSTG  * *ppenum);


/* [call_as] */ HRESULT __stdcall IStorage_EnumElements_Stub( 
    IStorage  * This,
    /* [in] */ unsigned long reserved1,
    /* [in] */ unsigned long cbReserved2,
    /* [size_is][unique][in] */ byte  *reserved2,
    /* [in] */ unsigned long reserved3,
    /* [out] */ IEnumSTATSTG  * *ppenum);

/* [local] */ HRESULT __stdcall ILockBytes_ReadAt_Proxy( 
    ILockBytes  * This,
    /* [in] */ ULARGE_INTEGER ulOffset,
    /* [length_is][size_is][out] */ void  *pv,
    /* [in] */ unsigned long cb,
    /* [out] */ unsigned long  *pcbRead);


/* [call_as] */ HRESULT __stdcall ILockBytes_ReadAt_Stub( 
    ILockBytes  * This,
    /* [in] */ ULARGE_INTEGER ulOffset,
    /* [length_is][size_is][out] */ byte  *pv,
    /* [in] */ unsigned long cb,
    /* [out] */ unsigned long  *pcbRead);

/* [local] */ HRESULT __stdcall ILockBytes_WriteAt_Proxy( 
    ILockBytes  * This,
    /* [in] */ ULARGE_INTEGER ulOffset,
    /* [size_is][in] */ const void  *pv,
    /* [in] */ unsigned long cb,
    /* [out] */ unsigned long  *pcbWritten);


/* [call_as] */ HRESULT __stdcall ILockBytes_WriteAt_Stub( 
    ILockBytes  * This,
    /* [in] */ ULARGE_INTEGER ulOffset,
    /* [size_is][in] */ const byte  *pv,
    /* [in] */ unsigned long cb,
    /* [out] */ unsigned long  *pcbWritten);

/* [local] */ HRESULT __stdcall IEnumFORMATETC_Next_Proxy( 
    IEnumFORMATETC  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ FORMATETC  *rgelt,
    /* [out] */ unsigned long  *pceltFetched);


/* [call_as] */ HRESULT __stdcall IEnumFORMATETC_Next_Stub( 
    IEnumFORMATETC  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ FORMATETC  *rgelt,
    /* [out] */ unsigned long  *pceltFetched);

/* [local] */ HRESULT __stdcall IEnumSTATDATA_Next_Proxy( 
    IEnumSTATDATA  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ STATDATA  *rgelt,
    /* [out] */ unsigned long  *pceltFetched);


/* [call_as] */ HRESULT __stdcall IEnumSTATDATA_Next_Stub( 
    IEnumSTATDATA  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ STATDATA  *rgelt,
    /* [out] */ unsigned long  *pceltFetched);

/* [local] */ void __stdcall IAdviseSink_OnDataChange_Proxy( 
    IAdviseSink  * This,
    /* [unique][in] */ FORMATETC  *pFormatetc,
    /* [unique][in] */ STGMEDIUM  *pStgmed);


/* [async][call_as] */ void __stdcall IAdviseSink_OnDataChange_Stub( 
    IAdviseSink  * This,
    /* [unique][in] */ FORMATETC  *pFormatetc,
    /* [unique][in] */ ASYNC_STGMEDIUM  *pStgmed);

/* [local] */ void __stdcall IAdviseSink_OnViewChange_Proxy( 
    IAdviseSink  * This,
    /* [in] */ unsigned long dwAspect,
    /* [in] */ LONG lindex);


/* [async][call_as] */ void __stdcall IAdviseSink_OnViewChange_Stub( 
    IAdviseSink  * This,
    /* [in] */ unsigned long dwAspect,
    /* [in] */ LONG lindex);

/* [local] */ void __stdcall IAdviseSink_OnRename_Proxy( 
    IAdviseSink  * This,
    /* [in] */ IMoniker  *pmk);


/* [async][call_as] */ void __stdcall IAdviseSink_OnRename_Stub( 
    IAdviseSink  * This,
    /* [in] */ IMoniker  *pmk);

/* [local] */ void __stdcall IAdviseSink_OnSave_Proxy( 
    IAdviseSink  * This);


/* [async][call_as] */ void __stdcall IAdviseSink_OnSave_Stub( 
    IAdviseSink  * This);

/* [local] */ void __stdcall IAdviseSink_OnClose_Proxy( 
    IAdviseSink  * This);


/* [call_as] */ HRESULT __stdcall IAdviseSink_OnClose_Stub( 
    IAdviseSink  * This);

/* [local] */ void __stdcall IAdviseSink2_OnLinkSrcChange_Proxy( 
    IAdviseSink2  * This,
    /* [unique][in] */ IMoniker  *pmk);


/* [async][call_as] */ void __stdcall IAdviseSink2_OnLinkSrcChange_Stub( 
    IAdviseSink2  * This,
    /* [unique][in] */ IMoniker  *pmk);

/* [local] */ HRESULT __stdcall IDataObject_GetData_Proxy( 
    IDataObject  * This,
    /* [unique][in] */ FORMATETC  *pformatetcIn,
    /* [out] */ STGMEDIUM  *pmedium);


/* [call_as] */ HRESULT __stdcall IDataObject_GetData_Stub( 
    IDataObject  * This,
    /* [unique][in] */ FORMATETC  *pformatetcIn,
    /* [out] */ STGMEDIUM  *pRemoteMedium);

/* [local] */ HRESULT __stdcall IDataObject_GetDataHere_Proxy( 
    IDataObject  * This,
    /* [unique][in] */ FORMATETC  *pformatetc,
    /* [out][in] */ STGMEDIUM  *pmedium);


/* [call_as] */ HRESULT __stdcall IDataObject_GetDataHere_Stub( 
    IDataObject  * This,
    /* [unique][in] */ FORMATETC  *pformatetc,
    /* [out][in] */ STGMEDIUM  *pRemoteMedium);

/* [local] */ HRESULT __stdcall IDataObject_SetData_Proxy( 
    IDataObject  * This,
    /* [unique][in] */ FORMATETC  *pformatetc,
    /* [unique][in] */ STGMEDIUM  *pmedium,
    /* [in] */ BOOL fRelease);


/* [call_as] */ HRESULT __stdcall IDataObject_SetData_Stub( 
    IDataObject  * This,
    /* [unique][in] */ FORMATETC  *pformatetc,
    /* [unique][in] */ FLAG_STGMEDIUM  *pmedium,
    /* [in] */ BOOL fRelease);

/* [local] */ HRESULT __stdcall IEnumSTATPROPSTG_Next_Proxy( 
    IEnumSTATPROPSTG  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ STATPROPSTG  *rgelt,
    /* [out] */ unsigned long  *pceltFetched);


/* [call_as] */ HRESULT __stdcall IEnumSTATPROPSTG_Next_Stub( 
    IEnumSTATPROPSTG  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ STATPROPSTG  *rgelt,
    /* [out] */ unsigned long  *pceltFetched);

/* [local] */ HRESULT __stdcall IEnumSTATPROPSETSTG_Next_Proxy( 
    IEnumSTATPROPSETSTG  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ STATPROPSETSTG  *rgelt,
    /* [out] */ unsigned long  *pceltFetched);


/* [call_as] */ HRESULT __stdcall IEnumSTATPROPSETSTG_Next_Stub( 
    IEnumSTATPROPSETSTG  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ STATPROPSETSTG  *rgelt,
    /* [out] */ unsigned long  *pceltFetched);

/* [local] */ HRESULT __stdcall IFillLockBytes_FillAppend_Proxy( 
    IFillLockBytes  * This,
    /* [size_is][in] */ const void  *pv,
    /* [in] */ unsigned long cb,
    /* [out] */ unsigned long  *pcbWritten);


/* [call_as] */ HRESULT __stdcall IFillLockBytes_FillAppend_Stub( 
    IFillLockBytes  * This,
    /* [size_is][in] */ const byte  *pv,
    /* [in] */ unsigned long cb,
    /* [out] */ unsigned long  *pcbWritten);

/* [local] */ HRESULT __stdcall IFillLockBytes_FillAt_Proxy( 
    IFillLockBytes  * This,
    /* [in] */ ULARGE_INTEGER ulOffset,
    /* [size_is][in] */ const void  *pv,
    /* [in] */ unsigned long cb,
    /* [out] */ unsigned long  *pcbWritten);


/* [call_as] */ HRESULT __stdcall IFillLockBytes_FillAt_Stub( 
    IFillLockBytes  * This,
    /* [in] */ ULARGE_INTEGER ulOffset,
    /* [size_is][in] */ const byte  *pv,
    /* [in] */ unsigned long cb,
    /* [out] */ unsigned long  *pcbWritten);



/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
