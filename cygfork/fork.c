/* BSD license

The idea of fork doing setjmp and then Exec longjmp, in
order for fork to return the pid, is from the documenation
explaining Cygwin's "new vfork".
*/

#define _INC_STDLIB
#include <stdarg.h>

#define NUMBER_OF(x) (sizeof(x) / sizeof(x)[0])
#define NULL 0UL

typedef unsigned char UINT8;
typedef unsigned UINT32;
typedef int BOOL;
typedef unsigned long DWORD;
typedef void* HANDLE;
#ifdef _WIN64
typedef unsigned __int64 size_t;
typedef unsigned __int64 size_t;
#else
typedef unsigned int size_t;
typedef unsigned long SIZE_T;
#endif
#define TRUE 1
#define FALSE 0
#define HEAP_ZERO_MEMORY 0x00000008
#pragma comment(lib, "ntdll.lib")
__declspec(dllimport) void __cdecl DbgPrint(const char*, ...);
__declspec(dllimport) void* __stdcall HeapAlloc(HANDLE, DWORD, SIZE_T);
__declspec(dllimport) BOOL __stdcall HeapFree(HANDLE, DWORD, void*);
__declspec(dllimport) long __stdcall InterlockedCompareExchange(volatile long*, long, long);
__declspec(dllimport) int __stdcall IsDebuggerPresent(void);
__declspec(dllimport) void __stdcall OutputDebugStringA(const char*);
__declspec(dllimport) void* __stdcall GetProcessHeap(void);
__declspec(dllimport) BOOL __stdcall TlsSetValue(DWORD, void*);
__declspec(dllimport) void* __stdcall TlsGetValue(DWORD);
__declspec(dllimport) DWORD __stdcall TlsAlloc(void);
__declspec(dllimport) BOOL __stdcall TlsFree(DWORD);
__declspec(dllimport) void __stdcall DebugBreak(void);
__declspec(dllimport) void __stdcall RtlMoveMemory(void*, void*, size_t);
__declspec(dllimport) void __stdcall RtlZeroMemory(void*, size_t);
__declspec(dllimport) DWORD __stdcall GetCurrentProcessId(void);
__declspec(dllimport) DWORD __stdcall GetCurrentThreadId(void);

#define F_GETFD 1
#define	F_SETFD 2
#define	FD_CLOEXEC 1
__declspec(dllimport) int __cdecl cygwin3_fcntl(int, int, int);
__declspec(dllimport) int cygwin3_close(int);

static BOOL Debug = FALSE;

static void* __stdcall MemAlloc(size_t n)
{ 
    return HeapAlloc(GetProcessHeap(), 0, n);
}

static void* __stdcall MemAllocZ(size_t n)
{
    return HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, n);
}

static void __stdcall MemFree(void* p)
{
    HeapFree(GetProcessHeap(), 0, p);
}

__declspec(dllimport) int __cdecl cygwin3_sprintf(char*, const char*, ...);
__declspec(dllimport) int* __cdecl cygwin3___errno(void); /* cygwin */
__declspec(dllimport) int* __cdecl _errno(void); /* msvcrt */
#define errno (*cygwin3___errno())
//#define errno (*__errno())
//#define errno (*_errno())

#define	ENOMEM 12 /* Not enough core */
#define	EINVAL 22 /* Invalid argument */

#define _P_VFORK    0
#define _P_WAIT		1
#define _P_NOWAIT	2
#define _P_OVERLAY	3
#define _P_NOWAITO	4
#define _P_DETACH	5

__declspec(dllexport) int __cdecl execvp(const char* file, char* const arg_vector[]);

/* --------------------------------------------------------------------- */

typedef int pid_t;

// http://en.wikipedia.org/wiki/Spawn_%28computing%29

//int __cdecl spawnl(int mode, char* file, char* arg0, ...);
//int __cdecl spawnle(int mode, char* file, char* arg0, ... /*, char** environment */);
//int __cdecl spawnlp(int mode, char* file, char* arg0, ...);
//int __cdecl spawnlpe(int mode, char* file, char* arg0, ... /*, char** environment */);
__declspec(dllimport) int __cdecl spawnv(int mode, char* file, char** arg_vector);
__declspec(dllimport) int __cdecl spawnve(int mode, char* file, char** arg_vector, char** environment);
__declspec(dllimport) int __cdecl spawnvp(int mode, char* file, char** arg_vector);
__declspec(dllimport) int __cdecl spawnvpe(int mode, char* file, char** arg_vector, char** environment);

