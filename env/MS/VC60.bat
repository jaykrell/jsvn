@if "%_echo%" == "" @echo off

call \dev2\j\\env\clearenv

rem call "\Program Files\Microsoft Visual Studio\VC98\Bin\vcvars32"
call \msdev\60\vc98\bin\vcvars32

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

Title VC60
