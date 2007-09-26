//************************************************************************
//**
//**  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
//**  ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
//**  TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR
//**  A PARTICULAR PURPOSE.
//**
//**  Copyright (C) 1993 - 1995 Microsoft Corporation. All Rights Reserved.
//**
//**  IDF.h
//**
//**  DESCRIPTION:
//**     This file contains the format of the .IDF files.
//**
//**  HISTORY:
//**     04/29/93       created.
//**     07/04/93       added UNICODE for displayable strings.
//**     09/04/93       added keymaps.
//**     09/05/93       added ID's for channel types.
//**
//************************************************************************

/*
@doc  EXTERNAL SDK

@types   IDFHEADER |
   This is the format of the "hdr " chunk in a Microsoft IDF file.
   This will be the first subchunk of a "MMAP" list chunk.  This will 
   provide information on the IDF itself; what version, who created it,
   and a unique ASCII ID for the instrument.

@field   unsigned long | cbStruct |
   This is the inclusive size of the header structure.

@field   unsigned long | dwVersion |
   This is the version of the IDF file.
   under.

@field   unsigned long | dwCreator |
   This is the creator ID for the IDF.

@field   unsigned long | cbInstID |
   This is the size of the unique instrument identifier including the NULL.

@field   BYTE | abInstID[] |
   This is the actual ASCII bytes of the unique instrument id. This _IS_ 
   NULL terminated.  There is no UNICODE version of this since this will
   only be used internally and not displayed to the user.

@othertype  IDFHEADER * | PIDFHEADER |
   A memory model dependant pointer to the structure.

@othertype  IDFHEADER * | LPIDFHEADER |
   A  pointer to the structure.
*/

typedef struct tag_IDFHEADER
{
   unsigned long cbStruct;

   unsigned long dwVersion;
   unsigned long dwCreator;

   unsigned long cbInstID;
   BYTE  abInstID[1];
} IDFHEADER, *PIDFHEADER,  *LPIDFHEADER;

/*
@doc  EXTERNAL SDK

@types   IDFINSTINFO |
   This is the format of the "inst" chunk in a Microsoft IDF file.
   This chunk will contain information on the instrument, e.g. who
   manufactured it, the name of the instrument, it's manufacturer and
   product id's and a revision number.

@field   unsigned long | cbStruct |
   This is the inclusive size of the instrument information structure.

@field   unsigned long | dwManufactID |
   Manufacturer's ID.

@field   unsigned long | dwProductID |
   Product's ID.

@field   unsigned long | dwRevision |
   Revision of the product.

@field   unsigned long | cbManufactASCII |
   Length of the ASCII version of the manufacturuers name.

@field   unsigned long | cbManufactUNICODE |
   Length of the UNICODE version of the manufacturuers name.

@field   unsigned long | cbProductASCII |
   Length of the ASCII version of the product name.

@field   unsigned long | cbProductUNICODE |
   Length of the UNICODE version of the product name.

@field   BYTE | abData[] |
   Contains the ASCII and UNICODE strings for the manufacturer and product
   names.  NOTE that all strings are separated by a NULL and the NULL IS
   counted in the string lengths.

@othertype  IDFINSTINFO * | PIDFINSTINFO |
   A memory model dependant pointer to the structure.

@othertype  IDFINSTINFO  * | LPIDFINSTINFO |
   A  pointer to the structure.

@comm The idea is that the cbManufactXXXXX and cbProductXXXXX will be the
      offsets into the bData array of bytes and it will contain a complete
      string that you can strcpy out.  That is why the NULL is included in
      the byte count and in the actual data.
*/

typedef struct tag_IDFINSTINFO
{
   unsigned long cbStruct;

   unsigned long dwManufactID;
   unsigned long dwProductID;
   unsigned long dwRevision;

   unsigned long cbManufactASCII;
   unsigned long cbManufactUNICODE;
   unsigned long cbProductASCII;
   unsigned long cbProductUNICODE;

   BYTE  abData[1];
} IDFINSTINFO,  *LPIDFINSTINFO;

