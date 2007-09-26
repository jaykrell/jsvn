#include "precompiled_header.h"
#include "nt.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int
__cdecl
wmain(
    int argc,
    wchar_t** argv
    )
{
    BOOL Success;

    if (argc == 2)
    {
        Success = DefineDosDeviceW(DDD_REMOVE_DEFINITION, argv[1], NULL);
        wprintf(L"success:%d error:%lu\n", Success, GetLastError());
    }
    return 0;
}