/* --------------------------------------------------------------------- */

/* There can only be one fork active per thread.
"active" means "not yet execed".
Failed Exec leaves active alone.
Successful Exec clears active.
future: have one per thread data structure for the entire library
*/

typedef void siginfo_t;
typedef void* _sig_func_ptr;
typedef unsigned long sigset_t;

#define SIG_SETMASK 0

struct sigaction
{
    union
    {
        _sig_func_ptr sa_handler;
        void (__cdecl * sa_sigaction)(int, siginfo_t *, void *);
    } u;
    sigset_t sa_mask;
    int sa_flags;
};
typedef struct sigaction sigaction_t;

typedef struct Fork_t {
    UINT32 ebp;
    UINT32 ebx;
    UINT32 edi;
    UINT32 esi;
    UINT32 esp;
    UINT32 pid;
    UINT32 Active;

    /* fork and Exec are "far apart" in bash

    execute_disk_command
        make_child
            fork
        shell_execve
            execve

    as a result, while ForkReturn would return to the
    parent code in make_child, it would still return to the
    child code in execute_disk_command, which calls exit.

    The fix for this is to save away and restore the stack,
    or at least "enough" of it.
    */
    UINT8 Stack[0x1000000];
    UINT32 StackSize;

    /*
    Between fork and exec, any calls to signal/sigation
    are meant to affect the child. We save the previous
    state and restore it for the parent in ForkReturn.
    */
    sigaction_t ParentSignalAction[34];
    sigset_t ParentSignalMask;

    struct
    {
        size_t Count;
        size_t Handles[64];
    } ParentCloseFiles;

} Fork_t;

static long volatile ForkTls = -1;

/*
future: in support of waitpid(pid == -1, 0, <0)
pid_t* child_processes;
size_t count_child_processes;
CRITICAL_SECTION child_processes_lock;
*/

/* --------------------------------------------------------------------------- */

__declspec(naked)
static
UINT8*
GetStackTop(void)
{
    __asm
    {
        mov eax, fs:[4]
        ret
    }
}

/* --------------------------------------------------------------------------- */

__declspec(dllimport) int __cdecl cygwin3_sigaction(int Signal, const sigaction_t* Action, sigaction_t* OldAction);
__declspec(dllimport) void* __cdecl cygwin3_sigprocmask(int How, void* Set, void* OldSet);

static
pid_t
__fastcall
ForkC(
    Fork_t* Fork
    )
{
    size_t i;
    UINT8* Top;
    UINT8* Bottom;
    size_t Size;

    Top = GetStackTop();
    Bottom = (UINT8*) Fork->esp;

    Size = (Top - Bottom);
    if (Size > sizeof(Fork->Stack))
        Size = sizeof(Fork->Stack);
    Fork->StackSize = Size;
    RtlMoveMemory(Fork->Stack, Bottom, Size);

    for (i = 0 ; i != NUMBER_OF(Fork->ParentSignalAction) ; ++i)
        cygwin3_sigaction(i, NULL, &Fork->ParentSignalAction[i]);
 
    cygwin3_sigprocmask(0, NULL, &Fork->ParentSignalMask);

    RtlZeroMemory(&Fork->ParentCloseFiles, sizeof(Fork->ParentCloseFiles));

    Fork->Active = TRUE;
    return 0;
}   

/* --------------------------------------------------------------------------- */

static
Fork_t*
__fastcall
ForkReturnToParentC(
    Fork_t* Fork
    )
{
    size_t i;

    RtlMoveMemory(((UINT8*) Fork->esp), Fork->Stack, Fork->StackSize);
    Fork->Active = FALSE;

    for (i = 0 ; i != NUMBER_OF(Fork->ParentSignalAction) ; ++i)
        cygwin3_sigaction(i, &Fork->ParentSignalAction[i], NULL);

    cygwin3_sigprocmask(SIG_SETMASK, &Fork->ParentSignalMask, NULL);

    for (i = 0 ; i != Fork->ParentCloseFiles.Count ; ++i)
        cygwin3_close(Fork->ParentCloseFiles.Handles[i]);

    return Fork;
}   

