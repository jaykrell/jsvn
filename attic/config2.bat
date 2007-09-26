@echo off

setlocal

set t=%time%%date%
set t=%t:/=%
set t=%t::=%
set t=%t: =%
set t=%t:.=%
set t=t
rem echo t is %t%

@echo testing if cl and link work and determining target architecture..

del 2>nul %t%.c

echo>>%t%.c #if defined(_X86_) ^|^| defined(_M_IX86)
echo>>%t%.c char Arch[]="\nset arch=x86\n";
echo>>%t%.c #elif defined(_IA64_) ^|^| defined(_M_IA64)
echo>>%t%.c char Arch[]="\nset arch=IA64\n";
echo>>%t%.c #elif defined(_AMD64_) ^|^| defined(_M_AMD64)
echo>>%t%.c char Arch[]="\nset arch=AMD64\n";
echo>>%t%.c #else
echo>>%t%.c char Arch[]="\nset arch=16bit\n";
echo>>%t%.c #endif
echo>>%t%.c int _acrtused;
echo>>%t%.c int _aFchkstk;
echo>>%t%.c main() { return (int) Arch[0]; }

del 2>nul %t%.obj
cl >nul 2>&1 -nologo -c -MD %t%.c
if exist %t%.obj echo cl works
if not exist %t%.obj echo cl does not work

del 2>nul %t%.exe

echo. 2>nul | link >nul %t%.obj
echo. 2>nul | link >nul 2>&1 -nologo %t%.obj

if exist %t%.exe echo link works
if not exist %t%.exe echo link does not work

for /f "tokens=*" %%a in ('findstr arch %t%.obj') do %%a 
echo target architecture is %arch%

@echo testing if windows.h is in %%INCLUDE%%

cl >nul 2>&1 -nologo -c -FIwindows.h nul && echo windows.h is in %%INCLUDE%%. || echo windows.h is not in %%INCLUDE%%

@echo testing if CreateHardLinkW is declared in windows.h

(cl 2>nul -nologo -D_WIN32_WINNT=0x500 -c -E -FIwindows.h nul | findstr CreateHardLinkW >nul) && echo CreateHardLinkW is declared in windows.h || echo CreateHardLinkW is not declared in windows.h

@echo testing if kernel32.lib is in %%LIB%%

del 2>nul %t%.exe
echo. 2>nul | link >nul 2>&1 -nologo %t%.obj kernel32.lib
if exist %t%.exe echo kernel32.lib is in %%LIB%%
if not exist %t%.exe echo kernel32.lib is not in %%LIB%%

@echo testing if CreateHardLinkW is in kernel32.lib

del 2>nul %t%.exe
del 2>nul %t%.obj
echo>>%t%.c void _stdcall CreateHardLinkW(void* a, void* b, void* c);
echo>>%t%.c void* x = CreateHardLinkW;
cl >nul 2>&1 -nologo -c -MD %t%.c
echo. 2>nul | link >nul 2>&1 -nologo %t%.obj kernel32.lib
if exist %t%.exe echo CreateHardLinkW is in kernel32.lib
if not exist %t%.exe echo CreateHardLinkW is not in kernel32.lib

@echo testing if cl supports -EH

(cl -c -nologo -EHs nul.c 2>&1 | find "-EHs" > nul) && echo cl not support -EH || echo cl supports -EH

@echo testing if cl supports -GX

(cl -c -nologo -GX nul.c 2>&1 | find "GX" > nul) && echo cl not support -GX || echo cl supports -GX

@echo testing if cl supports -TP

(cl -c -nologo -TP nul.c 2>&1 | find "TP" > nul) && echo cl not support -TP || echo cl supports -TP

@echo testing if cl supports -wd

(cl -c -nologo -wd4996 nul.c 2>&1 | find "-wd4996" >nul 2>&1) && echo cl not support -wd || echo cl supports -wd

@echo testing if link supports -opt:icf

(echo. 2>nul | link -opt:icf 2>&1 | find "opt:icf" >nul 2>&1) && echo link does not support -opt:icf || echo link supports -opt:icf

endlocal
goto :eof
