#! /usr/bin/env python

#
# Given a working system <platform1>, <platform2> sysroot:
#   - build current native tools
#   - build current cross tools
#   - cross build native tools
#
# sysroot is actually copying the file system from one machine to
# another, though heavily subsetted, e.g. /usr/include, /lib, /usr/lib.
#
# Almost everything below is editable. One size doesn't fit all.
#

import os
import sys
import re

ObjRoot = "/obj/gcc.7"

if ("gccrel" in sys.argv) == ("gccsvn" in sys.argv):
    print("ERROR: must specify either gccrel or gccsvn")
    sys.exit(1)

if "gccrel" in sys.argv:
    Source = "/src/gccrel"
    GccVersion = "4.3.2"

if "gccsvn" in sys.argv:
    Source = "/src/gccsvn"
    GccVersion = "4.4.0"

#
# use canonical names including version
#  - sometimes they get further canonicalized, sometimes not
#  - libgcc wants a version in Platform2
#
Build = "i686-pc-cygwin"

Prefix = "/usr/local"
# Prefix = "/usr"

#
# Check for some basic utilities.
# file
# make; GNU probably required?
# sed
# gcc; can another cc work?
#   One reason for this exercise was due to trouble building gcc with Sun cc.
# sh
# bash?
# mkdir (Python builtin doesn't work, related to Cygwin symlinks?)
# rm (could use Python builtin?)
#


#
# /usr/<local>/<Platform2>/sys-root must be prepared ahead of time
# with a /usr/include and /usr/local or a subset thereof from Platform2.
# Resulting in /usr/<local>/<Platform2>/sys-root/usr/include, /usr/<local>/<Platform2>/sys-root/usr/lib
# It might also be useful to link /usr/<local>/<Platform2>/sys-include to /usr/<local>/<Platform2>/sys-root/usr/include.
#

ConfigCommon = " "

#
# Sometimes it helps to specify -build explicitly, but currently we don't hit these.
# In particular, if you use a more central config.cache, -build is sniffed varyingly
# as i686-pc-cygwin and athlon64-pc-cygwin. Specifying it prevents the sniffing
# and it varying.
#

# ConfigCommon += " -build " + Platform1 + " "
ConfigCommon += " -verbose "

ConfigCommon += " -prefix=" + Prefix + " " 

#
# use cygwin's directory structure
# for one thing, merge libexec and lib -- fewer directories
#
ConfigCommon += " -exec-prefix=" + Prefix + " " 
ConfigCommon += " -libdir=" + Prefix + "/lib "
ConfigCommon += " -libexecdir=" + Prefix + "/lib "
ConfigCommon += " -mandir=" + Prefix + "/share/man "
ConfigCommon += " -infodir=" + Prefix + "/share/info "

# -sysconfdir=/etc

# -enable-languages=c,c++,fortran,java,objc,obj-c++ 
# -disable-nls
# -without-included-gettext
# -enable-version-specific-runtime-libs
# -without-x
# -enable-libgcj
# -disable-java-awt
# -with-system-zlib
# -enable-interpreter
# -disable-libgcj-debug
# -enable-threads=posix
# -enable-java-gc=boehm
# -disable-win32-registry
# -enable-sjlj-exceptions
# -enable-hash-synchronization
# -enable-libstdcxx-debug


#
# Keep everything in English, and don't waste time otherwise.
#
ConfigCommon += " -disable-nls "
ConfigCommon += " -disable-intl "
ConfigCommon += " -disable-po "

ConfigCommon += " -with-gnu-as "
ConfigCommon += " -with-gnu-ld "

#
# We already build and install the necessary compilers. Don't build them again.
#
ConfigCommon += " -disable-bootstrap "

#
# Cygwin defaults -enable-threads to off, but -enable-threads works, so enable it explicitly.
# However we'll probably have to remove this for DJGPP.
#
# ConfigCommon += " -enable-threads "

#
# Does this make things better on Solaris?
#
ConfigCommon += " -enable-rpath "

#
# -enable-cld is a compatibility deoptimization for Linux/x86 and possibly other x86/AMD64 operating systems.
#
ConfigCommon += " -enable-cld "

#
# Cygwin uses this. It sounds good.
#
ConfigCommon += " -enable-version-specific-runtime-libs "

#
# "Checking" reportedly is a significant slowdown, and rarely finds any problems.
#
ConfigCommon += " -disable-checking "

#
# On some platforms, enable targeting multiple targets with one toolset, typically
# for 32bit/64bit pairs like on PowerPC, SPARC, and x86.
# This also appears to enable gas/ld to support "everthing".
#
# TBD: breaks bfd, binutils, gas, ld
#
#ConfigCommon += " -enable-targets=all "

#
# Cygwin uses this. It sounds good.
#
ConfigCommon += " -disable-win32-registry "

#
# Similar to -enable-targets=all, for 32bit binutils.
#
ConfigCommon += " -enable-64-bit-bfd "

#
# This is a nice speed up, but it might take away ability for 32 bit and 64 bit
# to target each other, which is maybe ok, that support can be confusing,
# prone to not work, and not very valuable.
#
#ConfigCommon += " -disable-multilib "

#
# random speeds ups, some people will want these
#
ConfigCommon += " -disable-libgomp "
ConfigCommon += " -disable-libssp "

#
# This is probably a losing battle, but for now we use identical
# configure command for each package. At some point, there are probably
# clashing options or perhaps rejection of invalid options, however
# the second seems unlikely, given that most options just set
# sh variables that later configure code can either use or ignore,
# usually ignore.
#

ConfigCommon = re.sub(" +", " ", ConfigCommon)


# not yet used
#TargetDjgppEnv = "ac_cv_func_shl_load=no"
#TargetDjgppEnv += " ac_cv_func_mmap_dev_zero=no"
#TargetDjgppEnv += " lt_cv_sys_max_cmd_len=12000
#TargetDjgppEnv += " ac_cv_prog_LN_S='cp -p'
#TargetDjgppEnv += " ac_setrlimit=no


def Run(Directory, Command):

    Command = re.sub("  +", " ", Command)

    sys.stderr.flush()
    sys.stdout.flush()

    CommandToPrint = Command
    IgnoreError = False

    while len(Command) != 0 and (Command[0] == "@" or Command[0] == "-"):
        if Command[0] == '@':
            CommandToPrint = None
        if Command[0] == '-':
            IgnoreError = True
        Command = Command[1:]

    if CommandToPrint:
        if Directory != ".":
            print("cd " + Directory + " && " + CommandToPrint)
        else:
            print(CommandToPrint)

    PreviousDirectory = os.getcwd()
    os.chdir(Directory)

    ExitCode = 0
    if os.name == "nt":
        Command = "sh -c \"" + Command + "\""

    sys.stderr.flush()
    sys.stdout.flush()

    ExitCode = os.system(Command)
    os.chdir(PreviousDirectory)

    sys.stderr.flush()
    sys.stdout.flush()

    if not IgnoreError:
        if ExitCode != 0:
            sys.exit(ExitCode)

    return True


def CreateDirectories(a):
    if not os.path.isdir(a):
        os.makedirs(a)