/* --------------------------------------------------------------------------- */

static
long
__stdcall
TlsAllocOnDemand(
    long volatile * global
    )
{
    long volatile tls1;
    long volatile tls2;

    tls1 = *global;

    /* if already allocated, return it, done */
    if (tls1 != -1)
        return tls1;

    tls1 = TlsAlloc();

    /* If we failed, give the global another shot.
    Either someone else allocated in the interim,
    or we'll return -1 for failure. */
    if (tls1 == -1)
        return *global;

    /* attempt to store ours */
    tls2 = InterlockedCompareExchange(global, tls1, -1);

    /* did someone beat us in the race, if so, free ours */
    if (tls2 != -1)
    {
        TlsFree(tls1);
        return tls2;
    }
    return tls1;
}

/* --------------------------------------------------------------------------- */

static
Fork_t*
__stdcall
GetFork(
    void
    )
{
    long volatile tls;
    Fork_t* volatile p;

    p = 0;
    tls = ForkTls;
    if (tls == -1)
    {
        tls = TlsAllocOnDemand(&ForkTls);
        if (tls == -1)
            goto Exit;
    }
    p = TlsGetValue(tls);
    if (p != NULL)
        goto Exit;

    p = (Fork_t*) MemAllocZ(sizeof(*p));
    if (p == NULL)
        goto Exit;

    TlsSetValue(tls, p);
Exit:
    return p;
}

/* --------------------------------------------------------------------------- */

static
Fork_t*
__stdcall
GetForkNoAlloc(
    void
    )
{
    long tls = ForkTls;
    Fork_t* p = 0;
    if (tls == -1)
        goto Exit;
    p = TlsGetValue(tls);
Exit:
    return p;
}

/* --------------------------------------------------------------------------- */

static
int
__fastcall
SetErrno(
    int Error
    )
{
    errno = Error;
    return -1;
}

/* --------------------------------------------------------------------------- */

__declspec(naked dllexport) pid_t __cdecl fork(void)
{
    DbgPrint("%u:%u fork\n", GetCurrentProcessId(), GetCurrentThreadId());

    if (IsDebuggerPresent())
        DebugBreak();

    __asm
    {
        call GetFork
        mov ecx, ENOMEM
        cmp eax, 0
        je SetErrno

        mov ecx, eax
        mov DWORD PTR [eax], ebp
        mov DWORD PTR [eax + 4], ebx
        mov DWORD PTR [eax + 8], edi
        mov DWORD PTR [eax + 0xC], esi
        mov DWORD PTR [eax + 0x10], esp
        call ForkC
        ret
    }
}

__declspec(naked dllexport) pid_t __cdecl vfork(void) { __asm { jmp fork } }
__declspec(naked dllexport) pid_t __cdecl _vfork(void) { __asm { jmp fork } }
__declspec(naked dllexport) pid_t __cdecl _fork(void) { __asm { jmp fork } }

/* --------------------------------------------------------------------------- */

static int __stdcall NoteFileHandle(int FileHandle)
{
    Fork_t* Fork;

    DbgPrint("NoteFileHandle(%d)\n", FileHandle);

    if (FileHandle < 0)
        return FileHandle;

    Fork = GetForkNoAlloc();
    if ((!Fork) || (!Fork->Active))
        return FileHandle;
    
    if (Fork->ParentCloseFiles.Count >= NUMBER_OF(Fork->ParentCloseFiles.Handles))
    {
        DbgPrint("ParentCloseFiles overflow 1\n");
        if (IsDebuggerPresent())
            DebugBreak();
        return FileHandle;
    }

    Fork->ParentCloseFiles.Handles[Fork->ParentCloseFiles.Count++] = FileHandle;

    return FileHandle;
}

/* --------------------------------------------------------------------------- */

#if 1

__declspec(dllimport) int __cdecl cygwin3_dup(int FileHandle);

__declspec(dllexport) int __cdecl dup(int FileHandle)
{
    DbgPrint("dup(%d)\n", FileHandle);
    return NoteFileHandle(cygwin3_dup(FileHandle));
}

