Jay Krell
May 15 2004

files missed in recent submission:
  clearenv.cmd

new files since last submission, should be in good shape:
  def-std-pkgs.cmd
  do-cm3-min.cmd
  do-cm3-std.cmd

work in progress, does not work yet:
  install-cm3-compiler.cmd

new file in good shape depending on context
  cm3.cfg
    works with http://msdn.microsoft.com/visualc/vctoolkit2003/
    which lacks msvcrt.lib and win32 .libs like comctl32.lib
      use libcmt.lib instead of msvcrt.lib
    making .pdbs not working
       due to problems with cm3's included .libs
  comctl32.bat
    makes comct32.lib
    look at it, notice it copies it to \cm3\lib, your location might vary
    could use Platform SDK instead

diff.txt
  diffs
   do-cm3-base.cmd
     add goto :eof in case sysinfo.cmd errors
     cleanup via echo_and_run
   do-cm3-core.cmd
     ditto
   do-pkg.cmd
     ditto
   find-packages.cmd
     ditto
   pkgcmds.cmd
     ditto and fix &&
   pkginfo.cmd
     ditto
   pkgmap.cmd
     ditto
   sysinfo.cmd
     require fewer libs, libcmt.lib instead of msvcrt.lib
     allow spaces in %lib% and %include%
     setting of CM3_SYSCALL_WRAPPERS_EXIST, well baked?
