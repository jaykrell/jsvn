/****************************************************************************
*                                                                           *
* winuser.h -- USER procedure declarations, constant definitions and macros *
*                                                                           *
* Copyright (c) 1985-1996, Microsoft Corp. All rights reserved.             *
*                                                                           *
****************************************************************************/


#ifndef _WINUSER_
#define _WINUSER_

//
// Define API decoration for direct importing of DLL references.
//

#if !defined(_USER32_)
#define WINUSERAPI DECLSPEC_IMPORT
#else
#define WINUSERAPI
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#ifndef WINVER
#define WINVER  0x0400      /* version 4.0 */
#endif /* !WINVER */

#include <stdarg.h>

#ifndef NOUSER

typedef HANDLE HDWP;
typedef VOID MENUTEMPLATEA;
typedef VOID MENUTEMPLATEW;
#ifdef UNICODE
typedef MENUTEMPLATEW MENUTEMPLATE;
#else
typedef MENUTEMPLATEA MENUTEMPLATE;
#endif // UNICODE
typedef void* LPMENUTEMPLATEA;
typedef void* LPMENUTEMPLATEW;
#ifdef UNICODE
typedef LPMENUTEMPLATEW LPMENUTEMPLATE;
#else
typedef LPMENUTEMPLATEA LPMENUTEMPLATE;
#endif // UNICODE

typedef LRESULT (__stdcall* WNDPROC)(HWND, unsigned, WPARAM, LPARAM);

#ifdef STRICT

typedef BOOL (__stdcall* DLGPROC)(HWND, unsigned, WPARAM, LPARAM);
typedef VOID (__stdcall* TIMERPROC)(HWND, unsigned, unsigned, unsigned long);
typedef BOOL (__stdcall* GRAYSTRINGPROC)(HDC, LPARAM, int);
typedef BOOL (__stdcall* WNDENUMPROC)(HWND, LPARAM);
typedef LRESULT (__stdcall* HOOKPROC)(int code, WPARAM wParam, LPARAM lParam);
typedef VOID (__stdcall* SENDASYNCPROC)(HWND, unsigned, unsigned long, LRESULT);

typedef BOOL (__stdcall* PROPENUMPROCA)(HWND, const char*, HANDLE);
typedef BOOL (__stdcall* PROPENUMPROCW)(HWND, const wchar_t*, HANDLE);

typedef BOOL (__stdcall* PROPENUMPROCEXA)(HWND, char*, HANDLE, unsigned long);
typedef BOOL (__stdcall* PROPENUMPROCEXW)(HWND, wchar_t*, HANDLE, unsigned long);

typedef int (__stdcall* EDITWORDBREAKPROCA)(char* lpch, int ichCurrent, int cch, int code);
typedef int (__stdcall* EDITWORDBREAKPROCW)(wchar_t* lpch, int ichCurrent, int cch, int code);

#if(WINVER >= 0x0400)
typedef BOOL (__stdcall* DRAWSTATEPROC)(HDC hdc, LPARAM lData, WPARAM wData, int cx, int cy);
#endif /* WINVER >= 0x0400 */
#else /* !STRICT */

typedef FARPROC DLGPROC;
typedef FARPROC TIMERPROC;
typedef FARPROC GRAYSTRINGPROC;
typedef FARPROC WNDENUMPROC;
typedef FARPROC HOOKPROC;
typedef FARPROC SENDASYNCPROC;

typedef FARPROC EDITWORDBREAKPROCA;
typedef FARPROC EDITWORDBREAKPROCW;

typedef FARPROC PROPENUMPROCA;
typedef FARPROC PROPENUMPROCW;

typedef FARPROC PROPENUMPROCEXA;
typedef FARPROC PROPENUMPROCEXW;

#if(WINVER >= 0x0400)
typedef FARPROC DRAWSTATEPROC;
#endif /* WINVER >= 0x0400 */
#endif /* !STRICT */

#ifdef UNICODE
typedef PROPENUMPROCW        PROPENUMPROC;
typedef PROPENUMPROCEXW      PROPENUMPROCEX;
typedef EDITWORDBREAKPROCW   EDITWORDBREAKPROC;
#else  /* !UNICODE */
typedef PROPENUMPROCA        PROPENUMPROC;
typedef PROPENUMPROCEXA      PROPENUMPROCEX;
typedef EDITWORDBREAKPROCA   EDITWORDBREAKPROC;
#endif /* UNICODE */

#ifdef STRICT

typedef BOOL (__stdcall* NAMEENUMPROCA)(char*, LPARAM);
typedef BOOL (__stdcall* NAMEENUMPROCW)(wchar_t*, LPARAM);

typedef NAMEENUMPROCA   WINSTAENUMPROCA;
typedef NAMEENUMPROCA   DESKTOPENUMPROCA;
typedef NAMEENUMPROCW   WINSTAENUMPROCW;
typedef NAMEENUMPROCW   DESKTOPENUMPROCW;

#else /* !STRICT */

typedef FARPROC NAMEENUMPROCA;
typedef FARPROC NAMEENUMPROCW;
typedef FARPROC WINSTAENUMPROCA;
typedef FARPROC DESKTOPENUMPROCA;
typedef FARPROC WINSTAENUMPROCW;
typedef FARPROC DESKTOPENUMPROCW;

#endif /* !STRICT */

#ifdef UNICODE
typedef WINSTAENUMPROCW     WINSTAENUMPROC;
typedef DESKTOPENUMPROCW    DESKTOPENUMPROC;
#else  /* !UNICODE */
typedef WINSTAENUMPROCA     WINSTAENUMPROC;
typedef DESKTOPENUMPROCA    DESKTOPENUMPROC;
#endif /* UNICODE */

#define MAKEINTRESOURCEA(i) (char*)((unsigned long)((WORD)(i)))
#define MAKEINTRESOURCEW(i) (wchar_t*)((unsigned long)((WORD)(i)))
#ifdef UNICODE
#define MAKEINTRESOURCE  MAKEINTRESOURCEW
#else
#define MAKEINTRESOURCE  MAKEINTRESOURCEA
#endif // !UNICODE

#ifndef NORESOURCE

/*
 * Predefined Resource Types
 */
#define RT_CURSOR           MAKEINTRESOURCE(1)
#define RT_BITMAP           MAKEINTRESOURCE(2)
#define RT_ICON             MAKEINTRESOURCE(3)
#define RT_MENU             MAKEINTRESOURCE(4)
#define RT_DIALOG           MAKEINTRESOURCE(5)
#define RT_STRING           MAKEINTRESOURCE(6)
#define RT_FONTDIR          MAKEINTRESOURCE(7)
#define RT_FONT             MAKEINTRESOURCE(8)
#define RT_ACCELERATOR      MAKEINTRESOURCE(9)
#define RT_RCDATA           MAKEINTRESOURCE(10)
#define RT_MESSAGETABLE     MAKEINTRESOURCE(11)

#define DIFFERENCE          11
#define RT_GROUP_CURSOR MAKEINTRESOURCE((unsigned long)RT_CURSOR + DIFFERENCE)
#define RT_GROUP_ICON   MAKEINTRESOURCE((unsigned long)RT_ICON + DIFFERENCE)
#define RT_VERSION      MAKEINTRESOURCE(16)
#define RT_DLGINCLUDE   MAKEINTRESOURCE(17)
#if(WINVER >= 0x0400)
#define RT_PLUGPLAY     MAKEINTRESOURCE(19)
#define RT_VXD          MAKEINTRESOURCE(20)
#define RT_ANICURSOR    MAKEINTRESOURCE(21)
#define RT_ANIICON      MAKEINTRESOURCE(22)
#endif /* WINVER >= 0x0400 */

#endif /* !NORESOURCE */

/*WINUSERAPI*/
int
__stdcall
wvsprintfA(
    char*,
    const char*,
    va_list arglist);
/*WINUSERAPI*/
int
__stdcall
wvsprintfW(
    wchar_t*,
    const wchar_t*,
    va_list arglist);
#ifdef UNICODE
#define wvsprintf  wvsprintfW
#else
#define wvsprintf  wvsprintfA
#endif // !UNICODE

/*WINUSERAPI*/ int WINAPIV wsprintfA(char*, const char*, ...);
/*WINUSERAPI*/ int WINAPIV wsprintfW(wchar_t*, const wchar_t*, ...);
#ifdef UNICODE
#define wsprintf  wsprintfW
#else
#define wsprintf  wsprintfA
#endif // !UNICODE

#ifndef NOSCROLL

/*
 * Scroll Bar Constants
 */
#define SB_HORZ             0
#define SB_VERT             1
#define SB_CTL              2
#define SB_BOTH             3

/*
 * Scroll Bar Commands
 */
#define SB_LINEUP           0
#define SB_LINELEFT         0
#define SB_LINEDOWN         1
#define SB_LINERIGHT        1
#define SB_PAGEUP           2
#define SB_PAGELEFT         2
#define SB_PAGEDOWN         3
#define SB_PAGERIGHT        3
#define SB_THUMBPOSITION    4
#define SB_THUMBTRACK       5
#define SB_TOP              6
#define SB_LEFT             6
#define SB_BOTTOM           7
#define SB_RIGHT            7
#define SB_ENDSCROLL        8

#endif /* !NOSCROLL */

#ifndef NOSHOWWINDOW

// begin_r_winuser

/*
 * ShowWindow() Commands
 */
#define SW_HIDE             0
#define SW_SHOWNORMAL       1
#define SW_NORMAL           1
#define SW_SHOWMINIMIZED    2
#define SW_SHOWMAXIMIZED    3
#define SW_MAXIMIZE         3
#define SW_SHOWNOACTIVATE   4
#define SW_SHOW             5
#define SW_MINIMIZE         6
#define SW_SHOWMINNOACTIVE  7
#define SW_SHOWNA           8
#define SW_RESTORE          9
#define SW_SHOWDEFAULT      10
#define SW_MAX              10

/*
 * Old ShowWindow() Commands
 */
#define HIDE_WINDOW         0
#define SHOW_OPENWINDOW     1
#define SHOW_ICONWINDOW     2
#define SHOW_FULLSCREEN     3
#define SHOW_OPENNOACTIVATE 4

/*
 * Identifiers for the WM_SHOWWINDOW message
 */
#define SW_PARENTCLOSING    1
#define SW_OTHERZOOM        2
#define SW_PARENTOPENING    3
#define SW_OTHERUNZOOM      4

// end_r_winuser

#endif /* !NOSHOWWINDOW */

/*
 * WM_KEYUP/DOWN/char HIWORD(lParam) flags
 */
#define KF_EXTENDED         0x0100
#define KF_DLGMODE          0x0800
#define KF_MENUMODE         0x1000
#define KF_ALTDOWN          0x2000
#define KF_REPEAT           0x4000
#define KF_UP               0x8000

#ifndef NOVIRTUALKEYCODES

// begin_r_winuser

/*
 * Virtual Keys, Standard Set
 */
#define VK_LBUTTON        0x01
#define VK_RBUTTON        0x02
#define VK_CANCEL         0x03
#define VK_MBUTTON        0x04    /* NOT contiguous with L & RBUTTON */

#define VK_BACK           0x08
#define VK_TAB            0x09

#define VK_CLEAR          0x0C
#define VK_RETURN         0x0D

#define VK_SHIFT          0x10
#define VK_CONTROL        0x11
#define VK_MENU           0x12
#define VK_PAUSE          0x13
#define VK_CAPITAL        0x14


#define VK_ESCAPE         0x1B

#define VK_SPACE          0x20
#define VK_PRIOR          0x21
#define VK_NEXT           0x22
#define VK_END            0x23
#define VK_HOME           0x24
#define VK_LEFT           0x25
#define VK_UP             0x26
#define VK_RIGHT          0x27
#define VK_DOWN           0x28
#define VK_SELECT         0x29
#define VK_PRINT          0x2A
#define VK_EXECUTE        0x2B
#define VK_SNAPSHOT       0x2C
#define VK_INSERT         0x2D
#define VK_DELETE         0x2E
#define VK_HELP           0x2F

/* VK_0 thru VK_9 are the same as ASCII '0' thru '9' (0x30 - 0x39) */
/* VK_A thru VK_Z are the same as ASCII 'A' thru 'Z' (0x41 - 0x5A) */

#define VK_LWIN           0x5B
#define VK_RWIN           0x5C
#define VK_APPS           0x5D

#define VK_NUMPAD0        0x60
#define VK_NUMPAD1        0x61
#define VK_NUMPAD2        0x62
#define VK_NUMPAD3        0x63
#define VK_NUMPAD4        0x64
#define VK_NUMPAD5        0x65
#define VK_NUMPAD6        0x66
#define VK_NUMPAD7        0x67
#define VK_NUMPAD8        0x68
#define VK_NUMPAD9        0x69
#define VK_MULTIPLY       0x6A
#define VK_ADD            0x6B
#define VK_SEPARATOR      0x6C
#define VK_SUBTRACT       0x6D
#define VK_DECIMAL        0x6E
#define VK_DIVIDE         0x6F
#define VK_F1             0x70
#define VK_F2             0x71
#define VK_F3             0x72
#define VK_F4             0x73
#define VK_F5             0x74
#define VK_F6             0x75
#define VK_F7             0x76
#define VK_F8             0x77
#define VK_F9             0x78
#define VK_F10            0x79
#define VK_F11            0x7A
#define VK_F12            0x7B
#define VK_F13            0x7C
#define VK_F14            0x7D
#define VK_F15            0x7E
#define VK_F16            0x7F
#define VK_F17            0x80
#define VK_F18            0x81
#define VK_F19            0x82
#define VK_F20            0x83
#define VK_F21            0x84
#define VK_F22            0x85
#define VK_F23            0x86
#define VK_F24            0x87

#define VK_NUMLOCK        0x90
#define VK_SCROLL         0x91

/*
 * VK_L* & VK_R* - left and right Alt, Ctrl and Shift virtual keys.
 * Used only as parameters to GetAsyncKeyState() and GetKeyState().
 * No other API or message will distinguish left and right keys in this way.
 */
#define VK_LSHIFT         0xA0
#define VK_RSHIFT         0xA1
#define VK_LCONTROL       0xA2
#define VK_RCONTROL       0xA3
#define VK_LMENU          0xA4
#define VK_RMENU          0xA5

#if(WINVER >= 0x0400)
#define VK_PROCESSKEY     0xE5
#endif /* WINVER >= 0x0400 */

#define VK_ATTN           0xF6
#define VK_CRSEL          0xF7
#define VK_EXSEL          0xF8
#define VK_EREOF          0xF9
#define VK_PLAY           0xFA
#define VK_ZOOM           0xFB
#define VK_NONAME         0xFC
#define VK_PA1            0xFD
#define VK_OEM_CLEAR      0xFE

// end_r_winuser

#endif /* !NOVIRTUALKEYCODES */

#ifndef NOWH

/*
 * SetWindowsHook() codes
 */
#define WH_MIN              (-1)
#define WH_MSGFILTER        (-1)
#define WH_JOURNALRECORD    0
#define WH_JOURNALPLAYBACK  1
#define WH_KEYBOARD         2
#define WH_GETMESSAGE       3
#define WH_CALLWNDPROC      4
#define WH_CBT              5
#define WH_SYSMSGFILTER     6
#define WH_MOUSE            7
#define WH_HARDWARE         8
#define WH_DEBUG            9
#define WH_SHELL           10
#define WH_FOREGROUNDIDLE  11
#if(WINVER >= 0x0400)
#define WH_CALLWNDPROCRET  12
#endif /* WINVER >= 0x0400 */
#if(WINVER >= 0x0400)
#define WH_MAX             12
#else
#define WH_MAX             11
#endif
#define WH_MINHOOK         WH_MIN
#define WH_MAXHOOK         WH_MAX

/*
 * Hook Codes
 */
#define HC_ACTION           0
#define HC_GETNEXT          1
#define HC_SKIP             2
#define HC_NOREMOVE         3
#define HC_NOREM            HC_NOREMOVE
#define HC_SYSMODALON       4
#define HC_SYSMODALOFF      5

/*
 * CBT Hook Codes
 */
#define HCBT_MOVESIZE       0
#define HCBT_MINMAX         1
#define HCBT_QS             2
#define HCBT_CREATEWND      3
#define HCBT_DESTROYWND     4
#define HCBT_ACTIVATE       5
#define HCBT_CLICKSKIPPED   6
#define HCBT_KEYSKIPPED     7
#define HCBT_SYSCOMMAND     8
#define HCBT_SETFOCUS       9

/*
 * HCBT_CREATEWND parameters pointed to by lParam
 */
typedef struct tagCBT_CREATEWNDA
{
    struct tagCREATESTRUCTA *lpcs;
    HWND           hwndInsertAfter;
} CBT_CREATEWNDA, *LPCBT_CREATEWNDA;
/*
 * HCBT_CREATEWND parameters pointed to by lParam
 */
typedef struct tagCBT_CREATEWNDW
{
    struct tagCREATESTRUCTW *lpcs;
    HWND           hwndInsertAfter;
} CBT_CREATEWNDW, *LPCBT_CREATEWNDW;
#ifdef UNICODE
typedef CBT_CREATEWNDW CBT_CREATEWND;
typedef LPCBT_CREATEWNDW LPCBT_CREATEWND;
#else
typedef CBT_CREATEWNDA CBT_CREATEWND;
typedef LPCBT_CREATEWNDA LPCBT_CREATEWND;
#endif // UNICODE

/*
 * HCBT_ACTIVATE structure pointed to by lParam
 */
typedef struct tagCBTACTIVATESTRUCT
{
    BOOL    fMouse;
    HWND    hWndActive;
} CBTACTIVATESTRUCT, *LPCBTACTIVATESTRUCT;

/*
 * WH_MSGFILTER Filter Proc Codes
 */
#define MSGF_DIALOGBOX      0
#define MSGF_MESSAGEBOX     1
#define MSGF_MENU           2
#define MSGF_MOVE           3
#define MSGF_SIZE           4
#define MSGF_SCROLLBAR      5
#define MSGF_NEXTWINDOW     6
#define MSGF_MAINLOOP       8
#define MSGF_MAX            8
#define MSGF_USER           4096

/*
 * Shell support
 */
#define HSHELL_WINDOWCREATED        1
#define HSHELL_WINDOWDESTROYED      2
#define HSHELL_ACTIVATESHELLWINDOW  3

#if(WINVER >= 0x0400)
#define HSHELL_WINDOWACTIVATED      4
#define HSHELL_GETMINRECT           5
#define HSHELL_REDRAW               6
#define HSHELL_TASKMAN              7
#define HSHELL_LANGUAGE             8
#endif /* WINVER >= 0x0400 */


/*
 * Message Structure used in Journaling
 */
typedef struct tagEVENTMSG {
    unsigned    message;
    unsigned    paramL;
    unsigned    paramH;
    unsigned long    time;
    HWND     hwnd;
} EVENTMSG, *PEVENTMSGMSG, NEAR *NPEVENTMSGMSG,  *LPEVENTMSGMSG;

typedef struct tagEVENTMSG *PEVENTMSG, NEAR *NPEVENTMSG,  *LPEVENTMSG;

/*
 * Message structure used by WH_CALLWNDPROC
 */
typedef struct tagCWPSTRUCT {
    LPARAM  lParam;
    WPARAM  wParam;
    unsigned    message;
    HWND    hwnd;
} CWPSTRUCT, *PCWPSTRUCT, NEAR *NPCWPSTRUCT,  *LPCWPSTRUCT;

#if(WINVER >= 0x0400)
/*
 * Message structure used by WH_CALLWNDPROCRET
 */
typedef struct tagCWPRETSTRUCT {
    LRESULT lResult;
    LPARAM  lParam;
    WPARAM  wParam;
    unsigned    message;
    HWND    hwnd;
} CWPRETSTRUCT, *PCWPRETSTRUCT, NEAR *NPCWPRETSTRUCT,  *LPCWPRETSTRUCT;
#endif /* WINVER >= 0x0400 */

/*
 * Structure used by WH_DEBUG
 */
typedef struct tagDEBUGHOOKINFO
{
    unsigned long   idThread;
    unsigned long   idThreadInstaller;
    LPARAM  lParam;
    WPARAM  wParam;
    int     code;
} DEBUGHOOKINFO, *PDEBUGHOOKINFO, NEAR *NPDEBUGHOOKINFO, * LPDEBUGHOOKINFO;

/*
 * Structure used by WH_MOUSE
 */
typedef struct tagMOUSEHOOKSTRUCT {
    POINT   pt;
    HWND    hwnd;
    unsigned    wHitTestCode;
    unsigned long   dwExtraInfo;
} MOUSEHOOKSTRUCT,  *LPMOUSEHOOKSTRUCT, *PMOUSEHOOKSTRUCT;
#if(WINVER >= 0x0400)
/*
 * Structure used by WH_HARDWARE
 */
typedef struct tagHARDWAREHOOKSTRUCT {
    HWND    hwnd;
    unsigned    message;
    WPARAM  wParam;
    LPARAM  lParam;
} HARDWAREHOOKSTRUCT,  *LPHARDWAREHOOKSTRUCT, *PHARDWAREHOOKSTRUCT;
#endif /* WINVER >= 0x0400 */
#endif /* !NOWH */

/*
 * Keyboard Layout API
 */
#define HKL_PREV            0
#define HKL_NEXT            1


#define KLF_ACTIVATE        0x00000001
#define KLF_SUBSTITUTE_OK   0x00000002
#define KLF_UNLOADPREVIOUS  0x00000004
#define KLF_REORDER         0x00000008
#if(WINVER >= 0x0400)
#define KLF_REPLACELANG     0x00000010
#define KLF_NOTELLSHELL     0x00000080
#endif /* WINVER >= 0x0400 */

/*
 * Size of KeyboardLayoutName (number of characters), including nul terminator
 */
#define KL_NAMELENGTH       9

/*WINUSERAPI*/
HKL
__stdcall
LoadKeyboardLayoutA(
    const char* pwszKLID,
    unsigned Flags);
/*WINUSERAPI*/
HKL
__stdcall
LoadKeyboardLayoutW(
    const wchar_t* pwszKLID,
    unsigned Flags);
#ifdef UNICODE
#define LoadKeyboardLayout  LoadKeyboardLayoutW
#else
#define LoadKeyboardLayout  LoadKeyboardLayoutA
#endif // !UNICODE


#if(WINVER >= 0x0400)
/*WINUSERAPI*/
HKL
__stdcall
ActivateKeyboardLayout(
    HKL hkl,
    unsigned Flags);
#else
/*WINUSERAPI*/
BOOL
__stdcall
ActivateKeyboardLayout(
    HKL hkl,
    unsigned Flags);
#endif /* WINVER >= 0x0400 */

#if(WINVER >= 0x0400)
/*WINUSERAPI*/
int
__stdcall
ToUnicodeEx(
    unsigned wVirtKey,
    unsigned wScanCode,
    PBYTE lpKeyState,
    wchar_t* pwszBuff,
    int cchBuff,
    unsigned wFlags,
    HKL dwhkl);
#endif /* WINVER >= 0x0400 */

/*WINUSERAPI*/
BOOL
__stdcall
UnloadKeyboardLayout(
    HKL hkl);

/*WINUSERAPI*/
BOOL
__stdcall
GetKeyboardLayoutNameA(
    char* pwszKLID);
/*WINUSERAPI*/
BOOL
__stdcall
GetKeyboardLayoutNameW(
    wchar_t* pwszKLID);
#ifdef UNICODE
#define GetKeyboardLayoutName  GetKeyboardLayoutNameW
#else
#define GetKeyboardLayoutName  GetKeyboardLayoutNameA
#endif // !UNICODE

#if(WINVER >= 0x0400)
/*WINUSERAPI*/
int
__stdcall
GetKeyboardLayoutList(
        int nBuff,
        HKL  *lpList);

/*WINUSERAPI*/
HKL
__stdcall
GetKeyboardLayout(
    unsigned long dwLayout
);
#endif /* WINVER >= 0x0400 */

#ifndef NODESKTOP
/*
 * Desktop-specific access flags
 */
#define DESKTOP_READOBJECTS         0x0001L
#define DESKTOP_CREATEWINDOW        0x0002L
#define DESKTOP_CREATEMENU          0x0004L
#define DESKTOP_HOOKCONTROL         0x0008L
#define DESKTOP_JOURNALRECORD       0x0010L
#define DESKTOP_JOURNALPLAYBACK     0x0020L
#define DESKTOP_ENUMERATE           0x0040L
#define DESKTOP_WRITEOBJECTS        0x0080L
#define DESKTOP_SWITCHDESKTOP       0x0100L

/*
 * Desktop-specific control flags
 */
#define DF_ALLOWOTHERACCOUNTHOOK    0x0001L

#ifdef _WINGDI_
#ifndef NOGDI

/*WINUSERAPI*/
HDESK
__stdcall
CreateDesktopA(
    char* lpszDesktop,
    char* lpszDevice,
    LPDEVMODEA pDevmode,
    unsigned long dwFlags,
    unsigned long dwDesiredAccess,
    LPSECURITY_ATTRIBUTES lpsa);
/*WINUSERAPI*/
HDESK
__stdcall
CreateDesktopW(
    wchar_t* lpszDesktop,
    wchar_t* lpszDevice,
    LPDEVMODEW pDevmode,
    unsigned long dwFlags,
    unsigned long dwDesiredAccess,
    LPSECURITY_ATTRIBUTES lpsa);
#ifdef UNICODE
#define CreateDesktop  CreateDesktopW
#else
#define CreateDesktop  CreateDesktopA
#endif // !UNICODE

#endif /* NOGDI */
#endif /* _WINGDI_ */

/*WINUSERAPI*/
HDESK
__stdcall
OpenDesktopA(
    char* lpszDesktop,
    unsigned long dwFlags,
    BOOL fInherit,
    unsigned long dwDesiredAccess);
/*WINUSERAPI*/
HDESK
__stdcall
OpenDesktopW(
    wchar_t* lpszDesktop,
    unsigned long dwFlags,
    BOOL fInherit,
    unsigned long dwDesiredAccess);
#ifdef UNICODE
#define OpenDesktop  OpenDesktopW
#else
#define OpenDesktop  OpenDesktopA
#endif // !UNICODE

/*WINUSERAPI*/
HDESK
__stdcall
OpenInputDesktop(
    unsigned long dwFlags,
    BOOL fInherit,
    unsigned long dwDesiredAccess);

/*WINUSERAPI*/
BOOL
__stdcall
EnumDesktopsA(
    HWINSTA hwinsta,
    DESKTOPENUMPROCA lpEnumFunc,
    LPARAM lParam);
/*WINUSERAPI*/
BOOL
__stdcall
EnumDesktopsW(
    HWINSTA hwinsta,
    DESKTOPENUMPROCW lpEnumFunc,
    LPARAM lParam);
#ifdef UNICODE
#define EnumDesktops  EnumDesktopsW
#else
#define EnumDesktops  EnumDesktopsA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
EnumDesktopWindows(
    HDESK hDesktop,
    WNDENUMPROC lpfn,
    LPARAM lParam);

/*WINUSERAPI*/
BOOL
__stdcall
SwitchDesktop(
    HDESK hDesktop);

/*WINUSERAPI*/
BOOL
__stdcall
SetThreadDesktop(
    HDESK hDesktop);

/*WINUSERAPI*/
BOOL
__stdcall
CloseDesktop(
    HDESK hDesktop);

/*WINUSERAPI*/
HDESK
__stdcall
GetThreadDesktop(
    unsigned long dwThreadId);

#endif  /* !NODESKTOP */

#ifndef NOWINDOWSTATION
/*
 * Windowstation-specific access flags
 */
#define WINSTA_ENUMDESKTOPS         0x0001L
#define WINSTA_READATTRIBUTES       0x0002L
#define WINSTA_ACCESSCLIPBOARD      0x0004L
#define WINSTA_CREATEDESKTOP        0x0008L
#define WINSTA_WRITEATTRIBUTES      0x0010L
#define WINSTA_ACCESSGLOBALATOMS    0x0020L
#define WINSTA_EXITWINDOWS          0x0040L
#define WINSTA_ENUMERATE            0x0100L
#define WINSTA_READSCREEN           0x0200L

/*
 * Windowstation-specific attribute flags
 */
#define WSF_VISIBLE                 0x0001L

/*WINUSERAPI*/
HWINSTA
__stdcall
CreateWindowStationA(
    char* lpwinsta,
    unsigned long dwReserved,
    unsigned long dwDesiredAccess,
    LPSECURITY_ATTRIBUTES lpsa);
/*WINUSERAPI*/
HWINSTA
__stdcall
CreateWindowStationW(
    wchar_t* lpwinsta,
    unsigned long dwReserved,
    unsigned long dwDesiredAccess,
    LPSECURITY_ATTRIBUTES lpsa);
#ifdef UNICODE
#define CreateWindowStation  CreateWindowStationW
#else
#define CreateWindowStation  CreateWindowStationA
#endif // !UNICODE

/*WINUSERAPI*/
HWINSTA
__stdcall
OpenWindowStationA(
    char* lpszWinSta,
    BOOL fInherit,
    unsigned long dwDesiredAccess);
/*WINUSERAPI*/
HWINSTA
__stdcall
OpenWindowStationW(
    wchar_t* lpszWinSta,
    BOOL fInherit,
    unsigned long dwDesiredAccess);
#ifdef UNICODE
#define OpenWindowStation  OpenWindowStationW
#else
#define OpenWindowStation  OpenWindowStationA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
EnumWindowStationsA(
    WINSTAENUMPROCA lpEnumFunc,
    LPARAM lParam);
/*WINUSERAPI*/
BOOL
__stdcall
EnumWindowStationsW(
    WINSTAENUMPROCW lpEnumFunc,
    LPARAM lParam);
#ifdef UNICODE
#define EnumWindowStations  EnumWindowStationsW
#else
#define EnumWindowStations  EnumWindowStationsA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
CloseWindowStation(
    HWINSTA hWinSta);

/*WINUSERAPI*/
BOOL
__stdcall
SetProcessWindowStation(
    HWINSTA hWinSta);

/*WINUSERAPI*/
HWINSTA
__stdcall
GetProcessWindowStation(
    VOID);
#endif  /* !NOWINDOWSTATION */

#ifndef NOSECURITY

/*WINUSERAPI*/
BOOL
__stdcall
SetUserObjectSecurity(
    HANDLE hObj,
    PSECURITY_INFORMATION pSIRequested,
    PSECURITY_DESCRIPTOR pSID);

/*WINUSERAPI*/
BOOL
__stdcall
GetUserObjectSecurity(
    HANDLE hObj,
    PSECURITY_INFORMATION pSIRequested,
    PSECURITY_DESCRIPTOR pSID,
    unsigned long nLength,
    unsigned long* lpnLengthNeeded);

#define UOI_FLAGS       1
#define UOI_NAME        2
#define UOI_TYPE        3
#define UOI_USER_SID    4

typedef struct tagUSEROBJECTFLAGS {
    BOOL fInherit;
    BOOL fReserved;
    unsigned long dwFlags;
} USEROBJECTFLAGS, *PUSEROBJECTFLAGS;

/*WINUSERAPI*/
BOOL
__stdcall
GetUserObjectInformationA(
    HANDLE hObj,
    int nIndex,
    void* pvInfo,
    unsigned long nLength,
    unsigned long* lpnLengthNeeded);
/*WINUSERAPI*/
BOOL
__stdcall
GetUserObjectInformationW(
    HANDLE hObj,
    int nIndex,
    void* pvInfo,
    unsigned long nLength,
    unsigned long* lpnLengthNeeded);
#ifdef UNICODE
#define GetUserObjectInformation  GetUserObjectInformationW
#else
#define GetUserObjectInformation  GetUserObjectInformationA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
SetUserObjectInformationA(
    HANDLE hObj,
    int nIndex,
    void* pvInfo,
    unsigned long nLength);
/*WINUSERAPI*/
BOOL
__stdcall
SetUserObjectInformationW(
    HANDLE hObj,
    int nIndex,
    void* pvInfo,
    unsigned long nLength);
#ifdef UNICODE
#define SetUserObjectInformation  SetUserObjectInformationW
#else
#define SetUserObjectInformation  SetUserObjectInformationA
#endif // !UNICODE

