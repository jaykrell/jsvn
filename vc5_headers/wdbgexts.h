/*++

Copyright (c) 1992-1996  Microsoft Corporation

Module Name:

    wdbgexts.h

Abstract:

    This file contains the necessary prototypes and data types for a user
    to write a debugger extension DLL.  This header file is also included
    by the NT debuggers (WINDBG & KD).

    This header file must be included after "windows.h" and "imagehlp.h".

    Please see the NT DDK documentation for specific information about
    how to write your own debugger extension DLL.

Environment:

    Win32 only.

Revision History:

--*/

#ifndef _WDBGEXTS_
#define _WDBGEXTS_

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(WDBGAPI)
#define WDBGAPI __stdcall
#endif

#ifndef _WINDEF_
typedef CONST void  *LPCVOID;
#endif

typedef DWORDLONG ULONGLONG;


typedef
VOID
(WDBGAPI*PWINDBG_OUTPUT_ROUTINE)(
    const char* lpFormat,
    ...
    );

typedef
unsigned long
(WDBGAPI*PWINDBG_GET_EXPRESSION)(
    const char* lpExpression
    );

typedef
VOID
(WDBGAPI*PWINDBG_GET_SYMBOL)(
    void*   offset,
    PUCHAR  pchBuffer,
    PULONG  pDisplacement
    );

typedef
unsigned long
(WDBGAPI*PWINDBG_DISASM)(
    PULONG lpOffset,
    const char*  lpBuffer,
    unsigned long  fShowEffectiveAddress
    );

typedef
unsigned long
(WDBGAPI*PWINDBG_CHECK_CONTROL_C)(
    VOID
    );

typedef
unsigned long
(WDBGAPI*PWINDBG_READ_PROCESS_MEMORY_ROUTINE)(
    unsigned long  offset,
    void*  lpBuffer,
    unsigned long  cb,
    PULONG lpcbBytesRead
    );

typedef
unsigned long
(WDBGAPI*PWINDBG_WRITE_PROCESS_MEMORY_ROUTINE)(
    unsigned long   offset,
    LPCVOID lpBuffer,
    unsigned long   cb,
    PULONG  lpcbBytesWritten
    );

typedef
unsigned long
(WDBGAPI*PWINDBG_GET_THREAD_CONTEXT_ROUTINE)(
    unsigned long       Processor,
    PCONTEXT    lpContext,
    unsigned long       cbSizeOfContext
    );

typedef
unsigned long
(WDBGAPI*PWINDBG_SET_THREAD_CONTEXT_ROUTINE)(
    unsigned long       Processor,
    PCONTEXT    lpContext,
    unsigned long       cbSizeOfContext
    );

typedef
unsigned long
(WDBGAPI*PWINDBG_IOCTL_ROUTINE)(
    USHORT   IoctlType,
    void*    lpvData,
    unsigned long    cbSize
    );

typedef
unsigned long
(WDBGAPI*PWINDBG_OLDKD_READ_PHYSICAL_MEMORY)(
    LARGE_INTEGER    address,
    void*            buffer,
    unsigned long            count,
    PULONG           bytesread
    );

typedef
unsigned long
(WDBGAPI*PWINDBG_OLDKD_WRITE_PHYSICAL_MEMORY)(
    LARGE_INTEGER    address,
    void*            buffer,
    unsigned long            length,
    PULONG           byteswritten
    );


typedef struct _tagEXTSTACKTRACE {
    unsigned long       FramePointer;
    unsigned long       ProgramCounter;
    unsigned long       ReturnAddress;
    unsigned long       Args[4];
} EXTSTACKTRACE, *PEXTSTACKTRACE;


typedef
unsigned long
(*PWINDBG_STACKTRACE_ROUTINE)(
    unsigned long             FramePointer,
    unsigned long             StackPointer,
    unsigned long             ProgramCounter,
    PEXTSTACKTRACE    StackFrames,
    unsigned long             Frames
    );