#
# I have recoded my archives to tar+lzma = .tlz.
# Probe for .tar.gz, .tar.bz2, .tar.lzma, .tgz, .tbz, .tlz.
# Given gcc-1.2.3 we should also probe for gcc-1.23 and gcc123.
# We should also support .zip, and try to support the DJGPP names.
#
def Extract(Directory, MarkerDirectory, File):

    #
    # Make these more portable by running bzcat, gzcat, etc. directly?
    # Modern GNU tar has built-in support for gzip and bzip2.
    # Even the -z and -j switches are not needed.
    #

    if os.path.isdir(MarkerDirectory):
        return

    CreateDirectories(Directory);
    for ext in [".tar.gz", ".tgz"]:
        if os.path.exists(File + ext):
            Run(Directory, "tar --strip-components=1 -zxf " + File + ext)
            return

    for ext in [".tar.bz2", ".tbz"]:
        if os.path.exists(File + ext):
            Run(Directory, "tar --strip-components=1 -jxf " + File + ext)
            return

    #
    # lzma produces significantly smaller results than bzip2, and faster.
    #

    for ext in [".tlz", ".tar.lzma"]:
        if os.path.exists(File + ext):
            Run(Directory, "tar --strip-components=1 --lzma -xf " + File + ext)
            return

    Run(Directory, "tar --strip-components=1 -xf " + File)

#
# /obj and /src are actually symlinks to /d/obj, /d/src
# /d => /cygdrive/d
# Thus we do not want to rm -rf /obj /src.
#

#
# extract source -- note we carefully extract into a "combined" tree
#

#
# cygwin and binutils must precede gcc so that gcc replaces common files
#

if "cygwin" in sys.argv:
    Extract(Source, Source + "/winsup", "/net/distfiles/" + "cygwin-src-20080912")

if "binutils" in sys.argv:
    Extract(Source, Source + "/binutils", "/net/distfiles/" + "binutils-2.18")

if "gccrel" in sys.argv:
    Extract(Source, Source + "/gcc", "/net/distfiles/" + "gcc-4.3.2")

if "gccsvn" in sys.argv:
    #
    # Where there is no overlap with binutils, use /d for perf.
    # Where is overlap with binutils, don't use /d for correctness.
    #
    Run(".", "xcopy /qeyid " + "/dev2/gcc /src/gccsvn".replace("/", "\\\\"))

    # non recursive at the root
    Run(".", "xcopy /qyi " + "/dev2/gcc /src/gccsvn".replace("/", "\\\\"))

    for a in ["libiberty", "config", "include", "intl"]:
        Run(".", "xcopy /qyi " + ("/dev2/gcc/" + a + " /src/gccsvn/" + a).replace("/", "\\\\"))

if "gmp" in sys.argv:
    Extract(Source + "/gmp", Source + "/gmp", "/net/distfiles/" + "gmp-4.2.3")
    Extract(Source + "/mpfr", Source + "/mpfr", "/net/distfiles/" + "mpfr-2.3.1")

def AddLinesToFile(LinesToAdd, FilePath):
    LinesToAdd = dict().fromkeys(LinesToAdd)
    ExistingLines = dict().fromkeys(file(FilePath).readlines())
    for i in ExistingLines.keys():
        LinesToAdd.pop(i, None)
    if len(LinesToAdd) != 0:
        file(FilePath, "a").writelines(LinesToAdd.keys())

def ChangeLineInFile(From, To, FilePath):
    Changed = False
    NewLines = [ ]
    OldLines = file(FilePath).readlines()
    for Line in OldLines:
        if Line == From:
            Changed = True
            Line = To
        NewLines += Line
    if Changed:
        file(FilePath, "w").writelines(NewLines)

def AddLineAfterLine(First, Second, FilePath):
    Changed = False
    NewLines = [ ]
    OldLines = file(FilePath).readlines()
    for Line in OldLines:
        if Line == First:
            Changed = True
            NewLines += First
            Line = Second
        NewLines += Line
    if Changed:
        file(FilePath, "w").writelines(NewLines)

def AddLineBeforeLine(First, Second, FilePath):
    Changed = False
    NewLines = [ ]
    OldLines = file(FilePath).readlines()
    for Line in OldLines:
        if Line == First:
            return
        if Line == Second:
            Changed = True
            NewLines += First
        NewLines += Line
    if Changed:
        file(FilePath, "w").writelines(NewLines)

#
# gcc needs a very large stack to avoid crashing for small source files such
# as the 3,739 line libjava/classpath/gnu/javax/swing/text/html/parser/HTML_401F.java
#
# This is known to be broken and fixed by this for Cygwin.
# It is probably needed for more platforms.
#
# This is needed for 4.3.1.
# The patch has not been applied for 4.3.2 and is most likely
# needed there too.
#
AddLinesToFile(["LDFLAGS += -Wl,--stack,8388608\n"], Source + "/config/mh-cygwin")
AddLinesToFile(["LDFLAGS += -Wl,--stack,8388608\n", "CFLAGS += -D__USE_MINGW_ACCESS\n"], Source + "/config/mh-mingw")

#
# /src/gcc/libiberty/strsignal.c:408: error: conflicting types for 'strsignal'
#   const char *
#   strsignal (int signo)
#
# /src/gcc/newlib/libc/include/string.h:79: error: previous declaration of 'strsignal' was here
#   char  *_EXFUN(strsignal, (int __signo));
#
# make[1]: Leaving directory `/obj/gcc.1/i686-pc-cygwin/i686-pc-cygwin/i686-pc-cygwin/libiberty'
#
# and:
#   char *
#   /src/cygwin-snapshot-20080822-1/newlib/libc/sys/linux/strsignal.c(43):strsignal (int sig)
#   extern "C" char *
#   /src/cygwin-snapshot-20080822-1/winsup/cygwin/strsig.cc(77):strsignal (int signo)
#
# appears to be a autoconfiguration problem?
#
# /src/gcc/libiberty/configure:
#
#  *-*-cygwin*)
#    # The Cygwin library actually uses a couple of files from
#    # libiberty when it is built.  If we are building a native
#    # Cygwin, and we run the tests, we will appear to have these
#    # files.  However, when we go on to build winsup, we will wind up
#    # with a library which does not have the files, since they should
#    # have come from libiberty.
#
#    # We handle this by removing the functions the winsup library
#    # provides from our shell variables, so that they appear to be
#    # missing.
#
#    # DJ - only if we're *building* cygwin, not just building *with* cygwin
#
#    if test -n "${with_target_subdir}"
#    then
#      funcs="`echo $funcs | sed -e 's/random//'`"
#      case $LIBOBJS in
#    "random.$ac_objext"   | \
#  *" random.$ac_objext"   | \
#    "random.$ac_objext "* | \
#  *" random.$ac_objext "* ) ;;
#  *) LIBOBJS="$LIBOBJS random.$ac_objext" ;;
#esac
#
#      vars="`echo $vars | sed -e 's/sys_siglist//'`"
#      checkfuncs="`echo $checkfuncs | sed -e 's/strsignal//' -e 's/psignal//'`"
#    fi
#    ;;
#
# Cygwin got its own strsignal back in 2004, so libiberty should no longer provide it.
#  That is, it should let autoconfiguration work.
# http://cygwin.com/cgi-bin/cvsweb.cgi/src/winsup/cygwin/strsig.cc?cvsroot=src
# http://cygwin.com/cgi-bin/cvsweb.cgi/src/winsup/cygwin/Makefile.in.diff?r1=1.153&r2=1.154&cvsroot=src
# http://gcc.gnu.org/svn/gcc/trunk/libiberty/configure.ac
#
# < checkfuncs="`echo $checkfuncs | sed -e 's/strsignal//' -e 's/psignal//'`"
# > checkfuncs="`echo $checkfuncs | sed -e 's/psignal//'`"
#
for File in [Source + "/libiberty/configure", Source + "/libiberty/configure.ac"]:
    ChangeLineInFile("      checkfuncs=\"`echo $checkfuncs | sed -e 's/strsignal//' -e 's/psignal//'`\"\n",
                     "      checkfuncs=\"`echo $checkfuncs | sed -e 's/psignal//'`\"\n",
                     File)

