#pragma once
/*****************************************************************/
/**               Microsoft Windows 4.00                        **/
/**           Copyright (C) Microsoft Corp., 1995-1996          **/
/*****************************************************************/

/* WPAPI.H -- WebPost Interface definitions
 *
 */

#ifndef _wpapi_h_
#define _wpapi_h_

//
// Assume packing on unsigned long boundary
//
#include <pshpack4.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct tagWPSITEINFOA {
	unsigned long	dwSize;
	unsigned long	dwFlags;
	LPSTR	lpszSiteName;
	LPSTR	lpszSiteURL;
} WPSITEINFOA, *LPWPSITEINFOA;

typedef struct tagWPSITEINFOW {
	unsigned long	dwSize;
	unsigned long	dwFlags;
	LPWSTR	lpszSiteName;
	LPWSTR	lpszSiteURL;
} WPSITEINFOW, *LPWPSITEINFOW;

// dwFlag from WPSITEINFO
#define WPSF_CAN_BROWSE_DIR			0x00000001
#define WPSF_NEEDS_COMMIT			0x00000002
#define WPSF_CONNECTED_TO_NETWORK	0x00000004
#define WPSF_LOGGED_IN_TO_SERVER	0x00000008

#ifdef UNICODE
#define WPSITEINFO				WPSITEINFOW
#define LPWPSITEINFO			LPWPSITEINFOW

#else
#define WPSITEINFO				WPSITEINFOA
#define LPWPSITEINFO			LPWPSITEINFOA

#endif


// dwFlag for WpPost
#define WPF_NO_RECURSIVE_POST		0x00000001
#define WPF_NO_WIZARD				0x00000002
#define WPF_MINIMAL_UI				0x00000004
#define WPF_FIRST_FILE_AS_DEFAULT	0x00000008

unsigned long WINAPI WpPostW(HWND hwnd, 
					unsigned long cLocalPaths, LPWSTR *lppszLocalPaths, 
					LPDWORD lpcbSiteName, LPWSTR lpszSiteName,
					LPDWORD lpcbURL, LPWSTR lpszURL, 
					unsigned long dwFlag);
unsigned long WINAPI WpListSitesW(LPDWORD lpcbSites, LPWPSITEINFOW lpSiteInfo,
							LPDWORD lpcSites);
unsigned long WINAPI WpDeleteSiteW(const wchar_t* lpszSiteName);

unsigned long WINAPI
WpBindToSiteW(
	HWND	hwnd,
	const wchar_t*	lpszSiteName,
	const wchar_t*	lpszURL,
	unsigned long	dwFlag,
	unsigned long	dwReserved,
    void* 	*ppvObj);

unsigned long WINAPI WpPostA(HWND hwnd,
					unsigned long cLocalPaths, LPSTR *lppszLocalPaths, 
					LPDWORD lpcbSiteName, LPSTR lpszSiteName,
					LPDWORD lpcbURL, LPSTR lpszURL, 
					unsigned long dwFlag);
unsigned long WINAPI WpListSitesA(LPDWORD lpcbSites, LPWPSITEINFOA lpSiteInfo,
							LPDWORD lpcSites);
unsigned long WINAPI WpDeleteSiteA(const char* lpszSiteName);

unsigned long WINAPI
WpBindToSiteA(
	HWND	hwnd,
	const char*	lpszSiteName,
	const char*	lpszURL,
	unsigned long	dwFlag,
	unsigned long	dwReserved,
    void* 	*ppvObj);


#ifdef UNICODE
#define WpPost					WpPostW
#define WpListSites				WpListSitesW
#define WpDeleteSite			WpDeleteSiteW
#define WpBindToSite			WpBindToSiteW

#else
#define WpPost					WpPostA
#define WpListSites				WpListSitesA
#define WpDeleteSite			WpDeleteSiteA
#define WpBindToSite			WpBindToSiteA

#endif


#ifdef __cplusplus
}
#endif

#include <poppack.h>

#endif // _wpapi_h_
#pragma once 
