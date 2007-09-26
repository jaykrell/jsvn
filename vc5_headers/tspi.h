/*++ BUILD Version: 0000    // Increment this if a change has global effects

The  Telephony  API  is jointly copyrighted by Intel and Microsoft.  You are
granted  a royalty free worldwide, unlimited license to make copies, and use
the   API/SPI  for  making  applications/drivers  that  interface  with  the
specification provided that this paragraph and the Intel/Microsoft copyright
statement is maintained as is in the text and source code files.

Copyright (c) 1992-1996  Microsoft Corporation
Portions copyright 1992, 1993 Intel/Microsoft, all rights reserved.

Module Name:

    tspi.h

Notes:

    Additions to the Telephony Service Provider Interface (TSPI) since
    version 1.0 are noted by version number (i.e. "TSPI v1.4").

--*/

#ifndef TSPI_H
#define TSPI_H


#include <windows.h>

#include "tapi.h"


#if WIN32
#if TAPI_CURRENT_VERSION < 0x00020000
#error Building a 32bit 1.3 or 1.4 service provider is not supported.
#endif
#endif


// tspi.h  is  only  of  use  in  conjunction  with tapi.h.  Very few types are
// defined  in  tspi.h.   Most  types of procedure formal parameters are simply
// passed through from corresponding procedures in tapi.h.  A working knowledge
// of the TAPI interface is required for an understanding of this interface.

