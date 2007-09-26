#include "precompiled_header.h"
#include "nt.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4127) /* conditional expression is constant */

void
OutOfMemory(
    void
    )
{
    printf("out of memory\n");
    exit(1);
}

int
__cdecl
wmain()
{
    DWORD Size1 = { 0 };
    DWORD Size2 = { 0 };
    PWSTR Buffer1 = { 0 };
    PWSTR Buffer2 = { 0 };
    PWSTR p;
    PWSTR q;

    Size2 = 32;

    while (TRUE)
    {
        free(Buffer1);
        Buffer1 = NULL;
        Buffer1 = (PWSTR) calloc(Size2, sizeof(WCHAR));
        if (Buffer1 == NULL)
            OutOfMemory();

        Size1 = QueryDosDeviceW(NULL, Buffer1, Size2);
        if (Size1 >= Size2)
        {
            Size2 = (Size1 + 1);
        }
        else if (Size1 == 0 && GetLastError() == ERROR_INSUFFICIENT_BUFFER)
        {
            Size2 = ((Size2 * 2) + 1);
        }
        else
        {
            break;
        }
    }
    for (p = Buffer1; *p ; (p += wcslen(p) + 1))
    {
        Size2 = 32;
        while (TRUE)
        {
            free(Buffer2);
            Buffer2 = NULL;
            Buffer2 = (PWSTR) calloc(Size2, sizeof(WCHAR));
            if (Buffer2 == NULL)
                OutOfMemory();
            Size1 = QueryDosDeviceW(p, Buffer2, Size2);
            if (Size1 >= Size2)
            {
                Size2 = (Size1 + 1);
            }
            else if (Size1 == 0 && GetLastError() == ERROR_INSUFFICIENT_BUFFER)
            {
                Size2 = ((Size2 * 2) + 1);
            }
            else
            {
                break;
            }
        }
        for (q = Buffer2; *q ; (q += wcslen(q) + 1))
        {
            wprintf(L"%ls => %ls\n", p, q);
        }
    }
    free(Buffer1);
    free(Buffer2);
    return 0;
}
