@echo off

setlocal

del imagehlp.c
for /f "tokens=1,2" %%a in (imagehlp.txt) do call :_%%b %%a
cl /LD imagehlp.c /link /def:imagehlp.def
del imagehlp.c
goto :eof

:_0
echo void __stdcall %1(void) { } >> imagehlp.c
goto :eof

:_4
echo void __stdcall %1(void* a) { } >> imagehlp.c
goto :eof

:_8
echo void __stdcall %1(void* a, void* b) { } >> imagehlp.c
goto :eof

:_12
echo void __stdcall %1(void* a, void* b, void *c) { } >> imagehlp.c
goto :eof

:_16
echo void __stdcall %1(void* a, void* b, void *c, void *d) { } >> imagehlp.c
goto :eof

:_20
echo void __stdcall %1(void* a, void* b, void *c, void *d, void* e) { } >> imagehlp.c
goto :eof

:_24
echo void __stdcall %1(void* a, void* b, void *c, void *d, void* e, void *f) { } >> imagehlp.c
goto :eof

:_36
echo void __stdcall %1(void* a, void* b, void *c, void *d, void* e, void *f, void* g, void*h, void *i) { } >> imagehlp.c
goto :eof

:_44
echo void __stdcall %1(void* a, void* b, void *c, void *d, void* e, void *f, void* g, void*h, void *i, void* j, void* k) { } >> imagehlp.c
goto :eof
