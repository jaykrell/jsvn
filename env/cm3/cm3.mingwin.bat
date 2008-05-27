call "%~dp0..\compose" "%~f0"
call "%~dp0..\msys" "%~f0"
@echo on
set LIB=
set INCLUDE=

set CM3_GCC_BACKEND=
set CM3_OSTYPE=
set CM3_TARGET=
set OMIT_GCC=
set CM3_ROOT=%SystemDrive%\dev2\cm3
if exist %SystemDrive%\dev2\cm3.2 set CM3_ROOT=%SystemDrive%\dev2\cm3.2
set CM3_INSTALL=%SystemDrive%\cm3
set M3CONFIG=
