@if "%_echo%" == "" @echo off

setlocal

call \Env\ClearEnv

call :F1 Microsoft\VC20 || exit /b 1
call :F1 Microsoft\VC40 || exit /b 1
call :F1 Microsoft\VC41 || exit /b 1
call :F1 Microsoft\VC50 || exit /b 1
rem call :F1 Microsoft\VC60 || exit /b 1
call :F1 Microsoft\VC70 || exit /b 1
call :F1 Microsoft\VC71 || exit /b 1
call :F1 Microsoft\VC80 || exit /b 1

@rem ----------------------------------------------------------------------

Title %COMSPEC%
echo Success
goto :End

@rem ----------------------------------------------------------------------
:F1
@rem ----------------------------------------------------------------------

setlocal
echo %~n1
call \Env\%1 > nul
call configure
endlocal
del _configure.make2.%~n1
del _configure.signature.%~n1
ren _configure.make2     _configure.make2.%~n1
ren _configure.signature _configure.signature.%~n1
type _configure.make2.%~n1
goto :End

@rem ----------------------------------------------------------------------

:End
