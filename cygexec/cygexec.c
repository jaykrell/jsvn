#include <windows.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <process.h>
#include <stdio.h>

char* timestring()
{
    time_t t = time(NULL);
    char* s = asctime(localtime(&t));
    char* u = (s + strlen(s) - 1);
    while (isspace(*u))
        *(u--) = 0;
    return s;
}

int main(
    int argc,
    char** argv,
    char** env
    )
{
    LARGE_INTEGER t1 = { 0 };
    LARGE_INTEGER t2 = { 0 };
    LARGE_INTEGER freq = { 0 };
    char* ts1 = { 0 };
    char* ts2 = { 0 };
    unsigned i = { 0 };
    unsigned j = { 0 };
    static char * const args1[] = { "sh -c ./cygnothing", "/bin/sh", "-c", "./cygnothing", 0 };
    static char * const args2[] = { "sh -c ./cygnocyg", "/bin/sh", "-c", "./cygnocyg", 0 };
    static char * const args3[] = { "sh -c ./msvcdll", "/bin/sh", "-c", "./msvcdll", 0 };
    static char * const args4[] = { "ash -c ./cygnothing", "/bin/ash", "-c", "./cygnothing", 0 };
    static char * const args5[] = { "ash -c ./cygnocyg", "/bin/ash", "-c", "./cygnocyg", 0 };
    static char * const args6[] = { "ash -c ./msvcdll", "/bin/ash", "-c", "./msvcdll", 0 };
    static char * const args7[] = { "zsh -c ./cygnothing", "/bin/zsh", "-c", "./cygnothing", 0 };
    static char * const args8[] = { "zsh -c ./cygnocyg", "/bin/zsh", "-c", "./cygnocyg", 0 };
    static char * const args9[] = { "zsh -c ./msvcdll", "/bin/zsh", "-c", "./msvcdll", 0 };
    static char * const argsa[] = { ".\\cygnothing", "./cygnothing", 0 };
    static char * const argsb[] = { ".\\cygnocyg", "./cygnocyg", 0 };
    static char * const argsc[] = { ".\\msvcdll", "./msvcdll", 0 };
    static char * const argsd[] = { ".\\msvcstatic", "./msvcstatic", 0 };
    static char * const argse[] = { ".\\msvcmin", "./msvcmin", 0 };
    static char * const * const args[] = {
        /* sh */
        args1, args2, args3,

        /* ash */
        /* args4, args5, args6, */

        /* zh */
        /* args7, args8, args9, */

        /* no sh */
        argsa, argsb, argsc, argsd, argse,
    };
    int status = { 0 };
    pid_t pid = { 0 };
    int err;
    typedef int (*system_t)(const char*);
    system_t cygwin_system = { 0 };
    system_t msvcrt_system = { 0 };
    void* cygwin = { 0 };
    void* msvcrt = { 0 };
    FILE* f = { 0 };
    const unsigned iterations = 500;
    static char const * const Commands[] =
    {
        "gcc ./mainret.c -o ./cygnothing.exe",
        "gcc -mno-cygwin ./mainret.c -o ./cygnocyg.exe",
        "/msdev/80/vc/bin/cl -nologo -MD ./mainret.c -link -out:./msvcdll.exe -libpath:/msdev/80/vc/lib",
        "/msdev/80/vc/bin/cl -nologo -MT ./mainret.c -link -out:./msvcstatic.exe -libpath:/msdev/80/vc/lib",
        "/msdev/80/vc/bin/cl -nologo ./fastexit.c -link -out:./msvcmin.exe -libpath:/msdev/80/vc/lib -nodefaultlib kernel32.lib -entry:Entry -subsystem:console",
        0
    };

    QueryPerformanceFrequency(&freq);
    SetThreadAffinityMask(GetCurrentThread(), 1);

    cygwin = LoadLibraryW(L"cygwin1.dll");
    msvcrt = LoadLibraryW(L"msvcrt.dll");

    cygwin_system = (system_t) GetProcAddress(cygwin, "system");
    msvcrt_system = (system_t) GetProcAddress(msvcrt, "system");

    f = fopen("./mainret.c", "w");
    fprintf(f, "int main() { return 0; }\n");
    fclose(f);
    f = fopen("./fastexit.c", "w");
    fprintf(f,
            "void __stdcall TerminateProcess(void*, unsigned long);\n"
            "void* __stdcall GetCurrentProcess(void);\n"
            "void Entry() { TerminateProcess(GetCurrentProcess(), 0); }\n");
    fclose(f);
    for (i = 0 ; Commands[i]; ++i)
    {
        printf("%s\n", Commands[i]);
        fflush(stdout);
        msvcrt_system(Commands[i]);
    }

    printf("pagesize %x\n", (unsigned) getpagesize());
    fflush(stdout);

#if 1
    printf("%s\n", timestring());
    QueryPerformanceCounter(&t1);
    for (i = 0 ; i != 200 ; ++i)
    {
        pid = vfork();
        if (pid == 0)
        {
            _exit(99);
        }
        else if (pid < 0)
        {
            err = errno;
            printf("vfork failed %d %d %d\n", (int) i, (int) pid, (int) err);
            fflush(stdout);
            exit(err);
        }
    }
    QueryPerformanceCounter(&t2);
    printf("%s vfork %f\n", timestring(), ((t2.QuadPart - t1.QuadPart) / (double) freq.QuadPart));
    fflush(stdout);
#endif

    for (j = 0 ; j != sizeof(args)/sizeof(args[0]) ; ++j)
    {
        char * const * a = args[j];

#if 1
        QueryPerformanceCounter(&t1);
        for (i = 0 ; i != iterations ; ++i)
        {
            pid = vfork();
            if (pid == 0)
            {
                execve(a[1], &a[1], env);
                _exit(99);
            }
            else if (pid < 0)
            {
                err = errno;
                printf("vfork failed %d %d %d\n", (int) i, (int) pid, (int) err);
                fflush(stdout);
                exit(err);
            }
            else
            {
                waitpid(pid, &status, 0);
            }
        }
        QueryPerformanceCounter(&t2);
        printf("%s vfork/exec(%s) %f\n", timestring(), a[0], ((t2.QuadPart - t1.QuadPart) / (double) freq.QuadPart));
        fflush(stdout);
#endif

#if 1
        QueryPerformanceCounter(&t1);
        for (i = 0 ; i != iterations ; ++i)
        {
            pid = spawnve(_P_NOWAIT, a[1], &a[1], env);
            if (pid < 0)
            {
                err = errno;
                printf("spawnve failed %d %d %d\n", (int) i, (int) pid, (int) err);
                fflush(stdout);
                exit(err);
            }
            waitpid(pid, &status, 0);
        }
        QueryPerformanceCounter(&t2);
        printf("%s spawn(nowait, %s)/waitpid %f\n", timestring(), a[0], ((t2.QuadPart - t1.QuadPart) / (double) freq.QuadPart));
        fflush(stdout);

        QueryPerformanceCounter(&t1);
        for (i = 0 ; i != iterations ; ++i)
        {
            pid = spawnve(_P_WAIT, a[1], &a[1], env);
            if (pid < 0)
            {
                err = errno;
                printf("spawnve failed %d %d %d\n", (int) i, (int) pid, (int) err);
                fflush(stdout);
                exit(err);
            }
        }
        QueryPerformanceCounter(&t2);
        printf("%s spawn(wait, %s) %f\n", timestring(), a[0], ((t2.QuadPart - t1.QuadPart) / (double) freq.QuadPart));
        fflush(stdout);
#endif
        if (a[0][0] == '.')
        {
            STARTUPINFOA StartupInfo;
            PROCESS_INFORMATION ProcessInfo;

            ZeroMemory(&StartupInfo, sizeof(StartupInfo));
            ZeroMemory(&ProcessInfo, sizeof(ProcessInfo));
            StartupInfo.cb = sizeof(StartupInfo);
#if 1
            QueryPerformanceCounter(&t1);
            for (i = 0 ; i != iterations ; ++i)
            {
                cygwin_system(a[1]);
            }
            QueryPerformanceCounter(&t2);
            printf("%s cygwin_system(%s) %f\n", timestring(), a[1], ((t2.QuadPart - t1.QuadPart) / (double) freq.QuadPart));
            fflush(stdout);
#endif
            QueryPerformanceCounter(&t1);
            for (i = 0 ; i != iterations ; ++i)
            {
                msvcrt_system(a[0]);
            }
            QueryPerformanceCounter(&t2);
            printf("%s msvcrt_system(%s) %f\n", timestring(), a[0], ((t2.QuadPart - t1.QuadPart) / (double) freq.QuadPart));
            fflush(stdout);

            QueryPerformanceCounter(&t1);
            for (i = 0 ; i != iterations ; ++i)
            {
                if (!CreateProcessA(NULL, a[0], NULL, NULL, FALSE, 0, NULL, NULL, &StartupInfo, &ProcessInfo))
                {
                    err = GetLastError();
                    printf("CreateProcess(%s) failed %d\n", a[0], err);
                    fflush(stdout);
                    exit(err);
                }
                CloseHandle(ProcessInfo.hThread);
                WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
                CloseHandle(ProcessInfo.hProcess);
            }
            QueryPerformanceCounter(&t2);
            printf("%s CreateProcess(%s) %f\n", timestring(), a[0], ((t2.QuadPart - t1.QuadPart) / (double) freq.QuadPart));
            fflush(stdout);
        }
    }

    return 0;

}
