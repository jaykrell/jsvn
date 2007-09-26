/*++ BUILD VERSION: 0007    // INCREMENT THIS IF A CHANGE HAS GLOBAL EFFECTS

Copyright (c) 1990-1996  Microsoft Corporation

Module Name:

    lmserver.h

Abstract:

    This file contains information about NetServer APIs.
        Function Prototypes
        Data Structures
        Definition of special values

Environment:

    User Mode - Win32

Notes:

    You must include NETCONS.H before this file, since this file depends
    on values defined in NETCONS.H.

--*/

#ifndef _LMSERVER_
#define _LMSERVER_

#include <winsvc.h>     // SERVICE_STATUS_HANDLE

#ifdef __cplusplus
extern "C" {
#endif

//
// Function Prototypes - SERVER
//

NET_API_STATUS NET_API_FUNCTION
NetServerEnum (
    IN  const wchar_t*     servername OPTIONAL,
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
NetServerEnumEx (
    IN  const wchar_t*     ServerName OPTIONAL,
    IN  unsigned long       Level,
    OUT LPBYTE      *Bufptr,
    IN  unsigned long       PrefMaxlen,
    OUT LPDWORD     EntriesRead,
    OUT LPDWORD     totalentries,
    IN  unsigned long       servertype,
    IN  const wchar_t*     domain OPTIONAL,
    IN  const wchar_t*     FirstNameToReturn OPTIONAL
    );

NET_API_STATUS NET_API_FUNCTION
NetServerGetInfo (
    IN  LPTSTR  servername OPTIONAL,
    IN  unsigned long   level,
    OUT LPBYTE  *bufptr
    );

NET_API_STATUS NET_API_FUNCTION
NetServerSetInfo (
    IN  LPTSTR  servername OPTIONAL,
    IN  unsigned long   level,
    IN  LPBYTE  buf,
    OUT LPDWORD ParmError OPTIONAL
    );

//
// Temporary hack function.
//

NET_API_STATUS
NetServerSetInfoCommandLine (
    IN WORD argc,
    IN LPTSTR argv[]
    );

NET_API_STATUS NET_API_FUNCTION
NetServerDiskEnum (
    IN  LPTSTR      servername OPTIONAL,
    IN  unsigned long       level,
    OUT LPBYTE      *bufptr,
    IN  unsigned long       prefmaxlen,
    OUT LPDWORD     entriesread,
    OUT LPDWORD     totalentries,
    IN OUT LPDWORD  resume_handle OPTIONAL
    );

NET_API_STATUS NET_API_FUNCTION
NetServerComputerNameAdd(
    IN LPWSTR ServerName         OPTIONAL,
    IN LPWSTR EmulatedDomainName OPTIONAL,
    IN LPWSTR EmulatedServerName
);

NET_API_STATUS NET_API_FUNCTION
NetServerComputerNameDel (
    IN LPWSTR ServerName        OPTIONAL,
    IN LPWSTR EmulatedServerName
);

NET_API_STATUS NET_API_FUNCTION
NetServerTransportAdd (
    IN  LPTSTR  servername,
    IN  unsigned long   level,
    IN  LPBYTE  bufptr
    );

NET_API_STATUS NET_API_FUNCTION
NetServerTransportAddEx (
    IN  LPTSTR  servername      OPTIONAL,
    IN  unsigned long   level,
    IN  LPBYTE  bufptr
    );

NET_API_STATUS NET_API_FUNCTION
NetServerTransportDel (
    IN  LPTSTR  servername,
    IN  unsigned long   level,
    IN  LPBYTE  bufptr
    );

NET_API_STATUS NET_API_FUNCTION
NetServerTransportEnum (
    IN  LPTSTR      servername,
    IN  unsigned long       level,
    OUT LPBYTE      *bufptr,
    IN  unsigned long       prefmaxlen,
    OUT LPDWORD     entriesread,
    OUT LPDWORD     totalentries,
    IN OUT LPDWORD  resumehandle
    );

//
// The following function can be called by Win NT services to register
// their service type.  This function is exported from advapi32.dll.
// Therefore, if this is the only function called by that service, then
// it is not necessary to link to netapi32.lib.
//
BOOL
SetServiceBits(
    IN SERVICE_STATUS_HANDLE    hServiceStatus,
    IN unsigned long                    dwServiceBits,
    IN BOOL                     bSetBitsOn,
    IN BOOL                     bUpdateImmediately
    );

//
// Data Structures - SERVER
//

typedef struct _SERVER_INFO_100 {
    unsigned long           sv100_platform_id;
    LPTSTR          sv100_name;
} SERVER_INFO_100, *PSERVER_INFO_100, *LPSERVER_INFO_100;

typedef struct _SERVER_INFO_101 {
    unsigned long           sv101_platform_id;
    LPTSTR          sv101_name;
    unsigned long           sv101_version_major;
    unsigned long           sv101_version_minor;
    unsigned long           sv101_type;
    LPTSTR          sv101_comment;
} SERVER_INFO_101, *PSERVER_INFO_101, *LPSERVER_INFO_101;

typedef struct _SERVER_INFO_102 {
     unsigned long          sv102_platform_id;
     LPTSTR         sv102_name;
     unsigned long          sv102_version_major;
     unsigned long          sv102_version_minor;
     unsigned long          sv102_type;
     LPTSTR         sv102_comment;
     unsigned long          sv102_users;
     long           sv102_disc;
     BOOL           sv102_hidden;
     unsigned long          sv102_announce;
     unsigned long          sv102_anndelta;
     unsigned long          sv102_licenses;
     LPTSTR         sv102_userpath;
} SERVER_INFO_102, *PSERVER_INFO_102, *LPSERVER_INFO_102;

typedef struct _SERVER_INFO_402 {
     unsigned long          sv402_ulist_mtime;
     unsigned long          sv402_glist_mtime;
     unsigned long          sv402_alist_mtime;
     LPTSTR         sv402_alerts;
     unsigned long          sv402_security;
     unsigned long          sv402_numadmin;
     unsigned long          sv402_lanmask;
     LPTSTR         sv402_guestacct;
     unsigned long          sv402_chdevs;
     unsigned long          sv402_chdevq;
     unsigned long          sv402_chdevjobs;
     unsigned long          sv402_connections;
     unsigned long          sv402_shares;
     unsigned long          sv402_openfiles;
     unsigned long          sv402_sessopens;
     unsigned long          sv402_sessvcs;
     unsigned long          sv402_sessreqs;
     unsigned long          sv402_opensearch;
     unsigned long          sv402_activelocks;
     unsigned long          sv402_numreqbuf;
     unsigned long          sv402_sizreqbuf;
     unsigned long          sv402_numbigbuf;
     unsigned long          sv402_numfiletasks;
     unsigned long          sv402_alertsched;
     unsigned long          sv402_erroralert;
     unsigned long          sv402_logonalert;
     unsigned long          sv402_accessalert;
     unsigned long          sv402_diskalert;
     unsigned long          sv402_netioalert;
     unsigned long          sv402_maxauditsz;
     LPTSTR         sv402_srvheuristics;
} SERVER_INFO_402, *PSERVER_INFO_402, *LPSERVER_INFO_402;

typedef struct _SERVER_INFO_403 {
     unsigned long          sv403_ulist_mtime;
     unsigned long          sv403_glist_mtime;
     unsigned long          sv403_alist_mtime;
     LPTSTR         sv403_alerts;
     unsigned long          sv403_security;
     unsigned long          sv403_numadmin;
     unsigned long          sv403_lanmask;
     LPTSTR         sv403_guestacct;
     unsigned long          sv403_chdevs;
     unsigned long          sv403_chdevq;
     unsigned long          sv403_chdevjobs;
     unsigned long          sv403_connections;
     unsigned long          sv403_shares;
     unsigned long          sv403_openfiles;
     unsigned long          sv403_sessopens;
     unsigned long          sv403_sessvcs;
     unsigned long          sv403_sessreqs;
     unsigned long          sv403_opensearch;
     unsigned long          sv403_activelocks;
     unsigned long          sv403_numreqbuf;
     unsigned long          sv403_sizreqbuf;
     unsigned long          sv403_numbigbuf;
     unsigned long          sv403_numfiletasks;
     unsigned long          sv403_alertsched;
     unsigned long          sv403_erroralert;
     unsigned long          sv403_logonalert;
     unsigned long          sv403_accessalert;
     unsigned long          sv403_diskalert;
     unsigned long          sv403_netioalert;
     unsigned long          sv403_maxauditsz;
     LPTSTR         sv403_srvheuristics;
     unsigned long          sv403_auditedevents;
     unsigned long          sv403_autoprofile;
     LPTSTR         sv403_autopath;
} SERVER_INFO_403, *PSERVER_INFO_403, *LPSERVER_INFO_403;

typedef struct _SERVER_INFO_502 {
    unsigned long           sv502_sessopens;
    unsigned long           sv502_sessvcs;
    unsigned long           sv502_opensearch;
    unsigned long           sv502_sizreqbuf;
    unsigned long           sv502_initworkitems;
    unsigned long           sv502_maxworkitems;
    unsigned long           sv502_rawworkitems;
    unsigned long           sv502_irpstacksize;
    unsigned long           sv502_maxrawbuflen;
    unsigned long           sv502_sessusers;
    unsigned long           sv502_sessconns;
    unsigned long           sv502_maxpagedmemoryusage;
    unsigned long           sv502_maxnonpagedmemoryusage;
    BOOL            sv502_enablesoftcompat;
    BOOL            sv502_enableforcedlogoff;
    BOOL            sv502_timesource;
    BOOL            sv502_acceptdownlevelapis;
    BOOL            sv502_lmannounce;
} SERVER_INFO_502, *PSERVER_INFO_502, *LPSERVER_INFO_502;

typedef struct _SERVER_INFO_503 {
    unsigned long           sv503_sessopens;
    unsigned long           sv503_sessvcs;
    unsigned long           sv503_opensearch;
    unsigned long           sv503_sizreqbuf;
    unsigned long           sv503_initworkitems;
    unsigned long           sv503_maxworkitems;
    unsigned long           sv503_rawworkitems;
    unsigned long           sv503_irpstacksize;
    unsigned long           sv503_maxrawbuflen;
    unsigned long           sv503_sessusers;
    unsigned long           sv503_sessconns;
    unsigned long           sv503_maxpagedmemoryusage;
    unsigned long           sv503_maxnonpagedmemoryusage;
    BOOL            sv503_enablesoftcompat;
    BOOL            sv503_enableforcedlogoff;
    BOOL            sv503_timesource;
    BOOL            sv503_acceptdownlevelapis;
    BOOL            sv503_lmannounce;
    LPTSTR          sv503_domain;
    unsigned long           sv503_maxcopyreadlen;
    unsigned long           sv503_maxcopywritelen;
    unsigned long           sv503_minkeepsearch;
    unsigned long           sv503_maxkeepsearch;
    unsigned long           sv503_minkeepcomplsearch;
    unsigned long           sv503_maxkeepcomplsearch;
    unsigned long           sv503_threadcountadd;
    unsigned long           sv503_numblockthreads;
    unsigned long           sv503_scavtimeout;
    unsigned long           sv503_minrcvqueue;
    unsigned long           sv503_minfreeworkitems;
    unsigned long           sv503_xactmemsize;
    unsigned long           sv503_threadpriority;
    unsigned long           sv503_maxmpxct;
    unsigned long           sv503_oplockbreakwait;
    unsigned long           sv503_oplockbreakresponsewait;
    BOOL            sv503_enableoplocks;
    BOOL            sv503_enableoplockforceclose;
    BOOL            sv503_enablefcbopens;
    BOOL            sv503_enableraw;
    BOOL            sv503_enablesharednetdrives;
    unsigned long           sv503_minfreeconnections;
    unsigned long           sv503_maxfreeconnections;
} SERVER_INFO_503, *PSERVER_INFO_503, *LPSERVER_INFO_503;

typedef struct _SERVER_INFO_599 {
    unsigned long           sv599_sessopens;
    unsigned long           sv599_sessvcs;
    unsigned long           sv599_opensearch;
    unsigned long           sv599_sizreqbuf;
    unsigned long           sv599_initworkitems;
    unsigned long           sv599_maxworkitems;
    unsigned long           sv599_rawworkitems;
    unsigned long           sv599_irpstacksize;
    unsigned long           sv599_maxrawbuflen;
    unsigned long           sv599_sessusers;
    unsigned long           sv599_sessconns;
    unsigned long           sv599_maxpagedmemoryusage;
    unsigned long           sv599_maxnonpagedmemoryusage;
    BOOL            sv599_enablesoftcompat;
    BOOL            sv599_enableforcedlogoff;
    BOOL            sv599_timesource;
    BOOL            sv599_acceptdownlevelapis;
    BOOL            sv599_lmannounce;
    LPTSTR          sv599_domain;
    unsigned long           sv599_maxcopyreadlen;
    unsigned long           sv599_maxcopywritelen;
    unsigned long           sv599_minkeepsearch;
    unsigned long           sv599_maxkeepsearch;
    unsigned long           sv599_minkeepcomplsearch;
    unsigned long           sv599_maxkeepcomplsearch;
    unsigned long           sv599_threadcountadd;
    unsigned long           sv599_numblockthreads;
    unsigned long           sv599_scavtimeout;
    unsigned long           sv599_minrcvqueue;
    unsigned long           sv599_minfreeworkitems;
    unsigned long           sv599_xactmemsize;
    unsigned long           sv599_threadpriority;
    unsigned long           sv599_maxmpxct;
    unsigned long           sv599_oplockbreakwait;
    unsigned long           sv599_oplockbreakresponsewait;
    BOOL            sv599_enableoplocks;
    BOOL            sv599_enableoplockforceclose;
    BOOL            sv599_enablefcbopens;
    BOOL            sv599_enableraw;
    BOOL            sv599_enablesharednetdrives;
    unsigned long           sv599_minfreeconnections;
    unsigned long           sv599_maxfreeconnections;
    unsigned long           sv599_initsesstable;
    unsigned long           sv599_initconntable;
    unsigned long           sv599_initfiletable;
    unsigned long           sv599_initsearchtable;
    unsigned long           sv599_alertschedule;
    unsigned long           sv599_errorthreshold;
    unsigned long           sv599_networkerrorthreshold;
    unsigned long           sv599_diskspacethreshold;
    unsigned long           sv599_reserved;
    unsigned long           sv599_maxlinkdelay;
    unsigned long           sv599_minlinkthroughput;
    unsigned long           sv599_linkinfovalidtime;
    unsigned long           sv599_scavqosinfoupdatetime;
    unsigned long           sv599_maxworkitemidletime;
} SERVER_INFO_599, *PSERVER_INFO_599, *LPSERVER_INFO_599;

typedef struct _SERVER_INFO_598 {
    unsigned long           sv598_maxrawworkitems;
    unsigned long           sv598_maxthreadsperqueue;
    unsigned long           sv598_producttype;
    unsigned long           sv598_serversize;
    unsigned long           sv598_connectionlessautodisc;
    unsigned long           sv598_sharingviolationretries;
    unsigned long           sv598_sharingviolationdelay;
    unsigned long           sv598_maxglobalopensearch;
    unsigned long           sv598_removeduplicatesearches;
    unsigned long           sv598_lockviolationoffset;
    unsigned long           sv598_lockviolationdelay;
    unsigned long           sv598_mdlreadswitchover;
    unsigned long           sv598_cachedopenlimit;
    unsigned long           sv598_otherqueueaffinity;
    BOOL            sv598_restrictnullsessaccess;
    BOOL            sv598_enablewfw311directipx;
    unsigned long           sv598_queuesamplesecs;
    unsigned long           sv598_balancecount;
    unsigned long           sv598_preferredaffinity;
    unsigned long           sv598_maxfreerfcbs;
    unsigned long           sv598_maxfreemfcbs;
    unsigned long           sv598_maxfreelfcbs;
    unsigned long           sv598_maxfreepagedpoolchunks;
    unsigned long           sv598_minpagedpoolchunksize;
    unsigned long           sv598_maxpagedpoolchunksize;
    BOOL            sv598_sendsfrompreferredprocessor;
    unsigned long           sv598_cacheddirectorylimit;
    unsigned long           sv598_maxcopylength;
    BOOL            sv598_enablebulktransfer;
    BOOL            sv598_enablecompression;
    BOOL            sv598_autosharewks;
    BOOL            sv598_autoshareserver;
} SERVER_INFO_598, *PSERVER_INFO_598, *LPSERVER_INFO_598;

typedef struct _SERVER_INFO_1005 {
    LPTSTR          sv1005_comment;
} SERVER_INFO_1005, *PSERVER_INFO_1005, *LPSERVER_INFO_1005;

typedef struct _SERVER_INFO_1107 {
    unsigned long           sv1107_users;
} SERVER_INFO_1107, *PSERVER_INFO_1107, *LPSERVER_INFO_1107;

typedef struct _SERVER_INFO_1010 {
    long            sv1010_disc;
} SERVER_INFO_1010, *PSERVER_INFO_1010, *LPSERVER_INFO_1010;

typedef struct _SERVER_INFO_1016 {
    BOOL            sv1016_hidden;
} SERVER_INFO_1016, *PSERVER_INFO_1016, *LPSERVER_INFO_1016;

typedef struct _SERVER_INFO_1017 {
    unsigned long           sv1017_announce;
} SERVER_INFO_1017, *PSERVER_INFO_1017, *LPSERVER_INFO_1017;

typedef struct _SERVER_INFO_1018 {
    unsigned long           sv1018_anndelta;
} SERVER_INFO_1018, *PSERVER_INFO_1018, *LPSERVER_INFO_1018;

typedef struct _SERVER_INFO_1501 {
    unsigned long           sv1501_sessopens;
} SERVER_INFO_1501, *PSERVER_INFO_1501, *LPSERVER_INFO_1501;

typedef struct _SERVER_INFO_1502 {
    unsigned long           sv1502_sessvcs;
} SERVER_INFO_1502, *PSERVER_INFO_1502, *LPSERVER_INFO_1502;

typedef struct _SERVER_INFO_1503 {
    unsigned long           sv1503_opensearch;
} SERVER_INFO_1503, *PSERVER_INFO_1503, *LPSERVER_INFO_1503;

typedef struct _SERVER_INFO_1506 {
    unsigned long           sv1506_maxworkitems;
} SERVER_INFO_1506, *PSERVER_INFO_1506, *LPSERVER_INFO_1506;

typedef struct _SERVER_INFO_1509 {
    unsigned long           sv1509_maxrawbuflen;
} SERVER_INFO_1509, *PSERVER_INFO_1509, *LPSERVER_INFO_1509;

typedef struct _SERVER_INFO_1510 {
    unsigned long           sv1510_sessusers;
} SERVER_INFO_1510, *PSERVER_INFO_1510, *LPSERVER_INFO_1510;

typedef struct _SERVER_INFO_1511 {
    unsigned long           sv1511_sessconns;
} SERVER_INFO_1511, *PSERVER_INFO_1511, *LPSERVER_INFO_1511;

typedef struct _SERVER_INFO_1512 {
    unsigned long           sv1512_maxnonpagedmemoryusage;
} SERVER_INFO_1512, *PSERVER_INFO_1512, *LPSERVER_INFO_1512;

typedef struct _SERVER_INFO_1513 {
    unsigned long           sv1513_maxpagedmemoryusage;
} SERVER_INFO_1513, *PSERVER_INFO_1513, *LPSERVER_INFO_1513;

typedef struct _SERVER_INFO_1514 {
    BOOL            sv1514_enablesoftcompat;
} SERVER_INFO_1514, *PSERVER_INFO_1514, *LPSERVER_INFO_1514;

typedef struct _SERVER_INFO_1515 {
    BOOL            sv1515_enableforcedlogoff;
} SERVER_INFO_1515, *PSERVER_INFO_1515, *LPSERVER_INFO_1515;

typedef struct _SERVER_INFO_1516 {
    BOOL            sv1516_timesource;
} SERVER_INFO_1516, *PSERVER_INFO_1516, *LPSERVER_INFO_1516;

typedef struct _SERVER_INFO_1518 {
    BOOL            sv1518_lmannounce;
} SERVER_INFO_1518, *PSERVER_INFO_1518, *LPSERVER_INFO_1518;

typedef struct _SERVER_INFO_1520 {
    unsigned long           sv1520_maxcopyreadlen;
} SERVER_INFO_1520, *PSERVER_INFO_1520, *LPSERVER_INFO_1520;

typedef struct _SERVER_INFO_1521 {
    unsigned long           sv1521_maxcopywritelen;
} SERVER_INFO_1521, *PSERVER_INFO_1521, *LPSERVER_INFO_1521;

typedef struct _SERVER_INFO_1522 {
    unsigned long           sv1522_minkeepsearch;
} SERVER_INFO_1522, *PSERVER_INFO_1522, *LPSERVER_INFO_1522;

typedef struct _SERVER_INFO_1523 {
    unsigned long           sv1523_maxkeepsearch;
} SERVER_INFO_1523, *PSERVER_INFO_1523, *LPSERVER_INFO_1523;

typedef struct _SERVER_INFO_1524 {
    unsigned long           sv1524_minkeepcomplsearch;
} SERVER_INFO_1524, *PSERVER_INFO_1524, *LPSERVER_INFO_1524;

typedef struct _SERVER_INFO_1525 {
    unsigned long           sv1525_maxkeepcomplsearch;
} SERVER_INFO_1525, *PSERVER_INFO_1525, *LPSERVER_INFO_1525;

typedef struct _SERVER_INFO_1528 {
    unsigned long           sv1528_scavtimeout;
} SERVER_INFO_1528, *PSERVER_INFO_1528, *LPSERVER_INFO_1528;

typedef struct _SERVER_INFO_1529 {
    unsigned long           sv1529_minrcvqueue;
} SERVER_INFO_1529, *PSERVER_INFO_1529, *LPSERVER_INFO_1529;

typedef struct _SERVER_INFO_1530 {
    unsigned long           sv1530_minfreeworkitems;
} SERVER_INFO_1530, *PSERVER_INFO_1530, *LPSERVER_INFO_1530;

typedef struct _SERVER_INFO_1533 {
    unsigned long           sv1533_maxmpxct;
} SERVER_INFO_1533, *PSERVER_INFO_1533, *LPSERVER_INFO_1533;

typedef struct _SERVER_INFO_1534 {
    unsigned long           sv1534_oplockbreakwait;
} SERVER_INFO_1534, *PSERVER_INFO_1534, *LPSERVER_INFO_1534;

typedef struct _SERVER_INFO_1535 {
    unsigned long           sv1535_oplockbreakresponsewait;
} SERVER_INFO_1535, *PSERVER_INFO_1535, *LPSERVER_INFO_1535;

typedef struct _SERVER_INFO_1536 {
    BOOL            sv1536_enableoplocks;
} SERVER_INFO_1536, *PSERVER_INFO_1536, *LPSERVER_INFO_1536;

typedef struct _SERVER_INFO_1537 {
    BOOL            sv1537_enableoplockforceclose;
} SERVER_INFO_1537, *PSERVER_INFO_1537, *LPSERVER_INFO_1537;

typedef struct _SERVER_INFO_1538 {
    BOOL            sv1538_enablefcbopens;
} SERVER_INFO_1538, *PSERVER_INFO_1538, *LPSERVER_INFO_1538;

typedef struct _SERVER_INFO_1539 {
    BOOL            sv1539_enableraw;
} SERVER_INFO_1539, *PSERVER_INFO_1539, *LPSERVER_INFO_1539;

typedef struct _SERVER_INFO_1540 {
    BOOL            sv1540_enablesharednetdrives;
} SERVER_INFO_1540, *PSERVER_INFO_1540, *LPSERVER_INFO_1540;

typedef struct _SERVER_INFO_1541 {
    BOOL            sv1541_minfreeconnections;
} SERVER_INFO_1541, *PSERVER_INFO_1541, *LPSERVER_INFO_1541;

typedef struct _SERVER_INFO_1542 {
    BOOL            sv1542_maxfreeconnections;
} SERVER_INFO_1542, *PSERVER_INFO_1542, *LPSERVER_INFO_1542;

typedef struct _SERVER_INFO_1543 {
    unsigned long           sv1543_initsesstable;
} SERVER_INFO_1543, *PSERVER_INFO_1543, *LPSERVER_INFO_1543;

typedef struct _SERVER_INFO_1544 {
    unsigned long           sv1544_initconntable;
} SERVER_INFO_1544, *PSERVER_INFO_1544, *LPSERVER_INFO_1544;

typedef struct _SERVER_INFO_1545 {
    unsigned long           sv1545_initfiletable;
} SERVER_INFO_1545, *PSERVER_INFO_1545, *LPSERVER_INFO_1545;

typedef struct _SERVER_INFO_1546 {
    unsigned long           sv1546_initsearchtable;
} SERVER_INFO_1546, *PSERVER_INFO_1546, *LPSERVER_INFO_1546;

typedef struct _SERVER_INFO_1547 {
    unsigned long           sv1547_alertschedule;
} SERVER_INFO_1547, *PSERVER_INFO_1547, *LPSERVER_INFO_1547;

typedef struct _SERVER_INFO_1548 {
    unsigned long           sv1548_errorthreshold;
} SERVER_INFO_1548, *PSERVER_INFO_1548, *LPSERVER_INFO_1548;

typedef struct _SERVER_INFO_1549 {
    unsigned long           sv1549_networkerrorthreshold;
} SERVER_INFO_1549, *PSERVER_INFO_1549, *LPSERVER_INFO_1549;

typedef struct _SERVER_INFO_1550 {
    unsigned long           sv1550_diskspacethreshold;
} SERVER_INFO_1550, *PSERVER_INFO_1550, *LPSERVER_INFO_1550;

typedef struct _SERVER_INFO_1552 {
    unsigned long           sv1552_maxlinkdelay;
} SERVER_INFO_1552, *PSERVER_INFO_1552, *LPSERVER_INFO_1552;

typedef struct _SERVER_INFO_1553 {
    unsigned long           sv1553_minlinkthroughput;
} SERVER_INFO_1553, *PSERVER_INFO_1553, *LPSERVER_INFO_1553;

typedef struct _SERVER_INFO_1554 {
    unsigned long           sv1554_linkinfovalidtime;
} SERVER_INFO_1554, *PSERVER_INFO_1554, *LPSERVER_INFO_1554;

typedef struct _SERVER_INFO_1555 {
    unsigned long           sv1555_scavqosinfoupdatetime;
} SERVER_INFO_1555, *PSERVER_INFO_1555, *LPSERVER_INFO_1555;

typedef struct _SERVER_INFO_1556 {
    unsigned long           sv1556_maxworkitemidletime;
} SERVER_INFO_1556, *PSERVER_INFO_1556, *LPSERVER_INFO_1556;

typedef struct _SERVER_INFO_1557 {
    unsigned long           sv1557_maxrawworkitems;
} SERVER_INFO_1557, *PSERVER_INFO_1557, *LPSERVER_INFO_1557;

typedef struct _SERVER_INFO_1560 {
    unsigned long           sv1560_producttype;
} SERVER_INFO_1560, *PSERVER_INFO_1560, *LPSERVER_INFO_1560;

typedef struct _SERVER_INFO_1561 {
    unsigned long           sv1561_serversize;
} SERVER_INFO_1561, *PSERVER_INFO_1561, *LPSERVER_INFO_1561;

typedef struct _SERVER_INFO_1562 {
    unsigned long           sv1562_connectionlessautodisc;
} SERVER_INFO_1562, *PSERVER_INFO_1562, *LPSERVER_INFO_1562;

typedef struct _SERVER_INFO_1563 {
    unsigned long           sv1563_sharingviolationretries;
} SERVER_INFO_1563, *PSERVER_INFO_1563, *LPSERVER_INFO_1563;

typedef struct _SERVER_INFO_1564 {
    unsigned long           sv1564_sharingviolationdelay;
} SERVER_INFO_1564, *PSERVER_INFO_1564, *LPSERVER_INFO_1564;

typedef struct _SERVER_INFO_1565 {
    unsigned long           sv1565_maxglobalopensearch;
} SERVER_INFO_1565, *PSERVER_INFO_1565, *LPSERVER_INFO_1565;

typedef struct _SERVER_INFO_1566 {
    BOOL           sv1566_removeduplicatesearches;
} SERVER_INFO_1566, *PSERVER_INFO_1566, *LPSERVER_INFO_1566;

typedef struct _SERVER_INFO_1567 {
    unsigned long           sv1567_lockviolationretries;
} SERVER_INFO_1567, *PSERVER_INFO_1567, *LPSERVER_INFO_1567;

typedef struct _SERVER_INFO_1568 {
    unsigned long           sv1568_lockviolationoffset;
} SERVER_INFO_1568, *PSERVER_INFO_1568, *LPSERVER_INFO_1568;

typedef struct _SERVER_INFO_1569 {
    unsigned long           sv1569_lockviolationdelay;
} SERVER_INFO_1569, *PSERVER_INFO_1569, *LPSERVER_INFO_1569;

typedef struct _SERVER_INFO_1570 {
    unsigned long           sv1570_mdlreadswitchover;
} SERVER_INFO_1570, *PSERVER_INFO_1570, *LPSERVER_INFO_1570;

typedef struct _SERVER_INFO_1571 {
    unsigned long           sv1571_cachedopenlimit;
} SERVER_INFO_1571, *PSERVER_INFO_1571, *LPSERVER_INFO_1571;

typedef struct _SERVER_INFO_1572 {
    unsigned long           sv1572_criticalthreads;
} SERVER_INFO_1572, *PSERVER_INFO_1572, *LPSERVER_INFO_1572;

typedef struct _SERVER_INFO_1573 {
    unsigned long           sv1573_restrictnullsessaccess;
} SERVER_INFO_1573, *PSERVER_INFO_1573, *LPSERVER_INFO_1573;

typedef struct _SERVER_INFO_1574 {
    unsigned long           sv1574_enablewfw311directipx;
} SERVER_INFO_1574, *PSERVER_INFO_1574, *LPSERVER_INFO_1574;

typedef struct _SERVER_INFO_1575 {
    unsigned long           sv1575_otherqueueaffinity;
} SERVER_INFO_1575, *PSERVER_INFO_1575, *LPSERVER_INFO_1575;

typedef struct _SERVER_INFO_1576 {
    unsigned long           sv1576_queuesamplesecs;
} SERVER_INFO_1576, *PSERVER_INFO_1576, *LPSERVER_INFO_1576;

typedef struct _SERVER_INFO_1577 {
    unsigned long           sv1577_balancecount;
} SERVER_INFO_1577, *PSERVER_INFO_1577, *LPSERVER_INFO_1577;

typedef struct _SERVER_INFO_1578 {
    unsigned long           sv1578_preferredaffinity;
} SERVER_INFO_1578, *PSERVER_INFO_1578, *LPSERVER_INFO_1578;

typedef struct _SERVER_INFO_1579 {
    unsigned long           sv1579_maxfreerfcbs;
} SERVER_INFO_1579, *PSERVER_INFO_1579, *LPSERVER_INFO_1579;

typedef struct _SERVER_INFO_1580 {
    unsigned long           sv1580_maxfreemfcbs;
} SERVER_INFO_1580, *PSERVER_INFO_1580, *LPSERVER_INFO_1580;

typedef struct _SERVER_INFO_1581 {
    unsigned long           sv1581_maxfreemlcbs;
} SERVER_INFO_1581, *PSERVER_INFO_1581, *LPSERVER_INFO_1581;

typedef struct _SERVER_INFO_1582 {
    unsigned long           sv1582_maxfreepagedpoolchunks;
} SERVER_INFO_1582, *PSERVER_INFO_1582, *LPSERVER_INFO_1582;

typedef struct _SERVER_INFO_1583 {
    unsigned long           sv1583_minpagedpoolchunksize;
} SERVER_INFO_1583, *PSERVER_INFO_1583, *LPSERVER_INFO_1583;

typedef struct _SERVER_INFO_1584 {
    unsigned long           sv1584_maxpagedpoolchunksize;
} SERVER_INFO_1584, *PSERVER_INFO_1584, *LPSERVER_INFO_1584;

typedef struct _SERVER_INFO_1585 {
    BOOL           sv1585_sendsfrompreferredprocessor;
} SERVER_INFO_1585, *PSERVER_INFO_1585, *LPSERVER_INFO_1585;

typedef struct _SERVER_INFO_1586 {
    unsigned long          sv1586_maxthreadsperqueue;
} SERVER_INFO_1586, *PSERVER_INFO_1586, *LPSERVER_INFO_1586;

typedef struct _SERVER_INFO_1587 {
    unsigned long          sv1587_cacheddirectorylimit;
} SERVER_INFO_1587, *PSERVER_INFO_1587, *LPSERVER_INFO_1587;

typedef struct _SERVER_INFO_1588 {
    unsigned long          sv1588_maxcopylength;
} SERVER_INFO_1588, *PSERVER_INFO_1588, *LPSERVER_INFO_1588;

typedef struct _SERVER_INFO_1589 {
    unsigned long          sv1589_enablebulktransfer;
} SERVER_INFO_1589, *PSERVER_INFO_1589, *LPSERVER_INFO_1589;

typedef struct _SERVER_INFO_1590 {
    unsigned long          sv1590_enablecompression;
} SERVER_INFO_1590, *PSERVER_INFO_1590, *LPSERVER_INFO_1590;

typedef struct _SERVER_INFO_1591 {
    unsigned long          sv1591_autosharewks;
} SERVER_INFO_1591, *PSERVER_INFO_1591, *LPSERVER_INFO_1591;

typedef struct _SERVER_INFO_1592 {
    unsigned long          sv1592_autosharewks;
} SERVER_INFO_1592, *PSERVER_INFO_1592, *LPSERVER_INFO_1592;

//
// A special structure definition is required in order for this
// structure to work with RPC.  The problem is that having addresslength
// indicate the number of bytes in address means that RPC must know the
// link between the two.
//

#ifdef MIDL_PASS

typedef struct _SERVER_TRANSPORT_INFO_0 {
    unsigned long           svti0_numberofvcs;
    LPTSTR          svti0_transportname;
    [size_is(svti0_transportaddresslength)]  LPBYTE svti0_transportaddress;
    unsigned long           svti0_transportaddresslength;
    LPTSTR          svti0_networkaddress;
} SERVER_TRANSPORT_INFO_0, *PSERVER_TRANSPORT_INFO_0, *LPSERVER_TRANSPORT_INFO_0;

typedef struct _SERVER_TRANSPORT_INFO_1 {
    unsigned long           svti1_numberofvcs;
    LPTSTR          svti1_transportname;
    [size_is(svti1_transportaddresslength)]  LPBYTE svti1_transportaddress;
    unsigned long           svti1_transportaddresslength;
    LPTSTR          svti1_networkaddress;
    LPTSTR          svti1_domain;
} SERVER_TRANSPORT_INFO_1, *PSERVER_TRANSPORT_INFO_1, *LPSERVER_TRANSPORT_INFO_1;

#else

typedef struct _SERVER_TRANSPORT_INFO_0 {
    unsigned long           svti0_numberofvcs;
    LPTSTR          svti0_transportname;
    LPBYTE          svti0_transportaddress;
    unsigned long           svti0_transportaddresslength;
    LPTSTR          svti0_networkaddress;
} SERVER_TRANSPORT_INFO_0, *PSERVER_TRANSPORT_INFO_0, *LPSERVER_TRANSPORT_INFO_0;

typedef struct _SERVER_TRANSPORT_INFO_1 {
    unsigned long           svti1_numberofvcs;
    LPTSTR          svti1_transportname;
    LPBYTE          svti1_transportaddress;
    unsigned long           svti1_transportaddresslength;
    LPTSTR          svti1_networkaddress;
    LPTSTR          svti1_domain;
} SERVER_TRANSPORT_INFO_1, *PSERVER_TRANSPORT_INFO_1, *LPSERVER_TRANSPORT_INFO_1;

#endif

//
// Defines - SERVER
//

//
// The platform ID indicates the levels to use for platform-specific
// information.
//

#define SV_PLATFORM_ID_OS2 400
#define SV_PLATFORM_ID_NT  500

//
//      Mask to be applied to svX_version_major in order to obtain
//      the major version number.
//

#define MAJOR_VERSION_MASK  0x0F

//
//      Bit-mapped values for svX_type fields. X = 1, 2 or 3.
//

#define SV_TYPE_WORKSTATION         0x00000001
#define SV_TYPE_SERVER              0x00000002
#define SV_TYPE_SQLSERVER           0x00000004
#define SV_TYPE_DOMAIN_CTRL         0x00000008
#define SV_TYPE_DOMAIN_BAKCTRL      0x00000010
#define SV_TYPE_TIME_SOURCE         0x00000020
#define SV_TYPE_AFP                 0x00000040
#define SV_TYPE_NOVELL              0x00000080
#define SV_TYPE_DOMAIN_MEMBER       0x00000100
#define SV_TYPE_PRINTQ_SERVER       0x00000200
#define SV_TYPE_DIALIN_SERVER       0x00000400
#define SV_TYPE_XENIX_SERVER        0x00000800
#define SV_TYPE_SERVER_UNIX         SV_TYPE_XENIX_SERVER
#define SV_TYPE_NT                  0x00001000
#define SV_TYPE_WFW                 0x00002000
#define SV_TYPE_SERVER_MFPN         0x00004000
#define SV_TYPE_SERVER_NT           0x00008000
#define SV_TYPE_POTENTIAL_BROWSER   0x00010000
#define SV_TYPE_BACKUP_BROWSER      0x00020000
#define SV_TYPE_MASTER_BROWSER      0x00040000
#define SV_TYPE_DOMAIN_MASTER       0x00080000
#define SV_TYPE_SERVER_OSF          0x00100000
#define SV_TYPE_SERVER_VMS          0x00200000
#define SV_TYPE_WINDOWS             0x00400000  /* Windows95 and above */
#define SV_TYPE_DFS                 0x00800000  /* Root of a DFS tree */
#define SV_TYPE_ALTERNATE_XPORT     0x20000000  /* return list for alternate transport */
#define SV_TYPE_LOCAL_LIST_ONLY     0x40000000  /* Return local list only */
#define SV_TYPE_DOMAIN_ENUM         0x80000000
#define SV_TYPE_ALL                 0xFFFFFFFF  /* handy for NetServerEnum2 */

//
//      Special value for sv102_disc that specifies infinite disconnect
//      time.
//

#define SV_NODISC           (-1L)  /* No autodisconnect timeout enforced */

//
//      Values of svX_security field. X = 2 or 3.
//

#define SV_USERSECURITY     1
#define SV_SHARESECURITY    0

//
//      Values of svX_hidden field. X = 2 or 3.
//

#define SV_HIDDEN       1
#define SV_VISIBLE      0

//
//      Values for ParmError parameter to NetServerSetInfo.
//

#define SV_PLATFORM_ID_PARMNUM          101
#define SV_NAME_PARMNUM                 102
#define SV_VERSION_MAJOR_PARMNUM        103
#define SV_VERSION_MINOR_PARMNUM        104
#define SV_TYPE_PARMNUM                 105
#define SV_COMMENT_PARMNUM              5
#define SV_USERS_PARMNUM                107
#define SV_DISC_PARMNUM                 10
#define SV_HIDDEN_PARMNUM               16
#define SV_ANNOUNCE_PARMNUM             17
#define SV_ANNDELTA_PARMNUM             18
#define SV_USERPATH_PARMNUM             112

#define SV_ULIST_MTIME_PARMNUM          401
#define SV_GLIST_MTIME_PARMNUM          402
#define SV_ALIST_MTIME_PARMNUM          403
#define SV_ALERTS_PARMNUM               11
#define SV_SECURITY_PARMNUM             405
#define SV_NUMADMIN_PARMNUM             406
#define SV_LANMASK_PARMNUM              407
#define SV_GUESTACC_PARMNUM             408
#define SV_CHDEVQ_PARMNUM               410
#define SV_CHDEVJOBS_PARMNUM            411
#define SV_CONNECTIONS_PARMNUM          412
#define SV_SHARES_PARMNUM               413
#define SV_OPENFILES_PARMNUM            414
#define SV_SESSREQS_PARMNUM             417
#define SV_ACTIVELOCKS_PARMNUM          419
#define SV_NUMREQBUF_PARMNUM            420
#define SV_NUMBIGBUF_PARMNUM            422
#define SV_NUMFILETASKS_PARMNUM         423
#define SV_ALERTSCHED_PARMNUM           37
#define SV_ERRORALERT_PARMNUM           38
#define SV_LOGONALERT_PARMNUM           39
#define SV_ACCESSALERT_PARMNUM          40
#define SV_DISKALERT_PARMNUM            41
#define SV_NETIOALERT_PARMNUM           42
#define SV_MAXAUDITSZ_PARMNUM           43
#define SV_SRVHEURISTICS_PARMNUM        431

#define SV_SESSOPENS_PARMNUM                501
#define SV_SESSVCS_PARMNUM                  502
#define SV_OPENSEARCH_PARMNUM               503
#define SV_SIZREQBUF_PARMNUM                504
#define SV_INITWORKITEMS_PARMNUM            505
#define SV_MAXWORKITEMS_PARMNUM             506
#define SV_RAWWORKITEMS_PARMNUM             507
#define SV_IRPSTACKSIZE_PARMNUM             508
#define SV_MAXRAWBUFLEN_PARMNUM             509
#define SV_SESSUSERS_PARMNUM                510
#define SV_SESSCONNS_PARMNUM                511
#define SV_MAXNONPAGEDMEMORYUSAGE_PARMNUM   512
#define SV_MAXPAGEDMEMORYUSAGE_PARMNUM      513
#define SV_ENABLESOFTCOMPAT_PARMNUM         514
#define SV_ENABLEFORCEDLOGOFF_PARMNUM       515
#define SV_TIMESOURCE_PARMNUM               516
#define SV_ACCEPTDOWNLEVELAPIS_PARMNUM      517
#define SV_LMANNOUNCE_PARMNUM               518
#define SV_DOMAIN_PARMNUM                   519
#define SV_MAXCOPYREADLEN_PARMNUM           520
#define SV_MAXCOPYWRITELEN_PARMNUM          521
#define SV_MINKEEPSEARCH_PARMNUM            522
#define SV_MAXKEEPSEARCH_PARMNUM            523
#define SV_MINKEEPCOMPLSEARCH_PARMNUM       524
#define SV_MAXKEEPCOMPLSEARCH_PARMNUM       525
#define SV_THREADCOUNTADD_PARMNUM           526
#define SV_NUMBLOCKTHREADS_PARMNUM          527
#define SV_SCAVTIMEOUT_PARMNUM              528
#define SV_MINRCVQUEUE_PARMNUM              529
#define SV_MINFREEWORKITEMS_PARMNUM         530
#define SV_XACTMEMSIZE_PARMNUM              531
#define SV_THREADPRIORITY_PARMNUM           532
#define SV_MAXMPXCT_PARMNUM                 533
#define SV_OPLOCKBREAKWAIT_PARMNUM          534
#define SV_OPLOCKBREAKRESPONSEWAIT_PARMNUM  535
#define SV_ENABLEOPLOCKS_PARMNUM            536
#define SV_ENABLEOPLOCKFORCECLOSE_PARMNUM   537
#define SV_ENABLEFCBOPENS_PARMNUM           538
#define SV_ENABLERAW_PARMNUM                539
#define SV_ENABLESHAREDNETDRIVES_PARMNUM    540
#define SV_MINFREECONNECTIONS_PARMNUM       541
#define SV_MAXFREECONNECTIONS_PARMNUM       542
#define SV_INITSESSTABLE_PARMNUM            543
#define SV_INITCONNTABLE_PARMNUM            544
#define SV_INITFILETABLE_PARMNUM            545
#define SV_INITSEARCHTABLE_PARMNUM          546
#define SV_ALERTSCHEDULE_PARMNUM            547
#define SV_ERRORTHRESHOLD_PARMNUM           548
#define SV_NETWORKERRORTHRESHOLD_PARMNUM    549
#define SV_DISKSPACETHRESHOLD_PARMNUM       550
#define SV_MAXLINKDELAY_PARMNUM             552
#define SV_MINLINKTHROUGHPUT_PARMNUM        553
#define SV_LINKINFOVALIDTIME_PARMNUM        554
#define SV_SCAVQOSINFOUPDATETIME_PARMNUM    555
#define SV_MAXWORKITEMIDLETIME_PARMNUM      556
#define SV_MAXRAWWORKITEMS_PARMNUM          557
#define SV_PRODUCTTYPE_PARMNUM              560
#define SV_SERVERSIZE_PARMNUM               561
#define SV_CONNECTIONLESSAUTODISC_PARMNUM   562
#define SV_SHARINGVIOLATIONRETRIES_PARMNUM  563
#define SV_SHARINGVIOLATIONDELAY_PARMNUM    564
#define SV_MAXGLOBALOPENSEARCH_PARMNUM      565
#define SV_REMOVEDUPLICATESEARCHES_PARMNUM  566
#define SV_LOCKVIOLATIONRETRIES_PARMNUM     567
#define SV_LOCKVIOLATIONOFFSET_PARMNUM      568
#define SV_LOCKVIOLATIONDELAY_PARMNUM       569
#define SV_MDLREADSWITCHOVER_PARMNUM        570
#define SV_CACHEDOPENLIMIT_PARMNUM          571
#define SV_CRITICALTHREADS_PARMNUM          572
#define SV_RESTRICTNULLSESSACCESS_PARMNUM   573
#define SV_ENABLEWFW311DIRECTIPX_PARMNUM    574
#define SV_OTHERQUEUEAFFINITY_PARMNUM       575
#define SV_QUEUESAMPLESECS_PARMNUM          576
#define SV_BALANCECOUNT_PARMNUM             577
#define SV_PREFERREDAFFINITY_PARMNUM        578
#define SV_MAXFREERFCBS_PARMNUM             579
#define SV_MAXFREEMFCBS_PARMNUM             580
#define SV_MAXFREELFCBS_PARMNUM             581
#define SV_MAXFREEPAGEDPOOLCHUNKS_PARMNUM   582
#define SV_MINPAGEDPOOLCHUNKSIZE_PARMNUM    583
#define SV_MAXPAGEDPOOLCHUNKSIZE_PARMNUM    584
#define SV_SENDSFROMPREFERREDPROCESSOR_PARMNUM    585
#define SV_MAXTHREADSPERQUEUE_PARMNUM       586
#define SV_CACHEDDIRECTORYLIMIT_PARMNUM     587
#define SV_MAXCOPYLENGTH_PARMNUM            588
#define SV_ENABLEBULKTRANSFER_PARMNUM       589
#define SV_ENABLECOMPRESSION_PARMNUM        590
#define SV_AUTOSHAREWKS_PARMNUM             591
#define SV_AUTOSHARESERVER_PARMNUM          592

//
// Single-field infolevels for NetServerSetInfo.
//

#define SV_COMMENT_INFOLEVEL                    \
            (PARMNUM_BASE_INFOLEVEL + SV_COMMENT_PARMNUM)
#define SV_USERS_INFOLEVEL                      \
            (PARMNUM_BASE_INFOLEVEL + SV_USERS_PARMNUM)
#define SV_DISC_INFOLEVEL                       \
            (PARMNUM_BASE_INFOLEVEL + SV_DISC_PARMNUM)
#define SV_HIDDEN_INFOLEVEL                     \
            (PARMNUM_BASE_INFOLEVEL + SV_HIDDEN_PARMNUM)
#define SV_ANNOUNCE_INFOLEVEL                   \
            (PARMNUM_BASE_INFOLEVEL + SV_ANNOUNCE_PARMNUM)
#define SV_ANNDELTA_INFOLEVEL                   \
            (PARMNUM_BASE_INFOLEVEL + SV_ANNDELTA_PARMNUM)
#define SV_SESSOPENS_INFOLEVEL                  \
            (PARMNUM_BASE_INFOLEVEL + SV_SESSOPENS_PARMNUM)
#define SV_SESSVCS_INFOLEVEL                    \
            (PARMNUM_BASE_INFOLEVEL + SV_SESSVCS_PARMNUM)
#define SV_OPENSEARCH_INFOLEVEL                 \
            (PARMNUM_BASE_INFOLEVEL + SV_OPENSEARCH_PARMNUM)
#define SV_MAXWORKITEMS_INFOLEVEL               \
            (PARMNUM_BASE_INFOLEVEL + SV_MAXWORKITEMS_PARMNUM)
#define SV_MAXRAWBUFLEN_INFOLEVEL               \
            (PARMNUM_BASE_INFOLEVEL + SV_MAXRAWBUFLEN_PARMNUM)
#define SV_SESSUSERS_INFOLEVEL                  \
            (PARMNUM_BASE_INFOLEVEL + SV_SESSUSERS_PARMNUM)
#define SV_SESSCONNS_INFOLEVEL                  \
            (PARMNUM_BASE_INFOLEVEL + SV_SESSCONNS_PARMNUM)
#define SV_MAXNONPAGEDMEMORYUSAGE_INFOLEVEL     \
            (PARMNUM_BASE_INFOLEVEL + SV_MAXNONPAGEDMEMORYUSAGE_PARMNUM)
#define SV_MAXPAGEDMEMORYUSAGE_INFOLEVEL        \
            (PARMNUM_BASE_INFOLEVEL + SV_MAXPAGEDMEMORYUSAGE_PARMNUM)
#define SV_ENABLESOFTCOMPAT_INFOLEVEL           \
            (PARMNUM_BASE_INFOLEVEL + SV_ENABLESOFTCOMPAT_PARMNUM)
#define SV_ENABLEFORCEDLOGOFF_INFOLEVEL         \
            (PARMNUM_BASE_INFOLEVEL + SV_ENABLEFORCEDLOGOFF_PARMNUM)
#define SV_TIMESOURCE_INFOLEVEL                 \
            (PARMNUM_BASE_INFOLEVEL + SV_TIMESOURCE_PARMNUM)
#define SV_LMANNOUNCE_INFOLEVEL                 \
            (PARMNUM_BASE_INFOLEVEL + SV_LMANNOUNCE_PARMNUM)
#define SV_MAXCOPYREADLEN_INFOLEVEL             \
            (PARMNUM_BASE_INFOLEVEL + SV_MAXCOPYREADLEN_PARMNUM)
#define SV_MAXCOPYWRITELEN_INFOLEVEL            \
            (PARMNUM_BASE_INFOLEVEL + SV_MAXCOPYWRITELEN_PARMNUM)
#define SV_MINKEEPSEARCH_INFOLEVEL              \
            (PARMNUM_BASE_INFOLEVEL + SV_MINKEEPSEARCH_PARMNUM)
#define SV_MAXKEEPSEARCH_INFOLEVEL              \
            (PARMNUM_BASE_INFOLEVEL + SV_MAXKEEPSEARCH_PARMNUM)
#define SV_MINKEEPCOMPLSEARCH_INFOLEVEL         \
            (PARMNUM_BASE_INFOLEVEL + SV_MINKEEPCOMPLSEARCH_PARMNUM)
#define SV_MAXKEEPCOMPLSEARCH_INFOLEVEL         \
            (PARMNUM_BASE_INFOLEVEL + SV_MAXKEEPCOMPLSEARCH_PARMNUM)
#define SV_SCAVTIMEOUT_INFOLEVEL                \
            (PARMNUM_BASE_INFOLEVEL + SV_SCAVTIMEOUT_PARMNUM)
#define SV_MINRCVQUEUE_INFOLEVEL                \
            (PARMNUM_BASE_INFOLEVEL + SV_MINRCVQUEUE_PARMNUM)
#define SV_MINFREEWORKITEMS_INFOLEVEL           \
            (PARMNUM_BASE_INFOLEVEL + SV_MINFREEWORKITEMS_PARMNUM)
#define SV_MAXMPXCT_INFOLEVEL                   \
            (PARMNUM_BASE_INFOLEVEL + SV_MAXMPXCT_PARMNUM)
#define SV_OPLOCKBREAKWAIT_INFOLEVEL            \
            (PARMNUM_BASE_INFOLEVEL + SV_OPLOCKBREAKWAIT_PARMNUM)
#define SV_OPLOCKBREAKRESPONSEWAIT_INFOLEVEL    \
            (PARMNUM_BASE_INFOLEVEL + SV_OPLOCKBREAKRESPONSEWAIT_PARMNUM)
#define SV_ENABLEOPLOCKS_INFOLEVEL              \
            (PARMNUM_BASE_INFOLEVEL + SV_ENABLEOPLOCKS_PARMNUM)
#define SV_ENABLEOPLOCKFORCECLOSE_INFOLEVEL     \
            (PARMNUM_BASE_INFOLEVEL + SV_ENABLEOPLOCKFORCECLOSE_PARMNUM)
#define SV_ENABLEFCBOPENS_INFOLEVEL             \
            (PARMNUM_BASE_INFOLEVEL + SV_ENABLEFCBOPENS_PARMNUM)
#define SV_ENABLERAW_INFOLEVEL                  \
            (PARMNUM_BASE_INFOLEVEL + SV_ENABLERAW_PARMNUM)
#define SV_ENABLESHAREDNETDRIVES_INFOLEVEL      \
            (PARMNUM_BASE_INFOLEVEL + SV_ENABLESHAREDNETDRIVES_PARMNUM)
#define SV_MINFREECONNECTIONS_INFOLEVEL         \
            (PARMNUM_BASE_INFOLEVEL + SV_MINFREECONNECTIONS_PARMNUM)
#define SV_MAXFREECONNECTIONS_INFOLEVEL         \
            (PARMNUM_BASE_INFOLEVEL + SV_MAXFREECONNECTIONS_PARMNUM)
#define SV_INITSESSTABLE_INFOLEVEL              \
            (PARMNUM_BASE_INFOLEVEL + SV_INITSESSTABLE_PARMNUM)
#define SV_INITCONNTABLE_INFOLEVEL              \
            (PARMNUM_BASE_INFOLEVEL + SV_INITCONNTABLE_PARMNUM)
#define SV_INITFILETABLE_INFOLEVEL              \
            (PARMNUM_BASE_INFOLEVEL + SV_INITFILETABLE_PARMNUM)
#define SV_INITSEARCHTABLE_INFOLEVEL            \
            (PARMNUM_BASE_INFOLEVEL + SV_INITSEARCHTABLE_PARMNUM)
#define SV_ALERTSCHEDULE_INFOLEVEL              \
            (PARMNUM_BASE_INFOLEVEL + SV_ALERTSCHEDULE_PARMNUM)
#define SV_ERRORTHRESHOLD_INFOLEVEL             \
            (PARMNUM_BASE_INFOLEVEL + SV_ERRORTHRESHOLD_PARMNUM)
#define SV_NETWORKERRORTHRESHOLD_INFOLEVEL      \
            (PARMNUM_BASE_INFOLEVEL + SV_NETWORKERRORTHRESHOLD_PARMNUM)
#define SV_DISKSPACETHRESHOLD_INFOLEVEL         \
            (PARMNUM_BASE_INFOLEVEL + SV_DISKSPACETHRESHOLD_PARMNUM)
#define SV_MAXLINKDELAY_INFOLEVEL               \
            (PARMNUM_BASE_INFOLEVEL + SV_MAXLINKDELAY_PARMNUM)
#define SV_MINLINKTHROUGHPUT_INFOLEVEL          \
            (PARMNUM_BASE_INFOLEVEL + SV_MINLINKTHROUGHPUT_PARMNUM)
#define SV_LINKINFOVALIDTIME_INFOLEVEL          \
            (PARMNUM_BASE_INFOLEVEL + SV_LINKINFOVALIDTIME_PARMNUM)
#define SV_SCAVQOSINFOUPDATETIME_INFOLEVEL      \
            (PARMNUM_BASE_INFOLEVEL + SV_SCAVQOSINFOUPDATETIME_PARMNUM)
#define SV_MAXWORKITEMIDLETIME_INFOLEVEL        \
            (PARMNUM_BASE_INFOLEVEL + SV_MAXWORKITEMIDLETIME_PARMNUM)
#define SV_MAXRAWWORKITEMS_INFOLOEVEL           \
            (PARMNUM_BASE_INFOLEVEL + SV_MAXRAWWORKITEMS_PARMNUM)
#define SV_PRODUCTTYPE_INFOLOEVEL                \
            (PARMNUM_BASE_INFOLEVEL + SV_PRODUCTTYPE_PARMNUM)
#define SV_SERVERSIZE_INFOLOEVEL                \
            (PARMNUM_BASE_INFOLEVEL + SV_SERVERSIZE_PARMNUM)
#define SV_CONNECTIONLESSAUTODISC_INFOLOEVEL    \
            (PARMNUM_BASE_INFOLEVEL + SV_CONNECTIONLESSAUTODISC_PARMNUM)
#define SV_SHARINGVIOLATIONRETRIES_INFOLOEVEL   \
            (PARMNUM_BASE_INFOLEVEL + SV_SHARINGVIOLATIONRETRIES_PARMNUM)
#define SV_SHARINGVIOLATIONDELAY_INFOLOEVEL     \
            (PARMNUM_BASE_INFOLEVEL + SV_SHARINGVIOLATIONDELAY_PARMNUM)
#define SV_MAXGLOBALOPENSEARCH_INFOLOEVEL       \
            (PARMNUM_BASE_INFOLEVEL + SV_MAXGLOBALOPENSEARCH_PARMNUM)
#define SV_REMOVEDUPLICATESEARCHES_INFOLOEVEL       \
            (PARMNUM_BASE_INFOLEVEL + SV_REMOVEDUPLICATESEARCHES_PARMNUM)
#define SV_LOCKVIOLATIONRETRIES_INFOLOEVEL   \
            (PARMNUM_BASE_INFOLEVEL + SV_LOCKVIOLATIONRETRIES_PARMNUM)
#define SV_LOCKVIOLATIONOFFSET_INFOLOEVEL     \
            (PARMNUM_BASE_INFOLEVEL + SV_LOCKVIOLATIONOFFSET_PARMNUM)
#define SV_LOCKVIOLATIONDELAY_INFOLOEVEL     \
            (PARMNUM_BASE_INFOLEVEL + SV_LOCKVIOLATIONDELAY_PARMNUM)
#define SV_MDLREADSWITCHOVER_INFOLOEVEL     \
            (PARMNUM_BASE_INFOLEVEL + SV_MDLREADSWITCHOVER_PARMNUM)
#define SV_CACHEDOPENLIMIT_INFOLOEVEL     \
            (PARMNUM_BASE_INFOLEVEL + SV_CACHEDOPENLIMIT_PARMNUM)
#define SV_CRITICALTHREADS_INFOLOEVEL       \
            (PARMNUM_BASE_INFOLEVEL + SV_CRITICALTHREADS_PARMNUM)
#define SV_RESTRICTNULLSESSACCESS_INFOLOEVEL       \
            (PARMNUM_BASE_INFOLEVEL + SV_RESTRICTNULLSESSACCESS_PARMNUM)
#define SV_ENABLEWFW311DIRECTIPX_INFOLOEVEL       \
            (PARMNUM_BASE_INFOLEVEL + SV_ENABLEWFW311DIRECTIPX_PARMNUM)
#define SV_OTHERQUEUEAFFINITY_INFOLEVEL     \
            (PARMNUM_BASE_INFOLEVEL + SV_OTHERQUEUEAFFINITY_PARMNUM)
#define SV_QUEUESAMPLESECS_INFOLEVEL     \
            (PARMNUM_BASE_INFOLEVEL + SV_QUEUESAMPLESECS_PARMNUM)
#define SV_BALANCECOUNT_INFOLEVEL     \
            (PARMNUM_BASE_INFOLEVEL + SV_BALANCECOUNT_PARMNUM)
#define SV_PREFERREDAFFINITY_INFOLEVEL     \
            (PARMNUM_BASE_INFOLEVEL + SV_PREFERREDAFFINITY_PARMNUM)
#define SV_MAXFREERFCBS_INFOLEVEL     \
            (PARMNUM_BASE_INFOLEVEL + SV_MAXFREERFCBS_PARMNUM)
#define SV_MAXFREEMFCBS_INFOLEVEL     \
            (PARMNUM_BASE_INFOLEVEL + SV_MAXFREEMFCBS_PARMNUM)
#define SV_MAXFREELFCBS_INFOLEVEL     \
            (PARMNUM_BASE_INFOLEVEL + SV_MAXFREELFCBS_PARMNUM)
#define SV_MAXFREEPAGEDPOOLCHUNKS_INFOLEVEL     \
            (PARMNUM_BASE_INFOLEVEL + SV_MAXFREEPAGEDPOOLCHUNKS_PARMNUM)
#define SV_MINPAGEDPOOLCHUNKSIZE_INFOLEVEL     \
            (PARMNUM_BASE_INFOLEVEL + SV_MINPAGEDPOOLCHUNKSIZE_PARMNUM)
#define SV_MAXPAGEDPOOLCHUNKSIZE_INFOLEVEL     \
            (PARMNUM_BASE_INFOLEVEL + SV_MAXPAGEDPOOLCHUNKSIZE_PARMNUM)
#define SV_SENDSFROMPREFERREDPROCESSOR_INFOLEVEL     \
            (PARMNUM_BASE_INFOLEVEL + SV_SENDSFROMPREFERREDPROCESSOR_PARMNUM)
#define SV_MAXTHREADSPERQUEUE_INFOLEVEL     \
            (PARMNUM_BASE_INFOLEVEL + SV_MAXTHREADSPERQUEUE_PARMNUM)
#define SV_CACHEDDIRECTORYLIMIT_INFOLEVEL     \
            (PARMNUM_BASE_INFOLEVEL + SV_CACHEDDIRECTORYLIMIT_PARMNUM)
#define SV_MAXCOPYLENGTH_INFOLEVEL     \
            (PARMNUM_BASE_INFOLEVEL + SV_MAXCOPYLENGTH_PARMNUM)
#define SV_ENABLEBULKTRANSFER_INFOLEVEL     \
            (PARMNUM_BASE_INFOLEVEL + SV_ENABLEBULKTRANSFER_PARMNUM)
#define SV_ENABLECOMPRESSION_INFOLEVEL     \
            (PARMNUM_BASE_INFOLEVEL + SV_ENABLECOMPRESSION_PARMNUM)
#define SV_AUTOSHAREWKS_INFOLEVEL     \
            (PARMNUM_BASE_INFOLEVEL + SV_AUTOSHAREWKS_PARMNUM)
#define SV_AUTOSHARESERVER_INFOLEVEL     \
            (PARMNUM_BASE_INFOLEVEL + SV_AUTOSHARESERVER_PARMNUM)

#define SVI1_NUM_ELEMENTS       5
#define SVI2_NUM_ELEMENTS       40
#define SVI3_NUM_ELEMENTS       44

//
//      Maxmimum length for command string to NetServerAdminCommand.
//

#define SV_MAX_CMD_LEN          PATHLEN

//
//      Masks describing AUTOPROFILE parameters
//

#define SW_AUTOPROF_LOAD_MASK   0x1
#define SW_AUTOPROF_SAVE_MASK   0x2

//
//      Max size of svX_srvheuristics.
//

#define SV_MAX_SRV_HEUR_LEN     32      // Max heuristics info string length.

//
//      Equate for use with sv102_licenses.
//

#define SV_USERS_PER_LICENSE    5

#ifdef __cplusplus
}
#endif

#endif // _LMSERVER_

#pragma once 
