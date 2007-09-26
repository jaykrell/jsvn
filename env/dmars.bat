@if "%_echo%" == "" @echo off

call \dev2\j\env\clearenv

set PATH=c:\dmd\bin;c:\dm\bin;%PATH%

@rem reset errorlevel
dir > nul

Title Digital Mars
