@REM #!cmd.exe
@REM $Id$

@if "%_echo%" == "" @echo off

setlocal
call %~dp0sysinfo.cmd || goto :eof


set FRONTEND=%INSTALLROOT%\bin\cm3
set BACKEND=%INSTALLROOT%\bin\cm3cg
set FRONTEND_SRC=%ROOT%\m3-sys\cm3\%TARGET%\cm3
set BACKEND_SRC=%ROOT%\m3-sys\m3cc\%TARGET%\cm3cg

goto :main

:exit_if
{
  if [ "${NOACTION}" = yes ] ; then
    echo "error ignored due to -n" 1>&2
  else
    exit "$1"
  fi
}
goto :eof

:do_cp
{
  echo cp "$1" "$2"
  if [ "${NOACTION}" != yes ] ; then
    if cp "$1" "$2"; then
      true
    else
      exit_if 1
    fi
  fi
}
goto :eof

:cp_if
{
  if [ ! -r "$1" ] ; then
    echo "cp_if: source does not exist: $1" 1>&2 
    exit_if 1
  fi
  if [ -r "$2" ] ; then
    # destination exists
    if cmp "$1" "$2" >\dev/null 2>&1; then
      echo "cp_if: $1 and $2 identical" 1>&2
      true
    else
      if [ -w "$2" ] ; then
        do_cp "$1" "$2"
      else
        echo "cp_if: cannot write $2" 1>&2
        exit_if 1
      fi
    fi
  else
    do_cp "$1" "$2"
  fi
}
goto :eof

:getversion
cm3 -version || goto :eof
for /f "tokens=5" %%i in ('cm3 -version ^| findstr version') do echo %%i
goto :eof

:install_local_as_version
call :capture_output CM3VERSION "call :getversion"
set FRONTEND_CM3VERSION=%FRONTEND%-%CM3VERSION%
set BACKEND_CM3VERSION=%BACKEND%-%CM3VERSION%
set FRONTEND_DEST=%FRONTEND_CM3VERSION%
set BACKEND_DEST=%BACKEND_CM3VERSION%
call :cp_if %FRONTEND_SRC% %FRONTEND_DEST%
if "%GCC_BACKEND%" == "yes" (
    call :cp_if %BACKEND_SRC% %BACKEND_DEST%
)
goto :eof

:backup_old
call :capture_output OLDCM3VERSION "call :getversion %FRONTEND%"
call :cp_if %FRONTEND% %FRONTEND%-%OLDCM3VERSION%
if "%GCC_BACKEND%" == "yes" (
    call :cp_if %BACKEND% %BACKEND%-%OLDCM3VERSION%
)
goto :eof

:rm_curent
{
  if [ "${NOACTION}" != yes ] ; then
    rm -f "${FRONTEND}"
    if [ "${GCC_BACKEND}" = yes ] ; then
      rm -f "${BACKEND}"
    fi
  fi
}
goto :eof

:cp_version

{
  cp_if "${FRONTEND_CM3VERSION}" "${FRONTEND}"
  if [ "${GCC_BACKEND}" = yes ] ; then
    cp_if "${BACKEND_CM3VERSION}" "${BACKEND}"
  fi
}
goto :eof

:upgrade
call :backup_old
call :install_local_as_version
call :rm_curent
call :cp_version
goto :eof

:main
if [ "x${1}" = "x-n" ] ; then
  NOACTION=yes
  shift
fi

if [ "x${1}" = "xupgrade" ] ; then
  upgrade
elif [ "x${1}" = "xrestore" ] ; then
  if [ -z "$2" ] ; then
    echo "please specify a version" 1>&2 
    exit 1
  fi
  CM3VERSION="$2"
  FRONTEND_CM3VERSION="${FRONTEND}-${CM3VERSION}"
  BACKEND_CM3VERSION="${BACKEND}-${CM3VERSION}"
  cp_version
elif [ "x${1}" = "xnewversion" ] ; then
  install_local_as_version
elif [ "x${1}" = "xbackup" ] ; then
  backup_old
elif [ "x${1}" = "x" ] ; then
  usage
else
  echo "unknown command: $1" 1>&2
  exit 1
fi

goto :eof

:capture_output
for /f %%i in ('%2') do set %1=%%i
goto :eof
