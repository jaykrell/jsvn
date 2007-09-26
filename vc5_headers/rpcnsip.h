/*++

Copyright (c) 1992-1996 Microsoft Corporation

Module Name:

    rpcnsip.h

Abstract:

    This file contains the types and function definitions to use the
    to implement the autohandle features of the runtime.

--*/

#ifndef __RPCNSIP_H__
#define __RPCNSIP_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
   RPC_NS_HANDLE        LookupContext;
   RPC_BINDING_HANDLE   ProposedHandle;
   RPC_BINDING_VECTOR * Bindings;

} RPC_IMPORT_CONTEXT_P, * PRPC_IMPORT_CONTEXT_P;


/* Stub Auto Binding routines. */

RPC_STATUS __stdcall
I_RpcNsGetBuffer(
    IN PRPC_MESSAGE Message
    );

RPC_STATUS __stdcall
I_RpcNsSendReceive(
    IN PRPC_MESSAGE Message,
    OUT RPC_BINDING_HANDLE  * Handle
    );

void __stdcall
I_RpcNsRaiseException(
    IN PRPC_MESSAGE Message,
    IN RPC_STATUS Status
    );

RPC_STATUS __stdcall
I_RpcReBindBuffer(
    IN PRPC_MESSAGE Message
    );

RPC_STATUS __stdcall
I_NsServerBindSearch(
    );

RPC_STATUS __stdcall
I_NsClientBindSearch(
    );

void __stdcall
I_NsClientBindDone(
    );

#ifdef __cplusplus
}
#endif

#endif /* __RPCNSIP_H__ */
#pragma once 
