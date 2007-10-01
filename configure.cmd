@call :environment_variable_must_contain_files path cl.exe link.exe fc.exe nmake.exe
@if errorlevel 1 goto :Fail

@call :IsConfigurationUpToDate %0
@if errorlevel 1 goto :reconfigure

@rem @echo configuration is up to date
@del _configure.signature.new
@goto :end

:Fail
	 @echo %0 failing
	 @goto :end

:ClearLastError
    @dir . > nul
	@goto :end

:SetLastError
	@dir _nonexistant.971ffd40-a946-475c-8d79-d2a4d7bb1325 > nul
	goto :end

:reconfigure
    @del _configure.signature 2>nul
    @nmake /nologo /f %~dp0configure.make3 > _configure.make2.new
    @fc _configure.make2 _configure.make2.new >nul 2>nul
    @if errorlevel 1 goto :reconfigure_2

    @goto :reconfigure_2

    @del _configure.make2.new
    @del _configure.signature.new
    @goto :end

:reconfigure_2
    @del _configure.make2      2>nul
    @del _configure.signature  2>nul
    @move _configure.signature.new _configure.signature
    @move _configure.make2.new _configure.make2
    @goto :end

:IsConfigurationUpToDate

    @rem
    @rem If environment or configure itself has changed, out of date.
    @rem
    @rem Print each part of the configuration to .new, with guids between them.
    @rem

    @echo 4a579875-13bc-4f62-973e-763217b94598 > _configure.signature.new
    @set >> _configure.signature.new
    @echo d685ccc7-6847-4f83-a33b-7485dfe4ef67 >> _configure.signature.new
    @type %~dp1configure.cmd >> _configure.signature.new
    @echo 9a4023cb-194a-4895-8042-bcc2ac054b52 >> _configure.signature.new
    @type %~dp1configure.make >> _configure.signature.new
    @echo a35e935e-1581-499e-83d2-b8cdc515e25d >> _configure.signature.new
    @type %~dp1configure.make3 >> _configure.signature.new
    @echo 3f306058-0025-4a19-8b8d-545d7f64453a >> _configure.signature.new

    @rem
    @rem If the signature or the output does not exist, out of date.
    @rem
    @if not exist _configure.signature exit /b 1
    @if not exist _configure.make2 exit /b 1

    @fc _configure.signature.new _configure.signature >nul 2>nul

    @goto :end

:environment_variable_must_contain_files
	@setlocal
	@set a=%1
	@for /f "tokens=*" %%i in ('echo %%%1%%') do @set b=%%i
:environment_variable_must_contain_files_1
	@shift
	@if "%1" == "" (
	  @endlocal
	  @goto :eof
	)
	@if "%~$b:1" == "" (
		@echo %a% does not contain %1
		@endlocal
		@exit /b 1
	)
	@goto :environment_variable_must_contain_files_1

:end
