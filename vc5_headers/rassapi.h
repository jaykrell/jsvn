/******************************************************************\
*                     Microsoft Windows NT                         *
*               Copyright(c) Microsoft Corp., 1992-1996            *
\******************************************************************/

/*++

Module Name:

    RASSAPI.H

Description:

    This file contains the RASADMIN structures, defines and
    function prototypes for the following APIs and they can
    be imported from RASSAPI.DLL:

     RasAdminServerGetInfo
     RasAdminGetUserAccountServer
     RasAdminUserSetInfo
     RasAdminUserGetInfo
     RasAdminPortEnum
     RasAdminPortGetInfo
     RasAdminPortClearStatistics
     RasAdminPortDisconnect
     RasAdminFreeBuffer

Note:

    This header file and the sources containing the APIs will work
    only with UNICODE strings.

--*/


#ifndef _RASSAPI_H_
#define _RASSAPI_H_

#ifndef UNLEN
#include <lmcons.h>
#endif

#define RASSAPI_MAX_PHONENUMBER_SIZE     128
#define RASSAPI_MAX_MEDIA_NAME	         16
#define RASSAPI_MAX_PORT_NAME	            16
#define RASSAPI_MAX_DEVICE_NAME          128
#define RASSAPI_MAX_DEVICETYPE_NAME       16
#define RASSAPI_MAX_PARAM_KEY_SIZE        32

// Bits indicating user's Remote Access privileges and mask to isolate
// call back privilege.
//
// Note: Bit 0 MUST represent NoCallback due to a quirk of the "userparms"
//       storage method.  When a new LAN Manager user is created, bit 0 of the
//       userparms field is set to 1 and all other bits are 0.  These bits are
//       arranged so this "no Dial-In info" state maps to the "default Dial-In
//       privilege" state.

#define RASPRIV_NoCallback        0x01
#define RASPRIV_AdminSetCallback  0x02
#define RASPRIV_CallerSetCallback 0x04
#define RASPRIV_DialinPrivilege   0x08

#define RASPRIV_CallbackType (RASPRIV_AdminSetCallback \
                              | RASPRIV_CallerSetCallback \
                              | RASPRIV_NoCallback)

//
// Modem condition codes
//
#define	RAS_MODEM_OPERATIONAL	     1	// No modem errors.
#define	RAS_MODEM_NOT_RESPONDING     2
#define	RAS_MODEM_HARDWARE_FAILURE   3
#define	RAS_MODEM_INCORRECT_RESPONSE 4
#define	RAS_MODEM_UNKNOWN 	        5
//
// Line condition codes
//
#define	RAS_PORT_NON_OPERATIONAL 1
#define	RAS_PORT_DISCONNECTED	 2
#define	RAS_PORT_CALLING_BACK    3
#define	RAS_PORT_LISTENING	    4
#define	RAS_PORT_AUTHENTICATING  5
#define	RAS_PORT_AUTHENTICATED	 6
#define	RAS_PORT_INITIALIZING	 7

// The following three structures are same as the ones
// defined in rasman.h and have been renamed to prevent
// redefinitions when both header files are included.

enum RAS_PARAMS_FORMAT {

	ParamNumber	    = 0,

	ParamString	    = 1

} ;
typedef enum RAS_PARAMS_FORMAT	RAS_PARAMS_FORMAT ;

union RAS_PARAMS_VALUE {

	unsigned long	Number ;

	struct	{
		unsigned long	Length ;
		PCHAR	Data ;
		} String ;
} ;
typedef union RAS_PARAMS_VALUE	RAS_PARAMS_VALUE ;

struct RAS_PARAMETERS {

    CHAR	P_Key	[RASSAPI_MAX_PARAM_KEY_SIZE] ;

    RAS_PARAMS_FORMAT	P_Type ;

    BYTE	P_Attributes ;

    RAS_PARAMS_VALUE	P_Value ;

} ;
typedef struct RAS_PARAMETERS	RAS_PARAMETERS ;

// structures used by the RASADMIN APIs

typedef struct _RAS_USER_0
{
    BYTE bfPrivilege;
    WCHAR szPhoneNumber[ RASSAPI_MAX_PHONENUMBER_SIZE + 1];
} RAS_USER_0, *PRAS_USER_0;

