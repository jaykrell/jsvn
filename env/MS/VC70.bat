call \dev2\j\env\clearenv

@echo on

set INCLUDE=%SystemDrive%\msdev\70\VC7\ATLMFC\include;%SystemDrive%\msdev\70\VC7\include;%SystemDrive%\msdev\70\Vc7\PlatformSDK\include
set LIB=%SystemDrive%\msdev\70\VC7\ATLMFC\lib;%SystemDrive%\msdev\70\VC7\lib;%SystemDrive%\msdev\70\Vc7\PlatformSDK\lib
set PATH=%SystemDrive%\msdev\70\VC7\bin;%SystemDrive%\msdev\70\Common7\IDE;%PATH%

@rem reset errorlevel
@dir > nul

Title VC70
