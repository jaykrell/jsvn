typedef int T1;         
struct T2;              
typedef struct T2 T3;   
struct T4 { int i; };   
struct T5;              
typedef struct T6 { char i; } T7; 
typedef struct T8 { char i; } T8; 
static int F10(T1* a) { return (int) a; } 
__declspec(dllexport) int F11(void* a) { return F10(a); } 
