@if "%_echo%" == "" @echo off
echo on

setlocal

call \dev2\j\env\clearenv

@rem ----------------------------------------------------------------------
@rem Microsoft C++ for Windows CE, various versions and processors
@rem ----------------------------------------------------------------------

call :Compile MS\CE\200\mipsii clmips /nologo /c /Zi /GF || exit /b 1
call :Compile MS\CE\200\mipsii_fp clmips /nologo /c /Zi /GF || exit /b 1
call :Compile MS\CE\200\mipsiv clmips /nologo /c /Zi /GF || exit /b 1
call :Compile MS\CE\200\mipsiv_fp clmips /nologo /c /Zi /GF || exit /b 1
call :Compile MS\CE\200\ppc clppc /nologo /c /Zi /GF /EHsc || exit /b 1
call :Compile MS\CE\200\sh shcl /nologo /c /Zi /GF /GX || exit /b 1
call :Compile MS\CE\200\x86 cl /nologo /c /Zi /GF /GX || exit /b 1

call :Compile MS\CE\201\mipsii clmips /nologo /c /Zi /GF || exit /b 1
call :Compile MS\CE\201\mipsii_fp clmips /nologo /c /Zi /GF || exit /b 1
call :Compile MS\CE\201\mipsiv clmips /nologo /c /Zi /GF || exit /b 1
call :Compile MS\CE\201\mipsiv_fp clmips /nologo /c /Zi /GF || exit /b 1
call :Compile MS\CE\201\sh shcl /nologo /c /Zi /GF /GX || exit /b 1
call :Compile MS\CE\201\x86 cl /nologo /c /Zi /GF /GX || exit /b 1

call :Compile MS\CE\210\mipsii clmips /nologo /c /Zi /GF || exit /b 1
call :Compile MS\CE\210\mipsii_fp clmips /nologo /c /Zi /GF || exit /b 1
call :Compile MS\CE\210\mipsiv clmips /nologo /c /Zi /GF || exit /b 1
call :Compile MS\CE\210\mipsiv_fp clmips /nologo /c /Zi /GF || exit /b 1
call :Compile MS\CE\210\sh shcl /nologo /c /Zi /GF /GX || exit /b 1
call :Compile MS\CE\210\ppc clppc /nologo /c /Zi /GF /GX || exit /b 1
call :Compile MS\CE\210\x86 cl /nologo /c /Zi /GF /GX || exit /b 1

call :Compile MS\CE\211\mipsii clmips /nologo /c /Zi /GF || exit /b 1
call :Compile MS\CE\211\mipsii_fp clmips /nologo /c /Zi /GF || exit /b 1
call :Compile MS\CE\211\mipsiv clmips /nologo /c /Zi /GF || exit /b 1
call :Compile MS\CE\211\mipsiv_fp clmips /nologo /c /Zi /GF || exit /b 1
call :Compile MS\CE\211\sh shcl /nologo /c /Zi /GF || exit /b 1
call :Compile MS\CE\211\ppc clppc /nologo /c /Zi /GF || exit /b 1
call :Compile MS\CE\211\x86 cl /nologo /c /Zi /GF || exit /b 1

call :Compile MS\CE\212\mipsii clmips /nologo /c /Zi /GF || exit /b 1
call :Compile MS\CE\212\mipsii_fp clmips /nologo /c /Zi /GF || exit /b 1
call :Compile MS\CE\212\mipsiv clmips /nologo /c /Zi /GF || exit /b 1
call :Compile MS\CE\212\mipsiv_fp clmips /nologo /c /Zi /GF || exit /b 1
call :Compile MS\CE\212\sh shcl /nologo /c /Zi /GF /GX || exit /b 1
call :Compile MS\CE\212\ppc clppc /nologo /c /Zi /GF /GX || exit /b 1
call :Compile MS\CE\212\thumb clthumb /nologo /c /Zi /GF /GX || exit /b 1
call :Compile MS\CE\212\x86 cl /nologo /c /Zi /GF /GX || exit /b 1

