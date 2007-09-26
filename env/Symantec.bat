@if "%_echo%" == "" @echo off

call \dev2\j\env\clearenv

set path=c:\sc\bin;%path%
set help=c:\sc\help;%help%

@rem reset errorlevel
dir > nul

Title Symantec
