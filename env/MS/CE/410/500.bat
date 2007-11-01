@if "%_echo%" == "" @echo off

@rem
@rem %1 can be x86, mipsii, mipsii_fp, mipsiv_fp, armv4i, sh4, thumb
@rem

call \dev2\j\env\clearenv

set PATH=\msdev\ce\420\bin;%PATH%
set INCLUDE=\msdev\ce\500\Include;%INCLUDE%
set LIB=\msdev\ce\500\lib\%1;%LIB%

set _LINK_=/subsystem:windowsce

Title CE/500/%1

@rem reset errorlevel
@dir > nul
