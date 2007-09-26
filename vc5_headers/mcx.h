/************************************************************************
*                                                                       *
*   mcx.h -- This module defines the 32-Bit Windows MCX APIs            *
*                                                                       *
*   Copyright (c) 1990-1996, Microsoft Corp. All rights reserved.       *
*                                                                       *
************************************************************************/

#ifndef _MCX_H_
#define _MCX_H_

typedef struct _MODEMDEVCAPS {
    unsigned long   dwActualSize;
    unsigned long   dwRequiredSize;
    unsigned long   dwDevSpecificOffset;
    unsigned long   dwDevSpecificSize;

    // product and version identification
    unsigned long   dwModemProviderVersion;
    unsigned long   dwModemManufacturerOffset;
    unsigned long   dwModemManufacturerSize;
    unsigned long   dwModemModelOffset;
    unsigned long   dwModemModelSize;
    unsigned long   dwModemVersionOffset;
    unsigned long   dwModemVersionSize;

    // local option capabilities
    unsigned long   dwDialOptions;          // bitmap of supported values
    unsigned long   dwCallSetupFailTimer;   // maximum in seconds
    unsigned long   dwInactivityTimeout;    // maximum in seconds
    unsigned long   dwSpeakerVolume;        // bitmap of supported values
    unsigned long   dwSpeakerMode;          // bitmap of supported values
    unsigned long   dwModemOptions;         // bitmap of supported values
    unsigned long   dwMaxDTERate;           // maximum value in bit/s
    unsigned long   dwMaxDCERate;           // maximum value in bit/s

    // Variable portion for proprietary expansion
    BYTE    abVariablePortion [1];
} MODEMDEVCAPS, *PMODEMDEVCAPS, *LPMODEMDEVCAPS;

typedef struct _MODEMSETTINGS {
    unsigned long   dwActualSize;
    unsigned long   dwRequiredSize;
    unsigned long   dwDevSpecificOffset;
    unsigned long   dwDevSpecificSize;

    // static local options (read/write)
    unsigned long   dwCallSetupFailTimer;       // seconds
    unsigned long   dwInactivityTimeout;        // seconds
    unsigned long   dwSpeakerVolume;            // level
    unsigned long   dwSpeakerMode;              // mode
    unsigned long   dwPreferredModemOptions;    // bitmap

    // negotiated options (read only) for current or last call
    unsigned long   dwNegotiatedModemOptions;   // bitmap
    unsigned long   dwNegotiatedDCERate;        // bit/s

    // Variable portion for proprietary expansion
    BYTE    abVariablePortion [1];
} MODEMSETTINGS, *PMODEMSETTINGS, *LPMODEMSETTINGS;

// Dial Options
#define DIALOPTION_BILLING  0x00000040  // Supports wait for bong "$"
#define DIALOPTION_QUIET    0x00000080  // Supports wait for quiet "@"
#define DIALOPTION_DIALTONE 0x00000100  // Supports wait for dial tone "W"

// SpeakerVolume for MODEMDEVCAPS
#define MDMVOLFLAG_LOW      0x00000001
#define MDMVOLFLAG_MEDIUM   0x00000002
#define MDMVOLFLAG_HIGH     0x00000004

// SpeakerVolume for MODEMSETTINGS
#define MDMVOL_LOW          0x00000000
#define MDMVOL_MEDIUM       0x00000001
#define MDMVOL_HIGH         0x00000002

// SpeakerMode for MODEMDEVCAPS
#define MDMSPKRFLAG_OFF         0x00000001
#define MDMSPKRFLAG_DIAL        0x00000002
#define MDMSPKRFLAG_ON          0x00000004
#define MDMSPKRFLAG_CALLSETUP   0x00000008

// SpeakerMode for MODEMSETTINGS
#define MDMSPKR_OFF         0x00000000
#define MDMSPKR_DIAL        0x00000001
#define MDMSPKR_ON          0x00000002
#define MDMSPKR_CALLSETUP   0x00000003

// Modem Options
#define MDM_COMPRESSION      0x00000001
#define MDM_ERROR_CONTROL    0x00000002
#define MDM_FORCED_EC        0x00000004
#define MDM_CELLULAR         0x00000008
#define MDM_FLOWCONTROL_HARD 0x00000010
#define MDM_FLOWCONTROL_SOFT 0x00000020
#define MDM_CCITT_OVERRIDE   0x00000040
#define MDM_SPEED_ADJUST     0x00000080
#define MDM_TONE_DIAL        0x00000100
#define MDM_BLIND_DIAL       0x00000200
#define MDM_V23_OVERRIDE     0x00000400

#endif /* _MCX_H_ */
#pragma once 
