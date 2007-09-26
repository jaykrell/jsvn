/*****************************************************************************\
*                                                                             *
* tlhelp32.h -	WIN32 tool help functions, types, and definitions	      *
*                                                                             *
* Version 1.0								      *
*                                                                             *
* NOTE: windows.h/winbase.h must be #included first			      *
*                                                                             *
* Copyright (c) 1994-1995, Microsoft Corp.   All rights reserved. 	      *
*                                                                             *
\*****************************************************************************/

#ifndef _INC_TOOLHELP32
#define _INC_TOOLHELP32

#ifdef __cplusplus
extern "C" {            /* Assume C declarations for C++ */
#endif	/* __cplusplus */

#define MAX_MODULE_NAME32 255

/****** Shapshot function **********************************************/

HANDLE WINAPI CreateToolhelp32Snapshot(unsigned long dwFlags, unsigned long th32ProcessID);
//
// The th32ProcessID argument is only used if TH32CS_SNAPHEAPLIST or
// TH32CS_SNAPMODULE is specified. th32ProcessID == 0 means the current
// process.
//
// NOTE that all of the snapshots are global except for the heap and module
//	lists which are process specific. To enumerate the heap or module
//	state for all WIN32 processes call with TH32CS_SNAPALL and the
//	current process. Then for each process in the TH32CS_SNAPPROCESS
//	list that isn't the current process, do a call with just
//	TH32CS_SNAPHEAPLIST and/or TH32CS_SNAPMODULE.
//
// dwFlags
//
#define TH32CS_SNAPHEAPLIST 0x00000001
#define TH32CS_SNAPPROCESS  0x00000002
#define TH32CS_SNAPTHREAD   0x00000004
#define TH32CS_SNAPMODULE   0x00000008
#define TH32CS_SNAPALL	    (TH32CS_SNAPHEAPLIST | TH32CS_SNAPPROCESS | TH32CS_SNAPTHREAD | TH32CS_SNAPMODULE)
#define TH32CS_INHERIT	    0x80000000
//
// Use CloseHandle to destroy the snapshot
//

/****** heap walking ***************************************************/

typedef struct tagHEAPLIST32
{
    unsigned long  dwSize;
    unsigned long  th32ProcessID;   // owning process
    unsigned long  th32HeapID;	    // heap (in owning process's context!)
    unsigned long  dwFlags;
} HEAPLIST32;
typedef HEAPLIST32 *  PHEAPLIST32;
typedef HEAPLIST32 *  LPHEAPLIST32;
//
// dwFlags
//
#define HF32_DEFAULT	  1  // process's default heap
#define HF32_SHARED	  2  // is shared heap

BOOL WINAPI Heap32ListFirst(HANDLE hSnapshot, LPHEAPLIST32 lphl);
BOOL WINAPI Heap32ListNext(HANDLE hSnapshot, LPHEAPLIST32 lphl);

typedef struct tagHEAPENTRY32
{
    unsigned long  dwSize;
    HANDLE hHandle;	// Handle of this heap block
    unsigned long  dwAddress;	// Linear address of start of block
    unsigned long  dwBlockSize; // Size of block in bytes
    unsigned long  dwFlags;
    unsigned long  dwLockCount;
    unsigned long  dwResvd;
    unsigned long  th32ProcessID;   // owning process
    unsigned long  th32HeapID;	    // heap block is in
} HEAPENTRY32;
typedef HEAPENTRY32 *  PHEAPENTRY32;
typedef HEAPENTRY32 *  LPHEAPENTRY32;
//
// dwFlags
//
#define LF32_FIXED    0x00000001
#define LF32_FREE     0x00000002
#define LF32_MOVEABLE 0x00000004

BOOL WINAPI Heap32First(LPHEAPENTRY32 lphe, unsigned long th32ProcessID,
			unsigned long th32HeapID);
BOOL WINAPI Heap32Next(LPHEAPENTRY32 lphe);
BOOL WINAPI Toolhelp32ReadProcessMemory(unsigned long	th32ProcessID,
					LPCVOID lpBaseAddress,
					void*	lpBuffer,
					unsigned long	cbRead,
					LPDWORD lpNumberOfBytesRead);

/***** Process walking *************************************************/

typedef struct tagPROCESSENTRY32
{
    unsigned long   dwSize;
    unsigned long   cntUsage;
    unsigned long   th32ProcessID;	    // this process
    unsigned long   th32DefaultHeapID;
    unsigned long   th32ModuleID;	    // associated exe
    unsigned long   cntThreads;
    unsigned long   th32ParentProcessID;    // this process's parent process
    LONG    pcPriClassBase;	    // Base priority of process's threads
    unsigned long   dwFlags;
    char    szExeFile[MAX_PATH];    // Path
} PROCESSENTRY32;
typedef PROCESSENTRY32 *  PPROCESSENTRY32;
typedef PROCESSENTRY32 *  LPPROCESSENTRY32;

BOOL WINAPI Process32First(HANDLE hSnapshot, LPPROCESSENTRY32 lppe);
BOOL WINAPI Process32Next(HANDLE hSnapshot, LPPROCESSENTRY32 lppe);

/***** Thread walking **************************************************/

typedef struct tagTHREADENTRY32
{
    unsigned long   dwSize;
    unsigned long   cntUsage;
    unsigned long   th32ThreadID;	// this thread
    unsigned long   th32OwnerProcessID; // Process this thread is associated with
    LONG    tpBasePri;
    LONG    tpDeltaPri;
    unsigned long   dwFlags;
} THREADENTRY32;
typedef THREADENTRY32 *  PTHREADENTRY32;
typedef THREADENTRY32 *  LPTHREADENTRY32;

BOOL WINAPI Thread32First(HANDLE hSnapshot, LPTHREADENTRY32 lpte);
BOOL WINAPI Thread32Next(HANDLE hSnapshot, LPTHREADENTRY32 lpte);

/***** Module walking *************************************************/

typedef struct tagMODULEENTRY32
{
    unsigned long   dwSize;
    unsigned long   th32ModuleID;	// This module
    unsigned long   th32ProcessID;	// owning process
    unsigned long   GlblcntUsage;	// Global usage count on the module
    unsigned long   ProccntUsage;	// Module usage count in th32ProcessID's context
    BYTE  * modBaseAddr;	// Base address of module in th32ProcessID's context
    unsigned long   modBaseSize;	// Size in bytes of module starting at modBaseAddr
    HMODULE hModule;		// The hModule of this module in th32ProcessID's context
    char    szModule[MAX_MODULE_NAME32 + 1];
    char    szExePath[MAX_PATH];
} MODULEENTRY32;
typedef MODULEENTRY32 *  PMODULEENTRY32;
typedef MODULEENTRY32 *  LPMODULEENTRY32;

//
// NOTE CAREFULLY that the modBaseAddr and hModule fields are valid ONLY
// in th32ProcessID's process context.
//

BOOL WINAPI Module32First(HANDLE hSnapshot, LPMODULEENTRY32 lpme);
BOOL WINAPI Module32Next(HANDLE hSnapshot, LPMODULEENTRY32 lpme);

#ifdef __cplusplus
}
#endif

#endif // _INC_TOOLHELP32
#pragma once 
