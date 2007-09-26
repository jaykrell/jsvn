/*****************************************************************************\
*                                                                             *
* ole.h -       Object Linking and Embedding functions, types, and definitions*
*                                                                             *
*               Version 1.0                                                   *
*                                                                             *
*               NOTE: windows.h must be #included first                       *
*                                                                             *
*               Copyright (c) 1990-1996, Microsoft Corp.  All rights reserved.*
*                                                                             *
\*****************************************************************************/

#ifndef _INC_OLE
#define _INC_OLE

#ifdef WIN16
#include <pshpack1.h>   /* Assume byte packing throughout */
#endif

#ifdef __cplusplus
extern "C" {            /* Assume C declarations for C++ */
#endif  /* __cplusplus */

#ifndef __stdcall          /* If not included with 3.1 headers... */
#define __stdcall       PASCAL
#define __stdcall     PASCAL
#define const char*      LPSTR
#define LRESULT     LONG
#define HGLOBAL     HANDLE
#endif  /* _INC_WINDOWS */


#ifdef STRICT
#define OLE_LPCSTR  const char*
#define OLE_CONST   const
#else   /* STRICT */
#define OLE_LPCSTR  LPSTR
#define OLE_CONST
#endif /* !STRICT */

#define LRESULT     LONG
#define HGLOBAL     HANDLE


/* Object types */
#define OT_LINK             1L
#define OT_EMBEDDED         2L
#define OT_STATIC           3L

/* activate verbs */
#define OLEVERB_PRIMARY     0

/* target device info structure */
typedef struct _OLETARGETDEVICE
{
    USHORT otdDeviceNameOffset;
    USHORT otdDriverNameOffset;
    USHORT otdPortNameOffset;
    USHORT otdExtDevmodeOffset;
    USHORT otdExtDevmodeSize;
    USHORT otdEnvironmentOffset;
    USHORT otdEnvironmentSize;
    BYTE otdData[1];
} OLETARGETDEVICE;
typedef OLETARGETDEVICE * LPOLETARGETDEVICE;

/* flags used in some methods */
#define OF_SET              0x0001
#define OF_GET              0x0002
#define OF_HANDLER          0x0004

/* return codes for OLE functions */
typedef enum
{
    OLE_OK,                     /* 0   Function operated correctly             */

    OLE_WAIT_FOR_RELEASE,       /* 1   Command has been initiated, client      */
                                /*     must wait for release. keep dispatching */
                                /*     messages till OLE_RELESE in callback    */

    OLE_BUSY,                   /* 2   Tried to execute a method while another */
                                /*     method is in progress.                  */

    OLE_ERROR_PROTECT_ONLY,     /* 3   Ole APIs are called in real mode        */
    OLE_ERROR_MEMORY,           /* 4   Could not alloc or lock memory          */
    OLE_ERROR_STREAM,           /* 5  (OLESTREAM) stream error                 */
    OLE_ERROR_STATIC,           /* 6   Non static object expected              */
    OLE_ERROR_BLANK,            /* 7   Critical data missing                   */
    OLE_ERROR_DRAW,             /* 8   Error while drawing                     */
    OLE_ERROR_METAFILE,         /* 9   Invalid metafile                        */
    OLE_ERROR_ABORT,            /* 10  Client chose to abort metafile drawing  */
    OLE_ERROR_CLIPBOARD,        /* 11  Failed to get/set clipboard data        */
    OLE_ERROR_FORMAT,           /* 12  Requested format is not available       */
    OLE_ERROR_OBJECT,           /* 13  Not a valid object                      */
    OLE_ERROR_OPTION,           /* 14  Invalid option(link update / render)    */
    OLE_ERROR_PROTOCOL,         /* 15  Invalid protocol                        */
    OLE_ERROR_ADDRESS,          /* 16  One of the pointers is invalid          */
    OLE_ERROR_NOT_EQUAL,        /* 17  Objects are not equal                   */
    OLE_ERROR_HANDLE,           /* 18  Invalid handle encountered              */
    OLE_ERROR_GENERIC,          /* 19  Some general error                      */
    OLE_ERROR_CLASS,            /* 20  Invalid class                           */
    OLE_ERROR_SYNTAX,           /* 21  Command syntax is invalid               */
    OLE_ERROR_DATATYPE,         /* 22  Data format is not supported            */
    OLE_ERROR_PALETTE,          /* 23  Invalid color palette                   */
    OLE_ERROR_NOT_LINK,         /* 24  Not a linked object                     */
    OLE_ERROR_NOT_EMPTY,        /* 25  Client doc contains objects.            */
    OLE_ERROR_SIZE,             /* 26  Incorrect buffer size passed to the api */
                                /*     that places some string in caller's     */
                                /*     buffer                                  */

    OLE_ERROR_DRIVE,            /* 27  Drive letter in doc name is invalid     */
    OLE_ERROR_NETWORK,          /* 28  Failed to establish connection to a     */
                                /*     network share on which the document     */
                                /*     is located                              */

    OLE_ERROR_NAME,             /* 29  Invalid name(doc name, object name),    */
                                /*     etc.. passed to the APIs                */

    OLE_ERROR_TEMPLATE,         /* 30  Server failed to load template          */
    OLE_ERROR_NEW,              /* 31  Server failed to create new doc         */
    OLE_ERROR_EDIT,             /* 32  Server failed to create embedded        */
                                /*     instance                                */
    OLE_ERROR_OPEN,             /* 33  Server failed to open document,         */
                                /*     possible invalid link                   */

    OLE_ERROR_NOT_OPEN,         /* 34  Object is not open for editing          */
    OLE_ERROR_LAUNCH,           /* 35  Failed to launch server                 */
    OLE_ERROR_COMM,             /* 36  Failed to communicate with server       */
    OLE_ERROR_TERMINATE,        /* 37  Error in termination                    */
    OLE_ERROR_COMMAND,          /* 38  Error in execute                        */
    OLE_ERROR_SHOW,             /* 39  Error in show                           */
    OLE_ERROR_DOVERB,           /* 40  Error in sending do verb, or invalid    */
                                /*     verb                                    */
    OLE_ERROR_ADVISE_NATIVE,    /* 41  Item could be missing                   */
    OLE_ERROR_ADVISE_PICT,      /* 42  Item could be missing or server doesn't */
                                /*     this format.                            */

    OLE_ERROR_ADVISE_RENAME,    /* 43  Server doesn't support rename           */
    OLE_ERROR_POKE_NATIVE,      /* 44  Failure of poking native data to server */
    OLE_ERROR_REQUEST_NATIVE,   /* 45  Server failed to render native data     */
    OLE_ERROR_REQUEST_PICT,     /* 46  Server failed to render presentation    */
                                /*     data                                    */
    OLE_ERROR_SERVER_BLOCKED,   /* 47  Trying to block a blocked server or     */
                                /*     trying to revoke a blocked server       */
                                /*     or document                             */

    OLE_ERROR_REGISTRATION,     /* 48  Server is not registered in regestation */
                                /*     data base                               */
    OLE_ERROR_ALREADY_REGISTERED,/*49  Trying to register same doc multiple    */
                                 /*    times                                   */
    OLE_ERROR_TASK,             /* 50  Server or client task is invalid        */
    OLE_ERROR_OUTOFDATE,        /* 51  Object is out of date                   */
    OLE_ERROR_CANT_UPDATE_CLIENT,/* 52 Embed doc's client doesn't accept       */
                                /*     updates                                 */
    OLE_ERROR_UPDATE,           /* 53  erorr while trying to update            */
    OLE_ERROR_SETDATA_FORMAT,   /* 54  Server app doesn't understand the       */
                                /*     format given to its SetData method      */
    OLE_ERROR_STATIC_FROM_OTHER_OS,/* 55 trying to load a static object created */
                                   /*    on another Operating System           */
    OLE_ERROR_FILE_VER,

    /*  Following are warnings */
    OLE_WARN_DELETE_DATA = 1000 /*     Caller must delete the data when he is  */
                                /*     done with it.                           */
} OLESTATUS;



/* Codes for CallBack events */
typedef enum
{
    OLE_CHANGED,            /* 0                                             */
    OLE_SAVED,              /* 1                                             */
    OLE_CLOSED,             /* 2                                             */
    OLE_RENAMED,            /* 3                                             */
    OLE_QUERY_PAINT,        /* 4  Interruptible paint support                */
    OLE_RELEASE,            /* 5  Object is released(asynchronous operation  */
                            /*    is completed)                              */
    OLE_QUERY_RETRY        /* 6  Query for retry when server sends busy ACK */
} OLE_NOTIFICATION;

typedef enum
{
    OLE_NONE,               /* 0  no method active                           */
    OLE_DELETE,             /* 1  object delete                              */
    OLE_LNKPASTE,           /* 2  PasteLink(auto reconnect)                  */
    OLE_EMBPASTE,           /* 3  paste(and update)                          */
    OLE_SHOW,               /* 4  Show                                       */
    OLE_RUN,                /* 5  Run                                        */
    OLE_ACTIVATE,           /* 6  Activate                                   */
    OLE_UPDATE,             /* 7  Update                                     */
    OLE_CLOSE,              /* 8  Close                                      */
    OLE_RECONNECT,          /* 9  Reconnect                                  */
    OLE_SETUPDATEOPTIONS,   /* 10 setting update options                     */
    OLE_SERVERUNLAUNCH,     /* 11 server is being unlaunched                 */
    OLE_LOADFROMSTREAM,     /* 12 LoadFromStream(auto reconnect)             */
    OLE_SETDATA,            /* 13 OleSetData                                 */
    OLE_REQUESTDATA,        /* 14 OleRequestData                             */
    OLE_OTHER,              /* 15 other misc async operations                */
    OLE_CREATE,             /* 16 create                                     */
    OLE_CREATEFROMTEMPLATE, /* 17 CreatefromTemplate                         */
    OLE_CREATELINKFROMFILE, /* 18 CreateLinkFromFile                         */
    OLE_COPYFROMLNK,        /* 19 CopyFromLink(auto reconnect)               */
    OLE_CREATEFROMFILE,     /* 20 CreateFromFile                             */
    OLE_CREATEINVISIBLE     /* 21 CreateInvisible                            */
} OLE_RELEASE_METHOD;

/* rendering options */
typedef enum
{
    olerender_none,
    olerender_draw,
    olerender_format
} OLEOPT_RENDER;

/* standard clipboard format type */
typedef WORD OLECLIPFORMAT;

/* Link update options */
typedef enum
{
    oleupdate_always,
    oleupdate_onsave,
#ifdef OLE_INTERNAL
    oleupdate_oncall,
    oleupdate_onclose
#else
    oleupdate_oncall
#endif  /* OLE_INTERNAL */
} OLEOPT_UPDATE;

typedef HANDLE  HOBJECT;
typedef LONG    LHSERVER;
typedef LONG    LHCLIENTDOC;
typedef LONG    LHSERVERDOC;

typedef struct _OLEOBJECT *  LPOLEOBJECT;
typedef struct _OLESTREAM *  LPOLESTREAM;
typedef struct _OLECLIENT *  LPOLECLIENT;


/* object method table definitions. */
typedef struct _OLEOBJECTVTBL
{
    void *      (__stdcall* QueryProtocol)        (LPOLEOBJECT, OLE_LPCSTR);
    OLESTATUS      (__stdcall* Release)              (LPOLEOBJECT);
    OLESTATUS      (__stdcall* Show)                 (LPOLEOBJECT, BOOL);
    OLESTATUS      (__stdcall* DoVerb)               (LPOLEOBJECT, UINT, BOOL, BOOL);
    OLESTATUS      (__stdcall* GetData)              (LPOLEOBJECT, OLECLIPFORMAT, HANDLE *);
    OLESTATUS      (__stdcall* SetData)              (LPOLEOBJECT, OLECLIPFORMAT, HANDLE);
    OLESTATUS      (__stdcall* SetTargetDevice)      (LPOLEOBJECT, HGLOBAL);
    OLESTATUS      (__stdcall* SetBounds)            (LPOLEOBJECT, OLE_CONST RECT *);
    OLECLIPFORMAT  (__stdcall* EnumFormats)          (LPOLEOBJECT, OLECLIPFORMAT);
    OLESTATUS      (__stdcall* SetColorScheme)       (LPOLEOBJECT, OLE_CONST LOGPALETTE *);
    /* Server has to implement only the above methods. */

#ifndef SERVERONLY
    /* Extra methods required for client. */
    OLESTATUS      (__stdcall* Delete)               (LPOLEOBJECT);
    OLESTATUS      (__stdcall* SetHostNames)         (LPOLEOBJECT, OLE_LPCSTR, OLE_LPCSTR);
    OLESTATUS      (__stdcall* SaveToStream)         (LPOLEOBJECT, LPOLESTREAM);
    OLESTATUS      (__stdcall* Clone)                (LPOLEOBJECT, LPOLECLIENT, LHCLIENTDOC, OLE_LPCSTR, LPOLEOBJECT *);
    OLESTATUS      (__stdcall* CopyFromLink)         (LPOLEOBJECT, LPOLECLIENT, LHCLIENTDOC, OLE_LPCSTR, LPOLEOBJECT *);
    OLESTATUS      (__stdcall* Equal)                (LPOLEOBJECT, LPOLEOBJECT);
    OLESTATUS      (__stdcall* CopyToClipboard)      (LPOLEOBJECT);
    OLESTATUS      (__stdcall* Draw)                 (LPOLEOBJECT, HDC, OLE_CONST RECT *, OLE_CONST RECT *, HDC);
    OLESTATUS      (__stdcall* Activate)             (LPOLEOBJECT, UINT, BOOL, BOOL, HWND, OLE_CONST RECT *);
    OLESTATUS      (__stdcall* Execute)              (LPOLEOBJECT, HGLOBAL, UINT);
    OLESTATUS      (__stdcall* Close)                (LPOLEOBJECT);
    OLESTATUS      (__stdcall* Update)               (LPOLEOBJECT);
    OLESTATUS      (__stdcall* Reconnect)            (LPOLEOBJECT);

    OLESTATUS      (__stdcall* ObjectConvert)        (LPOLEOBJECT, OLE_LPCSTR, LPOLECLIENT, LHCLIENTDOC, OLE_LPCSTR, LPOLEOBJECT *);
    OLESTATUS      (__stdcall* GetLinkUpdateOptions) (LPOLEOBJECT, OLEOPT_UPDATE *);
    OLESTATUS      (__stdcall* SetLinkUpdateOptions) (LPOLEOBJECT, OLEOPT_UPDATE);

    OLESTATUS      (__stdcall* Rename)               (LPOLEOBJECT, OLE_LPCSTR);
    OLESTATUS      (__stdcall* QueryName)            (LPOLEOBJECT, LPSTR, UINT *);

    OLESTATUS      (__stdcall* QueryType)            (LPOLEOBJECT, LONG *);
    OLESTATUS      (__stdcall* QueryBounds)          (LPOLEOBJECT, RECT *);
    OLESTATUS      (__stdcall* QuerySize)            (LPOLEOBJECT, unsigned long *);
    OLESTATUS      (__stdcall* QueryOpen)            (LPOLEOBJECT);
    OLESTATUS      (__stdcall* QueryOutOfDate)       (LPOLEOBJECT);

    OLESTATUS      (__stdcall* QueryReleaseStatus)   (LPOLEOBJECT);
    OLESTATUS      (__stdcall* QueryReleaseError)    (LPOLEOBJECT);
    OLE_RELEASE_METHOD (__stdcall* QueryReleaseMethod)(LPOLEOBJECT);

    OLESTATUS      (__stdcall* RequestData)          (LPOLEOBJECT, OLECLIPFORMAT);
    OLESTATUS      (__stdcall* ObjectLong)           (LPOLEOBJECT, UINT, LONG *);

/* This method is internal only */
    OLESTATUS      (__stdcall* ChangeData)           (LPOLEOBJECT, HANDLE, LPOLECLIENT, BOOL);
#endif  /* !SERVERONLY */
} OLEOBJECTVTBL;
typedef  OLEOBJECTVTBL * LPOLEOBJECTVTBL;

#ifndef OLE_INTERNAL
typedef struct _OLEOBJECT
{
    LPOLEOBJECTVTBL    lpvtbl;
} OLEOBJECT;
#endif

/* ole client definitions */
typedef struct _OLECLIENTVTBL
{
    int (__stdcall* CallBack)(LPOLECLIENT, OLE_NOTIFICATION, LPOLEOBJECT);
} OLECLIENTVTBL;

typedef  OLECLIENTVTBL *  LPOLECLIENTVTBL;

typedef struct _OLECLIENT
{
    LPOLECLIENTVTBL   lpvtbl;
} OLECLIENT;

/* Stream definitions */
typedef struct _OLESTREAMVTBL
{
    unsigned long (__stdcall* Get)(LPOLESTREAM, void *, unsigned long);
    unsigned long (__stdcall* Put)(LPOLESTREAM, OLE_CONST void *, unsigned long);
} OLESTREAMVTBL;
typedef  OLESTREAMVTBL *  LPOLESTREAMVTBL;

typedef struct _OLESTREAM
{
    LPOLESTREAMVTBL      lpstbl;
} OLESTREAM;

/* Public Function Prototypes */
OLESTATUS   __stdcall  OleDelete(LPOLEOBJECT);
OLESTATUS   __stdcall  OleRelease(LPOLEOBJECT);
OLESTATUS   __stdcall  OleSaveToStream(LPOLEOBJECT, LPOLESTREAM);
OLESTATUS   __stdcall  OleEqual(LPOLEOBJECT, LPOLEOBJECT );
OLESTATUS   __stdcall  OleCopyToClipboard(LPOLEOBJECT);
OLESTATUS   __stdcall  OleSetHostNames(LPOLEOBJECT, const char*, const char*);
OLESTATUS   __stdcall  OleSetTargetDevice(LPOLEOBJECT, HGLOBAL);
OLESTATUS   __stdcall  OleSetBounds(LPOLEOBJECT, const RECT *);
OLESTATUS   __stdcall  OleSetColorScheme(LPOLEOBJECT, const LOGPALETTE *);
OLESTATUS   __stdcall  OleQueryBounds(LPOLEOBJECT, RECT *);
OLESTATUS   __stdcall  OleQuerySize(LPOLEOBJECT, unsigned long *);
OLESTATUS   __stdcall  OleDraw(LPOLEOBJECT, HDC, const RECT *, const RECT *, HDC);
OLESTATUS   __stdcall  OleQueryOpen(LPOLEOBJECT);
OLESTATUS   __stdcall  OleActivate(LPOLEOBJECT, UINT, BOOL, BOOL, HWND, const RECT *);
OLESTATUS   __stdcall  OleExecute(LPOLEOBJECT, HGLOBAL, UINT);
OLESTATUS   __stdcall  OleClose(LPOLEOBJECT);
OLESTATUS   __stdcall  OleUpdate(LPOLEOBJECT);
OLESTATUS   __stdcall  OleReconnect(LPOLEOBJECT);
OLESTATUS   __stdcall  OleGetLinkUpdateOptions(LPOLEOBJECT, OLEOPT_UPDATE *);
OLESTATUS   __stdcall  OleSetLinkUpdateOptions(LPOLEOBJECT, OLEOPT_UPDATE);
void *   __stdcall  OleQueryProtocol(LPOLEOBJECT, const char*);

/* Routines related to asynchronous operations. */
OLESTATUS   __stdcall  OleQueryReleaseStatus(LPOLEOBJECT);
OLESTATUS   __stdcall  OleQueryReleaseError(LPOLEOBJECT);
OLE_RELEASE_METHOD __stdcall OleQueryReleaseMethod(LPOLEOBJECT);

OLESTATUS   __stdcall  OleQueryType(LPOLEOBJECT, LONG *);

/* LOWORD is major version, HIWORD is minor version */
unsigned long       __stdcall  OleQueryClientVersion(void);
unsigned long       __stdcall  OleQueryServerVersion(void);

/* Converting to format (as in clipboard): */
OLECLIPFORMAT  __stdcall  OleEnumFormats(LPOLEOBJECT, OLECLIPFORMAT);
OLESTATUS   __stdcall  OleGetData(LPOLEOBJECT, OLECLIPFORMAT, HANDLE *);
OLESTATUS   __stdcall  OleSetData(LPOLEOBJECT, OLECLIPFORMAT, HANDLE);
OLESTATUS   __stdcall  OleQueryOutOfDate(LPOLEOBJECT);
OLESTATUS   __stdcall  OleRequestData(LPOLEOBJECT, OLECLIPFORMAT);

/* Query apis for creation from clipboard */
OLESTATUS   __stdcall  OleQueryLinkFromClip(const char*, OLEOPT_RENDER, OLECLIPFORMAT);
OLESTATUS   __stdcall  OleQueryCreateFromClip(const char*, OLEOPT_RENDER, OLECLIPFORMAT);

/* Object creation functions */
OLESTATUS   __stdcall  OleCreateFromClip(const char*, LPOLECLIENT, LHCLIENTDOC, const char*,  LPOLEOBJECT *, OLEOPT_RENDER, OLECLIPFORMAT);
OLESTATUS   __stdcall  OleCreateLinkFromClip(const char*, LPOLECLIENT, LHCLIENTDOC, const char*, LPOLEOBJECT *, OLEOPT_RENDER, OLECLIPFORMAT);
OLESTATUS   __stdcall  OleCreateFromFile(const char*, LPOLECLIENT, const char*, const char*, LHCLIENTDOC, const char*, LPOLEOBJECT *, OLEOPT_RENDER, OLECLIPFORMAT);
OLESTATUS   __stdcall  OleCreateLinkFromFile(const char*, LPOLECLIENT, const char*, const char*, const char*, LHCLIENTDOC, const char*, LPOLEOBJECT *, OLEOPT_RENDER, OLECLIPFORMAT);
OLESTATUS   __stdcall  OleLoadFromStream(LPOLESTREAM, const char*, LPOLECLIENT, LHCLIENTDOC, const char*, LPOLEOBJECT *);
OLESTATUS   __stdcall  OleCreate(const char*, LPOLECLIENT, const char*, LHCLIENTDOC, const char*, LPOLEOBJECT *, OLEOPT_RENDER, OLECLIPFORMAT);
OLESTATUS   __stdcall  OleCreateInvisible(const char*, LPOLECLIENT, const char*, LHCLIENTDOC, const char*, LPOLEOBJECT *, OLEOPT_RENDER, OLECLIPFORMAT, BOOL);
OLESTATUS   __stdcall  OleCreateFromTemplate(const char*, LPOLECLIENT, const char*, LHCLIENTDOC, const char*, LPOLEOBJECT *, OLEOPT_RENDER, OLECLIPFORMAT);
OLESTATUS   __stdcall  OleClone(LPOLEOBJECT, LPOLECLIENT, LHCLIENTDOC, const char*, LPOLEOBJECT *);
OLESTATUS   __stdcall  OleCopyFromLink(LPOLEOBJECT, const char*, LPOLECLIENT, LHCLIENTDOC, const char*, LPOLEOBJECT *);
OLESTATUS   __stdcall  OleObjectConvert(LPOLEOBJECT, const char*, LPOLECLIENT, LHCLIENTDOC, const char*, LPOLEOBJECT *);
OLESTATUS   __stdcall  OleRename(LPOLEOBJECT, const char*);
OLESTATUS   __stdcall  OleQueryName(LPOLEOBJECT, LPSTR, UINT *);
OLESTATUS   __stdcall  OleRevokeObject(LPOLECLIENT);
BOOL        __stdcall  OleIsDcMeta(HDC);

/* client document API */
OLESTATUS   __stdcall  OleRegisterClientDoc(const char*, const char*, LONG, LHCLIENTDOC *);
OLESTATUS   __stdcall  OleRevokeClientDoc(LHCLIENTDOC);
OLESTATUS   __stdcall  OleRenameClientDoc(LHCLIENTDOC, const char*);
OLESTATUS   __stdcall  OleRevertClientDoc(LHCLIENTDOC);
OLESTATUS   __stdcall  OleSavedClientDoc(LHCLIENTDOC);
OLESTATUS   __stdcall  OleEnumObjects(LHCLIENTDOC, LPOLEOBJECT *);

/* server usage definitions */
typedef enum {
    OLE_SERVER_MULTI,           /* multiple instances */
    OLE_SERVER_SINGLE           /* single instance(multiple document) */
} OLE_SERVER_USE;

/* Server API */
typedef struct _OLESERVER *  LPOLESERVER;

OLESTATUS   __stdcall  OleRegisterServer(const char*, LPOLESERVER, LHSERVER *, HINSTANCE, OLE_SERVER_USE);
OLESTATUS   __stdcall  OleRevokeServer(LHSERVER);
OLESTATUS   __stdcall  OleBlockServer(LHSERVER);
OLESTATUS   __stdcall  OleUnblockServer(LHSERVER, BOOL *);

/* APIs to keep server open */
OLESTATUS   __stdcall  OleLockServer(LPOLEOBJECT, LHSERVER *);
OLESTATUS   __stdcall  OleUnlockServer(LHSERVER);

/* Server document API */

typedef struct _OLESERVERDOC *  LPOLESERVERDOC;

OLESTATUS   __stdcall  OleRegisterServerDoc(LHSERVER, const char*, LPOLESERVERDOC, LHSERVERDOC *);
OLESTATUS   __stdcall  OleRevokeServerDoc(LHSERVERDOC);
OLESTATUS   __stdcall  OleRenameServerDoc(LHSERVERDOC, const char*);
OLESTATUS   __stdcall  OleRevertServerDoc(LHSERVERDOC);
OLESTATUS   __stdcall  OleSavedServerDoc(LHSERVERDOC);

typedef struct _OLESERVERVTBL
{
    OLESTATUS (__stdcall* Open)  (LPOLESERVER, LHSERVERDOC, OLE_LPCSTR, LPOLESERVERDOC *);
                                    /* long handle to doc(privtate to DLL)  */
                                    /* lp to OLESERVER                      */
                                    /* document name                        */
                                    /* place holder for returning oledoc.   */

    OLESTATUS (__stdcall* Create)(LPOLESERVER, LHSERVERDOC, OLE_LPCSTR, OLE_LPCSTR, LPOLESERVERDOC *);
                                    /* long handle to doc(privtate to DLL)  */
                                    /* lp to OLESERVER                      */
                                    /* lp class name                        */
                                    /* lp doc name                          */
                                    /* place holder for returning oledoc.   */

    OLESTATUS (__stdcall* CreateFromTemplate)(LPOLESERVER, LHSERVERDOC, OLE_LPCSTR, OLE_LPCSTR, OLE_LPCSTR, LPOLESERVERDOC *);
                                    /* long handle to doc(privtate to DLL)  */
                                    /* lp to OLESERVER                      */
                                    /* lp class name                        */
                                    /* lp doc name                          */
                                    /* lp template name                     */
                                    /* place holder for returning oledoc.   */

    OLESTATUS (__stdcall* Edit)  (LPOLESERVER, LHSERVERDOC, OLE_LPCSTR, OLE_LPCSTR, LPOLESERVERDOC *);
                                    /* long handle to doc(privtate to DLL)  */
                                    /* lp to OLESERVER                      */
                                    /* lp class name                        */
                                    /* lp doc name                          */
                                    /* place holder for returning oledoc.   */

    OLESTATUS (__stdcall* Exit)  (LPOLESERVER);
                                    /* lp OLESERVER                         */

    OLESTATUS (__stdcall* Release)  (LPOLESERVER);
                                    /* lp OLESERVER                         */

    OLESTATUS (__stdcall* Execute)(LPOLESERVER, HGLOBAL);
                                    /* lp OLESERVER                         */
                                    /* handle to command strings            */
} OLESERVERVTBL;
typedef  OLESERVERVTBL *  LPOLESERVERVTBL;

typedef struct _OLESERVER
{
    LPOLESERVERVTBL    lpvtbl;
} OLESERVER;

typedef struct _OLESERVERDOCVTBL
{
    OLESTATUS (__stdcall* Save)      (LPOLESERVERDOC);
    OLESTATUS (__stdcall* Close)     (LPOLESERVERDOC);
    OLESTATUS (__stdcall* SetHostNames)(LPOLESERVERDOC, OLE_LPCSTR, OLE_LPCSTR);
    OLESTATUS (__stdcall* SetDocDimensions)(LPOLESERVERDOC, OLE_CONST RECT *);
    OLESTATUS (__stdcall* GetObject) (LPOLESERVERDOC, OLE_LPCSTR, LPOLEOBJECT *, LPOLECLIENT);
    OLESTATUS (__stdcall* Release)   (LPOLESERVERDOC);
    OLESTATUS (__stdcall* SetColorScheme)(LPOLESERVERDOC, OLE_CONST LOGPALETTE *);
    OLESTATUS (__stdcall* Execute)  (LPOLESERVERDOC, HGLOBAL);
} OLESERVERDOCVTBL;
typedef  OLESERVERDOCVTBL *  LPOLESERVERDOCVTBL;

typedef struct _OLESERVERDOC
{
    LPOLESERVERDOCVTBL lpvtbl;
} OLESERVERDOC;

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#ifdef WIN16
#include <poppack.h>
#endif

#endif  /* !_INC_OLE */
#pragma once 
