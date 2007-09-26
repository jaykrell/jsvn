@if "%_echo%" == "" @echo off

call \dev2\j\env\clearenv

set PATH=C:\MinGW\bin;%PATH%

Title MinGW

if defined QTDIR set PATH=%QTDIR%\bin;%PATH%
if defined QTDIR Title MinGW/Qt

@rem reset errorlevel
dir > nul
