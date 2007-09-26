/************************************************************************
*                                                                       *
*   winbase.h -- This module defines the 32-Bit Windows Base APIs       *
*                                                                       *
*   Copyright (c) 1990-1996, Microsoft Corp. All rights reserved.       *
*                                                                       *
************************************************************************/
#ifndef _WINBASE_
#define _WINBASE_


//
// Define API decoration for direct importing of DLL references.
//

#if !defined(_ADVAPI32_)
#define WINADVAPI DECLSPEC_IMPORT
#else
#define WINADVAPI
#endif

#if !defined(_KERNEL32_)
#define WINBASEAPI DECLSPEC_IMPORT
#else
#define WINBASEAPI
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Compatibility macros
 */

#define DefineHandleTable(w)            ((w),TRUE)
#define LimitEmsPages(dw)
#define SetSwapAreaSize(w)              (w)
#define LockSegment(w)                  GlobalFix((HANDLE)(w))
#define UnlockSegment(w)                GlobalUnfix((HANDLE)(w))
#define GetCurrentTime()                GetTickCount()

#define Yield()

#define INVALID_HANDLE_VALUE (HANDLE)-1
#define INVALID_FILE_SIZE (unsigned long)0xFFFFFFFF

#define FILE_BEGIN           0
#define FILE_CURRENT         1
#define FILE_END             2

#define TIME_ZONE_ID_INVALID (unsigned long)0xFFFFFFFF

#define WAIT_FAILED (unsigned long)0xFFFFFFFF
#define WAIT_OBJECT_0       ((STATUS_WAIT_0 ) + 0 )

#define WAIT_ABANDONED         ((STATUS_ABANDONED_WAIT_0 ) + 0 )
#define WAIT_ABANDONED_0       ((STATUS_ABANDONED_WAIT_0 ) + 0 )

#define WAIT_TIMEOUT                        STATUS_TIMEOUT
#define WAIT_IO_COMPLETION                  STATUS_USER_APC
#define STILL_ACTIVE                        STATUS_PENDING
#define EXCEPTION_ACCESS_VIOLATION          STATUS_ACCESS_VIOLATION
#define EXCEPTION_DATATYPE_MISALIGNMENT     STATUS_DATATYPE_MISALIGNMENT
#define EXCEPTION_BREAKPOINT                STATUS_BREAKPOINT
#define EXCEPTION_SINGLE_STEP               STATUS_SINGLE_STEP
#define EXCEPTION_ARRAY_BOUNDS_EXCEEDED     STATUS_ARRAY_BOUNDS_EXCEEDED
#define EXCEPTION_FLT_DENORMAL_OPERAND      STATUS_FLOAT_DENORMAL_OPERAND
#define EXCEPTION_FLT_DIVIDE_BY_ZERO        STATUS_FLOAT_DIVIDE_BY_ZERO
#define EXCEPTION_FLT_INEXACT_RESULT        STATUS_FLOAT_INEXACT_RESULT
#define EXCEPTION_FLT_INVALID_OPERATION     STATUS_FLOAT_INVALID_OPERATION
#define EXCEPTION_FLT_OVERFLOW              STATUS_FLOAT_OVERFLOW
#define EXCEPTION_FLT_STACK_CHECK           STATUS_FLOAT_STACK_CHECK
#define EXCEPTION_FLT_UNDERFLOW             STATUS_FLOAT_UNDERFLOW
#define EXCEPTION_INT_DIVIDE_BY_ZERO        STATUS_INTEGER_DIVIDE_BY_ZERO
#define EXCEPTION_INT_OVERFLOW              STATUS_INTEGER_OVERFLOW
#define EXCEPTION_PRIV_INSTRUCTION          STATUS_PRIVILEGED_INSTRUCTION
#define EXCEPTION_IN_PAGE_ERROR             STATUS_IN_PAGE_ERROR
#define EXCEPTION_ILLEGAL_INSTRUCTION       STATUS_ILLEGAL_INSTRUCTION
#define EXCEPTION_NONCONTINUABLE_EXCEPTION  STATUS_NONCONTINUABLE_EXCEPTION
#define EXCEPTION_STACK_OVERFLOW            STATUS_STACK_OVERFLOW
#define EXCEPTION_INVALID_DISPOSITION       STATUS_INVALID_DISPOSITION
#define EXCEPTION_GUARD_PAGE                STATUS_GUARD_PAGE_VIOLATION
#define EXCEPTION_INVALID_HANDLE            STATUS_INVALID_HANDLE
#define CONTROL_C_EXIT                      STATUS_CONTROL_C_EXIT
#define MoveMemory RtlMoveMemory
#define CopyMemory RtlCopyMemory
#define FillMemory RtlFillMemory
#define ZeroMemory RtlZeroMemory

//
// File creation flags must start at the high end since they
// are combined with the attributes
//

#define FILE_FLAG_WRITE_THROUGH         0x80000000
#define FILE_FLAG_OVERLAPPED            0x40000000
#define FILE_FLAG_NO_BUFFERING          0x20000000
#define FILE_FLAG_RANDOM_ACCESS         0x10000000
#define FILE_FLAG_SEQUENTIAL_SCAN       0x08000000
#define FILE_FLAG_DELETE_ON_CLOSE       0x04000000
#define FILE_FLAG_BACKUP_SEMANTICS      0x02000000
#define FILE_FLAG_POSIX_SEMANTICS       0x01000000

#define CREATE_NEW          1
#define CREATE_ALWAYS       2
#define OPEN_EXISTING       3
#define OPEN_ALWAYS         4
#define TRUNCATE_EXISTING   5

#if(_WIN32_WINNT >= 0x0400)
//
// Define possible return codes from the CopyFileEx callback routine
//

#define PROGRESS_CONTINUE   0
#define PROGRESS_CANCEL     1
#define PROGRESS_STOP       2
#define PROGRESS_QUIET      3

//
// Define CopyFileEx callback routine state change values
//

#define CALLBACK_CHUNK_FINISHED         0x00000000
#define CALLBACK_STREAM_SWITCH          0x00000001

//
// Define CopyFileEx option flags
//

#define COPY_FILE_FAIL_IF_EXISTS        0x00000001
#define COPY_FILE_RESTARTABLE           0x00000002
#endif /* _WIN32_WINNT >= 0x0400 */

//
// Define the NamedPipe definitions
//


//
// Define the dwOpenMode values for CreateNamedPipe
//

#define PIPE_ACCESS_INBOUND         0x00000001
#define PIPE_ACCESS_OUTBOUND        0x00000002
#define PIPE_ACCESS_DUPLEX          0x00000003

//
// Define the Named Pipe End flags for GetNamedPipeInfo
//

#define PIPE_CLIENT_END             0x00000000
#define PIPE_SERVER_END             0x00000001

//
// Define the dwPipeMode values for CreateNamedPipe
//

#define PIPE_WAIT                   0x00000000
#define PIPE_NOWAIT                 0x00000001
#define PIPE_READMODE_BYTE          0x00000000
#define PIPE_READMODE_MESSAGE       0x00000002
#define PIPE_TYPE_BYTE              0x00000000
#define PIPE_TYPE_MESSAGE           0x00000004

//
// Define the well known values for CreateNamedPipe nMaxInstances
//

#define PIPE_UNLIMITED_INSTANCES    255

//
// Define the Security Quality of Service bits to be passed
// into CreateFile
//

#define SECURITY_ANONYMOUS          ( SecurityAnonymous      << 16 )
#define SECURITY_IDENTIFICATION     ( SecurityIdentification << 16 )
#define SECURITY_IMPERSONATION      ( SecurityImpersonation  << 16 )
#define SECURITY_DELEGATION         ( SecurityDelegation     << 16 )

#define SECURITY_CONTEXT_TRACKING  0x00040000
#define SECURITY_EFFECTIVE_ONLY    0x00080000

#define SECURITY_SQOS_PRESENT      0x00100000
#define SECURITY_VALID_SQOS_FLAGS  0x001F0000

//
//  File structures
//

typedef struct _OVERLAPPED {
    unsigned long   Internal;
    unsigned long   InternalHigh;
    unsigned long   Offset;
    unsigned long   OffsetHigh;
    HANDLE  hEvent;
} OVERLAPPED, *LPOVERLAPPED;

typedef struct _SECURITY_ATTRIBUTES {
    unsigned long nLength;
    void* lpSecurityDescriptor;
    BOOL bInheritHandle;
} SECURITY_ATTRIBUTES, *PSECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

typedef struct _PROCESS_INFORMATION {
    HANDLE hProcess;
    HANDLE hThread;
    unsigned long dwProcessId;
    unsigned long dwThreadId;
} PROCESS_INFORMATION, *PPROCESS_INFORMATION, *LPPROCESS_INFORMATION;

//
//  File System time stamps are represented with the following structure:
//

typedef struct _FILETIME {
    unsigned long dwLowDateTime;
    unsigned long dwHighDateTime;
} FILETIME, *PFILETIME, *LPFILETIME;

//
// System time is represented with the following structure:
//

typedef struct _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
} SYSTEMTIME, *PSYSTEMTIME, *LPSYSTEMTIME;

typedef unsigned long (__stdcall *PTHREAD_START_ROUTINE)(
    void* lpThreadParameter
    );
typedef PTHREAD_START_ROUTINE LPTHREAD_START_ROUTINE;

#if(_WIN32_WINNT >= 0x0400)
typedef void (__stdcall *PFIBER_START_ROUTINE)(
    void* lpFiberParameter
    );
typedef PFIBER_START_ROUTINE LPFIBER_START_ROUTINE;
#endif /* _WIN32_WINNT >= 0x0400 */

typedef RTL_CRITICAL_SECTION CRITICAL_SECTION;
typedef PRTL_CRITICAL_SECTION PCRITICAL_SECTION;
typedef PRTL_CRITICAL_SECTION LPCRITICAL_SECTION;

typedef RTL_CRITICAL_SECTION_DEBUG CRITICAL_SECTION_DEBUG;
typedef PRTL_CRITICAL_SECTION_DEBUG PCRITICAL_SECTION_DEBUG;
typedef PRTL_CRITICAL_SECTION_DEBUG LPCRITICAL_SECTION_DEBUG;

#ifdef _X86_
typedef PLDT_ENTRY LPLDT_ENTRY;
#else
typedef void* LPLDT_ENTRY;
#endif

#define MUTEX_MODIFY_STATE MUTANT_QUERY_STATE
#define MUTEX_ALL_ACCESS MUTANT_ALL_ACCESS

//
// Serial provider type.
//

#define SP_SERIALCOMM    ((unsigned long)0x00000001)

//
// Provider SubTypes
//

#define PST_UNSPECIFIED      ((unsigned long)0x00000000)
#define PST_RS232            ((unsigned long)0x00000001)
#define PST_PARALLELPORT     ((unsigned long)0x00000002)
#define PST_RS422            ((unsigned long)0x00000003)
#define PST_RS423            ((unsigned long)0x00000004)
#define PST_RS449            ((unsigned long)0x00000005)
#define PST_MODEM            ((unsigned long)0x00000006)
#define PST_FAX              ((unsigned long)0x00000021)
#define PST_SCANNER          ((unsigned long)0x00000022)
#define PST_NETWORK_BRIDGE   ((unsigned long)0x00000100)
#define PST_LAT              ((unsigned long)0x00000101)
#define PST_TCPIP_TELNET     ((unsigned long)0x00000102)
#define PST_X25              ((unsigned long)0x00000103)


//
// Provider capabilities flags.
//

#define PCF_DTRDSR        ((unsigned long)0x0001)
#define PCF_RTSCTS        ((unsigned long)0x0002)
#define PCF_RLSD          ((unsigned long)0x0004)
#define PCF_PARITY_CHECK  ((unsigned long)0x0008)
#define PCF_XONXOFF       ((unsigned long)0x0010)
#define PCF_SETXCHAR      ((unsigned long)0x0020)
#define PCF_TOTALTIMEOUTS ((unsigned long)0x0040)
#define PCF_INTTIMEOUTS   ((unsigned long)0x0080)
#define PCF_SPECIALCHARS  ((unsigned long)0x0100)
#define PCF_16BITMODE     ((unsigned long)0x0200)

//
// Comm provider settable parameters.
//

#define SP_PARITY         ((unsigned long)0x0001)
#define SP_BAUD           ((unsigned long)0x0002)
#define SP_DATABITS       ((unsigned long)0x0004)
#define SP_STOPBITS       ((unsigned long)0x0008)
#define SP_HANDSHAKING    ((unsigned long)0x0010)
#define SP_PARITY_CHECK   ((unsigned long)0x0020)
#define SP_RLSD           ((unsigned long)0x0040)

//
// Settable baud rates in the provider.
//

#define BAUD_075          ((unsigned long)0x00000001)
#define BAUD_110          ((unsigned long)0x00000002)
#define BAUD_134_5        ((unsigned long)0x00000004)
#define BAUD_150          ((unsigned long)0x00000008)
#define BAUD_300          ((unsigned long)0x00000010)
#define BAUD_600          ((unsigned long)0x00000020)
#define BAUD_1200         ((unsigned long)0x00000040)
#define BAUD_1800         ((unsigned long)0x00000080)
#define BAUD_2400         ((unsigned long)0x00000100)
#define BAUD_4800         ((unsigned long)0x00000200)
#define BAUD_7200         ((unsigned long)0x00000400)
#define BAUD_9600         ((unsigned long)0x00000800)
#define BAUD_14400        ((unsigned long)0x00001000)
#define BAUD_19200        ((unsigned long)0x00002000)
#define BAUD_38400        ((unsigned long)0x00004000)
#define BAUD_56K          ((unsigned long)0x00008000)
#define BAUD_128K         ((unsigned long)0x00010000)
#define BAUD_115200       ((unsigned long)0x00020000)
#define BAUD_57600        ((unsigned long)0x00040000)
#define BAUD_USER         ((unsigned long)0x10000000)

//
// Settable Data Bits
//

#define DATABITS_5        ((WORD)0x0001)
#define DATABITS_6        ((WORD)0x0002)
#define DATABITS_7        ((WORD)0x0004)
#define DATABITS_8        ((WORD)0x0008)
#define DATABITS_16       ((WORD)0x0010)
#define DATABITS_16X      ((WORD)0x0020)

//
// Settable Stop and Parity bits.
//

#define STOPBITS_10       ((WORD)0x0001)
#define STOPBITS_15       ((WORD)0x0002)
#define STOPBITS_20       ((WORD)0x0004)
#define PARITY_NONE       ((WORD)0x0100)
#define PARITY_ODD        ((WORD)0x0200)
#define PARITY_EVEN       ((WORD)0x0400)
#define PARITY_MARK       ((WORD)0x0800)
#define PARITY_SPACE      ((WORD)0x1000)

typedef struct _COMMPROP {
    WORD wPacketLength;
    WORD wPacketVersion;
    unsigned long dwServiceMask;
    unsigned long dwReserved1;
    unsigned long dwMaxTxQueue;
    unsigned long dwMaxRxQueue;
    unsigned long dwMaxBaud;
    unsigned long dwProvSubType;
    unsigned long dwProvCapabilities;
    unsigned long dwSettableParams;
    unsigned long dwSettableBaud;
    WORD wSettableData;
    WORD wSettableStopParity;
    unsigned long dwCurrentTxQueue;
    unsigned long dwCurrentRxQueue;
    unsigned long dwProvSpec1;
    unsigned long dwProvSpec2;
    wchar_t wcProvChar[1];
} COMMPROP,*LPCOMMPROP;

//
// Set dwProvSpec1 to COMMPROP_INITIALIZED to indicate that wPacketLength
// is valid before a call to GetCommProperties().
//
#define COMMPROP_INITIALIZED ((unsigned long)0xE73CF52E)

typedef struct _COMSTAT {
    unsigned fCtsHold : 1;
    unsigned fDsrHold : 1;
    unsigned fRlsdHold : 1;
    unsigned fXoffHold : 1;
    unsigned fXoffSent : 1;
    unsigned fEof : 1;
    unsigned fTxim : 1;
    unsigned fReserved : 25;
    unsigned long cbInQue;
    unsigned long cbOutQue;
} COMSTAT, *LPCOMSTAT;

//
// DTR Control Flow Values.
//
#define DTR_CONTROL_DISABLE    0x00
#define DTR_CONTROL_ENABLE     0x01
#define DTR_CONTROL_HANDSHAKE  0x02

//
// RTS Control Flow Values
//
#define RTS_CONTROL_DISABLE    0x00
#define RTS_CONTROL_ENABLE     0x01
#define RTS_CONTROL_HANDSHAKE  0x02
#define RTS_CONTROL_TOGGLE     0x03

typedef struct _DCB {
    unsigned long DCBlength;      /* sizeof(DCB)                     */
    unsigned long BaudRate;       /* Baudrate at which running       */
    unsigned fBinary: 1;     /* Binary Mode (skip EOF check)    */
    unsigned fParity: 1;     /* Enable parity checking          */
    unsigned fOutxCtsFlow:1; /* CTS handshaking on output       */
    unsigned fOutxDsrFlow:1; /* DSR handshaking on output       */
    unsigned fDtrControl:2;  /* DTR Flow control                */
    unsigned fDsrSensitivity:1; /* DSR Sensitivity              */
    unsigned fTXContinueOnXoff: 1; /* Continue TX when Xoff sent */
    unsigned fOutX: 1;       /* Enable output X-ON/X-OFF        */
    unsigned fInX: 1;        /* Enable input X-ON/X-OFF         */
    unsigned fErrorChar: 1;  /* Enable Err Replacement          */
    unsigned fNull: 1;       /* Enable Null stripping           */
    unsigned fRtsControl:2;  /* Rts Flow control                */
    unsigned fAbortOnError:1; /* Abort all reads and writes on Error */
    unsigned fDummy2:17;     /* Reserved                        */
    WORD wReserved;       /* Not currently used              */
    WORD XonLim;          /* Transmit X-ON threshold         */
    WORD XoffLim;         /* Transmit X-OFF threshold        */
    BYTE ByteSize;        /* Number of bits/byte, 4-8        */
    BYTE Parity;          /* 0-4=None,Odd,Even,Mark,Space    */
    BYTE StopBits;        /* 0,1,2 = 1, 1.5, 2               */
    char XonChar;         /* Tx and Rx X-ON character        */
    char XoffChar;        /* Tx and Rx X-OFF character       */
    char ErrorChar;       /* Error replacement char          */
    char EofChar;         /* End of Input character          */
    char EvtChar;         /* Received Event character        */
    WORD wReserved1;      /* Fill for now.                   */
} DCB, *LPDCB;

typedef struct _COMMTIMEOUTS {
    unsigned long ReadIntervalTimeout;          /* Maximum time between read chars. */
    unsigned long ReadTotalTimeoutMultiplier;   /* Multiplier of characters.        */
    unsigned long ReadTotalTimeoutConstant;     /* Constant in milliseconds.        */
    unsigned long WriteTotalTimeoutMultiplier;  /* Multiplier of characters.        */
    unsigned long WriteTotalTimeoutConstant;    /* Constant in milliseconds.        */
} COMMTIMEOUTS,*LPCOMMTIMEOUTS;

typedef struct _COMMCONFIG {
    unsigned long dwSize;               /* Size of the entire struct */
    WORD wVersion;              /* version of the structure */
    WORD wReserved;             /* alignment */
    DCB dcb;                    /* device control block */
    unsigned long dwProviderSubType;    /* ordinal value for identifying
                                   provider-defined data structure format*/
    unsigned long dwProviderOffset;     /* Specifies the offset of provider specific
                                   data field in bytes from the start */
    unsigned long dwProviderSize;       /* size of the provider-specific data field */
    wchar_t wcProviderData[1];    /* provider-specific data */
} COMMCONFIG,*LPCOMMCONFIG;

typedef struct _SYSTEM_INFO {
    union {
        unsigned long dwOemId;          // Obsolete field...do not use
        struct {
            WORD wProcessorArchitecture;
            WORD wReserved;
        };
    };
    unsigned long dwPageSize;
    void* lpMinimumApplicationAddress;
    void* lpMaximumApplicationAddress;
    unsigned long dwActiveProcessorMask;
    unsigned long dwNumberOfProcessors;
    unsigned long dwProcessorType;
    unsigned long dwAllocationGranularity;
    WORD wProcessorLevel;
    WORD wProcessorRevision;
} SYSTEM_INFO, *LPSYSTEM_INFO;

//
//


#define FreeModule(hLibModule) FreeLibrary((hLibModule))
#define MakeProcInstance(lpProc,hInstance) (lpProc)
#define FreeProcInstance(lpProc) (lpProc)

/* Global Memory Flags */
#define GMEM_FIXED          0x0000
#define GMEM_MOVEABLE       0x0002
#define GMEM_NOCOMPACT      0x0010
#define GMEM_NODISCARD      0x0020
#define GMEM_ZEROINIT       0x0040
#define GMEM_MODIFY         0x0080
#define GMEM_DISCARDABLE    0x0100
#define GMEM_NOT_BANKED     0x1000
#define GMEM_SHARE          0x2000
#define GMEM_DDESHARE       0x2000
#define GMEM_NOTIFY         0x4000
#define GMEM_LOWER          GMEM_NOT_BANKED
#define GMEM_VALID_FLAGS    0x7F72
#define GMEM_INVALID_HANDLE 0x8000

#define GHND                (GMEM_MOVEABLE | GMEM_ZEROINIT)
#define GPTR                (GMEM_FIXED | GMEM_ZEROINIT)

#define GlobalLRUNewest( h )    (HANDLE)(h)
#define GlobalLRUOldest( h )    (HANDLE)(h)
#define GlobalDiscard( h )      GlobalReAlloc( (h), 0, GMEM_MOVEABLE )

/* Flags returned by GlobalFlags (in addition to GMEM_DISCARDABLE) */
#define GMEM_DISCARDED      0x4000
#define GMEM_LOCKCOUNT      0x00FF

typedef struct _MEMORYSTATUS {
    unsigned long dwLength;
    unsigned long dwMemoryLoad;
    unsigned long dwTotalPhys;
    unsigned long dwAvailPhys;
    unsigned long dwTotalPageFile;
    unsigned long dwAvailPageFile;
    unsigned long dwTotalVirtual;
    unsigned long dwAvailVirtual;
} MEMORYSTATUS, *LPMEMORYSTATUS;

/* Local Memory Flags */
#define LMEM_FIXED          0x0000
#define LMEM_MOVEABLE       0x0002
#define LMEM_NOCOMPACT      0x0010
#define LMEM_NODISCARD      0x0020
#define LMEM_ZEROINIT       0x0040
#define LMEM_MODIFY         0x0080
#define LMEM_DISCARDABLE    0x0F00
#define LMEM_VALID_FLAGS    0x0F72
#define LMEM_INVALID_HANDLE 0x8000

#define LHND                (LMEM_MOVEABLE | LMEM_ZEROINIT)
#define LPTR                (LMEM_FIXED | LMEM_ZEROINIT)

#define NONZEROLHND         (LMEM_MOVEABLE)
#define NONZEROLPTR         (LMEM_FIXED)

#define LocalDiscard( h )   LocalReAlloc( (h), 0, LMEM_MOVEABLE )

/* Flags returned by LocalFlags (in addition to LMEM_DISCARDABLE) */
#define LMEM_DISCARDED      0x4000
#define LMEM_LOCKCOUNT      0x00FF

//
// dwCreationFlag values
//

#define DEBUG_PROCESS               0x00000001
#define DEBUG_ONLY_THIS_PROCESS     0x00000002

#define CREATE_SUSPENDED            0x00000004

#define DETACHED_PROCESS            0x00000008

#define CREATE_NEW_CONSOLE          0x00000010

#define NORMAL_PRIORITY_CLASS       0x00000020
#define IDLE_PRIORITY_CLASS         0x00000040
#define HIGH_PRIORITY_CLASS         0x00000080
#define REALTIME_PRIORITY_CLASS     0x00000100

#define CREATE_NEW_PROCESS_GROUP    0x00000200
#define CREATE_UNICODE_ENVIRONMENT  0x00000400

#define CREATE_SEPARATE_WOW_VDM     0x00000800
#define CREATE_SHARED_WOW_VDM       0x00001000
#define CREATE_FORCEDOS             0x00002000

#define CREATE_DEFAULT_ERROR_MODE   0x04000000
#define CREATE_NO_WINDOW            0x08000000

#define PROFILE_USER                0x10000000
#define PROFILE_KERNEL              0x20000000
#define PROFILE_SERVER              0x40000000

#define THREAD_PRIORITY_LOWEST          THREAD_BASE_PRIORITY_MIN
#define THREAD_PRIORITY_BELOW_NORMAL    (THREAD_PRIORITY_LOWEST+1)
#define THREAD_PRIORITY_NORMAL          0
#define THREAD_PRIORITY_HIGHEST         THREAD_BASE_PRIORITY_MAX
#define THREAD_PRIORITY_ABOVE_NORMAL    (THREAD_PRIORITY_HIGHEST-1)
#define THREAD_PRIORITY_ERROR_RETURN    (MAXLONG)

#define THREAD_PRIORITY_TIME_CRITICAL   THREAD_BASE_PRIORITY_LOWRT
#define THREAD_PRIORITY_IDLE            THREAD_BASE_PRIORITY_IDLE

