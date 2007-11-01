@if "%_echo%" == "" @echo off

@rem
@rem %1 can be x86, mipsii, mipsii_fp, mipsiv_fp, armv4i, sh4, thumb
@rem

call \dev2\j\env\clearenv

set PATH=\msdev\ce\%~n0\bin;%PATH%
set INCLUDE=\msdev\ce\420\Include;%INCLUDE%
set LIB=\msdev\ce\420\lib\%1;\msdev\ce\500\lib\%1;%LIB%

set _LINK_=/subsystem:windowsce

Title CE/420/%1

@rem reset errorlevel
@dir > nul
