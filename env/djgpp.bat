@if "%_echo%" == "" @echo off

call \dev2\j\env\clearenv

@rem if "%COMSPEC%" == "Z:\COMMAND.COM" set PATH=z:\
@rem if not "%COMSPEC%" == "Z:\COMMAND.COM" set PATH=%WINDIR%\system32;%WINDIR%;%WINDIR%\System32\Wbem

@if exist c:\djgpp\nul goto :c
@if exist c:\djgpp     goto :c
@if exist d:\djgpp\nul goto :d
@if exist d:\djgpp     goto :d
@echo \djgpp not found
@goto :end

:c
@set DJGPP=c:\djgpp
@goto :common

:d
@set DJGPP=d:\djgpp
@goto :common

:common
@set PATH=%DJGPP%\bin;%PATH%
@set DJGPP=%DJGPP%\djgpp.env

@rem reset errorlevel
@dir > nul

@Title djgpp

:end
