/* Copyright (c) 1992-1996, Microsoft Corporation, all rights reserved
**
** ras.h
** Remote Access external API
** Public header for external API clients
**
** WINVER values in this file:
**      WINVER < 0x400 = Windows NT 3.5, Windows NT 3.51
**      WINVER = 0x400 = Windows 95, Windows NT SUR (default)
**      WINVER > 0x400 = Windows NT SUR enhancements
*/

#ifndef _RAS_H_
#define _RAS_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef UNLEN
#include <lmcons.h>
#endif

#include <pshpack4.h>

#define RAS_MaxDeviceType     16
#define RAS_MaxPhoneNumber    128
#define RAS_MaxIpAddress      15
#define RAS_MaxIpxAddress     21

#if (WINVER >= 0x400)
#define RAS_MaxEntryName      256
#define RAS_MaxDeviceName     128
#define RAS_MaxCallbackNumber RAS_MaxPhoneNumber
#else
#define RAS_MaxEntryName      20
#define RAS_MaxDeviceName     32
#define RAS_MaxCallbackNumber 48
#endif

#define RAS_MaxAreaCode       10
#define RAS_MaxPadType        32
#define RAS_MaxX25Address     200
#define RAS_MaxFacilities     200
#define RAS_MaxUserData       200

DECLARE_HANDLE( HRASCONN );
#define LPHRASCONN HRASCONN*


/* Identifies an active RAS connection.  (See RasEnumConnections)
*/
#define RASCONNW struct tagRASCONNW
RASCONNW
{
    unsigned long    dwSize;
    HRASCONN hrasconn;
    WCHAR    szEntryName[ RAS_MaxEntryName + 1 ];

#if (WINVER >= 0x400)
    WCHAR    szDeviceType[ RAS_MaxDeviceType + 1 ];
    WCHAR    szDeviceName[ RAS_MaxDeviceName + 1 ];
#endif
#if (WINVER >= 0x401)
    WCHAR    szPhonebook [ MAX_PATH ];
    unsigned long    dwSubEntry;
#endif
};

#define RASCONNA struct tagRASCONNA
RASCONNA
{
    unsigned long    dwSize;
    HRASCONN hrasconn;
    CHAR     szEntryName[ RAS_MaxEntryName + 1 ];

#if (WINVER >= 0x400)
    CHAR     szDeviceType[ RAS_MaxDeviceType + 1 ];
    CHAR     szDeviceName[ RAS_MaxDeviceName + 1 ];
#endif
#if (WINVER >= 0x401)
    CHAR     szPhonebook [ MAX_PATH ];
    unsigned long    dwSubEntry;
#endif
};

#ifdef UNICODE
#define RASCONN RASCONNW
#else
#define RASCONN RASCONNA
#endif

#define LPRASCONNW RASCONNW*
#define LPRASCONNA RASCONNA*
#define LPRASCONN  RASCONN*


/* Enumerates intermediate states to a connection.  (See RasDial)
*/
#define RASCS_PAUSED 0x1000
#define RASCS_DONE   0x2000

#define RASCONNSTATE enum tagRASCONNSTATE
RASCONNSTATE
{
    RASCS_OpenPort = 0,
    RASCS_PortOpened,
    RASCS_ConnectDevice,
    RASCS_DeviceConnected,
    RASCS_AllDevicesConnected,
    RASCS_Authenticate,
    RASCS_AuthNotify,
    RASCS_AuthRetry,
    RASCS_AuthCallback,
    RASCS_AuthChangePassword,
    RASCS_AuthProject,
    RASCS_AuthLinkSpeed,
    RASCS_AuthAck,
    RASCS_ReAuthenticate,
    RASCS_Authenticated,
    RASCS_PrepareForCallback,
    RASCS_WaitForModemReset,
    RASCS_WaitForCallback,
    RASCS_Projected,

#if (WINVER >= 0x400)
    RASCS_StartAuthentication,
    RASCS_CallbackComplete,
    RASCS_LogonNetwork,
#endif
    RASCS_SubEntryConnected,
    RASCS_SubEntryDisconnected,

    RASCS_Interactive = RASCS_PAUSED,
    RASCS_RetryAuthentication,
    RASCS_CallbackSetByCaller,
    RASCS_PasswordExpired,

    RASCS_Connected = RASCS_DONE,
    RASCS_Disconnected
};

#define LPRASCONNSTATE RASCONNSTATE*


/* Describes the status of a RAS connection.  (See RasConnectionStatus)
*/
#define RASCONNSTATUSW struct tagRASCONNSTATUSW
RASCONNSTATUSW
{
    unsigned long        dwSize;
    RASCONNSTATE rasconnstate;
    unsigned long        dwError;
    WCHAR        szDeviceType[ RAS_MaxDeviceType + 1 ];
    WCHAR        szDeviceName[ RAS_MaxDeviceName + 1 ];
#if (WINVER >= 0x401)
    WCHAR        szPhoneNumber[ RAS_MaxPhoneNumber + 1 ];
#endif
};

#define RASCONNSTATUSA struct tagRASCONNSTATUSA
RASCONNSTATUSA
{
    unsigned long        dwSize;
    RASCONNSTATE rasconnstate;
    unsigned long        dwError;
    CHAR         szDeviceType[ RAS_MaxDeviceType + 1 ];
    CHAR         szDeviceName[ RAS_MaxDeviceName + 1 ];
#if (WINVER >= 0x401)
    CHAR         szPhoneNumber[ RAS_MaxPhoneNumber + 1 ];
#endif
};