#endif  /* !NOSECURITY */

#if(WINVER >= 0x0400)
typedef struct tagWNDCLASSEXA {
    unsigned        cbSize;
    /* Win 3.x */
    unsigned        style;
    WNDPROC     lpfnWndProc;
    int         cbClsExtra;
    int         cbWndExtra;
    HINSTANCE   hInstance;
    HICON       hIcon;
    HCURSOR     hCursor;
    HBRUSH      hbrBackground;
    const char*      lpszMenuName;
    const char*      lpszClassName;
    /* Win 4.0 */
    HICON       hIconSm;
} WNDCLASSEXA, *PWNDCLASSEXA, NEAR *NPWNDCLASSEXA,  *LPWNDCLASSEXA;
typedef struct tagWNDCLASSEXW {
    unsigned        cbSize;
    /* Win 3.x */
    unsigned        style;
    WNDPROC     lpfnWndProc;
    int         cbClsExtra;
    int         cbWndExtra;
    HINSTANCE   hInstance;
    HICON       hIcon;
    HCURSOR     hCursor;
    HBRUSH      hbrBackground;
    const wchar_t*     lpszMenuName;
    const wchar_t*     lpszClassName;
    /* Win 4.0 */
    HICON       hIconSm;
} WNDCLASSEXW, *PWNDCLASSEXW, NEAR *NPWNDCLASSEXW,  *LPWNDCLASSEXW;
#ifdef UNICODE
typedef WNDCLASSEXW WNDCLASSEX;
typedef PWNDCLASSEXW PWNDCLASSEX;
typedef NPWNDCLASSEXW NPWNDCLASSEX;
typedef LPWNDCLASSEXW LPWNDCLASSEX;
#else
typedef WNDCLASSEXA WNDCLASSEX;
typedef PWNDCLASSEXA PWNDCLASSEX;
typedef NPWNDCLASSEXA NPWNDCLASSEX;
typedef LPWNDCLASSEXA LPWNDCLASSEX;
#endif // UNICODE
#endif /* WINVER >= 0x0400 */

typedef struct tagWNDCLASSA {
    unsigned        style;
    WNDPROC     lpfnWndProc;
    int         cbClsExtra;
    int         cbWndExtra;
    HINSTANCE   hInstance;
    HICON       hIcon;
    HCURSOR     hCursor;
    HBRUSH      hbrBackground;
    const char*      lpszMenuName;
    const char*      lpszClassName;
} WNDCLASSA, *PWNDCLASSA, NEAR *NPWNDCLASSA,  *LPWNDCLASSA;
typedef struct tagWNDCLASSW {
    unsigned        style;
    WNDPROC     lpfnWndProc;
    int         cbClsExtra;
    int         cbWndExtra;
    HINSTANCE   hInstance;
    HICON       hIcon;
    HCURSOR     hCursor;
    HBRUSH      hbrBackground;
    const wchar_t*     lpszMenuName;
    const wchar_t*     lpszClassName;
} WNDCLASSW, *PWNDCLASSW, NEAR *NPWNDCLASSW,  *LPWNDCLASSW;
#ifdef UNICODE
typedef WNDCLASSW WNDCLASS;
typedef PWNDCLASSW PWNDCLASS;
typedef NPWNDCLASSW NPWNDCLASS;
typedef LPWNDCLASSW LPWNDCLASS;
#else
typedef WNDCLASSA WNDCLASS;
typedef PWNDCLASSA PWNDCLASS;
typedef NPWNDCLASSA NPWNDCLASS;
typedef LPWNDCLASSA LPWNDCLASS;
#endif // UNICODE



#ifndef NOMSG

/*
 * Message structure
 */
typedef struct tagMSG {
    HWND        hwnd;
    unsigned        message;
    WPARAM      wParam;
    LPARAM      lParam;
    unsigned long       time;
    POINT       pt;
} MSG, *PMSG, NEAR *NPMSG,  *LPMSG;

#define POINTSTOPOINT(pt, pts)                          \
        { (pt).x = (long)(SHORT)LOWORD(*(long*)&pts);   \
          (pt).y = (long)(SHORT)HIWORD(*(long*)&pts); }

#define POINTTOPOINTS(pt)      (MAKELONG((short)((pt).x), (short)((pt).y)))
#define MAKEWPARAM(l, h)      (WPARAM)MAKELONG(l, h)
#define MAKELPARAM(l, h)      (LPARAM)MAKELONG(l, h)
#define MAKELRESULT(l, h)     (LRESULT)MAKELONG(l, h)


#endif /* !NOMSG */

#ifndef NOWINOFFSETS

/*
 * Window field offsets for GetWindowLong()
 */
#define GWL_WNDPROC         (-4)
#define GWL_HINSTANCE       (-6)
#define GWL_HWNDPARENT      (-8)
#define GWL_STYLE           (-16)
#define GWL_EXSTYLE         (-20)
#define GWL_USERDATA        (-21)
#define GWL_ID              (-12)

/*
 * Class field offsets for GetClassLong()
 */
#define GCL_MENUNAME        (-8)
#define GCL_HBRBACKGROUND   (-10)
#define GCL_HCURSOR         (-12)
#define GCL_HICON           (-14)
#define GCL_HMODULE         (-16)
#define GCL_CBWNDEXTRA      (-18)
#define GCL_CBCLSEXTRA      (-20)
#define GCL_WNDPROC         (-24)
#define GCL_STYLE           (-26)
#define GCW_ATOM            (-32)

#if(WINVER >= 0x0400)
#define GCL_HICONSM         (-34)
#endif /* WINVER >= 0x0400 */

#endif /* !NOWINOFFSETS */

#ifndef NOWINMESSAGES

// begin_r_winuser

/*
 * Window Messages
 */

#define WM_NULL                         0x0000
#define WM_CREATE                       0x0001
#define WM_DESTROY                      0x0002
#define WM_MOVE                         0x0003
#define WM_SIZE                         0x0005

#define WM_ACTIVATE                     0x0006
/*
 * WM_ACTIVATE state values
 */
#define     WA_INACTIVE     0
#define     WA_ACTIVE       1
#define     WA_CLICKACTIVE  2

#define WM_SETFOCUS                     0x0007
#define WM_KILLFOCUS                    0x0008
#define WM_ENABLE                       0x000A
#define WM_SETREDRAW                    0x000B
#define WM_SETTEXT                      0x000C
#define WM_GETTEXT                      0x000D
#define WM_GETTEXTLENGTH                0x000E
#define WM_PAINT                        0x000F
#define WM_CLOSE                        0x0010
#define WM_QUERYENDSESSION              0x0011
#define WM_QUIT                         0x0012
#define WM_QUERYOPEN                    0x0013
#define WM_ERASEBKGND                   0x0014
#define WM_SYSCOLORCHANGE               0x0015
#define WM_ENDSESSION                   0x0016
#define WM_SHOWWINDOW                   0x0018
#define WM_WININICHANGE                 0x001A
#if(WINVER >= 0x0400)
#define WM_SETTINGCHANGE                WM_WININICHANGE
#endif /* WINVER >= 0x0400 */


#define WM_DEVMODECHANGE                0x001B
#define WM_ACTIVATEAPP                  0x001C
#define WM_FONTCHANGE                   0x001D
#define WM_TIMECHANGE                   0x001E
#define WM_CANCELMODE                   0x001F
#define WM_SETCURSOR                    0x0020
#define WM_MOUSEACTIVATE                0x0021
#define WM_CHILDACTIVATE                0x0022
#define WM_QUEUESYNC                    0x0023

#define WM_GETMINMAXINFO                0x0024
// end_r_winuser
/*
 * Struct pointed to by WM_GETMINMAXINFO lParam
 */
typedef struct tagMINMAXINFO {
    POINT ptReserved;
    POINT ptMaxSize;
    POINT ptMaxPosition;
    POINT ptMinTrackSize;
    POINT ptMaxTrackSize;
} MINMAXINFO, *PMINMAXINFO, *LPMINMAXINFO;

// begin_r_winuser
#define WM_PAINTICON                    0x0026
#define WM_ICONERASEBKGND               0x0027
#define WM_NEXTDLGCTL                   0x0028
#define WM_SPOOLERSTATUS                0x002A
#define WM_DRAWITEM                     0x002B
#define WM_MEASUREITEM                  0x002C
#define WM_DELETEITEM                   0x002D
#define WM_VKEYTOITEM                   0x002E
#define WM_CHARTOITEM                   0x002F
#define WM_SETFONT                      0x0030
#define WM_GETFONT                      0x0031
#define WM_SETHOTKEY                    0x0032
#define WM_GETHOTKEY                    0x0033
#define WM_QUERYDRAGICON                0x0037
#define WM_COMPAREITEM                  0x0039

#define WM_COMPACTING                   0x0041
#define WM_COMMNOTIFY                   0x0044  /* no longer suported */
#define WM_WINDOWPOSCHANGING            0x0046
#define WM_WINDOWPOSCHANGED             0x0047

#define WM_POWER                        0x0048
/*
 * wParam for WM_POWER window message and DRV_POWER driver notification
 */
#define PWR_OK              1
#define PWR_FAIL            (-1)
#define PWR_SUSPENDREQUEST  1
#define PWR_SUSPENDRESUME   2
#define PWR_CRITICALRESUME  3

#define WM_COPYDATA                     0x004A
#define WM_CANCELJOURNAL                0x004B

// end_r_winuser

/*
 * lParam of WM_COPYDATA message points to...
 */
typedef struct tagCOPYDATASTRUCT {
    unsigned long dwData;
    unsigned long cbData;
    void* lpData;
} COPYDATASTRUCT, *PCOPYDATASTRUCT;

// begin_r_winuser

#if(WINVER >= 0x0400)
#define WM_NOTIFY                       0x004E
#define WM_INPUTLANGCHANGEREQUEST       0x0050
#define WM_INPUTLANGCHANGE              0x0051
#define WM_TCARD                        0x0052
#define WM_HELP                         0x0053
#define WM_USERCHANGED                  0x0054
#define WM_NOTIFYFORMAT                 0x0055

#define NFR_ANSI                             1
#define NFR_UNICODE                          2
#define NF_QUERY                             3
#define NF_REQUERY                           4

#define WM_CONTEXTMENU                  0x007B
#define WM_STYLECHANGING                0x007C
#define WM_STYLECHANGED                 0x007D
#define WM_DISPLAYCHANGE                0x007E
#define WM_GETICON                      0x007F
#define WM_SETICON                      0x0080
#endif /* WINVER >= 0x0400 */


#define WM_NCCREATE                     0x0081
#define WM_NCDESTROY                    0x0082
#define WM_NCCALCSIZE                   0x0083
#define WM_NCHITTEST                    0x0084
#define WM_NCPAINT                      0x0085
#define WM_NCACTIVATE                   0x0086
#define WM_GETDLGCODE                   0x0087

#define WM_NCMOUSEMOVE                  0x00A0
#define WM_NCLBUTTONDOWN                0x00A1
#define WM_NCLBUTTONUP                  0x00A2
#define WM_NCLBUTTONDBLCLK              0x00A3
#define WM_NCRBUTTONDOWN                0x00A4
#define WM_NCRBUTTONUP                  0x00A5
#define WM_NCRBUTTONDBLCLK              0x00A6
#define WM_NCMBUTTONDOWN                0x00A7
#define WM_NCMBUTTONUP                  0x00A8
#define WM_NCMBUTTONDBLCLK              0x00A9

#define WM_KEYFIRST                     0x0100
#define WM_KEYDOWN                      0x0100
#define WM_KEYUP                        0x0101
#define WM_CHAR                         0x0102
#define WM_DEADCHAR                     0x0103
#define WM_SYSKEYDOWN                   0x0104
#define WM_SYSKEYUP                     0x0105
#define WM_SYSCHAR                      0x0106
#define WM_SYSDEADCHAR                  0x0107
#define WM_KEYLAST                      0x0108

#if(WINVER >= 0x0400)
#define WM_IME_STARTCOMPOSITION         0x010D
#define WM_IME_ENDCOMPOSITION           0x010E
#define WM_IME_COMPOSITION              0x010F
#define WM_IME_KEYLAST                  0x010F
#endif /* WINVER >= 0x0400 */

#define WM_INITDIALOG                   0x0110
#define WM_COMMAND                      0x0111
#define WM_SYSCOMMAND                   0x0112
#define WM_TIMER                        0x0113
#define WM_HSCROLL                      0x0114
#define WM_VSCROLL                      0x0115
#define WM_INITMENU                     0x0116
#define WM_INITMENUPOPUP                0x0117
#define WM_MENUSELECT                   0x011F
#define WM_MENUCHAR                     0x0120
#define WM_ENTERIDLE                    0x0121

#define WM_CTLCOLORMSGBOX               0x0132
#define WM_CTLCOLOREDIT                 0x0133
#define WM_CTLCOLORLISTBOX              0x0134
#define WM_CTLCOLORBTN                  0x0135
#define WM_CTLCOLORDLG                  0x0136
#define WM_CTLCOLORSCROLLBAR            0x0137
#define WM_CTLCOLORSTATIC               0x0138



#define WM_MOUSEFIRST                   0x0200
#define WM_MOUSEMOVE                    0x0200
#define WM_LBUTTONDOWN                  0x0201
#define WM_LBUTTONUP                    0x0202
#define WM_LBUTTONDBLCLK                0x0203
#define WM_RBUTTONDOWN                  0x0204
#define WM_RBUTTONUP                    0x0205
#define WM_RBUTTONDBLCLK                0x0206
#define WM_MBUTTONDOWN                  0x0207
#define WM_MBUTTONUP                    0x0208
#define WM_MBUTTONDBLCLK                0x0209
#if(_WIN32_WINNT >= 0x0400)
#define WM_MOUSEWHEEL                   0x020A
#endif /* _WIN32_WINNT >= 0x0400 */
#if (_WIN32_WINNT < 0x0400)
#define WM_MOUSELAST                    0x0209
#else
#define WM_MOUSELAST                    0x020A
#endif /* if (_WIN32_WINNT < 0x0400) */

#if(_WIN32_WINNT >= 0x0400)
#define WHEEL_DELTA                     120     /* Value for rolling one detent */
#endif /* _WIN32_WINNT >= 0x0400 */
#if(_WIN32_WINNT >= 0x0400)
#define WHEEL_PAGESCROLL                (UINT_MAX) /* Scroll one page */
#endif /* _WIN32_WINNT >= 0x0400 */

#define WM_PARENTNOTIFY                 0x0210
#define MENULOOP_WINDOW                 0
#define MENULOOP_POPUP                  1
#define WM_ENTERMENULOOP                0x0211
#define WM_EXITMENULOOP                 0x0212

#if(WINVER >= 0x0400)
#define WM_NEXTMENU                     0x0213
// end_r_winuser

typedef struct tagMDINEXTMENU
{
    HMENU   hmenuIn;
    HMENU   hmenuNext;
    HWND    hwndNext;
} MDINEXTMENU, * PMDINEXTMENU,  * LPMDINEXTMENU;

// begin_r_winuser
#define WM_SIZING                       0x0214
#define WM_CAPTURECHANGED               0x0215
#define WM_MOVING                       0x0216
#define WM_POWERBROADCAST               0x0218
#define WM_DEVICECHANGE                 0x0219

#define WM_IME_SETCONTEXT               0x0281
#define WM_IME_NOTIFY                   0x0282
#define WM_IME_CONTROL                  0x0283
#define WM_IME_COMPOSITIONFULL          0x0284
#define WM_IME_SELECT                   0x0285
#define WM_IME_CHAR                     0x0286
#define WM_IME_KEYDOWN                  0x0290
#define WM_IME_KEYUP                    0x0291
#endif /* WINVER >= 0x0400 */

#define WM_MDICREATE                    0x0220
#define WM_MDIDESTROY                   0x0221
#define WM_MDIACTIVATE                  0x0222
#define WM_MDIRESTORE                   0x0223
#define WM_MDINEXT                      0x0224
#define WM_MDIMAXIMIZE                  0x0225
#define WM_MDITILE                      0x0226
#define WM_MDICASCADE                   0x0227
#define WM_MDIICONARRANGE               0x0228
#define WM_MDIGETACTIVE                 0x0229



#define WM_MDISETMENU                   0x0230
#define WM_ENTERSIZEMOVE                0x0231
#define WM_EXITSIZEMOVE                 0x0232
#define WM_DROPFILES                    0x0233
#define WM_MDIREFRESHMENU               0x0234


#if(_WIN32_WINNT >= 0x0400)
#define WM_MOUSEHOVER                   0x02A1
#define WM_MOUSELEAVE                   0x02A3
#endif /* _WIN32_WINNT >= 0x0400 */

#define WM_CUT                          0x0300
#define WM_COPY                         0x0301
#define WM_PASTE                        0x0302
#define WM_CLEAR                        0x0303
#define WM_UNDO                         0x0304
#define WM_RENDERFORMAT                 0x0305
#define WM_RENDERALLFORMATS             0x0306
#define WM_DESTROYCLIPBOARD             0x0307
#define WM_DRAWCLIPBOARD                0x0308
#define WM_PAINTCLIPBOARD               0x0309
#define WM_VSCROLLCLIPBOARD             0x030A
#define WM_SIZECLIPBOARD                0x030B
#define WM_ASKCBFORMATNAME              0x030C
#define WM_CHANGECBCHAIN                0x030D
#define WM_HSCROLLCLIPBOARD             0x030E
#define WM_QUERYNEWPALETTE              0x030F
#define WM_PALETTEISCHANGING            0x0310
#define WM_PALETTECHANGED               0x0311
#define WM_HOTKEY                       0x0312

#if(WINVER >= 0x0400)
#define WM_PRINT                        0x0317
#define WM_PRINTCLIENT                  0x0318

#define WM_HANDHELDFIRST                0x0358
#define WM_HANDHELDLAST                 0x035F

#define WM_AFXFIRST                     0x0360
#define WM_AFXLAST                      0x037F
#endif /* WINVER >= 0x0400 */

#define WM_PENWINFIRST                  0x0380
#define WM_PENWINLAST                   0x038F




#if(WINVER >= 0x0400)
#define WM_APP                          0x8000
#endif /* WINVER >= 0x0400 */






/*
 * NOTE: All Message Numbers below 0x0400 are RESERVED.
 *
 * Private Window Messages Start Here:
 */
#define WM_USER                         0x0400

#if(WINVER >= 0x0400)

/*  wParam for WM_SIZING message  */
#define WMSZ_LEFT           1
#define WMSZ_RIGHT          2
#define WMSZ_TOP            3
#define WMSZ_TOPLEFT        4
#define WMSZ_TOPRIGHT       5
#define WMSZ_BOTTOM         6
#define WMSZ_BOTTOMLEFT     7
#define WMSZ_BOTTOMRIGHT    8
#endif /* WINVER >= 0x0400 */

#ifndef NONCMESSAGES

/*
 * WM_SYNCTASK Commands
 */
#define ST_BEGINSWP         0
#define ST_ENDSWP           1

/*
 * WM_NCHITTEST and MOUSEHOOKSTRUCT Mouse Position Codes
 */
#define HTERROR             (-2)
#define HTTRANSPARENT       (-1)
#define HTNOWHERE           0
#define HTCLIENT            1
#define HTCAPTION           2
#define HTSYSMENU           3
#define HTGROWBOX           4
#define HTSIZE              HTGROWBOX
#define HTMENU              5
#define HTHSCROLL           6
#define HTVSCROLL           7
#define HTMINBUTTON         8
#define HTMAXBUTTON         9
#define HTLEFT              10
#define HTRIGHT             11
#define HTTOP               12
#define HTTOPLEFT           13
#define HTTOPRIGHT          14
#define HTBOTTOM            15
#define HTBOTTOMLEFT        16
#define HTBOTTOMRIGHT       17
#define HTBORDER            18
#define HTREDUCE            HTMINBUTTON
#define HTZOOM              HTMAXBUTTON
#define HTSIZEFIRST         HTLEFT
#define HTSIZELAST          HTBOTTOMRIGHT
#if(WINVER >= 0x0400)
#define HTOBJECT            19
#define HTCLOSE             20
#define HTHELP              21
#endif /* WINVER >= 0x0400 */

/*
 * SendMessageTimeout values
 */
#define SMTO_NORMAL         0x0000
#define SMTO_BLOCK          0x0001
#define SMTO_ABORTIFHUNG    0x0002

#endif /* !NONCMESSAGES */

/*
 * WM_MOUSEACTIVATE Return Codes
 */
#define MA_ACTIVATE         1
#define MA_ACTIVATEANDEAT   2
#define MA_NOACTIVATE       3
#define MA_NOACTIVATEANDEAT 4

/*
 * WM_SETICON / WM_GETICON Type Codes
 */
#define ICON_SMALL          0
#define ICON_BIG            1

// end_r_winuser

/*WINUSERAPI*/
unsigned
__stdcall
RegisterWindowMessageA(
    const char* lpString);
/*WINUSERAPI*/
unsigned
__stdcall
RegisterWindowMessageW(
    const wchar_t* lpString);
#ifdef UNICODE
#define RegisterWindowMessage  RegisterWindowMessageW
#else
#define RegisterWindowMessage  RegisterWindowMessageA
#endif // !UNICODE

// begin_r_winuser

/*
 * WM_SIZE message wParam values
 */
#define SIZE_RESTORED       0
#define SIZE_MINIMIZED      1
#define SIZE_MAXIMIZED      2
#define SIZE_MAXSHOW        3
#define SIZE_MAXHIDE        4

/*
 * Obsolete constant names
 */
#define SIZENORMAL          SIZE_RESTORED
#define SIZEICONIC          SIZE_MINIMIZED
#define SIZEFULLSCREEN      SIZE_MAXIMIZED
#define SIZEZOOMSHOW        SIZE_MAXSHOW
#define SIZEZOOMHIDE        SIZE_MAXHIDE

// end_r_winuser
/*
 * WM_WINDOWPOSCHANGING/CHANGED struct pointed to by lParam
 */
typedef struct tagWINDOWPOS {
    HWND    hwnd;
    HWND    hwndInsertAfter;
    int     x;
    int     y;
    int     cx;
    int     cy;
    unsigned    flags;
} WINDOWPOS, *LPWINDOWPOS, *PWINDOWPOS;

/*
 * WM_NCCALCSIZE parameter structure
 */
typedef struct tagNCCALCSIZE_PARAMS {
    RECT       rgrc[3];
    PWINDOWPOS lppos;
} NCCALCSIZE_PARAMS, *LPNCCALCSIZE_PARAMS;

// begin_r_winuser
/*
 * WM_NCCALCSIZE "window valid rect" return values
 */
#define WVR_ALIGNTOP        0x0010
#define WVR_ALIGNLEFT       0x0020
#define WVR_ALIGNBOTTOM     0x0040
#define WVR_ALIGNRIGHT      0x0080
#define WVR_HREDRAW         0x0100
#define WVR_VREDRAW         0x0200
#define WVR_REDRAW         (WVR_HREDRAW | \
                            WVR_VREDRAW)
#define WVR_VALIDRECTS      0x0400


#ifndef NOKEYSTATES

/*
 * Key State Masks for Mouse Messages
 */
#define MK_LBUTTON          0x0001
#define MK_RBUTTON          0x0002
#define MK_SHIFT            0x0004
#define MK_CONTROL          0x0008
#define MK_MBUTTON          0x0010

#endif /* !NOKEYSTATES */

#if(_WIN32_WINNT >= 0x0400)
#ifndef NOTRACKMOUSEEVENT

#define TME_HOVER       0x00000001
#define TME_LEAVE       0x00000002
#define TME_QUERY       0x40000000
#define TME_CANCEL      0x80000000


#define HOVER_DEFAULT   0xFFFFFFFF
// end_r_winuser

typedef struct tagTRACKMOUSEEVENT {
    unsigned long cbSize;
    unsigned long dwFlags;
    HWND  hwndTrack;
    unsigned long dwHoverTime;
} TRACKMOUSEEVENT, *LPTRACKMOUSEEVENT;

/*WINUSERAPI*/
BOOL
__stdcall
TrackMouseEvent(
    LPTRACKMOUSEEVENT lpEventTrack);

// begin_r_winuser

#endif /* !NOTRACKMOUSEEVENT */
#endif /* _WIN32_WINNT >= 0x0400 */

// end_r_winuser

#endif /* !NOWINMESSAGES */

#ifndef NOWINSTYLES

// begin_r_winuser

/*
 * Window Styles
 */
#define WS_OVERLAPPED       0x00000000L
#define WS_POPUP            0x80000000L
#define WS_CHILD            0x40000000L
#define WS_MINIMIZE         0x20000000L
#define WS_VISIBLE          0x10000000L
#define WS_DISABLED         0x08000000L
#define WS_CLIPSIBLINGS     0x04000000L
#define WS_CLIPCHILDREN     0x02000000L
#define WS_MAXIMIZE         0x01000000L
#define WS_CAPTION          0x00C00000L     /* WS_BORDER | WS_DLGFRAME  */
#define WS_BORDER           0x00800000L
#define WS_DLGFRAME         0x00400000L
#define WS_VSCROLL          0x00200000L
#define WS_HSCROLL          0x00100000L
#define WS_SYSMENU          0x00080000L
#define WS_THICKFRAME       0x00040000L
#define WS_GROUP            0x00020000L
#define WS_TABSTOP          0x00010000L

#define WS_MINIMIZEBOX      0x00020000L
#define WS_MAXIMIZEBOX      0x00010000L

#define WS_TILED            WS_OVERLAPPED
#define WS_ICONIC           WS_MINIMIZE
#define WS_SIZEBOX          WS_THICKFRAME
#define WS_TILEDWINDOW      WS_OVERLAPPEDWINDOW

/*
 * Common Window Styles
 */
#define WS_OVERLAPPEDWINDOW (WS_OVERLAPPED     | \
                             WS_CAPTION        | \
                             WS_SYSMENU        | \
                             WS_THICKFRAME     | \
                             WS_MINIMIZEBOX    | \
                             WS_MAXIMIZEBOX)

#define WS_POPUPWINDOW      (WS_POPUP          | \
                             WS_BORDER         | \
                             WS_SYSMENU)

#define WS_CHILDWINDOW      (WS_CHILD)

/*
 * Extended Window Styles
 */
#define WS_EX_DLGMODALFRAME     0x00000001L
#define WS_EX_NOPARENTNOTIFY    0x00000004L
#define WS_EX_TOPMOST           0x00000008L
#define WS_EX_ACCEPTFILES       0x00000010L
#define WS_EX_TRANSPARENT       0x00000020L
#if(WINVER >= 0x0400)
#define WS_EX_MDICHILD          0x00000040L
#define WS_EX_TOOLWINDOW        0x00000080L
#define WS_EX_WINDOWEDGE        0x00000100L
#define WS_EX_CLIENTEDGE        0x00000200L
#define WS_EX_CONTEXTHELP       0x00000400L

#define WS_EX_RIGHT             0x00001000L
#define WS_EX_LEFT              0x00000000L
#define WS_EX_RTLREADING        0x00002000L
#define WS_EX_LTRREADING        0x00000000L
#define WS_EX_LEFTSCROLLBAR     0x00004000L
#define WS_EX_RIGHTSCROLLBAR    0x00000000L

#define WS_EX_CONTROLPARENT     0x00010000L
#define WS_EX_STATICEDGE        0x00020000L
#define WS_EX_APPWINDOW         0x00040000L


#define WS_EX_OVERLAPPEDWINDOW  (WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE)
#define WS_EX_PALETTEWINDOW     (WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW | WS_EX_TOPMOST)

#endif /* WINVER >= 0x0400 */



/*
 * Class styles
 */
#define CS_VREDRAW          0x0001
#define CS_HREDRAW          0x0002
#define CS_KEYCVTWINDOW     0x0004
#define CS_DBLCLKS          0x0008
#define CS_OWNDC            0x0020
#define CS_CLASSDC          0x0040
#define CS_PARENTDC         0x0080
#define CS_NOKEYCVT         0x0100
#define CS_NOCLOSE          0x0200
#define CS_SAVEBITS         0x0800
#define CS_BYTEALIGNCLIENT  0x1000
#define CS_BYTEALIGNWINDOW  0x2000
#define CS_GLOBALCLASS      0x4000

#if(WINVER >= 0x0400)
#define CS_IME              0x00010000
#endif /* WINVER >= 0x0400 */


// end_r_winuser

#endif /* !NOWINSTYLES */
#if(WINVER >= 0x0400)
/* WM_PRINT flags */
#define PRF_CHECKVISIBLE    0x00000001L
#define PRF_NONCLIENT       0x00000002L
#define PRF_CLIENT          0x00000004L
#define PRF_ERASEBKGND      0x00000008L
#define PRF_CHILDREN        0x00000010L
#define PRF_OWNED           0x00000020L

/* 3D border styles */
#define BDR_RAISEDOUTER 0x0001
#define BDR_SUNKENOUTER 0x0002
#define BDR_RAISEDINNER 0x0004
#define BDR_SUNKENINNER 0x0008

#define BDR_OUTER       0x0003
#define BDR_INNER       0x000c
#define BDR_RAISED      0x0005
#define BDR_SUNKEN      0x000a


#define EDGE_RAISED     (BDR_RAISEDOUTER | BDR_RAISEDINNER)
#define EDGE_SUNKEN     (BDR_SUNKENOUTER | BDR_SUNKENINNER)
#define EDGE_ETCHED     (BDR_SUNKENOUTER | BDR_RAISEDINNER)
#define EDGE_BUMP       (BDR_RAISEDOUTER | BDR_SUNKENINNER)

/* Border flags */
#define BF_LEFT         0x0001
#define BF_TOP          0x0002
#define BF_RIGHT        0x0004
#define BF_BOTTOM       0x0008

#define BF_TOPLEFT      (BF_TOP | BF_LEFT)
#define BF_TOPRIGHT     (BF_TOP | BF_RIGHT)
#define BF_BOTTOMLEFT   (BF_BOTTOM | BF_LEFT)
#define BF_BOTTOMRIGHT  (BF_BOTTOM | BF_RIGHT)
#define BF_RECT         (BF_LEFT | BF_TOP | BF_RIGHT | BF_BOTTOM)

#define BF_DIAGONAL     0x0010

// For diagonal lines, the BF_RECT flags specify the end point of the
// vector bounded by the rectangle parameter.
#define BF_DIAGONAL_ENDTOPRIGHT     (BF_DIAGONAL | BF_TOP | BF_RIGHT)
#define BF_DIAGONAL_ENDTOPLEFT      (BF_DIAGONAL | BF_TOP | BF_LEFT)
#define BF_DIAGONAL_ENDBOTTOMLEFT   (BF_DIAGONAL | BF_BOTTOM | BF_LEFT)
#define BF_DIAGONAL_ENDBOTTOMRIGHT  (BF_DIAGONAL | BF_BOTTOM | BF_RIGHT)


#define BF_MIDDLE       0x0800  /* Fill in the middle */
#define BF_SOFT         0x1000  /* For softer buttons */
#define BF_ADJUST       0x2000  /* Calculate the space left over */
#define BF_FLAT         0x4000  /* For flat rather than 3D borders */
#define BF_MONO         0x8000  /* For monochrome borders */


/*WINUSERAPI*/ BOOL __stdcall DrawEdge(HDC hdc, RECT* qrc, unsigned edge, unsigned grfFlags);

/* flags for DrawFrameControl */

#define DFC_CAPTION             1
#define DFC_MENU                2
#define DFC_SCROLL              3
#define DFC_BUTTON              4

#define DFCS_CAPTIONCLOSE       0x0000
#define DFCS_CAPTIONMIN         0x0001
#define DFCS_CAPTIONMAX         0x0002
#define DFCS_CAPTIONRESTORE     0x0003
#define DFCS_CAPTIONHELP        0x0004

#define DFCS_MENUARROW          0x0000
#define DFCS_MENUCHECK          0x0001
#define DFCS_MENUBULLET         0x0002
#define DFCS_MENUARROWRIGHT     0x0004

