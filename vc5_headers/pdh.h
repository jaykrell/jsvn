/*++

Copyright (C) 1996 Microsoft Corporation

Module Name:

    PDH.H

Abstract:

    Header file for the Performance Data Helper (PDH) DLL functions.

--*/
#ifndef _PDH_H_
#define _PDH_H_

// system include files required for datatype and constant definitions 
#include <windows.h>    // necessary for data types used in this file
#include <winperf.h>    // necessary for the Detail Level definitions

#ifdef __cplusplus
extern "C" {
#endif

typedef LONG            PDH_STATUS;

#define PDH_FUNCTION    PDH_STATUS __stdcall 

// version info
#define PDH_CVERSION_WIN40  0x0400
#define PDH_VERSION         PDH_CVERSION_WIN40

// define severity masks
#define IsSuccessSeverity(ErrorCode)    \
    ((((unsigned long)(ErrorCode) & (0xC0000000L)) == 0x00000000L) ? TRUE : FALSE)
#define IsInformationalSeverity(ErrorCode)    \
    ((((unsigned long)(ErrorCode) & (0xC0000000L)) == 0x40000000L) ? TRUE : FALSE)
#define IsWarningSeverity(ErrorCode)    \
    ((((unsigned long)(ErrorCode) & (0xC0000000L)) == 0x80000000L) ? TRUE : FALSE)
#define IsErrorSeverity(ErrorCode)      \
    ((((unsigned long)(ErrorCode) & (0xC0000000L)) == 0xC0000000L) ? TRUE : FALSE)

// data type definitions

typedef HANDLE  HCOUNTER;
typedef HANDLE  HQUERY;

typedef struct _PDH_RAW_COUNTER {
    unsigned long       CStatus;
    FILETIME    TimeStamp;
    LONGLONG    FirstValue;
    LONGLONG    SecondValue;
    unsigned long       MultiCount;
} PDH_RAW_COUNTER, *PPDH_RAW_COUNTER;

typedef struct _PDH_FMT_COUNTERVALUE {
    unsigned long    CStatus;
    union {
        LONG        longValue;
        double      doubleValue;
        LONGLONG    largeValue;
    };
} PDH_FMT_COUNTERVALUE, *PPDH_FMT_COUNTERVALUE;

typedef struct _PDH_STATISTICS {
    unsigned long                   dwFormat;
    unsigned long                   count;
    PDH_FMT_COUNTERVALUE    min;
    PDH_FMT_COUNTERVALUE    max;
    PDH_FMT_COUNTERVALUE    mean;
} PDH_STATISTICS, *PPDH_STATISTICS;

typedef struct _PDH_COUNTER_PATH_ELEMENTS_A {
    LPSTR   szMachineName;
    LPSTR   szObjectName;
    LPSTR   szInstanceName;
    LPSTR   szParentInstance;
    unsigned long   dwInstanceIndex;
    LPSTR   szCounterName;
} PDH_COUNTER_PATH_ELEMENTS_A, *PPDH_COUNTER_PATH_ELEMENTS_A;

typedef struct _PDH_COUNTER_PATH_ELEMENTS_W {
    LPWSTR  szMachineName;
    LPWSTR  szObjectName;
    LPWSTR  szInstanceName;
    LPWSTR  szParentInstance;
    unsigned long   dwInstanceIndex;
    LPWSTR  szCounterName;
} PDH_COUNTER_PATH_ELEMENTS_W, *PPDH_COUNTER_PATH_ELEMENTS_W;

typedef struct _PDH_COUNTER_INFO_A {
    unsigned long   dwLength;
    unsigned long   dwType;
    unsigned long   CVersion;
    unsigned long   CStatus;
    LONG    lScale;
    LONG    lDefaultScale;
    unsigned long   dwUserData;
    unsigned long   dwQueryUserData;
    LPSTR   szFullPath;
    union   {
        PDH_COUNTER_PATH_ELEMENTS_A CounterPath;
        struct {
            LPSTR   szMachineName;
            LPSTR   szObjectName;
            LPSTR   szInstanceName;
            LPSTR   szParentInstance;
            unsigned long   dwInstanceIndex;
            LPSTR   szCounterName;
        };
    };
    LPSTR   szExplainText;
    unsigned long   DataBuffer[1];
} PDH_COUNTER_INFO_A, *PPDH_COUNTER_INFO_A;

typedef struct _PDH_COUNTER_INFO_W {
    unsigned long   dwLength;
    unsigned long   dwType;
    unsigned long   CVersion;
    unsigned long   CStatus;
    LONG    lScale;
    LONG    lDefaultScale;
    unsigned long   dwUserData;
    unsigned long   dwQueryUserData;
    LPWSTR  szFullPath;
    union   {
        PDH_COUNTER_PATH_ELEMENTS_W CounterPath;
        struct {
            LPWSTR   szMachineName;
            LPWSTR   szObjectName;
            LPWSTR   szInstanceName;
            LPWSTR   szParentInstance;
            unsigned long    dwInstanceIndex;
            LPWSTR   szCounterName;
        };
    };
    LPWSTR  szExplainText;
    unsigned long   DataBuffer[1];
} PDH_COUNTER_INFO_W, *PPDH_COUNTER_INFO_W;

// function definitions

PDH_FUNCTION 
PdhGetDllVersion(
    IN  LPDWORD lpdwVersion
);

//
//  Query Functions
//

PDH_FUNCTION
PdhOpenQuery (
    IN      void*      pReserved,
    IN      unsigned long       dwUserData,
    IN      HQUERY      *phQuery
);

PDH_FUNCTION
PdhAddCounterW (
    IN      HQUERY      hQuery,
    IN      const wchar_t*     szFullCounterPath,
    IN      unsigned long       dwUserData,
    IN      HCOUNTER    *phCounter
);

PDH_FUNCTION
PdhAddCounterA (
    IN      HQUERY      hQuery,
    IN      const char*      szFullCounterPath,
    IN      unsigned long       dwUserData,
    IN      HCOUNTER    *phCounter
);

PDH_FUNCTION
PdhRemoveCounter (
    IN      HCOUNTER    hCounter
);

PDH_FUNCTION
PdhCollectQueryData (
    IN      HQUERY      hQuery
);

PDH_FUNCTION
PdhCloseQuery (
    IN      HQUERY      hQuery
);
    
//
//  Counter Functions
//

PDH_FUNCTION
PdhGetFormattedCounterValue (
    IN      HCOUNTER                hCounter,
    IN      unsigned long                   dwFormat,
    IN      LPDWORD                 lpdwType,
    IN      PPDH_FMT_COUNTERVALUE   pValue
);

// dwFormat flag values
// 
#define PDH_FMT_RAW     ((unsigned long)0x00000010)
#define PDH_FMT_ANSI    ((unsigned long)0x00000020)
#define PDH_FMT_UNICODE ((unsigned long)0x00000040)
#define PDH_FMT_LONG    ((unsigned long)0x00000100)
#define PDH_FMT_DOUBLE  ((unsigned long)0x00000200)
#define PDH_FMT_LARGE   ((unsigned long)0x00000400)
#define PDH_FMT_NOSCALE ((unsigned long)0x00001000)
#define PDH_FMT_1000    ((unsigned long)0x00002000)
#define PDH_FMT_NODATA  ((unsigned long)0x00004000)

PDH_FUNCTION
PdhGetRawCounterValue (
    IN      HCOUNTER            hCounter,
    IN      LPDWORD             lpdwType,
    IN      PPDH_RAW_COUNTER    pValue
);

PDH_FUNCTION
PdhCalculateCounterFromRawValue (
    IN      HCOUNTER                hCounter,
    IN      unsigned long                   dwFormat,
    IN      PPDH_RAW_COUNTER        rawValue1,
    IN      PPDH_RAW_COUNTER        rawValue2,
    IN      PPDH_FMT_COUNTERVALUE   fmtValue
);

PDH_FUNCTION
PdhComputeCounterStatistics (
    IN      HCOUNTER            hCounter,
    IN      unsigned long               dwFormat,
    IN      unsigned long               dwFirstEntry,
    IN      unsigned long               dwNumEntries,
    IN      PPDH_RAW_COUNTER    lpRawValueArray,
    IN      PPDH_STATISTICS     data
);

PDH_FUNCTION
PdhGetCounterInfoW (
    IN      HCOUNTER            hCounter,
    IN      BOOLEAN             bRetrieveExplainText,
    IN      LPDWORD             pdwBufferSize,
    IN      PPDH_COUNTER_INFO_W lpBuffer
);

PDH_FUNCTION
PdhGetCounterInfoA (
    IN      HCOUNTER            hCounter,
    IN      BOOLEAN             bRetrieveExplainText,
    IN      LPDWORD             pdwBufferSize,
    IN      PPDH_COUNTER_INFO_A lpBuffer
);

#define PDH_MAX_SCALE    (7L)
#define PDH_MIN_SCALE   (-7L)

PDH_FUNCTION
PdhSetCounterScaleFactor (
    IN      HCOUNTER    hCounter,
    IN      LONG        lFactor
);
//
//   Browsing and enumeration functions
//
PDH_FUNCTION
PdhConnectMachineW (
    IN      const wchar_t*  szMachineName
);

PDH_FUNCTION
PdhConnectMachineA (
    IN      const char*  szMachineName
);

PDH_FUNCTION
PdhEnumMachinesW (
    IN      const wchar_t* szReserved,
    IN      LPWSTR  mszMachineList,
    IN      LPDWORD pcchBufferSize
);

PDH_FUNCTION
PdhEnumMachinesA (
    IN      const char*   szReserved,
    IN      LPSTR    mszMachineList,
    IN      LPDWORD  pcchBufferSize
);

PDH_FUNCTION
PdhEnumObjectsW (
    IN      const wchar_t* szReserved,
    IN      const wchar_t* szMachineName,
    IN      LPWSTR  mszObjectList,
    IN      LPDWORD pcchBufferSize,
    IN      unsigned long   dwDetailLevel,
    IN      BOOL    bRefresh
);

PDH_FUNCTION
PdhEnumObjectsA (
    IN      const char*  szReserved,
    IN      const char*  szMachineName,
    IN      LPSTR   mszObjectList,
    IN      LPDWORD pcchBufferSize,
    IN      unsigned long   dwDetailLevel,
    IN      BOOL    bRefresh
);

PDH_FUNCTION
PdhEnumObjectItemsW (
    IN      const wchar_t* szReserved,
    IN      const wchar_t* szMachineName,
    IN      const wchar_t* szObjectName,
    IN      LPWSTR  mszCounterList,
    IN      LPDWORD pcchCounterListLength,
    IN      LPWSTR  mszInstanceList,
    IN      LPDWORD pcchInstanceListLength,
    IN      unsigned long   dwDetailLevel,
    IN      unsigned long   dwFlags
);

PDH_FUNCTION
PdhEnumObjectItemsA (
    IN      const char*  szReserved,
    IN      const char*  szMachineName,
    IN      const char*  szObjectName,
    IN      LPSTR   mszCounterList,
    IN      LPDWORD pcchCounterListLength,
    IN      LPSTR   mszInstanceList,
    IN      LPDWORD pcchInstanceListLength,
    IN      unsigned long   dwDetailLevel,
    IN      unsigned long   dwFlags
);

PDH_FUNCTION
PdhMakeCounterPathW (
    IN      PDH_COUNTER_PATH_ELEMENTS_W *pCounterPathElements,
    IN      LPWSTR                      szFullPathBuffer,
    IN      LPDWORD                     pcchBufferSize,
    IN      unsigned long                       dwFlags
);

PDH_FUNCTION
PdhMakeCounterPathA (
    IN      PDH_COUNTER_PATH_ELEMENTS_A *pCounterPathElements,
    IN      LPSTR                       szFullPathBuffer,
    IN      LPDWORD                     pcchBufferSize,
    IN      unsigned long                       dwFlags
);

PDH_FUNCTION
PdhParseCounterPathW (
    IN      const wchar_t*                     szFullPathBuffer,
    IN      PDH_COUNTER_PATH_ELEMENTS_W *pCounterPathElements,
    IN      LPDWORD                     pdwBufferSize,
    IN      unsigned long                       dwFlags
);

PDH_FUNCTION
PdhParseCounterPathA (
    IN      const char*                      szFullPathBuffer,
    IN      PDH_COUNTER_PATH_ELEMENTS_A *pCounterPathElements,
    IN      LPDWORD                     pdwBufferSize,
    IN      unsigned long                       dwFlags
);

PDH_FUNCTION
PdhParseInstanceNameW (
    IN      const wchar_t* szInstanceString,
    IN      LPWSTR  szInstanceName,
    IN      LPDWORD pcchInstanceNameLength,
    IN      LPWSTR  szParentName,
    IN      LPDWORD pcchParentNameLength,
    IN      LPDWORD lpIndex
);

PDH_FUNCTION
PdhParseInstanceNameA (
    IN      const char*  szInstanceString,
    IN      LPSTR   szInstanceName,
    IN      LPDWORD pcchInstanceNameLength,
    IN      LPSTR   szParentName,
    IN      LPDWORD pcchParentNameLength,
    IN      LPDWORD lpIndex
);

PDH_FUNCTION
PdhValidatePathW (
    IN      const wchar_t* szFullPathBuffer
);

PDH_FUNCTION
PdhValidatePathA (
    IN      const char*  szFullPathBuffer
);

PDH_FUNCTION
PdhGetDefaultPerfObjectW (
    IN      const wchar_t* szReserved,
    IN      const wchar_t* szMachineName,
    IN      LPWSTR  szDefaultObjectName,
    IN      LPDWORD pcchBufferSize
);

PDH_FUNCTION
PdhGetDefaultPerfObjectA (
    IN      const char*  szReserved,
    IN      const char*  szMachineName,
    IN      LPSTR   szDefaultObjectName,
    IN      LPDWORD pcchBufferSize
);

PDH_FUNCTION
PdhGetDefaultPerfCounterW (
    IN      const wchar_t* szReserved,
    IN      const wchar_t* szMachineName,
    IN      const wchar_t* szObjectName,
    IN      LPWSTR  szDefaultCounterName,
    IN      LPDWORD pcchBufferSize
);

PDH_FUNCTION
PdhGetDefaultPerfCounterA (
    IN      const char*  szReserved,
    IN      const char*  szMachineName,
    IN      const char*  szObjectName,
    IN      LPSTR   szDefaultCounterName,
    IN      LPDWORD pcchBufferSize
);

typedef PDH_STATUS (__stdcall *CounterPathCallBack)(unsigned long);

typedef struct _BrowseDlgConfig_W {
    // Configuration flags
    unsigned long   bIncludeInstanceIndex:1,
            bSingleCounterPerAdd:1,
            bSingleCounterPerDialog:1,
            bLocalCountersOnly:1,
            bWildCardInstances:1,
            bHideDetailBox:1,
            bInitializePath:1,
            bDisableMachineSelection:1,
            bReserved:24;

    HWND                hWndOwner;
    LPWSTR              szReserved;
    LPWSTR              szReturnPathBuffer;
    unsigned long               cchReturnPathLength;
    CounterPathCallBack pCallBack;
    unsigned long               dwCallBackArg;
    PDH_STATUS          CallBackStatus;
    unsigned long               dwDefaultDetailLevel;
    LPWSTR              szDialogBoxCaption;
} PDH_BROWSE_DLG_CONFIG_W, *PPDH_BROWSE_DLG_CONFIG_W;

typedef struct _BrowseDlgConfig_A {
    // Configuration flags
    unsigned long   bIncludeInstanceIndex:1,
            bSingleCounterPerAdd:1,
            bSingleCounterPerDialog:1,
            bLocalCountersOnly:1,
            bWildCardInstances:1,
            bHideDetailBox:1,
            bInitializePath:1,
            bDisableMachineSelection:1,
            bReserved:24;

    HWND                hWndOwner;
    LPSTR               szReserved;
    LPSTR               szReturnPathBuffer;
    unsigned long               cchReturnPathLength;
    CounterPathCallBack pCallBack;
    unsigned long               dwCallBackArg;
    PDH_STATUS          CallBackStatus;
    unsigned long               dwDefaultDetailLevel;
    LPSTR               szDialogBoxCaption;
} PDH_BROWSE_DLG_CONFIG_A, *PPDH_BROWSE_DLG_CONFIG_A;

PDH_FUNCTION
PdhBrowseCountersW (
    IN      PPDH_BROWSE_DLG_CONFIG_W    pBrowseDlgData
);

PDH_FUNCTION
PdhBrowseCountersA (
    IN      PPDH_BROWSE_DLG_CONFIG_A    pBrowseDlgData
);

PDH_FUNCTION
PdhExpandCounterPathW (
    IN      const wchar_t*     szWildCardPath,
    IN      LPWSTR      mszExpandedPathList,
    IN      LPDWORD     pcchPathListLength
);

PDH_FUNCTION
PdhExpandCounterPathA (
    IN      const char*      szWildCardPath,
    IN      LPSTR       mszExpandedPathList,
    IN      LPDWORD     pcchPathListLength
);

//
//   Unicode/ANSI compatibility section
//
#ifdef UNICODE
#ifndef _UNICODE
#define _UNICODE
#endif
#endif

#ifdef _UNICODE
#ifndef UNICODE
#define UNICODE
#endif
#endif

#ifdef UNICODE
// start of UNICODE definitions
#define PdhAddCounter	            PdhAddCounterW
#define PdhGetCounterInfo           PdhGetCounterInfoW
#define PDH_COUNTER_INFO	        PDH_COUNTER_INFO_W
#define PPDH_COUNTER_INFO	        PPDH_COUNTER_INFO_W
#define PdhConnectMachine           PdhConnectMachineW
#define PdhEnumMachines             PdhEnumMachinesW
#define PdhEnumObjects              PdhEnumObjectsW
#define PdhEnumObjectItems          PdhEnumObjectItemsW
#define PdhMakeCounterPath          PdhMakeCounterPathW
#define PDH_COUNTER_PATH_ELEMENTS   PDH_COUNTER_PATH_ELEMENTS_W
#define PPDH_COUNTER_PATH_ELEMENTS  PPDH_COUNTER_PATH_ELEMENTS_W
#define PdhParseCounterPath         PdhParseCounterPathW
#define PdhParseInstanceName        PdhParseInstanceNameW
#define PdhValidatePath             PdhValidatePathW
#define PdhGetDefaultPerfObject     PdhGetDefaultPerfObjectW
#define PdhGetDefaultPerfCounter    PdhGetDefaultPerfCounterW
#define PdhBrowseCounters           PdhBrowseCountersW
#define PDH_BROWSE_DLG_CONFIG       PDH_BROWSE_DLG_CONFIG_W
#define PPDH_BROWSE_DLG_CONFIG      PPDH_BROWSE_DLG_CONFIG_W
#define PdhExpandCounterPath        PdhExpandCounterPathW
// end of UNICODE definitions
#else 
// start of ANSI definitions
#define PdhAddCounter	            PdhAddCounterA
#define PdhGetCounterInfo           PdhGetCounterInfoA
#define PDH_COUNTER_INFO    	    PDH_COUNTER_INFO_A
#define PPDH_COUNTER_INFO	        PPDH_COUNTER_INFO_A
#define PdhConnectMachine           PdhConnectMachineA
#define PdhEnumMachines             PdhEnumMachinesA
#define PdhEnumObjects              PdhEnumObjectsA
#define PdhEnumObjectItems          PdhEnumObjectItemsA
#define PdhMakeCounterPath          PdhMakeCounterPathA
#define PDH_COUNTER_PATH_ELEMENTS   PDH_COUNTER_PATH_ELEMENTS_A
#define PPDH_COUNTER_PATH_ELEMENTS  PPDH_COUNTER_PATH_ELEMENTS_A
#define PdhParseCounterPath         PdhParseCounterPathA
#define PdhParseInstanceName        PdhParseInstanceNameA
#define PdhValidatePath             PdhValidatePathA
#define PdhGetDefaultPerfObject     PdhGetDefaultPerfObjectA
#define PdhGetDefaultPerfCounter    PdhGetDefaultPerfCounterA
#define PdhBrowseCounters           PdhBrowseCountersA
#define PDH_BROWSE_DLG_CONFIG       PDH_BROWSE_DLG_CONFIG_A
#define PPDH_BROWSE_DLG_CONFIG      PPDH_BROWSE_DLG_CONFIG_A
#define PdhExpandCounterPath        PdhExpandCounterPathA
// end of ANSI definitions
#endif  // UNICODE

#ifdef __cplusplus
}
#endif

#endif //_PDH_H_
#pragma once 
