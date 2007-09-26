@if "%_echo%" == "" @echo off

call \dev2\j\env\clearenv

@set WATCOM=C:\WATCOM
@set PATH=%WATCOM%\BINNT;%WATCOM%\BINW;%PATH%
@set EDPATH=%WATCOM%\EDDAT
@set INCLUDE=%WATCOM%\H;%WATCOM%\H\NT

@rem
@rem Temporary support for Modula-3.
@rem
set LIB=%WATCOM%\lib386\nt

@rem reset errorlevel
@dir > nul

@Title Watcom/Win32

:end