#define DFCS_SCROLLUP           0x0000
#define DFCS_SCROLLDOWN         0x0001
#define DFCS_SCROLLLEFT         0x0002
#define DFCS_SCROLLRIGHT        0x0003
#define DFCS_SCROLLCOMBOBOX     0x0005
#define DFCS_SCROLLSIZEGRIP     0x0008
#define DFCS_SCROLLSIZEGRIPRIGHT 0x0010

#define DFCS_BUTTONCHECK        0x0000
#define DFCS_BUTTONRADIOIMAGE   0x0001
#define DFCS_BUTTONRADIOMASK    0x0002
#define DFCS_BUTTONRADIO        0x0004
#define DFCS_BUTTON3STATE       0x0008
#define DFCS_BUTTONPUSH         0x0010

#define DFCS_INACTIVE           0x0100
#define DFCS_PUSHED             0x0200
#define DFCS_CHECKED            0x0400
#define DFCS_ADJUSTRECT         0x2000
#define DFCS_FLAT               0x4000
#define DFCS_MONO               0x8000

/*WINUSERAPI*/ BOOL    __stdcall DrawFrameControl(HDC, RECT*, unsigned, unsigned);


/* flags for DrawCaption */
#define DC_ACTIVE           0x0001
#define DC_SMALLCAP         0x0002
#define DC_ICON             0x0004
#define DC_TEXT             0x0008
#define DC_INBUTTON         0x0010

/*WINUSERAPI*/ BOOL    __stdcall DrawCaption(HWND, HDC, const RECT *, unsigned);

#define IDANI_OPEN          1
#define IDANI_CLOSE         2
#define IDANI_CAPTION       3


/*WINUSERAPI*/ BOOL    __stdcall DrawAnimatedRects(HWND hwnd, int idAni, const RECT * lprcFrom, const RECT * lprcTo);

#endif /* WINVER >= 0x0400 */

#ifndef NOCLIPBOARD

// begin_r_winuser

/*
 * Predefined Clipboard Formats
 */
#define CF_TEXT             1
#define CF_BITMAP           2
#define CF_METAFILEPICT     3
#define CF_SYLK             4
#define CF_DIF              5
#define CF_TIFF             6
#define CF_OEMTEXT          7
#define CF_DIB              8
#define CF_PALETTE          9
#define CF_PENDATA          10
#define CF_RIFF             11
#define CF_WAVE             12
#define CF_UNICODETEXT      13
#define CF_ENHMETAFILE      14
#if(WINVER >= 0x0400)
#define CF_HDROP            15
#define CF_LOCALE           16
#define CF_MAX              17
#endif /* WINVER >= 0x0400 */

#define CF_OWNERDISPLAY     0x0080
#define CF_DSPTEXT          0x0081
#define CF_DSPBITMAP        0x0082
#define CF_DSPMETAFILEPICT  0x0083
#define CF_DSPENHMETAFILE   0x008E

/*
 * "Private" formats don't get GlobalFree()'d
 */
#define CF_PRIVATEFIRST     0x0200
#define CF_PRIVATELAST      0x02FF

/*
 * "GDIOBJ" formats do get DeleteObject()'d
 */
#define CF_GDIOBJFIRST      0x0300
#define CF_GDIOBJLAST       0x03FF

// end_r_winuser

#endif /* !NOCLIPBOARD */

/*
 * Defines for the fVirt field of the Accelerator table structure.
 */
#define FVIRTKEY  TRUE          /* Assumed to be == TRUE */
#define FNOINVERT 0x02
#define FSHIFT    0x04
#define FCONTROL  0x08
#define FALT      0x10

typedef struct tagACCEL {
    BYTE   fVirt;               /* Also called the flags field */
    WORD   key;
    WORD   cmd;
} ACCEL, *LPACCEL;

typedef struct tagPAINTSTRUCT {
    HDC         hdc;
    BOOL        fErase;
    RECT        rcPaint;
    BOOL        fRestore;
    BOOL        fIncUpdate;
    BYTE        rgbReserved[32];
} PAINTSTRUCT, *PPAINTSTRUCT, *NPPAINTSTRUCT, *LPPAINTSTRUCT;

typedef struct tagCREATESTRUCTA {
    void*      lpCreateParams;
    HINSTANCE   hInstance;
    HMENU       hMenu;
    HWND        hwndParent;
    int         cy;
    int         cx;
    int         y;
    int         x;
    long        style;
    const char*      lpszName;
    const char*      lpszClass;
    unsigned long       dwExStyle;
} CREATESTRUCTA, *LPCREATESTRUCTA;
typedef struct tagCREATESTRUCTW {
    void*      lpCreateParams;
    HINSTANCE   hInstance;
    HMENU       hMenu;
    HWND        hwndParent;
    int         cy;
    int         cx;
    int         y;
    int         x;
    long        style;
    const wchar_t*     lpszName;
    const wchar_t*     lpszClass;
    unsigned long       dwExStyle;
} CREATESTRUCTW, *LPCREATESTRUCTW;
#ifdef UNICODE
typedef CREATESTRUCTW CREATESTRUCT;
typedef LPCREATESTRUCTW LPCREATESTRUCT;
#else
typedef CREATESTRUCTA CREATESTRUCT;
typedef LPCREATESTRUCTA LPCREATESTRUCT;
#endif // UNICODE

typedef struct tagWINDOWPLACEMENT {
    unsigned  length;
    unsigned  flags;
    unsigned  showCmd;
    POINT ptMinPosition;
    POINT ptMaxPosition;
    RECT  rcNormalPosition;
} WINDOWPLACEMENT;
typedef WINDOWPLACEMENT *PWINDOWPLACEMENT, *LPWINDOWPLACEMENT;

#define WPF_SETMINPOSITION      0x0001
#define WPF_RESTORETOMAXIMIZED  0x0002
#if(WINVER >= 0x0400)
typedef struct tagNMHDR
{
    HWND  hwndFrom;
    unsigned  idFrom;
    unsigned  code;         // NM_ code
}   NMHDR;
typedef NMHDR  * LPNMHDR;

typedef struct tagSTYLESTRUCT
{
    unsigned long   styleOld;
    unsigned long   styleNew;
} STYLESTRUCT, * LPSTYLESTRUCT;
#endif /* WINVER >= 0x0400 */


/*
 * Owner draw control types
 */
#define ODT_MENU        1
#define ODT_LISTBOX     2
#define ODT_COMBOBOX    3
#define ODT_BUTTON      4
#if(WINVER >= 0x0400)
#define ODT_STATIC      5
#endif /* WINVER >= 0x0400 */

/*
 * Owner draw actions
 */
#define ODA_DRAWENTIRE  0x0001
#define ODA_SELECT      0x0002
#define ODA_FOCUS       0x0004

/*
 * Owner draw state
 */
#define ODS_SELECTED    0x0001
#define ODS_GRAYED      0x0002
#define ODS_DISABLED    0x0004
#define ODS_CHECKED     0x0008
#define ODS_FOCUS       0x0010
#if(WINVER >= 0x0400)
#define ODS_DEFAULT         0x0020
#define ODS_COMBOBOXEDIT    0x1000
#endif /* WINVER >= 0x0400 */

/*
 * MEASUREITEMSTRUCT for ownerdraw
 */
typedef struct tagMEASUREITEMSTRUCT {
    unsigned       CtlType;
    unsigned       CtlID;
    unsigned       itemID;
    unsigned       itemWidth;
    unsigned       itemHeight;
    unsigned long      itemData;
} MEASUREITEMSTRUCT, NEAR *PMEASUREITEMSTRUCT,  *LPMEASUREITEMSTRUCT;



/*
 * DRAWITEMSTRUCT for ownerdraw
 */
typedef struct tagDRAWITEMSTRUCT {
    unsigned        CtlType;
    unsigned        CtlID;
    unsigned        itemID;
    unsigned        itemAction;
    unsigned        itemState;
    HWND        hwndItem;
    HDC         hDC;
    RECT        rcItem;
    unsigned long       itemData;
} DRAWITEMSTRUCT, NEAR *PDRAWITEMSTRUCT,  *LPDRAWITEMSTRUCT;

/*
 * DELETEITEMSTRUCT for ownerdraw
 */
typedef struct tagDELETEITEMSTRUCT {
    unsigned       CtlType;
    unsigned       CtlID;
    unsigned       itemID;
    HWND       hwndItem;
    unsigned       itemData;
} DELETEITEMSTRUCT, NEAR *PDELETEITEMSTRUCT,  *LPDELETEITEMSTRUCT;

/*
 * COMPAREITEMSTUCT for ownerdraw sorting
 */
typedef struct tagCOMPAREITEMSTRUCT {
    unsigned        CtlType;
    unsigned        CtlID;
    HWND        hwndItem;
    unsigned        itemID1;
    unsigned long       itemData1;
    unsigned        itemID2;
    unsigned long       itemData2;
    unsigned long       dwLocaleId;
} COMPAREITEMSTRUCT, NEAR *PCOMPAREITEMSTRUCT,  *LPCOMPAREITEMSTRUCT;

#ifndef NOMSG

/*
 * Message Function Templates
 */

/*WINUSERAPI*/
BOOL
__stdcall
GetMessageA(
    LPMSG lpMsg,
    HWND hWnd ,
    unsigned wMsgFilterMin,
    unsigned wMsgFilterMax);
/*WINUSERAPI*/
BOOL
__stdcall
GetMessageW(
    LPMSG lpMsg,
    HWND hWnd ,
    unsigned wMsgFilterMin,
    unsigned wMsgFilterMax);
#ifdef UNICODE
#define GetMessage  GetMessageW
#else
#define GetMessage  GetMessageA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
TranslateMessage(
    const MSG *lpMsg);

/*WINUSERAPI*/
long
__stdcall
DispatchMessageA(
    const MSG *lpMsg);
/*WINUSERAPI*/
long
__stdcall
DispatchMessageW(
    const MSG *lpMsg);
#ifdef UNICODE
#define DispatchMessage  DispatchMessageW
#else
#define DispatchMessage  DispatchMessageA
#endif // !UNICODE


/*WINUSERAPI*/
BOOL
__stdcall
SetMessageQueue(
    int cMessagesMax);

/*WINUSERAPI*/
BOOL
__stdcall
PeekMessageA(
    LPMSG lpMsg,
    HWND hWnd ,
    unsigned wMsgFilterMin,
    unsigned wMsgFilterMax,
    unsigned wRemoveMsg);
/*WINUSERAPI*/
BOOL
__stdcall
PeekMessageW(
    LPMSG lpMsg,
    HWND hWnd ,
    unsigned wMsgFilterMin,
    unsigned wMsgFilterMax,
    unsigned wRemoveMsg);
#ifdef UNICODE
#define PeekMessage  PeekMessageW
#else
#define PeekMessage  PeekMessageA
#endif // !UNICODE

/*
 * PeekMessage() Options
 */
#define PM_NOREMOVE         0x0000
#define PM_REMOVE           0x0001
#define PM_NOYIELD          0x0002

#endif /* !NOMSG */

/*WINUSERAPI*/
BOOL
__stdcall
RegisterHotKey(
    HWND hWnd ,
    int id,
    unsigned fsModifiers,
    unsigned vk);

/*WINUSERAPI*/
BOOL
__stdcall
UnregisterHotKey(
    HWND hWnd,
    int id);

#define MOD_ALT         0x0001
#define MOD_CONTROL     0x0002
#define MOD_SHIFT       0x0004
#define MOD_WIN         0x0008


#define IDHOT_SNAPWINDOW        (-1)    /* SHIFT-PRINTSCRN  */
#define IDHOT_SNAPDESKTOP       (-2)    /* PRINTSCRN        */

#ifdef WIN_INTERNAL
    #ifndef LSTRING
    #define NOLSTRING
    #endif /* LSTRING */
    #ifndef LFILEIO
    #define NOLFILEIO
    #endif /* LFILEIO */
#endif /* WIN_INTERNAL */

#if(WINVER >= 0x0400)
#define EW_RESTARTWINDOWS    0x0042L
#define EW_REBOOTSYSTEM      0x0043L
#define EW_EXITANDEXECAPP    0x0044L

#define ENDSESSION_LOGOFF    0x80000000
#endif /* WINVER >= 0x0400 */

#define EWX_LOGOFF   0
#define EWX_SHUTDOWN 1
#define EWX_REBOOT   2
#define EWX_FORCE    4
#define EWX_POWEROFF 8


#define ExitWindows(dwReserved, Code) ExitWindowsEx(EWX_LOGOFF, 0xFFFFFFFF)

/*WINUSERAPI*/
BOOL
__stdcall
ExitWindowsEx(
    unsigned uFlags,
    unsigned long dwReserved);

/*WINUSERAPI*/
BOOL
__stdcall
SwapMouseButton(
    BOOL fSwap);

/*WINUSERAPI*/
unsigned long
__stdcall
GetMessagePos(
    VOID);

/*WINUSERAPI*/
long
__stdcall
GetMessageTime(
    VOID);

/*WINUSERAPI*/
long
__stdcall
GetMessageExtraInfo(
    VOID);

#if(WINVER >= 0x0400)
/*WINUSERAPI*/
LPARAM
__stdcall
SetMessageExtraInfo(
    LPARAM lParam);
#endif /* WINVER >= 0x0400 */

/*WINUSERAPI*/
LRESULT
__stdcall
SendMessageA(
    HWND hWnd,
    unsigned Msg,
    WPARAM wParam,
    LPARAM lParam);
/*WINUSERAPI*/
LRESULT
__stdcall
SendMessageW(
    HWND hWnd,
    unsigned Msg,
    WPARAM wParam,
    LPARAM lParam);
#ifdef UNICODE
#define SendMessage  SendMessageW
#else
#define SendMessage  SendMessageA
#endif // !UNICODE

/*WINUSERAPI*/
LRESULT
__stdcall
SendMessageTimeoutA(
    HWND hWnd,
    unsigned Msg,
    WPARAM wParam,
    LPARAM lParam,
    unsigned fuFlags,
    unsigned uTimeout,
    unsigned long* lpdwResult);
/*WINUSERAPI*/
LRESULT
__stdcall
SendMessageTimeoutW(
    HWND hWnd,
    unsigned Msg,
    WPARAM wParam,
    LPARAM lParam,
    unsigned fuFlags,
    unsigned uTimeout,
    unsigned long* lpdwResult);
#ifdef UNICODE
#define SendMessageTimeout  SendMessageTimeoutW
#else
#define SendMessageTimeout  SendMessageTimeoutA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
SendNotifyMessageA(
    HWND hWnd,
    unsigned Msg,
    WPARAM wParam,
    LPARAM lParam);
/*WINUSERAPI*/
BOOL
__stdcall
SendNotifyMessageW(
    HWND hWnd,
    unsigned Msg,
    WPARAM wParam,
    LPARAM lParam);
#ifdef UNICODE
#define SendNotifyMessage  SendNotifyMessageW
#else
#define SendNotifyMessage  SendNotifyMessageA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
SendMessageCallbackA(
    HWND hWnd,
    unsigned Msg,
    WPARAM wParam,
    LPARAM lParam,
    SENDASYNCPROC lpResultCallBack,
    unsigned long dwData);
/*WINUSERAPI*/
BOOL
__stdcall
SendMessageCallbackW(
    HWND hWnd,
    unsigned Msg,
    WPARAM wParam,
    LPARAM lParam,
    SENDASYNCPROC lpResultCallBack,
    unsigned long dwData);
#ifdef UNICODE
#define SendMessageCallback  SendMessageCallbackW
#else
#define SendMessageCallback  SendMessageCallbackA
#endif // !UNICODE

#if(WINVER >= 0x0400)
/*WINUSERAPI*/ long  __stdcall  BroadcastSystemMessageA(unsigned long, unsigned long*, unsigned, WPARAM, LPARAM);
/*WINUSERAPI*/ long  __stdcall  BroadcastSystemMessageW(unsigned long, unsigned long*, unsigned, WPARAM, LPARAM);
#ifdef UNICODE
#define BroadcastSystemMessage  BroadcastSystemMessageW
#else
#define BroadcastSystemMessage  BroadcastSystemMessageA
#endif // !UNICODE
//Broadcast Special Message Recipient list
#define BSM_ALLCOMPONENTS       0x00000000
#define BSM_VXDS                0x00000001
#define BSM_NETDRIVER           0x00000002
#define BSM_INSTALLABLEDRIVERS  0x00000004
#define BSM_APPLICATIONS        0x00000008
#define BSM_ALLDESKTOPS         0x00000010

//Broadcast Special Message Flags
#define BSF_QUERY               0x00000001
#define BSF_IGNORECURRENTTASK   0x00000002
#define BSF_FLUSHDISK           0x00000004
#define BSF_NOHANG              0x00000008
#define BSF_POSTMESSAGE         0x00000010
#define BSF_FORCEIFHUNG         0x00000020
#define BSF_NOTIMEOUTIFNOTHUNG  0x00000040

typedef struct tagBROADCASTSYSMSG
{
    unsigned    uiMessage;
    WPARAM  wParam;
    LPARAM  lParam;
} BROADCASTSYSMSG;
typedef BROADCASTSYSMSG   *LPBROADCASTSYSMSG;

#define BROADCAST_QUERY_DENY         0x424D5144  // Return this value to deny a query.
#endif /* WINVER >= 0x0400 */

/*WINUSERAPI*/
BOOL
__stdcall
PostMessageA(
    HWND hWnd,
    unsigned Msg,
    WPARAM wParam,
    LPARAM lParam);
/*WINUSERAPI*/
BOOL
__stdcall
PostMessageW(
    HWND hWnd,
    unsigned Msg,
    WPARAM wParam,
    LPARAM lParam);
#ifdef UNICODE
#define PostMessage  PostMessageW
#else
#define PostMessage  PostMessageA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
PostThreadMessageA(
    unsigned long idThread,
    unsigned Msg,
    WPARAM wParam,
    LPARAM lParam);
/*WINUSERAPI*/
BOOL
__stdcall
PostThreadMessageW(
    unsigned long idThread,
    unsigned Msg,
    WPARAM wParam,
    LPARAM lParam);
#ifdef UNICODE
#define PostThreadMessage  PostThreadMessageW
#else
#define PostThreadMessage  PostThreadMessageA
#endif // !UNICODE

#define PostAppMessageA(idThread, wMsg, wParam, lParam)\
        PostThreadMessageA((unsigned long)idThread, wMsg, wParam, lParam)
#define PostAppMessageW(idThread, wMsg, wParam, lParam)\
        PostThreadMessageW((unsigned long)idThread, wMsg, wParam, lParam)
#ifdef UNICODE
#define PostAppMessage  PostAppMessageW
#else
#define PostAppMessage  PostAppMessageA
#endif // !UNICODE

/*
 * Special HWND value for use with PostMessage() and SendMessage()
 */
#define HWND_BROADCAST  ((HWND)0xffff)

/*WINUSERAPI*/
BOOL
__stdcall
AttachThreadInput(
    unsigned long idAttach,
    unsigned long idAttachTo,
    BOOL fAttach);


/*WINUSERAPI*/
BOOL
__stdcall
ReplyMessage(
    LRESULT lResult);

/*WINUSERAPI*/
BOOL
__stdcall
WaitMessage(
    VOID);

/*WINUSERAPI*/
unsigned long
__stdcall
WaitForInputIdle(
    HANDLE hProcess,
    unsigned long dwMilliseconds);

/*WINUSERAPI*/
LRESULT
__stdcall
DefWindowProcA(
    HWND hWnd,
    unsigned Msg,
    WPARAM wParam,
    LPARAM lParam);
/*WINUSERAPI*/
LRESULT
__stdcall
DefWindowProcW(
    HWND hWnd,
    unsigned Msg,
    WPARAM wParam,
    LPARAM lParam);
#ifdef UNICODE
#define DefWindowProc  DefWindowProcW
#else
#define DefWindowProc  DefWindowProcA
#endif // !UNICODE

/*WINUSERAPI*/
VOID
__stdcall
PostQuitMessage(
    int nExitCode);

#ifdef STRICT

/*WINUSERAPI*/
LRESULT
__stdcall
CallWindowProcA(
    WNDPROC lpPrevWndFunc,
    HWND hWnd,
    unsigned Msg,
    WPARAM wParam,
    LPARAM lParam);
/*WINUSERAPI*/
LRESULT
__stdcall
CallWindowProcW(
    WNDPROC lpPrevWndFunc,
    HWND hWnd,
    unsigned Msg,
    WPARAM wParam,
    LPARAM lParam);
#ifdef UNICODE
#define CallWindowProc  CallWindowProcW
#else
#define CallWindowProc  CallWindowProcA
#endif // !UNICODE

#else /* !STRICT */

/*WINUSERAPI*/
LRESULT
__stdcall
CallWindowProcA(
    FARPROC lpPrevWndFunc,
    HWND hWnd,
    unsigned Msg,
    WPARAM wParam,
    LPARAM lParam);
/*WINUSERAPI*/
LRESULT
__stdcall
CallWindowProcW(
    FARPROC lpPrevWndFunc,
    HWND hWnd,
    unsigned Msg,
    WPARAM wParam,
    LPARAM lParam);
#ifdef UNICODE
#define CallWindowProc  CallWindowProcW
#else
#define CallWindowProc  CallWindowProcA
#endif // !UNICODE

#endif /* !STRICT */

/*WINUSERAPI*/
BOOL
__stdcall
InSendMessage(
    VOID);

/*WINUSERAPI*/
unsigned
__stdcall
GetDoubleClickTime(
    VOID);

/*WINUSERAPI*/
BOOL
__stdcall
SetDoubleClickTime(
    unsigned);

/*WINUSERAPI*/
ATOM
__stdcall
RegisterClassA(
    const WNDCLASSA *lpWndClass);
/*WINUSERAPI*/
ATOM
__stdcall
RegisterClassW(
    const WNDCLASSW *lpWndClass);
#ifdef UNICODE
#define RegisterClass  RegisterClassW
#else
#define RegisterClass  RegisterClassA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
UnregisterClassA(
    const char* lpClassName,
    HINSTANCE hInstance);
/*WINUSERAPI*/
BOOL
__stdcall
UnregisterClassW(
    const wchar_t* lpClassName,
    HINSTANCE hInstance);
#ifdef UNICODE
#define UnregisterClass  UnregisterClassW
#else
#define UnregisterClass  UnregisterClassA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
GetClassInfoA(
    HINSTANCE hInstance ,
    const char* lpClassName,
    LPWNDCLASSA lpWndClass);
/*WINUSERAPI*/
BOOL
__stdcall
GetClassInfoW(
    HINSTANCE hInstance ,
    const wchar_t* lpClassName,
    LPWNDCLASSW lpWndClass);
#ifdef UNICODE
#define GetClassInfo  GetClassInfoW
#else
#define GetClassInfo  GetClassInfoA
#endif // !UNICODE

#if(WINVER >= 0x0400)
/*WINUSERAPI*/
ATOM
__stdcall
RegisterClassExA(const WNDCLASSEXA *);
/*WINUSERAPI*/
ATOM
__stdcall
RegisterClassExW(const WNDCLASSEXW *);
#ifdef UNICODE
#define RegisterClassEx  RegisterClassExW
#else
#define RegisterClassEx  RegisterClassExA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
GetClassInfoExA(HINSTANCE, const char*, LPWNDCLASSEXA);
/*WINUSERAPI*/
BOOL
__stdcall
GetClassInfoExW(HINSTANCE, const wchar_t*, LPWNDCLASSEXW);
#ifdef UNICODE
#define GetClassInfoEx  GetClassInfoExW
#else
#define GetClassInfoEx  GetClassInfoExA
#endif // !UNICODE

#endif /* WINVER >= 0x0400 */

#define CW_USEDEFAULT       ((int)0x80000000)

/*
 * Special value for CreateWindow, et al.
 */
#define HWND_DESKTOP        ((HWND)0)

/*WINUSERAPI*/
HWND
__stdcall
CreateWindowExA(
    unsigned long dwExStyle,
    const char* lpClassName,
    const char* lpWindowName,
    unsigned long dwStyle,
    int X,
    int Y,
    int nWidth,
    int nHeight,
    HWND hWndParent ,
    HMENU hMenu,
    HINSTANCE hInstance,
    void* lpParam);
/*WINUSERAPI*/
HWND
__stdcall
CreateWindowExW(
    unsigned long dwExStyle,
    const wchar_t* lpClassName,
    const wchar_t* lpWindowName,
    unsigned long dwStyle,
    int X,
    int Y,
    int nWidth,
    int nHeight,
    HWND hWndParent ,
    HMENU hMenu,
    HINSTANCE hInstance,
    void* lpParam);
#ifdef UNICODE
#define CreateWindowEx  CreateWindowExW
#else
#define CreateWindowEx  CreateWindowExA
#endif // !UNICODE

#define CreateWindowA(lpClassName, lpWindowName, dwStyle, x, y,\
nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)\
CreateWindowExA(0L, lpClassName, lpWindowName, dwStyle, x, y,\
nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)
#define CreateWindowW(lpClassName, lpWindowName, dwStyle, x, y,\
nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)\
CreateWindowExW(0L, lpClassName, lpWindowName, dwStyle, x, y,\
nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)
#ifdef UNICODE
#define CreateWindow  CreateWindowW
#else
#define CreateWindow  CreateWindowA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
IsWindow(
    HWND hWnd);

/*WINUSERAPI*/
BOOL
__stdcall
IsMenu(
    HMENU hMenu);

/*WINUSERAPI*/
BOOL
__stdcall
IsChild(
    HWND hWndParent,
    HWND hWnd);

/*WINUSERAPI*/
BOOL
__stdcall
DestroyWindow(
    HWND hWnd);

/*WINUSERAPI*/
BOOL
__stdcall
ShowWindow(
    HWND hWnd,
    int nCmdShow);

#if(WINVER >= 0x0400)
/*WINUSERAPI*/
BOOL
__stdcall
ShowWindowAsync(
    HWND hWnd,
    int nCmdShow);
#endif /* WINVER >= 0x0400 */

/*WINUSERAPI*/
BOOL
__stdcall
FlashWindow(
    HWND hWnd,
    BOOL bInvert);

/*WINUSERAPI*/
BOOL
__stdcall
ShowOwnedPopups(
    HWND hWnd,
    BOOL fShow);

/*WINUSERAPI*/
BOOL
__stdcall
OpenIcon(
    HWND hWnd);

/*WINUSERAPI*/
BOOL
__stdcall
CloseWindow(
    HWND hWnd);

/*WINUSERAPI*/
BOOL
__stdcall
MoveWindow(
    HWND hWnd,
    int X,
    int Y,
    int nWidth,
    int nHeight,
    BOOL bRepaint);

/*WINUSERAPI*/
BOOL
__stdcall
SetWindowPos(
    HWND hWnd,
    HWND hWndInsertAfter ,
    int X,
    int Y,
    int cx,
    int cy,
    unsigned uFlags);

/*WINUSERAPI*/
BOOL
__stdcall
GetWindowPlacement(
    HWND hWnd,
    WINDOWPLACEMENT *lpwndpl);

/*WINUSERAPI*/
BOOL
__stdcall
SetWindowPlacement(
    HWND hWnd,
    const WINDOWPLACEMENT *lpwndpl);


#ifndef NODEFERWINDOWPOS

/*WINUSERAPI*/
HDWP
__stdcall
BeginDeferWindowPos(
    int nNumWindows);

/*WINUSERAPI*/
HDWP
__stdcall
DeferWindowPos(
    HDWP hWinPosInfo,
    HWND hWnd,
    HWND hWndInsertAfter ,
    int x,
    int y,
    int cx,
    int cy,
    unsigned uFlags);

/*WINUSERAPI*/
BOOL
__stdcall
EndDeferWindowPos(
    HDWP hWinPosInfo);

#endif /* !NODEFERWINDOWPOS */

/*WINUSERAPI*/
BOOL
__stdcall
IsWindowVisible(
    HWND hWnd);

/*WINUSERAPI*/
BOOL
__stdcall
IsIconic(
    HWND hWnd);

/*WINUSERAPI*/
BOOL
__stdcall
AnyPopup(
    VOID);

/*WINUSERAPI*/
BOOL
__stdcall
BringWindowToTop(
    HWND hWnd);

/*WINUSERAPI*/
BOOL
__stdcall
IsZoomed(
    HWND hWnd);

/*
 * SetWindowPos Flags
 */
#define SWP_NOSIZE          0x0001
#define SWP_NOMOVE          0x0002
#define SWP_NOZORDER        0x0004
#define SWP_NOREDRAW        0x0008
#define SWP_NOACTIVATE      0x0010
#define SWP_FRAMECHANGED    0x0020  /* The frame changed: send WM_NCCALCSIZE */
#define SWP_SHOWWINDOW      0x0040
#define SWP_HIDEWINDOW      0x0080
#define SWP_NOCOPYBITS      0x0100
#define SWP_NOOWNERZORDER   0x0200  /* Don't do owner Z ordering */
#define SWP_NOSENDCHANGING  0x0400  /* Don't send WM_WINDOWPOSCHANGING */

#define SWP_DRAWFRAME       SWP_FRAMECHANGED
#define SWP_NOREPOSITION    SWP_NOOWNERZORDER

#if(WINVER >= 0x0400)
#define SWP_DEFERERASE      0x2000
#define SWP_ASYNCWINDOWPOS  0x4000
#endif /* WINVER >= 0x0400 */


#define HWND_TOP        ((HWND)0)
#define HWND_BOTTOM     ((HWND)1)
#define HWND_TOPMOST    ((HWND)-1)
#define HWND_NOTOPMOST  ((HWND)-2)


#ifndef NOCTLMGR

/*
 * WARNING:
 * The following structures must NOT be unsigned long padded because they are
 * followed by strings, etc that do not have to be unsigned long aligned.
 */
#include <pshpack2.h>

/*
 * original NT 32 bit dialog template:
 */
typedef struct {
    unsigned long style;
    unsigned long dwExtendedStyle;
    WORD cdit;
    short x;
    short y;
    short cx;
    short cy;
} DLGTEMPLATE;
typedef DLGTEMPLATE *LPDLGTEMPLATEA;
typedef DLGTEMPLATE *LPDLGTEMPLATEW;
#ifdef UNICODE
typedef LPDLGTEMPLATEW LPDLGTEMPLATE;
#else
typedef LPDLGTEMPLATEA LPDLGTEMPLATE;
#endif // UNICODE
typedef const DLGTEMPLATE *LPCDLGTEMPLATEA;
typedef const DLGTEMPLATE *LPCDLGTEMPLATEW;
#ifdef UNICODE
typedef LPCDLGTEMPLATEW LPCDLGTEMPLATE;
#else
typedef LPCDLGTEMPLATEA LPCDLGTEMPLATE;
#endif // UNICODE

/*
 * 32 bit Dialog item template.
 */
typedef struct {
    unsigned long style;
    unsigned long dwExtendedStyle;
    short x;
    short y;
    short cx;
    short cy;
    WORD id;
} DLGITEMTEMPLATE;
typedef DLGITEMTEMPLATE *PDLGITEMTEMPLATEA;
typedef DLGITEMTEMPLATE *PDLGITEMTEMPLATEW;
#ifdef UNICODE
typedef PDLGITEMTEMPLATEW PDLGITEMTEMPLATE;
#else
typedef PDLGITEMTEMPLATEA PDLGITEMTEMPLATE;
#endif // UNICODE
typedef DLGITEMTEMPLATE *LPDLGITEMTEMPLATEA;
typedef DLGITEMTEMPLATE *LPDLGITEMTEMPLATEW;
#ifdef UNICODE
typedef LPDLGITEMTEMPLATEW LPDLGITEMTEMPLATE;
#else
typedef LPDLGITEMTEMPLATEA LPDLGITEMTEMPLATE;
#endif // UNICODE


#include <poppack.h> /* Resume normal packing */

/*WINUSERAPI*/
HWND
__stdcall
CreateDialogParamA(
    HINSTANCE hInstance,
    const char* lpTemplateName,
    HWND hWndParent ,
    DLGPROC lpDialogFunc,
    LPARAM dwInitParam);
/*WINUSERAPI*/
HWND
__stdcall
CreateDialogParamW(
    HINSTANCE hInstance,
    const wchar_t* lpTemplateName,
    HWND hWndParent ,
    DLGPROC lpDialogFunc,
    LPARAM dwInitParam);
