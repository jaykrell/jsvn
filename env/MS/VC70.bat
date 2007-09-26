@if "%_echo%" == "" @echo off

call \dev2\j\env\clearenv

call "\Program Files\Microsoft Visual Studio .NET\Common7\Tools\vsvars32"
call \msdev\70\common7\tools\vsvars32

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

Title VC70