call :Compile MS\CE\300\mipsii clmips /nologo /c /Zi /GF || exit /b 1
call :Compile MS\CE\300\mipsii_fp clmips /nologo /c /Zi /GF || exit /b 1
call :Compile MS\CE\300\mipsiv clmips /nologo /c /Zi /GF || exit /b 1
call :Compile MS\CE\300\mipsiv_fp clmips /nologo /c /Zi /GF || exit /b 1
call :Compile MS\CE\300\sh shcl /nologo /c /Zi /GF /GX || exit /b 1
call :Compile MS\CE\300\ppc clppc /nologo /c /Zi /GF /GX || exit /b 1
call :Compile MS\CE\300\thumb clthumb /nologo /c /Zi /GF /GX || exit /b 1
call :Compile MS\CE\300\arm clarm /nologo /c /Zi /GF /GX || exit /b 1
call :Compile MS\CE\300\x86 cl /nologo /c /Zi /GF /GX || exit /b 1

call :CompileAndLink MS\CE\410\mipsii clmips /nologo /Zi /EHs || exit /b 1
call :CompileAndLink MS\CE\410\mipsii_fp clmips /nologo /Zi /EHs || exit /b 1
call :CompileAndLink MS\CE\410\mipsiv clmips /nologo /Zi /EHs || exit /b 1
call :CompileAndLink MS\CE\410\mipsiv_fp clmips /nologo /Zi /EHs || exit /b 1
call :Compile MS\CE\410\thumb clthumb /nologo /c /Zi /EHs || exit /b 1
call :CompileAndLink MS\CE\410\sh4 clsh /nologo /Zi /EHs || exit /b 1
call :Compile MS\CE\410\x86 cl /nologo /c /Zi /EHs || exit /b 1
call :CompileAndLink MS\CE\410\armv4i clarm /nologo /Zi /EHs || exit /b 1

call :CompileAndLink MS\CE\420\mipsii clmips /nologo /Zi /EHs || exit /b 1
call :CompileAndLink MS\CE\420\mipsii_fp clmips /nologo /Zi /EHs || exit /b 1
call :CompileAndLink MS\CE\420\mipsiv clmips /nologo /Zi /EHs || exit /b 1
call :CompileAndLink MS\CE\420\mipsiv_fp clmips /nologo /Zi /EHs || exit /b 1
call :Compile MS\CE\420\thumb clthumb /nologo /c /Zi /EHs || exit /b 1
call :CompileAndLink MS\CE\420\sh4 clsh /nologo /Zi /EHs || exit /b 1
call :Compile MS\CE\420\x86 cl /nologo /c /Zi /EHs || exit /b 1
call :CompileAndLink MS\CE\420\armv4i clarm /nologo /Zi /EHs || exit /b 1

call :CompileAndLink MS\CE\500\mipsii clmips /nologo /Zi /EHs || exit /b 1
call :CompileAndLink MS\CE\500\mipsii_fp clmips /nologo /Zi /EHs || exit /b 1
call :CompileAndLink MS\CE\500\mipsiv clmips /nologo /Zi /EHs || exit /b 1
call :CompileAndLink MS\CE\500\mipsiv_fp clmips /nologo /Zi /EHs || exit /b 1
call :Compile MS\CE\500\thumb clthumb /nologo /c /Zi /EHs || exit /b 1
call :CompileAndLink MS\CE\500\sh4 clsh /nologo /Zi /EHs || exit /b 1
call :Compile MS\CE\500\x86 cl /nologo /c /Zi /EHs || exit /b 1
call :CompileAndLink MS\CE\500\armv4i clarm /nologo /Zi /EHs || exit /b 1

@rem ----------------------------------------------------------------------
@rem Microsoft Visual C++ 16 bit
@rem ----------------------------------------------------------------------

@rem not yet working, needs a fix
@rem call :CompileAndLinkAndRun vc10 cl || exit /b 1

call :CompileAndLinkAndRun MS\VC15 cl /nologo /Zi /W4 /WX || exit /b 1

if not defined SystemRoot goto :eof

@rem ----------------------------------------------------------------------
@rem Open Watcom 16 bit, 32 bit
@rem ----------------------------------------------------------------------

call :CompileAndLinkAndRun Watcom\Dos wcl /xs || exit /b 1
call :CompileAndLinkAndRun Watcom\Dos wcl386 /xs || exit /b 1
@rem call :CompileAndLinkAndRun Watcom\Dos wcl386 /l=dos32a /xs || exit /b 1

