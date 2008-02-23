@if "%_echo%" == "" @echo off

@rem
@rem Get reasonable modern Perl building on DOS
@rem and then use it much as possible.
@rem Or Python or Ruby or even, heck, Tcl.
@rem Anything is better than MS-DOS command or NT cmd.
@rem

@rem
@rem This is unfortunate, but we have to ourselves
@rem establish a base %PATH%. We have to
@rem clear whatever our other env configurations
@rem have established, as well as keeping %PATH%
@rem minimal so that 16bit tools work.
@rem

@if "%COMSPEC%" == "Z:\COMMAND.COM" goto :DosBox
@if "%WINDIR%" == "" goto :Dos
@if "%OS%"== "Windows_NT" goto :NT

@rem
@rem UNDONE Win9x
@rem
@set PATH=
set _NT_SYMBOL_PATH=SRV*%SystemDrive%\symbols*\\jay-drive1\public\symbols*http://msdl.microsoft.com/download/symbols
@goto :Dos

:NT
@set PATH=%WINDIR%\system32;%WINDIR%;%WINDIR%\System32\Wbem;%SystemDrive%\bin
@set PATHEXT=.COM;.EXE;.BAT;.CMD
@set PATHEXT=.COM;.EXE;.BAT;.CMD;.VBS;.VBE;.JS;.JSE;.WSF;.WSH
@set PATHEXT=.COM;.EXE;.BAT;.CMD;.VBS;.VBE;.JS;.JSE;.WSF;.WSH;.RB;.RBW
@if exist %SystemDrive%\Python25 (
    @set PATHEXT=%PATHEXT%;.py;.pyw
    @set PATH=%PATH%;%SystemDrive%\Python25
)
@if exist %SystemDrive%\cygwin\bin (
    @set PATH=%PATH%;%SystemDrive%\cygwin\bin
)
if not defined _NT_SYMBOL_PATH (
    set _NT_SYMBOL_PATH=SRV*%SystemDrive%\symbols*http://msdl.microsoft.com/download/symbols
    if exist \\jay-drive1\public\symbols set _NT_SYMBOL_PATH=SRV*%SystemDrive%\symbols*\\jay-drive1\public\symbols*http://msdl.microsoft.com/download/symbols
)
@goto :Common

:DosBox
@set PATH=z:\
@set PATHEXT=
@goto :Dos

:Dos
@call \autoexec
@rem make more room in environment
@set PATHEXT=
@goto :Common

:Common

@rem
@rem The "base" environment consists of roughly:
@rem
@rem PATHEXT=
@rem HOMEDRIVE=
@rem HOMEPATH=
@rem LOGONSERVER=
@rem FP_NO_HOST_CHECK=
@rem
@rem ALLUSERSPROFILE=
@rem APPDATA=
@rem CLIENTNAME=
@rem CommonProgramFiles=
@rem COMPUTERNAME=
@rem ComSpec=
@rem NUMBER_OF_PROCESSORS=
@rem OS=
@rem PROCESSOR_ARCHITECTURE=
@rem PROCESSOR_IDENTIFIER=
@rem PROCESSOR_LEVEL=
@rem PROCESSOR_REVISION=
@rem ProgramFiles=
@rem PROMPT=
@rem SESSIONNAME=
@rem SystemDrive=
@rem SystemRoot=
@rem TEMP=
@rem TMP=
@rem USERDOMAIN=
@rem USERNAME=
@rem USERPROFILE=
@rem windir=

@rem
@rem Clear anything we ever set or any developer tool install
@rem ever sets. This list is to be expanded as more developer
@rem tools are tested.
@rem

