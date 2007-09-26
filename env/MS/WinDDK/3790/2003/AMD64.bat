@if "%_echo%" == "" @echo off
pushd .
call C:\WINDDK\3790\bin\setenv C:\WINDDK\3790 fre AMD64 WNET
popd
if errorlevel 1 goto :eof
set INCLUDE=%CRT_INC_PATH%;%INCLUDE%
set LIB=%SDK_LIB_DEST%\%_BuildArch:x86=i386%
set _CL_= %_CL_%
set _LINK_= %_LINK_%
set _ML_= %_ML_%
set _CL_= %_CL_: /Ztmp=%
set _LINK_= %_LINK_: /Tmp=%
set _ML_= %_ML_: /Zvc6=%
if "%_CL_: =%" == "" set _CL_=
if "%_ML_: =%" == "" set _ML_=
if "%_LINK_: =%" == "" set _LINK_=
Title WinDDK 3790 AMD64 fre