#ifdef UNICODE
#define RASCONNSTATUS RASCONNSTATUSW
#else
#define RASCONNSTATUS RASCONNSTATUSA
#endif

#define LPRASCONNSTATUSW RASCONNSTATUSW*
#define LPRASCONNSTATUSA RASCONNSTATUSA*
#define LPRASCONNSTATUS  RASCONNSTATUS*


/* Describes connection establishment parameters.  (See RasDial)
*/
#define RASDIALPARAMSW struct tagRASDIALPARAMSW
RASDIALPARAMSW
{
    unsigned long dwSize;
    WCHAR szEntryName[ RAS_MaxEntryName + 1 ];
    WCHAR szPhoneNumber[ RAS_MaxPhoneNumber + 1 ];
    WCHAR szCallbackNumber[ RAS_MaxCallbackNumber + 1 ];
    WCHAR szUserName[ UNLEN + 1 ];
    WCHAR szPassword[ PWLEN + 1 ];
    WCHAR szDomain[ DNLEN + 1 ];
#if (WINVER >= 0x401)
    unsigned long dwSubEntry;
    unsigned long dwCallbackId;
#endif
};

#define RASDIALPARAMSA struct tagRASDIALPARAMSA
RASDIALPARAMSA
{
    unsigned long dwSize;
    CHAR  szEntryName[ RAS_MaxEntryName + 1 ];
    CHAR  szPhoneNumber[ RAS_MaxPhoneNumber + 1 ];
    CHAR  szCallbackNumber[ RAS_MaxCallbackNumber + 1 ];
    CHAR  szUserName[ UNLEN + 1 ];
    CHAR  szPassword[ PWLEN + 1 ];
    CHAR  szDomain[ DNLEN + 1 ];
#if (WINVER >= 0x401)
    unsigned long dwSubEntry;
    unsigned long dwCallbackId;
#endif
};

#ifdef UNICODE
#define RASDIALPARAMS RASDIALPARAMSW
#else
#define RASDIALPARAMS RASDIALPARAMSA
#endif

#define LPRASDIALPARAMSW RASDIALPARAMSW*
#define LPRASDIALPARAMSA RASDIALPARAMSA*
#define LPRASDIALPARAMS  RASDIALPARAMS*


/* Describes extended connection establishment options.  (See RasDial)
*/
#define RASDIALEXTENSIONS struct tagRASDIALEXTENSIONS
RASDIALEXTENSIONS
{
    unsigned long dwSize;
    unsigned long dwfOptions;
    HWND  hwndParent;
    unsigned long reserved;
};

#define LPRASDIALEXTENSIONS RASDIALEXTENSIONS*

/* 'dwfOptions' bit flags.
*/
#define RDEOPT_UsePrefixSuffix           0x00000001
#define RDEOPT_PausedStates              0x00000002
#define RDEOPT_IgnoreModemSpeaker        0x00000004
#define RDEOPT_SetModemSpeaker           0x00000008
#define RDEOPT_IgnoreSoftwareCompression 0x00000010
#define RDEOPT_SetSoftwareCompression    0x00000020
#define RDEOPT_DisableConnectedUI        0x00000040
#define RDEOPT_DisableReconnectUI        0x00000080
#define RDEOPT_DisableReconnect          0x00000100
#define RDEOPT_NoUser                    0x00000200
#define RDEOPT_PauseOnScript             0x00000400


/* Describes an enumerated RAS phone book entry name.  (See RasEntryEnum)
*/
#define RASENTRYNAMEW struct tagRASENTRYNAMEW
RASENTRYNAMEW
{
    unsigned long dwSize;
    WCHAR szEntryName[ RAS_MaxEntryName + 1 ];
};

#define RASENTRYNAMEA struct tagRASENTRYNAMEA
RASENTRYNAMEA
{
    unsigned long dwSize;
    CHAR  szEntryName[ RAS_MaxEntryName + 1 ];
};

#ifdef UNICODE
#define RASENTRYNAME RASENTRYNAMEW
#else
#define RASENTRYNAME RASENTRYNAMEA
#endif

#define LPRASENTRYNAMEW RASENTRYNAMEW*
#define LPRASENTRYNAMEA RASENTRYNAMEA*
#define LPRASENTRYNAME  RASENTRYNAME*


/* Protocol code to projection data structure mapping.
*/
#define RASPROJECTION enum tagRASPROJECTION
RASPROJECTION
{
    RASP_Amb = 0x10000,
    RASP_PppNbf = 0x803F,
    RASP_PppIpx = 0x802B,
    RASP_PppIp = 0x8021,
    RASP_PppLcp = 0xC021,
    RASP_Slip = 0x20000
};

#define LPRASPROJECTION RASPROJECTION*


/* Describes the result of a RAS AMB (Authentication Message Block)
** projection.  This protocol is used with NT 3.1 and OS/2 1.3 downlevel
** RAS servers.
*/
#define RASAMBW struct tagRASAMBW
RASAMBW
{
    unsigned long dwSize;
    unsigned long dwError;
    WCHAR szNetBiosError[ NETBIOS_NAME_LEN + 1 ];
    BYTE  bLana;
};

#define RASAMBA struct tagRASAMBA
RASAMBA
{
    unsigned long dwSize;
    unsigned long dwError;
    CHAR  szNetBiosError[ NETBIOS_NAME_LEN + 1 ];
    BYTE  bLana;
};

#ifdef UNICODE
#define RASAMB RASAMBW
#else
#define RASAMB RASAMBA
#endif

