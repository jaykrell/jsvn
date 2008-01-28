@if "%_echo%" == "" @echo off

call \dev2\j\env\clearenv

set PATH=%SystemDrive%\dmd\bin;%SystemDrive%\dm\bin;%PATH%

@rem reset errorlevel
dir > nul

Title Digital Mars
