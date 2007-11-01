@call :F1 %~dp0. %1
@rem reset errorlevel
dir > nul
@goto :eof

:F1
@call %1\%~n1 %2
@goto :eof
