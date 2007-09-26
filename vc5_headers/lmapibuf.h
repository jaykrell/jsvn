/*++ BUILD Version: 0001    // Increment this if a change has global effects

Copyright (c) 1991-1996  Microsoft Corporation

Module Name:

    lmapibuf.h

Abstract:

    This file contains information about NetApiBuffer APIs.

Environment:

    User Mode - Win32

Notes:

    You must include LMCONS.H before this file, since this file depends
    on values defined in LMCONS.H.

--*/

#ifndef _LMAPIBUF_
#define _LMAPIBUF_

#ifdef __cplusplus
extern "C" {
#endif

//
// Function Prototypes
//

NET_API_STATUS NET_API_FUNCTION
NetApiBufferAllocate(
    IN unsigned long ByteCount,
    OUT void* * Buffer
    );

NET_API_STATUS NET_API_FUNCTION
NetApiBufferFree (
    IN void* Buffer
    );

NET_API_STATUS NET_API_FUNCTION
NetApiBufferReallocate(
    IN void* OldBuffer OPTIONAL,
    IN unsigned long NewByteCount,
    OUT void* * NewBuffer
    );

NET_API_STATUS NET_API_FUNCTION
NetApiBufferSize(
    IN void* Buffer,
    OUT LPDWORD ByteCount
    );


//
// The following private function will go away eventually.
// Call NetApiBufferAllocate instead.
//
NET_API_STATUS NET_API_FUNCTION
NetapipBufferAllocate (                 // Internal Function
    IN unsigned long ByteCount,
    OUT void* * Buffer
    );

#ifdef __cplusplus
}
#endif

#endif // _LMAPIBUF_
#pragma once 