typedef struct _RAS_PORT_0
{
    WCHAR wszPortName[RASSAPI_MAX_PORT_NAME];
    WCHAR wszDeviceType[RASSAPI_MAX_DEVICETYPE_NAME];
    WCHAR wszDeviceName[RASSAPI_MAX_DEVICE_NAME];
    WCHAR wszMediaName[RASSAPI_MAX_MEDIA_NAME];
    unsigned long reserved;
    unsigned long Flags;
    WCHAR wszUserName[UNLEN + 1];
    WCHAR wszComputer[NETBIOS_NAME_LEN];
    unsigned long dwStartSessionTime;          // seconds from 1/1/1970
    WCHAR wszLogonDomain[DNLEN + 1];
    BOOL fAdvancedServer;
} RAS_PORT_0, *PRAS_PORT_0;


// Possible values for MediaId

#define MEDIA_UNKNOWN       0
#define MEDIA_SERIAL        1
#define MEDIA_RAS10_SERIAL  2
#define MEDIA_X25           3
#define MEDIA_ISDN          4


// Possible bits set in Flags field

#define USER_AUTHENTICATED    0x0001
#define MESSENGER_PRESENT     0x0002
#define PPP_CLIENT            0x0004
#define GATEWAY_ACTIVE        0x0008
#define REMOTE_LISTEN         0x0010
#define PORT_MULTILINKED      0x0020


typedef unsigned long IPADDR;

// The following PPP structures are same as the ones
// defined in rasppp.h and have been renamed to prevent
// redefinitions when both header files are included
// in a module.

/* Maximum length of address string, e.g. "255.255.255.255" for IP.
*/
#define RAS_IPADDRESSLEN  15
#define RAS_IPXADDRESSLEN 22
#define RAS_ATADDRESSLEN  32

typedef struct _RAS_PPP_NBFCP_RESULT
{
    unsigned long dwError;
    unsigned long dwNetBiosError;
    CHAR  szName[ NETBIOS_NAME_LEN + 1 ];
    WCHAR wszWksta[ NETBIOS_NAME_LEN + 1 ];
} RAS_PPP_NBFCP_RESULT;

typedef struct _RAS_PPP_IPCP_RESULT
{
    unsigned long dwError;
    WCHAR wszAddress[ RAS_IPADDRESSLEN + 1 ];
} RAS_PPP_IPCP_RESULT;

typedef struct _RAS_PPP_IPXCP_RESULT
{
    unsigned long dwError;
    WCHAR wszAddress[ RAS_IPXADDRESSLEN + 1 ];
} RAS_PPP_IPXCP_RESULT;

typedef struct _RAS_PPP_ATCP_RESULT
{
    unsigned long dwError;
    WCHAR wszAddress[ RAS_ATADDRESSLEN + 1 ];
} RAS_PPP_ATCP_RESULT;

typedef struct _RAS_PPP_PROJECTION_RESULT
{
    RAS_PPP_NBFCP_RESULT nbf;
    RAS_PPP_IPCP_RESULT  ip;
    RAS_PPP_IPXCP_RESULT ipx;
    RAS_PPP_ATCP_RESULT  at;
} RAS_PPP_PROJECTION_RESULT;

typedef struct _RAS_PORT_1
{
    RAS_PORT_0                 rasport0;
    unsigned long                      LineCondition;
    unsigned long                      HardwareCondition;
    unsigned long                      LineSpeed;        // in bits/second
    WORD                       NumStatistics;
    WORD                       NumMediaParms;
    unsigned long                      SizeMediaParms;
    RAS_PPP_PROJECTION_RESULT  ProjResult;
} RAS_PORT_1, *PRAS_PORT_1;

typedef struct _RAS_PORT_STATISTICS
{
    // The connection statistics are followed by port statistics
    // A connection is across multiple ports.
    unsigned long   dwBytesXmited;
    unsigned long   dwBytesRcved;
    unsigned long   dwFramesXmited;
    unsigned long   dwFramesRcved;
    unsigned long   dwCrcErr;
    unsigned long   dwTimeoutErr;
    unsigned long   dwAlignmentErr;
    unsigned long   dwHardwareOverrunErr;
    unsigned long   dwFramingErr;
    unsigned long   dwBufferOverrunErr;
    unsigned long   dwBytesXmitedUncompressed;
    unsigned long   dwBytesRcvedUncompressed;
    unsigned long   dwBytesXmitedCompressed;
    unsigned long   dwBytesRcvedCompressed;

    // the following are the port statistics
    unsigned long   dwPortBytesXmited;
    unsigned long   dwPortBytesRcved;
    unsigned long   dwPortFramesXmited;
    unsigned long   dwPortFramesRcved;
    unsigned long   dwPortCrcErr;
    unsigned long   dwPortTimeoutErr;
    unsigned long   dwPortAlignmentErr;
    unsigned long   dwPortHardwareOverrunErr;
    unsigned long   dwPortFramingErr;
    unsigned long   dwPortBufferOverrunErr;
    unsigned long   dwPortBytesXmitedUncompressed;
    unsigned long   dwPortBytesRcvedUncompressed;
    unsigned long   dwPortBytesXmitedCompressed;
    unsigned long   dwPortBytesRcvedCompressed;

} RAS_PORT_STATISTICS, *PRAS_PORT_STATISTICS;

