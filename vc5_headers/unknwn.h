/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Fri Jul 12 18:09:25 1996
 */
/* Compiler settings for unknwn.idl:
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

#ifndef __unknwn_h__
#define __unknwn_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IUnknown_FWD_DEFINED__
#define __IUnknown_FWD_DEFINED__
typedef interface IUnknown IUnknown;
#endif 	/* __IUnknown_FWD_DEFINED__ */


#ifndef __IClassFactory_FWD_DEFINED__
#define __IClassFactory_FWD_DEFINED__
typedef interface IClassFactory IClassFactory;
#endif 	/* __IClassFactory_FWD_DEFINED__ */


/* header files for imported files */
#include "wtypes.h"

void  * __stdcall MIDL_user_allocate(size_t);
void __stdcall MIDL_user_free( void  * ); 

/****************************************
 * Generated header for interface: __MIDL__intf_0000
 * at Fri Jul 12 18:09:25 1996
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

#ifndef __IUnknown_INTERFACE_DEFINED__
#define __IUnknown_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IUnknown
 * at Fri Jul 12 18:09:25 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef /* [unique] */ IUnknown  *LPUNKNOWN;

//////////////////////////////////////////////////////////////////
// IID_IUnknown and all other system IIDs are provided in UUID.LIB
// Link that library in with your proxies, clients and servers
//////////////////////////////////////////////////////////////////

EXTERN_C const IID IID_IUnknown;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IUnknown
    {
    public:
        BEGIN_INTERFACE
        virtual HRESULT __stdcall QueryInterface( 
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject) = 0;
        
        virtual unsigned long __stdcall AddRef( void) = 0;
        
        virtual unsigned long __stdcall Release( void) = 0;
        
        END_INTERFACE
    };
    
#else 	/* C style interface */

    typedef struct IUnknownVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IUnknown  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IUnknown  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IUnknown  * This);
        
        END_INTERFACE
    } IUnknownVtbl;

    interface IUnknown
    {
        CONST_VTBL struct IUnknownVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUnknown_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IUnknown_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IUnknown_Release(This)	\
    (This)->lpVtbl -> Release(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IUnknown_QueryInterface_Proxy( 
    IUnknown  * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void  * *ppvObject);


void __stdcall IUnknown_QueryInterface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


unsigned long __stdcall IUnknown_AddRef_Proxy( 
    IUnknown  * This);


void __stdcall IUnknown_AddRef_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


unsigned long __stdcall IUnknown_Release_Proxy( 
    IUnknown  * This);


void __stdcall IUnknown_Release_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IUnknown_INTERFACE_DEFINED__ */


#ifndef __IClassFactory_INTERFACE_DEFINED__
#define __IClassFactory_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IClassFactory
 * at Fri Jul 12 18:09:25 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IClassFactory  *LPCLASSFACTORY;


EXTERN_C const IID IID_IClassFactory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IClassFactory : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT __stdcall CreateInstance( 
            /* [unique][in] */ IUnknown  *pUnkOuter,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject) = 0;
        
        virtual /* [local] */ HRESULT __stdcall LockServer( 
            /* [in] */ BOOL fLock) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClassFactoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IClassFactory  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IClassFactory  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IClassFactory  * This);
        
        /* [local] */ HRESULT ( __stdcall  *CreateInstance )( 
            IClassFactory  * This,
            /* [unique][in] */ IUnknown  *pUnkOuter,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        /* [local] */ HRESULT ( __stdcall  *LockServer )( 
            IClassFactory  * This,
            /* [in] */ BOOL fLock);
        
        END_INTERFACE
    } IClassFactoryVtbl;

    interface IClassFactory
    {
        CONST_VTBL struct IClassFactoryVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClassFactory_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClassFactory_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClassFactory_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClassFactory_CreateInstance(This,pUnkOuter,riid,ppvObject)	\
    (This)->lpVtbl -> CreateInstance(This,pUnkOuter,riid,ppvObject)

#define IClassFactory_LockServer(This,fLock)	\
    (This)->lpVtbl -> LockServer(This,fLock)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall IClassFactory_RemoteCreateInstance_Proxy( 
    IClassFactory  * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown  * *ppvObject);


void __stdcall IClassFactory_RemoteCreateInstance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall IClassFactory_RemoteLockServer_Proxy( 
    IClassFactory  * This,
    /* [in] */ BOOL fLock);


void __stdcall IClassFactory_RemoteLockServer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IClassFactory_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* [local] */ HRESULT __stdcall IClassFactory_CreateInstance_Proxy( 
    IClassFactory  * This,
    /* [unique][in] */ IUnknown  *pUnkOuter,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void  * *ppvObject);


/* [call_as] */ HRESULT __stdcall IClassFactory_CreateInstance_Stub( 
    IClassFactory  * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown  * *ppvObject);

/* [local] */ HRESULT __stdcall IClassFactory_LockServer_Proxy( 
    IClassFactory  * This,
    /* [in] */ BOOL fLock);


/* [call_as] */ HRESULT __stdcall IClassFactory_LockServer_Stub( 
    IClassFactory  * This,
    /* [in] */ BOOL fLock);



/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
#pragma once 