#
# But no! That is all just dead code.
# config.log jumps from 
# configure:4938: checking for pid_t
# ..
# configure:4992: result: yes
# to
# configure:8538: checking for stdlib.h
#
# It is all skipped because
# configure.ac:362: if test "x" = "y"; then
# configure:5068: if test "x" = "y"; then
#
# Uh, no. Because of this line:
#
# configure.ac 511 or 570?: if test -z "${setobjs}"; then
# configure:6027 or 6165?
#
# $checkfuncs is dead. $funcs is alive.
# This change should perhaps be conditionalized on platform being cygwin.
# But autoconf just works, right?
#
    #AddLineAfterLine("funcs=\"$funcs waitpid\"\n",
    #                 "funcs=\"$funcs strsignal\"\n",
    #                 File)

#
# Forget it, just do this:
#
AddLineAfterLine("#define HAVE_SYS_NERR 1\n",
                 "#ifdef __CYGWIN__\n#define HAVE_STRSIGNAL 1\n#endif\n",
                 Source + "/libiberty/configure")

AddLineAfterLine("AC_DEFINE(HAVE_SYS_NERR)\n",
                 "AC_DEFINE(HAVE_STRSIGNAL)\n",
                 Source + "/libiberty/configure.ac")
#
# NOTE this isn't what rebuilding from configure.ac will get you, but
# it is close enough. There are two occurences of #define HAVE_SYS_NERR 1,
# one is in the dead code, like 5675, guarded by if x = y. really this time,
# followed by HAVE_SYS_SIGLIST. The other is in a Cygwin-specific lump,
# line 6021, not dead, and what we want to hit (it also applies to mingwin;
# will that hurt us? We'll find out much later. Yes, it appears likely.
# Therefore the #ifdef __CYGWIN__, or #ifndef __MINGW32__.)
# So the right fix to configure.ac will include breaking up the switch on platform.
#


if "cygwin" in sys.argv:
#
# merged cygwin (winsup+newlib) tree with gcc tree
# 
# configure -build i686-pc-cygwin -host -i686-pc-cygwin -target i686-pc-mingw32
# jay@jay-win9 /obj/gcc.1/i686-pc-cygwin/i686-pc-cygwin/i686-pc-cygwin/winsup/mingw
# $ make
# /obj/gcc.1/i686-pc-cygwin/i686-pc-cygwin/./gcc/xgcc -nostdinc -c -D__CRTDLL__ -U
# __MSVCRT__ -g -g   -I/src/gcc/winsup/mingw/include -I/src/gcc/winsup/mingw/../in
# clude -nostdinc -iwithprefixbefore include -I /src/gcc/winsup/mingw/../w32api/in
# clude -mno-cygwin /src/gcc/winsup/mingw/crt1.c -o crt1.o
# xgcc: error trying to exec 'cc1': execvp: No such file or directory
# make: *** [crt1.o] Error 1
# 
# The problem is that in winsup/mingw/Makefile, CC's -B and -L options are all
# removed, in order to avoid picking up cygwin files. This code:
# 
# CC := @CC@
# override CC := ${filter-out -L% -B%,${shell echo $(CC) | sed -e 's%\(-isystem\|-iwithprefixbefore\)  *[^ ]*\( \|$$\)% %g'}}
# # FIXME: Which is it, CC or CC_FOR_TARGET?
# CC_FOR_TARGET = $(CC)
# AS_FOR_TARGET = $(AS)
# 
# This is too aggressive.
# An easy fix is to add -B../../../gcc to the end after the removals.
# The real point is to add xgcc's directory to -B.
#
#ChangeLineInFile("override CC := ${filter-out -L% -B%,${shell echo $(CC) | sed -e 's%\(-isystem\|-iwithprefixbefore\)  *[^ ]*\( \|$$\)% %g'}}\n",
#                 "override CC := ${filter-out -L% -B%,${shell echo $(CC) | sed -e 's%\(-isystem\|-iwithprefixbefore\)  *[^ ]*\( \|$$\)% %g'}} -B../../../gcc -B../../../../gcc\n",
#                 Source + "/winsup/mingw/Makefile.in")
#
#
# Here is a better fix:
#
    ChangeLineInFile("override CC := ${filter-out -L% -B%,${shell echo $(CC) | sed -e 's%\(-isystem\|-iwithprefixbefore\)  *[^ ]*\( \|$$\)% %g'}}\n",
"""\
#
# if target contains "cygwin", then remove from CC all -L, -B, -system, -withprefixbefore options,
# EXCEPT for the first -B option, if it is the second word of CC.
# CC is typically like CC := /obj/gcc.4/./gcc/xgcc -B/obj/gcc.4/./gcc/ ...
# and if that first -B option is omitted, then:
#   make[3]: Entering directory `/obj/gcc.4/i686-pc-cygwin/winsup/mingw'
#   /obj/gcc.4/./gcc/xgcc -nostdinc -c -D__CRTDLL__ -U__MSVCRT__ -O2 -g -g -O2   -I/src/gcc/winsup/mingw/include -I/src/gcc/winsup/mingw/../include -nostdinc -iwithprefixbefore include -I /src/gcc/winsup/mingw/../w32api/include -mno-cygwin /src/gcc/winsup/mingw/crt1.c -o crt1.o
#   xgcc: error trying to exec 'cc1': execvp: No such file or directory
#
# We want instead:
#   /obj/gcc.4/./gcc/xgcc -B/obj/gcc.4/./gcc/ -nostdinc -c -D__CRTDLL__ -U__MSVCRT__ -O2 -g -g -O2   -I/src/gcc/winsup/mingw/include -I/src/gcc/winsup/mingw/../include -nostdinc -iwithprefixbefore include -I /src/gcc/winsup/mingw/../w32api/include -mno-cygwin /src/gcc/winsup/mingw/crt1.c -o crt1.o
#
# Another good implementation would be that if the first word of CC ends in "./gcc/xgcc", then
# add -B of the first word's dir.
#
# Yet another very good implementation would be if realpath(second word, without the -B) + /xgcc == realpath(first word),
# then preserve the second word.
#
# It does not appear one can check for string equality.
# Therefore, we use findstring(a,b) and findstr(b,a) to imply a == b.
# And since findstring and "and" return the input non-empty string for a true output, the result of and is what we append.
#
override CC := ${filter-out -L% -B%,${shell echo $(CC) | sed -e 's%\(-isystem\|-iwithprefixbefore\)  *[^ ]*\( \|$$\)% %g'}} \\
 ${and ${findstring ${firstword ${filter -B%,$(CC)}},${word 2,$(CC)}},${findstring ${word 2,$(CC)},${firstword ${filter -B%,$(CC)}}}}
""",
                Source + "/winsup/mingw/Makefile.in")

#
# In file included from /src/gcc/winsup/cygwin/dcrt0.cc:24:
# /src/gcc/winsup/cygwin/fhandler.h:545: error: conflicting type attributes specified for 'virtual void fhandler_pipe::raw_read(void*, size_t&)'
# /src/gcc/winsup/cygwin/fhandler.h:344: error:   overriding 'virtual void fhandler_base::raw_read(void*, size_t&)'
#
# This appears to be an optimization to make raw_read's calling convention match that of what it "just" calls.
# Either undo that, remove __stdcall, or apply it all of the raw_reads.
# Here I remove it.
#
    ChangeLineInFile("  void __stdcall raw_read (void *ptr, size_t& len);\n",
                     "  void raw_read (void *ptr, size_t& len);\n",
                     Source + "/winsup/cygwin/fhandler.h")

