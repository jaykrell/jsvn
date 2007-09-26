/*++ BUILD Version: 0006    // Increment this if a change has global effects

Copyright (c) 1991-1996  Microsoft Corporation

Module Name:

    lmwksta.h

Abstract:

    This file contains structures, function prototypes, and definitions
    for the NetWorkstation and NetWkstaTransport API.

Environment:

    User Mode - Win32
    Portable to any flat, 32-bit environment.  (Uses Win32 typedefs.)
    Requires ANSI C extensions: slash-slash comments, long external names.

Notes:

    You must include NETCONS.H before this file, since this file depends
    on values defined in NETCONS.H.

--*/

#ifndef _LMWKSTA_
#define _LMWKSTA_

#ifdef __cplusplus
extern "C" {
#endif

#include <lmuseflg.h>                   // Deletion force level flags

//
// Function Prototypes
//

NET_API_STATUS NET_API_FUNCTION
NetWkstaGetInfo (
    IN  LPTSTR  servername OPTIONAL,
    IN  unsigned long   level,
    OUT LPBYTE  *bufptr
    );

NET_API_STATUS NET_API_FUNCTION
NetWkstaSetInfo (
    IN  LPTSTR  servername OPTIONAL,
    IN  unsigned long   level,
    IN  LPBYTE  buffer,
    OUT LPDWORD parm_err OPTIONAL
    );

NET_API_STATUS NET_API_FUNCTION
NetWkstaUserGetInfo (
    IN  LPTSTR reserved,
    IN  unsigned long   level,
    OUT LPBYTE  *bufptr
    );

NET_API_STATUS NET_API_FUNCTION
NetWkstaUserSetInfo (
    IN  LPTSTR reserved,
    IN  unsigned long   level,
    OUT LPBYTE  buf,
    OUT LPDWORD parm_err OPTIONAL
    );

NET_API_STATUS NET_API_FUNCTION
NetWkstaUserEnum (
    IN  LPTSTR      servername OPTIONAL,
    IN  unsigned long       level,
    OUT LPBYTE      *bufptr,
    IN  unsigned long       prefmaxlen,
    OUT LPDWORD     entriesread,
    OUT LPDWORD     totalentries,
    IN  OUT LPDWORD resumehandle OPTIONAL
    );

NET_API_STATUS NET_API_FUNCTION
NetWkstaTransportAdd (
    IN  LPTSTR  servername OPTIONAL,
    IN  unsigned long   level,
    IN  LPBYTE  buf,
    OUT LPDWORD parm_err
    );

NET_API_STATUS NET_API_FUNCTION
NetWkstaTransportDel (
    IN  LPTSTR  servername OPTIONAL,
    IN  LPTSTR  transportname,
    IN  unsigned long   ucond
    );

NET_API_STATUS NET_API_FUNCTION
NetWkstaTransportEnum (
    IN  LPTSTR      servername OPTIONAL,
    IN  unsigned long       level,
    OUT LPBYTE      *bufptr,
    IN  unsigned long       prefmaxlen,
    OUT LPDWORD     entriesread,
    OUT LPDWORD     totalentries,
    IN  OUT LPDWORD resumehandle OPTIONAL
    );

//
//  Data Structures
//

//
// NetWkstaGetInfo and NetWkstaSetInfo
//

//
// NetWkstaGetInfo only.  System information - guest access
//
typedef struct _WKSTA_INFO_100 {
    unsigned long   wki100_platform_id;
    LPTSTR  wki100_computername;
    LPTSTR  wki100_langroup;
    unsigned long   wki100_ver_major;
    unsigned long   wki100_ver_minor;
}WKSTA_INFO_100, *PWKSTA_INFO_100, *LPWKSTA_INFO_100;

//
// NetWkstaGetInfo only.  System information - user access
//
typedef struct _WKSTA_INFO_101 {
    unsigned long   wki101_platform_id;
    LPTSTR  wki101_computername;
    LPTSTR  wki101_langroup;
    unsigned long   wki101_ver_major;
    unsigned long   wki101_ver_minor;
    LPTSTR  wki101_lanroot;
}WKSTA_INFO_101, *PWKSTA_INFO_101, *LPWKSTA_INFO_101;

//
// NetWkstaGetInfo only.  System information - admin or operator access
//
typedef struct _WKSTA_INFO_102 {
    unsigned long   wki102_platform_id;
    LPTSTR  wki102_computername;
    LPTSTR  wki102_langroup;
    unsigned long   wki102_ver_major;
    unsigned long   wki102_ver_minor;
    LPTSTR  wki102_lanroot;
    unsigned long   wki102_logged_on_users;
}WKSTA_INFO_102, *PWKSTA_INFO_102, *LPWKSTA_INFO_102;

//
// Down-level NetWkstaGetInfo and NetWkstaSetInfo.
//
// DOS specific workstation information -
//    admin or domain operator access
//
typedef struct _WKSTA_INFO_302{
    unsigned long   wki302_char_wait;
    unsigned long   wki302_collection_time;
    unsigned long   wki302_maximum_collection_count;
    unsigned long   wki302_keep_conn;
    unsigned long   wki302_keep_search;
    unsigned long   wki302_max_cmds;
    unsigned long   wki302_num_work_buf;
    unsigned long   wki302_siz_work_buf;
    unsigned long   wki302_max_wrk_cache;
    unsigned long   wki302_sess_timeout;
    unsigned long   wki302_siz_error;
    unsigned long   wki302_num_alerts;
    unsigned long   wki302_num_services;
    unsigned long   wki302_errlog_sz;
    unsigned long   wki302_print_buf_time;
    unsigned long   wki302_num_char_buf;
    unsigned long   wki302_siz_char_buf;
    LPTSTR  wki302_wrk_heuristics;
    unsigned long   wki302_mailslots;
    unsigned long   wki302_num_dgram_buf;
}WKSTA_INFO_302, *PWKSTA_INFO_302, *LPWKSTA_INFO_302;

//
// Down-level NetWkstaGetInfo and NetWkstaSetInfo
//
// OS/2 specific workstation information -
//    admin or domain operator access
//
typedef struct _WKSTA_INFO_402{
    unsigned long   wki402_char_wait;
    unsigned long   wki402_collection_time;
    unsigned long   wki402_maximum_collection_count;
    unsigned long   wki402_keep_conn;
    unsigned long   wki402_keep_search;
    unsigned long   wki402_max_cmds;
    unsigned long   wki402_num_work_buf;
    unsigned long   wki402_siz_work_buf;
    unsigned long   wki402_max_wrk_cache;
    unsigned long   wki402_sess_timeout;
    unsigned long   wki402_siz_error;
    unsigned long   wki402_num_alerts;
    unsigned long   wki402_num_services;
    unsigned long   wki402_errlog_sz;
    unsigned long   wki402_print_buf_time;
    unsigned long   wki402_num_char_buf;
    unsigned long   wki402_siz_char_buf;
    LPTSTR  wki402_wrk_heuristics;
    unsigned long   wki402_mailslots;
    unsigned long   wki402_num_dgram_buf;
    unsigned long   wki402_max_threads;
}WKSTA_INFO_402, *PWKSTA_INFO_402, *LPWKSTA_INFO_402;

//
// Same-level NetWkstaGetInfo and NetWkstaSetInfo.
//
// NT specific workstation information -
//    admin or domain operator access
//
typedef struct _WKSTA_INFO_502{
    unsigned long   wki502_char_wait;
    unsigned long   wki502_collection_time;
    unsigned long   wki502_maximum_collection_count;
    unsigned long   wki502_keep_conn;
    unsigned long   wki502_max_cmds;
    unsigned long   wki502_sess_timeout;
    unsigned long   wki502_siz_char_buf;
    unsigned long   wki502_max_threads;

    unsigned long   wki502_lock_quota;
    unsigned long   wki502_lock_increment;
    unsigned long   wki502_lock_maximum;
    unsigned long   wki502_pipe_increment;
    unsigned long   wki502_pipe_maximum;
    unsigned long   wki502_cache_file_timeout;
    unsigned long   wki502_dormant_file_limit;
    unsigned long   wki502_read_ahead_throughput;

    unsigned long   wki502_num_mailslot_buffers;
    unsigned long   wki502_num_srv_announce_buffers;
    unsigned long   wki502_max_illegal_datagram_events;
    unsigned long   wki502_illegal_datagram_event_reset_frequency;
    BOOL    wki502_log_election_packets;

    BOOL    wki502_use_opportunistic_locking;
    BOOL    wki502_use_unlock_behind;
    BOOL    wki502_use_close_behind;
    BOOL    wki502_buf_named_pipes;
    BOOL    wki502_use_lock_read_unlock;
    BOOL    wki502_utilize_nt_caching;
    BOOL    wki502_use_raw_read;
    BOOL    wki502_use_raw_write;
    BOOL    wki502_use_write_raw_data;
    BOOL    wki502_use_encryption;
    BOOL    wki502_buf_files_deny_write;
    BOOL    wki502_buf_read_only_files;
    BOOL    wki502_force_core_create_mode;
    BOOL    wki502_use_512_byte_max_transfer;
}WKSTA_INFO_502, *PWKSTA_INFO_502, *LPWKSTA_INFO_502;


//
// The following info-levels are only valid for NetWkstaSetInfo
//

//
// The following levels are supported on down-level systems (LAN Man 2.x)
// as well as NT systems:
//
typedef struct _WKSTA_INFO_1010 {
     unsigned long  wki1010_char_wait;
} WKSTA_INFO_1010, *PWKSTA_INFO_1010, *LPWKSTA_INFO_1010;

typedef struct _WKSTA_INFO_1011 {
     unsigned long  wki1011_collection_time;
} WKSTA_INFO_1011, *PWKSTA_INFO_1011, *LPWKSTA_INFO_1011;

typedef struct _WKSTA_INFO_1012 {
     unsigned long  wki1012_maximum_collection_count;
} WKSTA_INFO_1012, *PWKSTA_INFO_1012, *LPWKSTA_INFO_1012;

//
// The following level are supported on down-level systems (LAN Man 2.x)
// only:
//
typedef struct _WKSTA_INFO_1027 {
     unsigned long  wki1027_errlog_sz;
} WKSTA_INFO_1027, *PWKSTA_INFO_1027, *LPWKSTA_INFO_1027;

typedef struct _WKSTA_INFO_1028 {
     unsigned long  wki1028_print_buf_time;
} WKSTA_INFO_1028, *PWKSTA_INFO_1028, *LPWKSTA_INFO_1028;

typedef struct _WKSTA_INFO_1032 {
     unsigned long  wki1032_wrk_heuristics;
} WKSTA_INFO_1032, *PWKSTA_INFO_1032, *LPWKSTA_INFO_1032;

//
// The following levels are settable on NT systems, and have no
// effect on down-level systems (i.e. LANMan 2.x) since these
// fields cannot be set on them:
//
typedef struct _WKSTA_INFO_1013 {
     unsigned long  wki1013_keep_conn;
} WKSTA_INFO_1013, *PWKSTA_INFO_1013, *LPWKSTA_INFO_1013;

typedef struct _WKSTA_INFO_1018 {
     unsigned long  wki1018_sess_timeout;
} WKSTA_INFO_1018, *PWKSTA_INFO_1018, *LPWKSTA_INFO_1018;

typedef struct _WKSTA_INFO_1023 {
     unsigned long  wki1023_siz_char_buf;
} WKSTA_INFO_1023, *PWKSTA_INFO_1023, *LPWKSTA_INFO_1023;

typedef struct _WKSTA_INFO_1033 {
     unsigned long  wki1033_max_threads;
} WKSTA_INFO_1033, *PWKSTA_INFO_1033, *LPWKSTA_INFO_1033;

//
// The following levels are only supported on NT systems:
//
typedef struct _WKSTA_INFO_1041 {
    unsigned long   wki1041_lock_quota;
} WKSTA_INFO_1041, *PWKSTA_INFO_1041, *LPWKSTA_INFO_1041;

typedef struct _WKSTA_INFO_1042 {
    unsigned long   wki1042_lock_increment;
} WKSTA_INFO_1042, *PWKSTA_INFO_1042, *LPWKSTA_INFO_1042;

typedef struct _WKSTA_INFO_1043 {
    unsigned long   wki1043_lock_maximum;
} WKSTA_INFO_1043, *PWKSTA_INFO_1043, *LPWKSTA_INFO_1043;

typedef struct _WKSTA_INFO_1044 {
    unsigned long   wki1044_pipe_increment;
} WKSTA_INFO_1044, *PWKSTA_INFO_1044, *LPWKSTA_INFO_1044;

typedef struct _WKSTA_INFO_1045 {
    unsigned long   wki1045_pipe_maximum;
} WKSTA_INFO_1045, *PWKSTA_INFO_1045, *LPWKSTA_INFO_1045;

typedef struct _WKSTA_INFO_1046 {
    unsigned long   wki1046_dormant_file_limit;
} WKSTA_INFO_1046, *PWKSTA_INFO_1046, *LPWKSTA_INFO_1046;

typedef struct _WKSTA_INFO_1047 {
    unsigned long    wki1047_cache_file_timeout;
} WKSTA_INFO_1047, *PWKSTA_INFO_1047, *LPWKSTA_INFO_1047;

typedef struct _WKSTA_INFO_1048 {
    BOOL     wki1048_use_opportunistic_locking;
} WKSTA_INFO_1048, *PWKSTA_INFO_1048, *LPWKSTA_INFO_1048;

typedef struct _WKSTA_INFO_1049 {
    BOOL     wki1049_use_unlock_behind;
} WKSTA_INFO_1049, *PWKSTA_INFO_1049, *LPWKSTA_INFO_1049;

typedef struct _WKSTA_INFO_1050 {
    BOOL     wki1050_use_close_behind;
} WKSTA_INFO_1050, *PWKSTA_INFO_1050, *LPWKSTA_INFO_1050;

typedef struct _WKSTA_INFO_1051 {
    BOOL     wki1051_buf_named_pipes;
} WKSTA_INFO_1051, *PWKSTA_INFO_1051, *LPWKSTA_INFO_1051;

typedef struct _WKSTA_INFO_1052 {
    BOOL     wki1052_use_lock_read_unlock;
} WKSTA_INFO_1052, *PWKSTA_INFO_1052, *LPWKSTA_INFO_1052;

typedef struct _WKSTA_INFO_1053 {
    BOOL     wki1053_utilize_nt_caching;
} WKSTA_INFO_1053, *PWKSTA_INFO_1053, *LPWKSTA_INFO_1053;

typedef struct _WKSTA_INFO_1054 {
    BOOL     wki1054_use_raw_read;
} WKSTA_INFO_1054, *PWKSTA_INFO_1054, *LPWKSTA_INFO_1054;

typedef struct _WKSTA_INFO_1055 {
    BOOL     wki1055_use_raw_write;
} WKSTA_INFO_1055, *PWKSTA_INFO_1055, *LPWKSTA_INFO_1055;

typedef struct _WKSTA_INFO_1056 {
    BOOL     wki1056_use_write_raw_data;
} WKSTA_INFO_1056, *PWKSTA_INFO_1056, *LPWKSTA_INFO_1056;

typedef struct _WKSTA_INFO_1057 {
    BOOL     wki1057_use_encryption;
} WKSTA_INFO_1057, *PWKSTA_INFO_1057, *LPWKSTA_INFO_1057;

typedef struct _WKSTA_INFO_1058 {
    BOOL     wki1058_buf_files_deny_write;
} WKSTA_INFO_1058, *PWKSTA_INFO_1058, *LPWKSTA_INFO_1058;

typedef struct _WKSTA_INFO_1059 {
    BOOL     wki1059_buf_read_only_files;
} WKSTA_INFO_1059, *PWKSTA_INFO_1059, *LPWKSTA_INFO_1059;

typedef struct _WKSTA_INFO_1060 {
    BOOL     wki1060_force_core_create_mode;
} WKSTA_INFO_1060, *PWKSTA_INFO_1060, *LPWKSTA_INFO_1060;

typedef struct _WKSTA_INFO_1061 {
    BOOL     wki1061_use_512_byte_max_transfer;
} WKSTA_INFO_1061, *PWKSTA_INFO_1061, *LPWKSTA_INFO_1061;

typedef struct _WKSTA_INFO_1062 {
    unsigned long   wki1062_read_ahead_throughput;
} WKSTA_INFO_1062, *PWKSTA_INFO_1062, *LPWKSTA_INFO_1062;


//
// NetWkstaUserGetInfo (local only) and NetWkstaUserEnum -
//     no access restrictions.
//
typedef struct _WKSTA_USER_INFO_0 {
    LPTSTR  wkui0_username;
}WKSTA_USER_INFO_0, *PWKSTA_USER_INFO_0, *LPWKSTA_USER_INFO_0;

//
// NetWkstaUserGetInfo (local only) and NetWkstaUserEnum -
//     no access restrictions.
//
typedef struct _WKSTA_USER_INFO_1 {
    LPTSTR  wkui1_username;
    LPTSTR  wkui1_logon_domain;
    LPTSTR  wkui1_oth_domains;
    LPTSTR  wkui1_logon_server;
}WKSTA_USER_INFO_1, *PWKSTA_USER_INFO_1, *LPWKSTA_USER_INFO_1;

//
// NetWkstaUserSetInfo - local access.
//
typedef struct _WKSTA_USER_INFO_1101 {
     LPTSTR  wkui1101_oth_domains;
} WKSTA_USER_INFO_1101, *PWKSTA_USER_INFO_1101,
  *LPWKSTA_USER_INFO_1101;


//
// NetWkstaTransportAdd - admin access
//
typedef struct _WKSTA_TRANSPORT_INFO_0 {
    unsigned long   wkti0_quality_of_service;
    unsigned long   wkti0_number_of_vcs;
    LPTSTR  wkti0_transport_name;
    LPTSTR  wkti0_transport_address;
    BOOL    wkti0_wan_ish;
}WKSTA_TRANSPORT_INFO_0, *PWKSTA_TRANSPORT_INFO_0,
 *LPWKSTA_TRANSPORT_INFO_0;


//
// Special Values and Constants
//

//
//  Identifiers for use as NetWkstaSetInfo parmnum parameter
//

//
// One of these values indicates the parameter within an information
// structure that is invalid when ERROR_INVALID_PARAMETER is returned by
// NetWkstaSetInfo.
//

#define WKSTA_PLATFORM_ID_PARMNUM               100
#define WKSTA_COMPUTERNAME_PARMNUM              1
#define WKSTA_LANGROUP_PARMNUM                  2
#define WKSTA_VER_MAJOR_PARMNUM                 4
#define WKSTA_VER_MINOR_PARMNUM                 5
#define WKSTA_LOGGED_ON_USERS_PARMNUM           6
#define WKSTA_LANROOT_PARMNUM                   7
#define WKSTA_LOGON_DOMAIN_PARMNUM              8
#define WKSTA_LOGON_SERVER_PARMNUM              9
#define WKSTA_CHARWAIT_PARMNUM                  10  // Supported by down-level.
#define WKSTA_CHARTIME_PARMNUM                  11  // Supported by down-level.
#define WKSTA_CHARCOUNT_PARMNUM                 12  // Supported by down-level.
#define WKSTA_KEEPCONN_PARMNUM                  13
#define WKSTA_KEEPSEARCH_PARMNUM                14
#define WKSTA_MAXCMDS_PARMNUM                   15
#define WKSTA_NUMWORKBUF_PARMNUM                16
#define WKSTA_MAXWRKCACHE_PARMNUM               17
#define WKSTA_SESSTIMEOUT_PARMNUM               18
#define WKSTA_SIZERROR_PARMNUM                  19
#define WKSTA_NUMALERTS_PARMNUM                 20
#define WKSTA_NUMSERVICES_PARMNUM               21
#define WKSTA_NUMCHARBUF_PARMNUM                22
#define WKSTA_SIZCHARBUF_PARMNUM                23
#define WKSTA_ERRLOGSZ_PARMNUM                  27  // Supported by down-level.
#define WKSTA_PRINTBUFTIME_PARMNUM              28  // Supported by down-level.
#define WKSTA_SIZWORKBUF_PARMNUM                29
#define WKSTA_MAILSLOTS_PARMNUM                 30
#define WKSTA_NUMDGRAMBUF_PARMNUM               31
#define WKSTA_WRKHEURISTICS_PARMNUM             32  // Supported by down-level.
#define WKSTA_MAXTHREADS_PARMNUM                33

#define WKSTA_LOCKQUOTA_PARMNUM                 41
#define WKSTA_LOCKINCREMENT_PARMNUM             42
#define WKSTA_LOCKMAXIMUM_PARMNUM               43
#define WKSTA_PIPEINCREMENT_PARMNUM             44
#define WKSTA_PIPEMAXIMUM_PARMNUM               45
#define WKSTA_DORMANTFILELIMIT_PARMNUM          46
#define WKSTA_CACHEFILETIMEOUT_PARMNUM          47
#define WKSTA_USEOPPORTUNISTICLOCKING_PARMNUM   48
#define WKSTA_USEUNLOCKBEHIND_PARMNUM           49
#define WKSTA_USECLOSEBEHIND_PARMNUM            50
#define WKSTA_BUFFERNAMEDPIPES_PARMNUM          51
#define WKSTA_USELOCKANDREADANDUNLOCK_PARMNUM   52
#define WKSTA_UTILIZENTCACHING_PARMNUM          53
#define WKSTA_USERAWREAD_PARMNUM                54
#define WKSTA_USERAWWRITE_PARMNUM               55
#define WKSTA_USEWRITERAWWITHDATA_PARMNUM       56
#define WKSTA_USEENCRYPTION_PARMNUM             57
#define WKSTA_BUFFILESWITHDENYWRITE_PARMNUM     58
#define WKSTA_BUFFERREADONLYFILES_PARMNUM       59
#define WKSTA_FORCECORECREATEMODE_PARMNUM       60
#define WKSTA_USE512BYTESMAXTRANSFER_PARMNUM    61
#define WKSTA_READAHEADTHRUPUT_PARMNUM          62


//
// One of these values indicates the parameter within an information
// structure that is invalid when ERROR_INVALID_PARAMETER is returned by
// NetWkstaUserSetInfo.
//

#define WKSTA_OTH_DOMAINS_PARMNUM              101


//
// One of these values indicates the parameter within an information
// structure that is invalid when ERROR_INVALID_PARAMETER is returned by
// NetWkstaTransportAdd.
//

#define TRANSPORT_QUALITYOFSERVICE_PARMNUM     201
#define TRANSPORT_NAME_PARMNUM                 202

#ifdef __cplusplus
}
#endif

#endif // _LMWKSTA_
#pragma once 
