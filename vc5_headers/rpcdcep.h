/*++

Copyright (c) 1991-1996 Microsoft Corporation

Module Name:

    rpcdcep.h

Abstract:

    This module contains the private RPC runtime APIs for use by the
    stubs and by support libraries.  Applications must not call these
    routines.

--*/

#ifndef __RPCDCEP_H__
#define __RPCDCEP_H__

// Set the packing level for RPC structures for Dos and Windows.

#if defined(__RPC_DOS__) || defined(__RPC_WIN16__)
#pragma pack(2)
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _RPC_VERSION {
    unsigned short MajorVersion;
    unsigned short MinorVersion;
} RPC_VERSION;

typedef struct _RPC_SYNTAX_IDENTIFIER {
    GUID SyntaxGUID;
    RPC_VERSION SyntaxVersion;
} RPC_SYNTAX_IDENTIFIER,  * PRPC_SYNTAX_IDENTIFIER;

typedef struct _RPC_MESSAGE
{
    RPC_BINDING_HANDLE Handle;
    unsigned long DataRepresentation;
    void  * Buffer;
    unsigned int BufferLength;
    unsigned int ProcNum;
    PRPC_SYNTAX_IDENTIFIER TransferSyntax;
    void  * RpcInterfaceInformation;
    void  * ReservedForRuntime;
    RPC_MGR_EPV  * ManagerEpv;
    void  * ImportContext;
    unsigned long RpcFlags;
} RPC_MESSAGE,  * PRPC_MESSAGE;


typedef RPC_STATUS __stdcall RPC_FORWARD_FUNCTION(
                       IN UUID              * InterfaceId,
                       IN RPC_VERSION       * InterfaceVersion,
                       IN UUID              * ObjectId,
                       IN unsigned char          * Rpcpro,
                       IN void  *  * ppDestEndpoint);

/*
 * Types of function calls for datagram rpc
 */

#define RPC_NCA_FLAGS_DEFAULT       0x00000000  /* 0b000...000 */
#define RPC_NCA_FLAGS_IDEMPOTENT    0x00000001  /* 0b000...001 */
#define RPC_NCA_FLAGS_BROADCAST     0x00000002  /* 0b000...010 */
#define RPC_NCA_FLAGS_MAYBE         0x00000004  /* 0b000...100 */

#define RPC_BUFFER_COMPLETE          0x00001000 /* used by pipes */
#define RPC_BUFFER_PARTIAL              0x00002000 /* used by pipes */
#define RPC_BUFFER_EXTRA                 0x00004000 /* used by pipes */

#define RPCFLG_NON_NDR                    0x80000000UL
#define RPCFLG_ASYNCHRONOUS         0x40000000UL
#define RPCFLG_INPUT_SYNCHRONOUS    0x20000000UL
#define RPCFLG_LOCAL_CALL                0x10000000UL

#if defined(__RPC_DOS__) || defined(__RPC_WIN16__)
#define RPC_FLAGS_VALID_BIT 0x8000
#endif

#if defined(__RPC_WIN32__) || defined(__RPC_MAC__)
#define RPC_FLAGS_VALID_BIT 0x00008000
#endif

typedef
void
(__stdcall  * RPC_DISPATCH_FUNCTION) (
    IN OUT PRPC_MESSAGE Message
    );

typedef struct {
    unsigned int DispatchTableCount;
    RPC_DISPATCH_FUNCTION  * DispatchTable;
    int Reserved;
} RPC_DISPATCH_TABLE,  * PRPC_DISPATCH_TABLE;

typedef struct _RPC_PROTSEQ_ENDPOINT
{
    unsigned char  * RpcProtocolSequence;
    unsigned char  * Endpoint;
} RPC_PROTSEQ_ENDPOINT,  * PRPC_PROTSEQ_ENDPOINT;

/*
Both of these types MUST start with the InterfaceId and TransferSyntax.
Look at RpcIfInqId and I_RpcIfInqTransferSyntaxes to see why.
*/
#define NT351_INTERFACE_SIZE 0x40
#define RPC_INTERFACE_HAS_PIPES           0x0001