#define LPRASAMBW RASAMBW*
#define LPRASAMBA RASAMBA*
#define LPRASAMB  RASAMB*


/* Describes the result of a PPP NBF (NetBEUI) projection.
*/
#define RASPPPNBFW struct tagRASPPPNBFW
RASPPPNBFW
{
    unsigned long dwSize;
    unsigned long dwError;
    unsigned long dwNetBiosError;
    WCHAR szNetBiosError[ NETBIOS_NAME_LEN + 1 ];
    WCHAR szWorkstationName[ NETBIOS_NAME_LEN + 1 ];
    BYTE  bLana;
};

#define RASPPPNBFA struct tagRASPPPNBFA
RASPPPNBFA
{
    unsigned long dwSize;
    unsigned long dwError;
    unsigned long dwNetBiosError;
    CHAR  szNetBiosError[ NETBIOS_NAME_LEN + 1 ];
    CHAR  szWorkstationName[ NETBIOS_NAME_LEN + 1 ];
    BYTE  bLana;
};

#ifdef UNICODE
#define RASPPPNBF RASPPPNBFW
#else
#define RASPPPNBF RASPPPNBFA
#endif

#define LPRASPPPNBFW RASPPPNBFW*
#define LPRASPPPNBFA RASPPPNBFA*
#define LPRASPPPNBF  RASPPPNBF*


/* Describes the results of a PPP IPX (Internetwork Packet Exchange)
** projection.
*/
#define RASPPPIPXW struct tagRASIPXW
RASPPPIPXW
{
    unsigned long dwSize;
    unsigned long dwError;
    WCHAR szIpxAddress[ RAS_MaxIpxAddress + 1 ];
};


#define RASPPPIPXA struct tagRASPPPIPXA
RASPPPIPXA
{
    unsigned long dwSize;
    unsigned long dwError;
    CHAR  szIpxAddress[ RAS_MaxIpxAddress + 1 ];
};

#ifdef UNICODE
#define RASPPPIPX RASPPPIPXW
#else
#define RASPPPIPX RASPPPIPXA
#endif

#define LPRASPPPIPXW RASPPPIPXW*
#define LPRASPPPIPXA RASPPPIPXA*
#define LPRASPPPIPX  RASPPPIPX*


/* Describes the results of a PPP IP (Internet) projection.
*/
#define RASPPPIPW struct tagRASPPPIPW
RASPPPIPW
{
    unsigned long dwSize;
    unsigned long dwError;
    WCHAR szIpAddress[ RAS_MaxIpAddress + 1 ];

#ifndef WINNT35COMPATIBLE

    /* This field was added between Windows NT 3.51 beta and Windows NT 3.51
    ** final, and between Windows 95 M8 beta and Windows 95 final.  If you do
    ** not require the server address and wish to retrieve PPP IP information
    ** from Windows NT 3.5 or early Windows NT 3.51 betas, or on early Windows
    ** 95 betas, define WINNT35COMPATIBLE.
    **
    ** The server IP address is not provided by all PPP implementations,
    ** though Windows NT server's do provide it.
    */
    WCHAR szServerIpAddress[ RAS_MaxIpAddress + 1 ];

#endif
};

#define RASPPPIPA struct tagRASPPPIPA
RASPPPIPA
{
    unsigned long dwSize;
    unsigned long dwError;
    CHAR  szIpAddress[ RAS_MaxIpAddress + 1 ];

#ifndef WINNT35COMPATIBLE

    /* See RASPPPIPW comment.
    */
    CHAR  szServerIpAddress[ RAS_MaxIpAddress + 1 ];

#endif
};

#ifdef UNICODE
#define RASPPPIP RASPPPIPW
#else
#define RASPPPIP RASPPPIPA
#endif

#define LPRASPPPIPW RASPPPIPW*
#define LPRASPPPIPA RASPPPIPA*
#define LPRASPPPIP  RASPPPIP*


/* Describes the results of a PPP LCP/multi-link negotiation.
*/
#define RASPPPLCP struct tagRASPPPLCP
RASPPPLCP
{
    unsigned long dwSize;
    BOOL  fBundled;
};

#define LPRASPPPLCP RASPPPLCP*


/* Describes the results of a SLIP (Serial Line IP) projection.
*/
#define RASSLIPW struct tagRASSLIPW
RASSLIPW
{
    unsigned long dwSize;
    unsigned long dwError;
    WCHAR szIpAddress[ RAS_MaxIpAddress + 1 ];
};


#define RASSLIPA struct tagRASSLIPA
RASSLIPA
{
    unsigned long dwSize;
    unsigned long dwError;
    CHAR  szIpAddress[ RAS_MaxIpAddress + 1 ];
};

#ifdef UNICODE
#define RASSLIP RASSLIPW
#else
#define RASSLIP RASSLIPA
#endif

#define LPRASSLIPW RASSLIPW*
#define LPRASSLIPA RASSLIPA*
#define LPRASSLIP  RASSLIP*


/* If using RasDial message notifications, get the notification message code
** by passing this string to the RegisterWindowMessageA() API.
** WM_RASDIALEVENT is used only if a unique message cannot be registered.
*/
#define RASDIALEVENT    "RasDialEvent"
#define WM_RASDIALEVENT 0xCCCD

