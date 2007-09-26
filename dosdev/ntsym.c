#include "precompiled_header.h"
#include "nt.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF(x) (sizeof(x) / sizeof((x)[0]))

#define MAXUSHORT 0xffff

void
InitializeString(
    PUNICODE_STRING a,
    PWSTR b
    )
{
    size_t Length = wcslen(b);
    if (Length > (MAXUSHORT / sizeof(WCHAR)))
    {
        printf("string too long\n");
        exit(1);
    }
    Length *= sizeof(WCHAR);
    a->Length = (USHORT) Length;
    a->MaximumLength = (USHORT) Length;
    a->Buffer = b;
}

int
__cdecl
wmain(
    int argc,
    wchar_t** argv
    )
{
    NTSTATUS Status = { 0 };

    if (argc == 3)
    {
        UNICODE_STRING From = { 0 };
        OBJECT_ATTRIBUTES FromObj = { sizeof(FromObj) };
        UNICODE_STRING To = { 0 };
        HANDLE Handle = { 0 };
        HANDLE ProcessToken = { 0 };
        const static PCWSTR PrivilegeNames[] = {
            SE_CREATE_TOKEN_NAME, SE_ASSIGNPRIMARYTOKEN_NAME, SE_LOCK_MEMORY_NAME, SE_INCREASE_QUOTA_NAME,
            /*SE_UNSOLICITED_INPUT_NAME,*/
            SE_MACHINE_ACCOUNT_NAME, SE_TCB_NAME, SE_SECURITY_NAME, SE_TAKE_OWNERSHIP_NAME,
            SE_LOAD_DRIVER_NAME, SE_SYSTEM_PROFILE_NAME, SE_SYSTEMTIME_NAME, SE_PROF_SINGLE_PROCESS_NAME,
            SE_INC_BASE_PRIORITY_NAME, SE_CREATE_PAGEFILE_NAME, SE_CREATE_PERMANENT_NAME, SE_BACKUP_NAME,
            SE_RESTORE_NAME, SE_SHUTDOWN_NAME, SE_DEBUG_NAME, SE_AUDIT_NAME,
            SE_SYSTEM_ENVIRONMENT_NAME, SE_CHANGE_NOTIFY_NAME, SE_REMOTE_SHUTDOWN_NAME
        };
        struct
        {
            TOKEN_PRIVILEGES Header;
            LUID_AND_ATTRIBUTES RoomForElements[NUMBER_OF(PrivilegeNames)];
        } Privileges = { 0 };
        struct
        {
            TOKEN_PRIVILEGES Header;
            LUID_AND_ATTRIBUTES RoomForElements[NUMBER_OF(PrivilegeNames)];
        } OldPrivileges = { 0 };
        size_t i = 0;
        DWORD ReturnedSize = { 0 };
#if 0
        size_t j = 0;
        for (i = 0 ; i != NUMBER_OF(PrivilegeNames) ; ++i)
        {
            Privileges.Header.Privileges[i].Attributes = SE_PRIVILEGE_ENABLED;
            if (!LookupPrivilegeValueW(NULL, PrivilegeNames[i], &Privileges.Header.Privileges[j].Luid))
            {
                wprintf(L"LookupPrivilegeValue(%ls) failed with %lx\n", PrivilegeNames[i], GetLastError());
            }
            else
            {
                j += 1;
            }
        }
        Privileges.Header.PrivilegeCount = j;
#endif
        if (!OpenProcessToken(GetCurrentProcess(), GENERIC_ALL, &ProcessToken))
        {
            wprintf(L"OpenProcessToken failed with %lx\n", GetLastError());
        }

        if (!AdjustTokenPrivileges(ProcessToken, FALSE, &Privileges.Header, sizeof(OldPrivileges), &OldPrivileges.Header, &ReturnedSize))
        {
            wprintf(L"AdjustTokenPrivileges failed with %lx\n", GetLastError());
        }

        Privileges.Header.PrivilegeCount = 1;
        Privileges.Header.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
        for (i = 0 ; i != NUMBER_OF(PrivilegeNames) ; ++i)
        {
            if (!LookupPrivilegeValueW(NULL, PrivilegeNames[i], &Privileges.Header.Privileges[0].Luid))
            {
                wprintf(L"LookupPrivilegeValue(%ls) failed with %lx\n", PrivilegeNames[i], GetLastError());
            }
            else
            {
                if (!AdjustTokenPrivileges(ProcessToken, FALSE, &Privileges.Header, sizeof(OldPrivileges), &OldPrivileges.Header, &ReturnedSize))
                {
                    wprintf(L"AdjustTokenPrivileges failed with %lx\n", GetLastError());
                }
            }
        }

        InitializeString(&From, argv[1]);
        InitializeString(&To, argv[2]);
        InitializeObjectAttributes(&FromObj, &From, (OBJ_CASE_INSENSITIVE | OBJ_PERMANENT), NULL, NULL);

        Status = NtCreateSymbolicLinkObject(&Handle, GENERIC_ALL, &FromObj, &To);
        if (Status == 0)
        {
            wprintf(L"success");
        }
        else if (Status == 0xc0000061)
        {
            wprintf(L"trying not permanent\n");
            FromObj.Attributes &= ~OBJ_PERMANENT;
            Status = NtCreateSymbolicLinkObject(&Handle, GENERIC_ALL, &FromObj, &To);
            if (Status == 0)
            {
                wprintf(L"success, control-c to delete");
                Sleep(INFINITE);
            }
        }
        if (Handle != NULL)
            NtClose(Handle);
    }
    wprintf(L"exiting with %lx\n", Status);
    return (int) Status;
}
