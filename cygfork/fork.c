/* BSD license

The idea of fork doing setjmp and then exec longjmp, in
order for fork to return the pid, is from the documenation
explaining Cygwin's "new vfork".
*/

#define _INC_STDLIB

#include <stdarg.h>
#include <windows.h>

#if 0
__declspec(dllimport) void* __cdecl malloc(size_t);
__declspec(dllimport) void __cdecl free(void*);
#else
static void* __stdcall MemAlloc(size_t n) { return HeapAlloc(GetProcessHeap(), 0, n); }
static void __stdcall MemFree(void* p) { HeapFree(GetProcessHeap(), 0, p); }
#endif

__declspec(dllimport) int* __cdecl printf(const char*, ...);
__declspec(dllimport) int* __cdecl __errno(void); /* cygwin */
__declspec(dllimport) int* __cdecl _errno(void); /* msvcrt */
//#define errno (*__errno())
#define errno (*_errno())

#define	ENOMEM 12 /* Not enough core */
#define	EINVAL 22 /* Invalid argument */

#define _P_VFORK    0
#define _P_WAIT		1
#define _P_NOWAIT	2
#define _P_OVERLAY	3
#define _P_NOWAITO	4
#define _P_DETACH	5

/* --------------------------------------------------------------------- */

typedef int pid_t;

// http://en.wikipedia.org/wiki/Spawn_%28computing%29

//__declspec(dllimport) int __cdecl spawnl(int mode, char* file, char* arg0, ...);
//__declspec(dllimport) int __cdecl spawnle(int mode, char* file, char* arg0, ... /*, char** environment */);
//__declspec(dllimport) int __cdecl spawnlp(int mode, char* file, char* arg0, ...);
//__declspec(dllimport) int __cdecl spawnlpe(int mode, char* file, char* arg0, ... /*, char** environment */);
__declspec(dllimport) int __cdecl spawnv(int mode, char* file, char** arg_vector);
__declspec(dllimport) int __cdecl spawnve(int mode, char* file, char** arg_vector, char** environment);
__declspec(dllimport) int __cdecl spawnvp(int mode, char* file, char** arg_vector);
__declspec(dllimport) int __cdecl spawnvpe(int mode, char* file, char** arg_vector, char** environment);

/* --------------------------------------------------------------------- */

/* There can only be one fork active per thread.
"active" means "not yet execed".
future: have one per thread data structure for the entire library
*/

typedef struct fork2_t {
    UINT32 ebp;
    UINT32 ebx;
    UINT32 edi;
    UINT32 esi;
    UINT32 esp;
    UINT32 eip;
    UINT32 pid;
    UINT32 active;
} fork2_t;

typedef struct fork1_t {
    UINT32 ebp;
    UINT32 ebx;
    UINT32 edi;
    UINT32 esi;
    UINT32 esp;
    UINT32 eip;
    UINT32 pid;
    UINT32 active;
    fork2_t* fork2;
} fork1_t;

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
    volatile long* global
    )
{
    long tls1;
    long tls2;

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
    long tls;
    fork_t* p;

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

    p = (fork_t*) MemAlloc(sizeof(*p));
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
    //errno = e;
}

#if 0

__declspec(dllexport)
pid_t
__cdecl
fork(
    void
    )
{
    register fork_t* volatile p;

    p = get_fork();
    if (!p)
    {
        set_errno(ENOMEM);
        return -1;
    }
    if (setjmp(p->jmp))
    {
        /* return second time in parent process */
        return p->pid;
    }
    /* continue in "child process" -- will exec */
    return 0;
}

#elif 0

/* must be inlined in the caller to avoid needing a return address that will get trashed.
Well, at least the setjmp call is needed there; we could push some work into a function.
NOTE: This is really vfork.
*/

#define fork() (get_fork() ? (setjmp(get_fork()->jmp) ? get_fork()->pid : 0) : (set_errno(ENOMEM), -1))

#else

/* macro not compatible with intent to drop in on top of cygwin1.dll, with forwarding to renamed cygwin1.dll
of all other functions */

__declspec(naked dllexport)
pid_t __cdecl fork(void)
{
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

__declspec(dllimport) int cygclose(int);

__declspec(dllexport)
int close(int fd)
{
    /* if a fork is "active", ignore close -- code think it is in child, but it isn't */
    fork_t* f;

    f = get_fork();
    if (f && f->active)
    {
        return 0;
    }
    return cygclose(fd);
}

__declspec(dllexport)
int _close(int fd)
{
    return close(fd);
}

__declspec(dllimport) void cyg_exit(int fd);

__declspec(dllexport)
void _exit(int status)
{
    /* if a fork is "active", ignore _exit -- exec probably failed */
    fork_t* f;

    f = get_fork();
    if (f && f->active)
    {
        return;
    }
    cyg_exit(status);
}

__declspec(naked)
static pid_t __fastcall fork_return(fork_t* f)
{
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

#endif

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
            environment = e->environment;
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

    //printf("about to spawn\n");

    switch ((e->flag.search_path << 1) | e->flag.environment)
    {
    case 0:
        pid = spawnv(mode, file, arg_vector);
        break;
    case 1:
        pid = spawnve(mode, file, arg_vector, environment);
        break;
    case 2:
        pid = spawnvp(mode, file, arg_vector);
        break;
    case 3:
        pid = spawnvpe(mode, file, arg_vector, environment);
        break;
    }
    //printf("spawned %d\n", pid);
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

    e.flag.search_path = 1;
    e.flag.arg_vector = 1;
    e.file = (char*) file;
    e.arg_vector = (char**) arg_vector;
    return exec(&e);
}

#ifdef MAIN

//#include <stdio.h>

int main()
{
    volatile int pid;
    char * arg[] = {"cmd", 0};

    pid = fork();
    if (pid == 0)
    {
        printf("child\n");
        execvp(arg[0], arg);
    }
    else
    {
        printf("waiting for %d\n", pid);
        waitpid(pid);
    }
}

void mainCRTStartup(void)
{
    volatile char a[0x2000];
    //_alloca(0x2000);
    a[0] = 0;
    a[0x1FFF] = 0;
    cygwin_dll_init();
    main();
}

#endif
