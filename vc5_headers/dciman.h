/****************************************************************************

 DCIMAN.H

 Copyright (C) 1993-1994 Microsoft Corporation.  All Rights Reserved.

 DCIMAN 1.0 client interface definitions

 ***************************************************************************/

#ifndef _INC_DCIMAN
#define _INC_DCIMAN

#ifdef __cplusplus
    #define __inline inline
    extern "C" {
#endif

/****************************************************************************
 ***************************************************************************/

#include "dciddi.h"         // interface to the DCI provider

/****************************************************************************
 ***************************************************************************/

DECLARE_HANDLE(HWINWATCH);  // context handle for WinWatch instance

/****************************************************************************
 ***************************************************************************/

HDC __stdcall DCIOpenProvider(void);
void __stdcall DCICloseProvider(HDC hdc);

int __stdcall DCICreatePrimary(HDC hdc, LPDCISURFACEINFO  *lplpSurface);
int __stdcall DCICreateOffscreen(HDC hdc, unsigned long dwCompression, unsigned long dwRedMask,
    unsigned long dwGreenMask, unsigned long dwBlueMask, unsigned long dwWidth, unsigned long dwHeight, 
    unsigned long dwDCICaps, unsigned long dwBitCount, LPDCIOFFSCREEN  *lplpSurface);
int __stdcall DCICreateOverlay(HDC hdc, void* lpOffscreenSurf, 
    LPDCIOVERLAY  *lplpSurface);
int __stdcall DCIEnum(HDC hdc, LPRECT lprDst, LPRECT lprSrc, void* lpFnCallback,
    void* lpContext);
DCIRVAL __stdcall DCISetSrcDestClip(LPDCIOFFSCREEN pdci, LPRECT srcrc,
			LPRECT destrc, LPRGNDATA prd );

HWINWATCH __stdcall WinWatchOpen(HWND hwnd);
void      __stdcall WinWatchClose(HWINWATCH hWW);

// API changed to copy region data instead of return pointer to it
UINT	 __stdcall WinWatchGetClipList(HWINWATCH hWW, LPRECT prc,
				UINT size,  LPRGNDATA prd);
BOOL      __stdcall WinWatchDidStatusChange(HWINWATCH hWW);

unsigned long     __stdcall GetWindowRegionData(HWND hwnd, unsigned long size, LPRGNDATA prd);
unsigned long     __stdcall GetDCRegionData(HDC hdc, unsigned long size, LPRGNDATA prd);


#define WINWATCHNOTIFY_START        0
#define WINWATCHNOTIFY_STOP         1
#define WINWATCHNOTIFY_DESTROY      2
#define WINWATCHNOTIFY_CHANGING     3
#define WINWATCHNOTIFY_CHANGED      4
typedef void (__stdcall *WINWATCHNOTIFYPROC)(HWINWATCH hww, HWND hwnd, unsigned long code, LPARAM lParam);

BOOL __stdcall WinWatchNotify(HWINWATCH hWW, WINWATCHNOTIFYPROC NotifyCallback,
						LPARAM NotifyParam );

#ifdef WIN32
/****************************************************************************
 helper functions to call DCIMAN16.DLL
 ***************************************************************************/
void __stdcall DCIEndAccess(LPDCISURFACEINFO pdci);
DCIRVAL __stdcall DCIBeginAccess(LPDCISURFACEINFO pdci, int x, int y, int dx, int dy);
void __stdcall DCIDestroy(LPDCISURFACEINFO pdci);
DCIRVAL __stdcall DCIDraw(LPDCIOFFSCREEN pdci);
DCIRVAL __stdcall DCISetClipList(LPDCIOFFSCREEN pdci, LPRGNDATA prd);
DCIRVAL __stdcall DCISetDestination(LPDCIOFFSCREEN pdci, LPRECT dst, LPRECT src);


#else

int __stdcall DCISendCommand(HDC hdc, void  *pcmd, int nSize, void  *  * lplpOut);

/****************************************************************************
 helper macros to call DCI callbacks
 ***************************************************************************/
__inline void DCIDestroy(LPDCISURFACEINFO pdci)
{
	if( pdci->DestroySurface != NULL ) {
		pdci->DestroySurface(pdci);
	}
}

__inline void DCIEndAccess(LPDCISURFACEINFO pdci)
{
	if( pdci->EndAccess != NULL ) {
		pdci->EndAccess(pdci);
	}
}

__inline DCIRVAL DCIBeginAccess(LPDCISURFACEINFO pdci, int x, int y, int dx, int dy)
{
    RECT rc;

	if( pdci->BeginAccess != NULL ) {
		rc.left=x;
		rc.top=y;
		rc.right = rc.left+dx;
		rc.bottom = rc.top+dy;
		return pdci->BeginAccess(pdci, &rc);
	} else {
		return DCI_OK;
	}
}

__inline DCIRVAL DCIDraw(LPDCIOFFSCREEN pdci)
{
	if( pdci->Draw != NULL ) {
		return pdci->Draw(pdci);
	} else {
		return DCI_OK;
	}
}

__inline DCIRVAL DCISetClipList(LPDCIOFFSCREEN pdci, LPRGNDATA prd)
{
	if( pdci->SetClipList != NULL ) {
		return pdci->SetClipList(pdci, prd);
	} else {
		return DCI_OK;
	}
}

__inline DCIRVAL DCISetDestination(LPDCIOFFSCREEN pdci, LPRECT dst, LPRECT src)
{
	if( pdci->SetDestination != NULL ) {
		return pdci->SetDestination(pdci, dst, src);
	} else {
		return DCI_OK;
	}
}
#endif

/****************************************************************************
 ***************************************************************************/

#ifdef __cplusplus
    }
#endif

#endif // _INC_DCIMAN
