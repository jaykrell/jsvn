/*++ BUILD Version: 0003    // Increment this if a change has global effects

Copyright (c) 1991-1996  Microsoft Corporation

Module Name:

    lmaudit.h

Abstract:

    This module defines the API function prototypes and data structures
    for the following groups of NT API functions:
        NetAudit

Environment:

    User Mode - Win32

Notes:

    You must include NETCONS.H before this file, since this file depends
    on values defined in NETCONS.H.

--*/

#ifndef _LMAUDIT_
#define _LMAUDIT_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _LMHLOGDEFINED_
#define _LMHLOGDEFINED_

typedef struct _HLOG {
     unsigned long          time;
     unsigned long          last_flags;
     unsigned long          offset;
     unsigned long          rec_offset;
} HLOG, *PHLOG, *LPHLOG;

#define LOGFLAGS_FORWARD	0
#define LOGFLAGS_BACKWARD	0x1
#define LOGFLAGS_SEEK		0x2

#endif

//
// Function Prototypes - Audit
//

NET_API_STATUS NET_API_FUNCTION
NetAuditClear (
    IN  const wchar_t*  server OPTIONAL,
    IN  const wchar_t*  backupfile OPTIONAL,
    IN  const wchar_t*  service OPTIONAL  // WARNING: buggy support before LM 2.0C!!
    );

NET_API_STATUS NET_API_FUNCTION
NetAuditRead (
    IN  const wchar_t*  server OPTIONAL,
    IN  const wchar_t*  service OPTIONAL,  // WARNING: buggy support before LM 2.0C!!
    IN  LPHLOG   auditloghandle,
    IN  unsigned long    offset,
    IN  LPDWORD  reserved1 OPTIONAL,
    IN  unsigned long   reserved2,
    IN  unsigned long   offsetflag,
    OUT LPBYTE  *bufptr,
    IN  unsigned long   prefmaxlen,
    OUT LPDWORD bytesread,
    OUT LPDWORD totalavailable
    );

NET_API_STATUS NET_API_FUNCTION
NetAuditWrite (
    IN  unsigned long    type,
    IN  LPBYTE   buf,
    IN  unsigned long    numbytes,
    IN  const wchar_t*  service OPTIONAL,
    IN  LPBYTE   reserved OPTIONAL
    );


//
// Data Structures - Audit
//

typedef struct _AUDIT_ENTRY {
     unsigned long          ae_len;
     unsigned long          ae_reserved;
     unsigned long          ae_time;
     unsigned long          ae_type;
     unsigned long          ae_data_offset;  /* Offset from beginning
                              address of audit_entry */
     unsigned long          ae_data_size;  // byte count of ae_data area (not incl pad).
} AUDIT_ENTRY, *PAUDIT_ENTRY, *LPAUDIT_ENTRY;

// BUGBUG: Temporary to let users ifdef on this struct layout.
#define REVISED_AUDIT_ENTRY_STRUCT


typedef struct _AE_SRVSTATUS {
     unsigned long	    ae_sv_status;
} AE_SRVSTATUS, *PAE_SRVSTATUS, *LPAE_SRVSTATUS;

typedef struct _AE_SESSLOGON {
     unsigned long          ae_so_compname;
     unsigned long          ae_so_username;
     unsigned long          ae_so_privilege;
} AE_SESSLOGON, *PAE_SESSLOGON, *LPAE_SESSLOGON;

typedef struct _AE_SESSLOGOFF {
     unsigned long          ae_sf_compname;
     unsigned long          ae_sf_username;
     unsigned long          ae_sf_reason;
} AE_SESSLOGOFF, *PAE_SESSLOGOFF, *LPAE_SESSLOGOFF;

typedef struct _AE_SESSPWERR {
     unsigned long          ae_sp_compname;
     unsigned long          ae_sp_username;
} AE_SESSPWERR, *PAE_SESSPWERR, *LPAE_SESSPWERR;

typedef struct _AE_CONNSTART {
     unsigned long          ae_ct_compname;
     unsigned long          ae_ct_username;
     unsigned long          ae_ct_netname;
     unsigned long          ae_ct_connid;
} AE_CONNSTART, *PAE_CONNSTART, *LPAE_CONNSTART;

typedef struct _AE_CONNSTOP {
     unsigned long          ae_cp_compname;
     unsigned long          ae_cp_username;
     unsigned long          ae_cp_netname;
     unsigned long          ae_cp_connid;
     unsigned long          ae_cp_reason;
} AE_CONNSTOP, *PAE_CONNSTOP, *LPAE_CONNSTOP;

typedef struct _AE_CONNREJ {
     unsigned long          ae_cr_compname;
     unsigned long          ae_cr_username;
     unsigned long          ae_cr_netname;
     unsigned long          ae_cr_reason;
} AE_CONNREJ, *PAE_CONNREJ, *LPAE_CONNREJ;

