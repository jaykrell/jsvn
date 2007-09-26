@REM #!cmd.exe
@REM $Id$

@if "%_echo%" == "" @echo off

for %%i in (ACTION ARGS BUILDGLOBAL BUILDLOCAL CLEANGLOBAL       ) do set %%i=
for %%i in (CLEANLOCAL CM3 CM3BINSEARCHPATH CM3LIBSEARCHPATH     ) do set %%i=
for %%i in (CM3ROOT CM3VERSION EXE GCC_BACKEND GREP IGNORE_MISS  ) do set %%i=
for %%i in (INSTALLROOT M3BUILD M3GDB M3OSTYPE M3SHIP PKG_ACTION ) do set %%i=
for %%i in (PKGS PKGSDB REALCLEAN ROOT SCRIPTS SYSINFO_DONE      ) do set %%i=
for %%i in (SHIP SL SYSLIBDIR SYSLIBS TAR TARGET TMPDIR          ) do set %%i=
for %%i in (CM3_SYSCALL_WRAPPERS_EXIST                           ) do set %%i=

