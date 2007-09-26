/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Sun Jul 07 10:45:05 1996
 */
/* Compiler settings for activscp.idl:
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

#ifndef __activscp_h__
#define __activscp_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IActiveScriptSite_FWD_DEFINED__
#define __IActiveScriptSite_FWD_DEFINED__
typedef interface IActiveScriptSite IActiveScriptSite;
#endif 	/* __IActiveScriptSite_FWD_DEFINED__ */


#ifndef __IActiveScriptError_FWD_DEFINED__
#define __IActiveScriptError_FWD_DEFINED__
typedef interface IActiveScriptError IActiveScriptError;
#endif 	/* __IActiveScriptError_FWD_DEFINED__ */


#ifndef __IActiveScriptSiteWindow_FWD_DEFINED__
#define __IActiveScriptSiteWindow_FWD_DEFINED__
typedef interface IActiveScriptSiteWindow IActiveScriptSiteWindow;
#endif 	/* __IActiveScriptSiteWindow_FWD_DEFINED__ */


#ifndef __IActiveScript_FWD_DEFINED__
#define __IActiveScript_FWD_DEFINED__
typedef interface IActiveScript IActiveScript;
#endif 	/* __IActiveScript_FWD_DEFINED__ */


#ifndef __IActiveScriptParse_FWD_DEFINED__
#define __IActiveScriptParse_FWD_DEFINED__
typedef interface IActiveScriptParse IActiveScriptParse;
#endif 	/* __IActiveScriptParse_FWD_DEFINED__ */


/* header files for imported files */
#include "ocidl.h"

void  * __stdcall MIDL_user_allocate(size_t);
void __stdcall MIDL_user_free( void  * ); 

/****************************************
 * Generated header for interface: __MIDL__intf_0000
 * at Sun Jul 07 10:45:05 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


//=--------------------------------------------------------------------------=
// ActivScp.h
//=--------------------------------------------------------------------------=
// (C) Copyright 1996 Microsoft Corporation.  All Rights Reserved.
//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//=--------------------------------------------------------------------------=
//
#pragma comment(lib,"uuid.lib")
//
// Declarations for ActiveX Scripting host applications and script engines.
//

#ifndef __ActivScp_h
#define __ActivScp_h

struct tagRemExcepInfo;
typedef struct tagRemEXCEPINFO RemEXCEPINFO;

/* GUIDs
 ********/

#ifndef _NO_SCRIPT_GUIDS
// {F0B7A1A1-9847-11cf-8F20-00805F2CD064}
DEFINE_GUID(CATID_ActiveScript, 0xf0b7a1a1, 0x9847, 0x11cf, 0x8f, 0x20, 0x0, 0x80, 0x5f, 0x2c, 0xd0, 0x64);

// {F0B7A1A2-9847-11cf-8F20-00805F2CD064}
DEFINE_GUID(CATID_ActiveScriptParse, 0xf0b7a1a2, 0x9847, 0x11cf, 0x8f, 0x20, 0x0, 0x80, 0x5f, 0x2c, 0xd0, 0x64);

// {BB1A2AE1-A4F9-11cf-8F20-00805F2CD064}
DEFINE_GUID(IID_IActiveScript, 0xbb1a2ae1, 0xa4f9, 0x11cf, 0x8f, 0x20, 0x0, 0x80, 0x5f, 0x2c, 0xd0, 0x64);

// {BB1A2AE2-A4F9-11cf-8F20-00805F2CD064}
DEFINE_GUID(IID_IActiveScriptParse, 0xbb1a2ae2, 0xa4f9, 0x11cf, 0x8f, 0x20, 0x0, 0x80, 0x5f, 0x2c, 0xd0, 0x64);

// {DB01A1E3-A42B-11cf-8F20-00805F2CD064}
DEFINE_GUID(IID_IActiveScriptSite, 0xdb01a1e3, 0xa42b, 0x11cf, 0x8f, 0x20, 0x0, 0x80, 0x5f, 0x2c, 0xd0, 0x64);

// {D10F6761-83E9-11cf-8F20-00805F2CD064}
DEFINE_GUID(IID_IActiveScriptSiteWindow, 0xd10f6761, 0x83e9, 0x11cf, 0x8f, 0x20, 0x0, 0x80, 0x5f, 0x2c, 0xd0, 0x64);

// {EAE1BA61-A4ED-11cf-8F20-00805F2CD064}
DEFINE_GUID(IID_IActiveScriptError, 0xeae1ba61, 0xa4ed, 0x11cf, 0x8f, 0x20, 0x0, 0x80, 0x5f, 0x2c, 0xd0, 0x64);

#endif // _NO_SCRIPT_GUIDS

// Constants used by ActiveX Scripting:
//

/* IActiveScript::AddNamedItem() input flags */