//
// Debug APIs
//
#define EXCEPTION_DEBUG_EVENT       1
#define CREATE_THREAD_DEBUG_EVENT   2
#define CREATE_PROCESS_DEBUG_EVENT  3
#define EXIT_THREAD_DEBUG_EVENT     4
#define EXIT_PROCESS_DEBUG_EVENT    5
#define LOAD_DLL_DEBUG_EVENT        6
#define UNLOAD_DLL_DEBUG_EVENT      7
#define OUTPUT_DEBUG_STRING_EVENT   8
#define RIP_EVENT                   9

typedef struct _EXCEPTION_DEBUG_INFO {
    EXCEPTION_RECORD ExceptionRecord;
    unsigned long dwFirstChance;
} EXCEPTION_DEBUG_INFO, *LPEXCEPTION_DEBUG_INFO;

typedef struct _CREATE_THREAD_DEBUG_INFO {
    HANDLE hThread;
    void* lpThreadLocalBase;
    LPTHREAD_START_ROUTINE lpStartAddress;
} CREATE_THREAD_DEBUG_INFO, *LPCREATE_THREAD_DEBUG_INFO;

typedef struct _CREATE_PROCESS_DEBUG_INFO {
    HANDLE hFile;
    HANDLE hProcess;
    HANDLE hThread;
    void* lpBaseOfImage;
    unsigned long dwDebugInfoFileOffset;
    unsigned long nDebugInfoSize;
    void* lpThreadLocalBase;
    LPTHREAD_START_ROUTINE lpStartAddress;
    void* lpImageName;
    WORD fUnicode;
} CREATE_PROCESS_DEBUG_INFO, *LPCREATE_PROCESS_DEBUG_INFO;

typedef struct _EXIT_THREAD_DEBUG_INFO {
    unsigned long dwExitCode;
} EXIT_THREAD_DEBUG_INFO, *LPEXIT_THREAD_DEBUG_INFO;

typedef struct _EXIT_PROCESS_DEBUG_INFO {
    unsigned long dwExitCode;
} EXIT_PROCESS_DEBUG_INFO, *LPEXIT_PROCESS_DEBUG_INFO;

typedef struct _LOAD_DLL_DEBUG_INFO {
    HANDLE hFile;
    void* lpBaseOfDll;
    unsigned long dwDebugInfoFileOffset;
    unsigned long nDebugInfoSize;
    void* lpImageName;
    WORD fUnicode;
} LOAD_DLL_DEBUG_INFO, *LPLOAD_DLL_DEBUG_INFO;

typedef struct _UNLOAD_DLL_DEBUG_INFO {
    void* lpBaseOfDll;
} UNLOAD_DLL_DEBUG_INFO, *LPUNLOAD_DLL_DEBUG_INFO;

typedef struct _OUTPUT_DEBUG_STRING_INFO {
    char* lpDebugStringData;
    WORD fUnicode;
    WORD nDebugStringLength;
} OUTPUT_DEBUG_STRING_INFO, *LPOUTPUT_DEBUG_STRING_INFO;

typedef struct _RIP_INFO {
    unsigned long dwError;
    unsigned long dwType;
} RIP_INFO, *LPRIP_INFO;


typedef struct _DEBUG_EVENT {
    unsigned long dwDebugEventCode;
    unsigned long dwProcessId;
    unsigned long dwThreadId;
    union {
        EXCEPTION_DEBUG_INFO Exception;
        CREATE_THREAD_DEBUG_INFO CreateThread;
        CREATE_PROCESS_DEBUG_INFO CreateProcessInfo;
        EXIT_THREAD_DEBUG_INFO ExitThread;
        EXIT_PROCESS_DEBUG_INFO ExitProcess;
        LOAD_DLL_DEBUG_INFO LoadDll;
        UNLOAD_DLL_DEBUG_INFO UnloadDll;
        OUTPUT_DEBUG_STRING_INFO DebugString;
        RIP_INFO RipInfo;
    } u;
} DEBUG_EVENT, *LPDEBUG_EVENT;

#if !defined(MIDL_PASS)
typedef PCONTEXT LPCONTEXT;
typedef PEXCEPTION_RECORD LPEXCEPTION_RECORD;
typedef PEXCEPTION_POINTERS LPEXCEPTION_POINTERS;
#endif

#define DRIVE_UNKNOWN     0
#define DRIVE_NO_ROOT_DIR 1
#define DRIVE_REMOVABLE   2
#define DRIVE_FIXED       3
#define DRIVE_REMOTE      4
#define DRIVE_CDROM       5
#define DRIVE_RAMDISK     6


#define GetFreeSpace(w)                 (0x100000L)


#define FILE_TYPE_UNKNOWN   0x0000
#define FILE_TYPE_DISK      0x0001
#define FILE_TYPE_CHAR      0x0002
#define FILE_TYPE_PIPE      0x0003
#define FILE_TYPE_REMOTE    0x8000


#define STD_INPUT_HANDLE    (unsigned long)-10
#define STD_OUTPUT_HANDLE   (unsigned long)-11
#define STD_ERROR_HANDLE      (unsigned long)-12

#define NOPARITY            0
#define ODDPARITY           1
#define EVENPARITY          2
#define MARKPARITY          3
#define SPACEPARITY         4

#define ONESTOPBIT          0
#define ONE5STOPBITS        1
#define TWOSTOPBITS         2

#define IGNORE              0       // Ignore signal
#define INFINITE            0xFFFFFFFF  // Infinite timeout

//
// Baud rates at which the communication device operates
//

#define CBR_110             110
#define CBR_300             300
#define CBR_600             600
#define CBR_1200            1200
#define CBR_2400            2400
#define CBR_4800            4800
#define CBR_9600            9600
#define CBR_14400           14400
#define CBR_19200           19200
#define CBR_38400           38400
#define CBR_56000           56000
#define CBR_57600           57600
#define CBR_115200          115200
#define CBR_128000          128000
#define CBR_256000          256000

//
// Error Flags
//

#define CE_RXOVER           0x0001  // Receive Queue overflow
#define CE_OVERRUN          0x0002  // Receive Overrun Error
#define CE_RXPARITY         0x0004  // Receive Parity Error
#define CE_FRAME            0x0008  // Receive Framing error
#define CE_BREAK            0x0010  // Break Detected
#define CE_TXFULL           0x0100  // TX Queue is full
#define CE_PTO              0x0200  // LPTx Timeout
#define CE_IOE              0x0400  // LPTx I/O Error
#define CE_DNS              0x0800  // LPTx Device not selected
#define CE_OOP              0x1000  // LPTx Out-Of-Paper
#define CE_MODE             0x8000  // Requested mode unsupported

#define IE_BADID            (-1)    // Invalid or unsupported id
#define IE_OPEN             (-2)    // Device Already Open
#define IE_NOPEN            (-3)    // Device Not Open
#define IE_MEMORY           (-4)    // Unable to allocate queues
#define IE_DEFAULT          (-5)    // Error in default parameters
#define IE_HARDWARE         (-10)   // Hardware Not Present
#define IE_BYTESIZE         (-11)   // Illegal Byte Size
#define IE_BAUDRATE         (-12)   // Unsupported BaudRate

//
// Events
//

#define EV_RXCHAR           0x0001  // Any Character received
#define EV_RXFLAG           0x0002  // Received certain character
#define EV_TXEMPTY          0x0004  // Transmitt Queue Empty
#define EV_CTS              0x0008  // CTS changed state
#define EV_DSR              0x0010  // DSR changed state
#define EV_RLSD             0x0020  // RLSD changed state
#define EV_BREAK            0x0040  // BREAK received
#define EV_ERR              0x0080  // Line status error occurred
#define EV_RING             0x0100  // Ring signal detected
#define EV_PERR             0x0200  // Printer error occured
#define EV_RX80FULL         0x0400  // Receive buffer is 80 percent full
#define EV_EVENT1           0x0800  // Provider specific event 1
#define EV_EVENT2           0x1000  // Provider specific event 2

//
// Escape Functions
//

#define SETXOFF             1       // Simulate XOFF received
#define SETXON              2       // Simulate XON received
#define SETRTS              3       // Set RTS high
#define CLRRTS              4       // Set RTS low
#define SETDTR              5       // Set DTR high
#define CLRDTR              6       // Set DTR low
#define RESETDEV            7       // Reset device if possible
#define SETBREAK            8       // Set the device break line.
#define CLRBREAK            9       // Clear the device break line.

//
// PURGE function flags.
//
#define PURGE_TXABORT       0x0001  // Kill the pending/current writes to the comm port.
#define PURGE_RXABORT       0x0002  // Kill the pending/current reads to the comm port.
#define PURGE_TXCLEAR       0x0004  // Kill the transmit queue if there.
#define PURGE_RXCLEAR       0x0008  // Kill the typeahead buffer if there.

#define LPTx                0x80    // Set if ID is for LPT device

//
// Modem Status Flags
//
#define MS_CTS_ON           ((unsigned long)0x0010)
#define MS_DSR_ON           ((unsigned long)0x0020)
#define MS_RING_ON          ((unsigned long)0x0040)
#define MS_RLSD_ON          ((unsigned long)0x0080)

//
// WaitSoundState() Constants
//

#define S_QUEUEEMPTY        0
#define S_THRESHOLD         1
#define S_ALLTHRESHOLD      2

//
// Accent Modes
//

#define S_NORMAL      0
#define S_LEGATO      1
#define S_STACCATO    2

//
// SetSoundNoise() Sources
//

#define S_PERIOD512   0     // Freq = N/512 high pitch, less coarse hiss
#define S_PERIOD1024  1     // Freq = N/1024
#define S_PERIOD2048  2     // Freq = N/2048 low pitch, more coarse hiss
#define S_PERIODVOICE 3     // Source is frequency from voice channel (3)
#define S_WHITE512    4     // Freq = N/512 high pitch, less coarse hiss
#define S_WHITE1024   5     // Freq = N/1024
#define S_WHITE2048   6     // Freq = N/2048 low pitch, more coarse hiss
#define S_WHITEVOICE  7     // Source is frequency from voice channel (3)

#define S_SERDVNA     (-1)  // Device not available
#define S_SEROFM      (-2)  // Out of memory
#define S_SERMACT     (-3)  // Music active
#define S_SERQFUL     (-4)  // Queue full
#define S_SERBDNT     (-5)  // Invalid note
#define S_SERDLN      (-6)  // Invalid note length
#define S_SERDCC      (-7)  // Invalid note count
#define S_SERDTP      (-8)  // Invalid tempo
#define S_SERDVL      (-9)  // Invalid volume
#define S_SERDMD      (-10) // Invalid mode
#define S_SERDSH      (-11) // Invalid shape
#define S_SERDPT      (-12) // Invalid pitch
#define S_SERDFQ      (-13) // Invalid frequency
#define S_SERDDR      (-14) // Invalid duration
#define S_SERDSR      (-15) // Invalid source
#define S_SERDST      (-16) // Invalid state

#define NMPWAIT_WAIT_FOREVER            0xffffffff
#define NMPWAIT_NOWAIT                  0x00000001
#define NMPWAIT_USE_DEFAULT_WAIT        0x00000000

#define FS_CASE_IS_PRESERVED            FILE_CASE_PRESERVED_NAMES
#define FS_CASE_SENSITIVE               FILE_CASE_SENSITIVE_SEARCH
#define FS_UNICODE_STORED_ON_DISK       FILE_UNICODE_ON_DISK
#define FS_PERSISTENT_ACLS              FILE_PERSISTENT_ACLS
#define FS_VOL_IS_COMPRESSED            FILE_VOLUME_IS_COMPRESSED
#define FS_FILE_COMPRESSION             FILE_FILE_COMPRESSION






#define FILE_MAP_COPY       SECTION_QUERY
#define FILE_MAP_WRITE      SECTION_MAP_WRITE
#define FILE_MAP_READ       SECTION_MAP_READ
#define FILE_MAP_ALL_ACCESS SECTION_ALL_ACCESS

#define OF_READ             0x00000000
#define OF_WRITE            0x00000001
#define OF_READWRITE        0x00000002
#define OF_SHARE_COMPAT     0x00000000
#define OF_SHARE_EXCLUSIVE  0x00000010
#define OF_SHARE_DENY_WRITE 0x00000020
#define OF_SHARE_DENY_READ  0x00000030
#define OF_SHARE_DENY_NONE  0x00000040
#define OF_PARSE            0x00000100
#define OF_DELETE           0x00000200
#define OF_VERIFY           0x00000400
#define OF_CANCEL           0x00000800
#define OF_CREATE           0x00001000
#define OF_PROMPT           0x00002000
#define OF_EXIST            0x00004000
#define OF_REOPEN           0x00008000

#define OFS_MAXPATHNAME 128
typedef struct _OFSTRUCT {
    BYTE cBytes;
    BYTE fFixedDisk;
    WORD nErrCode;
    WORD Reserved1;
    WORD Reserved2;
    char szPathName[OFS_MAXPATHNAME];
} OFSTRUCT, *LPOFSTRUCT, *POFSTRUCT;

//
// The MS-MIPS and Alpha compilers support intrinsic functions for interlocked
// increment, decrement, and exchange.
//

#if (defined(_M_MRX000) || defined(_M_ALPHA) || (defined(_M_PPC) && (_MSC_VER >= 1000))) && !defined(RC_INVOKED)

#define InterlockedIncrement _InterlockedIncrement
#define InterlockedDecrement _InterlockedDecrement
#define InterlockedExchange _InterlockedExchange
#define InterlockedExchangeAdd _InterlockedExchangeAdd
#define InterlockedCompareExchange _InterlockedCompareExchange

long
__stdcall
InterlockedIncrement(
    long* lpAddend
    );

long
__stdcall
InterlockedDecrement(
    long* lpAddend
    );

long
__stdcall
InterlockedExchange(
    long* Target,
    long Value
    );

void*
__stdcall
InterlockedCompareExchange (
    void** Destination,
    void* Exchange,
    void* Comperand
    );

long
__stdcall
InterlockedExchangeAdd(
    long* Addend,
    long Value
    );

#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)
#pragma intrinsic(_InterlockedExchange)
#pragma intrinsic(_InterlockedCompareExchange)
#pragma intrinsic(_InterlockedExchangeAdd)

#else

#ifndef _NTOS_

/*WINBASEAPI*/
long
__stdcall
InterlockedIncrement(
    long* lpAddend
    );

/*WINBASEAPI*/
long
__stdcall
InterlockedDecrement(
    long* lpAddend
    );

/*WINBASEAPI*/
long
__stdcall
InterlockedExchange(
    long* Target,
    long Value
    );

/*WINBASEAPI*/
long
__stdcall
InterlockedExchangeAdd(
    long* Addend,
    long Value
    );

/*WINBASEAPI*/
void*
__stdcall
InterlockedCompareExchange (
    void** Destination,
    void* Exchange,
    void* Comperand
    );

#endif /* NT_INCLUDED */

#endif

/*WINBASEAPI*/
BOOL
__stdcall
FreeResource(
        HGLOBAL hResData
        );

/*WINBASEAPI*/
void*
__stdcall
LockResource(
        HGLOBAL hResData
        );

#define UnlockResource(hResData) ((hResData), 0)
#define MAXINTATOM 0xC000
#define MAKEINTATOM(i)  (LPTSTR)((unsigned long)((WORD)(i)))
#define INVALID_ATOM ((ATOM)0)

int
__stdcall
WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    char* lpCmdLine,
    int nShowCmd
    );

/*WINBASEAPI*/
BOOL
__stdcall
FreeLibrary(
    HMODULE hLibModule
    );


/*WINBASEAPI*/
void
__stdcall
FreeLibraryAndExitThread(
    HMODULE hLibModule,
    unsigned long dwExitCode
    );

/*WINBASEAPI*/
BOOL
__stdcall
DisableThreadLibraryCalls(
    HMODULE hLibModule
    );

/*WINBASEAPI*/
FARPROC
__stdcall
GetProcAddress(
    HMODULE hModule,
    const char* lpProcName
    );

/*WINBASEAPI*/
unsigned long
__stdcall
GetVersion( void );

/*WINBASEAPI*/
HGLOBAL
__stdcall
GlobalAlloc(
    unsigned uFlags,
    unsigned long dwBytes
    );

/*WINBASEAPI*/
HGLOBAL
__stdcall
GlobalReAlloc(
    HGLOBAL hMem,
    unsigned long dwBytes,
    unsigned uFlags
    );

/*WINBASEAPI*/
unsigned long
__stdcall
GlobalSize(
    HGLOBAL hMem
    );

/*WINBASEAPI*/
unsigned
__stdcall
GlobalFlags(
    HGLOBAL hMem
    );


/*WINBASEAPI*/
void*
__stdcall
GlobalLock(
    HGLOBAL hMem
    );

//!!!MWH My version  win31 = unsigned long __stdcall GlobalHandle(unsigned)
/*WINBASEAPI*/
HGLOBAL
__stdcall
GlobalHandle(
    const void* pMem
    );


/*WINBASEAPI*/
BOOL
__stdcall
GlobalUnlock(
    HGLOBAL hMem
    );


/*WINBASEAPI*/
HGLOBAL
__stdcall
GlobalFree(
    HGLOBAL hMem
    );

/*WINBASEAPI*/
unsigned
__stdcall
GlobalCompact(
    unsigned long dwMinFree
    );

/*WINBASEAPI*/
void
__stdcall
GlobalFix(
    HGLOBAL hMem
    );

/*WINBASEAPI*/
void
__stdcall
GlobalUnfix(
    HGLOBAL hMem
    );

/*WINBASEAPI*/
void*
__stdcall
GlobalWire(
    HGLOBAL hMem
    );

/*WINBASEAPI*/
BOOL
__stdcall
GlobalUnWire(
    HGLOBAL hMem
    );

/*WINBASEAPI*/
void
__stdcall
GlobalMemoryStatus(
    LPMEMORYSTATUS lpBuffer
    );

/*WINBASEAPI*/
HLOCAL
__stdcall
LocalAlloc(
    unsigned uFlags,
    unsigned uBytes
    );

/*WINBASEAPI*/
HLOCAL
__stdcall
LocalReAlloc(
    HLOCAL hMem,
    unsigned uBytes,
    unsigned uFlags
    );

/*WINBASEAPI*/
void*
__stdcall
LocalLock(
    HLOCAL hMem
    );

/*WINBASEAPI*/
HLOCAL
__stdcall
LocalHandle(
    const void* pMem
    );

/*WINBASEAPI*/
BOOL
__stdcall
LocalUnlock(
    HLOCAL hMem
    );

/*WINBASEAPI*/
unsigned
__stdcall
LocalSize(
    HLOCAL hMem
    );

/*WINBASEAPI*/
unsigned
__stdcall
LocalFlags(
    HLOCAL hMem
    );

/*WINBASEAPI*/
HLOCAL
__stdcall
LocalFree(
    HLOCAL hMem
    );

/*WINBASEAPI*/
unsigned
__stdcall
LocalShrink(
    HLOCAL hMem,
    unsigned cbNewSize
    );

/*WINBASEAPI*/
unsigned
__stdcall
LocalCompact(
    unsigned uMinFree
    );

/*WINBASEAPI*/
BOOL
__stdcall
FlushInstructionCache(
    HANDLE hProcess,
    const void* lpBaseAddress,
    unsigned long dwSize
    );

/*WINBASEAPI*/
void*
__stdcall
VirtualAlloc(
    void* lpAddress,
    unsigned long dwSize,
    unsigned long flAllocationType,
    unsigned long flProtect
    );

/*WINBASEAPI*/
BOOL
__stdcall
VirtualFree(
    void* lpAddress,
    unsigned long dwSize,
    unsigned long dwFreeType
    );

/*WINBASEAPI*/
BOOL
__stdcall
VirtualProtect(
    void* lpAddress,
    unsigned long dwSize,
    unsigned long flNewProtect,
    unsigned long* lpflOldProtect
    );

/*WINBASEAPI*/
unsigned long
__stdcall
VirtualQuery(
    const void* lpAddress,
    PMEMORY_BASIC_INFORMATION lpBuffer,
    unsigned long dwLength
    );

/*WINBASEAPI*/
void*
__stdcall
VirtualAllocEx(
    HANDLE hProcess,
    void* lpAddress,
    unsigned long dwSize,
    unsigned long flAllocationType,
    unsigned long flProtect
    );

/*WINBASEAPI*/
BOOL
__stdcall
VirtualFreeEx(
    HANDLE hProcess,
    void* lpAddress,
    unsigned long dwSize,
    unsigned long dwFreeType
    );

/*WINBASEAPI*/
BOOL
__stdcall
VirtualProtectEx(
    HANDLE hProcess,
    void* lpAddress,
    unsigned long dwSize,
    unsigned long flNewProtect,
    unsigned long* lpflOldProtect
    );

/*WINBASEAPI*/
unsigned long
__stdcall
VirtualQueryEx(
    HANDLE hProcess,
    const void* lpAddress,
    PMEMORY_BASIC_INFORMATION lpBuffer,
    unsigned long dwLength
    );

/*WINBASEAPI*/
HANDLE
__stdcall
HeapCreate(
    unsigned long flOptions,
    unsigned long dwInitialSize,
    unsigned long dwMaximumSize
    );

/*WINBASEAPI*/
BOOL
__stdcall
HeapDestroy(
    HANDLE hHeap
    );


/*WINBASEAPI*/
void*
__stdcall
HeapAlloc(
    HANDLE hHeap,
    unsigned long dwFlags,
    unsigned long dwBytes
    );

/*WINBASEAPI*/
void*
__stdcall
HeapReAlloc(
    HANDLE hHeap,
    unsigned long dwFlags,
    void* lpMem,
    unsigned long dwBytes
    );

/*WINBASEAPI*/
BOOL
__stdcall
HeapFree(
    HANDLE hHeap,
    unsigned long dwFlags,
    void* lpMem
    );

/*WINBASEAPI*/
unsigned long
__stdcall
HeapSize(
    HANDLE hHeap,
    unsigned long dwFlags,
    const void* lpMem
    );

/*WINBASEAPI*/
BOOL
__stdcall
HeapValidate(
    HANDLE hHeap,
    unsigned long dwFlags,
    const void* lpMem
    );

/*WINBASEAPI*/
unsigned
__stdcall
HeapCompact(
    HANDLE hHeap,
    unsigned long dwFlags
    );

/*WINBASEAPI*/
HANDLE
__stdcall
GetProcessHeap( void );

/*WINBASEAPI*/
unsigned long
__stdcall
GetProcessHeaps(
    unsigned long NumberOfHeaps,
    HANDLE* ProcessHeaps
    );

typedef struct _PROCESS_HEAP_ENTRY {
    void* lpData;
    unsigned long cbData;
    BYTE cbOverhead;
    BYTE iRegionIndex;
    WORD wFlags;
    union {
        struct {
            HANDLE hMem;
            unsigned long dwReserved[ 3 ];
        } Block;
        struct {
            unsigned long dwCommittedSize;
            unsigned long dwUnCommittedSize;
            void* lpFirstBlock;
            void* lpLastBlock;
        } Region;
    };
} PROCESS_HEAP_ENTRY, *LPPROCESS_HEAP_ENTRY, *PPROCESS_HEAP_ENTRY;

#define PROCESS_HEAP_REGION             0x0001
#define PROCESS_HEAP_UNCOMMITTED_RANGE  0x0002
#define PROCESS_HEAP_ENTRY_BUSY         0x0004
#define PROCESS_HEAP_ENTRY_MOVEABLE     0x0010
#define PROCESS_HEAP_ENTRY_DDESHARE     0x0020

/*WINBASEAPI*/
BOOL
__stdcall
HeapLock(
    HANDLE hHeap
    );

/*WINBASEAPI*/
BOOL
__stdcall
HeapUnlock(
    HANDLE hHeap
    );


/*WINBASEAPI*/
BOOL
__stdcall
HeapWalk(
    HANDLE hHeap,
    LPPROCESS_HEAP_ENTRY lpEntry
    );

// GetBinaryType return values.

#define SCS_32BIT_BINARY    0
#define SCS_DOS_BINARY      1
#define SCS_WOW_BINARY      2
#define SCS_PIF_BINARY      3
#define SCS_POSIX_BINARY    4
#define SCS_OS216_BINARY    5

/*WINBASEAPI*/
BOOL
__stdcall
GetBinaryTypeA(
    const char* lpApplicationName,
    unsigned long* lpBinaryType
    );
/*WINBASEAPI*/
BOOL
__stdcall
GetBinaryTypeW(
    const wchar_t* lpApplicationName,
    unsigned long* lpBinaryType
    );
#ifdef UNICODE
#define GetBinaryType  GetBinaryTypeW
#else
#define GetBinaryType  GetBinaryTypeA
#endif // !UNICODE

/*WINBASEAPI*/
unsigned long
__stdcall
GetShortPathNameA(
    const char* lpszLongPath,
    char*  lpszShortPath,
    unsigned long    cchBuffer
    );
/*WINBASEAPI*/
unsigned long
__stdcall
GetShortPathNameW(
    const wchar_t* lpszLongPath,
    wchar_t*  lpszShortPath,
    unsigned long    cchBuffer
    );
#ifdef UNICODE
#define GetShortPathName  GetShortPathNameW
#else
#define GetShortPathName  GetShortPathNameA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
GetProcessAffinityMask(
    HANDLE hProcess,
    unsigned long* lpProcessAffinityMask,
    unsigned long* lpSystemAffinityMask
    );