typedef struct _AE_RESACCESS {
     unsigned long          ae_ra_compname;
     unsigned long          ae_ra_username;
     unsigned long          ae_ra_resname;
     unsigned long          ae_ra_operation;
     unsigned long          ae_ra_returncode;
     unsigned long          ae_ra_restype;
     unsigned long          ae_ra_fileid;
} AE_RESACCESS, *PAE_RESACCESS, *LPAE_RESACCESS;

typedef struct _AE_RESACCESSREJ {
     unsigned long          ae_rr_compname;
     unsigned long          ae_rr_username;
     unsigned long          ae_rr_resname;
     unsigned long          ae_rr_operation;
} AE_RESACCESSREJ, *PAE_RESACCESSREJ, *LPAE_RESACCESSREJ;

typedef struct _AE_CLOSEFILE {
     unsigned long          ae_cf_compname;
     unsigned long          ae_cf_username;
     unsigned long          ae_cf_resname;
     unsigned long          ae_cf_fileid;
     unsigned long          ae_cf_duration;
     unsigned long          ae_cf_reason;
} AE_CLOSEFILE, *PAE_CLOSEFILE, *LPAE_CLOSEFILE;

typedef struct _AE_SERVICESTAT {
     unsigned long          ae_ss_compname;
     unsigned long          ae_ss_username;
     unsigned long          ae_ss_svcname;
     unsigned long          ae_ss_status;
     unsigned long          ae_ss_code;
     unsigned long          ae_ss_text;
     unsigned long          ae_ss_returnval;
} AE_SERVICESTAT, *PAE_SERVICESTAT, *LPAE_SERVICESTAT;

typedef struct _AE_ACLMOD {
     unsigned long          ae_am_compname;
     unsigned long          ae_am_username;
     unsigned long          ae_am_resname;
     unsigned long          ae_am_action;
     unsigned long          ae_am_datalen;
} AE_ACLMOD, *PAE_ACLMOD, *LPAE_ACLMOD;

typedef struct _AE_UASMOD {
     unsigned long          ae_um_compname;
     unsigned long          ae_um_username;
     unsigned long          ae_um_resname;
     unsigned long          ae_um_rectype;
     unsigned long          ae_um_action;
     unsigned long          ae_um_datalen;
} AE_UASMOD, *PAE_UASMOD, *LPAE_UASMOD;

typedef struct _AE_NETLOGON {
     unsigned long          ae_no_compname;
     unsigned long          ae_no_username;
     unsigned long          ae_no_privilege;
     unsigned long          ae_no_authflags;
} AE_NETLOGON, *PAE_NETLOGON, *LPAE_NETLOGON;

typedef struct _AE_NETLOGOFF {
     unsigned long          ae_nf_compname;
     unsigned long          ae_nf_username;
     unsigned long          ae_nf_reserved1;
     unsigned long          ae_nf_reserved2;
} AE_NETLOGOFF, *PAE_NETLOGOFF, *LPAE_NETLOGOFF;

typedef struct _AE_ACCLIM {
     unsigned long          ae_al_compname;
     unsigned long          ae_al_username;
     unsigned long          ae_al_resname;
     unsigned long          ae_al_limit;
} AE_ACCLIM, *PAE_ACCLIM, *LPAE_ACCLIM;

#define ACTION_LOCKOUT          00
#define ACTION_ADMINUNLOCK      01

typedef struct _AE_LOCKOUT {
    unsigned long           ae_lk_compname;     // Ptr to computername of client.
    unsigned long           ae_lk_username;     // Ptr to username of client (NULL
                                        //  if same as computername).
    unsigned long           ae_lk_action;       // Action taken on account:
                                        // 0 means locked out, 1 means not.
    unsigned long           ae_lk_bad_pw_count; // Bad password count at the time
                                        // of lockout.
} AE_LOCKOUT, *PAE_LOCKOUT, *LPAE_LOCKOUT;

typedef struct _AE_GENERIC {
     unsigned long          ae_ge_msgfile;
     unsigned long          ae_ge_msgnum;
     unsigned long          ae_ge_params;
     unsigned long          ae_ge_param1;
     unsigned long          ae_ge_param2;
     unsigned long          ae_ge_param3;
     unsigned long          ae_ge_param4;
     unsigned long          ae_ge_param5;
     unsigned long          ae_ge_param6;
     unsigned long          ae_ge_param7;
     unsigned long          ae_ge_param8;
     unsigned long          ae_ge_param9;
} AE_GENERIC, *PAE_GENERIC, *LPAE_GENERIC;

//
// Special Values and Constants - Audit
//

//
// 	Audit entry types (field ae_type in audit_entry).
//

