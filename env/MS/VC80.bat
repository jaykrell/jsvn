@call \dev2\j\env\clearenv

@echo on

set INCLUDE=%SystemDrive%\msdev\80\VC\include;%SystemDrive%\Program Files\Microsoft Platform SDK for Windows Server 2003 R2\Include
set LIB=%SystemDrive%\msdev\80\VC\lib;%SystemDrive%\Program Files\Microsoft Platform SDK for Windows Server 2003 R2\Lib
set PATH=%SystemDrive%\msdev\80\VC\BIN;%SystemDrive%\msdev\80\Common7\IDE;%PATH%

@rem reset errorlevel
@dir > nul

@Title VC80
