/*++

Copyright (c) 1991-1996 Microsoft Corporation

Module Name:

    midles.h

Abstract:

    This module contains definitions needed for encoding/decoding
    support (serializing/deserializing a.k.a. pickling).

--*/

#ifndef __MIDLES_H__
#define __MIDLES_H__

#include <rpcndr.h>

//
// Set the packing level for RPC structures for Dos and Windows.
//

#if defined(__RPC_DOS__) || defined(__RPC_WIN16__)
#pragma pack(2)
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  Pickling support
 */
typedef enum
{
    MES_ENCODE,
    MES_DECODE,
} MIDL_ES_CODE;

typedef enum
{
    MES_INCREMENTAL_HANDLE,
    MES_FIXED_BUFFER_HANDLE,
    MES_DYNAMIC_BUFFER_HANDLE
} MIDL_ES_HANDLE_STYLE;


typedef void (__stdcall *  MIDL_ES_ALLOC )
                ( IN OUT  void  * state,
                  OUT     char  *   * pbuffer,
                  IN OUT  unsigned int  * psize );

typedef void (__stdcall *  MIDL_ES_WRITE)
                ( IN OUT  void  * state,
                  IN      char  * buffer,
                  IN      unsigned int  size );

typedef void (__stdcall *  MIDL_ES_READ)
                ( IN OUT  void  * state,
                  OUT     char  *   * pbuffer,
                  IN OUT     unsigned int  * psize );

typedef struct _MIDL_ES_MESSAGE
{
    MIDL_STUB_MESSAGE                       StubMsg;
    MIDL_ES_CODE                            Operation;
    void  *                        UserState;
    unsigned long                           MesVersion:8;
    unsigned long                           HandleStyle:8;
    unsigned long                           HandleFlags:8;
    unsigned long                           Reserve:8;
    MIDL_ES_ALLOC                           Alloc;
    MIDL_ES_WRITE                           Write;
    MIDL_ES_READ                            Read;
    unsigned char  *               Buffer;
    unsigned long                           BufferSize;
    unsigned char  *  *   pDynBuffer;
    unsigned long  *               pEncodedSize;
    RPC_SYNTAX_IDENTIFIER                   InterfaceId;
    unsigned long                           ProcNumber;
    unsigned long                           AlienDataRep;
    unsigned long                           IncrDataSize;
    unsigned long                           ByteCount;
} MIDL_ES_MESSAGE,  * PMIDL_ES_MESSAGE;

typedef  PMIDL_ES_MESSAGE  MIDL_ES_HANDLE;

RPC_STATUS  __stdcall
MesEncodeIncrementalHandleCreate(
    void       *  UserState,
    MIDL_ES_ALLOC          AllocFn,
    MIDL_ES_WRITE          WriteFn,
    handle_t   *  pHandle );

RPC_STATUS  __stdcall
MesDecodeIncrementalHandleCreate(
    void       *  UserState,
    MIDL_ES_READ           ReadFn,
    handle_t   *  pHandle );


RPC_STATUS  __stdcall
MesIncrementalHandleReset(
    handle_t             Handle,
    void     *  UserState,
    MIDL_ES_ALLOC        AllocFn,
    MIDL_ES_WRITE        WriteFn,
    MIDL_ES_READ         ReadFn,
    MIDL_ES_CODE         Operation );


RPC_STATUS  __stdcall
MesEncodeFixedBufferHandleCreate(
    char  *            pBuffer,
    unsigned long               BufferSize,
    unsigned long  *   pEncodedSize,
    handle_t   *       pHandle );

RPC_STATUS  __stdcall
MesEncodeDynBufferHandleCreate(
    char  *  *    pBuffer,
    unsigned long     *    pEncodedSize,
    handle_t   *           pHandle );

RPC_STATUS  __stdcall
MesDecodeBufferHandleCreate(
    char  *        pBuffer,
    unsigned long           BufferSize,
    handle_t   *   pHandle );


RPC_STATUS  __stdcall
MesBufferHandleReset(
    handle_t                        Handle,
    unsigned long                   HandleStyle,
    MIDL_ES_CODE                    Operation,
    char  *  *    pBuffer,
    unsigned long                   BufferSize,
    unsigned long  *       pEncodedSize );


RPC_STATUS  __stdcall
MesHandleFree( handle_t  Handle );

RPC_STATUS  __stdcall
MesInqProcEncodingId(
    handle_t                    Handle,
    PRPC_SYNTAX_IDENTIFIER      pInterfaceId,
    unsigned long  *   pProcNum );


#if defined(_MIPS_) || defined(_ALPHA_) || defined(_PPC_)
#define __RPC_UNALIGNED   __unaligned
#else
#define __RPC_UNALIGNED
#endif

void  __stdcall    I_NdrMesMessageInit( PMIDL_STUB_MESSAGE );

size_t  __stdcall
NdrMesSimpleTypeAlignSize ( handle_t );

void  __stdcall
NdrMesSimpleTypeDecode(
    handle_t            Handle,
    void  *    pObject,
    short               Size );

void  __stdcall
NdrMesSimpleTypeEncode(
    handle_t            Handle,
    PMIDL_STUB_DESC     pStubDesc,
    void  *    pObject,
    short               Size );


size_t  __stdcall
NdrMesTypeAlignSize(
    handle_t            Handle,
    PMIDL_STUB_DESC     pStubDesc,
    PFORMAT_STRING      pFormatString,
    void  *    pObject );

void  __stdcall
NdrMesTypeEncode(
    handle_t            Handle,
    PMIDL_STUB_DESC     pStubDesc,
    PFORMAT_STRING      pFormatString,
    void  *    pObject );

void  __stdcall
NdrMesTypeDecode(
    handle_t            Handle,
    PMIDL_STUB_DESC     pStubDesc,
    PFORMAT_STRING      pFormatString,
    void  *    pObject );

void  RPC_VAR_ENTRY
NdrMesProcEncodeDecode(
    handle_t            Handle,
    PMIDL_STUB_DESC     pStubDesc,
    PFORMAT_STRING      pFormatString,
    ... );


#ifdef __cplusplus
}
#endif

// Reset the packing level for DOS and Windows.

#if defined(__RPC_DOS__) || defined(__RPC_WIN16__)
#pragma pack()
#endif

#endif /* __MIDLES_H__ */