/* Prototypes for caller's RasDial callback handler.  Arguments are the
** message ID (currently always WM_RASDIALEVENT), the current RASCONNSTATE and
** the error that has occurred (or 0 if none).  Extended arguments are the
** handle of the RAS connection and an extended error code.
**
** For RASDIALFUNC2, subsequent callback notifications for all
** subentries can be cancelled by returning FALSE.
*/
typedef VOID (WINAPI *RASDIALFUNC)( UINT, RASCONNSTATE, unsigned long );
typedef VOID (WINAPI *RASDIALFUNC1)( HRASCONN, UINT, RASCONNSTATE, unsigned long, unsigned long );
typedef unsigned long (WINAPI *RASDIALFUNC2)( unsigned long, unsigned long, HRASCONN, UINT, RASCONNSTATE, unsigned long, unsigned long );


/* Information describing a RAS-capable device.
*/
#define RASDEVINFOW struct tagRASDEVINFOW
RASDEVINFOW
{
    unsigned long    dwSize;
    WCHAR    szDeviceType[ RAS_MaxDeviceType + 1 ];
    WCHAR    szDeviceName[ RAS_MaxDeviceName + 1 ];
};

#define RASDEVINFOA struct tagRASDEVINFOA
RASDEVINFOA
{
    unsigned long    dwSize;
    CHAR     szDeviceType[ RAS_MaxDeviceType + 1 ];
    CHAR     szDeviceName[ RAS_MaxDeviceName + 1 ];
};

#ifdef UNICODE
#define RASDEVINFO RASDEVINFOW
#else
#define RASDEVINFO RASDEVINFOA
#endif

#define LPRASDEVINFOW RASDEVINFOW*
#define LPRASDEVINFOA RASDEVINFOA*
#define LPRASDEVINFO  RASDEVINFO*

/* RAS country information (currently retrieved from TAPI).
*/
#define RASCTRYINFO struct RASCTRYINFO
RASCTRYINFO
{
    unsigned long   dwSize;
    unsigned long   dwCountryID;
    unsigned long   dwNextCountryID;
    unsigned long   dwCountryCode;
    unsigned long   dwCountryNameOffset;
};

/* There is currently no difference between
** RASCTRYINFOA and RASCTRYINFOW.  This may
** change in the future.
*/
#define RASCTRYINFOW   RASCTRYINFO
#define RASCTRYINFOA   RASCTRYINFO

#define LPRASCTRYINFOW RASCTRYINFOW*
#define LPRASCTRYINFOA RASCTRYINFOW*
#define LPRASCTRYINFO  RASCTRYINFO*

/* A RAS IP address.
*/
#define RASIPADDR struct RASIPADDR
RASIPADDR
{
    BYTE a;
    BYTE b;
    BYTE c;
    BYTE d;
};

/* A RAS phone book entry.
*/
#define RASENTRYA struct tagRASENTRYA
RASENTRYA
{
    unsigned long       dwSize;
    unsigned long       dwfOptions;
    //
    // Location/phone number.
    //
    unsigned long       dwCountryID;
    unsigned long       dwCountryCode;
    CHAR        szAreaCode[ RAS_MaxAreaCode + 1 ];
    CHAR        szLocalPhoneNumber[ RAS_MaxPhoneNumber + 1 ];
    unsigned long       dwAlternateOffset;
    //
    // PPP/Ip
    //
    RASIPADDR   ipaddr;
    RASIPADDR   ipaddrDns;
    RASIPADDR   ipaddrDnsAlt;
    RASIPADDR   ipaddrWins;
    RASIPADDR   ipaddrWinsAlt;
    //
    // Framing
    //
    unsigned long       dwFrameSize;
    unsigned long       dwfNetProtocols;
    unsigned long       dwFramingProtocol;
    //
    // Scripting
    //
    CHAR        szScript[ MAX_PATH ];
    //
    // AutoDial
    //
    CHAR        szAutodialDll[ MAX_PATH ];
    CHAR        szAutodialFunc[ MAX_PATH ];
    //
    // Device
    //
    CHAR        szDeviceType[ RAS_MaxDeviceType + 1 ];
    CHAR        szDeviceName[ RAS_MaxDeviceName + 1 ];
    //
    // X.25
    //
    CHAR        szX25PadType[ RAS_MaxPadType + 1 ];
    CHAR        szX25Address[ RAS_MaxX25Address + 1 ];
    CHAR        szX25Facilities[ RAS_MaxFacilities + 1 ];
    CHAR        szX25UserData[ RAS_MaxUserData + 1 ];
    unsigned long       dwChannels;
    //
    // Reserved
    //
    unsigned long       dwReserved1;
    unsigned long       dwReserved2;
#if (WINVER >= 0x401)
    //
    // Multilink
    //
    unsigned long       dwSubEntries;
    unsigned long       dwDialMode;
    unsigned long       dwDialExtraPercent;
    unsigned long       dwDialExtraSampleSeconds;
    unsigned long       dwHangUpExtraPercent;
    unsigned long       dwHangUpExtraSampleSeconds;
    //
    // Idle timeout
    //
    unsigned long       dwIdleDisconnectSeconds;
#endif
};