#
# /src/gcc/winsup/cygwin/dtable.cc: In function 'bool handle_to_fn(void*, char*)':
# /src/gcc/winsup/cygwin/dtable.cc:973: error: jump to label 'unknown'
# /src/gcc/winsup/cygwin/dtable.cc:874: error:   from here
# /src/gcc/winsup/cygwin/dtable.cc:878: error:   crosses initialization of 'size_t w32len'
# /src/gcc/winsup/cygwin/dtable.cc:877: error:   crosses initialization of 'WCHAR* w32'
# /src/gcc/winsup/cygwin/dtable.cc:973: error: jump to label 'unknown'
# /src/gcc/winsup/cygwin/dtable.cc:867: error:   from here
# /src/gcc/winsup/cygwin/dtable.cc:878: error:   crosses initialization of 'size_t w32len'
# /src/gcc/winsup/cygwin/dtable.cc:877: error:   crosses initialization of 'WCHAR* w32'
# /src/gcc/winsup/cygwin/dtable.cc:973: error: jump to label 'unknown'
# /src/gcc/winsup/cygwin/dtable.cc:858: error:   from here
# /src/gcc/winsup/cygwin/dtable.cc:878: error:   crosses initialization of 'size_t w32len'
# /src/gcc/winsup/cygwin/dtable.cc:877: error:   crosses initialization of 'WCHAR* w32'
# /src/gcc/winsup/cygwin/dtable.cc:862: error:   crosses initialization of 'NTSTATUS res'
# /src/gcc/winsup/cygwin/dtable.cc:861: error:   crosses initialization of 'OBJECT_NAME_INFORMATION* ntfn'
#
    ChangeLineInFile("  WCHAR *w32 = ntfn->Name.Buffer;\n",
                     "  WCHAR *w32;\n  w32 = ntfn->Name.Buffer;\n",
                     Source + "/winsup/cygwin/dtable.cc")
    ChangeLineInFile("  size_t w32len = ntfn->Name.Length / sizeof (WCHAR);\n",
                     "  size_t w32len;\n  w32len = ntfn->Name.Length / sizeof (WCHAR);\n",
                     Source + "/winsup/cygwin/dtable.cc")
    ChangeLineInFile("  OBJECT_NAME_INFORMATION *ntfn = (OBJECT_NAME_INFORMATION *) alloca (len + sizeof (WCHAR));\n",
                     "  OBJECT_NAME_INFORMATION *ntfn;\n  ntfn = (OBJECT_NAME_INFORMATION *) alloca (len + sizeof (WCHAR));\n",
                     Source + "/winsup/cygwin/dtable.cc")
    ChangeLineInFile("  NTSTATUS res = NtQueryObject (h, ObjectNameInformation, ntfn, len, NULL);\n",
                     "  NTSTATUS res;\n  res = NtQueryObject (h, ObjectNameInformation, ntfn, len, NULL);\n",
                     Source + "/winsup/cygwin/dtable.cc")
#
# /src/gcc/winsup/cygwin/fhandler_fifo.cc: In member function 'bool fhandler_fifo::wait(bool)':
# /src/gcc/winsup/cygwin/fhandler_fifo.cc:139: error: jump to case label
# /src/gcc/winsup/cygwin/fhandler_fifo.cc:134: error:   crosses initialization of 'bool res'
#
    ChangeLineInFile("      bool res = ConnectNamedPipe (get_handle (), get_overlapped ());\n",
                     "      bool res;\n      res = ConnectNamedPipe (get_handle (), get_overlapped ());\n",
                     Source + "/winsup/cygwin/fhandler_fifo.cc")
#
# /src/gcc/winsup/cygwin/hookapi.cc: In function 'const char* find_first_notloaded_dll(path_conv&)':
# /src/gcc/winsup/cygwin/hookapi.cc:220: error: jump to label 'out'
# /src/gcc/winsup/cygwin/hookapi.cc:200: error:   from here
# /src/gcc/winsup/cygwin/hookapi.cc:202: error:   crosses initialization of 'long int delta'
# /src/gcc/winsup/cygwin/hookapi.cc:220: error: jump to label 'out'
# /src/gcc/winsup/cygwin/hookapi.cc:195: error:   from here
# /src/gcc/winsup/cygwin/hookapi.cc:202: error:   crosses initialization of 'long int delta'
# /src/gcc/winsup/cygwin/hookapi.cc:220: error: jump to label 'out'
# /src/gcc/winsup/cygwin/hookapi.cc:187: error:   from here
# /src/gcc/winsup/cygwin/hookapi.cc:202: error:   crosses initialization of 'long int delta'
# /src/gcc/winsup/cygwin/hookapi.cc:220: error: jump to label 'out'
# /src/gcc/winsup/cygwin/hookapi.cc:182: error:   from here
# /src/gcc/winsup/cygwin/hookapi.cc:202: error:   crosses initialization of 'long int delta'
# 
    ChangeLineInFile("  long delta = rvadelta (pExeNTHdr, importRVA);\n",
                     "  long delta;\n  delta = rvadelta (pExeNTHdr, importRVA);\n",
                     Source + "/winsup/cygwin/hookapi.cc")
#
# /src/gcc/winsup/cygwin/path.cc: In function 'ssize_t cygwin_conv_path(cygwin_conv_path_t, const void*, void*, size_t)':
# /src/gcc/winsup/cygwin/path.cc:2795: error: jump to case label
# /src/gcc/winsup/cygwin/path.cc:2783: error:   crosses initialization of '_UNICODE_STRING* up'
# /src/gcc/winsup/cygwin/path.cc:2803: error: jump to case label
# /src/gcc/winsup/cygwin/path.cc:2783: error:   crosses initialization of '_UNICODE_STRING* up'
# /src/gcc/winsup/cygwin/path.cc:2811: error: jump to case label
# /src/gcc/winsup/cygwin/path.cc:2783: error:   crosses initialization of '_UNICODE_STRING* up'
# /src/gcc/winsup/cygwin/path.cc:2819: error: jump to case label
# /src/gcc/winsup/cygwin/path.cc:2783: error:   crosses initialization of '_UNICODE_STRING* up'
#
    ChangeLineInFile("      PUNICODE_STRING up = p.get_nt_native_path ();\n",
                     "      PUNICODE_STRING up;\n      up = p.get_nt_native_path ();\n",
                     Source + "/winsup/cygwin/path.cc")
#
# /src/gcc/winsup/cygwin/pipe.cc: In constructor 'pipesync::pipesync(void*, DWORD)':
# /src/gcc/winsup/cygwin/pipe.cc:144: error: jump to label 'out'
# /src/gcc/winsup/cygwin/pipe.cc:121: error:   from here
# /src/gcc/winsup/cygwin/pipe.cc:129: error:   crosses initialization of 'void* ht'
#
    ChangeLineInFile("  HANDLE ht = CreateThread (&sec_none_nih, 0, pipe_handler, this, 0, &tid);\n",
                     "  HANDLE ht;\n  ht = CreateThread (&sec_none_nih, 0, pipe_handler, this, 0, &tid);\n",
                     Source + "/winsup/cygwin/pipe.cc")
