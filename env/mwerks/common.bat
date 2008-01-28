@if "%_echo%" == "" @echo off

rem echo Usage:  cwenv.bat [-help] [-quiet] [-k6] [-dll] [-cross] [-ms] (order counts!)

call \dev2\j\env\clearenv

set CWFolder=%SystemDrive%\mwerks\%1

call "%CWFolder%\Other Metrowerks Tools\Command Line Tools\cwenv.bat" -quiet -cross %2 %3 %4 %5 %6 %7 %8 %9

@rem reset errorlevel
dir > nul

Title Metrowerks %1
