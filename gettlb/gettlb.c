//
// Extract a resource of type "TYPELIB" from the specified file outputing to the specified file.
// cl  /Wp64 /MD /Zi /W4 /WX gettlb.c
//
// ? Enumerate to determine the language?
// ? Enumerate of id is 0 or unspecified, take the first, error if more than one?
//

#include <windows.h>
#include <stdio.h>

DWORD
GetLastWin32Error(
    void
    )
{
    DWORD e = GetLastError();
    if (e == NO_ERROR)
        e = ERROR_INTERNAL_ERROR;
    return e;
}

PWSTR
GetErrorMessage(
    DWORD Win32Error
    )
{
    PWSTR Buffer = { 0 };

    FormatMessageW(
        (FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS),
        NULL,
        Win32Error,
        0,
        (PWSTR) &Buffer,
        0,
        NULL
        );

    if ((Buffer != NULL) && (*Buffer != L'\0'))
    {
        //
        // Errors often have annoying trailing whitespace -- remove.
        //
        WCHAR ch;
        PWSTR p = (Buffer + wcslen(Buffer));
        while ((p != Buffer) && (((ch = p[-1]) == ' ') || (ch == L'\t') || (ch == L'\r') || (ch == L'\n')))
        {
            p -= 1;
        }
        p[0] = L'\0';
    }

    return Buffer;
}

