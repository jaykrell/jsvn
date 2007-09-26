/*++

Copyright (c) 1992-1996 Microsoft Corporation

Module Name:

    rpcndr.h

Abstract:

    Definitions for stub data structures and prototypes of helper functions.

Author:

    DonnaLi (01-01-91)

Environment:

    DOS, Win 3.X, and Win/NT.

Revision History:

   DONNALI  08-29-91     Start recording history
   donnali  09-11-91     change conversion macros
   donnali  09-18-91     check in files for moving
   STEVEZ   10-15-91     Merge with NT tree
   donnali  10-28-91     add prototype
   donnali  11-19-91     bugfix for strings
   MIKEMON  12-17-91     DCE runtime API conversion
   donnali  03-24-92     change rpc public header f
   STEVEZ   04-04-92     add nsi include
   mikemon  04-18-92     security support and misc
   DovhH    04-24-24     Changed signature of <int>_from_ndr
                         (to unsigned <int>)
                         Added <base_type>_array_from_ndr routines
   RyszardK 06-17-93     Added support for hyper
   VibhasC  09-11-93     Created rpcndrn.h
   DKays    10-14-93     Fixed up rpcndrn.h MIDL 2.0
   RyszardK 01-15-94     Merged in the midl 2.0 changes from rpcndrn.h
   Stevebl  04-22-96     Hookole support changes to MIDL_*_INFO

--*/

#ifndef __RPCNDR_H__
#define __RPCNDR_H__

//
// Set the packing level for RPC structures for Dos, Windows and Mac.
//

#if defined(__RPC_DOS__) || defined(__RPC_WIN16__) || defined(__RPC_MAC__)
#pragma pack(2)
#endif

#if defined(__RPC_MAC__)
#define _MAC_
#endif

#include <rpcnsip.h>

