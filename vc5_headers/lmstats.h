/*++ BUILD Version: 0001    // Increment this if a change has global effects

Copyright (c) 1991-1996  Microsoft Corporation

Module Name:

    lmstats.h

Abstract:

    This module defines the API function prototypes and data structures
    for the following groups of NT API functions:
        NetStatistics

Environment:

    User Mode - Win32

Notes:

    You must include NETCONS.H before this file, since this file depends
    on values defined in NETCONS.H.

--*/

#ifndef _LMSTATS_
#define _LMSTATS_

#ifdef __cplusplus
extern "C" {
#endif

//
// Function Prototypes - Statistics
//

NET_API_STATUS NET_API_FUNCTION
NetStatisticsGet (
    IN  LPTSTR  server,
    IN  LPTSTR  service,
    IN  unsigned long   level,
    IN  unsigned long   options,
    OUT LPBYTE  *bufptr
    );

//
// Data Structures - Statistics
//

#ifdef LM20_WORKSTATION_STATISTICS
typedef struct _STAT_WORKSTATION_0 {
     unsigned long          stw0_start;
     unsigned long          stw0_numNCB_r;
     unsigned long          stw0_numNCB_s;
     unsigned long          stw0_numNCB_a;
     unsigned long          stw0_fiNCB_r;
     unsigned long          stw0_fiNCB_s;
     unsigned long          stw0_fiNCB_a;
     unsigned long          stw0_fcNCB_r;
     unsigned long          stw0_fcNCB_s;
     unsigned long          stw0_fcNCB_a;
     unsigned long          stw0_sesstart;
     unsigned long          stw0_sessfailcon;
     unsigned long          stw0_sessbroke;
     unsigned long          stw0_uses;
     unsigned long          stw0_usefail;
     unsigned long          stw0_autorec;
     unsigned long          stw0_bytessent_r_lo;
     unsigned long          stw0_bytessent_r_hi;
     unsigned long          stw0_bytesrcvd_r_lo;
     unsigned long          stw0_bytesrcvd_r_hi;
     unsigned long          stw0_bytessent_s_lo;
     unsigned long          stw0_bytessent_s_hi;
     unsigned long          stw0_bytesrcvd_s_lo;
     unsigned long          stw0_bytesrcvd_s_hi;
     unsigned long          stw0_bytessent_a_lo;
     unsigned long          stw0_bytessent_a_hi;
     unsigned long          stw0_bytesrcvd_a_lo;
     unsigned long          stw0_bytesrcvd_a_hi;
     unsigned long          stw0_reqbufneed;
     unsigned long          stw0_bigbufneed;
} STAT_WORKSTATION_0, *PSTAT_WORKSTATION_0, *LPSTAT_WORKSTATION_0;
#else

//
// NB: The following structure is REDIR_STATISTICS in sdk\inc\ntddnfs.h. If you
//     change the structure, change it in both places
//

typedef struct _STAT_WORKSTATION_0 {
    LARGE_INTEGER   StatisticsStartTime;

    LARGE_INTEGER   BytesReceived;
    LARGE_INTEGER   SmbsReceived;
    LARGE_INTEGER   PagingReadBytesRequested;
    LARGE_INTEGER   NonPagingReadBytesRequested;
    LARGE_INTEGER   CacheReadBytesRequested;
    LARGE_INTEGER   NetworkReadBytesRequested;

    LARGE_INTEGER   BytesTransmitted;
    LARGE_INTEGER   SmbsTransmitted;
    LARGE_INTEGER   PagingWriteBytesRequested;
    LARGE_INTEGER   NonPagingWriteBytesRequested;
    LARGE_INTEGER   CacheWriteBytesRequested;
    LARGE_INTEGER   NetworkWriteBytesRequested;

    unsigned long           InitiallyFailedOperations;
    unsigned long           FailedCompletionOperations;

    unsigned long           ReadOperations;
    unsigned long           RandomReadOperations;
    unsigned long           ReadSmbs;
    unsigned long           LargeReadSmbs;
    unsigned long           SmallReadSmbs;

    unsigned long           WriteOperations;
    unsigned long           RandomWriteOperations;
    unsigned long           WriteSmbs;
    unsigned long           LargeWriteSmbs;
    unsigned long           SmallWriteSmbs;

    unsigned long           RawReadsDenied;
    unsigned long           RawWritesDenied;

    unsigned long           NetworkErrors;

    //  Connection/Session counts
    unsigned long           Sessions;
    unsigned long           FailedSessions;
    unsigned long           Reconnects;
    unsigned long           CoreConnects;
    unsigned long           Lanman20Connects;
    unsigned long           Lanman21Connects;
    unsigned long           LanmanNtConnects;
    unsigned long           ServerDisconnects;
    unsigned long           HungSessions;
    unsigned long           UseCount;
    unsigned long           FailedUseCount;

    //
    //  Queue Lengths (updates protected by RdrMpxTableSpinLock NOT
    //  RdrStatisticsSpinlock)
    //

    unsigned long           CurrentCommands;

} STAT_WORKSTATION_0, *PSTAT_WORKSTATION_0, *LPSTAT_WORKSTATION_0;
#endif

typedef struct _STAT_SERVER_0 {
     unsigned long          sts0_start;
     unsigned long          sts0_fopens;
     unsigned long          sts0_devopens;
     unsigned long          sts0_jobsqueued;
     unsigned long          sts0_sopens;
     unsigned long          sts0_stimedout;
     unsigned long          sts0_serrorout;
     unsigned long          sts0_pwerrors;
     unsigned long          sts0_permerrors;
     unsigned long          sts0_syserrors;
     unsigned long          sts0_bytessent_low;
     unsigned long          sts0_bytessent_high;
     unsigned long          sts0_bytesrcvd_low;
     unsigned long          sts0_bytesrcvd_high;
     unsigned long          sts0_avresponse;
     unsigned long          sts0_reqbufneed;
     unsigned long          sts0_bigbufneed;
} STAT_SERVER_0, *PSTAT_SERVER_0, *LPSTAT_SERVER_0;


//
// Special Values and Constants
//

#define STATSOPT_CLR    1
#define STATS_NO_VALUE  ((unsigned long) -1L)
#define STATS_OVERFLOW  ((unsigned long) -2L)


#ifdef __cplusplus
}
#endif

#endif // _LMSTATS.H
#pragma once 
