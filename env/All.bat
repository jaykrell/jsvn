@if "%_echo%" == "" @echo off

rem
rem To a large extent, the environments do not clash.
rem The compiler/linkers have their own names, so the environments can be merged.
rem
rem Watcom -- wcl, wcl386, wlink (but contains cl, link translators)
rem CodeWarrior -- mwcc, mwld, mwcppc, mwld
rem Vistual C++ -- cl, link, nmake -- put this first to avoid impostors
rem Cygwin -- gcc, ld
rem MinGWin -- mingw32-gcc, ld
rem Digital Mars -- dmc, link, and contains cl translator
rem

set DevEnvDir=
set EDPATH=
set FrameworkDir=
set FrameworkSDKDir=
set FrameworkVersion=
set INCLUDE=
set INIT=
set LIB=
set LIBPATH=
set LM_LICENSE_FILE=
set MSVCDir=
set MWCMac68KIncludes=
set MWCMacPPCIncludes=
set MWCWinx86Includes=
set MWMac68KLibraries=
set MWMac68KLibraryFiles=
set MWMacMPW68KLibraries=
set MWMacMPW68KLibraryFiles=
set MWMacMPWPPCLibraries=
set MWMacMPWPPCLibraryFiles=
set MWMacPPCLibraries=
set MWMacPPCLibraryFiles=
set MWWinx86Libraries=
set MWWinx86LibraryFiles=
set TOOLROOTDIR=
set VCINSTALLDIR=
set VSINSTALLDIR=
set WATCOM=

call \Env\Watcom\Win32
call \Env\DigitalMars
call \Env\Microsoft\VC50

@rem reset errorlevel
dir > nul

Title C++ development
