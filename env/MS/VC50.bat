@if "%_echo%" == "" @echo off

call \dev2\j\env\clearenv

call \msdev\50\VC\bin\vcvars32

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

Title VC50
