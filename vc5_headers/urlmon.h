/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.00.44 */
/* at Fri Aug 02 15:31:22 1996
 */
/* Compiler settings for urlmon.idl:
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

#ifndef __urlmon_h__
#define __urlmon_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IPersistMoniker_FWD_DEFINED__
#define __IPersistMoniker_FWD_DEFINED__
typedef interface IPersistMoniker IPersistMoniker;
#endif 	/* __IPersistMoniker_FWD_DEFINED__ */


#ifndef __IBindProtocol_FWD_DEFINED__
#define __IBindProtocol_FWD_DEFINED__
typedef interface IBindProtocol IBindProtocol;
#endif 	/* __IBindProtocol_FWD_DEFINED__ */


#ifndef __IBinding_FWD_DEFINED__
#define __IBinding_FWD_DEFINED__
typedef interface IBinding IBinding;
#endif 	/* __IBinding_FWD_DEFINED__ */


#ifndef __IBindStatusCallback_FWD_DEFINED__
#define __IBindStatusCallback_FWD_DEFINED__
typedef interface IBindStatusCallback IBindStatusCallback;
#endif 	/* __IBindStatusCallback_FWD_DEFINED__ */


#ifndef __IAuthenticate_FWD_DEFINED__
#define __IAuthenticate_FWD_DEFINED__
typedef interface IAuthenticate IAuthenticate;
#endif 	/* __IAuthenticate_FWD_DEFINED__ */


#ifndef __IHttpNegotiate_FWD_DEFINED__
#define __IHttpNegotiate_FWD_DEFINED__
typedef interface IHttpNegotiate IHttpNegotiate;
#endif 	/* __IHttpNegotiate_FWD_DEFINED__ */


#ifndef __IWindowForBindingUI_FWD_DEFINED__
#define __IWindowForBindingUI_FWD_DEFINED__
typedef interface IWindowForBindingUI IWindowForBindingUI;
#endif 	/* __IWindowForBindingUI_FWD_DEFINED__ */


#ifndef __ICodeInstall_FWD_DEFINED__
#define __ICodeInstall_FWD_DEFINED__
typedef interface ICodeInstall ICodeInstall;
#endif 	/* __ICodeInstall_FWD_DEFINED__ */


#ifndef __IWinInetInfo_FWD_DEFINED__
#define __IWinInetInfo_FWD_DEFINED__
typedef interface IWinInetInfo IWinInetInfo;
#endif 	/* __IWinInetInfo_FWD_DEFINED__ */


#ifndef __IHttpSecurity_FWD_DEFINED__
#define __IHttpSecurity_FWD_DEFINED__
typedef interface IHttpSecurity IHttpSecurity;
#endif 	/* __IHttpSecurity_FWD_DEFINED__ */


#ifndef __IWinInetHttpInfo_FWD_DEFINED__
#define __IWinInetHttpInfo_FWD_DEFINED__
typedef interface IWinInetHttpInfo IWinInetHttpInfo;
#endif 	/* __IWinInetHttpInfo_FWD_DEFINED__ */


#ifndef __IBindHost_FWD_DEFINED__
#define __IBindHost_FWD_DEFINED__
typedef interface IBindHost IBindHost;
#endif 	/* __IBindHost_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"
#include "oleidl.h"
#include "servprov.h"

void  * __stdcall MIDL_user_allocate(size_t);
void __stdcall MIDL_user_free( void  * ); 

