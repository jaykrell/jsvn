@rem
@rem Jay Krell
@rem September 2007
@rem based on cm3.bat (ie: another one composable with ms)
@rem

@if "%_echo%" == "" @echo off

call \dev2\j\env\clearenv

@if "%1" == "" (
    call :set_moz_env %0
    goto :eof
)
@setlocal
@set a=%~n1
@set a=%a:moz.=%
@endlocal & call :set_vc_and_moz_path %0 %1 %a%
@goto :eof

:set_vc_and_moz_path
@if exist %~dp1..\Microsoft\%3.cmd @call %~dp1..\Microsoft\%3.cmd
@if exist %~dp1..\Microsoft\%3.bat @call %~dp1..\Microsoft\%3.bat
@if exist %~dp1..\MS\%3.cmd        @call %~dp1..\MS\%3.cmd
@if exist %~dp1..\MS\%3.bat        @call %~dp1..\MS\%3.bat
@echo on
@call :set_moz_env %2
@Title moz/%3
@goto :eof

:set_moz_env

set MOZILLABUILDDRIVE=%~d0%
set MOZILLABUILDPATH=\mozilla-build

set MOZ_MSVCVERSION=8
set MOZILLABUILD=%MOZILLABUILDDRIVE%%MOZILLABUILDPATH%
set MOZ_MSVCVERSION=8
set MOZ_TOOLS=%MOZILLABUILD%\moztools

set LIB=%LIB%;%MOZILLABUILD%\atlthunk_compat
set PATH=%PATH%;%MOZ_TOOLS%\bin

@goto :eof