#ifdef UNICODE
#define CreateDialogParam  CreateDialogParamW
#else
#define CreateDialogParam  CreateDialogParamA
#endif // !UNICODE

/*WINUSERAPI*/
HWND
__stdcall
CreateDialogIndirectParamA(
    HINSTANCE hInstance,
    LPCDLGTEMPLATEA lpTemplate,
    HWND hWndParent,
    DLGPROC lpDialogFunc,
    LPARAM dwInitParam);
/*WINUSERAPI*/
HWND
__stdcall
CreateDialogIndirectParamW(
    HINSTANCE hInstance,
    LPCDLGTEMPLATEW lpTemplate,
    HWND hWndParent,
    DLGPROC lpDialogFunc,
    LPARAM dwInitParam);
#ifdef UNICODE
#define CreateDialogIndirectParam  CreateDialogIndirectParamW
#else
#define CreateDialogIndirectParam  CreateDialogIndirectParamA
#endif // !UNICODE

#define CreateDialogA(hInstance, lpName, hWndParent, lpDialogFunc) \
CreateDialogParamA(hInstance, lpName, hWndParent, lpDialogFunc, 0L)
#define CreateDialogW(hInstance, lpName, hWndParent, lpDialogFunc) \
CreateDialogParamW(hInstance, lpName, hWndParent, lpDialogFunc, 0L)
#ifdef UNICODE
#define CreateDialog  CreateDialogW
#else
#define CreateDialog  CreateDialogA
#endif // !UNICODE

#define CreateDialogIndirectA(hInstance, lpTemplate, hWndParent, lpDialogFunc) \
CreateDialogIndirectParamA(hInstance, lpTemplate, hWndParent, lpDialogFunc, 0L)
#define CreateDialogIndirectW(hInstance, lpTemplate, hWndParent, lpDialogFunc) \
CreateDialogIndirectParamW(hInstance, lpTemplate, hWndParent, lpDialogFunc, 0L)
#ifdef UNICODE
#define CreateDialogIndirect  CreateDialogIndirectW
#else
#define CreateDialogIndirect  CreateDialogIndirectA
#endif // !UNICODE

/*WINUSERAPI*/
int
__stdcall
DialogBoxParamA(
    HINSTANCE hInstance,
    const char* lpTemplateName,
    HWND hWndParent ,
    DLGPROC lpDialogFunc,
    LPARAM dwInitParam);
/*WINUSERAPI*/
int
__stdcall
DialogBoxParamW(
    HINSTANCE hInstance,
    const wchar_t* lpTemplateName,
    HWND hWndParent ,
    DLGPROC lpDialogFunc,
    LPARAM dwInitParam);
#ifdef UNICODE
#define DialogBoxParam  DialogBoxParamW
#else
#define DialogBoxParam  DialogBoxParamA
#endif // !UNICODE

/*WINUSERAPI*/
int
__stdcall
DialogBoxIndirectParamA(
    HINSTANCE hInstance,
    LPCDLGTEMPLATEA hDialogTemplate,
    HWND hWndParent ,
    DLGPROC lpDialogFunc,
    LPARAM dwInitParam);
/*WINUSERAPI*/
int
__stdcall
DialogBoxIndirectParamW(
    HINSTANCE hInstance,
    LPCDLGTEMPLATEW hDialogTemplate,
    HWND hWndParent ,
    DLGPROC lpDialogFunc,
    LPARAM dwInitParam);
#ifdef UNICODE
#define DialogBoxIndirectParam  DialogBoxIndirectParamW
#else
#define DialogBoxIndirectParam  DialogBoxIndirectParamA
#endif // !UNICODE

#define DialogBoxA(hInstance, lpTemplate, hWndParent, lpDialogFunc) \
DialogBoxParamA(hInstance, lpTemplate, hWndParent, lpDialogFunc, 0L)
#define DialogBoxW(hInstance, lpTemplate, hWndParent, lpDialogFunc) \
DialogBoxParamW(hInstance, lpTemplate, hWndParent, lpDialogFunc, 0L)
#ifdef UNICODE
#define DialogBox  DialogBoxW
#else
#define DialogBox  DialogBoxA
#endif // !UNICODE

#define DialogBoxIndirectA(hInstance, lpTemplate, hWndParent, lpDialogFunc) \
DialogBoxIndirectParamA(hInstance, lpTemplate, hWndParent, lpDialogFunc, 0L)
#define DialogBoxIndirectW(hInstance, lpTemplate, hWndParent, lpDialogFunc) \
DialogBoxIndirectParamW(hInstance, lpTemplate, hWndParent, lpDialogFunc, 0L)
#ifdef UNICODE
#define DialogBoxIndirect  DialogBoxIndirectW
#else
#define DialogBoxIndirect  DialogBoxIndirectA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
EndDialog(
    HWND hDlg,
    int nResult);

/*WINUSERAPI*/
HWND
__stdcall
GetDlgItem(
    HWND hDlg,
    int nIDDlgItem);

/*WINUSERAPI*/
BOOL
__stdcall
SetDlgItemInt(
    HWND hDlg,
    int nIDDlgItem,
    unsigned uValue,
    BOOL bSigned);

/*WINUSERAPI*/
unsigned
__stdcall
GetDlgItemInt(
    HWND hDlg,
    int nIDDlgItem,
    BOOL *lpTranslated,
    BOOL bSigned);

/*WINUSERAPI*/
BOOL
__stdcall
SetDlgItemTextA(
    HWND hDlg,
    int nIDDlgItem,
    const char* lpString);
/*WINUSERAPI*/
BOOL
__stdcall
SetDlgItemTextW(
    HWND hDlg,
    int nIDDlgItem,
    const wchar_t* lpString);
#ifdef UNICODE
#define SetDlgItemText  SetDlgItemTextW
#else
#define SetDlgItemText  SetDlgItemTextA
#endif // !UNICODE

/*WINUSERAPI*/
unsigned
__stdcall
GetDlgItemTextA(
    HWND hDlg,
    int nIDDlgItem,
    char* lpString,
    int nMaxCount);
/*WINUSERAPI*/
unsigned
__stdcall
GetDlgItemTextW(
    HWND hDlg,
    int nIDDlgItem,
    wchar_t* lpString,
    int nMaxCount);
#ifdef UNICODE
#define GetDlgItemText  GetDlgItemTextW
#else
#define GetDlgItemText  GetDlgItemTextA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
CheckDlgButton(
    HWND hDlg,
    int nIDButton,
    unsigned uCheck);

/*WINUSERAPI*/
BOOL
__stdcall
CheckRadioButton(
    HWND hDlg,
    int nIDFirstButton,
    int nIDLastButton,
    int nIDCheckButton);

/*WINUSERAPI*/
unsigned
__stdcall
IsDlgButtonChecked(
    HWND hDlg,
    int nIDButton);

/*WINUSERAPI*/
long
__stdcall
SendDlgItemMessageA(
    HWND hDlg,
    int nIDDlgItem,
    unsigned Msg,
    WPARAM wParam,
    LPARAM lParam);
/*WINUSERAPI*/
long
__stdcall
SendDlgItemMessageW(
    HWND hDlg,
    int nIDDlgItem,
    unsigned Msg,
    WPARAM wParam,
    LPARAM lParam);
#ifdef UNICODE
#define SendDlgItemMessage  SendDlgItemMessageW
#else
#define SendDlgItemMessage  SendDlgItemMessageA
#endif // !UNICODE

/*WINUSERAPI*/
HWND
__stdcall
GetNextDlgGroupItem(
    HWND hDlg,
    HWND hCtl,
    BOOL bPrevious);

/*WINUSERAPI*/
HWND
__stdcall
GetNextDlgTabItem(
    HWND hDlg,
    HWND hCtl,
    BOOL bPrevious);

/*WINUSERAPI*/
int
__stdcall
GetDlgCtrlID(
    HWND hWnd);

/*WINUSERAPI*/
long
__stdcall
GetDialogBaseUnits(VOID);

/*WINUSERAPI*/
LRESULT
__stdcall
DefDlgProcA(
    HWND hDlg,
    unsigned Msg,
    WPARAM wParam,
    LPARAM lParam);
/*WINUSERAPI*/
LRESULT
__stdcall
DefDlgProcW(
    HWND hDlg,
    unsigned Msg,
    WPARAM wParam,
    LPARAM lParam);
#ifdef UNICODE
#define DefDlgProc  DefDlgProcW
#else
#define DefDlgProc  DefDlgProcA
#endif // !UNICODE

/*
 * Window extra byted needed for private dialog classes.
 */
#define DLGWINDOWEXTRA 30

#endif /* !NOCTLMGR */

#ifndef NOMSG

/*WINUSERAPI*/
BOOL
__stdcall
CallMsgFilterA(
    LPMSG lpMsg,
    int nCode);
/*WINUSERAPI*/
BOOL
__stdcall
CallMsgFilterW(
    LPMSG lpMsg,
    int nCode);
#ifdef UNICODE
#define CallMsgFilter  CallMsgFilterW
#else
#define CallMsgFilter  CallMsgFilterA
#endif // !UNICODE

#endif /* !NOMSG */

#ifndef NOCLIPBOARD

/*
 * Clipboard Manager Functions
 */

/*WINUSERAPI*/
BOOL
__stdcall
OpenClipboard(
    HWND hWndNewOwner);

/*WINUSERAPI*/
BOOL
__stdcall
CloseClipboard(
    VOID);

/*WINUSERAPI*/
HWND
__stdcall
GetClipboardOwner(
    VOID);

/*WINUSERAPI*/
HWND
__stdcall
SetClipboardViewer(
    HWND hWndNewViewer);

/*WINUSERAPI*/
HWND
__stdcall
GetClipboardViewer(
    VOID);

/*WINUSERAPI*/
BOOL
__stdcall
ChangeClipboardChain(
    HWND hWndRemove,
    HWND hWndNewNext);

/*WINUSERAPI*/
HANDLE
__stdcall
SetClipboardData(
    unsigned uFormat,
    HANDLE hMem);

/*WINUSERAPI*/
HANDLE
__stdcall
    GetClipboardData(
    unsigned uFormat);

/*WINUSERAPI*/
unsigned
__stdcall
RegisterClipboardFormatA(
    const char* lpszFormat);
/*WINUSERAPI*/
unsigned
__stdcall
RegisterClipboardFormatW(
    const wchar_t* lpszFormat);
#ifdef UNICODE
#define RegisterClipboardFormat  RegisterClipboardFormatW
#else
#define RegisterClipboardFormat  RegisterClipboardFormatA
#endif // !UNICODE

/*WINUSERAPI*/
int
__stdcall
CountClipboardFormats(
    VOID);

/*WINUSERAPI*/
unsigned
__stdcall
EnumClipboardFormats(
    unsigned format);

/*WINUSERAPI*/
int
__stdcall
GetClipboardFormatNameA(
    unsigned format,
    char* lpszFormatName,
    int cchMaxCount);
/*WINUSERAPI*/
int
__stdcall
GetClipboardFormatNameW(
    unsigned format,
    wchar_t* lpszFormatName,
    int cchMaxCount);
#ifdef UNICODE
#define GetClipboardFormatName  GetClipboardFormatNameW
#else
#define GetClipboardFormatName  GetClipboardFormatNameA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
EmptyClipboard(
    VOID);

/*WINUSERAPI*/
BOOL
__stdcall
IsClipboardFormatAvailable(
    unsigned format);

/*WINUSERAPI*/
int
__stdcall
GetPriorityClipboardFormat(
    unsigned *paFormatPriorityList,
    int cFormats);

/*WINUSERAPI*/
HWND
__stdcall
GetOpenClipboardWindow(
    VOID);

#endif /* !NOCLIPBOARD */

/*
 * Character Translation Routines
 */

/*WINUSERAPI*/
BOOL
__stdcall
CharToOemA(
    const char* lpszSrc,
    char* lpszDst);
/*WINUSERAPI*/
BOOL
__stdcall
CharToOemW(
    const wchar_t* lpszSrc,
    char* lpszDst);
#ifdef UNICODE
#define CharToOem  CharToOemW
#else
#define CharToOem  CharToOemA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
OemToCharA(
    const char* lpszSrc,
    char* lpszDst);
/*WINUSERAPI*/
BOOL
__stdcall
OemToCharW(
    const char* lpszSrc,
    wchar_t* lpszDst);
#ifdef UNICODE
#define OemToChar  OemToCharW
#else
#define OemToChar  OemToCharA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
CharToOemBuffA(
    const char* lpszSrc,
    char* lpszDst,
    unsigned long cchDstLength);
/*WINUSERAPI*/
BOOL
__stdcall
CharToOemBuffW(
    const wchar_t* lpszSrc,
    char* lpszDst,
    unsigned long cchDstLength);
#ifdef UNICODE
#define CharToOemBuff  CharToOemBuffW
#else
#define CharToOemBuff  CharToOemBuffA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
OemToCharBuffA(
    const char* lpszSrc,
    char* lpszDst,
    unsigned long cchDstLength);
/*WINUSERAPI*/
BOOL
__stdcall
OemToCharBuffW(
    const char* lpszSrc,
    wchar_t* lpszDst,
    unsigned long cchDstLength);
#ifdef UNICODE
#define OemToCharBuff  OemToCharBuffW
#else
#define OemToCharBuff  OemToCharBuffA
#endif // !UNICODE

/*WINUSERAPI*/
char*
__stdcall
CharUpperA(
    char* lpsz);
/*WINUSERAPI*/
wchar_t*
__stdcall
CharUpperW(
    wchar_t* lpsz);
#ifdef UNICODE
#define CharUpper  CharUpperW
#else
#define CharUpper  CharUpperA
#endif // !UNICODE

/*WINUSERAPI*/
unsigned long
__stdcall
CharUpperBuffA(
    char* lpsz,
    unsigned long cchLength);
/*WINUSERAPI*/
unsigned long
__stdcall
CharUpperBuffW(
    wchar_t* lpsz,
    unsigned long cchLength);
#ifdef UNICODE
#define CharUpperBuff  CharUpperBuffW
#else
#define CharUpperBuff  CharUpperBuffA
#endif // !UNICODE

/*WINUSERAPI*/
char*
__stdcall
CharLowerA(
    char* lpsz);
/*WINUSERAPI*/
wchar_t*
__stdcall
CharLowerW(
    wchar_t* lpsz);
#ifdef UNICODE
#define CharLower  CharLowerW
#else
#define CharLower  CharLowerA
#endif // !UNICODE

/*WINUSERAPI*/
unsigned long
__stdcall
CharLowerBuffA(
    char* lpsz,
    unsigned long cchLength);
/*WINUSERAPI*/
unsigned long
__stdcall
CharLowerBuffW(
    wchar_t* lpsz,
    unsigned long cchLength);
#ifdef UNICODE
#define CharLowerBuff  CharLowerBuffW
#else
#define CharLowerBuff  CharLowerBuffA
#endif // !UNICODE

/*WINUSERAPI*/
char*
__stdcall
CharNextA(
    const char* lpsz);
/*WINUSERAPI*/
wchar_t*
__stdcall
CharNextW(
    const wchar_t* lpsz);
#ifdef UNICODE
#define CharNext  CharNextW
#else
#define CharNext  CharNextA
#endif // !UNICODE

/*WINUSERAPI*/
char*
__stdcall
CharPrevA(
    const char* lpszStart,
    const char* lpszCurrent);
/*WINUSERAPI*/
wchar_t*
__stdcall
CharPrevW(
    const wchar_t* lpszStart,
    const wchar_t* lpszCurrent);
#ifdef UNICODE
#define CharPrev  CharPrevW
#else
#define CharPrev  CharPrevA
#endif // !UNICODE

#if(WINVER >= 0x0400)
/*WINUSERAPI*/
char*
__stdcall
CharNextExA(
     WORD CodePage,
     const char* lpCurrentChar,
     unsigned long dwFlags);

/*WINUSERAPI*/
char*
__stdcall
CharPrevExA(
     WORD CodePage,
     const char* lpStart,
     const char* lpCurrentChar,
     unsigned long dwFlags);
#endif /* WINVER >= 0x0400 */

/*
 * Compatibility defines for character translation routines
 */
#define AnsiToOem CharToOemA
#define OemToAnsi OemToCharA
#define AnsiToOemBuff CharToOemBuffA
#define OemToAnsiBuff OemToCharBuffA
#define AnsiUpper CharUpperA
#define AnsiUpperBuff CharUpperBuffA
#define AnsiLower CharLowerA
#define AnsiLowerBuff CharLowerBuffA
#define AnsiNext CharNextA
#define AnsiPrev CharPrevA

#ifndef  NOLANGUAGE
/*
 * Language dependent Routines
 */

/*WINUSERAPI*/
BOOL
__stdcall
IsCharAlphaA(
    char ch);
/*WINUSERAPI*/
BOOL
__stdcall
IsCharAlphaW(
    wchar_t ch);
#ifdef UNICODE
#define IsCharAlpha  IsCharAlphaW
#else
#define IsCharAlpha  IsCharAlphaA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
IsCharAlphaNumericA(
    char ch);
/*WINUSERAPI*/
BOOL
__stdcall
IsCharAlphaNumericW(
    wchar_t ch);
#ifdef UNICODE
#define IsCharAlphaNumeric  IsCharAlphaNumericW
#else
#define IsCharAlphaNumeric  IsCharAlphaNumericA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
IsCharUpperA(
    char ch);
/*WINUSERAPI*/
BOOL
__stdcall
IsCharUpperW(
    wchar_t ch);
#ifdef UNICODE
#define IsCharUpper  IsCharUpperW
#else
#define IsCharUpper  IsCharUpperA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
IsCharLowerA(
    char ch);
/*WINUSERAPI*/
BOOL
__stdcall
IsCharLowerW(
    wchar_t ch);
#ifdef UNICODE
#define IsCharLower  IsCharLowerW
#else
#define IsCharLower  IsCharLowerA
#endif // !UNICODE

#endif  /* !NOLANGUAGE */

/*WINUSERAPI*/
HWND
__stdcall
SetFocus(
    HWND hWnd);

/*WINUSERAPI*/
HWND
__stdcall
GetActiveWindow(
    VOID);

/*WINUSERAPI*/
HWND
__stdcall
GetFocus(
    VOID);

/*WINUSERAPI*/
unsigned
__stdcall
GetKBCodePage(
    VOID);

/*WINUSERAPI*/
SHORT
__stdcall
GetKeyState(
    int nVirtKey);

/*WINUSERAPI*/
SHORT
__stdcall
GetAsyncKeyState(
    int vKey);

/*WINUSERAPI*/
BOOL
__stdcall
GetKeyboardState(
    PBYTE lpKeyState);

/*WINUSERAPI*/
BOOL
__stdcall
SetKeyboardState(
    LPBYTE lpKeyState);

/*WINUSERAPI*/
int
__stdcall
GetKeyNameTextA(
    long lParam,
    char* lpString,
    int nSize
    );
/*WINUSERAPI*/
int
__stdcall
GetKeyNameTextW(
    long lParam,
    wchar_t* lpString,
    int nSize
    );
#ifdef UNICODE
#define GetKeyNameText  GetKeyNameTextW
#else
#define GetKeyNameText  GetKeyNameTextA
#endif // !UNICODE

/*WINUSERAPI*/
int
__stdcall
GetKeyboardType(
    int nTypeFlag);

/*WINUSERAPI*/
int
__stdcall
ToAscii(
    unsigned uVirtKey,
    unsigned uScanCode,
    PBYTE lpKeyState,
    LPWORD lpChar,
    unsigned uFlags);

#if(WINVER >= 0x0400)
/*WINUSERAPI*/
int
__stdcall
ToAsciiEx(
    unsigned uVirtKey,
    unsigned uScanCode,
    PBYTE lpKeyState,
    LPWORD lpChar,
    unsigned uFlags,
    HKL dwhkl);
#endif /* WINVER >= 0x0400 */

/*WINUSERAPI*/
int
__stdcall
ToUnicode(
    unsigned wVirtKey,
    unsigned wScanCode,
    PBYTE lpKeyState,
    wchar_t* pwszBuff,
    int cchBuff,
    unsigned wFlags);

/*WINUSERAPI*/
unsigned long
__stdcall
OemKeyScan(
    WORD wOemChar);

/*WINUSERAPI*/
SHORT
__stdcall
VkKeyScanA(
    char ch);
/*WINUSERAPI*/
SHORT
__stdcall
VkKeyScanW(
    wchar_t ch);
#ifdef UNICODE
#define VkKeyScan  VkKeyScanW
#else
#define VkKeyScan  VkKeyScanA
#endif // !UNICODE

#if(WINVER >= 0x0400)
/*WINUSERAPI*/
SHORT
__stdcall VkKeyScanExA(
    char  ch,
    HKL   dwhkl);
/*WINUSERAPI*/
SHORT
__stdcall VkKeyScanExW(
    wchar_t  ch,
    HKL   dwhkl);
#ifdef UNICODE
#define VkKeyScanEx  VkKeyScanExW
#else
#define VkKeyScanEx  VkKeyScanExA
#endif // !UNICODE
#endif /* WINVER >= 0x0400 */
#define KEYEVENTF_EXTENDEDKEY 0x0001
#define KEYEVENTF_KEYUP       0x0002

/*WINUSERAPI*/
VOID
__stdcall
keybd_event(
    BYTE bVk,
    BYTE bScan,
    unsigned long dwFlags,
    unsigned long dwExtraInfo);

#define MOUSEEVENTF_MOVE        0x0001 /* mouse move */
#define MOUSEEVENTF_LEFTDOWN    0x0002 /* left button down */
#define MOUSEEVENTF_LEFTUP      0x0004 /* left button up */
#define MOUSEEVENTF_RIGHTDOWN   0x0008 /* right button down */
#define MOUSEEVENTF_RIGHTUP     0x0010 /* right button up */
#define MOUSEEVENTF_MIDDLEDOWN  0x0020 /* middle button down */
#define MOUSEEVENTF_MIDDLEUP    0x0040 /* middle button up */
#define MOUSEEVENTF_WHEEL       0x0800 /* wheel button rolled */
#define MOUSEEVENTF_ABSOLUTE    0x8000 /* absolute move */

/*WINUSERAPI*/
VOID
__stdcall
mouse_event(
    unsigned long dwFlags,
    unsigned long dx,
    unsigned long dy,
    unsigned long dwData,
    unsigned long dwExtraInfo);

/*WINUSERAPI*/
unsigned
__stdcall
MapVirtualKeyA(
    unsigned uCode,
    unsigned uMapType);
/*WINUSERAPI*/
unsigned
__stdcall
MapVirtualKeyW(
    unsigned uCode,
    unsigned uMapType);
#ifdef UNICODE
#define MapVirtualKey  MapVirtualKeyW
#else
#define MapVirtualKey  MapVirtualKeyA
#endif // !UNICODE

#if(WINVER >= 0x0400)
/*WINUSERAPI*/
unsigned
__stdcall
MapVirtualKeyExA(
    unsigned uCode,
    unsigned uMapType,
    HKL dwhkl);
/*WINUSERAPI*/
unsigned
__stdcall
MapVirtualKeyExW(
    unsigned uCode,
    unsigned uMapType,
    HKL dwhkl);
#ifdef UNICODE
#define MapVirtualKeyEx  MapVirtualKeyExW
#else
#define MapVirtualKeyEx  MapVirtualKeyExA
#endif // !UNICODE
#endif /* WINVER >= 0x0400 */

/*WINUSERAPI*/
BOOL
__stdcall
GetInputState(
    VOID);

/*WINUSERAPI*/
unsigned long
__stdcall
GetQueueStatus(
    unsigned flags);

/*WINUSERAPI*/
HWND
__stdcall
GetCapture(
    VOID);

/*WINUSERAPI*/
HWND
__stdcall
SetCapture(
    HWND hWnd);

/*WINUSERAPI*/
BOOL
__stdcall
ReleaseCapture(
    VOID);

/*WINUSERAPI*/
unsigned long
__stdcall
MsgWaitForMultipleObjects(
    unsigned long nCount,
    LPHANDLE pHandles,
    BOOL fWaitAll,
    unsigned long dwMilliseconds,
    unsigned long dwWakeMask);

/*WINUSERAPI*/
unsigned long
__stdcall
MsgWaitForMultipleObjectsEx(
    unsigned long nCount,
    LPHANDLE pHandles,
    unsigned long dwMilliseconds,
    unsigned long dwWakeMask,
    unsigned long dwFlags);

#define MWMO_WAITALL      0x0001
#define MWMO_ALERTABLE    0x0002

/*
 * Queue status flags for GetQueueStatus() and MsgWaitForMultipleObjects()
 */
#define QS_KEY              0x0001
#define QS_MOUSEMOVE        0x0002
#define QS_MOUSEBUTTON      0x0004
#define QS_POSTMESSAGE      0x0008
#define QS_TIMER            0x0010
#define QS_PAINT            0x0020
#define QS_SENDMESSAGE      0x0040
#define QS_HOTKEY           0x0080
#define QS_ALLPOSTMESSAGE   0x0100



#define QS_MOUSE           (QS_MOUSEMOVE     | \
                            QS_MOUSEBUTTON)

#define QS_INPUT           (QS_MOUSE         | \
                            QS_KEY)

#define QS_ALLEVENTS       (QS_INPUT         | \
                            QS_POSTMESSAGE   | \
                            QS_TIMER         | \
                            QS_PAINT         | \
                            QS_HOTKEY)

#define QS_ALLINPUT        (QS_INPUT         | \
                            QS_POSTMESSAGE   | \
                            QS_TIMER         | \
                            QS_PAINT         | \
                            QS_HOTKEY        | \
                            QS_SENDMESSAGE)


/*
 * Windows Functions
 */

/*WINUSERAPI*/
unsigned
__stdcall
SetTimer(
    HWND hWnd ,
    unsigned nIDEvent,
    unsigned uElapse,
    TIMERPROC lpTimerFunc);

/*WINUSERAPI*/
BOOL
__stdcall
KillTimer(
    HWND hWnd,
    unsigned uIDEvent);

/*WINUSERAPI*/
BOOL
__stdcall
IsWindowUnicode(
    HWND hWnd);

/*WINUSERAPI*/
BOOL
__stdcall
EnableWindow(
    HWND hWnd,
    BOOL bEnable);

/*WINUSERAPI*/
BOOL
__stdcall
IsWindowEnabled(
    HWND hWnd);

/*WINUSERAPI*/
HACCEL
__stdcall
LoadAcceleratorsA(
    HINSTANCE hInstance,
    const char* lpTableName);
/*WINUSERAPI*/
HACCEL
__stdcall
LoadAcceleratorsW(
    HINSTANCE hInstance,
    const wchar_t* lpTableName);
#ifdef UNICODE
#define LoadAccelerators  LoadAcceleratorsW
#else
#define LoadAccelerators  LoadAcceleratorsA
#endif // !UNICODE

/*WINUSERAPI*/
HACCEL
__stdcall
CreateAcceleratorTableA(
    LPACCEL, int);
/*WINUSERAPI*/
HACCEL
__stdcall
CreateAcceleratorTableW(
    LPACCEL, int);
#ifdef UNICODE
#define CreateAcceleratorTable  CreateAcceleratorTableW
#else
#define CreateAcceleratorTable  CreateAcceleratorTableA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
DestroyAcceleratorTable(
    HACCEL hAccel);

/*WINUSERAPI*/
int
__stdcall
CopyAcceleratorTableA(
    HACCEL hAccelSrc,
    LPACCEL lpAccelDst,
    int cAccelEntries);
/*WINUSERAPI*/
int
__stdcall
CopyAcceleratorTableW(
    HACCEL hAccelSrc,
    LPACCEL lpAccelDst,
    int cAccelEntries);
#ifdef UNICODE
#define CopyAcceleratorTable  CopyAcceleratorTableW
#else
#define CopyAcceleratorTable  CopyAcceleratorTableA
#endif // !UNICODE

#ifndef NOMSG

/*WINUSERAPI*/
int
__stdcall
TranslateAcceleratorA(
    HWND hWnd,
    HACCEL hAccTable,
    LPMSG lpMsg);
/*WINUSERAPI*/
int
__stdcall
TranslateAcceleratorW(
    HWND hWnd,
    HACCEL hAccTable,
    LPMSG lpMsg);
#ifdef UNICODE
#define TranslateAccelerator  TranslateAcceleratorW
#else
#define TranslateAccelerator  TranslateAcceleratorA
#endif // !UNICODE

#endif /* !NOMSG */

#ifndef NOSYSMETRICS

/*
 * GetSystemMetrics() codes
 */
#define SM_CXSCREEN             0
#define SM_CYSCREEN             1
#define SM_CXVSCROLL            2
#define SM_CYHSCROLL            3
#define SM_CYCAPTION            4
#define SM_CXBORDER             5
#define SM_CYBORDER             6
#define SM_CXDLGFRAME           7
#define SM_CYDLGFRAME           8
#define SM_CYVTHUMB             9
#define SM_CXHTHUMB             10
#define SM_CXICON               11
#define SM_CYICON               12
#define SM_CXCURSOR             13
#define SM_CYCURSOR             14
#define SM_CYMENU               15
#define SM_CXFULLSCREEN         16
#define SM_CYFULLSCREEN         17
#define SM_CYKANJIWINDOW        18
#define SM_MOUSEPRESENT         19
#define SM_CYVSCROLL            20
#define SM_CXHSCROLL            21
#define SM_DEBUG                22
#define SM_SWAPBUTTON           23
#define SM_RESERVED1            24
#define SM_RESERVED2            25
#define SM_RESERVED3            26
#define SM_RESERVED4            27
#define SM_CXMIN                28
#define SM_CYMIN                29
#define SM_CXSIZE               30
#define SM_CYSIZE               31
#define SM_CXFRAME              32
#define SM_CYFRAME              33
#define SM_CXMINTRACK           34
#define SM_CYMINTRACK           35
#define SM_CXDOUBLECLK          36
#define SM_CYDOUBLECLK          37
#define SM_CXICONSPACING        38
#define SM_CYICONSPACING        39
#define SM_MENUDROPALIGNMENT    40
#define SM_PENWINDOWS           41
#define SM_DBCSENABLED          42
#define SM_CMOUSEBUTTONS        43

#if(WINVER >= 0x0400)
#define SM_CXFIXEDFRAME           SM_CXDLGFRAME  /* ;win40 name change */
#define SM_CYFIXEDFRAME           SM_CYDLGFRAME  /* ;win40 name change */
#define SM_CXSIZEFRAME            SM_CXFRAME     /* ;win40 name change */
#define SM_CYSIZEFRAME            SM_CYFRAME     /* ;win40 name change */

#define SM_SECURE               44
#define SM_CXEDGE               45
#define SM_CYEDGE               46
#define SM_CXMINSPACING         47
#define SM_CYMINSPACING         48
#define SM_CXSMICON             49
#define SM_CYSMICON             50
#define SM_CYSMCAPTION          51
#define SM_CXSMSIZE             52
#define SM_CYSMSIZE             53
#define SM_CXMENUSIZE           54
#define SM_CYMENUSIZE           55
#define SM_ARRANGE              56
#define SM_CXMINIMIZED          57
#define SM_CYMINIMIZED          58
#define SM_CXMAXTRACK           59
#define SM_CYMAXTRACK           60
#define SM_CXMAXIMIZED          61
#define SM_CYMAXIMIZED          62
#define SM_NETWORK              63
#define SM_CLEANBOOT            67
#define SM_CXDRAG               68
#define SM_CYDRAG               69
#endif /* WINVER >= 0x0400 */
#define SM_SHOWSOUNDS           70
#if(WINVER >= 0x0400)
#define SM_CXMENUCHECK          71   /* Use instead of GetMenuCheckMarkDimensions()! */
#define SM_CYMENUCHECK          72
#define SM_SLOWMACHINE          73
#define SM_MIDEASTENABLED       74
#endif /* WINVER >= 0x0400 */
#if(_WIN32_WINNT >= 0x0400)
#define SM_MOUSEWHEELPRESENT    75
#endif /* _WIN32_WINNT >= 0x0400 */
#if (_WIN32_WINNT < 0x0400)
#define SM_CMETRICS             75
#else
#define SM_CMETRICS             76
#endif



