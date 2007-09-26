@REM #!cmd.exe
@REM $Id$

@if "%_echo%" == "" @echo off

call %~dp0clearenv.cmd
setlocal
call %~dp0sysinfo.cmd || goto :eof
call %~dp0pkginfo.cmd
call %~dp0pkgcmds.cmd

set P=
@REM base libraries
if not "%TARGET%" == "NT386" (
  set P=%P% m3gc-simple
)
call %~dp0pkginfo.cmd syscall_wrappers_exist && (
  if not "%M3GC_SIMPLE%" == "" (
    if not "%TARGET%" == "NT386" (
      set P=%P% m3gc-enhanced
    )
  )
)
set P=%P% m3core
set P=%P% libm3

call %~dp0pkgcmds extract_options %*
call %~dp0pkgcmds map_action %* || goto :eof
call %~dp0pkgcmds add_action_opts %*

call :echo_and_run call %~dp0pkgmap.cmd %OPTIONS% %ADDARGS% -c "%ACTION%" %P%

endlocal
goto :eof

:echo_and_run
setlocal
set x=%*
set x=%x:  = %
set x=%x:  = %
echo %x%
%x%
endlocal
goto :eof