#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************

     Network Computing Architecture (NCA) definition:

     Network Data Representation: (NDR) Label format:
     An unsigned long (32 bits) with the following layout:

     3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
     1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
    +---------------+---------------+---------------+-------+-------+
    |   Reserved    |   Reserved    |Floating point | Int   | Char  |
    |               |               |Representation | Rep.  | Rep.  |
    +---------------+---------------+---------------+-------+-------+

     Where

         Reserved:

             Must be zero (0) for NCA 1.5 and NCA 2.0.

         Floating point Representation is:

             0 - IEEE
             1 - VAX
             2 - Cray
             3 - IBM

         Int Rep. is Integer Representation:

             0 - Big Endian
             1 - Little Endian

         Char Rep. is Character Representation:

             0 - ASCII
             1 - EBCDIC

     The Microsoft Local Data Representation (for all platforms which are
     of interest currently is edefined below:

 ****************************************************************************/

#define NDR_CHAR_REP_MASK               (unsigned long)0X0000000FL
#define NDR_INT_REP_MASK                (unsigned long)0X000000F0L
#define NDR_FLOAT_REP_MASK              (unsigned long)0X0000FF00L

#define NDR_LITTLE_ENDIAN               (unsigned long)0X00000010L
#define NDR_BIG_ENDIAN                  (unsigned long)0X00000000L

#define NDR_IEEE_FLOAT                  (unsigned long)0X00000000L
#define NDR_VAX_FLOAT                   (unsigned long)0X00000100L

#define NDR_ASCII_CHAR                  (unsigned long)0X00000000L
#define NDR_EBCDIC_CHAR                 (unsigned long)0X00000001L

#if defined(__RPC_MAC__)
#define NDR_LOCAL_DATA_REPRESENTATION   (unsigned long)0X00000000L
#define NDR_LOCAL_ENDIAN                NDR_BIG_ENDIAN
#else
#define NDR_LOCAL_DATA_REPRESENTATION   (unsigned long)0X00000010L
#define NDR_LOCAL_ENDIAN                NDR_LITTLE_ENDIAN
#endif


/****************************************************************************
 *  Macros for targeted platforms
 ****************************************************************************/

#if (0x500 <= _WIN32_WINNT)
#define TARGET_IS_NT50_OR_LATER                   1
#else
#define TARGET_IS_NT50_OR_LATER                   0
#endif

#if (defined(_WIN32_DCOM) || 0x400 <= _WIN32_WINNT)
#define TARGET_IS_NT40_OR_LATER                   1
#else
#define TARGET_IS_NT40_OR_LATER                   0
#endif

#if (0x400 <= WINVER)
#define TARGET_IS_NT351_OR_WIN95_OR_LATER         1
#else
#define TARGET_IS_NT351_OR_WIN95_OR_LATER         0
#endif

/****************************************************************************
 *  Other MIDL base types / predefined types:
 ****************************************************************************/

#define small char
typedef unsigned char byte;
typedef unsigned char boolean;

#ifndef _HYPER_DEFINED
#define _HYPER_DEFINED

#if !defined(__RPC_DOS__) && !defined(__RPC_WIN16__) && !defined(__RPC_MAC__) && (!defined(_M_IX86) || (defined(_INTEGRAL_MAX_BITS) && _INTEGRAL_MAX_BITS >= 64))
#define  hyper           __int64
#define MIDL_uhyper  unsigned __int64
#else
typedef double  hyper;
typedef double MIDL_uhyper;
#endif

#endif // _HYPER_DEFINED

#ifndef _WCHAR_T_DEFINED
typedef unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif

#ifndef _SIZE_T_DEFINED
typedef unsigned int size_t;
#define _SIZE_T_DEFINED
#endif

#ifdef __RPC_DOS__
#define __RPC_CALLEE       __far __pascal
#endif

#ifdef __RPC_WIN16__
#define __RPC_CALLEE       __far __pascal __export
#endif

#ifdef __RPC_WIN32__
#if   (_MSC_VER >= 800) || defined(_STDCALL_SUPPORTED)
#define __RPC_CALLEE       __stdcall
#else
#define __RPC_CALLEE
#endif
#endif

#ifdef __RPC_MAC__
#define __RPC_CALLEE __far
#endif

#ifndef __MIDL_USER_DEFINED
#define midl_user_allocate MIDL_user_allocate
#define midl_user_free     MIDL_user_free
#define __MIDL_USER_DEFINED
#endif

void  * __stdcall MIDL_user_allocate(size_t);
void             __stdcall MIDL_user_free( void  * );

#ifdef __RPC_WIN16__
#define RPC_VAR_ENTRY __export __cdecl
#else
#define RPC_VAR_ENTRY __cdecl
#endif


/* winnt only */
#if defined(_M_MRX000) || defined(_M_IX86) || defined(_M_ALPHA)
#define __MIDL_DECLSPEC_DLLIMPORT   __declspec(dllimport)
#define __MIDL_DECLSPEC_DLLEXPORT   __declspec(dllexport)
#else
#define __MIDL_DECLSPEC_DLLIMPORT
#define __MIDL_DECLSPEC_DLLEXPORT
#endif




/****************************************************************************
 * Context handle management related definitions:
 *
 * Client and Server Contexts.
 *
 ****************************************************************************/

typedef void  * NDR_CCONTEXT;

typedef struct
    {
    void  * pad[2];
    void  * userContext;
    }  * NDR_SCONTEXT;

#define NDRSContextValue(hContext) (&(hContext)->userContext)

#define cbNDRContext 20         /* size of context on WIRE */

typedef void (__stdcall  * NDR_RUNDOWN)(void  * context);

typedef struct _SCONTEXT_QUEUE {
    unsigned long   NumberOfObjects;
    NDR_SCONTEXT  * ArrayOfObjects;
    } SCONTEXT_QUEUE,  * PSCONTEXT_QUEUE;

RPC_BINDING_HANDLE __stdcall
NDRCContextBinding (
    IN NDR_CCONTEXT CContext
    );

void __stdcall
NDRCContextMarshall (
        IN  NDR_CCONTEXT CContext,
        OUT void  *pBuff
        );

void __stdcall
NDRCContextUnmarshall (
        OUT NDR_CCONTEXT  *pCContext,
        IN  RPC_BINDING_HANDLE hBinding,
        IN  void  *pBuff,
        IN  unsigned long DataRepresentation
        );

void __stdcall
NDRSContextMarshall (
        IN  NDR_SCONTEXT CContext,
        OUT void  *pBuff,
        IN  NDR_RUNDOWN userRunDownIn
        );

NDR_SCONTEXT __stdcall
NDRSContextUnmarshall (
    IN  void  *pBuff,
    IN  unsigned long DataRepresentation
    );

void __stdcall
RpcSsDestroyClientContext (
    IN void  *  * ContextHandle
    );


/****************************************************************************
    NDR conversion related definitions.
 ****************************************************************************/

#define byte_from_ndr(source, target) \
    { \
    *(target) = *(*(char  *  *)&(source)->Buffer)++; \
    }

#define byte_array_from_ndr(Source, LowerIndex, UpperIndex, Target) \
    { \
    NDRcopy ( \
        (((char  *)(Target))+(LowerIndex)), \
        (Source)->Buffer, \
        (unsigned int)((UpperIndex)-(LowerIndex))); \
    *(unsigned long  *)&(Source)->Buffer += ((UpperIndex)-(LowerIndex)); \
    }

#define boolean_from_ndr(source, target) \
    { \
    *(target) = *(*(char  *  *)&(source)->Buffer)++; \
    }

#define boolean_array_from_ndr(Source, LowerIndex, UpperIndex, Target) \
    { \
    NDRcopy ( \
        (((char  *)(Target))+(LowerIndex)), \
        (Source)->Buffer, \
        (unsigned int)((UpperIndex)-(LowerIndex))); \
    *(unsigned long  *)&(Source)->Buffer += ((UpperIndex)-(LowerIndex)); \
    }

#define small_from_ndr(source, target) \
    { \
    *(target) = *(*(char  *  *)&(source)->Buffer)++; \
    }

#define small_from_ndr_temp(source, target, format) \
    { \
    *(target) = *(*(char  *  *)(source))++; \
    }

#define small_array_from_ndr(Source, LowerIndex, UpperIndex, Target) \
    { \
    NDRcopy ( \
        (((char  *)(Target))+(LowerIndex)), \
        (Source)->Buffer, \
        (unsigned int)((UpperIndex)-(LowerIndex))); \
    *(unsigned long  *)&(Source)->Buffer += ((UpperIndex)-(LowerIndex)); \
    }

/****************************************************************************
    Platform specific mapping of c-runtime functions.
 ****************************************************************************/

#ifdef __RPC_DOS__
#define MIDL_ascii_strlen(string) \
    _fstrlen(string)
#define MIDL_ascii_strcpy(target,source) \
    _fstrcpy(target,source)
#define MIDL_memset(s,c,n) \
    _fmemset(s,c,n)
#endif

#ifdef __RPC_WIN16__
#define MIDL_ascii_strlen(string) \
    _fstrlen(string)
#define MIDL_ascii_strcpy(target,source) \
    _fstrcpy(target,source)
#define MIDL_memset(s,c,n) \
    _fmemset(s,c,n)
#endif

#if defined(__RPC_WIN32__) || defined(__RPC_MAC__)
#define MIDL_ascii_strlen(string) \
    strlen(string)
#define MIDL_ascii_strcpy(target,source) \
    strcpy(target,source)
#define MIDL_memset(s,c,n) \
    memset(s,c,n)
#endif

/****************************************************************************
    Ndr Library helper function prototypes for MIDL 1.0 ndr functions.
 ****************************************************************************/

void __stdcall
NDRcopy (
    IN void  *pTarget,
    IN void  *pSource,
    IN unsigned int size
    );

size_t __stdcall
MIDL_wchar_strlen (
    IN wchar_t  *   s
    );

void __stdcall
MIDL_wchar_strcpy (
    OUT void  *     t,
    IN wchar_t  *   s
    );

void __stdcall
char_from_ndr (
    IN OUT PRPC_MESSAGE                           SourceMessage,
    OUT unsigned char  *                 Target
    );

void __stdcall
char_array_from_ndr (
    IN OUT PRPC_MESSAGE                           SourceMessage,
    IN unsigned long                              LowerIndex,
    IN unsigned long                              UpperIndex,
    OUT unsigned char  *                 Target
    );

void __stdcall
short_from_ndr (
    IN OUT PRPC_MESSAGE                           source,
    OUT unsigned short  *                target
    );

void __stdcall
short_array_from_ndr(
    IN OUT PRPC_MESSAGE                           SourceMessage,
    IN unsigned long                              LowerIndex,
    IN unsigned long                              UpperIndex,
    OUT unsigned short  *                Target
    );

void __stdcall
short_from_ndr_temp (
    IN OUT unsigned char  *  *  source,
    OUT unsigned short  *                target,
    IN unsigned long                              format
    );

void __stdcall
long_from_ndr (
    IN OUT PRPC_MESSAGE                           source,
    OUT unsigned long  *                 target
    );

void __stdcall
long_array_from_ndr(
    IN OUT PRPC_MESSAGE                           SourceMessage,
    IN unsigned long                              LowerIndex,
    IN unsigned long                              UpperIndex,
    OUT unsigned long  *                 Target
    );

void __stdcall
long_from_ndr_temp (
    IN OUT unsigned char  *  *  source,
    OUT unsigned long  *                 target,
    IN unsigned long                              format
    );

void __stdcall
enum_from_ndr(
    IN OUT PRPC_MESSAGE                           SourceMessage,
    OUT unsigned int  *                  Target
    );

void __stdcall
float_from_ndr (
    IN OUT PRPC_MESSAGE                           SourceMessage,
    OUT void  *                          Target
    );

void __stdcall
float_array_from_ndr (
    IN OUT PRPC_MESSAGE                           SourceMessage,
    IN unsigned long                              LowerIndex,
    IN unsigned long                              UpperIndex,
    OUT void  *                          Target
    );

void __stdcall
double_from_ndr (
    IN OUT PRPC_MESSAGE                           SourceMessage,
    OUT void  *                          Target
    );

void __stdcall
double_array_from_ndr (
    IN OUT PRPC_MESSAGE                           SourceMessage,
    IN unsigned long                              LowerIndex,
    IN unsigned long                              UpperIndex,
    OUT void  *                          Target
    );

void __stdcall
hyper_from_ndr (
    IN OUT PRPC_MESSAGE                           source,
    OUT    hyper  *                      target
    );

void __stdcall
hyper_array_from_ndr(
    IN OUT PRPC_MESSAGE                           SourceMessage,
    IN unsigned long                              LowerIndex,
    IN unsigned long                              UpperIndex,
    OUT          hyper  *                Target
    );

void __stdcall
hyper_from_ndr_temp (
    IN OUT unsigned char  *  *  source,
    OUT             hyper  *             target,
    IN   unsigned   long                          format
    );

void __stdcall
data_from_ndr (
    PRPC_MESSAGE                                  source,
    void  *                              target,
    char  *                              format,
    unsigned char                                 MscPak
    );

void __stdcall
data_into_ndr (
    void  *                              source,
    PRPC_MESSAGE                                  target,
    char  *                              format,
    unsigned char                                 MscPak
    );

void __stdcall
tree_into_ndr (
    void  *                              source,
    PRPC_MESSAGE                                  target,
    char  *                              format,
    unsigned char                                 MscPak
    );

void __stdcall
data_size_ndr (
    void  *                              source,
    PRPC_MESSAGE                                  target,
    char  *                              format,
    unsigned char                                 MscPak
    );

void __stdcall
tree_size_ndr (
    void  *                              source,
    PRPC_MESSAGE                                  target,
    char  *                              format,
    unsigned char                                 MscPak
    );

void __stdcall
tree_peek_ndr (
    PRPC_MESSAGE                                  source,
    unsigned char  *  *         buffer,
    char  *                              format,
    unsigned char                                 MscPak
    );

void  * __stdcall
midl_allocate (
    size_t      size
    );

/****************************************************************************
    MIDL 2.0 ndr definitions.
 ****************************************************************************/

typedef unsigned long error_status_t;

#define _midl_ma1( p, cast )    *(*( cast **)&p)++
#define _midl_ma2( p, cast )    *(*( cast **)&p)++
#define _midl_ma4( p, cast )    *(*( cast **)&p)++
#define _midl_ma8( p, cast )    *(*( cast **)&p)++

#define _midl_unma1( p, cast )  *(( cast *)p)++
#define _midl_unma2( p, cast )  *(( cast *)p)++
#define _midl_unma3( p, cast )  *(( cast *)p)++
#define _midl_unma4( p, cast )  *(( cast *)p)++

// Some alignment specific macros.


#define _midl_fa2( p )          (p = (RPC_BUFPTR )((unsigned long)(p+1) & 0xfffffffe))
#define _midl_fa4( p )          (p = (RPC_BUFPTR )((unsigned long)(p+3) & 0xfffffffc))
#define _midl_fa8( p )          (p = (RPC_BUFPTR )((unsigned long)(p+7) & 0xfffffff8))

#define _midl_addp( p, n )      (p += n)

// Marshalling macros

#define _midl_marsh_lhs( p, cast )  *(*( cast **)&p)++
#define _midl_marsh_up( mp, p )     *(*(unsigned long **)&mp)++ = (unsigned long)p
#define _midl_advmp( mp )           *(*(unsigned long **)&mp)++
#define _midl_unmarsh_up( p )       (*(*(unsigned long **)&p)++)


////////////////////////////////////////////////////////////////////////////
// Ndr macros.
////////////////////////////////////////////////////////////////////////////

#define NdrMarshConfStringHdr( p, s, l )    (_midl_ma4( p, unsigned long) = s, \
                                            _midl_ma4( p, unsigned long) = 0, \
                                            _midl_ma4( p, unsigned long) = l)