/*WINBASEAPI*/
BOOL
__stdcall
SetProcessAffinityMask(
    HANDLE hProcess,
    unsigned long dwProcessAffinityMask
    );


/*WINBASEAPI*/
BOOL
__stdcall
GetProcessTimes(
    HANDLE hProcess,
    FILETIME* lpCreationTime,
    FILETIME* lpExitTime,
    FILETIME* lpKernelTime,
    FILETIME* lpUserTime
    );

/*WINBASEAPI*/
BOOL
__stdcall
GetProcessWorkingSetSize(
    HANDLE hProcess,
    unsigned long* lpMinimumWorkingSetSize,
    unsigned long* lpMaximumWorkingSetSize
    );

/*WINBASEAPI*/
BOOL
__stdcall
SetProcessWorkingSetSize(
    HANDLE hProcess,
    unsigned long dwMinimumWorkingSetSize,
    unsigned long dwMaximumWorkingSetSize
    );

/*WINBASEAPI*/
HANDLE
__stdcall
OpenProcess(
    unsigned long dwDesiredAccess,
    BOOL bInheritHandle,
    unsigned long dwProcessId
    );

/*WINBASEAPI*/
HANDLE
__stdcall
GetCurrentProcess(
    void
    );

/*WINBASEAPI*/
unsigned long
__stdcall
GetCurrentProcessId(
    void
    );

/*WINBASEAPI*/
void
__stdcall
ExitProcess(
    unsigned uExitCode
    );

/*WINBASEAPI*/
BOOL
__stdcall
TerminateProcess(
    HANDLE hProcess,
    unsigned uExitCode
    );

/*WINBASEAPI*/
BOOL
__stdcall
GetExitCodeProcess(
    HANDLE hProcess,
    unsigned long* lpExitCode
    );


/*WINBASEAPI*/
void
__stdcall
FatalExit(
    int ExitCode
    );

/*WINBASEAPI*/
char*
__stdcall
GetEnvironmentStrings(
    void
    );

/*WINBASEAPI*/
wchar_t*
__stdcall
GetEnvironmentStringsW(
    void
    );

#ifdef UNICODE
#define GetEnvironmentStrings  GetEnvironmentStringsW
#else
#define GetEnvironmentStringsA  GetEnvironmentStrings
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
FreeEnvironmentStringsA(
    char*
    );
/*WINBASEAPI*/
BOOL
__stdcall
FreeEnvironmentStringsW(
    wchar_t*
    );
#ifdef UNICODE
#define FreeEnvironmentStrings  FreeEnvironmentStringsW
#else
#define FreeEnvironmentStrings  FreeEnvironmentStringsA
#endif // !UNICODE

/*WINBASEAPI*/
void
__stdcall
RaiseException(
    unsigned long dwExceptionCode,
    unsigned long dwExceptionFlags,
    unsigned long nNumberOfArguments,
    const unsigned long* lpArguments
    );

/*WINBASEAPI*/
long
__stdcall
UnhandledExceptionFilter(
    struct _EXCEPTION_POINTERS* ExceptionInfo
    );

typedef long (__stdcall* PTOP_LEVEL_EXCEPTION_FILTER)(
    struct _EXCEPTION_POINTERS* ExceptionInfo
    );
typedef PTOP_LEVEL_EXCEPTION_FILTER LPTOP_LEVEL_EXCEPTION_FILTER;

/*WINBASEAPI*/
LPTOP_LEVEL_EXCEPTION_FILTER
__stdcall
SetUnhandledExceptionFilter(
    LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter
    );

#if(_WIN32_WINNT >= 0x0400)
/*WINBASEAPI*/
void*
__stdcall
CreateFiber(
    unsigned long dwStackSize,
    LPFIBER_START_ROUTINE lpStartAddress,
    void* lpParameter
    );

/*WINBASEAPI*/
void
__stdcall
DeleteFiber(
    void* lpFiber
    );

/*WINBASEAPI*/
void*
__stdcall
ConvertThreadToFiber(
    void* lpParameter
    );

/*WINBASEAPI*/
void
__stdcall
SwitchToFiber(
    void* lpFiber
    );

/*WINBASEAPI*/
BOOL
__stdcall
SwitchToThread(
    void
    );
#endif /* _WIN32_WINNT >= 0x0400 */

/*WINBASEAPI*/
HANDLE
__stdcall
CreateThread(
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    unsigned long dwStackSize,
    LPTHREAD_START_ROUTINE lpStartAddress,
    void* lpParameter,
    unsigned long dwCreationFlags,
    unsigned long* lpThreadId
    );

/*WINBASEAPI*/
HANDLE
__stdcall
CreateRemoteThread(
    HANDLE hProcess,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    unsigned long dwStackSize,
    LPTHREAD_START_ROUTINE lpStartAddress,
    void* lpParameter,
    unsigned long dwCreationFlags,
    unsigned long* lpThreadId
    );

/*WINBASEAPI*/
HANDLE
__stdcall
GetCurrentThread(
    void
    );

/*WINBASEAPI*/
unsigned long
__stdcall
GetCurrentThreadId(
    void
    );

/*WINBASEAPI*/
unsigned long
__stdcall
SetThreadAffinityMask(
    HANDLE hThread,
    unsigned long dwThreadAffinityMask
    );

#if(_WIN32_WINNT >= 0x0400)
/*WINBASEAPI*/
unsigned long
__stdcall
SetThreadIdealProcessor(
    HANDLE hThread,
    unsigned long dwIdealProcessor
    );
#endif /* _WIN32_WINNT >= 0x0400 */

/*WINBASEAPI*/
BOOL
__stdcall
SetProcessPriorityBoost(
    HANDLE hProcess,
    BOOL bDisablePriorityBoost
    );

/*WINBASEAPI*/
BOOL
__stdcall
GetProcessPriorityBoost(
    HANDLE hProcess,
    PBOOL pDisablePriorityBoost
    );


/*WINBASEAPI*/
BOOL
__stdcall
SetThreadPriority(
    HANDLE hThread,
    int nPriority
    );

/*WINBASEAPI*/
BOOL
__stdcall
SetThreadPriorityBoost(
    HANDLE hThread,
    BOOL bDisablePriorityBoost
    );

/*WINBASEAPI*/
BOOL
__stdcall
GetThreadPriorityBoost(
    HANDLE hThread,
    PBOOL pDisablePriorityBoost
    );

/*WINBASEAPI*/
int
__stdcall
GetThreadPriority(
    HANDLE hThread
    );

/*WINBASEAPI*/
BOOL
__stdcall
GetThreadTimes(
    HANDLE hThread,
    FILETIME* lpCreationTime,
    FILETIME* lpExitTime,
    FILETIME* lpKernelTime,
    FILETIME* lpUserTime
    );

/*WINBASEAPI*/
void
__stdcall
ExitThread(
    unsigned long dwExitCode
    );

/*WINBASEAPI*/
BOOL
__stdcall
TerminateThread(
    HANDLE hThread,
    unsigned long dwExitCode
    );

/*WINBASEAPI*/
BOOL
__stdcall
GetExitCodeThread(
    HANDLE hThread,
    unsigned long* lpExitCode
    );

/*WINBASEAPI*/
BOOL
__stdcall
GetThreadSelectorEntry(
    HANDLE hThread,
    unsigned long dwSelector,
    LPLDT_ENTRY lpSelectorEntry
    );

/*WINBASEAPI*/
unsigned long
__stdcall
GetLastError(
    void
    );

/*WINBASEAPI*/
void
__stdcall
SetLastError(
    unsigned long dwErrCode
    );

#define HasOverlappedIoCompleted(lpOverlapped) ((lpOverlapped)->Internal != STATUS_PENDING)

/*WINBASEAPI*/
BOOL
__stdcall
GetOverlappedResult(
    HANDLE hFile,
    OVERLAPPED* lpOverlapped,
    unsigned long* lpNumberOfBytesTransferred,
    BOOL bWait
    );

/*WINBASEAPI*/
HANDLE
__stdcall
CreateIoCompletionPort(
    HANDLE FileHandle,
    HANDLE ExistingCompletionPort,
    unsigned long CompletionKey,
    unsigned long NumberOfConcurrentThreads
    );

/*WINBASEAPI*/
BOOL
__stdcall
GetQueuedCompletionStatus(
    HANDLE CompletionPort,
    unsigned long* lpNumberOfBytesTransferred,
    unsigned long* lpCompletionKey,
    OVERLAPPED** lpOverlapped,
    unsigned long dwMilliseconds
    );

/*WINBASEAPI*/
BOOL
__stdcall
PostQueuedCompletionStatus(
    HANDLE CompletionPort,
    unsigned long dwNumberOfBytesTransferred,
    unsigned long dwCompletionKey,
    OVERLAPPED* lpOverlapped
    );

#define SEM_FAILCRITICALERRORS      0x0001
#define SEM_NOGPFAULTERRORBOX       0x0002
#define SEM_NOALIGNMENTFAULTEXCEPT  0x0004
#define SEM_NOOPENFILEERRORBOX      0x8000

/*WINBASEAPI*/
unsigned
__stdcall
SetErrorMode(
    unsigned uMode
    );

/*WINBASEAPI*/
BOOL
__stdcall
ReadProcessMemory(
    HANDLE hProcess,
    const void* lpBaseAddress,
    void* lpBuffer,
    unsigned long nSize,
    unsigned long* lpNumberOfBytesRead
    );

/*WINBASEAPI*/
BOOL
__stdcall
WriteProcessMemory(
    HANDLE hProcess,
    void* lpBaseAddress,
    void* lpBuffer,
    unsigned long nSize,
    unsigned long* lpNumberOfBytesWritten
    );

#if !defined(MIDL_PASS)
/*WINBASEAPI*/
BOOL
__stdcall
GetThreadContext(
    HANDLE hThread,
    LPCONTEXT lpContext
    );

/*WINBASEAPI*/
BOOL
__stdcall
SetThreadContext(
    HANDLE hThread,
    const CONTEXT* lpContext
    );
#endif

/*WINBASEAPI*/
unsigned long
__stdcall
SuspendThread(
    HANDLE hThread
    );

/*WINBASEAPI*/
unsigned long
__stdcall
ResumeThread(
    HANDLE hThread
    );


#if(_WIN32_WINNT >= 0x0400)
typedef
void
(__stdcall* PAPCFUNC)(
    unsigned long dwParam
    );

/*WINBASEAPI*/
unsigned long
__stdcall
QueueUserAPC(
    PAPCFUNC pfnAPC,
    HANDLE hThread,
    unsigned long dwData
    );
#endif /* _WIN32_WINNT >= 0x0400 */

/*WINBASEAPI*/
void
__stdcall
DebugBreak(
    void
    );

/*WINBASEAPI*/
BOOL
__stdcall
WaitForDebugEvent(
    LPDEBUG_EVENT lpDebugEvent,
    unsigned long dwMilliseconds
    );

/*WINBASEAPI*/
BOOL
__stdcall
ContinueDebugEvent(
    unsigned long dwProcessId,
    unsigned long dwThreadId,
    unsigned long dwContinueStatus
    );

/*WINBASEAPI*/
BOOL
__stdcall
DebugActiveProcess(
    unsigned long dwProcessId
    );

/*WINBASEAPI*/
void
__stdcall
InitializeCriticalSection(
    CRITICAL_SECTION* lpCriticalSection
    );

/*WINBASEAPI*/
void
__stdcall
EnterCriticalSection(
    CRITICAL_SECTION* lpCriticalSection
    );

/*WINBASEAPI*/
void
__stdcall
LeaveCriticalSection(
    CRITICAL_SECTION* lpCriticalSection
    );

#if(_WIN32_WINNT >= 0x0400)
WINBASEAPI
BOOL
__stdcall
TryEnterCriticalSection(
    CRITICAL_SECTION* lpCriticalSection
    );
#endif /* _WIN32_WINNT >= 0x0400 */

/*WINBASEAPI*/
void
__stdcall
DeleteCriticalSection(
    CRITICAL_SECTION* lpCriticalSection
    );

/*WINBASEAPI*/
BOOL
__stdcall
SetEvent(
    HANDLE hEvent
    );

/*WINBASEAPI*/
BOOL
__stdcall
ResetEvent(
    HANDLE hEvent
    );

/*WINBASEAPI*/
BOOL
__stdcall
PulseEvent(
    HANDLE hEvent
    );

/*WINBASEAPI*/
BOOL
__stdcall
ReleaseSemaphore(
    HANDLE hSemaphore,
    long lReleaseCount,
    long* lpPreviousCount
    );

/*WINBASEAPI*/
BOOL
__stdcall
ReleaseMutex(
    HANDLE hMutex
    );

/*WINBASEAPI*/
unsigned long
__stdcall
WaitForSingleObject(
    HANDLE hHandle,
    unsigned long dwMilliseconds
    );

/*WINBASEAPI*/
unsigned long
__stdcall
WaitForMultipleObjects(
    unsigned long nCount,
    const HANDLE* lpHandles,
    BOOL bWaitAll,
    unsigned long dwMilliseconds
    );

/*WINBASEAPI*/
void
__stdcall
Sleep(
    unsigned long dwMilliseconds
    );

/*WINBASEAPI*/
HGLOBAL
__stdcall
LoadResource(
    HMODULE hModule,
    HRSRC hResInfo
    );

/*WINBASEAPI*/
unsigned long
__stdcall
SizeofResource(
    HMODULE hModule,
    HRSRC hResInfo
    );


/*WINBASEAPI*/
ATOM
__stdcall
GlobalDeleteAtom(
    ATOM nAtom
    );

/*WINBASEAPI*/
BOOL
__stdcall
InitAtomTable(
    unsigned long nSize
    );

/*WINBASEAPI*/
ATOM
__stdcall
DeleteAtom(
    ATOM nAtom
    );

/*WINBASEAPI*/
unsigned
__stdcall
SetHandleCount(
    unsigned uNumber
    );

/*WINBASEAPI*/
unsigned long
__stdcall
GetLogicalDrives(
    void
    );

/*WINBASEAPI*/
BOOL
__stdcall
LockFile(
    HANDLE hFile,
    unsigned long dwFileOffsetLow,
    unsigned long dwFileOffsetHigh,
    unsigned long nNumberOfBytesToLockLow,
    unsigned long nNumberOfBytesToLockHigh
    );

/*WINBASEAPI*/
BOOL
__stdcall
UnlockFile(
    HANDLE hFile,
    unsigned long dwFileOffsetLow,
    unsigned long dwFileOffsetHigh,
    unsigned long nNumberOfBytesToUnlockLow,
    unsigned long nNumberOfBytesToUnlockHigh
    );

/*WINBASEAPI*/
BOOL
__stdcall
LockFileEx(
    HANDLE hFile,
    unsigned long dwFlags,
    unsigned long dwReserved,
    unsigned long nNumberOfBytesToLockLow,
    unsigned long nNumberOfBytesToLockHigh,
    OVERLAPPED* lpOverlapped
    );

#define LOCKFILE_FAIL_IMMEDIATELY   0x00000001
#define LOCKFILE_EXCLUSIVE_LOCK     0x00000002

/*WINBASEAPI*/
BOOL
__stdcall
UnlockFileEx(
    HANDLE hFile,
    unsigned long dwReserved,
    unsigned long nNumberOfBytesToUnlockLow,
    unsigned long nNumberOfBytesToUnlockHigh,
    OVERLAPPED* lpOverlapped
    );

typedef struct _BY_HANDLE_FILE_INFORMATION {
    unsigned long dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    unsigned long dwVolumeSerialNumber;
    unsigned long nFileSizeHigh;
    unsigned long nFileSizeLow;
    unsigned long nNumberOfLinks;
    unsigned long nFileIndexHigh;
    unsigned long nFileIndexLow;
} BY_HANDLE_FILE_INFORMATION, *PBY_HANDLE_FILE_INFORMATION, *LPBY_HANDLE_FILE_INFORMATION;

/*WINBASEAPI*/
BOOL
__stdcall
GetFileInformationByHandle(
    HANDLE hFile,
    LPBY_HANDLE_FILE_INFORMATION lpFileInformation
    );

/*WINBASEAPI*/
unsigned long
__stdcall
GetFileType(
    HANDLE hFile
    );

/*WINBASEAPI*/
unsigned long
__stdcall
GetFileSize(
    HANDLE hFile,
    unsigned long* lpFileSizeHigh
    );

/*WINBASEAPI*/
HANDLE
__stdcall
GetStdHandle(
    unsigned long nStdHandle
    );

/*WINBASEAPI*/
BOOL
__stdcall
SetStdHandle(
    unsigned long nStdHandle,
    HANDLE hHandle
    );

/*WINBASEAPI*/
BOOL
__stdcall
WriteFile(
    HANDLE hFile,
    const void* lpBuffer,
    unsigned long nNumberOfBytesToWrite,
    unsigned long* lpNumberOfBytesWritten,
    OVERLAPPED* lpOverlapped
    );

/*WINBASEAPI*/
BOOL
__stdcall
ReadFile(
    HANDLE hFile,
    void* lpBuffer,
    unsigned long nNumberOfBytesToRead,
    unsigned long* lpNumberOfBytesRead,
    OVERLAPPED* lpOverlapped
    );

/*WINBASEAPI*/
BOOL
__stdcall
FlushFileBuffers(
    HANDLE hFile
    );

/*WINBASEAPI*/
BOOL
__stdcall
DeviceIoControl(
    HANDLE hDevice,
    unsigned long dwIoControlCode,
    void* lpInBuffer,
    unsigned long nInBufferSize,
    void* lpOutBuffer,
    unsigned long nOutBufferSize,
    unsigned long* lpBytesReturned,
    OVERLAPPED* lpOverlapped
    );

/*WINBASEAPI*/
BOOL
__stdcall
SetEndOfFile(
    HANDLE hFile
    );

/*WINBASEAPI*/
unsigned long
__stdcall
SetFilePointer(
    HANDLE hFile,
    long lDistanceToMove,
    PLONG lpDistanceToMoveHigh,
    unsigned long dwMoveMethod
    );

/*WINBASEAPI*/
BOOL
__stdcall
FindClose(
    HANDLE hFindFile
    );

/*WINBASEAPI*/
BOOL
__stdcall
GetFileTime(
    HANDLE hFile,
    FILETIME* lpCreationTime,
    FILETIME* lpLastAccessTime,
    FILETIME* lpLastWriteTime
    );

/*WINBASEAPI*/
BOOL
__stdcall
SetFileTime(
    HANDLE hFile,
    const FILETIME* lpCreationTime,
    const FILETIME* lpLastAccessTime,
    const FILETIME* lpLastWriteTime
    );

/*WINBASEAPI*/
BOOL
__stdcall
CloseHandle(
    HANDLE hObject
    );

/*WINBASEAPI*/
BOOL
__stdcall
DuplicateHandle(
    HANDLE hSourceProcessHandle,
    HANDLE hSourceHandle,
    HANDLE hTargetProcessHandle,
    LPHANDLE lpTargetHandle,
    unsigned long dwDesiredAccess,
    BOOL bInheritHandle,
    unsigned long dwOptions
    );

/*WINBASEAPI*/
BOOL
__stdcall
GetHandleInformation(
    HANDLE hObject,
    unsigned long* lpdwFlags
    );

/*WINBASEAPI*/
BOOL
__stdcall
SetHandleInformation(
    HANDLE hObject,
    unsigned long dwMask,
    unsigned long dwFlags
    );

#define HANDLE_FLAG_INHERIT             0x00000001
#define HANDLE_FLAG_PROTECT_FROM_CLOSE  0x00000002

#define HINSTANCE_ERROR 32

/*WINBASEAPI*/
unsigned long
__stdcall
LoadModule(
    const char* lpModuleName,
    void* lpParameterBlock
    );

/*WINBASEAPI*/
unsigned
__stdcall
WinExec(
    const char* lpCmdLine,
    unsigned uCmdShow
    );

/*WINBASEAPI*/
BOOL
__stdcall
ClearCommBreak(
    HANDLE hFile
    );

/*WINBASEAPI*/
BOOL
__stdcall
ClearCommError(
    HANDLE hFile,
    unsigned long* lpErrors,
    LPCOMSTAT lpStat
    );

/*WINBASEAPI*/
BOOL
__stdcall
SetupComm(
    HANDLE hFile,
    unsigned long dwInQueue,
    unsigned long dwOutQueue
    );

/*WINBASEAPI*/
BOOL
__stdcall
EscapeCommFunction(
    HANDLE hFile,
    unsigned long dwFunc
    );

/*WINBASEAPI*/
BOOL
__stdcall
GetCommConfig(
    HANDLE hCommDev,
    LPCOMMCONFIG lpCC,
    unsigned long* lpdwSize
    );

/*WINBASEAPI*/
BOOL
__stdcall
GetCommMask(
    HANDLE hFile,
    unsigned long* lpEvtMask
    );

/*WINBASEAPI*/
BOOL
__stdcall
GetCommProperties(
    HANDLE hFile,
    LPCOMMPROP lpCommProp
    );

/*WINBASEAPI*/
BOOL
__stdcall
GetCommModemStatus(
    HANDLE hFile,
    unsigned long* lpModemStat
    );

/*WINBASEAPI*/
BOOL
__stdcall
GetCommState(
    HANDLE hFile,
    LPDCB lpDCB
    );

/*WINBASEAPI*/
BOOL
__stdcall
GetCommTimeouts(
    HANDLE hFile,
    LPCOMMTIMEOUTS lpCommTimeouts
    );

/*WINBASEAPI*/
BOOL
__stdcall
PurgeComm(
    HANDLE hFile,
    unsigned long dwFlags
    );

/*WINBASEAPI*/
BOOL
__stdcall
SetCommBreak(
    HANDLE hFile
    );

/*WINBASEAPI*/
BOOL
__stdcall
SetCommConfig(
    HANDLE hCommDev,
    LPCOMMCONFIG lpCC,
    unsigned long dwSize
    );

/*WINBASEAPI*/
BOOL
__stdcall
SetCommMask(
    HANDLE hFile,
    unsigned long dwEvtMask
    );

/*WINBASEAPI*/
BOOL
__stdcall
SetCommState(
    HANDLE hFile,
    LPDCB lpDCB
    );

/*WINBASEAPI*/
BOOL
__stdcall
SetCommTimeouts(
    HANDLE hFile,
    LPCOMMTIMEOUTS lpCommTimeouts
    );

/*WINBASEAPI*/
BOOL
__stdcall
TransmitCommChar(
    HANDLE hFile,
    char cChar
    );

/*WINBASEAPI*/
BOOL
__stdcall
WaitCommEvent(
    HANDLE hFile,
    unsigned long* lpEvtMask,
    OVERLAPPED* lpOverlapped
    );


/*WINBASEAPI*/
unsigned long
__stdcall
SetTapePosition(
    HANDLE hDevice,
    unsigned long dwPositionMethod,
    unsigned long dwPartition,
    unsigned long dwOffsetLow,
    unsigned long dwOffsetHigh,
    BOOL bImmediate
    );

/*WINBASEAPI*/
unsigned long
__stdcall
GetTapePosition(
    HANDLE hDevice,
    unsigned long dwPositionType,
    unsigned long* lpdwPartition,
    unsigned long* lpdwOffsetLow,
    unsigned long* lpdwOffsetHigh
    );

/*WINBASEAPI*/
unsigned long
__stdcall
PrepareTape(
    HANDLE hDevice,
    unsigned long dwOperation,
    BOOL bImmediate
    );

/*WINBASEAPI*/
unsigned long
__stdcall
EraseTape(
    HANDLE hDevice,
    unsigned long dwEraseType,
    BOOL bImmediate
    );

/*WINBASEAPI*/
unsigned long
__stdcall
CreateTapePartition(
    HANDLE hDevice,
    unsigned long dwPartitionMethod,
    unsigned long dwCount,
    unsigned long dwSize
    );

/*WINBASEAPI*/
unsigned long
__stdcall
WriteTapemark(
    HANDLE hDevice,
    unsigned long dwTapemarkType,
    unsigned long dwTapemarkCount,
    BOOL bImmediate
    );

/*WINBASEAPI*/
unsigned long
__stdcall
GetTapeStatus(
    HANDLE hDevice
    );

/*WINBASEAPI*/
unsigned long
__stdcall
GetTapeParameters(
    HANDLE hDevice,
    unsigned long dwOperation,
    unsigned long* lpdwSize,
    void* lpTapeInformation
    );

#define GET_TAPE_MEDIA_INFORMATION 0
#define GET_TAPE_DRIVE_INFORMATION 1

/*WINBASEAPI*/
unsigned long
__stdcall
SetTapeParameters(
    HANDLE hDevice,
    unsigned long dwOperation,
    void* lpTapeInformation
    );

#define SET_TAPE_MEDIA_INFORMATION 0
#define SET_TAPE_DRIVE_INFORMATION 1

/*WINBASEAPI*/
BOOL
__stdcall
Beep(
    unsigned long dwFreq,
    unsigned long dwDuration
    );

/*WINBASEAPI*/
int
__stdcall
MulDiv(
    int nNumber,
    int nNumerator,
    int nDenominator
    );

/*WINBASEAPI*/
void
__stdcall
GetSystemTime(
    LPSYSTEMTIME lpSystemTime
    );

/*WINBASEAPI*/
void
__stdcall
GetSystemTimeAsFileTime(
    FILETIME* lpSystemTimeAsFileTime
    );

/*WINBASEAPI*/
BOOL
__stdcall
SetSystemTime(
    const SYSTEMTIME* lpSystemTime
    );

