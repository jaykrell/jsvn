/*++ BUILD Version: 0007    // Increment this if a change has global effects

Copyright (c) 1990-1996  Microsoft Corporation

Module Name:

    lmbrowsr.h

Abstract:

    This file contains information about browser stubbed versions of the
    NetServer APIs.
        Function Prototypes
        Data Structures
        Definition of special values

Environment:

    User Mode - Win32

Notes:

    You must include NETCONS.H before this file, since this file depends
    on values defined in NETCONS.H.


--*/

#ifndef _LMBROWSR_
#define _LMBROWSR_

#ifdef __cplusplus
extern "C" {
#endif


typedef struct _BROWSER_STATISTICS {
    LARGE_INTEGER   StatisticsStartTime;
    LARGE_INTEGER   NumberOfServerAnnouncements;
    LARGE_INTEGER   NumberOfDomainAnnouncements;
    unsigned long           NumberOfElectionPackets;
    unsigned long           NumberOfMailslotWrites;
    unsigned long           NumberOfGetBrowserServerListRequests;
    unsigned long           NumberOfServerEnumerations;
    unsigned long           NumberOfDomainEnumerations;
    unsigned long           NumberOfOtherEnumerations;
    unsigned long           NumberOfMissedServerAnnouncements;
    unsigned long           NumberOfMissedMailslotDatagrams;
    unsigned long           NumberOfMissedGetBrowserServerListRequests;
    unsigned long           NumberOfFailedServerAnnounceAllocations;
    unsigned long           NumberOfFailedMailslotAllocations;
    unsigned long           NumberOfFailedMailslotReceives;
    unsigned long           NumberOfFailedMailslotWrites;
    unsigned long           NumberOfFailedMailslotOpens;
    unsigned long           NumberOfDuplicateMasterAnnouncements;
    LARGE_INTEGER   NumberOfIllegalDatagrams;
} BROWSER_STATISTICS, *PBROWSER_STATISTICS, *LPBROWSER_STATISTICS;

typedef struct _BROWSER_STATISTICS_100 {
    LARGE_INTEGER   StartTime;
    LARGE_INTEGER   NumberOfServerAnnouncements;
    LARGE_INTEGER   NumberOfDomainAnnouncements;
    unsigned long           NumberOfElectionPackets;
    unsigned long           NumberOfMailslotWrites;
    unsigned long           NumberOfGetBrowserServerListRequests;
    LARGE_INTEGER   NumberOfIllegalDatagrams;
} BROWSER_STATISTICS_100, *PBROWSER_STATISTICS_100;

typedef struct _BROWSER_STATISTICS_101 {
    LARGE_INTEGER   StartTime;
    LARGE_INTEGER   NumberOfServerAnnouncements;
    LARGE_INTEGER   NumberOfDomainAnnouncements;
    unsigned long           NumberOfElectionPackets;
    unsigned long           NumberOfMailslotWrites;
    unsigned long           NumberOfGetBrowserServerListRequests;
    LARGE_INTEGER   NumberOfIllegalDatagrams;

    unsigned long           NumberOfMissedServerAnnouncements;
    unsigned long           NumberOfMissedMailslotDatagrams;
    unsigned long           NumberOfMissedGetBrowserServerListRequests;
    unsigned long           NumberOfFailedServerAnnounceAllocations;
    unsigned long           NumberOfFailedMailslotAllocations;
    unsigned long           NumberOfFailedMailslotReceives;
    unsigned long           NumberOfFailedMailslotWrites;
    unsigned long           NumberOfFailedMailslotOpens;
    unsigned long           NumberOfDuplicateMasterAnnouncements;
} BROWSER_STATISTICS_101, *PBROWSER_STATISTICS_101;


typedef struct _BROWSER_EMULATED_DOMAIN {
#ifdef MIDL_PASS
    [string] wchar_t *DomainName;
#else
    LPWSTR DomainName;
#endif // MIDL_PASS
#ifdef MIDL_PASS
    [string] wchar_t *EmulatedServerName;
#else
    LPWSTR EmulatedServerName;
#endif // MIDL_PASS
    unsigned long Role;
} BROWSER_EMULATED_DOMAIN, *PBROWSER_EMULATED_DOMAIN;

//
// Function Prototypes - BROWSER
//

NET_API_STATUS NET_API_FUNCTION
I_BrowserServerEnum (
    IN  const wchar_t*     servername OPTIONAL,
    IN  const wchar_t*     transport OPTIONAL,
    IN  const wchar_t*     clientname OPTIONAL,
    IN  unsigned long       level,
    OUT LPBYTE      *bufptr,
    IN  unsigned long       prefmaxlen,
    OUT LPDWORD     entriesread,
    OUT LPDWORD     totalentries,
    IN  unsigned long       servertype,
    IN  const wchar_t*     domain OPTIONAL,
    IN OUT LPDWORD  resume_handle OPTIONAL
    );

NET_API_STATUS NET_API_FUNCTION
I_BrowserServerEnumEx (
    IN  const wchar_t*     servername OPTIONAL,
    IN  const wchar_t*     transport OPTIONAL,
    IN  const wchar_t*     clientname OPTIONAL,
    IN  unsigned long       level,
    OUT LPBYTE      *bufptr,
    IN  unsigned long       prefmaxlen,
    OUT LPDWORD     entriesread,
    OUT LPDWORD     totalentries,
    IN  unsigned long       servertype,
    IN  const wchar_t*     domain OPTIONAL,
    IN  const wchar_t*     FirstNameToReturn OPTIONAL
    );


NET_API_STATUS
I_BrowserQueryOtherDomains (
    IN  const wchar_t*      servername OPTIONAL,
    OUT LPBYTE      *bufptr,
    OUT LPDWORD     entriesread,
    OUT LPDWORD     totalentries
    );

NET_API_STATUS
I_BrowserResetNetlogonState (
    IN  const wchar_t*      servername OPTIONAL
    );

NET_API_STATUS
I_BrowserSetNetlogonState(
    IN LPWSTR ServerName OPTIONAL,
    IN LPWSTR DomainName,
    IN LPWSTR EmulatedServerName OPTIONAL,
    IN unsigned long Role
    );

#define BROWSER_ROLE_PDC 0x1
#define BROWSER_ROLE_BDC 0x2

NET_API_STATUS
I_BrowserQueryEmulatedDomains(
    IN LPWSTR ServerName OPTIONAL,
    OUT PBROWSER_EMULATED_DOMAIN *EmulatedDomains,
    OUT LPDWORD EntriesRead );

NET_API_STATUS
I_BrowserQueryStatistics (
    IN  const wchar_t*      servername OPTIONAL,
    OUT LPBROWSER_STATISTICS *statistics
    );

NET_API_STATUS
I_BrowserResetStatistics (
    IN  const wchar_t*      servername OPTIONAL
    );


WORD
I_BrowserServerEnumForXactsrv(
    IN const wchar_t* TransportName OPTIONAL,
    IN const wchar_t* ClientName OPTIONAL,

    IN unsigned long NtLevel,
    IN USHORT ClientLevel,

    OUT void* Buffer,
    IN WORD BufferLength,
    IN unsigned long PreferedMaximumLength,

    OUT LPDWORD EntriesRead,
    OUT LPDWORD TotalEntries,

    IN unsigned long ServerType,
    IN const wchar_t* Domain,
    IN const wchar_t* FirstNameToReturn,

    OUT PWORD Converter

    );

#ifdef __cplusplus
}
#endif

#if DBG
NET_API_STATUS
I_BrowserDebugTrace(
    PWCHAR Server,
    PCHAR Buffer
    );

#endif

#endif // _LMBROWSR_
#pragma once 