/****************************************
 * Generated header for interface: __MIDL__intf_0000
 * at Fri Aug 02 15:31:22 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


//=--------------------------------------------------------------------------=
// UrlMon.h
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
// URL Moniker Interfaces.











// These are for backwards compatibility with previous URLMON versions
#define BINDF_DONTUSECACHE BINDF_GETNEWESTVERSION
#define BINDF_DONTPUTINCACHE BINDF_NOWRITECACHE
#define BINDF_NOCOPYDATA BINDF_PULLDATA
EXTERN_C const IID IID_IAsyncMoniker;    
EXTERN_C const IID CLSID_StdURLMoniker;  
EXTERN_C const IID CLSID_HttpProtocol;   
EXTERN_C const IID CLSID_FtpProtocol;    
EXTERN_C const IID CLSID_GopherProtocol; 
EXTERN_C const IID CLSID_HttpSProtocol;  
EXTERN_C const IID CLSID_FileProtocol;   
EXTERN_C const IID CLSID_MkProtocol;     
 
#define SZ_URLCONTEXT           OLESTR("URL Context")
#define SZ_ASYNC_CALLEE         OLESTR("AsyncCallee")
#define MKSYS_URLMONIKER    6                 
 
STDAPI CreateURLMoniker(LPMONIKER pMkCtx, const wchar_t* szURL, LPMONIKER  * ppmk);             
STDAPI GetClassURL(const wchar_t* szURL, CLSID *pClsID);                                           
STDAPI CreateAsyncBindCtx(unsigned long reserved, IBindStatusCallback *pBSCb,                       
                                IEnumFORMATETC *pEFetc, IBindCtx **ppBC);                   
STDAPI MkParseDisplayNameEx(IBindCtx *pbc, const wchar_t* szDisplayName, unsigned long *pchEaten,          
                                LPMONIKER *ppmk);                                           
STDAPI RegisterBindStatusCallback(LPBC pBC, IBindStatusCallback *pBSCb,                     
                                IBindStatusCallback**  ppBSCBPrev, unsigned long dwReserved);       
STDAPI RevokeBindStatusCallback(LPBC pBC, IBindStatusCallback *pBSCb);                      
STDAPI GetClassFileOrMime(LPBC pBC, const wchar_t* szFilename, void* pBuffer, unsigned long cbSize, const wchar_t* szMime, unsigned long dwReserved, CLSID *pclsid); 
STDAPI IsValidURL(LPBC pBC, const wchar_t* szURL, unsigned long dwReserved);                               
STDAPI CoGetClassObjectFromURL( REFCLSID rCLASSID,
            const wchar_t* szCODE, unsigned long dwFileVersionMS, 
            unsigned long dwFileVersionLS, const wchar_t* szTYPE,
            LPBINDCTX pBindCtx, unsigned long dwClsContext,
            void* pvReserved, REFIID riid, void* * ppv);
 
//helper apis                                                                               
STDAPI IsAsyncMoniker(IMoniker* pmk);                                                       
STDAPI CreateURLBinding(const wchar_t* lpszUrl, IBindCtx *pbc, IBinding **ppBdg);                  
 
STDAPI RegisterMediaTypesW(UINT ctypes, const const wchar_t** rgszTypes, CLIPFORMAT* rgcfTypes);          
STDAPI RegisterMediaTypes(UINT ctypes, const const char** rgszTypes, CLIPFORMAT* rgcfTypes);            
STDAPI FindMediaType(const char* rgszTypes, CLIPFORMAT* rgcfTypes);                                       
STDAPI CreateFormatEnumerator( UINT cfmtetc, FORMATETC* rgfmtetc, IEnumFORMATETC** ppenumfmtetc); 
STDAPI RegisterFormatEnumerator(LPBC pBC, IEnumFORMATETC *pEFetc, unsigned long reserved);          
STDAPI RevokeFormatEnumerator(LPBC pBC, IEnumFORMATETC *pEFetc);                            
STDAPI RegisterMediaTypeClass(LPBC pBC,UINT ctypes, const const char** rgszTypes, CLSID *rgclsID, unsigned long reserved);    
STDAPI FindMediaTypeClass(LPBC pBC, const char* szType, CLSID *pclsID, unsigned long reserved);                          
STDAPI UrlMkSetSessionOption(unsigned long dwOption, void* pBuffer, unsigned long dwBufferLength, unsigned long dwReserved);       
 
// URLMON-specific defines for UrlMkSetSessionOption() above
#define URLMON_OPTION_USERAGENT  0x10000001
 
#define CF_NULL                 0                                  
#define CFSTR_MIME_NULL         NULL                               
#define CFSTR_MIME_TEXT         (TEXT("text/plain"))             
#define CFSTR_MIME_RICHTEXT     (TEXT("text/richtext"))          
#define CFSTR_MIME_X_BITMAP     (TEXT("image/x-xbitmap"))        
#define CFSTR_MIME_POSTSCRIPT   (TEXT("application/postscript")) 
#define CFSTR_MIME_AIFF         (TEXT("audio/aiff"))             
#define CFSTR_MIME_BASICAUDIO   (TEXT("audio/basic"))            
#define CFSTR_MIME_WAV          (TEXT("audio/wav"))              
#define CFSTR_MIME_X_WAV        (TEXT("audio/x-wav"))            
#define CFSTR_MIME_GIF          (TEXT("image/gif"))              
#define CFSTR_MIME_PJPEG        (TEXT("image/pjpeg"))            
#define CFSTR_MIME_JPEG         (TEXT("image/jpeg"))             
#define CFSTR_MIME_TIFF         (TEXT("image/tiff"))             
#define CFSTR_MIME_X_PNG        (TEXT("image/x-png"))            
#define CFSTR_MIME_BMP          (TEXT("image/bmp"))              
#define CFSTR_MIME_X_ART        (TEXT("image/x-jg"))             
#define CFSTR_MIME_AVI          (TEXT("video/avi"))              
#define CFSTR_MIME_MPEG         (TEXT("video/mpeg"))             
#define CFSTR_MIME_FRACTALS     (TEXT("application/fractals"))   
#define CFSTR_MIME_RAWDATA      (TEXT("application/octet-stream"))
#define CFSTR_MIME_RAWDATASTRM  (TEXT("application/octet-stream"))
#define CFSTR_MIME_PDF          (TEXT("application/pdf"))        
#define CFSTR_MIME_X_AIFF       (TEXT("audio/x-aiff"))           
#define CFSTR_MIME_X_REALAUDIO  (TEXT("audio/x-pn-realaudio"))   
#define CFSTR_MIME_XBM          (TEXT("image/xbm"))              
#define CFSTR_MIME_QUICKTIME    (TEXT("video/quicktime"))        
#define CFSTR_MIME_X_MSVIDEO    (TEXT("video/x-msvideo"))        
#define CFSTR_MIME_X_SGI_MOVIE  (TEXT("video/x-sgi-movie"))      
#define CFSTR_MIME_HTML         (TEXT("text/html"))              
 
// MessageId: MK_S_ASYNCHRONOUS                                              
// MessageText: Operation is successful, but will complete asynchronously.   
//                                                                           
#define MK_S_ASYNCHRONOUS    _HRESULT_TYPEDEF_(0x000401E8L)                  
#define S_ASYNCHRONOUS       MK_S_ASYNCHRONOUS                               
                                                                             
#ifndef E_PENDING                                                            
#define E_PENDING _HRESULT_TYPEDEF_(0x8000000AL)                             
#endif                                                                       
                                                                             
//                                                                           
//                                                                           
// WinINet and protocol specific errors are mapped to one of the following   
// error which are returned in IBSC::OnStopBinding                           
//                                                                           
//                                                                           
#define INET_E_INVALID_URL               _HRESULT_TYPEDEF_(0x800C0002L)      
#define INET_E_NO_SESSION                _HRESULT_TYPEDEF_(0x800C0003L)      
#define INET_E_CANNOT_CONNECT            _HRESULT_TYPEDEF_(0x800C0004L)      
#define INET_E_RESOURCE_NOT_FOUND        _HRESULT_TYPEDEF_(0x800C0005L)      
#define INET_E_OBJECT_NOT_FOUND          _HRESULT_TYPEDEF_(0x800C0006L)      
#define INET_E_DATA_NOT_AVAILABLE        _HRESULT_TYPEDEF_(0x800C0007L)      
#define INET_E_DOWNLOAD_FAILURE          _HRESULT_TYPEDEF_(0x800C0008L)      
#define INET_E_AUTHENTICATION_REQUIRED   _HRESULT_TYPEDEF_(0x800C0009L)      
#define INET_E_NO_VALID_MEDIA            _HRESULT_TYPEDEF_(0x800C000AL)      
#define INET_E_CONNECTION_TIMEOUT        _HRESULT_TYPEDEF_(0x800C000BL)      
#define INET_E_INVALID_REQUEST           _HRESULT_TYPEDEF_(0x800C000CL)      
#define INET_E_UNKNOWN_PROTOCOL          _HRESULT_TYPEDEF_(0x800C000DL)      
#define INET_E_SECURITY_PROBLEM          _HRESULT_TYPEDEF_(0x800C000EL)      
#define INET_E_CANNOT_LOAD_DATA          _HRESULT_TYPEDEF_(0x800C000FL)      
#define INET_E_CANNOT_INSTANTIATE_OBJECT _HRESULT_TYPEDEF_(0x800C0010L)      
#define INET_E_ERROR_FIRST               _HRESULT_TYPEDEF_(0x800C0002L)      
#define INET_E_ERROR_LAST                INET_E_CANNOT_INSTANTIATE_OBJECT    
#ifndef _LPPERSISTMONIKER_DEFINED
#define _LPPERSISTMONIKER_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0000_v0_0_s_ifspec;

#ifndef __IPersistMoniker_INTERFACE_DEFINED__
#define __IPersistMoniker_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IPersistMoniker
 * at Fri Aug 02 15:31:22 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IPersistMoniker  *LPPERSISTMONIKER;


EXTERN_C const IID IID_IPersistMoniker;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IPersistMoniker : public IUnknown
    {
    public:
        virtual HRESULT __stdcall GetClassID( 
            /* [out] */ CLSID  *pClassID) = 0;
        
        virtual HRESULT __stdcall IsDirty( void) = 0;
        
        virtual HRESULT __stdcall Load( 
            /* [in] */ BOOL fFullyAvailable,
            /* [in] */ IMoniker  *pimkName,
            /* [in] */ LPBC pibc,
            /* [in] */ unsigned long grfMode) = 0;
        
        virtual HRESULT __stdcall Save( 
            /* [in] */ IMoniker  *pimkName,
            /* [in] */ LPBC pbc,
            /* [in] */ BOOL fRemember) = 0;
        
        virtual HRESULT __stdcall SaveCompleted( 
            /* [in] */ IMoniker  *pimkName,
            /* [in] */ LPBC pibc) = 0;
        
        virtual HRESULT __stdcall GetCurMoniker( 
            /* [out] */ IMoniker  * *ppimkName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPersistMonikerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IPersistMoniker  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IPersistMoniker  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IPersistMoniker  * This);
        
        HRESULT ( __stdcall  *GetClassID )( 
            IPersistMoniker  * This,
            /* [out] */ CLSID  *pClassID);
        
        HRESULT ( __stdcall  *IsDirty )( 
            IPersistMoniker  * This);
        
        HRESULT ( __stdcall  *Load )( 
            IPersistMoniker  * This,
            /* [in] */ BOOL fFullyAvailable,
            /* [in] */ IMoniker  *pimkName,
            /* [in] */ LPBC pibc,
            /* [in] */ unsigned long grfMode);
        
        HRESULT ( __stdcall  *Save )( 
            IPersistMoniker  * This,
            /* [in] */ IMoniker  *pimkName,
            /* [in] */ LPBC pbc,
            /* [in] */ BOOL fRemember);
        
        HRESULT ( __stdcall  *SaveCompleted )( 
            IPersistMoniker  * This,
            /* [in] */ IMoniker  *pimkName,
            /* [in] */ LPBC pibc);
        
        HRESULT ( __stdcall  *GetCurMoniker )( 
            IPersistMoniker  * This,
            /* [out] */ IMoniker  * *ppimkName);
        
        END_INTERFACE
    } IPersistMonikerVtbl;

    interface IPersistMoniker
    {
        CONST_VTBL struct IPersistMonikerVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPersistMoniker_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPersistMoniker_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPersistMoniker_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPersistMoniker_GetClassID(This,pClassID)	\
    (This)->lpVtbl -> GetClassID(This,pClassID)

#define IPersistMoniker_IsDirty(This)	\
    (This)->lpVtbl -> IsDirty(This)

#define IPersistMoniker_Load(This,fFullyAvailable,pimkName,pibc,grfMode)	\
    (This)->lpVtbl -> Load(This,fFullyAvailable,pimkName,pibc,grfMode)

#define IPersistMoniker_Save(This,pimkName,pbc,fRemember)	\
    (This)->lpVtbl -> Save(This,pimkName,pbc,fRemember)

#define IPersistMoniker_SaveCompleted(This,pimkName,pibc)	\
    (This)->lpVtbl -> SaveCompleted(This,pimkName,pibc)

#define IPersistMoniker_GetCurMoniker(This,ppimkName)	\
    (This)->lpVtbl -> GetCurMoniker(This,ppimkName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IPersistMoniker_GetClassID_Proxy( 
    IPersistMoniker  * This,
    /* [out] */ CLSID  *pClassID);


void __stdcall IPersistMoniker_GetClassID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPersistMoniker_IsDirty_Proxy( 
    IPersistMoniker  * This);


void __stdcall IPersistMoniker_IsDirty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPersistMoniker_Load_Proxy( 
    IPersistMoniker  * This,
    /* [in] */ BOOL fFullyAvailable,
    /* [in] */ IMoniker  *pimkName,
    /* [in] */ LPBC pibc,
    /* [in] */ unsigned long grfMode);


void __stdcall IPersistMoniker_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPersistMoniker_Save_Proxy( 
    IPersistMoniker  * This,
    /* [in] */ IMoniker  *pimkName,
    /* [in] */ LPBC pbc,
    /* [in] */ BOOL fRemember);


void __stdcall IPersistMoniker_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPersistMoniker_SaveCompleted_Proxy( 
    IPersistMoniker  * This,
    /* [in] */ IMoniker  *pimkName,
    /* [in] */ LPBC pibc);


void __stdcall IPersistMoniker_SaveCompleted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IPersistMoniker_GetCurMoniker_Proxy( 
    IPersistMoniker  * This,
    /* [out] */ IMoniker  * *ppimkName);


void __stdcall IPersistMoniker_GetCurMoniker_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IPersistMoniker_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0082
 * at Fri Aug 02 15:31:22 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif
#ifndef _LPBINDPROTOCOL_DEFINED
#define _LPBINDPROTOCOL_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0082_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0082_v0_0_s_ifspec;

#ifndef __IBindProtocol_INTERFACE_DEFINED__
#define __IBindProtocol_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IBindProtocol
 * at Fri Aug 02 15:31:22 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef /* [unique] */ IBindProtocol  *LPBINDPROTOCOL;


EXTERN_C const IID IID_IBindProtocol;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IBindProtocol : public IUnknown
    {
    public:
        virtual HRESULT __stdcall CreateBinding( 
            /* [in] */ const wchar_t* szUrl,
            /* [in] */ IBindCtx  *pbc,
            /* [out] */ IBinding  * *ppb) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBindProtocolVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IBindProtocol  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IBindProtocol  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IBindProtocol  * This);
        
        HRESULT ( __stdcall  *CreateBinding )( 
            IBindProtocol  * This,
            /* [in] */ const wchar_t* szUrl,
            /* [in] */ IBindCtx  *pbc,
            /* [out] */ IBinding  * *ppb);
        
        END_INTERFACE
    } IBindProtocolVtbl;

    interface IBindProtocol
    {
        CONST_VTBL struct IBindProtocolVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBindProtocol_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBindProtocol_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBindProtocol_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBindProtocol_CreateBinding(This,szUrl,pbc,ppb)	\
    (This)->lpVtbl -> CreateBinding(This,szUrl,pbc,ppb)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IBindProtocol_CreateBinding_Proxy( 
    IBindProtocol  * This,
    /* [in] */ const wchar_t* szUrl,
    /* [in] */ IBindCtx  *pbc,
    /* [out] */ IBinding  * *ppb);


void __stdcall IBindProtocol_CreateBinding_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IBindProtocol_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0083
 * at Fri Aug 02 15:31:22 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif
#ifndef _LPBINDING_DEFINED
#define _LPBINDING_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0083_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0083_v0_0_s_ifspec;

#ifndef __IBinding_INTERFACE_DEFINED__
#define __IBinding_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IBinding
 * at Fri Aug 02 15:31:22 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IBinding  *LPBINDING;


EXTERN_C const IID IID_IBinding;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IBinding : public IUnknown
    {
    public:
        virtual HRESULT __stdcall Abort( void) = 0;
        
        virtual HRESULT __stdcall Suspend( void) = 0;
        
        virtual HRESULT __stdcall Resume( void) = 0;
        
        virtual HRESULT __stdcall SetPriority( 
            /* [in] */ LONG nPriority) = 0;
        
        virtual HRESULT __stdcall GetPriority( 
            /* [out] */ LONG  *pnPriority) = 0;
        
        virtual /* [local] */ HRESULT __stdcall GetBindResult( 
            /* [out] */ CLSID  *pclsidProtocol,
            /* [out] */ unsigned long  *pdwResult,
            /* [out] */ LPOLESTR  *pszResult,
            /* [out][in] */ unsigned long  *pdwReserved) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBindingVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IBinding  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IBinding  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IBinding  * This);
        
        HRESULT ( __stdcall  *Abort )( 
            IBinding  * This);
        
        HRESULT ( __stdcall  *Suspend )( 
            IBinding  * This);
        
        HRESULT ( __stdcall  *Resume )( 
            IBinding  * This);
        
        HRESULT ( __stdcall  *SetPriority )( 
            IBinding  * This,
            /* [in] */ LONG nPriority);
        
        HRESULT ( __stdcall  *GetPriority )( 
            IBinding  * This,
            /* [out] */ LONG  *pnPriority);
        
        /* [local] */ HRESULT ( __stdcall  *GetBindResult )( 
            IBinding  * This,
            /* [out] */ CLSID  *pclsidProtocol,
            /* [out] */ unsigned long  *pdwResult,
            /* [out] */ LPOLESTR  *pszResult,
            /* [out][in] */ unsigned long  *pdwReserved);
        
        END_INTERFACE
    } IBindingVtbl;

    interface IBinding
    {
        CONST_VTBL struct IBindingVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBinding_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBinding_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBinding_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBinding_Abort(This)	\
    (This)->lpVtbl -> Abort(This)

#define IBinding_Suspend(This)	\
    (This)->lpVtbl -> Suspend(This)

#define IBinding_Resume(This)	\
    (This)->lpVtbl -> Resume(This)

#define IBinding_SetPriority(This,nPriority)	\
    (This)->lpVtbl -> SetPriority(This,nPriority)

#define IBinding_GetPriority(This,pnPriority)	\
    (This)->lpVtbl -> GetPriority(This,pnPriority)

#define IBinding_GetBindResult(This,pclsidProtocol,pdwResult,pszResult,pdwReserved)	\
    (This)->lpVtbl -> GetBindResult(This,pclsidProtocol,pdwResult,pszResult,pdwReserved)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IBinding_Abort_Proxy( 
    IBinding  * This);


void __stdcall IBinding_Abort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IBinding_Suspend_Proxy( 
    IBinding  * This);


void __stdcall IBinding_Suspend_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IBinding_Resume_Proxy( 
    IBinding  * This);


void __stdcall IBinding_Resume_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IBinding_SetPriority_Proxy( 
    IBinding  * This,
    /* [in] */ LONG nPriority);


void __stdcall IBinding_SetPriority_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IBinding_GetPriority_Proxy( 
    IBinding  * This,
    /* [out] */ LONG  *pnPriority);


void __stdcall IBinding_GetPriority_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall IBinding_RemoteGetBindResult_Proxy( 
    IBinding  * This,
    /* [out] */ CLSID  *pclsidProtocol,
    /* [out] */ unsigned long  *pdwResult,
    /* [out] */ LPOLESTR  *pszResult,
    /* [in] */ unsigned long dwReserved);


void __stdcall IBinding_RemoteGetBindResult_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IBinding_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0084
 * at Fri Aug 02 15:31:22 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif
#ifndef _LPBINDSTATUSCALLBACK_DEFINED
#define _LPBINDSTATUSCALLBACK_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0084_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0084_v0_0_s_ifspec;

#ifndef __IBindStatusCallback_INTERFACE_DEFINED__
#define __IBindStatusCallback_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IBindStatusCallback
 * at Fri Aug 02 15:31:22 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IBindStatusCallback  *LPBINDSTATUSCALLBACK;

typedef /* [public] */ 
enum __MIDL_IBindStatusCallback_0001
    {	BINDVERB_GET	= 0,
	BINDVERB_POST	= 0x1,
	BINDVERB_PUT	= 0x2,
	BINDVERB_CUSTOM	= 0x3
    }	BINDVERB;

typedef /* [public] */ 
enum __MIDL_IBindStatusCallback_0002
    {	BINDINFOF_URLENCODESTGMEDDATA	= 0x1,
	BINDINFOF_URLENCODEDEXTRAINFO	= 0x2
    }	BINDINFOF;

typedef /* [public] */ 
enum __MIDL_IBindStatusCallback_0003
    {	BINDF_ASYNCHRONOUS	= 0x1,
	BINDF_ASYNCSTORAGE	= 0x2,
	BINDF_NOPROGRESSIVERENDERING	= 0x4,
	BINDF_OFFLINEOPERATION	= 0x8,
	BINDF_GETNEWESTVERSION	= 0x10,
	BINDF_NOWRITECACHE	= 0x20,
	BINDF_PULLDATA	= 0x80,
	BINDF_IGNORESECURITYPROBLEM	= 0x100,
	BINDF_RESYNCHRONIZE	= 0x200,
	BINDF_HYPERLINK	= 0x400,
	BINDF_INLINESGETNEWESTVERSION	= 0x10000000,
	BINDF_INLINESRESYNCHRONIZE	= 0x20000000,
	BINDF_CONTAINER_NOWRITECACHE	= 0x40000000
    }	BINDF;

typedef struct  _tagBINDINFO
    {
    unsigned long cbSize;
    wchar_t* szExtraInfo;
    STGMEDIUM stgmedData;
    unsigned long grfBindInfoF;
    unsigned long dwBindVerb;
    wchar_t* szCustomVerb;
    unsigned long cbstgmedData;
    }	BINDINFO;

typedef struct  _tagRemBINDINFO
    {
    unsigned long cbSize;
    wchar_t* szExtraInfo;
    unsigned long grfBindInfoF;
    unsigned long dwBindVerb;
    wchar_t* szCustomVerb;
    unsigned long cbstgmedData;
    }	RemBINDINFO;

typedef struct  tagRemFORMATETC
    {
    unsigned long cfFormat;
    unsigned long ptd;
    unsigned long dwAspect;
    LONG lindex;
    unsigned long tymed;
    }	RemFORMATETC;

typedef struct tagRemFORMATETC  *LPREMFORMATETC;

typedef /* [public] */ 
enum __MIDL_IBindStatusCallback_0004
    {	BSCF_FIRSTDATANOTIFICATION	= 0x1,
	BSCF_INTERMEDIATEDATANOTIFICATION	= 0x2,
	BSCF_LASTDATANOTIFICATION	= 0x4
    }	BSCF;

typedef 
enum tagBINDSTATUS
    {	BINDSTATUS_FINDINGRESOURCE	= 1,
	BINDSTATUS_CONNECTING	= BINDSTATUS_FINDINGRESOURCE + 1,
	BINDSTATUS_REDIRECTING	= BINDSTATUS_CONNECTING + 1,
	BINDSTATUS_BEGINDOWNLOADDATA	= BINDSTATUS_REDIRECTING + 1,
	BINDSTATUS_DOWNLOADINGDATA	= BINDSTATUS_BEGINDOWNLOADDATA + 1,
	BINDSTATUS_ENDDOWNLOADDATA	= BINDSTATUS_DOWNLOADINGDATA + 1,
	BINDSTATUS_BEGINDOWNLOADCOMPONENTS	= BINDSTATUS_ENDDOWNLOADDATA + 1,
	BINDSTATUS_INSTALLINGCOMPONENTS	= BINDSTATUS_BEGINDOWNLOADCOMPONENTS + 1,
	BINDSTATUS_ENDDOWNLOADCOMPONENTS	= BINDSTATUS_INSTALLINGCOMPONENTS + 1,
	BINDSTATUS_USINGCACHEDCOPY	= BINDSTATUS_ENDDOWNLOADCOMPONENTS + 1,
	BINDSTATUS_SENDINGREQUEST	= BINDSTATUS_USINGCACHEDCOPY + 1,
	BINDSTATUS_CLASSIDAVAILABLE	= BINDSTATUS_SENDINGREQUEST + 1,
	BINDSTATUS_MIMETYPEAVAILABLE	= BINDSTATUS_CLASSIDAVAILABLE + 1,
	BINDSTATUS_CACHEFILENAMEAVAILABLE	= BINDSTATUS_MIMETYPEAVAILABLE + 1
    }	BINDSTATUS;


EXTERN_C const IID IID_IBindStatusCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IBindStatusCallback : public IUnknown
    {
    public:
        virtual HRESULT __stdcall OnStartBinding( 
            /* [in] */ unsigned long dwReserved,
            /* [in] */ IBinding  *pib) = 0;
        
        virtual HRESULT __stdcall GetPriority( 
            /* [out] */ LONG  *pnPriority) = 0;
        
        virtual HRESULT __stdcall OnLowResource( 
            /* [in] */ unsigned long reserved) = 0;
        
        virtual HRESULT __stdcall OnProgress( 
            /* [in] */ unsigned long ulProgress,
            /* [in] */ unsigned long ulProgressMax,
            /* [in] */ unsigned long ulStatusCode,
            /* [in] */ const wchar_t* szStatusText) = 0;
        
        virtual HRESULT __stdcall OnStopBinding( 
            /* [in] */ HRESULT hresult,
            /* [unique][in] */ const wchar_t* szError) = 0;
        
        virtual /* [local] */ HRESULT __stdcall GetBindInfo( 
            /* [out] */ unsigned long  *grfBINDF,
            /* [unique][out][in] */ BINDINFO  *pbindinfo) = 0;
        
        virtual /* [local] */ HRESULT __stdcall OnDataAvailable( 
            /* [in] */ unsigned long grfBSCF,
            /* [in] */ unsigned long dwSize,
            /* [in] */ FORMATETC  *pformatetc,
            /* [in] */ STGMEDIUM  *pstgmed) = 0;
        
        virtual HRESULT __stdcall OnObjectAvailable( 
            /* [in] */ REFIID riid,
            /* [iid_is][in] */ IUnknown  *punk) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBindStatusCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IBindStatusCallback  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IBindStatusCallback  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IBindStatusCallback  * This);
        
        HRESULT ( __stdcall  *OnStartBinding )( 
            IBindStatusCallback  * This,
            /* [in] */ unsigned long dwReserved,
            /* [in] */ IBinding  *pib);
        
        HRESULT ( __stdcall  *GetPriority )( 
            IBindStatusCallback  * This,
            /* [out] */ LONG  *pnPriority);
        
        HRESULT ( __stdcall  *OnLowResource )( 
            IBindStatusCallback  * This,
            /* [in] */ unsigned long reserved);
        
        HRESULT ( __stdcall  *OnProgress )( 
            IBindStatusCallback  * This,
            /* [in] */ unsigned long ulProgress,
            /* [in] */ unsigned long ulProgressMax,
            /* [in] */ unsigned long ulStatusCode,
            /* [in] */ const wchar_t* szStatusText);
        
        HRESULT ( __stdcall  *OnStopBinding )( 
            IBindStatusCallback  * This,
            /* [in] */ HRESULT hresult,
            /* [unique][in] */ const wchar_t* szError);
        
        /* [local] */ HRESULT ( __stdcall  *GetBindInfo )( 
            IBindStatusCallback  * This,
            /* [out] */ unsigned long  *grfBINDF,
            /* [unique][out][in] */ BINDINFO  *pbindinfo);
        
        /* [local] */ HRESULT ( __stdcall  *OnDataAvailable )( 
            IBindStatusCallback  * This,
            /* [in] */ unsigned long grfBSCF,
            /* [in] */ unsigned long dwSize,
            /* [in] */ FORMATETC  *pformatetc,
            /* [in] */ STGMEDIUM  *pstgmed);
        
        HRESULT ( __stdcall  *OnObjectAvailable )( 
            IBindStatusCallback  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][in] */ IUnknown  *punk);
        
        END_INTERFACE
    } IBindStatusCallbackVtbl;

    interface IBindStatusCallback
    {
        CONST_VTBL struct IBindStatusCallbackVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBindStatusCallback_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBindStatusCallback_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBindStatusCallback_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBindStatusCallback_OnStartBinding(This,dwReserved,pib)	\
    (This)->lpVtbl -> OnStartBinding(This,dwReserved,pib)

#define IBindStatusCallback_GetPriority(This,pnPriority)	\
    (This)->lpVtbl -> GetPriority(This,pnPriority)

#define IBindStatusCallback_OnLowResource(This,reserved)	\
    (This)->lpVtbl -> OnLowResource(This,reserved)

#define IBindStatusCallback_OnProgress(This,ulProgress,ulProgressMax,ulStatusCode,szStatusText)	\
    (This)->lpVtbl -> OnProgress(This,ulProgress,ulProgressMax,ulStatusCode,szStatusText)

#define IBindStatusCallback_OnStopBinding(This,hresult,szError)	\
    (This)->lpVtbl -> OnStopBinding(This,hresult,szError)

#define IBindStatusCallback_GetBindInfo(This,grfBINDF,pbindinfo)	\
    (This)->lpVtbl -> GetBindInfo(This,grfBINDF,pbindinfo)

#define IBindStatusCallback_OnDataAvailable(This,grfBSCF,dwSize,pformatetc,pstgmed)	\
    (This)->lpVtbl -> OnDataAvailable(This,grfBSCF,dwSize,pformatetc,pstgmed)

#define IBindStatusCallback_OnObjectAvailable(This,riid,punk)	\
    (This)->lpVtbl -> OnObjectAvailable(This,riid,punk)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IBindStatusCallback_OnStartBinding_Proxy( 
    IBindStatusCallback  * This,
    /* [in] */ unsigned long dwReserved,
    /* [in] */ IBinding  *pib);


void __stdcall IBindStatusCallback_OnStartBinding_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IBindStatusCallback_GetPriority_Proxy( 
    IBindStatusCallback  * This,
    /* [out] */ LONG  *pnPriority);


void __stdcall IBindStatusCallback_GetPriority_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IBindStatusCallback_OnLowResource_Proxy( 
    IBindStatusCallback  * This,
    /* [in] */ unsigned long reserved);


void __stdcall IBindStatusCallback_OnLowResource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IBindStatusCallback_OnProgress_Proxy( 
    IBindStatusCallback  * This,
    /* [in] */ unsigned long ulProgress,
    /* [in] */ unsigned long ulProgressMax,
    /* [in] */ unsigned long ulStatusCode,
    /* [in] */ const wchar_t* szStatusText);


void __stdcall IBindStatusCallback_OnProgress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IBindStatusCallback_OnStopBinding_Proxy( 
    IBindStatusCallback  * This,
    /* [in] */ HRESULT hresult,
    /* [unique][in] */ const wchar_t* szError);


void __stdcall IBindStatusCallback_OnStopBinding_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall IBindStatusCallback_RemoteGetBindInfo_Proxy( 
    IBindStatusCallback  * This,
    /* [out] */ unsigned long  *grfBINDF,
    /* [unique][out][in] */ RemBINDINFO  *pbindinfo,
    /* [unique][out][in] */ RemSTGMEDIUM  *pstgmed);


void __stdcall IBindStatusCallback_RemoteGetBindInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall IBindStatusCallback_RemoteOnDataAvailable_Proxy( 
    IBindStatusCallback  * This,
    /* [in] */ unsigned long grfBSCF,
    /* [in] */ unsigned long dwSize,
    /* [in] */ RemFORMATETC  *pformatetc,
    /* [in] */ RemSTGMEDIUM  *pstgmed);


void __stdcall IBindStatusCallback_RemoteOnDataAvailable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IBindStatusCallback_OnObjectAvailable_Proxy( 
    IBindStatusCallback  * This,
    /* [in] */ REFIID riid,
    /* [iid_is][in] */ IUnknown  *punk);


void __stdcall IBindStatusCallback_OnObjectAvailable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IBindStatusCallback_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0085
 * at Fri Aug 02 15:31:22 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif
#ifndef _LPAUTHENTICATION_DEFINED
#define _LPAUTHENTICATION_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0085_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0085_v0_0_s_ifspec;

#ifndef __IAuthenticate_INTERFACE_DEFINED__
#define __IAuthenticate_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IAuthenticate
 * at Fri Aug 02 15:31:22 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef /* [unique] */ IAuthenticate  *LPAUTHENTICATION;


EXTERN_C const IID IID_IAuthenticate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IAuthenticate : public IUnknown
    {
    public:
        virtual HRESULT __stdcall Authenticate( 
            /* [out] */ HWND  *phwnd,
            /* [out] */ wchar_t*  *pszUsername,
            /* [out] */ wchar_t*  *pszPassword) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAuthenticateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IAuthenticate  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IAuthenticate  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IAuthenticate  * This);
        
        HRESULT ( __stdcall  *Authenticate )( 
            IAuthenticate  * This,
            /* [out] */ HWND  *phwnd,
            /* [out] */ wchar_t*  *pszUsername,
            /* [out] */ wchar_t*  *pszPassword);
        
        END_INTERFACE
    } IAuthenticateVtbl;

    interface IAuthenticate
    {
        CONST_VTBL struct IAuthenticateVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAuthenticate_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAuthenticate_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAuthenticate_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAuthenticate_Authenticate(This,phwnd,pszUsername,pszPassword)	\
    (This)->lpVtbl -> Authenticate(This,phwnd,pszUsername,pszPassword)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IAuthenticate_Authenticate_Proxy( 
    IAuthenticate  * This,
    /* [out] */ HWND  *phwnd,
    /* [out] */ wchar_t*  *pszUsername,
    /* [out] */ wchar_t*  *pszPassword);


void __stdcall IAuthenticate_Authenticate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IAuthenticate_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0086
 * at Fri Aug 02 15:31:22 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif
#ifndef _LPHTTPNEGOTIATE_DEFINED
#define _LPHTTPNEGOTIATE_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0086_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0086_v0_0_s_ifspec;

#ifndef __IHttpNegotiate_INTERFACE_DEFINED__
#define __IHttpNegotiate_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IHttpNegotiate
 * at Fri Aug 02 15:31:22 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IHttpNegotiate  *LPHTTPNEGOTIATE;


EXTERN_C const IID IID_IHttpNegotiate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IHttpNegotiate : public IUnknown
    {
    public:
        virtual HRESULT __stdcall BeginningTransaction( 
            /* [in] */ const wchar_t* szURL,
            /* [unique][in] */ const wchar_t* szHeaders,
            /* [in] */ unsigned long dwReserved,
            /* [out] */ wchar_t*  *pszAdditionalHeaders) = 0;
        
        virtual HRESULT __stdcall OnResponse( 
            /* [in] */ unsigned long dwResponseCode,
            /* [unique][in] */ const wchar_t* szResponseHeaders,
            /* [unique][in] */ const wchar_t* szRequestHeaders,
            /* [out] */ wchar_t*  *pszAdditionalRequestHeaders) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHttpNegotiateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IHttpNegotiate  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IHttpNegotiate  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IHttpNegotiate  * This);
        
        HRESULT ( __stdcall  *BeginningTransaction )( 
            IHttpNegotiate  * This,
            /* [in] */ const wchar_t* szURL,
            /* [unique][in] */ const wchar_t* szHeaders,
            /* [in] */ unsigned long dwReserved,
            /* [out] */ wchar_t*  *pszAdditionalHeaders);
        
        HRESULT ( __stdcall  *OnResponse )( 
            IHttpNegotiate  * This,
            /* [in] */ unsigned long dwResponseCode,
            /* [unique][in] */ const wchar_t* szResponseHeaders,
            /* [unique][in] */ const wchar_t* szRequestHeaders,
            /* [out] */ wchar_t*  *pszAdditionalRequestHeaders);
        
        END_INTERFACE
    } IHttpNegotiateVtbl;

    interface IHttpNegotiate
    {
        CONST_VTBL struct IHttpNegotiateVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHttpNegotiate_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHttpNegotiate_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHttpNegotiate_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHttpNegotiate_BeginningTransaction(This,szURL,szHeaders,dwReserved,pszAdditionalHeaders)	\
    (This)->lpVtbl -> BeginningTransaction(This,szURL,szHeaders,dwReserved,pszAdditionalHeaders)

#define IHttpNegotiate_OnResponse(This,dwResponseCode,szResponseHeaders,szRequestHeaders,pszAdditionalRequestHeaders)	\
    (This)->lpVtbl -> OnResponse(This,dwResponseCode,szResponseHeaders,szRequestHeaders,pszAdditionalRequestHeaders)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IHttpNegotiate_BeginningTransaction_Proxy( 
    IHttpNegotiate  * This,
    /* [in] */ const wchar_t* szURL,
    /* [unique][in] */ const wchar_t* szHeaders,
    /* [in] */ unsigned long dwReserved,
    /* [out] */ wchar_t*  *pszAdditionalHeaders);


void __stdcall IHttpNegotiate_BeginningTransaction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


HRESULT __stdcall IHttpNegotiate_OnResponse_Proxy( 
    IHttpNegotiate  * This,
    /* [in] */ unsigned long dwResponseCode,
    /* [unique][in] */ const wchar_t* szResponseHeaders,
    /* [unique][in] */ const wchar_t* szRequestHeaders,
    /* [out] */ wchar_t*  *pszAdditionalRequestHeaders);


void __stdcall IHttpNegotiate_OnResponse_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IHttpNegotiate_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0087
 * at Fri Aug 02 15:31:22 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif
#ifndef _LPWINDOWFORBINDINGUI_DEFINED
#define _LPWINDOWFORBINDINGUI_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0087_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0087_v0_0_s_ifspec;

#ifndef __IWindowForBindingUI_INTERFACE_DEFINED__
#define __IWindowForBindingUI_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IWindowForBindingUI
 * at Fri Aug 02 15:31:22 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef /* [unique] */ IWindowForBindingUI  *LPWINDOWFORBINDINGUI;


EXTERN_C const IID IID_IWindowForBindingUI;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IWindowForBindingUI : public IUnknown
    {
    public:
        virtual HRESULT __stdcall GetWindow( 
            /* [in] */ REFGUID rguidReason,
            /* [out] */ HWND  *phwnd) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWindowForBindingUIVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IWindowForBindingUI  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IWindowForBindingUI  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IWindowForBindingUI  * This);
        
        HRESULT ( __stdcall  *GetWindow )( 
            IWindowForBindingUI  * This,
            /* [in] */ REFGUID rguidReason,
            /* [out] */ HWND  *phwnd);
        
        END_INTERFACE
    } IWindowForBindingUIVtbl;

    interface IWindowForBindingUI
    {
        CONST_VTBL struct IWindowForBindingUIVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWindowForBindingUI_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWindowForBindingUI_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWindowForBindingUI_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWindowForBindingUI_GetWindow(This,rguidReason,phwnd)	\
    (This)->lpVtbl -> GetWindow(This,rguidReason,phwnd)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IWindowForBindingUI_GetWindow_Proxy( 
    IWindowForBindingUI  * This,
    /* [in] */ REFGUID rguidReason,
    /* [out] */ HWND  *phwnd);


void __stdcall IWindowForBindingUI_GetWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IWindowForBindingUI_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0088
 * at Fri Aug 02 15:31:22 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif
#ifndef _LPCODEINSTALL_DEFINED
#define _LPCODEINSTALL_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0088_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0088_v0_0_s_ifspec;

#ifndef __ICodeInstall_INTERFACE_DEFINED__
#define __ICodeInstall_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: ICodeInstall
 * at Fri Aug 02 15:31:22 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef /* [unique] */ ICodeInstall  *LPCODEINSTALL;

typedef /* [public] */ 
enum __MIDL_ICodeInstall_0001
    {	CIP_DISK_FULL	= 0,
	CIP_ACCESS_DENIED	= CIP_DISK_FULL + 1,
	CIP_NEWER_VERSION_EXISTS	= CIP_ACCESS_DENIED + 1,
	CIP_OLDER_VERSION_EXISTS	= CIP_NEWER_VERSION_EXISTS + 1,
	CIP_NAME_CONFLICT	= CIP_OLDER_VERSION_EXISTS + 1,
	CIP_TRUST_VERIFICATION_COMPONENT_MISSING	= CIP_NAME_CONFLICT + 1,
	CIP_EXE_SELF_REGISTERATION_TIMEOUT	= CIP_TRUST_VERIFICATION_COMPONENT_MISSING + 1,
	CIP_UNSAFE_TO_ABORT	= CIP_EXE_SELF_REGISTERATION_TIMEOUT + 1,
	CIP_NEED_REBOOT	= CIP_UNSAFE_TO_ABORT + 1
    }	CIP_STATUS;


EXTERN_C const IID IID_ICodeInstall;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface ICodeInstall : public IWindowForBindingUI
    {
    public:
        virtual HRESULT __stdcall OnCodeInstallProblem( 
            /* [in] */ unsigned long ulStatusCode,
            /* [unique][in] */ const wchar_t* szDestination,
            /* [unique][in] */ const wchar_t* szSource,
            /* [in] */ unsigned long dwReserved) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICodeInstallVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            ICodeInstall  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            ICodeInstall  * This);
        
        unsigned long ( __stdcall  *Release )( 
            ICodeInstall  * This);
        
        HRESULT ( __stdcall  *GetWindow )( 
            ICodeInstall  * This,
            /* [in] */ REFGUID rguidReason,
            /* [out] */ HWND  *phwnd);
        
        HRESULT ( __stdcall  *OnCodeInstallProblem )( 
            ICodeInstall  * This,
            /* [in] */ unsigned long ulStatusCode,
            /* [unique][in] */ const wchar_t* szDestination,
            /* [unique][in] */ const wchar_t* szSource,
            /* [in] */ unsigned long dwReserved);
        
        END_INTERFACE
    } ICodeInstallVtbl;

    interface ICodeInstall
    {
        CONST_VTBL struct ICodeInstallVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICodeInstall_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICodeInstall_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICodeInstall_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICodeInstall_GetWindow(This,rguidReason,phwnd)	\
    (This)->lpVtbl -> GetWindow(This,rguidReason,phwnd)


#define ICodeInstall_OnCodeInstallProblem(This,ulStatusCode,szDestination,szSource,dwReserved)	\
    (This)->lpVtbl -> OnCodeInstallProblem(This,ulStatusCode,szDestination,szSource,dwReserved)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall ICodeInstall_OnCodeInstallProblem_Proxy( 
    ICodeInstall  * This,
    /* [in] */ unsigned long ulStatusCode,
    /* [unique][in] */ const wchar_t* szDestination,
    /* [unique][in] */ const wchar_t* szSource,
    /* [in] */ unsigned long dwReserved);


void __stdcall ICodeInstall_OnCodeInstallProblem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __ICodeInstall_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0089
 * at Fri Aug 02 15:31:22 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif
#ifndef _LPWININETINFO_DEFINED
#define _LPWININETINFO_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0089_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0089_v0_0_s_ifspec;

#ifndef __IWinInetInfo_INTERFACE_DEFINED__
#define __IWinInetInfo_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IWinInetInfo
 * at Fri Aug 02 15:31:22 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef /* [unique] */ IWinInetInfo  *LPWININETINFO;


EXTERN_C const IID IID_IWinInetInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IWinInetInfo : public IUnknown
    {
    public:
        virtual HRESULT __stdcall QueryOption( 
            /* [in] */ unsigned long dwOption,
            /* [out] */ void* pBuffer,
            /* [out][in] */ unsigned long  *pcbBuf) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWinInetInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IWinInetInfo  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IWinInetInfo  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IWinInetInfo  * This);
        
        HRESULT ( __stdcall  *QueryOption )( 
            IWinInetInfo  * This,
            /* [in] */ unsigned long dwOption,
            /* [out] */ void* pBuffer,
            /* [out][in] */ unsigned long  *pcbBuf);
        
        END_INTERFACE
    } IWinInetInfoVtbl;

    interface IWinInetInfo
    {
        CONST_VTBL struct IWinInetInfoVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWinInetInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWinInetInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWinInetInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWinInetInfo_QueryOption(This,dwOption,pBuffer,pcbBuf)	\
    (This)->lpVtbl -> QueryOption(This,dwOption,pBuffer,pcbBuf)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IWinInetInfo_QueryOption_Proxy( 
    IWinInetInfo  * This,
    /* [in] */ unsigned long dwOption,
    /* [out] */ void* pBuffer,
    /* [out][in] */ unsigned long  *pcbBuf);


void __stdcall IWinInetInfo_QueryOption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IWinInetInfo_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0090
 * at Fri Aug 02 15:31:22 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif
#ifndef _LPHTTPSECURITY_DEFINED
#define _LPHTTPSECURITY_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0090_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0090_v0_0_s_ifspec;

#ifndef __IHttpSecurity_INTERFACE_DEFINED__
#define __IHttpSecurity_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IHttpSecurity
 * at Fri Aug 02 15:31:22 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef /* [unique] */ IHttpSecurity  *LPHTTPSECURITY;


EXTERN_C const IID IID_IHttpSecurity;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IHttpSecurity : public IWindowForBindingUI
    {
    public:
        virtual HRESULT __stdcall OnSecurityProblem( 
            /* [in] */ unsigned long dwProblem) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHttpSecurityVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IHttpSecurity  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IHttpSecurity  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IHttpSecurity  * This);
        
        HRESULT ( __stdcall  *GetWindow )( 
            IHttpSecurity  * This,
            /* [in] */ REFGUID rguidReason,
            /* [out] */ HWND  *phwnd);
        
        HRESULT ( __stdcall  *OnSecurityProblem )( 
            IHttpSecurity  * This,
            /* [in] */ unsigned long dwProblem);
        
        END_INTERFACE
    } IHttpSecurityVtbl;

    interface IHttpSecurity
    {
        CONST_VTBL struct IHttpSecurityVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHttpSecurity_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHttpSecurity_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHttpSecurity_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHttpSecurity_GetWindow(This,rguidReason,phwnd)	\
    (This)->lpVtbl -> GetWindow(This,rguidReason,phwnd)


#define IHttpSecurity_OnSecurityProblem(This,dwProblem)	\
    (This)->lpVtbl -> OnSecurityProblem(This,dwProblem)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IHttpSecurity_OnSecurityProblem_Proxy( 
    IHttpSecurity  * This,
    /* [in] */ unsigned long dwProblem);


void __stdcall IHttpSecurity_OnSecurityProblem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IHttpSecurity_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0091
 * at Fri Aug 02 15:31:22 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif
#ifndef _LPWININETHTTPINFO_DEFINED
#define _LPWININETHTTPINFO_DEFINED


extern RPC_IF_HANDLE __MIDL__intf_0091_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0091_v0_0_s_ifspec;

#ifndef __IWinInetHttpInfo_INTERFACE_DEFINED__
#define __IWinInetHttpInfo_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IWinInetHttpInfo
 * at Fri Aug 02 15:31:22 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object][local] */ 


