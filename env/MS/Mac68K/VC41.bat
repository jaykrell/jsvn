@if "%_echo%" == "" @echo off

@rem
@rem %1 can be x86, m68k, or mppc.
@rem

call \dev2\j\env\clearenv

call \msdev\41\bin\vcvars32 m68k

@rem reset errorlevel
dir > nul

Title VC41 Mac68K