#define RASENTRYW struct tagRASENTRYW
RASENTRYW
{
    unsigned long       dwSize;
    unsigned long       dwfOptions;
    //
    // Location/phone number
    //
    unsigned long       dwCountryID;
    unsigned long       dwCountryCode;
    WCHAR       szAreaCode[ RAS_MaxAreaCode + 1 ];
    WCHAR       szLocalPhoneNumber[ RAS_MaxPhoneNumber + 1 ];
    unsigned long       dwAlternateOffset;
    //
    // PPP/Ip
    //
    RASIPADDR   ipaddr;
    RASIPADDR   ipaddrDns;
    RASIPADDR   ipaddrDnsAlt;
    RASIPADDR   ipaddrWins;
    RASIPADDR   ipaddrWinsAlt;
    //
    // Framing
    //
    unsigned long       dwFrameSize;
    unsigned long       dwfNetProtocols;
    unsigned long       dwFramingProtocol;
    //
    // Scripting
    //
    WCHAR       szScript[ MAX_PATH ];
    //
    // AutoDial
    //
    WCHAR       szAutodialDll[ MAX_PATH ];
    WCHAR       szAutodialFunc[ MAX_PATH ];
    //
    // Device
    //
    WCHAR       szDeviceType[ RAS_MaxDeviceType + 1 ];
    WCHAR       szDeviceName[ RAS_MaxDeviceName + 1 ];
    //
    // X.25
    //
    WCHAR       szX25PadType[ RAS_MaxPadType + 1 ];
    WCHAR       szX25Address[ RAS_MaxX25Address + 1 ];
    WCHAR       szX25Facilities[ RAS_MaxFacilities + 1 ];
    WCHAR       szX25UserData[ RAS_MaxUserData + 1 ];
    unsigned long       dwChannels;
    //
    // Reserved
    //
    unsigned long       dwReserved1;
    unsigned long       dwReserved2;
#if (WINVER >= 0x401)
    //
    // Multilink
    //
    unsigned long       dwSubEntries;
    unsigned long       dwDialMode;
    unsigned long       dwDialExtraPercent;
    unsigned long       dwDialExtraSampleSeconds;
    unsigned long       dwHangUpExtraPercent;
    unsigned long       dwHangUpExtraSampleSeconds;
    //
    // Idle timeout
    //
    unsigned long       dwIdleDisconnectSeconds;
#endif
};

#ifdef UNICODE
#define RASENTRY RASENTRYW
#else
#define RASENTRY RASENTRYA
#endif

#define LPRASENTRYW RASENTRYW*
#define LPRASENTRYA RASENTRYA*
#define LPRASENTRY  RASENTRY*

/* RASENTRY 'dwfOptions' bit flags.
*/
#define RASEO_UseCountryAndAreaCodes    0x00000001
#define RASEO_SpecificIpAddr            0x00000002
#define RASEO_SpecificNameServers       0x00000004
#define RASEO_IpHeaderCompression       0x00000008
#define RASEO_RemoteDefaultGateway      0x00000010
#define RASEO_DisableLcpExtensions      0x00000020
#define RASEO_TerminalBeforeDial        0x00000040
#define RASEO_TerminalAfterDial         0x00000080
#define RASEO_ModemLights               0x00000100
#define RASEO_SwCompression             0x00000200
#define RASEO_RequireEncryptedPw        0x00000400
#define RASEO_RequireMsEncryptedPw      0x00000800
#define RASEO_RequireDataEncryption     0x00001000
#define RASEO_NetworkLogon              0x00002000
#define RASEO_UseLogonCredentials       0x00004000
#define RASEO_PromoteAlternates         0x00008000
#if (WINVER >= 0x401)
#define RASEO_SecureLocalFiles          0x00010000
#endif

/* RASENTRY 'dwProtocols' bit flags.
*/
#define RASNP_NetBEUI                   0x00000001
#define RASNP_Ipx                       0x00000002
#define RASNP_Ip                        0x00000004

/* RASENTRY 'dwFramingProtocols' bit flags.
*/
#define RASFP_Ppp                       0x00000001
#define RASFP_Slip                      0x00000002
#define RASFP_Ras                       0x00000004

/* RASENTRY 'szDeviceType' default strings.
*/
#define RASDT_Modem                     TEXT("modem")
#define RASDT_Isdn                      TEXT("isdn")
#define RASDT_X25                       TEXT("x25")

/* Old AutoDial DLL function prototype.
**
** This prototype is documented for backward-compatibility
** purposes only.  It is superceded by the RASADFUNCA
** and RASADFUNCW definitions below.  DO NOT USE THIS
** PROTOTYPE IN NEW CODE.  SUPPORT FOR IT MAY BE REMOVED
** IN FUTURE VERSIONS OF RAS.
*/
typedef BOOL (WINAPI *ORASADFUNC)( HWND, LPSTR, unsigned long, LPDWORD );

#if (WINVER >= 0x401)
/* Flags for RasConnectionNotification().
*/
#define RASCN_Connection        0x00000001
#define RASCN_Disconnection     0x00000002
#define RASCN_BandwidthAdded    0x00000004
#define RASCN_BandwidthRemoved  0x00000008

/* RASENTRY 'dwDialMode' values.
*/
#define RASEDM_DialAll                  1
#define RASEDM_DialAsNeeded             2

/* RASENTRY 'dwIdleDisconnectSeconds' constants.
*/
#define RASIDS_Disabled                 0xffffffff
#define RASIDS_UseGlobalValue           0

/* AutoDial DLL function parameter block.
*/
#define RASADPARAMS struct tagRASADPARAMS
RASADPARAMS
{
    unsigned long       dwSize;
    HWND        hwndOwner;
    unsigned long       dwFlags;
    LONG        xDlg;
    LONG        yDlg;
};

#define LPRASADPARAMS RASADPARAMS*

/* AutoDial DLL function parameter block 'dwFlags.'
*/
#define RASADFLG_PositionDlg            0x00000001

/* Prototype AutoDial DLL function.
*/
typedef BOOL (WINAPI *RASADFUNCA)( LPSTR, LPSTR, LPRASADPARAMS, LPDWORD );
typedef BOOL (WINAPI *RASADFUNCW)( LPWSTR, LPWSTR, LPRASADPARAMS, LPDWORD );