call :CompileAndLinkAndRun Watcom\Win16 wcl /xs || exit /b 1
call :CompileAndLinkAndRun Watcom\Win16 wcl386 /xs || exit /b 1
@rem call :CompileAndLinkAndRun Watcom\Win16 wcl386 /l=dos32a /xs || exit /b 1

call :CompileAndLinkAndRun Watcom\Win32 wcl /xs || exit /b 1
call :CompileAndLinkAndRun Watcom\Win32 wcl386 /xs || exit /b 1
@rem call :CompileAndLinkAndRun Watcom\Win32 wcl386 /l=dos32a || exit /b 1

@rem ----------------------------------------------------------------------
@rem Metrowerks 6, 7, 8, 68K (6), PowerPC, x86
@rem ----------------------------------------------------------------------

call :CompileAndLinkAndRun mwerks\6 mwcc || exit /b 1
call :Compile mwerks\6 mwcppc || exit /b 1
call :Compile mwerks\6 mwc68k || exit /b 1

call :CompileAndLinkAndRun mwerks\7 mwcc || exit /b 1
call :Compile mwerks\7 mwcppc || exit /b 1

call :CompileAndLinkAndRun mwerks\8 mwcc || exit /b 1
call :Compile mwerks\8 mwcppc || exit /b 1

rem goto :end

@rem ----------------------------------------------------------------------
@rem Microsoft Visual C++ 32 bit / 64 bit
@rem 2.0, 4.0, 4.1, 4.2, 5.0, 6.0, 7.0, 7.1, 8.0
@rem ----------------------------------------------------------------------

call :CompileAndLinkAndRun MS\VC20 cl "/nologo /MD /Zi /W4 /WX /GX /Oi" || exit /b 1
call :CompileAndLinkAndRun MS\VC40 cl "/nologo /MD /Zi /W4 /WX /GX /GR /Oi" || exit /b 1
call :CompileAndLinkAndRun MS\VC41 cl "/nologo /MD /Zi /W4 /WX /GX /GR /Oi" || exit /b 1
call :CompileAndLinkAndRun MS\VC50 cl "/nologo /MD /Zi /W4 /WX /EHsc /GR /Oi" || exit /b 1
call :CompileAndLinkAndRun MS\VC60 cl "/nologo /MD /Zi /W4 /WX /EHsc /GR /Oi" || exit /b 1
call :CompileAndLinkAndRun MS\VC60 cl "/nologo /MD /Zi /W4 /WX /Oi" || exit /b 1
call :CompileAndLinkAndRun MS\VC70 cl "/nologo /MD /Zi /W4 /WX /Wp64 /EHsc /GR /Oi" || exit /b 1
call :CompileAndLinkAndRun MS\VC71 cl "/nologo /MD /Zi /EHsc /GR /W4 /WX /Wp64 /Oi" || exit /b 1
call :CompileAndLinkAndRun MS\VC80 cl "/nologo /MD /Zi /EHsc /GR /W4 /WX /Wp64 /Oi" || exit /b 1

@rem ----------------------------------------------------------------------
@rem Visual C++ for Macintosh 4.0, 4.1, 68K, PowerPC
@rem ----------------------------------------------------------------------

call :CompileAndLink MS\MacPPC\VC40 cl "/nologo /MD /Zi /W4 /WX /GX /Oi" || exit /b 1
call :CompileAndLink MS\MacPPC\VC41 cl "/nologo /MD /Zi /W4 /WX /GX /Oi" || exit /b 1
call :CompileAndLink MS\MacPPC\VC42 cl "/nologo /MD /Zi /W4 /WX /GX /Oi" || exit /b 1

call :CompileAndLink MS\Mac68K\VC40 cl "/nologo /MD /Zi /W4 /WX /GX /Oi" || exit /b 1
call :CompileAndLink MS\Mac68K\VC41 cl "/nologo /MD /Zi /W4 /WX /GX /Oi" || exit /b 1
call :CompileAndLink MS\Mac68K\VC42 cl "/nologo /MD /Zi /W4 /WX /GX /Oi" || exit /b 1

