/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Wed Jan 08 22:25:26 1997
 */
/* Compiler settings for spam.idl:
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

#ifndef __mtxspm_h__
#define __mtxspm_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ISharedProperty_FWD_DEFINED__
#define __ISharedProperty_FWD_DEFINED__
typedef interface ISharedProperty ISharedProperty;
#endif 	/* __ISharedProperty_FWD_DEFINED__ */


#ifndef __ISharedPropertyGroup_FWD_DEFINED__
#define __ISharedPropertyGroup_FWD_DEFINED__
typedef interface ISharedPropertyGroup ISharedPropertyGroup;
#endif 	/* __ISharedPropertyGroup_FWD_DEFINED__ */


#ifndef __ISharedPropertyGroupManager_FWD_DEFINED__
#define __ISharedPropertyGroupManager_FWD_DEFINED__
typedef interface ISharedPropertyGroupManager ISharedPropertyGroupManager;
#endif 	/* __ISharedPropertyGroupManager_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

void  * __stdcall MIDL_user_allocate(size_t);
void __stdcall MIDL_user_free( void  * ); 

/****************************************
 * Generated header for interface: __MIDL__intf_0000
 * at Wed Jan 08 22:25:26 1997
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


// -----------------------------------------------------------------------	
// mtxspm.h  -- Microsoft Transaction Server SPM Interfaces					
//																			
// This file provides the COM interfaces for the Microsoft Transaction		
// Server Shared Property Manager.											
//																			
// Microsoft Transaction Server 1.0											
// Copyright (c) 1996 Microsoft Corporation.  All Rights Reserved.   		
// -----------------------------------------------------------------------	


extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_s_ifspec;

#ifndef __ISharedProperty_INTERFACE_DEFINED__
#define __ISharedProperty_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ISharedProperty
 * at Wed Jan 08 22:25:26 1997
 * using MIDL 3.00.44
 ****************************************/
/* [object][unique][helpcontext][helpstring][dual][uuid] */ 



