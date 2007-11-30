call \dev2\j\env\clearenv

@echo on

set INCLUDE=C:\msdev\70\VC7\ATLMFC\include;C:\msdev\70\VC7\include;C:\msdev\70\Vc7\PlatformSDK\include
set LIB=C:\msdev\70\VC7\ATLMFC\lib;C:\msdev\70\VC7\lib;C:\msdev\70\Vc7\PlatformSDK\lib
set PATH=C:\msdev\70\VC7\bin;C:\msdev\70\Common7\IDE;%PATH%

@rem reset errorlevel
@dir > nul

Title VC70
