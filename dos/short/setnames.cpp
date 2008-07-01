/*
Jay Krell
jay.krell@cornell.edu.
jayk123@hotmail.com
BSD licensed.

This program sets short names of files as if they were
created while "no numeric tail" was in effect.
This should help with using DJGPP, and this
behavior should perhaps, if possible, be extended to the DJGPP runtime,
so that creating config.status for example, gets a short name of config.sta.
"no numeric tail" doesn't seem to work for me. Maybe it is only for Win9x?
Unfortunately this is documented as being for NTFS only.
We would actually like these files to be on FAT.
However this might be useful for some DOS emulation environments.

NOTE:
    Only 7 bit clean names with zero or no dots are changed.
    Files with "extended" characters are not.
    More specifically, if a filename contains any characters not valid in a short name,
        it is left alone. The set of characters valid in short names is fairly small,
        a-z, 0-9, and a few more.
*/
#define _CRT_SECURE_NO_DEPRECATE
#define UNICODE
#define _UNICODE
#include <string>
#include <string.h>
#include <windows.h>
#include <stdio.h>
using namespace std;

bool Verbose = false;
bool DeleteUponClash = false;

//
// This is the experimentally derived set of characters valid in short names, on NTFS.
// Note that everything >= 0x80 is invalid.
// Note that everything <= ' ' is invalid.
// Note that most of the characters on a USA keyboard are valid, except:
//  []=+^;, and the invalid characters "*:<>?|/\
//
// See also:
//   http://support.microsoft.com/kb/120138
// which agrees, but we add dot here.
//
const char ValidShortFileNameCharacters[] = ".!#$%&'()-0123456789@ABCDEFGHIJKLMNOPQRSTUVWXYZ^_`abcdefghijklmnopqrstuvwxyz{}~";

//
// This is the set of experimentally derived set of invalid characters in long names, plus zero through 0x1F inclusive, on NTFS.
// Note that everything >= 0x80 is valid.
// Note that everything < ' ' (0x20) is invalid.
//
// See http://www.microsoft.com/technet/archive/winntas/proddocs/network/xnsapxe.mspx
//
//const char InvalidFileNameCharacters[] = "\"*:<>?|/\\";

#if 0

#include <vector>

void ConvertPathToLongPath(wstring& w)
//
// This lets us deal with the file name that is, for example, just a space.
//
{
    UINT32 Length = w.length();
    if (Length == 0)
    {
        return;
    }
    if (Length >= 3)
    {
        if ((w[0] == L'\\') && (w[1] == L'\\') && (w[2] == L'?'))
        {
            //
            // already in the form we want
            //
            return;
        }
    }

    vector<WCHAR> Buffer;
    Buffer.resize(0x10000);
    Length = GetFullPathNameW(w.c_str(), 0x10000, &Buffer[0], NULL);
    if (Length >= 2)
    {
        if ((Buffer[0] == L'\\') && (Buffer[1] == L'\\'))
        {
            if (Length >= 3)
            {
                if (Buffer[2] == L'?')
                {
                    //
                    // in the form we want
                    //
                    w = &Buffer[0];
                    return;
                }
            }
            w = (wstring(L"\\\\?\\UNC\\") + &Buffer[2]);
            return;
        }
    }
    w = (wstring(L"\\\\?\\") + &Buffer[0]);
}

UINT8 ValidShortNameCharacters[0x10000];