typedef struct _WINDBG_EXTENSION_APIS {
    unsigned long                                  nSize;
    PWINDBG_OUTPUT_ROUTINE                 lpOutputRoutine;
    PWINDBG_GET_EXPRESSION                 lpGetExpressionRoutine;
    PWINDBG_GET_SYMBOL                     lpGetSymbolRoutine;
    PWINDBG_DISASM                         lpDisasmRoutine;
    PWINDBG_CHECK_CONTROL_C                lpCheckControlCRoutine;
    PWINDBG_READ_PROCESS_MEMORY_ROUTINE    lpReadProcessMemoryRoutine;
    PWINDBG_WRITE_PROCESS_MEMORY_ROUTINE   lpWriteProcessMemoryRoutine;
    PWINDBG_GET_THREAD_CONTEXT_ROUTINE     lpGetThreadContextRoutine;
    PWINDBG_SET_THREAD_CONTEXT_ROUTINE     lpSetThreadContextRoutine;
    PWINDBG_IOCTL_ROUTINE                  lpIoctlRoutine;
    PWINDBG_STACKTRACE_ROUTINE             lpStackTraceRoutine;
} WINDBG_EXTENSION_APIS, *PWINDBG_EXTENSION_APIS;

typedef struct _WINDBG_OLD_EXTENSION_APIS {
    unsigned long                                  nSize;
    PWINDBG_OUTPUT_ROUTINE                 lpOutputRoutine;
    PWINDBG_GET_EXPRESSION                 lpGetExpressionRoutine;
    PWINDBG_GET_SYMBOL                     lpGetSymbolRoutine;
    PWINDBG_DISASM                         lpDisasmRoutine;
    PWINDBG_CHECK_CONTROL_C                lpCheckControlCRoutine;
} WINDBG_OLD_EXTENSION_APIS, *PWINDBG_OLD_EXTENSION_APIS;

typedef struct _WINDBG_OLDKD_EXTENSION_APIS {
    unsigned long                                  nSize;
    PWINDBG_OUTPUT_ROUTINE                 lpOutputRoutine;
    PWINDBG_GET_EXPRESSION                 lpGetExpressionRoutine;
    PWINDBG_GET_SYMBOL                     lpGetSymbolRoutine;
    PWINDBG_DISASM                         lpDisasmRoutine;
    PWINDBG_CHECK_CONTROL_C                lpCheckControlCRoutine;
    PWINDBG_READ_PROCESS_MEMORY_ROUTINE    lpReadVirtualMemRoutine;
    PWINDBG_WRITE_PROCESS_MEMORY_ROUTINE   lpWriteVirtualMemRoutine;
    PWINDBG_OLDKD_READ_PHYSICAL_MEMORY     lpReadPhysicalMemRoutine;
    PWINDBG_OLDKD_WRITE_PHYSICAL_MEMORY    lpWritePhysicalMemRoutine;
} WINDBG_OLDKD_EXTENSION_APIS, *PWINDBG_OLDKD_EXTENSION_APIS;

typedef
VOID
(WDBGAPI*PWINDBG_OLD_EXTENSION_ROUTINE)(
    HANDLE                  hCurrentProcess,
    HANDLE                  hCurrentThread,
    unsigned long                   dwCurrentPc,
    PWINDBG_EXTENSION_APIS  lpExtensionApis,
    const char*                   lpArgumentString
    );

typedef
VOID
(WDBGAPI*PWINDBG_EXTENSION_ROUTINE)(
    HANDLE                  hCurrentProcess,
    HANDLE                  hCurrentThread,
    unsigned long                   dwCurrentPc,
    unsigned long                   dwProcessor,
    const char*                   lpArgumentString
    );

typedef
VOID
(WDBGAPI*PWINDBG_OLDKD_EXTENSION_ROUTINE)(
    unsigned long                        dwCurrentPc,
    PWINDBG_OLDKD_EXTENSION_APIS lpExtensionApis,
    const char*                        lpArgumentString
    );

typedef
VOID
(WDBGAPI*PWINDBG_EXTENSION_DLL_INIT)(
    PWINDBG_EXTENSION_APIS lpExtensionApis,
    USHORT                 MajorVersion,
    USHORT                 MinorVersion
    );

typedef
unsigned long
(WDBGAPI*PWINDBG_CHECK_VERSION)(
    VOID
    );

#define EXT_API_VERSION_NUMBER 4

typedef struct EXT_API_VERSION {
    USHORT  MajorVersion;
    USHORT  MinorVersion;
    USHORT  Revision;
    USHORT  Reserved;
} EXT_API_VERSION, *LPEXT_API_VERSION;

typedef
LPEXT_API_VERSION
(WDBGAPI*PWINDBG_EXTENSION_API_VERSION)(
    VOID
    );

