/*++ BUILD Version: 0010    // Increment this if a change has global effects

Copyright (c) 1995-1996  Microsoft Corporation

Module Name:

    winsvc.h

Abstract:

    Header file for the Service Control Manager

Environment:

    User Mode - Win32

--*/
#ifndef _WINSVC_
#define _WINSVC_

//
// Define API decoration for direct importing of DLL references.
//

#if !defined(WINADVAPI)
#if !defined(_ADVAPI32_)
#define WINADVAPI DECLSPEC_IMPORT
#else
#define WINADVAPI
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

//
// Constants
//

//
// Service database names
//

#define SERVICES_ACTIVE_DATABASEW      L"ServicesActive"
#define SERVICES_FAILED_DATABASEW      L"ServicesFailed"

#define SERVICES_ACTIVE_DATABASEA      "ServicesActive"
#define SERVICES_FAILED_DATABASEA      "ServicesFailed"

//
// Character to designate that a name is a group
//

#define SC_GROUP_IDENTIFIERW           L'+'
#define SC_GROUP_IDENTIFIERA           '+'

#ifdef UNICODE

#define SERVICES_ACTIVE_DATABASE       SERVICES_ACTIVE_DATABASEW
#define SERVICES_FAILED_DATABASE       SERVICES_FAILED_DATABASEW


#define SC_GROUP_IDENTIFIER            SC_GROUP_IDENTIFIERW

#else // ndef UNICODE

#define SERVICES_ACTIVE_DATABASE       SERVICES_ACTIVE_DATABASEA
#define SERVICES_FAILED_DATABASE       SERVICES_FAILED_DATABASEA

#define SC_GROUP_IDENTIFIER            SC_GROUP_IDENTIFIERA
#endif // ndef UNICODE


//
// Value to indicate no change to an optional parameter
//
#define SERVICE_NO_CHANGE              0xffffffff

//
// Service State -- for Enum Requests (Bit Mask)
//
#define SERVICE_ACTIVE                 0x00000001
#define SERVICE_INACTIVE               0x00000002
#define SERVICE_STATE_ALL              (SERVICE_ACTIVE   | \
                                        SERVICE_INACTIVE)

//
// Controls
//
#define SERVICE_CONTROL_STOP           0x00000001
#define SERVICE_CONTROL_PAUSE          0x00000002
#define SERVICE_CONTROL_CONTINUE       0x00000003
#define SERVICE_CONTROL_INTERROGATE    0x00000004
#define SERVICE_CONTROL_SHUTDOWN       0x00000005

//
// Service State -- for CurrentState
//
#define SERVICE_STOPPED                0x00000001
#define SERVICE_START_PENDING          0x00000002
#define SERVICE_STOP_PENDING           0x00000003
#define SERVICE_RUNNING                0x00000004
#define SERVICE_CONTINUE_PENDING       0x00000005
#define SERVICE_PAUSE_PENDING          0x00000006
#define SERVICE_PAUSED                 0x00000007

//
// Controls Accepted  (Bit Mask)
//
#define SERVICE_ACCEPT_STOP            0x00000001
#define SERVICE_ACCEPT_PAUSE_CONTINUE  0x00000002
#define SERVICE_ACCEPT_SHUTDOWN        0x00000004

//
// Service Control Manager object specific access types
//
#define SC_MANAGER_CONNECT             0x0001
#define SC_MANAGER_CREATE_SERVICE      0x0002
#define SC_MANAGER_ENUMERATE_SERVICE   0x0004
#define SC_MANAGER_LOCK                0x0008
#define SC_MANAGER_QUERY_LOCK_STATUS   0x0010
#define SC_MANAGER_MODIFY_BOOT_CONFIG  0x0020

#define SC_MANAGER_ALL_ACCESS          (STANDARD_RIGHTS_REQUIRED      | \
                                        SC_MANAGER_CONNECT            | \
                                        SC_MANAGER_CREATE_SERVICE     | \
                                        SC_MANAGER_ENUMERATE_SERVICE  | \
                                        SC_MANAGER_LOCK               | \
                                        SC_MANAGER_QUERY_LOCK_STATUS  | \
                                        SC_MANAGER_MODIFY_BOOT_CONFIG)



