@if "%_echo%" == "" @echo off
call "%SystemDrive%\Program Files\Microsoft Platform SDK for Windows Server 2003 R2\setenv.cmd" /X64 /RETAIL
Title Windows Platform SDK AMD64

@rem reset errorlevel
dir > nul