#
# /src/gcc/winsup/cygwin/sec_auth.cc: In function 'void* create_token(cygsid&, user_groups&, passwd*)':
# /src/gcc/winsup/cygwin/sec_auth.cc:801: warning: suggest explicit braces to avoid ambiguous 'else'
# /src/gcc/winsup/cygwin/sec_auth.cc: In function 'void* lsaauth(cygsid&, user_groups&, passwd*)':
# /src/gcc/winsup/cygwin/sec_auth.cc:1161: error: jump to label 'out'
# /src/gcc/winsup/cygwin/sec_auth.cc:1048: error:   from here
# /src/gcc/winsup/cygwin/sec_auth.cc:1107: error:   crosses initialization of 'DWORD* csp_end'
# /src/gcc/winsup/cygwin/sec_auth.cc:1106: error:   crosses initialization of 'DWORD* csp'
# /src/gcc/winsup/cygwin/sec_auth.cc:1161: error: jump to label 'out'
# /src/gcc/winsup/cygwin/sec_auth.cc:1018: error:   from here
# /src/gcc/winsup/cygwin/sec_auth.cc:1107: error:   crosses initialization of 'DWORD* csp_end'
# /src/gcc/winsup/cygwin/sec_auth.cc:1106: error:   crosses initialization of 'DWORD* csp'
# /src/gcc/winsup/cygwin/sec_auth.cc:1161: error: jump to label 'out'
# /src/gcc/winsup/cygwin/sec_auth.cc:1015: error:   from here
# /src/gcc/winsup/cygwin/sec_auth.cc:1107: error:   crosses initialization of 'DWORD* csp_end'
# /src/gcc/winsup/cygwin/sec_auth.cc:1106: error:   crosses initialization of 'DWORD* csp'
# /src/gcc/winsup/cygwin/sec_auth.cc:1161: error: jump to label 'out'
# /src/gcc/winsup/cygwin/sec_auth.cc:1012: error:   from here
# /src/gcc/winsup/cygwin/sec_auth.cc:1107: error:   crosses initialization of 'DWORD* csp_end'
# /src/gcc/winsup/cygwin/sec_auth.cc:1106: error:   crosses initialization of 'DWORD* csp'
# /src/gcc/winsup/cygwin/sec_auth.cc:1161: error: jump to label 'out'
# /src/gcc/winsup/cygwin/sec_auth.cc:1010: error:   from here
# /src/gcc/winsup/cygwin/sec_auth.cc:1107: error:   crosses initialization of 'DWORD* csp_end'
# /src/gcc/winsup/cygwin/sec_auth.cc:1106: error:   crosses initialization of 'DWORD* csp'
# /src/gcc/winsup/cygwin/sec_auth.cc:1161: error: jump to label 'out'
# /src/gcc/winsup/cygwin/sec_auth.cc:1001: error:   from here
# /src/gcc/winsup/cygwin/sec_auth.cc:1107: error:   crosses initialization of 'DWORD* csp_end'
# /src/gcc/winsup/cygwin/sec_auth.cc:1106: error:   crosses initialization of 'DWORD* csp'
# /src/gcc/winsup/cygwin/sec_auth.cc:1161: error: jump to label 'out'
# /src/gcc/winsup/cygwin/sec_auth.cc:982: error:   from here
# /src/gcc/winsup/cygwin/sec_auth.cc:1107: error:   crosses initialization of 'DWORD* csp_end'
# /src/gcc/winsup/cygwin/sec_auth.cc:1106: error:   crosses initialization of 'DWORD* csp'
# /src/gcc/winsup/cygwin/sec_auth.cc:1161: error: jump to label 'out'
# /src/gcc/winsup/cygwin/sec_auth.cc:966: error:   from here
# /src/gcc/winsup/cygwin/sec_auth.cc:1107: error:   crosses initialization of 'DWORD* csp_end'
# /src/gcc/winsup/cygwin/sec_auth.cc:1106: error:   crosses initialization of 'DWORD* csp'
# /src/gcc/winsup/cygwin/sec_auth.cc:1161: error: jump to label 'out'
# /src/gcc/winsup/cygwin/sec_auth.cc:961: error:   from here
# /src/gcc/winsup/cygwin/sec_auth.cc:1107: error:   crosses initialization of 'DWORD* csp_end'
# /src/gcc/winsup/cygwin/sec_auth.cc:1106: error:   crosses initialization of 'DWORD* csp'
# /src/gcc/winsup/cygwin/sec_auth.cc:1161: error: jump to label 'out'
# /src/gcc/winsup/cygwin/sec_auth.cc:947: error:   from here
# /src/gcc/winsup/cygwin/sec_auth.cc:1107: error:   crosses initialization of 'DWORD* csp_end'
# /src/gcc/winsup/cygwin/sec_auth.cc:1106: error:   crosses initialization of 'DWORD* csp'
# 
    ChangeLineInFile("  PDWORD csp = (PDWORD) &authinf->username;\n",
                     "  PDWORD csp;\n  csp = (PDWORD) &authinf->username;\n",
                     Source + "/winsup/cygwin/sec_auth.cc")
    ChangeLineInFile("  PDWORD csp_end = (PDWORD) ((PBYTE) authinf + authinf_size);\n",
                     "  PDWORD csp_end;\n  csp_end = (PDWORD) ((PBYTE) authinf + authinf_size);\n",
                     Source + "/winsup/cygwin/sec_auth.cc")
#
# /src/gcc/winsup/cygwin/uinfo.cc: In member function 'void pwdgrp::load(const wchar_t*)':
# /src/gcc/winsup/cygwin/uinfo.cc:586: error: jump to label 'out'
# /src/gcc/winsup/cygwin/uinfo.cc:577: error:   from here
# /src/gcc/winsup/cygwin/uinfo.cc:580: error:   crosses initialization of 'char* eptr'
# /src/gcc/winsup/cygwin/uinfo.cc:586: error: jump to label 'out'
# /src/gcc/winsup/cygwin/uinfo.cc:569: error:   from here
# /src/gcc/winsup/cygwin/uinfo.cc:580: error:   crosses initialization of 'char* eptr'
# /src/gcc/winsup/cygwin/uinfo.cc:586: error: jump to label 'out'
# /src/gcc/winsup/cygwin/uinfo.cc:559: error:   from here
# /src/gcc/winsup/cygwin/uinfo.cc:580: error:   crosses initialization of 'char* eptr'
# /src/gcc/winsup/cygwin/uinfo.cc:586: error: jump to label 'out'
# /src/gcc/winsup/cygwin/uinfo.cc:551: error:   from here
# /src/gcc/winsup/cygwin/uinfo.cc:580: error:   crosses initialization of 'char* eptr'
# /src/gcc/winsup/cygwin/uinfo.cc:586: error: jump to label 'out'
# /src/gcc/winsup/cygwin/uinfo.cc:536: error:   from here
# /src/gcc/winsup/cygwin/uinfo.cc:580: error:   crosses initialization of 'char* eptr'
#
    ChangeLineInFile("  char *eptr = buf;\n",
                     "  char *eptr;\n  eptr = buf;\n",
                     Source + "/winsup/cygwin/uinfo.cc")
#
# /src/gcc/winsup/cygwin/syscalls.cc: In function 'FILE* popen(const char*, constchar*)':
# /src/gcc/winsup/cygwin/syscalls.cc:3529: error: jump to label 'err'
# /src/gcc/winsup/cygwin/syscalls.cc:3521: error:   from here
# /src/gcc/winsup/cygwin/syscalls.cc:3524: error:   crosses initialization of 'fhandler_pipe* fh'
# /src/gcc/winsup/cygwin/syscalls.cc:3529: error: jump to label 'err'
# /src/gcc/winsup/cygwin/syscalls.cc:3501: error:   from here
# /src/gcc/winsup/cygwin/syscalls.cc:3524: error:   crosses initialization of 'fhandler_pipe* fh'
#
    ChangeLineInFile("  fhandler_pipe *fh = (fhandler_pipe *) cygheap->fdtab[fd];\n",
                     "  fhandler_pipe *fh;\n  fh = (fhandler_pipe *) cygheap->fdtab[fd];\n",
                     Source + "/winsup/cygwin/syscalls.cc")