#define NdrUnMarshConfStringHdr(p, s, l)    ((s=_midl_unma4(p,unsigned long),\
                                            (_midl_addp(p,4)),               \
                                            (l=_midl_unma4(p,unsigned long))

#define NdrMarshCCtxtHdl(pc,p)  (NDRCContextMarshall( (NDR_CCONTEXT)pc, p ),p+20)

#define NdrUnMarshCCtxtHdl(pc,p,h,drep) \
        (NDRCContextUnmarshall((NDR_CONTEXT)pc,h,p,drep), p+20)

#define NdrUnMarshSCtxtHdl(pc, p,drep)  (pc = NdrSContextUnMarshall(p,drep ))


#define NdrMarshSCtxtHdl(pc,p,rd)   (NdrSContextMarshall((NDR_SCONTEXT)pc,p, (NDR_RUNDOWN)rd)

#define NdrFieldOffset(s,f)     (long)(& (((s  *)0)->f))
#define NdrFieldPad(s,f,p,t)    (NdrFieldOffset(s,f) - NdrFieldOffset(s,p) - sizeof(t))

#if defined(__RPC_MAC__)
#define NdrFcShort(s)   (unsigned char)(s >> 8), (unsigned char)(s & 0xff)
#define NdrFcLong(s)    (unsigned char)(s >> 24), (unsigned char)((s & 0x00ff0000) >> 16), \
                        (unsigned char)((s & 0x0000ff00) >> 8), (unsigned char)(s & 0xff)
#else
#define NdrFcShort(s)   (unsigned char)(s & 0xff), (unsigned char)(s >> 8)
#define NdrFcLong(s)    (unsigned char)(s & 0xff), (unsigned char)((s & 0x0000ff00) >> 8), \
                        (unsigned char)((s & 0x00ff0000) >> 16), (unsigned char)(s >> 24)
#endif //  Mac

//
// On the server side, the following exceptions are mapped to
// the bad stub data exception if -error stub_data is used.
//

#define RPC_BAD_STUB_DATA_EXCEPTION_FILTER  \
                 ( (RpcExceptionCode() == STATUS_ACCESS_VIOLATION)  || \
                   (RpcExceptionCode() == STATUS_DATATYPE_MISALIGNMENT) || \
                   (RpcExceptionCode() == RPC_X_BAD_STUB_DATA) )

/////////////////////////////////////////////////////////////////////////////
// Some stub helper functions.
/////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// Stub helper structures.
////////////////////////////////////////////////////////////////////////////

struct _MIDL_STUB_MESSAGE;
struct _MIDL_STUB_DESC;
struct _FULL_PTR_XLAT_TABLES;

typedef unsigned char  * RPC_BUFPTR;
typedef unsigned long             RPC_LENGTH;

// Expression evaluation callback routine prototype.
typedef void (__stdcall  * EXPR_EVAL)( struct _MIDL_STUB_MESSAGE  * );

typedef const unsigned char  * PFORMAT_STRING;

/*
 * Multidimensional conformant/varying array struct.
 */
typedef struct
    {
    long                            Dimension;

    /* These fields MUST be (unsigned long *) */
    unsigned long  *       BufferConformanceMark;
    unsigned long  *       BufferVarianceMark;

    /* Count arrays, used for top level arrays in -Os stubs */
    unsigned long  *       MaxCountArray;
    unsigned long  *       OffsetArray;
    unsigned long  *       ActualCountArray;
    } ARRAY_INFO,  *PARRAY_INFO;

/*
 *  Pipe related definitions.
 */

typedef void
( __stdcall * NDR_PIPE_PULL_RTN)(
        char           *  state,
        void           *  buf,
        unsigned long              esize,
        unsigned long  *  ecount );

typedef void
( __stdcall * NDR_PIPE_PUSH_RTN)(
        char           *  state,
        void           *  buf,
        unsigned long              ecount );

typedef void
( __stdcall * NDR_PIPE_ALLOC_RTN)(
        char              *  state,
        unsigned long                 bsize,
        void  *  *  buf,
        unsigned long     *  bcount );


typedef struct  _GENERIC_PIPE_TYPE
    {
    NDR_PIPE_PULL_RTN       pfnPull;
    NDR_PIPE_PUSH_RTN       pfnPush;
    NDR_PIPE_ALLOC_RTN      pfnAlloc;
    char   *       pState;
    } GENERIC_PIPE_TYPE;

typedef struct _NDR_PIPE_DESC *       PNDR_PIPE_DESC;
typedef struct _NDR_PIPE_MESSAGE *    PNDR_PIPE_MESSAGE;


/*
 * MIDL Stub Message
 */
#if !defined(__RPC_DOS__) && !defined(__RPC_WIN16__) && !defined(__RPC_MAC__)
#include <pshpack4.h>
#endif

