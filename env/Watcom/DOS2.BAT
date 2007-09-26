@if "%_echo%" == "" @echo off

call \dev2\j\env\clearenv

@rem if "%COMSPEC%" == "Z:\COMMAND.COM" set PATH=z:\
@rem if not "%COMSPEC%" == "Z:\COMMAND.COM" set PATH=%WINDIR%\system32;%WINDIR%;%WINDIR%\System32\Wbem

set WATCOM=
@for %%a in (c d e f g h i j k l m n o p q r s t u v w x y z) do if exist %%a:\watcom\binw\wcc.exe set  WATCOM=%%a:\watcom
if not "%WATCOM%" =="" goto :common
echo \watcom not found on any drive
goto :end

:common
@set PATH=%WATCOM%\BINW;%PATH%
@set EDPATH=%WATCOM%\EDDAT
@set INCLUDE=%WATCOM%\H

@rem reset errorlevel
@dir > nul

@Title Watcom/DOS

:end
