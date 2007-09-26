
setlocal

del ?.obj
del ?.pdb
del 1.c
del 2.c

echo typedef int T1;         >> 1.c
echo struct T2;              >> 1.c
echo typedef struct T2 T3;   >> 1.c
echo struct T4 { int i; };   >> 1.c
echo struct T5;              >> 1.c
echo typedef struct T6 { char i; } T7; >> 1.c
echo typedef struct T8 { char i; } T8; >> 1.c

echo __declspec(dllexport) void* F1(T1* a) { return a; } >> 1.c
echo __declspec(dllexport) void* F2(struct T2* a) { return a; } >> 1.c
echo __declspec(dllexport) void* F3(T3* a) { return a; } >> 1.c
echo __declspec(dllexport) void* F4(struct T4* a) { return a; } >> 1.c
echo __declspec(dllexport) void* F5(struct T5* a) { return a; } >> 1.c
echo __declspec(dllexport) void* F6(struct T6* a) { return a; } >> 1.c
echo __declspec(dllexport) void* F7(T7* a) { return a; } >> 1.c
echo __declspec(dllexport) void* F8(T8* a) { return a; } >> 1.c
echo #if _MSC_VER ^>= 1400 >> 1.c
echo __declspec(noreturn) void abort(); >> 1.c
echo __declspec(dllexport noreturn) void F9() { abort(); } >> 1.c
echo #endif >> 1.c

echo typedef int T1;         >> 2.c
echo struct T2;              >> 2.c
echo typedef struct T2 T3;   >> 2.c
echo struct T4 { int i; };   >> 2.c
echo struct T5;              >> 2.c
echo typedef struct T6 { char i; } T7; >> 2.c
echo typedef struct T8 { char i; } T8; >> 2.c

echo static int F10(T1* a) { return (int) a; } >> 2.c
echo __declspec(dllexport) int F11(void* a) { return F10(a); } >> 2.c

call \env\microsoft\vc20
echo on

echo ----------------------- a
del 1.obj 1.pdb 1.ilk 1.dll
cl /LD /MD /Z7 1.c /link /dll /noentry /incremental:no || exit /b 1
move 1.obj a.obj || exit /b 1
move 1.pdb a.pdb || exit /b 1
pdb a.obj > \a.obj.txt
pdb a.pdb > \a.pdb.txt

echo ----------------------- b
del 1.obj 1.pdb 1.ilk 1.dll
cl /LD /MD /Zi 1.c /link /dll /noentry /incremental:no || exit /b 1
move 1.obj b.obj || exit /b 1
move 1.pdb b.pdb || exit /b 1
pdb b.obj > \b.obj.txt
pdb b.pdb > \b.pdb.txt

echo ----------------------- c
del 1.obj 1.pdb 1.ilk 1.dll
cl /LD /MD /Z7 1.c /link /dll /noentry /incremental:no /pdb:none || exit /b 1
move 1.obj c.obj || exit /b 1
move 1.dll c.dll || exit /b 1
pdb c.obj > \c.obj.txt
pdb c.dll > \c.dll.txt

echo ----------------------- d
del 1.obj 1.pdb 1.ilk 1.dll
cl /LD /MD /Zi 1.c /link /dll /noentry /incremental:no /pdb:none || exit /b 1
move 1.obj d.obj || exit /b 1
move 1.dll d.dll || exit /b 1
pdb d.obj > \d.obj.txt
pdb d.dll > \d.dll.txt

call \env\microsoft\vc80
echo on

echo ----------------------- e
del 1.obj 1.pdb 1.ilk 1.dll
cl /LD /MD /Z7 1.c /link /dll /noentry /incremental:no || exit /b 1
move 1.obj e.obj || exit /b 1
move 1.pdb e.pdb || exit /b 1
pdb e.obj > \e.obj.txt
rem \bin\cdb pdb e.pdb

echo ----------------------- f
del 1.obj 1.pdb 1.ilk 1.dll
cl /LD /MD /Zi 1.c /link /dll /noentry /incremental:no || exit /b 1
move 1.obj f.obj || exit /b 1
move 1.pdb f.pdb || exit /b 1
pdb f.obj > \f.obj.txt
rem \bin\cdb pdb f.pdb

echo ----------------------- g
del 1.obj 1.pdb 1.ilk 1.dll
cl /LD /MD /ZI 1.c /link /dll /noentry || exit /b 1
move 1.obj g.obj || exit /b 1
move 1.pdb g.pdb || exit /b 1
pdb f.obj > \g.obj.txt
rem \bin\cdb pdb g.pdb

call \env\microsoft\vc50
echo on

echo ----------------------- h
del 1.obj 1.pdb 1.ilk 1.dll
cl /LD /MD /Z7 1.c /link /dll /noentry /incremental:no || exit /b 1
move 1.obj h.obj || exit /b 1
move 1.pdb h.pdb || exit /b 1
pdb h.obj > \h.obj.txt
pdb h.pdb

echo ----------------------- i
del 1.obj 1.pdb 1.ilk 1.dll
cl /LD /MD /Zi 1.c /link /dll /noentry /incremental:no || exit /b 1
move 1.obj i.obj || exit /b 1
move 1.pdb i.pdb || exit /b 1
pdb i.obj > \i.obj.txt
pdb i.pdb

call \env\microsoft\vc50
echo on

echo ----------------------- j
del 1.obj 1.pdb 1.ilk 1.dll 2.obj
cl /LD /MD /Z7 1.c 2.c /link /dll /noentry /incremental:no || exit /b 1
move 1.obj j.obj || exit /b 1
move 1.pdb j.pdb || exit /b 1
pdb j.obj > \j.obj.txt
pdb j.pdb > \j.pdb.txt

endlocal
