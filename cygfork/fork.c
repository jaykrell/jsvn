/* BSD license

The idea of fork doing setjmp and then exec longjmp, in
order for fork to return the pid, is from the documenation
explaining Cygwin's "new vfork".
*/

#define _INC_STDLIB

#include <stdarg.h>
#include <stddef.h>

/* It is difficult to be compatible with all headers, so just declare stuff ourselves. */
typedef unsigned UINT32;
typedef int BOOL;
typedef unsigned long DWORD;
typedef void* HANDLE;
#ifdef _WIN64
typedef size_t SIZE_T;
#else
typedef unsigned long SIZE_T;
#endif
#define HEAP_ZERO_MEMORY 0x00000008
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

__declspec(dllimport) int __cdecl cygwin3_printf(const char*, ...);
__declspec(dllimport) int __cdecl cygwin3_sprintf(char*, const char*, ...);
__declspec(dllimport) int* __cdecl cygwin3___errno(void); /* cygwin */
__declspec(dllimport) int* __cdecl __errno(void); /* cygwin */
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

__declspec(dllexport)
int __cdecl execvp(const char* file, char* const arg_vector[]);

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
Failed exec leaves active alone.
Successful exec clears active.
future: have one per thread data structure for the entire library
*/

typedef struct fork_t {
    UINT32 ebp;
    UINT32 ebx;
    UINT32 edi;
    UINT32 esi;
    UINT32 esp;
    UINT32 eip;
    UINT32 pid;
    UINT32 active;
} fork_t;

static long volatile fork_tls = -1;

/*
future: in support of waitpid(pid == -1, 0, <0)
pid_t* child_processes;
size_t count_child_processes;
CRITICAL_SECTION child_processes_lock;
*/

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

static
fork_t*
__stdcall
get_fork(
    void
    )
{
    long volatile tls;
    fork_t* volatile p;

    p = 0;
    tls = fork_tls;
    if (tls == -1)
    {
        tls = TlsAllocOnDemand(&fork_tls);
        if (tls == -1)
            goto Exit;
    }
    p = TlsGetValue(tls);
    if (p != NULL)
        goto Exit;

    p = (fork_t*) MemAllocZ(sizeof(*p));
    if (p == NULL)
        goto Exit;

    TlsSetValue(tls, p);
Exit:
    return p;
}

static
void
__stdcall
set_errno(
    int e
    )
{
    errno = e;
}

__declspec(naked dllexport)
pid_t __cdecl fork(void)
{
    OutputDebugStringA("fork\n");
    __asm
    {
        call get_fork
        cmp eax, 0
        je err

        mov DWORD PTR [eax], ebp
        mov DWORD PTR [eax + 4], ebx
        mov DWORD PTR [eax + 8], edi
        mov DWORD PTR [eax + 0xC], esi
        mov DWORD PTR [eax + 0x10], esp
        mov ecx, DWORD PTR [esp]
        mov DWORD PTR [eax + 0x14], ecx
        mov DWORD PTR [eax + 0x1C], 1 /* active = 1 */
        mov eax, 0
        ret
err:
        push ENOMEM
        call set_errno
        add esp,4
        mov eax, -1
        ret
    }
}

__declspec(naked dllexport) pid_t __cdecl vfork(void) { __asm { jmp fork } }
__declspec(naked dllexport) pid_t __cdecl _vfork(void) { __asm { jmp fork } }
__declspec(naked dllexport) pid_t __cdecl _fork(void) { __asm { jmp fork } }

int cygwin3_close(int);

__declspec(dllexport)
int __cdecl close(int fd)
{
    /* if a fork is "active", ignore close -- code thinks it is in child, but it isn't */
    fork_t* f;

    OutputDebugStringA("close\n");
    f = get_fork();
    if (f && f->active)
    {
        OutputDebugStringA("ignoring close\n");
        return 0;
    }
    /* call the real function */
    return cygwin3_close(fd);
}

__declspec(dllexport)
int __cdecl _close(int fd)
{
    return close(fd);
}

void cygwin3__exit(int fd);

__declspec(dllexport)
void __cdecl _exit(int status)
{
    /*
    If fork is active (ie: exec has failed, then this is to exit the new process,
    which has not actually been created. Create a dummy process and have it immediately exit.
    We can just CreateProcess(cmd, suspended) and then TerminateProcess it
    with the desired status.
    */
    fork_t* f;
#if 0
    STARTUPINFO StartupInfo;
    PROCESS_INFORMATION ProcessInfo;
#endif
    const static char arg1f[] = "/c exit /b %d";
    char arg1[sizeof(arg1f) + (sizeof(int) * 8)];
    char* argv[] = {"cmd.exe", arg1, 0};

    OutputDebugStringA("_exit\n");

    f = get_fork();
    if ((!f) || (!f->active))
    {
        /* call the real function */
        cygwin3__exit(status);
        return;
    }

#if 0
    /* We don't know what the spawn/wait pids are at this point, so should
    delegate to the real exec/spawn. Later we will either know they are
    Win32 pids, or Win32 handles, and/or implement exec/spawn ourselves. */
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
    cygwin3_printf("running: %s\n", arg1);
    execvp(argv[0], argv);
#endif
}

