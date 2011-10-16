call "%~dp0..\compose" "%~f0"

set LIB=
set INCLUDE=

set CM3_GCC_BACKEND=
set CM3_OSTYPE=
set CM3_TARGET=
set OMIT_GCC=
set CM3_ROOT=/dev2/cm3
if exist %SystemDrive%\dev2\cm3.2 set CM3_ROOT=/dev2/cm3.2
set CM3_INSTALL=/cm3
set M3CONFIG=
rem set M3CONFIG=/dev2/cm3/m3-sys/cminstall/src/config-no-install/NT386GNU
set CM3_TARGET=NT386GNU
