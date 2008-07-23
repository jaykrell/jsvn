@if "%_echo%" == "" @echo off

call \dev2\j\env\clearenv

@rem if "%COMSPEC%" == "Z:\COMMAND.COM" set PATH=z:\
@rem if not "%COMSPEC%" == "Z:\COMMAND.COM" set PATH=%WINDIR%\system32;%WINDIR%;%WINDIR%\System32\Wbem

@if exist c:\djgpp.203\nul goto :c
@if exist c:\djgpp.203     goto :c
@if exist d:\djgpp.203\nul goto :d
@if exist d:\djgpp.203     goto :d
@echo \djgpp\203 not found
@goto :end

:c
@set DJGPP=c:\djgpp.203
@goto :common

:d
@set DJGPP=d:\djgpp.203
@goto :common

:common
@set PATH=%DJGPP%\bin;%PATH%
@set DJGPP=%DJGPP%\djgpp.env

@rem reset errorlevel
@dir > nul

@Title djgpp 2.03

:end