typedef struct _RPC_SERVER_INTERFACE
{
    unsigned int Length;
    RPC_SYNTAX_IDENTIFIER InterfaceId;
    RPC_SYNTAX_IDENTIFIER TransferSyntax;
    PRPC_DISPATCH_TABLE DispatchTable;
    unsigned int RpcProtseqEndpointCount;
    PRPC_PROTSEQ_ENDPOINT RpcProtseqEndpoint;
    RPC_MGR_EPV  *DefaultManagerEpv;
    void const  *InterpreterInfo;
    unsigned int Flags ;
} RPC_SERVER_INTERFACE,  * PRPC_SERVER_INTERFACE;

typedef struct _RPC_CLIENT_INTERFACE
{
    unsigned int Length;
    RPC_SYNTAX_IDENTIFIER InterfaceId;
    RPC_SYNTAX_IDENTIFIER TransferSyntax;
    PRPC_DISPATCH_TABLE DispatchTable;
    unsigned int RpcProtseqEndpointCount;
    PRPC_PROTSEQ_ENDPOINT RpcProtseqEndpoint;
    unsigned long Reserved;
    void const  * InterpreterInfo;
    unsigned int Flags ;
} RPC_CLIENT_INTERFACE,  * PRPC_CLIENT_INTERFACE;

RPC_STATUS __stdcall
I_RpcGetBuffer (
    IN OUT RPC_MESSAGE  * Message
    );

RPC_STATUS __stdcall
I_RpcSendReceive (
    IN OUT RPC_MESSAGE  * Message
    );

RPC_STATUS __stdcall
I_RpcFreeBuffer (
    IN OUT RPC_MESSAGE  * Message
    );

RPC_STATUS __stdcall
I_RpcSend (
    IN OUT PRPC_MESSAGE Message
    ) ;

RPC_STATUS __stdcall
I_RpcReceive (
    IN OUT PRPC_MESSAGE Message,
    IN unsigned int Size
    ) ;

RPC_STATUS __stdcall
I_RpcFreePipeBuffer (
    IN OUT RPC_MESSAGE  * Message
    ) ;

RPC_STATUS __stdcall
I_RpcReallocPipeBuffer (
    IN PRPC_MESSAGE Message,
    IN unsigned int NewSize
    ) ;

typedef void * I_RPC_MUTEX;

void __stdcall
I_RpcRequestMutex (
    IN OUT I_RPC_MUTEX * Mutex
    );

void __stdcall
I_RpcClearMutex (
    IN I_RPC_MUTEX Mutex
    );

void __stdcall
I_RpcDeleteMutex (
    IN I_RPC_MUTEX Mutex
    );

void  * __stdcall
I_RpcAllocate (
    IN unsigned int Size
    );

void __stdcall
I_RpcFree (
    IN void  * Object
    );

void __stdcall
I_RpcPauseExecution (
    IN unsigned long Milliseconds
    );

typedef
void
(__stdcall  * PRPC_RUNDOWN) (
    void  * AssociationContext
    );

RPC_STATUS __stdcall
I_RpcMonitorAssociation (
    IN RPC_BINDING_HANDLE Handle,
    IN PRPC_RUNDOWN RundownRoutine,
    IN void * Context
    );

RPC_STATUS __stdcall
I_RpcStopMonitorAssociation (
    IN RPC_BINDING_HANDLE Handle
    );

RPC_BINDING_HANDLE __stdcall
I_RpcGetCurrentCallHandle(
    void
    );

RPC_STATUS __stdcall
I_RpcGetAssociationContext (
    OUT void  *  * AssociationContext
    );

RPC_STATUS __stdcall
I_RpcSetAssociationContext (
    IN void  * AssociationContext
    );

#ifdef __RPC_NT__

RPC_STATUS __stdcall
I_RpcNsBindingSetEntryName (
    IN RPC_BINDING_HANDLE Binding,
    IN unsigned long EntryNameSyntax,
    IN unsigned short  * EntryName
    );

#else

RPC_STATUS __stdcall
I_RpcNsBindingSetEntryName (
    IN RPC_BINDING_HANDLE Binding,
    IN unsigned long EntryNameSyntax,
    IN unsigned char  * EntryName
    );

#endif

#ifdef __RPC_NT__