EXTERN_C const IID IID_ISharedProperty;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ISharedProperty : public IDispatch
    {
    public:
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT __stdcall get_Value( 
            /* [retval][out] */ VARIANT  *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT __stdcall put_Value( 
            /* [in] */ VARIANT val) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISharedPropertyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            ISharedProperty  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            ISharedProperty  * This);
        
        unsigned long ( __stdcall  *Release )( 
            ISharedProperty  * This);
        
        HRESULT ( __stdcall  *GetTypeInfoCount )( 
            ISharedProperty  * This,
            /* [out] */ unsigned  *pctinfo);
        
        HRESULT ( __stdcall  *GetTypeInfo )( 
            ISharedProperty  * This,
            /* [in] */ unsigned iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo  * *ppTInfo);
        
        HRESULT ( __stdcall  *GetIDsOfNames )( 
            ISharedProperty  * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR  *rgszNames,
            /* [in] */ unsigned cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID  *rgDispId);
        
        /* [local] */ HRESULT ( __stdcall  *Invoke )( 
            ISharedProperty  * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS  *pDispParams,
            /* [out] */ VARIANT  *pVarResult,
            /* [out] */ EXCEPINFO  *pExcepInfo,
            /* [out] */ unsigned  *puArgErr);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( __stdcall  *get_Value )( 
            ISharedProperty  * This,
            /* [retval][out] */ VARIANT  *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( __stdcall  *put_Value )( 
            ISharedProperty  * This,
            /* [in] */ VARIANT val);
        
        END_INTERFACE
    } ISharedPropertyVtbl;

    interface ISharedProperty
    {
        CONST_VTBL struct ISharedPropertyVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISharedProperty_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISharedProperty_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISharedProperty_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISharedProperty_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISharedProperty_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISharedProperty_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISharedProperty_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISharedProperty_get_Value(This,pVal)	\
    (This)->lpVtbl -> get_Value(This,pVal)

#define ISharedProperty_put_Value(This,val)	\
    (This)->lpVtbl -> put_Value(This,val)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][helpcontext][id][propget] */ HRESULT __stdcall ISharedProperty_get_Value_Proxy( 
    ISharedProperty  * This,
    /* [retval][out] */ VARIANT  *pVal);


void __stdcall ISharedProperty_get_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [helpstring][helpcontext][id][propput] */ HRESULT __stdcall ISharedProperty_put_Value_Proxy( 
    ISharedProperty  * This,
    /* [in] */ VARIANT val);


void __stdcall ISharedProperty_put_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __ISharedProperty_INTERFACE_DEFINED__ */


#ifndef __ISharedPropertyGroup_INTERFACE_DEFINED__
#define __ISharedPropertyGroup_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ISharedPropertyGroup
 * at Wed Jan 08 22:25:26 1997
 * using MIDL 3.00.44
 ****************************************/
/* [object][unique][helpcontext][helpstring][dual][uuid] */ 



EXTERN_C const IID IID_ISharedPropertyGroup;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ISharedPropertyGroup : public IDispatch
    {
    public:
        virtual /* [helpstring][helpcontext][id] */ HRESULT __stdcall CreatePropertyByPosition( 
            /* [in] */ int Index,
            /* [out] */ VARIANT_BOOL  *fExists,
            /* [retval][out] */ ISharedProperty  * *ppProp) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT __stdcall get_PropertyByPosition( 
            /* [in] */ int Index,
            /* [retval][out] */ ISharedProperty  * *ppProperty) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT __stdcall CreateProperty( 
            /* [in] */ BSTR Name,
            /* [out] */ VARIANT_BOOL  *fExists,
            /* [retval][out] */ ISharedProperty  * *ppProp) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT __stdcall get_Property( 
            /* [in] */ BSTR Name,
            /* [retval][out] */ ISharedProperty  * *ppProperty) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISharedPropertyGroupVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            ISharedPropertyGroup  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            ISharedPropertyGroup  * This);
        
        unsigned long ( __stdcall  *Release )( 
            ISharedPropertyGroup  * This);
        
        HRESULT ( __stdcall  *GetTypeInfoCount )( 
            ISharedPropertyGroup  * This,
            /* [out] */ unsigned  *pctinfo);
        
        HRESULT ( __stdcall  *GetTypeInfo )( 
            ISharedPropertyGroup  * This,
            /* [in] */ unsigned iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo  * *ppTInfo);
        
        HRESULT ( __stdcall  *GetIDsOfNames )( 
            ISharedPropertyGroup  * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR  *rgszNames,
            /* [in] */ unsigned cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID  *rgDispId);
        
        /* [local] */ HRESULT ( __stdcall  *Invoke )( 
            ISharedPropertyGroup  * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS  *pDispParams,
            /* [out] */ VARIANT  *pVarResult,
            /* [out] */ EXCEPINFO  *pExcepInfo,
            /* [out] */ unsigned  *puArgErr);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( __stdcall  *CreatePropertyByPosition )( 
            ISharedPropertyGroup  * This,
            /* [in] */ int Index,
            /* [out] */ VARIANT_BOOL  *fExists,
            /* [retval][out] */ ISharedProperty  * *ppProp);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( __stdcall  *get_PropertyByPosition )( 
            ISharedPropertyGroup  * This,
            /* [in] */ int Index,
            /* [retval][out] */ ISharedProperty  * *ppProperty);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( __stdcall  *CreateProperty )( 
            ISharedPropertyGroup  * This,
            /* [in] */ BSTR Name,
            /* [out] */ VARIANT_BOOL  *fExists,
            /* [retval][out] */ ISharedProperty  * *ppProp);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( __stdcall  *get_Property )( 
            ISharedPropertyGroup  * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ ISharedProperty  * *ppProperty);
        
        END_INTERFACE
    } ISharedPropertyGroupVtbl;

    interface ISharedPropertyGroup
    {
        CONST_VTBL struct ISharedPropertyGroupVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISharedPropertyGroup_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISharedPropertyGroup_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISharedPropertyGroup_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISharedPropertyGroup_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISharedPropertyGroup_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISharedPropertyGroup_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISharedPropertyGroup_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISharedPropertyGroup_CreatePropertyByPosition(This,Index,fExists,ppProp)	\
    (This)->lpVtbl -> CreatePropertyByPosition(This,Index,fExists,ppProp)

#define ISharedPropertyGroup_get_PropertyByPosition(This,Index,ppProperty)	\
    (This)->lpVtbl -> get_PropertyByPosition(This,Index,ppProperty)

#define ISharedPropertyGroup_CreateProperty(This,Name,fExists,ppProp)	\
    (This)->lpVtbl -> CreateProperty(This,Name,fExists,ppProp)

#define ISharedPropertyGroup_get_Property(This,Name,ppProperty)	\
    (This)->lpVtbl -> get_Property(This,Name,ppProperty)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][helpcontext][id] */ HRESULT __stdcall ISharedPropertyGroup_CreatePropertyByPosition_Proxy( 
    ISharedPropertyGroup  * This,
    /* [in] */ int Index,
    /* [out] */ VARIANT_BOOL  *fExists,
    /* [retval][out] */ ISharedProperty  * *ppProp);