//
// Service object specific access type
//
#define SERVICE_QUERY_CONFIG           0x0001
#define SERVICE_CHANGE_CONFIG          0x0002
#define SERVICE_QUERY_STATUS           0x0004
#define SERVICE_ENUMERATE_DEPENDENTS   0x0008
#define SERVICE_START                  0x0010
#define SERVICE_STOP                   0x0020
#define SERVICE_PAUSE_CONTINUE         0x0040
#define SERVICE_INTERROGATE            0x0080
#define SERVICE_USER_DEFINED_CONTROL   0x0100

#define SERVICE_ALL_ACCESS             (STANDARD_RIGHTS_REQUIRED     | \
                                        SERVICE_QUERY_CONFIG         | \
                                        SERVICE_CHANGE_CONFIG        | \
                                        SERVICE_QUERY_STATUS         | \
                                        SERVICE_ENUMERATE_DEPENDENTS | \
                                        SERVICE_START                | \
                                        SERVICE_STOP                 | \
                                        SERVICE_PAUSE_CONTINUE       | \
                                        SERVICE_INTERROGATE          | \
                                        SERVICE_USER_DEFINED_CONTROL)


//
// Handle Types
//

typedef HANDLE      SC_HANDLE;
typedef SC_HANDLE   *LPSC_HANDLE;

typedef unsigned long       SERVICE_STATUS_HANDLE;

//
// Service Status Structure
//

typedef struct _SERVICE_STATUS {
    unsigned long   dwServiceType;
    unsigned long   dwCurrentState;
    unsigned long   dwControlsAccepted;
    unsigned long   dwWin32ExitCode;
    unsigned long   dwServiceSpecificExitCode;
    unsigned long   dwCheckPoint;
    unsigned long   dwWaitHint;
} SERVICE_STATUS, *LPSERVICE_STATUS;



//
// Service Status Enumeration Structure
//

typedef struct _ENUM_SERVICE_STATUSA {
    LPSTR          lpServiceName;
    LPSTR          lpDisplayName;
    SERVICE_STATUS ServiceStatus;
} ENUM_SERVICE_STATUSA, *LPENUM_SERVICE_STATUSA;
typedef struct _ENUM_SERVICE_STATUSW {
    LPWSTR         lpServiceName;
    LPWSTR         lpDisplayName;
    SERVICE_STATUS ServiceStatus;
} ENUM_SERVICE_STATUSW, *LPENUM_SERVICE_STATUSW;
#ifdef UNICODE
typedef ENUM_SERVICE_STATUSW ENUM_SERVICE_STATUS;
typedef LPENUM_SERVICE_STATUSW LPENUM_SERVICE_STATUS;
#else
typedef ENUM_SERVICE_STATUSA ENUM_SERVICE_STATUS;
typedef LPENUM_SERVICE_STATUSA LPENUM_SERVICE_STATUS;
#endif // UNICODE


//
// Structures for the Lock API functions
//

typedef void*  SC_LOCK;

typedef struct _QUERY_SERVICE_LOCK_STATUSA {
    unsigned long   fIsLocked;
    LPSTR   lpLockOwner;
    unsigned long   dwLockDuration;
} QUERY_SERVICE_LOCK_STATUSA, *LPQUERY_SERVICE_LOCK_STATUSA;
typedef struct _QUERY_SERVICE_LOCK_STATUSW {
    unsigned long   fIsLocked;
    LPWSTR  lpLockOwner;
    unsigned long   dwLockDuration;
} QUERY_SERVICE_LOCK_STATUSW, *LPQUERY_SERVICE_LOCK_STATUSW;
#ifdef UNICODE
typedef QUERY_SERVICE_LOCK_STATUSW QUERY_SERVICE_LOCK_STATUS;
typedef LPQUERY_SERVICE_LOCK_STATUSW LPQUERY_SERVICE_LOCK_STATUS;
#else
typedef QUERY_SERVICE_LOCK_STATUSA QUERY_SERVICE_LOCK_STATUS;
typedef LPQUERY_SERVICE_LOCK_STATUSA LPQUERY_SERVICE_LOCK_STATUS;
#endif // UNICODE