//
// Server version numbers
//
#define RASDOWNLEVEL       10    // identifies a LM RAS 1.0 server
#define RASADMIN_35        35    // Identifies a NT RAS 3.5 server or client
#define RASADMIN_CURRENT   40    // Identifies a NT RAS 4.0 server or client


typedef struct _RAS_SERVER_0
{
    WORD TotalPorts;             // Total ports configured on the server
    WORD PortsInUse;             // Ports currently in use by remote clients
    unsigned long RasVersion;            // version of RAS server
} RAS_SERVER_0, *PRAS_SERVER_0;


//
// function prototypes
//

unsigned long __stdcall RasAdminServerGetInfo(
    IN const WCHAR *  lpszServer,
    OUT PRAS_SERVER_0 pRasServer0
    );

unsigned long __stdcall RasAdminGetUserAccountServer(
    IN const WCHAR * lpszDomain,
    IN const WCHAR * lpszServer,
    OUT LPWSTR       lpszUserAccountServer
    );

unsigned long __stdcall RasAdminUserGetInfo(
    IN const WCHAR   * lpszUserAccountServer,
    IN const WCHAR   * lpszUser,
    OUT PRAS_USER_0    pRasUser0
    );

unsigned long __stdcall RasAdminUserSetInfo(
    IN const WCHAR       * lpszUserAccountServer,
    IN const WCHAR       * lpszUser,
    IN const PRAS_USER_0   pRasUser0
    );

unsigned long __stdcall RasAdminPortEnum(
    IN  const WCHAR * lpszServer,
    OUT PRAS_PORT_0 * ppRasPort0,
    OUT WORD *        pcEntriesRead
    );

unsigned long __stdcall RasAdminPortGetInfo(
    IN const WCHAR *            lpszServer,
    IN const WCHAR *            lpszPort,
    OUT RAS_PORT_1 *            pRasPort1,
    OUT RAS_PORT_STATISTICS *   pRasStats,
    OUT RAS_PARAMETERS **       ppRasParams
    );

unsigned long __stdcall RasAdminPortClearStatistics(
    IN const WCHAR * lpszServer,
    IN const WCHAR * lpszPort
    );

unsigned long __stdcall RasAdminPortDisconnect(
    IN const WCHAR * lpszServer,
    IN const WCHAR * lpszPort
    );

unsigned long __stdcall RasAdminFreeBuffer(
    void* Pointer
    );

unsigned long __stdcall RasAdminGetErrorString(
    IN  UINT    ResourceId,
    OUT WCHAR * lpszString,
    IN  unsigned long   InBufSize );

BOOL __stdcall RasAdminAcceptNewConnection (
	IN 		RAS_PORT_1 *		      pRasPort1,
    IN      RAS_PORT_STATISTICS *   pRasStats,
    IN      RAS_PARAMETERS *        pRasParams
	);

VOID __stdcall RasAdminConnectionHangupNotification (
	IN 		RAS_PORT_1 *		      pRasPort1,
    IN      RAS_PORT_STATISTICS *   pRasStats,
    IN      RAS_PARAMETERS *        pRasParams
	);

unsigned long __stdcall RasAdminGetIpAddressForUser (
	IN 		WCHAR  *		lpszUserName,
	IN 		WCHAR  *		lpszPortName,
	IN OUT 	IPADDR *	   pipAddress,
	OUT		BOOL	 *    bNotifyRelease
	);

VOID __stdcall RasAdminReleaseIpAddress (
	IN 		WCHAR  *		lpszUserName,
	IN 		WCHAR  *		lpszPortName,
	IN 		IPADDR *	   pipAddress
	);

// The following two APIs are used to get/set
// RAS user permissions in to a UsrParms buffer
// obtained by a call to NetUserGetInfo.
//
// Note that RasAdminUserGetInfo and RasAdminUserSetInfo
// are the APIs you should be using for getting and
// setting RAS permissions.

unsigned long __stdcall RasAdminGetUserParms(
    IN  WCHAR          * lpszParms,
    OUT PRAS_USER_0      pRasUser0
    );

unsigned long __stdcall RasAdminSetUserParms(
    IN OUT   WCHAR    * lpszParms,
    IN unsigned long          cchNewParms,
    IN PRAS_USER_0    pRasUser0
    );

#endif // _RASSAPI_H_

#pragma once 