#define SCRIPTITEM_ISVISIBLE            0x00000002
#define SCRIPTITEM_ISSOURCE             0x00000004
#define SCRIPTITEM_GLOBALMEMBERS        0x00000008
#define SCRIPTITEM_ISPERSISTENT         0x00000040
#define SCRIPTITEM_CODEONLY             0x00000200
#define SCRIPTITEM_NOCODE               0x00000400

#define SCRIPTITEM_ALL_FLAGS            (SCRIPTITEM_ISSOURCE | \
                                         SCRIPTITEM_ISVISIBLE | \
                                         SCRIPTITEM_ISPERSISTENT | \
                                         SCRIPTITEM_GLOBALMEMBERS | \
                                         SCRIPTITEM_NOCODE | \
                                         SCRIPTITEM_CODEONLY)

/* IActiveScript::AddTypeLib() input flags */

#define SCRIPTTYPELIB_ISCONTROL         0x00000010
#define SCRIPTTYPELIB_ISPERSISTENT      0x00000040
#define SCRIPTTYPELIB_ALL_FLAGS         (SCRIPTTEXT_ISCONTROL | SCRIPTTYPELIB_ISPERSISTENT)

/* IActiveScriptParse::AddScriptlet() and IActiveScriptParse::ParseScriptText() input flags */

#define SCRIPTTEXT_ISVISIBLE            0x00000002
#define SCRIPTTEXT_ISEXPRESSION         0x00000020
#define SCRIPTTEXT_ISPERSISTENT         0x00000040
#define SCRIPTTEXT_ALL_FLAGS            (SCRIPTTEXT_ISVISIBLE | \
                                         SCRIPTTEXT_ISEXPRESSION | \
                                         SCRIPTTEXT_ISPERSISTENT)

/* IActiveScriptSite::GetItemInfo() input flags */

#define SCRIPTINFO_IUNKNOWN             0x00000001
#define SCRIPTINFO_ITYPEINFO            0x00000002
#define SCRIPTINFO_ALL_FLAGS            (SCRIPTINFO_IUNKNOWN | \
                                         SCRIPTINFO_ITYPEINFO)

/* IActiveScript::Interrupt() Flags */

#define SCRIPTINTERRUPT_DEBUG           0x00000001
#define SCRIPTINTERRUPT_RAISEEXCEPTION  0x00000002
#define SCRIPTINTERRUPT_ALL_FLAGS       (SCRIPTINTERRUPT_DEBUG | \
                                         SCRIPTINTERRUPT_RAISEEXCEPTION)

/* script state values */

typedef 
enum tagSCRIPTSTATE
    {	SCRIPTSTATE_UNINITIALIZED	= 0,
	SCRIPTSTATE_INITIALIZED	= 5,
	SCRIPTSTATE_STARTED	= 1,
	SCRIPTSTATE_CONNECTED	= 2,
	SCRIPTSTATE_DISCONNECTED	= 3,
	SCRIPTSTATE_CLOSED	= 4
    }	SCRIPTSTATE;


/* script thread state values */

typedef 
enum tagSCRIPTTHREADSTATE
    {	SCRIPTTHREADSTATE_NOTINSCRIPT	= 0,
	SCRIPTTHREADSTATE_RUNNING	= 1
    }	SCRIPTTHREADSTATE;


/* Thread IDs */

typedef unsigned long SCRIPTTHREADID;


#define SCRIPTTHREADID_CURRENT  ((SCRIPTTHREADID)-1)
#define SCRIPTTHREADID_BASE     ((SCRIPTTHREADID)-2)
#define SCRIPTTHREADID_ALL      ((SCRIPTTHREADID)-3)

/* Structures */

/* Interfaces
 *************/









extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_s_ifspec;

#ifndef __IActiveScriptSite_INTERFACE_DEFINED__
#define __IActiveScriptSite_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IActiveScriptSite
 * at Sun Jul 07 10:45:05 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 