/*WINUSERAPI*/
int
__stdcall
GetSystemMetrics(
    int nIndex);

#endif /* !NOSYSMETRICS */

#ifndef NOMENUS

/*WINUSERAPI*/
HMENU
__stdcall
LoadMenuA(
    HINSTANCE hInstance,
    const char* lpMenuName);
/*WINUSERAPI*/
HMENU
__stdcall
LoadMenuW(
    HINSTANCE hInstance,
    const wchar_t* lpMenuName);
#ifdef UNICODE
#define LoadMenu  LoadMenuW
#else
#define LoadMenu  LoadMenuA
#endif // !UNICODE

/*WINUSERAPI*/
HMENU
__stdcall
LoadMenuIndirectA(
    const MENUTEMPLATEA *lpMenuTemplate);
/*WINUSERAPI*/
HMENU
__stdcall
LoadMenuIndirectW(
    const MENUTEMPLATEW *lpMenuTemplate);
#ifdef UNICODE
#define LoadMenuIndirect  LoadMenuIndirectW
#else
#define LoadMenuIndirect  LoadMenuIndirectA
#endif // !UNICODE

/*WINUSERAPI*/
HMENU
__stdcall
GetMenu(
    HWND hWnd);

/*WINUSERAPI*/
BOOL
__stdcall
SetMenu(
    HWND hWnd,
    HMENU hMenu);

/*WINUSERAPI*/
BOOL
__stdcall
ChangeMenuA(
    HMENU hMenu,
    unsigned cmd,
    const char* lpszNewItem,
    unsigned cmdInsert,
    unsigned flags);
/*WINUSERAPI*/
BOOL
__stdcall
ChangeMenuW(
    HMENU hMenu,
    unsigned cmd,
    const wchar_t* lpszNewItem,
    unsigned cmdInsert,
    unsigned flags);
#ifdef UNICODE
#define ChangeMenu  ChangeMenuW
#else
#define ChangeMenu  ChangeMenuA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
HiliteMenuItem(
    HWND hWnd,
    HMENU hMenu,
    unsigned uIDHiliteItem,
    unsigned uHilite);

/*WINUSERAPI*/
int
__stdcall
GetMenuStringA(
    HMENU hMenu,
    unsigned uIDItem,
    char* lpString,
    int nMaxCount,
    unsigned uFlag);
/*WINUSERAPI*/
int
__stdcall
GetMenuStringW(
    HMENU hMenu,
    unsigned uIDItem,
    wchar_t* lpString,
    int nMaxCount,
    unsigned uFlag);
#ifdef UNICODE
#define GetMenuString  GetMenuStringW
#else
#define GetMenuString  GetMenuStringA
#endif // !UNICODE

/*WINUSERAPI*/
unsigned
__stdcall
GetMenuState(
    HMENU hMenu,
    unsigned uId,
    unsigned uFlags);

/*WINUSERAPI*/
BOOL
__stdcall
DrawMenuBar(
    HWND hWnd);


/*WINUSERAPI*/
HMENU
__stdcall
GetSystemMenu(
    HWND hWnd,
    BOOL bRevert);



/*WINUSERAPI*/
HMENU
__stdcall
CreateMenu(
    VOID);

/*WINUSERAPI*/
HMENU
__stdcall
CreatePopupMenu(
    VOID);

/*WINUSERAPI*/
BOOL
__stdcall
DestroyMenu(
    HMENU hMenu);

/*WINUSERAPI*/
unsigned long
__stdcall
CheckMenuItem(
    HMENU hMenu,
    unsigned uIDCheckItem,
    unsigned uCheck);

/*WINUSERAPI*/
BOOL
__stdcall
EnableMenuItem(
    HMENU hMenu,
    unsigned uIDEnableItem,
    unsigned uEnable);

/*WINUSERAPI*/
HMENU
__stdcall
GetSubMenu(
    HMENU hMenu,
    int nPos);

/*WINUSERAPI*/
unsigned
__stdcall
GetMenuItemID(
    HMENU hMenu,
    int nPos);

/*WINUSERAPI*/
int
__stdcall
GetMenuItemCount(
    HMENU hMenu);

/*WINUSERAPI*/
BOOL
__stdcall
InsertMenuA(
    HMENU hMenu,
    unsigned uPosition,
    unsigned uFlags,
    unsigned uIDNewItem,
    const char* lpNewItem
    );
/*WINUSERAPI*/
BOOL
__stdcall
InsertMenuW(
    HMENU hMenu,
    unsigned uPosition,
    unsigned uFlags,
    unsigned uIDNewItem,
    const wchar_t* lpNewItem
    );
#ifdef UNICODE
#define InsertMenu  InsertMenuW
#else
#define InsertMenu  InsertMenuA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
AppendMenuA(
    HMENU hMenu,
    unsigned uFlags,
    unsigned uIDNewItem,
    const char* lpNewItem
    );
/*WINUSERAPI*/
BOOL
__stdcall
AppendMenuW(
    HMENU hMenu,
    unsigned uFlags,
    unsigned uIDNewItem,
    const wchar_t* lpNewItem
    );
#ifdef UNICODE
#define AppendMenu  AppendMenuW
#else
#define AppendMenu  AppendMenuA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
ModifyMenuA(
    HMENU hMnu,
    unsigned uPosition,
    unsigned uFlags,
    unsigned uIDNewItem,
    const char* lpNewItem
    );
/*WINUSERAPI*/
BOOL
__stdcall
ModifyMenuW(
    HMENU hMnu,
    unsigned uPosition,
    unsigned uFlags,
    unsigned uIDNewItem,
    const wchar_t* lpNewItem
    );
#ifdef UNICODE
#define ModifyMenu  ModifyMenuW
#else
#define ModifyMenu  ModifyMenuA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall RemoveMenu(
    HMENU hMenu,
    unsigned uPosition,
    unsigned uFlags);

/*WINUSERAPI*/
BOOL
__stdcall
DeleteMenu(
    HMENU hMenu,
    unsigned uPosition,
    unsigned uFlags);

/*WINUSERAPI*/
BOOL
__stdcall
SetMenuItemBitmaps(
    HMENU hMenu,
    unsigned uPosition,
    unsigned uFlags,
    HBITMAP hBitmapUnchecked,
    HBITMAP hBitmapChecked);

/*WINUSERAPI*/
long
__stdcall
GetMenuCheckMarkDimensions(
    VOID);

/*WINUSERAPI*/
BOOL
__stdcall
TrackPopupMenu(
    HMENU hMenu,
    unsigned uFlags,
    int x,
    int y,
    int nReserved,
    HWND hWnd,
    const RECT *prcRect);

#if(WINVER >= 0x0400)
/* return codes for WM_MENUCHAR */
#define MNC_IGNORE  0
#define MNC_CLOSE   1
#define MNC_EXECUTE 2
#define MNC_SELECT  3

typedef struct tagTPMPARAMS
{
    unsigned    cbSize;     /* Size of structure */
    RECT    rcExclude;  /* Screen coordinates of rectangle to exclude when positioning */
}   TPMPARAMS;
typedef TPMPARAMS  *LPTPMPARAMS;

/*WINUSERAPI*/ BOOL    __stdcall TrackPopupMenuEx(HMENU, unsigned, int, int, HWND, LPTPMPARAMS);
#endif /* WINVER >= 0x0400 */


#if(WINVER >= 0x0400)
#define MIIM_STATE       0x00000001
#define MIIM_ID          0x00000002
#define MIIM_SUBMENU     0x00000004
#define MIIM_CHECKMARKS  0x00000008
#define MIIM_TYPE        0x00000010
#define MIIM_DATA        0x00000020
#endif /* WINVER >= 0x0400 */


#if(WINVER >= 0x0400)
typedef struct tagMENUITEMINFOA
{
    unsigned    cbSize;
    unsigned    fMask;
    unsigned    fType;          // used if MIIM_TYPE
    unsigned    fState;         // used if MIIM_STATE
    unsigned    wID;            // used if MIIM_ID
    HMENU   hSubMenu;       // used if MIIM_SUBMENU
    HBITMAP hbmpChecked;    // used if MIIM_CHECKMARKS
    HBITMAP hbmpUnchecked;  // used if MIIM_CHECKMARKS
    unsigned long   dwItemData;     // used if MIIM_DATA
    char*   dwTypeData;     // used if MIIM_TYPE
    unsigned    cch;            // used if MIIM_TYPE
}   MENUITEMINFOA,  *LPMENUITEMINFOA;
typedef struct tagMENUITEMINFOW
{
    unsigned    cbSize;
    unsigned    fMask;
    unsigned    fType;          // used if MIIM_TYPE
    unsigned    fState;         // used if MIIM_STATE
    unsigned    wID;            // used if MIIM_ID
    HMENU   hSubMenu;       // used if MIIM_SUBMENU
    HBITMAP hbmpChecked;    // used if MIIM_CHECKMARKS
    HBITMAP hbmpUnchecked;  // used if MIIM_CHECKMARKS
    unsigned long   dwItemData;     // used if MIIM_DATA
    wchar_t*  dwTypeData;     // used if MIIM_TYPE
    unsigned    cch;            // used if MIIM_TYPE
}   MENUITEMINFOW,  *LPMENUITEMINFOW;
#ifdef UNICODE
typedef MENUITEMINFOW MENUITEMINFO;
typedef LPMENUITEMINFOW LPMENUITEMINFO;
#else
typedef MENUITEMINFOA MENUITEMINFO;
typedef LPMENUITEMINFOA LPMENUITEMINFO;
#endif // UNICODE
typedef MENUITEMINFOA const  *LPCMENUITEMINFOA;
typedef MENUITEMINFOW const  *LPCMENUITEMINFOW;
#ifdef UNICODE
typedef LPCMENUITEMINFOW LPCMENUITEMINFO;
#else
typedef LPCMENUITEMINFOA LPCMENUITEMINFO;
#endif // UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
InsertMenuItemA(
    HMENU,
    unsigned,
    BOOL,
    LPCMENUITEMINFOA
    );
/*WINUSERAPI*/
BOOL
__stdcall
InsertMenuItemW(
    HMENU,
    unsigned,
    BOOL,
    LPCMENUITEMINFOW
    );
#ifdef UNICODE
#define InsertMenuItem  InsertMenuItemW
#else
#define InsertMenuItem  InsertMenuItemA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
GetMenuItemInfoA(
    HMENU,
    unsigned,
    BOOL,
    LPMENUITEMINFOA
    );
/*WINUSERAPI*/
BOOL
__stdcall
GetMenuItemInfoW(
    HMENU,
    unsigned,
    BOOL,
    LPMENUITEMINFOW
    );
#ifdef UNICODE
#define GetMenuItemInfo  GetMenuItemInfoW
#else
#define GetMenuItemInfo  GetMenuItemInfoA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
SetMenuItemInfoA(
    HMENU,
    unsigned,
    BOOL,
    LPCMENUITEMINFOA
    );
/*WINUSERAPI*/
BOOL
__stdcall
SetMenuItemInfoW(
    HMENU,
    unsigned,
    BOOL,
    LPCMENUITEMINFOW
    );
#ifdef UNICODE
#define SetMenuItemInfo  SetMenuItemInfoW
#else
#define SetMenuItemInfo  SetMenuItemInfoA
#endif // !UNICODE


#define GMDI_USEDISABLED    0x0001L
#define GMDI_GOINTOPOPUPS   0x0002L

/*WINUSERAPI*/ unsigned    __stdcall GetMenuDefaultItem(HMENU hMenu, unsigned fByPos, unsigned gmdiFlags);
/*WINUSERAPI*/ BOOL    __stdcall SetMenuDefaultItem(HMENU hMenu, unsigned uItem, unsigned fByPos);

/*WINUSERAPI*/ BOOL    __stdcall GetMenuItemRect(HWND hWnd, HMENU hMenu, unsigned uItem, RECT* lprcItem);
/*WINUSERAPI*/ int     __stdcall MenuItemFromPoint(HWND hWnd, HMENU hMenu, POINT ptScreen);
#endif /* WINVER >= 0x0400 */

/*
 * Flags for TrackPopupMenu
 */
#define TPM_LEFTBUTTON  0x0000L
#define TPM_RIGHTBUTTON 0x0002L
#define TPM_LEFTALIGN   0x0000L
#define TPM_CENTERALIGN 0x0004L
#define TPM_RIGHTALIGN  0x0008L
#if(WINVER >= 0x0400)
#define TPM_TOPALIGN        0x0000L
#define TPM_VCENTERALIGN    0x0010L
#define TPM_BOTTOMALIGN     0x0020L

#define TPM_HORIZONTAL      0x0000L     /* Horz alignment matters more */
#define TPM_VERTICAL        0x0040L     /* Vert alignment matters more */
#define TPM_NONOTIFY        0x0080L     /* Don't send any notification msgs */
#define TPM_RETURNCMD       0x0100L
#endif /* WINVER >= 0x0400 */


#endif /* !NOMENUS */


#if(WINVER >= 0x0400)
//
// Drag-and-drop support
//

typedef struct tagDROPSTRUCT
{
    HWND    hwndSource;
    HWND    hwndSink;
    unsigned long   wFmt;
    unsigned long   dwData;
    POINT   ptDrop;
    unsigned long   dwControlData;
} DROPSTRUCT, *PDROPSTRUCT, *LPDROPSTRUCT;

#define DOF_EXECUTABLE      0x8001
#define DOF_DOCUMENT        0x8002
#define DOF_DIRECTORY       0x8003
#define DOF_MULTIPLE        0x8004
#define DOF_PROGMAN         0x0001
#define DOF_SHELLDATA       0x0002

#define DO_DROPFILE         0x454C4946L
#define DO_PRINTFILE        0x544E5250L

/*WINUSERAPI*/
unsigned long
__stdcall
DragObject(HWND, HWND, unsigned, unsigned long, HCURSOR);

/*WINUSERAPI*/
BOOL
__stdcall
DragDetect(HWND, POINT);
#endif /* WINVER >= 0x0400 */

/*WINUSERAPI*/
BOOL
__stdcall
DrawIcon(
    HDC hDC,
    int X,
    int Y,
    HICON hIcon);

#ifndef NODRAWTEXT

/*
 * DrawText() Format Flags
 */
#define DT_TOP              0x00000000
#define DT_LEFT             0x00000000
#define DT_CENTER           0x00000001
#define DT_RIGHT            0x00000002
#define DT_VCENTER          0x00000004
#define DT_BOTTOM           0x00000008
#define DT_WORDBREAK        0x00000010
#define DT_SINGLELINE       0x00000020
#define DT_EXPANDTABS       0x00000040
#define DT_TABSTOP          0x00000080
#define DT_NOCLIP           0x00000100
#define DT_EXTERNALLEADING  0x00000200
#define DT_CALCRECT         0x00000400
#define DT_NOPREFIX         0x00000800
#define DT_INTERNAL         0x00001000

#if(WINVER >= 0x0400)
#define DT_EDITCONTROL      0x00002000
#define DT_PATH_ELLIPSIS    0x00004000
#define DT_END_ELLIPSIS     0x00008000
#define DT_MODIFYSTRING     0x00010000
#define DT_RTLREADING       0x00020000
#define DT_WORD_ELLIPSIS    0x00040000



typedef struct tagDRAWTEXTPARAMS
{
    unsigned    cbSize;
    int     iTabLength;
    int     iLeftMargin;
    int     iRightMargin;
    unsigned    uiLengthDrawn;
} DRAWTEXTPARAMS,  *LPDRAWTEXTPARAMS;
#endif /* WINVER >= 0x0400 */





/*WINUSERAPI*/
int
__stdcall
DrawTextA(
    HDC hDC,
    const char* lpString,
    int nCount,
    RECT* lpRect,
    unsigned uFormat);
/*WINUSERAPI*/
int
__stdcall
DrawTextW(
    HDC hDC,
    const wchar_t* lpString,
    int nCount,
    RECT* lpRect,
    unsigned uFormat);
#ifdef UNICODE
#define DrawText  DrawTextW
#else
#define DrawText  DrawTextA
#endif // !UNICODE


#if(WINVER >= 0x0400)
/*WINUSERAPI*/
int
__stdcall
DrawTextExA(HDC, char*, int, RECT*, unsigned, LPDRAWTEXTPARAMS);
/*WINUSERAPI*/
int
__stdcall
DrawTextExW(HDC, wchar_t*, int, RECT*, unsigned, LPDRAWTEXTPARAMS);
#ifdef UNICODE
#define DrawTextEx  DrawTextExW
#else
#define DrawTextEx  DrawTextExA
#endif // !UNICODE
#endif /* WINVER >= 0x0400 */

#endif /* !NODRAWTEXT */

/*WINUSERAPI*/
BOOL
__stdcall
GrayStringA(
    HDC hDC,
    HBRUSH hBrush,
    GRAYSTRINGPROC lpOutputFunc,
    LPARAM lpData,
    int nCount,
    int X,
    int Y,
    int nWidth,
    int nHeight);
/*WINUSERAPI*/
BOOL
__stdcall
GrayStringW(
    HDC hDC,
    HBRUSH hBrush,
    GRAYSTRINGPROC lpOutputFunc,
    LPARAM lpData,
    int nCount,
    int X,
    int Y,
    int nWidth,
    int nHeight);
#ifdef UNICODE
#define GrayString  GrayStringW
#else
#define GrayString  GrayStringA
#endif // !UNICODE

#if(WINVER >= 0x0400)
/* Monolithic state-drawing routine */
/* Image type */
#define DST_COMPLEX     0x0000
#define DST_TEXT        0x0001
#define DST_PREFIXTEXT  0x0002
#define DST_ICON        0x0003
#define DST_BITMAP      0x0004

/* State type */
#define DSS_NORMAL      0x0000
#define DSS_UNION       0x0010  /* Gray string appearance */
#define DSS_DISABLED    0x0020
#define DSS_MONO        0x0080
#define DSS_RIGHT       0x8000

/*WINUSERAPI*/ BOOL __stdcall DrawStateA(HDC, HBRUSH, DRAWSTATEPROC, LPARAM, WPARAM, int, int, int, int, unsigned);
/*WINUSERAPI*/ BOOL __stdcall DrawStateW(HDC, HBRUSH, DRAWSTATEPROC, LPARAM, WPARAM, int, int, int, int, unsigned);
#ifdef UNICODE
#define DrawState  DrawStateW
#else
#define DrawState  DrawStateA
#endif // !UNICODE
#endif /* WINVER >= 0x0400 */


/*WINUSERAPI*/
long
__stdcall
TabbedTextOutA(
    HDC hDC,
    int X,
    int Y,
    const char* lpString,
    int nCount,
    int nTabPositions,
    LPINT lpnTabStopPositions,
    int nTabOrigin);
/*WINUSERAPI*/
long
__stdcall
TabbedTextOutW(
    HDC hDC,
    int X,
    int Y,
    const wchar_t* lpString,
    int nCount,
    int nTabPositions,
    LPINT lpnTabStopPositions,
    int nTabOrigin);
#ifdef UNICODE
#define TabbedTextOut  TabbedTextOutW
#else
#define TabbedTextOut  TabbedTextOutA
#endif // !UNICODE

/*WINUSERAPI*/
unsigned long
__stdcall
GetTabbedTextExtentA(
    HDC hDC,
    const char* lpString,
    int nCount,
    int nTabPositions,
    LPINT lpnTabStopPositions);
/*WINUSERAPI*/
unsigned long
__stdcall
GetTabbedTextExtentW(
    HDC hDC,
    const wchar_t* lpString,
    int nCount,
    int nTabPositions,
    LPINT lpnTabStopPositions);
#ifdef UNICODE
#define GetTabbedTextExtent  GetTabbedTextExtentW
#else
#define GetTabbedTextExtent  GetTabbedTextExtentA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
UpdateWindow(
    HWND hWnd);

/*WINUSERAPI*/
HWND
__stdcall
SetActiveWindow(
    HWND hWnd);

/*WINUSERAPI*/
HWND
__stdcall
GetForegroundWindow(
    VOID);

#if(WINVER >= 0x0400)
/*WINUSERAPI*/ BOOL __stdcall PaintDesktop(HDC hdc);

#endif /* WINVER >= 0x0400 */

/*WINUSERAPI*/
BOOL
__stdcall
SetForegroundWindow(
    HWND hWnd);

/*WINUSERAPI*/
HWND
__stdcall
WindowFromDC(
    HDC hDC);

/*WINUSERAPI*/
HDC
__stdcall
GetDC(
    HWND hWnd);

/*WINUSERAPI*/
HDC
__stdcall
GetDCEx(
    HWND hWnd ,
    HRGN hrgnClip,
    unsigned long flags);

/*
 * GetDCEx() flags
 */
#define DCX_WINDOW           0x00000001L
#define DCX_CACHE            0x00000002L
#define DCX_NORESETATTRS     0x00000004L
#define DCX_CLIPCHILDREN     0x00000008L
#define DCX_CLIPSIBLINGS     0x00000010L
#define DCX_PARENTCLIP       0x00000020L

#define DCX_EXCLUDERGN       0x00000040L
#define DCX_INTERSECTRGN     0x00000080L

#define DCX_EXCLUDEUPDATE    0x00000100L
#define DCX_INTERSECTUPDATE  0x00000200L

#define DCX_LOCKWINDOWUPDATE 0x00000400L

#define DCX_VALIDATE         0x00200000L




/*WINUSERAPI*/
HDC
__stdcall
GetWindowDC(
    HWND hWnd);

/*WINUSERAPI*/
int
__stdcall
ReleaseDC(
    HWND hWnd,
    HDC hDC);

/*WINUSERAPI*/
HDC
__stdcall
BeginPaint(
    HWND hWnd,
    LPPAINTSTRUCT lpPaint);

/*WINUSERAPI*/
BOOL
__stdcall
EndPaint(
    HWND hWnd,
    const PAINTSTRUCT *lpPaint);

/*WINUSERAPI*/
BOOL
__stdcall
GetUpdateRect(
    HWND hWnd,
    RECT* lpRect,
    BOOL bErase);

/*WINUSERAPI*/
int
__stdcall
GetUpdateRgn(
    HWND hWnd,
    HRGN hRgn,
    BOOL bErase);

/*WINUSERAPI*/
int
__stdcall
SetWindowRgn(
    HWND hWnd,
    HRGN hRgn,
    BOOL bRedraw);

/*WINUSERAPI*/
int
__stdcall
GetWindowRgn(
    HWND hWnd,
    HRGN hRgn);

/*WINUSERAPI*/
int
__stdcall
ExcludeUpdateRgn(
    HDC hDC,
    HWND hWnd);

/*WINUSERAPI*/
BOOL
__stdcall
InvalidateRect(
    HWND hWnd ,
    const RECT *lpRect,
    BOOL bErase);

/*WINUSERAPI*/
BOOL
__stdcall
ValidateRect(
    HWND hWnd ,
    const RECT *lpRect);

/*WINUSERAPI*/
BOOL
__stdcall
InvalidateRgn(
    HWND hWnd,
    HRGN hRgn,
    BOOL bErase);

/*WINUSERAPI*/
BOOL
__stdcall
ValidateRgn(
    HWND hWnd,
    HRGN hRgn);


/*WINUSERAPI*/
BOOL
__stdcall
RedrawWindow(
    HWND hWnd,
    const RECT *lprcUpdate,
    HRGN hrgnUpdate,
    unsigned flags);

/*
 * RedrawWindow() flags
 */
#define RDW_INVALIDATE          0x0001
#define RDW_INTERNALPAINT       0x0002
#define RDW_ERASE               0x0004

#define RDW_VALIDATE            0x0008
#define RDW_NOINTERNALPAINT     0x0010
#define RDW_NOERASE             0x0020

#define RDW_NOCHILDREN          0x0040
#define RDW_ALLCHILDREN         0x0080

#define RDW_UPDATENOW           0x0100
#define RDW_ERASENOW            0x0200

#define RDW_FRAME               0x0400
#define RDW_NOFRAME             0x0800



/*
 * LockWindowUpdate API
 */

/*WINUSERAPI*/
BOOL
__stdcall
LockWindowUpdate(
    HWND hWndLock);

/*WINUSERAPI*/
BOOL
__stdcall
ScrollWindow(
    HWND hWnd,
    int XAmount,
    int YAmount,
    const RECT *lpRect,
    const RECT *lpClipRect);

/*WINUSERAPI*/
BOOL
__stdcall
ScrollDC(
    HDC hDC,
    int dx,
    int dy,
    const RECT *lprcScroll,
    const RECT *lprcClip ,
    HRGN hrgnUpdate,
    RECT* lprcUpdate);

/*WINUSERAPI*/
int
__stdcall
ScrollWindowEx(
    HWND hWnd,
    int dx,
    int dy,
    const RECT *prcScroll,
    const RECT *prcClip ,
    HRGN hrgnUpdate,
    RECT* prcUpdate,
    unsigned flags);

#define SW_SCROLLCHILDREN   0x0001  /* Scroll children within *lprcScroll. */
#define SW_INVALIDATE       0x0002  /* Invalidate after scrolling */
#define SW_ERASE            0x0004  /* If SW_INVALIDATE, don't send WM_ERASEBACKGROUND */



#ifndef NOSCROLL

/*WINUSERAPI*/
int
__stdcall
SetScrollPos(
    HWND hWnd,
    int nBar,
    int nPos,
    BOOL bRedraw);

/*WINUSERAPI*/
int
__stdcall
GetScrollPos(
    HWND hWnd,
    int nBar);

/*WINUSERAPI*/
BOOL
__stdcall
SetScrollRange(
    HWND hWnd,
    int nBar,
    int nMinPos,
    int nMaxPos,
    BOOL bRedraw);

/*WINUSERAPI*/
BOOL
__stdcall
GetScrollRange(
    HWND hWnd,
    int nBar,
    LPINT lpMinPos,
    LPINT lpMaxPos);

/*WINUSERAPI*/
BOOL
__stdcall
ShowScrollBar(
    HWND hWnd,
    int wBar,
    BOOL bShow);

/*WINUSERAPI*/
BOOL
__stdcall
EnableScrollBar(
    HWND hWnd,
    unsigned wSBflags,
    unsigned wArrows);


/*
 * EnableScrollBar() flags
 */
#define ESB_ENABLE_BOTH     0x0000
#define ESB_DISABLE_BOTH    0x0003

#define ESB_DISABLE_LEFT    0x0001
#define ESB_DISABLE_RIGHT   0x0002

#define ESB_DISABLE_UP      0x0001
#define ESB_DISABLE_DOWN    0x0002

#define ESB_DISABLE_LTUP    ESB_DISABLE_LEFT
#define ESB_DISABLE_RTDN    ESB_DISABLE_RIGHT


#endif  /* !NOSCROLL */

/*WINUSERAPI*/
BOOL
__stdcall
SetPropA(
    HWND hWnd,
    const char* lpString,
    HANDLE hData);
/*WINUSERAPI*/
BOOL
__stdcall
SetPropW(
    HWND hWnd,
    const wchar_t* lpString,
    HANDLE hData);
#ifdef UNICODE
#define SetProp  SetPropW
#else
#define SetProp  SetPropA
#endif // !UNICODE

/*WINUSERAPI*/
HANDLE
__stdcall
GetPropA(
    HWND hWnd,
    const char* lpString);
/*WINUSERAPI*/
HANDLE
__stdcall
GetPropW(
    HWND hWnd,
    const wchar_t* lpString);
#ifdef UNICODE
#define GetProp  GetPropW
#else
#define GetProp  GetPropA
#endif // !UNICODE

/*WINUSERAPI*/
HANDLE
__stdcall
RemovePropA(
    HWND hWnd,
    const char* lpString);
/*WINUSERAPI*/
HANDLE
__stdcall
RemovePropW(
    HWND hWnd,
    const wchar_t* lpString);
#ifdef UNICODE
#define RemoveProp  RemovePropW
#else
#define RemoveProp  RemovePropA
#endif // !UNICODE

/*WINUSERAPI*/
int
__stdcall
EnumPropsExA(
    HWND hWnd,
    PROPENUMPROCEXA lpEnumFunc,
    LPARAM lParam);
/*WINUSERAPI*/
int
__stdcall
EnumPropsExW(
    HWND hWnd,
    PROPENUMPROCEXW lpEnumFunc,
    LPARAM lParam);
#ifdef UNICODE
#define EnumPropsEx  EnumPropsExW
#else
#define EnumPropsEx  EnumPropsExA
#endif // !UNICODE

/*WINUSERAPI*/
int
__stdcall
EnumPropsA(
    HWND hWnd,
    PROPENUMPROCA lpEnumFunc);
/*WINUSERAPI*/
int
__stdcall
EnumPropsW(
    HWND hWnd,
    PROPENUMPROCW lpEnumFunc);
#ifdef UNICODE
#define EnumProps  EnumPropsW
#else
#define EnumProps  EnumPropsA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
SetWindowTextA(
    HWND hWnd,
    const char* lpString);
/*WINUSERAPI*/
BOOL
__stdcall
SetWindowTextW(
    HWND hWnd,
    const wchar_t* lpString);
#ifdef UNICODE
#define SetWindowText  SetWindowTextW
#else
#define SetWindowText  SetWindowTextA
#endif // !UNICODE

/*WINUSERAPI*/
int
__stdcall
GetWindowTextA(
    HWND hWnd,
    char* lpString,
    int nMaxCount);
/*WINUSERAPI*/
int
__stdcall
GetWindowTextW(
    HWND hWnd,
    wchar_t* lpString,
    int nMaxCount);
#ifdef UNICODE
#define GetWindowText  GetWindowTextW
#else
#define GetWindowText  GetWindowTextA
#endif // !UNICODE

/*WINUSERAPI*/
int
__stdcall
GetWindowTextLengthA(
    HWND hWnd);
/*WINUSERAPI*/
int
__stdcall
GetWindowTextLengthW(
    HWND hWnd);
#ifdef UNICODE
#define GetWindowTextLength  GetWindowTextLengthW
#else
#define GetWindowTextLength  GetWindowTextLengthA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
GetClientRect(
    HWND hWnd,
    RECT* lpRect);

/*WINUSERAPI*/
BOOL
__stdcall
GetWindowRect(
    HWND hWnd,
    RECT* lpRect);

/*WINUSERAPI*/
BOOL
__stdcall
AdjustWindowRect(
    RECT* lpRect,
    unsigned long dwStyle,
    BOOL bMenu);

/*WINUSERAPI*/
BOOL
__stdcall
AdjustWindowRectEx(
    RECT* lpRect,
    unsigned long dwStyle,
    BOOL bMenu,
    unsigned long dwExStyle);

#if(WINVER >= 0x0400)
#define HELPINFO_WINDOW    0x0001
#define HELPINFO_MENUITEM  0x0002
typedef struct tagHELPINFO      /* Structure pointed to by lParam of WM_HELP */
{
    unsigned    cbSize;             /* Size in bytes of this struct  */
    int     iContextType;       /* Either HELPINFO_WINDOW or HELPINFO_MENUITEM */
    int     iCtrlId;            /* Control Id or a Menu item Id. */
    HANDLE  hItemHandle;        /* hWnd of control or hMenu.     */
    unsigned long   dwContextId;        /* Context Id associated with this item */
    POINT   MousePos;           /* Mouse Position in screen co-ordinates */
}  HELPINFO,  *LPHELPINFO;

/*WINUSERAPI*/ BOOL  __stdcall  SetWindowContextHelpId(HWND, unsigned long);
/*WINUSERAPI*/ unsigned long __stdcall  GetWindowContextHelpId(HWND);
/*WINUSERAPI*/ BOOL  __stdcall  SetMenuContextHelpId(HMENU, unsigned long);
/*WINUSERAPI*/ unsigned long __stdcall  GetMenuContextHelpId(HMENU);

#endif /* WINVER >= 0x0400 */



#ifndef NOMB

/*
 * MessageBox() Flags
 */
#define MB_OK                       0x00000000L
#define MB_OKCANCEL                 0x00000001L
#define MB_ABORTRETRYIGNORE         0x00000002L
#define MB_YESNOCANCEL              0x00000003L
#define MB_YESNO                    0x00000004L
#define MB_RETRYCANCEL              0x00000005L