/*
@doc  EXTERNAL SDK

@types   IDFINSTCAPS |
   This is the format of the "caps" chunk in a Microsoft IDF file.
   This chunk will contain information on the MIDI capabilities of
   the device. e.g. basic channel of the instrument, number of channels
   that the instrument has available. the polyphony of the instrument, 
   whether or not it supports General MIDI, etc....

@field   unsigned long | cbStruct |
   This is the size of the capabilities structure.

@field   unsigned long | fdwFlags |
   Flags specifiying additional capabilities of an instrument.

@flag IDFINSTCAPS_F_GENERAL_MIDI |
   Instrument supports General MIDI.

@flag IDFINSTCAPS_F_SYSTEMEXCLUSIVE |
   Instrument supports system exclusive messages

@field   unsigned long | dwBasicChannel |
   The basic channel for the instrument.

@field   unsigned long | cNumChannels |
   Number of channels that the instrument supports to.

@field   unsigned long | cInstrumentPolyphony |
   The total polyphony for the instrument.

@field   unsigned long | cChannelPolyphony |
   The polyphony per channel.

@othertype  IDFINSTCAPS * | PIDFINSTCAPS |
   A memory model dependant pointer to the structure.

@othertype  IDFINSTCAPS  * | LPIDFINSTCAPS |
   A  pointer to the structure.
*/

typedef struct tag_IDFINSTCAPS
{
   unsigned long cbStruct;
   unsigned long fdwFlags;
   unsigned long dwBasicChannel;
   unsigned long cNumChannels;
   unsigned long cInstrumentPolyphony;
   unsigned long cChannelPolyphony;
} IDFINSTCAPS, *PIDFINSTCAPS,  *LPIDFINSTCAPS;

#define  IDFINSTCAPS_F_GENERAL_MIDI       0x00000001
#define  IDFINSTCAPS_F_SYSTEMEXCLUSIVE    0x00000002

/*
@doc  EXTERNAL SDK

@types   IDFCHANNELHDR |
   This is the format of the "chan" chunk in a Microsoft IDF file.
   This contains a description on what "type" a channel is, i.e. 
   is it a General MIDI channel, a drum channel, etc... Directly 
   following this header is the actual data on each channel.

@field   unsigned long | cbStruct |
   This is the size of the channel header structure.

@field   unsigned long | fdwFlags |
   Flags describing the channel type information.

@flag IDFCHANNELHDR_F_GENERAL_MIDI |
   If this flag is set then any channels that are not defined in the 
   IDF are General MIDI channel types.  If this flag is _NOT_ set then
   any channels that are not defined in the IDF are undefined and should 
   NOT be used in mapping. This flag overrides the contents of dwGeneralMask
   and dwDrumMask.

@field unsigned long | dwGeneralMask |
   This mask indicates which channels are available for
   use as general channels. The channels will be considered usable even if
   there is no associcate IDFCHANNELINFO structure defined.

@field unsigned long | dwDrumMask |
   This mask indicates which channels are available for
   use as drum channels. The channels will be considered usable even if
   there is no associcate IDFCHANNELINFO structure defined.

@field   unsigned long | cNumChannels |
   This is the number of channels that follows the header.

@othertype  IDFCHANNELHDR * | PIDFCHANNELHDR |
   A memory model dependant pointer to the structure.

@othertype  IDFCHANNELHDR  * | LPIDFCHANNELHDR |
   A  pointer to the structure.
*/

typedef struct tag_IDFCHANNELHDR
{
   unsigned long cbStruct;
   unsigned long dwGeneralMask;
   unsigned long dwDrumMask;
   unsigned long dwReserved;                    // Must be zero
   unsigned long fdwFlags;
} IDFCHANNELHDR, *PIDFCHANNELHDR,  *LPIDFCHANNELHDR;

#define  IDFCHANNELHDR_F_GENERAL_MIDI     0x00000001

/*
@doc  EXTERNAL SDK

@types    IDFCHANNELINFO |
   This is the format of the actual channel information for Microsoft
   authored IDF files. This is the Microsoft supported format for
   channel information.

@field   unsigned long | dwChannel |
   This is the channel number that the structure defines.

@field   unsigned long | fdwChannel |
   Defines the possible types this channel can be.

   @flag    IDFCHANNELINFO_F_GENERAL_CHANNEL |
       Indicates that this channel may be a general channel.

   @flag    IDFCHANNELINFO_F_DRUM_CHANNEL |
       Indicates that this channel may be a drum channel.

@field   unsigned long | cbInitData |
    Specifies the length of the data which should be sent to initialize
    the channel. This data will be send to initialize the channel each
    time the mapper is opened.

@field    BYTE | abData[] |
    This field contains the actual initialization data.
    <f cbInitData> should indicate the length of this sequence,
    byte aligned. However, the actual sequence should be padded so that
    it is actually unsigned long aligned (i.e. even multiple
    of four bytes). <f cbStruct> should reflect the padded length of
    the sequences.
        
@othertype  IDFCHANNELINFO * | PIDFCHANNELINFO |
   A memory model dependant pointer to the structure.

@othertype  IDFCHANNELINFO  * | LPIDFCHANNELINFO |
   A  pointer to the structure.
*/

