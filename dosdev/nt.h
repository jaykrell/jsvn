/*
http://undocumented.ntinternals.net/UserMode/Undocumented%20Functions/NT%20Objects/Symbolic%20Link/NtCreateSymbolicLinkObject.html
http://msdn2.microsoft.com/en-us/library/aa491657.aspx
http://msdn2.microsoft.com/en-us/library/ms802947.aspx
http://www.osronline.com/ddkx/kmarch/k112_401e.htm
http://linux.dell.com/files/libsmbios/main/miniddk_8h.html
*/

#if _MSC_VER > 1000
#pragma once
#endif

#ifndef J_NT_H
#define J_NT_H

struct IRpcStubBuffer; /* \MSDEV\20\INCLUDE\rpcndr.h(1824) : warning C4115: 'IRpcStubBuffer' : named type definition in parentheses */
struct _RPC_ASYNC_STATE; /* \msdev\60\VC98\INCLUDE\rpcasync.h(45) : warning C4115: '_RPC_ASYNC_STATE' : named type definition in parentheses */

#pragma warning(disable:4127) /* conditional expression is constant */
#pragma warning(disable:4226) /* nonstandard extension: __export */
#pragma warning(disable:4201) /* nonstandard extension: nameless struct/union */
#pragma warning(disable:4214) /* nonstandard extension: bitfields other than int */
#pragma warning(disable:4209) /* nonstandard extension: benign retypedef */
#pragma warning(disable:4514) /* unused inline function removed */

#if _MSC_VER < 1000
#pragma warning(disable:4705) /* statement has no effect using UNREFERENCED_PARAMETER */
#endif

#if _MSC_VER < 1200
#pragma warning(disable:4057) /* unsigned short* vs. const unsigned short* on any use of wprintf */
#endif

typedef long NTSTATUS;
#define NTAPI __stdcall
#define IN
#define OUT
typedef void* HANDLE;
typedef HANDLE* PHANDLE;
typedef unsigned long ULONG;
typedef ULONG ACCESS_MASK;
typedef unsigned short USHORT;
typedef unsigned short WCHAR;
typedef WCHAR* PWSTR;
typedef void* PVOID;
#define CONST const

#define OBJ_CASE_INSENSITIVE 0x00000040
#define OBJ_PERMANENT 0x00000010L

typedef struct _UNICODE_STRING {
  USHORT Length;
  USHORT MaximumLength;
  PWSTR Buffer;
} UNICODE_STRING, *PUNICODE_STRING;

typedef struct _OBJECT_ATTRIBUTES {
    ULONG Length;
    HANDLE RootDirectory;
    PUNICODE_STRING ObjectName;
    ULONG Attributes;
    PVOID SecurityDescriptor;
    PVOID SecurityQualityOfService;
} OBJECT_ATTRIBUTES, *POBJECT_ATTRIBUTES;
typedef CONST OBJECT_ATTRIBUTES *PCOBJECT_ATTRIBUTES;

#define InitializeObjectAttributes(p, n, a, r, s) \
    do { \
        (p)->Length = sizeof(OBJECT_ATTRIBUTES); \
        (p)->RootDirectory = r; \
        (p)->Attributes = a; \
        (p)->ObjectName = n; \
        (p)->SecurityDescriptor = s; \
        (p)->SecurityQualityOfService = 0; \
    } while(0) 

NTSTATUS
NTAPI
NtCreateSymbolicLinkObject(
  OUT PHANDLE pHandle,
  IN ACCESS_MASK DesiredAccess,
  IN POBJECT_ATTRIBUTES ObjectAttributes,
  IN PUNICODE_STRING DestinationName
  );

NTSTATUS
NTAPI
NtClose(
  HANDLE Handle
  );

#endif