#define IG_KD_CONTEXT               1
#define IG_READ_CONTROL_SPACE       2
#define IG_WRITE_CONTROL_SPACE      3
#define IG_READ_IO_SPACE            4
#define IG_WRITE_IO_SPACE           5
#define IG_READ_PHYSICAL            6
#define IG_WRITE_PHYSICAL           7
#define IG_READ_IO_SPACE_EX         8
#define IG_WRITE_IO_SPACE_EX        9
#define IG_KSTACK_HELP             10
#define IG_SET_THREAD              11
#define IG_READ_MSR                12
#define IG_WRITE_MSR               13

typedef struct _tagPROCESSORINFO {
    USHORT      Processor;                // current processor
    USHORT      NumberProcessors;         // total number of processors
} PROCESSORINFO, *PPROCESSORINFO;

typedef struct _tagREADCONTROLSPACE {
    USHORT      Processor;
    unsigned long       Address;
    unsigned long       BufLen;
    UCHAR       Buf[1];
} READCONTROLSPACE, *PREADCONTROLSPACE;

typedef struct _tagIOSPACE {
    unsigned long       Address;
    unsigned long       Length;                   // 1, 2, or 4 bytes
    unsigned long       Data;
} IOSPACE, *PIOSPACE;

typedef struct _tagIOSPACE_EX {
    unsigned long       Address;
    unsigned long       Length;                   // 1, 2, or 4 bytes
    unsigned long       Data;
    unsigned long       InterfaceType;
    unsigned long       BusNumber;
    unsigned long       AddressSpace;
} IOSPACE_EX, *PIOSPACE_EX;

typedef struct _tagPHYSICAL {
    LARGE_INTEGER          Address;
    unsigned long                  BufLen;
    UCHAR                  Buf[1];
} PHYSICAL, *PPHYSICAL;

typedef struct _tagREAD_WRITE_MSR {
    unsigned long       Msr;
    LONGLONG    Value;
} READ_WRITE_MSR, *PREAD_WRITE_MSR;

#ifdef __cplusplus
#define CPPMOD extern "C"
#else
#define CPPMOD
#endif


#define DECLARE_API(s)                             \
    CPPMOD VOID                                    \
    s(                                             \
        HANDLE                 hCurrentProcess,    \
        HANDLE                 hCurrentThread,     \
        unsigned long                  dwCurrentPc,        \
        unsigned long                  dwProcessor,        \
        const char*                  args                \
     )

#ifndef NOEXTAPI

#define dprintf          (ExtensionApis.lpOutputRoutine)
#define GetExpression    (ExtensionApis.lpGetExpressionRoutine)
#define GetSymbol        (ExtensionApis.lpGetSymbolRoutine)
#define Disassm          (ExtensionApis.lpDisasmRoutine)
#define CheckControlC    (ExtensionApis.lpCheckControlCRoutine)
#define ReadMemory       (ExtensionApis.lpReadProcessMemoryRoutine)
#define WriteMemory      (ExtensionApis.lpWriteProcessMemoryRoutine)
#define GetContext       (ExtensionApis.lpGetThreadContextRoutine)
#define SetContext       (ExtensionApis.lpSetThreadContextRoutine)
#define Ioctl            (ExtensionApis.lpIoctlRoutine)
#define StackTrace       (ExtensionApis.lpStackTraceRoutine)


#define GetKdContext(ppi) \
    Ioctl( IG_KD_CONTEXT, (void*)ppi, sizeof(*ppi) )

extern WINDBG_EXTENSION_APIS ExtensionApis;

__inline VOID
ReadControlSpace(
    USHORT  processor,
    unsigned long   address,
    void*   buf,
    unsigned long   size
    )
{
    PREADCONTROLSPACE prc;
    prc = (PREADCONTROLSPACE)LocalAlloc(LPTR, sizeof(*prc) + size );
    ZeroMemory( prc->Buf, size );
    prc->Processor = processor;
    prc->Address = (unsigned long)address;
    prc->BufLen = size;
    Ioctl( IG_READ_CONTROL_SPACE, (void*)prc, sizeof(*prc) + size );
    CopyMemory( buf, prc->Buf, size );
    LocalFree( prc );
}

