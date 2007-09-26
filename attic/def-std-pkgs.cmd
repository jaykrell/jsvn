@REM #!cmd.exe
@REM $Id$

@if "%_echo%" == "" @echo off

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
set P=%P% m3core
@REM system / compiler libraries and tools
set P=%P% m3middle
set P=%P% m3quake
set P=%P% m3scanner
set P=%P% m3tools
set P=%P% m3cgcat
set P=%P% m3cggen
@REM not yet tested anywhere
@REM if "%M3GDB%" = "yes" (
@REM   set P=%P% m3gdb
@REM )
set P=%P% m3bundle
if "%M3OSTYPE%" == "WIN32" (
  set P=%P% mklib dll2lib fix_nl libdump
) else if not "%CM3_ALL" == "" (
  set P=%P% mklib dll2lib fix_nl libdump
)
@REM more useful quasi-standard libraries
set P=%P% bitvector
set P=%P% digraph
set P=%P% parseparams
set P=%P% realgeometry
set P=%P% set
set P=%P% slisp
set P=%P% sortedtableextras
set P=%P% table-list
set P=%P% tempfiles
if "%HAVE_TCL%" == "yes" (
  set P=%P% tcl
) else if not "%CM3_ALL" == "" (
  set P=%P% tcl
)
set P=%P% tcp
if "%M3OSTYPE%" == "POSIX" (
  set P=%P% udp
) else if not "%CM3_ALL" == "" (
  set P=%P% udp
)
set P=%P% libsio
set P=%P% libbuf
set P=%P% debug
set P=%P% listfuncs
set P=%P% patternmatching
set P=%P% embutils
set P=%P% m3tk-misc
set P=%P% http
set P=%P% binIO
set P=%P% deepcopy
set P=%P% sgml

@REM some CM3 communication extensions
if "%M3OSTYPE%" == "WIN32" (
  set P=%P% tapi
) else if not "%CM3_ALL" == "" (
  set P=%P% tapi
)
if "%HAVE_SERIAL%" == "yes" (
  set P=%P% serial
) else if not "%CM3_ALL" == "" (
  set P=%P% serial
)

@REM tools
set P=%P% m3tk
set P=%P% mtex
set P=%P% m3totex
set P=%P% m3tohtml
set P=%P% m3scan
set P=%P% m3markup
set P=%P% m3browser
set P=%P% cmpdir
set P=%P% cmpfp
set P=%P% dirfp
set P=%P% uniq
@REM needs lex and yacc or flex and bison
@REM set P=%P% pp

@REM network objects -- distributed programming
set P=%P% netobj
set P=%P% netobjd
set P=%P% stubgen
set P=%P% events
set P=%P% rdwr
set P=%P% sharedobj
set P=%P% sharedobjgen

@REM database packages
set P=%P% odbc
set P=%P% postgres95
set P=%P% db
set P=%P% smalldb
set P=%P% stable
set P=%P% stablegen

@REM the standard graphical user interface: trestle and formsvbt
if not "%M3OSTYPE%" == "WIN32" (
  set P=%P% X11R4
) else if not "%CM3_ALL" == "" (
  set P=%P% X11R4
)
set P=%P% ui
set P=%P% PEX
set P=%P% vbtkit
set P=%P% cmvbt
set P=%P% jvideo
set P=%P% videovbt
set P=%P% web
set P=%P% formsvbtpixmaps
set P=%P% formsvbt
set P=%P% formsview
set P=%P% formsedit
set P=%P% codeview
set P=%P% mg
set P=%P% mgkit
set P=%P% opengl
set P=%P% anim3D
set P=%P% zeus
set P=%P% m3zume

@REM obliq
set P=%P% synloc
set P=%P% synex
set P=%P% metasyn
set P=%P% obliqrt
set P=%P% obliqparse
set P=%P% obliqprint
set P=%P% obliq
set P=%P% obliqlibemb
set P=%P% obliqlibm3
set P=%P% obliqlibui
set P=%P% obliqlibanim
@REM does not compile
@REM set P=%P% obliqlib3D
set P=%P% obliqsrvstd
set P=%P% obliqsrvui
set P=%P% obliqbinmin
set P=%P% obliqbinstd
set P=%P% obliqbinui
set P=%P% obliqbinanim
set P=%P% visualobliq
set P=%P% vocgi
set P=%P% voquery
set P=%P% vorun

@REM more graphics depending on obliq
set P=%P% webvbt

@REM more tools
set P=%P% recordheap
set P=%P% rehearsecode
set P=%P% replayheap
set P=%P% showheap
set P=%P% shownew
if not "%M3OSTYPE%" == "WIN32" (
  set P=%P% showthread
) else if not "%CM3_ALL" == "" (
  set P=%P% showthread
)
@REM showthread needs ThreadEvent, which does not exist on win32

@REM The Juno-2 graphical constraint based editor
if not "%M3OSTYPE%" == "WIN32" (
  set P=%P% pkl-fonts juno-machine juno-compiler juno-app
) else if not "%CM3_ALL" == "" (
  set P=%P% pkl-fonts juno-machine juno-compiler juno-app
)

@REM demo programs
set P=%P% cube
set P=%P% calculator
set P=%P% fisheye
set P=%P% mentor
