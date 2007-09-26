typedef int T1;         
struct T2;              
typedef struct T2 T3;   
struct T4 { int i; };   
struct T5;              
typedef struct T6 { char i; } T7; 
typedef struct T8 { char i; } T8; 
__declspec(dllexport) void* F1(T1* a) { return a; } 
__declspec(dllexport) void* F2(struct T2* a) { return a; } 
__declspec(dllexport) void* F3(T3* a) { return a; } 
__declspec(dllexport) void* F4(struct T4* a) { return a; } 
__declspec(dllexport) void* F5(struct T5* a) { return a; } 
__declspec(dllexport) void* F6(struct T6* a) { return a; } 
__declspec(dllexport) void* F7(T7* a) { return a; } 
__declspec(dllexport) void* F8(T8* a) { return a; } 
#if _MSC_VER >= 1400 
__declspec(noreturn) void abort(); 
__declspec(dllexport noreturn) void F9() { abort(); } 
#endif 