typedef struct tag_IDFCHANNELINFO
{
   unsigned long cbStruct;
   unsigned long dwChannel;
   unsigned long cbInitData;
   BYTE  abData[];
} IDFCHANNELINFO, *PIDFCHANNELINFO,  *LPIDFCHANNELINFO;

/*
@doc  EXTERNAL SDK

@types   IDFPATCHMAPHDR |
   This is the format of the "map " chunk in a Microsoft IDF file.
   This chunk contains information on the patch map used for the 
   instrument. Directly following this header is the actual mapping 
   information for each patch.

@field   unsigned long | cbStruct |
   This is the size of the patch map header structure.

@field   BYTE | abPatchMap[128] |
   This array contains the actual patch map. The incoming patch is
   used to index the array; the array contents are the new patch value
   and must be in the range 0x00-0x7F. Patch maps will only apply to
   channels of type general. If the instrument needs a patch change
   on a drum channel, it should be included in the initialization data
   in the IDFCHANNELINFO.

@othertype  IDFPATCHMAPHDR * | PIDFPATCHMAPHDR |
   A memory model dependant pointer to the structure.

@othertype  IDFPATCHMAPHDR  * | LPIDFPATCHMAPHDR |
   A  pointer to the structure.
*/

typedef struct tag_IDFPATCHMAPHDR
{
   unsigned long cbStruct;
   BYTE  abPatchMap[128];
           
} IDFPATCHMAPHDR, *PIDFPATCHMAPHDR,  *LPIDFPATCHMAPHDR;

/*
@doc  EXTERNAL SDK

@types   IDFKEYMAPHDR |
   This is the format of the "key " chunk in a Microsoft IDF file.
   This chunk contains information on the all of the key maps used 
   for a given instrument. The information that is in this structure
   pertains to all of the key maps for the instrument.  It contains
   the total number of key maps for the instrument and whether or not
   the key maps are General MIDI.

@field   unsigned long | cbStruct |
   This is the size of the key map header structure.

@field   unsigned long | cNumKeyMaps |
   This is the number of key maps that follow the header.

@field   unsigned long | cbKeyMap |
   This is the size of each key map that follows the header.   

@othertype  IDFPATCHMAPHDR * | PIDFPATCHMAPHDR |
   A memory model dependant pointer to the structure.

@othertype  IDFPATCHMAPHDR  * | LPIDFPATCHMAPHDR |
   A  pointer to the structure.
*/

typedef struct tag_IDFKEYMAPHDR
{
   unsigned long cbStruct;
   unsigned long cNumKeyMaps;
   unsigned long cbKeyMap;
} IDFKEYMAPHDR, *PIDFKEYMAPHDR,  *LPIDFKEYMAPHDR;

/*
@doc  EXTERNAL SDK

@types   IDFKEYMAP |
   This is the format of the "gkey" or "dkey" chunk in a Microsoft
   IDF file. This chunk contains information on the all of the key maps
   used for a given instrument. The information that is in this structure
   pertains to all of the key maps for the instrument.  It contains
   the total number of key maps for the instrument and whether or not
   the key maps are General MIDI.

@field   unsigned long | cbStruct |
   This is the size of the key map header structure.

@field   BYTE | abKeyMap[128] |
    This field contains the actual key map. The incoming key number from
    a note on or note off message is used to index this array; the array
    contents are the new key value. If the high bit it set in the new
    key value, then the note on or note off will be ignore; otherwise,
    it will be transmitted with the new key value.
    
@othertype  IDFKEYMAP * | PIDFKEYMAP |
   A memory model dependant pointer to the structure.

@othertype  IDFKEYMAP  * | LPIDFKEYMAP |
   A  pointer to the structure.
*/

typedef struct tag_IDFKEYMAP
{
   unsigned long cbStruct;
   BYTE  abKeyMap[128];
} IDFKEYMAP, *PIDFKEYMAP,  *LPIDFKEYMAP;


