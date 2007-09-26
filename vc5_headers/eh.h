/***
*eh.h - User include file for exception handling.
*
*       Copyright (c) 1993-1997, Microsoft Corporation. All rights reserved.
*
*Purpose:
*       User include file for exception handling.
*
*       [Public]
*
****/

#if     _MSC_VER > 1000
#pragma once
#endif

#ifndef _INC_EH
#define _INC_EH

#if     !defined(_WIN32) && !defined(_MAC)
#error ERROR: Only Mac or Win32 targets supported!
#endif


#ifdef  _MSC_VER
// Currently, all MS C compilers for Win32 platforms default to 8 byte
// alignment.
#pragma pack(push,8)
#endif  // _MSC_VER

#ifndef __cplusplus
#error "eh.h is only for C++!"
#endif


/* Define _CRTIMP */

#ifndef _CRTIMP
#ifdef  _DLL
#define _CRTIMP __declspec(dllimport)
#else   /* ndef _DLL */
#define _CRTIMP
#endif  /* _DLL */
#endif  /* _CRTIMP */

typedef void (__cdecl *terminate_function)();
typedef void (__cdecl *unexpected_function)();
typedef void (__cdecl *terminate_handler)();
typedef void (__cdecl *unexpected_handler)();

#ifndef _MAC
struct _EXCEPTION_POINTERS;
typedef void (__cdecl *_se_translator_function)(unsigned int, struct _EXCEPTION_POINTERS*);
#endif

/*_CRTIMP*/ void __cdecl terminate(void);
/*_CRTIMP*/ void __cdecl unexpected(void);

/*_CRTIMP*/ terminate_function __cdecl set_terminate(terminate_function);
/*_CRTIMP*/ unexpected_function __cdecl set_unexpected(unexpected_function);
#ifndef _MAC
/*_CRTIMP*/ _se_translator_function __cdecl _set_se_translator(_se_translator_function);
#endif

#ifdef  _MSC_VER
#pragma pack(pop)
#endif  // _MSC_VER

#endif  // _INC_EH
#pragma once 
