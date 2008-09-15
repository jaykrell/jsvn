@if "%_echo%" == "" @echo off

call %SystemDrive%\dev2\j\env\clearenv

set PATH=%SystemDrive%\cygwin\usr\X11R6\bin;%PATH%
set PATH=%SystemDrive%\cygwin\bin;%PATH%
set PATH=%SystemDrive%\cygwin\usr\local\bin;%PATH%
set CYGWIN=server

@rem reset errorlevel
dir > nul

Title gcc