__inline VOID
ReadIoSpace(
    unsigned long   address,
    PULONG  data,
    PULONG  size
    )
{
    IOSPACE is;
    is.Address = (unsigned long)address;
    is.Length = *size;
    is.Data = 0;
    Ioctl( IG_READ_IO_SPACE, (void*)&is, sizeof(is) );
    *data = is.Data;
    *size = is.Length;
}

__inline VOID
WriteIoSpace(
    unsigned long   address,
    unsigned long   data,
    PULONG  size
    )
{
    IOSPACE is;
    is.Address = (unsigned long)address;
    is.Length = *size;
    is.Data = data;
    Ioctl( IG_WRITE_IO_SPACE, (void*)&is, sizeof(is) );
    *size = is.Length;
}

__inline VOID
ReadIoSpaceEx(
    unsigned long   address,
    PULONG  data,
    PULONG  size,
    unsigned long   interfacetype,
    unsigned long   busnumber,
    unsigned long   addressspace
    )
{
    IOSPACE_EX is;
    is.Address = (unsigned long)address;
    is.Length = *size;
    is.Data = 0;
    is.InterfaceType = interfacetype;
    is.BusNumber = busnumber;
    is.AddressSpace = addressspace;
    Ioctl( IG_READ_IO_SPACE_EX, (void*)&is, sizeof(is) );
    *data = is.Data;
    *size = is.Length;
}

__inline VOID
WriteIoSpaceEx(
    unsigned long   address,
    unsigned long   data,
    PULONG  size,
    unsigned long   interfacetype,
    unsigned long   busnumber,
    unsigned long   addressspace
    )
{
    IOSPACE_EX is;
    is.Address = (unsigned long)address;
    is.Length = *size;
    is.Data = data;
    is.InterfaceType = interfacetype;
    is.BusNumber = busnumber;
    is.AddressSpace = addressspace;
    Ioctl( IG_WRITE_IO_SPACE_EX, (void*)&is, sizeof(is) );
    *size = is.Length;
}

__inline VOID
ReadPhysical(
    LARGE_INTEGER       address,
    void*               buf,
    unsigned long               size,
    PULONG              sizer
    )
{
    PPHYSICAL phy;
    phy = (PPHYSICAL)LocalAlloc(LPTR,  sizeof(*phy) + size );
    ZeroMemory( phy->Buf, size );
    phy->Address = address;
    phy->BufLen = size;
    Ioctl( IG_READ_PHYSICAL, (void*)phy, sizeof(*phy) + size );
    *sizer = phy->BufLen;
    CopyMemory( buf, phy->Buf, *sizer );
    LocalFree( phy );
}

__inline VOID
WritePhysical(
    LARGE_INTEGER       address,
    void*               buf,
    unsigned long               size,
    PULONG              sizew
    )
{
    PPHYSICAL phy;
    phy = (PPHYSICAL)LocalAlloc(LPTR, sizeof(*phy) + size );
    ZeroMemory( phy->Buf, size );
    phy->Address = address;
    phy->BufLen = size;
    CopyMemory( phy->Buf, buf, size );
    Ioctl( IG_WRITE_PHYSICAL, (void*)phy, sizeof(*phy) + size );
    *sizew = phy->BufLen;
    LocalFree( phy );
}

__inline VOID
SetThreadForOperation(
    PULONG Thread
    )
{
    Ioctl(IG_SET_THREAD, (void*)Thread, sizeof(unsigned long));
}

__inline VOID
ReadMsr(
    unsigned long       MsrReg,
    ULONGLONG   *MsrValue
    )
{
    PREAD_WRITE_MSR msr;
    LARGE_INTEGER li;

    msr = (PREAD_WRITE_MSR)LocalAlloc(LPTR,  sizeof(*msr));
    msr->Msr = MsrReg;
    Ioctl( IG_READ_MSR, (void*)msr, sizeof(*msr) );

    *MsrValue = msr->Value;
    LocalFree( msr );
}

__inline VOID
WriteMsr(
    unsigned long       MsrReg,
    ULONGLONG   MsrValue
    )
{
    PREAD_WRITE_MSR msr;

    msr = (PREAD_WRITE_MSR)LocalAlloc(LPTR,  sizeof(*msr));
    msr->Msr = MsrReg;
    msr->Value = MsrValue;
    Ioctl( IG_WRITE_MSR, (void*)msr, sizeof(*msr) );
    LocalFree( msr );
}

#endif


#ifdef __cplusplus
}
#endif

#endif // _WDBGEXTS_
#pragma once 