__declspec(dllexport) int __cdecl _dup(int FileHandle)
{
    DbgPrint("_dup(%d)\n", FileHandle);
    return dup(FileHandle);
}

__declspec(dllimport) int __cdecl cygwin3_dup2(int FileHandle1, int FileHandle2);

__declspec(dllexport) int __cdecl dup2(int FileHandle1, int FileHandle2)
{
    DbgPrint("dup2(%d,%d)\n", FileHandle1, FileHandle2);
    return NoteFileHandle(cygwin3_dup2(FileHandle1, FileHandle2));
}

__declspec(dllexport) int __cdecl _dup2(int FileHandle1, int FileHandle2)
{
    DbgPrint("_dup2(%d,%d)\n", FileHandle1, FileHandle2);
    return dup2(FileHandle1, FileHandle2);
}

__declspec(dllimport) int __cdecl cygwin3_open(const char* Path, int Flags, int Mode);

__declspec(dllexport) int __cdecl open(const char* Path, int Flags, int Mode)
{
    return NoteFileHandle(cygwin3_open(Path, Flags, Mode));
}

__declspec(dllexport) int __cdecl _open(const char* Path, int Flags, int Mode)
{
    return open(Path, Flags, Mode);
}

#endif

#if 0

__declspec(dllimport) int __cdecl cygwin32_read(int FileHandle, void* Buffer, unsigned CountRequested);

__declspec(dllexport) int __cdecl read(int FileHandle, void* Buffer, unsigned CountRequested)
{
    int CountActual;
    int Error;

    if (Debug)
        DbgPrint(">%u:%u read(%d,%p,%u)\n", GetCurrentProcessId(), GetCurrentThreadId(), FileHandle, Buffer, CountRequested);

    errno = 0;
    CountActual = cygwin3_read(FileHandle, Buffer, CountRequested);
    if (Debug)
    {
        Error = errno;
        DbgPrint("<%u:%u read(%d,%p,%u):%d:%d\n", GetCurrentProcessId(), GetCurrentThreadId(), FileHandle, Buffer, CountRequested, CountActual, Error);
        errno = Error;
    }
    return CountActual;
}

__declspec(dllexport) int __cdecl _read(int FileHandle, void* Buffer, unsigned CountRequested)
{
    return read(FileHandle, Buffer, CountRequested);
}

__declspec(dllimport) int __cdecl cygwin32_write(int FileHandle, const void* Buffer, unsigned CountRequested);

__declspec(dllexport) int __cdecl write(int FileHandle, const void* Buffer, unsigned CountRequested)
{
    int CountActual;
    int Error;

    CountActual = cygwin3_write(FileHandle, Buffer, CountRequested);
    DbgPrint("%u:%u write(%d,%p,%u):%d:%d\n", GetCurrentProcessId(), GetCurrentThreadId(), FileHandle, Buffer, CountRequested, CountActual, Error);
    return CountActual;
}

__declspec(dllexport) int __cdecl _write(int FileHandle, const void* Buffer, unsigned CountRequested)
{
    return write(FileHandle, Buffer, CountRequested);
}

#endif

__declspec(dllexport) int __cdecl close(int FileHandle)
{
#if 1
    /* if a fork is "active", ignore close -- code thinks it is in child, but it isn't */
    Fork_t* Fork = GetForkNoAlloc();

    if (Fork && Fork->Active)
    {
        DbgPrint("%u:%u changing close(%d) to close-on-exec\n", GetCurrentProcessId(), GetCurrentThreadId(), FileHandle);
        cygwin3_fcntl(FileHandle, F_SETFD, cygwin3_fcntl(FileHandle, F_GETFD, 0) | FD_CLOEXEC);
        return 0;
    }
#endif
    /* call the real function */
    DbgPrint("%u:%u real close(%d)\n", GetCurrentProcessId(), GetCurrentThreadId(), FileHandle);
    return cygwin3_close(FileHandle);
}

__declspec(dllexport) int __cdecl _close(int FileHandle)
{
    return close(FileHandle);
}

