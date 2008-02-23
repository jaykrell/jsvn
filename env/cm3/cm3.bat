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
@endlocal & call :set_c_and_cm3_path %0 %1 %a%
@goto :eof

:set_c_and_cm3_path
@if exist %~dp1..\Microsoft\%3.cmd @call %~dp1..\Microsoft\%3.cmd
@if exist %~dp1..\Microsoft\%3.bat @call %~dp1..\Microsoft\%3.bat
@if exist %~dp1..\MS\%3.cmd        @call %~dp1..\MS\%3.cmd
@if exist %~dp1..\MS\%3.bat        @call %~dp1..\MS\%3.bat
@if exist %~dp1..\%3.cmd        @call %~dp1..\%3.cmd
@if exist %~dp1..\%3.bat        @call %~dp1..\%3.bat
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

set CM3_ROOT=c:\dev2\cm3.2
set CM3_INSTALL=c:\cm3
set CM3_TARGET=NT386
set CM3_OSTYPE=WIN32
set CM3_GCC_BACKEND=no
set M3CONFIG=%CM3_ROOT%\m3-sys\cminstall\src\config\NT386
set OMIT_GCC=yes

@goto :eof