@set _BUILDARCH=
@set _CL_=
@set _LINK_=
@set _ML_=
@set _NT_TARGET_VERSION=
@set _NT_TOOLS_VERSION=
@set APPVER=
@set ATL_INC_PATH=
@set AVENGINE=
@set BASEDIR=
@set BASEMAKE=
@set BASH_VERSINFO=
@set BASH_VERSION=
@set BASH=
@set BKOFFICE=
@set BUILD_ALT_DIR=
@set BUILD_DEFAULT_TARGETS=
@set BUILD_DEFAULT=
@set BUILD_MAKE_PROGRAM=
@set BUILD_MULTIPROCESSOR=
@set BUILD=
@set C16_ROOT=
@set C32_ROOT=
@set CLASSPATH=
@set COFFBASE_TXT_FILE=
@set COLORFGBG=
@set COLORTERM=
@set COLUMNS=
@set CPU=
@set CPU=
@set CRT_INC_PATH=
@set CRT_LIB_PATH=
@set CWFolder=
@set DDK_INC_PATH=
@set DDK_LIB_DEST=
@set DDK_LIB_PATH=
@set DDK_TARGET_OS=
@set DDK_VC5_COMPILE=
@set DDKBUILDENV=
@set DDKROOT=
@set DevEnvDir=
@set DIRSTACK=
@set DISPLAY=
@set DJGPP=
@set DRIVER_INC_PATH=
@set DXDDKROOT=
@set DXSDKROOT=
@set EDITOR=
@set EDPATH=
@set EUID=
@set FrameworkDir=
@set FrameworkSDKDir=
@set FrameworkVersion=
@set GROUPS=
@set HALKIT_INC_PATH=
@set HALKIT_LIB_PATH=
@set HELP=
@set HISTFILE=
@set HISTFILESIZE=
@set HISTSIZE=
@set HOME=
@set HOSTNAME=
@set HOSTTYPE=
@set HPCEmulDir=
@set IA64=
@set IEPPP=
@set IFS=
@set IFSKIT_INC_PATH=
@set IFSKIT_LIB_DEST=
@set IFSKIT_LIB_PATH=
@set INCLUDE=
@set INETSDK=
@set INIT=
@set INOCULAN=
@set INPUTRC=
@set LIB=
@set LIBPATH=
@set LINES=
@set LINK_LIB_IGNORE=
@set LM_LICENSE_FILE=
@set MACHTYPE=
@set MAILCHECK=
@set MAKE_MODE=
@set MASM_ROOT=
@set MFC_INCLUDES=
@set MOZ_MSVCVERSION=
@set MOZ_TOOLS=
@set MOZILLABUILD=
@set MOZILLABUILDDRIVE=
@set MOZILLABUILDPATH=
@set MSDevDir=
@set MSSDK=
@set MSTOOLS=
@set MSVC6KEY=
@set MSVC71KEY=
@set MSVC8EXPRESSKEY=
@set MSVC8KEY=
@set MSVCDir=
@set MSVCROOTKEY=
@set MSVCVER=
@set MSYS_MOZBUILD=
@set MSYSTEM=
@set MWCMac68KIncludes=
@set MWCMacPPCIncludes=
@set MWCWinx86Includes=
@set MWMac68KLibraries=
@set MWMac68KLibraryFiles=
@set MWMacMPW68KLibraries=
@set MWMacMPW68KLibraryFiles=
@set MWMacMPWPPCLibraries=
@set MWMacMPWPPCLibraryFiles=
@set MWMacPPCLibraries=
@set MWMacPPCLibraryFiles=
@set MWWinx86Libraries=
@set MWWinx86LibraryFiles=
@set NEW_CRTS=
@set NO_BINPLACE=
@set NODEBUG=
@set NT_UP=
@set NTDBGFILES=
@set NTDEBUG=
@set NTDEBUGTYPE=
@set NTMAKEENV=
@set OAK_INC_PATH=
@set OIVHOME=
@set OLDPWD=
@set OPTERR=
@set OPTIND=
@set PCTCP=
@set PIPESTATUS=
@set PPID=
@set PREFAST_ROOT=
@set PROCESSOR_INC_PATH=
@set PROCESSOR_LIB_PATH=
@set PROJECT_ROOT=
@set PUBLISH_CMD=
@set QTJava=
@set RUBYOPT=
@set SDK_INC_PATH=
@set SDK_LIB_DEST=
@set SDK_LIB_PATH=
@set SDK2003SP1KEY=
@set SDK2003SP2KEY=
@set SDKDIR=
@set SDKROOT=
@set SDKROOTKEY=
@set SHELL=
@set SHLVL=
@set SonicCentral=
@set TARGETOS=
@set TERM=
@set TOOLROOTDIR=
@set UID=
@set VC8EXPRESSDIR=
@set VCINSTALLDIR=
@set VCToolkitInstallDir=
@set VS80COMNTOOLS=
@set VS90COMNTOOLS=
@set VSCOMNTOOLS=
@set VSINSTALLDIR=
@set W2K=
@set WATCOM=
@set WDM_INC_PATH=
@set WIN2K_DDKBUILD=
@set WINDOWID=
@set WPCEmulDir=
@set WPP_CONFIG_PATH=

@Title %COMSPEC% >nul
