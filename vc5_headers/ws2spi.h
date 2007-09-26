#pragma once
/* WS2SPI.H -- definitions to be used with the WinSock service provider.
 *
 * This header file corresponds to version 2.2.x of the WinSock SPI
 * specification.
 *
 * This file includes parts which are Copyright (c) 1982-1986 Regents
 * of the University of California.  All rights reserved.  The
 * Berkeley Software License Agreement specifies the terms and
 * conditions for redistribution.
 */

#ifndef _WINSOCK2SPI_
#define _WINSOCK2SPI_

/*
 * Ensure structures are packed consistently.
 */

#include <pshpack4.h>

/*
 * Pull in WINSOCK2.H if necessary
 */

#ifndef _WINSOCK2API_
#include <winsock2.h>
#endif /* _WINSOCK2API_ */

#define WSPDESCRIPTION_LEN 255

typedef struct WSPData {
    WORD         wVersion;
    WORD         wHighVersion;
    wchar_t        szDescription[WSPDESCRIPTION_LEN+1];
} WSPDATA,  * LPWSPDATA;

typedef struct _WSATHREADID {
    HANDLE ThreadHandle;
    unsigned long Reserved;
} WSATHREADID,  * LPWSATHREADID;

/*
 * SPI function linkage.
 */

#define WSPAPI WSAAPI