#ifdef UNICODE
#define RASADFUNC RASADFUNCW
#else
#define RASADFUNC RASADFUNCA
#endif

/* A RAS phone book multilinked sub-entry.
*/
#define RASSUBENTRYA struct tagRASSUBENTRYA
RASSUBENTRYA
{
    unsigned long       dwSize;
    unsigned long       dwfFlags;
    //
    // Device
    //
    CHAR        szDeviceType[ RAS_MaxDeviceType + 1 ];
    CHAR        szDeviceName[ RAS_MaxDeviceName + 1 ];
    //
    // Phone numbers
    //
    CHAR        szLocalPhoneNumber[ RAS_MaxPhoneNumber + 1 ];
    unsigned long       dwAlternateOffset;
};

#define RASSUBENTRYW struct tagRASSUBENTRYW
RASSUBENTRYW
{
    unsigned long       dwSize;
    unsigned long       dwfFlags;
    //
    // Device
    //
    WCHAR       szDeviceType[ RAS_MaxDeviceType + 1 ];
    WCHAR       szDeviceName[ RAS_MaxDeviceName + 1 ];
    //
    // Phone numbers
    //
    WCHAR       szLocalPhoneNumber[ RAS_MaxPhoneNumber + 1 ];
    unsigned long       dwAlternateOffset;
};

#ifdef UNICODE
#define RASSUBENTRY RASSUBENTRYW
#else
#define RASSUBENTRY RASSUBENTRYA
#endif

#define LPRASSUBENTRYW RASSUBENTRYW*
#define LPRASSUBENTRYA RASSUBENTRYA*
#define LPRASSUBENTRY  RASSUBENTRY*

/* Ras{Get,Set}Credentials structure.  These calls
** supercede Ras{Get,Set}EntryDialParams.
*/
#define RASCREDENTIALSA struct tagRASCREDENTIALSA
RASCREDENTIALSA
{
    unsigned long dwSize;
    unsigned long dwMask;
    CHAR szUserName[ UNLEN + 1 ];
    CHAR szPassword[ PWLEN + 1 ];
    CHAR szDomain[ DNLEN + 1 ];
};

#define RASCREDENTIALSW struct tagRASCREDENTIALSW
RASCREDENTIALSW
{
    unsigned long dwSize;
    unsigned long dwMask;
    WCHAR szUserName[ UNLEN + 1 ];
    WCHAR szPassword[ PWLEN + 1 ];
    WCHAR szDomain[ DNLEN + 1 ];
};

#ifdef UNICODE
#define RASCREDENTIALS RASCREDENTIALSW
#else
#define RASCREDENTIALS RASCREDENTIALSA
#endif

#define LPRASCREDENTIALSW RASCREDENTIALSW*
#define LPRASCREDENTIALSA RASCREDENTIALSA*
#define LPRASCREDENTIALS  RASCREDENTIALS*

/* RASCREDENTIALS 'dwMask' values.
*/
#define RASCM_UserName       0x00000001
#define RASCM_Password       0x00000002
#define RASCM_Domain         0x00000004

/* AutoDial address properties.
*/
#define RASAUTODIALENTRYA struct tagRASAUTODIALENTRYA
RASAUTODIALENTRYA
{
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwDialingLocation;
    CHAR szEntry[ RAS_MaxEntryName + 1];
};

#define RASAUTODIALENTRYW struct tagRASAUTODIALENTRYW
RASAUTODIALENTRYW
{
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwDialingLocation;
    WCHAR szEntry[ RAS_MaxEntryName + 1];
};

#ifdef UNICODE
#define RASAUTODIALENTRY RASAUTODIALENTRYW
#else
#define RASAUTODIALENTRY RASAUTODIALENTRYA
#endif

#define LPRASAUTODIALENTRYW RASAUTODIALENTRYW*
#define LPRASAUTODIALENTRYA RASAUTODIALENTRYA*
#define LPRASAUTODIALENTRY  RASAUTODIALENTRY*

/* AutoDial control parameter values for
** Ras{Get,Set}AutodialParam.
*/
#define RASADP_DisableConnectionQuery           0
#define RASADP_LoginSessionDisable              1
#define RASADP_SavedAddressesLimit              2
#define RASADP_FailedConnectionTimeout          3
#define RASADP_ConnectionQueryTimeout           4

#endif // (WINVER >= 0x401)


/* External RAS API function prototypes.
*/
unsigned long __stdcall RasDialA( LPRASDIALEXTENSIONS, LPSTR, LPRASDIALPARAMSA, unsigned long,
                   void*, LPHRASCONN );

unsigned long __stdcall RasDialW( LPRASDIALEXTENSIONS, LPWSTR, LPRASDIALPARAMSW, unsigned long,
                   void*, LPHRASCONN );

unsigned long __stdcall RasEnumConnectionsA( LPRASCONNA, LPDWORD, LPDWORD );

unsigned long __stdcall RasEnumConnectionsW( LPRASCONNW, LPDWORD, LPDWORD );

unsigned long __stdcall RasEnumEntriesA( LPSTR, LPSTR, LPRASENTRYNAMEA, LPDWORD,
                   LPDWORD );

unsigned long __stdcall RasEnumEntriesW( LPWSTR, LPWSTR, LPRASENTRYNAMEW, LPDWORD,
                   LPDWORD );

unsigned long __stdcall RasGetConnectStatusA( HRASCONN, LPRASCONNSTATUSA );

