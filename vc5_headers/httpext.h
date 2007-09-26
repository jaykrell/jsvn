/********
*
*  Copyright (c) 1995  Process Software Corporation
*
*  Copyright (c) 1995-1996  Microsoft Corporation
*
*
*  Module Name  : HttpExt.h
*
*  Abstract :
*
*     This module contains  the structure definitions and prototypes for the
*     version 2.0 HTTP Server Extension interface.
*
******************/

#ifndef _HTTPEXT_H_
#define _HTTPEXT_H_

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

#define   HSE_VERSION_MAJOR           2      // major version of this spec
#define   HSE_VERSION_MINOR           0      // minor version of this spec
#define   HSE_LOG_BUFFER_LEN         80
#define   HSE_MAX_EXT_DLL_NAME_LEN  256

typedef   void*  HCONN;

// the following are the status codes returned by the Extension DLL

#define   HSE_STATUS_SUCCESS                       1
#define   HSE_STATUS_SUCCESS_AND_KEEP_CONN         2
#define   HSE_STATUS_PENDING                       3
#define   HSE_STATUS_ERROR                         4

// The following are the values to request services with the ServerSupportFunction.
//  Values from 0 to 1000 are reserved for future versions of the interface

#define   HSE_REQ_BASE                             0
#define   HSE_REQ_SEND_URL_REDIRECT_RESP           ( HSE_REQ_BASE + 1 )
#define   HSE_REQ_SEND_URL                         ( HSE_REQ_BASE + 2 )
#define   HSE_REQ_SEND_RESPONSE_HEADER             ( HSE_REQ_BASE + 3 )
#define   HSE_REQ_DONE_WITH_SESSION                ( HSE_REQ_BASE + 4 )
#define   HSE_REQ_END_RESERVED                     1000

//
//  These are Microsoft specific extensions
//

#define   HSE_REQ_MAP_URL_TO_PATH                  (HSE_REQ_END_RESERVED+1)
#define   HSE_REQ_GET_SSPI_INFO                    (HSE_REQ_END_RESERVED+2)
#define   HSE_APPEND_LOG_PARAMETER                 (HSE_REQ_END_RESERVED+3)
#define   HSE_REQ_SEND_URL_EX                      (HSE_REQ_END_RESERVED+4)
#define   HSE_REQ_IO_COMPLETION                    (HSE_REQ_END_RESERVED+5)
#define   HSE_REQ_TRANSMIT_FILE                    (HSE_REQ_END_RESERVED+6)
#define   HSE_REQ_REFRESH_ISAPI_ACL                (HSE_REQ_END_RESERVED+7)

//
//  Bit Flags for TerminateExtension
//
//    HSE_TERM_ADVISORY_UNLOAD - Server wants to unload the extension,
//          extension can return TRUE if OK, FALSE if the server should not
//          unload the extension
//
//    HSE_TERM_MUST_UNLOAD - Server indicating the extension is about to be
//          unloaded, the extension cannot refuse.
//

#define HSE_TERM_ADVISORY_UNLOAD                   0x00000001
#define HSE_TERM_MUST_UNLOAD                       0x00000002


//
// Flags for IO Functions, supported for IO Funcs.
//  TF means ServerSupportFunction( HSE_REQ_TRANSMIT_FILE)
//

# define HSE_IO_SYNC                      0x00000001   // for WriteClient
# define HSE_IO_ASYNC                     0x00000002   // for WriteClient/TF
# define HSE_IO_DISCONNECT_AFTER_SEND     0x00000004   // for TF
# define HSE_IO_SEND_HEADERS              0x00000008   // for TF



//
// passed to GetExtensionVersion
//

typedef struct   _HSE_VERSION_INFO {

    unsigned long  dwExtensionVersion;
    char   lpszExtensionDesc[HSE_MAX_EXT_DLL_NAME_LEN];

} HSE_VERSION_INFO, *LPHSE_VERSION_INFO;