#ifdef __cplusplus
extern "C" {
#endif

/*
 * Pointer to a blocking callback. A pointer to a blocking callback is
 * returned from the WPUQueryBlockingCallback() upcall. Note that this
 * function's signature is not identical to an application's blocking
 * hook function.
 */

typedef
BOOL
(__stdcall  * LPBLOCKINGCALLBACK)(
    unsigned long dwContext
    );

/*
 * Pointer to a user APC function. This is used as a parameter to the
 * WPUQueueUserApc() upcall. Note that this function's signature is not
 * identical to an application's completion routine.
 */

typedef
void
(__stdcall  * LPWSAUSERAPC)(
    unsigned long dwContext
    );

/*
 * Pointers to the individual entries in a service provider's proc table.
 */

typedef
SOCKET
(__stdcall * LPWSPACCEPT)(
    SOCKET s,
    struct sockaddr  * addr,
    int* addrlen,
    LPCONDITIONPROC lpfnCondition,
    unsigned long dwCallbackData,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWSPADDRESSTOSTRING)(
    LPSOCKADDR lpsaAddress,
    unsigned long dwAddressLength,
    LPWSAPROTOCOL_INFOW lpProtocolInfo,
    wchar_t* lpszAddressString,
    unsigned long* lpdwAddressStringLength,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWSPASYNCSELECT)(
    SOCKET s,
    HWND hWnd,
    unsigned int wMsg,
    long lEvent,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWSPBIND)(
    SOCKET s,
    const struct sockaddr  * name,
    int namelen,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWSPCANCELBLOCKINGCALL)(
    int* lpErrno
    );

typedef
int
(__stdcall * LPWSPCLEANUP)(
    int* lpErrno
    );

typedef
int
(__stdcall * LPWSPCLOSESOCKET)(
    SOCKET s,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWSPCONNECT)(
    SOCKET s,
    const struct sockaddr  * name,
    int namelen,
    LPWSABUF lpCallerData,
    LPWSABUF lpCalleeData,
    LPQOS lpSQOS,
    LPQOS lpGQOS,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWSPDUPLICATESOCKET)(
    SOCKET s,
    unsigned long dwProcessId,
    LPWSAPROTOCOL_INFOW lpProtocolInfo,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWSPENUMNETWORKEVENTS)(
    SOCKET s,
    WSAEVENT hEventObject,
    LPWSANETWORKEVENTS lpNetworkEvents,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWSPEVENTSELECT)(
    SOCKET s,
    WSAEVENT hEventObject,
    long lNetworkEvents,
    int* lpErrno
    );

typedef
BOOL
(__stdcall * LPWSPGETOVERLAPPEDRESULT)(
    SOCKET s,
    LPWSAOVERLAPPED lpOverlapped,
    unsigned long* lpcbTransfer,
    BOOL fWait,
    unsigned long* lpdwFlags,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWSPGETPEERNAME)(
    SOCKET s,
    struct sockaddr  * name,
    int* namelen,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWSPGETSOCKNAME)(
    SOCKET s,
    struct sockaddr  * name,
    int* namelen,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWSPGETSOCKOPT)(
    SOCKET s,
    int level,
    int optname,
    char  * optval,
    int* optlen,
    int* lpErrno
    );

typedef
BOOL
(__stdcall * LPWSPGETQOSBYNAME)(
    SOCKET s,
    LPWSABUF lpQOSName,
    LPQOS lpQOS,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWSPIOCTL)(
    SOCKET s,
    unsigned long dwIoControlCode,
    void* lpvInBuffer,
    unsigned long cbInBuffer,
    void* lpvOutBuffer,
    unsigned long cbOutBuffer,
    unsigned long* lpcbBytesReturned,
    LPWSAOVERLAPPED lpOverlapped,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine,
    LPWSATHREADID lpThreadId,
    int* lpErrno
    );

typedef
SOCKET
(__stdcall * LPWSPJOINLEAF)(
    SOCKET s,
    const struct sockaddr  * name,
    int namelen,
    LPWSABUF lpCallerData,
    LPWSABUF lpCalleeData,
    LPQOS lpSQOS,
    LPQOS lpGQOS,
    unsigned long dwFlags,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWSPLISTEN)(
    SOCKET s,
    int backlog,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWSPRECV)(
    SOCKET s,
    LPWSABUF lpBuffers,
    unsigned long dwBufferCount,
    unsigned long* lpNumberOfBytesRecvd,
    unsigned long* lpFlags,
    LPWSAOVERLAPPED lpOverlapped,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine,
    LPWSATHREADID lpThreadId,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWSPRECVDISCONNECT)(
    SOCKET s,
    LPWSABUF lpInboundDisconnectData,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWSPRECVFROM)(
    SOCKET s,
    LPWSABUF lpBuffers,
    unsigned long dwBufferCount,
    unsigned long* lpNumberOfBytesRecvd,
    unsigned long* lpFlags,
    struct sockaddr  * lpFrom,
    int* lpFromlen,
    LPWSAOVERLAPPED lpOverlapped,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine,
    LPWSATHREADID lpThreadId,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWSPSELECT)(
    int nfds,
    fd_set  * readfds,
    fd_set  * writefds,
    fd_set  * exceptfds,
    const struct timeval  * timeout,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWSPSEND)(
    SOCKET s,
    LPWSABUF lpBuffers,
    unsigned long dwBufferCount,
    unsigned long* lpNumberOfBytesSent,
    unsigned long dwFlags,
    LPWSAOVERLAPPED lpOverlapped,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine,
    LPWSATHREADID lpThreadId,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWSPSENDDISCONNECT)(
    SOCKET s,
    LPWSABUF lpOutboundDisconnectData,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWSPSENDTO)(
    SOCKET s,
    LPWSABUF lpBuffers,
    unsigned long dwBufferCount,
    unsigned long* lpNumberOfBytesSent,
    unsigned long dwFlags,
    const struct sockaddr  * lpTo,
    int iTolen,
    LPWSAOVERLAPPED lpOverlapped,
    LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine,
    LPWSATHREADID lpThreadId,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWSPSETSOCKOPT)(
    SOCKET s,
    int level,
    int optname,
    const char  * optval,
    int optlen,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWSPSHUTDOWN)(
    SOCKET s,
    int how,
    int* lpErrno
    );

typedef
SOCKET
(__stdcall * LPWSPSOCKET)(
    int af,
    int type,
    int protocol,
    LPWSAPROTOCOL_INFOW lpProtocolInfo,
    GROUP g,
    unsigned long dwFlags,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWSPSTRINGTOADDRESS)(
    wchar_t* AddressString,
    int AddressFamily,
    LPWSAPROTOCOL_INFOW lpProtocolInfo,
    LPSOCKADDR lpAddress,
    int* lpAddressLength,
    int* lpErrno
    );

/*
 * A service provider proc table. This structure is returned by value
 * from the service provider's WSPStartup() entrypoint.
 */

typedef struct _WSPPROC_TABLE {

    LPWSPACCEPT              lpWSPAccept;
    LPWSPADDRESSTOSTRING     lpWSPAddressToString;
    LPWSPASYNCSELECT         lpWSPAsyncSelect;
    LPWSPBIND                lpWSPBind;
    LPWSPCANCELBLOCKINGCALL  lpWSPCancelBlockingCall;
    LPWSPCLEANUP             lpWSPCleanup;
    LPWSPCLOSESOCKET         lpWSPCloseSocket;
    LPWSPCONNECT             lpWSPConnect;
    LPWSPDUPLICATESOCKET     lpWSPDuplicateSocket;
    LPWSPENUMNETWORKEVENTS   lpWSPEnumNetworkEvents;
    LPWSPEVENTSELECT         lpWSPEventSelect;
    LPWSPGETOVERLAPPEDRESULT lpWSPGetOverlappedResult;
    LPWSPGETPEERNAME         lpWSPGetPeerName;
    LPWSPGETSOCKNAME         lpWSPGetSockName;
    LPWSPGETSOCKOPT          lpWSPGetSockOpt;
    LPWSPGETQOSBYNAME        lpWSPGetQOSByName;
    LPWSPIOCTL               lpWSPIoctl;
    LPWSPJOINLEAF            lpWSPJoinLeaf;
    LPWSPLISTEN              lpWSPListen;
    LPWSPRECV                lpWSPRecv;
    LPWSPRECVDISCONNECT      lpWSPRecvDisconnect;
    LPWSPRECVFROM            lpWSPRecvFrom;
    LPWSPSELECT              lpWSPSelect;
    LPWSPSEND                lpWSPSend;
    LPWSPSENDDISCONNECT      lpWSPSendDisconnect;
    LPWSPSENDTO              lpWSPSendTo;
    LPWSPSETSOCKOPT          lpWSPSetSockOpt;
    LPWSPSHUTDOWN            lpWSPShutdown;
    LPWSPSOCKET              lpWSPSocket;
    LPWSPSTRINGTOADDRESS     lpWSPStringToAddress;

} WSPPROC_TABLE,  * LPWSPPROC_TABLE;

/*
 * Pointers to the individual entries in the upcall table.
 */

typedef
BOOL
(__stdcall * LPWPUCLOSEEVENT)(
    WSAEVENT hEvent,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWPUCLOSESOCKETHANDLE)(
    SOCKET s,
    int* lpErrno
    );

typedef
WSAEVENT
(__stdcall * LPWPUCREATEEVENT)(
    int* lpErrno
    );

typedef
SOCKET
(__stdcall * LPWPUCREATESOCKETHANDLE)(
    unsigned long dwCatalogEntryId,
    unsigned long dwContext,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWPUFDISSET)(
    SOCKET s,
    fd_set  * set
    );

typedef
int
(__stdcall * LPWPUGETPROVIDERPATH)(
    GUID* lpProviderId,
    wchar_t  * lpszProviderDllPath,
    int* lpProviderDllPathLen,
    int* lpErrno
    );

typedef
SOCKET
(__stdcall * LPWPUMODIFYIFSHANDLE)(
    unsigned long dwCatalogEntryId,
    SOCKET ProposedHandle,
    int* lpErrno
    );

typedef
BOOL
(__stdcall * LPWPUPOSTMESSAGE)(
    HWND hWnd,
    UINT Msg,
    WPARAM wParam,
    LPARAM lParam
    );

typedef
int
(__stdcall * LPWPUQUERYBLOCKINGCALLBACK)(
    unsigned long dwCatalogEntryId,
    LPBLOCKINGCALLBACK  * lplpfnCallback,
    unsigned long* lpdwContext,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWPUQUERYSOCKETHANDLECONTEXT)(
    SOCKET s,
    unsigned long* lpContext,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWPUQUEUEAPC)(
    LPWSATHREADID lpThreadId,
    LPWSAUSERAPC lpfnUserApc,
    unsigned long dwContext,
    int* lpErrno
    );

typedef
BOOL
(__stdcall * LPWPURESETEVENT)(
    WSAEVENT hEvent,
    int* lpErrno
    );

typedef
BOOL
(__stdcall * LPWPUSETEVENT)(
    WSAEVENT hEvent,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWPUOPENCURRENTTHREAD)(
    LPWSATHREADID lpThreadId,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWPUCLOSETHREAD)(
    LPWSATHREADID lpThreadId,
    int* lpErrno
    );

/*
 * The upcall table. This structure is passed by value to the service
 * provider's WSPStartup() entrypoint.
 */

typedef struct _WSPUPCALLTABLE {

    LPWPUCLOSEEVENT               lpWPUCloseEvent;
    LPWPUCLOSESOCKETHANDLE        lpWPUCloseSocketHandle;
    LPWPUCREATEEVENT              lpWPUCreateEvent;
    LPWPUCREATESOCKETHANDLE       lpWPUCreateSocketHandle;
    LPWPUFDISSET                  lpWPUFDIsSet;
    LPWPUGETPROVIDERPATH          lpWPUGetProviderPath;
    LPWPUMODIFYIFSHANDLE          lpWPUModifyIFSHandle;
    LPWPUPOSTMESSAGE              lpWPUPostMessage;
    LPWPUQUERYBLOCKINGCALLBACK    lpWPUQueryBlockingCallback;
    LPWPUQUERYSOCKETHANDLECONTEXT lpWPUQuerySocketHandleContext;
    LPWPUQUEUEAPC                 lpWPUQueueApc;
    LPWPURESETEVENT               lpWPUResetEvent;
    LPWPUSETEVENT                 lpWPUSetEvent;
    LPWPUOPENCURRENTTHREAD        lpWPUOpenCurrentThread;
    LPWPUCLOSETHREAD              lpWPUCloseThread;

} WSPUPCALLTABLE,  * LPWSPUPCALLTABLE;

/*
 *  WinSock 2 SPI socket function prototypes
 */

int
__stdcall
WSPStartup(
    WORD wVersionRequested,
    LPWSPDATA lpWSPData,
    LPWSAPROTOCOL_INFOW lpProtocolInfo,
    WSPUPCALLTABLE UpcallTable,
    LPWSPPROC_TABLE lpProcTable
    );

typedef
int
(__stdcall * LPWSPSTARTUP)(
    WORD wVersionRequested,
    LPWSPDATA lpWSPData,
    LPWSAPROTOCOL_INFOW lpProtocolInfo,
    WSPUPCALLTABLE UpcallTable,
    LPWSPPROC_TABLE lpProcTable
    );

/*
 * Installation and configuration entrypoints.
 */

int
__stdcall
WSCEnumProtocols(
    int* lpiProtocols,
    LPWSAPROTOCOL_INFOW lpProtocolBuffer,
    unsigned long* lpdwBufferLength,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWSCENUMPROTOCOLS)(
    int* lpiProtocols,
    LPWSAPROTOCOL_INFOW lpProtocolBuffer,
    unsigned long* lpdwBufferLength,
    int* lpErrno
    );

int
__stdcall
WSCDeinstallProvider(
    GUID* lpProviderId,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWSCDEINSTALLPROVIDER)(
    GUID* lpProviderId,
    int* lpErrno
    );

int
__stdcall
WSCInstallProvider(
    GUID* lpProviderId,
    const wchar_t  * lpszProviderDllPath,
    const LPWSAPROTOCOL_INFOW lpProtocolInfoList,
    unsigned long dwNumberOfEntries,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWSCINSTALLPROVIDER)(
    GUID* lpProviderId,
    const wchar_t  * lpszProviderDllPath,
    const LPWSAPROTOCOL_INFOW lpProtocolInfoList,
    unsigned long dwNumberOfEntries,
    int* lpErrno
    );

int
__stdcall
WSCGetProviderPath(
    GUID* lpProviderId,
    wchar_t  * lpszProviderDllPath,
    int* lpProviderDllPathLen,
    int* lpErrno
    );

typedef
int
(__stdcall * LPWSCGETPROVIDERPATH)(
    GUID* lpProviderId,
    wchar_t  * lpszProviderDllPath,
    int* lpProviderDllPathLen,
    int* lpErrno
    );

/*
 *  The following upcall function prototypes are only used by WinSock 2 DLL and
 *  should not be used by any service providers.
 */

BOOL
__stdcall
WPUCloseEvent(
    WSAEVENT hEvent,
    int* lpErrno
    );

int
__stdcall
WPUCloseSocketHandle(
    SOCKET s,
    int* lpErrno
    );

WSAEVENT
__stdcall
WPUCreateEvent(
    int* lpErrno
    );

SOCKET
__stdcall
WPUCreateSocketHandle(
    unsigned long dwCatalogEntryId,
    unsigned long dwContext,
    int* lpErrno
    );

int
__stdcall
WPUFDIsSet(
    SOCKET s,
    fd_set  * set
    );

int
__stdcall
WPUGetProviderPath(
    GUID* lpProviderId,
    wchar_t  * lpszProviderDllPath,
    int* lpProviderDllPathLen,
    int* lpErrno
    );

SOCKET
__stdcall
WPUModifyIFSHandle(
    unsigned long dwCatalogEntryId,
    SOCKET ProposedHandle,
    int* lpErrno
    );

BOOL
__stdcall
WPUPostMessage(
    HWND hWnd,
    UINT Msg,
    WPARAM wParam,
    LPARAM lParam
    );

int
__stdcall
WPUQueryBlockingCallback(
    unsigned long dwCatalogEntryId,
    LPBLOCKINGCALLBACK  * lplpfnCallback,
    unsigned long* lpdwContext,
    int* lpErrno
    );

int
__stdcall
WPUQuerySocketHandleContext(
    SOCKET s,
    unsigned long* lpContext,
    int* lpErrno
    );

int
__stdcall
WPUQueueApc(
    LPWSATHREADID lpThreadId,
    LPWSAUSERAPC lpfnUserApc,
    unsigned long dwContext,
    int* lpErrno
    );

BOOL
__stdcall
WPUResetEvent(
    WSAEVENT hEvent,
    int* lpErrno
    );

BOOL
__stdcall
WPUSetEvent(
    WSAEVENT hEvent,
    int* lpErrno
    );

/*
 * Installing and uninstalling name space providers.
 */

int
__stdcall
WSCInstallNameSpace (
    wchar_t* lpszIdentifier,
    wchar_t* lpszPathName,
    unsigned long dwNameSpace,
    unsigned long dwVersion,
    GUID* lpProviderId
    );

typedef
int
(__stdcall * LPWSCINSTALLNAMESPACE)(
    wchar_t* lpszIdentifier,
    wchar_t* lpszPathName,
    unsigned long dwNameSpace,
    unsigned long dwVersion,
    GUID* lpProviderId
    );

int
__stdcall
WSCUnInstallNameSpace (
    GUID* lpProviderId
    );

typedef
int
(__stdcall * LPWSCUNINSTALLNAMESPACE)(
    GUID* lpProviderId
    );

int
__stdcall
WSCEnableNSProvider (
    GUID* lpProviderId,
    BOOL fEnable
    );

typedef
int
(__stdcall * LPWSCENABLENSPROVIDER)(
    GUID* lpProviderId,
    BOOL fEnable
    );

/*
 * Pointers to the individual entries in the namespace proc table.
 */

typedef
int
(__stdcall * LPNSPCLEANUP)(
    GUID* lpProviderId
    );

typedef
int
(__stdcall * LPNSPLOOKUPSERVICEBEGIN)(
    GUID* lpProviderId,
    LPWSAQUERYSETW lpqsRestrictions,
    LPWSASERVICECLASSINFOW lpServiceClassInfo,
    unsigned long dwControlFlags,
    HANDLE* lphLookup
    );

typedef
int
(__stdcall * LPNSPLOOKUPSERVICENEXT)(
    HANDLE hLookup,
    unsigned long dwControlFlags,
    unsigned long* lpdwBufferLength,
    LPWSAQUERYSETW lpqsResults
    );

typedef
int
(__stdcall * LPNSPLOOKUPSERVICEEND)(
    HANDLE hLookup
    );

typedef
int
(__stdcall * LPNSPSETSERVICE)(
    GUID* lpProviderId,
    LPWSASERVICECLASSINFOW lpServiceClassInfo,
    LPWSAQUERYSETW lpqsRegInfo,
    WSAESETSERVICEOP essOperation,
    unsigned long dwControlFlags
    );

typedef
int
(__stdcall * LPNSPINSTALLSERVICECLASS)(
    GUID* lpProviderId,
    LPWSASERVICECLASSINFOW lpServiceClassInfo
    );

typedef
int
(__stdcall * LPNSPREMOVESERVICECLASS)(
    GUID* lpProviderId,
    GUID* lpServiceClassId
    );

typedef
int
(__stdcall * LPNSPGETSERVICECLASSINFO)(
    GUID* lpProviderId,
    unsigned long* lpdwBufSize,
    LPWSASERVICECLASSINFOW lpServiceClassInfo
    );

/*
 * The name space service provider procedure table.
 */

typedef struct _NSP_ROUTINE {

    /* Structure version information: */
    unsigned long           cbSize;
    unsigned long           dwMajorVersion;
    unsigned long           dwMinorVersion;

    /* Procedure-pointer table: */

    LPNSPCLEANUP             NSPCleanup;
    LPNSPLOOKUPSERVICEBEGIN  NSPLookupServiceBegin;
    LPNSPLOOKUPSERVICENEXT   NSPLookupServiceNext;
    LPNSPLOOKUPSERVICEEND    NSPLookupServiceEnd;
    LPNSPSETSERVICE          NSPSetService;
    LPNSPINSTALLSERVICECLASS NSPInstallServiceClass;
    LPNSPREMOVESERVICECLASS  NSPRemoveServiceClass;
    LPNSPGETSERVICECLASSINFO NSPGetServiceClassInfo;

} NSP_ROUTINE,  * LPNSP_ROUTINE;

/*
 * Startup procedures.
 */

int
__stdcall
NSPStartup(
    GUID* lpProviderId,
    LPNSP_ROUTINE lpnspRoutines
    );

typedef
int
(__stdcall * LPNSPSTARTUP)(
    GUID* lpProviderId,
    LPNSP_ROUTINE lpnspRoutines
    );


#ifdef __cplusplus
}
#endif


#include <poppack.h>


#endif  /* _WINSOCK2SPI_ */

#pragma once 
