/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.39 */
/* at Sat Jul 13 21:56:58 1996
 */
/* Compiler settings for c:\oa\src\idl\ocidl.idl:
    Oic (OptLev=i1), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ocidl_h__
#define __ocidl_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IEnumConnections_FWD_DEFINED__
#define __IEnumConnections_FWD_DEFINED__
typedef interface IEnumConnections IEnumConnections;
#endif 	/* __IEnumConnections_FWD_DEFINED__ */


#ifndef __IConnectionPoint_FWD_DEFINED__
#define __IConnectionPoint_FWD_DEFINED__
typedef interface IConnectionPoint IConnectionPoint;
#endif 	/* __IConnectionPoint_FWD_DEFINED__ */


#ifndef __IEnumConnectionPoints_FWD_DEFINED__
#define __IEnumConnectionPoints_FWD_DEFINED__
typedef interface IEnumConnectionPoints IEnumConnectionPoints;
#endif 	/* __IEnumConnectionPoints_FWD_DEFINED__ */


#ifndef __IConnectionPointContainer_FWD_DEFINED__
#define __IConnectionPointContainer_FWD_DEFINED__
typedef interface IConnectionPointContainer IConnectionPointContainer;
#endif 	/* __IConnectionPointContainer_FWD_DEFINED__ */


#ifndef __IClassFactory2_FWD_DEFINED__
#define __IClassFactory2_FWD_DEFINED__
typedef interface IClassFactory2 IClassFactory2;
#endif 	/* __IClassFactory2_FWD_DEFINED__ */


#ifndef __IProvideClassInfo_FWD_DEFINED__
#define __IProvideClassInfo_FWD_DEFINED__
typedef interface IProvideClassInfo IProvideClassInfo;
#endif 	/* __IProvideClassInfo_FWD_DEFINED__ */


#ifndef __IProvideClassInfo2_FWD_DEFINED__
#define __IProvideClassInfo2_FWD_DEFINED__
typedef interface IProvideClassInfo2 IProvideClassInfo2;
#endif 	/* __IProvideClassInfo2_FWD_DEFINED__ */


#ifndef __IOleControl_FWD_DEFINED__
#define __IOleControl_FWD_DEFINED__
typedef interface IOleControl IOleControl;
#endif 	/* __IOleControl_FWD_DEFINED__ */


#ifndef __IOleControlSite_FWD_DEFINED__
#define __IOleControlSite_FWD_DEFINED__
typedef interface IOleControlSite IOleControlSite;
#endif 	/* __IOleControlSite_FWD_DEFINED__ */


#ifndef __IPropertyPage_FWD_DEFINED__
#define __IPropertyPage_FWD_DEFINED__
typedef interface IPropertyPage IPropertyPage;
#endif 	/* __IPropertyPage_FWD_DEFINED__ */


#ifndef __IPropertyPage2_FWD_DEFINED__
#define __IPropertyPage2_FWD_DEFINED__
typedef interface IPropertyPage2 IPropertyPage2;
#endif 	/* __IPropertyPage2_FWD_DEFINED__ */


#ifndef __IPropertyPageSite_FWD_DEFINED__
#define __IPropertyPageSite_FWD_DEFINED__
typedef interface IPropertyPageSite IPropertyPageSite;
#endif 	/* __IPropertyPageSite_FWD_DEFINED__ */


#ifndef __IPropertyNotifySink_FWD_DEFINED__
#define __IPropertyNotifySink_FWD_DEFINED__
typedef interface IPropertyNotifySink IPropertyNotifySink;
#endif 	/* __IPropertyNotifySink_FWD_DEFINED__ */


#ifndef __ISpecifyPropertyPages_FWD_DEFINED__
#define __ISpecifyPropertyPages_FWD_DEFINED__
typedef interface ISpecifyPropertyPages ISpecifyPropertyPages;
#endif 	/* __ISpecifyPropertyPages_FWD_DEFINED__ */


#ifndef __IPersistMemory_FWD_DEFINED__
#define __IPersistMemory_FWD_DEFINED__
typedef interface IPersistMemory IPersistMemory;
#endif 	/* __IPersistMemory_FWD_DEFINED__ */


#ifndef __IPersistStreamInit_FWD_DEFINED__
#define __IPersistStreamInit_FWD_DEFINED__
typedef interface IPersistStreamInit IPersistStreamInit;
#endif 	/* __IPersistStreamInit_FWD_DEFINED__ */


#ifndef __IPersistPropertyBag_FWD_DEFINED__
#define __IPersistPropertyBag_FWD_DEFINED__
typedef interface IPersistPropertyBag IPersistPropertyBag;
#endif 	/* __IPersistPropertyBag_FWD_DEFINED__ */


#ifndef __ISimpleFrameSite_FWD_DEFINED__
#define __ISimpleFrameSite_FWD_DEFINED__
typedef interface ISimpleFrameSite ISimpleFrameSite;
#endif 	/* __ISimpleFrameSite_FWD_DEFINED__ */


#ifndef __IFont_FWD_DEFINED__
#define __IFont_FWD_DEFINED__
typedef interface IFont IFont;
#endif 	/* __IFont_FWD_DEFINED__ */


#ifndef __IPicture_FWD_DEFINED__
#define __IPicture_FWD_DEFINED__
typedef interface IPicture IPicture;
#endif 	/* __IPicture_FWD_DEFINED__ */


#ifndef __IFontDisp_FWD_DEFINED__
#define __IFontDisp_FWD_DEFINED__
typedef interface IFontDisp IFontDisp;
#endif 	/* __IFontDisp_FWD_DEFINED__ */


#ifndef __IPictureDisp_FWD_DEFINED__
#define __IPictureDisp_FWD_DEFINED__
typedef interface IPictureDisp IPictureDisp;
#endif 	/* __IPictureDisp_FWD_DEFINED__ */


#ifndef __IAdviseSinkEx_FWD_DEFINED__
#define __IAdviseSinkEx_FWD_DEFINED__
typedef interface IAdviseSinkEx IAdviseSinkEx;
#endif 	/* __IAdviseSinkEx_FWD_DEFINED__ */


#ifndef __IOleInPlaceObjectWindowless_FWD_DEFINED__
#define __IOleInPlaceObjectWindowless_FWD_DEFINED__
typedef interface IOleInPlaceObjectWindowless IOleInPlaceObjectWindowless;
#endif 	/* __IOleInPlaceObjectWindowless_FWD_DEFINED__ */


#ifndef __IOleInPlaceSiteEx_FWD_DEFINED__
#define __IOleInPlaceSiteEx_FWD_DEFINED__
typedef interface IOleInPlaceSiteEx IOleInPlaceSiteEx;
#endif 	/* __IOleInPlaceSiteEx_FWD_DEFINED__ */


#ifndef __IOleInPlaceSiteWindowless_FWD_DEFINED__
#define __IOleInPlaceSiteWindowless_FWD_DEFINED__
typedef interface IOleInPlaceSiteWindowless IOleInPlaceSiteWindowless;
#endif 	/* __IOleInPlaceSiteWindowless_FWD_DEFINED__ */


#ifndef __IViewObjectEx_FWD_DEFINED__
#define __IViewObjectEx_FWD_DEFINED__
typedef interface IViewObjectEx IViewObjectEx;
#endif 	/* __IViewObjectEx_FWD_DEFINED__ */


#ifndef __IOleUndoUnit_FWD_DEFINED__
#define __IOleUndoUnit_FWD_DEFINED__
typedef interface IOleUndoUnit IOleUndoUnit;
#endif 	/* __IOleUndoUnit_FWD_DEFINED__ */


#ifndef __IOleParentUndoUnit_FWD_DEFINED__
#define __IOleParentUndoUnit_FWD_DEFINED__
typedef interface IOleParentUndoUnit IOleParentUndoUnit;
#endif 	/* __IOleParentUndoUnit_FWD_DEFINED__ */


#ifndef __IEnumOleUndoUnits_FWD_DEFINED__
#define __IEnumOleUndoUnits_FWD_DEFINED__
typedef interface IEnumOleUndoUnits IEnumOleUndoUnits;
#endif 	/* __IEnumOleUndoUnits_FWD_DEFINED__ */


#ifndef __IOleUndoManager_FWD_DEFINED__
#define __IOleUndoManager_FWD_DEFINED__
typedef interface IOleUndoManager IOleUndoManager;
#endif 	/* __IOleUndoManager_FWD_DEFINED__ */


#ifndef __IQuickActivate_FWD_DEFINED__
#define __IQuickActivate_FWD_DEFINED__
typedef interface IQuickActivate IQuickActivate;
#endif 	/* __IQuickActivate_FWD_DEFINED__ */


#ifndef __IPointerInactive_FWD_DEFINED__
#define __IPointerInactive_FWD_DEFINED__
typedef interface IPointerInactive IPointerInactive;
#endif 	/* __IPointerInactive_FWD_DEFINED__ */


#ifndef __IObjectWithSite_FWD_DEFINED__
#define __IObjectWithSite_FWD_DEFINED__
typedef interface IObjectWithSite IObjectWithSite;
#endif 	/* __IObjectWithSite_FWD_DEFINED__ */


#ifndef __IErrorLog_FWD_DEFINED__
#define __IErrorLog_FWD_DEFINED__
typedef interface IErrorLog IErrorLog;
#endif 	/* __IErrorLog_FWD_DEFINED__ */


#ifndef __IPropertyBag_FWD_DEFINED__
#define __IPropertyBag_FWD_DEFINED__
typedef interface IPropertyBag IPropertyBag;
#endif 	/* __IPropertyBag_FWD_DEFINED__ */


#ifndef __IPerPropertyBrowsing_FWD_DEFINED__
#define __IPerPropertyBrowsing_FWD_DEFINED__
typedef interface IPerPropertyBrowsing IPerPropertyBrowsing;
#endif 	/* __IPerPropertyBrowsing_FWD_DEFINED__ */


/* header files for imported files */
#include "oleidl.h"
#include "oaidl.h"

void  * __stdcall MIDL_user_allocate(size_t);
void __stdcall MIDL_user_free( void  * ); 

/****************************************
 * Generated header for interface: __MIDL__intf_0000
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [local] */ 


//+-------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (C) Microsoft Corporation, 1993 - 1996.
//
//--------------------------------------------------------------------------







































extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_s_ifspec;

#ifndef __IOleControlTypes_INTERFACE_DEFINED__
#define __IOleControlTypes_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOleControlTypes
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [auto_handle][unique][version] */ 


typedef /* [v1_enum] */ 
enum tagUASFLAGS
    {	UAS_NORMAL	= 0,
	UAS_BLOCKED	= 0x1,
	UAS_NOPARENTENABLE	= 0x2,
	UAS_MASK	= 0x3
    }	UASFLAGS;

/* State values for the DISPID_READYSTATE property */
typedef /* [v1_enum] */ 
enum tagREADYSTATE
    {	READYSTATE_UNINITIALIZED	= 0,
	READYSTATE_LOADING	= 1,
	READYSTATE_LOADED	= 2,
	READYSTATE_INTERACTIVE	= 3,
	READYSTATE_COMPLETE	= 4
    }	READYSTATE;

typedef /* [represent_as] */ struct  tagUserHWND
    {
    wireHWND pRemHwnd;
    }	UserHWND;

typedef /* [represent_as] */ struct tagUserHWND UserHACCEL;

typedef /* [represent_as] */ struct tagUserHWND UserHDC;

typedef /* [represent_as] */ struct tagUserHWND UserHFONT;

typedef /* [represent_as] */ struct  tagUserMSG
    {
    wireHWND pRemHwnd;
    UINT message;
    WPARAM wParam;
    LPARAM lParam;
    unsigned long time;
    POINT pt;
    }	UserMSG;

typedef /* [represent_as] */ struct  tagUserBSTR
    {
    wireBSTR pBstrBlob;
    }	UserBSTR;

typedef struct  tagVARIANT_BLOB
    {
    unsigned long clSize;
    unsigned long rpcReserved;
    /* [size_is] */ ULONGLONG ahData[ 1 ];
    }	 *wireVARIANT_BLOB;

typedef /* [represent_as] */ struct  tagUserVARIANT
    {
    wireVARIANT_BLOB pVarBlob;
    }	UserVARIANT;

typedef /* [represent_as] */ struct  tagUserEXCEPINFO
    {
    WORD wCode;
    WORD wReserved;
    wireBSTR bstrSource;
    wireBSTR bstrDescription;
    wireBSTR bstrHelpFile;
    unsigned long dwHelpContext;
    unsigned long pvReserved;
    unsigned long pfnDeferredFillIn;
    SCODE scode;
    }	UserEXCEPINFO;



extern RPC_IF_HANDLE IOleControlTypes_v1_0_c_ifspec;
extern RPC_IF_HANDLE IOleControlTypes_v1_0_s_ifspec;
#endif /* __IOleControlTypes_INTERFACE_DEFINED__ */

#ifndef __IEnumConnections_INTERFACE_DEFINED__
#define __IEnumConnections_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumConnections
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef IEnumConnections  *PENUMCONNECTIONS;

typedef IEnumConnections  *LPENUMCONNECTIONS;

typedef struct  tagCONNECTDATA
    {
    IUnknown  *pUnk;
    unsigned long dwCookie;
    }	CONNECTDATA;

typedef struct tagCONNECTDATA  *PCONNECTDATA;

typedef struct tagCONNECTDATA  *LPCONNECTDATA;


EXTERN_C const IID IID_IEnumConnections;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IEnumConnections : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT __stdcall Next( 
            /* [in] */ unsigned long cConnections,
            /* [length_is][size_is][out] */ LPCONNECTDATA rgcd,
            /* [out] */ unsigned long  *pcFetched) = 0;
        
        virtual HRESULT __stdcall Skip( 
            /* [in] */ unsigned long cConnections) = 0;
        
        virtual HRESULT __stdcall Reset( void) = 0;
        
        virtual HRESULT __stdcall Clone( 
            /* [out] */ IEnumConnections  * *ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumConnectionsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IEnumConnections  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IEnumConnections  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IEnumConnections  * This);
        
        /* [local] */ HRESULT ( __stdcall  *Next )( 
            IEnumConnections  * This,
            /* [in] */ unsigned long cConnections,
            /* [length_is][size_is][out] */ LPCONNECTDATA rgcd,
            /* [out] */ unsigned long  *pcFetched);
        
        HRESULT ( __stdcall  *Skip )( 
            IEnumConnections  * This,
            /* [in] */ unsigned long cConnections);
        
        HRESULT ( __stdcall  *Reset )( 
            IEnumConnections  * This);
        
        HRESULT ( __stdcall  *Clone )( 
            IEnumConnections  * This,
            /* [out] */ IEnumConnections  * *ppEnum);
        
        END_INTERFACE
    } IEnumConnectionsVtbl;

    interface IEnumConnections
    {
        CONST_VTBL struct IEnumConnectionsVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumConnections_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumConnections_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumConnections_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumConnections_Next(This,cConnections,rgcd,pcFetched)	\
    (This)->lpVtbl -> Next(This,cConnections,rgcd,pcFetched)

#define IEnumConnections_Skip(This,cConnections)	\
    (This)->lpVtbl -> Skip(This,cConnections)

#define IEnumConnections_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumConnections_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall IEnumConnections_RemoteNext_Proxy( 
    IEnumConnections  * This,
    /* [in] */ unsigned long cConnections,
    /* [length_is][size_is][out] */ LPCONNECTDATA rgcd,
    /* [out] */ unsigned long  *pcFetched);


void __stdcall IEnumConnections_RemoteNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumConnections_Skip_Proxy( 
    IEnumConnections  * This,
    /* [in] */ unsigned long cConnections);


void __stdcall IEnumConnections_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumConnections_Reset_Proxy( 
    IEnumConnections  * This);


void __stdcall IEnumConnections_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumConnections_Clone_Proxy( 
    IEnumConnections  * This,
    /* [out] */ IEnumConnections  * *ppEnum);


void __stdcall IEnumConnections_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IEnumConnections_INTERFACE_DEFINED__ */


#ifndef __IConnectionPoint_INTERFACE_DEFINED__
#define __IConnectionPoint_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IConnectionPoint
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef IConnectionPoint  *PCONNECTIONPOINT;

typedef IConnectionPoint  *LPCONNECTIONPOINT;


