/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Tue Jul 30 17:20:06 1996
 */
/* Compiler settings for servprov.idl:
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

#ifndef __servprov_h__
#define __servprov_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IServiceProvider_FWD_DEFINED__
#define __IServiceProvider_FWD_DEFINED__
typedef interface IServiceProvider IServiceProvider;
#endif 	/* __IServiceProvider_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"

void  * __stdcall MIDL_user_allocate(size_t);
void __stdcall MIDL_user_free( void  * ); 

/****************************************
 * Generated header for interface: __MIDL__intf_0000
 * at Tue Jul 30 17:20:06 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


//=--------------------------------------------------------------------------=
// ServProv.h
//=--------------------------------------------------------------------------=
// (C) Copyright 1995-1996 Microsoft Corporation.  All Rights Reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//=--------------------------------------------------------------------------=

#pragma comment(lib,"uuid.lib")

//---------------------------------------------------------------------------=
// IServiceProvider Interfaces.


#ifndef _LPSERVICEPROVIDER_DEFINED
#define _LPSERVICEPROVIDER_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_s_ifspec;

#ifndef __IServiceProvider_INTERFACE_DEFINED__
#define __IServiceProvider_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IServiceProvider
 * at Tue Jul 30 17:20:06 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IServiceProvider  *LPSERVICEPROVIDER;


EXTERN_C const IID IID_IServiceProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IServiceProvider : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT __stdcall QueryService( 
            /* [in] */ REFGUID guidService,
            /* [in] */ REFIID riid,
            /* [out] */ void  * *ppvObject) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IServiceProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IServiceProvider  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IServiceProvider  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IServiceProvider  * This);
        
        /* [local] */ HRESULT ( __stdcall  *QueryService )( 
            IServiceProvider  * This,
            /* [in] */ REFGUID guidService,
            /* [in] */ REFIID riid,
            /* [out] */ void  * *ppvObject);
        
        END_INTERFACE
    } IServiceProviderVtbl;

    interface IServiceProvider
    {
        CONST_VTBL struct IServiceProviderVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IServiceProvider_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IServiceProvider_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IServiceProvider_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IServiceProvider_QueryService(This,guidService,riid,ppvObject)	\
    (This)->lpVtbl -> QueryService(This,guidService,riid,ppvObject)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall IServiceProvider_RemoteQueryService_Proxy( 
    IServiceProvider  * This,
    /* [in] */ REFGUID guidService,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown  * *ppvObject);


void __stdcall IServiceProvider_RemoteQueryService_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IServiceProvider_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0054
 * at Tue Jul 30 17:20:06 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif


extern RPC_IF_HANDLE __MIDL__intf_0054_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0054_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* [local] */ HRESULT __stdcall IServiceProvider_QueryService_Proxy( 
    IServiceProvider  * This,
    /* [in] */ REFGUID guidService,
    /* [in] */ REFIID riid,
    /* [out] */ void  * *ppvObject);


/* [call_as] */ HRESULT __stdcall IServiceProvider_QueryService_Stub( 
    IServiceProvider  * This,
    /* [in] */ REFGUID guidService,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown  * *ppvObject);



/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
#pragma once 
