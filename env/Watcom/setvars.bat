@if "%_echo%" == "" @echo off
@rem *****************************************************************
@rem SETVARS.BAT - Windows NT version
@rem *****************************************************************
@rem NOTE: Do not use this batch file directly, but copy it and
@rem       modify it as necessary for your own use!!

@rem Setup environment variables for Perforce
set P4PORT=perforce.scitechsoft.com:3488
set P4USER=YourName
set P4CLIENT=YOURCLIENT
set P4PASSWD=YourPassword

@rem Change this to point to your Open Watcom source tree - must be an 8.3 name!
set OWROOT=%SystemDrive%\ow

@rem Change this to point to your existing Open Watcom installation
set WATCOM=%SystemDrive%\watcom

@rem placeholder
@rem placeholder

@rem Change this to the install location of GhostScript for PDF creation (optional)
set GHOSTSCRIPT=%SystemDrive%\gs\gs7.04

@rem Modifications beyond this point should not be necessary

@rem Set this variable to 1 to get debug build
set DEBUG_BUILD=0

@rem Set this variable to 1 to get default windowing support in clib
set DEFAULT_WINDOWING=0

@rem Set this variable to 0 to suppress documentation build
set DOC_BUILD=1

@rem Documentation related variables
@rem set appropriate variables to blank for help compilers which you haven't installed
set WIN95HC=hcrtf
set OS2HC=ipfc

@rem Set up default path information variable
if "%DEFPATH%" == "" set DEFPATH=%PATH%

@rem Subdirectory to be used for bootstrapping
set OBJDIR=bootstrp

@rem Subdirectory to be used for building prerequisite utilities
set PREOBJDIR=prebuild

@rem Stuff for the Open Watcom build environment
set BUILD_PLATFORM=nt386
set BLD_VER=16
set BLD_VER_STR=1.6
set BUILDER_CTL=lang.ctl
set DEVDIR=%OWROOT%\bld
@rem Subdirectory to be used for bootstrapping/prebuild binaries
set OWBINDIR=%DEVDIR%\build\binnt
set DISTROOT=%OWROOT%\distrib
set RELROOT=%OWROOT%
set DWATCOM=%WATCOM%
set DOC_ROOT=%OWROOT%\docs
set INCLUDE=%WATCOM%\h;%WATCOM%\h\nt
set EDPATH=%WATCOM%\eddat
set PATH=%OWROOT%\bin;%OWBINDIR%;%OWROOT%\bat;%WATCOM%\binnt;%WATCOM%\binw;%WATCOM%\binp;%DOC_ROOT%\cmds;%DEFPATH%

echo Open Watcom compiler build environment

@rem OS specifics

cd %DEVDIR%

set DOS4G=quiet

@rem setup right COMSPEC for non-standard COMSPEC setting on NT based systems
if '%OS%' == 'Windows_NT' set COMSPEC=%windir%\system32\cmd.exe

set COPYCMD=/y
