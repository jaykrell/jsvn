#include <stdio.h>
#include <windows.h>
#include "critsec.h"

static CRITICAL_SECTION CriticalSection;

static unsigned TestCase;
static volatile long Count;
volatile BOOL Shutdown;

void
SetTestCase(
    unsigned i
    )
{
    TestCase = i;
}

void
RequestOrderlyShutdown(
    void
    )
{
    Shutdown = TRUE;
}

long
GetCount(
    void
    )
{
    return Count;
}

static
void
ThreadMainOnce(
    )
{
    static long x;

    InterlockedIncrement(&Count);

    EnterCriticalSection(&CriticalSection);

    switch (TestCase)
    {
    case 1:
    case 3: // this case works -- orderly shutdown
        // demo 1; this should only ever print 1, but also often prints 2
        printf("%4ld: %ld\n", GetCurrentThreadId(), ++x);
        --x;
        break;
    case 2:
    case 4: // this case works -- orderly shutdown
        // demo 2; this should only print increasing numbers, but sometimes
        // prints the same number twice or skips a number
        printf("%4ld: %ld\n", GetCurrentThreadId(), ++x);
        break;
    }
    LeaveCriticalSection(&CriticalSection);
}
    
DWORD
WINAPI
ThreadMain(
    PVOID lpThreadParameter
    )
{
    while (!Shutdown)
    {
        ThreadMainOnce();
    }
    return 0;
}

BOOL
WINAPI
DllMain(
    HINSTANCE DllHandle,
    DWORD Reason,
    size_t IsExiting
    )
{
    switch (Reason)
    {
    case DLL_PROCESS_ATTACH:
        printf("%4ld: process attach\n", GetCurrentThreadId());
        InitializeCriticalSection(&CriticalSection);
        DisableThreadLibraryCalls(DllHandle);
        break;
    case DLL_PROCESS_DETACH:
        printf("%4ld: process detach\n", GetCurrentThreadId());
        ThreadMainOnce();
        DeleteCriticalSection(&CriticalSection);
        break;
    }
    return TRUE;
}