/*WINBASEAPI*/
void
__stdcall
GetLocalTime(
    LPSYSTEMTIME lpSystemTime
    );

/*WINBASEAPI*/
BOOL
__stdcall
SetLocalTime(
    const SYSTEMTIME* lpSystemTime
    );

/*WINBASEAPI*/
void
__stdcall
GetSystemInfo(
    LPSYSTEM_INFO lpSystemInfo
    );

/*WINBASEAPI*/
BOOL
__stdcall
IsProcessorFeaturePresent(
    unsigned long ProcessorFeature
    );

typedef struct _TIME_ZONE_INFORMATION {
    long Bias;
    wchar_t StandardName[ 32 ];
    SYSTEMTIME StandardDate;
    long StandardBias;
    wchar_t DaylightName[ 32 ];
    SYSTEMTIME DaylightDate;
    long DaylightBias;
} TIME_ZONE_INFORMATION, *PTIME_ZONE_INFORMATION, *LPTIME_ZONE_INFORMATION;

/*WINBASEAPI*/
BOOL
__stdcall
SystemTimeToTzSpecificLocalTime(
    LPTIME_ZONE_INFORMATION lpTimeZoneInformation,
    LPSYSTEMTIME lpUniversalTime,
    LPSYSTEMTIME lpLocalTime
    );

/*WINBASEAPI*/
unsigned long
__stdcall
GetTimeZoneInformation(
    LPTIME_ZONE_INFORMATION lpTimeZoneInformation
    );

/*WINBASEAPI*/
BOOL
__stdcall
SetTimeZoneInformation(
    const TIME_ZONE_INFORMATION* lpTimeZoneInformation
    );


//
// Routines to convert back and forth between system time and file time
//

/*WINBASEAPI*/
BOOL
__stdcall
SystemTimeToFileTime(
    const SYSTEMTIME* lpSystemTime,
    FILETIME* lpFileTime
    );

/*WINBASEAPI*/
BOOL
__stdcall
FileTimeToLocalFileTime(
    const FILETIME* lpFileTime,
    FILETIME* lpLocalFileTime
    );

/*WINBASEAPI*/
BOOL
__stdcall
LocalFileTimeToFileTime(
    const FILETIME* lpLocalFileTime,
    FILETIME* lpFileTime
    );

/*WINBASEAPI*/
BOOL
__stdcall
FileTimeToSystemTime(
    const FILETIME* lpFileTime,
    LPSYSTEMTIME lpSystemTime
    );

/*WINBASEAPI*/
long
__stdcall
CompareFileTime(
    const FILETIME* lpFileTime1,
    const FILETIME* lpFileTime2
    );

/*WINBASEAPI*/
BOOL
__stdcall
FileTimeToDosDateTime(
    const FILETIME* lpFileTime,
    LPWORD lpFatDate,
    LPWORD lpFatTime
    );

/*WINBASEAPI*/
BOOL
__stdcall
DosDateTimeToFileTime(
    WORD wFatDate,
    WORD wFatTime,
    FILETIME* lpFileTime
    );

/*WINBASEAPI*/
unsigned long
__stdcall
GetTickCount(
    void
    );

/*WINBASEAPI*/
BOOL
__stdcall
SetSystemTimeAdjustment(
    unsigned long dwTimeAdjustment,
    BOOL  bTimeAdjustmentDisabled
    );

/*WINBASEAPI*/
BOOL
__stdcall
GetSystemTimeAdjustment(
    unsigned long* lpTimeAdjustment,
    unsigned long* lpTimeIncrement,
    PBOOL  lpTimeAdjustmentDisabled
    );

#if !defined(MIDL_PASS)
/*WINBASEAPI*/
unsigned long
__stdcall
FormatMessageA(
    unsigned long dwFlags,
    const void* lpSource,
    unsigned long dwMessageId,
    unsigned long dwLanguageId,
    char* lpBuffer,
    unsigned long nSize,
    va_list* Arguments
    );
/*WINBASEAPI*/
unsigned long
__stdcall
FormatMessageW(
    unsigned long dwFlags,
    const void* lpSource,
    unsigned long dwMessageId,
    unsigned long dwLanguageId,
    wchar_t* lpBuffer,
    unsigned long nSize,
    va_list* Arguments
    );
#ifdef UNICODE
#define FormatMessage  FormatMessageW
#else
#define FormatMessage  FormatMessageA
#endif // !UNICODE
#endif

#define FORMAT_MESSAGE_ALLOCATE_BUFFER 0x00000100
#define FORMAT_MESSAGE_IGNORE_INSERTS  0x00000200
#define FORMAT_MESSAGE_FROM_STRING     0x00000400
#define FORMAT_MESSAGE_FROM_HMODULE    0x00000800
#define FORMAT_MESSAGE_FROM_SYSTEM     0x00001000
#define FORMAT_MESSAGE_ARGUMENT_ARRAY  0x00002000
#define FORMAT_MESSAGE_MAX_WIDTH_MASK  0x000000FF


/*WINBASEAPI*/
BOOL
__stdcall
CreatePipe(
    HANDLE* hReadPipe,
    HANDLE* hWritePipe,
    LPSECURITY_ATTRIBUTES lpPipeAttributes,
    unsigned long nSize
    );

/*WINBASEAPI*/
BOOL
__stdcall
ConnectNamedPipe(
    HANDLE hNamedPipe,
    OVERLAPPED* lpOverlapped
    );

/*WINBASEAPI*/
BOOL
__stdcall
DisconnectNamedPipe(
    HANDLE hNamedPipe
    );

/*WINBASEAPI*/
BOOL
__stdcall
SetNamedPipeHandleState(
    HANDLE hNamedPipe,
    unsigned long* lpMode,
    unsigned long* lpMaxCollectionCount,
    unsigned long* lpCollectDataTimeout
    );

/*WINBASEAPI*/
BOOL
__stdcall
GetNamedPipeInfo(
    HANDLE hNamedPipe,
    unsigned long* lpFlags,
    unsigned long* lpOutBufferSize,
    unsigned long* lpInBufferSize,
    unsigned long* lpMaxInstances
    );

/*WINBASEAPI*/
BOOL
__stdcall
PeekNamedPipe(
    HANDLE hNamedPipe,
    void* lpBuffer,
    unsigned long nBufferSize,
    unsigned long* lpBytesRead,
    unsigned long* lpTotalBytesAvail,
    unsigned long* lpBytesLeftThisMessage
    );

/*WINBASEAPI*/
BOOL
__stdcall
TransactNamedPipe(
    HANDLE hNamedPipe,
    void* lpInBuffer,
    unsigned long nInBufferSize,
    void* lpOutBuffer,
    unsigned long nOutBufferSize,
    unsigned long* lpBytesRead,
    OVERLAPPED* lpOverlapped
    );

