@if "%_echo%" == "" @echo off

call \dev2\j\env\clearenv

set path=%SystemDrive%\sc\bin;%path%
set help=%SystemDrive%\sc\help;%help%

@rem reset errorlevel
dir > nul

Title Symantec