__declspec(naked)
static pid_t __fastcall fork_return(fork_t* f)
{
#if 1
    __asm
    {
        push ecx
    }
    OutputDebugStringA("fork_return\n");
    if (IsDebuggerPresent())
        DebugBreak();
    __asm
    {
        pop ecx
    }
#endif
    __asm
    {
        mov ebp, DWORD PTR [ecx]
        mov ebx, DWORD PTR [ecx + 4]
        mov edi, DWORD PTR [ecx + 8]
        mov esi, DWORD PTR [ecx + 0xC]
        mov esp, DWORD PTR [ecx + 0x10]
        mov eax, DWORD PTR [ecx + 0x14]
        mov DWORD PTR [esp], eax
        mov DWORD PTR [ecx + 0x1C], 0 /* active = 0 */
        mov eax, DWORD PTR [ecx + 0x18] /* pid */
        ret
    }
}

typedef struct exec_t {
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
} exec_t;

int __stdcall exec(exec_t* e)
{
    char** arg_vector = { 0 };
    char** environment = { 0 };
    fork_t* f = { 0 };
    pid_t pid;
    int mode = _P_NOWAIT;
    char* file;

    file = e->file;

    f = get_fork();
    if (!f)
    {
        set_errno(ENOMEM);
        goto Exit;
    }

    if (e->flag.arg_list == e->flag.arg_vector)
    {
        set_errno(EINVAL);
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
            set_errno(ENOMEM);
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

    cygwin3_printf("about to spawn\n");
#if 0
    if (IsDebuggerPresent())
        DebugBreak();
#endif

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
    cygwin3_printf("spawned %d\n", pid);
    if (!e->flag.arg_vector)
    {
        MemFree(arg_vector);
    }
    f->pid = pid;
    fork_return(f);

Exit:
    return -1;
}

__declspec(dllexport)
int __cdecl execl(const char* file, const char* arg0, ... )
{
    exec_t e = { 0 };
    int ret;

    OutputDebugStringA("execl\n");
    e.flag.arg_list = 1;
    e.file = (char*) file;
    e.arg0 = (char*) arg0;
    va_start(e.arg_list, arg0);
    ret = exec(&e);
    va_end(e.arg_list);
    return ret;
}

__declspec(dllexport)
int __cdecl execv(const char* file, char* const arg_vector[])
{
    exec_t e = { 0 };

    OutputDebugStringA("execv\n");
    e.flag.arg_vector = 1;
    e.file = (char*) file;
    e.arg_vector = (char**) arg_vector;
    return exec(&e);
}

__declspec(dllexport)
int __cdecl execle(const char* file, const char* arg0, ... )
{
    exec_t e = { 0 };
    int ret;

    OutputDebugStringA("execle\n");
    e.flag.environment = 1;
    e.flag.arg_list = 1;
    e.arg0 = (char*) arg0;
    e.file = (char*) file;
    va_start(e.arg_list, arg0);
    ret = exec(&e);
    va_end(e.arg_list);
    return ret;
}

__declspec(dllexport)
int __cdecl execve(const char* file, char* const arg_vector[], char* const environment[])
{
    exec_t e = { 0 };

    OutputDebugStringA("execve\n");
    e.flag.arg_vector = 1;
    e.flag.environment = 1;
    e.arg_vector = (char**) arg_vector;
    e.environment = (char**) environment;
    e.file = (char*) file;
    return exec(&e);
}

__declspec(dllexport)
int __cdecl execlp(const char* file, const char* arg0, ... )
{
    exec_t e = { 0 };
    int ret;

    OutputDebugStringA("execlp\n");
    e.flag.search_path = 1;
    e.flag.arg_list = 1;
    e.arg0 = (char*) arg0;
    e.file = (char*) file;
    va_start(e.arg_list, arg0);
    ret = exec(&e);
    va_end(e.arg_list);
    return ret;
}

__declspec(dllexport)
int __cdecl execvp(const char* file, char* const arg_vector[])
{
    exec_t e = { 0 };

    OutputDebugStringA("execvp\n");
    e.flag.search_path = 1;
    e.flag.arg_vector = 1;
    e.file = (char*) file;
    e.arg_vector = (char**) arg_vector;
    return exec(&e);
}