typedef /* [unique] */ IWinInetHttpInfo  *LPWININETHTTPINFO;


EXTERN_C const IID IID_IWinInetHttpInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IWinInetHttpInfo : public IWinInetInfo
    {
    public:
        virtual HRESULT __stdcall QueryInfo( 
            /* [in] */ unsigned long dwOption,
            /* [out] */ void* pBuffer,
            /* [out][in] */ unsigned long  *pcbBuf,
            /* [out][in] */ unsigned long  *pdwFlags,
            /* [out][in] */ unsigned long  *pdwReserved) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWinInetHttpInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IWinInetHttpInfo  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IWinInetHttpInfo  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IWinInetHttpInfo  * This);
        
        HRESULT ( __stdcall  *QueryOption )( 
            IWinInetHttpInfo  * This,
            /* [in] */ unsigned long dwOption,
            /* [out] */ void* pBuffer,
            /* [out][in] */ unsigned long  *pcbBuf);
        
        HRESULT ( __stdcall  *QueryInfo )( 
            IWinInetHttpInfo  * This,
            /* [in] */ unsigned long dwOption,
            /* [out] */ void* pBuffer,
            /* [out][in] */ unsigned long  *pcbBuf,
            /* [out][in] */ unsigned long  *pdwFlags,
            /* [out][in] */ unsigned long  *pdwReserved);
        
        END_INTERFACE
    } IWinInetHttpInfoVtbl;

    interface IWinInetHttpInfo
    {
        CONST_VTBL struct IWinInetHttpInfoVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWinInetHttpInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWinInetHttpInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWinInetHttpInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWinInetHttpInfo_QueryOption(This,dwOption,pBuffer,pcbBuf)	\
    (This)->lpVtbl -> QueryOption(This,dwOption,pBuffer,pcbBuf)


#define IWinInetHttpInfo_QueryInfo(This,dwOption,pBuffer,pcbBuf,pdwFlags,pdwReserved)	\
    (This)->lpVtbl -> QueryInfo(This,dwOption,pBuffer,pcbBuf,pdwFlags,pdwReserved)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IWinInetHttpInfo_QueryInfo_Proxy( 
    IWinInetHttpInfo  * This,
    /* [in] */ unsigned long dwOption,
    /* [out] */ void* pBuffer,
    /* [out][in] */ unsigned long  *pcbBuf,
    /* [out][in] */ unsigned long  *pdwFlags,
    /* [out][in] */ unsigned long  *pdwReserved);


void __stdcall IWinInetHttpInfo_QueryInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IWinInetHttpInfo_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0092
 * at Fri Aug 02 15:31:22 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif
#define SID_IBindHost IID_IBindHost
#define SID_SBindHost IID_IBindHost
#ifndef _LPBINDHOST_DEFINED
#define _LPBINDHOST_DEFINED
EXTERN_C const GUID SID_BindHost;


extern RPC_IF_HANDLE __MIDL__intf_0092_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0092_v0_0_s_ifspec;

#ifndef __IBindHost_INTERFACE_DEFINED__
#define __IBindHost_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IBindHost
 * at Fri Aug 02 15:31:22 1996
 * using MIDL 3.00.44
 ****************************************/
/* [unique][uuid][object] */ 


typedef /* [unique] */ IBindHost  *LPBINDHOST;


EXTERN_C const IID IID_IBindHost;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface IBindHost : public IUnknown
    {
    public:
        virtual HRESULT __stdcall CreateMoniker( 
            /* [in] */ LPOLESTR szName,
            /* [in] */ IBindCtx  *pBC,
            /* [out] */ IMoniker  * *ppmk,
            /* [in] */ unsigned long dwReserved) = 0;
        
        virtual /* [local] */ HRESULT __stdcall MonikerBindToStorage( 
            /* [in] */ IMoniker  *pMk,
            /* [in] */ IBindCtx  *pBC,
            /* [in] */ IBindStatusCallback  *pBSC,
            /* [in] */ REFIID riid,
            /* [out] */ void  * *ppvObj) = 0;
        
        virtual /* [local] */ HRESULT __stdcall MonikerBindToObject( 
            /* [in] */ IMoniker  *pMk,
            /* [in] */ IBindCtx  *pBC,
            /* [in] */ IBindStatusCallback  *pBSC,
            /* [in] */ REFIID riid,
            /* [out] */ void  * *ppvObj) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBindHostVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( __stdcall  *QueryInterface )( 
            IBindHost  * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void  * *ppvObject);
        
        unsigned long ( __stdcall  *AddRef )( 
            IBindHost  * This);
        
        unsigned long ( __stdcall  *Release )( 
            IBindHost  * This);
        
        HRESULT ( __stdcall  *CreateMoniker )( 
            IBindHost  * This,
            /* [in] */ LPOLESTR szName,
            /* [in] */ IBindCtx  *pBC,
            /* [out] */ IMoniker  * *ppmk,
            /* [in] */ unsigned long dwReserved);
        
        /* [local] */ HRESULT ( __stdcall  *MonikerBindToStorage )( 
            IBindHost  * This,
            /* [in] */ IMoniker  *pMk,
            /* [in] */ IBindCtx  *pBC,
            /* [in] */ IBindStatusCallback  *pBSC,
            /* [in] */ REFIID riid,
            /* [out] */ void  * *ppvObj);
        
        /* [local] */ HRESULT ( __stdcall  *MonikerBindToObject )( 
            IBindHost  * This,
            /* [in] */ IMoniker  *pMk,
            /* [in] */ IBindCtx  *pBC,
            /* [in] */ IBindStatusCallback  *pBSC,
            /* [in] */ REFIID riid,
            /* [out] */ void  * *ppvObj);
        
        END_INTERFACE
    } IBindHostVtbl;

    interface IBindHost
    {
        CONST_VTBL struct IBindHostVtbl  *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBindHost_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBindHost_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBindHost_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBindHost_CreateMoniker(This,szName,pBC,ppmk,dwReserved)	\
    (This)->lpVtbl -> CreateMoniker(This,szName,pBC,ppmk,dwReserved)

#define IBindHost_MonikerBindToStorage(This,pMk,pBC,pBSC,riid,ppvObj)	\
    (This)->lpVtbl -> MonikerBindToStorage(This,pMk,pBC,pBSC,riid,ppvObj)

#define IBindHost_MonikerBindToObject(This,pMk,pBC,pBSC,riid,ppvObj)	\
    (This)->lpVtbl -> MonikerBindToObject(This,pMk,pBC,pBSC,riid,ppvObj)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IBindHost_CreateMoniker_Proxy( 
    IBindHost  * This,
    /* [in] */ LPOLESTR szName,
    /* [in] */ IBindCtx  *pBC,
    /* [out] */ IMoniker  * *ppmk,
    /* [in] */ unsigned long dwReserved);


void __stdcall IBindHost_CreateMoniker_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall IBindHost_RemoteMonikerBindToStorage_Proxy( 
    IBindHost  * This,
    /* [unique][in] */ IMoniker  *pMk,
    /* [unique][in] */ IBindCtx  *pBC,
    /* [unique][in] */ IBindStatusCallback  *pBSC,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown  * *ppvObj);


void __stdcall IBindHost_RemoteMonikerBindToStorage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);


/* [call_as] */ HRESULT __stdcall IBindHost_RemoteMonikerBindToObject_Proxy( 
    IBindHost  * This,
    /* [unique][in] */ IMoniker  *pMk,
    /* [unique][in] */ IBindCtx  *pBC,
    /* [unique][in] */ IBindStatusCallback  *pBSC,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown  * *ppvObj);


void __stdcall IBindHost_RemoteMonikerBindToObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    unsigned long *_pdwStubPhase);