void DetermineValidShortNameCharacters(void)
/* not thread safe */
{
    WCHAR GuidString[33] = { 0 };
    union
    {
        UINT32 i[4];
        GUID g;
    } uGuid = { GetTickCount() };
    WIN32_FIND_DATAW FindData = { 0 };

    uGuid.i[1] = 1 + uGuid.i[0];
    uGuid.i[2] = 2 + uGuid.i[0];
    uGuid.i[3] = 3 + uGuid.i[0];
    UuidCreate(&uGuid.g);
    swprintf(GuidString, 33, L"%08lx%08lx%08lx%08lx", uGuid.i[0], uGuid.i[1], uGuid.i[1], uGuid.i[3]);

    wstring TempDir = _wgetenv(L"TEMP");
    ConvertPathToLongPath(TempDir);
    CreateDirectoryW(TempDir.c_str(), NULL);
    const wstring MyTempDir = (TempDir + L'\\' + GuidString);
    CreateDirectoryW(MyTempDir.c_str(), NULL);
    const wstring MyTempDirSlash = (MyTempDir + L'\\');

    for (UINT32 ch = 0 ; ch != 0x10000 ; ++ch)
    {
        if ((ch < 0x20) || (ch == L'"') || (ch == L'*') || (ch == L'.') || (ch == L':') || (ch == L'<') || (ch == L'>')
             || (ch == L'?') || (ch == L'|') || (ch == L'/') || (ch == L'\\'))
            continue;
        const wstring FileName = (MyTempDirSlash + (WCHAR) ch);
        const HANDLE FileHandle = CreateFileW(FileName.c_str(), GENERIC_ALL, (FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE),
            NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
        if (FileHandle != INVALID_HANDLE_VALUE)
        {
            CloseHandle(FileHandle);
            const HANDLE FindHandle = FindFirstFileW(FileName.c_str(), &FindData);
            if (FindHandle != INVALID_HANDLE_VALUE)
            {
                FindClose(FindHandle);
                if (_wcsicmp(FindData.cAlternateFileName, FindData.cFileName) == 0)
                {
                    ValidShortNameCharacters[ch] = TRUE;
                }
                if (FindData.cAlternateFileName[0] == 0)
                {
                    ValidShortNameCharacters[ch] = TRUE;
                }
            }
            else
            {
                const UINT32 Error = GetLastError();
                fwprintf(stderr, L"error 0x%x at line %u for character 0x%x %lc\n", Error, __LINE__, ch, ch);
            }
            DeleteFileW(FileName.c_str());
        }
        else
        {
            const UINT32 Error = GetLastError();
            //if ((Error != ERROR_INVALID_NAME) && (Error != ERROR_ACCESS_DENIED))
            {
                if (ch != 7)
                {
                    fwprintf(stderr, L"error 0x%x at line %u for character 0x%x %lc\n", Error, __LINE__, ch, ch);
                }
                else
                {
                    fwprintf(stderr, L"error 0x%x at line %u for character 0x%x\n", Error, __LINE__, ch);
                }
            }
        }
    }
    RemoveDirectoryW(MyTempDir.c_str());
}

bool IsCharacterValidForShortName(WCHAR ch)
/* not thread safe */
{
    if (!ValidShortNameCharacters[L'A'])
        DetermineValidShortNameCharacters();
    return !! ValidShortNameCharacters[ch];
}

#endif

bool IsCharacterValidForShortName(WCHAR ch)
{
    if (ch <= 0x20)
        return false;
    if (ch >= 0x80)
        return false;
    return !! strchr(ValidShortFileNameCharacters, (char) (ch & 0x7F));
}

bool GenerateShortName(PCWSTR s, wstring& t)
//
// Base truncated at 8 characters.
// Extension at 3 characters or dot, whichever is first.
// The last extension is used.
// Dot inserted before extension, if it exists.
// If extension is empty but name ends in dot, remove dot.
// If there are any characters in s that aren't valid for a short name, fail.
// We may need to relax this -- such as if they are truncated anyway.
//
// foo.c => foo.c
// foo.cabinet => foo.cab
// foo.c.d => foo.d
// foodbarf123 => foodbarf
// foodbarf123.c => foodbarf.c
// foodbarf123.cabinet => foodbarf.cab
// foodbar.c.d => foodbar.d
// food.       => food
//
{
    size_t i = { 0 };
    size_t iBase = { 0 };
    size_t iExtension = { 0 };
    WCHAR Base[9] = { 0 };
    WCHAR Extension[4] = { 0 };
    size_t Length = wcslen(s);
    bool InExtension = false;
    WCHAR ch = { 0 };
    t = L"";

    //
    // dot is not valid as the first character (.gdbinit cannot be renamed .gdb)
    //
    if (Length != 0)
    {
        if (s[0] == L'.')
            return false;
    }
    for (i = 0 ; i != Length ; ++i)
    {
        ch = s[i];
        if (!IsCharacterValidForShortName(ch))
            return false;
        if (ch == L'.')
        {
            InExtension = true;
            Extension[0] = L'\0';
            Extension[1] = L'\0';
            Extension[2] = L'\0';
            Extension[3] = L'\0';
            iExtension = 0;
            continue;
        }
        if (InExtension)
        {
            if (iExtension < 3)
            {
                Extension[iExtension++] = ch;
            }
            else
            {
                // truncating
            }
        }
        else
        {
            if (iBase < 8)
            {
                Base[iBase++] = ch;
            }
            else
            {
                // truncating
            }
        }
    }
    if (iExtension != 0)
    {
        t = (wstring(Base) + L'.' + Extension);
    }
    else
    {
        t = wstring(Base);
    }
    return true;
}

void GetPrivilege(void)
//
// http://msdn.microsoft.com/en-us/library/aa446619(VS.85).aspx
//
{
    static bool GotPrivilege;
    if (GotPrivilege)
        return;
    GotPrivilege = true;

    TOKEN_PRIVILEGES tp = { 0 };
    UINT32 Error = { 0 };

    if (!LookupPrivilegeValueW(NULL, SE_RESTORE_NAME, &tp.Privileges[0].Luid))
    {
        Error = GetLastError();
        fwprintf(stderr, L"LookupPrivilegeValue error: 0x%x\n", Error);
        //exit(Error);;
        return;
    }

    HANDLE Token = { 0 };
    if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &Token))
    {
        Error = GetLastError();
        fwprintf(stderr, L"OpenProcessToken error: 0x%x\n", Error);
        //exit(Error);;
        return;
    }

    tp.PrivilegeCount = 1;
    tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

    if (!AdjustTokenPrivileges(Token, FALSE, &tp, sizeof(TOKEN_PRIVILEGES), NULL, NULL))
    {
        Error = GetLastError();
        fwprintf(stderr, L"AdjustTokenPrivileges error: 0x%x\n", Error);
        //exit(Error);;
        return;
    }

    Error = GetLastError();
    CloseHandle(Token);
    if (Error == ERROR_NOT_ALL_ASSIGNED)
    {
        fwprintf(stderr, L"The token does not have the specified privilege.\n");
        //exit(1);
        return;
    }
}