#ifdef __cplusplus
extern "C" {            /* Assume C declarations for C++ */
#endif  /* __cplusplus */

#ifndef DECLARE_OPAQUE32
#define DECLARE_OPAQUE32(name)  struct name##__ { int unused; }; \
                typedef const struct name##__ * name
#endif  // DECLARE_OPAQUE32

#ifndef TSPIAPI

#define TSPIAPI PASCAL

#endif

DECLARE_OPAQUE32(HDRVCALL);
DECLARE_OPAQUE32(HDRVLINE);
DECLARE_OPAQUE32(HDRVPHONE);
DECLARE_OPAQUE32(HDRVDIALOGINSTANCE);

typedef HDRVCALL  * LPHDRVCALL;
typedef HDRVLINE  * LPHDRVLINE;
typedef HDRVPHONE  * LPHDRVPHONE;
typedef HDRVDIALOGINSTANCE  * LPHDRVDIALOGINSTANCE;

DECLARE_OPAQUE32(HTAPICALL);
DECLARE_OPAQUE32(HTAPILINE);
DECLARE_OPAQUE32(HTAPIPHONE);
DECLARE_OPAQUE32(HTAPIDIALOGINSTANCE);

typedef HTAPICALL  * LPHTAPICALL;
typedef HTAPILINE  * LPHTAPILINE;
typedef HTAPIPHONE  * LPHTAPIPHONE;
typedef HTAPIDIALOGINSTANCE  * LPHTAPIDIALOGINSTANCE;


DECLARE_OPAQUE32(HPROVIDER);
typedef HPROVIDER  * LPHPROVIDER;

typedef unsigned long DRV_REQUESTID;

typedef void (__stdcall * ASYNC_COMPLETION)(
    DRV_REQUESTID       dwRequestID,
    LONG                lResult
    );

typedef void (__stdcall * LINEEVENT)(
    HTAPILINE           htLine,
    HTAPICALL           htCall,
    unsigned long               dwMsg,
    unsigned long               dwParam1,
    unsigned long               dwParam2,
    unsigned long               dwParam3
    );

typedef void (__stdcall * PHONEEVENT)(
    HTAPIPHONE          htPhone,
    unsigned long               dwMsg,
    unsigned long               dwParam1,
    unsigned long               dwParam2,
    unsigned long               dwParam3
    );

typedef LONG (__stdcall * TUISPIDLLCALLBACK)(
    unsigned long               dwObjectID,
    unsigned long               dwObjectType,
    void*              lpParams,
    unsigned long               dwSize
    );

#if TAPI_CURRENT_VERSION >= 0x00020000
typedef struct tuispicreatedialoginstanceparams_tag
{
    DRV_REQUESTID           dwRequestID;

    HDRVDIALOGINSTANCE      hdDlgInst;

    HTAPIDIALOGINSTANCE     htDlgInst;

    const wchar_t*                 lpszUIDLLName;

    void*                  lpParams;

    unsigned long                   dwSize;

} TUISPICREATEDIALOGINSTANCEPARAMS, *LPTUISPICREATEDIALOGINSTANCEPARAMS;
#endif


#define TSPI_MESSAGE_BASE 500
    // The lowest-numbered TSPI-specific message ID number

#define LINE_NEWCALL                            ((long) TSPI_MESSAGE_BASE + 0)
#define LINE_CALLDEVSPECIFIC                    ((long) TSPI_MESSAGE_BASE + 1)
#define LINE_CALLDEVSPECIFICFEATURE             ((long) TSPI_MESSAGE_BASE + 2)
#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define LINE_CREATEDIALOGINSTANCE               ((long) TSPI_MESSAGE_BASE + 3)
                                                                // TSPI v2.0
#define LINE_SENDDIALOGINSTANCEDATA             ((long) TSPI_MESSAGE_BASE + 4)
                                                                // TSPI v2.0
#endif


#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define LINETSPIOPTION_NONREENTRANT             0x00000001      // TSPI v2.0
#endif


#if (TAPI_CURRENT_VERSION >= 0x00020000)
#define TUISPIDLL_OBJECT_LINEID                 1L              // TSPI v2.0
#define TUISPIDLL_OBJECT_PHONEID                2L              // TSPI v2.0
#define TUISPIDLL_OBJECT_PROVIDERID             3L              // TSPI v2.0
#define TUISPIDLL_OBJECT_DIALOGINSTANCE         4L              // TSPI v2.0
#endif


//
// The following function prototypes pertain
// to a service provider's core module
//



LONG
TSPIAPI
TSPI_lineAccept(
    DRV_REQUESTID       dwRequestID,
    HDRVCALL            hdCall,
    const char*              lpsUserUserInfo,
    unsigned long               dwSize
    );

LONG
TSPIAPI
TSPI_lineAddToConference(
    DRV_REQUESTID       dwRequestID,
    HDRVCALL            hdConfCall,
    HDRVCALL            hdConsultCall
    );

LONG
TSPIAPI
TSPI_lineAnswer(
    DRV_REQUESTID       dwRequestID,
    HDRVCALL            hdCall,
    const char*              lpsUserUserInfo,
    unsigned long               dwSize
    );

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
TSPIAPI
TSPI_lineBlindTransfer(
    DRV_REQUESTID       dwRequestID,
    HDRVCALL            hdCall,
    const wchar_t*             lpszDestAddress,
    unsigned long               dwCountryCode);
#else
LONG
TSPIAPI
TSPI_lineBlindTransfer(
    DRV_REQUESTID       dwRequestID,
    HDRVCALL            hdCall,
    const char*              lpszDestAddress,
    unsigned long               dwCountryCode);
#endif

LONG
TSPIAPI
TSPI_lineClose(
    HDRVLINE            hdLine
    );

LONG
TSPIAPI
TSPI_lineCloseCall(
    HDRVCALL            hdCall
    );

LONG
TSPIAPI
TSPI_lineCompleteCall(
    DRV_REQUESTID       dwRequestID,
    HDRVCALL            hdCall,
    LPDWORD             lpdwCompletionID,
    unsigned long               dwCompletionMode,
    unsigned long               dwMessageID
    );

LONG
TSPIAPI
TSPI_lineCompleteTransfer(
    DRV_REQUESTID       dwRequestID,
    HDRVCALL            hdCall,
    HDRVCALL            hdConsultCall,
    HTAPICALL           htConfCall,
    LPHDRVCALL          lphdConfCall,
    unsigned long               dwTransferMode
    );

LONG
TSPIAPI
TSPI_lineConditionalMediaDetection(
    HDRVLINE            hdLine,
    unsigned long               dwMediaModes,
    LPLINECALLPARAMS    const lpCallParams
    );

LONG
TSPIAPI
TSPI_lineDevSpecific(
    DRV_REQUESTID       dwRequestID,
    HDRVLINE            hdLine,
    unsigned long               dwAddressID,
    HDRVCALL            hdCall,
    void*              lpParams,
    unsigned long               dwSize
    );

LONG
TSPIAPI
TSPI_lineDevSpecificFeature(
    DRV_REQUESTID       dwRequestID,
    HDRVLINE            hdLine,
    unsigned long               dwFeature,
    void*              lpParams,
    unsigned long               dwSize
    );

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
TSPIAPI
TSPI_lineDial(
    DRV_REQUESTID       dwRequestID,
    HDRVCALL            hdCall,
    const wchar_t*             lpszDestAddress,
    unsigned long               dwCountryCode
    );
#else
LONG
TSPIAPI
TSPI_lineDial(
    DRV_REQUESTID       dwRequestID,
    HDRVCALL            hdCall,
    const char*              lpszDestAddress,
    unsigned long               dwCountryCode
    );
#endif

LONG
TSPIAPI
TSPI_lineDrop(
    DRV_REQUESTID       dwRequestID,
    HDRVCALL            hdCall,
    const char*              lpsUserUserInfo,
    unsigned long               dwSize
    );

LONG
TSPIAPI
TSPI_lineDropOnClose(                                           // TSPI v1.4
    HDRVCALL            hdCall
    );

LONG
TSPIAPI
TSPI_lineDropNoOwner(                                           // TSPI v1.4
    HDRVCALL            hdCall
    );

LONG
TSPIAPI
TSPI_lineForward(
    DRV_REQUESTID       dwRequestID,
    HDRVLINE            hdLine,
    unsigned long               bAllAddresses,
    unsigned long               dwAddressID,
    LPLINEFORWARDLIST   const lpForwardList,
    unsigned long               dwNumRingsNoAnswer,
    HTAPICALL           htConsultCall,
    LPHDRVCALL          lphdConsultCall,
    LPLINECALLPARAMS    const lpCallParams
    );

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
TSPIAPI
TSPI_lineGatherDigits(
    HDRVCALL            hdCall,
    unsigned long               dwEndToEndID,
    unsigned long               dwDigitModes,
    LPWSTR              lpsDigits,
    unsigned long               dwNumDigits,
    const wchar_t*             lpszTerminationDigits,
    unsigned long               dwFirstDigitTimeout,
    unsigned long               dwInterDigitTimeout
    );
#else
LONG
TSPIAPI
TSPI_lineGatherDigits(
    HDRVCALL            hdCall,
    unsigned long               dwEndToEndID,
    unsigned long               dwDigitModes,
    LPSTR               lpsDigits,
    unsigned long               dwNumDigits,
    const char*              lpszTerminationDigits,
    unsigned long               dwFirstDigitTimeout,
    unsigned long               dwInterDigitTimeout
    );
#endif

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
TSPIAPI
TSPI_lineGenerateDigits(
    HDRVCALL            hdCall,
    unsigned long               dwEndToEndID,
    unsigned long               dwDigitMode,
    const wchar_t*             lpszDigits,
    unsigned long               dwDuration
    );
#else
LONG
TSPIAPI
TSPI_lineGenerateDigits(
    HDRVCALL            hdCall,
    unsigned long               dwEndToEndID,
    unsigned long               dwDigitMode,
    const char*              lpszDigits,
    unsigned long               dwDuration
    );
#endif

LONG
TSPIAPI
TSPI_lineGenerateTone(
    HDRVCALL            hdCall,
    unsigned long               dwEndToEndID,
    unsigned long               dwToneMode,
    unsigned long               dwDuration,
    unsigned long               dwNumTones,
    LPLINEGENERATETONE  const lpTones
    );

LONG
TSPIAPI
TSPI_lineGetAddressCaps(
    unsigned long               dwDeviceID,
    unsigned long               dwAddressID,
    unsigned long               dwTSPIVersion,
    unsigned long               dwExtVersion,
    LPLINEADDRESSCAPS   lpAddressCaps
    );

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
TSPIAPI
TSPI_lineGetAddressID(
    HDRVLINE            hdLine,
    LPDWORD             lpdwAddressID,
    unsigned long               dwAddressMode,
    const wchar_t*             lpsAddress,
    unsigned long               dwSize
    );
#else
LONG
TSPIAPI
TSPI_lineGetAddressID(
    HDRVLINE            hdLine,
    LPDWORD             lpdwAddressID,
    unsigned long               dwAddressMode,
    const char*              lpsAddress,
    unsigned long               dwSize
    );
#endif

LONG
TSPIAPI
TSPI_lineGetAddressStatus(
    HDRVLINE            hdLine,
    unsigned long               dwAddressID,
    LPLINEADDRESSSTATUS lpAddressStatus
    );

LONG
TSPIAPI
TSPI_lineGetCallAddressID(
    HDRVCALL            hdCall,
    LPDWORD             lpdwAddressID
    );

LONG
TSPIAPI
TSPI_lineGetCallInfo(
    HDRVCALL            hdCall,
    LPLINECALLINFO      lpCallInfo
    );

LONG
TSPIAPI
TSPI_lineGetCallStatus(
    HDRVCALL            hdCall,
    LPLINECALLSTATUS    lpCallStatus
    );

LONG
TSPIAPI
TSPI_lineGetDevCaps(
    unsigned long               dwDeviceID,
    unsigned long               dwTSPIVersion,
    unsigned long               dwExtVersion,
    LPLINEDEVCAPS       lpLineDevCaps
    );

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
TSPIAPI
TSPI_lineGetDevConfig(
    unsigned long               dwDeviceID,
    LPVARSTRING         lpDeviceConfig,
    const wchar_t*             lpszDeviceClass
    );
#else
LONG
TSPIAPI
TSPI_lineGetDevConfig(
    unsigned long               dwDeviceID,
    LPVARSTRING         lpDeviceConfig,
    const char*              lpszDeviceClass
    );
#endif

LONG
TSPIAPI
TSPI_lineGetExtensionID(
    unsigned long               dwDeviceID,
    unsigned long               dwTSPIVersion,
    LPLINEEXTENSIONID   lpExtensionID
    );

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
TSPIAPI
TSPI_lineGetIcon(
    unsigned long               dwDeviceID,
    const wchar_t*             lpszDeviceClass,
    LPHICON             lphIcon
    );
#else
LONG
TSPIAPI
TSPI_lineGetIcon(
    unsigned long               dwDeviceID,
    const char*              lpszDeviceClass,
    LPHICON             lphIcon
    );
#endif

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
TSPIAPI
TSPI_lineGetID(
    HDRVLINE            hdLine,
    unsigned long               dwAddressID,
    HDRVCALL            hdCall,
    unsigned long               dwSelect,
    LPVARSTRING         lpDeviceID,
    const wchar_t*             lpszDeviceClass,
    HANDLE              hTargetProcess                          // TSPI v2.0
    );
#else
LONG
TSPIAPI
TSPI_lineGetID(
    HDRVLINE            hdLine,
    unsigned long               dwAddressID,
    HDRVCALL            hdCall,
    unsigned long               dwSelect,
    LPVARSTRING         lpDeviceID,
    const char*              lpszDeviceClass
    );
#endif


LONG
TSPIAPI
TSPI_lineGetLineDevStatus(
    HDRVLINE            hdLine,
    LPLINEDEVSTATUS     lpLineDevStatus
    );

LONG
TSPIAPI
TSPI_lineGetNumAddressIDs(
    HDRVLINE            hdLine,
    LPDWORD             lpdwNumAddressIDs
    );

LONG
TSPIAPI
TSPI_lineHold(
    DRV_REQUESTID       dwRequestID,
    HDRVCALL            hdCall
    );

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
TSPIAPI
TSPI_lineMakeCall(
    DRV_REQUESTID       dwRequestID,
    HDRVLINE            hdLine,
    HTAPICALL           htCall,
    LPHDRVCALL          lphdCall,
    const wchar_t*             lpszDestAddress,
    unsigned long               dwCountryCode,
    LPLINECALLPARAMS    const lpCallParams
    );
#else
LONG
TSPIAPI
TSPI_lineMakeCall(
    DRV_REQUESTID       dwRequestID,
    HDRVLINE            hdLine,
    HTAPICALL           htCall,
    LPHDRVCALL          lphdCall,
    const char*              lpszDestAddress,
    unsigned long               dwCountryCode,
    LPLINECALLPARAMS    const lpCallParams
    );
#endif

LONG
TSPIAPI
TSPI_lineMonitorDigits(
    HDRVCALL            hdCall,
    unsigned long               dwDigitModes
    );

LONG
TSPIAPI
TSPI_lineMonitorMedia(
    HDRVCALL            hdCall,
    unsigned long               dwMediaModes
    );

LONG
TSPIAPI
TSPI_lineMonitorTones(
    HDRVCALL            hdCall,
    unsigned long               dwToneListID,
    LPLINEMONITORTONE   const lpToneList,
    unsigned long               dwNumEntries
    );

LONG
TSPIAPI
TSPI_lineNegotiateExtVersion(
    unsigned long               dwDeviceID,
    unsigned long               dwTSPIVersion,
    unsigned long               dwLowVersion,
    unsigned long               dwHighVersion,
    LPDWORD             lpdwExtVersion
    );

LONG
TSPIAPI
TSPI_lineNegotiateTSPIVersion(
    unsigned long               dwDeviceID,
    unsigned long               dwLowVersion,
    unsigned long               dwHighVersion,
    LPDWORD             lpdwTSPIVersion
    );

LONG
TSPIAPI
TSPI_lineOpen(
    unsigned long               dwDeviceID,
    HTAPILINE           htLine,
    LPHDRVLINE          lphdLine,
    unsigned long               dwTSPIVersion,
    LINEEVENT           lpfnEventProc
    );

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
TSPIAPI
TSPI_linePark(
    DRV_REQUESTID       dwRequestID,
    HDRVCALL            hdCall,
    unsigned long               dwParkMode,
    const wchar_t*             lpszDirAddress,
    LPVARSTRING         lpNonDirAddress
    );
#else
LONG
TSPIAPI
TSPI_linePark(
    DRV_REQUESTID       dwRequestID,
    HDRVCALL            hdCall,
    unsigned long               dwParkMode,
    const char*              lpszDirAddress,
    LPVARSTRING         lpNonDirAddress
    );
#endif

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
TSPIAPI
TSPI_linePickup(
    DRV_REQUESTID       dwRequestID,
    HDRVLINE            hdLine,
    unsigned long               dwAddressID,
    HTAPICALL           htCall,
    LPHDRVCALL          lphdCall,
    const wchar_t*             lpszDestAddress,
    const wchar_t*             lpszGroupID
    );
#else
LONG
TSPIAPI
TSPI_linePickup(
    DRV_REQUESTID       dwRequestID,
    HDRVLINE            hdLine,
    unsigned long               dwAddressID,
    HTAPICALL           htCall,
    LPHDRVCALL          lphdCall,
    const char*              lpszDestAddress,
    const char*              lpszGroupID
    );
#endif

LONG
TSPIAPI
TSPI_linePrepareAddToConference(
    DRV_REQUESTID       dwRequestID,
    HDRVCALL            hdConfCall,
    HTAPICALL           htConsultCall,
    LPHDRVCALL          lphdConsultCall,
    LPLINECALLPARAMS    const lpCallParams
    );

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
TSPIAPI
TSPI_lineRedirect(
    DRV_REQUESTID       dwRequestID,
    HDRVCALL            hdCall,
    const wchar_t*             lpszDestAddress,
    unsigned long               dwCountryCode
    );
#else
LONG
TSPIAPI
TSPI_lineRedirect(
    DRV_REQUESTID       dwRequestID,
    HDRVCALL            hdCall,
    const char*              lpszDestAddress,
    unsigned long               dwCountryCode
    );
#endif

LONG
TSPIAPI
TSPI_lineReleaseUserUserInfo(                                   // TSPI v1.4
    DRV_REQUESTID       dwRequestID,
    HDRVCALL            hdCall
    );

LONG
TSPIAPI
TSPI_lineRemoveFromConference(
    DRV_REQUESTID       dwRequestID,
    HDRVCALL            hdCall
    );

LONG
TSPIAPI
TSPI_lineSecureCall(
    DRV_REQUESTID       dwRequestID,
    HDRVCALL            hdCall
    );

LONG
TSPIAPI
TSPI_lineSelectExtVersion(
    HDRVLINE            hdLine,
    unsigned long               dwExtVersion
    );

LONG
TSPIAPI
TSPI_lineSendUserUserInfo(
    DRV_REQUESTID       dwRequestID,
    HDRVCALL            hdCall,
    const char*              lpsUserUserInfo,
    unsigned long               dwSize
    );

LONG
TSPIAPI
TSPI_lineSetAppSpecific(
    HDRVCALL            hdCall,
    unsigned long               dwAppSpecific
    );

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
TSPIAPI
TSPI_lineSetCallData(                                           // TSPI v2.0
    DRV_REQUESTID       dwRequestID,
    HDRVCALL            hdCall,
    void*              lpCallData,
    unsigned long               dwSize
    );
#endif

LONG
TSPIAPI
TSPI_lineSetCallParams(
    DRV_REQUESTID       dwRequestID,
    HDRVCALL            hdCall,
    unsigned long               dwBearerMode,
    unsigned long               dwMinRate,
    unsigned long               dwMaxRate,
    LPLINEDIALPARAMS    const lpDialParams
    );

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
TSPIAPI
TSPI_lineSetCallQualityOfService(                               // TSPI v2.0
    DRV_REQUESTID       dwRequestID,
    HDRVCALL            hdCall,
    void*              lpSendingFlowspec,
    unsigned long               dwSendingFlowspecSize,
    void*              lpReceivingFlowspec,
    unsigned long               dwReceivingFlowspecSize
    );

LONG
TSPIAPI
TSPI_lineSetCallTreatment(                                      // TSPI v2.0
    DRV_REQUESTID       dwRequestID,
    HDRVCALL            hdCall,
    unsigned long               dwTreatment
    );
#endif

LONG
TSPIAPI
TSPI_lineSetCurrentLocation(                                    // TSPI v1.4
    unsigned long               dwLocation
    );

LONG
TSPIAPI
TSPI_lineSetDefaultMediaDetection(
    HDRVLINE            hdLine,
    unsigned long               dwMediaModes
    );

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
TSPIAPI
TSPI_lineSetDevConfig(
    unsigned long               dwDeviceID,
    void*              const lpDeviceConfig,
    unsigned long               dwSize,
    const wchar_t*             lpszDeviceClass
    );
#else
LONG
TSPIAPI
TSPI_lineSetDevConfig(
    unsigned long               dwDeviceID,
    void*              const lpDeviceConfig,
    unsigned long               dwSize,
    const char*              lpszDeviceClass
    );
#endif

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
TSPIAPI
TSPI_lineSetLineDevStatus(                                      // TSPI v2.0
    DRV_REQUESTID       dwRequestID,
    HDRVLINE            hdLine,
    unsigned long               dwStatusToChange,
    unsigned long               fStatus
    );
#endif

LONG
TSPIAPI
TSPI_lineSetMediaControl(
    HDRVLINE                    hdLine,
    unsigned long                       dwAddressID,
    HDRVCALL                    hdCall,
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
TSPIAPI
TSPI_lineSetMediaMode(
    HDRVCALL            hdCall,
    unsigned long               dwMediaMode
    );

LONG
TSPIAPI
TSPI_lineSetStatusMessages(
    HDRVLINE            hdLine,
    unsigned long               dwLineStates,
    unsigned long               dwAddressStates
    );

LONG
TSPIAPI
TSPI_lineSetTerminal(
    DRV_REQUESTID       dwRequestID,
    HDRVLINE            hdLine,
    unsigned long               dwAddressID,
    HDRVCALL            hdCall,
    unsigned long               dwSelect,
    unsigned long               dwTerminalModes,
    unsigned long               dwTerminalID,
    unsigned long               bEnable
    );

LONG
TSPIAPI
TSPI_lineSetupConference(
    DRV_REQUESTID       dwRequestID,
    HDRVCALL            hdCall,
    HDRVLINE            hdLine,
    HTAPICALL           htConfCall,
    LPHDRVCALL          lphdConfCall,
    HTAPICALL           htConsultCall,
    LPHDRVCALL          lphdConsultCall,
    unsigned long               dwNumParties,
    LPLINECALLPARAMS    const lpCallParams
    );

LONG
TSPIAPI
TSPI_lineSetupTransfer(
    DRV_REQUESTID       dwRequestID,
    HDRVCALL            hdCall,
    HTAPICALL           htConsultCall,
    LPHDRVCALL          lphdConsultCall,
    LPLINECALLPARAMS    const lpCallParams
    );

LONG
TSPIAPI
TSPI_lineSwapHold(
    DRV_REQUESTID       dwRequestID,
    HDRVCALL            hdActiveCall,
    HDRVCALL            hdHeldCall
    );

LONG
TSPIAPI
TSPI_lineUncompleteCall(
    DRV_REQUESTID       dwRequestID,
    HDRVLINE            hdLine,
    unsigned long               dwCompletionID
    );

LONG
TSPIAPI
TSPI_lineUnhold(
    DRV_REQUESTID       dwRequestID,
    HDRVCALL            hdCall
    );

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
TSPIAPI
TSPI_lineUnpark(
    DRV_REQUESTID       dwRequestID,
    HDRVLINE            hdLine,
    unsigned long               dwAddressID,
    HTAPICALL           htCall,
    LPHDRVCALL          lphdCall,
    const wchar_t*             lpszDestAddress
    );
#else
LONG
TSPIAPI
TSPI_lineUnpark(
    DRV_REQUESTID       dwRequestID,
    HDRVLINE            hdLine,
    unsigned long               dwAddressID,
    HTAPICALL           htCall,
    LPHDRVCALL          lphdCall,
    const char*              lpszDestAddress
    );
#endif



LONG
TSPIAPI
TSPI_phoneClose(
    HDRVPHONE           hdPhone
    );

LONG
TSPIAPI
TSPI_phoneDevSpecific(
    DRV_REQUESTID       dwRequestID,
    HDRVPHONE           hdPhone,
    void*              lpParams,
    unsigned long               dwSize
    );

LONG
TSPIAPI
TSPI_phoneGetButtonInfo(
    HDRVPHONE           hdPhone,
    unsigned long               dwButtonLampID,
    LPPHONEBUTTONINFO   lpButtonInfo
    );

LONG
TSPIAPI
TSPI_phoneGetData(
    HDRVPHONE           hdPhone,
    unsigned long               dwDataID,
    void*              lpData,
    unsigned long               dwSize
    );

LONG
TSPIAPI
TSPI_phoneGetDevCaps(
    unsigned long               dwDeviceID,
    unsigned long               dwTSPIVersion,
    unsigned long               dwExtVersion,
    LPPHONECAPS         lpPhoneCaps
    );

LONG
TSPIAPI
TSPI_phoneGetDisplay(
    HDRVPHONE           hdPhone,
    LPVARSTRING         lpDisplay
    );

LONG
TSPIAPI
TSPI_phoneGetExtensionID(
    unsigned long               dwDeviceID,
    unsigned long               dwTSPIVersion,
    LPPHONEEXTENSIONID  lpExtensionID
    );

LONG
TSPIAPI
TSPI_phoneGetGain(
    HDRVPHONE           hdPhone,
    unsigned long               dwHookSwitchDev,
    LPDWORD             lpdwGain
    );

LONG
TSPIAPI
TSPI_phoneGetHookSwitch(
    HDRVPHONE           hdPhone,
    LPDWORD             lpdwHookSwitchDevs
    );

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
TSPIAPI
TSPI_phoneGetIcon(
    unsigned long               dwDeviceID,
    const wchar_t*             lpszDeviceClass,
    LPHICON             lphIcon
    );
#else
LONG
TSPIAPI
TSPI_phoneGetIcon(
    unsigned long               dwDeviceID,
    const char*              lpszDeviceClass,
    LPHICON             lphIcon
    );
#endif

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
TSPIAPI
TSPI_phoneGetID(
    HDRVPHONE           hdPhone,
    LPVARSTRING         lpDeviceID,
    const wchar_t*             lpszDeviceClass,
    HANDLE              hTargetProcess                          // TSPI v2.0
    );
#else
LONG
TSPIAPI
TSPI_phoneGetID(
    HDRVPHONE           hdPhone,
    LPVARSTRING         lpDeviceID,
    const char*              lpszDeviceClass
    );
#endif

LONG
TSPIAPI
TSPI_phoneGetLamp(
    HDRVPHONE           hdPhone,
    unsigned long               dwButtonLampID,
    LPDWORD             lpdwLampMode
    );

LONG
TSPIAPI
TSPI_phoneGetRing(
    HDRVPHONE           hdPhone,
    LPDWORD             lpdwRingMode,
    LPDWORD             lpdwVolume
    );

LONG
TSPIAPI
TSPI_phoneGetStatus(
    HDRVPHONE           hdPhone,
    LPPHONESTATUS       lpPhoneStatus
    );

LONG
TSPIAPI
TSPI_phoneGetVolume(
    HDRVPHONE           hdPhone,
    unsigned long               dwHookSwitchDev,
    LPDWORD             lpdwVolume
    );

LONG
TSPIAPI
TSPI_phoneNegotiateExtVersion(
    unsigned long               dwDeviceID,
    unsigned long               dwTSPIVersion,
    unsigned long               dwLowVersion,
    unsigned long               dwHighVersion,
    LPDWORD             lpdwExtVersion
    );

LONG
TSPIAPI
TSPI_phoneNegotiateTSPIVersion(
    unsigned long               dwDeviceID,
    unsigned long               dwLowVersion,
    unsigned long               dwHighVersion,
    LPDWORD             lpdwTSPIVersion
    );

LONG
TSPIAPI
TSPI_phoneOpen(
    unsigned long               dwDeviceID,
    HTAPIPHONE          htPhone,
    LPHDRVPHONE         lphdPhone,
    unsigned long               dwTSPIVersion,
    PHONEEVENT          lpfnEventProc
    );

LONG
TSPIAPI
TSPI_phoneSelectExtVersion(
    HDRVPHONE           hdPhone,
    unsigned long               dwExtVersion
    );

LONG
TSPIAPI
TSPI_phoneSetButtonInfo(
    DRV_REQUESTID       dwRequestID,
    HDRVPHONE           hdPhone,
    unsigned long               dwButtonLampID,
    LPPHONEBUTTONINFO   const lpButtonInfo
    );

LONG
TSPIAPI
TSPI_phoneSetData(
    DRV_REQUESTID       dwRequestID,
    HDRVPHONE           hdPhone,
    unsigned long               dwDataID,
    void*              const lpData,
    unsigned long               dwSize
    );

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
TSPIAPI
TSPI_phoneSetDisplay(
    DRV_REQUESTID       dwRequestID,
    HDRVPHONE           hdPhone,
    unsigned long               dwRow,
    unsigned long               dwColumn,
    const wchar_t*             lpsDisplay,
    unsigned long               dwSize
    );
#else
LONG
TSPIAPI
TSPI_phoneSetDisplay(
    DRV_REQUESTID       dwRequestID,
    HDRVPHONE           hdPhone,
    unsigned long               dwRow,
    unsigned long               dwColumn,
    const char*              lpsDisplay,
    unsigned long               dwSize
    );
#endif

LONG
TSPIAPI
TSPI_phoneSetGain(
    DRV_REQUESTID       dwRequestID,
    HDRVPHONE           hdPhone,
    unsigned long               dwHookSwitchDev,
    unsigned long               dwGain
    );

LONG
TSPIAPI
TSPI_phoneSetHookSwitch(
    DRV_REQUESTID       dwRequestID,
    HDRVPHONE           hdPhone,
    unsigned long               dwHookSwitchDevs,
    unsigned long               dwHookSwitchMode
    );

LONG
TSPIAPI
TSPI_phoneSetLamp(
    DRV_REQUESTID       dwRequestID,
    HDRVPHONE           hdPhone,
    unsigned long               dwButtonLampID,
    unsigned long               dwLampMode
    );

LONG
TSPIAPI
TSPI_phoneSetRing(
    DRV_REQUESTID       dwRequestID,
    HDRVPHONE           hdPhone,
    unsigned long               dwRingMode,
    unsigned long               dwVolume
    );

LONG
TSPIAPI
TSPI_phoneSetStatusMessages(
    HDRVPHONE           hdPhone,
    unsigned long               dwPhoneStates,
    unsigned long               dwButtonModes,
    unsigned long               dwButtonStates
    );

LONG
TSPIAPI
TSPI_phoneSetVolume(
    DRV_REQUESTID       dwRequestID,
    HDRVPHONE           hdPhone,
    unsigned long               dwHookSwitchDev,
    unsigned long               dwVolume
    );



LONG
TSPIAPI
TSPI_providerCreateLineDevice(                                  // TSPI v1.4
    unsigned long               dwTempID,
    unsigned long               dwDeviceID
    );

LONG
TSPIAPI
TSPI_providerCreatePhoneDevice(                                 // TSPI v1.4
    unsigned long               dwTempID,
    unsigned long               dwDeviceID
    );

LONG
TSPIAPI
TSPI_providerEnumDevices(                                       // TSPI v1.4
    unsigned long               dwPermanentProviderID,
    LPDWORD             lpdwNumLines,
    LPDWORD             lpdwNumPhones,
    HPROVIDER           hProvider,
    LINEEVENT           lpfnLineCreateProc,
    PHONEEVENT          lpfnPhoneCreateProc
    );

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
TSPIAPI
TSPI_providerFreeDialogInstance(                                // TSPI v2.0
    HDRVDIALOGINSTANCE  hdDlgInst
    );

LONG
TSPIAPI
TSPI_providerGenericDialogData(                                 // TSPI v2.0
    unsigned long               dwObjectID,
    unsigned long               dwObjectType,
    void*              lpParams,
    unsigned long               dwSize
    );
#endif

LONG
TSPIAPI
TSPI_providerInit(
    unsigned long               dwTSPIVersion,
    unsigned long               dwPermanentProviderID,
    unsigned long               dwLineDeviceIDBase,
    unsigned long               dwPhoneDeviceIDBase,
    unsigned long               dwNumLines,
    unsigned long               dwNumPhones,
    ASYNC_COMPLETION    lpfnCompletionProc
#if (TAPI_CURRENT_VERSION >= 0x00020000)
    ,
    LPDWORD             lpdwTSPIOptions                         // TSPI v2.0
#endif
    );

LONG
TSPIAPI
TSPI_providerInstall(
    HWND                hwndOwner,
    unsigned long               dwPermanentProviderID
    );

LONG
TSPIAPI
TSPI_providerRemove(
    HWND                hwndOwner,
    unsigned long               dwPermanentProviderID
    );

LONG
TSPIAPI
TSPI_providerShutdown(
    unsigned long               dwTSPIVersion
#if (TAPI_CURRENT_VERSION >= 0x00020000)
    ,
    unsigned long               dwPermanentProviderID                   // TSPI v2.0
#endif
    );

#if (TAPI_CURRENT_VERSION >= 0x00020000)
LONG
TSPIAPI
TSPI_providerUIIdentify(                                        // TSPI v2.0
    LPWSTR              lpszUIDLLName
    );
#endif



#if (TAPI_CURRENT_VERSION >= 0x00020000)
//
// The following function prototypes pertain
// to a service provider's UI module
//

LONG
TSPIAPI
TUISPI_lineConfigDialog(                                        // TSPI v2.0
    TUISPIDLLCALLBACK   lpfnUIDLLCallback,
    unsigned long               dwDeviceID,
    HWND                hwndOwner,
    const wchar_t*             lpszDeviceClass
    );

LONG
TSPIAPI
TUISPI_lineConfigDialogEdit(                                    // TSPI v2.0
    TUISPIDLLCALLBACK   lpfnUIDLLCallback,
    unsigned long               dwDeviceID,
    HWND                hwndOwner,
    const wchar_t*             lpszDeviceClass,
    void*              const lpDeviceConfigIn,
    unsigned long               dwSize,
    LPVARSTRING         lpDeviceConfigOut
    );

LONG
TSPIAPI
TUISPI_phoneConfigDialog(                                       // TSPI v2.0
    TUISPIDLLCALLBACK   lpfnUIDLLCallback,
    unsigned long               dwDeviceID,
    HWND                hwndOwner,
    const wchar_t*             lpszDeviceClass
    );

LONG
TSPIAPI
TUISPI_providerConfig(                                          // TSPI v2.0
    TUISPIDLLCALLBACK   lpfnUIDLLCallback,
    HWND                hwndOwner,
    unsigned long               dwPermanentProviderID
    );

LONG
TSPIAPI
TUISPI_providerGenericDialog(                                   // TSPI v2.0
    TUISPIDLLCALLBACK   lpfnUIDLLCallback,
    HTAPIDIALOGINSTANCE htDlgInst,
    void*              lpParams,
    unsigned long               dwSize,
    HANDLE              hEvent
    );

LONG
TSPIAPI
TUISPI_providerGenericDialogData(                               // TSPI v2.0
    HTAPIDIALOGINSTANCE htDlgInst,
    void*              lpParams,
    unsigned long               dwSize
    );

LONG
TSPIAPI
TUISPI_providerInstall(                                         // TSPI v2.0
    TUISPIDLLCALLBACK   lpfnUIDLLCallback,
    HWND                hwndOwner,
    unsigned long               dwPermanentProviderID
    );

LONG
TSPIAPI
TUISPI_providerRemove(                                          // TSPI v2.0
    TUISPIDLLCALLBACK   lpfnUIDLLCallback,
    HWND                hwndOwner,
    unsigned long               dwPermanentProviderID
    );

#else

//
// The following were obsoleted by the above (but are needed to build 1.4 SPs)
//
LONG TSPIAPI TSPI_lineConfigDialog(
    unsigned long   dwDeviceID,
    HWND    hwndOwner,
    const char*  lpszDeviceClass);

LONG TSPIAPI TSPI_lineConfigDialogEdit(
    unsigned long   dwDeviceID,
    HWND    hwndOwner,
    const char*  lpszDeviceClass,
    void*  const lpDeviceConfigIn,
    unsigned long   dwSize,
    LPVARSTRING lpDeviceConfigOut);

LONG TSPIAPI TSPI_phoneConfigDialog(
    unsigned long   dwDeviceID,
    HWND    hwndOwner,
    const char*  lpszDeviceClass);

LONG TSPIAPI TSPI_providerConfig(
    HWND   hwndOwner,
    unsigned long  dwPermanentProviderID);


#endif




#if (TAPI_CURRENT_VERSION < 0x00020000)

//
// The following macros are the ordinal numbers of the exported tspi functions
//

#define TSPI_PROC_BASE                      500

#define TSPI_LINEACCEPT                     (TSPI_PROC_BASE + 0)
#define TSPI_LINEADDTOCONFERENCE            (TSPI_PROC_BASE + 1)
#define TSPI_LINEANSWER                     (TSPI_PROC_BASE + 2)
#define TSPI_LINEBLINDTRANSFER              (TSPI_PROC_BASE + 3)
#define TSPI_LINECLOSE                      (TSPI_PROC_BASE + 4)
#define TSPI_LINECLOSECALL                  (TSPI_PROC_BASE + 5)
#define TSPI_LINECOMPLETECALL               (TSPI_PROC_BASE + 6)
#define TSPI_LINECOMPLETETRANSFER           (TSPI_PROC_BASE + 7)
#define TSPI_LINECONDITIONALMEDIADETECTION  (TSPI_PROC_BASE + 8)
#define TSPI_LINECONFIGDIALOG               (TSPI_PROC_BASE + 9)
#define TSPI_LINEDEVSPECIFIC                (TSPI_PROC_BASE + 10)
#define TSPI_LINEDEVSPECIFICFEATURE         (TSPI_PROC_BASE + 11)
#define TSPI_LINEDIAL                       (TSPI_PROC_BASE + 12)
#define TSPI_LINEDROP                       (TSPI_PROC_BASE + 13)
#define TSPI_LINEFORWARD                    (TSPI_PROC_BASE + 14)
#define TSPI_LINEGATHERDIGITS               (TSPI_PROC_BASE + 15)
#define TSPI_LINEGENERATEDIGITS             (TSPI_PROC_BASE + 16)
#define TSPI_LINEGENERATETONE               (TSPI_PROC_BASE + 17)
#define TSPI_LINEGETADDRESSCAPS             (TSPI_PROC_BASE + 18)
#define TSPI_LINEGETADDRESSID               (TSPI_PROC_BASE + 19)
#define TSPI_LINEGETADDRESSSTATUS           (TSPI_PROC_BASE + 20)
#define TSPI_LINEGETCALLADDRESSID           (TSPI_PROC_BASE + 21)
#define TSPI_LINEGETCALLINFO                (TSPI_PROC_BASE + 22)
#define TSPI_LINEGETCALLSTATUS              (TSPI_PROC_BASE + 23)
#define TSPI_LINEGETDEVCAPS                 (TSPI_PROC_BASE + 24)
#define TSPI_LINEGETDEVCONFIG               (TSPI_PROC_BASE + 25)
#define TSPI_LINEGETEXTENSIONID             (TSPI_PROC_BASE + 26)
#define TSPI_LINEGETICON                    (TSPI_PROC_BASE + 27)
#define TSPI_LINEGETID                      (TSPI_PROC_BASE + 28)
#define TSPI_LINEGETLINEDEVSTATUS           (TSPI_PROC_BASE + 29)
#define TSPI_LINEGETNUMADDRESSIDS           (TSPI_PROC_BASE + 30)
#define TSPI_LINEHOLD                       (TSPI_PROC_BASE + 31)
#define TSPI_LINEMAKECALL                   (TSPI_PROC_BASE + 32)
#define TSPI_LINEMONITORDIGITS              (TSPI_PROC_BASE + 33)
#define TSPI_LINEMONITORMEDIA               (TSPI_PROC_BASE + 34)
#define TSPI_LINEMONITORTONES               (TSPI_PROC_BASE + 35)
#define TSPI_LINENEGOTIATEEXTVERSION        (TSPI_PROC_BASE + 36)
#define TSPI_LINENEGOTIATETSPIVERSION       (TSPI_PROC_BASE + 37)
#define TSPI_LINEOPEN                       (TSPI_PROC_BASE + 38)
#define TSPI_LINEPARK                       (TSPI_PROC_BASE + 39)
#define TSPI_LINEPICKUP                     (TSPI_PROC_BASE + 40)
#define TSPI_LINEPREPAREADDTOCONFERENCE     (TSPI_PROC_BASE + 41)
#define TSPI_LINEREDIRECT                   (TSPI_PROC_BASE + 42)
#define TSPI_LINEREMOVEFROMCONFERENCE       (TSPI_PROC_BASE + 43)
#define TSPI_LINESECURECALL                 (TSPI_PROC_BASE + 44)
#define TSPI_LINESELECTEXTVERSION           (TSPI_PROC_BASE + 45)
#define TSPI_LINESENDUSERUSERINFO           (TSPI_PROC_BASE + 46)
#define TSPI_LINESETAPPSPECIFIC             (TSPI_PROC_BASE + 47)
#define TSPI_LINESETCALLPARAMS              (TSPI_PROC_BASE + 48)
#define TSPI_LINESETDEFAULTMEDIADETECTION   (TSPI_PROC_BASE + 49)
#define TSPI_LINESETDEVCONFIG               (TSPI_PROC_BASE + 50)
#define TSPI_LINESETMEDIACONTROL            (TSPI_PROC_BASE + 51)
#define TSPI_LINESETMEDIAMODE               (TSPI_PROC_BASE + 52)
#define TSPI_LINESETSTATUSMESSAGES          (TSPI_PROC_BASE + 53)
#define TSPI_LINESETTERMINAL                (TSPI_PROC_BASE + 54)
#define TSPI_LINESETUPCONFERENCE            (TSPI_PROC_BASE + 55)
#define TSPI_LINESETUPTRANSFER              (TSPI_PROC_BASE + 56)
#define TSPI_LINESWAPHOLD                   (TSPI_PROC_BASE + 57)
#define TSPI_LINEUNCOMPLETECALL             (TSPI_PROC_BASE + 58)
#define TSPI_LINEUNHOLD                     (TSPI_PROC_BASE + 59)
#define TSPI_LINEUNPARK                     (TSPI_PROC_BASE + 60)
#define TSPI_PHONECLOSE                     (TSPI_PROC_BASE + 61)
#define TSPI_PHONECONFIGDIALOG              (TSPI_PROC_BASE + 62)
#define TSPI_PHONEDEVSPECIFIC               (TSPI_PROC_BASE + 63)
#define TSPI_PHONEGETBUTTONINFO             (TSPI_PROC_BASE + 64)
#define TSPI_PHONEGETDATA                   (TSPI_PROC_BASE + 65)
#define TSPI_PHONEGETDEVCAPS                (TSPI_PROC_BASE + 66)
#define TSPI_PHONEGETDISPLAY                (TSPI_PROC_BASE + 67)
#define TSPI_PHONEGETEXTENSIONID            (TSPI_PROC_BASE + 68)
#define TSPI_PHONEGETGAIN                   (TSPI_PROC_BASE + 69)
#define TSPI_PHONEGETHOOKSWITCH             (TSPI_PROC_BASE + 70)
#define TSPI_PHONEGETICON                   (TSPI_PROC_BASE + 71)
#define TSPI_PHONEGETID                     (TSPI_PROC_BASE + 72)
#define TSPI_PHONEGETLAMP                   (TSPI_PROC_BASE + 73)
#define TSPI_PHONEGETRING                   (TSPI_PROC_BASE + 74)
#define TSPI_PHONEGETSTATUS                 (TSPI_PROC_BASE + 75)
#define TSPI_PHONEGETVOLUME                 (TSPI_PROC_BASE + 76)
#define TSPI_PHONENEGOTIATEEXTVERSION       (TSPI_PROC_BASE + 77)
#define TSPI_PHONENEGOTIATETSPIVERSION      (TSPI_PROC_BASE + 78)
#define TSPI_PHONEOPEN                      (TSPI_PROC_BASE + 79)
#define TSPI_PHONESELECTEXTVERSION          (TSPI_PROC_BASE + 80)
#define TSPI_PHONESETBUTTONINFO             (TSPI_PROC_BASE + 81)
#define TSPI_PHONESETDATA                   (TSPI_PROC_BASE + 82)
#define TSPI_PHONESETDISPLAY                (TSPI_PROC_BASE + 83)
#define TSPI_PHONESETGAIN                   (TSPI_PROC_BASE + 84)
#define TSPI_PHONESETHOOKSWITCH             (TSPI_PROC_BASE + 85)
#define TSPI_PHONESETLAMP                   (TSPI_PROC_BASE + 86)
#define TSPI_PHONESETRING                   (TSPI_PROC_BASE + 87)
#define TSPI_PHONESETSTATUSMESSAGES         (TSPI_PROC_BASE + 88)
#define TSPI_PHONESETVOLUME                 (TSPI_PROC_BASE + 89)
#define TSPI_PROVIDERCONFIG                 (TSPI_PROC_BASE + 90)
#define TSPI_PROVIDERINIT                   (TSPI_PROC_BASE + 91)
#define TSPI_PROVIDERINSTALL                (TSPI_PROC_BASE + 92)
#define TSPI_PROVIDERREMOVE                 (TSPI_PROC_BASE + 93)
#define TSPI_PROVIDERSHUTDOWN               (TSPI_PROC_BASE + 94)

#define TSPI_PROVIDERENUMDEVICES            (TSPI_PROC_BASE + 95)  // TSPI v1.4
#define TSPI_LINEDROPONCLOSE                (TSPI_PROC_BASE + 96)  // TSPI v1.4
#define TSPI_LINEDROPNOOWNER                (TSPI_PROC_BASE + 97)  // TSPI v1.4
#define TSPI_PROVIDERCREATELINEDEVICE       (TSPI_PROC_BASE + 98)  // TSPI v1.4
#define TSPI_PROVIDERCREATEPHONEDEVICE      (TSPI_PROC_BASE + 99)  // TSPI v1.4
#define TSPI_LINESETCURRENTLOCATION         (TSPI_PROC_BASE + 100) // TSPI v1.4
#define TSPI_LINECONFIGDIALOGEDIT           (TSPI_PROC_BASE + 101) // TSPI v1.4
#define TSPI_LINERELEASEUSERUSERINFO        (TSPI_PROC_BASE + 102) // TSPI v1.4

#endif


#ifdef __cplusplus
}                       /* End of extern "C" { */
#endif  /* __cplusplus */

#endif  // TSPI_H
#pragma once 