#
# /src/gcc/winsup/utils/cygcheck.cc:129: error: extra qualification 'pathlike::' on member 'check_existence'
# /src/gcc/winsup/utils/cygcheck.cc: In function 'int display_internet_error(const char*, ...)':
#
    ChangeLineInFile("  void pathlike::check_existence (const char *fn, int showall, int verbose,\n",
                     "  void check_existence (const char *fn, int showall, int verbose,\n",
                     Source + "/winsup/utils/cygcheck.cc")
#
# In file included from /src/gcc/winsup/cygwin/dcrt0.cc:30:
# /src/gcc/winsup/cygwin/shared_info.h:98: error: extra qualification 'mount_info::' on member 'create_root_entry'
#
# This is fixed in the 8/27 snapshot.
#
    ChangeLineInFile("  void mount_info::create_root_entry (const PWCHAR root);\n",
                     "  void create_root_entry (const PWCHAR root);\n",
                     Source + "/winsup/cygwin/shared_info.h")

#
# workaround problem with gmp/configure detecting flex output file
# This occurs because Python sets SIGPIPE to be ignored,
# causing flex to NOT be terminated by SIGPIPE, leading flex
# to continue on and delete its output file, once it fails
# to run m4-not-needed, since it has no assembly code, since
# gcc configures it with cpu=none.
#
# This bug is present in at least gmp 4.2.2 and 4.2.3.
#
if "gmp" in sys.argv:
    ChangeLineInFile("  M4=m4-not-needed\n",
                     "  : # M4=m4-not-needed\n",
                     Source + "/gmp/configure")

def PatchOutLibIConv(Obj):
#
# libiconv is often present on the build machine, but not the later host of the same architecture,
# for example on Solaris; it would be nice to have -disable-libiconv or -without-libiconv.
#
# This is not really needed, but nice to have.
#
    PatchName = "libiconv dependency"

    for a in ["binutils", "gcc", "libcpp", "libdecnumber"]:
        FilePath = Obj + "/" + a
        if not os.path.isdir(FilePath):
            print("*** no " + FilePath)
            continue
        for b in ["Makefile", "auto-host.h", "config.h"]:
            FilePath = Obj + "/" + a + "/" + b
            if not os.path.isfile(FilePath):
                print("*** no " + FilePath)
                continue;
            print("patching " + PatchName + " in " + FilePath)
            OldLines = file(FilePath).readlines()
            NewLines = [ ]
            Changed = False
            for OldLine in OldLines:
                NewLine = OldLine
                if NewLine.startswith("LTLIBICONV = "):
                    NewLine = "LTLIBICONV = \n"
                    Changed = True
                elif NewLine.startswith("LIBICONV = "):
                    NewLine = "LIBICONV = \n"
                    Changed = True
                elif NewLine.startswith("LIBICONV_DEP = "):
                    NewLine = "LIBICONV_DEP = \n"
                    Changed = True
                elif NewLine == "#define HAVE_ICONV 1\n":
                    NewLine = "#undef HAVE_ICONV\n"
                    Changed = True
                elif NewLine == "#define HAVE_ICONV_H 1\n":
                    NewLine = "#undef HAVE_ICONV_H\n"
                    Changed = True
                NewLines += NewLine
            if Changed:
                file(FilePath, "w").writelines(NewLines)
            print("done patching " + PatchName + " in " + FilePath)

    print("done patching " + PatchName)


def PatchOutOptimizer(Target, Obj):
#
# This is not really needed, but should provide a nice
# speed boost to building the compiler.
#
    PatchName = "CFLAGS=-g"

    for a in [
            ".",
            "binutils",
            "gcc",
            "gcc/ada",
            "gmp",
            "gmp/cxx",
            "gmp/demos",
            "gmp/demos/calc",
            "gmp/demos/expr",
            "gmp/doc",
            "gmp/mpbsd",
            "gmp/mpf",
            "gmp/mpn",
            "gmp/mpq",
            "gmp/mpz",
            "gmp/printf",
            "gmp/scanf",
            "gmp/tests",
            "gmp/tests/cxx",
            "gmp/tests/devel",
            "gmp/tests/misc",
            "gmp/tests/mpbsd",
            "gmp/tests/mpf",
            "gmp/tests/mpn",
            "gmp/tests/mpq",
            "gmp/tests/mpz",
            "gmp/tests/rand",
            "gmp/tune",
            "libcpp",
            "libdecnumber",
            "libiberty",
            "libstdc++-v3/doc",
            "libstdc++-v3/include",
            "libstdc++-v3/libmath",
            "libstdc++-v3/libsupc++",
            "libstdc++-v3/po",
            "libstdc++-v3/src",
            "libstdc++-v3/testsuite",
            "mpfr",
            "mpfr/tests",
            Target + "/libgcc",
            Target + "/libgfortran",
            Target + "/libiberty",
            Target + "/libiberty/testsuite",
            Target + "/libstdc++-v3",
            Target + "/libstdc++-v3/doc",
            Target + "/libstdc++-v3/include",
            Target + "/libstdc++-v3/libmath",
            Target + "/libstdc++-v3/libsupc++",
            Target + "/libstdc++-v3/po",
            Target + "/libstdc++-v3/src",
            Target + "/libstdc++-v3/testsuite",
            Target + "/newlib",
            Target + "/newlib/doc",
            Target + "/newlib/libc",
            Target + "/newlib/libc/argz",
            Target + "/newlib/libc/ctype",
            Target + "/newlib/libc/errno",
            Target + "/newlib/libc/iconv",
            Target + "/newlib/libc/iconv/ccs",
            Target + "/newlib/libc/iconv/ccs/binary",
            Target + "/newlib/libc/iconv/ces",
            Target + "/newlib/libc/iconv/lib",
            Target + "/newlib/libc/locale",
            Target + "/newlib/libc/machine",
            Target + "/newlib/libc/machine/i386",
            Target + "/newlib/libc/misc",
            Target + "/newlib/libc/posix",
            Target + "/newlib/libc/reent",
            Target + "/newlib/libc/search",
            Target + "/newlib/libc/signal",
            Target + "/newlib/libc/stdio",
            Target + "/newlib/libc/stdio64",
            Target + "/newlib/libc/stdlib",
            Target + "/newlib/libc/string",
            Target + "/newlib/libc/sys",
            Target + "/newlib/libc/syscalls",
            Target + "/newlib/libc/time",
            Target + "/newlib/libc/unix",
            Target + "/newlib/libm",
            Target + "/newlib/libm/common",
            Target + "/newlib/libm/machine",
            Target + "/newlib/libm/machine/i386",
            Target + "/newlib/libm/math",
            Target + "/newlib/libm/mathfp",
            Target + "/winsup/lsaauth",
            Target + "/winsup/mingw",
            Target + "/winsup/w32api",
            Target + "/winsup/w32api/lib",
            Target + "/winsup/w32api/lib/ddk",
            Target + "/winsup/w32api/lib/directx",
            ]:
        FilePath = Obj + "/" + a
        if not os.path.isdir(FilePath):
            print("*** no " + FilePath)
            continue
        for b in ["Makefile"]:
            FilePath = Obj + "/" + a + "/" + b
            if not os.path.isfile(FilePath):
                print("*** no " + FilePath)
                continue;
            print("patching " + PatchName + " in " + FilePath)
            OldLines = file(FilePath).readlines()
            NewLines = [ ]
            Changed = False
            for OldLine in OldLines:
                NewLine = OldLine
                if NewLine.find(" -O2") != -1:
                    if (       NewLine.startswith("CFLAGS = -")
                            or NewLine.startswith("CFLAGS          := -")
                            or NewLine.startswith("CXXFLAGS = -")
                            or NewLine.startswith("BOOT_CFLAGS = -")
                            or NewLine.startswith("CFLAGS_FOR_TARGET = -")
                            or NewLine.startswith("CXXFLAGS_FOR_TARGET = -")
                            or NewLine.startswith("LIBGCC2_CFLAGS = -")
                            or NewLine.startswith("CRTSTUFF_CFLAGS = -")
                            or NewLine.startswith("GNATLIBCFLAGS = -")
                            or NewLine.startswith("NEWLIB_CFLAGS = -")
                            # tabs here
                            or NewLine.startswith("	$(CXX) $(PCHFLAGS) $(AM_CPPFLAGS) -")
                            or NewLine.startswith("	$(CC) -c $(ALL_ADAFLAGS) $(FORCE_DEBUG_ADAFLAGS) -")):
                        for i in range(0, 2):
                            print(i)
                            NewLine = NewLine.replace(" -O2 ", " ")
                            NewLine = NewLine.replace(" -O2\n", " \n")
                        Changed = True
                NewLines += NewLine
            if Changed:
                file(FilePath, "w").writelines(NewLines)
            print("done patching " + PatchName + " in " + FilePath)

    print("done patching " + PatchName)