EXTERN_C const IID IID_IActiveScriptSite;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IActiveScriptSite : public IUnknown
    {
    public:
        virtual HRESULT __stdcall GetLCID( 
            /* [out] */ LCID  *plcid) = 0;
        
        virtual HRESULT __stdcall GetItemInfo( 
            /* [in] */ LPCOLESTR pstrName,
            /* [in] */ unsigned long dwReturnMask,
            /* [out] */ IUnknown  * *ppiunkItem,
            /* [out] */ ITypeInfo  * *ppti) = 0;
        
        virtual HRESULT __stdcall GetDocVersionString( 
            /* [out] */ BSTR  *pbstrVersion) = 0;
        
        virtual HRESULT __stdcall OnScriptTerminate( 
            /* [in] */ const VARIANT  *pvarResult,
            /* [in] */ const EXCEPINFO  *pexcepinfo) = 0;
        
        virtual HRESULT __stdcall OnStateChange( 
            /* [in] */ SCRIPTSTATE ssScriptState) = 0;
        
        virtual HRESULT __stdcall OnScriptError( 
            /* [in] */ IActiveScriptError  *pscripterror) = 0;
        
        virtual HRESULT __stdcall OnEnterScript( void) = 0;
        
        virtual HRESULT __stdcall OnLeaveScript( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActiveScriptSiteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IActiveScriptSite  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IActiveScriptSite  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IActiveScriptSite  * This);
        
        HRESULT ( __stdcall  *GetLCID )( 
            IActiveScriptSite  * This,
            /* [out] */ LCID  *plcid);
        
        HRESULT ( __stdcall  *GetItemInfo )( 
            IActiveScriptSite  * This,
            /* [in] */ LPCOLESTR pstrName,
            /* [in] */ unsigned long dwReturnMask,
            /* [out] */ IUnknown  * *ppiunkItem,
            /* [out] */ ITypeInfo  * *ppti);
        
        HRESULT ( __stdcall  *GetDocVersionString )( 
            IActiveScriptSite  * This,
            /* [out] */ BSTR  *pbstrVersion);
        
        HRESULT ( __stdcall  *OnScriptTerminate )( 
            IActiveScriptSite  * This,
            /* [in] */ const VARIANT  *pvarResult,
            /* [in] */ const EXCEPINFO  *pexcepinfo);
        
        HRESULT ( __stdcall  *OnStateChange )( 
            IActiveScriptSite  * This,
            /* [in] */ SCRIPTSTATE ssScriptState);
        
        HRESULT ( __stdcall  *OnScriptError )( 
            IActiveScriptSite  * This,
            /* [in] */ IActiveScriptError  *pscripterror);
        
        HRESULT ( __stdcall  *OnEnterScript )( 
            IActiveScriptSite  * This);
        
        HRESULT ( __stdcall  *OnLeaveScript )( 
            IActiveScriptSite  * This);
        
        END_INTERFACE
    } IActiveScriptSiteVtbl;

    interface IActiveScriptSite
    {
        CONST_VTBL struct IActiveScriptSiteVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActiveScriptSite_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActiveScriptSite_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActiveScriptSite_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActiveScriptSite_GetLCID(This,plcid)	\
    (This)->lpVtbl -> GetLCID(This,plcid)

#define IActiveScriptSite_GetItemInfo(This,pstrName,dwReturnMask,ppiunkItem,ppti)	\
    (This)->lpVtbl -> GetItemInfo(This,pstrName,dwReturnMask,ppiunkItem,ppti)

#define IActiveScriptSite_GetDocVersionString(This,pbstrVersion)	\
    (This)->lpVtbl -> GetDocVersionString(This,pbstrVersion)

#define IActiveScriptSite_OnScriptTerminate(This,pvarResult,pexcepinfo)	\
    (This)->lpVtbl -> OnScriptTerminate(This,pvarResult,pexcepinfo)

#define IActiveScriptSite_OnStateChange(This,ssScriptState)	\
    (This)->lpVtbl -> OnStateChange(This,ssScriptState)

#define IActiveScriptSite_OnScriptError(This,pscripterror)	\
    (This)->lpVtbl -> OnScriptError(This,pscripterror)

#define IActiveScriptSite_OnEnterScript(This)	\
    (This)->lpVtbl -> OnEnterScript(This)

#define IActiveScriptSite_OnLeaveScript(This)	\
    (This)->lpVtbl -> OnLeaveScript(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IActiveScriptSite_GetLCID_Proxy( 
    IActiveScriptSite  * This,
    /* [out] */ LCID  *plcid);


void __stdcall IActiveScriptSite_GetLCID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IActiveScriptSite_GetItemInfo_Proxy( 
    IActiveScriptSite  * This,
    /* [in] */ LPCOLESTR pstrName,
    /* [in] */ unsigned long dwReturnMask,
    /* [out] */ IUnknown  * *ppiunkItem,
    /* [out] */ ITypeInfo  * *ppti);


void __stdcall IActiveScriptSite_GetItemInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IActiveScriptSite_GetDocVersionString_Proxy( 
    IActiveScriptSite  * This,
    /* [out] */ BSTR  *pbstrVersion);


void __stdcall IActiveScriptSite_GetDocVersionString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IActiveScriptSite_OnScriptTerminate_Proxy( 
    IActiveScriptSite  * This,
    /* [in] */ const VARIANT  *pvarResult,
    /* [in] */ const EXCEPINFO  *pexcepinfo);


void __stdcall IActiveScriptSite_OnScriptTerminate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IActiveScriptSite_OnStateChange_Proxy( 
    IActiveScriptSite  * This,
    /* [in] */ SCRIPTSTATE ssScriptState);


void __stdcall IActiveScriptSite_OnStateChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IActiveScriptSite_OnScriptError_Proxy( 
    IActiveScriptSite  * This,
    /* [in] */ IActiveScriptError  *pscripterror);


void __stdcall IActiveScriptSite_OnScriptError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IActiveScriptSite_OnEnterScript_Proxy( 
    IActiveScriptSite  * This);


void __stdcall IActiveScriptSite_OnEnterScript_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IActiveScriptSite_OnLeaveScript_Proxy( 
    IActiveScriptSite  * This);


void __stdcall IActiveScriptSite_OnLeaveScript_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IActiveScriptSite_INTERFACE_DEFINED__ */


#ifndef __IActiveScriptError_INTERFACE_DEFINED__
#define __IActiveScriptError_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IActiveScriptError
 * at Sun Jul 07 10:45:05 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 



EXTERN_C const IID IID_IActiveScriptError;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IActiveScriptError : public IUnknown
    {
    public:
        virtual HRESULT __stdcall GetExceptionInfo( 
            /* [out] */ EXCEPINFO  *pexcepinfo) = 0;
        
        virtual HRESULT __stdcall GetSourcePosition( 
            /* [out] */ unsigned long  *pdwSourceContext,
            /* [out] */ unsigned long  *pulLineNumber,
            /* [out] */ long  *plCharacterPosition) = 0;
        
        virtual HRESULT __stdcall GetSourceLineText( 
            /* [out] */ BSTR  *pbstrSourceLine) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActiveScriptErrorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IActiveScriptError  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IActiveScriptError  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IActiveScriptError  * This);
        
        HRESULT ( __stdcall  *GetExceptionInfo )( 
            IActiveScriptError  * This,
            /* [out] */ EXCEPINFO  *pexcepinfo);
        
        HRESULT ( __stdcall  *GetSourcePosition )( 
            IActiveScriptError  * This,
            /* [out] */ unsigned long  *pdwSourceContext,
            /* [out] */ unsigned long  *pulLineNumber,
            /* [out] */ long  *plCharacterPosition);
        
        HRESULT ( __stdcall  *GetSourceLineText )( 
            IActiveScriptError  * This,
            /* [out] */ BSTR  *pbstrSourceLine);
        
        END_INTERFACE
    } IActiveScriptErrorVtbl;

    interface IActiveScriptError
    {
        CONST_VTBL struct IActiveScriptErrorVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActiveScriptError_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActiveScriptError_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActiveScriptError_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActiveScriptError_GetExceptionInfo(This,pexcepinfo)	\
    (This)->lpVtbl -> GetExceptionInfo(This,pexcepinfo)

#define IActiveScriptError_GetSourcePosition(This,pdwSourceContext,pulLineNumber,plCharacterPosition)	\
    (This)->lpVtbl -> GetSourcePosition(This,pdwSourceContext,pulLineNumber,plCharacterPosition)

#define IActiveScriptError_GetSourceLineText(This,pbstrSourceLine)	\
    (This)->lpVtbl -> GetSourceLineText(This,pbstrSourceLine)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IActiveScriptError_GetExceptionInfo_Proxy( 
    IActiveScriptError  * This,
    /* [out] */ EXCEPINFO  *pexcepinfo);


void __stdcall IActiveScriptError_GetExceptionInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IActiveScriptError_GetSourcePosition_Proxy( 
    IActiveScriptError  * This,
    /* [out] */ unsigned long  *pdwSourceContext,
    /* [out] */ unsigned long  *pulLineNumber,
    /* [out] */ long  *plCharacterPosition);


void __stdcall IActiveScriptError_GetSourcePosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IActiveScriptError_GetSourceLineText_Proxy( 
    IActiveScriptError  * This,
    /* [out] */ BSTR  *pbstrSourceLine);


void __stdcall IActiveScriptError_GetSourceLineText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IActiveScriptError_INTERFACE_DEFINED__ */


#ifndef __IActiveScriptSiteWindow_INTERFACE_DEFINED__
#define __IActiveScriptSiteWindow_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IActiveScriptSiteWindow
 * at Sun Jul 07 10:45:05 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 



EXTERN_C const IID IID_IActiveScriptSiteWindow;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IActiveScriptSiteWindow : public IUnknown
    {
    public:
        virtual HRESULT __stdcall GetWindow( 
            /* [out] */ HWND  *phwnd) = 0;
        
        virtual HRESULT __stdcall EnableModeless( 
            /* [in] */ BOOL fEnable) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActiveScriptSiteWindowVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IActiveScriptSiteWindow  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IActiveScriptSiteWindow  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IActiveScriptSiteWindow  * This);
        
        HRESULT ( __stdcall  *GetWindow )( 
            IActiveScriptSiteWindow  * This,
            /* [out] */ HWND  *phwnd);
        
        HRESULT ( __stdcall  *EnableModeless )( 
            IActiveScriptSiteWindow  * This,
            /* [in] */ BOOL fEnable);
        
        END_INTERFACE
    } IActiveScriptSiteWindowVtbl;

    interface IActiveScriptSiteWindow
    {
        CONST_VTBL struct IActiveScriptSiteWindowVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActiveScriptSiteWindow_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActiveScriptSiteWindow_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActiveScriptSiteWindow_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActiveScriptSiteWindow_GetWindow(This,phwnd)	\
    (This)->lpVtbl -> GetWindow(This,phwnd)

#define IActiveScriptSiteWindow_EnableModeless(This,fEnable)	\
    (This)->lpVtbl -> EnableModeless(This,fEnable)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IActiveScriptSiteWindow_GetWindow_Proxy( 
    IActiveScriptSiteWindow  * This,
    /* [out] */ HWND  *phwnd);


void __stdcall IActiveScriptSiteWindow_GetWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IActiveScriptSiteWindow_EnableModeless_Proxy( 
    IActiveScriptSiteWindow  * This,
    /* [in] */ BOOL fEnable);


void __stdcall IActiveScriptSiteWindow_EnableModeless_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IActiveScriptSiteWindow_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0139
 * at Sun Jul 07 10:45:05 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


typedef IActiveScriptSite *PIActiveScriptSite;


extern RPC_IF_HANDLE __MIDL__intf_0139_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0139_v0_0_s_ifspec;

#ifndef __IActiveScript_INTERFACE_DEFINED__
#define __IActiveScript_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IActiveScript
 * at Sun Jul 07 10:45:05 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 



EXTERN_C const IID IID_IActiveScript;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IActiveScript : public IUnknown
    {
    public:
        virtual HRESULT __stdcall SetScriptSite( 
            /* [in] */ IActiveScriptSite  *pass) = 0;
        
        virtual HRESULT __stdcall GetScriptSite( 
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject) = 0;
        
        virtual HRESULT __stdcall SetScriptState( 
            /* [in] */ SCRIPTSTATE ss) = 0;
        
        virtual HRESULT __stdcall GetScriptState( 
            /* [out] */ SCRIPTSTATE  *pssState) = 0;
        
        virtual HRESULT __stdcall Close( void) = 0;
        
        virtual HRESULT __stdcall AddNamedItem( 
            /* [in] */ LPCOLESTR pstrName,
            /* [in] */ unsigned long dwFlags) = 0;
        
        virtual HRESULT __stdcall AddTypeLib( 
            /* [in] */ REFGUID rguidTypeLib,
            /* [in] */ unsigned long dwMajor,
            /* [in] */ unsigned long dwMinor,
            /* [in] */ unsigned long dwFlags) = 0;
        
        virtual HRESULT __stdcall GetScriptDispatch( 
            /* [in] */ LPCOLESTR pstrItemName,
            /* [out] */ IDispatch  * *ppdisp) = 0;
        
        virtual HRESULT __stdcall GetCurrentScriptThreadID( 
            /* [out] */ SCRIPTTHREADID  *pstidThread) = 0;
        
        virtual HRESULT __stdcall GetScriptThreadID( 
            /* [in] */ unsigned long dwWin32ThreadId,
            /* [out] */ SCRIPTTHREADID  *pstidThread) = 0;
        
        virtual HRESULT __stdcall GetScriptThreadState( 
            /* [in] */ SCRIPTTHREADID stidThread,
            /* [out] */ SCRIPTTHREADSTATE  *pstsState) = 0;
        
        virtual HRESULT __stdcall InterruptScriptThread( 
            /* [in] */ SCRIPTTHREADID stidThread,
            /* [in] */ const EXCEPINFO  *pexcepinfo,
            /* [in] */ unsigned long dwFlags) = 0;
        
        virtual HRESULT __stdcall Clone( 
            /* [out] */ IActiveScript  * *ppscript) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActiveScriptVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IActiveScript  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IActiveScript  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IActiveScript  * This);
        
        HRESULT ( __stdcall  *SetScriptSite )( 
            IActiveScript  * This,
            /* [in] */ IActiveScriptSite  *pass);
        
        HRESULT ( __stdcall  *GetScriptSite )( 
            IActiveScript  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        HRESULT ( __stdcall  *SetScriptState )( 
            IActiveScript  * This,
            /* [in] */ SCRIPTSTATE ss);
        
        HRESULT ( __stdcall  *GetScriptState )( 
            IActiveScript  * This,
            /* [out] */ SCRIPTSTATE  *pssState);
        
        HRESULT ( __stdcall  *Close )( 
            IActiveScript  * This);
        
        HRESULT ( __stdcall  *AddNamedItem )( 
            IActiveScript  * This,
            /* [in] */ LPCOLESTR pstrName,
            /* [in] */ unsigned long dwFlags);
        
        HRESULT ( __stdcall  *AddTypeLib )( 
            IActiveScript  * This,
            /* [in] */ REFGUID rguidTypeLib,
            /* [in] */ unsigned long dwMajor,
            /* [in] */ unsigned long dwMinor,
            /* [in] */ unsigned long dwFlags);
        
        HRESULT ( __stdcall  *GetScriptDispatch )( 
            IActiveScript  * This,
            /* [in] */ LPCOLESTR pstrItemName,
            /* [out] */ IDispatch  * *ppdisp);
        
        HRESULT ( __stdcall  *GetCurrentScriptThreadID )( 
            IActiveScript  * This,
            /* [out] */ SCRIPTTHREADID  *pstidThread);
        
        HRESULT ( __stdcall  *GetScriptThreadID )( 
            IActiveScript  * This,
            /* [in] */ unsigned long dwWin32ThreadId,
            /* [out] */ SCRIPTTHREADID  *pstidThread);
        
        HRESULT ( __stdcall  *GetScriptThreadState )( 
            IActiveScript  * This,
            /* [in] */ SCRIPTTHREADID stidThread,
            /* [out] */ SCRIPTTHREADSTATE  *pstsState);
        
        HRESULT ( __stdcall  *InterruptScriptThread )( 
            IActiveScript  * This,
            /* [in] */ SCRIPTTHREADID stidThread,
            /* [in] */ const EXCEPINFO  *pexcepinfo,
            /* [in] */ unsigned long dwFlags);
        
        HRESULT ( __stdcall  *Clone )( 
            IActiveScript  * This,
            /* [out] */ IActiveScript  * *ppscript);
        
        END_INTERFACE
    } IActiveScriptVtbl;

    interface IActiveScript
    {
        CONST_VTBL struct IActiveScriptVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActiveScript_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActiveScript_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActiveScript_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActiveScript_SetScriptSite(This,pass)	\
    (This)->lpVtbl -> SetScriptSite(This,pass)

#define IActiveScript_GetScriptSite(This,riid,ppvObject)	\
    (This)->lpVtbl -> GetScriptSite(This,riid,ppvObject)

#define IActiveScript_SetScriptState(This,ss)	\
    (This)->lpVtbl -> SetScriptState(This,ss)

#define IActiveScript_GetScriptState(This,pssState)	\
    (This)->lpVtbl -> GetScriptState(This,pssState)

#define IActiveScript_Close(This)	\
    (This)->lpVtbl -> Close(This)

#define IActiveScript_AddNamedItem(This,pstrName,dwFlags)	\
    (This)->lpVtbl -> AddNamedItem(This,pstrName,dwFlags)

#define IActiveScript_AddTypeLib(This,rguidTypeLib,dwMajor,dwMinor,dwFlags)	\
    (This)->lpVtbl -> AddTypeLib(This,rguidTypeLib,dwMajor,dwMinor,dwFlags)

#define IActiveScript_GetScriptDispatch(This,pstrItemName,ppdisp)	\
    (This)->lpVtbl -> GetScriptDispatch(This,pstrItemName,ppdisp)

#define IActiveScript_GetCurrentScriptThreadID(This,pstidThread)	\
    (This)->lpVtbl -> GetCurrentScriptThreadID(This,pstidThread)

#define IActiveScript_GetScriptThreadID(This,dwWin32ThreadId,pstidThread)	\
    (This)->lpVtbl -> GetScriptThreadID(This,dwWin32ThreadId,pstidThread)

#define IActiveScript_GetScriptThreadState(This,stidThread,pstsState)	\
    (This)->lpVtbl -> GetScriptThreadState(This,stidThread,pstsState)

#define IActiveScript_InterruptScriptThread(This,stidThread,pexcepinfo,dwFlags)	\
    (This)->lpVtbl -> InterruptScriptThread(This,stidThread,pexcepinfo,dwFlags)

#define IActiveScript_Clone(This,ppscript)	\
    (This)->lpVtbl -> Clone(This,ppscript)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IActiveScript_SetScriptSite_Proxy( 
    IActiveScript  * This,
    /* [in] */ IActiveScriptSite  *pass);


void __stdcall IActiveScript_SetScriptSite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IActiveScript_GetScriptSite_Proxy( 
    IActiveScript  * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void  * *ppvObject);


void __stdcall IActiveScript_GetScriptSite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IActiveScript_SetScriptState_Proxy( 
    IActiveScript  * This,
    /* [in] */ SCRIPTSTATE ss);


void __stdcall IActiveScript_SetScriptState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IActiveScript_GetScriptState_Proxy( 
    IActiveScript  * This,
    /* [out] */ SCRIPTSTATE  *pssState);


void __stdcall IActiveScript_GetScriptState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IActiveScript_Close_Proxy( 
    IActiveScript  * This);


void __stdcall IActiveScript_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IActiveScript_AddNamedItem_Proxy( 
    IActiveScript  * This,
    /* [in] */ LPCOLESTR pstrName,
    /* [in] */ unsigned long dwFlags);


void __stdcall IActiveScript_AddNamedItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IActiveScript_AddTypeLib_Proxy( 
    IActiveScript  * This,
    /* [in] */ REFGUID rguidTypeLib,
    /* [in] */ unsigned long dwMajor,
    /* [in] */ unsigned long dwMinor,
    /* [in] */ unsigned long dwFlags);


void __stdcall IActiveScript_AddTypeLib_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IActiveScript_GetScriptDispatch_Proxy( 
    IActiveScript  * This,
    /* [in] */ LPCOLESTR pstrItemName,
    /* [out] */ IDispatch  * *ppdisp);


void __stdcall IActiveScript_GetScriptDispatch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IActiveScript_GetCurrentScriptThreadID_Proxy( 
    IActiveScript  * This,
    /* [out] */ SCRIPTTHREADID  *pstidThread);


void __stdcall IActiveScript_GetCurrentScriptThreadID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IActiveScript_GetScriptThreadID_Proxy( 
    IActiveScript  * This,
    /* [in] */ unsigned long dwWin32ThreadId,
    /* [out] */ SCRIPTTHREADID  *pstidThread);


void __stdcall IActiveScript_GetScriptThreadID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IActiveScript_GetScriptThreadState_Proxy( 
    IActiveScript  * This,
    /* [in] */ SCRIPTTHREADID stidThread,
    /* [out] */ SCRIPTTHREADSTATE  *pstsState);


void __stdcall IActiveScript_GetScriptThreadState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IActiveScript_InterruptScriptThread_Proxy( 
    IActiveScript  * This,
    /* [in] */ SCRIPTTHREADID stidThread,
    /* [in] */ const EXCEPINFO  *pexcepinfo,
    /* [in] */ unsigned long dwFlags);


void __stdcall IActiveScript_InterruptScriptThread_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IActiveScript_Clone_Proxy( 
    IActiveScript  * This,
    /* [out] */ IActiveScript  * *ppscript);


void __stdcall IActiveScript_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IActiveScript_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0140
 * at Sun Jul 07 10:45:05 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


typedef IActiveScript *PIActiveScript;


extern RPC_IF_HANDLE __MIDL__intf_0140_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0140_v0_0_s_ifspec;

#ifndef __IActiveScriptParse_INTERFACE_DEFINED__
#define __IActiveScriptParse_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IActiveScriptParse
 * at Sun Jul 07 10:45:05 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 



EXTERN_C const IID IID_IActiveScriptParse;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IActiveScriptParse : public IUnknown
    {
    public:
        virtual HRESULT __stdcall InitNew( void) = 0;
        
        virtual HRESULT __stdcall AddScriptlet( 
            /* [in] */ LPCOLESTR pstrDefaultName,
            /* [in] */ LPCOLESTR pstrCode,
            /* [in] */ LPCOLESTR pstrItemName,
            /* [in] */ LPCOLESTR pstrSubItemName,
            /* [in] */ LPCOLESTR pstrEventName,
            /* [in] */ LPCOLESTR pstrDelimiter,
            /* [in] */ unsigned long dwSourceContextCookie,
            /* [in] */ unsigned long ulStartingLineNumber,
            /* [in] */ unsigned long dwFlags,
            /* [out] */ BSTR  *pbstrName,
            /* [out] */ EXCEPINFO  *pexcepinfo) = 0;
        
        virtual HRESULT __stdcall ParseScriptText( 
            /* [in] */ LPCOLESTR pstrCode,
            /* [in] */ LPCOLESTR pstrItemName,
            /* [in] */ IUnknown  *punkContext,
            /* [in] */ LPCOLESTR pstrDelimiter,
            /* [in] */ unsigned long dwSourceContextCookie,
            /* [in] */ unsigned long ulStartingLineNumber,
            /* [in] */ unsigned long dwFlags,
            /* [out] */ VARIANT  *pvarResult,
            /* [out] */ EXCEPINFO  *pexcepinfo) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActiveScriptParseVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IActiveScriptParse  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IActiveScriptParse  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IActiveScriptParse  * This);
        
        HRESULT ( __stdcall  *InitNew )( 
            IActiveScriptParse  * This);
        
        HRESULT ( __stdcall  *AddScriptlet )( 
            IActiveScriptParse  * This,
            /* [in] */ LPCOLESTR pstrDefaultName,
            /* [in] */ LPCOLESTR pstrCode,
            /* [in] */ LPCOLESTR pstrItemName,
            /* [in] */ LPCOLESTR pstrSubItemName,
            /* [in] */ LPCOLESTR pstrEventName,
            /* [in] */ LPCOLESTR pstrDelimiter,
            /* [in] */ unsigned long dwSourceContextCookie,
            /* [in] */ unsigned long ulStartingLineNumber,
            /* [in] */ unsigned long dwFlags,
            /* [out] */ BSTR  *pbstrName,
            /* [out] */ EXCEPINFO  *pexcepinfo);
        
        HRESULT ( __stdcall  *ParseScriptText )( 
            IActiveScriptParse  * This,
            /* [in] */ LPCOLESTR pstrCode,
            /* [in] */ LPCOLESTR pstrItemName,
            /* [in] */ IUnknown  *punkContext,
            /* [in] */ LPCOLESTR pstrDelimiter,
            /* [in] */ unsigned long dwSourceContextCookie,
            /* [in] */ unsigned long ulStartingLineNumber,
            /* [in] */ unsigned long dwFlags,
            /* [out] */ VARIANT  *pvarResult,
            /* [out] */ EXCEPINFO  *pexcepinfo);
        
        END_INTERFACE
    } IActiveScriptParseVtbl;

    interface IActiveScriptParse
    {
        CONST_VTBL struct IActiveScriptParseVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActiveScriptParse_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActiveScriptParse_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActiveScriptParse_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActiveScriptParse_InitNew(This)	\
    (This)->lpVtbl -> InitNew(This)

#define IActiveScriptParse_AddScriptlet(This,pstrDefaultName,pstrCode,pstrItemName,pstrSubItemName,pstrEventName,pstrDelimiter,dwSourceContextCookie,ulStartingLineNumber,dwFlags,pbstrName,pexcepinfo)	\
    (This)->lpVtbl -> AddScriptlet(This,pstrDefaultName,pstrCode,pstrItemName,pstrSubItemName,pstrEventName,pstrDelimiter,dwSourceContextCookie,ulStartingLineNumber,dwFlags,pbstrName,pexcepinfo)

#define IActiveScriptParse_ParseScriptText(This,pstrCode,pstrItemName,punkContext,pstrDelimiter,dwSourceContextCookie,ulStartingLineNumber,dwFlags,pvarResult,pexcepinfo)	\
    (This)->lpVtbl -> ParseScriptText(This,pstrCode,pstrItemName,punkContext,pstrDelimiter,dwSourceContextCookie,ulStartingLineNumber,dwFlags,pvarResult,pexcepinfo)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IActiveScriptParse_InitNew_Proxy( 
    IActiveScriptParse  * This);


void __stdcall IActiveScriptParse_InitNew_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IActiveScriptParse_AddScriptlet_Proxy( 
    IActiveScriptParse  * This,
    /* [in] */ LPCOLESTR pstrDefaultName,
    /* [in] */ LPCOLESTR pstrCode,
    /* [in] */ LPCOLESTR pstrItemName,
    /* [in] */ LPCOLESTR pstrSubItemName,
    /* [in] */ LPCOLESTR pstrEventName,
    /* [in] */ LPCOLESTR pstrDelimiter,
    /* [in] */ unsigned long dwSourceContextCookie,
    /* [in] */ unsigned long ulStartingLineNumber,
    /* [in] */ unsigned long dwFlags,
    /* [out] */ BSTR  *pbstrName,
    /* [out] */ EXCEPINFO  *pexcepinfo);


void __stdcall IActiveScriptParse_AddScriptlet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IActiveScriptParse_ParseScriptText_Proxy( 
    IActiveScriptParse  * This,
    /* [in] */ LPCOLESTR pstrCode,
    /* [in] */ LPCOLESTR pstrItemName,
    /* [in] */ IUnknown  *punkContext,
    /* [in] */ LPCOLESTR pstrDelimiter,
    /* [in] */ unsigned long dwSourceContextCookie,
    /* [in] */ unsigned long ulStartingLineNumber,
    /* [in] */ unsigned long dwFlags,
    /* [out] */ VARIANT  *pvarResult,
    /* [out] */ EXCEPINFO  *pexcepinfo);


void __stdcall IActiveScriptParse_ParseScriptText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IActiveScriptParse_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0141
 * at Sun Jul 07 10:45:05 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 



typedef IActiveScriptParse *PIActiveScriptParse;

#endif  // __ActivScp_h



extern RPC_IF_HANDLE __MIDL__intf_0141_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0141_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */


void __stdcall UserHWND_from_local( HWND  *, UserHWND  *  * );
void __stdcall UserHWND_to_local( UserHWND  *, HWND  * );
 void __stdcall UserHWND_free_inst( UserHWND  * );
void __stdcall UserHWND_free_local( HWND  * );

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

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
#pragma once 
