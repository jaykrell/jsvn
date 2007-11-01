@if "%_echo%" == "" @echo off
echo on
call "C:\Program Files\Microsoft Platform SDK for Windows Server 2003 R2\setenv.cmd" /SRV64 /RETAIL
Title Windows Platform SDK IA64

@rem reset errorlevel
dir > nul
