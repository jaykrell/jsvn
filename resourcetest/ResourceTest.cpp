#include <windows.h>
#include <stdio.h>

void
CombineDriverWithLoader(
    PCWSTR DriverLoaderPath,
    PCWSTR DriverPath
    )
{
    HANDLE File = { 0 };
    void* MappedFile = { 0 };
    HANDLE FileMapping = { 0 };
    HANDLE UpdateRes = { 0 };
    BOOL Success = { 0 };
    ULARGE_INTEGER FileSize = { 0 };
    DWORD Error = { 0 };

    File = CreateFileW(DriverPath, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
    if (INVALID_HANDLE_VALUE == File)
    {
        Error = GetLastError();
        wprintf(L"CreateFile fails with error: %x", Error);
        goto Exit;
    }

    FileSize.LowPart = GetFileSize(File, &FileSize.HighPart);
    if ((FileSize.LowPart == -1) && ((Error = GetLastError()) != 0))
    {
        wprintf(L"GetFileSize failed with error %x\n", Error);
        goto Exit;
    }
    if (FileSize.HighPart != 0)
    {
        wprintf(L"file too large\n");
        goto Exit;
    }
    
    FileMapping = CreateFileMappingW(File, NULL, PAGE_READONLY, 0, 0, NULL);
    if (FileMapping == NULL)
    {
        Error = GetLastError();
        wprintf(L"CreateFileMapping fails with error: %x", Error);
        goto Exit;
    }

    MappedFile = MapViewOfFile(FileMapping, FILE_MAP_READ, 0, 0, 0);
    if (MappedFile == NULL)
        goto Exit;
 
    UpdateRes = BeginUpdateResourceW(DriverLoaderPath, FALSE); 
    if (UpdateRes == NULL) 
    { 
        Error = GetLastError();
        wprintf(L"BeginUpdateResource fails with error: %x", Error);
        goto Exit;
    }
#if 1
    Success = UpdateResourceW(UpdateRes, L"DebugDriver", L"BINARY", 1033, MappedFile, FileSize.LowPart);
    if (!Success) 
    { 
        Error = GetLastError();
        wprintf(L"UpdateResource fails with error: %x", Error);
        goto Exit;
    } 
#endif
#if 0
    Success = UpdateResourceW(UpdateRes, L"DebugDriver", (PCWSTR) (size_t) 1, 1033, MappedFile, FileSize.LowPart);
    if (!Success) 
    { 
        Error = GetLastError();
        wprintf(L"UpdateResource fails with error: %x", Error);
        goto Exit;
    } 
#endif
    Success = EndUpdateResourceW(UpdateRes, FALSE);
    if (!Success)
    { 
        Error = GetLastError();
        wprintf(L"EndUpdateResource fails with error: %x", Error);
        goto Exit;
    }  

Exit:
    if (MappedFile != NULL)
        UnmapViewOfFile(MappedFile);

    if (FileMapping != NULL)
        CloseHandle(FileMapping);

    if ((File != NULL) && (File != INVALID_HANDLE_VALUE))
        CloseHandle(File);
}

int
__cdecl
wmain(
    )
{
    CombineDriverWithLoader(L".\\notepad.exe", L"ReadMe.txt");

    return 0;
}
