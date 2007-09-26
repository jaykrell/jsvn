__declspec(dllimport) void F1();

__declspec(dllexport) void F2() { F1(); }
