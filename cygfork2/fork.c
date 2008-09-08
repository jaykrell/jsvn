/* BSD license
*/

#include <windows.h>

typedef struct _CLIENT_ID {
  HANDLE  UniqueProcess;
  HANDLE  UniqueThread;
} CLIENT_ID, *PCLIENT_ID;

typedef PVOID;

#define NtCurrentProcess() ((HANDLE)0xFFFFFFFF)
#define NtCurrentThread() ((HANDLE)0xFFFFFFFE)

#define NTOSAPI __declspec(dllimport)
#define NTAPI __stdcall
typedef long NTSTATUS;
typedef PVOID POBJECT_ATTRIBUTES;

typedef struct _USER_STACK {
	PVOID  FixedStackBase;
	PVOID  FixedStackLimit;
	PVOID  ExpandableStackBase;
	PVOID  ExpandableStackLimit;
	PVOID  ExpandableStackBottom;
} USER_STACK, *PUSER_STACK;

NTSYSAPI
NTSTATUS
NTAPI
ZwTerminateProcess (
  /*IN*/ HANDLE   ProcessHandle /*OPTIONAL*/,
  /*IN*/ NTSTATUS ExitStatus
);

NTOSAPI
NTSTATUS
NTAPI
ZwCreateThread(
  /*OUT*/ PHANDLE  ThreadHandle,
  /*IN*/ ACCESS_MASK  DesiredAccess,
  /*IN*/ POBJECT_ATTRIBUTES  ObjectAttributes,
  /*IN*/ HANDLE  ProcessHandle,
  /*OUT*/ PCLIENT_ID  ClientId,
  /*IN*/ PCONTEXT  ThreadContext,
  /*IN*/ PUSER_STACK  UserStack,
  /*IN*/ BOOLEAN  CreateSuspended);

NTOSAPI
NTSTATUS
NTAPI
ZwCreateProcess(
  /*OUT*/ PHANDLE  ProcessHandle,
  /*IN*/ ACCESS_MASK  DesiredAccess,
  /*IN*/ POBJECT_ATTRIBUTES  ObjectAttributes,
  /*IN*/ HANDLE  InheritFromProcessHandle,
  /*IN*/ BOOLEAN  InheritHandles,
  /*IN*/ HANDLE  SectionHandle  /*OPTIONAL*/,
  /*IN*/ HANDLE  DebugPort  /*OPTIONAL*/,
  /*IN*/ HANDLE  ExceptionPort  /*OPTIONAL*/);

#pragma comment(lib, "ntdll.lib")
__declspec(dllimport) void __cdecl DbgPrint(const char*, ...);

typedef int pid_t;

#define NT_SUCCESS(x) ((x)>=0)

__declspec(dllimport) int __cdecl cygwin3_sprintf(char*, const char*, ...);
__declspec(dllimport) int* __cdecl cygwin3___errno(void); /* cygwin */
__declspec(dllimport) int* __cdecl _errno(void); /* msvcrt */
#undef errno
#define errno (*cygwin3___errno())
//#define errno (*__errno())
//#define errno (*_errno())

#define	ENOMEM 12 /* Not enough core */
#define	EINVAL 22 /* Invalid argument */

static int __fastcall SetErrno(int Error) { errno = Error; return -1; }

__declspec(dllexport) pid_t __cdecl fork(void)
{
    struct
    {
        NTSTATUS Status;
        HANDLE Process;
        HANDLE Thread;
        CLIENT_ID ClientId;
        CONTEXT Context;
        DWORD Parent;
    } L;

    ZeroMemory(&L, sizeof(L));

    L.Context.ContextFlags = (CONTEXT_FULL | CONTEXT_FLOATING_POINT);

    L.Parent = GetCurrentProcessId();

    DbgPrint("%u:%u fork\n", GetCurrentProcessId(), GetCurrentThreadId());

    if (IsDebuggerPresent())
        DebugBreak();

    L.Status = ZwCreateProcess(&L.Process, (GENERIC_ALL | SYNCHRONIZE), NULL, NtCurrentProcess(), TRUE, NULL, NULL, NULL);
    if (!NT_SUCCESS(L.Status))
        goto Exit;

    L.Status = -1;
    if (!GetThreadContext(GetCurrentThread(), &L.Context))
        goto Exit;

    L.Status = ZwCreateThread(&L.Thread, (GENERIC_ALL | SYNCHRONIZE), NULL, L.Process, &L.ClientId, &L.Context, (PUSER_STACK) NtCurrentTeb(), FALSE);
    if (!NT_SUCCESS(L.Status))
        goto Exit;

    DbgPrint("%u:%u fork.1\n", GetCurrentProcessId(), GetCurrentThreadId());

    if (L.Parent == (HANDLE) GetCurrentProcessId())
    {
        DbgPrint("parent\n");
    }
    else
    {
        DbgPrint("child\n");
        ZwTerminateProcess(NtCurrentProcess(), -1);
    }

Exit:
    if (!NT_SUCCESS(L.Status))
    {
#if 0
        if (L.Process)
            NtClose(L.Process);
        if (L.Thread)
            NtClose(L.Thread);
#endif
        SetErrno(L.Status);
        return -1;
    }
    return (int) L.ClientId.UniqueProcess;
}

__declspec(dllexport) pid_t __cdecl vfork(void) { return fork(); }
__declspec(dllexport) pid_t __cdecl _vfork(void) { return fork(); }
__declspec(dllexport) pid_t __cdecl _fork(void) { return fork(); }

/* --------------------------------------------------------------------------- */