#endif 	/* __IBindHost_INTERFACE_DEFINED__ */


/****************************************
 * Generated header for interface: __MIDL__intf_0093
 * at Fri Aug 02 15:31:22 1996
 * using MIDL 3.00.44
 ****************************************/
/* [local] */ 


#endif
                                                                                                           
// These are for backwards compatibility with previous URLMON versions
// Flags for the UrlDownloadToCacheFile                                                                    
#define URLOSTRM_USECACHEDCOPY_ONLY             0x1      // Only get from cache                            
#define URLOSTRM_USECACHEDCOPY                  0x2      // Get from cache if available else download      
#define URLOSTRM_GETNEWESTVERSION               0x3      // Get new version only. But put it in cache too  
                                                                                                           
                                                                                                           
struct IBindStatusCallback;                                                                                
STDAPI HlinkSimpleNavigateToString(                                                                        
    /* [in] */ const wchar_t* szTarget,         // required - target document - null if local jump w/in doc       
    /* [in] */ const wchar_t* szLocation,       // optional, for navigation into middle of a doc                  
    /* [in] */ const wchar_t* szTargetFrameName,// optional, for targeting frame-sets                             
    /* [in] */ IUnknown *pUnk,           // required - we'll search this for other necessary interfaces    
    /* [in] */ IBindCtx *pbc,            // optional. caller may register an IBSC in this                  
    /* [in] */ IBindStatusCallback *,                                                                      
    /* [in] */ unsigned long grfHLNF,            // flags                                                          
    /* [in] */ unsigned long dwReserved          // for future use, must be NULL                                   
);                                                                                                         
                                                                                                           
