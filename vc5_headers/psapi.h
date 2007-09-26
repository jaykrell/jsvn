/*++ BUILD Version: 0001    // Increment this if a change has global effects

Copyright (c) 1994-1999  Microsoft Corporation

Module Name:

    psapi.h

Abstract:

    Include file for APIs provided by PSAPI.DLL

Author:

    Richard Shupak   [richards]  06-Jan-1994

Revision History:

--*/

#ifndef _PSAPI_H_
#define _PSAPI_H_

#if _MSC_VER > 1000
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

BOOL
WINAPI
EnumProcesses(
    unsigned long * lpidProcess,
    unsigned long   cb,
    unsigned long * cbNeeded
    );

BOOL
WINAPI
EnumProcessModules(
    HANDLE hProcess,
    HMODULE *lphModule,
    unsigned long cb,
    LPDWORD lpcbNeeded
    );

unsigned long
WINAPI
GetModuleBaseNameA(
    HANDLE hProcess,
    HMODULE hModule,
    LPSTR lpBaseName,
    unsigned long nSize
    );

unsigned long
WINAPI
GetModuleBaseNameW(
    HANDLE hProcess,
    HMODULE hModule,
    LPWSTR lpBaseName,
    unsigned long nSize
    );

#ifdef UNICODE
#define GetModuleBaseName  GetModuleBaseNameW
#else
#define GetModuleBaseName  GetModuleBaseNameA
#endif // !UNICODE


unsigned long
WINAPI
GetModuleFileNameExA(
    HANDLE hProcess,
    HMODULE hModule,
    LPSTR lpFilename,
    unsigned long nSize
    );

unsigned long
WINAPI
GetModuleFileNameExW(
    HANDLE hProcess,
    HMODULE hModule,
    LPWSTR lpFilename,
    unsigned long nSize
    );

#ifdef UNICODE
#define GetModuleFileNameEx  GetModuleFileNameExW
#else
#define GetModuleFileNameEx  GetModuleFileNameExA
#endif // !UNICODE


typedef struct _MODULEINFO {
    void* lpBaseOfDll;
    unsigned long SizeOfImage;
    void* EntryPoint;
} MODULEINFO, *LPMODULEINFO;


BOOL
WINAPI
GetModuleInformation(
    HANDLE hProcess,
    HMODULE hModule,
    LPMODULEINFO lpmodinfo,
    unsigned long cb
    );


BOOL
WINAPI
EmptyWorkingSet(
    HANDLE hProcess
    );


BOOL
WINAPI
QueryWorkingSet(
    HANDLE hProcess,
    void* pv,
    unsigned long cb
    );

BOOL
WINAPI
InitializeProcessForWsWatch(
    HANDLE hProcess
    );


typedef struct _PSAPI_WS_WATCH_INFORMATION {
    void* FaultingPc;
    void* FaultingVa;
} PSAPI_WS_WATCH_INFORMATION, *PPSAPI_WS_WATCH_INFORMATION;

BOOL
WINAPI
GetWsChanges(
    HANDLE hProcess,
    PPSAPI_WS_WATCH_INFORMATION lpWatchInfo,
    unsigned long cb
    );

unsigned long
WINAPI
GetMappedFileNameW(
    HANDLE hProcess,
    void* lpv,
    LPWSTR lpFilename,
    unsigned long nSize
    );

unsigned long
WINAPI
GetMappedFileNameA(
    HANDLE hProcess,
    void* lpv,
    LPSTR lpFilename,
    unsigned long nSize
    );

#ifdef UNICODE
#define GetMappedFileName  GetMappedFileNameW
#else
#define GetMappedFileName  GetMappedFileNameA
#endif // !UNICODE

BOOL
WINAPI
EnumDeviceDrivers(
    void* *lpImageBase,
    unsigned long cb,
    LPDWORD lpcbNeeded
    );


unsigned long
WINAPI
GetDeviceDriverBaseNameA(
    void* ImageBase,
    LPSTR lpBaseName,
    unsigned long nSize
    );

unsigned long
WINAPI
GetDeviceDriverBaseNameW(
    void* ImageBase,
    LPWSTR lpBaseName,
    unsigned long nSize
    );

#ifdef UNICODE
#define GetDeviceDriverBaseName  GetDeviceDriverBaseNameW
#else
#define GetDeviceDriverBaseName  GetDeviceDriverBaseNameA
#endif // !UNICODE


unsigned long
WINAPI
GetDeviceDriverFileNameA(
    void* ImageBase,
    LPSTR lpFilename,
    unsigned long nSize
    );

unsigned long
WINAPI
GetDeviceDriverFileNameW(
    void* ImageBase,
    LPWSTR lpFilename,
    unsigned long nSize
    );

#ifdef UNICODE
#define GetDeviceDriverFileName  GetDeviceDriverFileNameW
#else
#define GetDeviceDriverFileName  GetDeviceDriverFileNameA
#endif // !UNICODE

// Structure for GetProcessMemoryInfo()

typedef struct _PROCESS_MEMORY_COUNTERS {
    unsigned long cb;
    unsigned long PageFaultCount;
    SIZE_T PeakWorkingSetSize;
    SIZE_T WorkingSetSize;
    SIZE_T QuotaPeakPagedPoolUsage;
    SIZE_T QuotaPagedPoolUsage;
    SIZE_T QuotaPeakNonPagedPoolUsage;
    SIZE_T QuotaNonPagedPoolUsage;
    SIZE_T PagefileUsage;
    SIZE_T PeakPagefileUsage;
} PROCESS_MEMORY_COUNTERS;
typedef PROCESS_MEMORY_COUNTERS *PPROCESS_MEMORY_COUNTERS;

BOOL
WINAPI
GetProcessMemoryInfo(
    HANDLE Process,
    PPROCESS_MEMORY_COUNTERS ppsmemCounters,
    unsigned long cb
    );

#ifdef __cplusplus
}
#endif

#endif
#pragma once 
