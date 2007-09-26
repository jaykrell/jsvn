/* Copyright (c) 1995-1996, Microsoft Corporation, all rights reserved
**
** rasdlg.h
** Remote Access Common Dialog APIs
** Public header
**
** These APIs live in RASDLG.DLL.
**
** The APIs in this header are added in Windows NT SUR and are not available
** in prior Windows NT or Windows 95 releases.
*/

#ifndef _RASDLG_H_
#define _RASDLG_H_

#include <pshpack4.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <ras.h>


/* RasPhonebookDlg API callback.
*/
typedef VOID (WINAPI* RASPBDLGFUNCW)( unsigned long, unsigned long, LPWSTR, void* );
typedef VOID (WINAPI* RASPBDLGFUNCA)( unsigned long, unsigned long, LPSTR, void* );

#define RASPBDEVENT_AddEntry    1
#define RASPBDEVENT_EditEntry   2
#define RASPBDEVENT_RemoveEntry 3
#define RASPBDEVENT_DialEntry   4
#define RASPBDEVENT_EditGlobals 5
#define RASPBDEVENT_NoUser      6
#define RASPBDEVENT_NoUserEdit  7

/* Defines the information passed in the 4th argument of RASPBDLGFUNC on
** "NoUser" and "NoUserEdit" events.  Usage shown is for "NoUser".  For
** "NoUserEdit", the timeout is ignored and the three strings are INs.
*/
#define RASNOUSERW struct tagRASNOUSERW
RASNOUSERW
{
    IN  unsigned long dwSize;
    IN  unsigned long dwFlags;
    OUT unsigned long dwTimeoutMs;
    OUT WCHAR szUserName[ UNLEN + 1 ];
    OUT WCHAR szPassword[ PWLEN + 1 ];
    OUT WCHAR szDomain[ DNLEN + 1 ];
};

#define RASNOUSERA struct tagRASNOUSERA
RASNOUSERA
{
    IN  unsigned long dwSize;
    IN  unsigned long dwFlags;
    OUT unsigned long dwTimeoutMs;
    OUT CHAR  szUserName[ UNLEN + 1 ];
    OUT CHAR  szPassword[ PWLEN + 1 ];
    OUT CHAR  szDomain[ DNLEN + 1 ];
};

#ifdef UNICODE
#define RASNOUSER RASNOUSERW
#else
#define RASNOUSER RASNOUSERA
#endif

#define LPRASNOUSERW RASNOUSERW*
#define LPRASNOUSERA RASNOUSERA*
#define LPRASNOUSER  RASNOUSER*


/* RasPhonebookDlg API parameters.
*/
#define RASPBDFLAG_PositionDlg      0x00000001
#define RASPBDFLAG_ForceCloseOnDial 0x00000002
#define RASPBDFLAG_NoUser           0x00000010
#define RASPBDFLAG_UpdateDefaults   0x80000000

#define RASPBDLGW struct tagRASPBDLGW
RASPBDLGW
{
    IN  unsigned long         dwSize;
    IN  HWND          hwndOwner;
    IN  unsigned long         dwFlags;
    IN  LONG          xDlg;
    IN  LONG          yDlg;
    IN  unsigned long         dwCallbackId;
    IN  RASPBDLGFUNCW pCallback;
    OUT unsigned long         dwError;
    IN  unsigned long         reserved;
    IN  unsigned long         reserved2;
};

#define RASPBDLGA struct tagRASPBDLGA
RASPBDLGA
{
    IN  unsigned long         dwSize;
    IN  HWND          hwndOwner;
    IN  unsigned long         dwFlags;
    IN  LONG          xDlg;
    IN  LONG          yDlg;
    IN  unsigned long         dwCallbackId;
    IN  RASPBDLGFUNCA pCallback;
    OUT unsigned long         dwError;
    IN  unsigned long         reserved;
    IN  unsigned long         reserved2;
};

#ifdef UNICODE
#define RASPBDLG     RASPBDLGW
#define RASPBDLGFUNC RASPBDLGFUNCW
#else
#define RASPBDLG     RASPBDLGA
#define RASPBDLGFUNC RASPBDLGFUNCA
#endif

#define LPRASPBDLGW RASPBDLGW*
#define LPRASPBDLGA RASPBDLGA*
#define LPRASPBDLG  RASPBDLG*


/* RasEntryDlg API parameters.
*/
#define RASEDFLAG_PositionDlg 0x00000001
#define RASEDFLAG_NewEntry    0x00000002
#define RASEDFLAG_CloneEntry  0x00000004
#define RASEDFLAG_NoRename    0x00000008

