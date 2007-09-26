@if "%_echo%" == "" @echo off

@rem
@rem %1 can be x86, m68k, or mppc.
@rem

call \dev2\j\env\clearenv

call \msdev\40\bin\vcvars32 %1

@set DevEnvDir=
@set FrameworkDir=
@set FrameworkSDKDir=
@set FrameworkVersion=
@set MSVCDir=
@set LIBPATH=
@set VCINSTALLDIR=
@set VSINSTALLDIR=

@rem reset errorlevel
dir > nul

Title VC40
