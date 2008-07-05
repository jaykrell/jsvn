void __stdcall TerminateProcess(void*, unsigned long);
void* __stdcall GetCurrentProcess(void);
void Entry() { TerminateProcess(GetCurrentProcess(), 0); }
