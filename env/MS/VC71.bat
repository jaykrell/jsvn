@call \dev2\j\env\clearenv

@echo on

set INCLUDE=C:\msdev\71\include;C:\Program Files\Microsoft Platform SDK for Windows Server 2003 R2\Include
set LIB=C:\msdev\71\lib;C:\Program Files\Microsoft Platform SDK for Windows Server 2003 R2\Lib
set PATH=C:\msdev\71\BIN;%PATH%

@rem reset errorlevel
@dir > nul

@Title VC71
