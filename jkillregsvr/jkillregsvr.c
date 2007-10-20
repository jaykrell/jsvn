#include <stdio.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

#define GENERIC_ALL (0x10000000L)
#define MAXIMUM_ALLOWED (0x02000000L)

void* __stdcall OpenProcess(unsigned long a, int b, unsigned long c);
void __stdcall EnumProcesses(unsigned long* a, unsigned long b, unsigned long* c);
int __stdcall EnumProcessModules(void* hProcess, void** lphModule, unsigned long cb, unsigned long* lpcbNeeded);
unsigned long __stdcall GetModuleBaseNameA(void* hProcess, void* hModule, char* BaseName, unsigned long size);
unsigned long __stdcall GetModuleBaseNameW(void* hProcess, void* hModule, wchar_t* BaseName, unsigned long size);
void __stdcall TerminateProcess(void* hProcess, unsigned long ExitCode);

wchar_t a[1000];

void* MyOpenProcess(unsigned i);
void GetProcessName(void* p);

int wmain()
{
    unsigned long cb = 1000;
    unsigned long ProcessIds[1000] = { 0 };
    unsigned i = 0;

    EnumProcesses(ProcessIds, 1000, &cb);
    for ( i = 0 ; (ProcessIds[i] || i == 0); ++i)
    {
        unsigned long ProcessId = ProcessIds[i];
        void* ProcessHandle = OpenProcess(MAXIMUM_ALLOWED, FALSE, ProcessId);
        wprintf(L"%lu: 0x%08lx 0n%lu\n", 1UL, ProcessId, ProcessId);
        if (!ProcessHandle)
        {
            wprintf(L"%lu: 0x%08lx 0n%lu\n", 2UL, ProcessId, ProcessId);
            continue;
        }
        wprintf(L"%lu: 0x%08lx 0n%lu\n", 3UL, ProcessId, ProcessId);
        a[0] = 0;
        GetProcessName(ProcessHandle);
        wprintf(L"%lu: 0x%08lx 0n%lu %s\n", 4UL, ProcessId, ProcessId, a);
        if (!a[0])
            continue;
        if ((_wcsicmp(a, L"regsvr32.exe") != 0) && (_wcsicmp(a, L"rundll32.exe") != 0))
            continue;
        wprintf(L"%lu: 0x%08lx 0n%lu (kill)\n", 5UL, ProcessId, ProcessId);
        TerminateProcess(ProcessHandle, -1);
    }
    return 0;
}

#ifdef __GNUC__
int main()
{
    return wmain();
}
#endif

void GetProcessName(void* ProcessHandle)
{
    void* Modules[1000];
    unsigned j = 0;
    unsigned long cb = 0;

    a[0] = 0;
    if (!EnumProcessModules(ProcessHandle, Modules, 1000, &cb))
        return;
    for ( j = 0  ; Modules[j] ; ++j)
    {
        if (GetModuleBaseNameW(ProcessHandle, Modules[j], a, 1000))
        {
            _wcslwr(a);
            if (wcsstr(a, L".exe"))
                return;
        }
    }
}
