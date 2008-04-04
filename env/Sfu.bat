@if "%_echo%" == "" @echo off

call \dev2\j\env\clearenv

set PATH=%SystemDrive%\sfu\bin;%SystemDrive%\sfu\opt\gcc.3.3\bin;%SystemDrive%\sfu\usr\contrib\bin;%SystemDrive%\sfu\usr\X11R6\bin;%SystemDrive%\sfu\usr\local\bin;%SystemDrive%\sfu\usr\contrib\win32\bin;%PATH%

@rem reset errorlevel
dir > nul

Title Sfu
