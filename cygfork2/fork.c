/* BSD license
*/

#define _WIN32_WINNT 0xFFFF

#include <windows.h>

typedef struct _CLIENT_ID {
  HANDLE  UniqueProcess;
  HANDLE  UniqueThread;
} CLIENT_ID, *PCLIENT_ID;

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

__declspec(dllimport) void __cdecl DbgPrint(const char*, ...);


NTSTATUS
NTAPI
NtTerminateProcess (
    /*IN*/ HANDLE   ProcessHandle /*OPTIONAL*/,
    /*IN*/ NTSTATUS ExitStatus
    );

NTSTATUS
NTAPI
NtCreateThread(
    /*OUT*/ PHANDLE  ThreadHandle,
    /*IN*/ ACCESS_MASK  DesiredAccess,
    /*IN*/ POBJECT_ATTRIBUTES  ObjectAttributes,
    /*IN*/ HANDLE  ProcessHandle,
    /*OUT*/ PCLIENT_ID  ClientId,
    /*IN*/ PCONTEXT  ThreadContext,
    /*IN*/ PUSER_STACK  UserStack,
    /*IN*/ BOOLEAN  CreateSuspended
    );

NTSTATUS
NTAPI
NtCreateProcess(
    /*OUT*/ PHANDLE  ProcessHandle,
    /*IN*/ ACCESS_MASK  DesiredAccess,
    /*IN*/ POBJECT_ATTRIBUTES  ObjectAttributes,
    /*IN*/ HANDLE  InheritFromProcessHandle,
    /*IN*/ BOOLEAN  InheritHandles,
    /*IN*/ HANDLE  SectionHandle  /*OPTIONAL*/,
    /*IN*/ HANDLE  DebugPort  /*OPTIONAL*/,
    /*IN*/ HANDLE  ExceptionPort  /*OPTIONAL*/
    );

#define NT_SUCCESS(x) ((x)>=0)

typedef int pid_t;

__declspec(dllimport) int* __cdecl cygwin3___errno(void); /* cygwin */
#undef errno
#define errno (*cygwin3___errno())
//#define errno (*__errno())
//#define errno (*_errno())

#define	ENOMEM 12 /* Not enough core */
#define	EINVAL 22 /* Invalid argument */

static int __fastcall SetErrno(int Error) { errno = Error; return -1; }

__declspec(dllexport) pid_t __cdecl fork(void)
{
    volatile struct
    {
        NTSTATUS Status;
        HANDLE Process;
        HANDLE Thread;
        CLIENT_ID ClientId;
        CONTEXT Context;
        UINT32 Parent;
        UINT32 xebp,xebx,xedi,xesi,xesp,xeip;
    } L;

    ZeroMemory(&L, sizeof(L));

    L.Context.ContextFlags = (CONTEXT_FULL | CONTEXT_FLOATING_POINT);

    L.Parent = GetCurrentProcessId();

    DbgPrint("%u:%u fork\n", GetCurrentProcessId(), GetCurrentThreadId());

    if (IsDebuggerPresent())
        DebugBreak();

    L.Status = -1;
    if (!GetThreadContext(GetCurrentThread(), &L.Context))
        goto Exit;

    __asm
    {
        mov L.xebp, ebp
        mov L.xebx, ebx
        mov L.xedi, edi
        mov L.xesi, esi
        mov L.xesp, esp
/* not clear where we resume, so add some padding and resume in the middle of it */
        nop
        nop
        nop
        nop
        call get_eip
get_eip:
        pop eax
        sub eax,8
        mov L.xeip, eax
    }
    L.Context.Ebp = L.xebp;
    L.Context.Ebx = L.xebx;
    L.Context.Edi = L.xedi;
    L.Context.Esi = L.xesi;
    L.Context.Esp = L.xesp;
    L.Context.Eip = L.xeip;

    if (L.Parent == GetCurrentProcessId())
    {
        L.Status = NtCreateProcess(&L.Process, (GENERIC_ALL | SYNCHRONIZE), NULL, NtCurrentProcess(), TRUE, NULL, NULL, NULL);
        if (!NT_SUCCESS(L.Status))
            goto Exit;

        L.Status = NtCreateThread(&L.Thread, (GENERIC_ALL | SYNCHRONIZE), NULL, L.Process, &L.ClientId, &L.Context, (PUSER_STACK) NtCurrentTeb(), FALSE);
        if (!NT_SUCCESS(L.Status))
            goto Exit;
    }

    if (IsDebuggerPresent())
        DebugBreak();
    DbgPrint("%u:%u fork.1\n", GetCurrentProcessId(), GetCurrentThreadId());

    if (L.Parent == GetCurrentProcessId())
    {
        DbgPrint("parent\n");
    }
    else
    {
        DbgPrint("child\n");
        return 0;
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
    //return L.Process;
}

__declspec(dllexport) pid_t __cdecl vfork(void) { return fork(); }
__declspec(dllexport) pid_t __cdecl _vfork(void) { return fork(); }
__declspec(dllexport) pid_t __cdecl _fork(void) { return fork(); }

/* --------------------------------------------------------------------------- */

