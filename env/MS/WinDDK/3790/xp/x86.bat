@if "%_echo%" == "" @echo off
pushd .
call C:\WINDDK\3790\bin\setenv C:\WINDDK\3790 fre WXP
popd

rem Errorlevel is set here upon success so we cannot check it.
@rem reset errorlevel
dir > nul

set INCLUDE=%CRT_INC_PATH%;%INCLUDE%
set LIB=%SDK_LIB_DEST%\%_BuildArch:x86=i386%
Title WinDDK 3790 x86 XP fre
