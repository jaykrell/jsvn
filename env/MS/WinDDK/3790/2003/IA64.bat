@if "%_echo%" == "" @echo off
pushd .
call %SystemDrive%\WINDDK\3790\bin\setenv %SystemDrive%\WINDDK\3790 fre 64 WNET
popd

rem Errorlevel is set here upon success so we cannot check it.
@rem reset errorlevel
dir > nul

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
Title WinDDK 3790 IA64 fre