//
// Query Service Configuration Structure
//

typedef struct _QUERY_SERVICE_CONFIGA {
    unsigned long   dwServiceType;
    unsigned long   dwStartType;
    unsigned long   dwErrorControl;
    LPSTR   lpBinaryPathName;
    LPSTR   lpLoadOrderGroup;
    unsigned long   dwTagId;
    LPSTR   lpDependencies;
    LPSTR   lpServiceStartName;
    LPSTR   lpDisplayName;
} QUERY_SERVICE_CONFIGA, *LPQUERY_SERVICE_CONFIGA;
typedef struct _QUERY_SERVICE_CONFIGW {
    unsigned long   dwServiceType;
    unsigned long   dwStartType;
    unsigned long   dwErrorControl;
    LPWSTR  lpBinaryPathName;
    LPWSTR  lpLoadOrderGroup;
    unsigned long   dwTagId;
    LPWSTR  lpDependencies;
    LPWSTR  lpServiceStartName;
    LPWSTR  lpDisplayName;
} QUERY_SERVICE_CONFIGW, *LPQUERY_SERVICE_CONFIGW;
#ifdef UNICODE
typedef QUERY_SERVICE_CONFIGW QUERY_SERVICE_CONFIG;
typedef LPQUERY_SERVICE_CONFIGW LPQUERY_SERVICE_CONFIG;
#else
typedef QUERY_SERVICE_CONFIGA QUERY_SERVICE_CONFIG;
typedef LPQUERY_SERVICE_CONFIGA LPQUERY_SERVICE_CONFIG;
#endif // UNICODE



//
// Function Prototype for the Service Main Function
//

typedef VOID (WINAPI *LPSERVICE_MAIN_FUNCTIONW)(
    unsigned long   dwNumServicesArgs,
    LPWSTR  *lpServiceArgVectors
    );

typedef VOID (WINAPI *LPSERVICE_MAIN_FUNCTIONA)(
    unsigned long   dwNumServicesArgs,
    LPSTR   *lpServiceArgVectors
    );

#ifdef UNICODE
#define LPSERVICE_MAIN_FUNCTION LPSERVICE_MAIN_FUNCTIONW
#else
#define LPSERVICE_MAIN_FUNCTION LPSERVICE_MAIN_FUNCTIONA
#endif //UNICODE


//
// Service Start Table
//

typedef struct _SERVICE_TABLE_ENTRYA {
    LPSTR                       lpServiceName;
    LPSERVICE_MAIN_FUNCTIONA    lpServiceProc;
}SERVICE_TABLE_ENTRYA, *LPSERVICE_TABLE_ENTRYA;
typedef struct _SERVICE_TABLE_ENTRYW {
    LPWSTR                      lpServiceName;
    LPSERVICE_MAIN_FUNCTIONW    lpServiceProc;
}SERVICE_TABLE_ENTRYW, *LPSERVICE_TABLE_ENTRYW;
#ifdef UNICODE
typedef SERVICE_TABLE_ENTRYW SERVICE_TABLE_ENTRY;
typedef LPSERVICE_TABLE_ENTRYW LPSERVICE_TABLE_ENTRY;
#else
typedef SERVICE_TABLE_ENTRYA SERVICE_TABLE_ENTRY;
typedef LPSERVICE_TABLE_ENTRYA LPSERVICE_TABLE_ENTRY;
#endif // UNICODE

//
// Prototype for the Service Control Handler Function
//

typedef VOID (WINAPI *LPHANDLER_FUNCTION)(
    unsigned long    dwControl
    );



///////////////////////////////////////////////////////////////////////////
// API Function Prototypes
///////////////////////////////////////////////////////////////////////////