int
wmain(
    int argc,
    wchar_t** argv
    )
{
    int ExitCode  = { 0 };
    HMODULE DllHandle = { 0 };
    HANDLE OutputFileHandle = INVALID_HANDLE_VALUE;
    HRSRC ResourceHandle = { 0 }; // legacy api design
    HGLOBAL ResourceGlobal = { 0 }; // legacy api design
    PVOID ResourcePointer = { 0 };
    ULONG FullPathLength1 = { 0 };
    ULONG FullPathLength2 = { 0 };
    PWSTR FullPathInput = { 0 };
    PCWSTR PathInput = { 0 };
    PCWSTR PathOutput = { 0 };
    PWSTR Id = { 0 };
    ULONG CurrentDirectoryLength = { 0 };
    PWSTR CurrentDirectory = { 0 };
    BOOL Usage = { 0 };
    ULONG ResourceSize = { 0 };
    ULONG BytesWritten = { 0 };
    BOOL Success = { 0 };

    //
    // This is for error reporting, but get it up front to avoid errors in error reporting.
    //
    CurrentDirectoryLength = GetCurrentDirectoryW(0, NULL);
    CurrentDirectory = (PWSTR) calloc(CurrentDirectoryLength, sizeof(WCHAR));
    GetCurrentDirectoryW(CurrentDirectoryLength, CurrentDirectory);

    //
    // usage: gettlb input id output
    // id is usually 1 -- or rather, #1
    //
    if (argc != 4)
    {
        wprintf(L"usage: gettlb input-file resource-id output-file\n");
        wprintf(L"  resource-id is typically #1\n");
        ExitCode = ERROR_INVALID_PARAMETER;
        Usage = TRUE;
        goto Exit;
    }

    PathInput = argv[1];
    Id = argv[2];
    PathOutput = argv[3];

    //
    // LoadLibrary has incorrect search semantics.
    // Establish the desired search path -- that of CreateFile, et. al.
    //
    FullPathLength1 = GetFullPathNameW(PathInput, 0, NULL, NULL);
    if (FullPathLength1 == 0)
    {
        ExitCode = (int) GetLastWin32Error();
        wprintf(L"ERROR: error %x for GetFullPathName(%ls)\n", ExitCode, PathInput);
        goto Exit;
    }

    FullPathInput = (PWSTR) calloc(FullPathLength1, sizeof(WCHAR));
    if (FullPathInput == NULL)
    {
        wprintf(L"ERROR: out of memory\n");
        ExitCode = ERROR_NOT_ENOUGH_MEMORY;
        goto Exit;
    }
    FullPathLength2 = GetFullPathNameW(PathInput, FullPathLength1, FullPathInput, NULL);
    if (FullPathLength2 != (FullPathLength1 - 1))
    {
        ExitCode = ERROR_INTERNAL_ERROR;
        wprintf(L"ERROR: internal error for GetFullPathName(%ls)\n", PathInput);
        goto Exit;
    }

    DllHandle = LoadLibraryExW(FullPathInput, NULL, LOAD_LIBRARY_AS_DATAFILE);
    if (DllHandle == NULL)
    {
        ExitCode = (int) GetLastWin32Error();
        wprintf(L"ERROR: error %x for input LoadLibraryExW(%ls)\n", ExitCode, FullPathInput);
        goto Exit;
    }

    ResourceHandle = FindResourceW(DllHandle, Id, L"TYPELIB");
    if (ResourceHandle == NULL)
    {
        ExitCode = (int) GetLastWin32Error();
        wprintf(L"ERROR: error %x for FindResourceW(%ls, TYPELIB, %ls)\n", ExitCode, FullPathInput, Id);
        goto Exit;
    }

    ResourceGlobal = LoadResource(DllHandle, ResourceHandle);
    if (ResourceGlobal == NULL)
    {
        ExitCode = (int) GetLastWin32Error();
        wprintf(L"ERROR: error %x for LoadResource(%ls, TYPELIB, %ls)\n", ExitCode, FullPathInput, Id);
        goto Exit;
    }

    ResourcePointer = LockResource(ResourceGlobal);
    if (ResourcePointer == NULL)
    {
        ExitCode = (int) GetLastWin32Error();
        wprintf(L"ERROR: error %x for LockResource(%ls, TYPELIB, %ls)\n", ExitCode, FullPathInput, Id);
        goto Exit;
    }

    ResourceSize = SizeofResource(DllHandle, ResourceHandle);
    if (ResourceSize == 0)
    {
        ExitCode = ERROR_INVALID_PARAMETER;
        wprintf(L"ERROR: zero sized resource? SizeofResource(%ls, TYPELIB, %ls)\n", FullPathInput, Id);
        goto Exit;
    }

    SetFileAttributesW(PathOutput, 0);
    DeleteFileW(PathOutput);
    OutputFileHandle = CreateFileW(PathOutput, GENERIC_ALL, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
    if (OutputFileHandle == INVALID_HANDLE_VALUE)
    {
        ExitCode = (int) GetLastWin32Error();
        wprintf(L"ERROR: error %x for output CreateFileW(%ls)\n", ExitCode, PathOutput);
        goto Exit;
    }

    Success = WriteFile(OutputFileHandle, ResourcePointer, ResourceSize, &BytesWritten, NULL);
    if (!Success)
    {
        ExitCode = (int) GetLastWin32Error();
        wprintf(L"ERROR: error %x for output WriteFile(%ls)\n", ExitCode, PathOutput);
        goto Exit;
    }
    if (ResourceSize != BytesWritten)
    {
        ExitCode = (int) GetLastWin32Error();
        wprintf(L"ERROR: not all bytes written (desired %lx, got %lx) error %x for output WriteFile(%ls)\n", ResourceSize, BytesWritten, ExitCode, PathOutput);
        goto Exit;
    }

    wprintf(L"%ls successfully wrote %lx bytes to %ls\n", argv[0], BytesWritten, PathOutput);

Exit:
    free(FullPathInput);

    if (DllHandle != NULL)
        FreeLibrary(DllHandle);

    if (OutputFileHandle != INVALID_HANDLE_VALUE)
    {
        CloseHandle(OutputFileHandle);
        //
        // If we failed, but got as far as creating output, delete the output.
        //
        if (ExitCode != 0)
        {
            if (PathOutput != NULL)
            {
                SetFileAttributesW(PathOutput, 0);
                DeleteFileW(PathOutput);
            }
        }
    }
    if ((ExitCode != 0) && !Usage)
    {
        PWSTR ErrorMessage = GetErrorMessage(ExitCode);
        wprintf(L"ERROR: error %x (%ls) running %ls in directory %ls\n", ExitCode, ErrorMessage, GetCommandLineW(), CurrentDirectory);
        LocalFree(ErrorMessage);
    }
    free(CurrentDirectory);
    return ExitCode;
}