@rem ----------------------------------------------------------------------
@rem Cygwin
@rem ----------------------------------------------------------------------

call :Compile Cygwin g++ -S -g || exit /b 1
call :CompileAndLinkAndRun Cygwin g++ -g || exit /b 1
call :Compile Cygwin i686-pc-cygwin-g++ -S -g || exit /b 1
call :CompileAndLinkAndRun Cygwin i686-pc-cygwin-g++ -g || exit /b 1

@rem ----------------------------------------------------------------------
@rem MinGWin
@rem ----------------------------------------------------------------------

call :Compile MinGWin g++ -S -g || exit /b 1
call :CompileAndLinkAndRun MinGWin g++ -g || exit /b 1
call :Compile MinGWin mingw32-g++ -S -g || exit /b 1
call :CompileAndLinkAndRun MinGWin mingw32-g++ -g || exit /b 1

@rem ----------------------------------------------------------------------
@rem WinDDK x86 (Microsoft Visual C++)
@rem ----------------------------------------------------------------------

call :CompileAndLinkAndRun MS\WinDDK\3790\2000\x86 cl "/nologo /MD /Zi /EHs" || exit /b 1
call :CompileAndLinkAndRun MS\WinDDK\3790\xp\x86 cl "/nologo /MD /Zi /EHs" || exit /b 1
call :CompileAndLinkAndRun MS\WinDDK\3790\2003\x86 cl /nologo /MD /Zi /EHs || exit /b 1

@rem ----------------------------------------------------------------------
@rem WinDDK IA64 (Microsoft Visual C++)
@rem ----------------------------------------------------------------------

call :CompileAndLink MS\WinDDK\3790\xp\IA64 cl /nologo /MD /Zi /EHs || exit /b 1
call :CompileAndLink MS\WinDDK\3790\2003\IA64 cl /nologo /MD /Zi /EHs || exit /b 1

@rem ----------------------------------------------------------------------
@rem WinDDK AMD64 (Microsoft Visual C++)
@rem ----------------------------------------------------------------------

call :CompileAndLink MS\WinDDK\3790\2003\AMD64 cl /nologo /MD /Zi /W4 /WX /Wp64 /EHsc /GR || exit /b 1

@rem ----------------------------------------------------------------------
@rem WinSDK IA64 (Microsoft Visual C++)
@rem ----------------------------------------------------------------------

call :CompileAndLink MS\WinSDK\IA64 cl /nologo /MD /Zi /W4 /WX /Wp64 /EHsc /GR || exit /b 1

@rem ----------------------------------------------------------------------
@rem WinSDK AMD64 (Microsoft Visual C++)
@rem ----------------------------------------------------------------------

call :CompileAndLink MS\WinSDK\AMD64 cl /nologo /MD /Zi /W4 /WX /Wp64 /EHsc /GR || exit /b 1

@rem ----------------------------------------------------------------------
@rem DigitalMars
@rem ----------------------------------------------------------------------

call :CompileAndLinkAndRun dmars cl /nologo /GX || exit /b 1
call :CompileAndLinkAndRun dmars dmc /Ae || exit /b 1

@rem ----------------------------------------------------------------------
@rem ----------------------------------------------------------------------

Title %COMSPEC%

echo Success

exit /b 0

@rem ----------------------------------------------------------------------
:CompileAndLinkAndRun
@rem ----------------------------------------------------------------------

setlocal
call :_CompileAndLink %1 %2 %3 %4 %5 %6 %7 %8 %9
if errorlevel 1 (
    endlocal
    exit /b 1
)
del a.exe 1.exe 2>nul
ren %a%.exe a.exe >nul
if exist %a%.exe.manifest ren %a%.exe.manifest a.exe.manifest
call a.exe >nul 2>&1
if errorlevel 1 call :Error %1
if errorlevel 1 exit /b 1
endlocal
exit /b 0

@rem ----------------------------------------------------------------------
:CompileAndLink
@rem ----------------------------------------------------------------------

setlocal
call :_CompileAndLink %1 %2 %3 %4 %5 %6 %7 %8 %9 || (
    endlocal
    exit /b 1
)
makepef %a%.exe %a%.pef 2>nul
endlocal
exit /b 0

@rem ----------------------------------------------------------------------
:_CompileAndLink
@rem ----------------------------------------------------------------------

