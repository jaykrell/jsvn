/*++

Copyright (c) 1991-1996 Microsoft Corporation

Module Name:

    rpcdce.h

Abstract:

    This module contains the DCE RPC runtime APIs.

--*/

#ifndef __RPCDCE_H__
#define __RPCDCE_H__

#ifdef __cplusplus
extern "C" {
#endif

#define IN
#define OUT
#define OPTIONAL

/*typedef char small;*/
/*typedef unsigned char byte;*/
/*typedef unsigned char boolean;*/

typedef I_RPC_HANDLE RPC_BINDING_HANDLE;
typedef RPC_BINDING_HANDLE handle_t;
#define rpc_binding_handle_t RPC_BINDING_HANDLE

#ifndef GUID_DEFINED
#define GUID_DEFINED
typedef struct _GUID
{
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
} GUID;
#endif /* GUID_DEFINED */

#ifndef UUID_DEFINED
#define UUID_DEFINED
typedef GUID UUID;
#ifndef uuid_t
#define uuid_t UUID
#endif
#endif

typedef struct _RPC_BINDING_VECTOR
{
    unsigned long Count;
    RPC_BINDING_HANDLE BindingH[1];
} RPC_BINDING_VECTOR;
#ifndef rpc_binding_vector_t
#define rpc_binding_vector_t RPC_BINDING_VECTOR
#endif

typedef struct _UUID_VECTOR
{
  unsigned long Count;
  UUID *Uuid[1];
} UUID_VECTOR;
#ifndef uuid_vector_t
#define uuid_vector_t UUID_VECTOR
#endif

typedef void  * RPC_IF_HANDLE;

#ifndef IFID_DEFINED
#define IFID_DEFINED
typedef struct _RPC_IF_ID
{
    UUID Uuid;
    unsigned short VersMajor;
    unsigned short VersMinor;
} RPC_IF_ID;
#endif

#define RPC_C_BINDING_INFINITE_TIMEOUT 10
#define RPC_C_BINDING_MIN_TIMEOUT 0
#define RPC_C_BINDING_DEFAULT_TIMEOUT 5
#define RPC_C_BINDING_MAX_TIMEOUT 9

#define RPC_C_CANCEL_INFINITE_TIMEOUT -1

#define RPC_C_LISTEN_MAX_CALLS_DEFAULT 1234
#define RPC_C_PROTSEQ_MAX_REQS_DEFAULT 10

#define RPC_C_BIND_TO_ALL_NICS 1
#define RPC_C_USE_INTERNET_PORT 1
#define RPC_C_USE_INTRANET_PORT 2

#ifdef RPC_UNICODE_SUPPORTED
typedef struct _RPC_PROTSEQ_VECTORA
{
    unsigned int Count;
    unsigned char  * Protseq[1];
} RPC_PROTSEQ_VECTORA;

typedef struct _RPC_PROTSEQ_VECTORW
{
    unsigned int Count;
    unsigned short  * Protseq[1];
} RPC_PROTSEQ_VECTORW;

#ifdef UNICODE
#define RPC_PROTSEQ_VECTOR RPC_PROTSEQ_VECTORW
#else /* UNICODE */
#define RPC_PROTSEQ_VECTOR RPC_PROTSEQ_VECTORA
#endif /* UNICODE */

#else /* RPC_UNICODE_SUPPORTED */

typedef struct _RPC_PROTSEQ_VECTOR
{
    unsigned int Count;
    unsigned char  * Protseq[1];
} RPC_PROTSEQ_VECTOR;

#endif /* RPC_UNICODE_SUPPORTED */
typedef struct _RPC_POLICY {
    unsigned int Length ;
    unsigned long EndpointFlags ;
    unsigned long NICFlags ;
    } RPC_POLICY,   *PRPC_POLICY ;

typedef void __stdcall
RPC_OBJECT_INQ_FN (
    IN UUID  * ObjectUuid,
    OUT UUID  * TypeUuid,
    OUT RPC_STATUS  * Status
    );

typedef RPC_STATUS
RPC_IF_CALLBACK_FN (
    IN RPC_IF_HANDLE  InterfaceUuid,
    IN void *Context
    ) ;

#define RPC_MGR_EPV void

typedef struct
{
    unsigned int Count;
    unsigned long Stats[1];
} RPC_STATS_VECTOR;

#define RPC_C_STATS_CALLS_IN 0
#define RPC_C_STATS_CALLS_OUT 1
#define RPC_C_STATS_PKTS_IN 2
#define RPC_C_STATS_PKTS_OUT 3

typedef struct
{
  unsigned long Count;
  RPC_IF_ID  * IfId[1];
} RPC_IF_ID_VECTOR;

/* client */
RPC_STATUS __stdcall
RpcBindingCopy (
    IN RPC_BINDING_HANDLE SourceBinding,
    OUT RPC_BINDING_HANDLE  * DestinationBinding
    );

/* client */
RPC_STATUS __stdcall
RpcBindingFree (
    IN OUT RPC_BINDING_HANDLE  * Binding
    );

/* client */

#ifdef RPC_UNICODE_SUPPORTED

RPC_STATUS __stdcall
RpcBindingFromStringBindingA (
    IN unsigned char  * StringBinding,
    OUT RPC_BINDING_HANDLE  * Binding
    );

RPC_STATUS __stdcall
RpcBindingFromStringBindingW (
    IN unsigned short  * StringBinding,
    OUT RPC_BINDING_HANDLE  * Binding
    );

#ifdef UNICODE
#define RpcBindingFromStringBinding RpcBindingFromStringBindingW
#else /* UNICODE */
#define RpcBindingFromStringBinding RpcBindingFromStringBindingA
#endif /* UNICODE */

#else /* RPC_UNICODE_SUPPORTED */

RPC_STATUS __stdcall
RpcBindingFromStringBinding (
    IN unsigned char  * StringBinding,
    OUT RPC_BINDING_HANDLE  * Binding
    );

#endif /* RPC_UNICODE_SUPPORTED */

/* client/server */
RPC_STATUS __stdcall
RpcBindingInqObject (
    IN RPC_BINDING_HANDLE Binding,
    OUT UUID  * ObjectUuid
    );

/* client */
RPC_STATUS __stdcall
RpcBindingReset (
    IN RPC_BINDING_HANDLE Binding
    );

/* RpcBindingServerFromClient : UNSUPPORTED */
/* RpcBindingSetAuthInfo */

/* client */
RPC_STATUS __stdcall
RpcBindingSetObject (
    IN RPC_BINDING_HANDLE Binding,
    IN UUID  * ObjectUuid
    );

/* client/server */
RPC_STATUS __stdcall
RpcMgmtInqDefaultProtectLevel(
    IN  unsigned long AuthnSvc,
    OUT unsigned long  *AuthnLevel
    );

/* client/server */

#ifdef RPC_UNICODE_SUPPORTED

RPC_STATUS __stdcall
RpcBindingToStringBindingA (
    IN RPC_BINDING_HANDLE Binding,
    OUT unsigned char  *  * StringBinding
    );

RPC_STATUS __stdcall
RpcBindingToStringBindingW (
    IN RPC_BINDING_HANDLE Binding,
    OUT unsigned short  *  * StringBinding
    );

#ifdef UNICODE
#define RpcBindingToStringBinding RpcBindingToStringBindingW
#else /* UNICODE */
#define RpcBindingToStringBinding RpcBindingToStringBindingA
#endif /* UNICODE */

#else /* RPC_UNICODE_SUPPORTED */

RPC_STATUS __stdcall
RpcBindingToStringBinding (
    IN RPC_BINDING_HANDLE Binding,
    OUT unsigned char  *  * StringBinding
    );

#endif /* RPC_UNICODE_SUPPORTED */

/* client/server */
RPC_STATUS __stdcall
RpcBindingVectorFree (
    IN OUT RPC_BINDING_VECTOR  *  * BindingVector
    );

/* client/server */

#ifdef RPC_UNICODE_SUPPORTED

RPC_STATUS __stdcall
RpcStringBindingComposeA (
    IN unsigned char  * ObjUuid OPTIONAL,
    IN unsigned char  * Protseq OPTIONAL,
    IN unsigned char  * NetworkAddr OPTIONAL,
    IN unsigned char  * Endpoint OPTIONAL,
    IN unsigned char  * Options OPTIONAL,
    OUT unsigned char  *  * StringBinding OPTIONAL
    );

RPC_STATUS __stdcall
RpcStringBindingComposeW (
    IN unsigned short  * ObjUuid OPTIONAL,
    IN unsigned short  * Protseq OPTIONAL,
    IN unsigned short  * NetworkAddr OPTIONAL,
    IN unsigned short  * Endpoint OPTIONAL,
    IN unsigned short  * Options OPTIONAL,
    OUT unsigned short  *  * StringBinding OPTIONAL
    );

#ifdef UNICODE
#define RpcStringBindingCompose RpcStringBindingComposeW
#else /* UNICODE */
#define RpcStringBindingCompose RpcStringBindingComposeA
#endif /* UNICODE */

#else /* RPC_UNICODE_SUPPORTED */

RPC_STATUS __stdcall
RpcStringBindingCompose (
    IN unsigned char  * ObjUuid OPTIONAL,
    IN unsigned char  * Protseq OPTIONAL,
    IN unsigned char  * NetworkAddr OPTIONAL,
    IN unsigned char  * Endpoint OPTIONAL,
    IN unsigned char  * Options OPTIONAL,
    OUT unsigned char  *  * StringBinding OPTIONAL
    );

#endif /* RPC_UNICODE_SUPPORTED */

/* client/server */

#ifdef RPC_UNICODE_SUPPORTED

RPC_STATUS __stdcall
RpcStringBindingParseA (
    IN unsigned char  * StringBinding,
    OUT unsigned char  *  * ObjUuid OPTIONAL,
    OUT unsigned char  *  * Protseq OPTIONAL,
    OUT unsigned char  *  * NetworkAddr OPTIONAL,
    OUT unsigned char  *  * Endpoint OPTIONAL,
    OUT unsigned char  *  * NetworkOptions OPTIONAL
    );

RPC_STATUS __stdcall
RpcStringBindingParseW (
    IN unsigned short  * StringBinding,
    OUT unsigned short  *  * ObjUuid OPTIONAL,
    OUT unsigned short  *  * Protseq OPTIONAL,
    OUT unsigned short  *  * NetworkAddr OPTIONAL,
    OUT unsigned short  *  * Endpoint OPTIONAL,
    OUT unsigned short  *  * NetworkOptions OPTIONAL
    );

#ifdef UNICODE
#define RpcStringBindingParse RpcStringBindingParseW
#else /* UNICODE */
#define RpcStringBindingParse RpcStringBindingParseA
#endif /* UNICODE */

#else /* RPC_UNICODE_SUPPORTED */

RPC_STATUS __stdcall
RpcStringBindingParse (
    IN unsigned char  * StringBinding,
    OUT unsigned char  *  * ObjUuid OPTIONAL,
    OUT unsigned char  *  * Protseq OPTIONAL,
    OUT unsigned char  *  * NetworkAddr OPTIONAL,
    OUT unsigned char  *  * Endpoint OPTIONAL,
    OUT unsigned char  *  * NetworkOptions OPTIONAL
    );

#endif /* RPC_UNICODE_SUPPORTED */

/* client/server */

#ifdef RPC_UNICODE_SUPPORTED

RPC_STATUS __stdcall
RpcStringFreeA (
    IN OUT unsigned char  *  * String
    );

RPC_STATUS __stdcall
RpcStringFreeW (
    IN OUT unsigned short  *  * String
    );

#ifdef UNICODE
#define RpcStringFree RpcStringFreeW
#else /* UNICODE */
#define RpcStringFree RpcStringFreeA
#endif /* UNICODE */

#else /* RPC_UNICODE_SUPPORTED */

RPC_STATUS __stdcall
RpcStringFree (
    IN OUT unsigned char  *  * String
    );

#endif /* RPC_UNICODE_SUPPORTED */

/* client/server */
RPC_STATUS __stdcall
RpcIfInqId (
    IN RPC_IF_HANDLE RpcIfHandle,
    OUT RPC_IF_ID  * RpcIfId
    );

/* client/server */

#ifdef RPC_UNICODE_SUPPORTED

RPC_STATUS __stdcall
RpcNetworkIsProtseqValidA (
    IN unsigned char  * Protseq
    );

RPC_STATUS __stdcall
RpcNetworkIsProtseqValidW (
    IN unsigned short  * Protseq
    );

#ifdef UNICODE
#define RpcNetworkIsProtseqValid RpcNetworkIsProtseqValidW
#else /* UNICODE */
#define RpcNetworkIsProtseqValid RpcNetworkIsProtseqValidA
#endif /* UNICODE */

#else /* RPC_UNICODE_SUPPORTED */

RPC_STATUS __stdcall
RpcNetworkIsProtseqValid (
    IN unsigned char  * Protseq
    );

#endif /* RPC_UNICODE_SUPPORTED */

/* client */
RPC_STATUS __stdcall
RpcMgmtInqComTimeout (
    IN RPC_BINDING_HANDLE Binding,
    OUT unsigned int  * Timeout
    );

/* client */
RPC_STATUS __stdcall
RpcMgmtSetComTimeout (
    IN RPC_BINDING_HANDLE Binding,
    IN unsigned int Timeout
    );

/* client */
RPC_STATUS __stdcall
RpcMgmtSetCancelTimeout(
    long Timeout
    );


/* server */

#ifdef RPC_UNICODE_SUPPORTED

RPC_STATUS __stdcall
RpcNetworkInqProtseqsA (
    OUT RPC_PROTSEQ_VECTORA  *  * ProtseqVector
    );

RPC_STATUS __stdcall
RpcNetworkInqProtseqsW (
    OUT RPC_PROTSEQ_VECTORW  *  * ProtseqVector
    );

#ifdef UNICODE
#define RpcNetworkInqProtseqs RpcNetworkInqProtseqsW
#else /* UNICODE */
#define RpcNetworkInqProtseqs RpcNetworkInqProtseqsA
#endif /* UNICODE */

#else /* RPC_UNICODE_SUPPORTED */

RPC_STATUS __stdcall
RpcNetworkInqProtseqs (
    OUT RPC_PROTSEQ_VECTOR  *  * ProtseqVector
    );

#endif /* RPC_UNICODE_SUPPORTED */

/* server */
RPC_STATUS __stdcall
RpcObjectInqType (
    IN UUID  * ObjUuid,
    OUT UUID  * TypeUuid OPTIONAL
    );

/* server */
RPC_STATUS __stdcall
RpcObjectSetInqFn (
    IN RPC_OBJECT_INQ_FN  * InquiryFn
    );

/* server */
RPC_STATUS __stdcall
RpcObjectSetType (
    IN UUID  * ObjUuid,
    IN UUID  * TypeUuid OPTIONAL
    );

/* server */

#ifdef RPC_UNICODE_SUPPORTED

RPC_STATUS __stdcall
RpcProtseqVectorFreeA (
    IN OUT RPC_PROTSEQ_VECTORA  *  * ProtseqVector
    );

RPC_STATUS __stdcall
RpcProtseqVectorFreeW (
    IN OUT RPC_PROTSEQ_VECTORW  *  * ProtseqVector
    );

#ifdef UNICODE
#define RpcProtseqVectorFree RpcProtseqVectorFreeW
#else /* UNICODE */
#define RpcProtseqVectorFree RpcProtseqVectorFreeA
#endif /* UNICODE */

#else /* RPC_UNICODE_SUPPORTED */

RPC_STATUS __stdcall
RpcProtseqVectorFree (
    IN OUT RPC_PROTSEQ_VECTOR  *  * ProtseqVector
    );

#endif /* RPC_UNICODE_SUPPORTED */

/* server */
RPC_STATUS __stdcall
RpcServerInqBindings (
    OUT RPC_BINDING_VECTOR  *  * BindingVector
    );

/* server */
RPC_STATUS __stdcall
RpcServerInqIf (
    IN RPC_IF_HANDLE IfSpec,
    IN UUID  * MgrTypeUuid, OPTIONAL
    OUT RPC_MGR_EPV  *  * MgrEpv
    );

/* server */
RPC_STATUS __stdcall
RpcServerListen (
    IN unsigned int MinimumCallThreads,
    IN unsigned int MaxCalls,
    IN unsigned int DontWait
    );

/* server */
RPC_STATUS __stdcall
RpcServerRegisterIf (
    IN RPC_IF_HANDLE IfSpec,
    IN UUID  * MgrTypeUuid OPTIONAL,
    IN RPC_MGR_EPV  * MgrEpv OPTIONAL
    );

/* server */
RPC_STATUS __stdcall
RpcServerRegisterIfEx (
    IN RPC_IF_HANDLE IfSpec,
    IN UUID  * MgrTypeUuid,
    IN RPC_MGR_EPV  * MgrEpv,
    IN unsigned int Flags,
    IN unsigned int MaxCalls,
    IN RPC_IF_CALLBACK_FN  *IfCallback
    );

/* server */
RPC_STATUS __stdcall
RpcServerUnregisterIf (
    IN RPC_IF_HANDLE IfSpec,
    IN UUID  * MgrTypeUuid, OPTIONAL
    IN unsigned int WaitForCallsToComplete
    );

/* server */
RPC_STATUS __stdcall
RpcServerUseAllProtseqs (
    IN unsigned int MaxCalls,
    IN void  * SecurityDescriptor OPTIONAL
    );

/* server */
RPC_STATUS __stdcall
RpcServerUseAllProtseqsEx (
    IN unsigned int MaxCalls,
    IN void  * SecurityDescriptor,
    IN PRPC_POLICY Policy
    );

/* server */
RPC_STATUS __stdcall
RpcServerUseAllProtseqsIf (
    IN unsigned int MaxCalls,
    IN RPC_IF_HANDLE IfSpec,
    IN void  * SecurityDescriptor OPTIONAL
    );

/* server */
RPC_STATUS __stdcall
RpcServerUseAllProtseqsIfEx (
    IN unsigned int MaxCalls,
    IN RPC_IF_HANDLE IfSpec,
    IN void  * SecurityDescriptor,
    IN PRPC_POLICY Policy
    );


/* server */

#ifdef RPC_UNICODE_SUPPORTED

RPC_STATUS __stdcall
RpcServerUseProtseqA (
    IN unsigned char  * Protseq,
    IN unsigned int MaxCalls,
    IN void  * SecurityDescriptor OPTIONAL
    );

RPC_STATUS __stdcall
RpcServerUseProtseqExA (
    IN unsigned char  * Protseq,
    IN unsigned int MaxCalls,
    IN void  * SecurityDescriptor,
    IN PRPC_POLICY Policy
    );

RPC_STATUS __stdcall
RpcServerUseProtseqW (
    IN unsigned short  * Protseq,
    IN unsigned int MaxCalls,
    IN void  * SecurityDescriptor OPTIONAL
    );

RPC_STATUS __stdcall
RpcServerUseProtseqExW (
    IN unsigned short  * Protseq,
    IN unsigned int MaxCalls,
    IN void  * SecurityDescriptor,
    IN PRPC_POLICY Policy
    );

#ifdef UNICODE
#define RpcServerUseProtseq RpcServerUseProtseqW
#define RpcServerUseProtseqEx RpcServerUseProtseqExW
#else /* UNICODE */
#define RpcServerUseProtseq RpcServerUseProtseqA
#define RpcServerUseProtseqEx RpcServerUseProtseqExA
#endif /* UNICODE */

#else /* RPC_UNICODE_SUPPORTED */

RPC_STATUS __stdcall
RpcServerUseProtseq (
    IN unsigned char  * Protseq,
    IN unsigned int MaxCalls,
    IN void  * SecurityDescriptor OPTIONAL
    );

RPC_STATUS __stdcall
RpcServerUseProtseqEx (
    IN unsigned char  * Protseq,
    IN unsigned int MaxCalls,
    IN void  * SecurityDescriptor,
    IN PRPC_POLICY Policy
    );

#endif /* RPC_UNICODE_SUPPORTED */

/* server */

#ifdef RPC_UNICODE_SUPPORTED

RPC_STATUS __stdcall
RpcServerUseProtseqEpA (
    IN unsigned char  * Protseq,
    IN unsigned int MaxCalls,
    IN unsigned char  * Endpoint,
    IN void  * SecurityDescriptor OPTIONAL
    );

RPC_STATUS __stdcall
RpcServerUseProtseqEpExA (
    IN unsigned char  * Protseq,
    IN unsigned int MaxCalls,
    IN unsigned char  * Endpoint,
    IN void  * SecurityDescriptor,
    IN PRPC_POLICY Policy
    );

RPC_STATUS __stdcall
RpcServerUseProtseqEpW (
    IN unsigned short  * Protseq,
    IN unsigned int MaxCalls,
    IN unsigned short  * Endpoint,
    IN void  * SecurityDescriptor OPTIONAL
    );

RPC_STATUS __stdcall
RpcServerUseProtseqEpExW (
    IN unsigned short  * Protseq,
    IN unsigned int MaxCalls,
    IN unsigned short  * Endpoint,
    IN void  * SecurityDescriptor,
    IN PRPC_POLICY Policy
    );

#ifdef UNICODE
#define RpcServerUseProtseqEp RpcServerUseProtseqEpW
#define RpcServerUseProtseqEpEx RpcServerUseProtseqEpExW
#else /* UNICODE */
#define RpcServerUseProtseqEp RpcServerUseProtseqEpA
#define RpcServerUseProtseqEpEx RpcServerUseProtseqEpExA
#endif /* UNICODE */

#else /* RPC_UNICODE_SUPPORTED */

RPC_STATUS __stdcall
RpcServerUseProtseqEp (
    IN unsigned char  * Protseq,
    IN unsigned int MaxCalls,
    IN unsigned char  * Endpoint,
    IN void  * SecurityDescriptor OPTIONAL
    );

RPC_STATUS __stdcall
RpcServerUseProtseqEpEx (
    IN unsigned char  * Protseq,
    IN unsigned int MaxCalls,
    IN unsigned char  * Endpoint,
    IN void  * SecurityDescriptor,
    IN PRPC_POLICY Policy
    );

#endif /* RPC_UNICODE_SUPPORTED */

/* server */

#ifdef RPC_UNICODE_SUPPORTED

RPC_STATUS __stdcall
RpcServerUseProtseqIfA (
    IN unsigned char  * Protseq,
    IN unsigned int MaxCalls,
    IN RPC_IF_HANDLE IfSpec,
    IN void  * SecurityDescriptor OPTIONAL
    );

RPC_STATUS __stdcall
RpcServerUseProtseqIfExA (
    IN unsigned char  * Protseq,
    IN unsigned int MaxCalls,
    IN RPC_IF_HANDLE IfSpec,
    IN void  * SecurityDescriptor,
    IN PRPC_POLICY Policy
    );

RPC_STATUS __stdcall
RpcServerUseProtseqIfW (
    IN unsigned short  * Protseq,
    IN unsigned int MaxCalls,
    IN RPC_IF_HANDLE IfSpec,
    IN void  * SecurityDescriptor OPTIONAL
    );

RPC_STATUS __stdcall
RpcServerUseProtseqIfExW (
    IN unsigned short  * Protseq,
    IN unsigned int MaxCalls,
    IN RPC_IF_HANDLE IfSpec,
    IN void  * SecurityDescriptor,
    IN PRPC_POLICY Policy
    );

#ifdef UNICODE
#define RpcServerUseProtseqIf RpcServerUseProtseqIfW
#define RpcServerUseProtseqIfEx RpcServerUseProtseqIfExW
#else /* UNICODE */
#define RpcServerUseProtseqIf RpcServerUseProtseqIfA
#define RpcServerUseProtseqIfEx RpcServerUseProtseqIfExA
#endif /* UNICODE */

#else /* RPC_UNICODE_SUPPORTED */

RPC_STATUS __stdcall
RpcServerUseProtseqIf (
    IN unsigned char  * Protseq,
    IN unsigned int MaxCalls,
    IN RPC_IF_HANDLE IfSpec,
    IN void  * SecurityDescriptor OPTIONAL
    );

RPC_STATUS __stdcall
RpcServerUseProtseqIfEx (
    IN unsigned char  * Protseq,
    IN unsigned int MaxCalls,
    IN RPC_IF_HANDLE IfSpec,
    IN void  * SecurityDescriptor,
    IN PRPC_POLICY Policy
    );

#endif /* RPC_UNICODE_SUPPORTED */

/* server */
RPC_STATUS __stdcall
RpcMgmtStatsVectorFree (
    IN RPC_STATS_VECTOR ** StatsVector
    );

/* server */
RPC_STATUS __stdcall
RpcMgmtInqStats (
    IN RPC_BINDING_HANDLE Binding,
    OUT RPC_STATS_VECTOR ** Statistics
    );

/* server */
RPC_STATUS __stdcall
RpcMgmtIsServerListening (
    IN RPC_BINDING_HANDLE Binding
    );

/* server */
RPC_STATUS __stdcall
RpcMgmtStopServerListening (
    IN RPC_BINDING_HANDLE Binding
    );

/* server */
RPC_STATUS __stdcall
RpcMgmtWaitServerListen (
    void
    );

/* server */
RPC_STATUS __stdcall
RpcMgmtSetServerStackSize (
    IN unsigned long ThreadStackSize
    );

/* server */
void __stdcall
RpcSsDontSerializeContext (
    void
    );

/* client */
RPC_STATUS __stdcall
RpcMgmtEnableIdleCleanup (
    void
    );

RPC_STATUS __stdcall
RpcMgmtInqIfIds (
    IN RPC_BINDING_HANDLE Binding,
    OUT RPC_IF_ID_VECTOR  *  * IfIdVector
    );

RPC_STATUS __stdcall
RpcIfIdVectorFree (
    IN OUT RPC_IF_ID_VECTOR  *  * IfIdVector
    );

#ifdef RPC_UNICODE_SUPPORTED

RPC_STATUS __stdcall
RpcMgmtInqServerPrincNameA (
    IN RPC_BINDING_HANDLE Binding,
    IN unsigned long AuthnSvc,
    OUT unsigned char  *  * ServerPrincName
    );

RPC_STATUS __stdcall
RpcMgmtInqServerPrincNameW (
    IN RPC_BINDING_HANDLE Binding,
    IN unsigned long AuthnSvc,
    OUT unsigned short  *  * ServerPrincName
    );

#ifdef UNICODE
#define RpcMgmtInqServerPrincName RpcMgmtInqServerPrincNameW
#else /* UNICODE */
#define RpcMgmtInqServerPrincName RpcMgmtInqServerPrincNameA
#endif /* UNICODE */

#else /* RPC_UNICODE_SUPPORTED */

RPC_STATUS __stdcall
RpcMgmtInqServerPrincName (
    IN RPC_BINDING_HANDLE Binding,
    IN unsigned long AuthnSvc,
    OUT unsigned char  *  * ServerPrincName
    );

#endif /* RPC_UNICODE_SUPPORTED */

#ifdef RPC_UNICODE_SUPPORTED

RPC_STATUS __stdcall
RpcServerInqDefaultPrincNameA (
    IN unsigned long AuthnSvc,
    OUT unsigned char  *  * PrincName
    );

RPC_STATUS __stdcall
RpcServerInqDefaultPrincNameW (
    IN unsigned long AuthnSvc,
    OUT unsigned short  *  * PrincName
    );

#ifdef UNICODE
#define RpcServerInqDefaultPrincName RpcServerInqDefaultPrincNameW
#else /* UNICODE */
#define RpcServerInqDefaultPrincName RpcServerInqDefaultPrincNameA
#endif /* UNICODE */

#else /* RPC_UNICODE_SUPPORTED */

RPC_STATUS __stdcall
RpcServerInqDefaultPrincName (
    IN unsigned long AuthnSvc,
    OUT unsigned char  *  * PrincName
    );

#endif /* RPC_UNICODE_SUPPORTED */

/* client */
RPC_STATUS __stdcall
RpcEpResolveBinding (
    IN RPC_BINDING_HANDLE Binding,
    IN RPC_IF_HANDLE IfSpec
    );

/* client */

#ifdef RPC_UNICODE_SUPPORTED

RPC_STATUS __stdcall
RpcNsBindingInqEntryNameA (
    IN RPC_BINDING_HANDLE Binding,
    IN unsigned long EntryNameSyntax,
    OUT unsigned char  *  * EntryName
    );

RPC_STATUS __stdcall
RpcNsBindingInqEntryNameW (
    IN RPC_BINDING_HANDLE Binding,
    IN unsigned long EntryNameSyntax,
    OUT unsigned short  *  * EntryName
    );

#ifdef UNICODE
#define RpcNsBindingInqEntryName RpcNsBindingInqEntryNameW
#else /* UNICODE */
#define RpcNsBindingInqEntryName RpcNsBindingInqEntryNameA
#endif /* UNICODE */

#else /* RPC_UNICODE_SUPPORTED */

RPC_STATUS __stdcall
RpcNsBindingInqEntryName (
    IN RPC_BINDING_HANDLE Binding,
    IN unsigned long EntryNameSyntax,
    OUT unsigned char  *  * EntryName
    );

#endif /* RPC_UNICODE_SUPPORTED */

typedef void  * RPC_AUTH_IDENTITY_HANDLE;
typedef void  * RPC_AUTHZ_HANDLE;

#define RPC_C_AUTHN_LEVEL_DEFAULT 0
#define RPC_C_AUTHN_LEVEL_NONE 1
#define RPC_C_AUTHN_LEVEL_CONNECT 2
#define RPC_C_AUTHN_LEVEL_CALL 3
#define RPC_C_AUTHN_LEVEL_PKT 4
#define RPC_C_AUTHN_LEVEL_PKT_INTEGRITY 5
#define RPC_C_AUTHN_LEVEL_PKT_PRIVACY 6

#define RPC_C_IMP_LEVEL_ANONYMOUS    1
#define RPC_C_IMP_LEVEL_IDENTIFY     2
#define RPC_C_IMP_LEVEL_IMPERSONATE  3
#define RPC_C_IMP_LEVEL_DELEGATE     4

#define RPC_C_QOS_IDENTITY_STATIC    0
#define RPC_C_QOS_IDENTITY_DYNAMIC   1

#define RPC_C_QOS_CAPABILITIES_DEFAULT     0
#define RPC_C_QOS_CAPABILITIES_MUTUAL_AUTH 1

#define RPC_C_PROTECT_LEVEL_DEFAULT       (RPC_C_AUTHN_LEVEL_DEFAULT)
#define RPC_C_PROTECT_LEVEL_NONE          (RPC_C_AUTHN_LEVEL_NONE)
#define RPC_C_PROTECT_LEVEL_CONNECT       (RPC_C_AUTHN_LEVEL_CONNECT)
#define RPC_C_PROTECT_LEVEL_CALL          (RPC_C_AUTHN_LEVEL_CALL)
#define RPC_C_PROTECT_LEVEL_PKT           (RPC_C_AUTHN_LEVEL_PKT)
#define RPC_C_PROTECT_LEVEL_PKT_INTEGRITY (RPC_C_AUTHN_LEVEL_PKT_INTEGRITY)
#define RPC_C_PROTECT_LEVEL_PKT_PRIVACY   (RPC_C_AUTHN_LEVEL_PKT_PRIVACY)

#define RPC_C_AUTHN_NONE 0
#define RPC_C_AUTHN_DCE_PRIVATE 1
#define RPC_C_AUTHN_DCE_PUBLIC 2
#define RPC_C_AUTHN_DEC_PUBLIC 4
#define RPC_C_AUTHN_WINNT       10
#define RPC_C_AUTHN_DEFAULT 0xFFFFFFFFL

#define RPC_C_SECURITY_QOS_VERSION  1L

typedef struct _RPC_SECURITY_QOS {
  unsigned long Version;
  unsigned long Capabilities;
  unsigned long IdentityTracking;
  unsigned long ImpersonationType;
} RPC_SECURITY_QOS, *PRPC_SECURITY_QOS;

#if defined(__RPC_DOS__) || defined(__RPC_WIN16__)
typedef struct _SEC_WINNT_AUTH_IDENTITY
{
  char  *User;
  char  *Domain;
  char  *Password;
} SEC_WINNT_AUTH_IDENTITY;
#else


#define SEC_WINNT_AUTH_IDENTITY_ANSI 0x1
#define SEC_WINNT_AUTH_IDENTITY_UNICODE 0x2

typedef struct _SEC_WINNT_AUTH_IDENTITY_W {
  unsigned short  *User;
  unsigned long UserLength;
  unsigned short  *Domain;
  unsigned long DomainLength;
  unsigned short  *Password;
  unsigned long PasswordLength;
  unsigned long Flags;
} SEC_WINNT_AUTH_IDENTITY_W, *PSEC_WINNT_AUTH_IDENTITY_W;

typedef struct _SEC_WINNT_AUTH_IDENTITY_A {
  unsigned char  *User;
  unsigned long UserLength;
  unsigned char  *Domain;
  unsigned long DomainLength;
  unsigned char  *Password;
  unsigned long PasswordLength;
  unsigned long Flags;
} SEC_WINNT_AUTH_IDENTITY_A, *PSEC_WINNT_AUTH_IDENTITY_A;


#ifdef UNICODE
#define SEC_WINNT_AUTH_IDENTITY SEC_WINNT_AUTH_IDENTITY_W
#define PSEC_WINNT_AUTH_IDENTITY PSEC_WINNT_AUTH_IDENTITY_W
#define _SEC_WINNT_AUTH_IDENTITY _SEC_WINNT_AUTH_IDENTITY_W
#else // UNICODE
#define SEC_WINNT_AUTH_IDENTITY SEC_WINNT_AUTH_IDENTITY_A
#define PSEC_WINNT_AUTH_IDENTITY PSEC_WINNT_AUTH_IDENTITY_A
#define _SEC_WINNT_AUTH_IDENTITY _SEC_WINNT_AUTH_IDENTITY_A
#endif // UNICODE
#endif // defined(__RPC_DOS__) || defined(__RPC_WIN16__)

#define RPC_C_AUTHZ_NONE 0
#define RPC_C_AUTHZ_NAME 1
#define RPC_C_AUTHZ_DCE 2

#ifdef RPC_UNICODE_SUPPORTED

RPC_STATUS __stdcall
RpcBindingInqAuthClientA (
    IN RPC_BINDING_HANDLE ClientBinding, OPTIONAL
    OUT RPC_AUTHZ_HANDLE  * Privs,
    OUT unsigned char  *  * ServerPrincName, OPTIONAL
    OUT unsigned long  * AuthnLevel, OPTIONAL
    OUT unsigned long  * AuthnSvc, OPTIONAL
    OUT unsigned long  * AuthzSvc OPTIONAL
    );

RPC_STATUS __stdcall
RpcBindingInqAuthClientW (
    IN RPC_BINDING_HANDLE ClientBinding, OPTIONAL
    OUT RPC_AUTHZ_HANDLE  * Privs,
    OUT unsigned short  *  * ServerPrincName, OPTIONAL
    OUT unsigned long  * AuthnLevel, OPTIONAL
    OUT unsigned long  * AuthnSvc, OPTIONAL
    OUT unsigned long  * AuthzSvc OPTIONAL
    );

RPC_STATUS __stdcall
RpcBindingInqAuthInfoA (
    IN RPC_BINDING_HANDLE Binding,
    OUT unsigned char  *  * ServerPrincName, OPTIONAL
    OUT unsigned long  * AuthnLevel, OPTIONAL
    OUT unsigned long  * AuthnSvc, OPTIONAL
    OUT RPC_AUTH_IDENTITY_HANDLE  * AuthIdentity, OPTIONAL
    OUT unsigned long  * AuthzSvc OPTIONAL
    );

RPC_STATUS __stdcall
RpcBindingInqAuthInfoW (
    IN RPC_BINDING_HANDLE Binding,
    OUT unsigned short  *  * ServerPrincName, OPTIONAL
    OUT unsigned long  * AuthnLevel, OPTIONAL
    OUT unsigned long  * AuthnSvc, OPTIONAL
    OUT RPC_AUTH_IDENTITY_HANDLE  * AuthIdentity, OPTIONAL
    OUT unsigned long  * AuthzSvc OPTIONAL
    );

RPC_STATUS __stdcall
RpcBindingSetAuthInfoA (
    IN RPC_BINDING_HANDLE Binding,
    IN unsigned char  * ServerPrincName,
    IN unsigned long AuthnLevel,
    IN unsigned long AuthnSvc,
    IN RPC_AUTH_IDENTITY_HANDLE AuthIdentity, OPTIONAL
    IN unsigned long AuthzSvc
    );

RPC_STATUS __stdcall
RpcBindingSetAuthInfoExA (
    IN RPC_BINDING_HANDLE Binding,
    IN unsigned char  * ServerPrincName,
    IN unsigned long AuthnLevel,
    IN unsigned long AuthnSvc,
    IN RPC_AUTH_IDENTITY_HANDLE AuthIdentity, OPTIONAL
    IN unsigned long AuthzSvc,
    IN RPC_SECURITY_QOS *SecurityQos OPTIONAL
    );

RPC_STATUS __stdcall
RpcBindingSetAuthInfoW (
    IN RPC_BINDING_HANDLE Binding,
    IN unsigned short  * ServerPrincName,
    IN unsigned long AuthnLevel,
    IN unsigned long AuthnSvc,
    IN RPC_AUTH_IDENTITY_HANDLE AuthIdentity, OPTIONAL
    IN unsigned long AuthzSvc
    );

RPC_STATUS __stdcall
RpcBindingSetAuthInfoExW (
    IN RPC_BINDING_HANDLE Binding,
    IN unsigned short  * ServerPrincName,
    IN unsigned long AuthnLevel,
    IN unsigned long AuthnSvc,
    IN RPC_AUTH_IDENTITY_HANDLE AuthIdentity, OPTIONAL
    IN unsigned long AuthzSvc, OPTIONAL
    IN RPC_SECURITY_QOS *SecurityQOS
    );

RPC_STATUS __stdcall
RpcBindingInqAuthInfoExA (
    IN RPC_BINDING_HANDLE Binding,
    OUT unsigned char  *  * ServerPrincName, OPTIONAL
    OUT unsigned long  * AuthnLevel, OPTIONAL
    OUT unsigned long  * AuthnSvc, OPTIONAL
    OUT RPC_AUTH_IDENTITY_HANDLE  * AuthIdentity, OPTIONAL
    OUT unsigned long  * AuthzSvc, OPTIONAL
    IN  unsigned long RpcQosVersion,
    OUT RPC_SECURITY_QOS *SecurityQOS
    );

RPC_STATUS __stdcall
RpcBindingInqAuthInfoExW (
    IN RPC_BINDING_HANDLE Binding,
    OUT unsigned short  *  * ServerPrincName, OPTIONAL
    OUT unsigned long  * AuthnLevel, OPTIONAL
    OUT unsigned long  * AuthnSvc, OPTIONAL
    OUT RPC_AUTH_IDENTITY_HANDLE  * AuthIdentity, OPTIONAL
    OUT unsigned long  * AuthzSvc OPTIONAL,
    IN  unsigned long RpcQosVersion,
    OUT RPC_SECURITY_QOS *SecurityQOS
    );

typedef void
(__stdcall * RPC_AUTH_KEY_RETRIEVAL_FN) (
    IN void  * Arg,
    IN unsigned short  * ServerPrincName,
    IN unsigned long KeyVer,
    OUT void  *  * Key,
    OUT RPC_STATUS  * Status
    );

RPC_STATUS __stdcall
RpcServerRegisterAuthInfoA (
    IN unsigned char  * ServerPrincName,
    IN unsigned long AuthnSvc,
    IN RPC_AUTH_KEY_RETRIEVAL_FN GetKeyFn OPTIONAL,
    IN void  * Arg OPTIONAL
    );

RPC_STATUS __stdcall
RpcServerRegisterAuthInfoW (
    IN unsigned short  * ServerPrincName,
    IN unsigned long AuthnSvc,
    IN RPC_AUTH_KEY_RETRIEVAL_FN GetKeyFn OPTIONAL,
    IN void  * Arg OPTIONAL
    );

#ifdef UNICODE
#define RpcBindingInqAuthClient RpcBindingInqAuthClientW
#define RpcBindingInqAuthInfo RpcBindingInqAuthInfoW
#define RpcBindingSetAuthInfo RpcBindingSetAuthInfoW
#define RpcServerRegisterAuthInfo RpcServerRegisterAuthInfoW
#define RpcBindingInqAuthInfoEx RpcBindingInqAuthInfoExW
#define RpcBindingSetAuthInfoEx RpcBindingSetAuthInfoExW
#else /* UNICODE */
#define RpcBindingInqAuthClient RpcBindingInqAuthClientA
#define RpcBindingInqAuthInfo RpcBindingInqAuthInfoA
#define RpcBindingSetAuthInfo RpcBindingSetAuthInfoA
#define RpcServerRegisterAuthInfo RpcServerRegisterAuthInfoA
#define RpcBindingInqAuthInfoEx RpcBindingInqAuthInfoExA
#define RpcBindingSetAuthInfoEx RpcBindingSetAuthInfoExA
#endif /* UNICODE */

#else /* RPC_UNICODE_SUPPORTED */

RPC_STATUS __stdcall
RpcBindingInqAuthClient (
    IN RPC_BINDING_HANDLE ClientBinding, OPTIONAL
    OUT RPC_AUTHZ_HANDLE  * Privs,
    OUT unsigned char  *  * ServerPrincName, OPTIONAL
    OUT unsigned long  * AuthnLevel, OPTIONAL
    OUT unsigned long  * AuthnSvc, OPTIONAL
    OUT unsigned long  * AuthzSvc OPTIONAL
    );

RPC_STATUS __stdcall
RpcBindingInqAuthInfo (
    IN RPC_BINDING_HANDLE Binding,
    OUT unsigned char  *  * ServerPrincName, OPTIONAL
    OUT unsigned long  * AuthnLevel, OPTIONAL
    OUT unsigned long  * AuthnSvc, OPTIONAL
    OUT RPC_AUTH_IDENTITY_HANDLE  * AuthIdentity, OPTIONAL
    OUT unsigned long  * AuthzSvc OPTIONAL
    );

RPC_STATUS __stdcall
RpcBindingSetAuthInfo (
    IN RPC_BINDING_HANDLE Binding,
    IN unsigned char  * ServerPrincName,
    IN unsigned long AuthnLevel,
    IN unsigned long AuthnSvc,
    IN RPC_AUTH_IDENTITY_HANDLE AuthIdentity, OPTIONAL
    IN unsigned long AuthzSvc
    );

typedef void
(__stdcall * RPC_AUTH_KEY_RETRIEVAL_FN) (
    IN void  * Arg,
    IN unsigned char  * ServerPrincName,
    IN unsigned long KeyVer,
    OUT void  *  * Key,
    OUT RPC_STATUS  * Status
    );

RPC_STATUS __stdcall
RpcServerRegisterAuthInfo (
    IN unsigned char  * ServerPrincName,
    IN unsigned long AuthnSvc,
    IN RPC_AUTH_KEY_RETRIEVAL_FN GetKeyFn OPTIONAL,
    IN void  * Arg OPTIONAL
    );

#endif /* RPC_UNICODE_SUPPORTED */

typedef struct {
    unsigned char  * UserName;
    unsigned char  * ComputerName;
    unsigned short Privilege;
    unsigned long AuthFlags;
} RPC_CLIENT_INFORMATION1,  * PRPC_CLIENT_INFORMATION1;

RPC_STATUS __stdcall
RpcBindingServerFromClient (
    IN RPC_BINDING_HANDLE ClientBinding,
    OUT RPC_BINDING_HANDLE  * ServerBinding
    );

void __stdcall
RpcRaiseException (
    IN RPC_STATUS exception
    );

RPC_STATUS __stdcall
RpcTestCancel(
    );

RPC_STATUS __stdcall
RpcCancelThread(
    IN void * Thread
    );

/* client/server */
RPC_STATUS __stdcall
UuidCreate (
    OUT UUID  * Uuid
    );

#ifdef RPC_UNICODE_SUPPORTED

/* client/server */
RPC_STATUS __stdcall
UuidToStringA (
    IN UUID  * Uuid,
    OUT unsigned char  *  * StringUuid
    );

/* client/server */
RPC_STATUS __stdcall
UuidFromStringA (
    IN unsigned char  * StringUuid,
    OUT UUID  * Uuid
    );

/* client/server */
RPC_STATUS __stdcall
UuidToStringW (
    IN UUID  * Uuid,
    OUT unsigned short  *  * StringUuid
    );

/* client/server */
RPC_STATUS __stdcall
UuidFromStringW (
    IN unsigned short  * StringUuid,
    OUT UUID  * Uuid
    );

#ifdef UNICODE
#define UuidFromString UuidFromStringW
#define UuidToString UuidToStringW
#else /* UNICODE */
#define UuidFromString UuidFromStringA
#define UuidToString UuidToStringA
#endif /* UNICODE */

#else /* RPC_UNICODE_SUPPORTED */

/* client/server */
RPC_STATUS __stdcall
UuidToString (
    IN UUID  * Uuid,
    OUT unsigned char  *  * StringUuid
    );

/* client/server */
RPC_STATUS __stdcall
UuidFromString (
    IN unsigned char  * StringUuid,
    OUT UUID  * Uuid
    );

#endif /* RPC_UNICODE_SUPPORTED */

signed int __stdcall
UuidCompare (
    IN UUID  * Uuid1,
    IN UUID  * Uuid2,
    OUT RPC_STATUS  * Status
    );

RPC_STATUS __stdcall
UuidCreateNil (
    OUT UUID  * NilUuid
    );

int __stdcall
UuidEqual (
    IN UUID  * Uuid1,
    IN UUID  * Uuid2,
    OUT RPC_STATUS  * Status
    );

unsigned short __stdcall
UuidHash (
    IN UUID  * Uuid,
    OUT RPC_STATUS  * Status
    );

int __stdcall
UuidIsNil (
    IN UUID  * Uuid,
    OUT RPC_STATUS  * Status
    );

#ifdef RPC_UNICODE_SUPPORTED

RPC_STATUS __stdcall
RpcEpRegisterNoReplaceA (
    IN RPC_IF_HANDLE IfSpec,
    IN RPC_BINDING_VECTOR * BindingVector,
    IN UUID_VECTOR * UuidVector OPTIONAL,
    IN unsigned char * Annotation
    );

RPC_STATUS __stdcall
RpcEpRegisterNoReplaceW (
    IN RPC_IF_HANDLE IfSpec,
    IN RPC_BINDING_VECTOR * BindingVector,
    IN UUID_VECTOR * UuidVector OPTIONAL,
    IN unsigned short  * Annotation
    );

RPC_STATUS __stdcall
RpcEpRegisterA (
    IN RPC_IF_HANDLE IfSpec,
    IN RPC_BINDING_VECTOR * BindingVector,
    IN UUID_VECTOR * UuidVector OPTIONAL,
    IN unsigned char * Annotation
    );

RPC_STATUS __stdcall
RpcEpRegisterW (
    IN RPC_IF_HANDLE IfSpec,
    IN RPC_BINDING_VECTOR * BindingVector,
    IN UUID_VECTOR * UuidVector OPTIONAL,
    IN unsigned short * Annotation
    );

#ifdef UNICODE
#define RpcEpRegisterNoReplace RpcEpRegisterNoReplaceW
#define RpcEpRegister RpcEpRegisterW
#else /* UNICODE */
#define RpcEpRegisterNoReplace RpcEpRegisterNoReplaceA
#define RpcEpRegister RpcEpRegisterA
#endif /* UNICODE */

#else /* RPC_UNICODE_SUPPORTED */

RPC_STATUS __stdcall
RpcEpRegisterNoReplace (
    IN RPC_IF_HANDLE IfSpec,
    IN RPC_BINDING_VECTOR * BindingVector,
    IN UUID_VECTOR * UuidVector OPTIONAL,
    IN unsigned  char * Annotation
    );

RPC_STATUS __stdcall
RpcEpRegister (
    IN RPC_IF_HANDLE IfSpec,
    IN RPC_BINDING_VECTOR * BindingVector,
    IN UUID_VECTOR * UuidVector OPTIONAL,
    IN unsigned char * Annotation
    );

#endif /* RPC_UNICODE_SUPPORTED */


RPC_STATUS __stdcall
RpcEpUnregister(
    IN RPC_IF_HANDLE IfSpec,
    IN RPC_BINDING_VECTOR * BindingVector,
    IN UUID_VECTOR * UuidVector
    );

#ifdef RPC_UNICODE_SUPPORTED

RPC_STATUS __stdcall
DceErrorInqTextA (
    IN RPC_STATUS RpcStatus,
    OUT unsigned char  * ErrorText
    );

RPC_STATUS __stdcall
DceErrorInqTextW (
    IN RPC_STATUS RpcStatus,
    OUT unsigned short  * ErrorText
    );

#ifdef UNICODE
#define DceErrorInqText DceErrorInqTextW
#else /* UNICODE */
#define DceErrorInqText DceErrorInqTextA
#endif /* UNICODE */

#else /* RPC_UNICODE_SUPPORTED */

RPC_STATUS __stdcall
DceErrorInqText (
    IN RPC_STATUS RpcStatus,
    OUT unsigned char  * ErrorText
    );

#endif /* RPC_UNICODE_SUPPORTED */

#define DCE_C_ERROR_STRING_LEN 256

typedef I_RPC_HANDLE * RPC_EP_INQ_HANDLE;

#define  RPC_C_EP_ALL_ELTS        0
#define  RPC_C_EP_MATCH_BY_IF     1
#define  RPC_C_EP_MATCH_BY_OBJ    2
#define  RPC_C_EP_MATCH_BY_BOTH   3

#define  RPC_C_VERS_ALL           1
#define  RPC_C_VERS_COMPATIBLE    2
#define  RPC_C_VERS_EXACT         3
#define  RPC_C_VERS_MAJOR_ONLY    4
#define  RPC_C_VERS_UPTO          5

RPC_STATUS __stdcall
RpcMgmtEpEltInqBegin (
    IN RPC_BINDING_HANDLE EpBinding OPTIONAL,
    IN unsigned long InquiryType,
    IN RPC_IF_ID  * IfId OPTIONAL,
    IN unsigned long VersOption OPTIONAL,
    IN UUID  * ObjectUuid OPTIONAL,
    OUT RPC_EP_INQ_HANDLE  * InquiryContext
    );

RPC_STATUS __stdcall
RpcMgmtEpEltInqDone (
    IN OUT RPC_EP_INQ_HANDLE  * InquiryContext
    );

#ifdef RPC_UNICODE_SUPPORTED

RPC_STATUS __stdcall
RpcMgmtEpEltInqNextA (
    IN RPC_EP_INQ_HANDLE InquiryContext,
    OUT RPC_IF_ID  * IfId,
    OUT RPC_BINDING_HANDLE  * Binding OPTIONAL,
    OUT UUID  * ObjectUuid OPTIONAL,
    OUT unsigned char  *  * Annotation OPTIONAL
    );

RPC_STATUS __stdcall
RpcMgmtEpEltInqNextW (
    IN RPC_EP_INQ_HANDLE InquiryContext,
    OUT RPC_IF_ID  * IfId,
    OUT RPC_BINDING_HANDLE  * Binding OPTIONAL,
    OUT UUID  * ObjectUuid OPTIONAL,
    OUT unsigned short  *  * Annotation OPTIONAL
    );

#ifdef UNICODE
#define RpcMgmtEpEltInqNext RpcMgmtEpEltInqNextW
#else /* UNICODE */
#define RpcMgmtEpEltInqNext RpcMgmtEpEltInqNextA
#endif /* UNICODE */

#else /* RPC_UNICODE_SUPPORTED */

RPC_STATUS __stdcall
RpcMgmtEpEltInqNext (
    IN RPC_EP_INQ_HANDLE InquiryContext,
    OUT RPC_IF_ID  * IfId,
    OUT RPC_BINDING_HANDLE  * Binding OPTIONAL,
    OUT unsigned char  *  * Annotation OPTIONAL
    );

#endif /* RPC_UNICODE_SUPPORTED */

RPC_STATUS __stdcall
RpcMgmtEpUnregister (
    IN RPC_BINDING_HANDLE EpBinding OPTIONAL,
    IN RPC_IF_ID  * IfId,
    IN RPC_BINDING_HANDLE Binding,
    IN UUID  * ObjectUuid OPTIONAL
    );

typedef int
(__stdcall * RPC_MGMT_AUTHORIZATION_FN) (
    IN RPC_BINDING_HANDLE ClientBinding,
    IN unsigned long RequestedMgmtOperation,
    OUT RPC_STATUS  * Status
    );

#define RPC_C_MGMT_INQ_IF_IDS         0
#define RPC_C_MGMT_INQ_PRINC_NAME     1
#define RPC_C_MGMT_INQ_STATS          2
#define RPC_C_MGMT_IS_SERVER_LISTEN   3
#define RPC_C_MGMT_STOP_SERVER_LISTEN 4

RPC_STATUS __stdcall
RpcMgmtSetAuthorizationFn (
    IN RPC_MGMT_AUTHORIZATION_FN AuthorizationFn
    );


#define RPC_C_PARM_MAX_PACKET_LENGTH    1
#define RPC_C_PARM_BUFFER_LENGTH        2

RPC_STATUS __stdcall
RpcMgmtInqParameter (
    IN unsigned Parameter,
    IN unsigned long  * Value
    );

RPC_STATUS __stdcall
RpcMgmtSetParameter (
    IN unsigned Parameter,
    IN unsigned long Value
    );

RPC_STATUS __stdcall
RpcMgmtBindingInqParameter (
    IN RPC_BINDING_HANDLE Handle,
    IN unsigned Parameter,
    IN unsigned long  * Value
    );

RPC_STATUS __stdcall
RpcMgmtBindingSetParameter (
    IN RPC_BINDING_HANDLE Handle,
    IN unsigned Parameter,
    IN unsigned long Value
    );

#define RPC_IF_AUTOLISTEN 0x0001
#define RPC_IF_OLE              0x0002

#include <rpcdcep.h>

#ifdef __cplusplus
}
#endif

#endif /* __RPCDCE_H__ */
#pragma once 
