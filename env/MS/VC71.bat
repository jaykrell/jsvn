@if "%_echo%" == "" @echo off

call \dev2\j\env\clearenv

call "\Program Files\Microsoft Platform SDK for Windows Server 2003 R2\SetEnv"
call \msdev\71\vcvars32

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

Title VC71
