@if "%_echo%" == "" @echo off

@rem
@rem %1 can be x86, m68k, or mppc.
@rem

call \dev2\j\env\clearenv

call \msdev\42\bin\vcvars32 mppc

@rem reset errorlevel
dir > nul

Title VC42 MacPPC
