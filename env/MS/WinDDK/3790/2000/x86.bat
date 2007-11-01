@if "%_echo%" == "" @echo off
pushd .
call \WINDDK\3790\bin\setenv C:\WINDDK\3790 w2k f
popd

rem Errorlevel is set here upon success so we cannot check it.
@rem reset errorlevel
dir > nul

set INCLUDE=%CRT_INC_PATH%;%INCLUDE%
set LIB=%SDK_LIB_DEST%\%_BuildArch:x86=i386%
Title WinDDK 3790 2000 x86 fre
