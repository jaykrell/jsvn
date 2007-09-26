/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Wed Jun 26 18:29:37 1996
 */
/* Compiler settings for objsafe.idl:
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

#ifndef __objsafe_h__
#define __objsafe_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IObjectSafety_FWD_DEFINED__
#define __IObjectSafety_FWD_DEFINED__
typedef interface IObjectSafety IObjectSafety;
#endif 	/* __IObjectSafety_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

void  * __stdcall MIDL_user_allocate(size_t);
void __stdcall MIDL_user_free( void  * ); 

/****************************************
 * Generated header for interface: __MIDL__intf_0000
 * at Wed Jun 26 18:29:37 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


//=--------------------------------------------------------------------------=
// ObjSafe.h
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
// Object Safety Interfaces.

//+--------------------------------------------------------------------------=
//
//  Contents:   IObjectSafety definition
//
//
//  IObjectSafety should be implemented by objects that have interfaces which
//      support "untrusted" clients (for example, scripts). It allows the owner of
//      the object to specify which interfaces need to be protected from untrusted
//      use. Examples of interfaces that might be protected in this way are:
//
//      IID_IDispatch           - "Safe for automating with untrusted automation client or script"
//      IID_IPersist*           - "Safe for initializing with untrusted data"
//      IID_IActiveScript       - "Safe for running untrusted scripts"
//
//---------------------------------------------------------------------------=
#ifndef _LPSAFEOBJECT_DEFINED
#define _LPSAFEOBJECT_DEFINED

// Option bit definitions for IObjectSafety:
#define	INTERFACESAFE_FOR_UNTRUSTED_CALLER	0x00000001	// Caller of interface may be untrusted
#define	INTERFACESAFE_FOR_UNTRUSTED_DATA	0x00000002	// Data passed into interface may be untrusted

// {CB5BDC81-93C1-11cf-8F20-00805F2CD064}
DEFINE_GUID(IID_IObjectSafety, 0xcb5bdc81, 0x93c1, 0x11cf, 0x8f, 0x20, 0x0, 0x80, 0x5f, 0x2c, 0xd0, 0x64);
EXTERN_C GUID CATID_SafeForScripting;
EXTERN_C GUID CATID_SafeForInitializing;



extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_s_ifspec;

#ifndef __IObjectSafety_INTERFACE_DEFINED__
#define __IObjectSafety_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IObjectSafety
 * at Wed Jun 26 18:29:37 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 



EXTERN_C const IID IID_IObjectSafety;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IObjectSafety : public IUnknown
    {
    public:
        virtual HRESULT __stdcall GetInterfaceSafetyOptions( 
            /* [in] */ REFIID riid,
            /* [out] */ unsigned long  *pdwSupportedOptions,
            /* [out] */ unsigned long  *pdwEnabledOptions) = 0;
        
        virtual HRESULT __stdcall SetInterfaceSafetyOptions( 
            /* [in] */ REFIID riid,
            /* [in] */ unsigned long dwOptionSetMask,
            /* [in] */ unsigned long dwEnabledOptions) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IObjectSafetyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IObjectSafety  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IObjectSafety  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IObjectSafety  * This);
        
        HRESULT ( __stdcall  *GetInterfaceSafetyOptions )( 
            IObjectSafety  * This,
            /* [in] */ REFIID riid,
            /* [out] */ unsigned long  *pdwSupportedOptions,
            /* [out] */ unsigned long  *pdwEnabledOptions);
        
        HRESULT ( __stdcall  *SetInterfaceSafetyOptions )( 
            IObjectSafety  * This,
            /* [in] */ REFIID riid,
            /* [in] */ unsigned long dwOptionSetMask,
            /* [in] */ unsigned long dwEnabledOptions);
        
        END_INTERFACE
    } IObjectSafetyVtbl;

    interface IObjectSafety
    {
        CONST_VTBL struct IObjectSafetyVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IObjectSafety_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IObjectSafety_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IObjectSafety_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IObjectSafety_GetInterfaceSafetyOptions(This,riid,pdwSupportedOptions,pdwEnabledOptions)	\
    (This)->lpVtbl -> GetInterfaceSafetyOptions(This,riid,pdwSupportedOptions,pdwEnabledOptions)

#define IObjectSafety_SetInterfaceSafetyOptions(This,riid,dwOptionSetMask,dwEnabledOptions)	\
    (This)->lpVtbl -> SetInterfaceSafetyOptions(This,riid,dwOptionSetMask,dwEnabledOptions)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IObjectSafety_GetInterfaceSafetyOptions_Proxy( 
    IObjectSafety  * This,
    /* [in] */ REFIID riid,
    /* [out] */ unsigned long  *pdwSupportedOptions,
    /* [out] */ unsigned long  *pdwEnabledOptions);


void __stdcall IObjectSafety_GetInterfaceSafetyOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IObjectSafety_SetInterfaceSafetyOptions_Proxy( 
    IObjectSafety  * This,
    /* [in] */ REFIID riid,
    /* [in] */ unsigned long dwOptionSetMask,
    /* [in] */ unsigned long dwEnabledOptions);


void __stdcall IObjectSafety_SetInterfaceSafetyOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IObjectSafety_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0006
 * at Wed Jun 26 18:29:37 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


typedef /* [unique] */ IObjectSafety  *LPOBJECTSAFETY;

#endif


extern RPC_IF_HANDLE __MIDL__intf_0006_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0006_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
#pragma once 
