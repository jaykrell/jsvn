@if "%_echo%" == "" @echo off

call \dev2\j\env\clearenv

set PATH=c:\cygwin\bin;%PATH%

@rem reset errorlevel
dir > nul

Title gcc