#define AE_SRVSTATUS	0
#define AE_SESSLOGON	1
#define AE_SESSLOGOFF	2
#define AE_SESSPWERR	3
#define AE_CONNSTART	4
#define AE_CONNSTOP	5
#define AE_CONNREJ	6
#define AE_RESACCESS	7
#define AE_RESACCESSREJ	8
#define AE_CLOSEFILE	9
#define AE_SERVICESTAT	11
#define AE_ACLMOD	12
#define AE_UASMOD	13
#define AE_NETLOGON	14
#define AE_NETLOGOFF	15
#define AE_NETLOGDENIED 16
#define AE_ACCLIMITEXCD 17
#define AE_RESACCESS2	18
#define AE_ACLMODFAIL	19
#define AE_LOCKOUT      20
#define AE_GENERIC_TYPE 21
//
//	Values for ae_ss_status field of ae_srvstatus.
//

#define AE_SRVSTART	0
#define AE_SRVPAUSED	1
#define AE_SRVCONT	2
#define AE_SRVSTOP	3

//
// 	Values for ae_so_privilege field of ae_sesslogon.
//

#define AE_GUEST	0		
#define AE_USER		1
#define AE_ADMIN	2

//
//	Values for various ae_XX_reason fields.
//

#define AE_NORMAL	0		
#define AE_USERLIMIT	0
#define AE_GENERAL	0
#define AE_ERROR	1
#define AE_SESSDIS	1
#define AE_BADPW	1
#define AE_AUTODIS	2
#define AE_UNSHARE	2
#define AE_ADMINPRIVREQD 2
#define AE_ADMINDIS	3
#define AE_NOACCESSPERM 3
#define AE_ACCRESTRICT	4

#define	AE_NORMAL_CLOSE	0
#define	AE_SES_CLOSE	1
#define	AE_ADMIN_CLOSE	2

//
// Values for xx_subreason fields.
//

#define AE_LIM_UNKNOWN	    0
#define AE_LIM_LOGONHOURS   1
#define AE_LIM_EXPIRED	    2
#define AE_LIM_INVAL_WKSTA  3
#define AE_LIM_DISABLED     4
#define AE_LIM_DELETED	    5

//
// Values for xx_action fields
//

#define AE_MOD		0
#define AE_DELETE	1
#define AE_ADD		2

//
// Types of UAS record for um_rectype field
//

#define AE_UAS_USER	    0
#define AE_UAS_GROUP	    1
#define AE_UAS_MODALS	    2

//
// Bitmasks for auditing events
//
// The parentheses around the hex constants broke h_to_inc
// and have been purged from the face of the earth.
//

#define SVAUD_SERVICE           0x1
#define SVAUD_GOODSESSLOGON     0x6
#define SVAUD_BADSESSLOGON      0x18
#define SVAUD_SESSLOGON         (SVAUD_GOODSESSLOGON | SVAUD_BADSESSLOGON)
#define SVAUD_GOODNETLOGON      0x60
#define SVAUD_BADNETLOGON       0x180
#define SVAUD_NETLOGON          (SVAUD_GOODNETLOGON | SVAUD_BADNETLOGON)
#define SVAUD_LOGON             (SVAUD_NETLOGON | SVAUD_SESSLOGON)
#define SVAUD_GOODUSE           0x600
#define SVAUD_BADUSE            0x1800
#define SVAUD_USE               (SVAUD_GOODUSE | SVAUD_BADUSE)
#define SVAUD_USERLIST          0x2000
#define SVAUD_PERMISSIONS       0x4000
#define SVAUD_RESOURCE          0x8000
#define SVAUD_LOGONLIM		0x00010000

//
// Resource access audit bitmasks.
//

#define AA_AUDIT_ALL	    0x0001
#define AA_A_OWNER	    0x0004
#define AA_CLOSE	    0x0008
#define AA_S_OPEN	    0x0010
#define AA_S_WRITE	    0x0020
#define AA_S_CREATE	    0x0020
#define AA_S_DELETE	    0x0040
#define AA_S_ACL	    0x0080
#define AA_S_ALL	    ( AA_S_OPEN | AA_S_WRITE | AA_S_DELETE | AA_S_ACL)
#define AA_F_OPEN	    0x0100
#define AA_F_WRITE	    0x0200
#define AA_F_CREATE	    0x0200
#define AA_F_DELETE	    0x0400
#define AA_F_ACL	    0x0800
#define AA_F_ALL	    ( AA_F_OPEN | AA_F_WRITE | AA_F_DELETE | AA_F_ACL)

// Pinball-specific
#define AA_A_OPEN	    0x1000
#define AA_A_WRITE	    0x2000
#define AA_A_CREATE	    0x2000
#define AA_A_DELETE	    0x4000
#define AA_A_ACL	    0x8000
#define AA_A_ALL	    ( AA_F_OPEN | AA_F_WRITE | AA_F_DELETE | AA_F_ACL)


#ifdef __cplusplus
}
#endif

#endif  // _LMAUDIT_
#pragma once 