#define MB_ICONHAND                 0x00000010L
#define MB_ICONQUESTION             0x00000020L
#define MB_ICONEXCLAMATION          0x00000030L
#define MB_ICONASTERISK             0x00000040L

#if(WINVER >= 0x0400)
#define MB_USERICON                 0x00000080L
#define MB_ICONWARNING              MB_ICONEXCLAMATION
#define MB_ICONERROR                MB_ICONHAND
#endif /* WINVER >= 0x0400 */

#define MB_ICONINFORMATION          MB_ICONASTERISK
#define MB_ICONSTOP                 MB_ICONHAND

#define MB_DEFBUTTON1               0x00000000L
#define MB_DEFBUTTON2               0x00000100L
#define MB_DEFBUTTON3               0x00000200L
#if(WINVER >= 0x0400)
#define MB_DEFBUTTON4               0x00000300L
#endif /* WINVER >= 0x0400 */

#define MB_APPLMODAL                0x00000000L
#define MB_SYSTEMMODAL              0x00001000L
#define MB_TASKMODAL                0x00002000L
#if(WINVER >= 0x0400)
#define MB_HELP                     0x00004000L // Help Button
#endif /* WINVER >= 0x0400 */

#define MB_NOFOCUS                  0x00008000L
#define MB_SETFOREGROUND            0x00010000L
#define MB_DEFAULT_DESKTOP_ONLY     0x00020000L

#if(WINVER >= 0x0400)
#define MB_TOPMOST                  0x00040000L
#define MB_RIGHT                    0x00080000L
#define MB_RTLREADING               0x00100000L


#endif /* WINVER >= 0x0400 */


#ifdef _WIN32_WINNT
#if (_WIN32_WINNT >= 0x0400)
#define MB_SERVICE_NOTIFICATION          0x00200000L
#else
#define MB_SERVICE_NOTIFICATION          0x00040000L
#endif
#define MB_SERVICE_NOTIFICATION_NT3X     0x00040000L
#endif

#define MB_TYPEMASK                 0x0000000FL
#define MB_ICONMASK                 0x000000F0L
#define MB_DEFMASK                  0x00000F00L
#define MB_MODEMASK                 0x00003000L
#define MB_MISCMASK                 0x0000C000L

/*WINUSERAPI*/
int
__stdcall
MessageBoxA(
    HWND hWnd ,
    const char* lpText,
    const char* lpCaption,
    unsigned uType);
/*WINUSERAPI*/
int
__stdcall
MessageBoxW(
    HWND hWnd ,
    const wchar_t* lpText,
    const wchar_t* lpCaption,
    unsigned uType);
#ifdef UNICODE
#define MessageBox  MessageBoxW
#else
#define MessageBox  MessageBoxA
#endif // !UNICODE

/*WINUSERAPI*/
int
__stdcall
MessageBoxExA(
    HWND hWnd ,
    const char* lpText,
    const char* lpCaption,
    unsigned uType,
    WORD wLanguageId);
/*WINUSERAPI*/
int
__stdcall
MessageBoxExW(
    HWND hWnd ,
    const wchar_t* lpText,
    const wchar_t* lpCaption,
    unsigned uType,
    WORD wLanguageId);
#ifdef UNICODE
#define MessageBoxEx  MessageBoxExW
#else
#define MessageBoxEx  MessageBoxExA
#endif // !UNICODE

#if(WINVER >= 0x0400)

typedef void (__stdcall *MSGBOXCALLBACK)(LPHELPINFO lpHelpInfo);

typedef struct tagMSGBOXPARAMSA
{
    unsigned        cbSize;
    HWND        hwndOwner;
    HINSTANCE   hInstance;
    const char*      lpszText;
    const char*      lpszCaption;
    unsigned long       dwStyle;
    const char*      lpszIcon;
    unsigned long       dwContextHelpId;
    MSGBOXCALLBACK      lpfnMsgBoxCallback;
    unsigned long   dwLanguageId;
} MSGBOXPARAMSA, *PMSGBOXPARAMSA, *LPMSGBOXPARAMSA;
typedef struct tagMSGBOXPARAMSW
{
    unsigned        cbSize;
    HWND        hwndOwner;
    HINSTANCE   hInstance;
    const wchar_t*     lpszText;
    const wchar_t*     lpszCaption;
    unsigned long       dwStyle;
    const wchar_t*     lpszIcon;
    unsigned long       dwContextHelpId;
    MSGBOXCALLBACK      lpfnMsgBoxCallback;
    unsigned long   dwLanguageId;
} MSGBOXPARAMSW, *PMSGBOXPARAMSW, *LPMSGBOXPARAMSW;
#ifdef UNICODE
typedef MSGBOXPARAMSW MSGBOXPARAMS;
typedef PMSGBOXPARAMSW PMSGBOXPARAMS;
typedef LPMSGBOXPARAMSW LPMSGBOXPARAMS;
#else
typedef MSGBOXPARAMSA MSGBOXPARAMS;
typedef PMSGBOXPARAMSA PMSGBOXPARAMS;
typedef LPMSGBOXPARAMSA LPMSGBOXPARAMS;
#endif // UNICODE


/*WINUSERAPI*/ int     __stdcall MessageBoxIndirectA(LPMSGBOXPARAMSA);
/*WINUSERAPI*/ int     __stdcall MessageBoxIndirectW(LPMSGBOXPARAMSW);
#ifdef UNICODE
#define MessageBoxIndirect  MessageBoxIndirectW
#else
#define MessageBoxIndirect  MessageBoxIndirectA
#endif // !UNICODE
#endif /* WINVER >= 0x0400 */



/*WINUSERAPI*/
BOOL
__stdcall
MessageBeep(
    unsigned uType);

#endif /* !NOMB */

/*WINUSERAPI*/
int
__stdcall
ShowCursor(
    BOOL bShow);

/*WINUSERAPI*/
BOOL
__stdcall
SetCursorPos(
    int X,
    int Y);

/*WINUSERAPI*/
HCURSOR
__stdcall
SetCursor(
    HCURSOR hCursor);

/*WINUSERAPI*/
BOOL
__stdcall
GetCursorPos(
    LPPOINT lpPoint);

/*WINUSERAPI*/
BOOL
__stdcall
ClipCursor(
    const RECT *lpRect);

/*WINUSERAPI*/
BOOL
__stdcall
GetClipCursor(
    RECT* lpRect);

/*WINUSERAPI*/
HCURSOR
__stdcall
GetCursor(
    VOID);

/*WINUSERAPI*/
BOOL
__stdcall
CreateCaret(
    HWND hWnd,
    HBITMAP hBitmap ,
    int nWidth,
    int nHeight);

/*WINUSERAPI*/
unsigned
__stdcall
GetCaretBlinkTime(
    VOID);

/*WINUSERAPI*/
BOOL
__stdcall
SetCaretBlinkTime(
    unsigned uMSeconds);

/*WINUSERAPI*/
BOOL
__stdcall
DestroyCaret(
    VOID);

/*WINUSERAPI*/
BOOL
__stdcall
HideCaret(
    HWND hWnd);

/*WINUSERAPI*/
BOOL
__stdcall
ShowCaret(
    HWND hWnd);

/*WINUSERAPI*/
BOOL
__stdcall
SetCaretPos(
    int X,
    int Y);

/*WINUSERAPI*/
BOOL
__stdcall
GetCaretPos(
    LPPOINT lpPoint);

/*WINUSERAPI*/
BOOL
__stdcall
ClientToScreen(
    HWND hWnd,
    LPPOINT lpPoint);

/*WINUSERAPI*/
BOOL
__stdcall
ScreenToClient(
    HWND hWnd,
    LPPOINT lpPoint);

/*WINUSERAPI*/
int
__stdcall
MapWindowPoints(
    HWND hWndFrom,
    HWND hWndTo,
    LPPOINT lpPoints,
    unsigned cPoints);

/*WINUSERAPI*/
HWND
__stdcall
WindowFromPoint(
    POINT Point);

/*WINUSERAPI*/
HWND
__stdcall
ChildWindowFromPoint(
    HWND hWndParent,
    POINT Point);

#if(WINVER >= 0x0400)
#define CWP_ALL             0x0000
#define CWP_SKIPINVISIBLE   0x0001
#define CWP_SKIPDISABLED    0x0002
#define CWP_SKIPTRANSPARENT 0x0004

/*WINUSERAPI*/ HWND    __stdcall ChildWindowFromPointEx(HWND, POINT, unsigned);
#endif /* WINVER >= 0x0400 */

#ifndef NOCOLOR

/*
 * Color Types
 */
#define CTLCOLOR_MSGBOX         0
#define CTLCOLOR_EDIT           1
#define CTLCOLOR_LISTBOX        2
#define CTLCOLOR_BTN            3
#define CTLCOLOR_DLG            4
#define CTLCOLOR_SCROLLBAR      5
#define CTLCOLOR_STATIC         6
#define CTLCOLOR_MAX            7

#define COLOR_SCROLLBAR         0
#define COLOR_BACKGROUND        1
#define COLOR_ACTIVECAPTION     2
#define COLOR_INACTIVECAPTION   3
#define COLOR_MENU              4
#define COLOR_WINDOW            5
#define COLOR_WINDOWFRAME       6
#define COLOR_MENUTEXT          7
#define COLOR_WINDOWTEXT        8
#define COLOR_CAPTIONTEXT       9
#define COLOR_ACTIVEBORDER      10
#define COLOR_INACTIVEBORDER    11
#define COLOR_APPWORKSPACE      12
#define COLOR_HIGHLIGHT         13
#define COLOR_HIGHLIGHTTEXT     14
#define COLOR_BTNFACE           15
#define COLOR_BTNSHADOW         16
#define COLOR_GRAYTEXT          17
#define COLOR_BTNTEXT           18
#define COLOR_INACTIVECAPTIONTEXT 19
#define COLOR_BTNHIGHLIGHT      20

#if(WINVER >= 0x0400)
#define COLOR_3DDKSHADOW        21
#define COLOR_3DLIGHT           22
#define COLOR_INFOTEXT          23
#define COLOR_INFOBK            24

#define COLOR_DESKTOP           COLOR_BACKGROUND
#define COLOR_3DFACE            COLOR_BTNFACE
#define COLOR_3DSHADOW          COLOR_BTNSHADOW
#define COLOR_3DHIGHLIGHT       COLOR_BTNHIGHLIGHT
#define COLOR_3DHILIGHT         COLOR_BTNHIGHLIGHT
#define COLOR_BTNHILIGHT        COLOR_BTNHIGHLIGHT
#endif /* WINVER >= 0x0400 */


/*WINUSERAPI*/
unsigned long
__stdcall
GetSysColor(
    int nIndex);

#if(WINVER >= 0x0400)
/*WINUSERAPI*/
HBRUSH
__stdcall
GetSysColorBrush(
    int nIndex);


#endif /* WINVER >= 0x0400 */

/*WINUSERAPI*/
BOOL
__stdcall
SetSysColors(
    int cElements,
    const int * lpaElements,
    const COLORREF * lpaRgbValues);

#endif /* !NOCOLOR */

/*WINUSERAPI*/
BOOL
__stdcall
DrawFocusRect(
    HDC hDC,
    const RECT * lprc);

/*WINUSERAPI*/
int
__stdcall
FillRect(
    HDC hDC,
    const RECT *lprc,
    HBRUSH hbr);

/*WINUSERAPI*/
int
__stdcall
FrameRect(
    HDC hDC,
    const RECT *lprc,
    HBRUSH hbr);

/*WINUSERAPI*/
BOOL
__stdcall
InvertRect(
    HDC hDC,
    const RECT *lprc);

/*WINUSERAPI*/
BOOL
__stdcall
SetRect(
    RECT* lprc,
    int xLeft,
    int yTop,
    int xRight,
    int yBottom);

/*WINUSERAPI*/
BOOL
__stdcall
    SetRectEmpty(
    RECT* lprc);

/*WINUSERAPI*/
BOOL
__stdcall
CopyRect(
    RECT* lprcDst,
    const RECT *lprcSrc);

/*WINUSERAPI*/
BOOL
__stdcall
InflateRect(
    RECT* lprc,
    int dx,
    int dy);

/*WINUSERAPI*/
BOOL
__stdcall
IntersectRect(
    RECT* lprcDst,
    const RECT *lprcSrc1,
    const RECT *lprcSrc2);

/*WINUSERAPI*/
BOOL
__stdcall
UnionRect(
    RECT* lprcDst,
    const RECT *lprcSrc1,
    const RECT *lprcSrc2);

/*WINUSERAPI*/
BOOL
__stdcall
SubtractRect(
    RECT* lprcDst,
    const RECT *lprcSrc1,
    const RECT *lprcSrc2);

/*WINUSERAPI*/
BOOL
__stdcall
OffsetRect(
    RECT* lprc,
    int dx,
    int dy);

/*WINUSERAPI*/
BOOL
__stdcall
IsRectEmpty(
    const RECT *lprc);

/*WINUSERAPI*/
BOOL
__stdcall
EqualRect(
    const RECT *lprc1,
    const RECT *lprc2);

/*WINUSERAPI*/
BOOL
__stdcall
PtInRect(
    const RECT *lprc,
    POINT pt);

#ifndef NOWINOFFSETS

/*WINUSERAPI*/
WORD
__stdcall
GetWindowWord(
    HWND hWnd,
    int nIndex);

/*WINUSERAPI*/
WORD
__stdcall
SetWindowWord(
    HWND hWnd,
    int nIndex,
    WORD wNewWord);

/*WINUSERAPI*/
long
__stdcall
GetWindowLongA(
    HWND hWnd,
    int nIndex);
/*WINUSERAPI*/
long
__stdcall
GetWindowLongW(
    HWND hWnd,
    int nIndex);
#ifdef UNICODE
#define GetWindowLong  GetWindowLongW
#else
#define GetWindowLong  GetWindowLongA
#endif // !UNICODE

/*WINUSERAPI*/
long
__stdcall
SetWindowLongA(
    HWND hWnd,
    int nIndex,
    long dwNewLong);
/*WINUSERAPI*/
long
__stdcall
SetWindowLongW(
    HWND hWnd,
    int nIndex,
    long dwNewLong);
#ifdef UNICODE
#define SetWindowLong  SetWindowLongW
#else
#define SetWindowLong  SetWindowLongA
#endif // !UNICODE

/*WINUSERAPI*/
WORD
__stdcall
GetClassWord(
    HWND hWnd,
    int nIndex);

/*WINUSERAPI*/
WORD
__stdcall
SetClassWord(
    HWND hWnd,
    int nIndex,
    WORD wNewWord);

/*WINUSERAPI*/
unsigned long
__stdcall
GetClassLongA(
    HWND hWnd,
    int nIndex);
/*WINUSERAPI*/
unsigned long
__stdcall
GetClassLongW(
    HWND hWnd,
    int nIndex);
#ifdef UNICODE
#define GetClassLong  GetClassLongW
#else
#define GetClassLong  GetClassLongA
#endif // !UNICODE

/*WINUSERAPI*/
unsigned long
__stdcall
SetClassLongA(
    HWND hWnd,
    int nIndex,
    long dwNewLong);
/*WINUSERAPI*/
unsigned long
__stdcall
SetClassLongW(
    HWND hWnd,
    int nIndex,
    long dwNewLong);
#ifdef UNICODE
#define SetClassLong  SetClassLongW
#else
#define SetClassLong  SetClassLongA
#endif // !UNICODE

#endif /* !NOWINOFFSETS */

/*WINUSERAPI*/
HWND
__stdcall
GetDesktopWindow(
    VOID);


/*WINUSERAPI*/
HWND
__stdcall
GetParent(
    HWND hWnd);

/*WINUSERAPI*/
HWND
__stdcall
SetParent(
    HWND hWndChild,
    HWND hWndNewParent);

/*WINUSERAPI*/
BOOL
__stdcall
EnumChildWindows(
    HWND hWndParent,
    WNDENUMPROC lpEnumFunc,
    LPARAM lParam);

/*WINUSERAPI*/
HWND
__stdcall
FindWindowA(
    const char* lpClassName ,
    const char* lpWindowName);
/*WINUSERAPI*/
HWND
__stdcall
FindWindowW(
    const wchar_t* lpClassName ,
    const wchar_t* lpWindowName);
#ifdef UNICODE
#define FindWindow  FindWindowW
#else
#define FindWindow  FindWindowA
#endif // !UNICODE

#if(WINVER >= 0x0400)
/*WINUSERAPI*/ HWND    __stdcall FindWindowExA(HWND, HWND, const char*, const char*);
/*WINUSERAPI*/ HWND    __stdcall FindWindowExW(HWND, HWND, const wchar_t*, const wchar_t*);
#ifdef UNICODE
#define FindWindowEx  FindWindowExW
#else
#define FindWindowEx  FindWindowExA
#endif // !UNICODE

#endif /* WINVER >= 0x0400 */


/*WINUSERAPI*/
BOOL
__stdcall
EnumWindows(
    WNDENUMPROC lpEnumFunc,
    LPARAM lParam);

/*WINUSERAPI*/
BOOL
__stdcall
EnumThreadWindows(
    unsigned long dwThreadId,
    WNDENUMPROC lpfn,
    LPARAM lParam);

#define EnumTaskWindows(hTask, lpfn, lParam) EnumThreadWindows((unsigned long)hTask, lpfn, lParam)

/*WINUSERAPI*/
int
__stdcall
GetClassNameA(
    HWND hWnd,
    char* lpClassName,
    int nMaxCount);
/*WINUSERAPI*/
int
__stdcall
GetClassNameW(
    HWND hWnd,
    wchar_t* lpClassName,
    int nMaxCount);
#ifdef UNICODE
#define GetClassName  GetClassNameW
#else
#define GetClassName  GetClassNameA
#endif // !UNICODE

/*WINUSERAPI*/
HWND
__stdcall
GetTopWindow(
    HWND hWnd);

#define GetNextWindow(hWnd, wCmd) GetWindow(hWnd, wCmd)
#define GetSysModalWindow() (NULL)
#define SetSysModalWindow(hWnd) (NULL)

/*WINUSERAPI*/
unsigned long
__stdcall
GetWindowThreadProcessId(
    HWND hWnd,
    unsigned long* lpdwProcessId);

#define GetWindowTask(hWnd) \
        ((HANDLE)GetWindowThreadProcessId(hWnd, NULL))

/*WINUSERAPI*/
HWND
__stdcall
GetLastActivePopup(
    HWND hWnd);

/*
 * GetWindow() Constants
 */
#define GW_HWNDFIRST        0
#define GW_HWNDLAST         1
#define GW_HWNDNEXT         2
#define GW_HWNDPREV         3
#define GW_OWNER            4
#define GW_CHILD            5
#define GW_MAX              5

/*WINUSERAPI*/
HWND
__stdcall
GetWindow(
    HWND hWnd,
    unsigned uCmd);



#ifndef NOWH

#ifdef STRICT

/*WINUSERAPI*/
HHOOK
__stdcall
SetWindowsHookA(
    int nFilterType,
    HOOKPROC pfnFilterProc);
/*WINUSERAPI*/
HHOOK
__stdcall
SetWindowsHookW(
    int nFilterType,
    HOOKPROC pfnFilterProc);
#ifdef UNICODE
#define SetWindowsHook  SetWindowsHookW
#else
#define SetWindowsHook  SetWindowsHookA
#endif // !UNICODE

#else /* !STRICT */

/*WINUSERAPI*/
HOOKPROC
__stdcall
SetWindowsHookA(
    int nFilterType,
    HOOKPROC pfnFilterProc);
/*WINUSERAPI*/
HOOKPROC
__stdcall
SetWindowsHookW(
    int nFilterType,
    HOOKPROC pfnFilterProc);
#ifdef UNICODE
#define SetWindowsHook  SetWindowsHookW
#else
#define SetWindowsHook  SetWindowsHookA
#endif // !UNICODE

#endif /* !STRICT */

/*WINUSERAPI*/
BOOL
__stdcall
UnhookWindowsHook(
    int nCode,
    HOOKPROC pfnFilterProc);

/*WINUSERAPI*/
HHOOK
__stdcall
SetWindowsHookExA(
    int idHook,
    HOOKPROC lpfn,
    HINSTANCE hmod,
    unsigned long dwThreadId);
/*WINUSERAPI*/
HHOOK
__stdcall
SetWindowsHookExW(
    int idHook,
    HOOKPROC lpfn,
    HINSTANCE hmod,
    unsigned long dwThreadId);
#ifdef UNICODE
#define SetWindowsHookEx  SetWindowsHookExW
#else
#define SetWindowsHookEx  SetWindowsHookExA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
UnhookWindowsHookEx(
    HHOOK hhk);

/*WINUSERAPI*/
LRESULT
__stdcall
CallNextHookEx(
    HHOOK hhk,
    int nCode,
    WPARAM wParam,
    LPARAM lParam);

/*
 * Macros for source-level compatibility with old functions.
 */
#ifdef STRICT
#define DefHookProc(nCode, wParam, lParam, phhk)\
        CallNextHookEx(*phhk, nCode, wParam, lParam)
#else
#define DefHookProc(nCode, wParam, lParam, phhk)\
        CallNextHookEx((HHOOK)*phhk, nCode, wParam, lParam)
#endif /* STRICT */

#endif /* !NOWH */

#ifndef NOMENUS

// begin_r_winuser

/* ;win40  -- A lot of MF_* flags have been renamed as MFT_* and MFS_* flags */
/*
 * Menu flags for Add/Check/EnableMenuItem()
 */
#define MF_INSERT           0x00000000L
#define MF_CHANGE           0x00000080L
#define MF_APPEND           0x00000100L
#define MF_DELETE           0x00000200L
#define MF_REMOVE           0x00001000L

#define MF_BYCOMMAND        0x00000000L
#define MF_BYPOSITION       0x00000400L

#define MF_SEPARATOR        0x00000800L

#define MF_ENABLED          0x00000000L
#define MF_GRAYED           0x00000001L
#define MF_DISABLED         0x00000002L

#define MF_UNCHECKED        0x00000000L
#define MF_CHECKED          0x00000008L
#define MF_USECHECKBITMAPS  0x00000200L

#define MF_STRING           0x00000000L
#define MF_BITMAP           0x00000004L
#define MF_OWNERDRAW        0x00000100L

#define MF_POPUP            0x00000010L
#define MF_MENUBARBREAK     0x00000020L
#define MF_MENUBREAK        0x00000040L

#define MF_UNHILITE         0x00000000L
#define MF_HILITE           0x00000080L

#if(WINVER >= 0x0400)
#define MF_DEFAULT          0x00001000L
#endif /* WINVER >= 0x0400 */
#define MF_SYSMENU          0x00002000L
#define MF_HELP             0x00004000L
#if(WINVER >= 0x0400)
#define MF_RIGHTJUSTIFY     0x00004000L
#endif /* WINVER >= 0x0400 */

#define MF_MOUSESELECT      0x00008000L
#if(WINVER >= 0x0400)
#define MF_END              0x00000080L  /* Obsolete -- only used by old RES files */
#endif /* WINVER >= 0x0400 */


#if(WINVER >= 0x0400)
#define MFT_STRING          MF_STRING
#define MFT_BITMAP          MF_BITMAP
#define MFT_MENUBARBREAK    MF_MENUBARBREAK
#define MFT_MENUBREAK       MF_MENUBREAK
#define MFT_OWNERDRAW       MF_OWNERDRAW
#define MFT_RADIOCHECK      0x00000200L
#define MFT_SEPARATOR       MF_SEPARATOR
#define MFT_RIGHTORDER      0x00002000L
#define MFT_RIGHTJUSTIFY    MF_RIGHTJUSTIFY

/* Menu flags for Add/Check/EnableMenuItem() */
#define MFS_GRAYED          0x00000003L
#define MFS_DISABLED        MFS_GRAYED
#define MFS_CHECKED         MF_CHECKED
#define MFS_HILITE          MF_HILITE
#define MFS_ENABLED         MF_ENABLED
#define MFS_UNCHECKED       MF_UNCHECKED
#define MFS_UNHILITE        MF_UNHILITE
#define MFS_DEFAULT         MF_DEFAULT



#endif /* WINVER >= 0x0400 */

// end_r_winuser

#if(WINVER >= 0x0400)

/*WINUSERAPI*/
BOOL
__stdcall
CheckMenuRadioItem(HMENU, unsigned, unsigned, unsigned, unsigned);
#endif /* WINVER >= 0x0400 */



/*
 * Menu item resource format
 */
typedef struct {
    WORD versionNumber;
    WORD offset;
} MENUITEMTEMPLATEHEADER, *PMENUITEMTEMPLATEHEADER;

typedef struct {        // version 0
    WORD mtOption;
    WORD mtID;
    wchar_t mtString[1];
} MENUITEMTEMPLATE, *PMENUITEMTEMPLATE;
#define MF_END             0x00000080L          // r_winuser

#endif /* !NOMENUS */

#ifndef NOSYSCOMMANDS

// begin_r_winuser
/*
 * System Menu Command Values
 */
#define SC_SIZE         0xF000
#define SC_MOVE         0xF010
#define SC_MINIMIZE     0xF020
#define SC_MAXIMIZE     0xF030
#define SC_NEXTWINDOW   0xF040
#define SC_PREVWINDOW   0xF050
#define SC_CLOSE        0xF060
#define SC_VSCROLL      0xF070
#define SC_HSCROLL      0xF080
#define SC_MOUSEMENU    0xF090
#define SC_KEYMENU      0xF100
#define SC_ARRANGE      0xF110
#define SC_RESTORE      0xF120
#define SC_TASKLIST     0xF130
#define SC_SCREENSAVE   0xF140
#define SC_HOTKEY       0xF150
#if(WINVER >= 0x0400)
#define SC_DEFAULT      0xF160
#define SC_MONITORPOWER 0xF170
#define SC_CONTEXTHELP  0xF180
#define SC_SEPARATOR    0xF00F
#endif /* WINVER >= 0x0400 */
/*
 * Obsolete names
 */
#define SC_ICON         SC_MINIMIZE
#define SC_ZOOM         SC_MAXIMIZE

// end_r_winuser
#endif /* !NOSYSCOMMANDS */

/*
 * Resource Loading Routines
 */

/*WINUSERAPI*/
HBITMAP
__stdcall
LoadBitmapA(
    HINSTANCE hInstance,
    const char* lpBitmapName);
/*WINUSERAPI*/
HBITMAP
__stdcall
LoadBitmapW(
    HINSTANCE hInstance,
    const wchar_t* lpBitmapName);
#ifdef UNICODE
#define LoadBitmap  LoadBitmapW
#else
#define LoadBitmap  LoadBitmapA
#endif // !UNICODE

/*WINUSERAPI*/
HCURSOR
__stdcall
LoadCursorA(
    HINSTANCE hInstance,
    const char* lpCursorName);
/*WINUSERAPI*/
HCURSOR
__stdcall
LoadCursorW(
    HINSTANCE hInstance,
    const wchar_t* lpCursorName);
#ifdef UNICODE
#define LoadCursor  LoadCursorW
#else
#define LoadCursor  LoadCursorA
#endif // !UNICODE

/*WINUSERAPI*/
HCURSOR
__stdcall
LoadCursorFromFileA(
    const char*    lpFileName);
/*WINUSERAPI*/
HCURSOR
__stdcall
LoadCursorFromFileW(
    const wchar_t*    lpFileName);
#ifdef UNICODE
#define LoadCursorFromFile  LoadCursorFromFileW
#else
#define LoadCursorFromFile  LoadCursorFromFileA
#endif // !UNICODE

/*WINUSERAPI*/
HCURSOR
__stdcall
CreateCursor(
    HINSTANCE hInst,
    int xHotSpot,
    int yHotSpot,
    int nWidth,
    int nHeight,
    const VOID *pvANDPlane,
    const VOID *pvXORPlane);

/*WINUSERAPI*/
BOOL
__stdcall
DestroyCursor(
    HCURSOR hCursor);

#define CopyCursor(pcur) ((HCURSOR)CopyIcon((HICON)(pcur)))

/*
 * Standard Cursor IDs
 */
#define IDC_ARROW           MAKEINTRESOURCE(32512)
#define IDC_IBEAM           MAKEINTRESOURCE(32513)
#define IDC_WAIT            MAKEINTRESOURCE(32514)
#define IDC_CROSS           MAKEINTRESOURCE(32515)
#define IDC_UPARROW         MAKEINTRESOURCE(32516)
#define IDC_SIZE            MAKEINTRESOURCE(32640)  /* OBSOLETE: use IDC_SIZEALL */
#define IDC_ICON            MAKEINTRESOURCE(32641)  /* OBSOLETE: use IDC_ARROW */
#define IDC_SIZENWSE        MAKEINTRESOURCE(32642)
#define IDC_SIZENESW        MAKEINTRESOURCE(32643)
#define IDC_SIZEWE          MAKEINTRESOURCE(32644)
#define IDC_SIZENS          MAKEINTRESOURCE(32645)
#define IDC_SIZEALL         MAKEINTRESOURCE(32646)
#define IDC_NO              MAKEINTRESOURCE(32648) /*not in win3.1 */
#define IDC_APPSTARTING     MAKEINTRESOURCE(32650) /*not in win3.1 */
#if(WINVER >= 0x0400)
#define IDC_HELP            MAKEINTRESOURCE(32651)
#endif /* WINVER >= 0x0400 */

/*WINUSERAPI*/
BOOL
__stdcall
SetSystemCursor(
    HCURSOR hcur,
    unsigned long   id);

typedef struct _ICONINFO {
    BOOL    fIcon;
    unsigned long   xHotspot;
    unsigned long   yHotspot;
    HBITMAP hbmMask;
    HBITMAP hbmColor;
} ICONINFO;
typedef ICONINFO *PICONINFO;

/*WINUSERAPI*/
HICON
__stdcall
LoadIconA(
    HINSTANCE hInstance,
    const char* lpIconName);
/*WINUSERAPI*/
HICON
__stdcall
LoadIconW(
    HINSTANCE hInstance,
    const wchar_t* lpIconName);
#ifdef UNICODE
#define LoadIcon  LoadIconW
#else
#define LoadIcon  LoadIconA
#endif // !UNICODE


/*WINUSERAPI*/
HICON
__stdcall
CreateIcon(
    HINSTANCE hInstance,
    int nWidth,
    int nHeight,
    BYTE cPlanes,
    BYTE cBitsPixel,
    const BYTE *lpbANDbits,
    const BYTE *lpbXORbits);

/*WINUSERAPI*/
BOOL
__stdcall
DestroyIcon(
    HICON hIcon);

/*WINUSERAPI*/
int
__stdcall
LookupIconIdFromDirectory(
    PBYTE presbits,
    BOOL fIcon);

#if(WINVER >= 0x0400)
/*WINUSERAPI*/
int
__stdcall
LookupIconIdFromDirectoryEx(
    PBYTE presbits,
    BOOL  fIcon,
    int   cxDesired,
    int   cyDesired,
    unsigned  Flags);
#endif /* WINVER >= 0x0400 */

/*WINUSERAPI*/
HICON
__stdcall
CreateIconFromResource(
    PBYTE presbits,
    unsigned long dwResSize,
    BOOL fIcon,
    unsigned long dwVer);

#if(WINVER >= 0x0400)
/*WINUSERAPI*/
HICON
__stdcall
CreateIconFromResourceEx(
    PBYTE presbits,
    unsigned long dwResSize,
    BOOL  fIcon,
    unsigned long dwVer,
    int   cxDesired,
    int   cyDesired,
    unsigned  Flags);

/* Icon/Cursor header */
typedef struct tagCURSORSHAPE
{
    int     xHotSpot;
    int     yHotSpot;
    int     cx;
    int     cy;
    int     cbWidth;
    BYTE    Planes;
    BYTE    BitsPixel;
} CURSORSHAPE,  *LPCURSORSHAPE;
#endif /* WINVER >= 0x0400 */

#define IMAGE_BITMAP        0
#define IMAGE_ICON          1
#define IMAGE_CURSOR        2
#if(WINVER >= 0x0400)
#define IMAGE_ENHMETAFILE   3

