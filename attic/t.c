#if defined(_X86_) || defined(_M_IX86)
char Arch[]="\nset arch=x86\n";
#elif defined(_IA64_) || defined(_M_IA64)
char Arch[]="\nset arch=IA64\n";
#elif defined(_AMD64_) || defined(_M_AMD64)
char Arch[]="\nset arch=AMD64\n";
#else
char Arch[]="\n set arch=16bit\n";
#endif
int _acrtused;
int _aFchkstk;
main() { return (int) Arch[0]; }
void _stdcall CreateHardLinkW(void* a, void* b, void* c);
void* x = CreateHardLinkW;