void __stdcall ISharedPropertyGroup_CreatePropertyByPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [helpstring][helpcontext][id][propget] */ HRESULT __stdcall ISharedPropertyGroup_get_PropertyByPosition_Proxy( 
    ISharedPropertyGroup  * This,
    /* [in] */ int Index,
    /* [retval][out] */ ISharedProperty  * *ppProperty);


void __stdcall ISharedPropertyGroup_get_PropertyByPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [helpstring][helpcontext][id] */ HRESULT __stdcall ISharedPropertyGroup_CreateProperty_Proxy( 
    ISharedPropertyGroup  * This,
    /* [in] */ BSTR Name,
    /* [out] */ VARIANT_BOOL  *fExists,
    /* [retval][out] */ ISharedProperty  * *ppProp);


void __stdcall ISharedPropertyGroup_CreateProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [helpstring][helpcontext][id][propget] */ HRESULT __stdcall ISharedPropertyGroup_get_Property_Proxy( 
    ISharedPropertyGroup  * This,
    /* [in] */ BSTR Name,
    /* [retval][out] */ ISharedProperty  * *ppProperty);


void __stdcall ISharedPropertyGroup_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __ISharedPropertyGroup_INTERFACE_DEFINED__ */


#ifndef __ISharedPropertyGroupManager_INTERFACE_DEFINED__
#define __ISharedPropertyGroupManager_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ISharedPropertyGroupManager
 * at Wed Jan 08 22:25:26 1997
 * using MIDL 3.00.44
 ****************************************/
/* [object][unique][helpcontext][helpstring][dual][uuid] */ 



EXTERN_C const IID IID_ISharedPropertyGroupManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ISharedPropertyGroupManager : public IDispatch
    {
    public:
        virtual /* [helpstring][helpcontext][id] */ HRESULT __stdcall CreatePropertyGroup( 
            /* [in] */ BSTR Name,
            /* [out][in] */ long  *dwIsoMode,
            /* [out][in] */ long  *dwRelMode,
            /* [out] */ VARIANT_BOOL  *fExists,
            /* [retval][out] */ ISharedPropertyGroup  * *ppGroup) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT __stdcall get_Group( 
            /* [in] */ BSTR Name,
            /* [retval][out] */ ISharedPropertyGroup  * *ppGroup) = 0;
        
        virtual /* [helpstring][helpcontext][id][restricted][propget] */ HRESULT __stdcall get__NewEnum( 
            /* [retval][out] */ IUnknown  * *retval) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISharedPropertyGroupManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            ISharedPropertyGroupManager  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            ISharedPropertyGroupManager  * This);
        
        unsigned long ( __stdcall  *Release )( 
            ISharedPropertyGroupManager  * This);
        
        HRESULT ( __stdcall  *GetTypeInfoCount )( 
            ISharedPropertyGroupManager  * This,
            /* [out] */ unsigned  *pctinfo);
        
        HRESULT ( __stdcall  *GetTypeInfo )( 
            ISharedPropertyGroupManager  * This,
            /* [in] */ unsigned iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo  * *ppTInfo);
        
        HRESULT ( __stdcall  *GetIDsOfNames )( 
            ISharedPropertyGroupManager  * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR  *rgszNames,
            /* [in] */ unsigned cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID  *rgDispId);
        
        /* [local] */ HRESULT ( __stdcall  *Invoke )( 
            ISharedPropertyGroupManager  * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS  *pDispParams,
            /* [out] */ VARIANT  *pVarResult,
            /* [out] */ EXCEPINFO  *pExcepInfo,
            /* [out] */ unsigned  *puArgErr);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( __stdcall  *CreatePropertyGroup )( 
            ISharedPropertyGroupManager  * This,
            /* [in] */ BSTR Name,
            /* [out][in] */ long  *dwIsoMode,
            /* [out][in] */ long  *dwRelMode,
            /* [out] */ VARIANT_BOOL  *fExists,
            /* [retval][out] */ ISharedPropertyGroup  * *ppGroup);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( __stdcall  *get_Group )( 
            ISharedPropertyGroupManager  * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ ISharedPropertyGroup  * *ppGroup);
        
        /* [helpstring][helpcontext][id][restricted][propget] */ HRESULT ( __stdcall  *get__NewEnum )( 
            ISharedPropertyGroupManager  * This,
            /* [retval][out] */ IUnknown  * *retval);
        
        END_INTERFACE
    } ISharedPropertyGroupManagerVtbl;

    interface ISharedPropertyGroupManager
    {
        CONST_VTBL struct ISharedPropertyGroupManagerVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISharedPropertyGroupManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISharedPropertyGroupManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISharedPropertyGroupManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISharedPropertyGroupManager_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISharedPropertyGroupManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISharedPropertyGroupManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISharedPropertyGroupManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISharedPropertyGroupManager_CreatePropertyGroup(This,Name,dwIsoMode,dwRelMode,fExists,ppGroup)	\
    (This)->lpVtbl -> CreatePropertyGroup(This,Name,dwIsoMode,dwRelMode,fExists,ppGroup)

#define ISharedPropertyGroupManager_get_Group(This,Name,ppGroup)	\
    (This)->lpVtbl -> get_Group(This,Name,ppGroup)

#define ISharedPropertyGroupManager_get__NewEnum(This,retval)	\
    (This)->lpVtbl -> get__NewEnum(This,retval)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][helpcontext][id] */ HRESULT __stdcall ISharedPropertyGroupManager_CreatePropertyGroup_Proxy( 
    ISharedPropertyGroupManager  * This,
    /* [in] */ BSTR Name,
    /* [out][in] */ long  *dwIsoMode,
    /* [out][in] */ long  *dwRelMode,
    /* [out] */ VARIANT_BOOL  *fExists,
    /* [retval][out] */ ISharedPropertyGroup  * *ppGroup);


