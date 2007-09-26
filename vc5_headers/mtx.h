/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Wed Jan 08 22:06:51 1997
 */
/* Compiler settings for .\mtx.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, app_config, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __mtx_h__
#define __mtx_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IObjectContext_FWD_DEFINED__
#define __IObjectContext_FWD_DEFINED__
typedef interface IObjectContext IObjectContext;
#endif 	/* __IObjectContext_FWD_DEFINED__ */


#ifndef __ISecurityProperty_FWD_DEFINED__
#define __ISecurityProperty_FWD_DEFINED__
typedef interface ISecurityProperty ISecurityProperty;
#endif 	/* __ISecurityProperty_FWD_DEFINED__ */


#ifndef __IObjectControl_FWD_DEFINED__
#define __IObjectControl_FWD_DEFINED__
typedef interface IObjectControl IObjectControl;
#endif 	/* __IObjectControl_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

void  * __stdcall MIDL_user_allocate(size_t);
void __stdcall MIDL_user_free( void  * ); 

/****************************************
 * Generated header for interface: __MIDL__intf_0000
 * at Wed Jan 08 22:06:51 1997
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


// -----------------------------------------------------------------------	
// mtx.h  -- Microsoft Transaction Server Programming Interfaces				
//																			
// This file provides the prototypes for the APIs and COM interfaces			
// used by Microsoft Transaction Server applications.													
//																			
// Microsoft Transaction Server 1.0												
// Copyright (c) 1996 Microsoft Corporation.  All Rights Reserved.		
// -----------------------------------------------------------------------	
#include <objbase.h>
#ifndef _MTX_NOFORCE_LIBS
#pragma comment(lib, "mtx.lib")
#endif
#define CONTEXT_E_ABORTED				0x8004E002
#define CONTEXT_E_ABORTING				0x8004E003
#define CONTEXT_E_NOCONTEXT				0x8004E004
#define CONTEXT_E_NOTREGISTERED			0x8004E005
#define CONTEXT_E_ACTIVITYTIMEOUT		0x8004E006
#define CONTEXT_E_OLDREF				0x8004E007
#define CONTEXT_E_ROLENOTFOUND			0x8004E00C
#define CONTEXT_E_NOSECURITY			0x8004E00D



extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_s_ifspec;

#ifndef __IObjectContext_INTERFACE_DEFINED__
#define __IObjectContext_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IObjectContext
 * at Wed Jan 08 22:06:51 1997
 * using MIDL 3.00.44
 ****************************************/
/* [object][unique][uuid][local] */ 



