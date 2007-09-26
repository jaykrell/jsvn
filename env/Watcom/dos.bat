@if "%_echo%" == "" @echo off

call \dev2\j\env\clearenv

@rem if "%COMSPEC%" == "Z:\COMMAND.COM" set PATH=z:\
@rem if not "%COMSPEC%" == "Z:\COMMAND.COM" set PATH=%WINDIR%\system32;%WINDIR%;%WINDIR%\System32\Wbem

@if exist c:\watcom\nul goto :c
@if exist d:\watcom\nul goto :d
@echo \watcom not found
@goto :end

:c
@set WATCOM=C:\WATCOM
@goto :common

:d
@set WATCOM=D:\WATCOM
@goto :common

:common
@set PATH=%WATCOM%\BINW;%PATH%
@set EDPATH=%WATCOM%\EDDAT
@set INCLUDE=%WATCOM%\H

@rem reset errorlevel
@dir > nul

@Title Watcom/DOS

:end