typedef struct _MIDL_STUB_MESSAGE
    {
    /* RPC message structure. */
    PRPC_MESSAGE                RpcMsg;

    /* Pointer into RPC message buffer. */
    unsigned char  *   Buffer;

    /*
     * These are used internally by the Ndr routines to mark the beginning
     * and end of an incoming RPC buffer.
     */
    unsigned char  *   BufferStart;
    unsigned char  *   BufferEnd;

    /*
     * Used internally by the Ndr routines as a place holder in the buffer.
     * On the marshalling side it's used to mark the location where conformance
     * size should be marshalled.
     * On the unmarshalling side it's used to mark the location in the buffer
     * used during pointer unmarshalling to base pointer offsets off of.
     */
    unsigned char  *   BufferMark;

    /* Set by the buffer sizing routines. */
    unsigned long               BufferLength;

    /* Set by the memory sizing routines. */
    unsigned long               MemorySize;

    /* Pointer to user memory. */
    unsigned char  *   Memory;

    /* Is the Ndr routine begin called from a client side stub. */
    int                         IsClient;

    /* Can the buffer be re-used for memory on unmarshalling. */
    int                         ReuseBuffer;

    /* Holds the current pointer to an allocate all nodes memory block. */
    unsigned char  *   AllocAllNodesMemory;

    /* Used for debugging asserts only, remove later. */
    unsigned char  *   AllocAllNodesMemoryEnd;

    /*
     * Stuff needed while handling complex structures
     */

    /* Ignore imbeded pointers while computing buffer or memory sizes. */
    int                         IgnoreEmbeddedPointers;

    /*
     * This marks the location in the buffer where pointees of a complex
     * struct reside.
     */
    unsigned char  *   PointerBufferMark;

    /*
     * Used to catch errors in SendReceive.
     */
    unsigned char               fBufferValid;

    /*
     * Obsolete unused field (formerly MaxContextHandleNumber).
     */
    unsigned char               Unused;

    /*
     * Used internally by the Ndr routines.  Holds the max counts for
     * a conformant array.
     */
    unsigned long               MaxCount;

    /*
     * Used internally by the Ndr routines.  Holds the offsets for a varying
     * array.
     */
    unsigned long               Offset;

    /*
     * Used internally by the Ndr routines.  Holds the actual counts for
     * a varying array.
     */
    unsigned long               ActualCount;

    /* Allocation and Free routine to be used by the Ndr routines. */
    void  *    ( __stdcall * pfnAllocate)(size_t);
    void                ( __stdcall * pfnFree)(void  *);

    /*
     * Top of parameter stack.  Used for "single call" stubs during marshalling
     * to hold the beginning of the parameter list on the stack.  Needed to
     * extract parameters which hold attribute values for top level arrays and
     * pointers.
     */
    unsigned char  *       StackTop;

    /*
     *  Fields used for the transmit_as and represent_as objects.
     *  For represent_as the mapping is: presented=local, transmit=named.
     */
    unsigned char  *       pPresentedType;
    unsigned char  *       pTransmitType;

    /*
     * When we first construct a binding on the client side, stick it
     * in the rpcmessage and later call RpcGetBuffer, the handle field
     * in the rpcmessage is changed. That's fine except that we need to
     * have that original handle for use in unmarshalling context handles
     * (the second argument in NDRCContextUnmarshall to be exact). So
     * stash the contructed handle here and extract it when needed.
     */
    handle_t                        SavedHandle;

    /*
     * Pointer back to the stub descriptor.  Use this to get all handle info.
     */
    const struct _MIDL_STUB_DESC  *    StubDesc;

    /*
     * Full pointer stuff.
     */
    struct _FULL_PTR_XLAT_TABLES  *    FullPtrXlatTables;

    unsigned long                   FullPtrRefId;

    /*
     * flags
     */

    int                             fCheckBounds;

    int                             fInDontFree       :1;
    int                             fDontCallFreeInst :1;
    int                             fInOnlyParam      :1;
    int                             fHasReturn        :1;

    unsigned long                   dwDestContext;
    void  *                pvDestContext;

    NDR_SCONTEXT *                  SavedContextHandles;

    long                            ParamNumber;

    struct IRpcChannelBuffer  *    pRpcChannelBuffer;

    PARRAY_INFO                     pArrayInfo;

    /*
     * This is where the Beta2 stub message ends.
     */

    unsigned long  *       SizePtrCountArray;
    unsigned long  *       SizePtrOffsetArray;
    unsigned long  *       SizePtrLengthArray;

    /*
     * Interpreter argument queue.  Used on server side only.
     */
    void  *                pArgQueue;

    unsigned long                   dwStubPhase;

    /*
     * Pipe descriptor, defined for the 4.0 release.
     */

    PNDR_PIPE_DESC                  pPipeDesc;

    unsigned long                   Reserved[4];

    /*
     *  Fields up to this point present since the 3.50 release.
     */

    } MIDL_STUB_MESSAGE,  *PMIDL_STUB_MESSAGE;

#if !defined(__RPC_DOS__) && !defined(__RPC_WIN16__) && !defined(__RPC_MAC__)
#include <poppack.h>
#endif

/*
 * Generic handle bind/unbind routine pair.
 */
typedef void  *
        ( __stdcall * GENERIC_BINDING_ROUTINE)
        (void  *);
typedef void
        ( __stdcall * GENERIC_UNBIND_ROUTINE)
        (void  *, unsigned char  *);

typedef struct _GENERIC_BINDING_ROUTINE_PAIR
    {
    GENERIC_BINDING_ROUTINE     pfnBind;
    GENERIC_UNBIND_ROUTINE      pfnUnbind;
    } GENERIC_BINDING_ROUTINE_PAIR,  *PGENERIC_BINDING_ROUTINE_PAIR;

typedef struct __GENERIC_BINDING_INFO
    {
    void  *            pObj;
    unsigned int                Size;
    GENERIC_BINDING_ROUTINE     pfnBind;
    GENERIC_UNBIND_ROUTINE      pfnUnbind;
    } GENERIC_BINDING_INFO,  *PGENERIC_BINDING_INFO;

// typedef EXPR_EVAL - see above
// typedefs for xmit_as

#if (defined(_MSC_VER)) && !defined(MIDL_PASS)
// a Microsoft C++ compiler
#define NDR_SHAREABLE __inline
#else
#define NDR_SHAREABLE static
#endif


typedef void ( __stdcall * XMIT_HELPER_ROUTINE)
    ( PMIDL_STUB_MESSAGE );

typedef struct _XMIT_ROUTINE_QUINTUPLE
    {
    XMIT_HELPER_ROUTINE     pfnTranslateToXmit;
    XMIT_HELPER_ROUTINE     pfnTranslateFromXmit;
    XMIT_HELPER_ROUTINE     pfnFreeXmit;
    XMIT_HELPER_ROUTINE     pfnFreeInst;
    } XMIT_ROUTINE_QUINTUPLE,  *PXMIT_ROUTINE_QUINTUPLE;

typedef unsigned long
( __stdcall * USER_MARSHAL_SIZING_ROUTINE)
    (unsigned long  *,
     unsigned long,
     void  * );

typedef unsigned char  *
( __stdcall * USER_MARSHAL_MARSHALLING_ROUTINE)
    (unsigned long  *,
     unsigned char   * ,
     void  * );

typedef unsigned char  *
( __stdcall * USER_MARSHAL_UNMARSHALLING_ROUTINE)
    (unsigned long  *,
     unsigned char   * ,
     void  * );

typedef void ( __stdcall * USER_MARSHAL_FREEING_ROUTINE)
    (unsigned long  *,
     void  * );

typedef struct _USER_MARSHAL_ROUTINE_QUADRUPLE
    {
    USER_MARSHAL_SIZING_ROUTINE          pfnBufferSize;
    USER_MARSHAL_MARSHALLING_ROUTINE     pfnMarshall;
    USER_MARSHAL_UNMARSHALLING_ROUTINE   pfnUnmarshall;
    USER_MARSHAL_FREEING_ROUTINE         pfnFree;
    } USER_MARSHAL_ROUTINE_QUADRUPLE;

typedef struct _USER_MARSHAL_CB
{
    unsigned long       Flags;
    PMIDL_STUB_MESSAGE  pStubMsg;
    PFORMAT_STRING      pReserve;
} USER_MARSHAL_CB;


#define USER_CALL_CTXT_MASK(f)	((f) & 0xff)
#define GET_USER_DATA_REP(f)    ((f) >> 16)

typedef struct _MALLOC_FREE_STRUCT
    {
    void  *	( __stdcall * pfnAllocate)(size_t);
    void                ( __stdcall * pfnFree)(void  *);
    } MALLOC_FREE_STRUCT;

typedef struct _COMM_FAULT_OFFSETS
    {
    short       CommOffset;
    short       FaultOffset;
    } COMM_FAULT_OFFSETS;

/*
 * MIDL Stub Descriptor
 */

typedef struct _MIDL_STUB_DESC
    {

    void  *    RpcInterfaceInformation;

    void  *    ( __stdcall * pfnAllocate)(size_t);
    void                ( __stdcall * pfnFree)(void  *);

    union
        {
        handle_t  *            pAutoHandle;
        handle_t  *            pPrimitiveHandle;
        PGENERIC_BINDING_INFO           pGenericBindingInfo;
        } IMPLICIT_HANDLE_INFO;

    const NDR_RUNDOWN  *                   apfnNdrRundownRoutines;
    const GENERIC_BINDING_ROUTINE_PAIR  *  aGenericBindingRoutinePairs;

    const EXPR_EVAL  *                     apfnExprEval;

    const XMIT_ROUTINE_QUINTUPLE  *        aXmitQuintuple;

    const unsigned char  *                 pFormatTypes;

    int                                             fCheckBounds;

    /* Ndr library version. */
    unsigned long                                   Version;

    /*
     * Reserved for future use. (no reserves )
     */

    MALLOC_FREE_STRUCT  *                  pMallocFreeStruct;

    long                                MIDLVersion;

    const COMM_FAULT_OFFSETS  *    CommFaultOffsets;

    // New fields for version 3.0+

    const USER_MARSHAL_ROUTINE_QUADRUPLE  * aUserMarshalQuadruple;

    long                                    Reserved1;
    long                                    Reserved2;
    long                                    Reserved3;
    long                                    Reserved4;
    long                                    Reserved5;

    } MIDL_STUB_DESC;

typedef const MIDL_STUB_DESC  * PMIDL_STUB_DESC;

typedef void  * PMIDL_XMIT_TYPE;

/*
 * MIDL Stub Format String.  This is a const in the stub.
 */
#if !defined( RC_INVOKED )
#pragma warning( disable:4200 )
#endif
typedef struct _MIDL_FORMAT_STRING
    {
    short               Pad;
    unsigned char       Format[];
    } MIDL_FORMAT_STRING;