EXTERN_C const IID IID_IConnectionPoint;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IConnectionPoint : public IUnknown
    {
    public:
        virtual HRESULT __stdcall GetConnectionInterface( 
            /* [out] */ IID  *pIID) = 0;
        
        virtual HRESULT __stdcall GetConnectionPointContainer( 
            /* [out] */ IConnectionPointContainer  * *ppCPC) = 0;
        
        virtual HRESULT __stdcall Advise( 
            /* [in] */ IUnknown  *pUnkSink,
            /* [out] */ unsigned long  *pdwCookie) = 0;
        
        virtual HRESULT __stdcall Unadvise( 
            /* [in] */ unsigned long dwCookie) = 0;
        
        virtual HRESULT __stdcall EnumConnections( 
            /* [out] */ IEnumConnections  * *ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IConnectionPointVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IConnectionPoint  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IConnectionPoint  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IConnectionPoint  * This);
        
        HRESULT ( __stdcall  *GetConnectionInterface )( 
            IConnectionPoint  * This,
            /* [out] */ IID  *pIID);
        
        HRESULT ( __stdcall  *GetConnectionPointContainer )( 
            IConnectionPoint  * This,
            /* [out] */ IConnectionPointContainer  * *ppCPC);
        
        HRESULT ( __stdcall  *Advise )( 
            IConnectionPoint  * This,
            /* [in] */ IUnknown  *pUnkSink,
            /* [out] */ unsigned long  *pdwCookie);
        
        HRESULT ( __stdcall  *Unadvise )( 
            IConnectionPoint  * This,
            /* [in] */ unsigned long dwCookie);
        
        HRESULT ( __stdcall  *EnumConnections )( 
            IConnectionPoint  * This,
            /* [out] */ IEnumConnections  * *ppEnum);
        
        END_INTERFACE
    } IConnectionPointVtbl;

    interface IConnectionPoint
    {
        CONST_VTBL struct IConnectionPointVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IConnectionPoint_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IConnectionPoint_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IConnectionPoint_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IConnectionPoint_GetConnectionInterface(This,pIID)	\
    (This)->lpVtbl -> GetConnectionInterface(This,pIID)

#define IConnectionPoint_GetConnectionPointContainer(This,ppCPC)	\
    (This)->lpVtbl -> GetConnectionPointContainer(This,ppCPC)

#define IConnectionPoint_Advise(This,pUnkSink,pdwCookie)	\
    (This)->lpVtbl -> Advise(This,pUnkSink,pdwCookie)

#define IConnectionPoint_Unadvise(This,dwCookie)	\
    (This)->lpVtbl -> Unadvise(This,dwCookie)

#define IConnectionPoint_EnumConnections(This,ppEnum)	\
    (This)->lpVtbl -> EnumConnections(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IConnectionPoint_GetConnectionInterface_Proxy( 
    IConnectionPoint  * This,
    /* [out] */ IID  *pIID);


void __stdcall IConnectionPoint_GetConnectionInterface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IConnectionPoint_GetConnectionPointContainer_Proxy( 
    IConnectionPoint  * This,
    /* [out] */ IConnectionPointContainer  * *ppCPC);


void __stdcall IConnectionPoint_GetConnectionPointContainer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IConnectionPoint_Advise_Proxy( 
    IConnectionPoint  * This,
    /* [in] */ IUnknown  *pUnkSink,
    /* [out] */ unsigned long  *pdwCookie);


void __stdcall IConnectionPoint_Advise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IConnectionPoint_Unadvise_Proxy( 
    IConnectionPoint  * This,
    /* [in] */ unsigned long dwCookie);


void __stdcall IConnectionPoint_Unadvise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IConnectionPoint_EnumConnections_Proxy( 
    IConnectionPoint  * This,
    /* [out] */ IEnumConnections  * *ppEnum);


void __stdcall IConnectionPoint_EnumConnections_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IConnectionPoint_INTERFACE_DEFINED__ */


#ifndef __IEnumConnectionPoints_INTERFACE_DEFINED__
#define __IEnumConnectionPoints_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumConnectionPoints
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef IEnumConnectionPoints  *PENUMCONNECTIONPOINTS;

typedef IEnumConnectionPoints  *LPENUMCONNECTIONPOINTS;


EXTERN_C const IID IID_IEnumConnectionPoints;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IEnumConnectionPoints : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT __stdcall Next( 
            /* [in] */ unsigned long cConnections,
            /* [length_is][size_is][out] */ LPCONNECTIONPOINT  *ppCP,
            /* [out] */ unsigned long  *pcFetched) = 0;
        
        virtual HRESULT __stdcall Skip( 
            /* [in] */ unsigned long cConnections) = 0;
        
        virtual HRESULT __stdcall Reset( void) = 0;
        
        virtual HRESULT __stdcall Clone( 
            /* [out] */ IEnumConnectionPoints  * *ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumConnectionPointsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IEnumConnectionPoints  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IEnumConnectionPoints  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IEnumConnectionPoints  * This);
        
        /* [local] */ HRESULT ( __stdcall  *Next )( 
            IEnumConnectionPoints  * This,
            /* [in] */ unsigned long cConnections,
            /* [length_is][size_is][out] */ LPCONNECTIONPOINT  *ppCP,
            /* [out] */ unsigned long  *pcFetched);
        
        HRESULT ( __stdcall  *Skip )( 
            IEnumConnectionPoints  * This,
            /* [in] */ unsigned long cConnections);
        
        HRESULT ( __stdcall  *Reset )( 
            IEnumConnectionPoints  * This);
        
        HRESULT ( __stdcall  *Clone )( 
            IEnumConnectionPoints  * This,
            /* [out] */ IEnumConnectionPoints  * *ppEnum);
        
        END_INTERFACE
    } IEnumConnectionPointsVtbl;

    interface IEnumConnectionPoints
    {
        CONST_VTBL struct IEnumConnectionPointsVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumConnectionPoints_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumConnectionPoints_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumConnectionPoints_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumConnectionPoints_Next(This,cConnections,ppCP,pcFetched)	\
    (This)->lpVtbl -> Next(This,cConnections,ppCP,pcFetched)

#define IEnumConnectionPoints_Skip(This,cConnections)	\
    (This)->lpVtbl -> Skip(This,cConnections)

#define IEnumConnectionPoints_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumConnectionPoints_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall IEnumConnectionPoints_RemoteNext_Proxy( 
    IEnumConnectionPoints  * This,
    /* [in] */ unsigned long cConnections,
    /* [length_is][size_is][out] */ LPCONNECTIONPOINT  *ppCP,
    /* [out] */ unsigned long  *pcFetched);


void __stdcall IEnumConnectionPoints_RemoteNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumConnectionPoints_Skip_Proxy( 
    IEnumConnectionPoints  * This,
    /* [in] */ unsigned long cConnections);


void __stdcall IEnumConnectionPoints_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumConnectionPoints_Reset_Proxy( 
    IEnumConnectionPoints  * This);


void __stdcall IEnumConnectionPoints_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumConnectionPoints_Clone_Proxy( 
    IEnumConnectionPoints  * This,
    /* [out] */ IEnumConnectionPoints  * *ppEnum);


void __stdcall IEnumConnectionPoints_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IEnumConnectionPoints_INTERFACE_DEFINED__ */


#ifndef __IConnectionPointContainer_INTERFACE_DEFINED__
#define __IConnectionPointContainer_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IConnectionPointContainer
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef IConnectionPointContainer  *PCONNECTIONPOINTCONTAINER;

typedef IConnectionPointContainer  *LPCONNECTIONPOINTCONTAINER;


EXTERN_C const IID IID_IConnectionPointContainer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IConnectionPointContainer : public IUnknown
    {
    public:
        virtual HRESULT __stdcall EnumConnectionPoints( 
            /* [out] */ IEnumConnectionPoints  * *ppEnum) = 0;
        
        virtual HRESULT __stdcall FindConnectionPoint( 
            /* [in] */ REFIID riid,
            /* [out] */ IConnectionPoint  * *ppCP) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IConnectionPointContainerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IConnectionPointContainer  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IConnectionPointContainer  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IConnectionPointContainer  * This);
        
        HRESULT ( __stdcall  *EnumConnectionPoints )( 
            IConnectionPointContainer  * This,
            /* [out] */ IEnumConnectionPoints  * *ppEnum);
        
        HRESULT ( __stdcall  *FindConnectionPoint )( 
            IConnectionPointContainer  * This,
            /* [in] */ REFIID riid,
            /* [out] */ IConnectionPoint  * *ppCP);
        
        END_INTERFACE
    } IConnectionPointContainerVtbl;

    interface IConnectionPointContainer
    {
        CONST_VTBL struct IConnectionPointContainerVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IConnectionPointContainer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IConnectionPointContainer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IConnectionPointContainer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IConnectionPointContainer_EnumConnectionPoints(This,ppEnum)	\
    (This)->lpVtbl -> EnumConnectionPoints(This,ppEnum)

#define IConnectionPointContainer_FindConnectionPoint(This,riid,ppCP)	\
    (This)->lpVtbl -> FindConnectionPoint(This,riid,ppCP)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IConnectionPointContainer_EnumConnectionPoints_Proxy( 
    IConnectionPointContainer  * This,
    /* [out] */ IEnumConnectionPoints  * *ppEnum);


void __stdcall IConnectionPointContainer_EnumConnectionPoints_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IConnectionPointContainer_FindConnectionPoint_Proxy( 
    IConnectionPointContainer  * This,
    /* [in] */ REFIID riid,
    /* [out] */ IConnectionPoint  * *ppCP);


void __stdcall IConnectionPointContainer_FindConnectionPoint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IConnectionPointContainer_INTERFACE_DEFINED__ */


#ifndef __IClassFactory2_INTERFACE_DEFINED__
#define __IClassFactory2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IClassFactory2
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef IClassFactory2  *LPCLASSFACTORY2;

typedef struct  tagLICINFO
    {
    LONG cbLicInfo;
    BOOL fRuntimeKeyAvail;
    BOOL fLicVerified;
    }	LICINFO;

typedef struct tagLICINFO  *LPLICINFO;


EXTERN_C const IID IID_IClassFactory2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IClassFactory2 : public IClassFactory
    {
    public:
        virtual HRESULT __stdcall GetLicInfo( 
            /* [out] */ LICINFO  *pLicInfo) = 0;
        
        virtual HRESULT __stdcall RequestLicKey( 
            /* [in] */ unsigned long dwReserved,
            /* [out] */ BSTR  *pBstrKey) = 0;
        
        virtual /* [local] */ HRESULT __stdcall CreateInstanceLic( 
            /* [in] */ IUnknown  *pUnkOuter,
            /* [in] */ IUnknown  *pUnkReserved,
            /* [in] */ REFIID riid,
            /* [in] */ BSTR bstrKey,
            /* [iid_is][out] */ void*  *ppvObj) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClassFactory2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IClassFactory2  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IClassFactory2  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IClassFactory2  * This);
        
        /* [local] */ HRESULT ( __stdcall  *CreateInstance )( 
            IClassFactory2  * This,
            /* [unique][in] */ IUnknown  *pUnkOuter,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        /* [local] */ HRESULT ( __stdcall  *LockServer )( 
            IClassFactory2  * This,
            /* [in] */ BOOL fLock);
        
        HRESULT ( __stdcall  *GetLicInfo )( 
            IClassFactory2  * This,
            /* [out] */ LICINFO  *pLicInfo);
        
        HRESULT ( __stdcall  *RequestLicKey )( 
            IClassFactory2  * This,
            /* [in] */ unsigned long dwReserved,
            /* [out] */ BSTR  *pBstrKey);
        
        /* [local] */ HRESULT ( __stdcall  *CreateInstanceLic )( 
            IClassFactory2  * This,
            /* [in] */ IUnknown  *pUnkOuter,
            /* [in] */ IUnknown  *pUnkReserved,
            /* [in] */ REFIID riid,
            /* [in] */ BSTR bstrKey,
            /* [iid_is][out] */ void*  *ppvObj);
        
        END_INTERFACE
    } IClassFactory2Vtbl;

    interface IClassFactory2
    {
        CONST_VTBL struct IClassFactory2Vtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClassFactory2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClassFactory2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClassFactory2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClassFactory2_CreateInstance(This,pUnkOuter,riid,ppvObject)	\
    (This)->lpVtbl -> CreateInstance(This,pUnkOuter,riid,ppvObject)

#define IClassFactory2_LockServer(This,fLock)	\
    (This)->lpVtbl -> LockServer(This,fLock)


#define IClassFactory2_GetLicInfo(This,pLicInfo)	\
    (This)->lpVtbl -> GetLicInfo(This,pLicInfo)

#define IClassFactory2_RequestLicKey(This,dwReserved,pBstrKey)	\
    (This)->lpVtbl -> RequestLicKey(This,dwReserved,pBstrKey)

#define IClassFactory2_CreateInstanceLic(This,pUnkOuter,pUnkReserved,riid,bstrKey,ppvObj)	\
    (This)->lpVtbl -> CreateInstanceLic(This,pUnkOuter,pUnkReserved,riid,bstrKey,ppvObj)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IClassFactory2_GetLicInfo_Proxy( 
    IClassFactory2  * This,
    /* [out] */ LICINFO  *pLicInfo);


void __stdcall IClassFactory2_GetLicInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IClassFactory2_RequestLicKey_Proxy( 
    IClassFactory2  * This,
    /* [in] */ unsigned long dwReserved,
    /* [out] */ BSTR  *pBstrKey);


void __stdcall IClassFactory2_RequestLicKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall IClassFactory2_RemoteCreateInstanceLic_Proxy( 
    IClassFactory2  * This,
    /* [in] */ REFIID riid,
    /* [in] */ BSTR bstrKey,
    /* [iid_is][out] */ IUnknown  * *ppvObj);


void __stdcall IClassFactory2_RemoteCreateInstanceLic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IClassFactory2_INTERFACE_DEFINED__ */


#ifndef __IProvideClassInfo_INTERFACE_DEFINED__
#define __IProvideClassInfo_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IProvideClassInfo
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef IProvideClassInfo  *LPPROVIDECLASSINFO;


EXTERN_C const IID IID_IProvideClassInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IProvideClassInfo : public IUnknown
    {
    public:
        virtual HRESULT __stdcall GetClassInfo( 
            /* [out] */ ITypeInfo  * *ppTI) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IProvideClassInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IProvideClassInfo  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IProvideClassInfo  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IProvideClassInfo  * This);
        
        HRESULT ( __stdcall  *GetClassInfo )( 
            IProvideClassInfo  * This,
            /* [out] */ ITypeInfo  * *ppTI);
        
        END_INTERFACE
    } IProvideClassInfoVtbl;

    interface IProvideClassInfo
    {
        CONST_VTBL struct IProvideClassInfoVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IProvideClassInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IProvideClassInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IProvideClassInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IProvideClassInfo_GetClassInfo(This,ppTI)	\
    (This)->lpVtbl -> GetClassInfo(This,ppTI)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IProvideClassInfo_GetClassInfo_Proxy( 
    IProvideClassInfo  * This,
    /* [out] */ ITypeInfo  * *ppTI);


void __stdcall IProvideClassInfo_GetClassInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IProvideClassInfo_INTERFACE_DEFINED__ */


#ifndef __IProvideClassInfo2_INTERFACE_DEFINED__
#define __IProvideClassInfo2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IProvideClassInfo2
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef IProvideClassInfo2  *LPPROVIDECLASSINFO2;

typedef 
enum tagGUIDKIND
    {	GUIDKIND_DEFAULT_SOURCE_DISP_IID	= 1
    }	GUIDKIND;


EXTERN_C const IID IID_IProvideClassInfo2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IProvideClassInfo2 : public IProvideClassInfo
    {
    public:
        virtual HRESULT __stdcall GetGUID( 
            /* [in] */ unsigned long dwGuidKind,
            /* [out] */ GUID  *pGUID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IProvideClassInfo2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IProvideClassInfo2  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IProvideClassInfo2  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IProvideClassInfo2  * This);
        
        HRESULT ( __stdcall  *GetClassInfo )( 
            IProvideClassInfo2  * This,
            /* [out] */ ITypeInfo  * *ppTI);
        
        HRESULT ( __stdcall  *GetGUID )( 
            IProvideClassInfo2  * This,
            /* [in] */ unsigned long dwGuidKind,
            /* [out] */ GUID  *pGUID);
        
        END_INTERFACE
    } IProvideClassInfo2Vtbl;

    interface IProvideClassInfo2
    {
        CONST_VTBL struct IProvideClassInfo2Vtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IProvideClassInfo2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IProvideClassInfo2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IProvideClassInfo2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IProvideClassInfo2_GetClassInfo(This,ppTI)	\
    (This)->lpVtbl -> GetClassInfo(This,ppTI)


#define IProvideClassInfo2_GetGUID(This,dwGuidKind,pGUID)	\
    (This)->lpVtbl -> GetGUID(This,dwGuidKind,pGUID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IProvideClassInfo2_GetGUID_Proxy( 
    IProvideClassInfo2  * This,
    /* [in] */ unsigned long dwGuidKind,
    /* [out] */ GUID  *pGUID);


void __stdcall IProvideClassInfo2_GetGUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IProvideClassInfo2_INTERFACE_DEFINED__ */


#ifndef __IOleControl_INTERFACE_DEFINED__
#define __IOleControl_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOleControl
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef IOleControl  *LPOLECONTROL;

typedef struct  tagCONTROLINFO
    {
    unsigned long cb;
    HACCEL hAccel;
    USHORT cAccel;
    unsigned long dwFlags;
    }	CONTROLINFO;

typedef struct tagCONTROLINFO  *LPCONTROLINFO;

typedef 
enum tagCTRLINFO
    {	CTRLINFO_EATS_RETURN	= 1,
	CTRLINFO_EATS_ESCAPE	= 2
    }	CTRLINFO;


EXTERN_C const IID IID_IOleControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IOleControl : public IUnknown
    {
    public:
        virtual HRESULT __stdcall GetControlInfo( 
            /* [out] */ CONTROLINFO  *pCI) = 0;
        
        virtual HRESULT __stdcall OnMnemonic( 
            /* [in] */ MSG  *pMsg) = 0;
        
        virtual HRESULT __stdcall OnAmbientPropertyChange( 
            /* [in] */ DISPID dispID) = 0;
        
        virtual HRESULT __stdcall FreezeEvents( 
            /* [in] */ BOOL bFreeze) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOleControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IOleControl  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IOleControl  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IOleControl  * This);
        
        HRESULT ( __stdcall  *GetControlInfo )( 
            IOleControl  * This,
            /* [out] */ CONTROLINFO  *pCI);
        
        HRESULT ( __stdcall  *OnMnemonic )( 
            IOleControl  * This,
            /* [in] */ MSG  *pMsg);
        
        HRESULT ( __stdcall  *OnAmbientPropertyChange )( 
            IOleControl  * This,
            /* [in] */ DISPID dispID);
        
        HRESULT ( __stdcall  *FreezeEvents )( 
            IOleControl  * This,
            /* [in] */ BOOL bFreeze);
        
        END_INTERFACE
    } IOleControlVtbl;

    interface IOleControl
    {
        CONST_VTBL struct IOleControlVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleControl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOleControl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOleControl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOleControl_GetControlInfo(This,pCI)	\
    (This)->lpVtbl -> GetControlInfo(This,pCI)

#define IOleControl_OnMnemonic(This,pMsg)	\
    (This)->lpVtbl -> OnMnemonic(This,pMsg)

#define IOleControl_OnAmbientPropertyChange(This,dispID)	\
    (This)->lpVtbl -> OnAmbientPropertyChange(This,dispID)

#define IOleControl_FreezeEvents(This,bFreeze)	\
    (This)->lpVtbl -> FreezeEvents(This,bFreeze)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IOleControl_GetControlInfo_Proxy( 
    IOleControl  * This,
    /* [out] */ CONTROLINFO  *pCI);


void __stdcall IOleControl_GetControlInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleControl_OnMnemonic_Proxy( 
    IOleControl  * This,
    /* [in] */ MSG  *pMsg);


void __stdcall IOleControl_OnMnemonic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleControl_OnAmbientPropertyChange_Proxy( 
    IOleControl  * This,
    /* [in] */ DISPID dispID);


void __stdcall IOleControl_OnAmbientPropertyChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleControl_FreezeEvents_Proxy( 
    IOleControl  * This,
    /* [in] */ BOOL bFreeze);


void __stdcall IOleControl_FreezeEvents_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IOleControl_INTERFACE_DEFINED__ */


#ifndef __IOleControlSite_INTERFACE_DEFINED__
#define __IOleControlSite_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOleControlSite
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef IOleControlSite  *LPOLECONTROLSITE;

typedef struct  tagPOINTF
    {
    FLOAT x;
    FLOAT y;
    }	POINTF;

typedef struct tagPOINTF  *LPPOINTF;

typedef 
enum tagXFORMCOORDS
    {	XFORMCOORDS_POSITION	= 0x1,
	XFORMCOORDS_SIZE	= 0x2,
	XFORMCOORDS_HIMETRICTOCONTAINER	= 0x4,
	XFORMCOORDS_CONTAINERTOHIMETRIC	= 0x8
    }	XFORMCOORDS;


EXTERN_C const IID IID_IOleControlSite;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IOleControlSite : public IUnknown
    {
    public:
        virtual HRESULT __stdcall OnControlInfoChanged( void) = 0;
        
        virtual HRESULT __stdcall LockInPlaceActive( 
            /* [in] */ BOOL fLock) = 0;
        
        virtual HRESULT __stdcall GetExtendedControl( 
            /* [out] */ IDispatch  * *ppDisp) = 0;
        
        virtual HRESULT __stdcall TransformCoords( 
            /* [out][in] */ POINTL  *pPtlHimetric,
            /* [out][in] */ POINTF  *pPtfContainer,
            /* [in] */ unsigned long dwFlags) = 0;
        
        virtual HRESULT __stdcall TranslateAccelerator( 
            /* [in] */ MSG  *pMsg,
            /* [in] */ unsigned long grfModifiers) = 0;
        
        virtual HRESULT __stdcall OnFocus( 
            /* [in] */ BOOL fGotFocus) = 0;
        
        virtual HRESULT __stdcall ShowPropertyFrame( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOleControlSiteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IOleControlSite  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IOleControlSite  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IOleControlSite  * This);
        
        HRESULT ( __stdcall  *OnControlInfoChanged )( 
            IOleControlSite  * This);
        
        HRESULT ( __stdcall  *LockInPlaceActive )( 
            IOleControlSite  * This,
            /* [in] */ BOOL fLock);
        
        HRESULT ( __stdcall  *GetExtendedControl )( 
            IOleControlSite  * This,
            /* [out] */ IDispatch  * *ppDisp);
        
        HRESULT ( __stdcall  *TransformCoords )( 
            IOleControlSite  * This,
            /* [out][in] */ POINTL  *pPtlHimetric,
            /* [out][in] */ POINTF  *pPtfContainer,
            /* [in] */ unsigned long dwFlags);
        
        HRESULT ( __stdcall  *TranslateAccelerator )( 
            IOleControlSite  * This,
            /* [in] */ MSG  *pMsg,
            /* [in] */ unsigned long grfModifiers);
        
        HRESULT ( __stdcall  *OnFocus )( 
            IOleControlSite  * This,
            /* [in] */ BOOL fGotFocus);
        
        HRESULT ( __stdcall  *ShowPropertyFrame )( 
            IOleControlSite  * This);
        
        END_INTERFACE
    } IOleControlSiteVtbl;

    interface IOleControlSite
    {
        CONST_VTBL struct IOleControlSiteVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleControlSite_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOleControlSite_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOleControlSite_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOleControlSite_OnControlInfoChanged(This)	\
    (This)->lpVtbl -> OnControlInfoChanged(This)

#define IOleControlSite_LockInPlaceActive(This,fLock)	\
    (This)->lpVtbl -> LockInPlaceActive(This,fLock)

#define IOleControlSite_GetExtendedControl(This,ppDisp)	\
    (This)->lpVtbl -> GetExtendedControl(This,ppDisp)

#define IOleControlSite_TransformCoords(This,pPtlHimetric,pPtfContainer,dwFlags)	\
    (This)->lpVtbl -> TransformCoords(This,pPtlHimetric,pPtfContainer,dwFlags)

#define IOleControlSite_TranslateAccelerator(This,pMsg,grfModifiers)	\
    (This)->lpVtbl -> TranslateAccelerator(This,pMsg,grfModifiers)

#define IOleControlSite_OnFocus(This,fGotFocus)	\
    (This)->lpVtbl -> OnFocus(This,fGotFocus)

#define IOleControlSite_ShowPropertyFrame(This)	\
    (This)->lpVtbl -> ShowPropertyFrame(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IOleControlSite_OnControlInfoChanged_Proxy( 
    IOleControlSite  * This);


void __stdcall IOleControlSite_OnControlInfoChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleControlSite_LockInPlaceActive_Proxy( 
    IOleControlSite  * This,
    /* [in] */ BOOL fLock);


void __stdcall IOleControlSite_LockInPlaceActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleControlSite_GetExtendedControl_Proxy( 
    IOleControlSite  * This,
    /* [out] */ IDispatch  * *ppDisp);


void __stdcall IOleControlSite_GetExtendedControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleControlSite_TransformCoords_Proxy( 
    IOleControlSite  * This,
    /* [out][in] */ POINTL  *pPtlHimetric,
    /* [out][in] */ POINTF  *pPtfContainer,
    /* [in] */ unsigned long dwFlags);


void __stdcall IOleControlSite_TransformCoords_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleControlSite_TranslateAccelerator_Proxy( 
    IOleControlSite  * This,
    /* [in] */ MSG  *pMsg,
    /* [in] */ unsigned long grfModifiers);


void __stdcall IOleControlSite_TranslateAccelerator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleControlSite_OnFocus_Proxy( 
    IOleControlSite  * This,
    /* [in] */ BOOL fGotFocus);


void __stdcall IOleControlSite_OnFocus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleControlSite_ShowPropertyFrame_Proxy( 
    IOleControlSite  * This);


void __stdcall IOleControlSite_ShowPropertyFrame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IOleControlSite_INTERFACE_DEFINED__ */


#ifndef __IPropertyPage_INTERFACE_DEFINED__
#define __IPropertyPage_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPropertyPage
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef IPropertyPage  *LPPROPERTYPAGE;

typedef struct  tagPROPPAGEINFO
    {
    unsigned long cb;
    LPOLESTR pszTitle;
    SIZE size;
    LPOLESTR pszDocString;
    LPOLESTR pszHelpFile;
    unsigned long dwHelpContext;
    }	PROPPAGEINFO;

typedef struct tagPROPPAGEINFO  *LPPROPPAGEINFO;


EXTERN_C const IID IID_IPropertyPage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IPropertyPage : public IUnknown
    {
    public:
        virtual HRESULT __stdcall SetPageSite( 
            /* [in] */ IPropertyPageSite  *pPageSite) = 0;
        
        virtual HRESULT __stdcall Activate( 
            /* [in] */ HWND hWndParent,
            /* [in] */ LPCRECT pRect,
            /* [in] */ BOOL bModal) = 0;
        
        virtual HRESULT __stdcall Deactivate( void) = 0;
        
        virtual HRESULT __stdcall GetPageInfo( 
            /* [out] */ PROPPAGEINFO  *pPageInfo) = 0;
        
        virtual HRESULT __stdcall SetObjects( 
            /* [in] */ unsigned long cObjects,
            /* [size_is][in] */ IUnknown  * *ppUnk) = 0;
        
        virtual HRESULT __stdcall Show( 
            /* [in] */ UINT nCmdShow) = 0;
        
        virtual HRESULT __stdcall Move( 
            /* [in] */ LPCRECT pRect) = 0;
        
        virtual HRESULT __stdcall IsPageDirty( void) = 0;
        
        virtual HRESULT __stdcall Apply( void) = 0;
        
        virtual HRESULT __stdcall Help( 
            /* [in] */ LPCOLESTR pszHelpDir) = 0;
        
        virtual HRESULT __stdcall TranslateAccelerator( 
            /* [in] */ MSG  *pMsg) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPropertyPageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IPropertyPage  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IPropertyPage  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IPropertyPage  * This);
        
        HRESULT ( __stdcall  *SetPageSite )( 
            IPropertyPage  * This,
            /* [in] */ IPropertyPageSite  *pPageSite);
        
        HRESULT ( __stdcall  *Activate )( 
            IPropertyPage  * This,
            /* [in] */ HWND hWndParent,
            /* [in] */ LPCRECT pRect,
            /* [in] */ BOOL bModal);
        
        HRESULT ( __stdcall  *Deactivate )( 
            IPropertyPage  * This);
        
        HRESULT ( __stdcall  *GetPageInfo )( 
            IPropertyPage  * This,
            /* [out] */ PROPPAGEINFO  *pPageInfo);
        
        HRESULT ( __stdcall  *SetObjects )( 
            IPropertyPage  * This,
            /* [in] */ unsigned long cObjects,
            /* [size_is][in] */ IUnknown  * *ppUnk);
        
        HRESULT ( __stdcall  *Show )( 
            IPropertyPage  * This,
            /* [in] */ UINT nCmdShow);
        
        HRESULT ( __stdcall  *Move )( 
            IPropertyPage  * This,
            /* [in] */ LPCRECT pRect);
        
        HRESULT ( __stdcall  *IsPageDirty )( 
            IPropertyPage  * This);
        
        HRESULT ( __stdcall  *Apply )( 
            IPropertyPage  * This);
        
        HRESULT ( __stdcall  *Help )( 
            IPropertyPage  * This,
            /* [in] */ LPCOLESTR pszHelpDir);
        
        HRESULT ( __stdcall  *TranslateAccelerator )( 
            IPropertyPage  * This,
            /* [in] */ MSG  *pMsg);
        
        END_INTERFACE
    } IPropertyPageVtbl;

    interface IPropertyPage
    {
        CONST_VTBL struct IPropertyPageVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPropertyPage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPropertyPage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPropertyPage_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPropertyPage_SetPageSite(This,pPageSite)	\
    (This)->lpVtbl -> SetPageSite(This,pPageSite)

#define IPropertyPage_Activate(This,hWndParent,pRect,bModal)	\
    (This)->lpVtbl -> Activate(This,hWndParent,pRect,bModal)

#define IPropertyPage_Deactivate(This)	\
    (This)->lpVtbl -> Deactivate(This)

#define IPropertyPage_GetPageInfo(This,pPageInfo)	\
    (This)->lpVtbl -> GetPageInfo(This,pPageInfo)

#define IPropertyPage_SetObjects(This,cObjects,ppUnk)	\
    (This)->lpVtbl -> SetObjects(This,cObjects,ppUnk)

#define IPropertyPage_Show(This,nCmdShow)	\
    (This)->lpVtbl -> Show(This,nCmdShow)

#define IPropertyPage_Move(This,pRect)	\
    (This)->lpVtbl -> Move(This,pRect)

#define IPropertyPage_IsPageDirty(This)	\
    (This)->lpVtbl -> IsPageDirty(This)

#define IPropertyPage_Apply(This)	\
    (This)->lpVtbl -> Apply(This)

#define IPropertyPage_Help(This,pszHelpDir)	\
    (This)->lpVtbl -> Help(This,pszHelpDir)

#define IPropertyPage_TranslateAccelerator(This,pMsg)	\
    (This)->lpVtbl -> TranslateAccelerator(This,pMsg)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPropertyPage_SetPageSite_Proxy( 
    IPropertyPage  * This,
    /* [in] */ IPropertyPageSite  *pPageSite);


void __stdcall IPropertyPage_SetPageSite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPropertyPage_Activate_Proxy( 
    IPropertyPage  * This,
    /* [in] */ HWND hWndParent,
    /* [in] */ LPCRECT pRect,
    /* [in] */ BOOL bModal);


void __stdcall IPropertyPage_Activate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPropertyPage_Deactivate_Proxy( 
    IPropertyPage  * This);


void __stdcall IPropertyPage_Deactivate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPropertyPage_GetPageInfo_Proxy( 
    IPropertyPage  * This,
    /* [out] */ PROPPAGEINFO  *pPageInfo);


void __stdcall IPropertyPage_GetPageInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPropertyPage_SetObjects_Proxy( 
    IPropertyPage  * This,
    /* [in] */ unsigned long cObjects,
    /* [size_is][in] */ IUnknown  * *ppUnk);


void __stdcall IPropertyPage_SetObjects_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPropertyPage_Show_Proxy( 
    IPropertyPage  * This,
    /* [in] */ UINT nCmdShow);


void __stdcall IPropertyPage_Show_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPropertyPage_Move_Proxy( 
    IPropertyPage  * This,
    /* [in] */ LPCRECT pRect);


void __stdcall IPropertyPage_Move_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPropertyPage_IsPageDirty_Proxy( 
    IPropertyPage  * This);


void __stdcall IPropertyPage_IsPageDirty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPropertyPage_Apply_Proxy( 
    IPropertyPage  * This);


void __stdcall IPropertyPage_Apply_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPropertyPage_Help_Proxy( 
    IPropertyPage  * This,
    /* [in] */ LPCOLESTR pszHelpDir);


void __stdcall IPropertyPage_Help_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPropertyPage_TranslateAccelerator_Proxy( 
    IPropertyPage  * This,
    /* [in] */ MSG  *pMsg);


void __stdcall IPropertyPage_TranslateAccelerator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IPropertyPage_INTERFACE_DEFINED__ */


#ifndef __IPropertyPage2_INTERFACE_DEFINED__
#define __IPropertyPage2_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPropertyPage2
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef IPropertyPage2  *LPPROPERTYPAGE2;


EXTERN_C const IID IID_IPropertyPage2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IPropertyPage2 : public IPropertyPage
    {
    public:
        virtual HRESULT __stdcall EditProperty( 
            /* [in] */ DISPID dispID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPropertyPage2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IPropertyPage2  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IPropertyPage2  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IPropertyPage2  * This);
        
        HRESULT ( __stdcall  *SetPageSite )( 
            IPropertyPage2  * This,
            /* [in] */ IPropertyPageSite  *pPageSite);
        
        HRESULT ( __stdcall  *Activate )( 
            IPropertyPage2  * This,
            /* [in] */ HWND hWndParent,
            /* [in] */ LPCRECT pRect,
            /* [in] */ BOOL bModal);
        
        HRESULT ( __stdcall  *Deactivate )( 
            IPropertyPage2  * This);
        
        HRESULT ( __stdcall  *GetPageInfo )( 
            IPropertyPage2  * This,
            /* [out] */ PROPPAGEINFO  *pPageInfo);
        
        HRESULT ( __stdcall  *SetObjects )( 
            IPropertyPage2  * This,
            /* [in] */ unsigned long cObjects,
            /* [size_is][in] */ IUnknown  * *ppUnk);
        
        HRESULT ( __stdcall  *Show )( 
            IPropertyPage2  * This,
            /* [in] */ UINT nCmdShow);
        
        HRESULT ( __stdcall  *Move )( 
            IPropertyPage2  * This,
            /* [in] */ LPCRECT pRect);
        
        HRESULT ( __stdcall  *IsPageDirty )( 
            IPropertyPage2  * This);
        
        HRESULT ( __stdcall  *Apply )( 
            IPropertyPage2  * This);
        
        HRESULT ( __stdcall  *Help )( 
            IPropertyPage2  * This,
            /* [in] */ LPCOLESTR pszHelpDir);
        
        HRESULT ( __stdcall  *TranslateAccelerator )( 
            IPropertyPage2  * This,
            /* [in] */ MSG  *pMsg);
        
        HRESULT ( __stdcall  *EditProperty )( 
            IPropertyPage2  * This,
            /* [in] */ DISPID dispID);
        
        END_INTERFACE
    } IPropertyPage2Vtbl;

    interface IPropertyPage2
    {
        CONST_VTBL struct IPropertyPage2Vtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPropertyPage2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPropertyPage2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPropertyPage2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPropertyPage2_SetPageSite(This,pPageSite)	\
    (This)->lpVtbl -> SetPageSite(This,pPageSite)

#define IPropertyPage2_Activate(This,hWndParent,pRect,bModal)	\
    (This)->lpVtbl -> Activate(This,hWndParent,pRect,bModal)

#define IPropertyPage2_Deactivate(This)	\
    (This)->lpVtbl -> Deactivate(This)

#define IPropertyPage2_GetPageInfo(This,pPageInfo)	\
    (This)->lpVtbl -> GetPageInfo(This,pPageInfo)

#define IPropertyPage2_SetObjects(This,cObjects,ppUnk)	\
    (This)->lpVtbl -> SetObjects(This,cObjects,ppUnk)

#define IPropertyPage2_Show(This,nCmdShow)	\
    (This)->lpVtbl -> Show(This,nCmdShow)

#define IPropertyPage2_Move(This,pRect)	\
    (This)->lpVtbl -> Move(This,pRect)

#define IPropertyPage2_IsPageDirty(This)	\
    (This)->lpVtbl -> IsPageDirty(This)

#define IPropertyPage2_Apply(This)	\
    (This)->lpVtbl -> Apply(This)

#define IPropertyPage2_Help(This,pszHelpDir)	\
    (This)->lpVtbl -> Help(This,pszHelpDir)

#define IPropertyPage2_TranslateAccelerator(This,pMsg)	\
    (This)->lpVtbl -> TranslateAccelerator(This,pMsg)


#define IPropertyPage2_EditProperty(This,dispID)	\
    (This)->lpVtbl -> EditProperty(This,dispID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPropertyPage2_EditProperty_Proxy( 
    IPropertyPage2  * This,
    /* [in] */ DISPID dispID);


void __stdcall IPropertyPage2_EditProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IPropertyPage2_INTERFACE_DEFINED__ */


#ifndef __IPropertyPageSite_INTERFACE_DEFINED__
#define __IPropertyPageSite_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPropertyPageSite
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef IPropertyPageSite  *LPPROPERTYPAGESITE;

typedef 
enum tagPROPPAGESTATUS
    {	PROPPAGESTATUS_DIRTY	= 0x1,
	PROPPAGESTATUS_VALIDATE	= 0x2,
	PROPPAGESTATUS_CLEAN	= 0x4
    }	PROPPAGESTATUS;


EXTERN_C const IID IID_IPropertyPageSite;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IPropertyPageSite : public IUnknown
    {
    public:
        virtual HRESULT __stdcall OnStatusChange( 
            /* [in] */ unsigned long dwFlags) = 0;
        
        virtual HRESULT __stdcall GetLocaleID( 
            /* [out] */ LCID  *pLocaleID) = 0;
        
        virtual HRESULT __stdcall GetPageContainer( 
            /* [out] */ IUnknown  * *ppUnk) = 0;
        
        virtual HRESULT __stdcall TranslateAccelerator( 
            /* [in] */ MSG  *pMsg) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPropertyPageSiteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IPropertyPageSite  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IPropertyPageSite  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IPropertyPageSite  * This);
        
        HRESULT ( __stdcall  *OnStatusChange )( 
            IPropertyPageSite  * This,
            /* [in] */ unsigned long dwFlags);
        
        HRESULT ( __stdcall  *GetLocaleID )( 
            IPropertyPageSite  * This,
            /* [out] */ LCID  *pLocaleID);
        
        HRESULT ( __stdcall  *GetPageContainer )( 
            IPropertyPageSite  * This,
            /* [out] */ IUnknown  * *ppUnk);
        
        HRESULT ( __stdcall  *TranslateAccelerator )( 
            IPropertyPageSite  * This,
            /* [in] */ MSG  *pMsg);
        
        END_INTERFACE
    } IPropertyPageSiteVtbl;

    interface IPropertyPageSite
    {
        CONST_VTBL struct IPropertyPageSiteVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPropertyPageSite_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPropertyPageSite_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPropertyPageSite_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPropertyPageSite_OnStatusChange(This,dwFlags)	\
    (This)->lpVtbl -> OnStatusChange(This,dwFlags)

#define IPropertyPageSite_GetLocaleID(This,pLocaleID)	\
    (This)->lpVtbl -> GetLocaleID(This,pLocaleID)

#define IPropertyPageSite_GetPageContainer(This,ppUnk)	\
    (This)->lpVtbl -> GetPageContainer(This,ppUnk)

#define IPropertyPageSite_TranslateAccelerator(This,pMsg)	\
    (This)->lpVtbl -> TranslateAccelerator(This,pMsg)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPropertyPageSite_OnStatusChange_Proxy( 
    IPropertyPageSite  * This,
    /* [in] */ unsigned long dwFlags);


void __stdcall IPropertyPageSite_OnStatusChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPropertyPageSite_GetLocaleID_Proxy( 
    IPropertyPageSite  * This,
    /* [out] */ LCID  *pLocaleID);


void __stdcall IPropertyPageSite_GetLocaleID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPropertyPageSite_GetPageContainer_Proxy( 
    IPropertyPageSite  * This,
    /* [out] */ IUnknown  * *ppUnk);


void __stdcall IPropertyPageSite_GetPageContainer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPropertyPageSite_TranslateAccelerator_Proxy( 
    IPropertyPageSite  * This,
    /* [in] */ MSG  *pMsg);


void __stdcall IPropertyPageSite_TranslateAccelerator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IPropertyPageSite_INTERFACE_DEFINED__ */


#ifndef __IPropertyNotifySink_INTERFACE_DEFINED__
#define __IPropertyNotifySink_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPropertyNotifySink
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef IPropertyNotifySink  *LPPROPERTYNOTIFYSINK;


EXTERN_C const IID IID_IPropertyNotifySink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IPropertyNotifySink : public IUnknown
    {
    public:
        virtual HRESULT __stdcall OnChanged( 
            /* [in] */ DISPID dispID) = 0;
        
        virtual HRESULT __stdcall OnRequestEdit( 
            /* [in] */ DISPID dispID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPropertyNotifySinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IPropertyNotifySink  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IPropertyNotifySink  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IPropertyNotifySink  * This);
        
        HRESULT ( __stdcall  *OnChanged )( 
            IPropertyNotifySink  * This,
            /* [in] */ DISPID dispID);
        
        HRESULT ( __stdcall  *OnRequestEdit )( 
            IPropertyNotifySink  * This,
            /* [in] */ DISPID dispID);
        
        END_INTERFACE
    } IPropertyNotifySinkVtbl;

    interface IPropertyNotifySink
    {
        CONST_VTBL struct IPropertyNotifySinkVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPropertyNotifySink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPropertyNotifySink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPropertyNotifySink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPropertyNotifySink_OnChanged(This,dispID)	\
    (This)->lpVtbl -> OnChanged(This,dispID)

#define IPropertyNotifySink_OnRequestEdit(This,dispID)	\
    (This)->lpVtbl -> OnRequestEdit(This,dispID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPropertyNotifySink_OnChanged_Proxy( 
    IPropertyNotifySink  * This,
    /* [in] */ DISPID dispID);


void __stdcall IPropertyNotifySink_OnChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPropertyNotifySink_OnRequestEdit_Proxy( 
    IPropertyNotifySink  * This,
    /* [in] */ DISPID dispID);


void __stdcall IPropertyNotifySink_OnRequestEdit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IPropertyNotifySink_INTERFACE_DEFINED__ */


#ifndef __ISpecifyPropertyPages_INTERFACE_DEFINED__
#define __ISpecifyPropertyPages_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ISpecifyPropertyPages
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef ISpecifyPropertyPages  *LPSPECIFYPROPERTYPAGES;

typedef struct  tagCAUUID
    {
    unsigned long cElems;
    /* [size_is] */ GUID  *pElems;
    }	CAUUID;

typedef struct tagCAUUID  *LPCAUUID;


EXTERN_C const IID IID_ISpecifyPropertyPages;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ISpecifyPropertyPages : public IUnknown
    {
    public:
        virtual HRESULT __stdcall GetPages( 
            /* [out] */ CAUUID  *pPages) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISpecifyPropertyPagesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            ISpecifyPropertyPages  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            ISpecifyPropertyPages  * This);
        
        unsigned long ( __stdcall  *Release )( 
            ISpecifyPropertyPages  * This);
        
        HRESULT ( __stdcall  *GetPages )( 
            ISpecifyPropertyPages  * This,
            /* [out] */ CAUUID  *pPages);
        
        END_INTERFACE
    } ISpecifyPropertyPagesVtbl;

    interface ISpecifyPropertyPages
    {
        CONST_VTBL struct ISpecifyPropertyPagesVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISpecifyPropertyPages_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISpecifyPropertyPages_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISpecifyPropertyPages_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISpecifyPropertyPages_GetPages(This,pPages)	\
    (This)->lpVtbl -> GetPages(This,pPages)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall ISpecifyPropertyPages_GetPages_Proxy( 
    ISpecifyPropertyPages  * This,
    /* [out] */ CAUUID  *pPages);


void __stdcall ISpecifyPropertyPages_GetPages_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __ISpecifyPropertyPages_INTERFACE_DEFINED__ */


#ifndef __IPersistMemory_INTERFACE_DEFINED__
#define __IPersistMemory_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPersistMemory
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef IPersistMemory  *LPPERSISTMEMORY;


EXTERN_C const IID IID_IPersistMemory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IPersistMemory : public IPersist
    {
    public:
        virtual HRESULT __stdcall IsDirty( void) = 0;
        
        virtual /* [local] */ HRESULT __stdcall Load( 
            /* [size_is][in] */ void* pMem,
            /* [in] */ unsigned long cbSize) = 0;
        
        virtual /* [local] */ HRESULT __stdcall Save( 
            /* [size_is][in] */ void* pMem,
            /* [in] */ BOOL fClearDirty,
            /* [in] */ unsigned long cbSize) = 0;
        
        virtual HRESULT __stdcall GetSizeMax( 
            /* [out] */ unsigned long  *pCbSize) = 0;
        
        virtual HRESULT __stdcall InitNew( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPersistMemoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IPersistMemory  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IPersistMemory  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IPersistMemory  * This);
        
        HRESULT ( __stdcall  *GetClassID )( 
            IPersistMemory  * This,
            /* [out] */ CLSID  *pClassID);
        
        HRESULT ( __stdcall  *IsDirty )( 
            IPersistMemory  * This);
        
        /* [local] */ HRESULT ( __stdcall  *Load )( 
            IPersistMemory  * This,
            /* [size_is][in] */ void* pMem,
            /* [in] */ unsigned long cbSize);
        
        /* [local] */ HRESULT ( __stdcall  *Save )( 
            IPersistMemory  * This,
            /* [size_is][in] */ void* pMem,
            /* [in] */ BOOL fClearDirty,
            /* [in] */ unsigned long cbSize);
        
        HRESULT ( __stdcall  *GetSizeMax )( 
            IPersistMemory  * This,
            /* [out] */ unsigned long  *pCbSize);
        
        HRESULT ( __stdcall  *InitNew )( 
            IPersistMemory  * This);
        
        END_INTERFACE
    } IPersistMemoryVtbl;

    interface IPersistMemory
    {
        CONST_VTBL struct IPersistMemoryVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPersistMemory_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPersistMemory_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPersistMemory_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPersistMemory_GetClassID(This,pClassID)	\
    (This)->lpVtbl -> GetClassID(This,pClassID)


#define IPersistMemory_IsDirty(This)	\
    (This)->lpVtbl -> IsDirty(This)

#define IPersistMemory_Load(This,pMem,cbSize)	\
    (This)->lpVtbl -> Load(This,pMem,cbSize)

#define IPersistMemory_Save(This,pMem,fClearDirty,cbSize)	\
    (This)->lpVtbl -> Save(This,pMem,fClearDirty,cbSize)

#define IPersistMemory_GetSizeMax(This,pCbSize)	\
    (This)->lpVtbl -> GetSizeMax(This,pCbSize)

#define IPersistMemory_InitNew(This)	\
    (This)->lpVtbl -> InitNew(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPersistMemory_IsDirty_Proxy( 
    IPersistMemory  * This);


void __stdcall IPersistMemory_IsDirty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall IPersistMemory_RemoteLoad_Proxy( 
    IPersistMemory  * This,
    /* [size_is][in] */ BYTE  *pMem,
    /* [in] */ unsigned long cbSize);


void __stdcall IPersistMemory_RemoteLoad_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall IPersistMemory_RemoteSave_Proxy( 
    IPersistMemory  * This,
    /* [size_is][in] */ BYTE  *pMem,
    /* [in] */ BOOL fClearDirty,
    /* [in] */ unsigned long cbSize);


void __stdcall IPersistMemory_RemoteSave_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPersistMemory_GetSizeMax_Proxy( 
    IPersistMemory  * This,
    /* [out] */ unsigned long  *pCbSize);


void __stdcall IPersistMemory_GetSizeMax_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPersistMemory_InitNew_Proxy( 
    IPersistMemory  * This);


void __stdcall IPersistMemory_InitNew_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IPersistMemory_INTERFACE_DEFINED__ */


#ifndef __IPersistStreamInit_INTERFACE_DEFINED__
#define __IPersistStreamInit_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPersistStreamInit
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef IPersistStreamInit  *LPPERSISTSTREAMINIT;


EXTERN_C const IID IID_IPersistStreamInit;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IPersistStreamInit : public IPersist
    {
    public:
        virtual HRESULT __stdcall IsDirty( void) = 0;
        
        virtual HRESULT __stdcall Load( 
            /* [in] */ LPSTREAM pStm) = 0;
        
        virtual HRESULT __stdcall Save( 
            /* [in] */ LPSTREAM pStm,
            /* [in] */ BOOL fClearDirty) = 0;
        
        virtual HRESULT __stdcall GetSizeMax( 
            /* [out] */ ULARGE_INTEGER  *pCbSize) = 0;
        
        virtual HRESULT __stdcall InitNew( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPersistStreamInitVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IPersistStreamInit  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IPersistStreamInit  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IPersistStreamInit  * This);
        
        HRESULT ( __stdcall  *GetClassID )( 
            IPersistStreamInit  * This,
            /* [out] */ CLSID  *pClassID);
        
        HRESULT ( __stdcall  *IsDirty )( 
            IPersistStreamInit  * This);
        
        HRESULT ( __stdcall  *Load )( 
            IPersistStreamInit  * This,
            /* [in] */ LPSTREAM pStm);
        
        HRESULT ( __stdcall  *Save )( 
            IPersistStreamInit  * This,
            /* [in] */ LPSTREAM pStm,
            /* [in] */ BOOL fClearDirty);
        
        HRESULT ( __stdcall  *GetSizeMax )( 
            IPersistStreamInit  * This,
            /* [out] */ ULARGE_INTEGER  *pCbSize);
        
        HRESULT ( __stdcall  *InitNew )( 
            IPersistStreamInit  * This);
        
        END_INTERFACE
    } IPersistStreamInitVtbl;

    interface IPersistStreamInit
    {
        CONST_VTBL struct IPersistStreamInitVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPersistStreamInit_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPersistStreamInit_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPersistStreamInit_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPersistStreamInit_GetClassID(This,pClassID)	\
    (This)->lpVtbl -> GetClassID(This,pClassID)


#define IPersistStreamInit_IsDirty(This)	\
    (This)->lpVtbl -> IsDirty(This)

#define IPersistStreamInit_Load(This,pStm)	\
    (This)->lpVtbl -> Load(This,pStm)

#define IPersistStreamInit_Save(This,pStm,fClearDirty)	\
    (This)->lpVtbl -> Save(This,pStm,fClearDirty)

#define IPersistStreamInit_GetSizeMax(This,pCbSize)	\
    (This)->lpVtbl -> GetSizeMax(This,pCbSize)

#define IPersistStreamInit_InitNew(This)	\
    (This)->lpVtbl -> InitNew(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPersistStreamInit_IsDirty_Proxy( 
    IPersistStreamInit  * This);


void __stdcall IPersistStreamInit_IsDirty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPersistStreamInit_Load_Proxy( 
    IPersistStreamInit  * This,
    /* [in] */ LPSTREAM pStm);


void __stdcall IPersistStreamInit_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPersistStreamInit_Save_Proxy( 
    IPersistStreamInit  * This,
    /* [in] */ LPSTREAM pStm,
    /* [in] */ BOOL fClearDirty);


void __stdcall IPersistStreamInit_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPersistStreamInit_GetSizeMax_Proxy( 
    IPersistStreamInit  * This,
    /* [out] */ ULARGE_INTEGER  *pCbSize);


void __stdcall IPersistStreamInit_GetSizeMax_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPersistStreamInit_InitNew_Proxy( 
    IPersistStreamInit  * This);


void __stdcall IPersistStreamInit_InitNew_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IPersistStreamInit_INTERFACE_DEFINED__ */


#ifndef __IPersistPropertyBag_INTERFACE_DEFINED__
#define __IPersistPropertyBag_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPersistPropertyBag
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef IPersistPropertyBag  *LPPERSISTPROPERTYBAG;


EXTERN_C const IID IID_IPersistPropertyBag;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IPersistPropertyBag : public IPersist
    {
    public:
        virtual HRESULT __stdcall InitNew( void) = 0;
        
        virtual HRESULT __stdcall Load( 
            /* [in] */ IPropertyBag  *pPropBag,
            /* [in] */ IErrorLog  *pErrorLog) = 0;
        
        virtual HRESULT __stdcall Save( 
            /* [in] */ IPropertyBag  *pPropBag,
            /* [in] */ BOOL fClearDirty,
            /* [in] */ BOOL fSaveAllProperties) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPersistPropertyBagVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IPersistPropertyBag  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IPersistPropertyBag  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IPersistPropertyBag  * This);
        
        HRESULT ( __stdcall  *GetClassID )( 
            IPersistPropertyBag  * This,
            /* [out] */ CLSID  *pClassID);
        
        HRESULT ( __stdcall  *InitNew )( 
            IPersistPropertyBag  * This);
        
        HRESULT ( __stdcall  *Load )( 
            IPersistPropertyBag  * This,
            /* [in] */ IPropertyBag  *pPropBag,
            /* [in] */ IErrorLog  *pErrorLog);
        
        HRESULT ( __stdcall  *Save )( 
            IPersistPropertyBag  * This,
            /* [in] */ IPropertyBag  *pPropBag,
            /* [in] */ BOOL fClearDirty,
            /* [in] */ BOOL fSaveAllProperties);
        
        END_INTERFACE
    } IPersistPropertyBagVtbl;

    interface IPersistPropertyBag
    {
        CONST_VTBL struct IPersistPropertyBagVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPersistPropertyBag_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPersistPropertyBag_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPersistPropertyBag_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPersistPropertyBag_GetClassID(This,pClassID)	\
    (This)->lpVtbl -> GetClassID(This,pClassID)


#define IPersistPropertyBag_InitNew(This)	\
    (This)->lpVtbl -> InitNew(This)

#define IPersistPropertyBag_Load(This,pPropBag,pErrorLog)	\
    (This)->lpVtbl -> Load(This,pPropBag,pErrorLog)

#define IPersistPropertyBag_Save(This,pPropBag,fClearDirty,fSaveAllProperties)	\
    (This)->lpVtbl -> Save(This,pPropBag,fClearDirty,fSaveAllProperties)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPersistPropertyBag_InitNew_Proxy( 
    IPersistPropertyBag  * This);


void __stdcall IPersistPropertyBag_InitNew_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPersistPropertyBag_Load_Proxy( 
    IPersistPropertyBag  * This,
    /* [in] */ IPropertyBag  *pPropBag,
    /* [in] */ IErrorLog  *pErrorLog);


void __stdcall IPersistPropertyBag_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPersistPropertyBag_Save_Proxy( 
    IPersistPropertyBag  * This,
    /* [in] */ IPropertyBag  *pPropBag,
    /* [in] */ BOOL fClearDirty,
    /* [in] */ BOOL fSaveAllProperties);


void __stdcall IPersistPropertyBag_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IPersistPropertyBag_INTERFACE_DEFINED__ */


#ifndef __ISimpleFrameSite_INTERFACE_DEFINED__
#define __ISimpleFrameSite_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ISimpleFrameSite
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef ISimpleFrameSite  *LPSIMPLEFRAMESITE;


EXTERN_C const IID IID_ISimpleFrameSite;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ISimpleFrameSite : public IUnknown
    {
    public:
        virtual HRESULT __stdcall PreMessageFilter( 
            /* [in] */ HWND hWnd,
            /* [in] */ UINT msg,
            /* [in] */ WPARAM wp,
            /* [in] */ LPARAM lp,
            /* [out] */ LRESULT  *plResult,
            /* [out] */ unsigned long  *pdwCookie) = 0;
        
        virtual HRESULT __stdcall PostMessageFilter( 
            /* [in] */ HWND hWnd,
            /* [in] */ UINT msg,
            /* [in] */ WPARAM wp,
            /* [in] */ LPARAM lp,
            /* [out] */ LRESULT  *plResult,
            /* [in] */ unsigned long dwCookie) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISimpleFrameSiteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            ISimpleFrameSite  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            ISimpleFrameSite  * This);
        
        unsigned long ( __stdcall  *Release )( 
            ISimpleFrameSite  * This);
        
        HRESULT ( __stdcall  *PreMessageFilter )( 
            ISimpleFrameSite  * This,
            /* [in] */ HWND hWnd,
            /* [in] */ UINT msg,
            /* [in] */ WPARAM wp,
            /* [in] */ LPARAM lp,
            /* [out] */ LRESULT  *plResult,
            /* [out] */ unsigned long  *pdwCookie);
        
        HRESULT ( __stdcall  *PostMessageFilter )( 
            ISimpleFrameSite  * This,
            /* [in] */ HWND hWnd,
            /* [in] */ UINT msg,
            /* [in] */ WPARAM wp,
            /* [in] */ LPARAM lp,
            /* [out] */ LRESULT  *plResult,
            /* [in] */ unsigned long dwCookie);
        
        END_INTERFACE
    } ISimpleFrameSiteVtbl;

    interface ISimpleFrameSite
    {
        CONST_VTBL struct ISimpleFrameSiteVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISimpleFrameSite_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISimpleFrameSite_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISimpleFrameSite_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISimpleFrameSite_PreMessageFilter(This,hWnd,msg,wp,lp,plResult,pdwCookie)	\
    (This)->lpVtbl -> PreMessageFilter(This,hWnd,msg,wp,lp,plResult,pdwCookie)

#define ISimpleFrameSite_PostMessageFilter(This,hWnd,msg,wp,lp,plResult,dwCookie)	\
    (This)->lpVtbl -> PostMessageFilter(This,hWnd,msg,wp,lp,plResult,dwCookie)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall ISimpleFrameSite_PreMessageFilter_Proxy( 
    ISimpleFrameSite  * This,
    /* [in] */ HWND hWnd,
    /* [in] */ UINT msg,
    /* [in] */ WPARAM wp,
    /* [in] */ LPARAM lp,
    /* [out] */ LRESULT  *plResult,
    /* [out] */ unsigned long  *pdwCookie);


void __stdcall ISimpleFrameSite_PreMessageFilter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall ISimpleFrameSite_PostMessageFilter_Proxy( 
    ISimpleFrameSite  * This,
    /* [in] */ HWND hWnd,
    /* [in] */ UINT msg,
    /* [in] */ WPARAM wp,
    /* [in] */ LPARAM lp,
    /* [out] */ LRESULT  *plResult,
    /* [in] */ unsigned long dwCookie);


void __stdcall ISimpleFrameSite_PostMessageFilter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __ISimpleFrameSite_INTERFACE_DEFINED__ */


#ifndef __IFont_INTERFACE_DEFINED__
#define __IFont_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IFont
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef IFont  *LPFONT;

#if defined(_WIN32) && !defined(OLE2ANSI)
typedef TEXTMETRICW TEXTMETRICOLE;

#else
typedef TEXTMETRIC TEXTMETRICOLE;
#endif
typedef TEXTMETRICOLE  *LPTEXTMETRICOLE;


EXTERN_C const IID IID_IFont;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IFont : public IUnknown
    {
    public:
        virtual HRESULT __stdcall get_Name( 
            /* [out] */ BSTR  *pName) = 0;
        
        virtual HRESULT __stdcall put_Name( 
            /* [in] */ BSTR name) = 0;
        
        virtual HRESULT __stdcall get_Size( 
            /* [out] */ CY  *pSize) = 0;
        
        virtual HRESULT __stdcall put_Size( 
            /* [in] */ CY size) = 0;
        
        virtual HRESULT __stdcall get_Bold( 
            /* [out] */ BOOL  *pBold) = 0;
        
        virtual HRESULT __stdcall put_Bold( 
            /* [in] */ BOOL bold) = 0;
        
        virtual HRESULT __stdcall get_Italic( 
            /* [out] */ BOOL  *pItalic) = 0;
        
        virtual HRESULT __stdcall put_Italic( 
            /* [in] */ BOOL italic) = 0;
        
        virtual HRESULT __stdcall get_Underline( 
            /* [out] */ BOOL  *pUnderline) = 0;
        
        virtual HRESULT __stdcall put_Underline( 
            /* [in] */ BOOL underline) = 0;
        
        virtual HRESULT __stdcall get_Strikethrough( 
            /* [out] */ BOOL  *pStrikethrough) = 0;
        
        virtual HRESULT __stdcall put_Strikethrough( 
            /* [in] */ BOOL strikethrough) = 0;
        
        virtual HRESULT __stdcall get_Weight( 
            /* [out] */ SHORT  *pWeight) = 0;
        
        virtual HRESULT __stdcall put_Weight( 
            /* [in] */ SHORT weight) = 0;
        
        virtual HRESULT __stdcall get_Charset( 
            /* [out] */ SHORT  *pCharset) = 0;
        
        virtual HRESULT __stdcall put_Charset( 
            /* [in] */ SHORT charset) = 0;
        
        virtual HRESULT __stdcall get_hFont( 
            /* [out] */ HFONT  *phFont) = 0;
        
        virtual HRESULT __stdcall Clone( 
            /* [out] */ IFont  * *ppFont) = 0;
        
        virtual HRESULT __stdcall IsEqual( 
            /* [in] */ IFont  *pFontOther) = 0;
        
        virtual HRESULT __stdcall SetRatio( 
            /* [in] */ LONG cyLogical,
            /* [in] */ LONG cyHimetric) = 0;
        
        virtual HRESULT __stdcall QueryTextMetrics( 
            /* [out] */ TEXTMETRICOLE  *pTM) = 0;
        
        virtual HRESULT __stdcall AddRefHfont( 
            /* [in] */ HFONT hFont) = 0;
        
        virtual HRESULT __stdcall ReleaseHfont( 
            /* [in] */ HFONT hFont) = 0;
        
        virtual HRESULT __stdcall SetHdc( 
            /* [in] */ HDC hDC) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFontVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IFont  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IFont  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IFont  * This);
        
        HRESULT ( __stdcall  *get_Name )( 
            IFont  * This,
            /* [out] */ BSTR  *pName);
        
        HRESULT ( __stdcall  *put_Name )( 
            IFont  * This,
            /* [in] */ BSTR name);
        
        HRESULT ( __stdcall  *get_Size )( 
            IFont  * This,
            /* [out] */ CY  *pSize);
        
        HRESULT ( __stdcall  *put_Size )( 
            IFont  * This,
            /* [in] */ CY size);
        
        HRESULT ( __stdcall  *get_Bold )( 
            IFont  * This,
            /* [out] */ BOOL  *pBold);
        
        HRESULT ( __stdcall  *put_Bold )( 
            IFont  * This,
            /* [in] */ BOOL bold);
        
        HRESULT ( __stdcall  *get_Italic )( 
            IFont  * This,
            /* [out] */ BOOL  *pItalic);
        
        HRESULT ( __stdcall  *put_Italic )( 
            IFont  * This,
            /* [in] */ BOOL italic);
        
        HRESULT ( __stdcall  *get_Underline )( 
            IFont  * This,
            /* [out] */ BOOL  *pUnderline);
        
        HRESULT ( __stdcall  *put_Underline )( 
            IFont  * This,
            /* [in] */ BOOL underline);
        
        HRESULT ( __stdcall  *get_Strikethrough )( 
            IFont  * This,
            /* [out] */ BOOL  *pStrikethrough);
        
        HRESULT ( __stdcall  *put_Strikethrough )( 
            IFont  * This,
            /* [in] */ BOOL strikethrough);
        
        HRESULT ( __stdcall  *get_Weight )( 
            IFont  * This,
            /* [out] */ SHORT  *pWeight);
        
        HRESULT ( __stdcall  *put_Weight )( 
            IFont  * This,
            /* [in] */ SHORT weight);
        
        HRESULT ( __stdcall  *get_Charset )( 
            IFont  * This,
            /* [out] */ SHORT  *pCharset);
        
        HRESULT ( __stdcall  *put_Charset )( 
            IFont  * This,
            /* [in] */ SHORT charset);
        
        HRESULT ( __stdcall  *get_hFont )( 
            IFont  * This,
            /* [out] */ HFONT  *phFont);
        
        HRESULT ( __stdcall  *Clone )( 
            IFont  * This,
            /* [out] */ IFont  * *ppFont);
        
        HRESULT ( __stdcall  *IsEqual )( 
            IFont  * This,
            /* [in] */ IFont  *pFontOther);
        
        HRESULT ( __stdcall  *SetRatio )( 
            IFont  * This,
            /* [in] */ LONG cyLogical,
            /* [in] */ LONG cyHimetric);
        
        HRESULT ( __stdcall  *QueryTextMetrics )( 
            IFont  * This,
            /* [out] */ TEXTMETRICOLE  *pTM);
        
        HRESULT ( __stdcall  *AddRefHfont )( 
            IFont  * This,
            /* [in] */ HFONT hFont);
        
        HRESULT ( __stdcall  *ReleaseHfont )( 
            IFont  * This,
            /* [in] */ HFONT hFont);
        
        HRESULT ( __stdcall  *SetHdc )( 
            IFont  * This,
            /* [in] */ HDC hDC);
        
        END_INTERFACE
    } IFontVtbl;

    interface IFont
    {
        CONST_VTBL struct IFontVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFont_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFont_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFont_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFont_get_Name(This,pName)	\
    (This)->lpVtbl -> get_Name(This,pName)

#define IFont_put_Name(This,name)	\
    (This)->lpVtbl -> put_Name(This,name)

#define IFont_get_Size(This,pSize)	\
    (This)->lpVtbl -> get_Size(This,pSize)

#define IFont_put_Size(This,size)	\
    (This)->lpVtbl -> put_Size(This,size)

#define IFont_get_Bold(This,pBold)	\
    (This)->lpVtbl -> get_Bold(This,pBold)

#define IFont_put_Bold(This,bold)	\
    (This)->lpVtbl -> put_Bold(This,bold)

#define IFont_get_Italic(This,pItalic)	\
    (This)->lpVtbl -> get_Italic(This,pItalic)

#define IFont_put_Italic(This,italic)	\
    (This)->lpVtbl -> put_Italic(This,italic)

#define IFont_get_Underline(This,pUnderline)	\
    (This)->lpVtbl -> get_Underline(This,pUnderline)

#define IFont_put_Underline(This,underline)	\
    (This)->lpVtbl -> put_Underline(This,underline)

#define IFont_get_Strikethrough(This,pStrikethrough)	\
    (This)->lpVtbl -> get_Strikethrough(This,pStrikethrough)

#define IFont_put_Strikethrough(This,strikethrough)	\
    (This)->lpVtbl -> put_Strikethrough(This,strikethrough)

#define IFont_get_Weight(This,pWeight)	\
    (This)->lpVtbl -> get_Weight(This,pWeight)

#define IFont_put_Weight(This,weight)	\
    (This)->lpVtbl -> put_Weight(This,weight)

#define IFont_get_Charset(This,pCharset)	\
    (This)->lpVtbl -> get_Charset(This,pCharset)

#define IFont_put_Charset(This,charset)	\
    (This)->lpVtbl -> put_Charset(This,charset)

#define IFont_get_hFont(This,phFont)	\
    (This)->lpVtbl -> get_hFont(This,phFont)

#define IFont_Clone(This,ppFont)	\
    (This)->lpVtbl -> Clone(This,ppFont)

#define IFont_IsEqual(This,pFontOther)	\
    (This)->lpVtbl -> IsEqual(This,pFontOther)

#define IFont_SetRatio(This,cyLogical,cyHimetric)	\
    (This)->lpVtbl -> SetRatio(This,cyLogical,cyHimetric)

#define IFont_QueryTextMetrics(This,pTM)	\
    (This)->lpVtbl -> QueryTextMetrics(This,pTM)

#define IFont_AddRefHfont(This,hFont)	\
    (This)->lpVtbl -> AddRefHfont(This,hFont)

#define IFont_ReleaseHfont(This,hFont)	\
    (This)->lpVtbl -> ReleaseHfont(This,hFont)

#define IFont_SetHdc(This,hDC)	\
    (This)->lpVtbl -> SetHdc(This,hDC)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IFont_get_Name_Proxy( 
    IFont  * This,
    /* [out] */ BSTR  *pName);


void __stdcall IFont_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IFont_put_Name_Proxy( 
    IFont  * This,
    /* [in] */ BSTR name);


void __stdcall IFont_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IFont_get_Size_Proxy( 
    IFont  * This,
    /* [out] */ CY  *pSize);


void __stdcall IFont_get_Size_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IFont_put_Size_Proxy( 
    IFont  * This,
    /* [in] */ CY size);


void __stdcall IFont_put_Size_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IFont_get_Bold_Proxy( 
    IFont  * This,
    /* [out] */ BOOL  *pBold);


void __stdcall IFont_get_Bold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IFont_put_Bold_Proxy( 
    IFont  * This,
    /* [in] */ BOOL bold);


void __stdcall IFont_put_Bold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IFont_get_Italic_Proxy( 
    IFont  * This,
    /* [out] */ BOOL  *pItalic);


void __stdcall IFont_get_Italic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IFont_put_Italic_Proxy( 
    IFont  * This,
    /* [in] */ BOOL italic);


void __stdcall IFont_put_Italic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IFont_get_Underline_Proxy( 
    IFont  * This,
    /* [out] */ BOOL  *pUnderline);


void __stdcall IFont_get_Underline_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IFont_put_Underline_Proxy( 
    IFont  * This,
    /* [in] */ BOOL underline);


void __stdcall IFont_put_Underline_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IFont_get_Strikethrough_Proxy( 
    IFont  * This,
    /* [out] */ BOOL  *pStrikethrough);


void __stdcall IFont_get_Strikethrough_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IFont_put_Strikethrough_Proxy( 
    IFont  * This,
    /* [in] */ BOOL strikethrough);


void __stdcall IFont_put_Strikethrough_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IFont_get_Weight_Proxy( 
    IFont  * This,
    /* [out] */ SHORT  *pWeight);


void __stdcall IFont_get_Weight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IFont_put_Weight_Proxy( 
    IFont  * This,
    /* [in] */ SHORT weight);


void __stdcall IFont_put_Weight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IFont_get_Charset_Proxy( 
    IFont  * This,
    /* [out] */ SHORT  *pCharset);


void __stdcall IFont_get_Charset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IFont_put_Charset_Proxy( 
    IFont  * This,
    /* [in] */ SHORT charset);


void __stdcall IFont_put_Charset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IFont_get_hFont_Proxy( 
    IFont  * This,
    /* [out] */ HFONT  *phFont);


void __stdcall IFont_get_hFont_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IFont_Clone_Proxy( 
    IFont  * This,
    /* [out] */ IFont  * *ppFont);


void __stdcall IFont_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IFont_IsEqual_Proxy( 
    IFont  * This,
    /* [in] */ IFont  *pFontOther);


void __stdcall IFont_IsEqual_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IFont_SetRatio_Proxy( 
    IFont  * This,
    /* [in] */ LONG cyLogical,
    /* [in] */ LONG cyHimetric);


void __stdcall IFont_SetRatio_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IFont_QueryTextMetrics_Proxy( 
    IFont  * This,
    /* [out] */ TEXTMETRICOLE  *pTM);


void __stdcall IFont_QueryTextMetrics_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IFont_AddRefHfont_Proxy( 
    IFont  * This,
    /* [in] */ HFONT hFont);


void __stdcall IFont_AddRefHfont_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IFont_ReleaseHfont_Proxy( 
    IFont  * This,
    /* [in] */ HFONT hFont);


void __stdcall IFont_ReleaseHfont_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IFont_SetHdc_Proxy( 
    IFont  * This,
    /* [in] */ HDC hDC);


void __stdcall IFont_SetHdc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IFont_INTERFACE_DEFINED__ */


#ifndef __IPicture_INTERFACE_DEFINED__
#define __IPicture_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPicture
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef IPicture  *LPPICTURE;

typedef 
enum tagPictureAttributes
    {	PICTURE_SCALABLE	= 0x1,
	PICTURE_TRANSPARENT	= 0x2
    }	PICTUREATTRIBUTES;

typedef UINT OLE_HANDLE;

typedef LONG OLE_XPOS_HIMETRIC;

typedef LONG OLE_YPOS_HIMETRIC;

typedef LONG OLE_XSIZE_HIMETRIC;

typedef LONG OLE_YSIZE_HIMETRIC;


EXTERN_C const IID IID_IPicture;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IPicture : public IUnknown
    {
    public:
        virtual HRESULT __stdcall get_Handle( 
            /* [out] */ OLE_HANDLE  *pHandle) = 0;
        
        virtual HRESULT __stdcall get_hPal( 
            /* [out] */ OLE_HANDLE  *phPal) = 0;
        
        virtual HRESULT __stdcall get_Type( 
            /* [out] */ SHORT  *pType) = 0;
        
        virtual HRESULT __stdcall get_Width( 
            /* [out] */ OLE_XSIZE_HIMETRIC  *pWidth) = 0;
        
        virtual HRESULT __stdcall get_Height( 
            /* [out] */ OLE_YSIZE_HIMETRIC  *pHeight) = 0;
        
        virtual HRESULT __stdcall Render( 
            /* [in] */ HDC hDC,
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ LONG cx,
            /* [in] */ LONG cy,
            /* [in] */ OLE_XPOS_HIMETRIC xSrc,
            /* [in] */ OLE_YPOS_HIMETRIC ySrc,
            /* [in] */ OLE_XSIZE_HIMETRIC cxSrc,
            /* [in] */ OLE_YSIZE_HIMETRIC cySrc,
            /* [in] */ LPCRECT pRcWBounds) = 0;
        
        virtual HRESULT __stdcall set_hPal( 
            /* [in] */ OLE_HANDLE hPal) = 0;
        
        virtual HRESULT __stdcall get_CurDC( 
            /* [out] */ HDC  *phDC) = 0;
        
        virtual HRESULT __stdcall SelectPicture( 
            /* [in] */ HDC hDCIn,
            /* [out] */ HDC  *phDCOut,
            /* [out] */ OLE_HANDLE  *phBmpOut) = 0;
        
        virtual HRESULT __stdcall get_KeepOriginalFormat( 
            /* [out] */ BOOL  *pKeep) = 0;
        
        virtual HRESULT __stdcall put_KeepOriginalFormat( 
            /* [in] */ BOOL keep) = 0;
        
        virtual HRESULT __stdcall PictureChanged( void) = 0;
        
        virtual HRESULT __stdcall SaveAsFile( 
            /* [in] */ LPSTREAM pStream,
            /* [in] */ BOOL fSaveMemCopy,
            /* [out] */ LONG  *pCbSize) = 0;
        
        virtual HRESULT __stdcall get_Attributes( 
            /* [out] */ unsigned long  *pDwAttr) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPictureVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IPicture  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IPicture  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IPicture  * This);
        
        HRESULT ( __stdcall  *get_Handle )( 
            IPicture  * This,
            /* [out] */ OLE_HANDLE  *pHandle);
        
        HRESULT ( __stdcall  *get_hPal )( 
            IPicture  * This,
            /* [out] */ OLE_HANDLE  *phPal);
        
        HRESULT ( __stdcall  *get_Type )( 
            IPicture  * This,
            /* [out] */ SHORT  *pType);
        
        HRESULT ( __stdcall  *get_Width )( 
            IPicture  * This,
            /* [out] */ OLE_XSIZE_HIMETRIC  *pWidth);
        
        HRESULT ( __stdcall  *get_Height )( 
            IPicture  * This,
            /* [out] */ OLE_YSIZE_HIMETRIC  *pHeight);
        
        HRESULT ( __stdcall  *Render )( 
            IPicture  * This,
            /* [in] */ HDC hDC,
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ LONG cx,
            /* [in] */ LONG cy,
            /* [in] */ OLE_XPOS_HIMETRIC xSrc,
            /* [in] */ OLE_YPOS_HIMETRIC ySrc,
            /* [in] */ OLE_XSIZE_HIMETRIC cxSrc,
            /* [in] */ OLE_YSIZE_HIMETRIC cySrc,
            /* [in] */ LPCRECT pRcWBounds);
        
        HRESULT ( __stdcall  *set_hPal )( 
            IPicture  * This,
            /* [in] */ OLE_HANDLE hPal);
        
        HRESULT ( __stdcall  *get_CurDC )( 
            IPicture  * This,
            /* [out] */ HDC  *phDC);
        
        HRESULT ( __stdcall  *SelectPicture )( 
            IPicture  * This,
            /* [in] */ HDC hDCIn,
            /* [out] */ HDC  *phDCOut,
            /* [out] */ OLE_HANDLE  *phBmpOut);
        
        HRESULT ( __stdcall  *get_KeepOriginalFormat )( 
            IPicture  * This,
            /* [out] */ BOOL  *pKeep);
        
        HRESULT ( __stdcall  *put_KeepOriginalFormat )( 
            IPicture  * This,
            /* [in] */ BOOL keep);
        
        HRESULT ( __stdcall  *PictureChanged )( 
            IPicture  * This);
        
        HRESULT ( __stdcall  *SaveAsFile )( 
            IPicture  * This,
            /* [in] */ LPSTREAM pStream,
            /* [in] */ BOOL fSaveMemCopy,
            /* [out] */ LONG  *pCbSize);
        
        HRESULT ( __stdcall  *get_Attributes )( 
            IPicture  * This,
            /* [out] */ unsigned long  *pDwAttr);
        
        END_INTERFACE
    } IPictureVtbl;

    interface IPicture
    {
        CONST_VTBL struct IPictureVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPicture_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPicture_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPicture_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPicture_get_Handle(This,pHandle)	\
    (This)->lpVtbl -> get_Handle(This,pHandle)

#define IPicture_get_hPal(This,phPal)	\
    (This)->lpVtbl -> get_hPal(This,phPal)

#define IPicture_get_Type(This,pType)	\
    (This)->lpVtbl -> get_Type(This,pType)

#define IPicture_get_Width(This,pWidth)	\
    (This)->lpVtbl -> get_Width(This,pWidth)

#define IPicture_get_Height(This,pHeight)	\
    (This)->lpVtbl -> get_Height(This,pHeight)

#define IPicture_Render(This,hDC,x,y,cx,cy,xSrc,ySrc,cxSrc,cySrc,pRcWBounds)	\
    (This)->lpVtbl -> Render(This,hDC,x,y,cx,cy,xSrc,ySrc,cxSrc,cySrc,pRcWBounds)

#define IPicture_set_hPal(This,hPal)	\
    (This)->lpVtbl -> set_hPal(This,hPal)

#define IPicture_get_CurDC(This,phDC)	\
    (This)->lpVtbl -> get_CurDC(This,phDC)

#define IPicture_SelectPicture(This,hDCIn,phDCOut,phBmpOut)	\
    (This)->lpVtbl -> SelectPicture(This,hDCIn,phDCOut,phBmpOut)

#define IPicture_get_KeepOriginalFormat(This,pKeep)	\
    (This)->lpVtbl -> get_KeepOriginalFormat(This,pKeep)

#define IPicture_put_KeepOriginalFormat(This,keep)	\
    (This)->lpVtbl -> put_KeepOriginalFormat(This,keep)

#define IPicture_PictureChanged(This)	\
    (This)->lpVtbl -> PictureChanged(This)

#define IPicture_SaveAsFile(This,pStream,fSaveMemCopy,pCbSize)	\
    (This)->lpVtbl -> SaveAsFile(This,pStream,fSaveMemCopy,pCbSize)

#define IPicture_get_Attributes(This,pDwAttr)	\
    (This)->lpVtbl -> get_Attributes(This,pDwAttr)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPicture_get_Handle_Proxy( 
    IPicture  * This,
    /* [out] */ OLE_HANDLE  *pHandle);


void __stdcall IPicture_get_Handle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPicture_get_hPal_Proxy( 
    IPicture  * This,
    /* [out] */ OLE_HANDLE  *phPal);


void __stdcall IPicture_get_hPal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPicture_get_Type_Proxy( 
    IPicture  * This,
    /* [out] */ SHORT  *pType);


void __stdcall IPicture_get_Type_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPicture_get_Width_Proxy( 
    IPicture  * This,
    /* [out] */ OLE_XSIZE_HIMETRIC  *pWidth);


void __stdcall IPicture_get_Width_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPicture_get_Height_Proxy( 
    IPicture  * This,
    /* [out] */ OLE_YSIZE_HIMETRIC  *pHeight);


void __stdcall IPicture_get_Height_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPicture_Render_Proxy( 
    IPicture  * This,
    /* [in] */ HDC hDC,
    /* [in] */ LONG x,
    /* [in] */ LONG y,
    /* [in] */ LONG cx,
    /* [in] */ LONG cy,
    /* [in] */ OLE_XPOS_HIMETRIC xSrc,
    /* [in] */ OLE_YPOS_HIMETRIC ySrc,
    /* [in] */ OLE_XSIZE_HIMETRIC cxSrc,
    /* [in] */ OLE_YSIZE_HIMETRIC cySrc,
    /* [in] */ LPCRECT pRcWBounds);


void __stdcall IPicture_Render_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPicture_set_hPal_Proxy( 
    IPicture  * This,
    /* [in] */ OLE_HANDLE hPal);


void __stdcall IPicture_set_hPal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPicture_get_CurDC_Proxy( 
    IPicture  * This,
    /* [out] */ HDC  *phDC);


void __stdcall IPicture_get_CurDC_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPicture_SelectPicture_Proxy( 
    IPicture  * This,
    /* [in] */ HDC hDCIn,
    /* [out] */ HDC  *phDCOut,
    /* [out] */ OLE_HANDLE  *phBmpOut);


void __stdcall IPicture_SelectPicture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPicture_get_KeepOriginalFormat_Proxy( 
    IPicture  * This,
    /* [out] */ BOOL  *pKeep);


void __stdcall IPicture_get_KeepOriginalFormat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPicture_put_KeepOriginalFormat_Proxy( 
    IPicture  * This,
    /* [in] */ BOOL keep);


void __stdcall IPicture_put_KeepOriginalFormat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPicture_PictureChanged_Proxy( 
    IPicture  * This);


void __stdcall IPicture_PictureChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPicture_SaveAsFile_Proxy( 
    IPicture  * This,
    /* [in] */ LPSTREAM pStream,
    /* [in] */ BOOL fSaveMemCopy,
    /* [out] */ LONG  *pCbSize);


void __stdcall IPicture_SaveAsFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPicture_get_Attributes_Proxy( 
    IPicture  * This,
    /* [out] */ unsigned long  *pDwAttr);


void __stdcall IPicture_get_Attributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IPicture_INTERFACE_DEFINED__ */


#ifndef __IFontDisp_INTERFACE_DEFINED__
#define __IFontDisp_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IFontDisp
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef IFontDisp  *LPFONTDISP;


EXTERN_C const IID IID_IFontDisp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IFontDisp : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IFontDispVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IFontDisp  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IFontDisp  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IFontDisp  * This);
        
        HRESULT ( __stdcall  *GetTypeInfoCount )( 
            IFontDisp  * This,
            /* [out] */ UINT  *pctinfo);
        
        HRESULT ( __stdcall  *GetTypeInfo )( 
            IFontDisp  * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo  * *ppTInfo);
        
        HRESULT ( __stdcall  *GetIDsOfNames )( 
            IFontDisp  * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR  *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID  *rgDispId);
        
        /* [local] */ HRESULT ( __stdcall  *Invoke )( 
            IFontDisp  * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS  *pDispParams,
            /* [out] */ VARIANT  *pVarResult,
            /* [out] */ EXCEPINFO  *pExcepInfo,
            /* [out] */ UINT  *puArgErr);
        
        END_INTERFACE
    } IFontDispVtbl;

    interface IFontDisp
    {
        CONST_VTBL struct IFontDispVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFontDisp_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFontDisp_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFontDisp_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFontDisp_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFontDisp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFontDisp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFontDisp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFontDisp_INTERFACE_DEFINED__ */


#ifndef __IPictureDisp_INTERFACE_DEFINED__
#define __IPictureDisp_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPictureDisp
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef IPictureDisp  *LPPICTUREDISP;


EXTERN_C const IID IID_IPictureDisp;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IPictureDisp : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IPictureDispVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IPictureDisp  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IPictureDisp  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IPictureDisp  * This);
        
        HRESULT ( __stdcall  *GetTypeInfoCount )( 
            IPictureDisp  * This,
            /* [out] */ UINT  *pctinfo);
        
        HRESULT ( __stdcall  *GetTypeInfo )( 
            IPictureDisp  * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo  * *ppTInfo);
        
        HRESULT ( __stdcall  *GetIDsOfNames )( 
            IPictureDisp  * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR  *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID  *rgDispId);
        
        /* [local] */ HRESULT ( __stdcall  *Invoke )( 
            IPictureDisp  * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS  *pDispParams,
            /* [out] */ VARIANT  *pVarResult,
            /* [out] */ EXCEPINFO  *pExcepInfo,
            /* [out] */ UINT  *puArgErr);
        
        END_INTERFACE
    } IPictureDispVtbl;

    interface IPictureDisp
    {
        CONST_VTBL struct IPictureDispVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPictureDisp_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPictureDisp_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPictureDisp_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPictureDisp_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPictureDisp_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPictureDisp_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPictureDisp_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPictureDisp_INTERFACE_DEFINED__ */


#ifndef __IAdviseSinkEx_INTERFACE_DEFINED__
#define __IAdviseSinkEx_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAdviseSinkEx
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [uuid][unique][object] */ 


typedef IAdviseSinkEx  *LPADVISESINKEX;


EXTERN_C const IID IID_IAdviseSinkEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IAdviseSinkEx : public IAdviseSink
    {
    public:
        virtual /* [local] */ void __stdcall OnViewStatusChange( 
            /* [in] */ unsigned long dwViewStatus) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAdviseSinkExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IAdviseSinkEx  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IAdviseSinkEx  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IAdviseSinkEx  * This);
        
        /* [local] */ void ( __stdcall  *OnDataChange )( 
            IAdviseSinkEx  * This,
            /* [unique][in] */ FORMATETC  *pFormatetc,
            /* [unique][in] */ STGMEDIUM  *pStgmed);
        
        /* [local] */ void ( __stdcall  *OnViewChange )( 
            IAdviseSinkEx  * This,
            /* [in] */ unsigned long dwAspect,
            /* [in] */ LONG lindex);
        
        /* [local] */ void ( __stdcall  *OnRename )( 
            IAdviseSinkEx  * This,
            /* [in] */ IMoniker  *pmk);
        
        /* [local] */ void ( __stdcall  *OnSave )( 
            IAdviseSinkEx  * This);
        
        /* [local] */ void ( __stdcall  *OnClose )( 
            IAdviseSinkEx  * This);
        
        /* [local] */ void ( __stdcall  *OnViewStatusChange )( 
            IAdviseSinkEx  * This,
            /* [in] */ unsigned long dwViewStatus);
        
        END_INTERFACE
    } IAdviseSinkExVtbl;

    interface IAdviseSinkEx
    {
        CONST_VTBL struct IAdviseSinkExVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAdviseSinkEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAdviseSinkEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAdviseSinkEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAdviseSinkEx_OnDataChange(This,pFormatetc,pStgmed)	\
    (This)->lpVtbl -> OnDataChange(This,pFormatetc,pStgmed)

#define IAdviseSinkEx_OnViewChange(This,dwAspect,lindex)	\
    (This)->lpVtbl -> OnViewChange(This,dwAspect,lindex)

#define IAdviseSinkEx_OnRename(This,pmk)	\
    (This)->lpVtbl -> OnRename(This,pmk)

#define IAdviseSinkEx_OnSave(This)	\
    (This)->lpVtbl -> OnSave(This)

#define IAdviseSinkEx_OnClose(This)	\
    (This)->lpVtbl -> OnClose(This)


#define IAdviseSinkEx_OnViewStatusChange(This,dwViewStatus)	\
    (This)->lpVtbl -> OnViewStatusChange(This,dwViewStatus)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [async][call_as] */ void __stdcall IAdviseSinkEx_RemoteOnViewStatusChange_Proxy( 
    IAdviseSinkEx  * This,
    /* [in] */ unsigned long dwViewStatus);


void __stdcall IAdviseSinkEx_RemoteOnViewStatusChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IAdviseSinkEx_INTERFACE_DEFINED__ */


#ifndef __IOleInPlaceObjectWindowless_INTERFACE_DEFINED__
#define __IOleInPlaceObjectWindowless_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOleInPlaceObjectWindowless
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [uuid][unique][object][local] */ 


typedef IOleInPlaceObjectWindowless  *LPOLEINPLACEOBJECTWINDOWLESS;


EXTERN_C const IID IID_IOleInPlaceObjectWindowless;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IOleInPlaceObjectWindowless : public IOleInPlaceObject
    {
    public:
        virtual HRESULT __stdcall OnWindowMessage( 
            /* [in] */ UINT msg,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam,
            /* [out] */ LRESULT  *plResult) = 0;
        
        virtual HRESULT __stdcall GetDropTarget( 
            /* [out] */ IDropTarget  * *ppDropTarget) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOleInPlaceObjectWindowlessVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IOleInPlaceObjectWindowless  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IOleInPlaceObjectWindowless  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IOleInPlaceObjectWindowless  * This);
        
        /* [input_sync] */ HRESULT ( __stdcall  *GetWindow )( 
            IOleInPlaceObjectWindowless  * This,
            /* [out] */ HWND  *phwnd);
        
        HRESULT ( __stdcall  *ContextSensitiveHelp )( 
            IOleInPlaceObjectWindowless  * This,
            /* [in] */ BOOL fEnterMode);
        
        HRESULT ( __stdcall  *InPlaceDeactivate )( 
            IOleInPlaceObjectWindowless  * This);
        
        HRESULT ( __stdcall  *UIDeactivate )( 
            IOleInPlaceObjectWindowless  * This);
        
        /* [input_sync] */ HRESULT ( __stdcall  *SetObjectRects )( 
            IOleInPlaceObjectWindowless  * This,
            /* [in] */ LPCRECT lprcPosRect,
            /* [in] */ LPCRECT lprcClipRect);
        
        HRESULT ( __stdcall  *ReactivateAndUndo )( 
            IOleInPlaceObjectWindowless  * This);
        
        HRESULT ( __stdcall  *OnWindowMessage )( 
            IOleInPlaceObjectWindowless  * This,
            /* [in] */ UINT msg,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam,
            /* [out] */ LRESULT  *plResult);
        
        HRESULT ( __stdcall  *GetDropTarget )( 
            IOleInPlaceObjectWindowless  * This,
            /* [out] */ IDropTarget  * *ppDropTarget);
        
        END_INTERFACE
    } IOleInPlaceObjectWindowlessVtbl;

    interface IOleInPlaceObjectWindowless
    {
        CONST_VTBL struct IOleInPlaceObjectWindowlessVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleInPlaceObjectWindowless_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOleInPlaceObjectWindowless_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOleInPlaceObjectWindowless_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOleInPlaceObjectWindowless_GetWindow(This,phwnd)	\
    (This)->lpVtbl -> GetWindow(This,phwnd)

#define IOleInPlaceObjectWindowless_ContextSensitiveHelp(This,fEnterMode)	\
    (This)->lpVtbl -> ContextSensitiveHelp(This,fEnterMode)


#define IOleInPlaceObjectWindowless_InPlaceDeactivate(This)	\
    (This)->lpVtbl -> InPlaceDeactivate(This)

#define IOleInPlaceObjectWindowless_UIDeactivate(This)	\
    (This)->lpVtbl -> UIDeactivate(This)

#define IOleInPlaceObjectWindowless_SetObjectRects(This,lprcPosRect,lprcClipRect)	\
    (This)->lpVtbl -> SetObjectRects(This,lprcPosRect,lprcClipRect)

#define IOleInPlaceObjectWindowless_ReactivateAndUndo(This)	\
    (This)->lpVtbl -> ReactivateAndUndo(This)


#define IOleInPlaceObjectWindowless_OnWindowMessage(This,msg,wParam,lParam,plResult)	\
    (This)->lpVtbl -> OnWindowMessage(This,msg,wParam,lParam,plResult)

#define IOleInPlaceObjectWindowless_GetDropTarget(This,ppDropTarget)	\
    (This)->lpVtbl -> GetDropTarget(This,ppDropTarget)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IOleInPlaceObjectWindowless_OnWindowMessage_Proxy( 
    IOleInPlaceObjectWindowless  * This,
    /* [in] */ UINT msg,
    /* [in] */ WPARAM wParam,
    /* [in] */ LPARAM lParam,
    /* [out] */ LRESULT  *plResult);


void __stdcall IOleInPlaceObjectWindowless_OnWindowMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceObjectWindowless_GetDropTarget_Proxy( 
    IOleInPlaceObjectWindowless  * This,
    /* [out] */ IDropTarget  * *ppDropTarget);


void __stdcall IOleInPlaceObjectWindowless_GetDropTarget_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IOleInPlaceObjectWindowless_INTERFACE_DEFINED__ */


#ifndef __IOleInPlaceSiteEx_INTERFACE_DEFINED__
#define __IOleInPlaceSiteEx_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOleInPlaceSiteEx
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [uuid][unique][object] */ 


typedef IOleInPlaceSiteEx  *LPOLEINPLACESITEEX;

typedef /* [v1_enum] */ 
enum tagACTIVATEFLAGS
    {	ACTIVATE_WINDOWLESS	= 1
    }	ACTIVATEFLAGS;


EXTERN_C const IID IID_IOleInPlaceSiteEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IOleInPlaceSiteEx : public IOleInPlaceSite
    {
    public:
        virtual HRESULT __stdcall OnInPlaceActivateEx( 
            /* [out] */ BOOL  *pfNoRedraw,
            /* [in] */ unsigned long dwFlags) = 0;
        
        virtual HRESULT __stdcall OnInPlaceDeactivateEx( 
            /* [in] */ BOOL fNoRedraw) = 0;
        
        virtual HRESULT __stdcall RequestUIActivate( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOleInPlaceSiteExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IOleInPlaceSiteEx  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IOleInPlaceSiteEx  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IOleInPlaceSiteEx  * This);
        
        /* [input_sync] */ HRESULT ( __stdcall  *GetWindow )( 
            IOleInPlaceSiteEx  * This,
            /* [out] */ HWND  *phwnd);
        
        HRESULT ( __stdcall  *ContextSensitiveHelp )( 
            IOleInPlaceSiteEx  * This,
            /* [in] */ BOOL fEnterMode);
        
        HRESULT ( __stdcall  *CanInPlaceActivate )( 
            IOleInPlaceSiteEx  * This);
        
        HRESULT ( __stdcall  *OnInPlaceActivate )( 
            IOleInPlaceSiteEx  * This);
        
        HRESULT ( __stdcall  *OnUIActivate )( 
            IOleInPlaceSiteEx  * This);
        
        HRESULT ( __stdcall  *GetWindowContext )( 
            IOleInPlaceSiteEx  * This,
            /* [out] */ IOleInPlaceFrame  * *ppFrame,
            /* [out] */ IOleInPlaceUIWindow  * *ppDoc,
            /* [out] */ LPRECT lprcPosRect,
            /* [out] */ LPRECT lprcClipRect,
            /* [out][in] */ LPOLEINPLACEFRAMEINFO lpFrameInfo);
        
        HRESULT ( __stdcall  *Scroll )( 
            IOleInPlaceSiteEx  * This,
            /* [in] */ SIZE scrollExtant);
        
        HRESULT ( __stdcall  *OnUIDeactivate )( 
            IOleInPlaceSiteEx  * This,
            /* [in] */ BOOL fUndoable);
        
        HRESULT ( __stdcall  *OnInPlaceDeactivate )( 
            IOleInPlaceSiteEx  * This);
        
        HRESULT ( __stdcall  *DiscardUndoState )( 
            IOleInPlaceSiteEx  * This);
        
        HRESULT ( __stdcall  *DeactivateAndUndo )( 
            IOleInPlaceSiteEx  * This);
        
        HRESULT ( __stdcall  *OnPosRectChange )( 
            IOleInPlaceSiteEx  * This,
            /* [in] */ LPCRECT lprcPosRect);
        
        HRESULT ( __stdcall  *OnInPlaceActivateEx )( 
            IOleInPlaceSiteEx  * This,
            /* [out] */ BOOL  *pfNoRedraw,
            /* [in] */ unsigned long dwFlags);
        
        HRESULT ( __stdcall  *OnInPlaceDeactivateEx )( 
            IOleInPlaceSiteEx  * This,
            /* [in] */ BOOL fNoRedraw);
        
        HRESULT ( __stdcall  *RequestUIActivate )( 
            IOleInPlaceSiteEx  * This);
        
        END_INTERFACE
    } IOleInPlaceSiteExVtbl;

    interface IOleInPlaceSiteEx
    {
        CONST_VTBL struct IOleInPlaceSiteExVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleInPlaceSiteEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOleInPlaceSiteEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOleInPlaceSiteEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOleInPlaceSiteEx_GetWindow(This,phwnd)	\
    (This)->lpVtbl -> GetWindow(This,phwnd)

#define IOleInPlaceSiteEx_ContextSensitiveHelp(This,fEnterMode)	\
    (This)->lpVtbl -> ContextSensitiveHelp(This,fEnterMode)


#define IOleInPlaceSiteEx_CanInPlaceActivate(This)	\
    (This)->lpVtbl -> CanInPlaceActivate(This)

#define IOleInPlaceSiteEx_OnInPlaceActivate(This)	\
    (This)->lpVtbl -> OnInPlaceActivate(This)

#define IOleInPlaceSiteEx_OnUIActivate(This)	\
    (This)->lpVtbl -> OnUIActivate(This)

#define IOleInPlaceSiteEx_GetWindowContext(This,ppFrame,ppDoc,lprcPosRect,lprcClipRect,lpFrameInfo)	\
    (This)->lpVtbl -> GetWindowContext(This,ppFrame,ppDoc,lprcPosRect,lprcClipRect,lpFrameInfo)

#define IOleInPlaceSiteEx_Scroll(This,scrollExtant)	\
    (This)->lpVtbl -> Scroll(This,scrollExtant)

#define IOleInPlaceSiteEx_OnUIDeactivate(This,fUndoable)	\
    (This)->lpVtbl -> OnUIDeactivate(This,fUndoable)

#define IOleInPlaceSiteEx_OnInPlaceDeactivate(This)	\
    (This)->lpVtbl -> OnInPlaceDeactivate(This)

#define IOleInPlaceSiteEx_DiscardUndoState(This)	\
    (This)->lpVtbl -> DiscardUndoState(This)

#define IOleInPlaceSiteEx_DeactivateAndUndo(This)	\
    (This)->lpVtbl -> DeactivateAndUndo(This)

#define IOleInPlaceSiteEx_OnPosRectChange(This,lprcPosRect)	\
    (This)->lpVtbl -> OnPosRectChange(This,lprcPosRect)


#define IOleInPlaceSiteEx_OnInPlaceActivateEx(This,pfNoRedraw,dwFlags)	\
    (This)->lpVtbl -> OnInPlaceActivateEx(This,pfNoRedraw,dwFlags)

#define IOleInPlaceSiteEx_OnInPlaceDeactivateEx(This,fNoRedraw)	\
    (This)->lpVtbl -> OnInPlaceDeactivateEx(This,fNoRedraw)

#define IOleInPlaceSiteEx_RequestUIActivate(This)	\
    (This)->lpVtbl -> RequestUIActivate(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IOleInPlaceSiteEx_OnInPlaceActivateEx_Proxy( 
    IOleInPlaceSiteEx  * This,
    /* [out] */ BOOL  *pfNoRedraw,
    /* [in] */ unsigned long dwFlags);


void __stdcall IOleInPlaceSiteEx_OnInPlaceActivateEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceSiteEx_OnInPlaceDeactivateEx_Proxy( 
    IOleInPlaceSiteEx  * This,
    /* [in] */ BOOL fNoRedraw);


void __stdcall IOleInPlaceSiteEx_OnInPlaceDeactivateEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceSiteEx_RequestUIActivate_Proxy( 
    IOleInPlaceSiteEx  * This);


void __stdcall IOleInPlaceSiteEx_RequestUIActivate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IOleInPlaceSiteEx_INTERFACE_DEFINED__ */


#ifndef __IOleInPlaceSiteWindowless_INTERFACE_DEFINED__
#define __IOleInPlaceSiteWindowless_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOleInPlaceSiteWindowless
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [uuid][unique][object][local] */ 


typedef IOleInPlaceSiteWindowless  *LPOLEINPLACESITEWINDOWLESS;

typedef /* [v1_enum] */ 
enum tagOLEDCFLAGS
    {	OLEDC_NODRAW	= 0x1,
	OLEDC_PAINTBKGND	= 0x2,
	OLEDC_OFFSCREEN	= 0x4
    }	OLEDCFLAGS;


EXTERN_C const IID IID_IOleInPlaceSiteWindowless;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IOleInPlaceSiteWindowless : public IOleInPlaceSiteEx
    {
    public:
        virtual HRESULT __stdcall CanWindowlessActivate( void) = 0;
        
        virtual HRESULT __stdcall GetCapture( void) = 0;
        
        virtual HRESULT __stdcall SetCapture( 
            /* [in] */ BOOL fCapture) = 0;
        
        virtual HRESULT __stdcall GetFocus( void) = 0;
        
        virtual HRESULT __stdcall SetFocus( 
            /* [in] */ BOOL fFocus) = 0;
        
        virtual HRESULT __stdcall GetDC( 
            /* [in] */ LPCRECT pRect,
            /* [in] */ unsigned long grfFlags,
            /* [out] */ HDC  *phDC) = 0;
        
        virtual HRESULT __stdcall ReleaseDC( 
            /* [in] */ HDC hDC) = 0;
        
        virtual HRESULT __stdcall InvalidateRect( 
            /* [in] */ LPCRECT pRect,
            /* [in] */ BOOL fErase) = 0;
        
        virtual HRESULT __stdcall InvalidateRgn( 
            /* [in] */ HRGN hRGN,
            /* [in] */ BOOL fErase) = 0;
        
        virtual HRESULT __stdcall ScrollRect( 
            /* [in] */ INT dx,
            /* [in] */ INT dy,
            /* [in] */ LPCRECT pRectScroll,
            /* [in] */ LPCRECT pRectClip) = 0;
        
        virtual HRESULT __stdcall AdjustRect( 
            /* [out][in] */ LPRECT prc) = 0;
        
        virtual HRESULT __stdcall OnDefWindowMessage( 
            /* [in] */ UINT msg,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam,
            /* [out] */ LRESULT  *plResult) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOleInPlaceSiteWindowlessVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IOleInPlaceSiteWindowless  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IOleInPlaceSiteWindowless  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IOleInPlaceSiteWindowless  * This);
        
        /* [input_sync] */ HRESULT ( __stdcall  *GetWindow )( 
            IOleInPlaceSiteWindowless  * This,
            /* [out] */ HWND  *phwnd);
        
        HRESULT ( __stdcall  *ContextSensitiveHelp )( 
            IOleInPlaceSiteWindowless  * This,
            /* [in] */ BOOL fEnterMode);
        
        HRESULT ( __stdcall  *CanInPlaceActivate )( 
            IOleInPlaceSiteWindowless  * This);
        
        HRESULT ( __stdcall  *OnInPlaceActivate )( 
            IOleInPlaceSiteWindowless  * This);
        
        HRESULT ( __stdcall  *OnUIActivate )( 
            IOleInPlaceSiteWindowless  * This);
        
        HRESULT ( __stdcall  *GetWindowContext )( 
            IOleInPlaceSiteWindowless  * This,
            /* [out] */ IOleInPlaceFrame  * *ppFrame,
            /* [out] */ IOleInPlaceUIWindow  * *ppDoc,
            /* [out] */ LPRECT lprcPosRect,
            /* [out] */ LPRECT lprcClipRect,
            /* [out][in] */ LPOLEINPLACEFRAMEINFO lpFrameInfo);
        
        HRESULT ( __stdcall  *Scroll )( 
            IOleInPlaceSiteWindowless  * This,
            /* [in] */ SIZE scrollExtant);
        
        HRESULT ( __stdcall  *OnUIDeactivate )( 
            IOleInPlaceSiteWindowless  * This,
            /* [in] */ BOOL fUndoable);
        
        HRESULT ( __stdcall  *OnInPlaceDeactivate )( 
            IOleInPlaceSiteWindowless  * This);
        
        HRESULT ( __stdcall  *DiscardUndoState )( 
            IOleInPlaceSiteWindowless  * This);
        
        HRESULT ( __stdcall  *DeactivateAndUndo )( 
            IOleInPlaceSiteWindowless  * This);
        
        HRESULT ( __stdcall  *OnPosRectChange )( 
            IOleInPlaceSiteWindowless  * This,
            /* [in] */ LPCRECT lprcPosRect);
        
        HRESULT ( __stdcall  *OnInPlaceActivateEx )( 
            IOleInPlaceSiteWindowless  * This,
            /* [out] */ BOOL  *pfNoRedraw,
            /* [in] */ unsigned long dwFlags);
        
        HRESULT ( __stdcall  *OnInPlaceDeactivateEx )( 
            IOleInPlaceSiteWindowless  * This,
            /* [in] */ BOOL fNoRedraw);
        
        HRESULT ( __stdcall  *RequestUIActivate )( 
            IOleInPlaceSiteWindowless  * This);
        
        HRESULT ( __stdcall  *CanWindowlessActivate )( 
            IOleInPlaceSiteWindowless  * This);
        
        HRESULT ( __stdcall  *GetCapture )( 
            IOleInPlaceSiteWindowless  * This);
        
        HRESULT ( __stdcall  *SetCapture )( 
            IOleInPlaceSiteWindowless  * This,
            /* [in] */ BOOL fCapture);
        
        HRESULT ( __stdcall  *GetFocus )( 
            IOleInPlaceSiteWindowless  * This);
        
        HRESULT ( __stdcall  *SetFocus )( 
            IOleInPlaceSiteWindowless  * This,
            /* [in] */ BOOL fFocus);
        
        HRESULT ( __stdcall  *GetDC )( 
            IOleInPlaceSiteWindowless  * This,
            /* [in] */ LPCRECT pRect,
            /* [in] */ unsigned long grfFlags,
            /* [out] */ HDC  *phDC);
        
        HRESULT ( __stdcall  *ReleaseDC )( 
            IOleInPlaceSiteWindowless  * This,
            /* [in] */ HDC hDC);
        
        HRESULT ( __stdcall  *InvalidateRect )( 
            IOleInPlaceSiteWindowless  * This,
            /* [in] */ LPCRECT pRect,
            /* [in] */ BOOL fErase);
        
        HRESULT ( __stdcall  *InvalidateRgn )( 
            IOleInPlaceSiteWindowless  * This,
            /* [in] */ HRGN hRGN,
            /* [in] */ BOOL fErase);
        
        HRESULT ( __stdcall  *ScrollRect )( 
            IOleInPlaceSiteWindowless  * This,
            /* [in] */ INT dx,
            /* [in] */ INT dy,
            /* [in] */ LPCRECT pRectScroll,
            /* [in] */ LPCRECT pRectClip);
        
        HRESULT ( __stdcall  *AdjustRect )( 
            IOleInPlaceSiteWindowless  * This,
            /* [out][in] */ LPRECT prc);
        
        HRESULT ( __stdcall  *OnDefWindowMessage )( 
            IOleInPlaceSiteWindowless  * This,
            /* [in] */ UINT msg,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam,
            /* [out] */ LRESULT  *plResult);
        
        END_INTERFACE
    } IOleInPlaceSiteWindowlessVtbl;

    interface IOleInPlaceSiteWindowless
    {
        CONST_VTBL struct IOleInPlaceSiteWindowlessVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleInPlaceSiteWindowless_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOleInPlaceSiteWindowless_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOleInPlaceSiteWindowless_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOleInPlaceSiteWindowless_GetWindow(This,phwnd)	\
    (This)->lpVtbl -> GetWindow(This,phwnd)

#define IOleInPlaceSiteWindowless_ContextSensitiveHelp(This,fEnterMode)	\
    (This)->lpVtbl -> ContextSensitiveHelp(This,fEnterMode)


#define IOleInPlaceSiteWindowless_CanInPlaceActivate(This)	\
    (This)->lpVtbl -> CanInPlaceActivate(This)

#define IOleInPlaceSiteWindowless_OnInPlaceActivate(This)	\
    (This)->lpVtbl -> OnInPlaceActivate(This)

#define IOleInPlaceSiteWindowless_OnUIActivate(This)	\
    (This)->lpVtbl -> OnUIActivate(This)

#define IOleInPlaceSiteWindowless_GetWindowContext(This,ppFrame,ppDoc,lprcPosRect,lprcClipRect,lpFrameInfo)	\
    (This)->lpVtbl -> GetWindowContext(This,ppFrame,ppDoc,lprcPosRect,lprcClipRect,lpFrameInfo)

#define IOleInPlaceSiteWindowless_Scroll(This,scrollExtant)	\
    (This)->lpVtbl -> Scroll(This,scrollExtant)

#define IOleInPlaceSiteWindowless_OnUIDeactivate(This,fUndoable)	\
    (This)->lpVtbl -> OnUIDeactivate(This,fUndoable)

#define IOleInPlaceSiteWindowless_OnInPlaceDeactivate(This)	\
    (This)->lpVtbl -> OnInPlaceDeactivate(This)

#define IOleInPlaceSiteWindowless_DiscardUndoState(This)	\
    (This)->lpVtbl -> DiscardUndoState(This)

#define IOleInPlaceSiteWindowless_DeactivateAndUndo(This)	\
    (This)->lpVtbl -> DeactivateAndUndo(This)

#define IOleInPlaceSiteWindowless_OnPosRectChange(This,lprcPosRect)	\
    (This)->lpVtbl -> OnPosRectChange(This,lprcPosRect)


#define IOleInPlaceSiteWindowless_OnInPlaceActivateEx(This,pfNoRedraw,dwFlags)	\
    (This)->lpVtbl -> OnInPlaceActivateEx(This,pfNoRedraw,dwFlags)

#define IOleInPlaceSiteWindowless_OnInPlaceDeactivateEx(This,fNoRedraw)	\
    (This)->lpVtbl -> OnInPlaceDeactivateEx(This,fNoRedraw)

#define IOleInPlaceSiteWindowless_RequestUIActivate(This)	\
    (This)->lpVtbl -> RequestUIActivate(This)


#define IOleInPlaceSiteWindowless_CanWindowlessActivate(This)	\
    (This)->lpVtbl -> CanWindowlessActivate(This)

#define IOleInPlaceSiteWindowless_GetCapture(This)	\
    (This)->lpVtbl -> GetCapture(This)

#define IOleInPlaceSiteWindowless_SetCapture(This,fCapture)	\
    (This)->lpVtbl -> SetCapture(This,fCapture)

#define IOleInPlaceSiteWindowless_GetFocus(This)	\
    (This)->lpVtbl -> GetFocus(This)

#define IOleInPlaceSiteWindowless_SetFocus(This,fFocus)	\
    (This)->lpVtbl -> SetFocus(This,fFocus)

#define IOleInPlaceSiteWindowless_GetDC(This,pRect,grfFlags,phDC)	\
    (This)->lpVtbl -> GetDC(This,pRect,grfFlags,phDC)

#define IOleInPlaceSiteWindowless_ReleaseDC(This,hDC)	\
    (This)->lpVtbl -> ReleaseDC(This,hDC)

#define IOleInPlaceSiteWindowless_InvalidateRect(This,pRect,fErase)	\
    (This)->lpVtbl -> InvalidateRect(This,pRect,fErase)

#define IOleInPlaceSiteWindowless_InvalidateRgn(This,hRGN,fErase)	\
    (This)->lpVtbl -> InvalidateRgn(This,hRGN,fErase)

#define IOleInPlaceSiteWindowless_ScrollRect(This,dx,dy,pRectScroll,pRectClip)	\
    (This)->lpVtbl -> ScrollRect(This,dx,dy,pRectScroll,pRectClip)

#define IOleInPlaceSiteWindowless_AdjustRect(This,prc)	\
    (This)->lpVtbl -> AdjustRect(This,prc)

#define IOleInPlaceSiteWindowless_OnDefWindowMessage(This,msg,wParam,lParam,plResult)	\
    (This)->lpVtbl -> OnDefWindowMessage(This,msg,wParam,lParam,plResult)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IOleInPlaceSiteWindowless_CanWindowlessActivate_Proxy( 
    IOleInPlaceSiteWindowless  * This);


void __stdcall IOleInPlaceSiteWindowless_CanWindowlessActivate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceSiteWindowless_GetCapture_Proxy( 
    IOleInPlaceSiteWindowless  * This);


void __stdcall IOleInPlaceSiteWindowless_GetCapture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceSiteWindowless_SetCapture_Proxy( 
    IOleInPlaceSiteWindowless  * This,
    /* [in] */ BOOL fCapture);


void __stdcall IOleInPlaceSiteWindowless_SetCapture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceSiteWindowless_GetFocus_Proxy( 
    IOleInPlaceSiteWindowless  * This);


void __stdcall IOleInPlaceSiteWindowless_GetFocus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceSiteWindowless_SetFocus_Proxy( 
    IOleInPlaceSiteWindowless  * This,
    /* [in] */ BOOL fFocus);


void __stdcall IOleInPlaceSiteWindowless_SetFocus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceSiteWindowless_GetDC_Proxy( 
    IOleInPlaceSiteWindowless  * This,
    /* [in] */ LPCRECT pRect,
    /* [in] */ unsigned long grfFlags,
    /* [out] */ HDC  *phDC);


void __stdcall IOleInPlaceSiteWindowless_GetDC_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceSiteWindowless_ReleaseDC_Proxy( 
    IOleInPlaceSiteWindowless  * This,
    /* [in] */ HDC hDC);


void __stdcall IOleInPlaceSiteWindowless_ReleaseDC_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceSiteWindowless_InvalidateRect_Proxy( 
    IOleInPlaceSiteWindowless  * This,
    /* [in] */ LPCRECT pRect,
    /* [in] */ BOOL fErase);


void __stdcall IOleInPlaceSiteWindowless_InvalidateRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceSiteWindowless_InvalidateRgn_Proxy( 
    IOleInPlaceSiteWindowless  * This,
    /* [in] */ HRGN hRGN,
    /* [in] */ BOOL fErase);


void __stdcall IOleInPlaceSiteWindowless_InvalidateRgn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceSiteWindowless_ScrollRect_Proxy( 
    IOleInPlaceSiteWindowless  * This,
    /* [in] */ INT dx,
    /* [in] */ INT dy,
    /* [in] */ LPCRECT pRectScroll,
    /* [in] */ LPCRECT pRectClip);


void __stdcall IOleInPlaceSiteWindowless_ScrollRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceSiteWindowless_AdjustRect_Proxy( 
    IOleInPlaceSiteWindowless  * This,
    /* [out][in] */ LPRECT prc);


void __stdcall IOleInPlaceSiteWindowless_AdjustRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleInPlaceSiteWindowless_OnDefWindowMessage_Proxy( 
    IOleInPlaceSiteWindowless  * This,
    /* [in] */ UINT msg,
    /* [in] */ WPARAM wParam,
    /* [in] */ LPARAM lParam,
    /* [out] */ LRESULT  *plResult);


void __stdcall IOleInPlaceSiteWindowless_OnDefWindowMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IOleInPlaceSiteWindowless_INTERFACE_DEFINED__ */


#ifndef __IViewObjectEx_INTERFACE_DEFINED__
#define __IViewObjectEx_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IViewObjectEx
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [uuid][unique][object][local] */ 


typedef IViewObjectEx  *LPVIEWOBJECTEX;

typedef /* [v1_enum] */ 
enum tagVIEWSTATUS
    {	VIEWSTATUS_OPAQUE	= 1,
	VIEWSTATUS_SOLIDBKGND	= 2,
	VIEWSTATUS_DVASPECTOPAQUE	= 4,
	VIEWSTATUS_DVASPECTTRANSPARENT	= 8
    }	VIEWSTATUS;

typedef /* [v1_enum] */ 
enum tagHITRESULT
    {	HITRESULT_OUTSIDE	= 0,
	HITRESULT_TRANSPARENT	= 1,
	HITRESULT_CLOSE	= 2,
	HITRESULT_HIT	= 3
    }	HITRESULT;

typedef /* [v1_enum] */ 
enum tagDVASPECT2
    {	DVASPECT_OPAQUE	= 16,
	DVASPECT_TRANSPARENT	= 32
    }	DVASPECT2;

typedef struct  tagExtentInfo
    {
    unsigned long cb;
    unsigned long dwExtentMode;
    SIZEL sizelProposed;
    }	DVEXTENTINFO;

typedef /* [v1_enum] */ 
enum tagExtentMode
    {	DVEXTENT_CONTENT	= 0,
	DVEXTENT_INTEGRAL	= DVEXTENT_CONTENT + 1
    }	DVEXTENTMODE;

typedef /* [v1_enum] */ 
enum tagAspectInfoFlag
    {	DVASPECTINFOFLAG_CANOPTIMIZE	= 1
    }	DVASPECTINFOFLAG;

typedef struct  tagAspectInfo
    {
    unsigned long cb;
    unsigned long dwFlags;
    }	DVASPECTINFO;


EXTERN_C const IID IID_IViewObjectEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IViewObjectEx : public IViewObject2
    {
    public:
        virtual HRESULT __stdcall GetRect( 
            /* [in] */ unsigned long dwAspect,
            /* [out] */ LPRECTL pRect) = 0;
        
        virtual HRESULT __stdcall GetViewStatus( 
            /* [out] */ unsigned long  *pdwStatus) = 0;
        
        virtual HRESULT __stdcall QueryHitPoint( 
            /* [in] */ unsigned long dwAspect,
            /* [in] */ LPCRECT pRectBounds,
            /* [in] */ POINT ptlLoc,
            /* [in] */ LONG lCloseHint,
            /* [out] */ unsigned long  *pHitResult) = 0;
        
        virtual HRESULT __stdcall QueryHitRect( 
            /* [in] */ unsigned long dwAspect,
            /* [in] */ LPCRECT pRectBounds,
            /* [in] */ LPCRECT pRectLoc,
            /* [in] */ LONG lCloseHint,
            /* [out] */ unsigned long  *pHitResult) = 0;
        
        virtual HRESULT __stdcall GetNaturalExtent( 
            /* [in] */ unsigned long dwAspect,
            /* [in] */ LONG lindex,
            /* [in] */ DVTARGETDEVICE  *ptd,
            /* [in] */ HDC hicTargetDev,
            /* [in] */ DVEXTENTINFO  *pExtentInfo,
            /* [out] */ LPSIZEL pSizel) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IViewObjectExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IViewObjectEx  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IViewObjectEx  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IViewObjectEx  * This);
        
        /* [local] */ HRESULT ( __stdcall  *Draw )( 
            IViewObjectEx  * This,
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
            IViewObjectEx  * This,
            /* [in] */ unsigned long dwDrawAspect,
            /* [in] */ LONG lindex,
            /* [unique][in] */ void  *pvAspect,
            /* [unique][in] */ DVTARGETDEVICE  *ptd,
            /* [in] */ HDC hicTargetDev,
            /* [out] */ LOGPALETTE  * *ppColorSet);
        
        /* [local] */ HRESULT ( __stdcall  *Freeze )( 
            IViewObjectEx  * This,
            /* [in] */ unsigned long dwDrawAspect,
            /* [in] */ LONG lindex,
            /* [unique][in] */ void  *pvAspect,
            /* [out] */ unsigned long  *pdwFreeze);
        
        HRESULT ( __stdcall  *Unfreeze )( 
            IViewObjectEx  * This,
            /* [in] */ unsigned long dwFreeze);
        
        HRESULT ( __stdcall  *SetAdvise )( 
            IViewObjectEx  * This,
            /* [in] */ unsigned long aspects,
            /* [in] */ unsigned long advf,
            /* [unique][in] */ IAdviseSink  *pAdvSink);
        
        HRESULT ( __stdcall  *GetAdvise )( 
            IViewObjectEx  * This,
            /* [out] */ unsigned long  *pAspects,
            /* [out] */ unsigned long  *pAdvf,
            /* [out] */ IAdviseSink  * *ppAdvSink);
        
        HRESULT ( __stdcall  *GetExtent )( 
            IViewObjectEx  * This,
            /* [in] */ unsigned long dwDrawAspect,
            /* [in] */ LONG lindex,
            /* [unique][in] */ DVTARGETDEVICE  *ptd,
            /* [out] */ LPSIZEL lpsizel);
        
        HRESULT ( __stdcall  *GetRect )( 
            IViewObjectEx  * This,
            /* [in] */ unsigned long dwAspect,
            /* [out] */ LPRECTL pRect);
        
        HRESULT ( __stdcall  *GetViewStatus )( 
            IViewObjectEx  * This,
            /* [out] */ unsigned long  *pdwStatus);
        
        HRESULT ( __stdcall  *QueryHitPoint )( 
            IViewObjectEx  * This,
            /* [in] */ unsigned long dwAspect,
            /* [in] */ LPCRECT pRectBounds,
            /* [in] */ POINT ptlLoc,
            /* [in] */ LONG lCloseHint,
            /* [out] */ unsigned long  *pHitResult);
        
        HRESULT ( __stdcall  *QueryHitRect )( 
            IViewObjectEx  * This,
            /* [in] */ unsigned long dwAspect,
            /* [in] */ LPCRECT pRectBounds,
            /* [in] */ LPCRECT pRectLoc,
            /* [in] */ LONG lCloseHint,
            /* [out] */ unsigned long  *pHitResult);
        
        HRESULT ( __stdcall  *GetNaturalExtent )( 
            IViewObjectEx  * This,
            /* [in] */ unsigned long dwAspect,
            /* [in] */ LONG lindex,
            /* [in] */ DVTARGETDEVICE  *ptd,
            /* [in] */ HDC hicTargetDev,
            /* [in] */ DVEXTENTINFO  *pExtentInfo,
            /* [out] */ LPSIZEL pSizel);
        
        END_INTERFACE
    } IViewObjectExVtbl;

    interface IViewObjectEx
    {
        CONST_VTBL struct IViewObjectExVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IViewObjectEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IViewObjectEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IViewObjectEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IViewObjectEx_Draw(This,dwDrawAspect,lindex,pvAspect,ptd,hdcTargetDev,hdcDraw,lprcBounds,lprcWBounds,pfnContinue,dwContinue)	\
    (This)->lpVtbl -> Draw(This,dwDrawAspect,lindex,pvAspect,ptd,hdcTargetDev,hdcDraw,lprcBounds,lprcWBounds,pfnContinue,dwContinue)

#define IViewObjectEx_GetColorSet(This,dwDrawAspect,lindex,pvAspect,ptd,hicTargetDev,ppColorSet)	\
    (This)->lpVtbl -> GetColorSet(This,dwDrawAspect,lindex,pvAspect,ptd,hicTargetDev,ppColorSet)

#define IViewObjectEx_Freeze(This,dwDrawAspect,lindex,pvAspect,pdwFreeze)	\
    (This)->lpVtbl -> Freeze(This,dwDrawAspect,lindex,pvAspect,pdwFreeze)

#define IViewObjectEx_Unfreeze(This,dwFreeze)	\
    (This)->lpVtbl -> Unfreeze(This,dwFreeze)

#define IViewObjectEx_SetAdvise(This,aspects,advf,pAdvSink)	\
    (This)->lpVtbl -> SetAdvise(This,aspects,advf,pAdvSink)

#define IViewObjectEx_GetAdvise(This,pAspects,pAdvf,ppAdvSink)	\
    (This)->lpVtbl -> GetAdvise(This,pAspects,pAdvf,ppAdvSink)


#define IViewObjectEx_GetExtent(This,dwDrawAspect,lindex,ptd,lpsizel)	\
    (This)->lpVtbl -> GetExtent(This,dwDrawAspect,lindex,ptd,lpsizel)


#define IViewObjectEx_GetRect(This,dwAspect,pRect)	\
    (This)->lpVtbl -> GetRect(This,dwAspect,pRect)

#define IViewObjectEx_GetViewStatus(This,pdwStatus)	\
    (This)->lpVtbl -> GetViewStatus(This,pdwStatus)

#define IViewObjectEx_QueryHitPoint(This,dwAspect,pRectBounds,ptlLoc,lCloseHint,pHitResult)	\
    (This)->lpVtbl -> QueryHitPoint(This,dwAspect,pRectBounds,ptlLoc,lCloseHint,pHitResult)

#define IViewObjectEx_QueryHitRect(This,dwAspect,pRectBounds,pRectLoc,lCloseHint,pHitResult)	\
    (This)->lpVtbl -> QueryHitRect(This,dwAspect,pRectBounds,pRectLoc,lCloseHint,pHitResult)

#define IViewObjectEx_GetNaturalExtent(This,dwAspect,lindex,ptd,hicTargetDev,pExtentInfo,pSizel)	\
    (This)->lpVtbl -> GetNaturalExtent(This,dwAspect,lindex,ptd,hicTargetDev,pExtentInfo,pSizel)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IViewObjectEx_GetRect_Proxy( 
    IViewObjectEx  * This,
    /* [in] */ unsigned long dwAspect,
    /* [out] */ LPRECTL pRect);


void __stdcall IViewObjectEx_GetRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IViewObjectEx_GetViewStatus_Proxy( 
    IViewObjectEx  * This,
    /* [out] */ unsigned long  *pdwStatus);


void __stdcall IViewObjectEx_GetViewStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IViewObjectEx_QueryHitPoint_Proxy( 
    IViewObjectEx  * This,
    /* [in] */ unsigned long dwAspect,
    /* [in] */ LPCRECT pRectBounds,
    /* [in] */ POINT ptlLoc,
    /* [in] */ LONG lCloseHint,
    /* [out] */ unsigned long  *pHitResult);


void __stdcall IViewObjectEx_QueryHitPoint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IViewObjectEx_QueryHitRect_Proxy( 
    IViewObjectEx  * This,
    /* [in] */ unsigned long dwAspect,
    /* [in] */ LPCRECT pRectBounds,
    /* [in] */ LPCRECT pRectLoc,
    /* [in] */ LONG lCloseHint,
    /* [out] */ unsigned long  *pHitResult);


void __stdcall IViewObjectEx_QueryHitRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IViewObjectEx_GetNaturalExtent_Proxy( 
    IViewObjectEx  * This,
    /* [in] */ unsigned long dwAspect,
    /* [in] */ LONG lindex,
    /* [in] */ DVTARGETDEVICE  *ptd,
    /* [in] */ HDC hicTargetDev,
    /* [in] */ DVEXTENTINFO  *pExtentInfo,
    /* [out] */ LPSIZEL pSizel);


void __stdcall IViewObjectEx_GetNaturalExtent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IViewObjectEx_INTERFACE_DEFINED__ */


#ifndef __IOleUndoUnit_INTERFACE_DEFINED__
#define __IOleUndoUnit_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOleUndoUnit
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [uuid][unique][object] */ 


typedef IOleUndoUnit  *LPOLEUNDOUNIT;


EXTERN_C const IID IID_IOleUndoUnit;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IOleUndoUnit : public IUnknown
    {
    public:
        virtual HRESULT __stdcall Do( 
            /* [in] */ IOleUndoManager  *pUndoManager) = 0;
        
        virtual HRESULT __stdcall GetDescription( 
            /* [out] */ BSTR  *pBstr) = 0;
        
        virtual HRESULT __stdcall GetUnitType( 
            /* [out] */ CLSID  *pClsid,
            /* [out] */ LONG  *plID) = 0;
        
        virtual HRESULT __stdcall OnNextAdd( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOleUndoUnitVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IOleUndoUnit  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IOleUndoUnit  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IOleUndoUnit  * This);
        
        HRESULT ( __stdcall  *Do )( 
            IOleUndoUnit  * This,
            /* [in] */ IOleUndoManager  *pUndoManager);
        
        HRESULT ( __stdcall  *GetDescription )( 
            IOleUndoUnit  * This,
            /* [out] */ BSTR  *pBstr);
        
        HRESULT ( __stdcall  *GetUnitType )( 
            IOleUndoUnit  * This,
            /* [out] */ CLSID  *pClsid,
            /* [out] */ LONG  *plID);
        
        HRESULT ( __stdcall  *OnNextAdd )( 
            IOleUndoUnit  * This);
        
        END_INTERFACE
    } IOleUndoUnitVtbl;

    interface IOleUndoUnit
    {
        CONST_VTBL struct IOleUndoUnitVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleUndoUnit_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOleUndoUnit_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOleUndoUnit_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOleUndoUnit_Do(This,pUndoManager)	\
    (This)->lpVtbl -> Do(This,pUndoManager)

#define IOleUndoUnit_GetDescription(This,pBstr)	\
    (This)->lpVtbl -> GetDescription(This,pBstr)

#define IOleUndoUnit_GetUnitType(This,pClsid,plID)	\
    (This)->lpVtbl -> GetUnitType(This,pClsid,plID)

#define IOleUndoUnit_OnNextAdd(This)	\
    (This)->lpVtbl -> OnNextAdd(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IOleUndoUnit_Do_Proxy( 
    IOleUndoUnit  * This,
    /* [in] */ IOleUndoManager  *pUndoManager);


void __stdcall IOleUndoUnit_Do_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleUndoUnit_GetDescription_Proxy( 
    IOleUndoUnit  * This,
    /* [out] */ BSTR  *pBstr);


void __stdcall IOleUndoUnit_GetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleUndoUnit_GetUnitType_Proxy( 
    IOleUndoUnit  * This,
    /* [out] */ CLSID  *pClsid,
    /* [out] */ LONG  *plID);


void __stdcall IOleUndoUnit_GetUnitType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleUndoUnit_OnNextAdd_Proxy( 
    IOleUndoUnit  * This);


void __stdcall IOleUndoUnit_OnNextAdd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IOleUndoUnit_INTERFACE_DEFINED__ */


#ifndef __IOleParentUndoUnit_INTERFACE_DEFINED__
#define __IOleParentUndoUnit_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOleParentUndoUnit
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [uuid][unique][object] */ 


typedef IOleParentUndoUnit  *LPOLEPARENTUNDOUNIT;


EXTERN_C const IID IID_IOleParentUndoUnit;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IOleParentUndoUnit : public IOleUndoUnit
    {
    public:
        virtual HRESULT __stdcall Open( 
            /* [in] */ IOleParentUndoUnit  *pPUU) = 0;
        
        virtual HRESULT __stdcall Close( 
            /* [in] */ IOleParentUndoUnit  *pPUU,
            /* [in] */ BOOL fCommit) = 0;
        
        virtual HRESULT __stdcall Add( 
            /* [in] */ IOleUndoUnit  *pUU) = 0;
        
        virtual HRESULT __stdcall FindUnit( 
            /* [in] */ IOleUndoUnit  *pUU) = 0;
        
        virtual HRESULT __stdcall GetParentState( 
            /* [out] */ unsigned long  *pdwState) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOleParentUndoUnitVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IOleParentUndoUnit  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IOleParentUndoUnit  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IOleParentUndoUnit  * This);
        
        HRESULT ( __stdcall  *Do )( 
            IOleParentUndoUnit  * This,
            /* [in] */ IOleUndoManager  *pUndoManager);
        
        HRESULT ( __stdcall  *GetDescription )( 
            IOleParentUndoUnit  * This,
            /* [out] */ BSTR  *pBstr);
        
        HRESULT ( __stdcall  *GetUnitType )( 
            IOleParentUndoUnit  * This,
            /* [out] */ CLSID  *pClsid,
            /* [out] */ LONG  *plID);
        
        HRESULT ( __stdcall  *OnNextAdd )( 
            IOleParentUndoUnit  * This);
        
        HRESULT ( __stdcall  *Open )( 
            IOleParentUndoUnit  * This,
            /* [in] */ IOleParentUndoUnit  *pPUU);
        
        HRESULT ( __stdcall  *Close )( 
            IOleParentUndoUnit  * This,
            /* [in] */ IOleParentUndoUnit  *pPUU,
            /* [in] */ BOOL fCommit);
        
        HRESULT ( __stdcall  *Add )( 
            IOleParentUndoUnit  * This,
            /* [in] */ IOleUndoUnit  *pUU);
        
        HRESULT ( __stdcall  *FindUnit )( 
            IOleParentUndoUnit  * This,
            /* [in] */ IOleUndoUnit  *pUU);
        
        HRESULT ( __stdcall  *GetParentState )( 
            IOleParentUndoUnit  * This,
            /* [out] */ unsigned long  *pdwState);
        
        END_INTERFACE
    } IOleParentUndoUnitVtbl;

    interface IOleParentUndoUnit
    {
        CONST_VTBL struct IOleParentUndoUnitVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleParentUndoUnit_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOleParentUndoUnit_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOleParentUndoUnit_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOleParentUndoUnit_Do(This,pUndoManager)	\
    (This)->lpVtbl -> Do(This,pUndoManager)

#define IOleParentUndoUnit_GetDescription(This,pBstr)	\
    (This)->lpVtbl -> GetDescription(This,pBstr)

#define IOleParentUndoUnit_GetUnitType(This,pClsid,plID)	\
    (This)->lpVtbl -> GetUnitType(This,pClsid,plID)

#define IOleParentUndoUnit_OnNextAdd(This)	\
    (This)->lpVtbl -> OnNextAdd(This)


#define IOleParentUndoUnit_Open(This,pPUU)	\
    (This)->lpVtbl -> Open(This,pPUU)

#define IOleParentUndoUnit_Close(This,pPUU,fCommit)	\
    (This)->lpVtbl -> Close(This,pPUU,fCommit)

#define IOleParentUndoUnit_Add(This,pUU)	\
    (This)->lpVtbl -> Add(This,pUU)

#define IOleParentUndoUnit_FindUnit(This,pUU)	\
    (This)->lpVtbl -> FindUnit(This,pUU)

#define IOleParentUndoUnit_GetParentState(This,pdwState)	\
    (This)->lpVtbl -> GetParentState(This,pdwState)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IOleParentUndoUnit_Open_Proxy( 
    IOleParentUndoUnit  * This,
    /* [in] */ IOleParentUndoUnit  *pPUU);


void __stdcall IOleParentUndoUnit_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleParentUndoUnit_Close_Proxy( 
    IOleParentUndoUnit  * This,
    /* [in] */ IOleParentUndoUnit  *pPUU,
    /* [in] */ BOOL fCommit);


void __stdcall IOleParentUndoUnit_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleParentUndoUnit_Add_Proxy( 
    IOleParentUndoUnit  * This,
    /* [in] */ IOleUndoUnit  *pUU);


void __stdcall IOleParentUndoUnit_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleParentUndoUnit_FindUnit_Proxy( 
    IOleParentUndoUnit  * This,
    /* [in] */ IOleUndoUnit  *pUU);


void __stdcall IOleParentUndoUnit_FindUnit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleParentUndoUnit_GetParentState_Proxy( 
    IOleParentUndoUnit  * This,
    /* [out] */ unsigned long  *pdwState);


void __stdcall IOleParentUndoUnit_GetParentState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IOleParentUndoUnit_INTERFACE_DEFINED__ */


#ifndef __IEnumOleUndoUnits_INTERFACE_DEFINED__
#define __IEnumOleUndoUnits_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IEnumOleUndoUnits
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [uuid][unique][object] */ 


typedef IEnumOleUndoUnits  *LPENUMOLEUNDOUNITS;


EXTERN_C const IID IID_IEnumOleUndoUnits;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IEnumOleUndoUnits : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT __stdcall Next( 
            /* [in] */ unsigned long cElt,
            /* [length_is][size_is][out] */ IOleUndoUnit  * *rgElt,
            /* [out] */ unsigned long  *pcEltFetched) = 0;
        
        virtual HRESULT __stdcall Skip( 
            /* [in] */ unsigned long cElt) = 0;
        
        virtual HRESULT __stdcall Reset( void) = 0;
        
        virtual HRESULT __stdcall Clone( 
            /* [out] */ IEnumOleUndoUnits  * *ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumOleUndoUnitsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IEnumOleUndoUnits  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IEnumOleUndoUnits  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IEnumOleUndoUnits  * This);
        
        /* [local] */ HRESULT ( __stdcall  *Next )( 
            IEnumOleUndoUnits  * This,
            /* [in] */ unsigned long cElt,
            /* [length_is][size_is][out] */ IOleUndoUnit  * *rgElt,
            /* [out] */ unsigned long  *pcEltFetched);
        
        HRESULT ( __stdcall  *Skip )( 
            IEnumOleUndoUnits  * This,
            /* [in] */ unsigned long cElt);
        
        HRESULT ( __stdcall  *Reset )( 
            IEnumOleUndoUnits  * This);
        
        HRESULT ( __stdcall  *Clone )( 
            IEnumOleUndoUnits  * This,
            /* [out] */ IEnumOleUndoUnits  * *ppEnum);
        
        END_INTERFACE
    } IEnumOleUndoUnitsVtbl;

    interface IEnumOleUndoUnits
    {
        CONST_VTBL struct IEnumOleUndoUnitsVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumOleUndoUnits_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumOleUndoUnits_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumOleUndoUnits_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumOleUndoUnits_Next(This,cElt,rgElt,pcEltFetched)	\
    (This)->lpVtbl -> Next(This,cElt,rgElt,pcEltFetched)

#define IEnumOleUndoUnits_Skip(This,cElt)	\
    (This)->lpVtbl -> Skip(This,cElt)

#define IEnumOleUndoUnits_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumOleUndoUnits_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall IEnumOleUndoUnits_RemoteNext_Proxy( 
    IEnumOleUndoUnits  * This,
    /* [in] */ unsigned long cElt,
    /* [length_is][size_is][out] */ IOleUndoUnit  * *rgElt,
    /* [out] */ unsigned long  *pcEltFetched);


void __stdcall IEnumOleUndoUnits_RemoteNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumOleUndoUnits_Skip_Proxy( 
    IEnumOleUndoUnits  * This,
    /* [in] */ unsigned long cElt);


void __stdcall IEnumOleUndoUnits_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumOleUndoUnits_Reset_Proxy( 
    IEnumOleUndoUnits  * This);


void __stdcall IEnumOleUndoUnits_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IEnumOleUndoUnits_Clone_Proxy( 
    IEnumOleUndoUnits  * This,
    /* [out] */ IEnumOleUndoUnits  * *ppEnum);


void __stdcall IEnumOleUndoUnits_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IEnumOleUndoUnits_INTERFACE_DEFINED__ */


#ifndef __IOleUndoManager_INTERFACE_DEFINED__
#define __IOleUndoManager_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IOleUndoManager
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [uuid][unique][object] */ 


#define SID_SOleUndoManager IID_IOleUndoManager;
typedef IOleUndoManager  *LPOLEUNDOMANAGER;


EXTERN_C const IID IID_IOleUndoManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IOleUndoManager : public IUnknown
    {
    public:
        virtual HRESULT __stdcall Open( 
            /* [in] */ IOleParentUndoUnit  *pPUU) = 0;
        
        virtual HRESULT __stdcall Close( 
            /* [in] */ IOleParentUndoUnit  *pPUU,
            /* [in] */ BOOL fCommit) = 0;
        
        virtual HRESULT __stdcall Add( 
            /* [in] */ IOleUndoUnit  *pUU) = 0;
        
        virtual HRESULT __stdcall GetOpenParentState( 
            /* [out] */ unsigned long  *pdwState) = 0;
        
        virtual HRESULT __stdcall DiscardFrom( 
            /* [in] */ IOleUndoUnit  *pUU) = 0;
        
        virtual HRESULT __stdcall UndoTo( 
            /* [in] */ IOleUndoUnit  *pUU) = 0;
        
        virtual HRESULT __stdcall RedoTo( 
            /* [in] */ IOleUndoUnit  *pUU) = 0;
        
        virtual HRESULT __stdcall EnumUndoable( 
            /* [out] */ IEnumOleUndoUnits  * *ppEnum) = 0;
        
        virtual HRESULT __stdcall EnumRedoable( 
            /* [out] */ IEnumOleUndoUnits  * *ppEnum) = 0;
        
        virtual HRESULT __stdcall GetLastUndoDescription( 
            /* [out] */ BSTR  *pBstr) = 0;
        
        virtual HRESULT __stdcall GetLastRedoDescription( 
            /* [out] */ BSTR  *pBstr) = 0;
        
        virtual HRESULT __stdcall Enable( 
            /* [in] */ BOOL fEnable) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOleUndoManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IOleUndoManager  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IOleUndoManager  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IOleUndoManager  * This);
        
        HRESULT ( __stdcall  *Open )( 
            IOleUndoManager  * This,
            /* [in] */ IOleParentUndoUnit  *pPUU);
        
        HRESULT ( __stdcall  *Close )( 
            IOleUndoManager  * This,
            /* [in] */ IOleParentUndoUnit  *pPUU,
            /* [in] */ BOOL fCommit);
        
        HRESULT ( __stdcall  *Add )( 
            IOleUndoManager  * This,
            /* [in] */ IOleUndoUnit  *pUU);
        
        HRESULT ( __stdcall  *GetOpenParentState )( 
            IOleUndoManager  * This,
            /* [out] */ unsigned long  *pdwState);
        
        HRESULT ( __stdcall  *DiscardFrom )( 
            IOleUndoManager  * This,
            /* [in] */ IOleUndoUnit  *pUU);
        
        HRESULT ( __stdcall  *UndoTo )( 
            IOleUndoManager  * This,
            /* [in] */ IOleUndoUnit  *pUU);
        
        HRESULT ( __stdcall  *RedoTo )( 
            IOleUndoManager  * This,
            /* [in] */ IOleUndoUnit  *pUU);
        
        HRESULT ( __stdcall  *EnumUndoable )( 
            IOleUndoManager  * This,
            /* [out] */ IEnumOleUndoUnits  * *ppEnum);
        
        HRESULT ( __stdcall  *EnumRedoable )( 
            IOleUndoManager  * This,
            /* [out] */ IEnumOleUndoUnits  * *ppEnum);
        
        HRESULT ( __stdcall  *GetLastUndoDescription )( 
            IOleUndoManager  * This,
            /* [out] */ BSTR  *pBstr);
        
        HRESULT ( __stdcall  *GetLastRedoDescription )( 
            IOleUndoManager  * This,
            /* [out] */ BSTR  *pBstr);
        
        HRESULT ( __stdcall  *Enable )( 
            IOleUndoManager  * This,
            /* [in] */ BOOL fEnable);
        
        END_INTERFACE
    } IOleUndoManagerVtbl;

    interface IOleUndoManager
    {
        CONST_VTBL struct IOleUndoManagerVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOleUndoManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOleUndoManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOleUndoManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOleUndoManager_Open(This,pPUU)	\
    (This)->lpVtbl -> Open(This,pPUU)

#define IOleUndoManager_Close(This,pPUU,fCommit)	\
    (This)->lpVtbl -> Close(This,pPUU,fCommit)

#define IOleUndoManager_Add(This,pUU)	\
    (This)->lpVtbl -> Add(This,pUU)

#define IOleUndoManager_GetOpenParentState(This,pdwState)	\
    (This)->lpVtbl -> GetOpenParentState(This,pdwState)

#define IOleUndoManager_DiscardFrom(This,pUU)	\
    (This)->lpVtbl -> DiscardFrom(This,pUU)

#define IOleUndoManager_UndoTo(This,pUU)	\
    (This)->lpVtbl -> UndoTo(This,pUU)

#define IOleUndoManager_RedoTo(This,pUU)	\
    (This)->lpVtbl -> RedoTo(This,pUU)

#define IOleUndoManager_EnumUndoable(This,ppEnum)	\
    (This)->lpVtbl -> EnumUndoable(This,ppEnum)

#define IOleUndoManager_EnumRedoable(This,ppEnum)	\
    (This)->lpVtbl -> EnumRedoable(This,ppEnum)

#define IOleUndoManager_GetLastUndoDescription(This,pBstr)	\
    (This)->lpVtbl -> GetLastUndoDescription(This,pBstr)

#define IOleUndoManager_GetLastRedoDescription(This,pBstr)	\
    (This)->lpVtbl -> GetLastRedoDescription(This,pBstr)

#define IOleUndoManager_Enable(This,fEnable)	\
    (This)->lpVtbl -> Enable(This,fEnable)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IOleUndoManager_Open_Proxy( 
    IOleUndoManager  * This,
    /* [in] */ IOleParentUndoUnit  *pPUU);


void __stdcall IOleUndoManager_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleUndoManager_Close_Proxy( 
    IOleUndoManager  * This,
    /* [in] */ IOleParentUndoUnit  *pPUU,
    /* [in] */ BOOL fCommit);


void __stdcall IOleUndoManager_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleUndoManager_Add_Proxy( 
    IOleUndoManager  * This,
    /* [in] */ IOleUndoUnit  *pUU);


void __stdcall IOleUndoManager_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleUndoManager_GetOpenParentState_Proxy( 
    IOleUndoManager  * This,
    /* [out] */ unsigned long  *pdwState);


void __stdcall IOleUndoManager_GetOpenParentState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleUndoManager_DiscardFrom_Proxy( 
    IOleUndoManager  * This,
    /* [in] */ IOleUndoUnit  *pUU);


void __stdcall IOleUndoManager_DiscardFrom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleUndoManager_UndoTo_Proxy( 
    IOleUndoManager  * This,
    /* [in] */ IOleUndoUnit  *pUU);


void __stdcall IOleUndoManager_UndoTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleUndoManager_RedoTo_Proxy( 
    IOleUndoManager  * This,
    /* [in] */ IOleUndoUnit  *pUU);


void __stdcall IOleUndoManager_RedoTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleUndoManager_EnumUndoable_Proxy( 
    IOleUndoManager  * This,
    /* [out] */ IEnumOleUndoUnits  * *ppEnum);


void __stdcall IOleUndoManager_EnumUndoable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleUndoManager_EnumRedoable_Proxy( 
    IOleUndoManager  * This,
    /* [out] */ IEnumOleUndoUnits  * *ppEnum);


void __stdcall IOleUndoManager_EnumRedoable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleUndoManager_GetLastUndoDescription_Proxy( 
    IOleUndoManager  * This,
    /* [out] */ BSTR  *pBstr);


void __stdcall IOleUndoManager_GetLastUndoDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleUndoManager_GetLastRedoDescription_Proxy( 
    IOleUndoManager  * This,
    /* [out] */ BSTR  *pBstr);


void __stdcall IOleUndoManager_GetLastRedoDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IOleUndoManager_Enable_Proxy( 
    IOleUndoManager  * This,
    /* [in] */ BOOL fEnable);


void __stdcall IOleUndoManager_Enable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IOleUndoManager_INTERFACE_DEFINED__ */


#ifndef __IQuickActivate_INTERFACE_DEFINED__
#define __IQuickActivate_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IQuickActivate
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [uuid][unique][object][local] */ 


typedef IQuickActivate  *LPQUICKACTIVATE;

typedef /* [v1_enum] */ 
enum tagQACONTAINERFLAGS
    {	QACONTAINER_SHOWHATCHING	= 0x1,
	QACONTAINER_SHOWGRABHANDLES	= 0x2,
	QACONTAINER_USERMODE	= 0x4,
	QACONTAINER_DISPLAYASDEFAULT	= 0x8,
	QACONTAINER_UIDEAD	= 0x10,
	QACONTAINER_AUTOCLIP	= 0x20,
	QACONTAINER_MESSAGEREFLECT	= 0x40,
	QACONTAINER_SUPPORTSMNEMONICS	= 0x80
    }	QACONTAINERFLAGS;

typedef unsigned long OLE_COLOR;

typedef struct  tagQACONTAINER
    {
    unsigned long cbSize;
    IOleClientSite  *pClientSite;
    IAdviseSinkEx  *pAdviseSink;
    IPropertyNotifySink  *pPropertyNotifySink;
    IUnknown  *pUnkEventSink;
    unsigned long dwAmbientFlags;
    OLE_COLOR colorFore;
    OLE_COLOR colorBack;
    IFont  *pFont;
    IOleUndoManager  *pUndoMgr;
    unsigned long dwAppearance;
    LONG lcid;
    HPALETTE hpal;
    struct IBindHost  *pBindHost;
    }	QACONTAINER;

typedef struct  tagQACONTROL
    {
    unsigned long cbSize;
    unsigned long dwMiscStatus;
    unsigned long dwViewStatus;
    unsigned long dwEventCookie;
    unsigned long dwPropNotifyCookie;
    unsigned long dwPointerActivationPolicy;
    }	QACONTROL;


EXTERN_C const IID IID_IQuickActivate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IQuickActivate : public IUnknown
    {
    public:
        virtual HRESULT __stdcall QuickActivate( 
            /* [in] */ QACONTAINER  *pQaContainer,
            /* [out] */ QACONTROL  *pQaControl) = 0;
        
        virtual HRESULT __stdcall SetContentExtent( 
            LPSIZEL pSizel) = 0;
        
        virtual HRESULT __stdcall GetContentExtent( 
            LPSIZEL pSizel) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IQuickActivateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IQuickActivate  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IQuickActivate  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IQuickActivate  * This);
        
        HRESULT ( __stdcall  *QuickActivate )( 
            IQuickActivate  * This,
            /* [in] */ QACONTAINER  *pQaContainer,
            /* [out] */ QACONTROL  *pQaControl);
        
        HRESULT ( __stdcall  *SetContentExtent )( 
            IQuickActivate  * This,
            LPSIZEL pSizel);
        
        HRESULT ( __stdcall  *GetContentExtent )( 
            IQuickActivate  * This,
            LPSIZEL pSizel);
        
        END_INTERFACE
    } IQuickActivateVtbl;

    interface IQuickActivate
    {
        CONST_VTBL struct IQuickActivateVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IQuickActivate_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IQuickActivate_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IQuickActivate_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IQuickActivate_QuickActivate(This,pQaContainer,pQaControl)	\
    (This)->lpVtbl -> QuickActivate(This,pQaContainer,pQaControl)

#define IQuickActivate_SetContentExtent(This,pSizel)	\
    (This)->lpVtbl -> SetContentExtent(This,pSizel)

#define IQuickActivate_GetContentExtent(This,pSizel)	\
    (This)->lpVtbl -> GetContentExtent(This,pSizel)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IQuickActivate_QuickActivate_Proxy( 
    IQuickActivate  * This,
    /* [in] */ QACONTAINER  *pQaContainer,
    /* [out] */ QACONTROL  *pQaControl);


void __stdcall IQuickActivate_QuickActivate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IQuickActivate_SetContentExtent_Proxy( 
    IQuickActivate  * This,
    LPSIZEL pSizel);


void __stdcall IQuickActivate_SetContentExtent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IQuickActivate_GetContentExtent_Proxy( 
    IQuickActivate  * This,
    LPSIZEL pSizel);


void __stdcall IQuickActivate_GetContentExtent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IQuickActivate_INTERFACE_DEFINED__ */


#ifndef __IPointerInactive_INTERFACE_DEFINED__
#define __IPointerInactive_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPointerInactive
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [uuid][unique][object] */ 


typedef IPointerInactive  *LPPOINTERINACTIVE;

typedef /* [v1_enum] */ 
enum tagPOINTERINACTIVE
    {	POINTERINACTIVE_ACTIVATEONENTRY	= 1,
	POINTERINACTIVE_DEACTIVATEONLEAVE	= 2,
	POINTERINACTIVE_ACTIVATEONDRAG	= 4
    }	POINTERINACTIVE;


EXTERN_C const IID IID_IPointerInactive;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IPointerInactive : public IUnknown
    {
    public:
        virtual HRESULT __stdcall GetActivationPolicy( 
            /* [out] */ unsigned long  *pdwPolicy) = 0;
        
        virtual HRESULT __stdcall OnInactiveMouseMove( 
            /* [in] */ LPCRECT pRectBounds,
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ unsigned long grfKeyState) = 0;
        
        virtual HRESULT __stdcall OnInactiveSetCursor( 
            /* [in] */ LPCRECT pRectBounds,
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ unsigned long dwMouseMsg,
            /* [in] */ BOOL fSetAlways) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPointerInactiveVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IPointerInactive  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IPointerInactive  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IPointerInactive  * This);
        
        HRESULT ( __stdcall  *GetActivationPolicy )( 
            IPointerInactive  * This,
            /* [out] */ unsigned long  *pdwPolicy);
        
        HRESULT ( __stdcall  *OnInactiveMouseMove )( 
            IPointerInactive  * This,
            /* [in] */ LPCRECT pRectBounds,
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ unsigned long grfKeyState);
        
        HRESULT ( __stdcall  *OnInactiveSetCursor )( 
            IPointerInactive  * This,
            /* [in] */ LPCRECT pRectBounds,
            /* [in] */ LONG x,
            /* [in] */ LONG y,
            /* [in] */ unsigned long dwMouseMsg,
            /* [in] */ BOOL fSetAlways);
        
        END_INTERFACE
    } IPointerInactiveVtbl;

    interface IPointerInactive
    {
        CONST_VTBL struct IPointerInactiveVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPointerInactive_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPointerInactive_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPointerInactive_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPointerInactive_GetActivationPolicy(This,pdwPolicy)	\
    (This)->lpVtbl -> GetActivationPolicy(This,pdwPolicy)

#define IPointerInactive_OnInactiveMouseMove(This,pRectBounds,x,y,grfKeyState)	\
    (This)->lpVtbl -> OnInactiveMouseMove(This,pRectBounds,x,y,grfKeyState)

#define IPointerInactive_OnInactiveSetCursor(This,pRectBounds,x,y,dwMouseMsg,fSetAlways)	\
    (This)->lpVtbl -> OnInactiveSetCursor(This,pRectBounds,x,y,dwMouseMsg,fSetAlways)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPointerInactive_GetActivationPolicy_Proxy( 
    IPointerInactive  * This,
    /* [out] */ unsigned long  *pdwPolicy);


void __stdcall IPointerInactive_GetActivationPolicy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPointerInactive_OnInactiveMouseMove_Proxy( 
    IPointerInactive  * This,
    /* [in] */ LPCRECT pRectBounds,
    /* [in] */ LONG x,
    /* [in] */ LONG y,
    /* [in] */ unsigned long grfKeyState);


void __stdcall IPointerInactive_OnInactiveMouseMove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPointerInactive_OnInactiveSetCursor_Proxy( 
    IPointerInactive  * This,
    /* [in] */ LPCRECT pRectBounds,
    /* [in] */ LONG x,
    /* [in] */ LONG y,
    /* [in] */ unsigned long dwMouseMsg,
    /* [in] */ BOOL fSetAlways);


void __stdcall IPointerInactive_OnInactiveSetCursor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IPointerInactive_INTERFACE_DEFINED__ */


#ifndef __IObjectWithSite_INTERFACE_DEFINED__
#define __IObjectWithSite_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IObjectWithSite
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef IObjectWithSite  *LPOBJECTWITHSITE;


EXTERN_C const IID IID_IObjectWithSite;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IObjectWithSite : public IUnknown
    {
    public:
        virtual HRESULT __stdcall SetSite( 
            /* [in] */ IUnknown  *pUnkSite) = 0;
        
        virtual HRESULT __stdcall GetSite( 
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvSite) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IObjectWithSiteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IObjectWithSite  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IObjectWithSite  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IObjectWithSite  * This);
        
        HRESULT ( __stdcall  *SetSite )( 
            IObjectWithSite  * This,
            /* [in] */ IUnknown  *pUnkSite);
        
        HRESULT ( __stdcall  *GetSite )( 
            IObjectWithSite  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvSite);
        
        END_INTERFACE
    } IObjectWithSiteVtbl;

    interface IObjectWithSite
    {
        CONST_VTBL struct IObjectWithSiteVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IObjectWithSite_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IObjectWithSite_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IObjectWithSite_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IObjectWithSite_SetSite(This,pUnkSite)	\
    (This)->lpVtbl -> SetSite(This,pUnkSite)

#define IObjectWithSite_GetSite(This,riid,ppvSite)	\
    (This)->lpVtbl -> GetSite(This,riid,ppvSite)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IObjectWithSite_SetSite_Proxy( 
    IObjectWithSite  * This,
    /* [in] */ IUnknown  *pUnkSite);


void __stdcall IObjectWithSite_SetSite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IObjectWithSite_GetSite_Proxy( 
    IObjectWithSite  * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void  * *ppvSite);


void __stdcall IObjectWithSite_GetSite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IObjectWithSite_INTERFACE_DEFINED__ */


#ifndef __IErrorLog_INTERFACE_DEFINED__
#define __IErrorLog_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IErrorLog
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef IErrorLog  *LPERRORLOG;


EXTERN_C const IID IID_IErrorLog;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IErrorLog : public IUnknown
    {
    public:
        virtual HRESULT __stdcall AddError( 
            /* [in] */ LPCOLESTR pszPropName,
            /* [in] */ EXCEPINFO  *pExcepInfo) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IErrorLogVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IErrorLog  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IErrorLog  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IErrorLog  * This);
        
        HRESULT ( __stdcall  *AddError )( 
            IErrorLog  * This,
            /* [in] */ LPCOLESTR pszPropName,
            /* [in] */ EXCEPINFO  *pExcepInfo);
        
        END_INTERFACE
    } IErrorLogVtbl;

    interface IErrorLog
    {
        CONST_VTBL struct IErrorLogVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IErrorLog_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IErrorLog_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IErrorLog_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IErrorLog_AddError(This,pszPropName,pExcepInfo)	\
    (This)->lpVtbl -> AddError(This,pszPropName,pExcepInfo)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IErrorLog_AddError_Proxy( 
    IErrorLog  * This,
    /* [in] */ LPCOLESTR pszPropName,
    /* [in] */ EXCEPINFO  *pExcepInfo);


void __stdcall IErrorLog_AddError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IErrorLog_INTERFACE_DEFINED__ */


#ifndef __IPropertyBag_INTERFACE_DEFINED__
#define __IPropertyBag_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPropertyBag
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef IPropertyBag  *LPPROPERTYBAG;


EXTERN_C const IID IID_IPropertyBag;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IPropertyBag : public IUnknown
    {
    public:
        virtual /* [local] */ HRESULT __stdcall Read( 
            /* [in] */ LPCOLESTR pszPropName,
            /* [out][in] */ VARIANT  *pVar,
            /* [in] */ IErrorLog  *pErrorLog) = 0;
        
        virtual HRESULT __stdcall Write( 
            /* [in] */ LPCOLESTR pszPropName,
            /* [in] */ VARIANT  *pVar) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPropertyBagVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IPropertyBag  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IPropertyBag  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IPropertyBag  * This);
        
        /* [local] */ HRESULT ( __stdcall  *Read )( 
            IPropertyBag  * This,
            /* [in] */ LPCOLESTR pszPropName,
            /* [out][in] */ VARIANT  *pVar,
            /* [in] */ IErrorLog  *pErrorLog);
        
        HRESULT ( __stdcall  *Write )( 
            IPropertyBag  * This,
            /* [in] */ LPCOLESTR pszPropName,
            /* [in] */ VARIANT  *pVar);
        
        END_INTERFACE
    } IPropertyBagVtbl;

    interface IPropertyBag
    {
        CONST_VTBL struct IPropertyBagVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPropertyBag_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPropertyBag_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPropertyBag_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPropertyBag_Read(This,pszPropName,pVar,pErrorLog)	\
    (This)->lpVtbl -> Read(This,pszPropName,pVar,pErrorLog)

#define IPropertyBag_Write(This,pszPropName,pVar)	\
    (This)->lpVtbl -> Write(This,pszPropName,pVar)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [call_as] */ HRESULT __stdcall IPropertyBag_RemoteRead_Proxy( 
    IPropertyBag  * This,
    /* [in] */ LPCOLESTR pszPropName,
    /* [out] */ VARIANT  *pVar,
    /* [in] */ IErrorLog  *pErrorLog,
    /* [in] */ unsigned long varType,
    /* [in] */ IUnknown  *pUnkObj);


void __stdcall IPropertyBag_RemoteRead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPropertyBag_Write_Proxy( 
    IPropertyBag  * This,
    /* [in] */ LPCOLESTR pszPropName,
    /* [in] */ VARIANT  *pVar);


void __stdcall IPropertyBag_Write_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IPropertyBag_INTERFACE_DEFINED__ */


#ifndef __IPerPropertyBrowsing_INTERFACE_DEFINED__
#define __IPerPropertyBrowsing_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPerPropertyBrowsing
 * at Sat Jul 13 21:56:58 1996
 * using MIDL 3.00.39
 ****************************************/
/* [unique][uuid][object] */ 


typedef IPerPropertyBrowsing  *LPPERPROPERTYBROWSING;

typedef struct  tagCALPOLESTR
    {
    unsigned long cElems;
    /* [size_is] */ LPOLESTR  *pElems;
    }	CALPOLESTR;

typedef struct tagCALPOLESTR  *LPCALPOLESTR;

typedef struct  tagCADWORD
    {
    unsigned long cElems;
    /* [size_is] */ unsigned long  *pElems;
    }	CADWORD;

typedef struct tagCADWORD  *LPCADWORD;


EXTERN_C const IID IID_IPerPropertyBrowsing;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IPerPropertyBrowsing : public IUnknown
    {
    public:
        virtual HRESULT __stdcall GetDisplayString( 
            /* [in] */ DISPID dispID,
            /* [out] */ BSTR  *pBstr) = 0;
        
        virtual HRESULT __stdcall MapPropertyToPage( 
            /* [in] */ DISPID dispID,
            /* [out] */ CLSID  *pClsid) = 0;
        
        virtual HRESULT __stdcall GetPredefinedStrings( 
            /* [in] */ DISPID dispID,
            /* [out] */ CALPOLESTR  *pCaStringsOut,
            /* [out] */ CADWORD  *pCaCookiesOut) = 0;
        
        virtual HRESULT __stdcall GetPredefinedValue( 
            /* [in] */ DISPID dispID,
            /* [in] */ unsigned long dwCookie,
            /* [out] */ VARIANT  *pVarOut) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPerPropertyBrowsingVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IPerPropertyBrowsing  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IPerPropertyBrowsing  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IPerPropertyBrowsing  * This);
        
        HRESULT ( __stdcall  *GetDisplayString )( 
            IPerPropertyBrowsing  * This,
            /* [in] */ DISPID dispID,
            /* [out] */ BSTR  *pBstr);
        
        HRESULT ( __stdcall  *MapPropertyToPage )( 
            IPerPropertyBrowsing  * This,
            /* [in] */ DISPID dispID,
            /* [out] */ CLSID  *pClsid);
        
        HRESULT ( __stdcall  *GetPredefinedStrings )( 
            IPerPropertyBrowsing  * This,
            /* [in] */ DISPID dispID,
            /* [out] */ CALPOLESTR  *pCaStringsOut,
            /* [out] */ CADWORD  *pCaCookiesOut);
        
        HRESULT ( __stdcall  *GetPredefinedValue )( 
            IPerPropertyBrowsing  * This,
            /* [in] */ DISPID dispID,
            /* [in] */ unsigned long dwCookie,
            /* [out] */ VARIANT  *pVarOut);
        
        END_INTERFACE
    } IPerPropertyBrowsingVtbl;

    interface IPerPropertyBrowsing
    {
        CONST_VTBL struct IPerPropertyBrowsingVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPerPropertyBrowsing_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPerPropertyBrowsing_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPerPropertyBrowsing_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPerPropertyBrowsing_GetDisplayString(This,dispID,pBstr)	\
    (This)->lpVtbl -> GetDisplayString(This,dispID,pBstr)

#define IPerPropertyBrowsing_MapPropertyToPage(This,dispID,pClsid)	\
    (This)->lpVtbl -> MapPropertyToPage(This,dispID,pClsid)

#define IPerPropertyBrowsing_GetPredefinedStrings(This,dispID,pCaStringsOut,pCaCookiesOut)	\
    (This)->lpVtbl -> GetPredefinedStrings(This,dispID,pCaStringsOut,pCaCookiesOut)

#define IPerPropertyBrowsing_GetPredefinedValue(This,dispID,dwCookie,pVarOut)	\
    (This)->lpVtbl -> GetPredefinedValue(This,dispID,dwCookie,pVarOut)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPerPropertyBrowsing_GetDisplayString_Proxy( 
    IPerPropertyBrowsing  * This,
    /* [in] */ DISPID dispID,
    /* [out] */ BSTR  *pBstr);


void __stdcall IPerPropertyBrowsing_GetDisplayString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPerPropertyBrowsing_MapPropertyToPage_Proxy( 
    IPerPropertyBrowsing  * This,
    /* [in] */ DISPID dispID,
    /* [out] */ CLSID  *pClsid);


void __stdcall IPerPropertyBrowsing_MapPropertyToPage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPerPropertyBrowsing_GetPredefinedStrings_Proxy( 
    IPerPropertyBrowsing  * This,
    /* [in] */ DISPID dispID,
    /* [out] */ CALPOLESTR  *pCaStringsOut,
    /* [out] */ CADWORD  *pCaCookiesOut);


void __stdcall IPerPropertyBrowsing_GetPredefinedStrings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPerPropertyBrowsing_GetPredefinedValue_Proxy( 
    IPerPropertyBrowsing  * This,
    /* [in] */ DISPID dispID,
    /* [in] */ unsigned long dwCookie,
    /* [out] */ VARIANT  *pVarOut);


void __stdcall IPerPropertyBrowsing_GetPredefinedValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IPerPropertyBrowsing_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */


void __stdcall UserHWND_from_local( HWND  *, UserHWND  *  * );
void __stdcall UserHWND_to_local( UserHWND  *, HWND  * );
 void __stdcall UserHWND_free_inst( UserHWND  * );
void __stdcall UserHWND_free_local( HWND  * );

void __stdcall UserHACCEL_from_local( HACCEL  *, UserHACCEL  *  * );
void __stdcall UserHACCEL_to_local( UserHACCEL  *, HACCEL  * );
 void __stdcall UserHACCEL_free_inst( UserHACCEL  * );
void __stdcall UserHACCEL_free_local( HACCEL  * );

void __stdcall UserHDC_from_local( HDC  *, UserHDC  *  * );
void __stdcall UserHDC_to_local( UserHDC  *, HDC  * );
 void __stdcall UserHDC_free_inst( UserHDC  * );
void __stdcall UserHDC_free_local( HDC  * );

void __stdcall UserHFONT_from_local( HFONT  *, UserHFONT  *  * );
void __stdcall UserHFONT_to_local( UserHFONT  *, HFONT  * );
 void __stdcall UserHFONT_free_inst( UserHFONT  * );
void __stdcall UserHFONT_free_local( HFONT  * );

void __stdcall UserMSG_from_local( MSG  *, UserMSG  *  * );
void __stdcall UserMSG_to_local( UserMSG  *, MSG  * );
 void __stdcall UserMSG_free_inst( UserMSG  * );
void __stdcall UserMSG_free_local( MSG  * );

void __stdcall UserBSTR_from_local( BSTR  *, UserBSTR  *  * );
void __stdcall UserBSTR_to_local( UserBSTR  *, BSTR  * );
 void __stdcall UserBSTR_free_inst( UserBSTR  * );
void __stdcall UserBSTR_free_local( BSTR  * );

void __stdcall UserVARIANT_from_local( VARIANT  *, UserVARIANT  *  * );
void __stdcall UserVARIANT_to_local( UserVARIANT  *, VARIANT  * );
 void __stdcall UserVARIANT_free_inst( UserVARIANT  * );
void __stdcall UserVARIANT_free_local( VARIANT  * );

void __stdcall UserEXCEPINFO_from_local( EXCEPINFO  *, UserEXCEPINFO  *  * );
void __stdcall UserEXCEPINFO_to_local( UserEXCEPINFO  *, EXCEPINFO  * );
 void __stdcall UserEXCEPINFO_free_inst( UserEXCEPINFO  * );
void __stdcall UserEXCEPINFO_free_local( EXCEPINFO  * );

/* [local] */ HRESULT __stdcall IEnumConnections_Next_Proxy( 
    IEnumConnections  * This,
    /* [in] */ unsigned long cConnections,
    /* [length_is][size_is][out] */ LPCONNECTDATA rgcd,
    /* [out] */ unsigned long  *pcFetched);


/* [call_as] */ HRESULT __stdcall IEnumConnections_Next_Stub( 
    IEnumConnections  * This,
    /* [in] */ unsigned long cConnections,
    /* [length_is][size_is][out] */ LPCONNECTDATA rgcd,
    /* [out] */ unsigned long  *pcFetched);

/* [local] */ HRESULT __stdcall IEnumConnectionPoints_Next_Proxy( 
    IEnumConnectionPoints  * This,
    /* [in] */ unsigned long cConnections,
    /* [length_is][size_is][out] */ LPCONNECTIONPOINT  *ppCP,
    /* [out] */ unsigned long  *pcFetched);


/* [call_as] */ HRESULT __stdcall IEnumConnectionPoints_Next_Stub( 
    IEnumConnectionPoints  * This,
    /* [in] */ unsigned long cConnections,
    /* [length_is][size_is][out] */ LPCONNECTIONPOINT  *ppCP,
    /* [out] */ unsigned long  *pcFetched);

/* [local] */ HRESULT __stdcall IClassFactory2_CreateInstanceLic_Proxy( 
    IClassFactory2  * This,
    /* [in] */ IUnknown  *pUnkOuter,
    /* [in] */ IUnknown  *pUnkReserved,
    /* [in] */ REFIID riid,
    /* [in] */ BSTR bstrKey,
    /* [iid_is][out] */ void*  *ppvObj);


/* [call_as] */ HRESULT __stdcall IClassFactory2_CreateInstanceLic_Stub( 
    IClassFactory2  * This,
    /* [in] */ REFIID riid,
    /* [in] */ BSTR bstrKey,
    /* [iid_is][out] */ IUnknown  * *ppvObj);

/* [local] */ HRESULT __stdcall IPersistMemory_Load_Proxy( 
    IPersistMemory  * This,
    /* [size_is][in] */ void* pMem,
    /* [in] */ unsigned long cbSize);


/* [call_as] */ HRESULT __stdcall IPersistMemory_Load_Stub( 
    IPersistMemory  * This,
    /* [size_is][in] */ BYTE  *pMem,
    /* [in] */ unsigned long cbSize);

/* [local] */ HRESULT __stdcall IPersistMemory_Save_Proxy( 
    IPersistMemory  * This,
    /* [size_is][in] */ void* pMem,
    /* [in] */ BOOL fClearDirty,
    /* [in] */ unsigned long cbSize);


/* [call_as] */ HRESULT __stdcall IPersistMemory_Save_Stub( 
    IPersistMemory  * This,
    /* [size_is][in] */ BYTE  *pMem,
    /* [in] */ BOOL fClearDirty,
    /* [in] */ unsigned long cbSize);

/* [local] */ void __stdcall IAdviseSinkEx_OnViewStatusChange_Proxy( 
    IAdviseSinkEx  * This,
    /* [in] */ unsigned long dwViewStatus);


/* [async][call_as] */ void __stdcall IAdviseSinkEx_OnViewStatusChange_Stub( 
    IAdviseSinkEx  * This,
    /* [in] */ unsigned long dwViewStatus);

/* [local] */ HRESULT __stdcall IEnumOleUndoUnits_Next_Proxy( 
    IEnumOleUndoUnits  * This,
    /* [in] */ unsigned long cElt,
    /* [length_is][size_is][out] */ IOleUndoUnit  * *rgElt,
    /* [out] */ unsigned long  *pcEltFetched);


/* [call_as] */ HRESULT __stdcall IEnumOleUndoUnits_Next_Stub( 
    IEnumOleUndoUnits  * This,
    /* [in] */ unsigned long cElt,
    /* [length_is][size_is][out] */ IOleUndoUnit  * *rgElt,
    /* [out] */ unsigned long  *pcEltFetched);

/* [local] */ HRESULT __stdcall IPropertyBag_Read_Proxy( 
    IPropertyBag  * This,
    /* [in] */ LPCOLESTR pszPropName,
    /* [out][in] */ VARIANT  *pVar,
    /* [in] */ IErrorLog  *pErrorLog);


/* [call_as] */ HRESULT __stdcall IPropertyBag_Read_Stub( 
    IPropertyBag  * This,
    /* [in] */ LPCOLESTR pszPropName,
    /* [out] */ VARIANT  *pVar,
    /* [in] */ IErrorLog  *pErrorLog,
    /* [in] */ unsigned long varType,
    /* [in] */ IUnknown  *pUnkObj);



/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
