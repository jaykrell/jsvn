/*++ BUILD Version: 0000    // Increment this if a change has global effects

The  Telephony  API  is jointly copyrighted by Intel and Microsoft.  You are
granted  a royalty free worldwide, unlimited license to make copies, and use
the   API/SPI  for  making  applications/drivers  that  interface  with  the
specification provided that this paragraph and the Intel/Microsoft copyright
statement is maintained as is in the text and source code files.

Copyright 1995-96 Microsoft, all rights reserved.
Portions copyright 1992, 1993 Intel/Microsoft, all rights reserved.

Module Name:

    tapi.h

Notes:

    Additions to the Telephony Application Programming Interface (TAPI) since
    version 1.0 are noted by version number (e.g. "TAPI v1.4").

--*/

#ifndef TAPI_H
#define TAPI_H



//
//  -- TAPI VERSION INFO -- TAPI VERSION INFO -- TAPI VERSION INFO --
//  -- TAPI VERSION INFO -- TAPI VERSION INFO -- TAPI VERSION INFO --
//  -- TAPI VERSION INFO -- TAPI VERSION INFO -- TAPI VERSION INFO --
//
// To build  a TAPI 1.4 application put a define as below in your source
// file before you include TAPI.H:
//
// #define TAPI_CURRENT_VERSION 0x00010004
//
//
#ifndef TAPI_CURRENT_VERSION
#define TAPI_CURRENT_VERSION 0x00020000
#endif

#include <windows.h>

#pragma pack(1)
// Type definitions of the data types used in tapi