void __stdcall ISharedPropertyGroupManager_CreatePropertyGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [helpstring][helpcontext][id][propget] */ HRESULT __stdcall ISharedPropertyGroupManager_get_Group_Proxy( 
    ISharedPropertyGroupManager  * This,
    /* [in] */ BSTR Name,
    /* [retval][out] */ ISharedPropertyGroup  * *ppGroup);


void __stdcall ISharedPropertyGroupManager_get_Group_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [helpstring][helpcontext][id][restricted][propget] */ HRESULT __stdcall ISharedPropertyGroupManager_get__NewEnum_Proxy( 
    ISharedPropertyGroupManager  * This,
    /* [retval][out] */ IUnknown  * *retval);


void __stdcall ISharedPropertyGroupManager_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __ISharedPropertyGroupManager_INTERFACE_DEFINED__ */



#ifndef __MTxSpm_LIBRARY_DEFINED__
#define __MTxSpm_LIBRARY_DEFINED__

/****************************************
 * Generated header for library: MTxSpm
 * at Wed Jan 08 22:25:26 1997
 * using MIDL 3.00.44
 ****************************************/
/* [helpstring][helpfile][version][uuid] */ 


typedef /* [public] */ 
enum __MIDL___MIDL__intf_0075_0001
    {	LockSetGet	= 0,
	LockMethod	= LockSetGet + 1
    }	LockModes;

typedef /* [public] */ 
enum __MIDL___MIDL__intf_0075_0002
    {	Standard	= 0,
	Process	= Standard + 1
    }	ReleaseModes;


EXTERN_C const IID LIBID_MTxSpm;

#ifdef __cplusplus
EXTERN_C const CLSID CLSID_SharedProperty;

class SharedProperty;
#endif

#ifdef __cplusplus
EXTERN_C const CLSID CLSID_SharedPropertyGroup;

class SharedPropertyGroup;
#endif

#ifdef __cplusplus
EXTERN_C const CLSID CLSID_SharedPropertyGroupManager;

class SharedPropertyGroupManager;
#endif
#endif /* __MTxSpm_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __stdcall  BSTR_UserSize(     unsigned long  *, unsigned long            , BSTR  * ); 
unsigned char  * __stdcall  BSTR_UserMarshal(  unsigned long  *, unsigned char  *, BSTR  * ); 
unsigned char  * __stdcall  BSTR_UserUnmarshal(unsigned long  *, unsigned char  *, BSTR  * ); 
void                      __stdcall  BSTR_UserFree(     unsigned long  *, BSTR  * ); 

unsigned long             __stdcall  VARIANT_UserSize(     unsigned long  *, unsigned long            , VARIANT  * ); 
unsigned char  * __stdcall  VARIANT_UserMarshal(  unsigned long  *, unsigned char  *, VARIANT  * ); 
unsigned char  * __stdcall  VARIANT_UserUnmarshal(unsigned long  *, unsigned char  *, VARIANT  * ); 
void                      __stdcall  VARIANT_UserFree(     unsigned long  *, VARIANT  * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
#pragma once 