def WorkaroundUnableToFindSparc64LibGcc():
#
# http://gcc.gnu.org/bugzilla/show_bug.cgi?id=37079
# ld: cannot find -lgcc_s
# collect2: ld returned 1 exit status
# make[4]: *** [libstdc++.la] Error 1
# make[4]: Leaving directory /obj/gcc.1/sparc64-sun-solaris2.10/sparc64-sun-solaris2.10/sparc64-sun-solaris2.10/libstdc++-v3/src
#
# -disable-shared is probably also a good workaround here
#
    #Directory = Prefix + "/lib/gcc/sparc64-sun-solaris2.10/" + GccVersion
    #Run(".", "mkdir -p " + Directory)
    #Run(Directory, "-ln -s sparcv9/libgcc_s.so libgcc_s.so")
    #Run(Directory, "-ln -s sparcv9/libgcc_s.so.1 libgcc_s.so.1")
    #
    # disable shared instead
    #
    pass

WorkaroundUnableToFindSparc64LibGcc()

def Date():
    Run(".", "@sh -c date")

def DoBuild(Host = None, Target = None, ExtraConfig = " "):

    if Host == None:
        Host = Build

    if Target == None:
        Target = Build

    #
    # in particular, avoiding -O2 to speed up the build, and to aid debugging
    #

    Environ = " "
    Environ += " CFLAGS=-g"
    Environ += " CFLAGS_FOR_BUILD=-g"
    Environ += " BOOT_CFLAGS=-g"
    Environ += " CXXFLAGS=-g"
    Environ += " CXXFLAGS_FOR_BUILD=-g"
    Environ += " FCFLAGS=-g"
    Environ += " GNATLIBCFLAGS=-g"
    Environ += " STAGE_CC_WRAPPER=ccache"
    #
    # Environ += " CC=\"ccache gcc\""
    # This breaks Canadian.
    #
    Environ = re.sub("  +", " ", Environ)

    DefaultSysroot = (Prefix + "/" + Target + "/sys-root")

    #
    # workaround problems building libjava -- fixed with big stack
    #
    #if Host != Build or Host != Target:
    #ExtraConfig += " -enable-languages=c,c++ "
    #ExtraConfig += " -enable-languages=c,c++,fortran,java,objc,ada "


    #
    # just to speed it up
    # works without and supports more languages, such as Fortran and Java
    #

    ExtraConfig += " -enable-languages=c,c++ "

    #
    # Cross building native does not work for Ada.
    # http://gcc.gnu.org/bugzilla/show_bug.cgi?id=37109
    #
    # and msdos:
    # In file included from socket.c:38:
    # gsocket.h:151:24: error: sys/socket.h: No such file or directory
    # gsocket.h:153:25: error: netinet/tcp.h: No such file or directory
    # gsocket.h:155:19: error: netdb.h: No such file or directory
    # socket.c: In function '__gnat_get_h_errno':
    # socket.c:411: error: 'h_errno' undeclared (first use in this function)
    # socket.c:411: error: (Each undeclared identifier is reported only once
    # socket.c:411: error: for each function it appears in.)
    # make[4]: *** [socket.o] Error 1
    # make[4]: Leaving directory `/obj/gcc.1/i686-pc-cygwin/i586-pc-msdosdjgpp/gcc/ada/rts'
    #
    if ((Host != Target) or (Build == Host)) and (Target.find("msdosdjgpp") != -1):
        #ExtraConfig += " -enable-languages=all,ada "
        pass

    if Target.find("msdosdjgpp") != -1:
        #ExtraConfig += " -enable-languages=c,c++,fortran,java,objc "
        pass

    if (Target.find("sparc64") != -1) and (Target.find("solaris") != -1):
        #
        # see WorkaroundUnableToFindSparc64LibGcc
        #
        ExtraConfig += " -disable-shared"

    if Target.find("-cygwin") != -1:
        #
        # default is to disable threads, but threads work
        #
        ExtraConfig += " -enable-threads"

        #
        # errors building shared libgcc for lack of -lc and -lpthread on command line
        #
        ExtraConfig += " -disable-shared"


    #
    # cross builds have extra requirements that are not automated,
    # in particular setting up "sys-root" or headers/libs ahead of time.
    # This is a very tricky area -- since it isn't automated and errors
    # doing this are often not caught till late, which is extra
    # frustrating.
    # Try to catch these errors early here.
    #
    # NOTE that if you are doing an "integrated" build with glibc or newlib,
    # then this is likely less of an issue, you are building the sysroot.
    # glibc is typical for Linux.
    # newlib is typical for embedded systems.
    # That still leaves many other systems such as Cygwin, MinGWin, and
    # commercial Unices with their native libc such as Solaris, HP-UX, AIX.
    #
    # NOTE that Cygwin does use newlib, but I don't have that setup to work here yet.
    # I build Cygwin separately.
    #

    if Build != Target:

        if Target.find("msdosdjgpp") != -1:

            #
            # I don't remember why I put this in, but it makes some sense -- no dynamic linking on djgpp.
            #

            ExtraConfig += " -disable-shared -enable-static "

            #
            # djgpp "favors" the pre-sysroot method, via the djgpp cross package
            #

            #for a in ["lib", "include"]:
            for a in ["include"]:
                b = Prefix + "/" + Target + "/" + a
                if not os.path.isdir(b):
                    print("ERROR: Please create " + b + ", such as by extracting djcrx<version>.zip in /usr/local/" + Target)
                    exit(1)
            ExtraConfig += " -with-headers=" + Prefix + "/" + Target + "/include "
            #ExtraConfig += " -with-libs=" + Prefix + "/" + Target + "/lib "

        else:

            #
            # mingw sys-root is unusual; help the user
            #

            if Target.find("-mingw32") != -1:
                for a in ["lib", "include"]:
                    if True:
                        b = DefaultSysroot + "/mingw/" + a
                        if not os.path.isdir(b):
                            print("ERROR: Please create " + b + ", such as by a link (or NTFS junction) to /mingw/" + a)
                            print("")
                            print("Such as like so (on Windows):")
                            print("  install mingw, such as to c:\mingw")
                            print("  mkdir c:\cygwin\usr\local\i686-pc-mingw32\sys-root\mingw")
                            print("  copy \\\\live.sysinternals.com\\tools\\junction.exe %windir%")
                            print("  junction c:\\cygwin\\usr\\local\\i686-pc-mingw32\\sys-root\\mingw\\include c:\\mingw\\include")
                            print("  junction c:\\cygwin\\usr\\local\\i686-pc-mingw32\\sys-root\\mingw\\lib c:\\mingw\\lib")
                            print("")
                            #print("In order for gcc -mno-cygwin to work, besides just i686-pc-mingw32-gcc, you MIGHT also need");
                            #print("  junction c:\\cygwin\\usr\\local\\include c:\\mingw\\include")
                            #print("  junction c:\\cygwin\\usr\\local\\lib c:\\mingw\\lib")
                            #print("")
                            exit(1)

                ExtraConfig += " -with-sysroot "

            #
            # normal sys-root
            #
                    
            else:
                if not os.path.isdir(DefaultSysroot):
                    print("ERROR: Please put appropriate subset of " + Target + " file system at " + DefaultSysroot + " (such as /lib, /usr/lib, /usr/include)")
                    exit(1)
                ExtraConfig += " -with-sysroot "

    #
    # Workaround Canadian fixincludes not understanding sysroot of the cross compiler used to build it.
    # http://gcc.gnu.org/bugzilla/show_bug.cgi?id=37036
    #
    if (Host == Target) and (Host != Build):
        ExtraConfig += " -with-sysroot=/"
        ExtraConfig += " -with-build-sysroot=" + DefaultSysroot
        

    ExtraConfig = re.sub("  +", " ", ExtraConfig)

    print("starting " + Host + "/" + Target)
    Date()

    ExtraInstall = " "
    DestDir = None
    if Host != Build:
        #
        # There seems to be no convention here.
        #
        DestDir = Prefix + "/" + Host + "/install"
        ExtraInstall = " DESTDIR=" + DestDir

    # Obj = ObjRoot + "/" + Build + "/" + Host + "/" + Target
    Obj = ObjRoot + "/" + Host + "/" + Target

    print("configuring " + Host + "/" + Target)
    Date()
    if not os.path.isfile(Obj + "/Makefile"):
        CreateDirectories(Obj)
        Run(Obj, Source + "/configure -host " + Host + " -target " + Target + " " + ConfigCommon + " " + ExtraConfig + Environ)

    print("making " + Host + "/" + Target)
    Date()

    for a in ["build", "host", "target"]:
        #
        # configure-build does not exist
        #
        if a != "build":
            Run(Obj, "make configure-" + a + " " + Environ)
            PatchOutLibIConv(Obj)
            PatchOutOptimizer(Target, Obj)
        Run(Obj, "make all-" + a + " " + Environ)

    Run(Obj, "make all " + Environ)

    if True:
        print("installing " + Host + "/" + Target)
        Date()
        Run(Obj, "make install " + ExtraInstall + Environ)

    if DestDir:
        print("Success; copy " + DestDir + " to your " + Host + " machine")