STDAPI HlinkSimpleNavigateToMoniker(                                                                       
    /* [in] */ IMoniker *pmkTarget,      // required - target document - (may be null                      
    /* [in] */ const wchar_t* szLocation,       // optional, for navigation into middle of a doc                  
    /* [in] */ const wchar_t* szTargetFrameName,// optional, for targeting frame-sets                             
    /* [in] */ IUnknown *pUnk,           // required - we'll search this for other necessary interfaces    
    /* [in] */ IBindCtx *pbc,            // optional. caller may register an IBSC in this                  
    /* [in] */ IBindStatusCallback *,                                                                      
    /* [in] */ unsigned long grfHLNF,            // flags                                                          
    /* [in] */ unsigned long dwReserved          // for future use, must be NULL                                   
);                                                                                                         
                                                                                                           
STDAPI URLOpenStreamA(LPUNKNOWN,const char*,unsigned long,LPBINDSTATUSCALLBACK);                                        
STDAPI URLOpenStreamW(LPUNKNOWN,const wchar_t*,unsigned long,LPBINDSTATUSCALLBACK);                                       
STDAPI URLOpenPullStreamA(LPUNKNOWN,const char*,unsigned long,LPBINDSTATUSCALLBACK);                                    
STDAPI URLOpenPullStreamW(LPUNKNOWN,const wchar_t*,unsigned long,LPBINDSTATUSCALLBACK);                                   
STDAPI URLDownloadToFileA(LPUNKNOWN,const char*,const char*,unsigned long,LPBINDSTATUSCALLBACK);                             
STDAPI URLDownloadToFileW(LPUNKNOWN,const wchar_t*,const wchar_t*,unsigned long,LPBINDSTATUSCALLBACK);                           
STDAPI URLDownloadToCacheFileA(LPUNKNOWN,const char*,LPTSTR,unsigned long,unsigned long,LPBINDSTATUSCALLBACK);                  
STDAPI URLDownloadToCacheFileW(LPUNKNOWN,const wchar_t*,wchar_t*,unsigned long,unsigned long,LPBINDSTATUSCALLBACK);                 
STDAPI URLOpenBlockingStreamA(LPUNKNOWN,const char*,LPSTREAM*,unsigned long,LPBINDSTATUSCALLBACK);                      
STDAPI URLOpenBlockingStreamW(LPUNKNOWN,const wchar_t*,LPSTREAM*,unsigned long,LPBINDSTATUSCALLBACK);                     
                                                                                                           
