/*
** lzdos.h - Public interface to LZEXP?.LIB.
*/

#ifndef _LZEXPAND_
#define _LZEXPAND_

#ifdef __cplusplus
extern "C" {
#endif

/*
** Error Return Codes
*/

#define LZERROR_BADINHANDLE   (-1)  /* invalid input handle */
#define LZERROR_BADOUTHANDLE  (-2)  /* invalid output handle */
#define LZERROR_READ          (-3)  /* corrupt compressed file format */
#define LZERROR_WRITE         (-4)  /* out of space for output file */
#define LZERROR_GLOBALLOC     (-5)  /* insufficient memory for LZFile struct */
#define LZERROR_GLOBLOCK      (-6)  /* bad global handle */
#define LZERROR_BADVALUE      (-7)  /* input parameter out of acceptable range*/
#define LZERROR_UNKNOWNALG    (-8)  /* compression algorithm not recognized */


/*
** Prototypes
*/

int
__stdcall
LZStart(
	VOID
	);

VOID
__stdcall
LZDone(
	VOID
	);

long
__stdcall
CopyLZFile(
	int,
	int
	);

long
__stdcall
LZCopy(
	int,
	int
	);

int
__stdcall
LZInit(
	int
	);

int
__stdcall
GetExpandedNameA(
	char*,
	char*
	);
int
__stdcall
GetExpandedNameW(
	wchar_t*,
	wchar_t*
	);
#ifdef UNICODE
#define GetExpandedName  GetExpandedNameW
#else
#define GetExpandedName  GetExpandedNameA
#endif // !UNICODE

int
__stdcall
LZOpenFileA(
	char*,
	LPOFSTRUCT,
	WORD
	);
int
__stdcall
LZOpenFileW(
	wchar_t*,
	LPOFSTRUCT,
	WORD
	);
#ifdef UNICODE
#define LZOpenFile  LZOpenFileW
#else
#define LZOpenFile  LZOpenFileA
#endif // !UNICODE

long
__stdcall
LZSeek(
	int,
	long,
	int
	);

int
__stdcall
LZRead(
	int,
	char*,
	int
	);

VOID
__stdcall
LZClose(
	int
	);

#ifdef __cplusplus
}
#endif


#endif // _LZEXPAND_
#pragma once 
