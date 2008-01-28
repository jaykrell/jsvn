@if "%_echo%" == "" @echo off
pushd .
call %SystemDrive%\WINDDK\2600.1106\bin\setenv %SystemDrive%\WINDDK\2600.1106 w2k f
popd
if errorlevel 1 goto :eof
set INCLUDE=%CRT_INC_PATH%;%INCLUDE%
set LIB=%SDK_LIB_DEST%\%_BuildArch:x86=i386%
Title WinDDK 2600 2000 x86 fre
