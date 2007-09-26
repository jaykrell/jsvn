/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Wed Jun 26 18:29:20 1996
 */
/* Compiler settings for comcat.idl:
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

#ifndef __comcat_h__
#define __comcat_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IEnumGUID_FWD_DEFINED__
#define __IEnumGUID_FWD_DEFINED__
typedef interface IEnumGUID IEnumGUID;
#endif 	/* __IEnumGUID_FWD_DEFINED__ */


#ifndef __IEnumCATEGORYINFO_FWD_DEFINED__
#define __IEnumCATEGORYINFO_FWD_DEFINED__
typedef interface IEnumCATEGORYINFO IEnumCATEGORYINFO;
#endif 	/* __IEnumCATEGORYINFO_FWD_DEFINED__ */


#ifndef __ICatRegister_FWD_DEFINED__
#define __ICatRegister_FWD_DEFINED__
typedef interface ICatRegister ICatRegister;
#endif 	/* __ICatRegister_FWD_DEFINED__ */


#ifndef __ICatInformation_FWD_DEFINED__
#define __ICatInformation_FWD_DEFINED__
typedef interface ICatInformation ICatInformation;
#endif 	/* __ICatInformation_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

void  * __stdcall MIDL_user_allocate(size_t);
void __stdcall MIDL_user_free( void  * ); 