Platform1 = Build

# native
# DoBuild()

Platform2 = "i686-pc-mingw32"
# DoBuild(Platform1, Platform2)

#DoBuild(Platform2, Platform2)

Platform2 = "sparc-sun-solaris2.10"
# DoBuild(Platform1, Platform2)
DoBuild(Platform2, Platform2)

Platform2 = "sparc64-sun-solaris2.10"
DoBuild(Platform1, Platform2)
DoBuild(Platform2, Platform2)

Platform2 = "i586-pc-msdosdjgpp"
DoBuild(Platform1, Platform2)
DoBuild(Platform2, Platform2)


#
# working tools
#
# i586-pc-msdosdjgpp
# sparc64-sun-solaris2.10
# i686-pc-linux
# i686-pc-cygwin
# i686-pc-mingw32
#
# easily up and running host
#   i686-pc-cygwin
#   i686-pc-linux
#   x86_64-pc-linux
#   x86_64-pc-cygwin
#   ppc-apple-darwin
#
# owned hardware
#   i686-pc
#   i686_64-pc
#   sparc64-sun
#   ppc-apple
#   mips-sgi (not powered up, 64?)
#
# planned to purchase
#   x86_64-apple (darwin)
#   ppc64-apple (darwin)
#   itanium (hpux, linux, vms)
#   alpha (linux, vms, osf)
#   hppa64 (hpux, linux)
#   alpha-pc/nt? (linux, osf, nt?)
#   ppc-pc/nt? (nt?)
#   mips-pc/nt? (nt?)
#
# candidate tools
#  needs pruning
#  needs sysroots
#  needs config.guess, config.sub
#  needs hardware
#
#
# i686-apple-darwin
# i686-sun-solaris
# i686-unknown-netbsd
# i686-unknown-freebsd
# i686-unknown-netbsd
# i686-unknown-openbsd
# x86_64-pc-linux
# x86_64-pc-cygwin
# x86_64-pc-mingwin
# x86_64-apple-darwin
# x86_64-sun-solaris
# x86_64-unknown-freebsd
# x86_64-unknown-netbsd
# x86_64-unknown-openbsd
# ppc-apple-darwin
# ppc-unknown-linux
# ppc-unknown-openbsd
# ppc-unknown-freebsd
# ppc-unknown-netbsd
# ppc-unknown-aix
# ppc64-apple-darwin
# ppc64-unknown-linux
# ppc64-unknown-freebsd
# ppc64-unknown-netbsd
# ppc64-unknown-openbsd
# ppc64-unknown-aix
# sparc-unknown-linux
# sparc-unknown-openbsd
# sparc-unknown-freebsd
# sparc-unknown-netbsd
# sparc-sun-solaris
# sparc64-unknown-linux
# sparc64-unknown-freebsd
# sparc64-unknown-netbsd
# sparc64-unknown-openbsd
# mips-sgi-irix
# mips-sgi-linux
# mips64-sgi-irix
# mips64-sgi-linux
# alpha-digital-linux
# alpha-digital-osf
# alpha-digital-vms
# hppa-hp-hpux
# hppa-hp-linux
# hppa64-hp-hpux
# hppa64-hp-linux
# itanium-unknown-linux
# itanium-unknown-hpux
# itanium-unknown-vms
# vax-unknown-linux
# vax-unknown-freebsd
# vax-unknown-netbsd
# vax-unknown-openbsd
# vax-unknown-vms
#


#
# some unsolved/worked-around problems
#

#
# why not use Python's multithreading:
#
# sem_init: Resource temporarily unavailable
# Traceback (most recent call last):
#   File "./build.py", line 254, in <module>
#
#   File "./build.py", line 165, in Run
#     t.start()
#   File "/usr/lib/python2.5/threading.py", line 405, in __init__
#     self.__block = Condition(Lock())
# thread.error: can't allocate lock
# cd /obj/gmp1 && /src/gmp-4.2.2/configure   -verbose -enable-languages=c,ada,c++,
# d,f77,pascal,java,objc -without-included-gettext -enable-version-specific-runtim
#
# can't allocate lock
#