WINADVAPI
BOOL
WINAPI
ChangeServiceConfigA(
    SC_HANDLE    hService,
    unsigned long        dwServiceType,
    unsigned long        dwStartType,
    unsigned long        dwErrorControl,
    const char*     lpBinaryPathName,
    const char*     lpLoadOrderGroup,
    LPDWORD      lpdwTagId,
    const char*     lpDependencies,
    const char*     lpServiceStartName,
    const char*     lpPassword,
    const char*     lpDisplayName
    );
WINADVAPI
BOOL
WINAPI
ChangeServiceConfigW(
    SC_HANDLE    hService,
    unsigned long        dwServiceType,
    unsigned long        dwStartType,
    unsigned long        dwErrorControl,
    const wchar_t*     lpBinaryPathName,
    const wchar_t*     lpLoadOrderGroup,
    LPDWORD      lpdwTagId,
    const wchar_t*     lpDependencies,
    const wchar_t*     lpServiceStartName,
    const wchar_t*     lpPassword,
    const wchar_t*     lpDisplayName
    );
#ifdef UNICODE
#define ChangeServiceConfig  ChangeServiceConfigW
#else
#define ChangeServiceConfig  ChangeServiceConfigA
#endif // !UNICODE

WINADVAPI
BOOL
WINAPI
CloseServiceHandle(
    SC_HANDLE   hSCObject
    );

WINADVAPI
BOOL
WINAPI
ControlService(
    SC_HANDLE           hService,
    unsigned long               dwControl,
    LPSERVICE_STATUS    lpServiceStatus
    );

WINADVAPI
SC_HANDLE
WINAPI
CreateServiceA(
    SC_HANDLE    hSCManager,
    const char*     lpServiceName,
    const char*     lpDisplayName,
    unsigned long        dwDesiredAccess,
    unsigned long        dwServiceType,
    unsigned long        dwStartType,
    unsigned long        dwErrorControl,
    const char*     lpBinaryPathName,
    const char*     lpLoadOrderGroup,
    LPDWORD      lpdwTagId,
    const char*     lpDependencies,
    const char*     lpServiceStartName,
    const char*     lpPassword
    );
WINADVAPI
SC_HANDLE
WINAPI
CreateServiceW(
    SC_HANDLE    hSCManager,
    const wchar_t*     lpServiceName,
    const wchar_t*     lpDisplayName,
    unsigned long        dwDesiredAccess,
    unsigned long        dwServiceType,
    unsigned long        dwStartType,
    unsigned long        dwErrorControl,
    const wchar_t*     lpBinaryPathName,
    const wchar_t*     lpLoadOrderGroup,
    LPDWORD      lpdwTagId,
    const wchar_t*     lpDependencies,
    const wchar_t*     lpServiceStartName,
    const wchar_t*     lpPassword
    );
#ifdef UNICODE
#define CreateService  CreateServiceW
#else
#define CreateService  CreateServiceA
#endif // !UNICODE

WINADVAPI
BOOL
WINAPI
DeleteService(
    SC_HANDLE   hService
    );

WINADVAPI
BOOL
WINAPI
EnumDependentServicesA(
    SC_HANDLE               hService,
    unsigned long                   dwServiceState,
    LPENUM_SERVICE_STATUSA  lpServices,
    unsigned long                   cbBufSize,
    LPDWORD                 pcbBytesNeeded,
    LPDWORD                 lpServicesReturned
    );
WINADVAPI
BOOL
WINAPI
EnumDependentServicesW(
    SC_HANDLE               hService,
    unsigned long                   dwServiceState,
    LPENUM_SERVICE_STATUSW  lpServices,
    unsigned long                   cbBufSize,
    LPDWORD                 pcbBytesNeeded,
    LPDWORD                 lpServicesReturned
    );
#ifdef UNICODE
#define EnumDependentServices  EnumDependentServicesW
#else
#define EnumDependentServices  EnumDependentServicesA
#endif // !UNICODE

WINADVAPI
BOOL
WINAPI
EnumServicesStatusA(
    SC_HANDLE               hSCManager,
    unsigned long                   dwServiceType,
    unsigned long                   dwServiceState,
    LPENUM_SERVICE_STATUSA  lpServices,
    unsigned long                   cbBufSize,
    LPDWORD                 pcbBytesNeeded,
    LPDWORD                 lpServicesReturned,
    LPDWORD                 lpResumeHandle
    );
