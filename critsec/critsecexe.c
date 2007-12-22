#include <stdio.h>
#include <windows.h>
#include "critsec.h"

int
__cdecl
wmain(
    int argc,
    wchar_t** argv
    )
{
    DWORD ThreadId;
    int TestCase;
    HANDLE Threads[2];

    if (argv[1] != NULL)
    {
        TestCase = _wtoi(argv[1]);
        SetTestCase(TestCase);
    }
    else
    {
        printf("please specify a test case -- 1, 2, 3, or 4\n");
        printf("1 and 2 \"don't work\", 3 and 4 do\n");
        return 1;
    }

    Threads[0] = CreateThread(NULL, 0, &ThreadMain, NULL, 0, &ThreadId);
    Threads[1] = CreateThread(NULL, 0, &ThreadMain, NULL, 0, &ThreadId);
    while (GetCount() < 10)
    {
        Sleep(0);
    }
    if (TestCase > 2)
    {
        RequestOrderlyShutdown();
        WaitForMultipleObjects(2, Threads, TRUE, INFINITE);
    }
    return 0;
}