#if !defined( RC_INVOKED )
#pragma warning( default:4200 )
#endif

/*
 * Stub thunk used for some interpreted server stubs.
 */
typedef void ( __stdcall * STUB_THUNK)( PMIDL_STUB_MESSAGE );

typedef long ( __stdcall * SERVER_ROUTINE)();

/*
 * Server Interpreter's information strucuture.
 */
typedef struct  _MIDL_SERVER_INFO_
    {
    PMIDL_STUB_DESC             pStubDesc;
    const SERVER_ROUTINE *      DispatchTable;
    PFORMAT_STRING              ProcString;
    const unsigned short *      FmtStringOffset;
    const STUB_THUNK *          ThunkTable;
    PFORMAT_STRING              LocalFormatTypes;
    PFORMAT_STRING              LocalProcString;
    const unsigned short *      LocalFmtStringOffset;
    } MIDL_SERVER_INFO, *PMIDL_SERVER_INFO;

/*
 * Stubless object proxy information structure.
 */
typedef struct _MIDL_STUBLESS_PROXY_INFO
    {
    PMIDL_STUB_DESC                     pStubDesc;
    PFORMAT_STRING                      ProcFormatString;
    const unsigned short  *    FormatStringOffset;
    PFORMAT_STRING                      LocalFormatTypes;
    PFORMAT_STRING                      LocalProcString;
    const unsigned short  *    LocalFmtStringOffset;
    } MIDL_STUBLESS_PROXY_INFO;

typedef MIDL_STUBLESS_PROXY_INFO  * PMIDL_STUBLESS_PROXY_INFO;

/*
 * This is the return value from NdrClientCall.
 */
typedef union _CLIENT_CALL_RETURN
    {
    void  *        Pointer;
    long                    Simple;
    } CLIENT_CALL_RETURN;

/*
 * Full pointer data structures.
 */

typedef enum
        {
        XLAT_SERVER = 1,
        XLAT_CLIENT
        } XLAT_SIDE;

/*
 * Stores the translation for the conversion from a full pointer into it's
 * corresponding ref id.
 */
typedef struct _FULL_PTR_TO_REFID_ELEMENT
    {
    struct _FULL_PTR_TO_REFID_ELEMENT  *  Next;

    void  *            Pointer;
    unsigned long       RefId;
    unsigned char       State;
    } FULL_PTR_TO_REFID_ELEMENT,  *PFULL_PTR_TO_REFID_ELEMENT;

/*
 * Full pointer translation tables.
 */
typedef struct _FULL_PTR_XLAT_TABLES
    {
    /*
     * Ref id to pointer translation information.
     */
    struct
        {
        void  * *             XlatTable;
        unsigned char  *     StateTable;
        unsigned long       NumberOfEntries;
        } RefIdToPointer;

    /*
     * Pointer to ref id translation information.
     */
    struct
        {
        PFULL_PTR_TO_REFID_ELEMENT  *  XlatTable;
        unsigned long                   NumberOfBuckets;
        unsigned long                   HashMask;
        } PointerToRefId;

    /*
     * Next ref id to use.
     */
    unsigned long           NextRefId;

    /*
     * Keep track of the translation size we're handling : server or client.
     * This tells us when we have to do reverse translations when we insert
     * new translations.  On the server we must insert a pointer-to-refid
     * translation whenever we insert a refid-to-pointer translation, and
     * vica versa for the client.
     */
    XLAT_SIDE               XlatSide;
    } FULL_PTR_XLAT_TABLES,  *PFULL_PTR_XLAT_TABLES;

/***************************************************************************
 ** New MIDL 2.0 Ndr routine templates
 ***************************************************************************/

/*
 * Marshall routines
 */

void __stdcall
NdrSimpleTypeMarshall(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *                       pMemory,
    unsigned char                       FormatChar
    );