/****************************************
 * Generated header for interface: __MIDL__intf_0000
 * at Wed Jun 26 18:29:20 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


//=--------------------------------------------------------------------------=
// ComCat.h
//=--------------------------------------------------------------------------=
// (C) Copyright 1995-1996 Microsoft Corporation.  All Rights Reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//=--------------------------------------------------------------------------=

#pragma comment(lib,"uuid.lib")

//=--------------------------------------------------------------------------=
// OLE Component Categories Interfaces.
//=--------------------------------------------------------------------------=
//




EXTERN_C const CLSID CLSID_StdComponentCategoriesMgr;

////////////////////////////////////////////////////////////////////////////
//  Types
typedef GUID CATID;

typedef REFGUID REFCATID;

#define IID_IEnumCLSID              IID_IEnumGUID
#define IEnumCLSID                  IEnumGUID
#define LPENUMCLSID                 LPENUMGUID
#define CATID_NULL                   GUID_NULL
#define IsEqualCATID(rcatid1, rcatid2)       IsEqualGUID(rcatid1, rcatid2)
#define IID_IEnumCATID       IID_IEnumGUID
#define IEnumCATID           IEnumGUID

////////////////////////////////////////////////////////////////////////////
//  Category IDs (link to uuid3.lib)
EXTERN_C const CATID CATID_Insertable;
EXTERN_C const CATID CATID_Control;
EXTERN_C const CATID CATID_Programmable;
EXTERN_C const CATID CATID_IsShortcut;
EXTERN_C const CATID CATID_NeverShowExt;
EXTERN_C const CATID CATID_DocObject;
EXTERN_C const CATID CATID_Printable;
EXTERN_C const CATID CATID_RequiresDataPathHost;
EXTERN_C const CATID CATID_PersistsToMoniker;
EXTERN_C const CATID CATID_PersistsToStorage;
EXTERN_C const CATID CATID_PersistsToStreamInit;
EXTERN_C const CATID CATID_PersistsToStream;
EXTERN_C const CATID CATID_PersistsToMemory;
EXTERN_C const CATID CATID_PersistsToFile;
EXTERN_C const CATID CATID_PersistsToPropertyBag;
EXTERN_C const CATID CATID_InternetAware;

////////////////////////////////////////////////////////////////////////////
//  Interface Definitions
#ifndef _LPENUMGUID_DEFINED
#define _LPENUMGUID_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_s_ifspec;

#ifndef __IEnumGUID_INTERFACE_DEFINED__
#define __IEnumGUID_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumGUID
 * at Wed Jun 26 18:29:20 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IEnumGUID  *LPENUMGUID;


EXTERN_C const IID IID_IEnumGUID;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IEnumGUID : public IUnknown
    {
    public:
        virtual HRESULT __stdcall Next( 
            /* [in] */ unsigned long celt,
            /* [length_is][size_is][out] */ GUID  *rgelt,
            /* [out] */ unsigned long  *pceltFetched) = 0;
        
        virtual HRESULT __stdcall Skip( 
            /* [in] */ unsigned long celt) = 0;
        
        virtual HRESULT __stdcall Reset( void) = 0;
        
        virtual HRESULT __stdcall Clone( 
            /* [out] */ IEnumGUID  * *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumGUIDVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IEnumGUID  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IEnumGUID  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IEnumGUID  * This);
        
        HRESULT ( __stdcall  *Next )( 
            IEnumGUID  * This,
            /* [in] */ unsigned long celt,
            /* [length_is][size_is][out] */ GUID  *rgelt,
            /* [out] */ unsigned long  *pceltFetched);
        
        HRESULT ( __stdcall  *Skip )( 
            IEnumGUID  * This,
            /* [in] */ unsigned long celt);
        
        HRESULT ( __stdcall  *Reset )( 
            IEnumGUID  * This);
        
        HRESULT ( __stdcall  *Clone )( 
            IEnumGUID  * This,
            /* [out] */ IEnumGUID  * *ppenum);
        
        END_INTERFACE
    } IEnumGUIDVtbl;

    interface IEnumGUID
    {
        CONST_VTBL struct IEnumGUIDVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumGUID_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumGUID_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumGUID_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumGUID_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumGUID_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumGUID_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumGUID_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IEnumGUID_Next_Proxy( 
    IEnumGUID  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ GUID  *rgelt,
    /* [out] */ unsigned long  *pceltFetched);


void __stdcall IEnumGUID_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumGUID_Skip_Proxy( 
    IEnumGUID  * This,
    /* [in] */ unsigned long celt);


void __stdcall IEnumGUID_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumGUID_Reset_Proxy( 
    IEnumGUID  * This);


void __stdcall IEnumGUID_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumGUID_Clone_Proxy( 
    IEnumGUID  * This,
    /* [out] */ IEnumGUID  * *ppenum);


void __stdcall IEnumGUID_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IEnumGUID_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0006
 * at Wed Jun 26 18:29:20 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif
#ifndef _LPENUMCATEGORYINFO_DEFINED
#define _LPENUMCATEGORYINFO_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0006_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0006_v0_0_s_ifspec;

#ifndef __IEnumCATEGORYINFO_INTERFACE_DEFINED__
#define __IEnumCATEGORYINFO_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumCATEGORYINFO
 * at Wed Jun 26 18:29:20 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IEnumCATEGORYINFO  *LPENUNCATEGORYINFO;

typedef struct  tagCATEGORYINFO
    {
    CATID catid;
    LCID lcid;
    OLECHAR szDescription[ 128 ];
    }	CATEGORYINFO;

typedef struct tagCATEGORYINFO  *LPCATEGORYINFO;


EXTERN_C const IID IID_IEnumCATEGORYINFO;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IEnumCATEGORYINFO : public IUnknown
    {
    public:
        virtual HRESULT __stdcall Next( 
            /* [in] */ unsigned long celt,
            /* [length_is][size_is][out] */ CATEGORYINFO  *rgelt,
            /* [out] */ unsigned long  *pceltFetched) = 0;
        
        virtual HRESULT __stdcall Skip( 
            /* [in] */ unsigned long celt) = 0;
        
        virtual HRESULT __stdcall Reset( void) = 0;
        
        virtual HRESULT __stdcall Clone( 
            /* [out] */ IEnumCATEGORYINFO  * *ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumCATEGORYINFOVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IEnumCATEGORYINFO  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IEnumCATEGORYINFO  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IEnumCATEGORYINFO  * This);
        
        HRESULT ( __stdcall  *Next )( 
            IEnumCATEGORYINFO  * This,
            /* [in] */ unsigned long celt,
            /* [length_is][size_is][out] */ CATEGORYINFO  *rgelt,
            /* [out] */ unsigned long  *pceltFetched);
        
        HRESULT ( __stdcall  *Skip )( 
            IEnumCATEGORYINFO  * This,
            /* [in] */ unsigned long celt);
        
        HRESULT ( __stdcall  *Reset )( 
            IEnumCATEGORYINFO  * This);
        
        HRESULT ( __stdcall  *Clone )( 
            IEnumCATEGORYINFO  * This,
            /* [out] */ IEnumCATEGORYINFO  * *ppenum);
        
        END_INTERFACE
    } IEnumCATEGORYINFOVtbl;

    interface IEnumCATEGORYINFO
    {
        CONST_VTBL struct IEnumCATEGORYINFOVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumCATEGORYINFO_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumCATEGORYINFO_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumCATEGORYINFO_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumCATEGORYINFO_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumCATEGORYINFO_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumCATEGORYINFO_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumCATEGORYINFO_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IEnumCATEGORYINFO_Next_Proxy( 
    IEnumCATEGORYINFO  * This,
    /* [in] */ unsigned long celt,
    /* [length_is][size_is][out] */ CATEGORYINFO  *rgelt,
    /* [out] */ unsigned long  *pceltFetched);


void __stdcall IEnumCATEGORYINFO_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumCATEGORYINFO_Skip_Proxy( 
    IEnumCATEGORYINFO  * This,
    /* [in] */ unsigned long celt);


void __stdcall IEnumCATEGORYINFO_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumCATEGORYINFO_Reset_Proxy( 
    IEnumCATEGORYINFO  * This);


void __stdcall IEnumCATEGORYINFO_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumCATEGORYINFO_Clone_Proxy( 
    IEnumCATEGORYINFO  * This,
    /* [out] */ IEnumCATEGORYINFO  * *ppenum);


void __stdcall IEnumCATEGORYINFO_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IEnumCATEGORYINFO_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0007
 * at Wed Jun 26 18:29:20 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif
#ifndef _LPCATREGISTER_DEFINED
#define _LPCATREGISTER_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0007_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0007_v0_0_s_ifspec;

#ifndef __ICatRegister_INTERFACE_DEFINED__
#define __ICatRegister_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ICatRegister
 * at Wed Jun 26 18:29:20 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ ICatRegister  *LPCATREGISTER;


EXTERN_C const IID IID_ICatRegister;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ICatRegister : public IUnknown
    {
    public:
        virtual HRESULT __stdcall RegisterCategories( 
            /* [in] */ unsigned long cCategories,
            /* [size_is][in] */ CATEGORYINFO  rgCategoryInfo[  ]) = 0;
        
        virtual HRESULT __stdcall UnRegisterCategories( 
            /* [in] */ unsigned long cCategories,
            /* [size_is][in] */ CATID  rgcatid[  ]) = 0;
        
        virtual HRESULT __stdcall RegisterClassImplCategories( 
            /* [in] */ REFCLSID rclsid,
            /* [in] */ unsigned long cCategories,
            /* [size_is][in] */ CATID  rgcatid[  ]) = 0;
        
        virtual HRESULT __stdcall UnRegisterClassImplCategories( 
            /* [in] */ REFCLSID rclsid,
            /* [in] */ unsigned long cCategories,
            /* [size_is][in] */ CATID  rgcatid[  ]) = 0;
        
        virtual HRESULT __stdcall RegisterClassReqCategories( 
            /* [in] */ REFCLSID rclsid,
            /* [in] */ unsigned long cCategories,
            /* [size_is][in] */ CATID  rgcatid[  ]) = 0;
        
        virtual HRESULT __stdcall UnRegisterClassReqCategories( 
            /* [in] */ REFCLSID rclsid,
            /* [in] */ unsigned long cCategories,
            /* [size_is][in] */ CATID  rgcatid[  ]) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICatRegisterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            ICatRegister  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            ICatRegister  * This);
        
        unsigned long ( __stdcall  *Release )( 
            ICatRegister  * This);
        
        HRESULT ( __stdcall  *RegisterCategories )( 
            ICatRegister  * This,
            /* [in] */ unsigned long cCategories,
            /* [size_is][in] */ CATEGORYINFO  rgCategoryInfo[  ]);
        
        HRESULT ( __stdcall  *UnRegisterCategories )( 
            ICatRegister  * This,
            /* [in] */ unsigned long cCategories,
            /* [size_is][in] */ CATID  rgcatid[  ]);
        
        HRESULT ( __stdcall  *RegisterClassImplCategories )( 
            ICatRegister  * This,
            /* [in] */ REFCLSID rclsid,
            /* [in] */ unsigned long cCategories,
            /* [size_is][in] */ CATID  rgcatid[  ]);
        
        HRESULT ( __stdcall  *UnRegisterClassImplCategories )( 
            ICatRegister  * This,
            /* [in] */ REFCLSID rclsid,
            /* [in] */ unsigned long cCategories,
            /* [size_is][in] */ CATID  rgcatid[  ]);
        
        HRESULT ( __stdcall  *RegisterClassReqCategories )( 
            ICatRegister  * This,
            /* [in] */ REFCLSID rclsid,
            /* [in] */ unsigned long cCategories,
            /* [size_is][in] */ CATID  rgcatid[  ]);
        
        HRESULT ( __stdcall  *UnRegisterClassReqCategories )( 
            ICatRegister  * This,
            /* [in] */ REFCLSID rclsid,
            /* [in] */ unsigned long cCategories,
            /* [size_is][in] */ CATID  rgcatid[  ]);
        
        END_INTERFACE
    } ICatRegisterVtbl;

    interface ICatRegister
    {
        CONST_VTBL struct ICatRegisterVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICatRegister_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICatRegister_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICatRegister_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICatRegister_RegisterCategories(This,cCategories,rgCategoryInfo)	\
    (This)->lpVtbl -> RegisterCategories(This,cCategories,rgCategoryInfo)

#define ICatRegister_UnRegisterCategories(This,cCategories,rgcatid)	\
    (This)->lpVtbl -> UnRegisterCategories(This,cCategories,rgcatid)

#define ICatRegister_RegisterClassImplCategories(This,rclsid,cCategories,rgcatid)	\
    (This)->lpVtbl -> RegisterClassImplCategories(This,rclsid,cCategories,rgcatid)

#define ICatRegister_UnRegisterClassImplCategories(This,rclsid,cCategories,rgcatid)	\
    (This)->lpVtbl -> UnRegisterClassImplCategories(This,rclsid,cCategories,rgcatid)

#define ICatRegister_RegisterClassReqCategories(This,rclsid,cCategories,rgcatid)	\
    (This)->lpVtbl -> RegisterClassReqCategories(This,rclsid,cCategories,rgcatid)

#define ICatRegister_UnRegisterClassReqCategories(This,rclsid,cCategories,rgcatid)	\
    (This)->lpVtbl -> UnRegisterClassReqCategories(This,rclsid,cCategories,rgcatid)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall ICatRegister_RegisterCategories_Proxy( 
    ICatRegister  * This,
    /* [in] */ unsigned long cCategories,
    /* [size_is][in] */ CATEGORYINFO  rgCategoryInfo[  ]);


void __stdcall ICatRegister_RegisterCategories_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICatRegister_UnRegisterCategories_Proxy( 
    ICatRegister  * This,
    /* [in] */ unsigned long cCategories,
    /* [size_is][in] */ CATID  rgcatid[  ]);


void __stdcall ICatRegister_UnRegisterCategories_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICatRegister_RegisterClassImplCategories_Proxy( 
    ICatRegister  * This,
    /* [in] */ REFCLSID rclsid,
    /* [in] */ unsigned long cCategories,
    /* [size_is][in] */ CATID  rgcatid[  ]);


void __stdcall ICatRegister_RegisterClassImplCategories_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICatRegister_UnRegisterClassImplCategories_Proxy( 
    ICatRegister  * This,
    /* [in] */ REFCLSID rclsid,
    /* [in] */ unsigned long cCategories,
    /* [size_is][in] */ CATID  rgcatid[  ]);


void __stdcall ICatRegister_UnRegisterClassImplCategories_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICatRegister_RegisterClassReqCategories_Proxy( 
    ICatRegister  * This,
    /* [in] */ REFCLSID rclsid,
    /* [in] */ unsigned long cCategories,
    /* [size_is][in] */ CATID  rgcatid[  ]);


void __stdcall ICatRegister_RegisterClassReqCategories_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICatRegister_UnRegisterClassReqCategories_Proxy( 
    ICatRegister  * This,
    /* [in] */ REFCLSID rclsid,
    /* [in] */ unsigned long cCategories,
    /* [size_is][in] */ CATID  rgcatid[  ]);


void __stdcall ICatRegister_UnRegisterClassReqCategories_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __ICatRegister_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0008
 * at Wed Jun 26 18:29:20 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif
#ifndef _LPCATINFORMATION_DEFINED
#define _LPCATINFORMATION_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0008_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0008_v0_0_s_ifspec;

#ifndef __ICatInformation_INTERFACE_DEFINED__
#define __ICatInformation_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ICatInformation
 * at Wed Jun 26 18:29:20 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ ICatInformation  *LPCATINFORMATION;


EXTERN_C const IID IID_ICatInformation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ICatInformation : public IUnknown
    {
    public:
        virtual HRESULT __stdcall EnumCategories( 
            /* [in] */ LCID lcid,
            /* [out] */ IEnumCATEGORYINFO  * *ppenumCategoryInfo) = 0;
        
        virtual HRESULT __stdcall GetCategoryDesc( 
            /* [in] */ REFCATID rcatid,
            /* [in] */ LCID lcid,
            /* [out] */ LPWSTR  *pszDesc) = 0;
        
        virtual HRESULT __stdcall EnumClassesOfCategories( 
            /* [in] */ unsigned long cImplemented,
            /* [size_is][in] */ CATID  rgcatidImpl[  ],
            /* [in] */ unsigned long cRequired,
            /* [size_is][in] */ CATID  rgcatidReq[  ],
            /* [out] */ IEnumGUID  * *ppenumClsid) = 0;
        
        virtual HRESULT __stdcall IsClassOfCategories( 
            /* [in] */ REFCLSID rclsid,
            /* [in] */ unsigned long cImplemented,
            /* [size_is][in] */ CATID  rgcatidImpl[  ],
            /* [in] */ unsigned long cRequired,
            /* [size_is][in] */ CATID  rgcatidReq[  ]) = 0;
        
        virtual HRESULT __stdcall EnumImplCategoriesOfClass( 
            /* [in] */ REFCLSID rclsid,
            /* [out] */ IEnumGUID  * *ppenumCatid) = 0;
        
        virtual HRESULT __stdcall EnumReqCategoriesOfClass( 
            /* [in] */ REFCLSID rclsid,
            /* [out] */ IEnumGUID  * *ppenumCatid) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICatInformationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            ICatInformation  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            ICatInformation  * This);
        
        unsigned long ( __stdcall  *Release )( 
            ICatInformation  * This);
        
        HRESULT ( __stdcall  *EnumCategories )( 
            ICatInformation  * This,
            /* [in] */ LCID lcid,
            /* [out] */ IEnumCATEGORYINFO  * *ppenumCategoryInfo);
        
        HRESULT ( __stdcall  *GetCategoryDesc )( 
            ICatInformation  * This,
            /* [in] */ REFCATID rcatid,
            /* [in] */ LCID lcid,
            /* [out] */ LPWSTR  *pszDesc);
        
        HRESULT ( __stdcall  *EnumClassesOfCategories )( 
            ICatInformation  * This,
            /* [in] */ unsigned long cImplemented,
            /* [size_is][in] */ CATID  rgcatidImpl[  ],
            /* [in] */ unsigned long cRequired,
            /* [size_is][in] */ CATID  rgcatidReq[  ],
            /* [out] */ IEnumGUID  * *ppenumClsid);
        
        HRESULT ( __stdcall  *IsClassOfCategories )( 
            ICatInformation  * This,
            /* [in] */ REFCLSID rclsid,
            /* [in] */ unsigned long cImplemented,
            /* [size_is][in] */ CATID  rgcatidImpl[  ],
            /* [in] */ unsigned long cRequired,
            /* [size_is][in] */ CATID  rgcatidReq[  ]);
        
        HRESULT ( __stdcall  *EnumImplCategoriesOfClass )( 
            ICatInformation  * This,
            /* [in] */ REFCLSID rclsid,
            /* [out] */ IEnumGUID  * *ppenumCatid);
        
        HRESULT ( __stdcall  *EnumReqCategoriesOfClass )( 
            ICatInformation  * This,
            /* [in] */ REFCLSID rclsid,
            /* [out] */ IEnumGUID  * *ppenumCatid);
        
        END_INTERFACE
    } ICatInformationVtbl;

    interface ICatInformation
    {
        CONST_VTBL struct ICatInformationVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICatInformation_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICatInformation_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICatInformation_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICatInformation_EnumCategories(This,lcid,ppenumCategoryInfo)	\
    (This)->lpVtbl -> EnumCategories(This,lcid,ppenumCategoryInfo)

#define ICatInformation_GetCategoryDesc(This,rcatid,lcid,pszDesc)	\
    (This)->lpVtbl -> GetCategoryDesc(This,rcatid,lcid,pszDesc)

#define ICatInformation_EnumClassesOfCategories(This,cImplemented,rgcatidImpl,cRequired,rgcatidReq,ppenumClsid)	\
    (This)->lpVtbl -> EnumClassesOfCategories(This,cImplemented,rgcatidImpl,cRequired,rgcatidReq,ppenumClsid)

#define ICatInformation_IsClassOfCategories(This,rclsid,cImplemented,rgcatidImpl,cRequired,rgcatidReq)	\
    (This)->lpVtbl -> IsClassOfCategories(This,rclsid,cImplemented,rgcatidImpl,cRequired,rgcatidReq)

#define ICatInformation_EnumImplCategoriesOfClass(This,rclsid,ppenumCatid)	\
    (This)->lpVtbl -> EnumImplCategoriesOfClass(This,rclsid,ppenumCatid)

#define ICatInformation_EnumReqCategoriesOfClass(This,rclsid,ppenumCatid)	\
    (This)->lpVtbl -> EnumReqCategoriesOfClass(This,rclsid,ppenumCatid)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall ICatInformation_EnumCategories_Proxy( 
    ICatInformation  * This,
    /* [in] */ LCID lcid,
    /* [out] */ IEnumCATEGORYINFO  * *ppenumCategoryInfo);


void __stdcall ICatInformation_EnumCategories_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICatInformation_GetCategoryDesc_Proxy( 
    ICatInformation  * This,
    /* [in] */ REFCATID rcatid,
    /* [in] */ LCID lcid,
    /* [out] */ LPWSTR  *pszDesc);


void __stdcall ICatInformation_GetCategoryDesc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICatInformation_EnumClassesOfCategories_Proxy( 
    ICatInformation  * This,
    /* [in] */ unsigned long cImplemented,
    /* [size_is][in] */ CATID  rgcatidImpl[  ],
    /* [in] */ unsigned long cRequired,
    /* [size_is][in] */ CATID  rgcatidReq[  ],
    /* [out] */ IEnumGUID  * *ppenumClsid);


void __stdcall ICatInformation_EnumClassesOfCategories_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICatInformation_IsClassOfCategories_Proxy( 
    ICatInformation  * This,
    /* [in] */ REFCLSID rclsid,
    /* [in] */ unsigned long cImplemented,
    /* [size_is][in] */ CATID  rgcatidImpl[  ],
    /* [in] */ unsigned long cRequired,
    /* [size_is][in] */ CATID  rgcatidReq[  ]);


void __stdcall ICatInformation_IsClassOfCategories_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICatInformation_EnumImplCategoriesOfClass_Proxy( 
    ICatInformation  * This,
    /* [in] */ REFCLSID rclsid,
    /* [out] */ IEnumGUID  * *ppenumCatid);


void __stdcall ICatInformation_EnumImplCategoriesOfClass_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ICatInformation_EnumReqCategoriesOfClass_Proxy( 
    ICatInformation  * This,
    /* [in] */ REFCLSID rclsid,
    /* [out] */ IEnumGUID  * *ppenumCatid);


void __stdcall ICatInformation_EnumReqCategoriesOfClass_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __ICatInformation_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0009
 * at Wed Jun 26 18:29:20 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif


extern RPC_IF_HANDLE __MIDL__intf_0009_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0009_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
#pragma once 