#ifdef UNICODE                                                                                             
#define URLOpenStream            URLOpenStreamW                                                            
#define URLOpenPullStream        URLOpenPullStreamW                                                        
#define URLDownloadToFile        URLDownloadToFileW                                                        
#define URLDownloadToCacheFile   URLDownloadToCacheFileW                                                   
#define URLOpenBlockingStream    URLOpenBlockingStreamW                                                    
#else                                                                                                      
#define URLOpenStream            URLOpenStreamA                                                            
#define URLOpenPullStream        URLOpenPullStreamA                                                        
#define URLDownloadToFile        URLDownloadToFileA                                                        
#define URLDownloadToCacheFile   URLDownloadToCacheFileA                                                   
#define URLOpenBlockingStream    URLOpenBlockingStreamA                                                    
#endif // !UNICODE                                                                                         
                                                                                                           
                                                                                                           
STDAPI HlinkGoBack(IUnknown *pUnk);                                                                        
STDAPI HlinkGoForward(IUnknown *pUnk);                                                                     
STDAPI HlinkNavigateString(IUnknown *pUnk, const wchar_t* szTarget);                                              
STDAPI HlinkNavigateMoniker(IUnknown *pUnk, IMoniker *pmkTarget);                                          
                                                                                                           


extern RPC_IF_HANDLE __MIDL__intf_0093_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL__intf_0093_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* [local] */ HRESULT __stdcall IBinding_GetBindResult_Proxy( 
    IBinding  * This,
    /* [out] */ CLSID  *pclsidProtocol,
    /* [out] */ unsigned long  *pdwResult,
    /* [out] */ LPOLESTR  *pszResult,
    /* [out][in] */ unsigned long  *pdwReserved);


