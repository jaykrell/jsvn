void HeapFree(void* Heap, unsigned long Flags, void* p)
{
    free(p);
}

void* HeapAlloc(void* Heap, unsigned long Flags, unsigned long i)
{
    return malloc(i);
}

void* GetProcessHeap()
{
    return 0;
}

unsigned long GetTickCount()
{
    static unsigned long i;
    return ++i;
}

unsigned long GetCurrentProcessId()
{
    return (unsigned long)&GetCurrentProcessId;
}

void EnterCriticalSection(void*)
{
}

void LeaveCriticalSection(void*)
{
}

void* GetCurrentProcess()
{
    return 0;
}

void TerminateProcess(void*, unsigned lont i)
{
    exit((int) i);
}

void ExitProcess(unsigned lont i)
{
    exit((int) i);
}

std::vector<unsigned long> tls_free;
std::vector<void*> tls;

void* TlsGetValue(unsigned long i)
{
    return tls[i];
}

unsigned long TlsAlloc()
{
    unsigned long i;
    if (tls_free.size() != 0)
    {
        i = tls_free.pop_back();
    }
    else
    {
        i = tls.size();
        tls.resize(i + 1);
    }
    tls[i] = 0;
    return i;
}

void TlsSetValue(unsigned long i, void* p)
{
    tls[i] = p;
}

void TlsFree(unsigned long i)
{
    /* undone -- tls_free should be sorted
    and when possible we should shrink tls
    we only do that sometimes
    */
    if (tls.size() == (i + 1))
    {
        tls.resize(i);
    }
    else
    {
        tls_free.push_back(i);
    }
}

int IsDebuggerPresent()
{
    return 0;
}

// ??2@YAPAXI@Z void * __cdecl operator new(unsigned int)
// ??3@YAXPAX@Z void __cdecl operator delete(void *)"

??_7?$basic_ios@DU?$char_traits@D@std@@@std@@6B@
??0ostrstream@std@@QAE@PADHH@Z
??1?$basic_ios@DU?$char_traits@D@std@@@std@@UAE@XZ
??1ios_base@std@@UAE@XZ
??1ostrstream@std@@UAE@XZ
??1type_info@@UAE@XZ
??6?$basic_ostream@DU?$char_traits@D@std@@@std@@QAEAAV01@F@Z
??6?$basic_ostream@DU?$char_traits@D@std@@@std@@QAEAAV01@G@Z
??6?$basic_ostream@DU?$char_traits@D@std@@@std@@QAEAAV01@H@Z
??6?$basic_ostream@DU?$char_traits@D@std@@@std@@QAEAAV01@I@Z
??6?$basic_ostream@DU?$char_traits@D@std@@@std@@QAEAAV01@K@Z
??6std@@YAAAV?$basic_ostream@DU?$char_traits@D@std@@@0@AAV10@D@Z
??6std@@YAAAV?$basic_ostream@DU?$char_traits@D@std@@@0@AAV10@PBD@Z
?ends@std@@YAAAV?$basic_ostream@DU?$char_traits@D@std@@@1@AAV21@@Z
?setw@std@@YA?AU?$_Smanip@H@1@H@Z
__CxxFrameHandler
__dllonexit
__doserrno
__getmainargs
__p___initenv
__p__commode
__p__fmode
__p__pgmptr
__set_app_type
__setusermatherr
__unDName
_access
_adjust_fdiv
_chsize
_close
_controlfp
_dup2
_errno
_except_handler3
_exit
_fcloseall
_filelength
_flushall
_fsopen
_ftime
_fullpath
_getmbcp
_initterm
_iob
_isatty
_ismbblead
_ismbcspace
_itoa
_lseek
_makepath
_mbccpy
_mbclen
_mbctolower
_mbctype
_mbschr
_mbscmp
_mbsdec
_mbsicmp
_mbsinc
_mbslwr
_mbsnbcmp
_mbsnbcpy
_mbsnbicmp
_mbsncmp
_mbspbrk
_mbsrchr
_mbsspn
_mbsstr
_mbstok
_mbsupr
_memicmp
_mktemp
_onexit
_purecall
_putenv
_read
_searchenv
_seh_longjmp_unwind
_setjmp3
_setmbcp
_snprintf
_sopen
_spawnv
_spawnvp
_splitpath
_stat
_strdup
_stricmp
_strnicmp
_strupr
_tell
_tempnam
_tzset
_ultoa
_unlink
_utime
_write
_XcptFilter
atoi
BindImageEx
bsearch
calloc
CheckSumMappedFile
CloseHandle
CopyFileA
CreateFileA
CreateFileMappingA
ctime
DeleteCriticalSection
DeleteFileA
DisableThreadLibraryCalls
exit
ExitProcess
fclose
fflush
fgets
FindClose
FindFirstFileA
FindNextFileA
FlushFileBuffers
fopen
fprintf
fputc
fputs
fread
free
FreeEnvironmentStringsA
FreeEnvironmentStringsW
FreeLibrary
fseek
ftell
fwrite
GetACP
getc
getchar
GetCommandLineA
GetConsoleCP
GetConsoleMode
GetConsoleOutputCP
GetConsoleScreenBufferInfo
GetCPInfo
GetCurrentProcess
GetCurrentThread
GetCurrentThreadId
GetDiskFreeSpaceA
getenv
GetEnvironmentStrings
GetEnvironmentStringsW
GetFileInformationByHandle
GetFileSize
GetFileType
GetLastError
GetLocaleInfoA
GetModuleFileNameA
GetModuleHandleA
GetOEMCP
GetProcAddress
GetStartupInfoA
GetStdHandle
GetStringTypeA
GetStringTypeW
GetSystemInfo
GetSystemTime
GetSystemTimeAsFileTime
GetTempFileNameA
GetTempPathA
GetTickCount
GetVersion
GetVersionExA
GlobalMemoryStatus
HeapAlloc
HeapCreate
HeapDestroy
HeapFree
HeapReAlloc
HeapSize
InitializeCriticalSection
int IsDebuggerPresent()
InterlockedDecrement
InterlockedIncrement
isalnum
isdigit
isprint
IsValidCodePage
isxdigit
LCMapStringA
LCMapStringW
LoadLibraryA
LoadStringA
longjmp
malloc
MapFileAndCheckSumA
MapViewOfFileEx
memcpy
memmove
memset
MultiByteToWideChar
printf
putc
puts
qsort
QueryPerformanceCounter
ReadFile
realloc
ReBaseImage
remove
rename
rewind
RtlUnwind
SearchPathA
SetConsoleCtrlHandler
SetEndOfFile
SetEnvironmentVariableA
SetFilePointer
SetHandleCount
SetLastError
setlocale
SetStdHandle
SetThreadPriority
SetUnhandledExceptionFilter
setvbuf
Sleep
sprintf
sscanf
strcat
strchr
strcmp
strcpy
strcspn
strlen
strncat
strncmp
strncpy
strpbrk
strrchr
strstr
strtok
strtoul
SystemTimeToFileTime
time
toupper
UnhandledExceptionFilter
UnmapViewOfFile
vfprintf
VirtualAlloc
VirtualFree
vprintf
WideCharToMultiByte
WriteConsoleA
WriteConsoleW

int WriteFile(void* handle, void* buffer, unsigned long n, unsigned long* m, void* overlapped)
{
}