WINADVAPI
BOOL
WINAPI
EnumServicesStatusW(
    SC_HANDLE               hSCManager,
    unsigned long                   dwServiceType,
    unsigned long                   dwServiceState,
    LPENUM_SERVICE_STATUSW  lpServices,
    unsigned long                   cbBufSize,
    LPDWORD                 pcbBytesNeeded,
    LPDWORD                 lpServicesReturned,
    LPDWORD                 lpResumeHandle
    );
#ifdef UNICODE
#define EnumServicesStatus  EnumServicesStatusW
#else
#define EnumServicesStatus  EnumServicesStatusA
#endif // !UNICODE

WINADVAPI
BOOL
WINAPI
GetServiceKeyNameA(
    SC_HANDLE               hSCManager,
    const char*                lpDisplayName,
    LPSTR                 lpServiceName,
    LPDWORD                 lpcchBuffer
    );
WINADVAPI
BOOL
WINAPI
GetServiceKeyNameW(
    SC_HANDLE               hSCManager,
    const wchar_t*                lpDisplayName,
    LPWSTR                 lpServiceName,
    LPDWORD                 lpcchBuffer
    );
#ifdef UNICODE
#define GetServiceKeyName  GetServiceKeyNameW
#else
#define GetServiceKeyName  GetServiceKeyNameA
#endif // !UNICODE

WINADVAPI
BOOL
WINAPI
GetServiceDisplayNameA(
    SC_HANDLE               hSCManager,
    const char*                lpServiceName,
    LPSTR                 lpDisplayName,
    LPDWORD                 lpcchBuffer
    );
WINADVAPI
BOOL
WINAPI
GetServiceDisplayNameW(
    SC_HANDLE               hSCManager,
    const wchar_t*                lpServiceName,
    LPWSTR                 lpDisplayName,
    LPDWORD                 lpcchBuffer
    );
#ifdef UNICODE
#define GetServiceDisplayName  GetServiceDisplayNameW
#else
#define GetServiceDisplayName  GetServiceDisplayNameA
#endif // !UNICODE

WINADVAPI
SC_LOCK
WINAPI
LockServiceDatabase(
    SC_HANDLE   hSCManager
    );

WINADVAPI
BOOL
WINAPI
NotifyBootConfigStatus(
    BOOL     BootAcceptable
    );

WINADVAPI
SC_HANDLE
WINAPI
OpenSCManagerA(
    const char* lpMachineName,
    const char* lpDatabaseName,
    unsigned long   dwDesiredAccess
    );
WINADVAPI
SC_HANDLE
WINAPI
OpenSCManagerW(
    const wchar_t* lpMachineName,
    const wchar_t* lpDatabaseName,
    unsigned long   dwDesiredAccess
    );
#ifdef UNICODE
#define OpenSCManager  OpenSCManagerW
#else
#define OpenSCManager  OpenSCManagerA
#endif // !UNICODE

WINADVAPI
SC_HANDLE
WINAPI
OpenServiceA(
    SC_HANDLE   hSCManager,
    const char*    lpServiceName,
    unsigned long       dwDesiredAccess
    );
WINADVAPI
SC_HANDLE
WINAPI
OpenServiceW(
    SC_HANDLE   hSCManager,
    const wchar_t*    lpServiceName,
    unsigned long       dwDesiredAccess
    );
#ifdef UNICODE
#define OpenService  OpenServiceW
#else
#define OpenService  OpenServiceA
#endif // !UNICODE

WINADVAPI
BOOL
WINAPI
QueryServiceConfigA(
    SC_HANDLE               hService,
    LPQUERY_SERVICE_CONFIGA lpServiceConfig,
    unsigned long                   cbBufSize,
    LPDWORD                 pcbBytesNeeded
    );
WINADVAPI
BOOL
WINAPI
QueryServiceConfigW(
    SC_HANDLE               hService,
    LPQUERY_SERVICE_CONFIGW lpServiceConfig,
    unsigned long                   cbBufSize,
    LPDWORD                 pcbBytesNeeded
    );