#define LR_DEFAULTCOLOR     0x0000
#define LR_MONOCHROME       0x0001
#define LR_COLOR            0x0002
#define LR_COPYRETURNORG    0x0004
#define LR_COPYDELETEORG    0x0008
#define LR_LOADFROMFILE     0x0010
#define LR_LOADTRANSPARENT  0x0020
#define LR_DEFAULTSIZE      0x0040
#define LR_VGACOLOR         0x0080
#define LR_LOADMAP3DCOLORS  0x1000
#define LR_CREATEDIBSECTION 0x2000
#define LR_COPYFROMRESOURCE 0x4000
#define LR_SHARED           0x8000

/*WINUSERAPI*/
HANDLE
__stdcall
LoadImageA(
    HINSTANCE,
    const char*,
    unsigned,
    int,
    int,
    unsigned);
/*WINUSERAPI*/
HANDLE
__stdcall
LoadImageW(
    HINSTANCE,
    const wchar_t*,
    unsigned,
    int,
    int,
    unsigned);
#ifdef UNICODE
#define LoadImage  LoadImageW
#else
#define LoadImage  LoadImageA
#endif // !UNICODE

/*WINUSERAPI*/
HANDLE
__stdcall
CopyImage(
    HANDLE,
    unsigned,
    int,
    int,
    unsigned);

#define DI_MASK         0x0001
#define DI_IMAGE        0x0002
#define DI_NORMAL       0x0003
#define DI_COMPAT       0x0004
#define DI_DEFAULTSIZE  0x0008


/*WINUSERAPI*/ BOOL __stdcall DrawIconEx(HDC hdc, int xLeft, int yTop,
              HICON hIcon, int cxWidth, int cyWidth,
              unsigned istepIfAniCur, HBRUSH hbrFlickerFreeDraw, unsigned diFlags);
#endif /* WINVER >= 0x0400 */

/*WINUSERAPI*/
HICON
__stdcall
CreateIconIndirect(
    PICONINFO piconinfo);

/*WINUSERAPI*/
HICON
__stdcall
CopyIcon(
    HICON hIcon);

/*WINUSERAPI*/
BOOL
__stdcall
GetIconInfo(
    HICON hIcon,
    PICONINFO piconinfo);

#if(WINVER >= 0x0400)
#define RES_ICON    1
#define RES_CURSOR  2
#endif /* WINVER >= 0x0400 */

#ifdef OEMRESOURCE

// begin_r_winuser

/*
 * OEM Resource Ordinal Numbers
 */
#define OBM_CLOSE           32754
#define OBM_UPARROW         32753
#define OBM_DNARROW         32752
#define OBM_RGARROW         32751
#define OBM_LFARROW         32750
#define OBM_REDUCE          32749
#define OBM_ZOOM            32748
#define OBM_RESTORE         32747
#define OBM_REDUCED         32746
#define OBM_ZOOMD           32745
#define OBM_RESTORED        32744
#define OBM_UPARROWD        32743
#define OBM_DNARROWD        32742
#define OBM_RGARROWD        32741
#define OBM_LFARROWD        32740
#define OBM_MNARROW         32739
#define OBM_COMBO           32738
#define OBM_UPARROWI        32737
#define OBM_DNARROWI        32736
#define OBM_RGARROWI        32735
#define OBM_LFARROWI        32734

#define OBM_OLD_CLOSE       32767
#define OBM_SIZE            32766
#define OBM_OLD_UPARROW     32765
#define OBM_OLD_DNARROW     32764
#define OBM_OLD_RGARROW     32763
#define OBM_OLD_LFARROW     32762
#define OBM_BTSIZE          32761
#define OBM_CHECK           32760
#define OBM_CHECKBOXES      32759
#define OBM_BTNCORNERS      32758
#define OBM_OLD_REDUCE      32757
#define OBM_OLD_ZOOM        32756
#define OBM_OLD_RESTORE     32755

#define OCR_NORMAL          32512
#define OCR_IBEAM           32513
#define OCR_WAIT            32514
#define OCR_CROSS           32515
#define OCR_UP              32516
#define OCR_SIZE            32640   /* OBSOLETE: use OCR_SIZEALL */
#define OCR_ICON            32641   /* OBSOLETE: use OCR_NORMAL */
#define OCR_SIZENWSE        32642
#define OCR_SIZENESW        32643
#define OCR_SIZEWE          32644
#define OCR_SIZENS          32645
#define OCR_SIZEALL         32646
#define OCR_ICOCUR          32647   /* OBSOLETE: use OIC_WINLOGO */
#define OCR_NO              32648
#if(WINVER >= 0x0400)
#define OCR_APPSTARTING     32650
#endif /* WINVER >= 0x0400 */



#define OIC_SAMPLE          32512
#define OIC_HAND            32513
#define OIC_QUES            32514
#define OIC_BANG            32515
#define OIC_NOTE            32516
#if(WINVER >= 0x0400)
#define OIC_WINLOGO         32517
#define OIC_WARNING         OIC_BANG
#define OIC_ERROR           OIC_HAND
#define OIC_INFORMATION     OIC_NOTE
#endif /* WINVER >= 0x0400 */


// end_r_winuser

#endif /* OEMRESOURCE */

#define ORD_LANGDRIVER    1     /* The ordinal number for the entry point of
                                ** language drivers.
                                */

#ifndef NOICONS

// begin_r_winuser
/*
 * Standard Icon IDs
 */
#ifdef RC_INVOKED
#define IDI_APPLICATION     32512
#define IDI_HAND            32513
#define IDI_QUESTION        32514
#define IDI_EXCLAMATION     32515
#define IDI_ASTERISK        32516
#if(WINVER >= 0x0400)
#define IDI_WINLOGO         32517
#endif /* WINVER >= 0x0400 */
#else
#define IDI_APPLICATION     MAKEINTRESOURCE(32512)
#define IDI_HAND            MAKEINTRESOURCE(32513)
#define IDI_QUESTION        MAKEINTRESOURCE(32514)
#define IDI_EXCLAMATION     MAKEINTRESOURCE(32515)
#define IDI_ASTERISK        MAKEINTRESOURCE(32516)
#if(WINVER >= 0x0400)
#define IDI_WINLOGO         MAKEINTRESOURCE(32517)
#endif /* WINVER >= 0x0400 */
#endif /* RC_INVOKED */

#if(WINVER >= 0x0400)
#define IDI_WARNING     IDI_EXCLAMATION
#define IDI_ERROR       IDI_HAND
#define IDI_INFORMATION IDI_ASTERISK
#endif /* WINVER >= 0x0400 */

// end_r_winuser

#endif /* !NOICONS */

/*WINUSERAPI*/
int
__stdcall
LoadStringA(
    HINSTANCE hInstance,
    unsigned uID,
    char* lpBuffer,
    int nBufferMax);
/*WINUSERAPI*/
int
__stdcall
LoadStringW(
    HINSTANCE hInstance,
    unsigned uID,
    wchar_t* lpBuffer,
    int nBufferMax);
#ifdef UNICODE
#define LoadString  LoadStringW
#else
#define LoadString  LoadStringA
#endif // !UNICODE

// begin_r_winuser

/*
 * Dialog Box Command IDs
 */
#define IDOK                1
#define IDCANCEL            2
#define IDABORT             3
#define IDRETRY             4
#define IDIGNORE            5
#define IDYES               6
#define IDNO                7
#if(WINVER >= 0x0400)
#define IDCLOSE         8
#define IDHELP          9
#endif /* WINVER >= 0x0400 */

// end_r_winuser

#ifndef NOCTLMGR

/*
 * Control Manager Structures and Definitions
 */

#ifndef NOWINSTYLES

// begin_r_winuser

/*
 * Edit Control Styles
 */
#define ES_LEFT             0x0000L
#define ES_CENTER           0x0001L
#define ES_RIGHT            0x0002L
#define ES_MULTILINE        0x0004L
#define ES_UPPERCASE        0x0008L
#define ES_LOWERCASE        0x0010L
#define ES_PASSWORD         0x0020L
#define ES_AUTOVSCROLL      0x0040L
#define ES_AUTOHSCROLL      0x0080L
#define ES_NOHIDESEL        0x0100L
#define ES_OEMCONVERT       0x0400L
#define ES_READONLY         0x0800L
#define ES_WANTRETURN       0x1000L
#if(WINVER >= 0x0400)
#define ES_NUMBER           0x2000L
#endif /* WINVER >= 0x0400 */

// end_r_winuser

#endif /* !NOWINSTYLES */

/*
 * Edit Control Notification Codes
 */
#define EN_SETFOCUS         0x0100
#define EN_KILLFOCUS        0x0200
#define EN_CHANGE           0x0300
#define EN_UPDATE           0x0400
#define EN_ERRSPACE         0x0500
#define EN_MAXTEXT          0x0501
#define EN_HSCROLL          0x0601
#define EN_VSCROLL          0x0602

#if(WINVER >= 0x0400)
/* Edit control EM_SETMARGIN parameters */
#define EC_LEFTMARGIN       0x0001
#define EC_RIGHTMARGIN      0x0002
#define EC_USEFONTINFO      0xffff
#endif /* WINVER >= 0x0400 */

#ifndef NOWINMESSAGES

// begin_r_winuser

/*
 * Edit Control Messages
 */
#define EM_GETSEL               0x00B0
#define EM_SETSEL               0x00B1
#define EM_GETRECT              0x00B2
#define EM_SETRECT              0x00B3
#define EM_SETRECTNP            0x00B4
#define EM_SCROLL               0x00B5
#define EM_LINESCROLL           0x00B6
#define EM_SCROLLCARET          0x00B7
#define EM_GETMODIFY            0x00B8
#define EM_SETMODIFY            0x00B9
#define EM_GETLINECOUNT         0x00BA
#define EM_LINEINDEX            0x00BB
#define EM_SETHANDLE            0x00BC
#define EM_GETHANDLE            0x00BD
#define EM_GETTHUMB             0x00BE
#define EM_LINELENGTH           0x00C1
#define EM_REPLACESEL           0x00C2
#define EM_GETLINE              0x00C4
#define EM_LIMITTEXT            0x00C5
#define EM_CANUNDO              0x00C6
#define EM_UNDO                 0x00C7
#define EM_FMTLINES             0x00C8
#define EM_LINEFROMCHAR         0x00C9
#define EM_SETTABSTOPS          0x00CB
#define EM_SETPASSWORDCHAR      0x00CC
#define EM_EMPTYUNDOBUFFER      0x00CD
#define EM_GETFIRSTVISIBLELINE  0x00CE
#define EM_SETREADONLY          0x00CF
#define EM_SETWORDBREAKPROC     0x00D0
#define EM_GETWORDBREAKPROC     0x00D1
#define EM_GETPASSWORDCHAR      0x00D2
#if(WINVER >= 0x0400)
#define EM_SETMARGINS           0x00D3
#define EM_GETMARGINS           0x00D4
#define EM_SETLIMITTEXT         EM_LIMITTEXT   /* ;win40 Name change */
#define EM_GETLIMITTEXT         0x00D5
#define EM_POSFROMCHAR          0x00D6
#define EM_CHARFROMPOS          0x00D7
#endif /* WINVER >= 0x0400 */


// end_r_winuser
#endif /* !NOWINMESSAGES */

/*
 * EDITWORDBREAKPROC code values
 */
#define WB_LEFT            0
#define WB_RIGHT           1
#define WB_ISDELIMITER     2

// begin_r_winuser

/*
 * Button Control Styles
 */
#define BS_PUSHBUTTON       0x00000000L
#define BS_DEFPUSHBUTTON    0x00000001L
#define BS_CHECKBOX         0x00000002L
#define BS_AUTOCHECKBOX     0x00000003L
#define BS_RADIOBUTTON      0x00000004L
#define BS_3STATE           0x00000005L
#define BS_AUTO3STATE       0x00000006L
#define BS_GROUPBOX         0x00000007L
#define BS_USERBUTTON       0x00000008L
#define BS_AUTORADIOBUTTON  0x00000009L
#define BS_OWNERDRAW        0x0000000BL
#define BS_LEFTTEXT         0x00000020L
#if(WINVER >= 0x0400)
#define BS_TEXT             0x00000000L
#define BS_ICON             0x00000040L
#define BS_BITMAP           0x00000080L
#define BS_LEFT             0x00000100L
#define BS_RIGHT            0x00000200L
#define BS_CENTER           0x00000300L
#define BS_TOP              0x00000400L
#define BS_BOTTOM           0x00000800L
#define BS_VCENTER          0x00000C00L
#define BS_PUSHLIKE         0x00001000L
#define BS_MULTILINE        0x00002000L
#define BS_NOTIFY           0x00004000L
#define BS_FLAT             0x00008000L
#define BS_RIGHTBUTTON      BS_LEFTTEXT
#endif /* WINVER >= 0x0400 */


/*
 * User Button Notification Codes
 */
#define BN_CLICKED          0
#define BN_PAINT            1
#define BN_HILITE           2
#define BN_UNHILITE         3
#define BN_DISABLE          4
#define BN_DOUBLECLICKED    5
#if(WINVER >= 0x0400)
#define BN_PUSHED           BN_HILITE
#define BN_UNPUSHED         BN_UNHILITE
#define BN_DBLCLK           BN_DOUBLECLICKED
#define BN_SETFOCUS         6
#define BN_KILLFOCUS        7
#endif /* WINVER >= 0x0400 */

/*
 * Button Control Messages
 */
#define BM_GETCHECK        0x00F0
#define BM_SETCHECK        0x00F1
#define BM_GETSTATE        0x00F2
#define BM_SETSTATE        0x00F3
#define BM_SETSTYLE        0x00F4
#if(WINVER >= 0x0400)
#define BM_CLICK           0x00F5
#define BM_GETIMAGE        0x00F6
#define BM_SETIMAGE        0x00F7

#define BST_UNCHECKED      0x0000
#define BST_CHECKED        0x0001
#define BST_INDETERMINATE  0x0002
#define BST_PUSHED         0x0004
#define BST_FOCUS          0x0008
#endif /* WINVER >= 0x0400 */

/*
 * Static Control Constants
 */
#define SS_LEFT             0x00000000L
#define SS_CENTER           0x00000001L
#define SS_RIGHT            0x00000002L
#define SS_ICON             0x00000003L
#define SS_BLACKRECT        0x00000004L
#define SS_GRAYRECT         0x00000005L
#define SS_WHITERECT        0x00000006L
#define SS_BLACKFRAME       0x00000007L
#define SS_GRAYFRAME        0x00000008L
#define SS_WHITEFRAME       0x00000009L
#define SS_USERITEM         0x0000000AL
#define SS_SIMPLE           0x0000000BL
#define SS_LEFTNOWORDWRAP   0x0000000CL
#if(WINVER >= 0x0400)
#define SS_OWNERDRAW        0x0000000DL
#define SS_BITMAP           0x0000000EL
#define SS_ENHMETAFILE      0x0000000FL
#define SS_ETCHEDHORZ       0x00000010L
#define SS_ETCHEDVERT       0x00000011L
#define SS_ETCHEDFRAME      0x00000012L
#define SS_TYPEMASK         0x0000001FL
#endif /* WINVER >= 0x0400 */
#define SS_NOPREFIX         0x00000080L /* Don't do "&" character translation */
#if(WINVER >= 0x0400)
#define SS_NOTIFY           0x00000100L
#define SS_CENTERIMAGE      0x00000200L
#define SS_RIGHTJUST        0x00000400L
#define SS_REALSIZEIMAGE    0x00000800L
#define SS_SUNKEN           0x00001000L
#define SS_ENDELLIPSIS      0x00004000L
#define SS_PATHELLIPSIS     0x00008000L
#define SS_WORDELLIPSIS     0x0000C000L
#define SS_ELLIPSISMASK     0x0000C000L
#endif /* WINVER >= 0x0400 */

// end_r_winuser

#ifndef NOWINMESSAGES
/*
 * Static Control Mesages
 */
#define STM_SETICON         0x0170
#define STM_GETICON         0x0171
#if(WINVER >= 0x0400)
#define STM_SETIMAGE        0x0172
#define STM_GETIMAGE        0x0173
#define STN_CLICKED         0
#define STN_DBLCLK          1
#define STN_ENABLE          2
#define STN_DISABLE         3
#endif /* WINVER >= 0x0400 */
#define STM_MSGMAX          0x0174
#endif /* !NOWINMESSAGES */

/*
 * Dialog window class
 */
#define WC_DIALOG       (MAKEINTATOM(0x8002))

/*
 * Get/SetWindowWord/Long offsets for use with WC_DIALOG windows
 */
#define DWL_MSGRESULT   0
#define DWL_DLGPROC     4
#define DWL_USER        8

/*
 * Dialog Manager Routines
 */

#ifndef NOMSG

/*WINUSERAPI*/
BOOL
__stdcall
IsDialogMessageA(
    HWND hDlg,
    LPMSG lpMsg);
/*WINUSERAPI*/
BOOL
__stdcall
IsDialogMessageW(
    HWND hDlg,
    LPMSG lpMsg);
#ifdef UNICODE
#define IsDialogMessage  IsDialogMessageW
#else
#define IsDialogMessage  IsDialogMessageA
#endif // !UNICODE

#endif /* !NOMSG */

/*WINUSERAPI*/
BOOL
__stdcall
MapDialogRect(
    HWND hDlg,
    RECT* lpRect);

/*WINUSERAPI*/
int
__stdcall
DlgDirListA(
    HWND hDlg,
    char* lpPathSpec,
    int nIDListBox,
    int nIDStaticPath,
    unsigned uFileType);
/*WINUSERAPI*/
int
__stdcall
DlgDirListW(
    HWND hDlg,
    wchar_t* lpPathSpec,
    int nIDListBox,
    int nIDStaticPath,
    unsigned uFileType);
#ifdef UNICODE
#define DlgDirList  DlgDirListW
#else
#define DlgDirList  DlgDirListA
#endif // !UNICODE

/*
 * DlgDirList, DlgDirListComboBox flags values
 */
#define DDL_READWRITE       0x0000
#define DDL_READONLY        0x0001
#define DDL_HIDDEN          0x0002
#define DDL_SYSTEM          0x0004
#define DDL_DIRECTORY       0x0010
#define DDL_ARCHIVE         0x0020

#define DDL_POSTMSGS        0x2000
#define DDL_DRIVES          0x4000
#define DDL_EXCLUSIVE       0x8000

/*WINUSERAPI*/
BOOL
__stdcall
DlgDirSelectExA(
    HWND hDlg,
    char* lpString,
    int nCount,
    int nIDListBox);
/*WINUSERAPI*/
BOOL
__stdcall
DlgDirSelectExW(
    HWND hDlg,
    wchar_t* lpString,
    int nCount,
    int nIDListBox);
#ifdef UNICODE
#define DlgDirSelectEx  DlgDirSelectExW
#else
#define DlgDirSelectEx  DlgDirSelectExA
#endif // !UNICODE

/*WINUSERAPI*/
int
__stdcall
DlgDirListComboBoxA(
    HWND hDlg,
    char* lpPathSpec,
    int nIDComboBox,
    int nIDStaticPath,
    unsigned uFiletype);
/*WINUSERAPI*/
int
__stdcall
DlgDirListComboBoxW(
    HWND hDlg,
    wchar_t* lpPathSpec,
    int nIDComboBox,
    int nIDStaticPath,
    unsigned uFiletype);
#ifdef UNICODE
#define DlgDirListComboBox  DlgDirListComboBoxW
#else
#define DlgDirListComboBox  DlgDirListComboBoxA
#endif // !UNICODE

/*WINUSERAPI*/
BOOL
__stdcall
DlgDirSelectComboBoxExA(
    HWND hDlg,
    char* lpString,
    int nCount,
    int nIDComboBox);
/*WINUSERAPI*/
BOOL
__stdcall
DlgDirSelectComboBoxExW(
    HWND hDlg,
    wchar_t* lpString,
    int nCount,
    int nIDComboBox);
#ifdef UNICODE
#define DlgDirSelectComboBoxEx  DlgDirSelectComboBoxExW
#else
#define DlgDirSelectComboBoxEx  DlgDirSelectComboBoxExA
#endif // !UNICODE


// begin_r_winuser

/*
 * Dialog Styles
 */
#define DS_ABSALIGN         0x01L
#define DS_SYSMODAL         0x02L
#define DS_LOCALEDIT        0x20L   /* Edit items get Local storage. */
#define DS_SETFONT          0x40L   /* User specified font for Dlg controls */
#define DS_MODALFRAME       0x80L   /* Can be combined with WS_CAPTION  */
#define DS_NOIDLEMSG        0x100L  /* WM_ENTERIDLE message will not be sent */
#define DS_SETFOREGROUND    0x200L  /* not in win3.1 */



#if(WINVER >= 0x0400)
#define DS_3DLOOK           0x0004L
#define DS_FIXEDSYS         0x0008L
#define DS_NOFAILCREATE     0x0010L
#define DS_CONTROL          0x0400L
#define DS_CENTER           0x0800L
#define DS_CENTERMOUSE      0x1000L
#define DS_CONTEXTHELP      0x2000L


#endif /* WINVER >= 0x0400 */

// end_r_winuser

#define DM_GETDEFID         (WM_USER+0)
#define DM_SETDEFID         (WM_USER+1)

#if(WINVER >= 0x0400)
#define DM_REPOSITION       (WM_USER+2)

#define PSM_PAGEINFO        (WM_USER+100)
#define PSM_SHEETINFO       (WM_USER+101)

#define PSI_SETACTIVE       0x0001L
#define PSI_KILLACTIVE      0x0002L
#define PSI_APPLY           0x0003L
#define PSI_RESET           0x0004L
#define PSI_HASHELP         0x0005L
#define PSI_HELP            0x0006L

#define PSI_CHANGED         0x0001L
#define PSI_GUISTART        0x0002L
#define PSI_REBOOT          0x0003L
#define PSI_GETSIBLINGS     0x0004L
#endif /* WINVER >= 0x0400 */
/*
 * Returned in HIWORD() of DM_GETDEFID result if msg is supported
 */
#define DC_HASDEFID         0x534B

/*
 * Dialog Codes
 */
#define DLGC_WANTARROWS     0x0001      /* Control wants arrow keys         */
#define DLGC_WANTTAB        0x0002      /* Control wants tab keys           */
#define DLGC_WANTALLKEYS    0x0004      /* Control wants all keys           */
#define DLGC_WANTMESSAGE    0x0004      /* Pass message to control          */
#define DLGC_HASSETSEL      0x0008      /* Understands EM_SETSEL message    */
#define DLGC_DEFPUSHBUTTON  0x0010      /* Default pushbutton               */
#define DLGC_UNDEFPUSHBUTTON 0x0020     /* Non-default pushbutton           */
#define DLGC_RADIOBUTTON    0x0040      /* Radio button                     */
#define DLGC_WANTCHARS      0x0080      /* Want WM_CHAR messages            */
#define DLGC_STATIC         0x0100      /* Static item: don't include       */
#define DLGC_BUTTON         0x2000      /* Button item: can be checked      */

#define LB_CTLCODE          0L

/*
 * Listbox Return Values
 */
#define LB_OKAY             0
#define LB_ERR              (-1)
#define LB_ERRSPACE         (-2)

/*
**  The idStaticPath parameter to DlgDirList can have the following values
**  ORed if the list box should show other details of the files along with
**  the name of the files;
*/
                                  /* all other details also will be returned */


/*
 * Listbox Notification Codes
 */
#define LBN_ERRSPACE        (-2)
#define LBN_SELCHANGE       1
#define LBN_DBLCLK          2
#define LBN_SELCANCEL       3
#define LBN_SETFOCUS        4
#define LBN_KILLFOCUS       5



#ifndef NOWINMESSAGES

/*
 * Listbox messages
 */
#define LB_ADDSTRING            0x0180
#define LB_INSERTSTRING         0x0181
#define LB_DELETESTRING         0x0182
#define LB_SELITEMRANGEEX       0x0183
#define LB_RESETCONTENT         0x0184
#define LB_SETSEL               0x0185
#define LB_SETCURSEL            0x0186
#define LB_GETSEL               0x0187
#define LB_GETCURSEL            0x0188
#define LB_GETTEXT              0x0189
#define LB_GETTEXTLEN           0x018A
#define LB_GETCOUNT             0x018B
#define LB_SELECTSTRING         0x018C
#define LB_DIR                  0x018D
#define LB_GETTOPINDEX          0x018E
#define LB_FINDSTRING           0x018F
#define LB_GETSELCOUNT          0x0190
#define LB_GETSELITEMS          0x0191
#define LB_SETTABSTOPS          0x0192
#define LB_GETHORIZONTALEXTENT  0x0193
#define LB_SETHORIZONTALEXTENT  0x0194
#define LB_SETCOLUMNWIDTH       0x0195
#define LB_ADDFILE              0x0196
#define LB_SETTOPINDEX          0x0197
#define LB_GETITEMRECT          0x0198
#define LB_GETITEMDATA          0x0199
#define LB_SETITEMDATA          0x019A
#define LB_SELITEMRANGE         0x019B
#define LB_SETANCHORINDEX       0x019C
#define LB_GETANCHORINDEX       0x019D
#define LB_SETCARETINDEX        0x019E
#define LB_GETCARETINDEX        0x019F
#define LB_SETITEMHEIGHT        0x01A0
#define LB_GETITEMHEIGHT        0x01A1
#define LB_FINDSTRINGEXACT      0x01A2
#define LB_SETLOCALE            0x01A5
#define LB_GETLOCALE            0x01A6
#define LB_SETCOUNT             0x01A7
#if(WINVER >= 0x0400)
#define LB_INITSTORAGE          0x01A8
#define LB_ITEMFROMPOINT        0x01A9
#endif /* WINVER >= 0x0400 */
#if(WINVER >= 0x0400)
#define LB_MSGMAX               0x01B0
#else
#define LB_MSGMAX               0x01A8
#endif

#endif /* !NOWINMESSAGES */

#ifndef NOWINSTYLES

// begin_r_winuser

/*
 * Listbox Styles
 */
#define LBS_NOTIFY            0x0001L
#define LBS_SORT              0x0002L
#define LBS_NOREDRAW          0x0004L
#define LBS_MULTIPLESEL       0x0008L
#define LBS_OWNERDRAWFIXED    0x0010L
#define LBS_OWNERDRAWVARIABLE 0x0020L
#define LBS_HASSTRINGS        0x0040L
#define LBS_USETABSTOPS       0x0080L
#define LBS_NOINTEGRALHEIGHT  0x0100L
#define LBS_MULTICOLUMN       0x0200L
#define LBS_WANTKEYBOARDINPUT 0x0400L
#define LBS_EXTENDEDSEL       0x0800L
#define LBS_DISABLENOSCROLL   0x1000L
#define LBS_NODATA            0x2000L
#if(WINVER >= 0x0400)
#define LBS_NOSEL             0x4000L
#endif /* WINVER >= 0x0400 */
#define LBS_STANDARD          (LBS_NOTIFY | LBS_SORT | WS_VSCROLL | WS_BORDER)

// end_r_winuser

#endif /* !NOWINSTYLES */


/*
 * Combo Box return Values
 */
#define CB_OKAY             0
#define CB_ERR              (-1)
#define CB_ERRSPACE         (-2)


/*
 * Combo Box Notification Codes
 */
#define CBN_ERRSPACE        (-1)
#define CBN_SELCHANGE       1
#define CBN_DBLCLK          2
#define CBN_SETFOCUS        3
#define CBN_KILLFOCUS       4
#define CBN_EDITCHANGE      5
#define CBN_EDITUPDATE      6
#define CBN_DROPDOWN        7
#define CBN_CLOSEUP         8
#define CBN_SELENDOK        9
#define CBN_SELENDCANCEL    10

#ifndef NOWINSTYLES
// begin_r_winuser

/*
 * Combo Box styles
 */
#define CBS_SIMPLE            0x0001L
#define CBS_DROPDOWN          0x0002L
#define CBS_DROPDOWNLIST      0x0003L
#define CBS_OWNERDRAWFIXED    0x0010L
#define CBS_OWNERDRAWVARIABLE 0x0020L
#define CBS_AUTOHSCROLL       0x0040L
#define CBS_OEMCONVERT        0x0080L
#define CBS_SORT              0x0100L
#define CBS_HASSTRINGS        0x0200L
#define CBS_NOINTEGRALHEIGHT  0x0400L
#define CBS_DISABLENOSCROLL   0x0800L
#if(WINVER >= 0x0400)
#define CBS_UPPERCASE           0x2000L
#define CBS_LOWERCASE           0x4000L
#endif /* WINVER >= 0x0400 */

// end_r_winuser
#endif  /* !NOWINSTYLES */


/*
 * Combo Box messages
 */
#ifndef NOWINMESSAGES
#define CB_GETEDITSEL               0x0140
#define CB_LIMITTEXT                0x0141
#define CB_SETEDITSEL               0x0142
#define CB_ADDSTRING                0x0143
#define CB_DELETESTRING             0x0144
#define CB_DIR                      0x0145
#define CB_GETCOUNT                 0x0146
#define CB_GETCURSEL                0x0147
#define CB_GETLBTEXT                0x0148
#define CB_GETLBTEXTLEN             0x0149
#define CB_INSERTSTRING             0x014A
#define CB_RESETCONTENT             0x014B
#define CB_FINDSTRING               0x014C
#define CB_SELECTSTRING             0x014D
#define CB_SETCURSEL                0x014E
#define CB_SHOWDROPDOWN             0x014F
#define CB_GETITEMDATA              0x0150
#define CB_SETITEMDATA              0x0151
#define CB_GETDROPPEDCONTROLRECT    0x0152
#define CB_SETITEMHEIGHT            0x0153
#define CB_GETITEMHEIGHT            0x0154
#define CB_SETEXTENDEDUI            0x0155
#define CB_GETEXTENDEDUI            0x0156
#define CB_GETDROPPEDSTATE          0x0157
#define CB_FINDSTRINGEXACT          0x0158
#define CB_SETLOCALE                0x0159
#define CB_GETLOCALE                0x015A
#if(WINVER >= 0x0400)
#define CB_GETTOPINDEX              0x015b
#define CB_SETTOPINDEX              0x015c
#define CB_GETHORIZONTALEXTENT      0x015d
#define CB_SETHORIZONTALEXTENT      0x015e
#define CB_GETDROPPEDWIDTH          0x015f
#define CB_SETDROPPEDWIDTH          0x0160
#define CB_INITSTORAGE              0x0161
#endif /* WINVER >= 0x0400 */
#if(WINVER >= 0x0400)
#define CB_MSGMAX                   0x0162
#else
#define CB_MSGMAX                   0x015B
#endif
#endif  /* !NOWINMESSAGES */



#ifndef NOWINSTYLES

// begin_r_winuser

/*
 * Scroll Bar Styles
 */
#define SBS_HORZ                    0x0000L
#define SBS_VERT                    0x0001L
#define SBS_TOPALIGN                0x0002L
#define SBS_LEFTALIGN               0x0002L
#define SBS_BOTTOMALIGN             0x0004L
#define SBS_RIGHTALIGN              0x0004L
#define SBS_SIZEBOXTOPLEFTALIGN     0x0002L
#define SBS_SIZEBOXBOTTOMRIGHTALIGN 0x0004L
#define SBS_SIZEBOX                 0x0008L
#if(WINVER >= 0x0400)
#define SBS_SIZEGRIP                0x0010L
#endif /* WINVER >= 0x0400 */

// end_r_winuser

#endif /* !NOWINSTYLES */

/*
 * Scroll bar messages
 */
#ifndef NOWINMESSAGES
#define SBM_SETPOS                  0x00E0 /*not in win3.1 */
#define SBM_GETPOS                  0x00E1 /*not in win3.1 */
#define SBM_SETRANGE                0x00E2 /*not in win3.1 */
#define SBM_SETRANGEREDRAW          0x00E6 /*not in win3.1 */
#define SBM_GETRANGE                0x00E3 /*not in win3.1 */
#define SBM_ENABLE_ARROWS           0x00E4 /*not in win3.1 */
#if(WINVER >= 0x0400)
#define SBM_SETSCROLLINFO           0x00E9
#define SBM_GETSCROLLINFO           0x00EA

