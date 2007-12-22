#pragma warning(disable:4100) /* unreferenced formal parameter -- in our own code */

DWORD
WINAPI
ThreadMain(
    PVOID ThreadParameter
    );

long
GetCount(
    void
    );

void
SetTestCase(
    unsigned i
    );

void
RequestOrderlyShutdown(
    void
    );
