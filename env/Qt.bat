@if "%_echo%" == "" @echo off

call \dev2\j\env\clearenv

set QTDIR=%SystemDrive%\Qt\4.2.1
set PATH=%SystemDrive%\Qt\4.2.1\bin;%PATH%
set PATH=%SystemDrive%\MinGW\bin;%PATH%
set QMAKESPEC=win32-g++

if not "%1" == "compile_debug" goto END
cd %QTDIR%
echo This will configure and compile qt in debug.
echo The release libraries will not be recompiled.
pause
configure -plugin-sql-sqlite -plugin-sql-odbc -qt-libpng -qt-libjpeg
cd %QTDIR%\src
mingw32-make debug
:END

@rem reset errorlevel
dir > nul

Title Qt