#define SIF_RANGE           0x0001
#define SIF_PAGE            0x0002
#define SIF_POS             0x0004
#define SIF_DISABLENOSCROLL 0x0008
#define SIF_TRACKPOS        0x0010
#define SIF_ALL             (SIF_RANGE | SIF_PAGE | SIF_POS | SIF_TRACKPOS)

typedef struct tagSCROLLINFO
{
    unsigned    cbSize;
    unsigned    fMask;
    int     nMin;
    int     nMax;
    unsigned    nPage;
    int     nPos;
    int     nTrackPos;
}   SCROLLINFO,  *LPSCROLLINFO;
typedef SCROLLINFO const  *LPCSCROLLINFO;

/*WINUSERAPI*/ int     __stdcall SetScrollInfo(HWND, int, LPCSCROLLINFO, BOOL);
/*WINUSERAPI*/ BOOL    __stdcall GetScrollInfo(HWND, int, LPSCROLLINFO);
#endif /* WINVER >= 0x0400 */
#endif /* !NOWINMESSAGES */
#endif /* !NOCTLMGR */

#ifndef NOMDI

/*
 * MDI client style bits
 */
#define MDIS_ALLCHILDSTYLES    0x0001

/*
 * wParam Flags for WM_MDITILE and WM_MDICASCADE messages.
 */
#define MDITILE_VERTICAL       0x0000 /*not in win3.1 */
#define MDITILE_HORIZONTAL     0x0001 /*not in win3.1 */
#define MDITILE_SKIPDISABLED   0x0002 /*not in win3.1 */

typedef struct tagMDICREATESTRUCTA {
    const char*   szClass;
    const char*   szTitle;
    HANDLE hOwner;
    int x;
    int y;
    int cx;
    int cy;
    unsigned long style;
    LPARAM lParam;        /* app-defined stuff */
} MDICREATESTRUCTA, *LPMDICREATESTRUCTA;
typedef struct tagMDICREATESTRUCTW {
    const wchar_t*  szClass;
    const wchar_t*  szTitle;
    HANDLE hOwner;
    int x;
    int y;
    int cx;
    int cy;
    unsigned long style;
    LPARAM lParam;        /* app-defined stuff */
} MDICREATESTRUCTW, *LPMDICREATESTRUCTW;
#ifdef UNICODE
typedef MDICREATESTRUCTW MDICREATESTRUCT;
typedef LPMDICREATESTRUCTW LPMDICREATESTRUCT;
#else
typedef MDICREATESTRUCTA MDICREATESTRUCT;
typedef LPMDICREATESTRUCTA LPMDICREATESTRUCT;
#endif // UNICODE

typedef struct tagCLIENTCREATESTRUCT {
    HANDLE hWindowMenu;
    unsigned idFirstChild;
} CLIENTCREATESTRUCT, *LPCLIENTCREATESTRUCT;

/*WINUSERAPI*/
LRESULT
__stdcall
DefFrameProcA(
    HWND hWnd,
    HWND hWndMDIClient ,
    unsigned uMsg,
    WPARAM wParam,
    LPARAM lParam);
/*WINUSERAPI*/
LRESULT
__stdcall
DefFrameProcW(
    HWND hWnd,
    HWND hWndMDIClient ,
    unsigned uMsg,
    WPARAM wParam,
    LPARAM lParam);
#ifdef UNICODE
#define DefFrameProc  DefFrameProcW
#else
#define DefFrameProc  DefFrameProcA
#endif // !UNICODE

/*WINUSERAPI*/
LRESULT
__stdcall
DefMDIChildProcA(
    HWND hWnd,
    unsigned uMsg,
    WPARAM wParam,
    LPARAM lParam);
/*WINUSERAPI*/
LRESULT
__stdcall
DefMDIChildProcW(
    HWND hWnd,
    unsigned uMsg,
    WPARAM wParam,
    LPARAM lParam);
#ifdef UNICODE
#define DefMDIChildProc  DefMDIChildProcW
#else
#define DefMDIChildProc  DefMDIChildProcA
#endif // !UNICODE

#ifndef NOMSG

/*WINUSERAPI*/
BOOL
__stdcall
TranslateMDISysAccel(
    HWND hWndClient,
    LPMSG lpMsg);

#endif /* !NOMSG */

/*WINUSERAPI*/
unsigned
__stdcall
ArrangeIconicWindows(
    HWND hWnd);

/*WINUSERAPI*/
HWND
__stdcall
CreateMDIWindowA(
    char* lpClassName,
    char* lpWindowName,
    unsigned long dwStyle,
    int X,
    int Y,
    int nWidth,
    int nHeight,
    HWND hWndParent,
    HINSTANCE hInstance,
    LPARAM lParam
    );
/*WINUSERAPI*/
HWND
__stdcall
CreateMDIWindowW(
    wchar_t* lpClassName,
    wchar_t* lpWindowName,
    unsigned long dwStyle,
    int X,
    int Y,
    int nWidth,
    int nHeight,
    HWND hWndParent,
    HINSTANCE hInstance,
    LPARAM lParam
    );
#ifdef UNICODE
#define CreateMDIWindow  CreateMDIWindowW
#else
#define CreateMDIWindow  CreateMDIWindowA
#endif // !UNICODE

#if(WINVER >= 0x0400)
/*WINUSERAPI*/ WORD    __stdcall TileWindows(HWND hwndParent, unsigned wHow, const RECT * lpRect, unsigned cKids, const HWND  * lpKids);
/*WINUSERAPI*/ WORD    __stdcall CascadeWindows(HWND hwndParent, unsigned wHow, const RECT * lpRect, unsigned cKids,  const HWND  * lpKids);
#endif /* WINVER >= 0x0400 */
#endif /* !NOMDI */

#endif /* !NOUSER */

/****** Help support ********************************************************/

#ifndef NOHELP

typedef unsigned long HELPPOLY;
typedef struct tagMULTIKEYHELPA {
    unsigned long  mkSize;
    char   mkKeylist;
    char   szKeyphrase[1];
} MULTIKEYHELPA, *PMULTIKEYHELPA, *LPMULTIKEYHELPA;
typedef struct tagMULTIKEYHELPW {
    unsigned long  mkSize;
    wchar_t  mkKeylist;
    wchar_t  szKeyphrase[1];
} MULTIKEYHELPW, *PMULTIKEYHELPW, *LPMULTIKEYHELPW;
#ifdef UNICODE
typedef MULTIKEYHELPW MULTIKEYHELP;
typedef PMULTIKEYHELPW PMULTIKEYHELP;
typedef LPMULTIKEYHELPW LPMULTIKEYHELP;
#else
typedef MULTIKEYHELPA MULTIKEYHELP;
typedef PMULTIKEYHELPA PMULTIKEYHELP;
typedef LPMULTIKEYHELPA LPMULTIKEYHELP;
#endif // UNICODE

typedef struct tagHELPWININFOA {
    int  wStructSize;
    int  x;
    int  y;
    int  dx;
    int  dy;
    int  wMax;
    char   rgchMember[2];
} HELPWININFOA, *PHELPWININFOA, *LPHELPWININFOA;
typedef struct tagHELPWININFOW {
    int  wStructSize;
    int  x;
    int  y;
    int  dx;
    int  dy;
    int  wMax;
    wchar_t  rgchMember[2];
} HELPWININFOW, *PHELPWININFOW, *LPHELPWININFOW;
#ifdef UNICODE
typedef HELPWININFOW HELPWININFO;
typedef PHELPWININFOW PHELPWININFO;
typedef LPHELPWININFOW LPHELPWININFO;
#else
typedef HELPWININFOA HELPWININFO;
typedef PHELPWININFOA PHELPWININFO;
typedef LPHELPWININFOA LPHELPWININFO;
#endif // UNICODE

// begin_r_winuser

/*
 * Commands to pass to WinHelp()
 */
#define HELP_CONTEXT      0x0001L  /* Display topic in ulTopic */
#define HELP_QUIT         0x0002L  /* Terminate help */
#define HELP_INDEX        0x0003L  /* Display index */
#define HELP_CONTENTS     0x0003L
#define HELP_HELPONHELP   0x0004L  /* Display help on using help */
#define HELP_SETINDEX     0x0005L  /* Set current Index for multi index help */
#define HELP_SETCONTENTS  0x0005L
#define HELP_CONTEXTPOPUP 0x0008L
#define HELP_FORCEFILE    0x0009L
#define HELP_KEY          0x0101L  /* Display topic for keyword in offabData */
#define HELP_COMMAND      0x0102L
#define HELP_PARTIALKEY   0x0105L
#define HELP_MULTIKEY     0x0201L
#define HELP_SETWINPOS    0x0203L
#if(WINVER >= 0x0400)
#define HELP_CONTEXTMENU  0x000a
#define HELP_FINDER       0x000b
#define HELP_WM_HELP      0x000c
#define HELP_SETPOPUP_POS 0x000d

#define HELP_TCARD              0x8000
#define HELP_TCARD_DATA         0x0010
#define HELP_TCARD_OTHER_CALLER 0x0011

// These are in winhelp.h in Win95.
#define IDH_NO_HELP                     28440
#define IDH_MISSING_CONTEXT             28441 // Control doesn't have matching help context
#define IDH_GENERIC_HELP_BUTTON         28442 // Property sheet help button
#define IDH_OK                          28443
#define IDH_CANCEL                      28444
#define IDH_HELP                        28445

#endif /* WINVER >= 0x0400 */

// end_r_winuser


/*WINUSERAPI*/
BOOL
__stdcall
WinHelpA(
    HWND hWndMain,
    const char* lpszHelp,
    unsigned uCommand,
    unsigned long dwData
    );
/*WINUSERAPI*/
BOOL
__stdcall
WinHelpW(
    HWND hWndMain,
    const wchar_t* lpszHelp,
    unsigned uCommand,
    unsigned long dwData
    );
#ifdef UNICODE
#define WinHelp  WinHelpW
#else
#define WinHelp  WinHelpA
#endif // !UNICODE

#endif /* !NOHELP */

#ifndef NOSYSPARAMSINFO

/*
 * Parameter for SystemParametersInfo()
 */

#define SPI_GETBEEP                 1
#define SPI_SETBEEP                 2
#define SPI_GETMOUSE                3
#define SPI_SETMOUSE                4
#define SPI_GETBORDER               5
#define SPI_SETBORDER               6
#define SPI_GETKEYBOARDSPEED       10
#define SPI_SETKEYBOARDSPEED       11
#define SPI_LANGDRIVER             12
#define SPI_ICONHORIZONTALSPACING  13
#define SPI_GETSCREENSAVETIMEOUT   14
#define SPI_SETSCREENSAVETIMEOUT   15
#define SPI_GETSCREENSAVEACTIVE    16
#define SPI_SETSCREENSAVEACTIVE    17
#define SPI_GETGRIDGRANULARITY     18
#define SPI_SETGRIDGRANULARITY     19
#define SPI_SETDESKWALLPAPER       20
#define SPI_SETDESKPATTERN         21
#define SPI_GETKEYBOARDDELAY       22
#define SPI_SETKEYBOARDDELAY       23
#define SPI_ICONVERTICALSPACING    24
#define SPI_GETICONTITLEWRAP       25
#define SPI_SETICONTITLEWRAP       26
#define SPI_GETMENUDROPALIGNMENT   27
#define SPI_SETMENUDROPALIGNMENT   28
#define SPI_SETDOUBLECLKWIDTH      29
#define SPI_SETDOUBLECLKHEIGHT     30
#define SPI_GETICONTITLELOGFONT    31
#define SPI_SETDOUBLECLICKTIME     32
#define SPI_SETMOUSEBUTTONSWAP     33
#define SPI_SETICONTITLELOGFONT    34
#define SPI_GETFASTTASKSWITCH      35
#define SPI_SETFASTTASKSWITCH      36
#if(WINVER >= 0x0400)
#define SPI_SETDRAGFULLWINDOWS     37
#define SPI_GETDRAGFULLWINDOWS     38
#define SPI_GETNONCLIENTMETRICS    41
#define SPI_SETNONCLIENTMETRICS    42
#define SPI_GETMINIMIZEDMETRICS    43
#define SPI_SETMINIMIZEDMETRICS    44
#define SPI_GETICONMETRICS         45
#define SPI_SETICONMETRICS         46
#define SPI_SETWORKAREA            47
#define SPI_GETWORKAREA            48
#define SPI_SETPENWINDOWS          49

#define SPI_GETHIGHCONTRAST        66
#define SPI_SETHIGHCONTRAST        67
#define SPI_GETKEYBOARDPREF        68
#define SPI_SETKEYBOARDPREF        69
#define SPI_GETSCREENREADER        70
#define SPI_SETSCREENREADER        71
#define SPI_GETANIMATION           72
#define SPI_SETANIMATION           73
#define SPI_GETFONTSMOOTHING       74
#define SPI_SETFONTSMOOTHING       75
#define SPI_SETDRAGWIDTH           76
#define SPI_SETDRAGHEIGHT          77
#define SPI_SETHANDHELD            78
#define SPI_GETLOWPOWERTIMEOUT     79
#define SPI_GETPOWEROFFTIMEOUT     80
#define SPI_SETLOWPOWERTIMEOUT     81
#define SPI_SETPOWEROFFTIMEOUT     82
#define SPI_GETLOWPOWERACTIVE      83
#define SPI_GETPOWEROFFACTIVE      84
#define SPI_SETLOWPOWERACTIVE      85
#define SPI_SETPOWEROFFACTIVE      86
#define SPI_SETCURSORS             87
#define SPI_SETICONS               88
#define SPI_GETDEFAULTINPUTLANG    89
#define SPI_SETDEFAULTINPUTLANG    90
#define SPI_SETLANGTOGGLE          91
#define SPI_GETWINDOWSEXTENSION    92
#define SPI_SETMOUSETRAILS         93
#define SPI_GETMOUSETRAILS         94
#define SPI_SCREENSAVERRUNNING     97
#endif /* WINVER >= 0x0400 */
#define SPI_GETFILTERKEYS          50
#define SPI_SETFILTERKEYS          51
#define SPI_GETTOGGLEKEYS          52
#define SPI_SETTOGGLEKEYS          53
#define SPI_GETMOUSEKEYS           54
#define SPI_SETMOUSEKEYS           55
#define SPI_GETSHOWSOUNDS          56
#define SPI_SETSHOWSOUNDS          57
#define SPI_GETSTICKYKEYS          58
#define SPI_SETSTICKYKEYS          59
#define SPI_GETACCESSTIMEOUT       60
#define SPI_SETACCESSTIMEOUT       61
#if(WINVER >= 0x0400)
#define SPI_GETSERIALKEYS          62
#define SPI_SETSERIALKEYS          63
#endif /* WINVER >= 0x0400 */
#define SPI_GETSOUNDSENTRY         64
#define SPI_SETSOUNDSENTRY         65
#if(_WIN32_WINNT >= 0x0400)
#define SPI_GETSNAPTODEFBUTTON     95
#define SPI_SETSNAPTODEFBUTTON     96
#define SPI_GETMOUSEHOVERWIDTH     98
#define SPI_SETMOUSEHOVERWIDTH     99
#define SPI_GETMOUSEHOVERHEIGHT   100
#define SPI_SETMOUSEHOVERHEIGHT   101
#define SPI_GETMOUSEHOVERTIME     102
#define SPI_SETMOUSEHOVERTIME     103
#define SPI_GETWHEELSCROLLLINES   104
#define SPI_SETWHEELSCROLLLINES   105

#endif /* _WIN32_WINNT >= 0x0400 */

/*
 * SPI User Preferences.
 */

/*
 * Flags
 */
#define SPIF_UPDATEINIFILE    0x0001
#define SPIF_SENDWININICHANGE 0x0002
#define SPIF_SENDCHANGE       SPIF_SENDWININICHANGE


#define METRICS_USEDEFAULT -1
#ifdef _WINGDI_
#ifndef NOGDI
typedef struct tagNONCLIENTMETRICSA
{
    unsigned    cbSize;
    int     iBorderWidth;
    int     iScrollWidth;
    int     iScrollHeight;
    int     iCaptionWidth;
    int     iCaptionHeight;
    LOGFONTA lfCaptionFont;
    int     iSmCaptionWidth;
    int     iSmCaptionHeight;
    LOGFONTA lfSmCaptionFont;
    int     iMenuWidth;
    int     iMenuHeight;
    LOGFONTA lfMenuFont;
    LOGFONTA lfStatusFont;
    LOGFONTA lfMessageFont;
}   NONCLIENTMETRICSA, *PNONCLIENTMETRICSA, * LPNONCLIENTMETRICSA;
typedef struct tagNONCLIENTMETRICSW
{
    unsigned    cbSize;
    int     iBorderWidth;
    int     iScrollWidth;
    int     iScrollHeight;
    int     iCaptionWidth;
    int     iCaptionHeight;
    LOGFONTW lfCaptionFont;
    int     iSmCaptionWidth;
    int     iSmCaptionHeight;
    LOGFONTW lfSmCaptionFont;
    int     iMenuWidth;
    int     iMenuHeight;
    LOGFONTW lfMenuFont;
    LOGFONTW lfStatusFont;
    LOGFONTW lfMessageFont;
}   NONCLIENTMETRICSW, *PNONCLIENTMETRICSW, * LPNONCLIENTMETRICSW;
#ifdef UNICODE
typedef NONCLIENTMETRICSW NONCLIENTMETRICS;
typedef PNONCLIENTMETRICSW PNONCLIENTMETRICS;
typedef LPNONCLIENTMETRICSW LPNONCLIENTMETRICS;
#else
typedef NONCLIENTMETRICSA NONCLIENTMETRICS;
typedef PNONCLIENTMETRICSA PNONCLIENTMETRICS;
typedef LPNONCLIENTMETRICSA LPNONCLIENTMETRICS;
#endif // UNICODE
#endif /* NOGDI */
#endif /* _WINGDI_ */

#define ARW_BOTTOMLEFT              0x0000L
#define ARW_BOTTOMRIGHT             0x0001L
#define ARW_TOPLEFT                 0x0002L
#define ARW_TOPRIGHT                0x0003L
#define ARW_STARTMASK               0x0003L
#define ARW_STARTRIGHT              0x0001L
#define ARW_STARTTOP                0x0002L

#define ARW_LEFT                    0x0000L
#define ARW_RIGHT                   0x0000L
#define ARW_UP                      0x0004L
#define ARW_DOWN                    0x0004L
#define ARW_HIDE                    0x0008L
#define ARW_VALID                   0x000FL

typedef struct tagMINIMIZEDMETRICS
{
    unsigned    cbSize;
    int     iWidth;
    int     iHorzGap;
    int     iVertGap;
    int     iArrange;
}   MINIMIZEDMETRICS, *PMINIMIZEDMETRICS, *LPMINIMIZEDMETRICS;

#ifdef _WINGDI_
#ifndef NOGDI
typedef struct tagICONMETRICSA
{
    unsigned    cbSize;
    int     iHorzSpacing;
    int     iVertSpacing;
    int     iTitleWrap;
    LOGFONTA lfFont;
}   ICONMETRICSA, *PICONMETRICSA, *LPICONMETRICSA;
typedef struct tagICONMETRICSW
{
    unsigned    cbSize;
    int     iHorzSpacing;
    int     iVertSpacing;
    int     iTitleWrap;
    LOGFONTW lfFont;
}   ICONMETRICSW, *PICONMETRICSW, *LPICONMETRICSW;
#ifdef UNICODE
typedef ICONMETRICSW ICONMETRICS;
typedef PICONMETRICSW PICONMETRICS;
typedef LPICONMETRICSW LPICONMETRICS;
#else
typedef ICONMETRICSA ICONMETRICS;
typedef PICONMETRICSA PICONMETRICS;
typedef LPICONMETRICSA LPICONMETRICS;
#endif // UNICODE
#endif /* NOGDI */
#endif /* _WINGDI_ */

typedef struct tagANIMATIONINFO
{
    unsigned    cbSize;
    int     iMinAnimate;
}   ANIMATIONINFO, *LPANIMATIONINFO;

typedef struct tagSERIALKEYSA
{
    unsigned    cbSize;
    unsigned long   dwFlags;
    char*     lpszActivePort;
    char*     lpszPort;
    unsigned    iBaudRate;
    unsigned    iPortState;
    unsigned    iActive;
}   SERIALKEYSA, *LPSERIALKEYSA;
typedef struct tagSERIALKEYSW
{
    unsigned    cbSize;
    unsigned long   dwFlags;
    wchar_t*    lpszActivePort;
    wchar_t*    lpszPort;
    unsigned    iBaudRate;
    unsigned    iPortState;
    unsigned    iActive;
}   SERIALKEYSW, *LPSERIALKEYSW;
#ifdef UNICODE
typedef SERIALKEYSW SERIALKEYS;
typedef LPSERIALKEYSW LPSERIALKEYS;
#else
typedef SERIALKEYSA SERIALKEYS;
typedef LPSERIALKEYSA LPSERIALKEYS;
#endif // UNICODE

/* flags for SERIALKEYS dwFlags field */
#define SERKF_SERIALKEYSON  0x00000001
#define SERKF_AVAILABLE     0x00000002
#define SERKF_INDICATOR     0x00000004


typedef struct tagHIGHCONTRASTA
{
    unsigned    cbSize;
    unsigned long   dwFlags;
    char*   lpszDefaultScheme;
}   HIGHCONTRASTA, *LPHIGHCONTRASTA;
typedef struct tagHIGHCONTRASTW
{
    unsigned    cbSize;
    unsigned long   dwFlags;
    wchar_t*  lpszDefaultScheme;
}   HIGHCONTRASTW, *LPHIGHCONTRASTW;
#ifdef UNICODE
typedef HIGHCONTRASTW HIGHCONTRAST;
typedef LPHIGHCONTRASTW LPHIGHCONTRAST;
#else
typedef HIGHCONTRASTA HIGHCONTRAST;
typedef LPHIGHCONTRASTA LPHIGHCONTRAST;
#endif // UNICODE

/* flags for HIGHCONTRAST dwFlags field */
#define HCF_HIGHCONTRASTON  0x00000001
#define HCF_AVAILABLE       0x00000002
#define HCF_HOTKEYACTIVE    0x00000004
#define HCF_CONFIRMHOTKEY   0x00000008
#define HCF_HOTKEYSOUND     0x00000010
#define HCF_INDICATOR       0x00000020
#define HCF_HOTKEYAVAILABLE 0x00000040

/* Flags for ChangeDisplaySettings */
#define CDS_UPDATEREGISTRY  0x00000001
#define CDS_TEST            0x00000002
#define CDS_FULLSCREEN      0x00000004
#define CDS_GLOBAL          0x00000008
#define CDS_SET_PRIMARY     0x00000010
#define CDS_RESET           0x40000000
#define CDS_SETRECT         0x20000000
#define CDS_NORESET         0x10000000

/* Return values for ChangeDisplaySettings */
#define DISP_CHANGE_SUCCESSFUL       0
#define DISP_CHANGE_RESTART          1
#define DISP_CHANGE_FAILED          -1
#define DISP_CHANGE_BADMODE         -2
#define DISP_CHANGE_NOTUPDATED      -3
#define DISP_CHANGE_BADFLAGS        -4
#define DISP_CHANGE_BADPARAM        -5

#ifdef _WINGDI_
#ifndef NOGDI

/*WINUSERAPI*/
long
__stdcall
ChangeDisplaySettingsA(
    LPDEVMODEA  lpDevMode,
    unsigned long       dwFlags);
/*WINUSERAPI*/
long
__stdcall
ChangeDisplaySettingsW(
    LPDEVMODEW  lpDevMode,
    unsigned long       dwFlags);
#ifdef UNICODE
#define ChangeDisplaySettings  ChangeDisplaySettingsW
#else
#define ChangeDisplaySettings  ChangeDisplaySettingsA
#endif // !UNICODE

/*WINUSERAPI*/
long
__stdcall
ChangeDisplaySettingsExA(
    const char*    lpszDeviceName,
    LPDEVMODEA  lpDevMode,
    HWND        hwnd,
    unsigned long       dwflags,
    void*      lParam);
/*WINUSERAPI*/
long
__stdcall
ChangeDisplaySettingsExW(
    const wchar_t*    lpszDeviceName,
    LPDEVMODEW  lpDevMode,
    HWND        hwnd,
    unsigned long       dwflags,
    void*      lParam);
#ifdef UNICODE
#define ChangeDisplaySettingsEx  ChangeDisplaySettingsExW
#else
#define ChangeDisplaySettingsEx  ChangeDisplaySettingsExA
#endif // !UNICODE

#define ENUM_CURRENT_SETTINGS       ((unsigned long)-1)
#define ENUM_REGISTRY_SETTINGS      ((unsigned long)-2)

/*WINUSERAPI*/
BOOL
__stdcall
EnumDisplaySettingsA(
    const char* lpszDeviceName,
    unsigned long iModeNum,
    LPDEVMODEA lpDevMode);
/*WINUSERAPI*/
BOOL
__stdcall
EnumDisplaySettingsW(
    const wchar_t* lpszDeviceName,
    unsigned long iModeNum,
    LPDEVMODEW lpDevMode);
#ifdef UNICODE
#define EnumDisplaySettings  EnumDisplaySettingsW
#else
#define EnumDisplaySettings  EnumDisplaySettingsA
#endif // !UNICODE


#endif /* NOGDI */
#endif /* _WINGDI_ */


/*WINUSERAPI*/
BOOL
__stdcall
SystemParametersInfoA(
    unsigned uiAction,
    unsigned uiParam,
    void* pvParam,
    unsigned fWinIni);
/*WINUSERAPI*/
BOOL
__stdcall
SystemParametersInfoW(
    unsigned uiAction,
    unsigned uiParam,
    void* pvParam,
    unsigned fWinIni);
#ifdef UNICODE
#define SystemParametersInfo  SystemParametersInfoW
#else
#define SystemParametersInfo  SystemParametersInfoA
#endif // !UNICODE

#endif  /* !NOSYSPARAMSINFO  */

/*
 * Accessibility support
 */
typedef struct tagFILTERKEYS
{
    unsigned  cbSize;
    unsigned long dwFlags;
    unsigned long iWaitMSec;            // Acceptance Delay
    unsigned long iDelayMSec;           // Delay Until Repeat
    unsigned long iRepeatMSec;          // Repeat Rate
    unsigned long iBounceMSec;          // Debounce Time
} FILTERKEYS, *LPFILTERKEYS;

/*
 * FILTERKEYS dwFlags field
 */
#define FKF_FILTERKEYSON    0x00000001
#define FKF_AVAILABLE       0x00000002
#define FKF_HOTKEYACTIVE    0x00000004
#define FKF_CONFIRMHOTKEY   0x00000008
#define FKF_HOTKEYSOUND     0x00000010
#define FKF_INDICATOR       0x00000020
#define FKF_CLICKON         0x00000040

typedef struct tagSTICKYKEYS
{
    unsigned  cbSize;
    unsigned long dwFlags;
} STICKYKEYS, *LPSTICKYKEYS;

/*
 * STICKYKEYS dwFlags field
 */
#define SKF_STICKYKEYSON    0x00000001
#define SKF_AVAILABLE       0x00000002
#define SKF_HOTKEYACTIVE    0x00000004
#define SKF_CONFIRMHOTKEY   0x00000008
#define SKF_HOTKEYSOUND     0x00000010
#define SKF_INDICATOR       0x00000020
#define SKF_AUDIBLEFEEDBACK 0x00000040
#define SKF_TRISTATE        0x00000080
#define SKF_TWOKEYSOFF      0x00000100

typedef struct tagMOUSEKEYS
{
    unsigned cbSize;
    unsigned long dwFlags;
    unsigned long iMaxSpeed;
    unsigned long iTimeToMaxSpeed;
    unsigned long iCtrlSpeed;
    unsigned long dwReserved1;
    unsigned long dwReserved2;
} MOUSEKEYS, *LPMOUSEKEYS;

/*
 * MOUSEKEYS dwFlags field
 */
#define MKF_MOUSEKEYSON     0x00000001
#define MKF_AVAILABLE       0x00000002
#define MKF_HOTKEYACTIVE    0x00000004
#define MKF_CONFIRMHOTKEY   0x00000008
#define MKF_HOTKEYSOUND     0x00000010
#define MKF_INDICATOR       0x00000020
#define MKF_MODIFIERS       0x00000040
#define MKF_REPLACENUMBERS  0x00000080

typedef struct tagACCESSTIMEOUT
{
    unsigned  cbSize;
    unsigned long dwFlags;
    unsigned long iTimeOutMSec;
} ACCESSTIMEOUT, *LPACCESSTIMEOUT;

/*
 * ACCESSTIMEOUT dwFlags field
 */
#define ATF_TIMEOUTON       0x00000001
#define ATF_ONOFFFEEDBACK   0x00000002

/* values for SOUNDSENTRY iFSGrafEffect field */
#define SSGF_NONE       0
#define SSGF_DISPLAY    3

/* values for SOUNDSENTRY iFSTextEffect field */
#define SSTF_NONE       0
#define SSTF_CHARS      1
#define SSTF_BORDER     2
#define SSTF_DISPLAY    3

/* values for SOUNDSENTRY iWindowsEffect field */
#define SSWF_NONE     0
#define SSWF_TITLE    1
#define SSWF_WINDOW   2
#define SSWF_DISPLAY  3
#define SSWF_CUSTOM   4

typedef struct tagSOUNDSENTRYA
{
    unsigned cbSize;
    unsigned long dwFlags;
    unsigned long iFSTextEffect;
    unsigned long iFSTextEffectMSec;
    unsigned long iFSTextEffectColorBits;
    unsigned long iFSGrafEffect;
    unsigned long iFSGrafEffectMSec;
    unsigned long iFSGrafEffectColor;
    unsigned long iWindowsEffect;
    unsigned long iWindowsEffectMSec;
    char*   lpszWindowsEffectDLL;
    unsigned long iWindowsEffectOrdinal;
} SOUNDSENTRYA, *LPSOUNDSENTRYA;
typedef struct tagSOUNDSENTRYW
{
    unsigned cbSize;
    unsigned long dwFlags;
    unsigned long iFSTextEffect;
    unsigned long iFSTextEffectMSec;
    unsigned long iFSTextEffectColorBits;
    unsigned long iFSGrafEffect;
    unsigned long iFSGrafEffectMSec;
    unsigned long iFSGrafEffectColor;
    unsigned long iWindowsEffect;
    unsigned long iWindowsEffectMSec;
    wchar_t*  lpszWindowsEffectDLL;
    unsigned long iWindowsEffectOrdinal;
} SOUNDSENTRYW, *LPSOUNDSENTRYW;
#ifdef UNICODE
typedef SOUNDSENTRYW SOUNDSENTRY;
typedef LPSOUNDSENTRYW LPSOUNDSENTRY;
#else
typedef SOUNDSENTRYA SOUNDSENTRY;
typedef LPSOUNDSENTRYA LPSOUNDSENTRY;
#endif // UNICODE

/*
 * SOUNDSENTRY dwFlags field
 */
#define SSF_SOUNDSENTRYON   0x00000001
#define SSF_AVAILABLE       0x00000002
#define SSF_INDICATOR       0x00000004

typedef struct tagTOGGLEKEYS
{
    unsigned cbSize;
    unsigned long dwFlags;
} TOGGLEKEYS, *LPTOGGLEKEYS;

/*
 * TOGGLEKEYS dwFlags field
 */
#define TKF_TOGGLEKEYSON    0x00000001
#define TKF_AVAILABLE       0x00000002
#define TKF_HOTKEYACTIVE    0x00000004
#define TKF_CONFIRMHOTKEY   0x00000008
#define TKF_HOTKEYSOUND     0x00000010
#define TKF_INDICATOR       0x00000020




/*
 * Set debug level
 */

/*WINUSERAPI*/
VOID
__stdcall
SetDebugErrorLevel(
    unsigned long dwLevel
    );

/*
 * SetLastErrorEx() types.
 */

#define SLE_ERROR       0x00000001
#define SLE_MINORERROR  0x00000002
#define SLE_WARNING     0x00000003

/*WINUSERAPI*/
VOID
__stdcall
SetLastErrorEx(
    unsigned long dwErrCode,
    unsigned long dwType
    );


#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* !_WINUSER_ */
#pragma once 