#ifdef __cplusplus
extern "C" {            /* Assume C declarations for C++ */
#endif  /* __cplusplus */


//
// TAPI type definitions
//

#define DECLARE_OPAQUE32(name)  struct name##__ { int unused; }; \
                typedef const struct name##__ * name

DECLARE_OPAQUE32(HCALL);
typedef HCALL  * LPHCALL;

DECLARE_OPAQUE32(HLINE);
typedef HLINE  * LPHLINE;

DECLARE_OPAQUE32(HPHONE);
typedef HPHONE  * LPHPHONE;

DECLARE_OPAQUE32(HLINEAPP);
typedef HLINEAPP  * LPHLINEAPP;

DECLARE_OPAQUE32(HPHONEAPP);
typedef HPHONEAPP  * LPHPHONEAPP;

typedef HICON  * LPHICON;

typedef void (__stdcall * LINECALLBACK)(
    unsigned long               hDevice,
    unsigned long               dwMessage,
    unsigned long               dwInstance,
    unsigned long               dwParam1,
    unsigned long               dwParam2,
    unsigned long               dwParam3
    );

typedef void (__stdcall * PHONECALLBACK)(
    unsigned long               hDevice,
    unsigned long               dwMessage,
    unsigned long               dwInstance,
    unsigned long               dwParam1,
    unsigned long               dwParam2,
    unsigned long               dwParam3
    );


// Messages for Phones and Lines

#define LINE_ADDRESSSTATE                       0L
#define LINE_CALLINFO                           1L
#define LINE_CALLSTATE                          2L
#define LINE_CLOSE                              3L
#define LINE_DEVSPECIFIC                        4L
#define LINE_DEVSPECIFICFEATURE                 5L
#define LINE_GATHERDIGITS                       6L
#define LINE_GENERATE                           7L
#define LINE_LINEDEVSTATE                       8L
#define LINE_MONITORDIGITS                      9L
#define LINE_MONITORMEDIA                       10L
#define LINE_MONITORTONE                        11L
#define LINE_REPLY                              12L
#define LINE_REQUEST                            13L
#define PHONE_BUTTON                            14L
#define PHONE_CLOSE                             15L
#define PHONE_DEVSPECIFIC                       16L
#define PHONE_REPLY                             17L
#define PHONE_STATE                             18L
#define LINE_CREATE                             19L             // TAPI v1.4
#define PHONE_CREATE                            20L             // TAPI v1.4

#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define LINE_AGENTSPECIFIC                      21L             // TAPI v2.0
#define LINE_AGENTSTATUS                        22L             // TAPI v2.0
#define LINE_APPNEWCALL                         23L             // TAPI v2.0
#define LINE_PROXYREQUEST                       24L             // TAPI v2.0
#define LINE_REMOVE                             25L             // TAPI v2.0
#define PHONE_REMOVE                            26L             // TAPI v2.0
#endif


#define INITIALIZE_NEGOTIATION                  0xFFFFFFFFL

#define LINEADDRCAPFLAGS_FWDNUMRINGS            0x00000001
#define LINEADDRCAPFLAGS_PICKUPGROUPID          0x00000002
#define LINEADDRCAPFLAGS_SECURE                 0x00000004
#define LINEADDRCAPFLAGS_BLOCKIDDEFAULT         0x00000008
#define LINEADDRCAPFLAGS_BLOCKIDOVERRIDE        0x00000010
#define LINEADDRCAPFLAGS_DIALED                 0x00000020
#define LINEADDRCAPFLAGS_ORIGOFFHOOK            0x00000040
#define LINEADDRCAPFLAGS_DESTOFFHOOK            0x00000080
#define LINEADDRCAPFLAGS_FWDCONSULT             0x00000100
#define LINEADDRCAPFLAGS_SETUPCONFNULL          0x00000200
#define LINEADDRCAPFLAGS_AUTORECONNECT          0x00000400
#define LINEADDRCAPFLAGS_COMPLETIONID           0x00000800
#define LINEADDRCAPFLAGS_TRANSFERHELD           0x00001000
#define LINEADDRCAPFLAGS_TRANSFERMAKE           0x00002000
#define LINEADDRCAPFLAGS_CONFERENCEHELD         0x00004000
#define LINEADDRCAPFLAGS_CONFERENCEMAKE         0x00008000
#define LINEADDRCAPFLAGS_PARTIALDIAL            0x00010000
#define LINEADDRCAPFLAGS_FWDSTATUSVALID         0x00020000
#define LINEADDRCAPFLAGS_FWDINTEXTADDR          0x00040000
#define LINEADDRCAPFLAGS_FWDBUSYNAADDR          0x00080000
#define LINEADDRCAPFLAGS_ACCEPTTOALERT          0x00100000
#define LINEADDRCAPFLAGS_CONFDROP               0x00200000
#define LINEADDRCAPFLAGS_PICKUPCALLWAIT         0x00400000
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define LINEADDRCAPFLAGS_PREDICTIVEDIALER       0x00800000      // TAPI v2.0
#define LINEADDRCAPFLAGS_QUEUE                  0x01000000      // TAPI v2.0
#define LINEADDRCAPFLAGS_ROUTEPOINT             0x02000000      // TAPI v2.0
#define LINEADDRCAPFLAGS_HOLDMAKESNEW           0x04000000      // TAPI v2.0
#define LINEADDRCAPFLAGS_NOINTERNALCALLS        0x08000000      // TAPI v2.0
#define LINEADDRCAPFLAGS_NOEXTERNALCALLS        0x10000000      // TAPI v2.0
#define LINEADDRCAPFLAGS_SETCALLINGID           0x20000000      // TAPI v2.0
#endif

#define LINEADDRESSMODE_ADDRESSID               0x00000001
#define LINEADDRESSMODE_DIALABLEADDR            0x00000002

#define LINEADDRESSSHARING_PRIVATE              0x00000001
#define LINEADDRESSSHARING_BRIDGEDEXCL          0x00000002
#define LINEADDRESSSHARING_BRIDGEDNEW           0x00000004
#define LINEADDRESSSHARING_BRIDGEDSHARED        0x00000008
#define LINEADDRESSSHARING_MONITORED            0x00000010

#define LINEADDRESSSTATE_OTHER                  0x00000001
#define LINEADDRESSSTATE_DEVSPECIFIC            0x00000002
#define LINEADDRESSSTATE_INUSEZERO              0x00000004
#define LINEADDRESSSTATE_INUSEONE               0x00000008
#define LINEADDRESSSTATE_INUSEMANY              0x00000010
#define LINEADDRESSSTATE_NUMCALLS               0x00000020
#define LINEADDRESSSTATE_FORWARD                0x00000040
#define LINEADDRESSSTATE_TERMINALS              0x00000080
#define LINEADDRESSSTATE_CAPSCHANGE             0x00000100      // TAPI v1.4

#define LINEADDRFEATURE_FORWARD                 0x00000001
#define LINEADDRFEATURE_MAKECALL                0x00000002
#define LINEADDRFEATURE_PICKUP                  0x00000004
#define LINEADDRFEATURE_SETMEDIACONTROL         0x00000008
#define LINEADDRFEATURE_SETTERMINAL             0x00000010
#define LINEADDRFEATURE_SETUPCONF               0x00000020
#define LINEADDRFEATURE_UNCOMPLETECALL          0x00000040
#define LINEADDRFEATURE_UNPARK                  0x00000080
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define LINEADDRFEATURE_PICKUPHELD              0x00000100      // TAPI v2.0
#define LINEADDRFEATURE_PICKUPGROUP             0x00000200      // TAPI v2.0
#define LINEADDRFEATURE_PICKUPDIRECT            0x00000400      // TAPI v2.0
#define LINEADDRFEATURE_PICKUPWAITING           0x00000800      // TAPI v2.0
#define LINEADDRFEATURE_FORWARDFWD              0x00001000      // TAPI v2.0
#define LINEADDRFEATURE_FORWARDDND              0x00002000      // TAPI v2.0
#endif

#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define LINEAGENTFEATURE_SETAGENTGROUP          0x00000001      // TAPI v2.0
#define LINEAGENTFEATURE_SETAGENTSTATE          0x00000002      // TAPI v2.0
#define LINEAGENTFEATURE_SETAGENTACTIVITY       0x00000004      // TAPI v2.0
#define LINEAGENTFEATURE_AGENTSPECIFIC          0x00000008      // TAPI v2.0
#define LINEAGENTFEATURE_GETAGENTACTIVITYLIST   0x00000010      // TAPI v2.0
#define LINEAGENTFEATURE_GETAGENTGROUP          0x00000020      // TAPI v2.0

#define LINEAGENTSTATE_LOGGEDOFF                0x00000001      // TAPI v2.0
#define LINEAGENTSTATE_NOTREADY                 0x00000002      // TAPI v2.0
#define LINEAGENTSTATE_READY                    0x00000004      // TAPI v2.0
#define LINEAGENTSTATE_BUSYACD                  0x00000008      // TAPI v2.0
#define LINEAGENTSTATE_BUSYINCOMING             0x00000010      // TAPI v2.0
#define LINEAGENTSTATE_BUSYOUTBOUND             0x00000020      // TAPI v2.0
#define LINEAGENTSTATE_BUSYOTHER                0x00000040      // TAPI v2.0
#define LINEAGENTSTATE_WORKINGAFTERCALL         0x00000080      // TAPI v2.0
#define LINEAGENTSTATE_UNKNOWN                  0x00000100      // TAPI v2.0
#define LINEAGENTSTATE_UNAVAIL                  0x00000200      // TAPI v2.0

#define LINEAGENTSTATUS_GROUP                   0x00000001      // TAPI v2.0
#define LINEAGENTSTATUS_STATE                   0x00000002      // TAPI v2.0
#define LINEAGENTSTATUS_NEXTSTATE               0x00000004      // TAPI v2.0
#define LINEAGENTSTATUS_ACTIVITY                0x00000008      // TAPI v2.0
#define LINEAGENTSTATUS_ACTIVITYLIST            0x00000010      // TAPI v2.0
#define LINEAGENTSTATUS_GROUPLIST               0x00000020      // TAPI v2.0
#define LINEAGENTSTATUS_CAPSCHANGE              0x00000040      // TAPI v2.0
#define LINEAGENTSTATUS_VALIDSTATES             0x00000080      // TAPI v2.0
#define LINEAGENTSTATUS_VALIDNEXTSTATES         0x00000100      // TAPI v2.0
#endif


#define LINEANSWERMODE_NONE                     0x00000001
#define LINEANSWERMODE_DROP                     0x00000002
#define LINEANSWERMODE_HOLD                     0x00000004

#define LINEBEARERMODE_VOICE                    0x00000001
#define LINEBEARERMODE_SPEECH                   0x00000002
#define LINEBEARERMODE_MULTIUSE                 0x00000004
#define LINEBEARERMODE_DATA                     0x00000008
#define LINEBEARERMODE_ALTSPEECHDATA            0x00000010
#define LINEBEARERMODE_NONCALLSIGNALING         0x00000020
#define LINEBEARERMODE_PASSTHROUGH              0x00000040      // TAPI v1.4
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define LINEBEARERMODE_RESTRICTEDDATA           0x00000080      // TAPI v2.0
#endif

#define LINEBUSYMODE_STATION                    0x00000001
#define LINEBUSYMODE_TRUNK                      0x00000002
#define LINEBUSYMODE_UNKNOWN                    0x00000004
#define LINEBUSYMODE_UNAVAIL                    0x00000008

#define LINECALLCOMPLCOND_BUSY                  0x00000001
#define LINECALLCOMPLCOND_NOANSWER              0x00000002

#define LINECALLCOMPLMODE_CAMPON                0x00000001
#define LINECALLCOMPLMODE_CALLBACK              0x00000002
#define LINECALLCOMPLMODE_INTRUDE               0x00000004
#define LINECALLCOMPLMODE_MESSAGE               0x00000008

#define LINECALLFEATURE_ACCEPT                  0x00000001
#define LINECALLFEATURE_ADDTOCONF               0x00000002
#define LINECALLFEATURE_ANSWER                  0x00000004
#define LINECALLFEATURE_BLINDTRANSFER           0x00000008
#define LINECALLFEATURE_COMPLETECALL            0x00000010
#define LINECALLFEATURE_COMPLETETRANSF          0x00000020
#define LINECALLFEATURE_DIAL                    0x00000040
#define LINECALLFEATURE_DROP                    0x00000080
#define LINECALLFEATURE_GATHERDIGITS            0x00000100
#define LINECALLFEATURE_GENERATEDIGITS          0x00000200
#define LINECALLFEATURE_GENERATETONE            0x00000400
#define LINECALLFEATURE_HOLD                    0x00000800
#define LINECALLFEATURE_MONITORDIGITS           0x00001000
#define LINECALLFEATURE_MONITORMEDIA            0x00002000
#define LINECALLFEATURE_MONITORTONES            0x00004000
#define LINECALLFEATURE_PARK                    0x00008000
#define LINECALLFEATURE_PREPAREADDCONF          0x00010000
#define LINECALLFEATURE_REDIRECT                0x00020000
#define LINECALLFEATURE_REMOVEFROMCONF          0x00040000
#define LINECALLFEATURE_SECURECALL              0x00080000
#define LINECALLFEATURE_SENDUSERUSER            0x00100000
#define LINECALLFEATURE_SETCALLPARAMS           0x00200000
#define LINECALLFEATURE_SETMEDIACONTROL         0x00400000
#define LINECALLFEATURE_SETTERMINAL             0x00800000
#define LINECALLFEATURE_SETUPCONF               0x01000000
#define LINECALLFEATURE_SETUPTRANSFER           0x02000000
#define LINECALLFEATURE_SWAPHOLD                0x04000000
#define LINECALLFEATURE_UNHOLD                  0x08000000
#define LINECALLFEATURE_RELEASEUSERUSERINFO     0x10000000      // TAPI v1.4
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define LINECALLFEATURE_SETTREATMENT            0x20000000      // TAPI v2.0
#define LINECALLFEATURE_SETQOS                  0x40000000      // TAPI v2.0
#define LINECALLFEATURE_SETCALLDATA             0x80000000      // TAPI v2.0
#endif

#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define LINECALLFEATURE2_NOHOLDCONFERENCE       0x00000001      // TAPI v2.0
#define LINECALLFEATURE2_ONESTEPTRANSFER        0x00000002      // TAPI v2.0
#define LINECALLFEATURE2_COMPLCAMPON            0x00000004      // TAPI v2.0
#define LINECALLFEATURE2_COMPLCALLBACK          0x00000008      // TAPI v2.0
#define LINECALLFEATURE2_COMPLINTRUDE           0x00000010      // TAPI v2.0
#define LINECALLFEATURE2_COMPLMESSAGE           0x00000020      // TAPI v2.0
#define LINECALLFEATURE2_TRANSFERNORM           0x00000040      // TAPI v2.0
#define LINECALLFEATURE2_TRANSFERCONF           0x00000080      // TAPI v2.0
#define LINECALLFEATURE2_PARKDIRECT             0x00000100      // TAPI v2.0
#define LINECALLFEATURE2_PARKNONDIRECT          0x00000200      // TAPI v2.0
#endif

#define LINECALLINFOSTATE_OTHER                 0x00000001
#define LINECALLINFOSTATE_DEVSPECIFIC           0x00000002
#define LINECALLINFOSTATE_BEARERMODE            0x00000004
#define LINECALLINFOSTATE_RATE                  0x00000008
#define LINECALLINFOSTATE_MEDIAMODE             0x00000010
#define LINECALLINFOSTATE_APPSPECIFIC           0x00000020
#define LINECALLINFOSTATE_CALLID                0x00000040
#define LINECALLINFOSTATE_RELATEDCALLID         0x00000080
#define LINECALLINFOSTATE_ORIGIN                0x00000100
#define LINECALLINFOSTATE_REASON                0x00000200
#define LINECALLINFOSTATE_COMPLETIONID          0x00000400
#define LINECALLINFOSTATE_NUMOWNERINCR          0x00000800
#define LINECALLINFOSTATE_NUMOWNERDECR          0x00001000
#define LINECALLINFOSTATE_NUMMONITORS           0x00002000
#define LINECALLINFOSTATE_TRUNK                 0x00004000
#define LINECALLINFOSTATE_CALLERID              0x00008000
#define LINECALLINFOSTATE_CALLEDID              0x00010000
#define LINECALLINFOSTATE_CONNECTEDID           0x00020000
#define LINECALLINFOSTATE_REDIRECTIONID         0x00040000
#define LINECALLINFOSTATE_REDIRECTINGID         0x00080000
#define LINECALLINFOSTATE_DISPLAY               0x00100000
#define LINECALLINFOSTATE_USERUSERINFO          0x00200000
#define LINECALLINFOSTATE_HIGHLEVELCOMP         0x00400000
#define LINECALLINFOSTATE_LOWLEVELCOMP          0x00800000
#define LINECALLINFOSTATE_CHARGINGINFO          0x01000000
#define LINECALLINFOSTATE_TERMINAL              0x02000000
#define LINECALLINFOSTATE_DIALPARAMS            0x04000000
#define LINECALLINFOSTATE_MONITORMODES          0x08000000
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define LINECALLINFOSTATE_TREATMENT             0x10000000      // TAPI v2.0
#define LINECALLINFOSTATE_QOS                   0x20000000      // TAPI v2.0
#define LINECALLINFOSTATE_CALLDATA              0x40000000      // TAPI v2.0
#endif

#define LINECALLORIGIN_OUTBOUND                 0x00000001
#define LINECALLORIGIN_INTERNAL                 0x00000002
#define LINECALLORIGIN_EXTERNAL                 0x00000004
#define LINECALLORIGIN_UNKNOWN                  0x00000010
#define LINECALLORIGIN_UNAVAIL                  0x00000020
#define LINECALLORIGIN_CONFERENCE               0x00000040
#define LINECALLORIGIN_INBOUND                  0x00000080      // TAPI v1.4

#define LINECALLPARAMFLAGS_SECURE               0x00000001
#define LINECALLPARAMFLAGS_IDLE                 0x00000002
#define LINECALLPARAMFLAGS_BLOCKID              0x00000004
#define LINECALLPARAMFLAGS_ORIGOFFHOOK          0x00000008
#define LINECALLPARAMFLAGS_DESTOFFHOOK          0x00000010
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define LINECALLPARAMFLAGS_NOHOLDCONFERENCE     0x00000020      // TAPI v2.0
#define LINECALLPARAMFLAGS_PREDICTIVEDIAL       0x00000040      // TAPI v2.0
#define LINECALLPARAMFLAGS_ONESTEPTRANSFER      0x00000080      // TAPI v2.0
#endif

#define LINECALLPARTYID_BLOCKED                 0x00000001
#define LINECALLPARTYID_OUTOFAREA               0x00000002
#define LINECALLPARTYID_NAME                    0x00000004
#define LINECALLPARTYID_ADDRESS                 0x00000008
#define LINECALLPARTYID_PARTIAL                 0x00000010
#define LINECALLPARTYID_UNKNOWN                 0x00000020
#define LINECALLPARTYID_UNAVAIL                 0x00000040

#define LINECALLPRIVILEGE_NONE                  0x00000001
#define LINECALLPRIVILEGE_MONITOR               0x00000002
#define LINECALLPRIVILEGE_OWNER                 0x00000004

#define LINECALLREASON_DIRECT                   0x00000001
#define LINECALLREASON_FWDBUSY                  0x00000002
#define LINECALLREASON_FWDNOANSWER              0x00000004
#define LINECALLREASON_FWDUNCOND                0x00000008
#define LINECALLREASON_PICKUP                   0x00000010
#define LINECALLREASON_UNPARK                   0x00000020
#define LINECALLREASON_REDIRECT                 0x00000040
#define LINECALLREASON_CALLCOMPLETION           0x00000080
#define LINECALLREASON_TRANSFER                 0x00000100
#define LINECALLREASON_REMINDER                 0x00000200
#define LINECALLREASON_UNKNOWN                  0x00000400
#define LINECALLREASON_UNAVAIL                  0x00000800
#define LINECALLREASON_INTRUDE                  0x00001000      // TAPI v1.4
#define LINECALLREASON_PARKED                   0x00002000      // TAPI v1.4
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define LINECALLREASON_CAMPEDON                 0x00004000      // TAPI v2.0
#define LINECALLREASON_ROUTEREQUEST             0x00008000      // TAPI v2.0
#endif

#define LINECALLSELECT_LINE                     0x00000001
#define LINECALLSELECT_ADDRESS                  0x00000002
#define LINECALLSELECT_CALL                     0x00000004

#define LINECALLSTATE_IDLE                      0x00000001
#define LINECALLSTATE_OFFERING                  0x00000002
#define LINECALLSTATE_ACCEPTED                  0x00000004
#define LINECALLSTATE_DIALTONE                  0x00000008
#define LINECALLSTATE_DIALING                   0x00000010
#define LINECALLSTATE_RINGBACK                  0x00000020
#define LINECALLSTATE_BUSY                      0x00000040
#define LINECALLSTATE_SPECIALINFO               0x00000080
#define LINECALLSTATE_CONNECTED                 0x00000100
#define LINECALLSTATE_PROCEEDING                0x00000200
#define LINECALLSTATE_ONHOLD                    0x00000400
#define LINECALLSTATE_CONFERENCED               0x00000800
#define LINECALLSTATE_ONHOLDPENDCONF            0x00001000
#define LINECALLSTATE_ONHOLDPENDTRANSFER        0x00002000
#define LINECALLSTATE_DISCONNECTED              0x00004000
#define LINECALLSTATE_UNKNOWN                   0x00008000

#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define LINECALLTREATMENT_SILENCE               0x00000001      // TAPI v2.0
#define LINECALLTREATMENT_RINGBACK              0x00000002      // TAPI v2.0
#define LINECALLTREATMENT_BUSY                  0x00000003      // TAPI v2.0
#define LINECALLTREATMENT_MUSIC                 0x00000004      // TAPI v2.0
#endif

#define LINECARDOPTION_PREDEFINED               0x00000001      // TAPI v1.4
#define LINECARDOPTION_HIDDEN                   0x00000002      // TAPI v1.4

#define LINECONNECTEDMODE_ACTIVE                0x00000001      // TAPI v1.4
#define LINECONNECTEDMODE_INACTIVE              0x00000002      // TAPI v1.4
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define LINECONNECTEDMODE_ACTIVEHELD            0x00000004      // TAPI v2.0
#define LINECONNECTEDMODE_INACTIVEHELD          0x00000008      // TAPI v2.0
#define LINECONNECTEDMODE_CONFIRMED             0x00000010      // TAPI v2.0
#endif

#define LINEDEVCAPFLAGS_CROSSADDRCONF           0x00000001
#define LINEDEVCAPFLAGS_HIGHLEVCOMP             0x00000002
#define LINEDEVCAPFLAGS_LOWLEVCOMP              0x00000004
#define LINEDEVCAPFLAGS_MEDIACONTROL            0x00000008
#define LINEDEVCAPFLAGS_MULTIPLEADDR            0x00000010
#define LINEDEVCAPFLAGS_CLOSEDROP               0x00000020
#define LINEDEVCAPFLAGS_DIALBILLING             0x00000040
#define LINEDEVCAPFLAGS_DIALQUIET               0x00000080
#define LINEDEVCAPFLAGS_DIALDIALTONE            0x00000100

#define LINEDEVSTATE_OTHER                      0x00000001
#define LINEDEVSTATE_RINGING                    0x00000002
#define LINEDEVSTATE_CONNECTED                  0x00000004
#define LINEDEVSTATE_DISCONNECTED               0x00000008
#define LINEDEVSTATE_MSGWAITON                  0x00000010
#define LINEDEVSTATE_MSGWAITOFF                 0x00000020
#define LINEDEVSTATE_INSERVICE                  0x00000040
#define LINEDEVSTATE_OUTOFSERVICE               0x00000080
#define LINEDEVSTATE_MAINTENANCE                0x00000100
#define LINEDEVSTATE_OPEN                       0x00000200
#define LINEDEVSTATE_CLOSE                      0x00000400
#define LINEDEVSTATE_NUMCALLS                   0x00000800
#define LINEDEVSTATE_NUMCOMPLETIONS             0x00001000
#define LINEDEVSTATE_TERMINALS                  0x00002000
#define LINEDEVSTATE_ROAMMODE                   0x00004000
#define LINEDEVSTATE_BATTERY                    0x00008000
#define LINEDEVSTATE_SIGNAL                     0x00010000
#define LINEDEVSTATE_DEVSPECIFIC                0x00020000
#define LINEDEVSTATE_REINIT                     0x00040000
#define LINEDEVSTATE_LOCK                       0x00080000
#define LINEDEVSTATE_CAPSCHANGE                 0x00100000      // TAPI v1.4
#define LINEDEVSTATE_CONFIGCHANGE               0x00200000      // TAPI v1.4
#define LINEDEVSTATE_TRANSLATECHANGE            0x00400000      // TAPI v1.4
#define LINEDEVSTATE_COMPLCANCEL                0x00800000      // TAPI v1.4
#define LINEDEVSTATE_REMOVED                    0x01000000      // TAPI v1.4

#define LINEDEVSTATUSFLAGS_CONNECTED            0x00000001
#define LINEDEVSTATUSFLAGS_MSGWAIT              0x00000002
#define LINEDEVSTATUSFLAGS_INSERVICE            0x00000004
#define LINEDEVSTATUSFLAGS_LOCKED               0x00000008

#define LINEDIALTONEMODE_NORMAL                 0x00000001
#define LINEDIALTONEMODE_SPECIAL                0x00000002
#define LINEDIALTONEMODE_INTERNAL               0x00000004
#define LINEDIALTONEMODE_EXTERNAL               0x00000008
#define LINEDIALTONEMODE_UNKNOWN                0x00000010
#define LINEDIALTONEMODE_UNAVAIL                0x00000020
    
#define LINEDIGITMODE_PULSE                     0x00000001
#define LINEDIGITMODE_DTMF                      0x00000002
#define LINEDIGITMODE_DTMFEND                   0x00000004
    
#define LINEDISCONNECTMODE_NORMAL               0x00000001
#define LINEDISCONNECTMODE_UNKNOWN              0x00000002
#define LINEDISCONNECTMODE_REJECT               0x00000004
#define LINEDISCONNECTMODE_PICKUP               0x00000008
#define LINEDISCONNECTMODE_FORWARDED            0x00000010
#define LINEDISCONNECTMODE_BUSY                 0x00000020
#define LINEDISCONNECTMODE_NOANSWER             0x00000040
#define LINEDISCONNECTMODE_BADADDRESS           0x00000080
#define LINEDISCONNECTMODE_UNREACHABLE          0x00000100
#define LINEDISCONNECTMODE_CONGESTION           0x00000200
#define LINEDISCONNECTMODE_INCOMPATIBLE         0x00000400
#define LINEDISCONNECTMODE_UNAVAIL              0x00000800
#define LINEDISCONNECTMODE_NODIALTONE           0x00001000      // TAPI v1.4
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define LINEDISCONNECTMODE_NUMBERCHANGED        0x00002000      // TAPI v2.0
#define LINEDISCONNECTMODE_OUTOFORDER           0x00004000      // TAPI v2.0
#define LINEDISCONNECTMODE_TEMPFAILURE          0x00008000      // TAPI v2.0
#define LINEDISCONNECTMODE_QOSUNAVAIL           0x00010000      // TAPI v2.0
#define LINEDISCONNECTMODE_BLOCKED              0x00020000      // TAPI v2.0
#define LINEDISCONNECTMODE_DONOTDISTURB         0x00040000      // TAPI v2.0
#define LINEDISCONNECTMODE_CANCELLED            0x00080000      // TAPI v2.0
#endif

#define LINEERR_ALLOCATED                       0x80000001
#define LINEERR_BADDEVICEID                     0x80000002
#define LINEERR_BEARERMODEUNAVAIL               0x80000003
#define LINEERR_CALLUNAVAIL                     0x80000005
#define LINEERR_COMPLETIONOVERRUN               0x80000006
#define LINEERR_CONFERENCEFULL                  0x80000007
#define LINEERR_DIALBILLING                     0x80000008
#define LINEERR_DIALDIALTONE                    0x80000009
#define LINEERR_DIALPROMPT                      0x8000000A
#define LINEERR_DIALQUIET                       0x8000000B
#define LINEERR_INCOMPATIBLEAPIVERSION          0x8000000C
#define LINEERR_INCOMPATIBLEEXTVERSION          0x8000000D
#define LINEERR_INIFILECORRUPT                  0x8000000E
#define LINEERR_INUSE                           0x8000000F
#define LINEERR_INVALADDRESS                    0x80000010
#define LINEERR_INVALADDRESSID                  0x80000011
#define LINEERR_INVALADDRESSMODE                0x80000012
#define LINEERR_INVALADDRESSSTATE               0x80000013
#define LINEERR_INVALAPPHANDLE                  0x80000014
#define LINEERR_INVALAPPNAME                    0x80000015
#define LINEERR_INVALBEARERMODE                 0x80000016
#define LINEERR_INVALCALLCOMPLMODE              0x80000017
#define LINEERR_INVALCALLHANDLE                 0x80000018
#define LINEERR_INVALCALLPARAMS                 0x80000019
#define LINEERR_INVALCALLPRIVILEGE              0x8000001A
#define LINEERR_INVALCALLSELECT                 0x8000001B
#define LINEERR_INVALCALLSTATE                  0x8000001C
#define LINEERR_INVALCALLSTATELIST              0x8000001D
#define LINEERR_INVALCARD                       0x8000001E
#define LINEERR_INVALCOMPLETIONID               0x8000001F
#define LINEERR_INVALCONFCALLHANDLE             0x80000020
#define LINEERR_INVALCONSULTCALLHANDLE          0x80000021
#define LINEERR_INVALCOUNTRYCODE                0x80000022
#define LINEERR_INVALDEVICECLASS                0x80000023
#define LINEERR_INVALDEVICEHANDLE               0x80000024
#define LINEERR_INVALDIALPARAMS                 0x80000025
#define LINEERR_INVALDIGITLIST                  0x80000026
#define LINEERR_INVALDIGITMODE                  0x80000027
#define LINEERR_INVALDIGITS                     0x80000028
#define LINEERR_INVALEXTVERSION                 0x80000029
#define LINEERR_INVALGROUPID                    0x8000002A
#define LINEERR_INVALLINEHANDLE                 0x8000002B
#define LINEERR_INVALLINESTATE                  0x8000002C
#define LINEERR_INVALLOCATION                   0x8000002D
#define LINEERR_INVALMEDIALIST                  0x8000002E
#define LINEERR_INVALMEDIAMODE                  0x8000002F
#define LINEERR_INVALMESSAGEID                  0x80000030
#define LINEERR_INVALPARAM                      0x80000032
#define LINEERR_INVALPARKID                     0x80000033
#define LINEERR_INVALPARKMODE                   0x80000034
#define LINEERR_INVALPOINTER                    0x80000035
#define LINEERR_INVALPRIVSELECT                 0x80000036
#define LINEERR_INVALRATE                       0x80000037
#define LINEERR_INVALREQUESTMODE                0x80000038
#define LINEERR_INVALTERMINALID                 0x80000039
#define LINEERR_INVALTERMINALMODE               0x8000003A
#define LINEERR_INVALTIMEOUT                    0x8000003B
#define LINEERR_INVALTONE                       0x8000003C
#define LINEERR_INVALTONELIST                   0x8000003D
#define LINEERR_INVALTONEMODE                   0x8000003E
#define LINEERR_INVALTRANSFERMODE               0x8000003F
#define LINEERR_LINEMAPPERFAILED                0x80000040
#define LINEERR_NOCONFERENCE                    0x80000041
#define LINEERR_NODEVICE                        0x80000042
#define LINEERR_NODRIVER                        0x80000043
#define LINEERR_NOMEM                           0x80000044
#define LINEERR_NOREQUEST                       0x80000045
#define LINEERR_NOTOWNER                        0x80000046
#define LINEERR_NOTREGISTERED                   0x80000047
#define LINEERR_OPERATIONFAILED                 0x80000048
#define LINEERR_OPERATIONUNAVAIL                0x80000049
#define LINEERR_RATEUNAVAIL                     0x8000004A
#define LINEERR_RESOURCEUNAVAIL                 0x8000004B
#define LINEERR_REQUESTOVERRUN                  0x8000004C
#define LINEERR_STRUCTURETOOSMALL               0x8000004D
#define LINEERR_TARGETNOTFOUND                  0x8000004E
#define LINEERR_TARGETSELF                      0x8000004F
#define LINEERR_UNINITIALIZED                   0x80000050
#define LINEERR_USERUSERINFOTOOBIG              0x80000051
#define LINEERR_REINIT                          0x80000052
#define LINEERR_ADDRESSBLOCKED                  0x80000053
#define LINEERR_BILLINGREJECTED                 0x80000054
#define LINEERR_INVALFEATURE                    0x80000055
#define LINEERR_NOMULTIPLEINSTANCE              0x80000056
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define LINEERR_INVALAGENTID                    0x80000057      // TAPI v2.0
#define LINEERR_INVALAGENTGROUP                 0x80000058      // TAPI v2.0
#define LINEERR_INVALPASSWORD                   0x80000059      // TAPI v2.0
#define LINEERR_INVALAGENTSTATE                 0x8000005A      // TAPI v2.0
#define LINEERR_INVALAGENTACTIVITY              0x8000005B      // TAPI v2.0
#define LINEERR_DIALVOICEDETECT                 0x8000005C      // TAPI v2.0


#endif

#define LINEFEATURE_DEVSPECIFIC                 0x00000001
#define LINEFEATURE_DEVSPECIFICFEAT             0x00000002
#define LINEFEATURE_FORWARD                     0x00000004
#define LINEFEATURE_MAKECALL                    0x00000008
#define LINEFEATURE_SETMEDIACONTROL             0x00000010
#define LINEFEATURE_SETTERMINAL                 0x00000020
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define LINEFEATURE_SETDEVSTATUS                0x00000040      // TAPI v2.0
#define LINEFEATURE_FORWARDFWD                  0x00000080      // TAPI v2.0
#define LINEFEATURE_FORWARDDND                  0x00000100      // TAPI v2.0
#endif

#define LINEFORWARDMODE_UNCOND                  0x00000001
#define LINEFORWARDMODE_UNCONDINTERNAL          0x00000002
#define LINEFORWARDMODE_UNCONDEXTERNAL          0x00000004
#define LINEFORWARDMODE_UNCONDSPECIFIC          0x00000008
#define LINEFORWARDMODE_BUSY                    0x00000010
#define LINEFORWARDMODE_BUSYINTERNAL            0x00000020
#define LINEFORWARDMODE_BUSYEXTERNAL            0x00000040
#define LINEFORWARDMODE_BUSYSPECIFIC            0x00000080
#define LINEFORWARDMODE_NOANSW                  0x00000100
#define LINEFORWARDMODE_NOANSWINTERNAL          0x00000200
#define LINEFORWARDMODE_NOANSWEXTERNAL          0x00000400
#define LINEFORWARDMODE_NOANSWSPECIFIC          0x00000800
#define LINEFORWARDMODE_BUSYNA                  0x00001000
#define LINEFORWARDMODE_BUSYNAINTERNAL          0x00002000
#define LINEFORWARDMODE_BUSYNAEXTERNAL          0x00004000
#define LINEFORWARDMODE_BUSYNASPECIFIC          0x00008000
#define LINEFORWARDMODE_UNKNOWN                 0x00010000      // TAPI v1.4
#define LINEFORWARDMODE_UNAVAIL                 0x00020000      // TAPI v1.4

#define LINEGATHERTERM_BUFFERFULL               0x00000001
#define LINEGATHERTERM_TERMDIGIT                0x00000002
#define LINEGATHERTERM_FIRSTTIMEOUT             0x00000004
#define LINEGATHERTERM_INTERTIMEOUT             0x00000008
#define LINEGATHERTERM_CANCEL                   0x00000010

#define LINEGENERATETERM_DONE                   0x00000001
#define LINEGENERATETERM_CANCEL                 0x00000002

#if (TAPI_CURRENT_VERSION >= 0x00020000)
//
// These constants are mutually exclusive - there's no way to specify more
// than one at a time (and it doesn't make sense, either) so they're
// ordinal rather than bits.
//
#define LINEINITIALIZEEXOPTION_USEHIDDENWINDOW      0x00000001  // TAPI v2.0
#define LINEINITIALIZEEXOPTION_USEEVENT             0x00000002  // TAPI v2.0
#define LINEINITIALIZEEXOPTION_USECOMPLETIONPORT    0x00000003  // TAPI v2.0
#endif

#define LINELOCATIONOPTION_PULSEDIAL            0x00000001      // TAPI v1.4

#define LINEMAPPER                              0xFFFFFFFF

#define LINEMEDIACONTROL_NONE                   0x00000001
#define LINEMEDIACONTROL_START                  0x00000002
#define LINEMEDIACONTROL_RESET                  0x00000004
#define LINEMEDIACONTROL_PAUSE                  0x00000008
#define LINEMEDIACONTROL_RESUME                 0x00000010
#define LINEMEDIACONTROL_RATEUP                 0x00000020
#define LINEMEDIACONTROL_RATEDOWN               0x00000040
#define LINEMEDIACONTROL_RATENORMAL             0x00000080
#define LINEMEDIACONTROL_VOLUMEUP               0x00000100
#define LINEMEDIACONTROL_VOLUMEDOWN             0x00000200
#define LINEMEDIACONTROL_VOLUMENORMAL           0x00000400

#define LINEMEDIAMODE_UNKNOWN                   0x00000002
#define LINEMEDIAMODE_INTERACTIVEVOICE          0x00000004
#define LINEMEDIAMODE_AUTOMATEDVOICE            0x00000008
#define LINEMEDIAMODE_DATAMODEM                 0x00000010
#define LINEMEDIAMODE_G3FAX                     0x00000020
#define LINEMEDIAMODE_TDD                       0x00000040
#define LINEMEDIAMODE_G4FAX                     0x00000080
#define LINEMEDIAMODE_DIGITALDATA               0x00000100
#define LINEMEDIAMODE_TELETEX                   0x00000200
#define LINEMEDIAMODE_VIDEOTEX                  0x00000400
#define LINEMEDIAMODE_TELEX                     0x00000800
#define LINEMEDIAMODE_MIXED                     0x00001000
#define LINEMEDIAMODE_ADSI                      0x00002000
#define LINEMEDIAMODE_VOICEVIEW                 0x00004000      // TAPI v1.4
#define LAST_LINEMEDIAMODE                      0x00004000

#define LINEOFFERINGMODE_ACTIVE                 0x00000001      // TAPI v1.4
#define LINEOFFERINGMODE_INACTIVE               0x00000002      // TAPI v1.4

#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define LINEOPENOPTION_SINGLEADDRESS            0x80000000      // TAPI v2.0
#define LINEOPENOPTION_PROXY                    0x40000000      // TAPI v2.0
#endif

#define LINEPARKMODE_DIRECTED                   0x00000001
#define LINEPARKMODE_NONDIRECTED                0x00000002

#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define LINEPROXYREQUEST_SETAGENTGROUP          0x00000001      // TAPI v2.0
#define LINEPROXYREQUEST_SETAGENTSTATE          0x00000002      // TAPI v2.0
#define LINEPROXYREQUEST_SETAGENTACTIVITY       0x00000003      // TAPI v2.0
#define LINEPROXYREQUEST_GETAGENTCAPS           0x00000004      // TAPI v2.0
#define LINEPROXYREQUEST_GETAGENTSTATUS         0x00000005      // TAPI v2.0
#define LINEPROXYREQUEST_AGENTSPECIFIC          0x00000006      // TAPI v2.0
#define LINEPROXYREQUEST_GETAGENTACTIVITYLIST   0x00000007      // TAPI v2.0
#define LINEPROXYREQUEST_GETAGENTGROUPLIST      0x00000008      // TAPI v2.0
#endif

#define LINEREMOVEFROMCONF_NONE                 0x00000001
#define LINEREMOVEFROMCONF_LAST                 0x00000002
#define LINEREMOVEFROMCONF_ANY                  0x00000003

#define LINEREQUESTMODE_MAKECALL                0x00000001
#define LINEREQUESTMODE_MEDIACALL               0x00000002
#define LINEREQUESTMODE_DROP                    0x00000004
#define LAST_LINEREQUESTMODE                    LINEREQUESTMODE_MEDIACALL

#define LINEROAMMODE_UNKNOWN                    0x00000001
#define LINEROAMMODE_UNAVAIL                    0x00000002
#define LINEROAMMODE_HOME                       0x00000004
#define LINEROAMMODE_ROAMA                      0x00000008
#define LINEROAMMODE_ROAMB                      0x00000010

#define LINESPECIALINFO_NOCIRCUIT               0x00000001
#define LINESPECIALINFO_CUSTIRREG               0x00000002
#define LINESPECIALINFO_REORDER                 0x00000004
#define LINESPECIALINFO_UNKNOWN                 0x00000008
#define LINESPECIALINFO_UNAVAIL                 0x00000010

#define LINETERMDEV_PHONE                       0x00000001
#define LINETERMDEV_HEADSET                     0x00000002
#define LINETERMDEV_SPEAKER                     0x00000004

#define LINETERMMODE_BUTTONS                    0x00000001
#define LINETERMMODE_LAMPS                      0x00000002
#define LINETERMMODE_DISPLAY                    0x00000004
#define LINETERMMODE_RINGER                     0x00000008
#define LINETERMMODE_HOOKSWITCH                 0x00000010
#define LINETERMMODE_MEDIATOLINE                0x00000020
#define LINETERMMODE_MEDIAFROMLINE              0x00000040
#define LINETERMMODE_MEDIABIDIRECT              0x00000080

#define LINETERMSHARING_PRIVATE                 0x00000001
#define LINETERMSHARING_SHAREDEXCL              0x00000002
#define LINETERMSHARING_SHAREDCONF              0x00000004

#define LINETOLLLISTOPTION_ADD                  0x00000001
#define LINETOLLLISTOPTION_REMOVE               0x00000002

#define LINETONEMODE_CUSTOM                     0x00000001
#define LINETONEMODE_RINGBACK                   0x00000002
#define LINETONEMODE_BUSY                       0x00000004
#define LINETONEMODE_BEEP                       0x00000008
#define LINETONEMODE_BILLING                    0x00000010

#define LINETRANSFERMODE_TRANSFER               0x00000001
#define LINETRANSFERMODE_CONFERENCE             0x00000002

#define LINETRANSLATEOPTION_CARDOVERRIDE        0x00000001
#define LINETRANSLATEOPTION_CANCELCALLWAITING   0x00000002      // TAPI v1.4
#define LINETRANSLATEOPTION_FORCELOCAL          0x00000004      // TAPI v1.4
#define LINETRANSLATEOPTION_FORCELD             0x00000008      // TAPI v1.4

#define LINETRANSLATERESULT_CANONICAL           0x00000001
#define LINETRANSLATERESULT_INTERNATIONAL       0x00000002
#define LINETRANSLATERESULT_LONGDISTANCE        0x00000004
#define LINETRANSLATERESULT_LOCAL               0x00000008
#define LINETRANSLATERESULT_INTOLLLIST          0x00000010
#define LINETRANSLATERESULT_NOTINTOLLLIST       0x00000020
#define LINETRANSLATERESULT_DIALBILLING         0x00000040
#define LINETRANSLATERESULT_DIALQUIET           0x00000080
#define LINETRANSLATERESULT_DIALDIALTONE        0x00000100
#define LINETRANSLATERESULT_DIALPROMPT          0x00000200
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define LINETRANSLATERESULT_VOICEDETECT         0x00000400      // TAPI v2.0
#endif

#define PHONEBUTTONFUNCTION_UNKNOWN             0x00000000
#define PHONEBUTTONFUNCTION_CONFERENCE          0x00000001
#define PHONEBUTTONFUNCTION_TRANSFER            0x00000002
#define PHONEBUTTONFUNCTION_DROP                0x00000003
#define PHONEBUTTONFUNCTION_HOLD                0x00000004
#define PHONEBUTTONFUNCTION_RECALL              0x00000005
#define PHONEBUTTONFUNCTION_DISCONNECT          0x00000006
#define PHONEBUTTONFUNCTION_CONNECT             0x00000007
#define PHONEBUTTONFUNCTION_MSGWAITON           0x00000008
#define PHONEBUTTONFUNCTION_MSGWAITOFF          0x00000009
#define PHONEBUTTONFUNCTION_SELECTRING          0x0000000A
#define PHONEBUTTONFUNCTION_ABBREVDIAL          0x0000000B
#define PHONEBUTTONFUNCTION_FORWARD             0x0000000C
#define PHONEBUTTONFUNCTION_PICKUP              0x0000000D
#define PHONEBUTTONFUNCTION_RINGAGAIN           0x0000000E
#define PHONEBUTTONFUNCTION_PARK                0x0000000F
#define PHONEBUTTONFUNCTION_REJECT              0x00000010
#define PHONEBUTTONFUNCTION_REDIRECT            0x00000011
#define PHONEBUTTONFUNCTION_MUTE                0x00000012
#define PHONEBUTTONFUNCTION_VOLUMEUP            0x00000013
#define PHONEBUTTONFUNCTION_VOLUMEDOWN          0x00000014
#define PHONEBUTTONFUNCTION_SPEAKERON           0x00000015
#define PHONEBUTTONFUNCTION_SPEAKEROFF          0x00000016
#define PHONEBUTTONFUNCTION_FLASH               0x00000017
#define PHONEBUTTONFUNCTION_DATAON              0x00000018
#define PHONEBUTTONFUNCTION_DATAOFF             0x00000019
#define PHONEBUTTONFUNCTION_DONOTDISTURB        0x0000001A
#define PHONEBUTTONFUNCTION_INTERCOM            0x0000001B
#define PHONEBUTTONFUNCTION_BRIDGEDAPP          0x0000001C
#define PHONEBUTTONFUNCTION_BUSY                0x0000001D
#define PHONEBUTTONFUNCTION_CALLAPP             0x0000001E
#define PHONEBUTTONFUNCTION_DATETIME            0x0000001F
#define PHONEBUTTONFUNCTION_DIRECTORY           0x00000020
#define PHONEBUTTONFUNCTION_COVER               0x00000021
#define PHONEBUTTONFUNCTION_CALLID              0x00000022
#define PHONEBUTTONFUNCTION_LASTNUM             0x00000023
#define PHONEBUTTONFUNCTION_NIGHTSRV            0x00000024
#define PHONEBUTTONFUNCTION_SENDCALLS           0x00000025
#define PHONEBUTTONFUNCTION_MSGINDICATOR        0x00000026
#define PHONEBUTTONFUNCTION_REPDIAL             0x00000027
#define PHONEBUTTONFUNCTION_SETREPDIAL          0x00000028
#define PHONEBUTTONFUNCTION_SYSTEMSPEED         0x00000029
#define PHONEBUTTONFUNCTION_STATIONSPEED        0x0000002A
#define PHONEBUTTONFUNCTION_CAMPON              0x0000002B
#define PHONEBUTTONFUNCTION_SAVEREPEAT          0x0000002C
#define PHONEBUTTONFUNCTION_QUEUECALL           0x0000002D
#define PHONEBUTTONFUNCTION_NONE                0x0000002E

#define PHONEBUTTONMODE_DUMMY                   0x00000001
#define PHONEBUTTONMODE_CALL                    0x00000002
#define PHONEBUTTONMODE_FEATURE                 0x00000004
#define PHONEBUTTONMODE_KEYPAD                  0x00000008
#define PHONEBUTTONMODE_LOCAL                   0x00000010
#define PHONEBUTTONMODE_DISPLAY                 0x00000020

#define PHONEBUTTONSTATE_UP                     0x00000001
#define PHONEBUTTONSTATE_DOWN                   0x00000002
#define PHONEBUTTONSTATE_UNKNOWN                0x00000004      // TAPI v1.4
#define PHONEBUTTONSTATE_UNAVAIL                0x00000008      // TAPI v1.4

#define PHONEERR_ALLOCATED                      0x90000001
#define PHONEERR_BADDEVICEID                    0x90000002
#define PHONEERR_INCOMPATIBLEAPIVERSION         0x90000003
#define PHONEERR_INCOMPATIBLEEXTVERSION         0x90000004
#define PHONEERR_INIFILECORRUPT                 0x90000005
#define PHONEERR_INUSE                          0x90000006
#define PHONEERR_INVALAPPHANDLE                 0x90000007
#define PHONEERR_INVALAPPNAME                   0x90000008
#define PHONEERR_INVALBUTTONLAMPID              0x90000009
#define PHONEERR_INVALBUTTONMODE                0x9000000A
#define PHONEERR_INVALBUTTONSTATE               0x9000000B
#define PHONEERR_INVALDATAID                    0x9000000C
#define PHONEERR_INVALDEVICECLASS               0x9000000D
#define PHONEERR_INVALEXTVERSION                0x9000000E
#define PHONEERR_INVALHOOKSWITCHDEV             0x9000000F
#define PHONEERR_INVALHOOKSWITCHMODE            0x90000010
#define PHONEERR_INVALLAMPMODE                  0x90000011
#define PHONEERR_INVALPARAM                     0x90000012
#define PHONEERR_INVALPHONEHANDLE               0x90000013
#define PHONEERR_INVALPHONESTATE                0x90000014
#define PHONEERR_INVALPOINTER                   0x90000015
#define PHONEERR_INVALPRIVILEGE                 0x90000016
#define PHONEERR_INVALRINGMODE                  0x90000017
#define PHONEERR_NODEVICE                       0x90000018
#define PHONEERR_NODRIVER                       0x90000019
#define PHONEERR_NOMEM                          0x9000001A
#define PHONEERR_NOTOWNER                       0x9000001B
#define PHONEERR_OPERATIONFAILED                0x9000001C
#define PHONEERR_OPERATIONUNAVAIL               0x9000001D
#define PHONEERR_RESOURCEUNAVAIL                0x9000001F
#define PHONEERR_REQUESTOVERRUN                 0x90000020
#define PHONEERR_STRUCTURETOOSMALL              0x90000021
#define PHONEERR_UNINITIALIZED                  0x90000022
#define PHONEERR_REINIT                         0x90000023


#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define PHONEFEATURE_GETBUTTONINFO              0x00000001      // TAPI v2.0
#define PHONEFEATURE_GETDATA                    0x00000002      // TAPI v2.0
#define PHONEFEATURE_GETDISPLAY                 0x00000004      // TAPI v2.0
#define PHONEFEATURE_GETGAINHANDSET             0x00000008      // TAPI v2.0
#define PHONEFEATURE_GETGAINSPEAKER             0x00000010      // TAPI v2.0
#define PHONEFEATURE_GETGAINHEADSET             0x00000020      // TAPI v2.0
#define PHONEFEATURE_GETHOOKSWITCHHANDSET       0x00000040      // TAPI v2.0
#define PHONEFEATURE_GETHOOKSWITCHSPEAKER       0x00000080      // TAPI v2.0
#define PHONEFEATURE_GETHOOKSWITCHHEADSET       0x00000100      // TAPI v2.0
#define PHONEFEATURE_GETLAMP                    0x00000200      // TAPI v2.0
#define PHONEFEATURE_GETRING                    0x00000400      // TAPI v2.0
#define PHONEFEATURE_GETVOLUMEHANDSET           0x00000800      // TAPI v2.0
#define PHONEFEATURE_GETVOLUMESPEAKER           0x00001000      // TAPI v2.0
#define PHONEFEATURE_GETVOLUMEHEADSET           0x00002000      // TAPI v2.0
#define PHONEFEATURE_SETBUTTONINFO              0x00004000      // TAPI v2.0
#define PHONEFEATURE_SETDATA                    0x00008000      // TAPI v2.0
#define PHONEFEATURE_SETDISPLAY                 0x00010000      // TAPI v2.0
#define PHONEFEATURE_SETGAINHANDSET             0x00020000      // TAPI v2.0
#define PHONEFEATURE_SETGAINSPEAKER             0x00040000      // TAPI v2.0
#define PHONEFEATURE_SETGAINHEADSET             0x00080000      // TAPI v2.0
#define PHONEFEATURE_SETHOOKSWITCHHANDSET       0x00100000      // TAPI v2.0
#define PHONEFEATURE_SETHOOKSWITCHSPEAKER       0x00200000      // TAPI v2.0
#define PHONEFEATURE_SETHOOKSWITCHHEADSET       0x00400000      // TAPI v2.0
#define PHONEFEATURE_SETLAMP                    0x00800000      // TAPI v2.0
#define PHONEFEATURE_SETRING                    0x01000000      // TAPI v2.0
#define PHONEFEATURE_SETVOLUMEHANDSET           0x02000000      // TAPI v2.0
#define PHONEFEATURE_SETVOLUMESPEAKER           0x04000000      // TAPI v2.0
#define PHONEFEATURE_SETVOLUMEHEADSET           0x08000000      // TAPI v2.0
#endif

#define PHONEHOOKSWITCHDEV_HANDSET              0x00000001
#define PHONEHOOKSWITCHDEV_SPEAKER              0x00000002
#define PHONEHOOKSWITCHDEV_HEADSET              0x00000004

#define PHONEHOOKSWITCHMODE_ONHOOK              0x00000001
#define PHONEHOOKSWITCHMODE_MIC                 0x00000002
#define PHONEHOOKSWITCHMODE_SPEAKER             0x00000004
#define PHONEHOOKSWITCHMODE_MICSPEAKER          0x00000008
#define PHONEHOOKSWITCHMODE_UNKNOWN             0x00000010

#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define PHONEINITIALIZEEXOPTION_USEHIDDENWINDOW     0x00000001  // TAPI v2.0
#define PHONEINITIALIZEEXOPTION_USEEVENT            0x00000002  // TAPI v2.0
#define PHONEINITIALIZEEXOPTION_USECOMPLETIONPORT   0x00000003  // TAPI v2.0
#endif

#define PHONELAMPMODE_DUMMY                     0x00000001
#define PHONELAMPMODE_OFF                       0x00000002
#define PHONELAMPMODE_STEADY                    0x00000004
#define PHONELAMPMODE_WINK                      0x00000008
#define PHONELAMPMODE_FLASH                     0x00000010
#define PHONELAMPMODE_FLUTTER                   0x00000020
#define PHONELAMPMODE_BROKENFLUTTER             0x00000040
#define PHONELAMPMODE_UNKNOWN                   0x00000080

#define PHONEPRIVILEGE_MONITOR                  0x00000001
#define PHONEPRIVILEGE_OWNER                    0x00000002

#define PHONESTATE_OTHER                        0x00000001
#define PHONESTATE_CONNECTED                    0x00000002
#define PHONESTATE_DISCONNECTED                 0x00000004
#define PHONESTATE_OWNER                        0x00000008
#define PHONESTATE_MONITORS                     0x00000010
#define PHONESTATE_DISPLAY                      0x00000020
#define PHONESTATE_LAMP                         0x00000040
#define PHONESTATE_RINGMODE                     0x00000080
#define PHONESTATE_RINGVOLUME                   0x00000100
#define PHONESTATE_HANDSETHOOKSWITCH            0x00000200
#define PHONESTATE_HANDSETVOLUME                0x00000400
#define PHONESTATE_HANDSETGAIN                  0x00000800
#define PHONESTATE_SPEAKERHOOKSWITCH            0x00001000
#define PHONESTATE_SPEAKERVOLUME                0x00002000
#define PHONESTATE_SPEAKERGAIN                  0x00004000
#define PHONESTATE_HEADSETHOOKSWITCH            0x00008000
#define PHONESTATE_HEADSETVOLUME                0x00010000
#define PHONESTATE_HEADSETGAIN                  0x00020000
#define PHONESTATE_SUSPEND                      0x00040000
#define PHONESTATE_RESUME                       0x00080000
#define PHONESTATE_DEVSPECIFIC                  0x00100000
#define PHONESTATE_REINIT                       0x00200000
#define PHONESTATE_CAPSCHANGE                   0x00400000      // TAPI v1.4
#define PHONESTATE_REMOVED                      0x00800000      // TAPI v1.4

#define PHONESTATUSFLAGS_CONNECTED              0x00000001
#define PHONESTATUSFLAGS_SUSPENDED              0x00000002

#define STRINGFORMAT_ASCII                      0x00000001
#define STRINGFORMAT_DBCS                       0x00000002
#define STRINGFORMAT_UNICODE                    0x00000003
#define STRINGFORMAT_BINARY                     0x00000004

#define TAPI_REPLY                              WM_USER + 99

#define TAPIERR_CONNECTED                       0L
#define TAPIERR_DROPPED                         -1L
#define TAPIERR_NOREQUESTRECIPIENT              -2L
#define TAPIERR_REQUESTQUEUEFULL                -3L
#define TAPIERR_INVALDESTADDRESS                -4L
#define TAPIERR_INVALWINDOWHANDLE               -5L
#define TAPIERR_INVALDEVICECLASS                -6L
#define TAPIERR_INVALDEVICEID                   -7L
#define TAPIERR_DEVICECLASSUNAVAIL              -8L
#define TAPIERR_DEVICEIDUNAVAIL                 -9L
#define TAPIERR_DEVICEINUSE                     -10L
#define TAPIERR_DESTBUSY                        -11L
#define TAPIERR_DESTNOANSWER                    -12L
#define TAPIERR_DESTUNAVAIL                     -13L
#define TAPIERR_UNKNOWNWINHANDLE                -14L
#define TAPIERR_UNKNOWNREQUESTID                -15L
#define TAPIERR_REQUESTFAILED                   -16L
#define TAPIERR_REQUESTCANCELLED                -17L
#define TAPIERR_INVALPOINTER                    -18L


#define TAPIMAXDESTADDRESSSIZE                  80L
#define TAPIMAXAPPNAMESIZE                      40L
#define TAPIMAXCALLEDPARTYSIZE                  40L
#define TAPIMAXCOMMENTSIZE                      80L
#define TAPIMAXDEVICECLASSSIZE                  40L
#define TAPIMAXDEVICEIDSIZE                     40L



typedef struct lineaddresscaps_tag
{
    unsigned long       dwTotalSize;
    unsigned long       dwNeededSize;
    unsigned long       dwUsedSize;
    unsigned long       dwLineDeviceID;
    unsigned long       dwAddressSize;
    unsigned long       dwAddressOffset;
    unsigned long       dwDevSpecificSize;
    unsigned long       dwDevSpecificOffset;
    unsigned long       dwAddressSharing;
    unsigned long       dwAddressStates;
    unsigned long       dwCallInfoStates;
    unsigned long       dwCallerIDFlags;
    unsigned long       dwCalledIDFlags;
    unsigned long       dwConnectedIDFlags;
    unsigned long       dwRedirectionIDFlags;
    unsigned long       dwRedirectingIDFlags;
    unsigned long       dwCallStates;
    unsigned long       dwDialToneModes;
    unsigned long       dwBusyModes;
    unsigned long       dwSpecialInfo;
    unsigned long       dwDisconnectModes;
    unsigned long       dwMaxNumActiveCalls;
    unsigned long       dwMaxNumOnHoldCalls;
    unsigned long       dwMaxNumOnHoldPendingCalls;
    unsigned long       dwMaxNumConference;
    unsigned long       dwMaxNumTransConf;
    unsigned long       dwAddrCapFlags;
    unsigned long       dwCallFeatures;
    unsigned long       dwRemoveFromConfCaps;
    unsigned long       dwRemoveFromConfState;
    unsigned long       dwTransferModes;
    unsigned long       dwParkModes;
    unsigned long       dwForwardModes;
    unsigned long       dwMaxForwardEntries;
    unsigned long       dwMaxSpecificEntries;
    unsigned long       dwMinFwdNumRings;
    unsigned long       dwMaxFwdNumRings;
    unsigned long       dwMaxCallCompletions;
    unsigned long       dwCallCompletionConds;
    unsigned long       dwCallCompletionModes;
    unsigned long       dwNumCompletionMessages;
    unsigned long       dwCompletionMsgTextEntrySize;
    unsigned long       dwCompletionMsgTextSize;
    unsigned long       dwCompletionMsgTextOffset;

    unsigned long       dwAddressFeatures;                              // TAPI v1.4

#if (TAPI_CURRENT_VERSION >= 0x00020000)
    unsigned long       dwPredictiveAutoTransferStates;                 // TAPI v2.0
    unsigned long       dwNumCallTreatments;                            // TAPI v2.0
    unsigned long       dwCallTreatmentListSize;                        // TAPI v2.0
    unsigned long       dwCallTreatmentListOffset;                      // TAPI v2.0
    unsigned long       dwDeviceClassesSize;                            // TAPI v2.0
    unsigned long       dwDeviceClassesOffset;                          // TAPI v2.0
    unsigned long       dwMaxCallDataSize;                              // TAPI v2.0
    unsigned long       dwCallFeatures2;                                // TAPI v2.0
    unsigned long       dwMaxNoAnswerTimeout;                           // TAPI v2.0
    unsigned long       dwConnectedModes;                               // TAPI v2.0
    unsigned long       dwOfferingModes;                                // TAPI v2.0
    unsigned long       dwAvailableMediaModes;                          // TAPI v2.0
#endif

} LINEADDRESSCAPS,  *LPLINEADDRESSCAPS;

typedef struct lineaddressstatus_tag
{
    unsigned long       dwTotalSize;
    unsigned long       dwNeededSize;
    unsigned long       dwUsedSize;
    unsigned long       dwNumInUse;
    unsigned long       dwNumActiveCalls;
    unsigned long       dwNumOnHoldCalls;
    unsigned long       dwNumOnHoldPendCalls;
    unsigned long       dwAddressFeatures;
    unsigned long       dwNumRingsNoAnswer;
    unsigned long       dwForwardNumEntries;
    unsigned long       dwForwardSize;
    unsigned long       dwForwardOffset;
    unsigned long       dwTerminalModesSize;
    unsigned long       dwTerminalModesOffset;
    unsigned long       dwDevSpecificSize;
    unsigned long       dwDevSpecificOffset;

} LINEADDRESSSTATUS,  *LPLINEADDRESSSTATUS;

#if (TAPI_CURRENT_VERSION >= 0x00020000)
typedef struct lineagentactivityentry_tag
{
    unsigned long       dwID;                                           // TAPI v2.0
    unsigned long       dwNameSize;                                     // TAPI v2.0
    unsigned long       dwNameOffset;                                   // TAPI v2.0

} LINEAGENTACTIVITYENTRY, *LPLINEAGENTACTIVITYENTRY;

typedef struct lineagentactivitylist_tag
{
    unsigned long       dwTotalSize;                                    // TAPI v2.0
    unsigned long       dwNeededSize;                                   // TAPI v2.0
    unsigned long       dwUsedSize;                                     // TAPI v2.0
    unsigned long       dwNumEntries;                                   // TAPI v2.0
    unsigned long       dwListSize;                                     // TAPI v2.0
    unsigned long       dwListOffset;                                   // TAPI v2.0

} LINEAGENTACTIVITYLIST, *LPLINEAGENTACTIVITYLIST;

typedef struct lineagentcaps_tag
{
    unsigned long       dwTotalSize;                                    // TAPI v2.0
    unsigned long       dwNeededSize;                                   // TAPI v2.0
    unsigned long       dwUsedSize;                                     // TAPI v2.0
    unsigned long       dwAgentHandlerInfoSize;                         // TAPI v2.0
    unsigned long       dwAgentHandlerInfoOffset;                       // TAPI v2.0
    unsigned long       dwCapsVersion;                                  // TAPI v2.0
    unsigned long       dwFeatures;                                     // TAPI v2.0
    unsigned long       dwStates;                                       // TAPI v2.0
    unsigned long       dwNextStates;                                   // TAPI v2.0
    unsigned long       dwMaxNumGroupEntries;                           // TAPI v2.0
    unsigned long       dwAgentStatusMessages;                          // TAPI v2.0
    unsigned long       dwNumAgentExtensionIDs;                         // TAPI v2.0
    unsigned long       dwAgentExtensionIDListSize;                     // TAPI v2.0
    unsigned long       dwAgentExtensionIDListOffset;                   // TAPI v2.0

} LINEAGENTCAPS, *LPLINEAGENTCAPS;

typedef struct lineagentgroupentry_tag
{
    struct
    {
        unsigned long   dwGroupID1;                                     // TAPI v2.0
        unsigned long   dwGroupID2;                                     // TAPI v2.0
        unsigned long   dwGroupID3;                                     // TAPI v2.0
        unsigned long   dwGroupID4;                                     // TAPI v2.0

    } GroupID;

    unsigned long       dwNameSize;                                     // TAPI v2.0
    unsigned long       dwNameOffset;                                   // TAPI v2.0

} LINEAGENTGROUPENTRY, *LPLINEAGENTGROUPENTRY;

typedef struct lineagentgrouplist_tag
{
    unsigned long       dwTotalSize;                                    // TAPI v2.0
    unsigned long       dwNeededSize;                                   // TAPI v2.0
    unsigned long       dwUsedSize;                                     // TAPI v2.0
    unsigned long       dwNumEntries;                                   // TAPI v2.0
    unsigned long       dwListSize;                                     // TAPI v2.0
    unsigned long       dwListOffset;                                   // TAPI v2.0

} LINEAGENTGROUPLIST, *LPLINEAGENTGROUPLIST;

typedef struct lineagentstatus_tag
{
    unsigned long       dwTotalSize;                                    // TAPI v2.0
    unsigned long       dwNeededSize;                                   // TAPI v2.0
    unsigned long       dwUsedSize;                                     // TAPI v2.0
    unsigned long       dwNumEntries;                                   // TAPI v2.0
    unsigned long       dwGroupListSize;                                // TAPI v2.0
    unsigned long       dwGroupListOffset;                              // TAPI v2.0
    unsigned long       dwState;                                        // TAPI v2.0
    unsigned long       dwNextState;                                    // TAPI v2.0
    unsigned long       dwActivityID;                                   // TAPI v2.0
    unsigned long       dwActivitySize;                                 // TAPI v2.0
    unsigned long       dwActivityOffset;                               // TAPI v2.0
    unsigned long       dwAgentFeatures;                                // TAPI v2.0
    unsigned long       dwValidStates;                                  // TAPI v2.0
    unsigned long       dwValidNextStates;                              // TAPI v2.0

} LINEAGENTSTATUS, *LPLINEAGENTSTATUS;

typedef struct lineappinfo_tag
{
    unsigned long       dwMachineNameSize;                              // TAPI v2.0
    unsigned long       dwMachineNameOffset;                            // TAPI v2.0
    unsigned long       dwUserNameSize;                                 // TAPI v2.0
    unsigned long       dwUserNameOffset;                               // TAPI v2.0
    unsigned long       dwModuleFilenameSize;                           // TAPI v2.0
    unsigned long       dwModuleFilenameOffset;                         // TAPI v2.0
    unsigned long       dwFriendlyNameSize;                             // TAPI v2.0
    unsigned long       dwFriendlyNameOffset;                           // TAPI v2.0
    unsigned long       dwMediaModes;                                   // TAPI v2.0
    unsigned long       dwAddressID;                                    // TAPI v2.0

} LINEAPPINFO, *LPLINEAPPINFO;
#endif


typedef struct linedialparams_tag
{
    unsigned long       dwDialPause;
    unsigned long       dwDialSpeed;
    unsigned long       dwDigitDuration;
    unsigned long       dwWaitForDialtone;

} LINEDIALPARAMS,  *LPLINEDIALPARAMS;

typedef struct linecallinfo_tag
{
    unsigned long       dwTotalSize;
    unsigned long       dwNeededSize;
    unsigned long       dwUsedSize;
    HLINE       hLine;
    unsigned long       dwLineDeviceID;
    unsigned long       dwAddressID;
    unsigned long       dwBearerMode;
    unsigned long       dwRate;
    unsigned long       dwMediaMode;
    unsigned long       dwAppSpecific;
    unsigned long       dwCallID;
    unsigned long       dwRelatedCallID;
    unsigned long       dwCallParamFlags;
    unsigned long       dwCallStates;
    unsigned long       dwMonitorDigitModes;
    unsigned long       dwMonitorMediaModes;
    LINEDIALPARAMS  DialParams;
    unsigned long       dwOrigin;
    unsigned long       dwReason;
    unsigned long       dwCompletionID;
    unsigned long       dwNumOwners;
    unsigned long       dwNumMonitors;
    unsigned long       dwCountryCode;
    unsigned long       dwTrunk;
    unsigned long       dwCallerIDFlags;
    unsigned long       dwCallerIDSize;
    unsigned long       dwCallerIDOffset;
    unsigned long       dwCallerIDNameSize;
    unsigned long       dwCallerIDNameOffset;
    unsigned long       dwCalledIDFlags;
    unsigned long       dwCalledIDSize;
    unsigned long       dwCalledIDOffset;
    unsigned long       dwCalledIDNameSize;
    unsigned long       dwCalledIDNameOffset;
    unsigned long       dwConnectedIDFlags;
    unsigned long       dwConnectedIDSize;
    unsigned long       dwConnectedIDOffset;
    unsigned long       dwConnectedIDNameSize;
    unsigned long       dwConnectedIDNameOffset;
    unsigned long       dwRedirectionIDFlags;
    unsigned long       dwRedirectionIDSize;
    unsigned long       dwRedirectionIDOffset;
    unsigned long       dwRedirectionIDNameSize;
    unsigned long       dwRedirectionIDNameOffset;
    unsigned long       dwRedirectingIDFlags;
    unsigned long       dwRedirectingIDSize;
    unsigned long       dwRedirectingIDOffset;
    unsigned long       dwRedirectingIDNameSize;
    unsigned long       dwRedirectingIDNameOffset;
    unsigned long       dwAppNameSize;
    unsigned long       dwAppNameOffset;
    unsigned long       dwDisplayableAddressSize;
    unsigned long       dwDisplayableAddressOffset;
    unsigned long       dwCalledPartySize;
    unsigned long       dwCalledPartyOffset;
    unsigned long       dwCommentSize;
    unsigned long       dwCommentOffset;
    unsigned long       dwDisplaySize;
    unsigned long       dwDisplayOffset;
    unsigned long       dwUserUserInfoSize;
    unsigned long       dwUserUserInfoOffset;
    unsigned long       dwHighLevelCompSize;
    unsigned long       dwHighLevelCompOffset;
    unsigned long       dwLowLevelCompSize;
    unsigned long       dwLowLevelCompOffset;
    unsigned long       dwChargingInfoSize;
    unsigned long       dwChargingInfoOffset;
    unsigned long       dwTerminalModesSize;
    unsigned long       dwTerminalModesOffset;
    unsigned long       dwDevSpecificSize;
    unsigned long       dwDevSpecificOffset;

#if (TAPI_CURRENT_VERSION >= 0x00020000)
    unsigned long       dwCallTreatment;                                // TAPI v2.0
    unsigned long       dwCallDataSize;                                 // TAPI v2.0
    unsigned long       dwCallDataOffset;                               // TAPI v2.0
    unsigned long       dwSendingFlowspecSize;                          // TAPI v2.0
    unsigned long       dwSendingFlowspecOffset;                        // TAPI v2.0
    unsigned long       dwReceivingFlowspecSize;                        // TAPI v2.0
    unsigned long       dwReceivingFlowspecOffset;                      // TAPI v2.0
#endif

} LINECALLINFO,  *LPLINECALLINFO;

typedef struct linecalllist_tag
{
    unsigned long       dwTotalSize;
    unsigned long       dwNeededSize;
    unsigned long       dwUsedSize;
    unsigned long       dwCallsNumEntries;
    unsigned long       dwCallsSize;
    unsigned long       dwCallsOffset;

} LINECALLLIST,  *LPLINECALLLIST;

typedef struct linecallparams_tag               // Defaults:
{
    unsigned long       dwTotalSize;                    // ---------
    unsigned long       dwBearerMode;                   // voice
    unsigned long       dwMinRate;                      // (3.1kHz)
    unsigned long       dwMaxRate;                      // (3.1kHz)
    unsigned long       dwMediaMode;                    // interactiveVoice
    unsigned long       dwCallParamFlags;               // 0
    unsigned long       dwAddressMode;                  // addressID
    unsigned long       dwAddressID;                    // (any available)
    LINEDIALPARAMS  DialParams;                 // (0, 0, 0, 0)
    unsigned long       dwOrigAddressSize;              // 0
    unsigned long       dwOrigAddressOffset;
    unsigned long       dwDisplayableAddressSize;
    unsigned long       dwDisplayableAddressOffset;
    unsigned long       dwCalledPartySize;              // 0
    unsigned long       dwCalledPartyOffset;
    unsigned long       dwCommentSize;                  // 0
    unsigned long       dwCommentOffset;
    unsigned long       dwUserUserInfoSize;             // 0
    unsigned long       dwUserUserInfoOffset;
    unsigned long       dwHighLevelCompSize;            // 0
    unsigned long       dwHighLevelCompOffset;
    unsigned long       dwLowLevelCompSize;             // 0
    unsigned long       dwLowLevelCompOffset;
    unsigned long       dwDevSpecificSize;              // 0
    unsigned long       dwDevSpecificOffset;

#if (TAPI_CURRENT_VERSION >= 0x00020000)
    unsigned long       dwPredictiveAutoTransferStates;                 // TAPI v2.0
    unsigned long       dwTargetAddressSize;                            // TAPI v2.0
    unsigned long       dwTargetAddressOffset;                          // TAPI v2.0
    unsigned long       dwSendingFlowspecSize;                          // TAPI v2.0
    unsigned long       dwSendingFlowspecOffset;                        // TAPI v2.0
    unsigned long       dwReceivingFlowspecSize;                        // TAPI v2.0
    unsigned long       dwReceivingFlowspecOffset;                      // TAPI v2.0
    unsigned long       dwDeviceClassSize;                              // TAPI v2.0
    unsigned long       dwDeviceClassOffset;                            // TAPI v2.0
    unsigned long       dwDeviceConfigSize;                             // TAPI v2.0
    unsigned long       dwDeviceConfigOffset;                           // TAPI v2.0
    unsigned long       dwCallDataSize;                                 // TAPI v2.0
    unsigned long       dwCallDataOffset;                               // TAPI v2.0
    unsigned long       dwNoAnswerTimeout;                              // TAPI v2.0
    unsigned long       dwCallingPartyIDSize;                           // TAPI v2.0
    unsigned long       dwCallingPartyIDOffset;                         // TAPI v2.0
#endif

} LINECALLPARAMS,  *LPLINECALLPARAMS;

typedef struct linecallstatus_tag
{
    unsigned long       dwTotalSize;
    unsigned long       dwNeededSize;
    unsigned long       dwUsedSize;
    unsigned long       dwCallState;
    unsigned long       dwCallStateMode;
    unsigned long       dwCallPrivilege;
    unsigned long       dwCallFeatures;
    unsigned long       dwDevSpecificSize;
    unsigned long       dwDevSpecificOffset;

#if (TAPI_CURRENT_VERSION >= 0x00020000)
    unsigned long       dwCallFeatures2;                                // TAPI v2.0
#if WIN32
    SYSTEMTIME  tStateEntryTime;                                // TAPI v2.0
#else
    WORD        tStateEntryTime[8];                             // TAPI v2.0
#endif
#endif

} LINECALLSTATUS,  *LPLINECALLSTATUS;


#if (TAPI_CURRENT_VERSION >= 0x00020000)
typedef struct linecalltreatmententry_tag
{
    unsigned long       dwCallTreatmentID;                              // TAPI v2.0
    unsigned long       dwCallTreatmentNameSize;                        // TAPI v2.0
    unsigned long       dwCallTreatmentNameOffset;                      // TAPI v2.0

} LINECALLTREATMENTENTRY,  *LPLINECALLTREATMENTENTRY;
#endif


typedef struct linecardentry_tag
{
    unsigned long       dwPermanentCardID;
    unsigned long       dwCardNameSize;
    unsigned long       dwCardNameOffset;
    unsigned long       dwCardNumberDigits;                             // TAPI v1.4
    unsigned long       dwSameAreaRuleSize;                             // TAPI v1.4
    unsigned long       dwSameAreaRuleOffset;                           // TAPI v1.4
    unsigned long       dwLongDistanceRuleSize;                         // TAPI v1.4
    unsigned long       dwLongDistanceRuleOffset;                       // TAPI v1.4
    unsigned long       dwInternationalRuleSize;                        // TAPI v1.4
    unsigned long       dwInternationalRuleOffset;                      // TAPI v1.4
    unsigned long       dwOptions;                                      // TAPI v1.4

} LINECARDENTRY,  *LPLINECARDENTRY;

typedef struct linecountryentry_tag
{
    unsigned long       dwCountryID;                                    // TAPI v1.4
    unsigned long       dwCountryCode;                                  // TAPI v1.4
    unsigned long       dwNextCountryID;                                // TAPI v1.4
    unsigned long       dwCountryNameSize;                              // TAPI v1.4
    unsigned long       dwCountryNameOffset;                            // TAPI v1.4
    unsigned long       dwSameAreaRuleSize;                             // TAPI v1.4
    unsigned long       dwSameAreaRuleOffset;                           // TAPI v1.4
    unsigned long       dwLongDistanceRuleSize;                         // TAPI v1.4
    unsigned long       dwLongDistanceRuleOffset;                       // TAPI v1.4
    unsigned long       dwInternationalRuleSize;                        // TAPI v1.4
    unsigned long       dwInternationalRuleOffset;                      // TAPI v1.4

} LINECOUNTRYENTRY,  *LPLINECOUNTRYENTRY;

typedef struct linecountrylist_tag
{
    unsigned long       dwTotalSize;                                    // TAPI v1.4
    unsigned long       dwNeededSize;                                   // TAPI v1.4
    unsigned long       dwUsedSize;                                     // TAPI v1.4
    unsigned long       dwNumCountries;                                 // TAPI v1.4
    unsigned long       dwCountryListSize;                              // TAPI v1.4
    unsigned long       dwCountryListOffset;                            // TAPI v1.4

} LINECOUNTRYLIST,  *LPLINECOUNTRYLIST;

typedef struct linedevcaps_tag
{
    unsigned long       dwTotalSize;
    unsigned long       dwNeededSize;
    unsigned long       dwUsedSize;
    unsigned long       dwProviderInfoSize;
    unsigned long       dwProviderInfoOffset;
    unsigned long       dwSwitchInfoSize;
    unsigned long       dwSwitchInfoOffset;
    unsigned long       dwPermanentLineID;
    unsigned long       dwLineNameSize;
    unsigned long       dwLineNameOffset;
    unsigned long       dwStringFormat;
    unsigned long       dwAddressModes;
    unsigned long       dwNumAddresses;
    unsigned long       dwBearerModes;
    unsigned long       dwMaxRate;
    unsigned long       dwMediaModes;
    unsigned long       dwGenerateToneModes;
    unsigned long       dwGenerateToneMaxNumFreq;
    unsigned long       dwGenerateDigitModes;
    unsigned long       dwMonitorToneMaxNumFreq;
    unsigned long       dwMonitorToneMaxNumEntries;
    unsigned long       dwMonitorDigitModes;
    unsigned long       dwGatherDigitsMinTimeout;
    unsigned long       dwGatherDigitsMaxTimeout;
    unsigned long       dwMedCtlDigitMaxListSize;
    unsigned long       dwMedCtlMediaMaxListSize;
    unsigned long       dwMedCtlToneMaxListSize;
    unsigned long       dwMedCtlCallStateMaxListSize;
    unsigned long       dwDevCapFlags;
    unsigned long       dwMaxNumActiveCalls;
    unsigned long       dwAnswerMode;
    unsigned long       dwRingModes;
    unsigned long       dwLineStates;
    unsigned long       dwUUIAcceptSize;
    unsigned long       dwUUIAnswerSize;
    unsigned long       dwUUIMakeCallSize;
    unsigned long       dwUUIDropSize;
    unsigned long       dwUUISendUserUserInfoSize;
    unsigned long       dwUUICallInfoSize;
    LINEDIALPARAMS  MinDialParams;
    LINEDIALPARAMS  MaxDialParams;
    LINEDIALPARAMS  DefaultDialParams;
    unsigned long       dwNumTerminals;
    unsigned long       dwTerminalCapsSize;
    unsigned long       dwTerminalCapsOffset;
    unsigned long       dwTerminalTextEntrySize;
    unsigned long       dwTerminalTextSize;
    unsigned long       dwTerminalTextOffset;
    unsigned long       dwDevSpecificSize;
    unsigned long       dwDevSpecificOffset;

    unsigned long       dwLineFeatures;                                 // TAPI v1.4

#if (TAPI_CURRENT_VERSION >= 0x00020000)
    unsigned long       dwSettableDevStatus;                            // TAPI v2.0
    unsigned long       dwDeviceClassesSize;                            // TAPI v2.0
    unsigned long       dwDeviceClassesOffset;                          // TAPI v2.0
#endif

} LINEDEVCAPS,  *LPLINEDEVCAPS;
    
typedef struct linedevstatus_tag
{
    unsigned long       dwTotalSize;
    unsigned long       dwNeededSize;
    unsigned long       dwUsedSize;
    unsigned long       dwNumOpens;
    unsigned long       dwOpenMediaModes;
    unsigned long       dwNumActiveCalls;
    unsigned long       dwNumOnHoldCalls;
    unsigned long       dwNumOnHoldPendCalls;
    unsigned long       dwLineFeatures;
    unsigned long       dwNumCallCompletions;
    unsigned long       dwRingMode;
    unsigned long       dwSignalLevel;
    unsigned long       dwBatteryLevel;
    unsigned long       dwRoamMode;
    unsigned long       dwDevStatusFlags;
    unsigned long       dwTerminalModesSize;
    unsigned long       dwTerminalModesOffset;
    unsigned long       dwDevSpecificSize;
    unsigned long       dwDevSpecificOffset;

#if (TAPI_CURRENT_VERSION >= 0x00020000)
    unsigned long       dwAvailableMediaModes;                          // TAPI v2.0
    unsigned long       dwAppInfoSize;                                  // TAPI v2.0
    unsigned long       dwAppInfoOffset;                                // TAPI v2.0
#endif

} LINEDEVSTATUS,  *LPLINEDEVSTATUS;

typedef struct lineextensionid_tag
{
    unsigned long       dwExtensionID0;
    unsigned long       dwExtensionID1;
    unsigned long       dwExtensionID2;
    unsigned long       dwExtensionID3;

} LINEEXTENSIONID,  *LPLINEEXTENSIONID;

typedef struct lineforward_tag
{
    unsigned long       dwForwardMode;
    unsigned long       dwCallerAddressSize;
    unsigned long       dwCallerAddressOffset;
    unsigned long       dwDestCountryCode;
    unsigned long       dwDestAddressSize;
    unsigned long       dwDestAddressOffset;

} LINEFORWARD,  *LPLINEFORWARD;

typedef struct lineforwardlist_tag
{
    unsigned long       dwTotalSize;
    unsigned long       dwNumEntries;
    LINEFORWARD ForwardList[1];

} LINEFORWARDLIST,  *LPLINEFORWARDLIST;

typedef struct linegeneratetone_tag
{
    unsigned long       dwFrequency;
    unsigned long       dwCadenceOn;
    unsigned long       dwCadenceOff;
    unsigned long       dwVolume;

} LINEGENERATETONE,  *LPLINEGENERATETONE;

#if (TAPI_CURRENT_VERSION >= 0x00020000)
typedef struct lineinitializeexparams_tag
{
    unsigned long       dwTotalSize;                                    // TAPI v2.0
    unsigned long       dwNeededSize;                                   // TAPI v2.0
    unsigned long       dwUsedSize;                                     // TAPI v2.0
    unsigned long       dwOptions;                                      // TAPI v2.0

    union
    {
        HANDLE  hEvent;                                         // TAPI v2.0
        HANDLE  hCompletionPort;                                // TAPI v2.0

    } Handles;

    unsigned long       dwCompletionKey;                                // TAPI v2.0

} LINEINITIALIZEEXPARAMS,  *LPLINEINITIALIZEEXPARAMS;
#endif

typedef struct linelocationentry_tag
{
    unsigned long       dwPermanentLocationID;
    unsigned long       dwLocationNameSize;
    unsigned long       dwLocationNameOffset;
    unsigned long       dwCountryCode;
    unsigned long       dwCityCodeSize;
    unsigned long       dwCityCodeOffset;
    unsigned long       dwPreferredCardID;

    unsigned long       dwLocalAccessCodeSize;                          // TAPI v1.4
    unsigned long       dwLocalAccessCodeOffset;                        // TAPI v1.4
    unsigned long       dwLongDistanceAccessCodeSize;                   // TAPI v1.4
    unsigned long       dwLongDistanceAccessCodeOffset;                 // TAPI v1.4
    unsigned long       dwTollPrefixListSize;                           // TAPI v1.4
    unsigned long       dwTollPrefixListOffset;                         // TAPI v1.4
    unsigned long       dwCountryID;                                    // TAPI v1.4
    unsigned long       dwOptions;                                      // TAPI v1.4
    unsigned long       dwCancelCallWaitingSize;                        // TAPI v1.4
    unsigned long       dwCancelCallWaitingOffset;                      // TAPI v1.4

} LINELOCATIONENTRY,  *LPLINELOCATIONENTRY;

typedef struct linemediacontrolcallstate_tag
{
    unsigned long       dwCallStates;
    unsigned long       dwMediaControl;

} LINEMEDIACONTROLCALLSTATE,  *LPLINEMEDIACONTROLCALLSTATE;

typedef struct linemediacontroldigit_tag
{
    unsigned long       dwDigit;
    unsigned long       dwDigitModes;
    unsigned long       dwMediaControl;

} LINEMEDIACONTROLDIGIT,  *LPLINEMEDIACONTROLDIGIT;

typedef struct linemediacontrolmedia_tag
{
    unsigned long       dwMediaModes;
    unsigned long       dwDuration;
    unsigned long       dwMediaControl;

} LINEMEDIACONTROLMEDIA,  *LPLINEMEDIACONTROLMEDIA;

typedef struct linemediacontroltone_tag
{
    unsigned long       dwAppSpecific;
    unsigned long       dwDuration;
    unsigned long       dwFrequency1;
    unsigned long       dwFrequency2;
    unsigned long       dwFrequency3;
    unsigned long       dwMediaControl;

} LINEMEDIACONTROLTONE,  *LPLINEMEDIACONTROLTONE;

#if (TAPI_CURRENT_VERSION >= 0x00020000)
typedef struct linemessage_tag
{
    unsigned long       hDevice;                                        // TAPI v2.0
    unsigned long       dwMessageID;                                    // TAPI v2.0
    unsigned long       dwCallbackInstance;                             // TAPI v2.0
    unsigned long       dwParam1;                                       // TAPI v2.0
    unsigned long       dwParam2;                                       // TAPI v2.0
    unsigned long       dwParam3;                                       // TAPI v2.0

} LINEMESSAGE,  *LPLINEMESSAGE;
#endif

typedef struct linemonitortone_tag
{
    unsigned long       dwAppSpecific;
    unsigned long       dwDuration;
    unsigned long       dwFrequency1;
    unsigned long       dwFrequency2;
    unsigned long       dwFrequency3;

} LINEMONITORTONE,  *LPLINEMONITORTONE;

typedef struct lineproviderentry_tag
{
    unsigned long       dwPermanentProviderID;                          // TAPI v1.4
    unsigned long       dwProviderFilenameSize;                         // TAPI v1.4
    unsigned long       dwProviderFilenameOffset;                       // TAPI v1.4

} LINEPROVIDERENTRY,  *LPLINEPROVIDERENTRY;

typedef struct lineproviderlist_tag
{
    unsigned long       dwTotalSize;                                    // TAPI v1.4
    unsigned long       dwNeededSize;                                   // TAPI v1.4
    unsigned long       dwUsedSize;                                     // TAPI v1.4
    unsigned long       dwNumProviders;                                 // TAPI v1.4
    unsigned long       dwProviderListSize;                             // TAPI v1.4
    unsigned long       dwProviderListOffset;                           // TAPI v1.4

} LINEPROVIDERLIST,  *LPLINEPROVIDERLIST;


#if (TAPI_CURRENT_VERSION >= 0x00020000)
typedef struct lineproxyrequest_tag
{
    unsigned long       dwSize;                                         // TAPI v2.0
    unsigned long       dwClientMachineNameSize;                        // TAPI v2.0
    unsigned long       dwClientMachineNameOffset;                      // TAPI v2.0
    unsigned long       dwClientUserNameSize;                           // TAPI v2.0
    unsigned long       dwClientUserNameOffset;                         // TAPI v2.0
    unsigned long       dwClientAppAPIVersion;                          // TAPI v2.0
    unsigned long       dwRequestType;                                  // TAPI v2.0

    union
    {
    struct
    {
        unsigned long                   dwAddressID;                    // TAPI v2.0
        LINEAGENTGROUPLIST      GroupList;                      // TAPI v2.0

    } SetAgentGroup;

    struct
    {
        unsigned long                   dwAddressID;                    // TAPI v2.0
        unsigned long                   dwAgentState;                   // TAPI v2.0
        unsigned long                   dwNextAgentState;               // TAPI v2.0

    } SetAgentState;

    struct
    {
        unsigned long                   dwAddressID;                    // TAPI v2.0
        unsigned long                   dwActivityID;                   // TAPI v2.0

    } SetAgentActivity;

    struct
    {
        unsigned long                   dwAddressID;                    // TAPI v2.0
        LINEAGENTCAPS           AgentCaps;                      // TAPI v2.0

    } GetAgentCaps;

    struct
    {
        unsigned long                   dwAddressID;                    // TAPI v2.0
        LINEAGENTSTATUS         AgentStatus;                    // TAPI v2.0

    } GetAgentStatus;

    struct
    {
        unsigned long                   dwAddressID;                    // TAPI v2.0
        unsigned long                   dwAgentExtensionIDIndex;        // TAPI v2.0
        unsigned long                   dwSize;                         // TAPI v2.0
        BYTE                    Params[1];                      // TAPI v2.0

    } AgentSpecific;

    struct
    {
        unsigned long                   dwAddressID;                    // TAPI v2.0
        LINEAGENTACTIVITYLIST   ActivityList;                   // TAPI v2.0

    } GetAgentActivityList;

    struct
    {
        unsigned long                   dwAddressID;                    // TAPI v2.0
        LINEAGENTGROUPLIST      GroupList;                      // TAPI v2.0

    } GetAgentGroupList;
    }; //ProxyRequestType;

} LINEPROXYREQUEST, *LPLINEPROXYREQUEST;
#endif


typedef struct linereqmakecall_tag
{
    char        szDestAddress[TAPIMAXDESTADDRESSSIZE];
    char        szAppName[TAPIMAXAPPNAMESIZE];
    char        szCalledParty[TAPIMAXCALLEDPARTYSIZE];
    char        szComment[TAPIMAXCOMMENTSIZE];

} LINEREQMAKECALL,  *LPLINEREQMAKECALL;

#if (TAPI_CURRENT_VERSION >= 0x00020000)
typedef struct linereqmakecallW_tag
{
    WCHAR       szDestAddress[TAPIMAXDESTADDRESSSIZE];
    WCHAR       szAppName[TAPIMAXAPPNAMESIZE];
    WCHAR       szCalledParty[TAPIMAXCALLEDPARTYSIZE];
    WCHAR       szComment[TAPIMAXCOMMENTSIZE];

} LINEREQMAKECALLW,  *LPLINEREQMAKECALLW;
#endif

#ifdef UNICODE
#define LINEREQMAKECALL LINEREQMAKECALLW
#endif

typedef struct linereqmediacall_tag
{
    HWND        hWnd;
    WPARAM      wRequestID;
    char        szDeviceClass[TAPIMAXDEVICECLASSSIZE];
    unsigned char   ucDeviceID[TAPIMAXDEVICEIDSIZE];
    unsigned long       dwSize;
    unsigned long       dwSecure;
    char        szDestAddress[TAPIMAXDESTADDRESSSIZE];
    char        szAppName[TAPIMAXAPPNAMESIZE];
    char        szCalledParty[TAPIMAXCALLEDPARTYSIZE];
    char        szComment[TAPIMAXCOMMENTSIZE];

} LINEREQMEDIACALL,  *LPLINEREQMEDIACALL;

#if (TAPI_CURRENT_VERSION >= 0x00020000)
typedef struct linereqmediacallW_tag
{
    HWND        hWnd;
    WPARAM      wRequestID;
    WCHAR       szDeviceClass[TAPIMAXDEVICECLASSSIZE];
    unsigned char   ucDeviceID[TAPIMAXDEVICEIDSIZE];
    unsigned long       dwSize;
    unsigned long       dwSecure;
    WCHAR       szDestAddress[TAPIMAXDESTADDRESSSIZE];
    WCHAR       szAppName[TAPIMAXAPPNAMESIZE];
    WCHAR       szCalledParty[TAPIMAXCALLEDPARTYSIZE];
    WCHAR       szComment[TAPIMAXCOMMENTSIZE];

} LINEREQMEDIACALLW,  *LPLINEREQMEDIACALLW;
#endif

#ifdef UNICODE
#define LINEREQMEDIACALL LINEREQMEDIACALLW
#endif


typedef struct linetermcaps_tag
{
    unsigned long       dwTermDev;
    unsigned long       dwTermModes;
    unsigned long       dwTermSharing;

} LINETERMCAPS,  *LPLINETERMCAPS;

typedef struct linetranslatecaps_tag
{
    unsigned long       dwTotalSize;
    unsigned long       dwNeededSize;
    unsigned long       dwUsedSize;
    unsigned long       dwNumLocations;
    unsigned long       dwLocationListSize;
    unsigned long       dwLocationListOffset;
    unsigned long       dwCurrentLocationID;
    unsigned long       dwNumCards;
    unsigned long       dwCardListSize;
    unsigned long       dwCardListOffset;
    unsigned long       dwCurrentPreferredCardID;

} LINETRANSLATECAPS,  *LPLINETRANSLATECAPS;

typedef struct linetranslateoutput_tag
{
    unsigned long       dwTotalSize;
    unsigned long       dwNeededSize;
    unsigned long       dwUsedSize;
    unsigned long       dwDialableStringSize;
    unsigned long       dwDialableStringOffset;
    unsigned long       dwDisplayableStringSize;
    unsigned long       dwDisplayableStringOffset;
    unsigned long       dwCurrentCountry;
    unsigned long       dwDestCountry;
    unsigned long       dwTranslateResults;

} LINETRANSLATEOUTPUT,  *LPLINETRANSLATEOUTPUT;

typedef struct phonebuttoninfo_tag
{
    unsigned long       dwTotalSize;
    unsigned long       dwNeededSize;
    unsigned long       dwUsedSize;
    unsigned long       dwButtonMode;
    unsigned long       dwButtonFunction;
    unsigned long       dwButtonTextSize;
    unsigned long       dwButtonTextOffset;
    unsigned long       dwDevSpecificSize;
    unsigned long       dwDevSpecificOffset;

    unsigned long       dwButtonState;                                  // TAPI v1.4

} PHONEBUTTONINFO,  *LPPHONEBUTTONINFO;

typedef struct phonecaps_tag
{
    unsigned long       dwTotalSize;
    unsigned long       dwNeededSize;
    unsigned long       dwUsedSize;
    unsigned long       dwProviderInfoSize;
    unsigned long       dwProviderInfoOffset;
    unsigned long       dwPhoneInfoSize;
    unsigned long       dwPhoneInfoOffset;
    unsigned long       dwPermanentPhoneID;
    unsigned long       dwPhoneNameSize;
    unsigned long       dwPhoneNameOffset;
    unsigned long       dwStringFormat;
    unsigned long       dwPhoneStates;
    unsigned long       dwHookSwitchDevs;
    unsigned long       dwHandsetHookSwitchModes;
    unsigned long       dwSpeakerHookSwitchModes;
    unsigned long       dwHeadsetHookSwitchModes;
    unsigned long       dwVolumeFlags;
    unsigned long       dwGainFlags;
    unsigned long       dwDisplayNumRows;
    unsigned long       dwDisplayNumColumns;
    unsigned long       dwNumRingModes;
    unsigned long       dwNumButtonLamps;
    unsigned long       dwButtonModesSize;
    unsigned long       dwButtonModesOffset;
    unsigned long       dwButtonFunctionsSize;
    unsigned long       dwButtonFunctionsOffset;
    unsigned long       dwLampModesSize;
    unsigned long       dwLampModesOffset;
    unsigned long       dwNumSetData;
    unsigned long       dwSetDataSize;
    unsigned long       dwSetDataOffset;
    unsigned long       dwNumGetData;
    unsigned long       dwGetDataSize;
    unsigned long       dwGetDataOffset;
    unsigned long       dwDevSpecificSize;
    unsigned long       dwDevSpecificOffset;

#if (TAPI_CURRENT_VERSION >= 0x00020000)
    unsigned long       dwDeviceClassesSize;                            // TAPI v2.0
    unsigned long       dwDeviceClassesOffset;                          // TAPI v2.0
    unsigned long       dwPhoneFeatures;                                // TAPI v2.0
    unsigned long       dwSettableHandsetHookSwitchModes;               // TAPI v2.0
    unsigned long       dwSettableSpeakerHookSwitchModes;               // TAPI v2.0
    unsigned long       dwSettableHeadsetHookSwitchModes;               // TAPI v2.0
    unsigned long       dwMonitoredHandsetHookSwitchModes;              // TAPI v2.0
    unsigned long       dwMonitoredSpeakerHookSwitchModes;              // TAPI v2.0
    unsigned long       dwMonitoredHeadsetHookSwitchModes;              // TAPI v2.0
#endif

} PHONECAPS,  *LPPHONECAPS;

typedef struct phoneextensionid_tag
{
    unsigned long       dwExtensionID0;
    unsigned long       dwExtensionID1;
    unsigned long       dwExtensionID2;
    unsigned long       dwExtensionID3;

} PHONEEXTENSIONID,  *LPPHONEEXTENSIONID;

#if (TAPI_CURRENT_VERSION >= 0x00020000)
typedef struct phoneinitializeexparams_tag
{
    unsigned long       dwTotalSize;                                    // TAPI v2.0
    unsigned long       dwNeededSize;                                   // TAPI v2.0
    unsigned long       dwUsedSize;                                     // TAPI v2.0
    unsigned long       dwOptions;                                      // TAPI v2.0

    union
    {
        HANDLE  hEvent;                                         // TAPI v2.0
        HANDLE  hCompletionPort;                                // TAPI v2.0

    } Handles;

    unsigned long       dwCompletionKey;                                // TAPI v2.0

} PHONEINITIALIZEEXPARAMS,  *LPPHONEINITIALIZEEXPARAMS;

typedef struct phonemessage_tag
{
    unsigned long       hDevice;                                        // TAPI v2.0
    unsigned long       dwMessageID;                                    // TAPI v2.0
    unsigned long       dwCallbackInstance;                             // TAPI v2.0
    unsigned long       dwParam1;                                       // TAPI v2.0
    unsigned long       dwParam2;                                       // TAPI v2.0
    unsigned long       dwParam3;                                       // TAPI v2.0

} PHONEMESSAGE,  *LPPHONEMESSAGE;
#endif

typedef struct phonestatus_tag
{
    unsigned long       dwTotalSize;
    unsigned long       dwNeededSize;
    unsigned long       dwUsedSize;
    unsigned long       dwStatusFlags;
    unsigned long       dwNumOwners;
    unsigned long       dwNumMonitors;
    unsigned long       dwRingMode;
    unsigned long       dwRingVolume;
    unsigned long       dwHandsetHookSwitchMode;
    unsigned long       dwHandsetVolume;
    unsigned long       dwHandsetGain;
    unsigned long       dwSpeakerHookSwitchMode;
    unsigned long       dwSpeakerVolume;
    unsigned long       dwSpeakerGain;
    unsigned long       dwHeadsetHookSwitchMode;
    unsigned long       dwHeadsetVolume;
    unsigned long       dwHeadsetGain;
    unsigned long       dwDisplaySize;
    unsigned long       dwDisplayOffset;
    unsigned long       dwLampModesSize;
    unsigned long       dwLampModesOffset;
    unsigned long       dwOwnerNameSize;
    unsigned long       dwOwnerNameOffset;
    unsigned long       dwDevSpecificSize;
    unsigned long       dwDevSpecificOffset;

#if (TAPI_CURRENT_VERSION >= 0x00020000)
    unsigned long       dwPhoneFeatures;                                // TAPI v2.0
#endif

} PHONESTATUS,  *LPPHONESTATUS;

typedef struct varstring_tag
{
    unsigned long       dwTotalSize;
    unsigned long       dwNeededSize;
    unsigned long       dwUsedSize;
    unsigned long       dwStringFormat;
    unsigned long       dwStringSize;
    unsigned long       dwStringOffset;

} VARSTRING,  *LPVARSTRING;



LONG
__stdcall
lineAccept(
    HCALL               hCall,
    const char*              lpsUserUserInfo,
    unsigned long               dwSize
    );

LONG
__stdcall
lineAddProvider(                                                // TAPI v1.4
    const char*              lpszProviderFilename,
    HWND                hwndOwner,
    LPDWORD             lpdwPermanentProviderID
    );

#if WIN32
LONG
__stdcall
lineAddProviderA(                                               // TAPI v1.4
    const char*              lpszProviderFilename,
    HWND                hwndOwner,
    LPDWORD             lpdwPermanentProviderID
    );

LONG
__stdcall
lineAddProviderW(
    const wchar_t*             lpszProviderFilename,
    HWND                hwndOwner,
    LPDWORD             lpdwPermanentProviderID
    );

#ifdef UNICODE
#define lineAddProvider lineAddProviderW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineAddProvider lineAddProviderA
#endif
#endif

#endif


LONG
__stdcall
lineAddToConference(
    HCALL               hConfCall,
    HCALL               hConsultCall
    );

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
__stdcall
lineAgentSpecific(                                              // TAPI v2.0
    HLINE               hLine,
    unsigned long               dwAddressID,
    unsigned long               dwAgentExtensionIDIndex,
    void*              lpParams,
    unsigned long               dwSize
    );
#endif

LONG
__stdcall
lineAnswer(
    HCALL               hCall,
    const char*              lpsUserUserInfo,
    unsigned long               dwSize
    );

LONG
__stdcall
lineBlindTransfer(
    HCALL               hCall,
    const char*              lpszDestAddress,
    unsigned long               dwCountryCode
    );

#if WIN32
LONG
__stdcall
lineBlindTransferA(
    HCALL               hCall,
    const char*              lpszDestAddress,
    unsigned long               dwCountryCode
    );

LONG
__stdcall
lineBlindTransferW(
    HCALL               hCall,
    const wchar_t*             lpszDestAddressW,
    unsigned long               dwCountryCode
    );

#ifdef UNICODE
#define lineBlindTransfer lineBlindTransferW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineBlindTransfer lineBlindTransferA
#endif
#endif

#endif


LONG
__stdcall
lineClose(
    HLINE               hLine
    );

LONG
__stdcall
lineCompleteCall(
    HCALL               hCall,
    LPDWORD             lpdwCompletionID,
    unsigned long               dwCompletionMode,
    unsigned long               dwMessageID
    );

LONG
__stdcall
lineCompleteTransfer(
    HCALL               hCall,
    HCALL               hConsultCall,
    LPHCALL             lphConfCall,
    unsigned long               dwTransferMode
    );

LONG
__stdcall
lineConfigDialog(
    unsigned long               dwDeviceID,
    HWND                hwndOwner,
    const char*              lpszDeviceClass
    );

#if WIN32
LONG
__stdcall
lineConfigDialogA(
    unsigned long               dwDeviceID,
    HWND                hwndOwner,
    const char*              lpszDeviceClass
    );

LONG
__stdcall
lineConfigDialogW(
    unsigned long               dwDeviceID,
    HWND                hwndOwner,
    const wchar_t*             lpszDeviceClass
    );

#ifdef UNICODE
#define lineConfigDialog lineConfigDialogW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineConfigDialog lineConfigDialogA
#endif
#endif

#endif


LONG
__stdcall
lineConfigDialogEdit(                                           // TAPI v1.4
    unsigned long               dwDeviceID,
    HWND                hwndOwner,
    const char*              lpszDeviceClass,
    void*              const lpDeviceConfigIn,
    unsigned long               dwSize,
    LPVARSTRING         lpDeviceConfigOut
    );

#if WIN32
LONG
__stdcall
lineConfigDialogEditA(                                          // TAPI v1.4
    unsigned long               dwDeviceID,
    HWND                hwndOwner,
    const char*              lpszDeviceClass,
    void*              const lpDeviceConfigIn,
    unsigned long               dwSize,
    LPVARSTRING         lpDeviceConfigOut
    );

LONG
__stdcall
lineConfigDialogEditW(
    unsigned long               dwDeviceID,
    HWND                hwndOwner,
    const wchar_t*             lpszDeviceClass,
    void*              const lpDeviceConfigIn,
    unsigned long               dwSize,
    LPVARSTRING         lpDeviceConfigOut
    );

#ifdef UNICODE
#define lineConfigDialogEdit lineConfigDialogEditW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineConfigDialogEdit lineConfigDialogEditA
#endif
#endif

#endif

LONG
__stdcall
lineConfigProvider(                                             // TAPI v1.4
    HWND                hwndOwner,
    unsigned long               dwPermanentProviderID
    );

LONG
__stdcall
lineDeallocateCall(
    HCALL               hCall
    );

LONG
__stdcall
lineDevSpecific(
    HLINE               hLine,
    unsigned long               dwAddressID,
    HCALL               hCall,
    void*              lpParams,
    unsigned long               dwSize
    );

LONG
__stdcall
lineDevSpecificFeature(
    HLINE               hLine,
    unsigned long               dwFeature,
    void*              lpParams,
    unsigned long               dwSize
    );

LONG
__stdcall
lineDial(
    HCALL               hCall,
    const char*              lpszDestAddress,
    unsigned long               dwCountryCode
    );

#if WIN32
LONG
__stdcall
lineDialA(
    HCALL               hCall,
    const char*              lpszDestAddress,
    unsigned long               dwCountryCode
    );

LONG
__stdcall
lineDialW(
    HCALL               hCall,
    const wchar_t*             lpszDestAddress,
    unsigned long               dwCountryCode
    );

#ifdef UNICODE
#define lineDial lineDialW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineDial lineDialA
#endif
#endif

#endif

LONG
__stdcall
lineDrop(
    HCALL               hCall,
    const char*              lpsUserUserInfo,
    unsigned long               dwSize
    );

LONG
__stdcall
lineForward(
    HLINE               hLine,
    unsigned long               bAllAddresses,
    unsigned long               dwAddressID,
    LPLINEFORWARDLIST   const lpForwardList,
    unsigned long               dwNumRingsNoAnswer,
    LPHCALL             lphConsultCall,
    LPLINECALLPARAMS    const lpCallParams
    );

#if WIN32
LONG
__stdcall
lineForwardA(
    HLINE               hLine,
    unsigned long               bAllAddresses,
    unsigned long               dwAddressID,
    LPLINEFORWARDLIST   const lpForwardList,
    unsigned long               dwNumRingsNoAnswer,
    LPHCALL             lphConsultCall,
    LPLINECALLPARAMS    const lpCallParams
    );

LONG
__stdcall
lineForwardW(
    HLINE               hLine,
    unsigned long               bAllAddresses,
    unsigned long               dwAddressID,
    LPLINEFORWARDLIST   const lpForwardList,
    unsigned long               dwNumRingsNoAnswer,
    LPHCALL             lphConsultCall,
    LPLINECALLPARAMS    const lpCallParams
    );

#ifdef UNICODE
#define lineForward lineForwardW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineForward lineForwardA
#endif
#endif

#endif

LONG
__stdcall
lineGatherDigits(
    HCALL               hCall,
    unsigned long               dwDigitModes,
    LPSTR               lpsDigits,
    unsigned long               dwNumDigits,
    const char*              lpszTerminationDigits,
    unsigned long               dwFirstDigitTimeout,
    unsigned long               dwInterDigitTimeout
    );

#if WIN32
LONG
__stdcall
lineGatherDigitsA(
    HCALL               hCall,
    unsigned long               dwDigitModes,
    LPSTR               lpsDigits,
    unsigned long               dwNumDigits,
    const char*              lpszTerminationDigits,
    unsigned long               dwFirstDigitTimeout,
    unsigned long               dwInterDigitTimeout
    );

LONG
__stdcall
lineGatherDigitsW(
    HCALL               hCall,
    unsigned long               dwDigitModes,
    LPWSTR              lpsDigits,
    unsigned long               dwNumDigits,
    const wchar_t*             lpszTerminationDigits,
    unsigned long               dwFirstDigitTimeout,
    unsigned long               dwInterDigitTimeout
    );

#ifdef UNICODE
#define lineGatherDigits lineGatherDigitsW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineGatherDigits lineGatherDigitsA
#endif
#endif

#endif

LONG
__stdcall
lineGenerateDigits(
    HCALL               hCall,
    unsigned long               dwDigitMode,
    const char*              lpszDigits,
    unsigned long               dwDuration
    );

#if WIN32
LONG
__stdcall
lineGenerateDigitsA(
    HCALL               hCall,
    unsigned long               dwDigitMode,
    const char*              lpszDigits,
    unsigned long               dwDuration
    );

LONG
__stdcall
lineGenerateDigitsW(
    HCALL               hCall,
    unsigned long               dwDigitMode,
    const wchar_t*             lpszDigits,
    unsigned long               dwDuration
    );

#ifdef UNICODE
#define lineGenerateDigits lineGenerateDigitsW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineGenerateDigits lineGenerateDigitsA
#endif
#endif

#endif

LONG
__stdcall
lineGenerateTone(
    HCALL               hCall,
    unsigned long               dwToneMode,
    unsigned long               dwDuration,
    unsigned long               dwNumTones,
    LPLINEGENERATETONE  const lpTones
    );

LONG
__stdcall
lineGetAddressCaps(
    HLINEAPP            hLineApp,
    unsigned long               dwDeviceID,
    unsigned long               dwAddressID,
    unsigned long               dwAPIVersion,
    unsigned long               dwExtVersion,
    LPLINEADDRESSCAPS   lpAddressCaps
    );

#if WIN32
LONG
__stdcall
lineGetAddressCapsA(
    HLINEAPP            hLineApp,
    unsigned long               dwDeviceID,
    unsigned long               dwAddressID,
    unsigned long               dwAPIVersion,
    unsigned long               dwExtVersion,
    LPLINEADDRESSCAPS   lpAddressCaps
    );

LONG
__stdcall
lineGetAddressCapsW(
    HLINEAPP            hLineApp,
    unsigned long               dwDeviceID,
    unsigned long               dwAddressID,
    unsigned long               dwAPIVersion,
    unsigned long               dwExtVersion,
    LPLINEADDRESSCAPS   lpAddressCaps
    );

#ifdef UNICODE
#define lineGetAddressCaps lineGetAddressCapsW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineGetAddressCaps lineGetAddressCapsA
#endif
#endif

#endif

LONG
__stdcall
lineGetAddressID(
    HLINE               hLine,
    LPDWORD             lpdwAddressID,
    unsigned long               dwAddressMode,
    const char*              lpsAddress,
    unsigned long               dwSize
    );

#if WIN32
LONG
__stdcall
lineGetAddressIDA(
    HLINE               hLine,
    LPDWORD             lpdwAddressID,
    unsigned long               dwAddressMode,
    const char*              lpsAddress,
    unsigned long               dwSize
    );

LONG
__stdcall
lineGetAddressIDW(
    HLINE               hLine,
    LPDWORD             lpdwAddressID,
    unsigned long               dwAddressMode,
    const wchar_t*             lpsAddress,
    unsigned long               dwSize
    );

#ifdef UNICODE
#define lineGetAddressID lineGetAddressIDW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineGetAddressID lineGetAddressIDA
#endif
#endif

#endif

LONG
__stdcall
lineGetAddressStatus(
    HLINE               hLine,
    unsigned long               dwAddressID,
    LPLINEADDRESSSTATUS lpAddressStatus
    );

#if WIN32
LONG
__stdcall
lineGetAddressStatusA(
    HLINE               hLine,
    unsigned long               dwAddressID,
    LPLINEADDRESSSTATUS lpAddressStatus
    );

LONG
__stdcall
lineGetAddressStatusW(
    HLINE               hLine,
    unsigned long               dwAddressID,
    LPLINEADDRESSSTATUS lpAddressStatus
    );

#ifdef UNICODE
#define lineGetAddressStatus lineGetAddressStatusW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineGetAddressStatus lineGetAddressStatusA
#endif
#endif

#endif

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
__stdcall
lineGetAgentActivityListA(                                       // TAPI v2.0
    HLINE                   hLine,
    unsigned long                   dwAddressID,
    LPLINEAGENTACTIVITYLIST lpAgentActivityList
    );

LONG
__stdcall
lineGetAgentActivityListW(                                       // TAPI v2.0
    HLINE                   hLine,
    unsigned long                   dwAddressID,
    LPLINEAGENTACTIVITYLIST lpAgentActivityList
    );

#ifdef UNICODE
#define lineGetAgentActivityList lineGetAgentActivityListW
#else
#define lineGetAgentActivityList lineGetAgentActivityListA
#endif


LONG
__stdcall
lineGetAgentCapsA(                                               // TAPI v2.0
    HLINEAPP            hLineApp,
    unsigned long               dwDeviceID,
    unsigned long               dwAddressID,
    unsigned long               dwAppAPIVersion,
    LPLINEAGENTCAPS     lpAgentCaps
    );

LONG
__stdcall
lineGetAgentCapsW(                                               // TAPI v2.0
    HLINEAPP            hLineApp,
    unsigned long               dwDeviceID,
    unsigned long               dwAddressID,
    unsigned long               dwAppAPIVersion,
    LPLINEAGENTCAPS     lpAgentCaps
    );

#ifdef UNICODE
#define lineGetAgentCaps lineGetAgentCapsW
#else
#define lineGetAgentCaps lineGetAgentCapsA
#endif


LONG
__stdcall
lineGetAgentGroupListA(                                          // TAPI v2.0
    HLINE                   hLine,
    unsigned long                   dwAddressID,
    LPLINEAGENTGROUPLIST    lpAgentGroupList
    );

LONG
__stdcall
lineGetAgentGroupListW(                                          // TAPI v2.0
    HLINE                   hLine,
    unsigned long                   dwAddressID,
    LPLINEAGENTGROUPLIST    lpAgentGroupList
    );

#ifdef UNICODE
#define lineGetAgentGroupList lineGetAgentGroupListW
#else
#define lineGetAgentGroupList lineGetAgentGroupListA
#endif

LONG
__stdcall
lineGetAgentStatusA(                                             // TAPI v2.0
    HLINE               hLine,
    unsigned long               dwAddressID,
    LPLINEAGENTSTATUS   lpAgentStatus
    );

LONG
__stdcall
lineGetAgentStatusW(                                             // TAPI v2.0
    HLINE               hLine,
    unsigned long               dwAddressID,
    LPLINEAGENTSTATUS   lpAgentStatus
    );

#ifdef UNICODE
#define lineGetAgentStatus lineGetAgentStatusW
#else
#define lineGetAgentStatus lineGetAgentStatusA
#endif

#endif

LONG
__stdcall
lineGetAppPriority(                                             // TAPI v1.4
    const char*              lpszAppFilename,
    unsigned long               dwMediaMode,
    LPLINEEXTENSIONID   lpExtensionID,
    unsigned long               dwRequestMode,
    LPVARSTRING         lpExtensionName,
    LPDWORD             lpdwPriority
    );

#if WIN32
LONG
__stdcall
lineGetAppPriorityA(                                            // TAPI v1.4
    const char*              lpszAppFilename,
    unsigned long               dwMediaMode,
    LPLINEEXTENSIONID   lpExtensionID,
    unsigned long               dwRequestMode,
    LPVARSTRING         lpExtensionName,
    LPDWORD             lpdwPriority
    );

LONG
__stdcall
lineGetAppPriorityW(                                             // TAPI v1.4
    const wchar_t*             lpszAppFilename,
    unsigned long               dwMediaMode,
    LPLINEEXTENSIONID   lpExtensionID,
    unsigned long               dwRequestMode,
    LPVARSTRING         lpExtensionName,
    LPDWORD             lpdwPriority
    );

#ifdef UNICODE
#define lineGetAppPriority lineGetAppPriorityW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineGetAppPriority lineGetAppPriorityA
#endif
#endif

#endif

LONG
__stdcall
lineGetCallInfo(
    HCALL               hCall,
    LPLINECALLINFO      lpCallInfo
    );

#if WIN32
LONG
__stdcall
lineGetCallInfoA(
    HCALL               hCall,
    LPLINECALLINFO      lpCallInfo
    );

LONG
__stdcall
lineGetCallInfoW(
    HCALL               hCall,
    LPLINECALLINFO      lpCallInfo
    );

#ifdef UNICODE
#define lineGetCallInfo lineGetCallInfoW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineGetCallInfo lineGetCallInfoA
#endif
#endif

#endif

LONG
__stdcall
lineGetCallStatus(
    HCALL               hCall,
    LPLINECALLSTATUS    lpCallStatus
    );

LONG
__stdcall
lineGetConfRelatedCalls(
    HCALL               hCall,
    LPLINECALLLIST      lpCallList
    );
    
LONG
__stdcall
lineGetCountry(                                                 // TAPI v1.4
    unsigned long               dwCountryID,
    unsigned long               dwAPIVersion,
    LPLINECOUNTRYLIST   lpLineCountryList
    );

#if WIN32
LONG
__stdcall
lineGetCountryA(                                                 // TAPI v1.4
    unsigned long               dwCountryID,
    unsigned long               dwAPIVersion,
    LPLINECOUNTRYLIST   lpLineCountryList
    );

LONG
__stdcall
lineGetCountryW(                                                // TAPI v1.4
    unsigned long               dwCountryID,
    unsigned long               dwAPIVersion,
    LPLINECOUNTRYLIST   lpLineCountryList
    );

#ifdef UNICODE
#define lineGetCountry lineGetCountryW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineGetCountry lineGetCountryA
#endif
#endif

#endif


LONG
__stdcall
lineGetDevCaps(
    HLINEAPP            hLineApp,
    unsigned long               dwDeviceID,
    unsigned long               dwAPIVersion,
    unsigned long               dwExtVersion,
    LPLINEDEVCAPS       lpLineDevCaps
    );

#if WIN32
LONG
__stdcall
lineGetDevCapsA(
    HLINEAPP            hLineApp,
    unsigned long               dwDeviceID,
    unsigned long               dwAPIVersion,
    unsigned long               dwExtVersion,
    LPLINEDEVCAPS       lpLineDevCaps
    );

LONG
__stdcall
lineGetDevCapsW(
    HLINEAPP            hLineApp,
    unsigned long               dwDeviceID,
    unsigned long               dwAPIVersion,
    unsigned long               dwExtVersion,
    LPLINEDEVCAPS       lpLineDevCaps
    );

#ifdef UNICODE
#define lineGetDevCaps lineGetDevCapsW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineGetDevCaps lineGetDevCapsA
#endif
#endif

#endif

LONG
__stdcall
lineGetDevConfig(
    unsigned long               dwDeviceID,
    LPVARSTRING         lpDeviceConfig,
    const char*              lpszDeviceClass
    );

#if WIN32
LONG
__stdcall
lineGetDevConfigA(
    unsigned long               dwDeviceID,
    LPVARSTRING         lpDeviceConfig,
    const char*              lpszDeviceClass
    );

LONG
__stdcall
lineGetDevConfigW(
    unsigned long               dwDeviceID,
    LPVARSTRING         lpDeviceConfig,
    const wchar_t*             lpszDeviceClass
    );

#ifdef UNICODE
#define lineGetDevConfig lineGetDevConfigW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineGetDevConfig lineGetDevConfigA
#endif
#endif

#endif

LONG
__stdcall
lineGetNewCalls(
    HLINE               hLine,
    unsigned long               dwAddressID,
    unsigned long               dwSelect,
    LPLINECALLLIST      lpCallList
    );

LONG
__stdcall
lineGetIcon(
    unsigned long               dwDeviceID,
    const char*              lpszDeviceClass,
    LPHICON             lphIcon
    );

#if WIN32
LONG
__stdcall
lineGetIconA(
    unsigned long               dwDeviceID,
    const char*              lpszDeviceClass,
    LPHICON             lphIcon
    );

LONG
__stdcall
lineGetIconW(
    unsigned long               dwDeviceID,
    const wchar_t*             lpszDeviceClass,
    LPHICON             lphIcon
    );

#ifdef UNICODE
#define lineGetIcon lineGetIconW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineGetIcon lineGetIconA
#endif
#endif

#endif
    
LONG
__stdcall
lineGetID(
    HLINE               hLine,
    unsigned long               dwAddressID,
    HCALL               hCall,
    unsigned long               dwSelect,
    LPVARSTRING         lpDeviceID,
    const char*              lpszDeviceClass
    );

#if WIN32
LONG
__stdcall
lineGetIDA(
    HLINE               hLine,
    unsigned long               dwAddressID,
    HCALL               hCall,
    unsigned long               dwSelect,
    LPVARSTRING         lpDeviceID,
    const char*              lpszDeviceClass
    );

LONG
__stdcall
lineGetIDW(
    HLINE               hLine,
    unsigned long               dwAddressID,
    HCALL               hCall,
    unsigned long               dwSelect,
    LPVARSTRING         lpDeviceID,
    const wchar_t*             lpszDeviceClass
    );

#ifdef UNICODE
#define lineGetID lineGetIDW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineGetID lineGetIDA
#endif
#endif

#endif

LONG
__stdcall
lineGetLineDevStatus(
    HLINE               hLine,
    LPLINEDEVSTATUS     lpLineDevStatus
    );

#if WIN32
LONG
__stdcall
lineGetLineDevStatusA(
    HLINE               hLine,
    LPLINEDEVSTATUS     lpLineDevStatus
    );

LONG
__stdcall
lineGetLineDevStatusW(
    HLINE               hLine,
    LPLINEDEVSTATUS     lpLineDevStatus
    );

#ifdef UNICODE
#define lineGetDevStatus lineGetDevStatusW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineGetDevStatus lineGetDevStatusA
#endif
#endif

#endif

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
__stdcall
lineGetMessage(                                                 // TAPI v2.0
    HLINEAPP        hLineApp,
    LPLINEMESSAGE   lpMessage,
    unsigned long           dwTimeout
    );
#endif

LONG
__stdcall
lineGetNumRings(
    HLINE               hLine,
    unsigned long               dwAddressID,
    LPDWORD             lpdwNumRings
    );

LONG
__stdcall
lineGetProviderList(                                            // TAPI v1.4
    unsigned long               dwAPIVersion,
    LPLINEPROVIDERLIST  lpProviderList
    );

#if WIN32
LONG
__stdcall
lineGetProviderListA(
    unsigned long               dwAPIVersion,
    LPLINEPROVIDERLIST  lpProviderList
    );

LONG
__stdcall
lineGetProviderListW(
    unsigned long               dwAPIVersion,
    LPLINEPROVIDERLIST  lpProviderList
    );

#ifdef UNICODE
#define lineGetProviderList lineGetProviderListW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineGetProviderList lineGetProviderListA
#endif
#endif

#endif

LONG
__stdcall
lineGetRequest(
    HLINEAPP            hLineApp,
    unsigned long               dwRequestMode,
    void*              lpRequestBuffer
    );

#if WIN32
LONG
__stdcall
lineGetRequestA(
    HLINEAPP            hLineApp,
    unsigned long               dwRequestMode,
    void*              lpRequestBuffer
    );

LONG
__stdcall
lineGetRequestW(
    HLINEAPP            hLineApp,
    unsigned long               dwRequestMode,
    void*              lpRequestBuffer
    );

#ifdef UNICODE
#define lineGetRequest lineGetRequestW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineGetRequest lineGetRequestA
#endif
#endif

#endif

LONG
__stdcall
lineGetStatusMessages(
    HLINE               hLine,
    LPDWORD             lpdwLineStates,
    LPDWORD             lpdwAddressStates
    );

LONG
__stdcall
lineGetTranslateCaps(
    HLINEAPP hLineApp,
    unsigned long dwAPIVersion,
    LPLINETRANSLATECAPS lpTranslateCaps
    );

#if WIN32
LONG
__stdcall
lineGetTranslateCapsA(
    HLINEAPP hLineApp,
    unsigned long dwAPIVersion,
    LPLINETRANSLATECAPS lpTranslateCaps
    );

LONG
__stdcall
lineGetTranslateCapsW(
    HLINEAPP hLineApp,
    unsigned long dwAPIVersion,
    LPLINETRANSLATECAPS lpTranslateCaps
    );

#ifdef UNICODE
#define lineGetTranslateCaps lineGetTranslateCapsW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineGetTranslateCaps lineGetTranslateCapsA
#endif
#endif

#endif


LONG
__stdcall
lineHandoff(
    HCALL               hCall,
    const char*              lpszFileName,
    unsigned long               dwMediaMode
    );

#if WIN32
LONG
__stdcall
lineHandoffA(
    HCALL               hCall,
    const char*              lpszFileName,
    unsigned long               dwMediaMode
    );

LONG
__stdcall
lineHandoffW(
    HCALL               hCall,
    const wchar_t*             lpszFileName,
    unsigned long               dwMediaMode
    );

#ifdef UNICODE
#define lineHandoff lineHandoffW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineHandoff lineHandoffA
#endif
#endif

#endif

LONG
__stdcall
lineHold(
    HCALL               hCall
    );

LONG
__stdcall
lineInitialize(
    LPHLINEAPP          lphLineApp,
    HINSTANCE           hInstance,
    LINECALLBACK        lpfnCallback,
    const char*              lpszAppName,
    LPDWORD             lpdwNumDevs
    );

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
__stdcall
lineInitializeExA(                                               // TAPI v2.0
    LPHLINEAPP                  lphLineApp,
    HINSTANCE                   hInstance,
    LINECALLBACK                lpfnCallback,
    const char*                      lpszFriendlyAppName,
    LPDWORD                     lpdwNumDevs,
    LPDWORD                     lpdwAPIVersion,
    LPLINEINITIALIZEEXPARAMS    lpLineInitializeExParams
    );

LONG
__stdcall
lineInitializeExW(                                               // TAPI v2.0
    LPHLINEAPP                  lphLineApp,
    HINSTANCE                   hInstance,
    LINECALLBACK                lpfnCallback,
    const wchar_t*                     lpszFriendlyAppName,
    LPDWORD                     lpdwNumDevs,
    LPDWORD                     lpdwAPIVersion,
    LPLINEINITIALIZEEXPARAMS    lpLineInitializeExParams
    );

#ifdef UNICODE
#define lineInitializeEx lineInitializeExW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineInitializeEx lineInitializeExA
#endif
#endif

#endif


LONG
__stdcall
lineMakeCall(
    HLINE               hLine,
    LPHCALL             lphCall,
    const char*              lpszDestAddress,
    unsigned long               dwCountryCode,
    LPLINECALLPARAMS    const lpCallParams
    );

#if WIN32
LONG
__stdcall
lineMakeCallA(
    HLINE               hLine,
    LPHCALL             lphCall,
    const char*              lpszDestAddress,
    unsigned long               dwCountryCode,
    LPLINECALLPARAMS    const lpCallParams
    );

LONG
__stdcall
lineMakeCallW(
    HLINE               hLine,
    LPHCALL             lphCall,
    const wchar_t*             lpszDestAddress,
    unsigned long               dwCountryCode,
    LPLINECALLPARAMS    const lpCallParams
    );

#ifdef UNICODE
#define lineMakeCall lineMakeCallW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineMakeCall lineMakeCallA
#endif
#endif

#endif

LONG
__stdcall
lineMonitorDigits(
    HCALL               hCall,
    unsigned long               dwDigitModes
    );

LONG
__stdcall
lineMonitorMedia(
    HCALL               hCall,
    unsigned long               dwMediaModes
    );

LONG
__stdcall
lineMonitorTones(
    HCALL               hCall,
    LPLINEMONITORTONE   const lpToneList,
    unsigned long               dwNumEntries
    );

LONG
__stdcall
lineNegotiateAPIVersion(
    HLINEAPP            hLineApp,
    unsigned long               dwDeviceID,
    unsigned long               dwAPILowVersion,
    unsigned long               dwAPIHighVersion,
    LPDWORD             lpdwAPIVersion,
    LPLINEEXTENSIONID   lpExtensionID
    );

LONG
__stdcall
lineNegotiateExtVersion(
    HLINEAPP            hLineApp,
    unsigned long               dwDeviceID,
    unsigned long               dwAPIVersion,
    unsigned long               dwExtLowVersion,
    unsigned long               dwExtHighVersion,
    LPDWORD             lpdwExtVersion
    );

LONG
__stdcall
lineOpen(
    HLINEAPP hLineApp, 
    unsigned long dwDeviceID,
    LPHLINE lphLine,
    unsigned long               dwAPIVersion,
    unsigned long               dwExtVersion,
    unsigned long               dwCallbackInstance,
    unsigned long               dwPrivileges,
    unsigned long               dwMediaModes,
    LPLINECALLPARAMS    const lpCallParams
    );

#if WIN32
LONG
__stdcall
lineOpenA(
    HLINEAPP hLineApp, 
    unsigned long dwDeviceID,
    LPHLINE lphLine,
    unsigned long               dwAPIVersion,
    unsigned long               dwExtVersion,
    unsigned long               dwCallbackInstance,
    unsigned long               dwPrivileges,
    unsigned long               dwMediaModes,
    LPLINECALLPARAMS    const lpCallParams
    );

LONG
__stdcall
lineOpenW(
    HLINEAPP hLineApp, 
    unsigned long dwDeviceID,
    LPHLINE lphLine,
    unsigned long               dwAPIVersion,
    unsigned long               dwExtVersion,
    unsigned long               dwCallbackInstance,
    unsigned long               dwPrivileges,
    unsigned long               dwMediaModes,
    LPLINECALLPARAMS    const lpCallParams
    );

#ifdef UNICODE
#define lineOpen lineOpenW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineOpen lineOpenA
#endif
#endif

#endif

LONG
__stdcall
linePark(
    HCALL               hCall,
    unsigned long               dwParkMode,
    const char*              lpszDirAddress,
    LPVARSTRING         lpNonDirAddress
    );

#if WIN32
LONG
__stdcall
lineParkA(
    HCALL               hCall,
    unsigned long               dwParkMode,
    const char*              lpszDirAddress,
    LPVARSTRING         lpNonDirAddress
    );

LONG
__stdcall
lineParkW(
    HCALL               hCall,
    unsigned long               dwParkMode,
    const wchar_t*             lpszDirAddress,
    LPVARSTRING         lpNonDirAddress
    );

#ifdef UNICODE
#define linePark lineParkW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define linePark lineParkA
#endif
#endif

#endif

LONG
__stdcall
linePickup(
    HLINE               hLine,
    unsigned long               dwAddressID,
    LPHCALL             lphCall,
    const char*              lpszDestAddress,
    const char*              lpszGroupID
    );

#if WIN32
LONG
__stdcall
linePickupA(
    HLINE               hLine,
    unsigned long               dwAddressID,
    LPHCALL             lphCall,
    const char*              lpszDestAddress,
    const char*              lpszGroupID
    );

LONG
__stdcall
linePickupW(
    HLINE               hLine,
    unsigned long               dwAddressID,
    LPHCALL             lphCall,
    const wchar_t*             lpszDestAddress,
    const wchar_t*             lpszGroupID
    );

#ifdef UNICODE
#define linePickup linePickupW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define linePickup linePickupA
#endif
#endif

#endif

LONG
__stdcall
linePrepareAddToConference(
    HCALL               hConfCall,
    LPHCALL             lphConsultCall,
    LPLINECALLPARAMS    const lpCallParams
    );

#if WIN32
LONG
__stdcall
linePrepareAddToConferenceA(
    HCALL               hConfCall,
    LPHCALL             lphConsultCall,
    LPLINECALLPARAMS    const lpCallParams
    );

LONG
__stdcall
linePrepareAddToConferenceW(
    HCALL               hConfCall,
    LPHCALL             lphConsultCall,
    LPLINECALLPARAMS    const lpCallParams
    );

#ifdef UNICODE
#define linePrepareAddToConference linePrepareAddToConferenceW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define linePrepareAddToConference linePrepareAddToConferenceA
#endif
#endif

#endif

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
__stdcall
lineProxyMessage(                                               // TAPI v2.0
    HLINE               hLine,
    HCALL               hCall,
    unsigned long               dwMsg,
    unsigned long               dwParam1,
    unsigned long               dwParam2,
    unsigned long               dwParam3
    );

LONG
__stdcall
lineProxyResponse(                                              // TAPI v2.0
    HLINE               hLine,
    LPLINEPROXYREQUEST  lpProxyRequest,
    unsigned long               dwResult
    );
#endif

LONG
__stdcall
lineRedirect(
    HCALL               hCall,
    const char*              lpszDestAddress,
    unsigned long               dwCountryCode
    );

#if WIN32
LONG
__stdcall
lineRedirectA(
    HCALL               hCall,
    const char*              lpszDestAddress,
    unsigned long               dwCountryCode
    );

LONG
__stdcall
lineRedirectW(
    HCALL               hCall,
    const wchar_t*             lpszDestAddress,
    unsigned long               dwCountryCode
    );

#ifdef UNICODE
#define lineRedirect lineRedirectW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineRedirect lineRedirectA
#endif
#endif

#endif

LONG
__stdcall
lineRegisterRequestRecipient(
    HLINEAPP            hLineApp,
    unsigned long               dwRegistrationInstance,
    unsigned long               dwRequestMode,
    unsigned long               bEnable
    );

LONG
__stdcall
lineReleaseUserUserInfo(                                        // TAPI v1.4
    HCALL               hCall
    );

LONG
__stdcall
lineRemoveFromConference(
    HCALL               hCall
    );

LONG
__stdcall
lineRemoveProvider(                                             // TAPI v1.4
    unsigned long               dwPermanentProviderID,
    HWND                hwndOwner
    );

LONG
__stdcall
lineSecureCall(
    HCALL               hCall
    );

LONG
__stdcall
lineSendUserUserInfo(
    HCALL               hCall,
    const char*              lpsUserUserInfo,
    unsigned long               dwSize
    );

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
__stdcall
lineSetAgentActivity(                                           // TAPI v2.0
    HLINE               hLine,
    unsigned long               dwAddressID,
    unsigned long               dwActivityID
    );

LONG
__stdcall
lineSetAgentGroup(                                              // TAPI v2.0
    HLINE                   hLine,
    unsigned long                   dwAddressID,
    LPLINEAGENTGROUPLIST    lpAgentGroupList
    );

LONG
__stdcall
lineSetAgentState(                                              // TAPI v2.0
    HLINE               hLine,
    unsigned long               dwAddressID,
    unsigned long               dwAgentState,
    unsigned long               dwNextAgentState
    );
#endif

LONG
__stdcall
lineSetAppPriority(                                             // TAPI v1.4
    const char*              lpszAppFilename,
    unsigned long               dwMediaMode,
    LPLINEEXTENSIONID   lpExtensionID,
    unsigned long               dwRequestMode,
    const char*              lpszExtensionName,
    unsigned long               dwPriority
    );

#if WIN32
LONG
__stdcall
lineSetAppPriorityA(                                             // TAPI v1.4
    const char*              lpszAppFilename,
    unsigned long               dwMediaMode,
    LPLINEEXTENSIONID   lpExtensionID,
    unsigned long               dwRequestMode,
    const char*              lpszExtensionName,
    unsigned long               dwPriority
    );

LONG
__stdcall
lineSetAppPriorityW(                                             // TAPI v1.4
    const wchar_t*             lpszAppFilename,
    unsigned long               dwMediaMode,
    LPLINEEXTENSIONID   lpExtensionID,
    unsigned long               dwRequestMode,
    const wchar_t*             lpszExtensionName,
    unsigned long               dwPriority
    );

#ifdef UNICODE
#define lineSetAppPriority lineSetAppPriorityW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineSetAppPriority lineSetAppPriorityA
#endif
#endif

#endif

LONG
__stdcall
lineSetAppSpecific(
    HCALL               hCall,
    unsigned long               dwAppSpecific
    );

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
__stdcall
lineSetCallData(                                                // TAPI v2.0
    HCALL               hCall,
    void*              lpCallData,
    unsigned long               dwSize
    );
#endif

LONG
__stdcall
lineSetCallParams(
    HCALL               hCall,
    unsigned long               dwBearerMode,
    unsigned long               dwMinRate,
    unsigned long               dwMaxRate,
    LPLINEDIALPARAMS    const lpDialParams
    );

LONG
__stdcall
lineSetCallPrivilege(
    HCALL               hCall,
    unsigned long               dwCallPrivilege
    );

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
__stdcall
lineSetCallQualityOfService(                                    // TAPI v2.0
    HCALL               hCall,
    void*              lpSendingFlowspec,
    unsigned long               dwSendingFlowspecSize,
    void*              lpReceivingFlowspec,
    unsigned long               dwReceivingFlowspecSize
    );

LONG
__stdcall
lineSetCallTreatment(                                           // TAPI v2.0
    HCALL               hCall,
    unsigned long               dwTreatment
    );
#endif

LONG
__stdcall
lineSetCurrentLocation(
    HLINEAPP            hLineApp,
    unsigned long               dwLocation
    );

LONG
__stdcall
lineSetDevConfig(
    unsigned long               dwDeviceID,
    void*              const lpDeviceConfig,
    unsigned long               dwSize,
    const char*              lpszDeviceClass
    );

#if WIN32
LONG
__stdcall
lineSetDevConfigA(
    unsigned long               dwDeviceID,
    void*              const lpDeviceConfig,
    unsigned long               dwSize,
    const char*              lpszDeviceClass
    );

LONG
__stdcall
lineSetDevConfigW(
    unsigned long               dwDeviceID,
    void*              const lpDeviceConfig,
    unsigned long               dwSize,
    const wchar_t*             lpszDeviceClass
    );

#ifdef UNICODE
#define lineSetDevConfig lineSetDevConfigW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineSetDevConfig lineSetDevConfigA
#endif
#endif

#endif

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
__stdcall
lineSetLineDevStatus(                                           // TAPI v2.0
    HLINE               hLine,
    unsigned long               dwStatusToChange,
    unsigned long               fStatus
    );
#endif

LONG
__stdcall
lineSetMediaControl(
    HLINE                       hLine,
    unsigned long                       dwAddressID,
    HCALL                       hCall,
    unsigned long                       dwSelect,
    LPLINEMEDIACONTROLDIGIT     const lpDigitList,
    unsigned long                       dwDigitNumEntries,
    LPLINEMEDIACONTROLMEDIA     const lpMediaList,
    unsigned long                       dwMediaNumEntries,
    LPLINEMEDIACONTROLTONE      const lpToneList,
    unsigned long                       dwToneNumEntries,
    LPLINEMEDIACONTROLCALLSTATE const lpCallStateList, 
    unsigned long                       dwCallStateNumEntries
    );

LONG
__stdcall
lineSetMediaMode(
    HCALL               hCall,
    unsigned long               dwMediaModes
    );

LONG
__stdcall
lineSetNumRings(
    HLINE               hLine,
    unsigned long               dwAddressID,
    unsigned long               dwNumRings
    );

LONG
__stdcall
lineSetStatusMessages(
    HLINE               hLine,
    unsigned long               dwLineStates,
    unsigned long               dwAddressStates
    );

LONG
__stdcall
lineSetTerminal(
    HLINE               hLine,
    unsigned long               dwAddressID,
    HCALL               hCall,
    unsigned long               dwSelect,
    unsigned long               dwTerminalModes,
    unsigned long               dwTerminalID,
    unsigned long               bEnable
    );

LONG
__stdcall
lineSetTollList(
    HLINEAPP            hLineApp,
    unsigned long               dwDeviceID,
    const char*              lpszAddressIn,
    unsigned long               dwTollListOption
    );

#if WIN32
LONG
__stdcall
lineSetTollListA(
    HLINEAPP            hLineApp,
    unsigned long               dwDeviceID,
    const char*              lpszAddressIn,
    unsigned long               dwTollListOption
    );

LONG
__stdcall
lineSetTollListW(
    HLINEAPP            hLineApp,
    unsigned long               dwDeviceID,
    const wchar_t*             lpszAddressInW,
    unsigned long               dwTollListOption
    );

#ifdef UNICODE
#define lineSetTollList lineSetTollListW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineSetTollList lineSetTollListA
#endif
#endif

#endif


LONG
__stdcall
lineSetupConference(
    HCALL               hCall,
    HLINE               hLine,
    LPHCALL             lphConfCall,
    LPHCALL             lphConsultCall,
    unsigned long               dwNumParties,
    LPLINECALLPARAMS    const lpCallParams
    );

#if WIN32
LONG
__stdcall
lineSetupConferenceA(
    HCALL               hCall,
    HLINE               hLine,
    LPHCALL             lphConfCall,
    LPHCALL             lphConsultCall,
    unsigned long               dwNumParties,
    LPLINECALLPARAMS    const lpCallParams
    );

LONG
__stdcall
lineSetupConferenceW(
    HCALL               hCall,
    HLINE               hLine,
    LPHCALL             lphConfCall,
    LPHCALL             lphConsultCall,
    unsigned long               dwNumParties,
    LPLINECALLPARAMS    const lpCallParams
    );

#ifdef UNICODE
#define lineSetupConference lineSetupConferenceW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineSetupConference lineSetupConferenceA
#endif
#endif

#endif

LONG
__stdcall
lineSetupTransfer(
    HCALL               hCall,
    LPHCALL             lphConsultCall,
    LPLINECALLPARAMS    const lpCallParams
    );

#if WIN32
LONG
__stdcall
lineSetupTransferA(
    HCALL               hCall,
    LPHCALL             lphConsultCall,
    LPLINECALLPARAMS    const lpCallParams
    );

LONG
__stdcall
lineSetupTransferW(
    HCALL               hCall,
    LPHCALL             lphConsultCall,
    LPLINECALLPARAMS    const lpCallParams
    );

#ifdef UNICODE
#define lineSetupTransfer lineSetupTransferW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineSetupTransfer lineSetupTransferA
#endif
#endif

#endif

LONG
__stdcall
lineShutdown(
    HLINEAPP            hLineApp
    );

LONG
__stdcall
lineSwapHold(
    HCALL               hActiveCall,
    HCALL               hHeldCall
    );

LONG
__stdcall
lineTranslateAddress(
    HLINEAPP                hLineApp,
    unsigned long                   dwDeviceID,
    unsigned long                   dwAPIVersion,
    const char*                  lpszAddressIn,
    unsigned long                   dwCard,
    unsigned long                   dwTranslateOptions,
    LPLINETRANSLATEOUTPUT   lpTranslateOutput
    );

#if WIN32
LONG
__stdcall
lineTranslateAddressA(
    HLINEAPP                hLineApp,
    unsigned long                   dwDeviceID,
    unsigned long                   dwAPIVersion,
    const char*                  lpszAddressIn,
    unsigned long                   dwCard,
    unsigned long                   dwTranslateOptions,
    LPLINETRANSLATEOUTPUT   lpTranslateOutput
    );

LONG
__stdcall
lineTranslateAddressW(
    HLINEAPP                hLineApp,
    unsigned long                   dwDeviceID,
    unsigned long                   dwAPIVersion,
    const wchar_t*                 lpszAddressIn,
    unsigned long                   dwCard,
    unsigned long                   dwTranslateOptions,
    LPLINETRANSLATEOUTPUT   lpTranslateOutput
    );

#ifdef UNICODE
#define lineTranslateAddress lineTranslateAddressW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineTranslateAddressA lineTranslateAddressA
#endif
#endif

#endif

LONG
__stdcall
lineTranslateDialog(                                            // TAPI v1.4
    HLINEAPP            hLineApp,
    unsigned long               dwDeviceID,
    unsigned long               dwAPIVersion,
    HWND                hwndOwner,
    const char*              lpszAddressIn
    );

#if WIN32
LONG
__stdcall
lineTranslateDialogA(                                            // TAPI v1.4
    HLINEAPP            hLineApp,
    unsigned long               dwDeviceID,
    unsigned long               dwAPIVersion,
    HWND                hwndOwner,
    const char*              lpszAddressIn
    );

LONG
__stdcall
lineTranslateDialogW(
    HLINEAPP            hLineApp,
    unsigned long               dwDeviceID,
    unsigned long               dwAPIVersion,
    HWND                hwndOwner,
    const wchar_t*             lpszAddressIn
    );

#ifdef UNICODE
#define lineTranslateDialog lineTranslateDialogW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineTranslateDialogA lineTranslateDialogA
#endif
#endif

#endif

LONG
__stdcall
lineUncompleteCall(
    HLINE               hLine,
    unsigned long               dwCompletionID
    );

LONG
__stdcall
lineUnhold(
    HCALL               hCall
    );

LONG
__stdcall
lineUnpark(
    HLINE               hLine,
    unsigned long               dwAddressID,
    LPHCALL             lphCall,
    const char*              lpszDestAddress
    );

#if WIN32
LONG
__stdcall
lineUnparkA(
    HLINE               hLine,
    unsigned long               dwAddressID,
    LPHCALL             lphCall,
    const char*              lpszDestAddress
    );

LONG
__stdcall
lineUnparkW(
    HLINE               hLine,
    unsigned long               dwAddressID,
    LPHCALL             lphCall,
    const wchar_t*             lpszDestAddress
    );

#ifdef UNICODE
#define lineUnpark lineUnparkW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define lineUnpark lineUnparkA
#endif
#endif

#endif



LONG
__stdcall
phoneClose(
    HPHONE              hPhone
    );

LONG
__stdcall
phoneConfigDialog(
    unsigned long               dwDeviceID,
    HWND                hwndOwner,
    const char*              lpszDeviceClass
    );

#if WIN32
LONG
__stdcall
phoneConfigDialogA(
    unsigned long               dwDeviceID,
    HWND                hwndOwner,
    const char*              lpszDeviceClass
    );

LONG
__stdcall
phoneConfigDialogW(
    unsigned long               dwDeviceID,
    HWND                hwndOwner,
    const wchar_t*             lpszDeviceClass
    );

#ifdef UNICODE
#define phoneConfigDialog phoneConfigDialogW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define phoneConfigDialog phoneConfigDialogA
#endif
#endif

#endif

LONG
__stdcall
phoneDevSpecific(
    HPHONE              hPhone,
    void*              lpParams,
    unsigned long               dwSize
    );

LONG
__stdcall
phoneGetButtonInfo(
    HPHONE              hPhone,
    unsigned long               dwButtonLampID,
    LPPHONEBUTTONINFO   lpButtonInfo
    );

#if WIN32
LONG
__stdcall
phoneGetButtonInfoA(
    HPHONE              hPhone,
    unsigned long               dwButtonLampID,
    LPPHONEBUTTONINFO   lpButtonInfo
    );

LONG
__stdcall
phoneGetButtonInfoW(
    HPHONE              hPhone,
    unsigned long               dwButtonLampID,
    LPPHONEBUTTONINFO   lpButtonInfo
    );

#ifdef UNICODE
#define phoneGetButtonInfo phoneGetButtonInfoW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define phoneGetButtonInfo phoneGetButtonInfoA
#endif
#endif

#endif

LONG
__stdcall
phoneGetData(
    HPHONE              hPhone,
    unsigned long               dwDataID,
    void*              lpData,
    unsigned long               dwSize
    );

LONG
__stdcall
phoneGetDevCaps(
    HPHONEAPP           hPhoneApp,
    unsigned long               dwDeviceID,
    unsigned long               dwAPIVersion,
    unsigned long               dwExtVersion,
    LPPHONECAPS         lpPhoneCaps
    );

#if WIN32
LONG
__stdcall
phoneGetDevCapsA(
    HPHONEAPP           hPhoneApp,
    unsigned long               dwDeviceID,
    unsigned long               dwAPIVersion,
    unsigned long               dwExtVersion,
    LPPHONECAPS         lpPhoneCaps
    );

LONG
__stdcall
phoneGetDevCapsW(
    HPHONEAPP           hPhoneApp,
    unsigned long               dwDeviceID,
    unsigned long               dwAPIVersion,
    unsigned long               dwExtVersion,
    LPPHONECAPS         lpPhoneCaps
    );

#ifdef UNICODE
#define phoneGetDevCaps phoneGetDevCapsW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define phoneGetDevCaps phoneGetDevCapsA
#endif
#endif

#endif

LONG
__stdcall
phoneGetDisplay(
    HPHONE              hPhone,
    LPVARSTRING         lpDisplay
    );

LONG
__stdcall
phoneGetGain(
    HPHONE              hPhone,
    unsigned long               dwHookSwitchDev,
    LPDWORD             lpdwGain
    );

LONG
__stdcall
phoneGetHookSwitch(
    HPHONE              hPhone,
    LPDWORD             lpdwHookSwitchDevs
    );

LONG
__stdcall
phoneGetIcon(
    unsigned long               dwDeviceID,
    const char*              lpszDeviceClass,
    LPHICON             lphIcon
    );

#if WIN32
LONG
__stdcall
phoneGetIconA(
    unsigned long               dwDeviceID,
    const char*              lpszDeviceClass,
    LPHICON             lphIcon
    );

LONG
__stdcall
phoneGetIconW(
    unsigned long               dwDeviceID,
    const wchar_t*             lpszDeviceClass,
    LPHICON             lphIcon
    );

#ifdef UNICODE
#define phoneGetIcon phoneGetIconW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define phoneGetIcon phoneGetIconA
#endif
#endif

#endif

LONG
__stdcall
phoneGetID(
    HPHONE              hPhone,
    LPVARSTRING         lpDeviceID,
    const char*              lpszDeviceClass
    );

#if WIN32
LONG
__stdcall
phoneGetIDA(
    HPHONE              hPhone,
    LPVARSTRING         lpDeviceID,
    const char*              lpszDeviceClass
    );

LONG
__stdcall
phoneGetIDW(
    HPHONE              hPhone,
    LPVARSTRING         lpDeviceID,
    const wchar_t*             lpszDeviceClass
    );

#ifdef UNICODE
#define phoneGetID phoneGetIDW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define phoneGetID phoneGetIDA
#endif
#endif

#endif

LONG
__stdcall
phoneGetLamp(
    HPHONE              hPhone,
    unsigned long               dwButtonLampID,
    LPDWORD             lpdwLampMode
    );

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
__stdcall
phoneGetMessage(                                                // TAPI v2.0
    HPHONEAPP       hPhoneApp,
    LPPHONEMESSAGE  lpMessage,
    unsigned long           dwTimeout
    );
#endif

LONG
__stdcall
phoneGetRing(
    HPHONE              hPhone,
    LPDWORD             lpdwRingMode,
    LPDWORD             lpdwVolume
    );

LONG
__stdcall
phoneGetStatus(
    HPHONE              hPhone,
    LPPHONESTATUS       lpPhoneStatus
    );

#if WIN32
LONG
__stdcall
phoneGetStatusA(
    HPHONE              hPhone,
    LPPHONESTATUS       lpPhoneStatus
    );

LONG
__stdcall
phoneGetStatusW(
    HPHONE              hPhone,
    LPPHONESTATUS       lpPhoneStatus
    );


#ifdef UNICODE
#define phoneGetStatus phoneGetStatusW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define phoneGetStatus phoneGetStatusA
#endif
#endif

#endif

LONG
__stdcall
phoneGetStatusMessages(
    HPHONE              hPhone,
    LPDWORD             lpdwPhoneStates,
    LPDWORD             lpdwButtonModes,
    LPDWORD             lpdwButtonStates
    );

LONG
__stdcall
phoneGetVolume(
    HPHONE              hPhone,
    unsigned long               dwHookSwitchDev,
    LPDWORD             lpdwVolume
    );

LONG
__stdcall
phoneInitialize(
    LPHPHONEAPP         lphPhoneApp,
    HINSTANCE           hInstance,
    PHONECALLBACK       lpfnCallback,
    const char*              lpszAppName,
    LPDWORD             lpdwNumDevs
    );


#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
__stdcall
phoneInitializeExA(                                              // TAPI v2.0
    LPHPHONEAPP                 lphPhoneApp,
    HINSTANCE                   hInstance,
    PHONECALLBACK               lpfnCallback,
    const char*                      lpszFriendlyAppName,
    LPDWORD                     lpdwNumDevs,
    LPDWORD                     lpdwAPIVersion,
    LPPHONEINITIALIZEEXPARAMS   lpPhoneInitializeExParams
    );

LONG
__stdcall
phoneInitializeExW(                                              // TAPI v2.0
    LPHPHONEAPP                 lphPhoneApp,
    HINSTANCE                   hInstance,
    PHONECALLBACK               lpfnCallback,
    const wchar_t*                     lpszFriendlyAppName,
    LPDWORD                     lpdwNumDevs,
    LPDWORD                     lpdwAPIVersion,
    LPPHONEINITIALIZEEXPARAMS   lpPhoneInitializeExParams
    );

#ifdef UNICODE
#define phoneInitializeEx phoneInitializeExW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define phoneInitializeEx phoneInitializeExA
#endif
#endif

#endif

LONG
__stdcall
phoneNegotiateAPIVersion(
    HPHONEAPP           hPhoneApp,
    unsigned long               dwDeviceID,
    unsigned long               dwAPILowVersion,
    unsigned long               dwAPIHighVersion,
    LPDWORD             lpdwAPIVersion,
    LPPHONEEXTENSIONID  lpExtensionID
    );

LONG
__stdcall
phoneNegotiateExtVersion(
    HPHONEAPP           hPhoneApp,
    unsigned long               dwDeviceID,
    unsigned long               dwAPIVersion,
    unsigned long               dwExtLowVersion,
    unsigned long               dwExtHighVersion,
    LPDWORD             lpdwExtVersion
    );

LONG
__stdcall
phoneOpen(
    HPHONEAPP           hPhoneApp,
    unsigned long               dwDeviceID,
    LPHPHONE            lphPhone,
    unsigned long               dwAPIVersion,
    unsigned long               dwExtVersion,
    unsigned long               dwCallbackInstance,
    unsigned long               dwPrivilege
    );

LONG
__stdcall
phoneSetButtonInfo(
    HPHONE              hPhone,
    unsigned long               dwButtonLampID,
    LPPHONEBUTTONINFO   const lpButtonInfo
    );

#if WIN32
LONG
__stdcall
phoneSetButtonInfoA(
    HPHONE              hPhone,
    unsigned long               dwButtonLampID,
    LPPHONEBUTTONINFO   const lpButtonInfo
    );

LONG
__stdcall
phoneSetButtonInfoW(
    HPHONE              hPhone,
    unsigned long               dwButtonLampID,
    LPPHONEBUTTONINFO   const lpButtonInfo
    );

#ifdef UNICODE
#define phoneSetButtonInfo phoneSetButtonInfoW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define phoneSetButtonInfo phoneSetButtonInfoA
#endif
#endif

#endif

LONG
__stdcall
phoneSetData(
    HPHONE              hPhone,
    unsigned long               dwDataID,
    void*              const lpData,
    unsigned long               dwSize
    );

LONG
__stdcall
phoneSetDisplay(
    HPHONE              hPhone,
    unsigned long               dwRow,
    unsigned long               dwColumn,
    const char*              lpsDisplay,
    unsigned long               dwSize
    );

LONG
__stdcall
phoneSetGain(
    HPHONE              hPhone,
    unsigned long               dwHookSwitchDev,
    unsigned long               dwGain
    );

LONG
__stdcall
phoneSetHookSwitch(
    HPHONE              hPhone,
    unsigned long               dwHookSwitchDevs,
    unsigned long               dwHookSwitchMode
    );

LONG
__stdcall
phoneSetLamp(
    HPHONE              hPhone,
    unsigned long               dwButtonLampID,
    unsigned long               dwLampMode
    );

LONG
__stdcall
phoneSetRing(
    HPHONE              hPhone,
    unsigned long               dwRingMode,
    unsigned long               dwVolume
    );

LONG
__stdcall
phoneSetStatusMessages(
    HPHONE              hPhone,
    unsigned long               dwPhoneStates,
    unsigned long               dwButtonModes,
    unsigned long               dwButtonStates
    );

LONG
__stdcall
phoneSetVolume(
    HPHONE              hPhone,
    unsigned long               dwHookSwitchDev,
    unsigned long               dwVolume
    );

LONG
__stdcall
phoneShutdown(
    HPHONEAPP           hPhoneApp
    );



LONG
__stdcall
tapiGetLocationInfo(
    LPSTR               lpszCountryCode,
    LPSTR               lpszCityCode
    );
    
#if WIN32
LONG
__stdcall
tapiGetLocationInfoA(
    LPSTR               lpszCountryCode,
    LPSTR               lpszCityCode
    );
    
LONG
__stdcall
tapiGetLocationInfoW(
    LPWSTR               lpszCountryCodeW,
    LPWSTR               lpszCityCodeW
    );

#ifdef UNICODE
#define tapiGetLocationInfo tapiGetLocationInfoW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define tapiGetLocationInfo tapiGetLocationInfoA
#endif
#endif

#endif
    

LONG
__stdcall
tapiRequestDrop(
    HWND                hwnd,
    WPARAM              wRequestID
    );

LONG
__stdcall
tapiRequestMakeCall(
    const char*              lpszDestAddress,
    const char*              lpszAppName,
    const char*              lpszCalledParty,
    const char*              lpszComment
    );

#if WIN32
LONG
__stdcall
tapiRequestMakeCallA(
    const char*              lpszDestAddress,
    const char*              lpszAppName,
    const char*              lpszCalledParty,
    const char*              lpszComment
    );

LONG
__stdcall
tapiRequestMakeCallW(
    const wchar_t*              lpszDestAddress,
    const wchar_t*              lpszAppName,
    const wchar_t*              lpszCalledParty,
    const wchar_t*              lpszComment
    );

#ifdef UNICODE
#define tapiRequestMakeCall tapiRequestMakeCallW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define tapiRequestMakeCall tapiRequestMakeCallA
#endif
#endif

#endif
    
LONG
__stdcall
tapiRequestMediaCall(
    HWND                hwnd,
    WPARAM              wRequestID,
    const char*              lpszDeviceClass,
    const char*              lpDeviceID,
    unsigned long               dwSize,
    unsigned long               dwSecure,
    const char*              lpszDestAddress,
    const char*              lpszAppName,
    const char*              lpszCalledParty,
    const char*              lpszComment
    );

#if WIN32
LONG
__stdcall
tapiRequestMediaCallA(
    HWND                hwnd,
    WPARAM              wRequestID,
    const char*              lpszDeviceClass,
    const char*              lpDeviceID,
    unsigned long               dwSize,
    unsigned long               dwSecure,
    const char*              lpszDestAddress,
    const char*              lpszAppName,
    const char*              lpszCalledParty,
    const char*              lpszComment
    );

LONG
__stdcall
tapiRequestMediaCallW(
    HWND                hwnd,
    WPARAM              wRequestID,
    const wchar_t*             lpszDeviceClass,
    const wchar_t*             lpDeviceID,
    unsigned long               dwSize,
    unsigned long               dwSecure,
    const wchar_t*             lpszDestAddress,
    const wchar_t*             lpszAppName,
    const wchar_t*             lpszCalledParty,
    const wchar_t*             lpszComment
    );

#ifdef UNICODE
#define tapiRequestMediaCall tapiRequestMediaCallW
#else
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define tapiRequestMediaCall tapiRequestMediaCallA
#endif
#endif

#endif
    
/*

TAPIERROR_FORMATMESSAGE - macro to convert a TAPI error constant
    into a constant that FormatMessage will accept
    
        TAPIERR : Negative numbers and 0
            Map to : strip off high WORD
            Example: 0xFFFFFFFF (-1) becomes 0x0000FFFF
        LINEERR : Start at 0x80000000
            Map to : strip off 0x80000000 and add 0xE000
            Example: 0x80000004 becomes 0x0000E004
        PHONEERR: Start at 0x90000000
            Map to : strip off 0x90000000 and add 0xF000
            Example: 0x9000000A becomes 0x0000F00A

        pseudocode:
        
        if (__ErrCode__ is a TAPIERR)
            strip off high word

            else if (__ErrCode__ is a PHONEERR)
                strip off 0x90000000
                add 0xE000

                else
                    strip off 0x80000000
                    add 0xF000

*/

#define TAPIERROR_FORMATMESSAGE(__ErrCode__)                                                   \
                                                                                               \
                    ( ( (__ErrCode__) > 0xFFFF0000 ) ?                                         \
                                                                                               \
                            ( (__ErrCode__) & 0x0000FFFF ) :                                   \
                                                                                               \
                            ( ( (__ErrCode__) & 0x10000000 ) ?                                 \
                                                                                               \
                              ( (__ErrCode__) - 0x90000000 + 0xF000 ) :                        \
                                                                                               \
                              ( (__ErrCode__) - 0x80000000 + 0xE000 ) ) )



#ifdef __cplusplus
}                       /* End of extern "C" { */
#endif  /* __cplusplus */

#pragma pack()

#endif // TAPI_H
#pragma once 