unsigned long __stdcall RasGetConnectStatusW( HRASCONN, LPRASCONNSTATUSW );

unsigned long __stdcall RasGetErrorStringA( UINT, LPSTR, unsigned long );

unsigned long __stdcall RasGetErrorStringW( UINT, LPWSTR, unsigned long );

unsigned long __stdcall RasHangUpA( HRASCONN );

unsigned long __stdcall RasHangUpW( HRASCONN );

unsigned long __stdcall RasGetProjectionInfoA( HRASCONN, RASPROJECTION, void*,
                   LPDWORD );

unsigned long __stdcall RasGetProjectionInfoW( HRASCONN, RASPROJECTION, void*,
                   LPDWORD );

unsigned long __stdcall RasCreatePhonebookEntryA( HWND, LPSTR );

unsigned long __stdcall RasCreatePhonebookEntryW( HWND, LPWSTR );

unsigned long __stdcall RasEditPhonebookEntryA( HWND, LPSTR, LPSTR );

unsigned long __stdcall RasEditPhonebookEntryW( HWND, LPWSTR, LPWSTR );

unsigned long __stdcall RasSetEntryDialParamsA( LPSTR, LPRASDIALPARAMSA, BOOL );

unsigned long __stdcall RasSetEntryDialParamsW( LPWSTR, LPRASDIALPARAMSW, BOOL );

unsigned long __stdcall RasGetEntryDialParamsA( LPSTR, LPRASDIALPARAMSA, LPBOOL );

unsigned long __stdcall RasGetEntryDialParamsW( LPWSTR, LPRASDIALPARAMSW, LPBOOL );

unsigned long __stdcall RasEnumDevicesA( LPRASDEVINFOA, LPDWORD, LPDWORD );

unsigned long __stdcall RasEnumDevicesW( LPRASDEVINFOW, LPDWORD, LPDWORD );

unsigned long __stdcall RasGetCountryInfoA( LPRASCTRYINFOA, LPDWORD );

unsigned long __stdcall RasGetCountryInfoW( LPRASCTRYINFOW, LPDWORD );

unsigned long __stdcall RasGetEntryPropertiesA( LPSTR, LPSTR, LPRASENTRYA, LPDWORD, LPBYTE, LPDWORD );

unsigned long __stdcall RasGetEntryPropertiesW( LPWSTR, LPWSTR, LPRASENTRYW, LPDWORD, LPBYTE, LPDWORD );

unsigned long __stdcall RasSetEntryPropertiesA( LPSTR, LPSTR, LPRASENTRYA, unsigned long, LPBYTE, unsigned long );

unsigned long __stdcall RasSetEntryPropertiesW( LPWSTR, LPWSTR, LPRASENTRYW, unsigned long, LPBYTE, unsigned long );

unsigned long __stdcall RasRenameEntryA( LPSTR, LPSTR, LPSTR );

unsigned long __stdcall RasRenameEntryW( LPWSTR, LPWSTR, LPWSTR );

unsigned long __stdcall RasDeleteEntryA( LPSTR, LPSTR );

unsigned long __stdcall RasDeleteEntryW( LPWSTR, LPWSTR );

unsigned long __stdcall RasValidateEntryNameA( LPSTR, LPSTR );

unsigned long __stdcall RasValidateEntryNameW( LPWSTR, LPWSTR );

#if (WINVER >= 0x401)
unsigned long __stdcall RasGetSubEntryHandleA( HRASCONN, unsigned long, LPHRASCONN );

unsigned long __stdcall RasGetSubEntryHandleW( HRASCONN, unsigned long, LPHRASCONN );

unsigned long __stdcall RasGetCredentialsA( LPSTR, LPSTR, LPRASCREDENTIALSA);

unsigned long __stdcall RasGetCredentialsW( LPWSTR, LPWSTR, LPRASCREDENTIALSW );

unsigned long __stdcall RasSetCredentialsA( LPSTR, LPSTR, LPRASCREDENTIALSA, BOOL );

unsigned long __stdcall RasSetCredentialsW( LPWSTR, LPWSTR, LPRASCREDENTIALSW, BOOL );

unsigned long __stdcall RasConnectionNotificationA( HRASCONN, HANDLE, unsigned long );

unsigned long __stdcall RasConnectionNotificationW( HRASCONN, HANDLE, unsigned long );

unsigned long __stdcall RasGetSubEntryPropertiesA( LPSTR, LPSTR, unsigned long,
                    LPRASSUBENTRYA, LPDWORD, LPBYTE, LPDWORD );

unsigned long __stdcall RasGetSubEntryPropertiesW( LPWSTR, LPWSTR, unsigned long,
                    LPRASSUBENTRYW, LPDWORD, LPBYTE, LPDWORD );

unsigned long __stdcall RasSetSubEntryPropertiesA( LPSTR, LPSTR, unsigned long,
                    LPRASSUBENTRYA, unsigned long, LPBYTE, unsigned long );

unsigned long __stdcall RasSetSubEntryPropertiesW( LPWSTR, LPWSTR, unsigned long,
                    LPRASSUBENTRYW, unsigned long, LPBYTE, unsigned long );

unsigned long __stdcall RasGetAutodialAddressA( LPSTR, LPDWORD, LPRASAUTODIALENTRYA,
                    LPDWORD, LPDWORD );

unsigned long __stdcall RasGetAutodialAddressW( LPWSTR, LPDWORD, LPRASAUTODIALENTRYW,
                    LPDWORD, LPDWORD);