#ifdef UNICODE
#define QueryServiceConfig  QueryServiceConfigW
#else
#define QueryServiceConfig  QueryServiceConfigA
#endif // !UNICODE

WINADVAPI
BOOL
WINAPI
QueryServiceLockStatusA(
    SC_HANDLE                       hSCManager,
    LPQUERY_SERVICE_LOCK_STATUSA    lpLockStatus,
    unsigned long                           cbBufSize,
    LPDWORD                         pcbBytesNeeded
    );
WINADVAPI
BOOL
WINAPI
QueryServiceLockStatusW(
    SC_HANDLE                       hSCManager,
    LPQUERY_SERVICE_LOCK_STATUSW    lpLockStatus,
    unsigned long                           cbBufSize,
    LPDWORD                         pcbBytesNeeded
    );
#ifdef UNICODE
#define QueryServiceLockStatus  QueryServiceLockStatusW
#else
#define QueryServiceLockStatus  QueryServiceLockStatusA
#endif // !UNICODE

WINADVAPI
BOOL
WINAPI
QueryServiceObjectSecurity(
    SC_HANDLE               hService,
    SECURITY_INFORMATION    dwSecurityInformation,
    PSECURITY_DESCRIPTOR    lpSecurityDescriptor,
    unsigned long                   cbBufSize,
    LPDWORD                 pcbBytesNeeded
    );

WINADVAPI
BOOL
WINAPI
QueryServiceStatus(
    SC_HANDLE           hService,
    LPSERVICE_STATUS    lpServiceStatus
    );

WINADVAPI
SERVICE_STATUS_HANDLE
WINAPI
RegisterServiceCtrlHandlerA(
    const char*             lpServiceName,
    LPHANDLER_FUNCTION   lpHandlerProc
    );
WINADVAPI
SERVICE_STATUS_HANDLE
WINAPI
RegisterServiceCtrlHandlerW(
    const wchar_t*             lpServiceName,
    LPHANDLER_FUNCTION   lpHandlerProc
    );
#ifdef UNICODE
#define RegisterServiceCtrlHandler  RegisterServiceCtrlHandlerW
#else
#define RegisterServiceCtrlHandler  RegisterServiceCtrlHandlerA
#endif // !UNICODE

WINADVAPI
BOOL
WINAPI
SetServiceObjectSecurity(
    SC_HANDLE               hService,
    SECURITY_INFORMATION    dwSecurityInformation,
    PSECURITY_DESCRIPTOR    lpSecurityDescriptor
    );

WINADVAPI
BOOL
WINAPI
SetServiceStatus(
    SERVICE_STATUS_HANDLE   hServiceStatus,
    LPSERVICE_STATUS        lpServiceStatus
    );

WINADVAPI
BOOL
WINAPI
StartServiceCtrlDispatcherA(
    LPSERVICE_TABLE_ENTRYA    lpServiceStartTable
    );
WINADVAPI
BOOL
WINAPI
StartServiceCtrlDispatcherW(
    LPSERVICE_TABLE_ENTRYW    lpServiceStartTable
    );
#ifdef UNICODE
#define StartServiceCtrlDispatcher  StartServiceCtrlDispatcherW
#else
#define StartServiceCtrlDispatcher  StartServiceCtrlDispatcherA
#endif // !UNICODE


WINADVAPI
BOOL
WINAPI
StartServiceA(
    SC_HANDLE            hService,
    unsigned long                dwNumServiceArgs,
    const char*             *lpServiceArgVectors
    );
WINADVAPI
BOOL
WINAPI
StartServiceW(
    SC_HANDLE            hService,
    unsigned long                dwNumServiceArgs,
    const wchar_t*             *lpServiceArgVectors
    );
#ifdef UNICODE
#define StartService  StartServiceW
#else
#define StartService  StartServiceA
#endif // !UNICODE

WINADVAPI
BOOL
WINAPI
UnlockServiceDatabase(
    SC_LOCK     ScLock
    );


#ifdef __cplusplus
}
#endif

#endif // _WINSVC_
#pragma once 