/*WINBASEAPI*/
HANDLE
__stdcall
CreateMailslotA(
    const char* lpName,
    unsigned long nMaxMessageSize,
    unsigned long lReadTimeout,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
/*WINBASEAPI*/
HANDLE
__stdcall
CreateMailslotW(
    const wchar_t* lpName,
    unsigned long nMaxMessageSize,
    unsigned long lReadTimeout,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
#ifdef UNICODE
#define CreateMailslot  CreateMailslotW
#else
#define CreateMailslot  CreateMailslotA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
GetMailslotInfo(
    HANDLE hMailslot,
    unsigned long* lpMaxMessageSize,
    unsigned long* lpNextSize,
    unsigned long* lpMessageCount,
    unsigned long* lpReadTimeout
    );

/*WINBASEAPI*/
BOOL
__stdcall
SetMailslotInfo(
    HANDLE hMailslot,
    unsigned long lReadTimeout
    );

/*WINBASEAPI*/
void*
__stdcall
MapViewOfFile(
    HANDLE hFileMappingObject,
    unsigned long dwDesiredAccess,
    unsigned long dwFileOffsetHigh,
    unsigned long dwFileOffsetLow,
    unsigned long dwNumberOfBytesToMap
    );

/*WINBASEAPI*/
BOOL
__stdcall
FlushViewOfFile(
    const void* lpBaseAddress,
    unsigned long dwNumberOfBytesToFlush
    );

/*WINBASEAPI*/
BOOL
__stdcall
UnmapViewOfFile(
    const void* lpBaseAddress
    );


//
// _l Compat Functions
//

/*WINBASEAPI*/
int
__stdcall
lstrcmpA(
    const char* lpString1,
    const char* lpString2
    );
/*WINBASEAPI*/
int
__stdcall
lstrcmpW(
    const wchar_t* lpString1,
    const wchar_t* lpString2
    );
#ifdef UNICODE
#define lstrcmp  lstrcmpW
#else
#define lstrcmp  lstrcmpA
#endif // !UNICODE

/*WINBASEAPI*/
int
__stdcall
lstrcmpiA(
    const char* lpString1,
    const char* lpString2
    );
/*WINBASEAPI*/
int
__stdcall
lstrcmpiW(
    const wchar_t* lpString1,
    const wchar_t* lpString2
    );
#ifdef UNICODE
#define lstrcmpi  lstrcmpiW
#else
#define lstrcmpi  lstrcmpiA
#endif // !UNICODE

/*WINBASEAPI*/
char*
__stdcall
lstrcpynA(
    char* lpString1,
    const char* lpString2,
    int iMaxLength
    );
/*WINBASEAPI*/
wchar_t*
__stdcall
lstrcpynW(
    wchar_t* lpString1,
    const wchar_t* lpString2,
    int iMaxLength
    );
#ifdef UNICODE
#define lstrcpyn  lstrcpynW
#else
#define lstrcpyn  lstrcpynA
#endif // !UNICODE

/*WINBASEAPI*/
char*
__stdcall
lstrcpyA(
    char* lpString1,
    const char* lpString2
    );
/*WINBASEAPI*/
wchar_t*
__stdcall
lstrcpyW(
    wchar_t* lpString1,
    const wchar_t* lpString2
    );
#ifdef UNICODE
#define lstrcpy  lstrcpyW
#else
#define lstrcpy  lstrcpyA
#endif // !UNICODE

/*WINBASEAPI*/
char*
__stdcall
lstrcatA(
    char* lpString1,
    const char* lpString2
    );
/*WINBASEAPI*/
wchar_t*
__stdcall
lstrcatW(
    wchar_t* lpString1,
    const wchar_t* lpString2
    );
#ifdef UNICODE
#define lstrcat  lstrcatW
#else
#define lstrcat  lstrcatA
#endif // !UNICODE

/*WINBASEAPI*/
int
__stdcall
lstrlenA(
    const char* lpString
    );
/*WINBASEAPI*/
int
__stdcall
lstrlenW(
    const wchar_t* lpString
    );
#ifdef UNICODE
#define lstrlen  lstrlenW
#else
#define lstrlen  lstrlenA
#endif // !UNICODE

/*WINBASEAPI*/
HFILE
__stdcall
OpenFile(
    const char* lpFileName,
    LPOFSTRUCT lpReOpenBuff,
    unsigned uStyle
    );

/*WINBASEAPI*/
HFILE
__stdcall
_lopen(
    const char* lpPathName,
    int iReadWrite
    );

/*WINBASEAPI*/
HFILE
__stdcall
_lcreat(
    const char* lpPathName,
    int  iAttribute
    );

/*WINBASEAPI*/
unsigned
__stdcall
_lread(
    HFILE hFile,
    void* lpBuffer,
    unsigned uBytes
    );

/*WINBASEAPI*/
unsigned
__stdcall
_lwrite(
    HFILE hFile,
    const char* lpBuffer,
    unsigned uBytes
    );

/*WINBASEAPI*/
long
__stdcall
_hread(
    HFILE hFile,
    void* lpBuffer,
    long lBytes
    );

/*WINBASEAPI*/
long
__stdcall
_hwrite(
    HFILE hFile,
    const char* lpBuffer,
    long lBytes
    );

/*WINBASEAPI*/
HFILE
__stdcall
_lclose(
    HFILE hFile
    );

/*WINBASEAPI*/
long
__stdcall
_llseek(
    HFILE hFile,
    long lOffset,
    int iOrigin
    );

/*WINADVAPI*/
BOOL
__stdcall
IsTextUnicode(
    const void* lpBuffer,
    int cb,
    LPINT lpi
    );

/*WINBASEAPI*/
unsigned long
__stdcall
TlsAlloc(
    void
    );

#define TLS_OUT_OF_INDEXES (unsigned long)0xFFFFFFFF

/*WINBASEAPI*/
void*
__stdcall
TlsGetValue(
    unsigned long dwTlsIndex
    );

/*WINBASEAPI*/
BOOL
__stdcall
TlsSetValue(
    unsigned long dwTlsIndex,
    void* lpTlsValue
    );

/*WINBASEAPI*/
BOOL
__stdcall
TlsFree(
    unsigned long dwTlsIndex
    );

typedef
void
(__stdcall* LPOVERLAPPED_COMPLETION_ROUTINE)(
    unsigned long dwErrorCode,
    unsigned long dwNumberOfBytesTransfered,
    OVERLAPPED* lpOverlapped
    );

/*WINBASEAPI*/
unsigned long
__stdcall
SleepEx(
    unsigned long dwMilliseconds,
    BOOL bAlertable
    );

/*WINBASEAPI*/
unsigned long
__stdcall
WaitForSingleObjectEx(
    HANDLE hHandle,
    unsigned long dwMilliseconds,
    BOOL bAlertable
    );

/*WINBASEAPI*/
unsigned long
__stdcall
WaitForMultipleObjectsEx(
    unsigned long nCount,
    const HANDLE* lpHandles,
    BOOL bWaitAll,
    unsigned long dwMilliseconds,
    BOOL bAlertable
    );

#if(_WIN32_WINNT >= 0x0400)
/*WINBASEAPI*/
unsigned long
__stdcall
SignalObjectAndWait(
    HANDLE hObjectToSignal,
    HANDLE hObjectToWaitOn,
    unsigned long dwMilliseconds,
    BOOL bAlertable
    );
#endif /* _WIN32_WINNT >= 0x0400 */

/*WINBASEAPI*/
BOOL
__stdcall
ReadFileEx(
    HANDLE hFile,
    void* lpBuffer,
    unsigned long nNumberOfBytesToRead,
    OVERLAPPED* lpOverlapped,
    LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
    );

/*WINBASEAPI*/
BOOL
__stdcall
WriteFileEx(
    HANDLE hFile,
    const void* lpBuffer,
    unsigned long nNumberOfBytesToWrite,
    OVERLAPPED* lpOverlapped,
    LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
    );

/*WINBASEAPI*/
BOOL
__stdcall
BackupRead(
    HANDLE hFile,
    BYTE* lpBuffer,
    unsigned long nNumberOfBytesToRead,
    unsigned long* lpNumberOfBytesRead,
    BOOL bAbort,
    BOOL bProcessSecurity,
    void** lpContext
    );

/*WINBASEAPI*/
BOOL
__stdcall
BackupSeek(
    HANDLE hFile,
    unsigned long  dwLowBytesToSeek,
    unsigned long  dwHighBytesToSeek,
    unsigned long* lpdwLowByteSeeked,
    unsigned long* lpdwHighByteSeeked,
    void** lpContext
    );

/*WINBASEAPI*/
BOOL
__stdcall
BackupWrite(
    HANDLE hFile,
    BYTE* lpBuffer,
    unsigned long nNumberOfBytesToWrite,
    unsigned long* lpNumberOfBytesWritten,
    BOOL bAbort,
    BOOL bProcessSecurity,
    void** lpContext
    );

//
//  Stream id structure
//
typedef struct _WIN32_STREAM_ID {
        unsigned long          dwStreamId ;
        unsigned long          dwStreamAttributes ;
        LARGE_INTEGER  Size ;
        unsigned long          dwStreamNameSize ;
        wchar_t          cStreamName[ ANYSIZE_ARRAY ] ;
} WIN32_STREAM_ID, *LPWIN32_STREAM_ID ;

//
//  Stream Ids
//

#define BACKUP_INVALID          0x00000000
#define BACKUP_DATA             0x00000001
#define BACKUP_EA_DATA          0x00000002
#define BACKUP_SECURITY_DATA    0x00000003
#define BACKUP_ALTERNATE_DATA   0x00000004
#define BACKUP_LINK             0x00000005
#define BACKUP_PROPERTY_DATA    0x00000006

//
//  Stream Attributes
//

#define STREAM_NORMAL_ATTRIBUTE         0x00000000
#define STREAM_MODIFIED_WHEN_READ       0x00000001
#define STREAM_CONTAINS_SECURITY        0x00000002
#define STREAM_CONTAINS_PROPERTIES      0x00000004

//
// Dual Mode API below this line. Dual Mode Structures also included.
//

#define STARTF_USESHOWWINDOW    0x00000001
#define STARTF_USESIZE          0x00000002
#define STARTF_USEPOSITION      0x00000004
#define STARTF_USECOUNTCHARS    0x00000008
#define STARTF_USEFILLATTRIBUTE 0x00000010
#define STARTF_RUNFULLSCREEN    0x00000020  // ignored for non-x86 platforms
#define STARTF_FORCEONFEEDBACK  0x00000040
#define STARTF_FORCEOFFFEEDBACK 0x00000080
#define STARTF_USESTDHANDLES    0x00000100
#if(WINVER >= 0x0400)
#define STARTF_USEHOTKEY        0x00000200
#endif /* WINVER >= 0x0400 */

typedef struct _STARTUPINFOA {
    unsigned long   cb;
    char*   lpReserved;
    char*   lpDesktop;
    char*   lpTitle;
    unsigned long   dwX;
    unsigned long   dwY;
    unsigned long   dwXSize;
    unsigned long   dwYSize;
    unsigned long   dwXCountChars;
    unsigned long   dwYCountChars;
    unsigned long   dwFillAttribute;
    unsigned long   dwFlags;
    WORD    wShowWindow;
    WORD    cbReserved2;
    BYTE*  lpReserved2;
    HANDLE  hStdInput;
    HANDLE  hStdOutput;
    HANDLE  hStdError;
} STARTUPINFOA, *LPSTARTUPINFOA;
typedef struct _STARTUPINFOW {
    unsigned long   cb;
    wchar_t*  lpReserved;
    wchar_t*  lpDesktop;
    wchar_t*  lpTitle;
    unsigned long   dwX;
    unsigned long   dwY;
    unsigned long   dwXSize;
    unsigned long   dwYSize;
    unsigned long   dwXCountChars;
    unsigned long   dwYCountChars;
    unsigned long   dwFillAttribute;
    unsigned long   dwFlags;
    WORD    wShowWindow;
    WORD    cbReserved2;
    BYTE*  lpReserved2;
    HANDLE  hStdInput;
    HANDLE  hStdOutput;
    HANDLE  hStdError;
} STARTUPINFOW, *LPSTARTUPINFOW;
#ifdef UNICODE
typedef STARTUPINFOW STARTUPINFO;
typedef LPSTARTUPINFOW LPSTARTUPINFO;
#else
typedef STARTUPINFOA STARTUPINFO;
typedef LPSTARTUPINFOA LPSTARTUPINFO;
#endif // UNICODE

#define SHUTDOWN_NORETRY                0x00000001

typedef struct _WIN32_FIND_DATAA {
    unsigned long dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    unsigned long nFileSizeHigh;
    unsigned long nFileSizeLow;
    unsigned long dwReserved0;
    unsigned long dwReserved1;
    char   cFileName[ MAX_PATH ];
    char   cAlternateFileName[ 14 ];
} WIN32_FIND_DATAA, *PWIN32_FIND_DATAA, *LPWIN32_FIND_DATAA;
typedef struct _WIN32_FIND_DATAW {
    unsigned long dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    unsigned long nFileSizeHigh;
    unsigned long nFileSizeLow;
    unsigned long dwReserved0;
    unsigned long dwReserved1;
    wchar_t  cFileName[ MAX_PATH ];
    wchar_t  cAlternateFileName[ 14 ];
} WIN32_FIND_DATAW, *PWIN32_FIND_DATAW, *LPWIN32_FIND_DATAW;
#ifdef UNICODE
typedef WIN32_FIND_DATAW WIN32_FIND_DATA;
typedef PWIN32_FIND_DATAW PWIN32_FIND_DATA;
typedef LPWIN32_FIND_DATAW LPWIN32_FIND_DATA;
#else
typedef WIN32_FIND_DATAA WIN32_FIND_DATA;
typedef PWIN32_FIND_DATAA PWIN32_FIND_DATA;
typedef LPWIN32_FIND_DATAA LPWIN32_FIND_DATA;
#endif // UNICODE

typedef struct _WIN32_FILE_ATTRIBUTE_DATA {
    unsigned long dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    unsigned long nFileSizeHigh;
    unsigned long nFileSizeLow;
} WIN32_FILE_ATTRIBUTE_DATA, *LPWIN32_FILE_ATTRIBUTE_DATA;

/*WINBASEAPI*/
HANDLE
__stdcall
CreateMutexA(
    LPSECURITY_ATTRIBUTES lpMutexAttributes,
    BOOL bInitialOwner,
    const char* lpName
    );
/*WINBASEAPI*/
HANDLE
__stdcall
CreateMutexW(
    LPSECURITY_ATTRIBUTES lpMutexAttributes,
    BOOL bInitialOwner,
    const wchar_t* lpName
    );
#ifdef UNICODE
#define CreateMutex  CreateMutexW
#else
#define CreateMutex  CreateMutexA
#endif // !UNICODE

/*WINBASEAPI*/
HANDLE
__stdcall
OpenMutexA(
    unsigned long dwDesiredAccess,
    BOOL bInheritHandle,
    const char* lpName
    );
/*WINBASEAPI*/
HANDLE
__stdcall
OpenMutexW(
    unsigned long dwDesiredAccess,
    BOOL bInheritHandle,
    const wchar_t* lpName
    );
#ifdef UNICODE
#define OpenMutex  OpenMutexW
#else
#define OpenMutex  OpenMutexA
#endif // !UNICODE

/*WINBASEAPI*/
HANDLE
__stdcall
CreateEventA(
    LPSECURITY_ATTRIBUTES lpEventAttributes,
    BOOL bManualReset,
    BOOL bInitialState,
    const char* lpName
    );
/*WINBASEAPI*/
HANDLE
__stdcall
CreateEventW(
    LPSECURITY_ATTRIBUTES lpEventAttributes,
    BOOL bManualReset,
    BOOL bInitialState,
    const wchar_t* lpName
    );
#ifdef UNICODE
#define CreateEvent  CreateEventW
#else
#define CreateEvent  CreateEventA
#endif // !UNICODE

/*WINBASEAPI*/
HANDLE
__stdcall
OpenEventA(
    unsigned long dwDesiredAccess,
    BOOL bInheritHandle,
    const char* lpName
    );
/*WINBASEAPI*/
HANDLE
__stdcall
OpenEventW(
    unsigned long dwDesiredAccess,
    BOOL bInheritHandle,
    const wchar_t* lpName
    );
#ifdef UNICODE
#define OpenEvent  OpenEventW
#else
#define OpenEvent  OpenEventA
#endif // !UNICODE

/*WINBASEAPI*/
HANDLE
__stdcall
CreateSemaphoreA(
    LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
    long lInitialCount,
    long lMaximumCount,
    const char* lpName
    );
/*WINBASEAPI*/
HANDLE
__stdcall
CreateSemaphoreW(
    LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
    long lInitialCount,
    long lMaximumCount,
    const wchar_t* lpName
    );
#ifdef UNICODE
#define CreateSemaphore  CreateSemaphoreW
#else
#define CreateSemaphore  CreateSemaphoreA
#endif // !UNICODE

/*WINBASEAPI*/
HANDLE
__stdcall
OpenSemaphoreA(
    unsigned long dwDesiredAccess,
    BOOL bInheritHandle,
    const char* lpName
    );
/*WINBASEAPI*/
HANDLE
__stdcall
OpenSemaphoreW(
    unsigned long dwDesiredAccess,
    BOOL bInheritHandle,
    const wchar_t* lpName
    );
#ifdef UNICODE
#define OpenSemaphore  OpenSemaphoreW
#else
#define OpenSemaphore  OpenSemaphoreA
#endif // !UNICODE

#if(_WIN32_WINNT >= 0x0400)
typedef
void
(__stdcall *PTIMERAPCROUTINE)(
    void* lpArgToCompletionRoutine,
    unsigned long dwTimerLowValue,
    unsigned long dwTimerHighValue
    );

/*WINBASEAPI*/
HANDLE
__stdcall
CreateWaitableTimerA(
    LPSECURITY_ATTRIBUTES lpTimerAttributes,
    BOOL bManualReset,
    const char* lpTimerName
    );
/*WINBASEAPI*/
HANDLE
__stdcall
CreateWaitableTimerW(
    LPSECURITY_ATTRIBUTES lpTimerAttributes,
    BOOL bManualReset,
    const wchar_t* lpTimerName
    );
#ifdef UNICODE
#define CreateWaitableTimer  CreateWaitableTimerW
#else
#define CreateWaitableTimer  CreateWaitableTimerA
#endif // !UNICODE

/*WINBASEAPI*/
HANDLE
__stdcall
OpenWaitableTimerA(
    unsigned long dwDesiredAccess,
    BOOL bInheritHandle,
    const char* lpTimerName
    );
/*WINBASEAPI*/
HANDLE
__stdcall
OpenWaitableTimerW(
    unsigned long dwDesiredAccess,
    BOOL bInheritHandle,
    const wchar_t* lpTimerName
    );
#ifdef UNICODE
#define OpenWaitableTimer  OpenWaitableTimerW
#else
#define OpenWaitableTimer  OpenWaitableTimerA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
SetWaitableTimer(
    HANDLE hTimer,
    const LARGE_INTEGER* lpDueTime,
    long lPeriod,
    PTIMERAPCROUTINE pfnCompletionRoutine,
    void* lpArgToCompletionRoutine,
    BOOL fResume
    );

/*WINBASEAPI*/
BOOL
__stdcall
CancelWaitableTimer(
    HANDLE hTimer
    );
#endif /* _WIN32_WINNT >= 0x0400 */

/*WINBASEAPI*/
HANDLE
__stdcall
CreateFileMappingA(
    HANDLE hFile,
    LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
    unsigned long flProtect,
    unsigned long dwMaximumSizeHigh,
    unsigned long dwMaximumSizeLow,
    const char* lpName
    );
/*WINBASEAPI*/
HANDLE
__stdcall
CreateFileMappingW(
    HANDLE hFile,
    LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
    unsigned long flProtect,
    unsigned long dwMaximumSizeHigh,
    unsigned long dwMaximumSizeLow,
    const wchar_t* lpName
    );
#ifdef UNICODE
#define CreateFileMapping  CreateFileMappingW
#else
#define CreateFileMapping  CreateFileMappingA
#endif // !UNICODE

/*WINBASEAPI*/
HANDLE
__stdcall
OpenFileMappingA(
    unsigned long dwDesiredAccess,
    BOOL bInheritHandle,
    const char* lpName
    );
/*WINBASEAPI*/
HANDLE
__stdcall
OpenFileMappingW(
    unsigned long dwDesiredAccess,
    BOOL bInheritHandle,
    const wchar_t* lpName
    );
#ifdef UNICODE
#define OpenFileMapping  OpenFileMappingW
#else
#define OpenFileMapping  OpenFileMappingA
#endif // !UNICODE

/*WINBASEAPI*/
unsigned long
__stdcall
GetLogicalDriveStringsA(
    unsigned long nBufferLength,
    char* lpBuffer
    );
/*WINBASEAPI*/
unsigned long
__stdcall
GetLogicalDriveStringsW(
    unsigned long nBufferLength,
    wchar_t* lpBuffer
    );
#ifdef UNICODE
#define GetLogicalDriveStrings  GetLogicalDriveStringsW
#else
#define GetLogicalDriveStrings  GetLogicalDriveStringsA
#endif // !UNICODE

/*WINBASEAPI*/
HMODULE
__stdcall
LoadLibraryA(
    const char* lpLibFileName
    );
/*WINBASEAPI*/
HMODULE
__stdcall
LoadLibraryW(
    const wchar_t* lpLibFileName
    );
#ifdef UNICODE
#define LoadLibrary  LoadLibraryW
#else
#define LoadLibrary  LoadLibraryA
#endif // !UNICODE

/*WINBASEAPI*/
HMODULE
__stdcall
LoadLibraryExA(
    const char* lpLibFileName,
    HANDLE hFile,
    unsigned long dwFlags
    );
/*WINBASEAPI*/
HMODULE
__stdcall
LoadLibraryExW(
    const wchar_t* lpLibFileName,
    HANDLE hFile,
    unsigned long dwFlags
    );
#ifdef UNICODE
#define LoadLibraryEx  LoadLibraryExW
#else
#define LoadLibraryEx  LoadLibraryExA
#endif // !UNICODE


#define DONT_RESOLVE_DLL_REFERENCES     0x00000001
#define LOAD_LIBRARY_AS_DATAFILE        0x00000002
#define LOAD_WITH_ALTERED_SEARCH_PATH   0x00000008


/*WINBASEAPI*/
unsigned long
__stdcall
GetModuleFileNameA(
    HMODULE hModule,
    char* lpFilename,
    unsigned long nSize
    );
/*WINBASEAPI*/
unsigned long
__stdcall
GetModuleFileNameW(
    HMODULE hModule,
    wchar_t* lpFilename,
    unsigned long nSize
    );
#ifdef UNICODE
#define GetModuleFileName  GetModuleFileNameW
#else
#define GetModuleFileName  GetModuleFileNameA
#endif // !UNICODE

/*WINBASEAPI*/
HMODULE
__stdcall
GetModuleHandleA(
    const char* lpModuleName
    );
/*WINBASEAPI*/
HMODULE
__stdcall
GetModuleHandleW(
    const wchar_t* lpModuleName
    );
#ifdef UNICODE
#define GetModuleHandle  GetModuleHandleW
#else
#define GetModuleHandle  GetModuleHandleA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
CreateProcessA(
    const char* lpApplicationName,
    char* lpCommandLine,
    LPSECURITY_ATTRIBUTES lpProcessAttributes,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    BOOL bInheritHandles,
    unsigned long dwCreationFlags,
    void* lpEnvironment,
    const char* lpCurrentDirectory,
    LPSTARTUPINFOA lpStartupInfo,
    LPPROCESS_INFORMATION lpProcessInformation
    );
/*WINBASEAPI*/
BOOL
__stdcall
CreateProcessW(
    const wchar_t* lpApplicationName,
    wchar_t* lpCommandLine,
    LPSECURITY_ATTRIBUTES lpProcessAttributes,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    BOOL bInheritHandles,
    unsigned long dwCreationFlags,
    void* lpEnvironment,
    const wchar_t* lpCurrentDirectory,
    LPSTARTUPINFOW lpStartupInfo,
    LPPROCESS_INFORMATION lpProcessInformation
    );
#ifdef UNICODE
#define CreateProcess  CreateProcessW
#else
#define CreateProcess  CreateProcessA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
SetProcessShutdownParameters(
    unsigned long dwLevel,
    unsigned long dwFlags
    );

/*WINBASEAPI*/
BOOL
__stdcall
GetProcessShutdownParameters(
    unsigned long* lpdwLevel,
    unsigned long* lpdwFlags
    );

/*WINBASEAPI*/
unsigned long
__stdcall
GetProcessVersion(
    unsigned long ProcessId
    );

/*WINBASEAPI*/
void
__stdcall
FatalAppExitA(
    unsigned uAction,
    const char* lpMessageText
    );
/*WINBASEAPI*/
void
__stdcall
FatalAppExitW(
    unsigned uAction,
    const wchar_t* lpMessageText
    );
#ifdef UNICODE
#define FatalAppExit  FatalAppExitW
#else
#define FatalAppExit  FatalAppExitA
#endif // !UNICODE

/*WINBASEAPI*/
void
__stdcall
GetStartupInfoA(
    LPSTARTUPINFOA lpStartupInfo
    );
/*WINBASEAPI*/
void
__stdcall
GetStartupInfoW(
    LPSTARTUPINFOW lpStartupInfo
    );
#ifdef UNICODE
#define GetStartupInfo  GetStartupInfoW
#else
#define GetStartupInfo  GetStartupInfoA
#endif // !UNICODE

/*WINBASEAPI*/
char*
__stdcall
GetCommandLineA(
    void
    );
/*WINBASEAPI*/
wchar_t*
__stdcall
GetCommandLineW(
    void
    );
#ifdef UNICODE
#define GetCommandLine  GetCommandLineW
#else
#define GetCommandLine  GetCommandLineA
#endif // !UNICODE

/*WINBASEAPI*/
unsigned long
__stdcall
GetEnvironmentVariableA(
    const char* lpName,
    char* lpBuffer,
    unsigned long nSize
    );
/*WINBASEAPI*/
unsigned long
__stdcall
GetEnvironmentVariableW(
    const wchar_t* lpName,
    wchar_t* lpBuffer,
    unsigned long nSize
    );
#ifdef UNICODE
#define GetEnvironmentVariable  GetEnvironmentVariableW
#else
#define GetEnvironmentVariable  GetEnvironmentVariableA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
SetEnvironmentVariableA(
    const char* lpName,
    const char* lpValue
    );
/*WINBASEAPI*/
BOOL
__stdcall
SetEnvironmentVariableW(
    const wchar_t* lpName,
    const wchar_t* lpValue
    );
#ifdef UNICODE
#define SetEnvironmentVariable  SetEnvironmentVariableW
#else
#define SetEnvironmentVariable  SetEnvironmentVariableA
#endif // !UNICODE

/*WINBASEAPI*/
unsigned long
__stdcall
ExpandEnvironmentStringsA(
    const char* lpSrc,
    char* lpDst,
    unsigned long nSize
    );
/*WINBASEAPI*/
unsigned long
__stdcall
ExpandEnvironmentStringsW(
    const wchar_t* lpSrc,
    wchar_t* lpDst,
    unsigned long nSize
    );
#ifdef UNICODE
#define ExpandEnvironmentStrings  ExpandEnvironmentStringsW
#else
#define ExpandEnvironmentStrings  ExpandEnvironmentStringsA
#endif // !UNICODE

/*WINBASEAPI*/
void
__stdcall
OutputDebugStringA(
    const char* lpOutputString
    );
/*WINBASEAPI*/
void
__stdcall
OutputDebugStringW(
    const wchar_t* lpOutputString
    );
#ifdef UNICODE
#define OutputDebugString  OutputDebugStringW
#else
#define OutputDebugString  OutputDebugStringA
#endif // !UNICODE

/*WINBASEAPI*/
HRSRC
__stdcall
FindResourceA(
    HMODULE hModule,
    const char* lpName,
    const char* lpType
    );
/*WINBASEAPI*/
HRSRC
__stdcall
FindResourceW(
    HMODULE hModule,
    const wchar_t* lpName,
    const wchar_t* lpType
    );
#ifdef UNICODE
#define FindResource  FindResourceW
#else
#define FindResource  FindResourceA
#endif // !UNICODE

/*WINBASEAPI*/
HRSRC
__stdcall
FindResourceExA(
    HMODULE hModule,
    const char* lpType,
    const char* lpName,
    WORD    wLanguage
    );
/*WINBASEAPI*/
HRSRC
__stdcall
FindResourceExW(
    HMODULE hModule,
    const wchar_t* lpType,
    const wchar_t* lpName,
    WORD    wLanguage
    );
#ifdef UNICODE
#define FindResourceEx  FindResourceExW
#else
#define FindResourceEx  FindResourceExA
#endif // !UNICODE

#ifdef STRICT
typedef BOOL (__stdcall* ENUMRESTYPEPROC)(HMODULE hModule, LPTSTR lpType,
        long lParam);
typedef BOOL (__stdcall* ENUMRESNAMEPROC)(HMODULE hModule, LPCTSTR lpType,
        LPTSTR lpName, long lParam);
typedef BOOL (__stdcall* ENUMRESLANGPROC)(HMODULE hModule, LPCTSTR lpType,
        LPCTSTR lpName, WORD  wLanguage, long lParam);
#else
typedef FARPROC ENUMRESTYPEPROC;
typedef FARPROC ENUMRESNAMEPROC;
typedef FARPROC ENUMRESLANGPROC;
#endif

/*WINBASEAPI*/
BOOL
__stdcall
EnumResourceTypesA(
    HMODULE hModule,
    ENUMRESTYPEPROC lpEnumFunc,
    long lParam
    );
/*WINBASEAPI*/
BOOL
__stdcall
EnumResourceTypesW(
    HMODULE hModule,
    ENUMRESTYPEPROC lpEnumFunc,
    long lParam
    );
#ifdef UNICODE
#define EnumResourceTypes  EnumResourceTypesW
#else
#define EnumResourceTypes  EnumResourceTypesA
#endif // !UNICODE


/*WINBASEAPI*/
BOOL
__stdcall
EnumResourceNamesA(
    HMODULE hModule,
    const char* lpType,
    ENUMRESNAMEPROC lpEnumFunc,
    long lParam
    );
/*WINBASEAPI*/
BOOL
__stdcall
EnumResourceNamesW(
    HMODULE hModule,
    const wchar_t* lpType,
    ENUMRESNAMEPROC lpEnumFunc,
    long lParam
    );
#ifdef UNICODE
#define EnumResourceNames  EnumResourceNamesW
#else
#define EnumResourceNames  EnumResourceNamesA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
EnumResourceLanguagesA(
    HMODULE hModule,
    const char* lpType,
    const char* lpName,
    ENUMRESLANGPROC lpEnumFunc,
    long lParam
    );
/*WINBASEAPI*/
BOOL
__stdcall
EnumResourceLanguagesW(
    HMODULE hModule,
    const wchar_t* lpType,
    const wchar_t* lpName,
    ENUMRESLANGPROC lpEnumFunc,
    long lParam
    );
#ifdef UNICODE
#define EnumResourceLanguages  EnumResourceLanguagesW
#else
#define EnumResourceLanguages  EnumResourceLanguagesA
#endif // !UNICODE

/*WINBASEAPI*/
HANDLE
__stdcall
BeginUpdateResourceA(
    const char* pFileName,
    BOOL bDeleteExistingResources
    );
/*WINBASEAPI*/
HANDLE
__stdcall
BeginUpdateResourceW(
    const wchar_t* pFileName,
    BOOL bDeleteExistingResources
    );
#ifdef UNICODE
#define BeginUpdateResource  BeginUpdateResourceW
#else
#define BeginUpdateResource  BeginUpdateResourceA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
UpdateResourceA(
    HANDLE      hUpdate,
    const char*     lpType,
    const char*     lpName,
    WORD        wLanguage,
    void*      lpData,
    unsigned long       cbData
    );
/*WINBASEAPI*/
BOOL
__stdcall
UpdateResourceW(
    HANDLE      hUpdate,
    const wchar_t*     lpType,
    const wchar_t*     lpName,
    WORD        wLanguage,
    void*      lpData,
    unsigned long       cbData
    );
#ifdef UNICODE
#define UpdateResource  UpdateResourceW
#else
#define UpdateResource  UpdateResourceA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
EndUpdateResourceA(
    HANDLE      hUpdate,
    BOOL        fDiscard
    );
/*WINBASEAPI*/
BOOL
__stdcall
EndUpdateResourceW(
    HANDLE      hUpdate,
    BOOL        fDiscard
    );
#ifdef UNICODE
#define EndUpdateResource  EndUpdateResourceW
#else
#define EndUpdateResource  EndUpdateResourceA
#endif // !UNICODE

/*WINBASEAPI*/
ATOM
__stdcall
GlobalAddAtomA(
    const char* lpString
    );
/*WINBASEAPI*/
ATOM
__stdcall
GlobalAddAtomW(
    const wchar_t* lpString
    );
#ifdef UNICODE
#define GlobalAddAtom  GlobalAddAtomW
#else
#define GlobalAddAtom  GlobalAddAtomA
#endif // !UNICODE

/*WINBASEAPI*/
ATOM
__stdcall
GlobalFindAtomA(
    const char* lpString
    );
/*WINBASEAPI*/
ATOM
__stdcall
GlobalFindAtomW(
    const wchar_t* lpString
    );
#ifdef UNICODE
#define GlobalFindAtom  GlobalFindAtomW
#else
#define GlobalFindAtom  GlobalFindAtomA
#endif // !UNICODE

/*WINBASEAPI*/
unsigned
__stdcall
GlobalGetAtomNameA(
    ATOM nAtom,
    char* lpBuffer,
    int nSize
    );
/*WINBASEAPI*/
unsigned
__stdcall
GlobalGetAtomNameW(
    ATOM nAtom,
    wchar_t* lpBuffer,
    int nSize
    );
#ifdef UNICODE
#define GlobalGetAtomName  GlobalGetAtomNameW
#else
#define GlobalGetAtomName  GlobalGetAtomNameA
#endif // !UNICODE

/*WINBASEAPI*/
ATOM
__stdcall
AddAtomA(
    const char* lpString
    );
/*WINBASEAPI*/
ATOM
__stdcall
AddAtomW(
    const wchar_t* lpString
    );
#ifdef UNICODE
#define AddAtom  AddAtomW
#else
#define AddAtom  AddAtomA
#endif // !UNICODE

/*WINBASEAPI*/
ATOM
__stdcall
FindAtomA(
    const char* lpString
    );
/*WINBASEAPI*/
ATOM
__stdcall
FindAtomW(
    const wchar_t* lpString
    );
#ifdef UNICODE
#define FindAtom  FindAtomW
#else
#define FindAtom  FindAtomA
#endif // !UNICODE

/*WINBASEAPI*/
unsigned
__stdcall
GetAtomNameA(
    ATOM nAtom,
    char* lpBuffer,
    int nSize
    );
/*WINBASEAPI*/
unsigned
__stdcall
GetAtomNameW(
    ATOM nAtom,
    wchar_t* lpBuffer,
    int nSize
    );
#ifdef UNICODE
#define GetAtomName  GetAtomNameW
#else
#define GetAtomName  GetAtomNameA
#endif // !UNICODE

/*WINBASEAPI*/
unsigned
__stdcall
GetProfileIntA(
    const char* lpAppName,
    const char* lpKeyName,
    int nDefault
    );
/*WINBASEAPI*/
unsigned
__stdcall
GetProfileIntW(
    const wchar_t* lpAppName,
    const wchar_t* lpKeyName,
    int nDefault
    );
#ifdef UNICODE
#define GetProfileInt  GetProfileIntW
#else
#define GetProfileInt  GetProfileIntA
#endif // !UNICODE

/*WINBASEAPI*/
unsigned long
__stdcall
GetProfileStringA(
    const char* lpAppName,
    const char* lpKeyName,
    const char* lpDefault,
    char* lpReturnedString,
    unsigned long nSize
    );
/*WINBASEAPI*/
unsigned long
__stdcall
GetProfileStringW(
    const wchar_t* lpAppName,
    const wchar_t* lpKeyName,
    const wchar_t* lpDefault,
    wchar_t* lpReturnedString,
    unsigned long nSize
    );
#ifdef UNICODE
#define GetProfileString  GetProfileStringW
#else
#define GetProfileString  GetProfileStringA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
WriteProfileStringA(
    const char* lpAppName,
    const char* lpKeyName,
    const char* lpString
    );
/*WINBASEAPI*/
BOOL
__stdcall
WriteProfileStringW(
    const wchar_t* lpAppName,
    const wchar_t* lpKeyName,
    const wchar_t* lpString
    );
#ifdef UNICODE
#define WriteProfileString  WriteProfileStringW
#else
#define WriteProfileString  WriteProfileStringA
#endif // !UNICODE

/*WINBASEAPI*/
unsigned long
__stdcall
GetProfileSectionA(
    const char* lpAppName,
    char* lpReturnedString,
    unsigned long nSize
    );
/*WINBASEAPI*/
unsigned long
__stdcall
GetProfileSectionW(
    const wchar_t* lpAppName,
    wchar_t* lpReturnedString,
    unsigned long nSize
    );
#ifdef UNICODE
#define GetProfileSection  GetProfileSectionW
#else
#define GetProfileSection  GetProfileSectionA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
WriteProfileSectionA(
    const char* lpAppName,
    const char* lpString
    );
/*WINBASEAPI*/
BOOL
__stdcall
WriteProfileSectionW(
    const wchar_t* lpAppName,
    const wchar_t* lpString
    );
#ifdef UNICODE
#define WriteProfileSection  WriteProfileSectionW
#else
#define WriteProfileSection  WriteProfileSectionA
#endif // !UNICODE

/*WINBASEAPI*/
unsigned
__stdcall
GetPrivateProfileIntA(
    const char* lpAppName,
    const char* lpKeyName,
    int nDefault,
    const char* lpFileName
    );
/*WINBASEAPI*/
unsigned
__stdcall
GetPrivateProfileIntW(
    const wchar_t* lpAppName,
    const wchar_t* lpKeyName,
    int nDefault,
    const wchar_t* lpFileName
    );
#ifdef UNICODE
#define GetPrivateProfileInt  GetPrivateProfileIntW
#else
#define GetPrivateProfileInt  GetPrivateProfileIntA
#endif // !UNICODE

/*WINBASEAPI*/
unsigned long
__stdcall
GetPrivateProfileStringA(
    const char* lpAppName,
    const char* lpKeyName,
    const char* lpDefault,
    char* lpReturnedString,
    unsigned long nSize,
    const char* lpFileName
    );
/*WINBASEAPI*/
unsigned long
__stdcall
GetPrivateProfileStringW(
    const wchar_t* lpAppName,
    const wchar_t* lpKeyName,
    const wchar_t* lpDefault,
    wchar_t* lpReturnedString,
    unsigned long nSize,
    const wchar_t* lpFileName
    );
#ifdef UNICODE
#define GetPrivateProfileString  GetPrivateProfileStringW
#else
#define GetPrivateProfileString  GetPrivateProfileStringA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
WritePrivateProfileStringA(
    const char* lpAppName,
    const char* lpKeyName,
    const char* lpString,
    const char* lpFileName
    );
/*WINBASEAPI*/
BOOL
__stdcall
WritePrivateProfileStringW(
    const wchar_t* lpAppName,
    const wchar_t* lpKeyName,
    const wchar_t* lpString,
    const wchar_t* lpFileName
    );
#ifdef UNICODE
#define WritePrivateProfileString  WritePrivateProfileStringW
#else
#define WritePrivateProfileString  WritePrivateProfileStringA
#endif // !UNICODE

/*WINBASEAPI*/
unsigned long
__stdcall
GetPrivateProfileSectionA(
    const char* lpAppName,
    char* lpReturnedString,
    unsigned long nSize,
    const char* lpFileName
    );
/*WINBASEAPI*/
unsigned long
__stdcall
GetPrivateProfileSectionW(
    const wchar_t* lpAppName,
    wchar_t* lpReturnedString,
    unsigned long nSize,
    const wchar_t* lpFileName
    );
#ifdef UNICODE
#define GetPrivateProfileSection  GetPrivateProfileSectionW
#else
#define GetPrivateProfileSection  GetPrivateProfileSectionA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
WritePrivateProfileSectionA(
    const char* lpAppName,
    const char* lpString,
    const char* lpFileName
    );
/*WINBASEAPI*/
BOOL
__stdcall
WritePrivateProfileSectionW(
    const wchar_t* lpAppName,
    const wchar_t* lpString,
    const wchar_t* lpFileName
    );
#ifdef UNICODE
#define WritePrivateProfileSection  WritePrivateProfileSectionW
#else
#define WritePrivateProfileSection  WritePrivateProfileSectionA
#endif // !UNICODE


/*WINBASEAPI*/
unsigned long
__stdcall
GetPrivateProfileSectionNamesA(
    char* lpszReturnBuffer,
    unsigned long nSize,
    const char* lpFileName
    );
/*WINBASEAPI*/
unsigned long
__stdcall
GetPrivateProfileSectionNamesW(
    wchar_t* lpszReturnBuffer,
    unsigned long nSize,
    const wchar_t* lpFileName
    );
#ifdef UNICODE
#define GetPrivateProfileSectionNames  GetPrivateProfileSectionNamesW
#else
#define GetPrivateProfileSectionNames  GetPrivateProfileSectionNamesA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
GetPrivateProfileStructA(
    const char* lpszSection,
    const char* lpszKey,
    void*   lpStruct,
    unsigned     uSizeStruct,
    const char* szFile
    );
/*WINBASEAPI*/
BOOL
__stdcall
GetPrivateProfileStructW(
    const wchar_t* lpszSection,
    const wchar_t* lpszKey,
    void*   lpStruct,
    unsigned     uSizeStruct,
    const wchar_t* szFile
    );
#ifdef UNICODE
#define GetPrivateProfileStruct  GetPrivateProfileStructW
#else
#define GetPrivateProfileStruct  GetPrivateProfileStructA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
WritePrivateProfileStructA(
    const char* lpszSection,
    const char* lpszKey,
    void*   lpStruct,
    unsigned     uSizeStruct,
    const char* szFile
    );
/*WINBASEAPI*/
BOOL
__stdcall
WritePrivateProfileStructW(
    const wchar_t* lpszSection,
    const wchar_t* lpszKey,
    void*   lpStruct,
    unsigned     uSizeStruct,
    const wchar_t* szFile
    );
#ifdef UNICODE
#define WritePrivateProfileStruct  WritePrivateProfileStructW
#else
#define WritePrivateProfileStruct  WritePrivateProfileStructA
#endif // !UNICODE


/*WINBASEAPI*/
unsigned
__stdcall
GetDriveTypeA(
    const char* lpRootPathName
    );
/*WINBASEAPI*/
unsigned
__stdcall
GetDriveTypeW(
    const wchar_t* lpRootPathName
    );
#ifdef UNICODE
#define GetDriveType  GetDriveTypeW
#else
#define GetDriveType  GetDriveTypeA
#endif // !UNICODE

/*WINBASEAPI*/
unsigned
__stdcall
GetSystemDirectoryA(
    char* lpBuffer,
    unsigned uSize
    );
/*WINBASEAPI*/
unsigned
__stdcall
GetSystemDirectoryW(
    wchar_t* lpBuffer,
    unsigned uSize
    );
#ifdef UNICODE
#define GetSystemDirectory  GetSystemDirectoryW
#else
#define GetSystemDirectory  GetSystemDirectoryA
#endif // !UNICODE

/*WINBASEAPI*/
unsigned long
__stdcall
GetTempPathA(
    unsigned long nBufferLength,
    char* lpBuffer
    );
/*WINBASEAPI*/
unsigned long
__stdcall
GetTempPathW(
    unsigned long nBufferLength,
    wchar_t* lpBuffer
    );
#ifdef UNICODE
#define GetTempPath  GetTempPathW
#else
#define GetTempPath  GetTempPathA
#endif // !UNICODE

/*WINBASEAPI*/
unsigned
__stdcall
GetTempFileNameA(
    const char* lpPathName,
    const char* lpPrefixString,
    unsigned uUnique,
    char* lpTempFileName
    );
/*WINBASEAPI*/
unsigned
__stdcall
GetTempFileNameW(
    const wchar_t* lpPathName,
    const wchar_t* lpPrefixString,
    unsigned uUnique,
    wchar_t* lpTempFileName
    );
#ifdef UNICODE
#define GetTempFileName  GetTempFileNameW
#else
#define GetTempFileName  GetTempFileNameA
#endif // !UNICODE

/*WINBASEAPI*/
unsigned
__stdcall
GetWindowsDirectoryA(
    char* lpBuffer,
    unsigned uSize
    );
/*WINBASEAPI*/
unsigned
__stdcall
GetWindowsDirectoryW(
    wchar_t* lpBuffer,
    unsigned uSize
    );
#ifdef UNICODE
#define GetWindowsDirectory  GetWindowsDirectoryW
#else
#define GetWindowsDirectory  GetWindowsDirectoryA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
SetCurrentDirectoryA(
    const char* lpPathName
    );
/*WINBASEAPI*/
BOOL
__stdcall
SetCurrentDirectoryW(
    const wchar_t* lpPathName
    );
#ifdef UNICODE
#define SetCurrentDirectory  SetCurrentDirectoryW
#else
#define SetCurrentDirectory  SetCurrentDirectoryA
#endif // !UNICODE

/*WINBASEAPI*/
unsigned long
__stdcall
GetCurrentDirectoryA(
    unsigned long nBufferLength,
    char* lpBuffer
    );
/*WINBASEAPI*/
unsigned long
__stdcall
GetCurrentDirectoryW(
    unsigned long nBufferLength,
    wchar_t* lpBuffer
    );
#ifdef UNICODE
#define GetCurrentDirectory  GetCurrentDirectoryW
#else
#define GetCurrentDirectory  GetCurrentDirectoryA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
GetDiskFreeSpaceA(
    const char* lpRootPathName,
    unsigned long* lpSectorsPerCluster,
    unsigned long* lpBytesPerSector,
    unsigned long* lpNumberOfFreeClusters,
    unsigned long* lpTotalNumberOfClusters
    );
/*WINBASEAPI*/
BOOL
__stdcall
GetDiskFreeSpaceW(
    const wchar_t* lpRootPathName,
    unsigned long* lpSectorsPerCluster,
    unsigned long* lpBytesPerSector,
    unsigned long* lpNumberOfFreeClusters,
    unsigned long* lpTotalNumberOfClusters
    );
#ifdef UNICODE
#define GetDiskFreeSpace  GetDiskFreeSpaceW
#else
#define GetDiskFreeSpace  GetDiskFreeSpaceA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
GetDiskFreeSpaceExA(
    const char* lpDirectoryName,
    PULARGE_INTEGER lpFreeBytesAvailableToCaller,
    PULARGE_INTEGER lpTotalNumberOfBytes,
    PULARGE_INTEGER lpTotalNumberOfFreeBytes
    );
/*WINBASEAPI*/
BOOL
__stdcall
GetDiskFreeSpaceExW(
    const wchar_t* lpDirectoryName,
    PULARGE_INTEGER lpFreeBytesAvailableToCaller,
    PULARGE_INTEGER lpTotalNumberOfBytes,
    PULARGE_INTEGER lpTotalNumberOfFreeBytes
    );
#ifdef UNICODE
#define GetDiskFreeSpaceEx  GetDiskFreeSpaceExW
#else
#define GetDiskFreeSpaceEx  GetDiskFreeSpaceExA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
CreateDirectoryA(
    const char* lpPathName,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
/*WINBASEAPI*/
BOOL
__stdcall
CreateDirectoryW(
    const wchar_t* lpPathName,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
#ifdef UNICODE
#define CreateDirectory  CreateDirectoryW
#else
#define CreateDirectory  CreateDirectoryA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
CreateDirectoryExA(
    const char* lpTemplateDirectory,
    const char* lpNewDirectory,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
/*WINBASEAPI*/
BOOL
__stdcall
CreateDirectoryExW(
    const wchar_t* lpTemplateDirectory,
    const wchar_t* lpNewDirectory,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
#ifdef UNICODE
#define CreateDirectoryEx  CreateDirectoryExW
#else
#define CreateDirectoryEx  CreateDirectoryExA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
RemoveDirectoryA(
    const char* lpPathName
    );
/*WINBASEAPI*/
BOOL
__stdcall
RemoveDirectoryW(
    const wchar_t* lpPathName
    );
#ifdef UNICODE
#define RemoveDirectory  RemoveDirectoryW
#else
#define RemoveDirectory  RemoveDirectoryA
#endif // !UNICODE

/*WINBASEAPI*/
unsigned long
__stdcall
GetFullPathNameA(
    const char* lpFileName,
    unsigned long nBufferLength,
    char* lpBuffer,
    char** lpFilePart
    );
/*WINBASEAPI*/
unsigned long
__stdcall
GetFullPathNameW(
    const wchar_t* lpFileName,
    unsigned long nBufferLength,
    wchar_t* lpBuffer,
    wchar_t** lpFilePart
    );
#ifdef UNICODE
#define GetFullPathName  GetFullPathNameW
#else
#define GetFullPathName  GetFullPathNameA
#endif // !UNICODE


#define DDD_RAW_TARGET_PATH         0x00000001
#define DDD_REMOVE_DEFINITION       0x00000002
#define DDD_EXACT_MATCH_ON_REMOVE   0x00000004
#define DDD_NO_BROADCAST_SYSTEM     0x00000008

/*WINBASEAPI*/
BOOL
__stdcall
DefineDosDeviceA(
    unsigned long dwFlags,
    const char* lpDeviceName,
    const char* lpTargetPath
    );
/*WINBASEAPI*/
BOOL
__stdcall
DefineDosDeviceW(
    unsigned long dwFlags,
    const wchar_t* lpDeviceName,
    const wchar_t* lpTargetPath
    );
#ifdef UNICODE
#define DefineDosDevice  DefineDosDeviceW
#else
#define DefineDosDevice  DefineDosDeviceA
#endif // !UNICODE

/*WINBASEAPI*/
unsigned long
__stdcall
QueryDosDeviceA(
    const char* lpDeviceName,
    char* lpTargetPath,
    unsigned long ucchMax
    );
/*WINBASEAPI*/
unsigned long
__stdcall
QueryDosDeviceW(
    const wchar_t* lpDeviceName,
    wchar_t* lpTargetPath,
    unsigned long ucchMax
    );
#ifdef UNICODE
#define QueryDosDevice  QueryDosDeviceW
#else
#define QueryDosDevice  QueryDosDeviceA
#endif // !UNICODE

#define EXPAND_LOCAL_DRIVES

/*WINBASEAPI*/
HANDLE
__stdcall
CreateFileA(
    const char* lpFileName,
    unsigned long dwDesiredAccess,
    unsigned long dwShareMode,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    unsigned long dwCreationDisposition,
    unsigned long dwFlagsAndAttributes,
    HANDLE hTemplateFile
    );
/*WINBASEAPI*/
HANDLE
__stdcall
CreateFileW(
    const wchar_t* lpFileName,
    unsigned long dwDesiredAccess,
    unsigned long dwShareMode,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    unsigned long dwCreationDisposition,
    unsigned long dwFlagsAndAttributes,
    HANDLE hTemplateFile
    );
#ifdef UNICODE
#define CreateFile  CreateFileW
#else
#define CreateFile  CreateFileA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
SetFileAttributesA(
    const char* lpFileName,
    unsigned long dwFileAttributes
    );
/*WINBASEAPI*/
BOOL
__stdcall
SetFileAttributesW(
    const wchar_t* lpFileName,
    unsigned long dwFileAttributes
    );
#ifdef UNICODE
#define SetFileAttributes  SetFileAttributesW
#else
#define SetFileAttributes  SetFileAttributesA
#endif // !UNICODE

/*WINBASEAPI*/
unsigned long
__stdcall
GetFileAttributesA(
    const char* lpFileName
    );
/*WINBASEAPI*/
unsigned long
__stdcall
GetFileAttributesW(
    const wchar_t* lpFileName
    );
#ifdef UNICODE
#define GetFileAttributes  GetFileAttributesW
#else
#define GetFileAttributes  GetFileAttributesA
#endif // !UNICODE

typedef enum _GET_FILEEX_INFO_LEVELS {
    GetFileExInfoStandard,
    GetFileExMaxInfoLevel
} GET_FILEEX_INFO_LEVELS;

/*WINBASEAPI*/
BOOL
__stdcall
GetFileAttributesExA(
    const char* lpFileName,
    GET_FILEEX_INFO_LEVELS fInfoLevelId,
    void* lpFileInformation
    );
/*WINBASEAPI*/
BOOL
__stdcall
GetFileAttributesExW(
    const wchar_t* lpFileName,
    GET_FILEEX_INFO_LEVELS fInfoLevelId,
    void* lpFileInformation
    );
#ifdef UNICODE
#define GetFileAttributesEx  GetFileAttributesExW
#else
#define GetFileAttributesEx  GetFileAttributesExA
#endif // !UNICODE

/*WINBASEAPI*/
unsigned long
__stdcall
GetCompressedFileSizeA(
    const char* lpFileName,
    unsigned long* lpFileSizeHigh
    );
/*WINBASEAPI*/
unsigned long
__stdcall
GetCompressedFileSizeW(
    const wchar_t* lpFileName,
    unsigned long* lpFileSizeHigh
    );
#ifdef UNICODE
#define GetCompressedFileSize  GetCompressedFileSizeW
#else
#define GetCompressedFileSize  GetCompressedFileSizeA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
DeleteFileA(
    const char* lpFileName
    );
/*WINBASEAPI*/
BOOL
__stdcall
DeleteFileW(
    const wchar_t* lpFileName
    );
#ifdef UNICODE
#define DeleteFile  DeleteFileW
#else
#define DeleteFile  DeleteFileA
#endif // !UNICODE

#if(_WIN32_WINNT >= 0x0400)
typedef enum _FINDEX_INFO_LEVELS {
    FindExInfoStandard,
    FindExInfoMaxInfoLevel
} FINDEX_INFO_LEVELS;

typedef enum _FINDEX_SEARCH_OPS {
    FindExSearchNameMatch,
    FindExSearchLimitToDirectories,
    FindExSearchLimitToDevices,
    FindExSearchMaxSearchOp
} FINDEX_SEARCH_OPS;

#define FIND_FIRST_EX_CASE_SENSITIVE   0x00000001

/*WINBASEAPI*/
HANDLE
__stdcall
FindFirstFileExA(
    const char* lpFileName,
    FINDEX_INFO_LEVELS fInfoLevelId,
    void* lpFindFileData,
    FINDEX_SEARCH_OPS fSearchOp,
    void* lpSearchFilter,
    unsigned long dwAdditionalFlags
    );
/*WINBASEAPI*/
HANDLE
__stdcall
FindFirstFileExW(
    const wchar_t* lpFileName,
    FINDEX_INFO_LEVELS fInfoLevelId,
    void* lpFindFileData,
    FINDEX_SEARCH_OPS fSearchOp,
    void* lpSearchFilter,
    unsigned long dwAdditionalFlags
    );
#ifdef UNICODE
#define FindFirstFileEx  FindFirstFileExW
#else
#define FindFirstFileEx  FindFirstFileExA
#endif // !UNICODE
#endif /* _WIN32_WINNT >= 0x0400 */

/*WINBASEAPI*/
HANDLE
__stdcall
FindFirstFileA(
    const char* lpFileName,
    LPWIN32_FIND_DATAA lpFindFileData
    );
/*WINBASEAPI*/
HANDLE
__stdcall
FindFirstFileW(
    const wchar_t* lpFileName,
    LPWIN32_FIND_DATAW lpFindFileData
    );
#ifdef UNICODE
#define FindFirstFile  FindFirstFileW
#else
#define FindFirstFile  FindFirstFileA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
FindNextFileA(
    HANDLE hFindFile,
    LPWIN32_FIND_DATAA lpFindFileData
    );
/*WINBASEAPI*/
BOOL
__stdcall
FindNextFileW(
    HANDLE hFindFile,
    LPWIN32_FIND_DATAW lpFindFileData
    );
#ifdef UNICODE
#define FindNextFile  FindNextFileW
#else
#define FindNextFile  FindNextFileA
#endif // !UNICODE

/*WINBASEAPI*/
unsigned long
__stdcall
SearchPathA(
    const char* lpPath,
    const char* lpFileName,
    const char* lpExtension,
    unsigned long nBufferLength,
    char* lpBuffer,
    char** lpFilePart
    );
/*WINBASEAPI*/
unsigned long
__stdcall
SearchPathW(
    const wchar_t* lpPath,
    const wchar_t* lpFileName,
    const wchar_t* lpExtension,
    unsigned long nBufferLength,
    wchar_t* lpBuffer,
    wchar_t** lpFilePart
    );
#ifdef UNICODE
#define SearchPath  SearchPathW
#else
#define SearchPath  SearchPathA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
CopyFileA(
    const char* lpExistingFileName,
    const char* lpNewFileName,
    BOOL bFailIfExists
    );
/*WINBASEAPI*/
BOOL
__stdcall
CopyFileW(
    const wchar_t* lpExistingFileName,
    const wchar_t* lpNewFileName,
    BOOL bFailIfExists
    );
#ifdef UNICODE
#define CopyFile  CopyFileW
#else
#define CopyFile  CopyFileA
#endif // !UNICODE

#if(_WIN32_WINNT >= 0x0400)
typedef
unsigned long
(__stdcall* LPPROGRESS_ROUTINE)(
    LARGE_INTEGER TotalFileSize,
    LARGE_INTEGER TotalBytesTransferred,
    LARGE_INTEGER StreamSize,
    LARGE_INTEGER StreamBytesTransferred,
    unsigned long dwStreamNumber,
    unsigned long dwCallbackReason,
    HANDLE hSourceFile,
    HANDLE hDestinationFile,
    void* lpData OPTIONAL
    );

/*WINBASEAPI*/
BOOL
__stdcall
CopyFileExA(
    const char* lpExistingFileName,
    const char* lpNewFileName,
    LPPROGRESS_ROUTINE lpProgressRoutine OPTIONAL,
    void* lpData OPTIONAL,
    BOOL* pbCancel OPTIONAL,
    unsigned long dwCopyFlags
    );
/*WINBASEAPI*/
BOOL
__stdcall
CopyFileExW(
    const wchar_t* lpExistingFileName,
    const wchar_t* lpNewFileName,
    LPPROGRESS_ROUTINE lpProgressRoutine OPTIONAL,
    void* lpData OPTIONAL,
    BOOL* pbCancel OPTIONAL,
    unsigned long dwCopyFlags
    );
#ifdef UNICODE
#define CopyFileEx  CopyFileExW
#else
#define CopyFileEx  CopyFileExA
#endif // !UNICODE
#endif /* _WIN32_WINNT >= 0x0400 */

/*WINBASEAPI*/
BOOL
__stdcall
MoveFileA(
    const char* lpExistingFileName,
    const char* lpNewFileName
    );
/*WINBASEAPI*/
BOOL
__stdcall
MoveFileW(
    const wchar_t* lpExistingFileName,
    const wchar_t* lpNewFileName
    );
#ifdef UNICODE
#define MoveFile  MoveFileW
#else
#define MoveFile  MoveFileA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
MoveFileExA(
    const char* lpExistingFileName,
    const char* lpNewFileName,
    unsigned long dwFlags
    );
/*WINBASEAPI*/
BOOL
__stdcall
MoveFileExW(
    const wchar_t* lpExistingFileName,
    const wchar_t* lpNewFileName,
    unsigned long dwFlags
    );
#ifdef UNICODE
#define MoveFileEx  MoveFileExW
#else
#define MoveFileEx  MoveFileExA
#endif // !UNICODE

#define MOVEFILE_REPLACE_EXISTING   0x00000001
#define MOVEFILE_COPY_ALLOWED       0x00000002
#define MOVEFILE_DELAY_UNTIL_REBOOT 0x00000004
#define MOVEFILE_WRITE_THROUGH      0x00000008

/*WINBASEAPI*/
HANDLE
__stdcall
CreateNamedPipeA(
    const char* lpName,
    unsigned long dwOpenMode,
    unsigned long dwPipeMode,
    unsigned long nMaxInstances,
    unsigned long nOutBufferSize,
    unsigned long nInBufferSize,
    unsigned long nDefaultTimeOut,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
/*WINBASEAPI*/
HANDLE
__stdcall
CreateNamedPipeW(
    const wchar_t* lpName,
    unsigned long dwOpenMode,
    unsigned long dwPipeMode,
    unsigned long nMaxInstances,
    unsigned long nOutBufferSize,
    unsigned long nInBufferSize,
    unsigned long nDefaultTimeOut,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
#ifdef UNICODE
#define CreateNamedPipe  CreateNamedPipeW
#else
#define CreateNamedPipe  CreateNamedPipeA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
GetNamedPipeHandleStateA(
    HANDLE hNamedPipe,
    unsigned long* lpState,
    unsigned long* lpCurInstances,
    unsigned long* lpMaxCollectionCount,
    unsigned long* lpCollectDataTimeout,
    char* lpUserName,
    unsigned long nMaxUserNameSize
    );
/*WINBASEAPI*/
BOOL
__stdcall
GetNamedPipeHandleStateW(
    HANDLE hNamedPipe,
    unsigned long* lpState,
    unsigned long* lpCurInstances,
    unsigned long* lpMaxCollectionCount,
    unsigned long* lpCollectDataTimeout,
    wchar_t* lpUserName,
    unsigned long nMaxUserNameSize
    );
#ifdef UNICODE
#define GetNamedPipeHandleState  GetNamedPipeHandleStateW
#else
#define GetNamedPipeHandleState  GetNamedPipeHandleStateA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
CallNamedPipeA(
    const char* lpNamedPipeName,
    void* lpInBuffer,
    unsigned long nInBufferSize,
    void* lpOutBuffer,
    unsigned long nOutBufferSize,
    unsigned long* lpBytesRead,
    unsigned long nTimeOut
    );
/*WINBASEAPI*/
BOOL
__stdcall
CallNamedPipeW(
    const wchar_t* lpNamedPipeName,
    void* lpInBuffer,
    unsigned long nInBufferSize,
    void* lpOutBuffer,
    unsigned long nOutBufferSize,
    unsigned long* lpBytesRead,
    unsigned long nTimeOut
    );
#ifdef UNICODE
#define CallNamedPipe  CallNamedPipeW
#else
#define CallNamedPipe  CallNamedPipeA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
WaitNamedPipeA(
    const char* lpNamedPipeName,
    unsigned long nTimeOut
    );
/*WINBASEAPI*/
BOOL
__stdcall
WaitNamedPipeW(
    const wchar_t* lpNamedPipeName,
    unsigned long nTimeOut
    );
#ifdef UNICODE
#define WaitNamedPipe  WaitNamedPipeW
#else
#define WaitNamedPipe  WaitNamedPipeA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
SetVolumeLabelA(
    const char* lpRootPathName,
    const char* lpVolumeName
    );
/*WINBASEAPI*/
BOOL
__stdcall
SetVolumeLabelW(
    const wchar_t* lpRootPathName,
    const wchar_t* lpVolumeName
    );
#ifdef UNICODE
#define SetVolumeLabel  SetVolumeLabelW
#else
#define SetVolumeLabel  SetVolumeLabelA
#endif // !UNICODE

/*WINBASEAPI*/
void
__stdcall
SetFileApisToOEM( void );

/*WINBASEAPI*/
void
__stdcall
SetFileApisToANSI( void );

/*WINBASEAPI*/
BOOL
__stdcall
AreFileApisANSI( void );

/*WINBASEAPI*/
BOOL
__stdcall
GetVolumeInformationA(
    const char* lpRootPathName,
    char* lpVolumeNameBuffer,
    unsigned long nVolumeNameSize,
    unsigned long* lpVolumeSerialNumber,
    unsigned long* lpMaximumComponentLength,
    unsigned long* lpFileSystemFlags,
    char* lpFileSystemNameBuffer,
    unsigned long nFileSystemNameSize
    );
/*WINBASEAPI*/
BOOL
__stdcall
GetVolumeInformationW(
    const wchar_t* lpRootPathName,
    wchar_t* lpVolumeNameBuffer,
    unsigned long nVolumeNameSize,
    unsigned long* lpVolumeSerialNumber,
    unsigned long* lpMaximumComponentLength,
    unsigned long* lpFileSystemFlags,
    wchar_t* lpFileSystemNameBuffer,
    unsigned long nFileSystemNameSize
    );
#ifdef UNICODE
#define GetVolumeInformation  GetVolumeInformationW
#else
#define GetVolumeInformation  GetVolumeInformationA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
CancelIo(
    HANDLE hFile
    );

//
// Event logging APIs
//

/*WINADVAPI*/
BOOL
__stdcall
ClearEventLogA (
    HANDLE hEventLog,
    const char* lpBackupFileName
    );
/*WINADVAPI*/
BOOL
__stdcall
ClearEventLogW (
    HANDLE hEventLog,
    const wchar_t* lpBackupFileName
    );
#ifdef UNICODE
#define ClearEventLog  ClearEventLogW
#else
#define ClearEventLog  ClearEventLogA
#endif // !UNICODE

/*WINADVAPI*/
BOOL
__stdcall
BackupEventLogA (
    HANDLE hEventLog,
    const char* lpBackupFileName
    );
/*WINADVAPI*/
BOOL
__stdcall
BackupEventLogW (
    HANDLE hEventLog,
    const wchar_t* lpBackupFileName
    );
#ifdef UNICODE
#define BackupEventLog  BackupEventLogW
#else
#define BackupEventLog  BackupEventLogA
#endif // !UNICODE

/*WINADVAPI*/
BOOL
__stdcall
CloseEventLog (
    HANDLE hEventLog
    );

/*WINADVAPI*/
BOOL
__stdcall
DeregisterEventSource (
    HANDLE hEventLog
    );

/*WINADVAPI*/
BOOL
__stdcall
NotifyChangeEventLog(
    HANDLE  hEventLog,
    HANDLE  hEvent
    );

/*WINADVAPI*/
BOOL
__stdcall
GetNumberOfEventLogRecords (
    HANDLE hEventLog,
    unsigned long* NumberOfRecords
    );

/*WINADVAPI*/
BOOL
__stdcall
GetOldestEventLogRecord (
    HANDLE hEventLog,
    unsigned long* OldestRecord
    );

/*WINADVAPI*/
HANDLE
__stdcall
OpenEventLogA (
    const char* lpUNCServerName,
    const char* lpSourceName
    );
/*WINADVAPI*/
HANDLE
__stdcall
OpenEventLogW (
    const wchar_t* lpUNCServerName,
    const wchar_t* lpSourceName
    );
#ifdef UNICODE
#define OpenEventLog  OpenEventLogW
#else
#define OpenEventLog  OpenEventLogA
#endif // !UNICODE

/*WINADVAPI*/
HANDLE
__stdcall
RegisterEventSourceA (
    const char* lpUNCServerName,
    const char* lpSourceName
    );
/*WINADVAPI*/
HANDLE
__stdcall
RegisterEventSourceW (
    const wchar_t* lpUNCServerName,
    const wchar_t* lpSourceName
    );
#ifdef UNICODE
#define RegisterEventSource  RegisterEventSourceW
#else
#define RegisterEventSource  RegisterEventSourceA
#endif // !UNICODE

/*WINADVAPI*/
HANDLE
__stdcall
OpenBackupEventLogA (
    const char* lpUNCServerName,
    const char* lpFileName
    );
/*WINADVAPI*/
HANDLE
__stdcall
OpenBackupEventLogW (
    const wchar_t* lpUNCServerName,
    const wchar_t* lpFileName
    );
#ifdef UNICODE
#define OpenBackupEventLog  OpenBackupEventLogW
#else
#define OpenBackupEventLog  OpenBackupEventLogA
#endif // !UNICODE

/*WINADVAPI*/
BOOL
__stdcall
ReadEventLogA (
     HANDLE     hEventLog,
     unsigned long      dwReadFlags,
     unsigned long      dwRecordOffset,
     void*     lpBuffer,
     unsigned long      nNumberOfBytesToRead,
     unsigned long      *pnBytesRead,
     unsigned long      *pnMinNumberOfBytesNeeded
    );
/*WINADVAPI*/
BOOL
__stdcall
ReadEventLogW (
     HANDLE     hEventLog,
     unsigned long      dwReadFlags,
     unsigned long      dwRecordOffset,
     void*     lpBuffer,
     unsigned long      nNumberOfBytesToRead,
     unsigned long      *pnBytesRead,
     unsigned long * pnMinNumberOfBytesNeeded
    );
#ifdef UNICODE
#define ReadEventLog  ReadEventLogW
#else
#define ReadEventLog  ReadEventLogA
#endif // !UNICODE

/*WINADVAPI*/
BOOL
__stdcall
ReportEventA (
     HANDLE     hEventLog,
     WORD       wType,
     WORD       wCategory,
     unsigned long      dwEventID,
     PSID       lpUserSid,
     WORD       wNumStrings,
     unsigned long      dwDataSize,
     const char** lpStrings,
     void*     lpRawData
    );
/*WINADVAPI*/
BOOL
__stdcall
ReportEventW (
     HANDLE     hEventLog,
     WORD       wType,
     WORD       wCategory,
     unsigned long      dwEventID,
     PSID       lpUserSid,
     WORD       wNumStrings,
     unsigned long      dwDataSize,
     const wchar_t** lpStrings,
     void*     lpRawData
    );
#ifdef UNICODE
#define ReportEvent  ReportEventW
#else
#define ReportEvent  ReportEventA
#endif // !UNICODE

//
//
// Security APIs
//


/*WINADVAPI*/
BOOL
__stdcall
DuplicateToken(
    HANDLE ExistingTokenHandle,
    SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,
    HANDLE* DuplicateTokenHandle
    );

/*WINADVAPI*/
BOOL
__stdcall
GetKernelObjectSecurity (
    HANDLE Handle,
    SECURITY_INFORMATION RequestedInformation,
    PSECURITY_DESCRIPTOR pSecurityDescriptor,
    unsigned long nLength,
    unsigned long* lpnLengthNeeded
    );

/*WINADVAPI*/
BOOL
__stdcall
ImpersonateNamedPipeClient(
    HANDLE hNamedPipe
    );

/*WINADVAPI*/
BOOL
__stdcall
ImpersonateSelf(
    SECURITY_IMPERSONATION_LEVEL ImpersonationLevel
    );


/*WINADVAPI*/
BOOL
__stdcall
RevertToSelf (
    void
    );

/*WINADVAPI*/
BOOL
__stdcall
SetThreadToken (
    HANDLE* Thread,
    HANDLE Token
    );

/*WINADVAPI*/
BOOL
__stdcall
AccessCheck (
    PSECURITY_DESCRIPTOR pSecurityDescriptor,
    HANDLE ClientToken,
    unsigned long DesiredAccess,
    PGENERIC_MAPPING GenericMapping,
    PPRIVILEGE_SET PrivilegeSet,
    unsigned long* PrivilegeSetLength,
    unsigned long* GrantedAccess,
    BOOL* AccessStatus
    );


/*WINADVAPI*/
BOOL
__stdcall
OpenProcessToken (
    HANDLE ProcessHandle,
    unsigned long DesiredAccess,
    HANDLE* TokenHandle
    );


/*WINADVAPI*/
BOOL
__stdcall
OpenThreadToken (
    HANDLE ThreadHandle,
    unsigned long DesiredAccess,
    BOOL OpenAsSelf,
    HANDLE* TokenHandle
    );


/*WINADVAPI*/
BOOL
__stdcall
GetTokenInformation (
    HANDLE TokenHandle,
    TOKEN_INFORMATION_CLASS TokenInformationClass,
    void* TokenInformation,
    unsigned long TokenInformationLength,
    unsigned long* ReturnLength
    );


/*WINADVAPI*/
BOOL
__stdcall
SetTokenInformation (
    HANDLE TokenHandle,
    TOKEN_INFORMATION_CLASS TokenInformationClass,
    void* TokenInformation,
    unsigned long TokenInformationLength
    );


/*WINADVAPI*/
BOOL
__stdcall
AdjustTokenPrivileges (
    HANDLE TokenHandle,
    BOOL DisableAllPrivileges,
    PTOKEN_PRIVILEGES NewState,
    unsigned long BufferLength,
    PTOKEN_PRIVILEGES PreviousState,
    unsigned long* ReturnLength
    );


/*WINADVAPI*/
BOOL
__stdcall
AdjustTokenGroups (
    HANDLE TokenHandle,
    BOOL ResetToDefault,
    PTOKEN_GROUPS NewState,
    unsigned long BufferLength,
    PTOKEN_GROUPS PreviousState,
    unsigned long* ReturnLength
    );


/*WINADVAPI*/
BOOL
__stdcall
PrivilegeCheck (
    HANDLE ClientToken,
    PPRIVILEGE_SET RequiredPrivileges,
    BOOL* pfResult
    );


/*WINADVAPI*/
BOOL
__stdcall
AccessCheckAndAuditAlarmA (
    const char* SubsystemName,
    void* HandleId,
    char* ObjectTypeName,
    char* ObjectName,
    PSECURITY_DESCRIPTOR SecurityDescriptor,
    unsigned long DesiredAccess,
    PGENERIC_MAPPING GenericMapping,
    BOOL ObjectCreation,
    unsigned long* GrantedAccess,
    BOOL* AccessStatus,
    BOOL* pfGenerateOnClose
    );
/*WINADVAPI*/
BOOL
__stdcall
AccessCheckAndAuditAlarmW (
    const wchar_t* SubsystemName,
    void* HandleId,
    wchar_t* ObjectTypeName,
    wchar_t* ObjectName,
    PSECURITY_DESCRIPTOR SecurityDescriptor,
    unsigned long DesiredAccess,
    PGENERIC_MAPPING GenericMapping,
    BOOL ObjectCreation,
    unsigned long* GrantedAccess,
    BOOL* AccessStatus,
    BOOL* pfGenerateOnClose
    );
#ifdef UNICODE
#define AccessCheckAndAuditAlarm  AccessCheckAndAuditAlarmW
#else
#define AccessCheckAndAuditAlarm  AccessCheckAndAuditAlarmA
#endif // !UNICODE


/*WINADVAPI*/
BOOL
__stdcall
ObjectOpenAuditAlarmA (
    const char* SubsystemName,
    void* HandleId,
    char* ObjectTypeName,
    char* ObjectName,
    PSECURITY_DESCRIPTOR pSecurityDescriptor,
    HANDLE ClientToken,
    unsigned long DesiredAccess,
    unsigned long GrantedAccess,
    PPRIVILEGE_SET Privileges,
    BOOL ObjectCreation,
    BOOL AccessGranted,
    BOOL* GenerateOnClose
    );
/*WINADVAPI*/
BOOL
__stdcall
ObjectOpenAuditAlarmW (
    const wchar_t* SubsystemName,
    void* HandleId,
    wchar_t* ObjectTypeName,
    wchar_t* ObjectName,
    PSECURITY_DESCRIPTOR pSecurityDescriptor,
    HANDLE ClientToken,
    unsigned long DesiredAccess,
    unsigned long GrantedAccess,
    PPRIVILEGE_SET Privileges,
    BOOL ObjectCreation,
    BOOL AccessGranted,
    BOOL* GenerateOnClose
    );
#ifdef UNICODE
#define ObjectOpenAuditAlarm  ObjectOpenAuditAlarmW
#else
#define ObjectOpenAuditAlarm  ObjectOpenAuditAlarmA
#endif // !UNICODE


/*WINADVAPI*/
BOOL
__stdcall
ObjectPrivilegeAuditAlarmA (
    const char* SubsystemName,
    void* HandleId,
    HANDLE ClientToken,
    unsigned long DesiredAccess,
    PPRIVILEGE_SET Privileges,
    BOOL AccessGranted
    );
/*WINADVAPI*/
BOOL
__stdcall
ObjectPrivilegeAuditAlarmW (
    const wchar_t* SubsystemName,
    void* HandleId,
    HANDLE ClientToken,
    unsigned long DesiredAccess,
    PPRIVILEGE_SET Privileges,
    BOOL AccessGranted
    );
#ifdef UNICODE
#define ObjectPrivilegeAuditAlarm  ObjectPrivilegeAuditAlarmW
#else
#define ObjectPrivilegeAuditAlarm  ObjectPrivilegeAuditAlarmA
#endif // !UNICODE


/*WINADVAPI*/
BOOL
__stdcall
ObjectCloseAuditAlarmA (
    const char* SubsystemName,
    void* HandleId,
    BOOL GenerateOnClose
    );
/*WINADVAPI*/
BOOL
__stdcall
ObjectCloseAuditAlarmW (
    const wchar_t* SubsystemName,
    void* HandleId,
    BOOL GenerateOnClose
    );
#ifdef UNICODE
#define ObjectCloseAuditAlarm  ObjectCloseAuditAlarmW
#else
#define ObjectCloseAuditAlarm  ObjectCloseAuditAlarmA
#endif // !UNICODE


/*WINADVAPI*/
BOOL
__stdcall
ObjectDeleteAuditAlarmA (
    const char* SubsystemName,
    void* HandleId,
    BOOL GenerateOnClose
    );
/*WINADVAPI*/
BOOL
__stdcall
ObjectDeleteAuditAlarmW (
    const wchar_t* SubsystemName,
    void* HandleId,
    BOOL GenerateOnClose
    );
#ifdef UNICODE
#define ObjectDeleteAuditAlarm  ObjectDeleteAuditAlarmW
#else
#define ObjectDeleteAuditAlarm  ObjectDeleteAuditAlarmA
#endif // !UNICODE


/*WINADVAPI*/
BOOL
__stdcall
PrivilegedServiceAuditAlarmA (
    const char* SubsystemName,
    const char* ServiceName,
    HANDLE ClientToken,
    PPRIVILEGE_SET Privileges,
    BOOL AccessGranted
    );
/*WINADVAPI*/
BOOL
__stdcall
PrivilegedServiceAuditAlarmW (
    const wchar_t* SubsystemName,
    const wchar_t* ServiceName,
    HANDLE ClientToken,
    PPRIVILEGE_SET Privileges,
    BOOL AccessGranted
    );
#ifdef UNICODE
#define PrivilegedServiceAuditAlarm  PrivilegedServiceAuditAlarmW
#else
#define PrivilegedServiceAuditAlarm  PrivilegedServiceAuditAlarmA
#endif // !UNICODE


/*WINADVAPI*/
BOOL
__stdcall
IsValidSid (
    PSID pSid
    );


/*WINADVAPI*/
BOOL
__stdcall
EqualSid (
    PSID pSid1,
    PSID pSid2
    );


/*WINADVAPI*/
BOOL
__stdcall
EqualPrefixSid (
    PSID pSid1,
    PSID pSid2
    );


/*WINADVAPI*/
unsigned long
__stdcall
GetSidLengthRequired (
    UCHAR nSubAuthorityCount
    );


/*WINADVAPI*/
BOOL
__stdcall
AllocateAndInitializeSid (
    PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,
    BYTE nSubAuthorityCount,
    unsigned long nSubAuthority0,
    unsigned long nSubAuthority1,
    unsigned long nSubAuthority2,
    unsigned long nSubAuthority3,
    unsigned long nSubAuthority4,
    unsigned long nSubAuthority5,
    unsigned long nSubAuthority6,
    unsigned long nSubAuthority7,
    PSID* pSid
    );

/*WINADVAPI*/
void*
__stdcall
FreeSid(
    PSID pSid
    );

/*WINADVAPI*/
BOOL
__stdcall
InitializeSid (
    PSID Sid,
    PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,
    BYTE nSubAuthorityCount
    );


/*WINADVAPI*/
PSID_IDENTIFIER_AUTHORITY
__stdcall
GetSidIdentifierAuthority (
    PSID pSid
    );


/*WINADVAPI*/
unsigned long*
__stdcall
GetSidSubAuthority (
    PSID pSid,
    unsigned long nSubAuthority
    );


/*WINADVAPI*/
PUCHAR
__stdcall
GetSidSubAuthorityCount (
    PSID pSid
    );


/*WINADVAPI*/
unsigned long
__stdcall
GetLengthSid (
    PSID pSid
    );


/*WINADVAPI*/
BOOL
__stdcall
CopySid (
    unsigned long nDestinationSidLength,
    PSID pDestinationSid,
    PSID pSourceSid
    );


/*WINADVAPI*/
BOOL
__stdcall
AreAllAccessesGranted (
    unsigned long GrantedAccess,
    unsigned long DesiredAccess
    );


/*WINADVAPI*/
BOOL
__stdcall
AreAnyAccessesGranted (
    unsigned long GrantedAccess,
    unsigned long DesiredAccess
    );


/*WINADVAPI*/
void
__stdcall
MapGenericMask (
    unsigned long* AccessMask,
    PGENERIC_MAPPING GenericMapping
    );


/*WINADVAPI*/
BOOL
__stdcall
IsValidAcl (
    PACL pAcl
    );


/*WINADVAPI*/
BOOL
__stdcall
InitializeAcl (
    PACL pAcl,
    unsigned long nAclLength,
    unsigned long dwAclRevision
    );


/*WINADVAPI*/
BOOL
__stdcall
GetAclInformation (
    PACL pAcl,
    void* pAclInformation,
    unsigned long nAclInformationLength,
    ACL_INFORMATION_CLASS dwAclInformationClass
    );


/*WINADVAPI*/
BOOL
__stdcall
SetAclInformation (
    PACL pAcl,
    void* pAclInformation,
    unsigned long nAclInformationLength,
    ACL_INFORMATION_CLASS dwAclInformationClass
    );


/*WINADVAPI*/
BOOL
__stdcall
AddAce (
    PACL pAcl,
    unsigned long dwAceRevision,
    unsigned long dwStartingAceIndex,
    void* pAceList,
    unsigned long nAceListLength
    );


/*WINADVAPI*/
BOOL
__stdcall
DeleteAce (
    PACL pAcl,
    unsigned long dwAceIndex
    );


/*WINADVAPI*/
BOOL
__stdcall
GetAce (
    PACL pAcl,
    unsigned long dwAceIndex,
    void** pAce
    );


/*WINADVAPI*/
BOOL
__stdcall
AddAccessAllowedAce (
    PACL pAcl,
    unsigned long dwAceRevision,
    unsigned long AccessMask,
    PSID pSid
    );


/*WINADVAPI*/
BOOL
__stdcall
AddAccessDeniedAce (
    PACL pAcl,
    unsigned long dwAceRevision,
    unsigned long AccessMask,
    PSID pSid
    );


/*WINADVAPI*/
BOOL
__stdcall
AddAuditAccessAce(
    PACL pAcl,
    unsigned long dwAceRevision,
    unsigned long dwAccessMask,
    PSID pSid,
    BOOL bAuditSuccess,
    BOOL bAuditFailure
    );


/*WINADVAPI*/
BOOL
__stdcall
FindFirstFreeAce (
    PACL pAcl,
    void** pAce
    );


/*WINADVAPI*/
BOOL
__stdcall
InitializeSecurityDescriptor (
    PSECURITY_DESCRIPTOR pSecurityDescriptor,
    unsigned long dwRevision
    );


/*WINADVAPI*/
BOOL
__stdcall
IsValidSecurityDescriptor (
    PSECURITY_DESCRIPTOR pSecurityDescriptor
    );


/*WINADVAPI*/
unsigned long
__stdcall
GetSecurityDescriptorLength (
    PSECURITY_DESCRIPTOR pSecurityDescriptor
    );


/*WINADVAPI*/
BOOL
__stdcall
GetSecurityDescriptorControl (
    PSECURITY_DESCRIPTOR pSecurityDescriptor,
    PSECURITY_DESCRIPTOR_CONTROL pControl,
    unsigned long* lpdwRevision
    );


/*WINADVAPI*/
BOOL
__stdcall
SetSecurityDescriptorDacl (
    PSECURITY_DESCRIPTOR pSecurityDescriptor,
    BOOL bDaclPresent,
    PACL pDacl,
    BOOL bDaclDefaulted
    );


/*WINADVAPI*/
BOOL
__stdcall
GetSecurityDescriptorDacl (
    PSECURITY_DESCRIPTOR pSecurityDescriptor,
    BOOL* lpbDaclPresent,
    PACL* pDacl,
    BOOL* lpbDaclDefaulted
    );


/*WINADVAPI*/
BOOL
__stdcall
SetSecurityDescriptorSacl (
    PSECURITY_DESCRIPTOR pSecurityDescriptor,
    BOOL bSaclPresent,
    PACL pSacl,
    BOOL bSaclDefaulted
    );


/*WINADVAPI*/
BOOL
__stdcall
GetSecurityDescriptorSacl (
    PSECURITY_DESCRIPTOR pSecurityDescriptor,
    BOOL* lpbSaclPresent,
    PACL* pSacl,
    BOOL* lpbSaclDefaulted
    );


/*WINADVAPI*/
BOOL
__stdcall
SetSecurityDescriptorOwner (
    PSECURITY_DESCRIPTOR pSecurityDescriptor,
    PSID pOwner,
    BOOL bOwnerDefaulted
    );


/*WINADVAPI*/
BOOL
__stdcall
GetSecurityDescriptorOwner (
    PSECURITY_DESCRIPTOR pSecurityDescriptor,
    PSID* pOwner,
    BOOL* lpbOwnerDefaulted
    );


/*WINADVAPI*/
BOOL
__stdcall
SetSecurityDescriptorGroup (
    PSECURITY_DESCRIPTOR pSecurityDescriptor,
    PSID pGroup,
    BOOL bGroupDefaulted
    );


/*WINADVAPI*/
BOOL
__stdcall
GetSecurityDescriptorGroup (
    PSECURITY_DESCRIPTOR pSecurityDescriptor,
    PSID* pGroup,
    BOOL* lpbGroupDefaulted
    );


/*WINADVAPI*/
BOOL
__stdcall
CreatePrivateObjectSecurity (
    PSECURITY_DESCRIPTOR ParentDescriptor,
    PSECURITY_DESCRIPTOR CreatorDescriptor,
    PSECURITY_DESCRIPTOR*  NewDescriptor,
    BOOL IsDirectoryObject,
    HANDLE Token,
    PGENERIC_MAPPING GenericMapping
    );


/*WINADVAPI*/
BOOL
__stdcall
SetPrivateObjectSecurity (
    SECURITY_INFORMATION SecurityInformation,
    PSECURITY_DESCRIPTOR ModificationDescriptor,
    PSECURITY_DESCRIPTOR* ObjectsSecurityDescriptor,
    PGENERIC_MAPPING GenericMapping,
    HANDLE Token
    );


/*WINADVAPI*/
BOOL
__stdcall
GetPrivateObjectSecurity (
    PSECURITY_DESCRIPTOR ObjectDescriptor,
    SECURITY_INFORMATION SecurityInformation,
    PSECURITY_DESCRIPTOR ResultantDescriptor,
    unsigned long DescriptorLength,
    unsigned long* ReturnLength
    );


/*WINADVAPI*/
BOOL
__stdcall
DestroyPrivateObjectSecurity (
    PSECURITY_DESCRIPTOR*  ObjectDescriptor
    );


/*WINADVAPI*/
BOOL
__stdcall
MakeSelfRelativeSD (
    PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,
    PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,
    unsigned long* lpdwBufferLength
    );


/*WINADVAPI*/
BOOL
__stdcall
MakeAbsoluteSD (
    PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,
    PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,
    unsigned long* lpdwAbsoluteSecurityDescriptorSize,
    PACL pDacl,
    unsigned long* lpdwDaclSize,
    PACL pSacl,
    unsigned long* lpdwSaclSize,
    PSID pOwner,
    unsigned long* lpdwOwnerSize,
    PSID pPrimaryGroup,
    unsigned long* lpdwPrimaryGroupSize
    );


/*WINADVAPI*/
BOOL
__stdcall
SetFileSecurityA (
    const char* lpFileName,
    SECURITY_INFORMATION SecurityInformation,
    PSECURITY_DESCRIPTOR pSecurityDescriptor
    );
/*WINADVAPI*/
BOOL
__stdcall
SetFileSecurityW (
    const wchar_t* lpFileName,
    SECURITY_INFORMATION SecurityInformation,
    PSECURITY_DESCRIPTOR pSecurityDescriptor
    );
#ifdef UNICODE
#define SetFileSecurity  SetFileSecurityW
#else
#define SetFileSecurity  SetFileSecurityA
#endif // !UNICODE


/*WINADVAPI*/
BOOL
__stdcall
GetFileSecurityA (
    const char* lpFileName,
    SECURITY_INFORMATION RequestedInformation,
    PSECURITY_DESCRIPTOR pSecurityDescriptor,
    unsigned long nLength,
    unsigned long* lpnLengthNeeded
    );
/*WINADVAPI*/
BOOL
__stdcall
GetFileSecurityW (
    const wchar_t* lpFileName,
    SECURITY_INFORMATION RequestedInformation,
    PSECURITY_DESCRIPTOR pSecurityDescriptor,
    unsigned long nLength,
    unsigned long* lpnLengthNeeded
    );
#ifdef UNICODE
#define GetFileSecurity  GetFileSecurityW
#else
#define GetFileSecurity  GetFileSecurityA
#endif // !UNICODE


/*WINADVAPI*/
BOOL
__stdcall
SetKernelObjectSecurity (
    HANDLE Handle,
    SECURITY_INFORMATION SecurityInformation,
    PSECURITY_DESCRIPTOR SecurityDescriptor
    );



/*WINBASEAPI*/
HANDLE
__stdcall
FindFirstChangeNotificationA(
    const char* lpPathName,
    BOOL bWatchSubtree,
    unsigned long dwNotifyFilter
    );
/*WINBASEAPI*/
HANDLE
__stdcall
FindFirstChangeNotificationW(
    const wchar_t* lpPathName,
    BOOL bWatchSubtree,
    unsigned long dwNotifyFilter
    );
#ifdef UNICODE
#define FindFirstChangeNotification  FindFirstChangeNotificationW
#else
#define FindFirstChangeNotification  FindFirstChangeNotificationA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
FindNextChangeNotification(
    HANDLE hChangeHandle
    );

/*WINBASEAPI*/
BOOL
__stdcall
FindCloseChangeNotification(
    HANDLE hChangeHandle
    );

#if(_WIN32_WINNT >= 0x0400)
/*WINBASEAPI*/
BOOL
__stdcall
ReadDirectoryChangesW(
    HANDLE hDirectory,
    void* lpBuffer,
    unsigned long nBufferLength,
    BOOL bWatchSubtree,
    unsigned long dwNotifyFilter,
    unsigned long* lpBytesReturned,
    OVERLAPPED* lpOverlapped,
    LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
    );
#endif /* _WIN32_WINNT >= 0x0400 */

/*WINBASEAPI*/
BOOL
__stdcall
VirtualLock(
    void* lpAddress,
    unsigned long dwSize
    );

/*WINBASEAPI*/
BOOL
__stdcall
VirtualUnlock(
    void* lpAddress,
    unsigned long dwSize
    );

/*WINBASEAPI*/
void*
__stdcall
MapViewOfFileEx(
    HANDLE hFileMappingObject,
    unsigned long dwDesiredAccess,
    unsigned long dwFileOffsetHigh,
    unsigned long dwFileOffsetLow,
    unsigned long dwNumberOfBytesToMap,
    void* lpBaseAddress
    );

/*WINBASEAPI*/
BOOL
__stdcall
SetPriorityClass(
    HANDLE hProcess,
    unsigned long dwPriorityClass
    );

/*WINBASEAPI*/
unsigned long
__stdcall
GetPriorityClass(
    HANDLE hProcess
    );

/*WINBASEAPI*/
BOOL
__stdcall
IsBadReadPtr(
    const void* lp,
    unsigned ucb
    );

/*WINBASEAPI*/
BOOL
__stdcall
IsBadWritePtr(
    void* lp,
    unsigned ucb
    );

/*WINBASEAPI*/
BOOL
__stdcall
IsBadHugeReadPtr(
    const void* lp,
    unsigned ucb
    );

/*WINBASEAPI*/
BOOL
__stdcall
IsBadHugeWritePtr(
    void* lp,
    unsigned ucb
    );

/*WINBASEAPI*/
BOOL
__stdcall
IsBadCodePtr(
    FARPROC lpfn
    );

/*WINBASEAPI*/
BOOL
__stdcall
IsBadStringPtrA(
    const char* lpsz,
    unsigned ucchMax
    );
/*WINBASEAPI*/
BOOL
__stdcall
IsBadStringPtrW(
    const wchar_t* lpsz,
    unsigned ucchMax
    );
#ifdef UNICODE
#define IsBadStringPtr  IsBadStringPtrW
#else
#define IsBadStringPtr  IsBadStringPtrA
#endif // !UNICODE

/*WINADVAPI*/
BOOL
__stdcall
LookupAccountSidA(
    const char* lpSystemName,
    PSID Sid,
    char* Name,
    unsigned long* cbName,
    char* ReferencedDomainName,
    unsigned long* cbReferencedDomainName,
    PSID_NAME_USE peUse
    );
/*WINADVAPI*/
BOOL
__stdcall
LookupAccountSidW(
    const wchar_t* lpSystemName,
    PSID Sid,
    wchar_t* Name,
    unsigned long* cbName,
    wchar_t* ReferencedDomainName,
    unsigned long* cbReferencedDomainName,
    PSID_NAME_USE peUse
    );
#ifdef UNICODE
#define LookupAccountSid  LookupAccountSidW
#else
#define LookupAccountSid  LookupAccountSidA
#endif // !UNICODE

/*WINADVAPI*/
BOOL
__stdcall
LookupAccountNameA(
    const char* lpSystemName,
    const char* lpAccountName,
    PSID Sid,
    unsigned long* cbSid,
    char* ReferencedDomainName,
    unsigned long* cbReferencedDomainName,
    PSID_NAME_USE peUse
    );
/*WINADVAPI*/
BOOL
__stdcall
LookupAccountNameW(
    const wchar_t* lpSystemName,
    const wchar_t* lpAccountName,
    PSID Sid,
    unsigned long* cbSid,
    wchar_t* ReferencedDomainName,
    unsigned long* cbReferencedDomainName,
    PSID_NAME_USE peUse
    );
#ifdef UNICODE
#define LookupAccountName  LookupAccountNameW
#else
#define LookupAccountName  LookupAccountNameA
#endif // !UNICODE

/*WINADVAPI*/
BOOL
__stdcall
LookupPrivilegeValueA(
    const char* lpSystemName,
    const char* lpName,
    PLUID   lpLuid
    );
/*WINADVAPI*/
BOOL
__stdcall
LookupPrivilegeValueW(
    const wchar_t* lpSystemName,
    const wchar_t* lpName,
    PLUID   lpLuid
    );
#ifdef UNICODE
#define LookupPrivilegeValue  LookupPrivilegeValueW
#else
#define LookupPrivilegeValue  LookupPrivilegeValueA
#endif // !UNICODE

/*WINADVAPI*/
BOOL
__stdcall
LookupPrivilegeNameA(
    const char* lpSystemName,
    PLUID   lpLuid,
    char* lpName,
    unsigned long* cbName
    );
/*WINADVAPI*/
BOOL
__stdcall
LookupPrivilegeNameW(
    const wchar_t* lpSystemName,
    PLUID   lpLuid,
    wchar_t* lpName,
    unsigned long* cbName
    );
#ifdef UNICODE
#define LookupPrivilegeName  LookupPrivilegeNameW
#else
#define LookupPrivilegeName  LookupPrivilegeNameA
#endif // !UNICODE

/*WINADVAPI*/
BOOL
__stdcall
LookupPrivilegeDisplayNameA(
    const char* lpSystemName,
    const char* lpName,
    char* lpDisplayName,
    unsigned long* cbDisplayName,
    unsigned long* lpLanguageId
    );
/*WINADVAPI*/
BOOL
__stdcall
LookupPrivilegeDisplayNameW(
    const wchar_t* lpSystemName,
    const wchar_t* lpName,
    wchar_t* lpDisplayName,
    unsigned long* cbDisplayName,
    unsigned long* lpLanguageId
    );
#ifdef UNICODE
#define LookupPrivilegeDisplayName  LookupPrivilegeDisplayNameW
#else
#define LookupPrivilegeDisplayName  LookupPrivilegeDisplayNameA
#endif // !UNICODE

/*WINADVAPI*/
BOOL
__stdcall
AllocateLocallyUniqueId(
    PLUID Luid
    );

/*WINBASEAPI*/
BOOL
__stdcall
BuildCommDCBA(
    const char* lpDef,
    LPDCB lpDCB
    );
/*WINBASEAPI*/
BOOL
__stdcall
BuildCommDCBW(
    const wchar_t* lpDef,
    LPDCB lpDCB
    );
#ifdef UNICODE
#define BuildCommDCB  BuildCommDCBW
#else
#define BuildCommDCB  BuildCommDCBA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
BuildCommDCBAndTimeoutsA(
    const char* lpDef,
    LPDCB lpDCB,
    LPCOMMTIMEOUTS lpCommTimeouts
    );
/*WINBASEAPI*/
BOOL
__stdcall
BuildCommDCBAndTimeoutsW(
    const wchar_t* lpDef,
    LPDCB lpDCB,
    LPCOMMTIMEOUTS lpCommTimeouts
    );
#ifdef UNICODE
#define BuildCommDCBAndTimeouts  BuildCommDCBAndTimeoutsW
#else
#define BuildCommDCBAndTimeouts  BuildCommDCBAndTimeoutsA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
CommConfigDialogA(
    const char* lpszName,
    HWND hWnd,
    LPCOMMCONFIG lpCC
    );
/*WINBASEAPI*/
BOOL
__stdcall
CommConfigDialogW(
    const wchar_t* lpszName,
    HWND hWnd,
    LPCOMMCONFIG lpCC
    );
#ifdef UNICODE
#define CommConfigDialog  CommConfigDialogW
#else
#define CommConfigDialog  CommConfigDialogA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
GetDefaultCommConfigA(
    const char* lpszName,
    LPCOMMCONFIG lpCC,
    unsigned long* lpdwSize
    );
/*WINBASEAPI*/
BOOL
__stdcall
GetDefaultCommConfigW(
    const wchar_t* lpszName,
    LPCOMMCONFIG lpCC,
    unsigned long* lpdwSize
    );
#ifdef UNICODE
#define GetDefaultCommConfig  GetDefaultCommConfigW
#else
#define GetDefaultCommConfig  GetDefaultCommConfigA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
SetDefaultCommConfigA(
    const char* lpszName,
    LPCOMMCONFIG lpCC,
    unsigned long dwSize
    );
/*WINBASEAPI*/
BOOL
__stdcall
SetDefaultCommConfigW(
    const wchar_t* lpszName,
    LPCOMMCONFIG lpCC,
    unsigned long dwSize
    );
#ifdef UNICODE
#define SetDefaultCommConfig  SetDefaultCommConfigW
#else
#define SetDefaultCommConfig  SetDefaultCommConfigA
#endif // !UNICODE

#define MAX_COMPUTERNAME_LENGTH 15

/*WINBASEAPI*/
BOOL
__stdcall
GetComputerNameA (
    char* lpBuffer,
    unsigned long* nSize
    );
/*WINBASEAPI*/
BOOL
__stdcall
GetComputerNameW (
    wchar_t* lpBuffer,
    unsigned long* nSize
    );
#ifdef UNICODE
#define GetComputerName  GetComputerNameW
#else
#define GetComputerName  GetComputerNameA
#endif // !UNICODE

/*WINBASEAPI*/
BOOL
__stdcall
SetComputerNameA (
    const char* lpComputerName
    );
/*WINBASEAPI*/
BOOL
__stdcall
SetComputerNameW (
    const wchar_t* lpComputerName
    );
#ifdef UNICODE
#define SetComputerName  SetComputerNameW
#else
#define SetComputerName  SetComputerNameA
#endif // !UNICODE

/*WINADVAPI*/
BOOL
__stdcall
GetUserNameA (
    char* lpBuffer,
    unsigned long* nSize
    );
/*WINADVAPI*/
BOOL
__stdcall
GetUserNameW (
    wchar_t* lpBuffer,
    unsigned long* nSize
    );
#ifdef UNICODE
#define GetUserName  GetUserNameW
#else
#define GetUserName  GetUserNameA
#endif // !UNICODE

//
// Logon Support APIs
//

#define LOGON32_LOGON_INTERACTIVE   2
#define LOGON32_LOGON_NETWORK       3
#define LOGON32_LOGON_BATCH         4
#define LOGON32_LOGON_SERVICE       5

#define LOGON32_PROVIDER_DEFAULT    0
#define LOGON32_PROVIDER_WINNT35    1
#if(_WIN32_WINNT >= 0x0400)
#define LOGON32_PROVIDER_WINNT40    2
#endif /* _WIN32_WINNT >= 0x0400 */



/*WINADVAPI*/
BOOL
__stdcall
LogonUserA (
    char* lpszUsername,
    char* lpszDomain,
    char* lpszPassword,
    unsigned long dwLogonType,
    unsigned long dwLogonProvider,
    HANDLE* phToken
    );
/*WINADVAPI*/
BOOL
__stdcall
LogonUserW (
    wchar_t* lpszUsername,
    wchar_t* lpszDomain,
    wchar_t* lpszPassword,
    unsigned long dwLogonType,
    unsigned long dwLogonProvider,
    HANDLE* phToken
    );
#ifdef UNICODE
#define LogonUser  LogonUserW
#else
#define LogonUser  LogonUserA
#endif // !UNICODE

/*WINADVAPI*/
BOOL
__stdcall
ImpersonateLoggedOnUser(
    HANDLE  hToken
    );

/*WINADVAPI*/
BOOL
__stdcall
CreateProcessAsUserA (
    HANDLE hToken,
    const char* lpApplicationName,
    char* lpCommandLine,
    LPSECURITY_ATTRIBUTES lpProcessAttributes,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    BOOL bInheritHandles,
    unsigned long dwCreationFlags,
    void* lpEnvironment,
    const char* lpCurrentDirectory,
    LPSTARTUPINFOA lpStartupInfo,
    LPPROCESS_INFORMATION lpProcessInformation
    );
/*WINADVAPI*/
BOOL
__stdcall
CreateProcessAsUserW (
    HANDLE hToken,
    const wchar_t* lpApplicationName,
    wchar_t* lpCommandLine,
    LPSECURITY_ATTRIBUTES lpProcessAttributes,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    BOOL bInheritHandles,
    unsigned long dwCreationFlags,
    void* lpEnvironment,
    const wchar_t* lpCurrentDirectory,
    LPSTARTUPINFOW lpStartupInfo,
    LPPROCESS_INFORMATION lpProcessInformation
    );
#ifdef UNICODE
#define CreateProcessAsUser  CreateProcessAsUserW
#else
#define CreateProcessAsUser  CreateProcessAsUserA
#endif // !UNICODE

/*WINADVAPI*/
BOOL
__stdcall
DuplicateTokenEx(
    HANDLE hExistingToken,
    unsigned long dwDesiredAccess,
    LPSECURITY_ATTRIBUTES lpTokenAttributes,
    SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,
    TOKEN_TYPE TokenType,
    HANDLE* phNewToken);


#if(_WIN32_WINNT >= 0x0400)
//
// Plug-and-Play API's
//

#define HW_PROFILE_GUIDLEN         39      // 36-characters plus NULL terminator
#define MAX_PROFILE_LEN            80

#define DOCKINFO_UNDOCKED          (0x1)
#define DOCKINFO_DOCKED            (0x2)
#define DOCKINFO_USER_SUPPLIED     (0x4)
#define DOCKINFO_USER_UNDOCKED     (DOCKINFO_USER_SUPPLIED | DOCKINFO_UNDOCKED)
#define DOCKINFO_USER_DOCKED       (DOCKINFO_USER_SUPPLIED | DOCKINFO_DOCKED)

typedef struct tagHW_PROFILE_INFOA {
    unsigned long  dwDockInfo;
    char   szHwProfileGuid[HW_PROFILE_GUIDLEN];
    char   szHwProfileName[MAX_PROFILE_LEN];
} HW_PROFILE_INFOA, *LPHW_PROFILE_INFOA;
typedef struct tagHW_PROFILE_INFOW {
    unsigned long  dwDockInfo;
    wchar_t  szHwProfileGuid[HW_PROFILE_GUIDLEN];
    wchar_t  szHwProfileName[MAX_PROFILE_LEN];
} HW_PROFILE_INFOW, *LPHW_PROFILE_INFOW;
#ifdef UNICODE
typedef HW_PROFILE_INFOW HW_PROFILE_INFO;
typedef LPHW_PROFILE_INFOW LPHW_PROFILE_INFO;
#else
typedef HW_PROFILE_INFOA HW_PROFILE_INFO;
typedef LPHW_PROFILE_INFOA LPHW_PROFILE_INFO;
#endif // UNICODE


/*WINADVAPI*/
BOOL
__stdcall
GetCurrentHwProfileA (
    OUT LPHW_PROFILE_INFOA  lpHwProfileInfo
    );
/*WINADVAPI*/
BOOL
__stdcall
GetCurrentHwProfileW (
    OUT LPHW_PROFILE_INFOW  lpHwProfileInfo
    );
#ifdef UNICODE
#define GetCurrentHwProfile  GetCurrentHwProfileW
#else
#define GetCurrentHwProfile  GetCurrentHwProfileA
#endif // !UNICODE
#endif /* _WIN32_WINNT >= 0x0400 */

//
// Performance counter API's
//

/*WINBASEAPI*/
BOOL
__stdcall
QueryPerformanceCounter(
    LARGE_INTEGER* lpPerformanceCount
    );

/*WINBASEAPI*/
BOOL
__stdcall
QueryPerformanceFrequency(
    LARGE_INTEGER* lpFrequency
    );

typedef struct _OSVERSIONINFOA {
    unsigned long dwOSVersionInfoSize;
    unsigned long dwMajorVersion;
    unsigned long dwMinorVersion;
    unsigned long dwBuildNumber;
    unsigned long dwPlatformId;
    char   szCSDVersion[ 128 ];       // Maintenance string for PSS usage
} OSVERSIONINFOA, *POSVERSIONINFOA, *LPOSVERSIONINFOA;
typedef struct _OSVERSIONINFOW {
    unsigned long dwOSVersionInfoSize;
    unsigned long dwMajorVersion;
    unsigned long dwMinorVersion;
    unsigned long dwBuildNumber;
    unsigned long dwPlatformId;
    wchar_t  szCSDVersion[ 128 ];       // Maintenance string for PSS usage
} OSVERSIONINFOW, *POSVERSIONINFOW, *LPOSVERSIONINFOW;
#ifdef UNICODE
typedef OSVERSIONINFOW OSVERSIONINFO;
typedef POSVERSIONINFOW POSVERSIONINFO;
typedef LPOSVERSIONINFOW LPOSVERSIONINFO;
#else
typedef OSVERSIONINFOA OSVERSIONINFO;
typedef POSVERSIONINFOA POSVERSIONINFO;
typedef LPOSVERSIONINFOA LPOSVERSIONINFO;
#endif // UNICODE

//
// dwPlatformId defines:
//

#define VER_PLATFORM_WIN32s             0
#define VER_PLATFORM_WIN32_WINDOWS      1
#define VER_PLATFORM_WIN32_NT           2


/*WINBASEAPI*/
BOOL
__stdcall
GetVersionExA(
    LPOSVERSIONINFOA lpVersionInformation
    );
/*WINBASEAPI*/
BOOL
__stdcall
GetVersionExW(
    LPOSVERSIONINFOW lpVersionInformation
    );
#ifdef UNICODE
#define GetVersionEx  GetVersionExW
#else
#define GetVersionEx  GetVersionExA
#endif // !UNICODE


// DOS and OS/2 Compatible Error Code definitions returned by the Win32 Base
// API functions.
//

#include <winerror.h>

/* Abnormal termination codes */

#define TC_NORMAL       0
#define TC_HARDERR      1
#define TC_GP_TRAP      2
#define TC_SIGNAL       3

#if(WINVER >= 0x0400)
//
// Power Management APIs
//

#define AC_LINE_OFFLINE                 0x00
#define AC_LINE_ONLINE                  0x01
#define AC_LINE_BACKUP_POWER            0x02
#define AC_LINE_UNKNOWN                 0xFF

#define BATTERY_FLAG_HIGH               0x01
#define BATTERY_FLAG_LOW                0x02
#define BATTERY_FLAG_CRITICAL           0x04
#define BATTERY_FLAG_CHARGING           0x08
#define BATTERY_FLAG_NO_BATTERY         0x80
#define BATTERY_FLAG_UNKNOWN            0xFF

#define BATTERY_PERCENTAGE_UNKNOWN      0xFF

#define BATTERY_LIFE_UNKNOWN        0xFFFFFFFF

typedef struct _SYSTEM_POWER_STATUS {
    BYTE ACLineStatus;
    BYTE BatteryFlag;
    BYTE BatteryLifePercent;
    BYTE Reserved1;
    unsigned long BatteryLifeTime;
    unsigned long BatteryFullLifeTime;
}   SYSTEM_POWER_STATUS, *LPSYSTEM_POWER_STATUS;

BOOL
__stdcall
GetSystemPowerStatus(
    LPSYSTEM_POWER_STATUS lpSystemPowerStatus
    );

BOOL
__stdcall
SetSystemPowerState(
    BOOL fSuspend,
    BOOL fForce
    );

#endif /* WINVER >= 0x0400 */




///////////////////////////////////////////////////////////////
//                                                           //
//      Win Certificate API and Structures                   //
//                                                           //
///////////////////////////////////////////////////////////////

//
// Structures
//

typedef struct _WIN_CERTIFICATE {
    unsigned long       dwLength;
    WORD        wRevision;
    WORD        wCertificateType;   // WIN_CERT_TYPE_xxx
    BYTE        bCertificate[ANYSIZE_ARRAY];
} WIN_CERTIFICATE, *LPWIN_CERTIFICATE;

//
// Currently, the only defined certificate revision is WIN_CERT_REVISION_1_0
//

#define WIN_CERT_REVISION_1_0           (0x0100)

//
// Possible certificate types are specified by the following values
//

#define  WIN_CERT_TYPE_X509               (0x0001)   // bCertificate contains an X.509 Certificate
#define  WIN_CERT_TYPE_PKCS_SIGNED_DATA   (0x0002)   // bCertificate contains a PKCS SignedData structure
#define  WIN_CERT_TYPE_RESERVED_1         (0x0003)   // Reserved

//
// API
//




BOOL
__stdcall
WinSubmitCertificate(
    LPWIN_CERTIFICATE lpCertificate
    );



///////////////////////////////////////////////////////////////
//                                                           //
//             Trust API and Structures                      //
//                                                           //
///////////////////////////////////////////////////////////////

long
__stdcall
WinVerifyTrust(
    HWND    hwnd,
    GUID*   ActionID,
    void*  ActionData
    );


BOOL
__stdcall
WinLoadTrustProvider(
    GUID*  ActionID
    );

///////////////////////////////////////////////////////////////
//                                                           //
//             Common Trust API Data Structures              //
//                                                           //
///////////////////////////////////////////////////////////////


//
// Data type commonly used in ActionData structures
//

typedef void* WIN_TRUST_SUBJECT;

//
// Two commonly used ActionData structures
//

typedef struct _WIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJECT {

    HANDLE            hClientToken;
    GUID*             SubjectType;
    WIN_TRUST_SUBJECT Subject;

} WIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJECT, *LPWIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJECT ;


typedef struct _WIN_TRUST_ACTDATA_SUBJECT_ONLY {

    GUID*             SubjectType;
    WIN_TRUST_SUBJECT Subject;

} WIN_TRUST_ACTDATA_SUBJECT_ONLY, *LPWIN_TRUST_ACTDATA_SUBJECT_ONLY;


////////////////////////////////////////////////////////////////////
//                                                                 /
//      SUBJECT FORM DEFINITIONS                                   /
//                                                                 /
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//                                                                 /
// Currently defined Subject Type Identifiers.  All of the below   /
// use the WIN_TRUST_SUBJECT_FILE subject form, defined below.     /
//                                                                 /
////////////////////////////////////////////////////////////////////

/* RawFile == 959dc450-8d9e-11cf-8736-00aa00a485eb */
#define WIN_TRUST_SUBJTYPE_RAW_FILE                              \
            { 0x959dc450,                                        \
              0x8d9e,                                            \
              0x11cf,                                            \
              {0x87, 0x36, 0x00, 0xaa, 0x00, 0xa4, 0x85, 0xeb}   \
            }

/* PeImage == 43c9a1e0-8da0-11cf-8736-00aa00a485eb */
#define WIN_TRUST_SUBJTYPE_PE_IMAGE                              \
            { 0x43c9a1e0,                                        \
              0x8da0,                                            \
              0x11cf,                                            \
              {0x87, 0x36, 0x00, 0xaa, 0x00, 0xa4, 0x85, 0xeb}   \
            }


/* JavaClass = 08ad3990-8da1-11cf-8736-00aa00a485eb */
#define WIN_TRUST_SUBJTYPE_JAVA_CLASS                            \
            { 0x08ad3990,                                        \
              0x8da1,                                            \
              0x11cf,                                            \
              {0x87, 0x36, 0x00, 0xaa, 0x00, 0xa4, 0x85, 0xeb}   \
            }
/* Cabinet = d17c5374-a392-11cf-9df5-00aa00c184e0 */
#define WIN_TRUST_SUBJTYPE_CABINET                               \
            { 0xd17c5374,                                        \
              0xa392,                                            \
              0x11cf,                                            \
              { 0x9d, 0xf5, 0x0, 0xaa, 0x0, 0xc1, 0x84, 0xe0 }   \
            }

//
// Associated Subject Data Structure:
//

typedef struct _WIN_TRUST_SUBJECT_FILE {

    HANDLE  hFile;
    const wchar_t* lpPath;

} WIN_TRUST_SUBJECT_FILE, *LPWIN_TRUST_SUBJECT_FILE;




////////////////////////////////////////////////////////////////////
//                                                                 /
// The following subject types use the                             /
// WIN_TRUST_SUBJECT_FILE_AND_DISPLAY subject type, defined        /
// below.                                                          /
//                                                                 /
////////////////////////////////////////////////////////////////////

#define WIN_TRUST_SUBJTYPE_RAW_FILEEX                            \
            { 0x6f458110,                                        \
              0xc2f1,                                            \
              0x11cf,                                            \
              { 0x8a, 0x69, 0x0, 0xaa, 0x0, 0x6c, 0x37, 0x6 }    \
            }

#define WIN_TRUST_SUBJTYPE_PE_IMAGEEX                            \
            { 0x6f458111,                                        \
              0xc2f1,                                            \
              0x11cf,                                            \
              { 0x8a, 0x69, 0x0, 0xaa, 0x0, 0x6c, 0x37, 0x6 }    \
            }

#define WIN_TRUST_SUBJTYPE_JAVA_CLASSEX                          \
            { 0x6f458113,                                        \
              0xc2f1,                                            \
              0x11cf,                                            \
              { 0x8a, 0x69, 0x0, 0xaa, 0x0, 0x6c, 0x37, 0x6 }    \
            }

#define WIN_TRUST_SUBJTYPE_CABINETEX                             \
            { 0x6f458114,                                        \
              0xc2f1,                                            \
              0x11cf,                                            \
              { 0x8a, 0x69, 0x0, 0xaa, 0x0, 0x6c, 0x37, 0x6 }    \
            }

//
// Associated Subject Data Structure:
//

typedef struct _WIN_TRUST_SUBJECT_FILE_AND_DISPLAY {

    HANDLE  hFile;              // handle to the open file if you got it
    const wchar_t* lpPath;             // the path to open if you don't
    const wchar_t* lpDisplayName;      // (optional) display name to show to user 
                                //      in place of path

} WIN_TRUST_SUBJECT_FILE_AND_DISPLAY, *LPWIN_TRUST_SUBJECT_FILE_AND_DISPLAY;


////////////////////////////////////////////////////////////////////
//                                                                 /
// Other subject types:                                            /
//                                                                 /
////////////////////////////////////////////////////////////////////

/* OleStorage == c257e740-8da0-11cf-8736-00aa00a485eb */
#define WIN_TRUST_SUBJTYPE_OLE_STORAGE                           \
            { 0xc257e740,                                        \
              0x8da0,                                            \
              0x11cf,                                            \
              {0x87, 0x36, 0x00, 0xaa, 0x00, 0xa4, 0x85, 0xeb}   \
            }


////////////////////////////////////////////////////////////////////
//                                                                 /
//      TRUST PROVIDER SPECIFIC DEFINITIONS                        /
//                                                                 /
//                                                                 /
//      Each trust provider will have the following                /
//      sections defined:                                          /
//                                                                 /
//      Actions - What actions are supported by the trust          /
//          provider.                                              /
//                                                                 /
//      SubjectForms - Subjects that may be evaluated by this      /
//          trust provider.                                        /
//                                                                 /
//                     and                                         /
//                                                                 /
//      Data structures to support the subject forms.              /
//                                                                 /
//                                                                 /
////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////
//                                                                 /
//             Software Publisher Trust Provider                   /
//                                                                 /
////////////////////////////////////////////////////////////////////

//
// Actions:
//

/* TrustedPublisher == 66426730-8da1-11cf-8736-00aa00a485eb */
#define WIN_SPUB_ACTION_TRUSTED_PUBLISHER                        \
            { 0x66426730,                                        \
              0x8da1,                                            \
              0x11cf,                                            \
              {0x87, 0x36, 0x00, 0xaa, 0x00, 0xa4, 0x85, 0xeb}   \
            }

/* NtActivateImage == 8bc96b00-8da1-11cf-8736-00aa00a485eb */
#define     WIN_SPUB_ACTION_NT_ACTIVATE_IMAGE                    \
            { 0x8bc96b00,                                        \
              0x8da1,                                            \
              0x11cf,                                            \
              {0x87, 0x36, 0x00, 0xaa, 0x00, 0xa4, 0x85, 0xeb}   \
            }

/* PublishedSoftware == 64b9d180-8da2-11cf-8736-00aa00a485eb */
#define WIN_SPUB_ACTION_PUBLISHED_SOFTWARE                       \
            { 0x64b9d180,                                        \
              0x8da2,                                            \
              0x11cf,                                            \
              {0x87, 0x36, 0x00, 0xaa, 0x00, 0xa4, 0x85, 0xeb}   \
            }

//
// Data Structures:
//
// WIN_SPUB_ACTION_TRUSTED_PUBLISHER:
//
//      Uses WIN_SPUB_TRUSTED_PUBLISHER_DATA
//
// WIN_SPUB_ACTION_NT_ACTIVATE_IMAGE:
//
//      Uses WIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJECT
//
// WIN_SPUB_ACTION_PUBLISHED_SOFTWARE:
//
//      Uses WIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJECT
//

typedef struct _WIN_SPUB_TRUSTED_PUBLISHER_DATA {

    HANDLE            hClientToken;
    LPWIN_CERTIFICATE lpCertificate;

} WIN_SPUB_TRUSTED_PUBLISHER_DATA, *LPWIN_SPUB_TRUSTED_PUBLISHER_DATA;


#ifdef __cplusplus
}
#endif



#endif // _WINBASE_
#pragma once 