void F(wstring Dir,
       wstring& ShortName,
       WIN32_FIND_DATAW& FindData)
{
    UINT32 Error = { 0 };

    Dir += L'\\';
    size_t const DirLength = Dir.length();
    HANDLE const FindHandle = FindFirstFileW((Dir + L"*").c_str(), &FindData);
    if (FindHandle == INVALID_HANDLE_VALUE)
        return;

    PCWSTR const FileName = FindData.cFileName;
    PCWSTR const AlternateFileName = FindData.cAlternateFileName;
    do
    {
        size_t FileNameLength = wcslen(FileName);
        if (FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            if ((FileNameLength == 1) && (wcscmp(FileName, L".") == 0))
                continue;
            if ((FileNameLength == 2) && (wcscmp(FileName, L"..") == 0))
                continue;
        }
        if (AlternateFileName[0] != 0)
        {
            size_t AlternateFileNameLength = wcslen(AlternateFileName);
            if (GenerateShortName(FileName, ShortName))
            {
                if (_wcsicmp(ShortName.c_str(), AlternateFileName) != 0)
                {
                    GetPrivilege();
                    const wstring FilePath = (Dir + FileName);
                    HANDLE FileHandle = CreateFileW(FilePath.c_str(), (GENERIC_WRITE | DELETE), (FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE),
                        NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
                    if (FileHandle == INVALID_HANDLE_VALUE)
                    {
                        Error = GetLastError();
                        fwprintf(stderr, L"CreateFileW(%ls) error: 0x%x\n", FilePath.c_str(), Error);
                    }
                    else
                    {
                        fwprintf(stdout, L"%ls => %ls instead of %ls\n", FilePath.c_str(), ShortName.c_str(), AlternateFileName);
                        BOOL Success = SetFileShortName(FileHandle, ShortName.c_str());
                        Error = GetLastError();
                        CloseHandle(FileHandle);
                        if (!Success)
                        {
                            fwprintf(stderr, L"SetFileShortName(%ls, %ls) error: 0x%x\n", FilePath.c_str(), ShortName.c_str(), Error);
                            if (Error == ERROR_ALREADY_EXISTS)
                            {
                                if (DeleteUponClash)
                                {
                                    fwprintf(stdout, L"del %ls\n", FilePath.c_str());
                                    DeleteFileW(FilePath.c_str());
                                }
                            }
                        }
                    }
                }
                else
                {
                    if (Verbose)
                    {
                        fwprintf(stdout, L"%ls%ls => %ls same as %ls\n", Dir.c_str(), FileName, ShortName.c_str(), AlternateFileName);
                    }
                }
            }
            else
            {
                fwprintf(stdout, L"failed to generate shortname for %ls%ls\n", Dir.c_str(), FileName);
            }
        }
        if (FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            F(Dir + FileName, ShortName, FindData);
        }
    } while (FindNextFileW(FindHandle, &FindData));
    FindClose(FindHandle);
}

int __cdecl wmain(void)
{
#if 0 // test code
    wstring a;

    a = L"";
    ConvertPathToLongPath(a);
    fwprintf(stderr, L"'%ls'\n", a.c_str());

    a = L".";
    ConvertPathToLongPath(a);
    fwprintf(stderr, L"'%ls'\n", a.c_str());

    a = L"\\\\localhost\\c$";
    ConvertPathToLongPath(a);
    fwprintf(stderr, L"'%ls'\n", a.c_str());

    a = L"\\\\?\\UNC\\localhost\\c$";
    ConvertPathToLongPath(a);
    fwprintf(stderr, L"'%ls'\n", a.c_str());

    DetermineValidShortNameCharacters();
    for (UINT32 ch = 0 ; ch != 0x10000 ; ++ch)
    {
        if (ValidShortNameCharacters[ch])
        {
            fwprintf(stderr, L"%c", ch);
        }
    }

    exit(1);
#endif

#if 0 // test code
    wstring a;

    GenerateShortName(L"a", a);
    fwprintf(stderr, L"'%ls'\n", a.c_str());

    GenerateShortName(L"foo.c", a);
    fwprintf(stderr, L"'%ls'\n", a.c_str());

    GenerateShortName(L"foo.c.d", a);
    fwprintf(stderr, L"'%ls'\n", a.c_str());

    GenerateShortName(L"foodbarf", a);
    fwprintf(stderr, L"'%ls'\n", a.c_str());

    GenerateShortName(L"foodbarf.", a);
    fwprintf(stderr, L"'%ls'\n", a.c_str());

    GenerateShortName(L"foodbarf.c.d", a);
    fwprintf(stderr, L"'%ls'\n", a.c_str());

    GenerateShortName(L"foodbarf.c.", a);
    fwprintf(stderr, L"'%ls'\n", a.c_str());

    GenerateShortName(L"foodbarf.cabinet", a);
    fwprintf(stderr, L"'%ls'\n", a.c_str());

    GenerateShortName(L"foodbarf123.cabinet", a);
    fwprintf(stderr, L"'%ls'\n", a.c_str());

    GenerateShortName(L"foodbarf123[].cabinet", a);
    fwprintf(stderr, L"'%ls'\n", a.c_str());

    exit(1);
#endif

    wstring ShortName;
    WIN32_FIND_DATAW FindData;
    F(L".", ShortName, FindData);
}