#define RASENTRYDLGW struct tagRASENTRYDLGW
RASENTRYDLGW
{
    IN  unsigned long dwSize;
    IN  HWND  hwndOwner;
    IN  unsigned long dwFlags;
    IN  LONG  xDlg;
    IN  LONG  yDlg;
    OUT WCHAR szEntry[ RAS_MaxEntryName + 1 ];
    OUT unsigned long dwError;
    IN  unsigned long reserved;
    IN  unsigned long reserved2;
};

#define RASENTRYDLGA struct tagRASENTRYDLGA
RASENTRYDLGA
{
    IN  unsigned long dwSize;
    IN  HWND  hwndOwner;
    IN  unsigned long dwFlags;
    IN  LONG  xDlg;
    IN  LONG  yDlg;
    OUT CHAR  szEntry[ RAS_MaxEntryName + 1 ];
    OUT unsigned long dwError;
    IN  unsigned long reserved;
    IN  unsigned long reserved2;
};

#ifdef UNICODE
#define RASENTRYDLG RASENTRYDLGW
#else
#define RASENTRYDLG RASENTRYDLGA
#endif

#define LPRASENTRYDLGW RASENTRYDLGW*
#define LPRASENTRYDLGA RASENTRYDLGA*
#define LPRASENTRYDLG  RASENTRYDLG*


/* RasDialDlg API parameters.
*/
#define RASDDFLAG_PositionDlg 0x00000001
#define RASDDFLAG_LinkFailure 0x80000000

#define RASDIALDLG struct tagRASDIALDLG
RASDIALDLG
{
    IN  unsigned long dwSize;
    IN  HWND  hwndOwner;
    IN  unsigned long dwFlags;
    IN  LONG  xDlg;
    IN  LONG  yDlg;
    IN  unsigned long dwSubEntry;
    OUT unsigned long dwError;
    IN  unsigned long reserved;
    IN  unsigned long reserved2;
};

#define LPRASDIALDLG RASDIALDLG*


/* RasMonitorDlg API parameters.
*/

#define RASMDPAGE_Status            0
#define RASMDPAGE_Summary           1
#define RASMDPAGE_Preferences       2

#define RASMDFLAG_PositionDlg       0x00000001
#define RASMDFLAG_UpdateDefaults    0x80000000

#define RASMONITORDLG struct tagRASMONITORDLG
RASMONITORDLG
{
    IN  unsigned long dwSize;
    IN  HWND  hwndOwner;
    IN  unsigned long dwFlags;
    IN  unsigned long dwStartPage;
    IN  LONG  xDlg;
    IN  LONG  yDlg;
    OUT unsigned long dwError;
    IN  unsigned long reserved;
    IN  unsigned long reserved2;
};

#define LPRASMONITORDLG RASMONITORDLG*


/* RAS common dialog API prototypes.
*/
BOOL __stdcall RasPhonebookDlgA(
    LPSTR lpszPhonebook, LPSTR lpszEntry, LPRASPBDLGA lpInfo );

BOOL __stdcall RasPhonebookDlgW(
    LPWSTR lpszPhonebook, LPWSTR lpszEntry, LPRASPBDLGW lpInfo );

BOOL __stdcall RasEntryDlgA(
    LPSTR lpszPhonebook, LPSTR lpszEntry, LPRASENTRYDLGA lpInfo );

BOOL __stdcall RasEntryDlgW(
    LPWSTR lpszPhonebook, LPWSTR lpszEntry, LPRASENTRYDLGW lpInfo );

BOOL __stdcall RasDialDlgA(
    LPSTR lpszPhonebook, LPSTR lpszEntry, LPSTR lpszPhoneNumber,
    LPRASDIALDLG lpInfo );

BOOL __stdcall RasDialDlgW(
    LPWSTR lpszPhonebook, LPWSTR lpszEntry, LPWSTR lpszPhoneNumber,
    LPRASDIALDLG lpInfo );

BOOL __stdcall RasMonitorDlgA(
    LPSTR lpszDeviceName, LPRASMONITORDLG lpInfo );

BOOL __stdcall RasMonitorDlgW(
    LPWSTR lpszDeviceName, LPRASMONITORDLG lpInfo );


#ifdef UNICODE
#define RasPhonebookDlg RasPhonebookDlgW
#define RasEntryDlg     RasEntryDlgW
#define RasDialDlg      RasDialDlgW
#define RasMonitorDlg   RasMonitorDlgW
#else
#define RasPhonebookDlg RasPhonebookDlgA
#define RasEntryDlg     RasEntryDlgA
#define RasDialDlg      RasDialDlgA
#define RasMonitorDlg   RasMonitorDlgA
#endif



#ifdef __cplusplus
}
#endif

#include <poppack.h>

#endif // _RASDLG_H_
#pragma once 