#define FORWARDER1(name, args_in, args_out) \
    __declspec(dllimport) void* __cdecl cygwin3_##name args_in; \
    __declspec(dllexport) void* __cdecl name args_in { return cygwin3##name args_out; } \
    __declspec(dllexport) void* __cdecl _##name args_in { return name args_out; } \

/* if a fork is "active", ignore -- code thinks it is in child, but it isn't */

#define FORWARDER2(name, args_in, args_out) \
    __declspec(dllimport) void* __cdecl cygwin3_##name args_in; \
    __declspec(dllexport) void* __cdecl name args_in \
    { \
        Fork_t* Fork = GetForkNoAlloc(); \
        if ((!Fork) || (!Fork->Active)) \
            return cygwin3_##name args_out; \
        return 0; \
    } \
    __declspec(dllexport) void* __cdecl _##name args_in { return name args_out; } \

/* --------------------------------------------------------------------------- */
/* exit, _exit, _Exit */

static void __stdcall MyExit(int status, void (__cdecl * cygexit)(int status))
{
    /*
    If fork is active (ie: Exec has failed, then this is to exit the new process,
    which has not actually been created. Create a dummy process and have it immediately exit.
    We can just CreateProcess(cmd, suspended) and then TerminateProcess it
    with the desired status.
    */
    Fork_t* Fork;
#if 0
    STARTUPINFO StartupInfo;
    PROCESS_INFORMATION ProcessInfo;
#endif
    const static char arg1f[] = "/c exit /b %d";
    char arg1[sizeof(arg1f) + (sizeof(int) * 8)];
    char* argv[] = {"cmd.exe", arg1, 0};

    if (Debug)
    {
        OutputDebugStringA("MyExit\n");
        if (IsDebuggerPresent())
        {
            //DebugBreak();
        }
    }

    Fork = GetForkNoAlloc();
    if ((!Fork) || (!Fork->Active))
    {
        /* call the real function */
        DbgPrint("%u:%u MyExit => realexit %d\n", GetCurrentProcessId(), GetCurrentThreadId(), status);
        (*cygexit)(status);
        return;
    }

#if 0
    /* We don't know what the spawn/wait pids are at this point, so should
    delegate to the real Exec/spawn. Later we will either know they are
    Win32 pids, or Win32 handles, and/or implement Exec/spawn ourselves. */
    ZeroMemory(&StartupInfo, sizeof(StartupInfo));
    ZeroMemory(&ProcessInfo, sizeof(ProcessInfo));
    StartupInfo.cb = sizeof(StartupInfo);
    if (!CreateProcess(NULL, cmd, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &StartupInfo, &ProcessInfo))
    {
        return;
    }
    CloseHandle(ProcessInfo.hThread);
    TerminateProcess(ProcessInfo.hProcess, status);
#else
    cygwin3_sprintf(arg1, arg1f, status);
    DbgPrint("%u:%u MyExit => %s %s\n", GetCurrentProcessId(), GetCurrentThreadId(), argv[0], argv[1]);
    execvp(argv[0], argv);
#endif
}

void __cdecl cygwin3_exit(int status);
void __cdecl cygwin3__exit(int status);
void __cdecl cygwin3__Exit(int status);

__declspec(dllexport)
void __cdecl exit(int status)
{
    MyExit(status, cygwin3_exit);
}

__declspec(dllexport)
void __cdecl _exit(int status)
{
    MyExit(status, cygwin3__exit);
}

__declspec(dllexport)
void __cdecl _Exit(int status)
{
    MyExit(status, cygwin3__Exit);
}

/* --------------------------------------------------------------------------- */
/* signal  */

#if 0

__declspec(dllimport) void* __cdecl cygwin3_signal(int a, void* b, void* c);
__declspec(dllexport) void* __cdecl signal(int a, void* b, void* c)
{
    Fork_t* Fork = GetForkNoAlloc();

    DbgPrint("%u:%u signal(%d)\n", GetCurrentProcessId(), GetCurrentThreadId(), a);
    if (IsDebuggerPresent())
    {
        //DebugBreak();
    }

    if ((!Fork) || (!Fork->Active))
        return cygwin3_signal (a, b, c);

    return 0;
    return cygwin3_signal (a, b, c);
}

__declspec(dllexport) void* __cdecl _signal(int a, void* b, void* c)
{
    return signal(a, b, c);
}

#endif

/* --------------------------------------------------------------------------- */
/* sigaction */

#if 0

__declspec(dllexport) int __cdecl sigaction(int Signal, const sigaction_t* Action, sigaction_t* OldAction)
{
    int Result;
    Fork_t* Fork = GetForkNoAlloc();

    if ((!Fork) || (!Fork->Active) || ((Signal + 1) >= NUMBER_OF(Fork->ParentSignalAction)) || Fork->ParentSignalAction[Signal].Valid)
    {
        Result = cygwin3_sigaction(Signal, Action, OldAction);
    }
    else
    {
        Result = cygwin3_sigaction(Signal, Action, OldAction ? OldAction : &Fork->ParentSignalAction[Signal + 1].Value);
        if (Result == 0)
        {
            if (OldAction != NULL)
                Fork->ParentSignalAction[Signal + 1].Value = *OldAction;
            Fork->ParentSignalAction[Signal + 1].Valid = TRUE;
        }
    }
    return Result;
    return cygwin3_sigaction(Signal, Action, OldAction);
}

__declspec(dllexport) int __cdecl _sigaction(int Signal, const sigaction_t* Action, sigaction_t* OldAction)
{
    return sigaction(Signal, Action, OldAction);
}

#endif

/* --------------------------------------------------------------------------- */
/* sigprocmask */

#if 0

__declspec(dllexport) void* __cdecl sigprocmask(int How, void* Set, void* OldSet)
{
    Fork_t* Fork = GetForkNoAlloc();

    if (Fork && Fork->Active && !Fork->ParentSignalMask.Valid)
    {
        cygwin3_sigprocmask(0, NULL, &Fork->ParentSignalMask.Value);
        Fork->ParentSignalMask.Valid = TRUE;
    }
    return cygwin3_sigprocmask(How, Set, OldSet);
}

__declspec(dllexport) void* __cdecl _sigprocmask(int How, void* Set, void* OldSet)
{
    return sigprocmask(How, Set, OldSet);
}

#endif

/* --------------------------------------------------------------------------- */

__declspec(naked)
static pid_t __fastcall ForkReturnToParent(Fork_t* Fork)
{
    __asm
    {
        push ecx
    }
    DbgPrint("%u:%u ForkReturn\n", GetCurrentProcessId(), GetCurrentThreadId());
    if (IsDebuggerPresent())
    {
        DebugBreak();
    }
    __asm
    {
        pop ecx
    }
    __asm
    {
        call ForkReturnToParentC
        mov ebp, DWORD PTR [eax]
        mov ebx, DWORD PTR [eax + 4]
        mov edi, DWORD PTR [eax + 8]
        mov esi, DWORD PTR [eax + 0xC]
        mov esp, DWORD PTR [eax + 0x10]
        mov eax, DWORD PTR [eax + 0x14]
        ret
    }
}

/* --------------------------------------------------------------------------- */

typedef struct Exec_t {
    va_list arg_list;
    char* file;
    char* arg0;
    char** arg_vector;
    char** environment;
    struct {
        unsigned search_path : 1;
        unsigned environment : 1;
        unsigned arg_vector : 1;
        unsigned arg_list : 1;
    } flag;
} Exec_t;

int __stdcall Exec(Exec_t* e)
{
    char** arg_vector = { 0 };
    char** environment = { 0 };
    Fork_t* Fork = { 0 };
    pid_t pid;
    int mode = _P_NOWAIT;
    char* file;

    errno = 0;

    file = e->file;

    Fork = GetFork();
    if (!Fork)
    {
        SetErrno(ENOMEM);
        goto Exit;
    }

    if (e->flag.arg_list == e->flag.arg_vector)
    {
        SetErrno(EINVAL);
        goto Exit;
    }
    if (e->flag.arg_vector)
    {
        arg_vector = e->arg_vector;
        if (e->flag.environment)
        {
            environment = e->environment;
        }
    }

    if (e->flag.arg_list)
    {
        size_t argc = 1;
        char* arg;
        va_list arg_list;
        va_list original_arg_list;

        arg_list = e->arg_list;
        arg = e->arg0;
        do
        {
            argc += 1;
        } while (va_arg(arg_list, char*));
        if (e->flag.environment)
            environment = va_arg(arg_list, char**);

        arg_list = e->arg_list;
        arg = e->arg0;
        argc = 0;
        arg_vector = (char**) MemAlloc(argc*  sizeof(char*));
        if (!arg_vector)
        {
            SetErrno(ENOMEM);
            goto Exit;
        }
        do
        {
            arg_vector[argc++] = arg;
            arg = va_arg(arg_list, char*);
        }
        while (arg);
        arg_vector[argc] = 0;
    }

    DbgPrint("%u:%u about to spawn %s\n", GetCurrentProcessId(), GetCurrentThreadId(), file);
    if (IsDebuggerPresent())
    {
        //DebugBreak();
    }

    switch ((e->flag.search_path << 1) | e->flag.environment)
    {
    case 0:
        pid = cygwin3_spawnv(mode, file, arg_vector);
        break;
    case 1:
        pid = cygwin3_spawnve(mode, file, arg_vector, environment);
        break;
    case 2:
        pid = cygwin3_spawnvp(mode, file, arg_vector);
        break;
    case 3:
        pid = cygwin3_spawnvpe(mode, file, arg_vector, environment);
        break;
    }
    DbgPrint("%u:%u spawned %s %u\n", GetCurrentProcessId(), GetCurrentThreadId(), file, pid);

    if (!e->flag.arg_vector)
    {
        MemFree(arg_vector);
    }
    Fork->pid = pid;
    ForkReturnToParent(Fork);

Exit:
    return -1;
}

/* --------------------------------------------------------------------------- */

__declspec(dllexport)
int __cdecl execl(const char* file, const char* arg0, ... )
{
    Exec_t e = { 0 };
    int ret;

    DbgPrint("%u:%u execl\n", GetCurrentProcessId(), GetCurrentThreadId());

    e.flag.arg_list = TRUE;
    e.file = (char*) file;
    e.arg0 = (char*) arg0;
    va_start(e.arg_list, arg0);
    ret = Exec(&e);
    va_end(e.arg_list);
    return ret;
}

__declspec(dllexport)
int __cdecl execv(const char* file, char* const arg_vector[])
{
    Exec_t e = { 0 };

    DbgPrint("%u:%u execv\n", GetCurrentProcessId(), GetCurrentThreadId());

    e.flag.arg_vector = TRUE;
    e.file = (char*) file;
    e.arg_vector = (char**) arg_vector;
    return Exec(&e);
}

__declspec(dllexport)
int __cdecl execle(const char* file, const char* arg0, ... )
{
    Exec_t e = { 0 };
    int ret;

    DbgPrint("%u:%u execle\n", GetCurrentProcessId(), GetCurrentThreadId());

    e.flag.environment = TRUE;
    e.flag.arg_list = TRUE;
    e.arg0 = (char*) arg0;
    e.file = (char*) file;
    va_start(e.arg_list, arg0);
    ret = Exec(&e);
    va_end(e.arg_list);
    return ret;
}

__declspec(dllexport)
int __cdecl execve(const char* file, char* const arg_vector[], char* const environment[])
{
    Exec_t e = { 0 };

    DbgPrint("%u:%u execve\n", GetCurrentProcessId(), GetCurrentThreadId());

    e.flag.arg_vector = TRUE;
    e.flag.environment = TRUE;
    e.arg_vector = (char**) arg_vector;
    e.environment = (char**) environment;
    e.file = (char*) file;
    return Exec(&e);
}

__declspec(dllexport)
int __cdecl execlp(const char* file, const char* arg0, ... )
{
    Exec_t e = { 0 };
    int ret;

    DbgPrint("%u:%u execlp\n", GetCurrentProcessId(), GetCurrentThreadId());

    e.flag.search_path = TRUE;
    e.flag.arg_list = TRUE;
    e.arg0 = (char*) arg0;
    e.file = (char*) file;
    va_start(e.arg_list, arg0);
    ret = Exec(&e);
    va_end(e.arg_list);
    return ret;
}

__declspec(dllexport)
int __cdecl execvp(const char* file, char* const arg_vector[])
{
    Exec_t e = { 0 };

    DbgPrint("%u:%u execvp\n", GetCurrentProcessId(), GetCurrentThreadId());

    e.flag.search_path = TRUE;
    e.flag.arg_vector = TRUE;
    e.file = (char*) file;
    e.arg_vector = (char**) arg_vector;
    return Exec(&e);
}