//
// passed to extension procedure on a new request
//
typedef struct _EXTENSION_CONTROL_BLOCK {

    unsigned long     cbSize;                 // size of this struct.
    unsigned long     dwVersion;              // version info of this spec
    HCONN     ConnID;                 // Context number not to be modified!
    unsigned long     dwHttpStatusCode;       // HTTP Status code
    char      lpszLogData[HSE_LOG_BUFFER_LEN];// null terminated log info specific to this Extension DLL

    char*     lpszMethod;             // REQUEST_METHOD
    char*     lpszQueryString;        // QUERY_STRING
    char*     lpszPathInfo;           // PATH_INFO
    char*     lpszPathTranslated;     // PATH_TRANSLATED

    unsigned long     cbTotalBytes;           // Total bytes indicated from client
    unsigned long     cbAvailable;            // Available number of bytes
    BYTE*    lpbData;                // pointer to cbAvailable bytes

    char*     lpszContentType;        // Content type of client data

    BOOL (__stdcall * GetServerVariable) ( HCONN       hConn,
                                        char*       lpszVariableName,
                                        void*      lpvBuffer,
                                        unsigned long*     lpdwSize );

    BOOL (__stdcall * WriteClient)  ( HCONN      ConnID,
                                   void*     Buffer,
                                   unsigned long*    lpdwBytes,
                                   unsigned long      dwReserved );

    BOOL (__stdcall * ReadClient)  ( HCONN      ConnID,
                                  void*     lpvBuffer,
                                  unsigned long*    lpdwSize );

    BOOL (__stdcall * ServerSupportFunction)( HCONN      hConn,
                                           unsigned long      dwHSERRequest,
                                           void*     lpvBuffer,
                                           unsigned long*    lpdwSize,
                                           unsigned long*    lpdwDataType );

} EXTENSION_CONTROL_BLOCK, *LPEXTENSION_CONTROL_BLOCK;

//
//  these are the prototypes that must be exported from the extension DLL
//

BOOL  __stdcall   GetExtensionVersion( HSE_VERSION_INFO  *pVer );
unsigned long __stdcall   HttpExtensionProc(  EXTENSION_CONTROL_BLOCK *pECB );
BOOL  __stdcall   TerminateExtension( unsigned long dwFlags );

// the following type declarations is for the server side

typedef BOOL  (__stdcall * PFN_GETEXTENSIONVERSION)( HSE_VERSION_INFO  *pVer );
typedef unsigned long (__stdcall * PFN_HTTPEXTENSIONPROC )( EXTENSION_CONTROL_BLOCK *pECB );
typedef BOOL  (__stdcall * PFN_TERMINATEEXTENSION )( unsigned long dwFlags );

typedef VOID
  (__stdcall * PFN_HSE_IO_COMPLETION)(
                                   IN EXTENSION_CONTROL_BLOCK * pECB,
                                   IN void*    pContext,
                                   IN unsigned long    cbIO,
                                   IN unsigned long    dwError
                                   );




//
// HSE_TF_INFO defines the type for HTTP SERVER EXTENSION support for
//  ISAPI applications to send files using TransmitFile.
// A pointer to this object should be used with ServerSupportFunction()
//  for HSE_REQ_TRANSMIT_FILE.
//

typedef struct _HSE_TF_INFO  {

    //
    // callback and context information
    // the callback function will be called when IO is completed.
    // the context specified will be used during such callback.
    //
    // These values (if non-NULL) will override the one set by calling
    //  ServerSupportFunction() with HSE_REQ_IO_COMPLETION
    //
    PFN_HSE_IO_COMPLETION   pfnHseIO;
    void*  pContext;

    // file should have been opened with FILE_FLAG_SEQUENTIAL_SCAN
    HANDLE hFile;

    //
    // HTTP header and status code
    // These fields are used only if HSE_IO_SEND_HEADERS is present in dwFlags
    //

    const char* pszStatusCode; // HTTP Status Code  eg: "200 OK"

    unsigned long  BytesToWrite;  // special value of "0" means write entire file.
    unsigned long  Offset;        // offset value within the file to start from

    void*  pHead;         // Head buffer to be sent before file data
    unsigned long  HeadLength;    // header length
    void*  pTail;         // Tail buffer to be sent after file data
    unsigned long  TailLength;    // tail length

    unsigned long  dwFlags;       // includes HSE_IO_DISCONNECT_AFTER_SEND, ...

} HSE_TF_INFO, * LPHSE_TF_INFO;





#ifdef __cplusplus
}
#endif

#endif  // end definition _HTTPEXT_H_
#pragma once 