RPC_STATUS __stdcall
I_RpcBindingInqDynamicEndpoint (
    IN RPC_BINDING_HANDLE Binding,
    OUT unsigned short  *  * DynamicEndpoint
    );

#else

RPC_STATUS __stdcall
I_RpcBindingInqDynamicEndpoint (
    IN RPC_BINDING_HANDLE Binding,
    OUT unsigned char  *  * DynamicEndpoint
    );

#endif

#define TRANSPORT_TYPE_CN        0x1
#define TRANSPORT_TYPE_DG        0x2
#define TRANSPORT_TYPE_LPC       0x4
#define TRANSPORT_TYPE_WMSG   0x8

RPC_STATUS __stdcall
I_RpcBindingInqTransportType (
    IN RPC_BINDING_HANDLE Binding,
    OUT unsigned int  * Type
    );

typedef struct _RPC_TRANSFER_SYNTAX
{
    UUID Uuid;
    unsigned short VersMajor;
    unsigned short VersMinor;
} RPC_TRANSFER_SYNTAX;

RPC_STATUS __stdcall
I_RpcIfInqTransferSyntaxes (
    IN RPC_IF_HANDLE RpcIfHandle,
    OUT RPC_TRANSFER_SYNTAX  * TransferSyntaxes,
    IN unsigned int TransferSyntaxSize,
    OUT unsigned int  * TransferSyntaxCount
    );

RPC_STATUS __stdcall
I_UuidCreate (
    OUT UUID  * Uuid
    );

RPC_STATUS __stdcall
I_RpcBindingCopy (
    IN RPC_BINDING_HANDLE SourceBinding,
    OUT RPC_BINDING_HANDLE  * DestinationBinding
    );

RPC_STATUS __stdcall
I_RpcBindingIsClientLocal (
    IN RPC_BINDING_HANDLE BindingHandle OPTIONAL,
    OUT unsigned int  * ClientLocalFlag
    );

void __stdcall
I_RpcSsDontSerializeContext (
    void
    );

RPC_STATUS __stdcall
I_RpcLaunchDatagramReceiveThread(
    void  * pAddress
    );

RPC_STATUS __stdcall
I_RpcServerRegisterForwardFunction (
    IN RPC_FORWARD_FUNCTION  * pForwardFunction
    );


RPC_STATUS __stdcall
I_RpcConnectionInqSockBuffSize(
  OUT unsigned long  * RecvBuffSize,
  OUT unsigned long  * SendBuffSize
  );

RPC_STATUS __stdcall
I_RpcConnectionSetSockBuffSize(
   IN unsigned long RecvBuffSize,
   IN unsigned long SendBuffSize
   );


#ifdef MSWMSG
RPC_STATUS __stdcall
I_RpcServerStartListening(
    HWND hWnd
    ) ;

RPC_STATUS __stdcall
I_RpcServerStopListening(
    ) ;

RPC_STATUS __stdcall
I_RpcGetThreadWindowHandle(
    OUT HWND *WindowHandle
    ) ;

typedef RPC_STATUS (*RPC_BLOCKING_FN) (
    IN void *wnd,
    IN void *Context,
    IN HANDLE hSyncEvent
    ) ;

RPC_STATUS __stdcall
I_RpcAsyncSendReceive(
    IN OUT PRPC_MESSAGE pRpcMessage,
    IN OPTIONAL void *Context,
    HWND hWnd
    ) ;

RPC_STATUS __stdcall
I_RpcBindingSetAsync(
    IN RPC_BINDING_HANDLE Binding,
    IN RPC_BLOCKING_FN BlockingFn
    ) ;

LONG __stdcall
I_RpcWindowProc(
    IN HWND hWnd,
    IN UINT Message,
    IN WPARAM wParam,
    IN LPARAM lParam
    ) ;

RPC_STATUS __stdcall
I_RpcSetWMsgEndpoint (
    IN WCHAR  * Endpoint
    ) ;
#endif

RPC_STATUS __stdcall
I_RpcServerInqTransportType(
    OUT unsigned int  * Type
    ) ;

#ifdef __cplusplus
}
#endif

// Reset the packing level for Dos and Windows.

#if defined(__RPC_DOS__) || defined(__RPC_WIN16__)
#pragma pack()
#endif

#endif /* __RPCDCEP_H__ */
#pragma once 