unsigned char  * __stdcall
NdrPointerMarshall(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

/* Structures */

unsigned char  * __stdcall
NdrSimpleStructMarshall(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

unsigned char  * __stdcall
NdrConformantStructMarshall(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

unsigned char  * __stdcall
NdrConformantVaryingStructMarshall(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

unsigned char  * __stdcall
NdrHardStructMarshall(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

unsigned char  * __stdcall
NdrComplexStructMarshall(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

/* Arrays */

unsigned char  * __stdcall
NdrFixedArrayMarshall(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

unsigned char  * __stdcall
NdrConformantArrayMarshall(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

unsigned char  * __stdcall
NdrConformantVaryingArrayMarshall(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

unsigned char  * __stdcall
NdrVaryingArrayMarshall(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

unsigned char  * __stdcall
NdrComplexArrayMarshall(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

/* Strings */

unsigned char  * __stdcall
NdrNonConformantStringMarshall(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

unsigned char  * __stdcall
NdrConformantStringMarshall(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

/* Unions */

unsigned char  * __stdcall
NdrEncapsulatedUnionMarshall(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

unsigned char  * __stdcall
NdrNonEncapsulatedUnionMarshall(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

/* Byte count pointer */

unsigned char  * __stdcall
NdrByteCountPointerMarshall(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

/* Transmit as and represent as*/

unsigned char  * __stdcall
NdrXmitOrRepAsMarshall(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

/* User_marshal */

unsigned char  * __stdcall
NdrUserMarshalMarshall(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

/* Cairo interface pointer */

unsigned char  * __stdcall
NdrInterfacePointerMarshall(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

/* Context handles */

void __stdcall
NdrClientContextMarshall(
    PMIDL_STUB_MESSAGE    pStubMsg,
    NDR_CCONTEXT          ContextHandle,
    int                   fCheck
    );

void __stdcall
NdrServerContextMarshall(
    PMIDL_STUB_MESSAGE    pStubMsg,
    NDR_SCONTEXT          ContextHandle,
    NDR_RUNDOWN           RundownRoutine
    );

/*
 * Unmarshall routines
 */

void __stdcall
NdrSimpleTypeUnmarshall(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    unsigned char                       FormatChar
    );

unsigned char  * __stdcall
NdrPointerUnmarshall(
    PMIDL_STUB_MESSAGE                      pStubMsg,
    unsigned char  *  *   ppMemory,
    PFORMAT_STRING                          pFormat,
    unsigned char                           fMustAlloc
    );

/* Structures */

unsigned char  * __stdcall
NdrSimpleStructUnmarshall(
    PMIDL_STUB_MESSAGE                      pStubMsg,
    unsigned char  *  *   ppMemory,
    PFORMAT_STRING                          pFormat,
    unsigned char                           fMustAlloc
    );

unsigned char  * __stdcall
NdrConformantStructUnmarshall(
    PMIDL_STUB_MESSAGE                      pStubMsg,
    unsigned char  *  *   ppMemory,
    PFORMAT_STRING                          pFormat,
    unsigned char                           fMustAlloc
    );

unsigned char  * __stdcall
NdrConformantVaryingStructUnmarshall(
    PMIDL_STUB_MESSAGE                      pStubMsg,
    unsigned char  *  *   ppMemory,
    PFORMAT_STRING                          pFormat,
    unsigned char                           fMustAlloc
    );

unsigned char  * __stdcall
NdrHardStructUnmarshall(
    PMIDL_STUB_MESSAGE                      pStubMsg,
    unsigned char  *  *   ppMemory,
    PFORMAT_STRING                          pFormat,
    unsigned char                           fMustAlloc
    );

unsigned char  * __stdcall
NdrComplexStructUnmarshall(
    PMIDL_STUB_MESSAGE                      pStubMsg,
    unsigned char  *  *   ppMemory,
    PFORMAT_STRING                          pFormat,
    unsigned char                           fMustAlloc
    );

/* Arrays */

unsigned char  * __stdcall
NdrFixedArrayUnmarshall(
    PMIDL_STUB_MESSAGE                      pStubMsg,
    unsigned char  *  *   ppMemory,
    PFORMAT_STRING                          pFormat,
    unsigned char                           fMustAlloc
    );

unsigned char  * __stdcall
NdrConformantArrayUnmarshall(
    PMIDL_STUB_MESSAGE                      pStubMsg,
    unsigned char  *  *   ppMemory,
    PFORMAT_STRING                          pFormat,
    unsigned char                           fMustAlloc
    );

unsigned char  * __stdcall
NdrConformantVaryingArrayUnmarshall(
    PMIDL_STUB_MESSAGE                      pStubMsg,
    unsigned char  *  *   ppMemory,
    PFORMAT_STRING                          pFormat,
    unsigned char                           fMustAlloc
    );

unsigned char  * __stdcall
NdrVaryingArrayUnmarshall(
    PMIDL_STUB_MESSAGE                      pStubMsg,
    unsigned char  *  *   ppMemory,
    PFORMAT_STRING                          pFormat,
    unsigned char                           fMustAlloc
    );

unsigned char  * __stdcall
NdrComplexArrayUnmarshall(
    PMIDL_STUB_MESSAGE                      pStubMsg,
    unsigned char  *  *   ppMemory,
    PFORMAT_STRING                          pFormat,
    unsigned char                           fMustAlloc
    );

/* Strings */

unsigned char  * __stdcall
NdrNonConformantStringUnmarshall(
    PMIDL_STUB_MESSAGE                      pStubMsg,
    unsigned char  *  *   ppMemory,
    PFORMAT_STRING                          pFormat,
    unsigned char                           fMustAlloc
    );

unsigned char  * __stdcall
NdrConformantStringUnmarshall(
    PMIDL_STUB_MESSAGE                      pStubMsg,
    unsigned char  *  *   ppMemory,
    PFORMAT_STRING                          pFormat,
    unsigned char                           fMustAlloc
    );

/* Unions */

unsigned char  * __stdcall
NdrEncapsulatedUnionUnmarshall(
    PMIDL_STUB_MESSAGE                      pStubMsg,
    unsigned char  *  *   ppMemory,
    PFORMAT_STRING                          pFormat,
    unsigned char                           fMustAlloc
    );

unsigned char  * __stdcall
NdrNonEncapsulatedUnionUnmarshall(
    PMIDL_STUB_MESSAGE                      pStubMsg,
    unsigned char  *  *   ppMemory,
    PFORMAT_STRING                          pFormat,
    unsigned char                           fMustAlloc
    );

/* Byte count pointer */

unsigned char  * __stdcall
NdrByteCountPointerUnmarshall(
    PMIDL_STUB_MESSAGE                      pStubMsg,
    unsigned char  *  *   ppMemory,
    PFORMAT_STRING                          pFormat,
    unsigned char                           fMustAlloc
    );

/* Transmit as and represent as*/

unsigned char  * __stdcall
NdrXmitOrRepAsUnmarshall(
    PMIDL_STUB_MESSAGE                      pStubMsg,
    unsigned char  *  *   ppMemory,
    PFORMAT_STRING                          pFormat,
    unsigned char                           fMustAlloc
    );

/* User_marshal */

unsigned char  * __stdcall
NdrUserMarshalUnmarshall(
    PMIDL_STUB_MESSAGE                      pStubMsg,
    unsigned char  *  *   ppMemory,
    PFORMAT_STRING                          pFormat,
    unsigned char                           fMustAlloc
    );

/* Cairo interface pointer */

unsigned char  * __stdcall
NdrInterfacePointerUnmarshall(
    PMIDL_STUB_MESSAGE                      pStubMsg,
    unsigned char  *  *   ppMemory,
    PFORMAT_STRING                          pFormat,
    unsigned char                           fMustAlloc
    );

/* Context handles */

void __stdcall
NdrClientContextUnmarshall(
    PMIDL_STUB_MESSAGE          pStubMsg,
    NDR_CCONTEXT  *    pContextHandle,
    RPC_BINDING_HANDLE          BindHandle
    );

NDR_SCONTEXT __stdcall
NdrServerContextUnmarshall(
    PMIDL_STUB_MESSAGE          pStubMsg
    );

/*
 * Buffer sizing routines
 */

void __stdcall
NdrPointerBufferSize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

/* Structures */

void __stdcall
NdrSimpleStructBufferSize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

void __stdcall
NdrConformantStructBufferSize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

void __stdcall
NdrConformantVaryingStructBufferSize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

void __stdcall
NdrHardStructBufferSize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

void __stdcall
NdrComplexStructBufferSize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

/* Arrays */

void __stdcall
NdrFixedArrayBufferSize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

void __stdcall
NdrConformantArrayBufferSize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

void __stdcall
NdrConformantVaryingArrayBufferSize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

void __stdcall
NdrVaryingArrayBufferSize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

void __stdcall
NdrComplexArrayBufferSize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

/* Strings */

void __stdcall
NdrConformantStringBufferSize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

void __stdcall
NdrNonConformantStringBufferSize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

/* Unions */

void __stdcall
NdrEncapsulatedUnionBufferSize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

void __stdcall
NdrNonEncapsulatedUnionBufferSize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

/* Byte count pointer */

void __stdcall
NdrByteCountPointerBufferSize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

/* Transmit as and represent as*/

void __stdcall
NdrXmitOrRepAsBufferSize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

/* User_marshal */

void __stdcall
NdrUserMarshalBufferSize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

/* Cairo Interface pointer */

void __stdcall
NdrInterfacePointerBufferSize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

// Context Handle size
//
void __stdcall
NdrContextHandleSize(
    PMIDL_STUB_MESSAGE          pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

/*
 * Memory sizing routines
 */

unsigned long __stdcall
NdrPointerMemorySize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    PFORMAT_STRING                      pFormat
    );

/* Structures */

unsigned long __stdcall
NdrSimpleStructMemorySize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    PFORMAT_STRING                      pFormat
    );

unsigned long __stdcall
NdrConformantStructMemorySize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    PFORMAT_STRING                      pFormat
    );

unsigned long __stdcall
NdrConformantVaryingStructMemorySize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    PFORMAT_STRING                      pFormat
    );

unsigned long __stdcall
NdrHardStructMemorySize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    PFORMAT_STRING                      pFormat
    );

unsigned long __stdcall
NdrComplexStructMemorySize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    PFORMAT_STRING                      pFormat
    );

/* Arrays */

unsigned long __stdcall
NdrFixedArrayMemorySize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    PFORMAT_STRING                      pFormat
    );

unsigned long __stdcall
NdrConformantArrayMemorySize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    PFORMAT_STRING                      pFormat
    );

unsigned long __stdcall
NdrConformantVaryingArrayMemorySize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    PFORMAT_STRING                      pFormat
    );

unsigned long __stdcall
NdrVaryingArrayMemorySize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    PFORMAT_STRING                      pFormat
    );

unsigned long __stdcall
NdrComplexArrayMemorySize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    PFORMAT_STRING                      pFormat
    );

/* Strings */

unsigned long __stdcall
NdrConformantStringMemorySize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    PFORMAT_STRING                      pFormat
    );

unsigned long __stdcall
NdrNonConformantStringMemorySize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    PFORMAT_STRING                      pFormat
    );

/* Unions */

unsigned long __stdcall
NdrEncapsulatedUnionMemorySize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    PFORMAT_STRING                      pFormat
    );

unsigned long __stdcall
NdrNonEncapsulatedUnionMemorySize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    PFORMAT_STRING                      pFormat
    );

/* Transmit as and represent as*/

unsigned long __stdcall
NdrXmitOrRepAsMemorySize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    PFORMAT_STRING                      pFormat
    );

/* User_marshal */

unsigned long __stdcall
NdrUserMarshalMemorySize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    PFORMAT_STRING                      pFormat
    );

/* Cairo Interface pointer */

unsigned long __stdcall
NdrInterfacePointerMemorySize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    PFORMAT_STRING                      pFormat
    );

/*
 * Freeing routines
 */

void __stdcall
NdrPointerFree(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

/* Structures */

void __stdcall
NdrSimpleStructFree(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

void __stdcall
NdrConformantStructFree(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

void __stdcall
NdrConformantVaryingStructFree(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

void __stdcall
NdrHardStructFree(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

void __stdcall
NdrComplexStructFree(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

/* Arrays */

void __stdcall
NdrFixedArrayFree(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

void __stdcall
NdrConformantArrayFree(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

void __stdcall
NdrConformantVaryingArrayFree(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

void __stdcall
NdrVaryingArrayFree(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

void __stdcall
NdrComplexArrayFree(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

/* Unions */

void __stdcall
NdrEncapsulatedUnionFree(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

void __stdcall
NdrNonEncapsulatedUnionFree(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

/* Byte count */

void __stdcall
NdrByteCountPointerFree(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

/* Transmit as and represent as*/

void __stdcall
NdrXmitOrRepAsFree(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

/* User_marshal */

void __stdcall
NdrUserMarshalFree(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

/* Cairo Interface pointer */

void __stdcall
NdrInterfacePointerFree(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pMemory,
    PFORMAT_STRING                      pFormat
    );

/*
 * Endian conversion routine.
 */

void __stdcall
NdrConvert2(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    PFORMAT_STRING                      pFormat,
    long                                NumberParams
    );

void __stdcall
NdrConvert(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    PFORMAT_STRING                      pFormat
    );

#define USER_MARSHAL_FC_BYTE         1
#define USER_MARSHAL_FC_CHAR         2
#define USER_MARSHAL_FC_SMALL        3
#define USER_MARSHAL_FC_USMALL       4
#define USER_MARSHAL_FC_WCHAR        5
#define USER_MARSHAL_FC_SHORT        6
#define USER_MARSHAL_FC_USHORT       7
#define USER_MARSHAL_FC_LONG         8
#define USER_MARSHAL_FC_ULONG        9
#define USER_MARSHAL_FC_FLOAT       10
#define USER_MARSHAL_FC_HYPER       11
#define USER_MARSHAL_FC_DOUBLE      12

unsigned char  * __stdcall
NdrUserMarshalSimpleTypeConvert(
    unsigned long * pFlags,
    unsigned char * pBuffer,
    unsigned char   FormatChar
    );

/*
 * Auxilary routines
 */

void __stdcall
NdrClientInitializeNew(
    PRPC_MESSAGE                        pRpcMsg,
    PMIDL_STUB_MESSAGE                  pStubMsg,
    PMIDL_STUB_DESC                     pStubDescriptor,
    unsigned int                        ProcNum
    );

unsigned char  * __stdcall
NdrServerInitializeNew(
    PRPC_MESSAGE                        pRpcMsg,
    PMIDL_STUB_MESSAGE                  pStubMsg,
    PMIDL_STUB_DESC                     pStubDescriptor
    );

void __stdcall
NdrServerInitializePartial(
    PRPC_MESSAGE                        pRpcMsg,
    PMIDL_STUB_MESSAGE                  pStubMsg,
    PMIDL_STUB_DESC                     pStubDescriptor,
    unsigned long                       RequestedBufferSize
    );

void __stdcall
NdrClientInitialize(
    PRPC_MESSAGE                        pRpcMsg,
    PMIDL_STUB_MESSAGE                  pStubMsg,
    PMIDL_STUB_DESC                     pStubDescriptor,
    unsigned int                        ProcNum
    );

unsigned char  * __stdcall
NdrServerInitialize(
    PRPC_MESSAGE                        pRpcMsg,
    PMIDL_STUB_MESSAGE                  pStubMsg,
    PMIDL_STUB_DESC                     pStubDescriptor
    );

unsigned char  * __stdcall
NdrServerInitializeUnmarshall (
    PMIDL_STUB_MESSAGE                  pStubMsg,
    PMIDL_STUB_DESC                     pStubDescriptor,
    PRPC_MESSAGE                        pRpcMsg
    );

void __stdcall
NdrServerInitializeMarshall (
    PRPC_MESSAGE                        pRpcMsg,
    PMIDL_STUB_MESSAGE                  pStubMsg
    );

unsigned char  * __stdcall
NdrGetBuffer(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned long                       BufferLength,
    RPC_BINDING_HANDLE                  Handle
    );

unsigned char  * __stdcall
NdrNsGetBuffer(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned long                       BufferLength,
    RPC_BINDING_HANDLE                  Handle
    );

unsigned char  * __stdcall
NdrGetPipeBuffer(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned long                       BufferLength,
    RPC_BINDING_HANDLE                  Handle );

void __stdcall
NdrGetPartialBuffer(
    PMIDL_STUB_MESSAGE                  pStubMsg );

unsigned char  * __stdcall
NdrSendReceive(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char *            pBufferEnd
    );

unsigned char  * __stdcall
NdrNsSendReceive(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char  *           pBufferEnd,
    RPC_BINDING_HANDLE  *      pAutoHandle
    );

void  __stdcall
NdrPipeSendReceive(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    PNDR_PIPE_DESC                      pPipeDesc
    );

void __stdcall
NdrFreeBuffer(
    PMIDL_STUB_MESSAGE                  pStubMsg
    );


/*
 * Pipe specific calls
 */

void __stdcall
NdrPipesInitialize(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    PFORMAT_STRING                      pParamDesc,
    PNDR_PIPE_DESC                      pPipeDesc,
    PNDR_PIPE_MESSAGE                   pPipeMsg,
    char              *        pStackTop,
    unsigned long                       NumberParams );

void
NdrMarkNextActivePipe( 
    PNDR_PIPE_DESC                      pPipeDesc,
    unsigned int                        DirectionMask );

void __stdcall
NdrPipePull(
    char           *           pState,
    void           *           buf,
    unsigned long                       esize,
    unsigned long  *           ecount );

void  __stdcall
NdrPipePush(
    char           *           pState,
    void           *           buf,
    unsigned long                       ecount );

void __stdcall
NdrIsAppDoneWithPipes( 
    PNDR_PIPE_DESC                      pPipeDesc
    );

void __stdcall
NdrPipesDone( 
    PMIDL_STUB_MESSAGE                  pStubMsg
    );


/*
 * Interpeter calls.
 */

/* client */

CLIENT_CALL_RETURN RPC_VAR_ENTRY
NdrClientCall2(
    PMIDL_STUB_DESC                     pStubDescriptor,
    PFORMAT_STRING                      pFormat,
    ...
    );

CLIENT_CALL_RETURN RPC_VAR_ENTRY
NdrClientCall(
    PMIDL_STUB_DESC                     pStubDescriptor,
    PFORMAT_STRING                      pFormat,
    ...
    );

/* server */
typedef enum {
    STUB_UNMARSHAL,
    STUB_CALL_SERVER,
    STUB_MARSHAL,
    STUB_CALL_SERVER_NO_HRESULT
}STUB_PHASE;

typedef enum {
    PROXY_CALCSIZE,
    PROXY_GETBUFFER,
    PROXY_MARSHAL,
    PROXY_SENDRECEIVE,
    PROXY_UNMARSHAL
}PROXY_PHASE;

long __stdcall
NdrStubCall2(
    struct IRpcStubBuffer  *    pThis,
    struct IRpcChannelBuffer  * pChannel,
    PRPC_MESSAGE                         pRpcMsg,
    unsigned long  *            pdwStubPhase
    );

void __stdcall
NdrServerCall2(
    PRPC_MESSAGE                         pRpcMsg
    );

long __stdcall
NdrStubCall (
    struct IRpcStubBuffer  *    pThis,
    struct IRpcChannelBuffer  * pChannel,
    PRPC_MESSAGE                         pRpcMsg,
    unsigned long  *            pdwStubPhase
    );

void __stdcall
NdrServerCall(
    PRPC_MESSAGE                        pRpcMsg
    );

int __stdcall
NdrServerUnmarshall(
    struct IRpcChannelBuffer  * pChannel,
    PRPC_MESSAGE                         pRpcMsg,
    PMIDL_STUB_MESSAGE                   pStubMsg,
    PMIDL_STUB_DESC                      pStubDescriptor,
    PFORMAT_STRING                       pFormat,
    void  *                     pParamList
    );

void __stdcall
NdrServerMarshall(
    struct IRpcStubBuffer  *    pThis,
    struct IRpcChannelBuffer  * pChannel,
    PMIDL_STUB_MESSAGE                   pStubMsg,
    PFORMAT_STRING                       pFormat
    );

/* Comm and Fault status */

RPC_STATUS __stdcall
NdrMapCommAndFaultStatus(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned long  *                       pCommStatus,
    unsigned long  *                       pFaultStatus,
    RPC_STATUS                          Status
    );

/* Helper routines */

int __stdcall
NdrSH_UPDecision(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char            * *          pPtrInMem,
    RPC_BUFPTR                          pBuffer
    );

int __stdcall
NdrSH_TLUPDecision(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char            * *          pPtrInMem
    );

int __stdcall
NdrSH_TLUPDecisionBuffer(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char            * *          pPtrInMem
    );

int __stdcall
NdrSH_IfAlloc(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char            * *          pPtrInMem,
    unsigned long                       Count
    );

int __stdcall
NdrSH_IfAllocRef(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char            * *          pPtrInMem,
    unsigned long                       Count
    );

int __stdcall
NdrSH_IfAllocSet(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char            * *          pPtrInMem,
    unsigned long                       Count
    );

RPC_BUFPTR __stdcall
NdrSH_IfCopy(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char            * *          pPtrInMem,
    unsigned long                       Count
    );

RPC_BUFPTR __stdcall
NdrSH_IfAllocCopy(
    PMIDL_STUB_MESSAGE                  pStubMsg,
    unsigned char            * *          pPtrInMem,
    unsigned long                       Count
    );

unsigned long __stdcall
NdrSH_Copy(
    unsigned char            *         pStubMsg,
    unsigned char            *         pPtrInMem,
    unsigned long                       Count
    );

void __stdcall
NdrSH_IfFree(
    PMIDL_STUB_MESSAGE                  pMessage,
    unsigned char            *         pPtr );


RPC_BUFPTR  __stdcall
NdrSH_StringMarshall(
    PMIDL_STUB_MESSAGE                  pMessage,
    unsigned char            *         pMemory,
    unsigned long                       Count,
    int                                 Size );

RPC_BUFPTR  __stdcall
NdrSH_StringUnMarshall(
    PMIDL_STUB_MESSAGE                  pMessage,
    unsigned char            * *          pMemory,
    int                                 Size );

/****************************************************************************
    MIDL 2.0 memory package: rpc_ss_* rpc_sm_*
 ****************************************************************************/

typedef void  * RPC_SS_THREAD_HANDLE;

typedef void  * __stdcall
RPC_CLIENT_ALLOC (
    IN size_t Size
    );

typedef void __stdcall
RPC_CLIENT_FREE (
    IN void  * Ptr
    );

/*++
     RpcSs* package
--*/

void  * __stdcall
RpcSsAllocate (
    IN size_t Size
    );

void __stdcall
RpcSsDisableAllocate (
    void
    );

void __stdcall
RpcSsEnableAllocate (
    void
    );

void __stdcall
RpcSsFree (
    IN void  * NodeToFree
    );

RPC_SS_THREAD_HANDLE __stdcall
RpcSsGetThreadHandle (
    void
    );

void __stdcall
RpcSsSetClientAllocFree (
    IN RPC_CLIENT_ALLOC  * ClientAlloc,
    IN RPC_CLIENT_FREE  * ClientFree
    );

void __stdcall
RpcSsSetThreadHandle (
    IN RPC_SS_THREAD_HANDLE Id
    );

void __stdcall
RpcSsSwapClientAllocFree (
    IN RPC_CLIENT_ALLOC  * ClientAlloc,
    IN RPC_CLIENT_FREE  * ClientFree,
    OUT RPC_CLIENT_ALLOC  *  * OldClientAlloc,
    OUT RPC_CLIENT_FREE  *  * OldClientFree
    );

/*++
     RpcSm* package
--*/

void  * __stdcall
RpcSmAllocate (
    IN  size_t          Size,
    OUT RPC_STATUS  *    pStatus
    );

RPC_STATUS __stdcall
RpcSmClientFree (
    IN  void  * pNodeToFree
    );

RPC_STATUS  __stdcall
RpcSmDestroyClientContext (
    IN void  *  * ContextHandle
    );

RPC_STATUS  __stdcall
RpcSmDisableAllocate (
    void
    );

RPC_STATUS  __stdcall
RpcSmEnableAllocate (
    void
    );

RPC_STATUS  __stdcall
RpcSmFree (
    IN void  * NodeToFree
    );

RPC_SS_THREAD_HANDLE __stdcall
RpcSmGetThreadHandle (
    OUT RPC_STATUS  *    pStatus
    );

RPC_STATUS  __stdcall
RpcSmSetClientAllocFree (
    IN RPC_CLIENT_ALLOC  * ClientAlloc,
    IN RPC_CLIENT_FREE  * ClientFree
    );

RPC_STATUS  __stdcall
RpcSmSetThreadHandle (
    IN RPC_SS_THREAD_HANDLE Id
    );

RPC_STATUS  __stdcall
RpcSmSwapClientAllocFree (
    IN RPC_CLIENT_ALLOC  * ClientAlloc,
    IN RPC_CLIENT_FREE  * ClientFree,
    OUT RPC_CLIENT_ALLOC  *  * OldClientAlloc,
    OUT RPC_CLIENT_FREE  *  * OldClientFree
    );

/*++
     Ndr stub entry points
--*/

void __stdcall
NdrRpcSsEnableAllocate(
    PMIDL_STUB_MESSAGE      pMessage );

void __stdcall
NdrRpcSsDisableAllocate(
    PMIDL_STUB_MESSAGE      pMessage );

void __stdcall
NdrRpcSmSetClientToOsf(
    PMIDL_STUB_MESSAGE      pMessage );

void  *  __stdcall
NdrRpcSmClientAllocate (
    IN size_t Size
    );

void  __stdcall
NdrRpcSmClientFree (
    IN void  * NodeToFree
    );

void  *  __stdcall
NdrRpcSsDefaultAllocate (
    IN size_t Size
    );

void  __stdcall
NdrRpcSsDefaultFree (
    IN void  * NodeToFree
    );

/****************************************************************************
    end of memory package: rpc_ss_* rpc_sm_*
 ****************************************************************************/

/****************************************************************************
 * Full Pointer APIs
 ****************************************************************************/

PFULL_PTR_XLAT_TABLES __stdcall
NdrFullPointerXlatInit(
    unsigned long           NumberOfPointers,
    XLAT_SIDE               XlatSide
    );

void __stdcall
NdrFullPointerXlatFree(
    PFULL_PTR_XLAT_TABLES   pXlatTables
    );

int __stdcall
NdrFullPointerQueryPointer(
    PFULL_PTR_XLAT_TABLES   pXlatTables,
    void  *                    pPointer,
    unsigned char           QueryType,
    unsigned long  *           pRefId
    );

int __stdcall
NdrFullPointerQueryRefId(
    PFULL_PTR_XLAT_TABLES   pXlatTables,
    unsigned long           RefId,
    unsigned char           QueryType,
    void  * *                 ppPointer
    );

void __stdcall
NdrFullPointerInsertRefId(
    PFULL_PTR_XLAT_TABLES   pXlatTables,
    unsigned long           RefId,
    void  *                    pPointer
    );

int __stdcall
NdrFullPointerFree(
    PFULL_PTR_XLAT_TABLES   pXlatTables,
    void  *                    Pointer
    );

void  *  __stdcall
NdrAllocate(
    PMIDL_STUB_MESSAGE      pStubMsg,
    size_t                  Len
    );

void __stdcall
NdrClearOutParameters(
    PMIDL_STUB_MESSAGE      pStubMsg,
    PFORMAT_STRING          pFormat,
    void  *        ArgAddr
    );


/****************************************************************************
 * Proxy APIs
 ****************************************************************************/

void  * __stdcall
NdrOleAllocate (
    IN size_t Size
    );

void __stdcall
NdrOleFree (
    IN void  * NodeToFree
    );

#ifdef CONST_VTABLE
#define CONST_VTBL const
#else
#define CONST_VTBL
#endif

/****************************************************************************
 * Special things for VC5 Com support
 ****************************************************************************/

#if _MSC_VER >= 1100
#define DECLSPEC_UUID(x)    __declspec(uuid(x))
#else
#define DECLSPEC_UUID(x)
#endif

#if _MSC_VER >= 1100
#define EXTERN_GUID(itf,l1,s1,s2,c1,c2,c3,c4,c5,c6,c7,c8)  \
  EXTERN_C const IID __declspec(selectany) itf = {l1,s1,s2,{c1,c2,c3,c4,c5,c6,c7,c8}}
#else
#define EXTERN_GUID(itf,l1,s1,s2,c1,c2,c3,c4,c5,c6,c7,c8) EXTERN_C const IID itf
#endif



#ifdef __cplusplus
}
#endif

// Reset the packing level for DOS, Windows and Mac.

#if defined(__RPC_DOS__) || defined(__RPC_WIN16__) || defined(__RPC_MAC__)
#pragma pack()
#endif

#endif /* __RPCNDR_H__ */





#pragma once 