/* [call_as] */ HRESULT __stdcall IBinding_GetBindResult_Stub( 
    IBinding  * This,
    /* [out] */ CLSID  *pclsidProtocol,
    /* [out] */ unsigned long  *pdwResult,
    /* [out] */ LPOLESTR  *pszResult,
    /* [in] */ unsigned long dwReserved);

/* [local] */ HRESULT __stdcall IBindStatusCallback_GetBindInfo_Proxy( 
    IBindStatusCallback  * This,
    /* [out] */ unsigned long  *grfBINDF,
    /* [unique][out][in] */ BINDINFO  *pbindinfo);


/* [call_as] */ HRESULT __stdcall IBindStatusCallback_GetBindInfo_Stub( 
    IBindStatusCallback  * This,
    /* [out] */ unsigned long  *grfBINDF,
    /* [unique][out][in] */ RemBINDINFO  *pbindinfo,
    /* [unique][out][in] */ RemSTGMEDIUM  *pstgmed);

/* [local] */ HRESULT __stdcall IBindStatusCallback_OnDataAvailable_Proxy( 
    IBindStatusCallback  * This,
    /* [in] */ unsigned long grfBSCF,
    /* [in] */ unsigned long dwSize,
    /* [in] */ FORMATETC  *pformatetc,
    /* [in] */ STGMEDIUM  *pstgmed);


