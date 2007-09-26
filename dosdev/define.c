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

    if (argc == 3)
    {
        Success = DefineDosDeviceW(DDD_RAW_TARGET_PATH, argv[1], argv[2]);
        wprintf(L"success:%d error:%lu\n", Success, GetLastError());
    }
    return 0;
}
