@rem
@rem Jay Krell
@rem December 2006
@rem

@if "%1" == "" (
    call :set_cm3_env %0
    goto :eof
)
@setlocal
@set a=%~n1
@set a=%a:cm3.=%
@endlocal & call :set_vc_and_cm3_path %0 %1 %a%
@goto :eof

:set_vc_and_cm3_path
@if exist %~dp1..\Microsoft\%3.cmd @call %~dp1..\Microsoft\%3.cmd
@if exist %~dp1..\Microsoft\%3.bat @call %~dp1..\Microsoft\%3.bat
@if exist %~dp1..\MS\%3.cmd        @call %~dp1..\MS\%3.cmd
@if exist %~dp1..\MS\%3.bat        @call %~dp1..\MS\%3.bat
@echo on
@call :set_cm3_env %2
@Title cm3/%3
@goto :eof

:set_cm3_env
@rem set PATH=%~d1\%~n1\bin;%PATH%
@rem set LIB=%~d1\%~n1\lib;%Lib%
set PATH=%~d1\cm3\bin;%PATH%
set LIB=%~d1\cm3\lib;%Lib%
set INCLUDE=%INCLUDE%
set CVS_RSH=ssh
set CVSROOT=:ext:jkrell@m3.elegosoft.com:/usr/cvs
@goto :eof
