#pragma once
/*++ BUILD Version: 0001    // Increment this if a change has global effects

Copyright (c) 1991-1996 Microsoft Corporation

Module Name:

    Winreg.h

Abstract:

    This module contains the function prototypes and constant, type and
    structure definitions for the Windows 32-Bit Registry API.

--*/

#ifndef _WINREG_
#define _WINREG_


#ifdef __cplusplus
extern "C" {
#endif

#ifndef WINVER
#define WINVER 0x0400   // version 4.0
#endif /* !WINVER */

//
// Requested Key access mask type.
//

typedef ACCESS_MASK REGSAM;

//
// Type definitions.
//

DECLARE_HANDLE(HKEY);
typedef HKEY *PHKEY;

//
// Reserved Key Handles.
//

#define HKEY_CLASSES_ROOT           (( HKEY ) 0x80000000 )
#define HKEY_CURRENT_USER           (( HKEY ) 0x80000001 )
#define HKEY_LOCAL_MACHINE          (( HKEY ) 0x80000002 )
#define HKEY_USERS                  (( HKEY ) 0x80000003 )
#define HKEY_PERFORMANCE_DATA       (( HKEY ) 0x80000004 )
#if(WINVER >= 0x0400)
#define HKEY_CURRENT_CONFIG         (( HKEY ) 0x80000005 )
#define HKEY_DYN_DATA               (( HKEY ) 0x80000006 )

/*NOINC*/
#ifndef _PROVIDER_STRUCTS_DEFINED
#define _PROVIDER_STRUCTS_DEFINED

#define PROVIDER_KEEPS_VALUE_LENGTH 0x1
struct val_context {
    int valuelen;       // the total length of this value
    void* value_context;   // provider's context
    void* val_buff_ptr;    // where in the ouput buffer the value is.
};

typedef struct val_context  *PVALCONTEXT;

typedef struct pvalueA {           // Provider supplied value/context.
    char*   pv_valuename;          // The value name pointer
    int pv_valuelen;
    void* pv_value_context;
    unsigned long pv_type;
}PVALUEA,  *PPVALUEA;
typedef struct pvalueW {           // Provider supplied value/context.
    wchar_t*  pv_valuename;          // The value name pointer
    int pv_valuelen;
    void* pv_value_context;
    unsigned long pv_type;
}PVALUEW,  *PPVALUEW;
#ifdef UNICODE
typedef PVALUEW PVALUE;
typedef PPVALUEW PPVALUE;
#else
typedef PVALUEA PVALUE;
typedef PPVALUEA PPVALUE;
#endif // UNICODE

typedef
unsigned long _cdecl
QUERYHANDLER (void* keycontext, PVALCONTEXT val_list, unsigned long num_vals,
          void* outputbuffer, unsigned long  *total_outlen, unsigned long input_blen);

typedef QUERYHANDLER  *PQUERYHANDLER;

typedef struct provider_info {
    PQUERYHANDLER pi_R0_1val;
    PQUERYHANDLER pi_R0_allvals;
    PQUERYHANDLER pi_R3_1val;
    PQUERYHANDLER pi_R3_allvals;
    unsigned long pi_flags;    // capability flags (none defined yet).
    void* pi_key_context;
}REG_PROVIDER;

typedef struct provider_info  *PPROVIDER;

typedef struct value_entA {
    char*   ve_valuename;
    unsigned long ve_valuelen;
    unsigned long ve_valueptr;
    unsigned long ve_type;
}VALENTA,  *PVALENTA;
typedef struct value_entW {
    wchar_t*  ve_valuename;
    unsigned long ve_valuelen;
    unsigned long ve_valueptr;
    unsigned long ve_type;
}VALENTW,  *PVALENTW;
#ifdef UNICODE
typedef VALENTW VALENT;
typedef PVALENTW PVALENT;
#else
typedef VALENTA VALENT;
typedef PVALENTA PVALENT;
#endif // UNICODE

#endif // not(_PROVIDER_STRUCTS_DEFINED)
/*INC*/

#endif /* WINVER >= 0x0400 */

//
// Default values for parameters that do not exist in the Win 3.1
// compatible APIs.
//

#define WIN31_CLASS                 NULL

//
// API Prototypes.
//


/*WINADVAPI*/
long
__stdcall
RegCloseKey (
    HKEY hKey
    );

/*WINADVAPI*/
long
__stdcall
RegConnectRegistryA (
    char* lpMachineName,
    HKEY hKey,
    HKEY* phkResult
    );
/*WINADVAPI*/
long
__stdcall
RegConnectRegistryW (
    wchar_t* lpMachineName,
    HKEY hKey,
    HKEY* phkResult
    );
#ifdef UNICODE
#define RegConnectRegistry  RegConnectRegistryW
#else
#define RegConnectRegistry  RegConnectRegistryA
#endif // !UNICODE

/*WINADVAPI*/
long
__stdcall
RegCreateKeyA (
    HKEY hKey,
    const char* lpSubKey,
    HKEY* phkResult
    );
/*WINADVAPI*/
long
__stdcall
RegCreateKeyW (
    HKEY hKey,
    const wchar_t* lpSubKey,
    HKEY* phkResult
    );
#ifdef UNICODE
#define RegCreateKey  RegCreateKeyW
#else
#define RegCreateKey  RegCreateKeyA
#endif // !UNICODE

/*WINADVAPI*/
long
__stdcall
RegCreateKeyExA (
    HKEY hKey,
    const char* lpSubKey,
    unsigned long Reserved,
    char* lpClass,
    unsigned long dwOptions,
    REGSAM samDesired,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    HKEY* phkResult,
    unsigned long* lpdwDisposition
    );
/*WINADVAPI*/
long
__stdcall
RegCreateKeyExW (
    HKEY hKey,
    const wchar_t* lpSubKey,
    unsigned long Reserved,
    wchar_t* lpClass,
    unsigned long dwOptions,
    REGSAM samDesired,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    HKEY* phkResult,
    unsigned long* lpdwDisposition
    );
#ifdef UNICODE
#define RegCreateKeyEx  RegCreateKeyExW
#else
#define RegCreateKeyEx  RegCreateKeyExA
#endif // !UNICODE

/*WINADVAPI*/
long
__stdcall
RegDeleteKeyA (
    HKEY hKey,
    const char* lpSubKey
    );
/*WINADVAPI*/
long
__stdcall
RegDeleteKeyW (
    HKEY hKey,
    const wchar_t* lpSubKey
    );
#ifdef UNICODE
#define RegDeleteKey  RegDeleteKeyW
#else
#define RegDeleteKey  RegDeleteKeyA
#endif // !UNICODE

/*WINADVAPI*/
long
__stdcall
RegDeleteValueA (
    HKEY hKey,
    const char* lpValueName
    );
/*WINADVAPI*/
long
__stdcall
RegDeleteValueW (
    HKEY hKey,
    const wchar_t* lpValueName
    );
#ifdef UNICODE
#define RegDeleteValue  RegDeleteValueW
#else
#define RegDeleteValue  RegDeleteValueA
#endif // !UNICODE

/*WINADVAPI*/
long
__stdcall
RegEnumKeyA (
    HKEY hKey,
    unsigned long dwIndex,
    char* lpName,
    unsigned long cbName
    );
/*WINADVAPI*/
long
__stdcall
RegEnumKeyW (
    HKEY hKey,
    unsigned long dwIndex,
    wchar_t* lpName,
    unsigned long cbName
    );
#ifdef UNICODE
#define RegEnumKey  RegEnumKeyW
#else
#define RegEnumKey  RegEnumKeyA
#endif // !UNICODE

/*WINADVAPI*/
long
__stdcall
RegEnumKeyExA (
    HKEY hKey,
    unsigned long dwIndex,
    char* lpName,
    unsigned long* lpcbName,
    unsigned long* lpReserved,
    char* lpClass,
    unsigned long* lpcbClass,
    PFILETIME lpftLastWriteTime
    );
/*WINADVAPI*/
long
__stdcall
RegEnumKeyExW (
    HKEY hKey,
    unsigned long dwIndex,
    wchar_t* lpName,
    unsigned long* lpcbName,
    unsigned long* lpReserved,
    wchar_t* lpClass,
    unsigned long* lpcbClass,
    PFILETIME lpftLastWriteTime
    );
#ifdef UNICODE
#define RegEnumKeyEx  RegEnumKeyExW
#else
#define RegEnumKeyEx  RegEnumKeyExA
#endif // !UNICODE

/*WINADVAPI*/
long
__stdcall
RegEnumValueA (
    HKEY hKey,
    unsigned long dwIndex,
    char* lpValueName,
    unsigned long* lpcbValueName,
    unsigned long* lpReserved,
    unsigned long* lpType,
    BYTE* lpData,
    unsigned long* lpcbData
    );
/*WINADVAPI*/
long
__stdcall
RegEnumValueW (
    HKEY hKey,
    unsigned long dwIndex,
    wchar_t* lpValueName,
    unsigned long* lpcbValueName,
    unsigned long* lpReserved,
    unsigned long* lpType,
    BYTE* lpData,
    unsigned long* lpcbData
    );
#ifdef UNICODE
#define RegEnumValue  RegEnumValueW
#else
#define RegEnumValue  RegEnumValueA
#endif // !UNICODE

/*WINADVAPI*/
long
__stdcall
RegFlushKey (
    HKEY hKey
    );

/*WINADVAPI*/
long
__stdcall
RegGetKeySecurity (
    HKEY hKey,
    SECURITY_INFORMATION SecurityInformation,
    PSECURITY_DESCRIPTOR pSecurityDescriptor,
    unsigned long* lpcbSecurityDescriptor
    );

/*WINADVAPI*/
long
__stdcall
RegLoadKeyA (
    HKEY    hKey,
    const char*  lpSubKey,
    const char*  lpFile
    );
/*WINADVAPI*/
long
__stdcall
RegLoadKeyW (
    HKEY    hKey,
    const wchar_t*  lpSubKey,
    const wchar_t*  lpFile
    );
#ifdef UNICODE
#define RegLoadKey  RegLoadKeyW
#else
#define RegLoadKey  RegLoadKeyA
#endif // !UNICODE

/*WINADVAPI*/
long
__stdcall
RegNotifyChangeKeyValue (
    HKEY hKey,
    BOOL bWatchSubtree,
    unsigned long dwNotifyFilter,
    HANDLE hEvent,
    BOOL fAsynchronus
    );

/*WINADVAPI*/
long
__stdcall
RegOpenKeyA (
    HKEY hKey,
    const char* lpSubKey,
    HKEY* phkResult
    );
/*WINADVAPI*/
long
__stdcall
RegOpenKeyW (
    HKEY hKey,
    const wchar_t* lpSubKey,
    HKEY* phkResult
    );
#ifdef UNICODE
#define RegOpenKey  RegOpenKeyW
#else
#define RegOpenKey  RegOpenKeyA
#endif // !UNICODE

/*WINADVAPI*/
long
__stdcall
RegOpenKeyExA (
    HKEY hKey,
    const char* lpSubKey,
    unsigned long ulOptions,
    REGSAM samDesired,
    HKEY* phkResult
    );
/*WINADVAPI*/
long
__stdcall
RegOpenKeyExW (
    HKEY hKey,
    const wchar_t* lpSubKey,
    unsigned long ulOptions,
    REGSAM samDesired,
    HKEY* phkResult
    );
#ifdef UNICODE
#define RegOpenKeyEx  RegOpenKeyExW
#else
#define RegOpenKeyEx  RegOpenKeyExA
#endif // !UNICODE

/*WINADVAPI*/
long
__stdcall
RegQueryInfoKeyA (
    HKEY hKey,
    char* lpClass,
    unsigned long* lpcbClass,
    unsigned long* lpReserved,
    unsigned long* lpcSubKeys,
    unsigned long* lpcbMaxSubKeyLen,
    unsigned long* lpcbMaxClassLen,
    unsigned long* lpcValues,
    unsigned long* lpcbMaxValueNameLen,
    unsigned long* lpcbMaxValueLen,
    unsigned long* lpcbSecurityDescriptor,
    PFILETIME lpftLastWriteTime
    );
/*WINADVAPI*/
long
__stdcall
RegQueryInfoKeyW (
    HKEY hKey,
    wchar_t* lpClass,
    unsigned long* lpcbClass,
    unsigned long* lpReserved,
    unsigned long* lpcSubKeys,
    unsigned long* lpcbMaxSubKeyLen,
    unsigned long* lpcbMaxClassLen,
    unsigned long* lpcValues,
    unsigned long* lpcbMaxValueNameLen,
    unsigned long* lpcbMaxValueLen,
    unsigned long* lpcbSecurityDescriptor,
    PFILETIME lpftLastWriteTime
    );
#ifdef UNICODE
#define RegQueryInfoKey  RegQueryInfoKeyW
#else
#define RegQueryInfoKey  RegQueryInfoKeyA
#endif // !UNICODE

/*WINADVAPI*/
long
__stdcall
RegQueryValueA (
    HKEY hKey,
    const char* lpSubKey,
    char* lpValue,
    long*   lpcbValue
    );
/*WINADVAPI*/
long
__stdcall
RegQueryValueW (
    HKEY hKey,
    const wchar_t* lpSubKey,
    wchar_t* lpValue,
    long*   lpcbValue
    );
#ifdef UNICODE
#define RegQueryValue  RegQueryValueW
#else
#define RegQueryValue  RegQueryValueA
#endif // !UNICODE

#if(WINVER >= 0x0400)
/*WINADVAPI*/
long
__stdcall
RegQueryMultipleValuesA (
    HKEY hKey,
    PVALENTA val_list,
    unsigned long num_vals,
    char* lpValueBuf,
    unsigned long* ldwTotsize
    );
/*WINADVAPI*/
long
__stdcall
RegQueryMultipleValuesW (
    HKEY hKey,
    PVALENTW val_list,
    unsigned long num_vals,
    wchar_t* lpValueBuf,
    unsigned long* ldwTotsize
    );
#ifdef UNICODE
#define RegQueryMultipleValues  RegQueryMultipleValuesW
#else
#define RegQueryMultipleValues  RegQueryMultipleValuesA
#endif // !UNICODE
#endif /* WINVER >= 0x0400 */

/*WINADVAPI*/
long
__stdcall
RegQueryValueExA (
    HKEY hKey,
    const char* lpValueName,
    unsigned long* lpReserved,
    unsigned long* lpType,
    BYTE* lpData,
    unsigned long* lpcbData
    );
/*WINADVAPI*/
long
__stdcall
RegQueryValueExW (
    HKEY hKey,
    const wchar_t* lpValueName,
    unsigned long* lpReserved,
    unsigned long* lpType,
    BYTE* lpData,
    unsigned long* lpcbData
    );
#ifdef UNICODE
#define RegQueryValueEx  RegQueryValueExW
#else
#define RegQueryValueEx  RegQueryValueExA
#endif // !UNICODE

/*WINADVAPI*/
long
__stdcall
RegReplaceKeyA (
    HKEY     hKey,
    const char*  lpSubKey,
    const char*  lpNewFile,
    const char*  lpOldFile
    );
/*WINADVAPI*/
long
__stdcall
RegReplaceKeyW (
    HKEY     hKey,
    const wchar_t*  lpSubKey,
    const wchar_t*  lpNewFile,
    const wchar_t*  lpOldFile
    );
#ifdef UNICODE
#define RegReplaceKey  RegReplaceKeyW
#else
#define RegReplaceKey  RegReplaceKeyA
#endif // !UNICODE

/*WINADVAPI*/
long
__stdcall
RegRestoreKeyA (
    HKEY hKey,
    const char* lpFile,
    unsigned long   dwFlags
    );
/*WINADVAPI*/
long
__stdcall
RegRestoreKeyW (
    HKEY hKey,
    const wchar_t* lpFile,
    unsigned long   dwFlags
    );
#ifdef UNICODE
#define RegRestoreKey  RegRestoreKeyW
#else
#define RegRestoreKey  RegRestoreKeyA
#endif // !UNICODE

/*WINADVAPI*/
long
__stdcall
RegSaveKeyA (
    HKEY hKey,
    const char* lpFile,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
/*WINADVAPI*/
long
__stdcall
RegSaveKeyW (
    HKEY hKey,
    const wchar_t* lpFile,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes
    );
#ifdef UNICODE
#define RegSaveKey  RegSaveKeyW
#else
#define RegSaveKey  RegSaveKeyA
#endif // !UNICODE

/*WINADVAPI*/
long
__stdcall
RegSetKeySecurity (
    HKEY hKey,
    SECURITY_INFORMATION SecurityInformation,
    PSECURITY_DESCRIPTOR pSecurityDescriptor
    );

/*WINADVAPI*/
long
__stdcall
RegSetValueA (
    HKEY hKey,
    const char* lpSubKey,
    unsigned long dwType,
    const char* lpData,
    unsigned long cbData
    );
/*WINADVAPI*/
long
__stdcall
RegSetValueW (
    HKEY hKey,
    const wchar_t* lpSubKey,
    unsigned long dwType,
    const wchar_t* lpData,
    unsigned long cbData
    );
#ifdef UNICODE
#define RegSetValue  RegSetValueW
#else
#define RegSetValue  RegSetValueA
#endif // !UNICODE


/*WINADVAPI*/
long
__stdcall
RegSetValueExA (
    HKEY hKey,
    const char* lpValueName,
    unsigned long Reserved,
    unsigned long dwType,
    const BYTE* lpData,
    unsigned long cbData
    );
/*WINADVAPI*/
long
__stdcall
RegSetValueExW (
    HKEY hKey,
    const wchar_t* lpValueName,
    unsigned long Reserved,
    unsigned long dwType,
    const BYTE* lpData,
    unsigned long cbData
    );
#ifdef UNICODE
#define RegSetValueEx  RegSetValueExW
#else
#define RegSetValueEx  RegSetValueExA
#endif // !UNICODE

/*WINADVAPI*/
long
__stdcall
RegUnLoadKeyA (
    HKEY    hKey,
    const char* lpSubKey
    );
/*WINADVAPI*/
long
__stdcall
RegUnLoadKeyW (
    HKEY    hKey,
    const wchar_t* lpSubKey
    );
#ifdef UNICODE
#define RegUnLoadKey  RegUnLoadKeyW
#else
#define RegUnLoadKey  RegUnLoadKeyA
#endif // !UNICODE

//
// Remoteable System Shutdown APIs
//

/*WINADVAPI*/
BOOL
__stdcall
InitiateSystemShutdownA(
    char* lpMachineName,
    char* lpMessage,
    unsigned long dwTimeout,
    BOOL bForceAppsClosed,
    BOOL bRebootAfterShutdown
    );
/*WINADVAPI*/
BOOL
__stdcall
InitiateSystemShutdownW(
    wchar_t* lpMachineName,
    wchar_t* lpMessage,
    unsigned long dwTimeout,
    BOOL bForceAppsClosed,
    BOOL bRebootAfterShutdown
    );
#ifdef UNICODE
#define InitiateSystemShutdown  InitiateSystemShutdownW
#else
#define InitiateSystemShutdown  InitiateSystemShutdownA
#endif // !UNICODE


/*WINADVAPI*/
BOOL
__stdcall
AbortSystemShutdownA(
    char* lpMachineName
    );
/*WINADVAPI*/
BOOL
__stdcall
AbortSystemShutdownW(
    wchar_t* lpMachineName
    );
#ifdef UNICODE
#define AbortSystemShutdown  AbortSystemShutdownW
#else
#define AbortSystemShutdown  AbortSystemShutdownA
#endif // !UNICODE

#ifdef __cplusplus
}
#endif


#endif // _WINREG_
#pragma once 
