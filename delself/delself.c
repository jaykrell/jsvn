#pragma warning(disable:4127) /* expression is constant */
#include <stdio.h>
#include <windows.h>
#define NUMBER_OF(a) (sizeof(a)/sizeof((a)[0]))
#include <rpc.h>
#include <string.h>

void ToHex(
    WCHAR* Buffer,
    BYTE* Bytes,
    ULONG NumberOfBytes
    )
{
    while (NumberOfBytes-- != 0)
    {
        BYTE b = *Bytes++;
        const static char Hex[] = "0123456789ABCDEF";
        *Buffer++ = Hex[b >> 4];
        *Buffer++ = Hex[b & 0xF];
    }
}

WCHAR*
MyGetModuleFileName(
    HMODULE ModuleHandle
    )
{
    ULONG Size = 4;
    WCHAR* Buffer = { 0 };
    BOOL Success = { 0 };

    while (1)
    {
        Size *= 2;
        Buffer = (WCHAR*) calloc(sizeof(WCHAR), Size);
        if (Buffer == NULL)
            goto Exit;
        Success = GetModuleFileNameW(ModuleHandle, Buffer, (Size - 1));
        if (!Success)
            goto Exit;
        if (Buffer[Size - 2] == 0)
            break;
        free(Buffer);
        Buffer = NULL;
    }
Exit:
    if (!Success)
    {
        free(Buffer);
        Buffer = NULL;
    }
    return Buffer;
}

int wmain()
{
    WCHAR* MyPath = { 0 };
    WCHAR* AnotherPath = { 0 };
    BOOL Success = { 0 };
    DWORD Error = { 0 };
    UUID Uuid = { 0 };
    HMODULE MyDllHandle = { 0 };
    ULONG MyPathLength = { 0 };
    HANDLE FileHandle = INVALID_HANDLE_VALUE;
    ULONG AnotherPathLength = { 0 };
    STARTUPINFOW StartupInfo = { sizeof(StartupInfo) };
    PROCESS_INFORMATION ProcessInfo = { 0 };
    WCHAR* Dot = { 0 };

    MyDllHandle = GetModuleHandleW(NULL);
    wprintf(L"MyDllHandle is %x\n", MyDllHandle);

    UnmapViewOfFile(MyDllHandle);

    MyPath = MyGetModuleFileName(MyDllHandle);

    Dot = wcschr(MyPath, L'.');
    if (Dot != NULL)
    {
        if (_wcsicmp(Dot, L".exe") != 0)
        {
            *Dot = 0;
            while (!DeleteFileW(MyPath) && (GetLastError() == ERROR_ACCESS_DENIED))
            {
                Sleep(1);
            }
        }
    }
    else
    {
        MyPathLength = (1 + wcslen(MyPath));

        AnotherPathLength = (MyPathLength + 1 + (sizeof(UUID) * 8 / 4));
        AnotherPath = (WCHAR*) calloc(sizeof(WCHAR), AnotherPathLength);
        UuidCreate(&Uuid);
        CopyMemory(AnotherPath, MyPath, (MyPathLength * sizeof(WCHAR)));
        ToHex((AnotherPath + MyPathLength - 1), ((BYTE*) &Uuid), sizeof(Uuid));

        Success = CopyFileW(MyPath, AnotherPath, FALSE);
        wprintf(L"CopyFileW(%ls,%ls):%x,%x\n", MyPath, AnotherPath, Success, Error);

        FileHandle = CreateFileW(AnotherPath, (DELETE | GENERIC_READ | SYNCHRONIZE),
                (FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE), NULL,
                CREATE_ALWAYS, FILE_FLAG_DELETE_ON_CLOSE, NULL);
        Error = GetLastError();        
        wprintf(L"CreateFile(%ls, delete-on-close):%x,%x\n", AnotherPath, (FileHandle != INVALID_HANDLE_VALUE), Error);

        //Success = MoveFileW(MyPath, AnotherPath);
        //wprintf(L"MoveFile(%ls,%ls):%x,%x\n", MyPath, AnotherPath, Success, Error);

        CreateProcessW(AnotherPath, AnotherPath, NULL, NULL, FALSE, 0, NULL, NULL, &StartupInfo, &ProcessInfo);
    }


    free(MyPath);
    free(AnotherPath);
    if (FileHandle != INVALID_HANDLE_VALUE)
        CloseHandle(FileHandle);
    return 0;
}
