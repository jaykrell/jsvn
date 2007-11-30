@call \dev2\j\env\clearenv

@echo on

set INCLUDE=C:\msdev\80\VC\include;C:\Program Files\Microsoft Platform SDK for Windows Server 2003 R2\Include
set LIB=C:\msdev\80\VC\lib;C:\Program Files\Microsoft Platform SDK for Windows Server 2003 R2\Lib
set PATH=C:\msdev\80\VC\BIN;C:\msdev\80\Common7\IDE;%PATH%

@rem reset errorlevel
@dir > nul

@Title VC80
