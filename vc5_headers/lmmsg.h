/*++ BUILD Version: 0001    // Increment this if a change has global effects

Copyright (c) 1991-1996  Microsoft Corporation

Module Name:

    lmmsg.h

Abstract:

    This file contains structures, function prototypes, and definitions
    for the NetMessage API.

[Environment:]

    User Mode - Win32

[Notes:]

    You must include NETCONS.H before this file, since this file depends
    on values defined in NETCONS.H.

--*/

#ifndef _LMMSG_
#define _LMMSG_

#ifdef __cplusplus
extern "C" {
#endif

//
// Function Prototypes
//

NET_API_STATUS NET_API_FUNCTION
NetMessageNameAdd (
    IN  const wchar_t*  servername,
    IN  const wchar_t*  msgname
    );

NET_API_STATUS NET_API_FUNCTION
NetMessageNameEnum (
    IN  const wchar_t*     servername,
    IN  unsigned long       level,
    OUT LPBYTE      *bufptr,
    IN  unsigned long       prefmaxlen,
    OUT LPDWORD     entriesread,
    OUT LPDWORD     totalentries,
    IN OUT LPDWORD  resume_handle
    );

NET_API_STATUS NET_API_FUNCTION
NetMessageNameGetInfo (
    IN  const wchar_t* servername,
    IN  const wchar_t* msgname,
    IN  unsigned long   level,
    OUT LPBYTE  *bufptr
    );

NET_API_STATUS NET_API_FUNCTION
NetMessageNameDel (
    IN  const wchar_t*   servername,
    IN  const wchar_t*   msgname
    );

NET_API_STATUS NET_API_FUNCTION
NetMessageBufferSend (
    IN  const wchar_t*  servername,
    IN  const wchar_t*  msgname,
    IN  const wchar_t*  fromname,
    IN  LPBYTE   buf,
    IN  unsigned long    buflen
    );

//
//  Data Structures
//

typedef struct _MSG_INFO_0 {
    LPWSTR  msgi0_name;
}MSG_INFO_0, *PMSG_INFO_0, *LPMSG_INFO_0;

typedef struct _MSG_INFO_1 {
    LPWSTR  msgi1_name;
    unsigned long   msgi1_forward_flag;
    LPWSTR  msgi1_forward;
}MSG_INFO_1, *PMSG_INFO_1, *LPMSG_INFO_1;

//
// Special Values and Constants
//

//
// Values for msgi1_forward_flag.
//

#define MSGNAME_NOT_FORWARDED   0       // Name not forwarded
#define MSGNAME_FORWARDED_TO    0x04    // Name forward to remote station
#define MSGNAME_FORWARDED_FROM  0x10    // Name forwarded from remote station

#ifdef __cplusplus
}
#endif

#endif //_LMMSG_
#pragma once 
