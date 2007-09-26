/***
* mbstring.h - MBCS string manipulation macros and functions
*
*       Copyright (c) 1990-1997, Microsoft Corporation.  All rights reserved.
*
*Purpose:
*       This file contains macros and function declarations for the MBCS
*       string manipulation functions.
*
*       [Public]
*
****/

#if     _MSC_VER > 1000
#pragma once
#endif

#ifndef _INC_MBSTRING
#define _INC_MBSTRING

#if     !defined(_WIN32) && !defined(_MAC)
#error ERROR: Only Mac or Win32 targets supported!
#endif


#ifdef  _MSC_VER
/*
 * Currently, all MS C compilers for Win32 platforms default to 8 byte
 * alignment.
 */
#pragma pack(push,8)
#endif  /* _MSC_VER */

#ifdef  __cplusplus
extern "C" {
#endif


/* Define _CRTIMP */

#ifndef _CRTIMP
#ifdef  _DLL
#define _CRTIMP __declspec(dllimport)
#else   /* ndef _DLL */
#define _CRTIMP
#endif  /* _DLL */
#endif  /* _CRTIMP */


/* Define __cdecl for non-Microsoft compilers */

#if     ( !defined(_MSC_VER) && !defined(__cdecl) )
#define __cdecl
#endif


#ifndef _SIZE_T_DEFINED
typedef unsigned int size_t;
#define _SIZE_T_DEFINED
#endif


#ifndef _NLSCMP_DEFINED
#define _NLSCMPERROR    2147483647      /* currently == INT_MAX */
#define _NLSCMP_DEFINED
#endif


#ifndef _VA_LIST_DEFINED
#ifdef  _M_ALPHA
typedef struct {
        char *a0;       /* pointer to first homed integer argument */
        int offset;     /* byte offset of next parameter */
} va_list;
#else
typedef char *  va_list;
#endif
#define _VA_LIST_DEFINED
#endif

#ifndef _FILE_DEFINED
struct _iobuf {
        char *_ptr;
        int   _cnt;
        char *_base;
        int   _flag;
        int   _file;
        int   _charbuf;
        int   _bufsiz;
        char *_tmpfname;
        };
typedef struct _iobuf FILE;
#define _FILE_DEFINED
#endif

/*
 * MBCS - Multi-Byte Character Set
 */

#ifndef _MBSTRING_DEFINED

/* function prototypes */

/*_CRTIMP*/ unsigned int __cdecl _mbbtombc(unsigned int);
/*_CRTIMP*/ int __cdecl _mbbtype(char, int);
/*_CRTIMP*/ unsigned int __cdecl _mbctombb(unsigned int);
/*_CRTIMP*/ int __cdecl _mbsbtype(const char *, size_t);
/*_CRTIMP*/ char * __cdecl _mbscat(char *, const char *);
/*_CRTIMP*/ char * __cdecl _mbschr(const char *, unsigned int);
/*_CRTIMP*/ int __cdecl _mbscmp(const char *, const char *);
/*_CRTIMP*/ int __cdecl _mbscoll(const char *, const char *);
/*_CRTIMP*/ char * __cdecl _mbscpy(char *, const char *);
/*_CRTIMP*/ size_t __cdecl _mbscspn(const char *, const char *);
/*_CRTIMP*/ char * __cdecl _mbsdec(const char *, const char *);
/*_CRTIMP*/ char * __cdecl _mbsdup(const char *);
/*_CRTIMP*/ int __cdecl _mbsicmp(const char *, const char *);
/*_CRTIMP*/ int __cdecl _mbsicoll(const char *, const char *);
/*_CRTIMP*/ char * __cdecl _mbsinc(const char *);
/*_CRTIMP*/ size_t __cdecl _mbslen(const char *);
/*_CRTIMP*/ char * __cdecl _mbslwr(char *);
/*_CRTIMP*/ char * __cdecl _mbsnbcat(char *, const char *, size_t);
/*_CRTIMP*/ int __cdecl _mbsnbcmp(const char *, const char *, size_t);
/*_CRTIMP*/ int __cdecl _mbsnbcoll(const char *, const char *, size_t);
/*_CRTIMP*/ size_t __cdecl _mbsnbcnt(const char *, size_t);
/*_CRTIMP*/ char * __cdecl _mbsnbcpy(char *, const char *, size_t);
/*_CRTIMP*/ int __cdecl _mbsnbicmp(const char *, const char *, size_t);
/*_CRTIMP*/ int __cdecl _mbsnbicoll(const char *, const char *, size_t);
/*_CRTIMP*/ char * __cdecl _mbsnbset(char *, unsigned int, size_t);
/*_CRTIMP*/ char * __cdecl _mbsncat(char *, const char *, size_t);
/*_CRTIMP*/ size_t __cdecl _mbsnccnt(const char *, size_t);
/*_CRTIMP*/ int __cdecl _mbsncmp(const char *, const char *, size_t);
/*_CRTIMP*/ int __cdecl _mbsncoll(const char *, const char *, size_t);
/*_CRTIMP*/ char * __cdecl _mbsncpy(char *, const char *, size_t);
/*_CRTIMP*/ unsigned int __cdecl _mbsnextc (const char *);
/*_CRTIMP*/ int __cdecl _mbsnicmp(const char *, const char *, size_t);
/*_CRTIMP*/ int __cdecl _mbsnicoll(const char *, const char *, size_t);
/*_CRTIMP*/ char * __cdecl _mbsninc(const char *, size_t);
/*_CRTIMP*/ char * __cdecl _mbsnset(char *, unsigned int, size_t);
/*_CRTIMP*/ char * __cdecl _mbspbrk(const char *, const char *);
/*_CRTIMP*/ char * __cdecl _mbsrchr(const char *, unsigned int);
/*_CRTIMP*/ char * __cdecl _mbsrev(char *);
/*_CRTIMP*/ char * __cdecl _mbsset(char *, unsigned int);
/*_CRTIMP*/ size_t __cdecl _mbsspn(const char *, const char *);
/*_CRTIMP*/ char * __cdecl _mbsspnp(const char *, const char *);
/*_CRTIMP*/ char * __cdecl _mbsstr(const char *, const char *);
/*_CRTIMP*/ char * __cdecl _mbstok(char *, const char *);
/*_CRTIMP*/ char * __cdecl _mbsupr(char *);

/*_CRTIMP*/ size_t __cdecl _mbclen(const char *);
/*_CRTIMP*/ void __cdecl _mbccpy(char *, const char *);
#define _mbccmp(_cpc1, _cpc2) _mbsncmp((_cpc1),(_cpc2),1)

/* character routines */

/*_CRTIMP*/ int __cdecl _ismbcalnum(unsigned int);
/*_CRTIMP*/ int __cdecl _ismbcalpha(unsigned int);
/*_CRTIMP*/ int __cdecl _ismbcdigit(unsigned int);
/*_CRTIMP*/ int __cdecl _ismbcgraph(unsigned int);
/*_CRTIMP*/ int __cdecl _ismbclegal(unsigned int);
/*_CRTIMP*/ int __cdecl _ismbclower(unsigned int);
/*_CRTIMP*/ int __cdecl _ismbcprint(unsigned int);
/*_CRTIMP*/ int __cdecl _ismbcpunct(unsigned int);
/*_CRTIMP*/ int __cdecl _ismbcspace(unsigned int);
/*_CRTIMP*/ int __cdecl _ismbcupper(unsigned int);

/*_CRTIMP*/ unsigned int __cdecl _mbctolower(unsigned int);
/*_CRTIMP*/ unsigned int __cdecl _mbctoupper(unsigned int);

#define _MBSTRING_DEFINED
#endif

#ifndef _MBLEADTRAIL_DEFINED
/*_CRTIMP*/ int __cdecl _ismbblead( unsigned int );
/*_CRTIMP*/ int __cdecl _ismbbtrail( unsigned int );
/*_CRTIMP*/ int __cdecl _ismbslead( const char *, const char *);
/*_CRTIMP*/ int __cdecl _ismbstrail( const char *, const char *);
#define _MBLEADTRAIL_DEFINED
#endif

/*  Kanji specific prototypes.  */

/*_CRTIMP*/ int __cdecl _ismbchira(unsigned int);
/*_CRTIMP*/ int __cdecl _ismbckata(unsigned int);
/*_CRTIMP*/ int __cdecl _ismbcsymbol(unsigned int);
/*_CRTIMP*/ int __cdecl _ismbcl0(unsigned int);
/*_CRTIMP*/ int __cdecl _ismbcl1(unsigned int);
/*_CRTIMP*/ int __cdecl _ismbcl2(unsigned int);
/*_CRTIMP*/ unsigned int __cdecl _mbcjistojms(unsigned int);
/*_CRTIMP*/ unsigned int __cdecl _mbcjmstojis(unsigned int);
/*_CRTIMP*/ unsigned int __cdecl _mbctohira(unsigned int);
/*_CRTIMP*/ unsigned int __cdecl _mbctokata(unsigned int);

#ifdef  __cplusplus
}
#endif

#ifdef  _MSC_VER
#pragma pack(pop)
#endif  /* _MSC_VER */

#endif  /* _INC_MBSTRING */
#pragma once 