EXTERN_C const IID IID_IObjectContext;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IObjectContext : public IUnknown
    {
    public:
        virtual HRESULT __stdcall CreateInstance( 
            /* [in] */ REFCLSID rclsid,
            /* [in] */ REFIID riid,
            /* [retval][iid_is][out] */ void*  *ppv) = 0;
        
        virtual HRESULT __stdcall SetComplete( void) = 0;
        
        virtual HRESULT __stdcall SetAbort( void) = 0;
        
        virtual HRESULT __stdcall EnableCommit( void) = 0;
        
        virtual HRESULT __stdcall DisableCommit( void) = 0;
        
        virtual BOOL __stdcall IsInTransaction( void) = 0;
        
        virtual BOOL __stdcall IsSecurityEnabled( void) = 0;
        
        virtual HRESULT __stdcall IsCallerInRole( 
            /* [in] */ BSTR __MIDL_0000,
            /* [retval][out] */ BOOL  *__MIDL_0001) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IObjectContextVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IObjectContext  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IObjectContext  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IObjectContext  * This);
        
        HRESULT ( __stdcall  *CreateInstance )( 
            IObjectContext  * This,
            /* [in] */ REFCLSID rclsid,
            /* [in] */ REFIID riid,
            /* [retval][iid_is][out] */ void*  *ppv);
        
        HRESULT ( __stdcall  *SetComplete )( 
            IObjectContext  * This);
        
        HRESULT ( __stdcall  *SetAbort )( 
            IObjectContext  * This);
        
        HRESULT ( __stdcall  *EnableCommit )( 
            IObjectContext  * This);
        
        HRESULT ( __stdcall  *DisableCommit )( 
            IObjectContext  * This);
        
        BOOL ( __stdcall  *IsInTransaction )( 
            IObjectContext  * This);
        
        BOOL ( __stdcall  *IsSecurityEnabled )( 
            IObjectContext  * This);
        
        HRESULT ( __stdcall  *IsCallerInRole )( 
            IObjectContext  * This,
            /* [in] */ BSTR __MIDL_0000,
            /* [retval][out] */ BOOL  *__MIDL_0001);
        
        END_INTERFACE
    } IObjectContextVtbl;

    interface IObjectContext
    {
        CONST_VTBL struct IObjectContextVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IObjectContext_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IObjectContext_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IObjectContext_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IObjectContext_CreateInstance(This,rclsid,riid,ppv)	\
    (This)->lpVtbl -> CreateInstance(This,rclsid,riid,ppv)

#define IObjectContext_SetComplete(This)	\
    (This)->lpVtbl -> SetComplete(This)

#define IObjectContext_SetAbort(This)	\
    (This)->lpVtbl -> SetAbort(This)

#define IObjectContext_EnableCommit(This)	\
    (This)->lpVtbl -> EnableCommit(This)

#define IObjectContext_DisableCommit(This)	\
    (This)->lpVtbl -> DisableCommit(This)

#define IObjectContext_IsInTransaction(This)	\
    (This)->lpVtbl -> IsInTransaction(This)

#define IObjectContext_IsSecurityEnabled(This)	\
    (This)->lpVtbl -> IsSecurityEnabled(This)

#define IObjectContext_IsCallerInRole(This,__MIDL_0000,__MIDL_0001)	\
    (This)->lpVtbl -> IsCallerInRole(This,__MIDL_0000,__MIDL_0001)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IObjectContext_CreateInstance_Proxy( 
    IObjectContext  * This,
    /* [in] */ REFCLSID rclsid,
    /* [in] */ REFIID riid,
    /* [retval][iid_is][out] */ void*  *ppv);


void __stdcall IObjectContext_CreateInstance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IObjectContext_SetComplete_Proxy( 
    IObjectContext  * This);


void __stdcall IObjectContext_SetComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IObjectContext_SetAbort_Proxy( 
    IObjectContext  * This);


void __stdcall IObjectContext_SetAbort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IObjectContext_EnableCommit_Proxy( 
    IObjectContext  * This);


void __stdcall IObjectContext_EnableCommit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IObjectContext_DisableCommit_Proxy( 
    IObjectContext  * This);


void __stdcall IObjectContext_DisableCommit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


BOOL __stdcall IObjectContext_IsInTransaction_Proxy( 
    IObjectContext  * This);


void __stdcall IObjectContext_IsInTransaction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


BOOL __stdcall IObjectContext_IsSecurityEnabled_Proxy( 
    IObjectContext  * This);


void __stdcall IObjectContext_IsSecurityEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IObjectContext_IsCallerInRole_Proxy( 
    IObjectContext  * This,
    /* [in] */ BSTR __MIDL_0000,
    /* [retval][out] */ BOOL  *__MIDL_0001);


void __stdcall IObjectContext_IsCallerInRole_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IObjectContext_INTERFACE_DEFINED__ */


#ifndef __ISecurityProperty_INTERFACE_DEFINED__
#define __ISecurityProperty_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ISecurityProperty
 * at Wed Jan 08 22:06:51 1997
 * using MIDL 3.00.44
 ****************************************/
/* [object][unique][uuid][local] */ 



EXTERN_C const IID IID_ISecurityProperty;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ISecurityProperty : public IUnknown
    {
    public:
        virtual HRESULT __stdcall GetDirectCreatorSID( 
            PSID  *pSID) = 0;
        
        virtual HRESULT __stdcall GetOriginalCreatorSID( 
            PSID  *pSID) = 0;
        
        virtual HRESULT __stdcall GetDirectCallerSID( 
            PSID  *pSID) = 0;
        
        virtual HRESULT __stdcall GetOriginalCallerSID( 
            PSID  *pSID) = 0;
        
        virtual HRESULT __stdcall ReleaseSID( 
            PSID pSID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISecurityPropertyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            ISecurityProperty  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            ISecurityProperty  * This);
        
        unsigned long ( __stdcall  *Release )( 
            ISecurityProperty  * This);
        
        HRESULT ( __stdcall  *GetDirectCreatorSID )( 
            ISecurityProperty  * This,
            PSID  *pSID);
        
        HRESULT ( __stdcall  *GetOriginalCreatorSID )( 
            ISecurityProperty  * This,
            PSID  *pSID);
        
        HRESULT ( __stdcall  *GetDirectCallerSID )( 
            ISecurityProperty  * This,
            PSID  *pSID);
        
        HRESULT ( __stdcall  *GetOriginalCallerSID )( 
            ISecurityProperty  * This,
            PSID  *pSID);
        
        HRESULT ( __stdcall  *ReleaseSID )( 
            ISecurityProperty  * This,
            PSID pSID);
        
        END_INTERFACE
    } ISecurityPropertyVtbl;

    interface ISecurityProperty
    {
        CONST_VTBL struct ISecurityPropertyVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISecurityProperty_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISecurityProperty_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISecurityProperty_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISecurityProperty_GetDirectCreatorSID(This,pSID)	\
    (This)->lpVtbl -> GetDirectCreatorSID(This,pSID)

#define ISecurityProperty_GetOriginalCreatorSID(This,pSID)	\
    (This)->lpVtbl -> GetOriginalCreatorSID(This,pSID)

#define ISecurityProperty_GetDirectCallerSID(This,pSID)	\
    (This)->lpVtbl -> GetDirectCallerSID(This,pSID)

#define ISecurityProperty_GetOriginalCallerSID(This,pSID)	\
    (This)->lpVtbl -> GetOriginalCallerSID(This,pSID)

#define ISecurityProperty_ReleaseSID(This,pSID)	\
    (This)->lpVtbl -> ReleaseSID(This,pSID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall ISecurityProperty_GetDirectCreatorSID_Proxy( 
    ISecurityProperty  * This,
    PSID  *pSID);


void __stdcall ISecurityProperty_GetDirectCreatorSID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ISecurityProperty_GetOriginalCreatorSID_Proxy( 
    ISecurityProperty  * This,
    PSID  *pSID);


void __stdcall ISecurityProperty_GetOriginalCreatorSID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ISecurityProperty_GetDirectCallerSID_Proxy( 
    ISecurityProperty  * This,
    PSID  *pSID);


void __stdcall ISecurityProperty_GetDirectCallerSID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ISecurityProperty_GetOriginalCallerSID_Proxy( 
    ISecurityProperty  * This,
    PSID  *pSID);


void __stdcall ISecurityProperty_GetOriginalCallerSID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ISecurityProperty_ReleaseSID_Proxy( 
    ISecurityProperty  * This,
    PSID pSID);


void __stdcall ISecurityProperty_ReleaseSID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __ISecurityProperty_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0007
 * at Wed Jan 08 22:06:51 1997
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


DEFINE_GUID( IID_IObjectControl, 0x51372aec, 
		0xcae7, 0x11cf, 0xbe, 0x81, 0x00, 0xaa, 0x00, 0xa2, 0xfa, 0x25);


extern RPC_IF_HANDLE __MIDL__intf_0007_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0007_v0_0_s_ifspec;

#ifndef __IObjectControl_INTERFACE_DEFINED__
#define __IObjectControl_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IObjectControl
 * at Wed Jan 08 22:06:51 1997
 * using MIDL 3.00.44
 ****************************************/
/* [object][unique][uuid][local] */ 



EXTERN_C const IID IID_IObjectControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IObjectControl : public IUnknown
    {
    public:
        virtual HRESULT __stdcall Activate( void) = 0;
        
        virtual void __stdcall Deactivate( void) = 0;
        
        virtual BOOL __stdcall CanBePooled( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IObjectControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IObjectControl  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IObjectControl  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IObjectControl  * This);
        
        HRESULT ( __stdcall  *Activate )( 
            IObjectControl  * This);
        
        void ( __stdcall  *Deactivate )( 
            IObjectControl  * This);
        
        BOOL ( __stdcall  *CanBePooled )( 
            IObjectControl  * This);
        
        END_INTERFACE
    } IObjectControlVtbl;

    interface IObjectControl
    {
        CONST_VTBL struct IObjectControlVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IObjectControl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IObjectControl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IObjectControl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IObjectControl_Activate(This)	\
    (This)->lpVtbl -> Activate(This)

#define IObjectControl_Deactivate(This)	\
    (This)->lpVtbl -> Deactivate(This)

#define IObjectControl_CanBePooled(This)	\
    (This)->lpVtbl -> CanBePooled(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IObjectControl_Activate_Proxy( 
    IObjectControl  * This);


void __stdcall IObjectControl_Activate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


void __stdcall IObjectControl_Deactivate_Proxy( 
    IObjectControl  * This);


void __stdcall IObjectControl_Deactivate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


BOOL __stdcall IObjectControl_CanBePooled_Proxy( 
    IObjectControl  * This);


void __stdcall IObjectControl_CanBePooled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IObjectControl_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0008
 * at Wed Jan 08 22:06:51 1997
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


extern HRESULT GetObjectContext (IObjectContext** ppInstanceContext);
extern void * SafeRef(REFIID rid, IUnknown* pUnk);


extern RPC_IF_HANDLE __MIDL__intf_0008_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0008_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
#pragma once 
