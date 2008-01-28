@if "%_echo%" == "" @echo off

call \dev2\j\env\clearenv

set PATH=%SystemDrive%\cygwin\bin;%PATH%

@rem reset errorlevel
dir > nul

Title gcc
