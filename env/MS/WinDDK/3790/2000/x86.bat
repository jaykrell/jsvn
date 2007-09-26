@if "%_echo%" == "" @echo off
pushd .
call \WINDDK\3790\bin\setenv C:\WINDDK\3790 w2k f
popd
if errorlevel 1 goto :eof
set INCLUDE=%CRT_INC_PATH%;%INCLUDE%
set LIB=%SDK_LIB_DEST%\%_BuildArch:x86=i386%
Title WinDDK 3790 2000 x86 fre