/* [call_as] */ HRESULT __stdcall IBindStatusCallback_OnDataAvailable_Stub( 
    IBindStatusCallback  * This,
    /* [in] */ unsigned long grfBSCF,
    /* [in] */ unsigned long dwSize,
    /* [in] */ RemFORMATETC  *pformatetc,
    /* [in] */ RemSTGMEDIUM  *pstgmed);

/* [local] */ HRESULT __stdcall IBindHost_MonikerBindToStorage_Proxy( 
    IBindHost  * This,
    /* [in] */ IMoniker  *pMk,
    /* [in] */ IBindCtx  *pBC,
    /* [in] */ IBindStatusCallback  *pBSC,
    /* [in] */ REFIID riid,
    /* [out] */ void  * *ppvObj);


/* [call_as] */ HRESULT __stdcall IBindHost_MonikerBindToStorage_Stub( 
    IBindHost  * This,
    /* [unique][in] */ IMoniker  *pMk,
    /* [unique][in] */ IBindCtx  *pBC,
    /* [unique][in] */ IBindStatusCallback  *pBSC,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown  * *ppvObj);

/* [local] */ HRESULT __stdcall IBindHost_MonikerBindToObject_Proxy( 
    IBindHost  * This,
    /* [in] */ IMoniker  *pMk,
    /* [in] */ IBindCtx  *pBC,
    /* [in] */ IBindStatusCallback  *pBSC,
    /* [in] */ REFIID riid,
    /* [out] */ void  * *ppvObj);


/* [call_as] */ HRESULT __stdcall IBindHost_MonikerBindToObject_Stub( 
    IBindHost  * This,
    /* [unique][in] */ IMoniker  *pMk,
    /* [unique][in] */ IBindCtx  *pBC,
    /* [unique][in] */ IBindStatusCallback  *pBSC,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ IUnknown  * *ppvObj);



/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
#pragma once 
