@call \dev2\j\env\clearenv

@echo on

set INCLUDE=%SystemDrive%\msdev\71\include;%SystemDrive%\Program Files\Microsoft Platform SDK for Windows Server 2003 R2\Include
set LIB=%SystemDrive%\msdev\71\lib;%SystemDrive%\Program Files\Microsoft Platform SDK for Windows Server 2003 R2\Lib
set PATH=%SystemDrive%\msdev\71\BIN;%PATH%

@rem reset errorlevel
@dir > nul

@Title VC71