@rem
@rem This does not have setlocal/endlocal.
@rem Its caller should.
@rem

del a.exe 1.exe 2>nul

call :_Compile %1 %2 %3 %4 %5 %6 %7 %8 %9

if not exist 1.exe if not exist a.exe (
    call %2 %3 %4 %5 %6 1.cpp
    call :Error %1
    exit /b 1
)

if exist 1.exe ren 1.exe %a%.exe
if errorlevel 1 call :Error %1
if errorlevel 1 exit /b 1

if exist 1.exe.manifest ren 1.exe.manifest %a%.exe.manifest
if errorlevel 1 call :Error %1
if errorlevel 1 exit /b 1

if exist 1.pdb ren 1.pdb %a%.pdb
if errorlevel 1 call :Error %1
if errorlevel 1 exit /b 1

if exist a.exe ren a.exe %a%.exe
if errorlevel 1 call :Error %1
if errorlevel 1 exit /b 1

if exist a.exe.manifest ren a.exe.manifest %a%.exe.manifest
if errorlevel 1 call :Error %1
if errorlevel 1 exit /b 1

if exist a.pdb ren a.pdb %a%.pdb
if errorlevel 1 call :Error %1
if errorlevel 1 exit /b 1

exit /b 0

@rem ----------------------------------------------------------------------
:Compile
@rem ----------------------------------------------------------------------

setlocal
call :_Compile %1 %2 %3 %4 %5 %6 %7 %8 %9 || (
    endlocal
    exit /b 1
)
endlocal
exit /b 0

@rem ----------------------------------------------------------------------
:_Compile
@rem ----------------------------------------------------------------------

@rem
@rem This does not have setlocal/endlocal.
@rem Its caller should.
@rem

rem echo %1 %2 %3 %4 %5 %6 %7 %8 %9

set a=%1 %2 %3 %4 %5 %6 %7 %8 %9
set a=%a: =%
set a=%a:\=_%
set a=%a:/=_%
set a=%a:"=_%

for %%b in (vc*.pdb) do del %%b
for %%b in (*.ilk) do del %%b
for %%b in (msvc.pdb 1.exe 1.pdb %a%.exe %a%.exe.manifest %a%.pdb %a%.obj %a%.s) do if exist %%b del %%b

@rem
@rem in particular, 16bit tools require a small environment
@rem
call clearenv

call %1 >nul 2>&1
if errorlevel 1 call %1
if errorlevel 1 call :Error %1
if errorlevel 1 exit /b 1

@rem set _CL_= %_CL_%
@rem set _LINK_= %_LINK_%
@rem set _ML_= %_ML_%

@rem set _CL_= %_CL_: /Ztmp=%
@rem set _LINK_= %_LINK_: /Tmp=%
@rem set _ML_= %_ML_: /Zvc6=%

@rem echo _CL_ is %_CL_%
@rem echo _LINK_ is %_LINK_%
@rem echo LIB is %LIB%
@rem echo INCLUDE is %INCLUDE%

set command=%2 %3 %4 %5 %6 %7 1.cpp
set command=%command:"=%

@rem handle symlinks
if /i "%1" == "Cygwin" set command=sh -c "%2 %3 %4 %5 %6 %7 1.cpp"

set command=%command:  = %
set command=%command:  = %
set command=%command:  = %

echo %1 %command%
call %command% >nul 2>&1
if errorlevel 1 (
    call %command%
    call :Error %1
    exit /b 1
)

if exist 1.cpp.o ren 1.cpp.o %a%.obj
if errorlevel 1 call :Error %1
if errorlevel 1 exit /b 1

if exist 1.obj  ren 1.obj %a%.obj
if errorlevel 1 call :Error %1
if errorlevel 1 exit /b 1

if exist 1.o    ren 1.o %a%.obj
if errorlevel 1 call :Error %1
if errorlevel 1 exit /b 1

if exist 1.s    ren 1.s %a%.s
if errorlevel 1 call :Error %1
if errorlevel 1 exit /b 1

exit /b 0

@rem ----------------------------------------------------------------------

:Error
echo Error : %1 failed
Title %COMSPEC%
exit /b 1

:eof
:end