unsigned long __stdcall RasSetAutodialAddressA( LPSTR, unsigned long, LPRASAUTODIALENTRYA,
                    unsigned long, unsigned long );

unsigned long __stdcall RasSetAutodialAddressW( LPWSTR, unsigned long, LPRASAUTODIALENTRYW,
                    unsigned long, unsigned long );

unsigned long __stdcall RasEnumAutodialAddressesA( LPSTR *, LPDWORD, LPDWORD );

unsigned long __stdcall RasEnumAutodialAddressesW( LPWSTR *, LPDWORD, LPDWORD );

unsigned long __stdcall RasGetAutodialEnableA( unsigned long, LPBOOL );

unsigned long __stdcall RasGetAutodialEnableW( unsigned long, LPBOOL );

unsigned long __stdcall RasSetAutodialEnableA( unsigned long, BOOL );

unsigned long __stdcall RasSetAutodialEnableW( unsigned long, BOOL );

unsigned long __stdcall RasGetAutodialParamA( unsigned long, void*, LPDWORD );

unsigned long __stdcall RasGetAutodialParamW( unsigned long, void*, LPDWORD );

unsigned long __stdcall RasSetAutodialParamA( unsigned long, void*, unsigned long );

unsigned long __stdcall RasSetAutodialParamW( unsigned long, void*, unsigned long );
#endif


#ifdef UNICODE
#define RasDial                 RasDialW
#define RasEnumConnections      RasEnumConnectionsW
#define RasEnumEntries          RasEnumEntriesW
#define RasGetConnectStatus     RasGetConnectStatusW
#define RasGetErrorString       RasGetErrorStringW
#define RasHangUp               RasHangUpW
#define RasGetProjectionInfo    RasGetProjectionInfoW
#define RasCreatePhonebookEntry RasCreatePhonebookEntryW
#define RasEditPhonebookEntry   RasEditPhonebookEntryW
#define RasSetEntryDialParams   RasSetEntryDialParamsW
#define RasGetEntryDialParams   RasGetEntryDialParamsW
#define RasEnumDevices          RasEnumDevicesW
#define RasGetCountryInfo       RasGetCountryInfoW
#define RasGetEntryProperties   RasGetEntryPropertiesW
#define RasSetEntryProperties   RasSetEntryPropertiesW
#define RasRenameEntry          RasRenameEntryW
#define RasDeleteEntry          RasDeleteEntryW
#define RasValidateEntryName    RasValidateEntryNameW
#if (WINVER >= 0x401)
#define RasGetSubEntryHandle        RasGetSubEntryHandleW
#define RasConnectionNotification   RasConnectionNotificationW
#define RasGetSubEntryProperties    RasGetSubEntryPropertiesW
#define RasSetSubEntryProperties    RasSetSubEntryPropertiesW
#define RasGetCredentials           RasGetCredentialsW
#define RasSetCredentials           RasSetCredentialsW
#define RasGetAutodialAddress       RasGetAutodialAddressW
#define RasSetAutodialAddress       RasSetAutodialAddressW
#define RasEnumAutodialAddresses    RasEnumAutodialAddressesW
#define RasGetAutodialEnable        RasGetAutodialEnableW
#define RasSetAutodialEnable        RasSetAutodialEnableW
#define RasGetAutodialParam         RasGetAutodialParamW
#define RasSetAutodialParam         RasSetAutodialParamW
#endif
#else
#define RasDial                 RasDialA
#define RasEnumConnections      RasEnumConnectionsA
#define RasEnumEntries          RasEnumEntriesA
#define RasGetConnectStatus     RasGetConnectStatusA
#define RasGetErrorString       RasGetErrorStringA
#define RasHangUp               RasHangUpA
#define RasGetProjectionInfo    RasGetProjectionInfoA
#define RasCreatePhonebookEntry RasCreatePhonebookEntryA
#define RasEditPhonebookEntry   RasEditPhonebookEntryA
#define RasSetEntryDialParams   RasSetEntryDialParamsA
#define RasGetEntryDialParams   RasGetEntryDialParamsA
#define RasEnumDevices          RasEnumDevicesA
#define RasGetCountryInfo       RasGetCountryInfoA
#define RasGetEntryProperties   RasGetEntryPropertiesA
#define RasSetEntryProperties   RasSetEntryPropertiesA
#define RasRenameEntry          RasRenameEntryA
#define RasDeleteEntry          RasDeleteEntryA
#define RasValidateEntryName    RasValidateEntryNameA
#if (WINVER >= 0x401)
#define RasGetSubEntryHandle        RasGetSubEntryHandleA
#define RasConnectionNotification   RasConnectionNotificationA
#define RasGetSubEntryProperties    RasGetSubEntryPropertiesA
#define RasSetSubEntryProperties    RasSetSubEntryPropertiesA
#define RasGetCredentials           RasGetCredentialsA
#define RasSetCredentials           RasSetCredentialsA
#define RasGetAutodialAddress       RasGetAutodialAddressA
#define RasSetAutodialAddress       RasSetAutodialAddressA
#define RasEnumAutodialAddresses    RasEnumAutodialAddressesA
#define RasGetAutodialEnable        RasGetAutodialEnableA
#define RasSetAutodialEnable        RasSetAutodialEnableA
#define RasGetAutodialParam         RasGetAutodialParamA
#define RasSetAutodialParam         RasSetAutodialParamA
#endif
#endif

#ifdef __cplusplus
}
#endif

#include <poppack.h>

#endif // _RAS_H_
#pragma once 
