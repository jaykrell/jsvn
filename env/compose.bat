@call :F1 %~dp1 %~n1
@goto :eof
:F1
@call :F2 %1 %~n2 %~x2
@goto :eof
:F2
@setlocal
@set a=%3
@echo call %1%2 %a:~1%
@endlocal & call %1%2 %a:~1%
