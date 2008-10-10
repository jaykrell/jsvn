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

ObjRoot = "/obj/gcc.1"
Source = "/src"
Archives = "/net/src"
GccRelVersion = "4.3.2"
GccSvnVersion = "4.4.0"
GccVersion = None
GmpVersion = "4.2.3"
MpfrVersion = "2.3.2"

#
# use canonical names including version
#  - sometimes they get further canonicalized, sometimes not
#  - libgcc wants a version in Platform2
# TBD: run config.guess, or do it ourselves for platforms we support
#
Build = "i686-pc-cygwin"

Prefix = "/usr/local"
# Prefix = "/usr"


i = 0
while i != len(sys.argv):
    arg = sys.argv[i]
    if arg == "obj":
        i += 1
        ObjRoot = sys.argv[i]
    elif arg == "archives":
        i += 1
        Archives = sys.argv[i]
    elif arg == "source":
        i += 1
        Source = sys.argv[i]
    elif arg == "gccsvn" or arg == "gcc-svn":
        Source += "/gccsvn"
        if not GccVersion:
            GccVersion = GccSvnVersion
    elif arg == "gccrel" or arg == "gcc-rel":
        Source += "/gccrel"
        if not GccVersion:
            GccVersion = GccRelVersion
    elif arg == "gccver" or arg == "gcc-ver":
        i += 1
        GccVersion = sys.argv[i]
    elif arg == "gmpver" or  arg == "gmp-ver":
        i += 1
        GmpVersion = sys.argv[i]
    elif arg == "mpfrver" or arg == "mpfr-ver":
        i += 1
        MpfrVersion = sys.argv[i]
    elif arg == "build":
        i += 1
        Build = sys.argv[i]
    i += 1

if "source" not in sys.argv:
    if ("gccrel" in sys.argv) == ("gccsvn" in sys.argv):
        print("ERROR: must specify either gccrel or gccsvn")
        sys.exit(1)


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
ConfigCommon += " -disable-multilib "

#
# unfortunate, but fixes multiple problems on multiple platforms
#
ConfigCommon += " -disable-shared -enable-static "

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
# Favor "gmake" and "gtar" if they appear to be present.
# In particular, GNU tar is needed for some long symlinks and
# GNU make is needed for building gcc, at least outside the source directory.
#
# In the future when build.py is further extended, such as to build
# make and tar themselves, bootstrapping some packages with native tar and make
# is viable. As well, bootstrapping gcc with output in the source directory
# should be attempted.
#

Tar = None
Make = None

def FindGnuTool(CurrentValue, ToolName):
#
# favor gnumake, gnutar, then gmake, gtar, then make, tar
#
    if not CurrentValue:
        for g in ["gnu", "g", ""]:
            CurrentValue = g + ToolName
            if os.system(CurrentValue + " --help >/dev/null 2>&1") == 0:
                break
    #print("using " + CurrentValue + " for " + ToolName)
    return CurrentValue
        
def FindTar():
    global Tar
    Tar = FindGnuTool(Tar, "tar")

def FindMake():
    global Make
    Make = FindGnuTool(Make, "make")

FindMake()
FindTar()

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
        return False

    FindTar()

    CreateDirectories(Directory);
    for ext in [".tar.gz", ".tgz"]:
        if os.path.exists(File + ext):
            Run(Directory, Tar + " --strip-components=1 -zxf " + File + ext)
            return True

    for ext in [".tar.bz2", ".tbz"]:
        if os.path.exists(File + ext):
            Run(Directory, Tar + " --strip-components=1 -jxf " + File + ext)
            return True

    #
    # lzma produces significantly smaller results than bzip2, and faster.
    # However lzma is written in C++ and therefore harder to bootstrap on, e.g., Irix
    #

    for ext in [".tlz", ".tar.lzma"]:
        if os.path.exists(File + ext):
            Run(Directory, Tar + " --strip-components=1 --lzma -xf " + File + ext)
            return True

    Run(Directory, Tar + " --strip-components=1 -xf " + File)
    return True

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

if ("cygwin" in sys.argv) or ("winsup" in sys.argv):
    Extract(Source, Source + "/winsup", Archives + "/" + "cygwin-src-20080912")

ExtractedBinutils = False

if "binutils" in sys.argv:
    ExtractedBinutils = Extract(Source, Source + "/binutils", Archives + "/" + "binutils-2.18")

if "gccrel" in sys.argv or "gcc-rel" in sys.argv:
    Marker = Source + "/gcc"
    if ExtractedBinutils:
        Marker += "nonexistant"
    if "gcc-core" in sys.argv or "gcccore" in sys.argv:
        Extract(Source, Marker, Archives + "/" + "gcc-core-" + GccRelVersion)
    else:
        Extract(Source, Marker, Archives + "/" + "gcc-" + GccRelVersion)

if "gccsvn" in sys.argv or "gcc-svn" in sys.argv:
    #
    # Where there is no overlap with binutils, use /d for perf.
    # Where is overlap with binutils, don't use /d for correctness.
    # FUTURE make this portable
    #
    Run(".", "xcopy /qeyid " + "/dev2/gcc /src/gccsvn".replace("/", "\\\\"))

    # non recursive at the root
    Run(".", "xcopy /qyi " + "/dev2/gcc /src/gccsvn".replace("/", "\\\\"))

    for a in ["libiberty", "config", "include", "intl"]:
        Run(".", "xcopy /qyi " + ("/dev2/gcc/" + a + " /src/gccsvn/" + a).replace("/", "\\\\"))

if ("gmp" in sys.argv) or ("mpfr" in sys.argv):
    Extract(Source + "/gmp", Source + "/gmp", Archives + "/" + "gmp-" + GmpVersion)
    Extract(Source + "/mpfr", Source + "/mpfr", Archives + "/" + "mpfr-" + MpfrVersion)

def RemoveEOL(a):
    return a.replace("\n", "").replace("\r", "")

def AddLines(LinesToAdd, FilePath):
    LinesToAdd = dict().fromkeys(LinesToAdd)
    ExistingLines = dict().fromkeys(file(FilePath).readlines())
    for i in ExistingLines.keys():
        LinesToAdd.pop(i, None)
    if len(LinesToAdd) != 0:
        print("AddLines: updating " + FilePath)
        file(FilePath, "a").writelines(LinesToAdd.keys())
    else:
        print("AddLines: already up to date " + FilePath)

def ChangeLine(From, To, FilePath):
    Changed = False
    NewLines = [ ]
    OldLines = file(FilePath).readlines()
    for Line in OldLines:
        if Line == From:
            Changed = True
            Line = To
        NewLines += Line
    if Changed:
        print("ChangeLine: updating " + FilePath)
        file(FilePath, "w").writelines(NewLines)
    else:
        print("ChangeLine: already up to date " + FilePath)

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
        print("AddLineAfterLine: updating " + FilePath)
        file(FilePath, "w").writelines(NewLines)
    else:
        print("AddLineAfterLine: already up to date " + FilePath)

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
        print("AddLineBeforeLine: updating " + FilePath)
        file(FilePath, "w").writelines(NewLines)
    else:
        print("AddLineBeforeLine: already up to date " + FilePath)

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
AddLines(["LDFLAGS += -Wl,--stack,8388608\n"], Source + "/config/mh-cygwin")
AddLines(["LDFLAGS += -Wl,--stack,8388608\n", "CFLAGS += -D__USE_MINGW_ACCESS\n"], Source + "/config/mh-mingw")

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
    ChangeLine(
        "      checkfuncs=\"`echo $checkfuncs | sed -e 's/strsignal//' -e 's/psignal//'`\"\n",
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
AddLineAfterLine(
    "#define HAVE_SYS_NERR 1\n",
    "#ifdef __CYGWIN__\n#define HAVE_STRSIGNAL 1\n#endif\n",
    Source + "/libiberty/configure")
AddLineAfterLine(
    "AC_DEFINE(HAVE_SYS_NERR)\n",
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


if ("cygwin" in sys.argv) or ("winsup" in sys.argv):
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
#ChangeLine(
#   "override CC := ${filter-out -L% -B%,${shell echo $(CC) | sed -e 's%\(-isystem\|-iwithprefixbefore\)  *[^ ]*\( \|$$\)% %g'}}\n",
#   "override CC := ${filter-out -L% -B%,${shell echo $(CC) | sed -e 's%\(-isystem\|-iwithprefixbefore\)  *[^ ]*\( \|$$\)% %g'}} -B../../../gcc -B../../../../gcc\n",
#   Source + "/winsup/mingw/Makefile.in")
#
#
# Here is a better fix:
#
    ChangeLine(
        "override CC := ${filter-out -L% -B%,${shell echo $(CC) | sed -e 's%\(-isystem\|-iwithprefixbefore\)  *[^ ]*\( \|$$\)% %g'}}\n",
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
    ChangeLine(
        "  void __stdcall raw_read (void *ptr, size_t& len);\n",
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
    ChangeLine(
        "  WCHAR *w32 = ntfn->Name.Buffer;\n",
        "  WCHAR *w32;\n  w32 = ntfn->Name.Buffer;\n",
        Source + "/winsup/cygwin/dtable.cc")
    ChangeLine(
        "  size_t w32len = ntfn->Name.Length / sizeof (WCHAR);\n",
        "  size_t w32len;\n  w32len = ntfn->Name.Length / sizeof (WCHAR);\n",
        Source + "/winsup/cygwin/dtable.cc")
    ChangeLine(
        "  OBJECT_NAME_INFORMATION *ntfn = (OBJECT_NAME_INFORMATION *) alloca (len + sizeof (WCHAR));\n",
        "  OBJECT_NAME_INFORMATION *ntfn;\n  ntfn = (OBJECT_NAME_INFORMATION *) alloca (len + sizeof (WCHAR));\n",
        Source + "/winsup/cygwin/dtable.cc")
    ChangeLine(
        "  NTSTATUS res = NtQueryObject (h, ObjectNameInformation, ntfn, len, NULL);\n",
        "  NTSTATUS res;\n  res = NtQueryObject (h, ObjectNameInformation, ntfn, len, NULL);\n",
        Source + "/winsup/cygwin/dtable.cc")
#
# /src/gcc/winsup/cygwin/fhandler_fifo.cc: In member function 'bool fhandler_fifo::wait(bool)':
# /src/gcc/winsup/cygwin/fhandler_fifo.cc:139: error: jump to case label
# /src/gcc/winsup/cygwin/fhandler_fifo.cc:134: error:   crosses initialization of 'bool res'
#
    ChangeLine(
        "      bool res = ConnectNamedPipe (get_handle (), get_overlapped ());\n",
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
    ChangeLine(
        "  long delta = rvadelta (pExeNTHdr, importRVA);\n",
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
    ChangeLine(
        "      PUNICODE_STRING up = p.get_nt_native_path ();\n",
        "      PUNICODE_STRING up;\n      up = p.get_nt_native_path ();\n",
        Source + "/winsup/cygwin/path.cc")
#
# /src/gcc/winsup/cygwin/pipe.cc: In constructor 'pipesync::pipesync(void*, DWORD)':
# /src/gcc/winsup/cygwin/pipe.cc:144: error: jump to label 'out'
# /src/gcc/winsup/cygwin/pipe.cc:121: error:   from here
# /src/gcc/winsup/cygwin/pipe.cc:129: error:   crosses initialization of 'void* ht'
#
    ChangeLine(
        "  HANDLE ht = CreateThread (&sec_none_nih, 0, pipe_handler, this, 0, &tid);\n",
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
    ChangeLine(
        "  PDWORD csp = (PDWORD) &authinf->username;\n",
        "  PDWORD csp;\n  csp = (PDWORD) &authinf->username;\n",
        Source + "/winsup/cygwin/sec_auth.cc")
    ChangeLine(
        "  PDWORD csp_end = (PDWORD) ((PBYTE) authinf + authinf_size);\n",
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
    ChangeLine(
        "  char *eptr = buf;\n",
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
    ChangeLine(
        "  fhandler_pipe *fh = (fhandler_pipe *) cygheap->fdtab[fd];\n",
        "  fhandler_pipe *fh;\n  fh = (fhandler_pipe *) cygheap->fdtab[fd];\n",
        Source + "/winsup/cygwin/syscalls.cc")
#
# /src/gcc/winsup/utils/cygcheck.cc:129: error: extra qualification 'pathlike::' on member 'check_existence'
# /src/gcc/winsup/utils/cygcheck.cc: In function 'int display_internet_error(const char*, ...)':
#
    ChangeLine(
        "  void pathlike::check_existence (const char *fn, int showall, int verbose,\n",
        "  void check_existence (const char *fn, int showall, int verbose,\n",
        Source + "/winsup/utils/cygcheck.cc")
#
# In file included from /src/gcc/winsup/cygwin/dcrt0.cc:30:
# /src/gcc/winsup/cygwin/shared_info.h:98: error: extra qualification 'mount_info::' on member 'create_root_entry'
#
# This is fixed in the 8/27 snapshot.
#
    ChangeLine(
        "  void mount_info::create_root_entry (const PWCHAR root);\n",
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
if ("gmp" in sys.argv) or ("mpfr" in sys.argv):
    ChangeLine(
        "  M4=m4-not-needed\n",
        "  : # M4=m4-not-needed\n",
        Source + "/gmp/configure")
#
# workaround Irix /usr/WorkShop/usr/bin/ncc:
#
ChangeLine(
    "  return (ivs->bad_uses ? infinite_cost : ivs->cost);\n",
    "  if (ivs->bad_uses)\n"
    + "    return infinite_cost;\n"
    + "  return ivs->cost;\n",
    Source + "/gcc/tree-ssa-loop-ivopts.c")
#
# Irix /usr/WorkShop/usr/bin/ncc has trouble preprocessing combine.c
#
def ReplaceFunctionIf(FunctionName, Replacement, If, File):
    if Replacement:
        xFunctionName = "ReplaceFunctionIf"
    else:
        xFunctionName = "RemoveFunctionIf"
    ChangedFile = False
    NewLines = [ ]
    OldLines = file(File).readlines()
    len_OldLines = len(OldLines)
    i = 0
    FunctionParen = FunctionName + " ("
    FoundFunction = False
    while i != len_OldLines:
        ChangedLine = False
        if (        ((i + 1) != len_OldLines)
                and ((i + 2) != len_OldLines)
                and OldLines[i + 1].startswith(FunctionParen)
                and RemoveEOL(OldLines[i + 1]).endswith(")")
                and RemoveEOL(OldLines[i + 2]) == "{"):

            FoundFunction = True

            # print("1 found function " + FunctionName + " in " + File + " at line " + str(i))

            if (((not Replacement)
                    and (  (i < 3)
                        or (RemoveEOL(OldLines[i - 1]) != "#else")
                        or (RemoveEOL(OldLines[i - 2]) != "/* nothing */")
                        or (RemoveEOL(OldLines[i - 3]) != If)))
                    or (Replacement
                        and (  ((i + 3) == len_OldLines)
                            or ((i + 4) == len_OldLines)
                            or ((i + 5) == len_OldLines)
                            or (RemoveEOL(OldLines[i + 3]) != If)
                            or (RemoveEOL(OldLines[i + 4]) != Replacement)
                            or (RemoveEOL(OldLines[i + 5]) != "#else")))):
                
                # print("2 found function " + FunctionName + " in " + File + " at line " + str(i))

                ChangedLine = True

                if not Replacement:
                    NewLines += If + "\n"
                    NewLines += "/* nothing */\n"
                    NewLines += "#else\n"

                NewLines += OldLines[i] # return type
                NewLines += OldLines[i + 1] # prototype
                NewLines += OldLines[i + 2] # opening brace

                if Replacement:
                    NewLines += If + "\n"
                    NewLines += Replacement + "\n"
                    NewLines += "#else\n"

                i += 3
                while i != len_OldLines and ((len(OldLines[i]) > 3) or RemoveEOL(OldLines[i]) != "}"):
                    NewLines += OldLines[i]
                    i += 1
                if i == len_OldLines:
                    print("ERROR: did not find end of function " + FunctionName)
                    sys.exit(1)
                if not Replacement:
                    NewLines += OldLines[i] # closing brace
                    i += 1;
                NewLines += "#endif\n"
        if ChangedLine:
            ChangedFile = True
        else:
            NewLines += OldLines[i]
            i += 1

    if not FoundFunction:
        print("ERROR: did not find function " + FunctionName + " in " + File)
        sys.exit(1)

    if ChangedFile:
        print(xFunctionName + ": updating " + FunctionName + " in " + File)
        file(File, "w").writelines(NewLines)
    else:
        print(xFunctionName + ": already up to date " + FunctionName + " in " + File)

def RemoveFunctionIf(FunctionName, If, File):
    ReplaceFunctionIf(FunctionName, None, If, File)

def CreateFile(File, Contents):
    if (not os.path.exists(File)) or (Contents != file(File).read()):
        print("CreateFile: creating or updating " + File)
        file(File, "w").write(Contents)
    else:
        print("CreateFile: already exists and has correct contents " + File)

IfIrixBootstrap = "#if !defined(__GNUC__) && defined(_ABIO32) /* Irix /usr/WorkShop/usr/bin/ncc has trouble preprocessing in this function. */"

RemoveFunctionIf("find_split_point", IfIrixBootstrap, Source + "/gcc/combine.c")
ReplaceFunctionIf("combine_simplify_rtx", "return x;", IfIrixBootstrap, Source + "/gcc/combine.c")
ReplaceFunctionIf("try_combine", "return 0;", IfIrixBootstrap, Source + "/gcc/combine.c")
ReplaceFunctionIf("expand_field_assignment", "return x;", IfIrixBootstrap, Source + "/gcc/combine.c")

#
# Irix /usr/WorkShop/usr/bin/ncc doesn't like .c files that #include themselves.
# It compiles them without error, but incorrectly -- their symbols aren't found when linking.
#

ChangeLine(
    "libmpfr_la_SOURCES = mpfr.h mpf2mpfr.h mpfr-gmp.h mpfr-impl.h mpfr-longlong.h mpfr-thread.h exceptions.c extract.c uceil_exp2.c uceil_log2.c ufloor_log2.c add.c add1.c add_ui.c agm.c clear.c cmp.c cmp_abs.c cmp_si.c cmp_ui.c comparisons.c div_2exp.c div_2si.c div_2ui.c div.c div_ui.c dump.c eq.c exp10.c exp2.c exp3.c exp.c frac.c get_d.c get_exp.c get_str.c init.c inp_str.c isinteger.c isinf.c isnan.c isnum.c const_log2.c log.c mul_2exp.c mul_2si.c mul_2ui.c mul.c mul_ui.c neg.c next.c out_str.c const_pi.c pow.c pow_si.c pow_ui.c print_raw.c print_rnd_mode.c random2.c random.c reldiff.c round_prec.c set.c setmax.c setmin.c set_d.c set_dfl_prec.c set_exp.c set_rnd.c set_f.c set_prc_raw.c set_prec.c set_q.c set_si.c set_str.c set_str_raw.c set_ui.c set_z.c sqrt.c sqrt_ui.c sub.c sub1.c sub_ui.c rint.c ui_div.c ui_sub.c urandomb.c get_z_exp.c swap.c  factorial.c cosh.c sinh.c tanh.c acosh.c asinh.c atanh.c atan.c cmp2.c exp_2.c asin.c const_euler.c cos.c sin.c tan.c fma.c fms.c hypot.c log1p.c expm1.c log2.c log10.c ui_pow.c ui_pow_ui.c minmax.c dim.c signbit.c copysign.c setsign.c gmp_op.c init2.c acos.c sin_cos.c set_nan.c set_inf.c powerof2.c gamma.c set_ld.c get_ld.c cbrt.c volatile.c fits_s.h fits_sshort.c fits_sint.c fits_slong.c fits_u.h fits_ushort.c fits_uint.c fits_ulong.c fits_uintmax.c fits_intmax.c get_si.c get_ui.c zeta.c cmp_d.c erf.c inits.c inits2.c clears.c sgn.c check.c sub1sp.c version.c mpn_exp.c mpfr-gmp.c mp_clz_tab.c sum.c add1sp.c free_cache.c si_op.c cmp_ld.c set_ui_2exp.c set_si_2exp.c set_uj.c set_sj.c get_sj.c get_uj.c get_z.c iszero.c cache.c sqr.c int_ceil_log2.c isqrt.c strtofr.c pow_z.c logging.c mulders.c get_f.c round_p.c erfc.c atan2.c subnormal.c const_catalan.c root.c gen_inverse.h sec.c csc.c cot.c eint.c sech.c csch.c coth.c round_near_x.c constant.c abort_prec_max.c stack_interface.c lngamma.c zeta_ui.c set_d64.c get_d64.c jn.c yn.c remquo.c get_patches.c",
    "libmpfr_la_SOURCES = mpfr.h mpf2mpfr.h mpfr-gmp.h mpfr-impl.h mpfr-longlong.h mpfr-thread.h exceptions.c extract.c uceil_exp2.c uceil_log2.c ufloor_log2.c add.c add1.c add_ui.c agm.c clear.c cmp.c cmp_abs.c cmp_si.c cmp_ui.c comparisons.c div_2exp.c div_2si.c div_2ui.c div.c div_ui.c dump.c eq.c exp10.c exp2.c exp3.c exp.c frac.c get_d.c get_exp.c get_str.c init.c inp_str.c isinteger.c isinf.c isnan.c isnum.c const_log2.c log.c mul_2exp.c mul_2si.c mul_2ui.c mul.c mul_ui.c neg.c next.c out_str.c const_pi.c pow.c pow_si.c pow_ui.c print_raw.c print_rnd_mode.c random2.c random.c reldiff.c round_prec.c set.c setmax.c setmin.c set_d.c set_dfl_prec.c set_exp.c set_rnd.c set_f.c set_prc_raw.c set_prec.c set_q.c set_si.c set_str.c set_str_raw.c set_ui.c set_z.c sqrt.c sqrt_ui.c sub.c sub1.c sub_ui.c rint.c ui_div.c ui_sub.c urandomb.c get_z_exp.c swap.c  factorial.c cosh.c sinh.c tanh.c acosh.c asinh.c atanh.c atan.c cmp2.c exp_2.c asin.c const_euler.c cos.c sin.c tan.c fma.c fms.c hypot.c log1p.c expm1.c log2.c log10.c ui_pow.c ui_pow_ui.c minmax.c dim.c signbit.c copysign.c setsign.c gmp_op.c init2.c acos.c sin_cos.c set_nan.c set_inf.c powerof2.c gamma.c set_ld.c get_ld.c cbrt.c volatile.c fits_s.h fits_sshort.c fits_sint.c fits_slong.c fits_u.h fits_ushort.c fits_uint.c fits_ulong.c fits_uintmax.c fits_intmax.c get_si.c get_ui.c zeta.c cmp_d.c erf.c inits.c inits2.c clears.c sgn.c check.c sub1sp.c version.c mpn_exp.c mpfr-gmp.c mp_clz_tab.c sum.c add1sp.c free_cache.c si_op.c cmp_ld.c set_ui_2exp.c set_si_2exp.c set_uj.c set_sj.c get_sj.c get_uj.c get_z.c iszero.c cache.c sqr.c int_ceil_log2.c isqrt.c strtofr.c pow_z.c logging.c mulders.c get_f.c round_p.c erfc.c atan2.c subnormal.c const_catalan.c root.c gen_inverse.h sec.c csc.c cot.c eint.c sech.c csch.c coth.c round_near_x.c constant.c abort_prec_max.c stack_interface.c lngamma.c zeta_ui.c set_d64.c get_d64.c jn.c yn.c remquo1.c remquo2.c get_patches.c",
    Source + "/mpfr/Makefile.am")

ChangeLine(
    "	get_d64$U.lo jn$U.lo yn$U.lo remquo$U.lo get_patches$U.lo",
    "	get_d64$U.lo jn$U.lo yn$U.lo remquo1$U.lo remquo2$U.lo get_patches$U.lo",
    Source + "/mpfr/Makefile.in")

ChangeLine(
    "	set_d64.c get_d64.c jn.c yn.c remquo.c get_patches.c",
    "	set_d64.c get_d64.c jn.c yn.c remquo1.c remquo2.c get_patches.c",
    Source + "/mpfr/Makefile.in")

CreateFile(
    Source + "/mpfr/remquo1.c",
    "#define _INSIDE_REMQUO\n"
    + "#include \"mpfr-impl.h\"\n"
    + "#include \"remquo.c\"\n");

CreateFile(
    Source + "/mpfr/remquo2.c",
    "#define _INSIDE_REMQUO\n"
    + "#include \"mpfr-impl.h\"\n"
    + "#define WANTED_BITS (sizeof(long) * CHAR_BIT - 1)\n"
    + "#define REMQUO\n"
    + "#include \"remquo.c\"\n");

#
# i686-pc-mingw32-gcc -DHAVE_CONFIG_H -I. -I/src/gccsvn/binutils -I. -D_GNU_SOURCE
#  -I. -I/src/gccsvn/binutils -I../bfd -I/src/gccsvn/binutils/../bfd -I/src/gccsvn
# /binutils/../include -D__USE_MINGW_FSEEK -DLOCALEDIR="\"/usr/local/share/locale\
# "" -Dbin_dummy_emulation=bin_vanilla_emulation   -W -Wall -Wstrict-prototypes -W
# missing-prototypes -Werror -g -c /src/gccsvn/binutils/strings.c
# cc1: warnings being treated as errors
# /src/gccsvn/binutils/strings.c: In function 'print_strings':
# /src/gccsvn/binutils/strings.c:596: error: unknown conversion type character 'L'
#  in format
# /src/gccsvn/binutils/strings.c:596: error: too many arguments for format
# /src/gccsvn/binutils/strings.c:611: error: unknown conversion type character 'L'
#  in format
# /src/gccsvn/binutils/strings.c:611: error: too many arguments for format
# /src/gccsvn/binutils/strings.c:626: error: unknown conversion type character 'L'
#  in format
# /src/gccsvn/binutils/strings.c:626: error: too many arguments for format
# make[3]: *** [strings.o] Error 1
# make[3]: Leaving directory `/obj/gcc.7/i686-pc-mingw32/i686-pc-mingw32/binutils'
#
if "binutils" in sys.argv:
    ChangeLine(
        "#if __STDC_VERSION__ >= 199901L || (defined(__GNUC__) && __GNUC__ >= 2)\n",
        "#if 0\n",
        Source + "/binutils/strings.c")
#
# ln -s libgcc.map libgcc.map.def && if [ ! -d ./shlib ]; then mkdir ./shlib else
# true; fi && ccache /obj/gcc.7/i686-pc-cygwin/i686-pc-mingw32/./gcc/xgcc -B/obj/g
# cc.7/i686-pc-cygwin/i686-pc-mingw32/./gcc/ -L/obj/gcc.7/i686-pc-cygwin/i686-pc-m
# ingw32/i686-pc-mingw32/winsup/mingw -L/obj/gcc.7/i686-pc-cygwin/i686-pc-mingw32/
# i686-pc-mingw32/winsup/w32api/lib -isystem /src/gccsvn/winsup/mingw/include -isy
# stem /src/gccsvn/winsup/w32api/include -B/usr/local/i686-pc-mingw32/bin/ -B/usr/
# local/i686-pc-mingw32/lib/ -isystem /usr/local/i686-pc-mingw32/include -isystem
# /usr/local/i686-pc-mingw32/sys-include -L/obj/gcc.7/i686-pc-cygwin/i686-pc-mingw
# 32/./ld -I/src/gccsvn/gcc/../winsup/w32api/include  -DIN_GCC -DCROSS_DIRECTORY_S
# TRUCTURE  -W -Wall -Wwrite-strings -Wstrict-prototypes -Wmissing-prototypes -Wca
# st-qual -Wold-style-definition  -isystem ./include   -g -DHAVE_GTHR_DEFAULT -DIN
# _LIBGCC2 -D__GCC_FLOAT_NOT_NEEDED  -shared -nodefaultlibs libgcc.map.def -Wl,--o
# ut-implib,./shlib/libgcc_s.a.tmp -o ./shlib/libgcc_s_1.dll.tmp -g -B./ _chkstk_s
# .o _muldi3_s.o _negdi2_s.o _lshrdi3_s.o _ashldi3_s.o _ashrdi3_s.o _cmpdi2_s.o _u
# cmpdi2_s.o _clear_cache_s.o _enable_execute_stack_s.o _trampoline_s.o __main_s.o
#  _absvsi2_s.o _absvdi2_s.o _addvsi3_s.o _addvdi3_s.o _subvsi3_s.o _subvdi3_s.o _
# mulvsi3_s.o _mulvdi3_s.o _negvsi2_s.o _negvdi2_s.o _ctors_s.o _ffssi2_s.o _ffsdi
# 2_s.o _clz_s.o _clzsi2_s.o _clzdi2_s.o _ctzsi2_s.o _ctzdi2_s.o _popcount_tab_s.o
#  _popcountsi2_s.o _popcountdi2_s.o _paritysi2_s.o _paritydi2_s.o _powisf2_s.o _p
# owidf2_s.o _powixf2_s.o _powitf2_s.o _mulsc3_s.o _muldc3_s.o _mulxc3_s.o _multc3
# _s.o _divsc3_s.o _divdc3_s.o _divxc3_s.o _divtc3_s.o _bswapsi2_s.o _bswapdi2_s.o
#  _fixunssfsi_s.o _fixunsdfsi_s.o _fixunsxfsi_s.o _fixsfdi_s.o _fixdfdi_s.o _fixx
# fdi_s.o _fixtfdi_s.o _fixunssfdi_s.o _fixunsdfdi_s.o _fixunsxfdi_s.o _fixunstfdi
# _s.o _floatdisf_s.o _floatdidf_s.o _floatdixf_s.o _floatditf_s.o _floatundisf_s.
# o _floatundidf_s.o _floatundixf_s.o _floatunditf_s.o _divdi3_s.o _moddi3_s.o _ud
# ivdi3_s.o _umoddi3_s.o _udiv_w_sdiv_s.o _udivmoddi4_s.o gthr-win32_s.o unwind-dw
# 2_s.o unwind-dw2-fde_s.o unwind-sjlj_s.o gthr-gnat_s.o unwind-c_s.o emutls_s.o -
# lmingw32 -lmingwex -lmoldname -lmsvcrt -luser32 -lkernel32 -ladvapi32 -lshell32
# && /obj/gcc.7/i686-pc-cygwin/i686-pc-mingw32/gcc/../binutils/ar -r ./shlib/libgc
# c_s.a.tmp _chkstk.o _ctors.o gthr-win32.o && if [ -f ./shlib/libgcc_s_1.dll ]; t
# hen mv -f ./shlib/libgcc_s_1.dll ./shlib/libgcc_s_1.dll.backup; else true; fi &&
#  mv ./shlib/libgcc_s_1.dll.tmp ./shlib/libgcc_s_1.dll && mv ./shlib/libgcc_s.a.t
# mp ./shlib/libgcc_s.a
# ln: creating symbolic link `libgcc.map.def': File exists
# make: *** [libgcc_s.dll] Error 1
#
ChangeLine(
    "SHLIB_LINK = $(LN_S) $(SHLIB_MAP) $(SHLIB_MAP).def && \\\n",
    "SHLIB_LINK = rm -f $(SHLIB_MAP).def; $(LN_S) $(SHLIB_MAP) $(SHLIB_MAP).def && \\\n",
    Source + "/gcc/config/i386/t-cygming")
#
# or just don't build shared libgcc, which fixes other problems on other platforms
#

def ReplaceWithinLines(Strings, Files):
    for File in Files:
        File = Source + "/" + File
        if not os.path.isfile(File):
            continue
        #print("ReplaceWithinLines: " + Strings[0] + ":" + File)
        Changed = False
        NewLines = [ ]
        OldLines = file(File).readlines()
        for Line in OldLines:
            i = 0
            while i != len(Strings):
                xLine = Line.replace(Strings[i], Strings[i + 1])
                if Line != xLine:
                    Changed = True
                    Line = xLine
                i += 2
            NewLines += Line
            #sys.stdout.write(".")
        if Changed:
            print("ReplaceWithinLines: updating " + File)
            file(File, "w").writelines(NewLines)
        else:
            print("ReplaceWithinLines: already up to date " + File)

ReplaceWithinLines(
    [" = obstack_alloc", " = (void *) obstack_alloc",
    " = oballoc", " = (void *) oballoc"],
    ["gas/hash.c", "gas/subsegs.c", "gas/symbols.c",
    "gas/write.c", "gas/config/tc-hppa.c", "gas/config/tc-ia64.c",
    "gas/config/tc-m68k.c", "gas/config/tc-score.c", "ld/ldlang.c",
    "gcc/bt-load.c", "gcc/c-parser.c", "gcc/cfg.c", "gcc/collect2.c",
    "gcc/fix-header.c", "gcc/gcse.c", "gcc/genattrtab.c", "gcc/genautomata.c",
    "gcc/genpreds.c", "gcc/regrename.c", "gcc/reload1.c", "gcc/reorg.c", "gcc/tlink.c",
    "gcc/tree-sra.c", "gcc/cp/calls.c", "gcc/cp/mangle.c", "gcc/cp/parser.c"])

def ReplaceLineSequence(From, To, Files):
    #print("ReplaceLineSequence:" + From[0] + ":" + Files[0])
    len_From = len(From)
    for File in Files:
        File = Source + "/" + File
        Changed = False
        NewLines = [ ]
        OldLines = file(File).readlines()
        len_OldLines = len(OldLines)
        i = 0
        while i != len_OldLines:
            j = 0
            while j != len_From:
                if OldLines[i + j] != From[j]:
                    break
                j += 1
            if j == len(From):
                Changed = True
                i += len_From - 1
                for j in range(len(To)):
                    NewLines += To[j]
            else:
                NewLines += OldLines[i]
            i += 1
        if Changed:
            print("ReplaceLineSequence: updating " + File)
            file(File, "w").writelines(NewLines)
        else:
            print("ReplaceLineSequence: already up to date " + File)

ReplaceLineSequence(
    ["  const int     bufsz = 4096;\n",
    "  char          symbuf [bufsz];\n"],
    ["  char          symbuf [4096];\n",
    "  const int     bufsz = sizeof(symbuf);\n"],
    ["bfd/elflink.c"]);

def RemoveCplusplusComments(Files):
    for File in Files:
        File = Source + "/" + File
        if not os.path.isfile(File):
            continue
        Changed = False
        NewLines = [ ]
        OldLines = file(File).readlines()
        for Line in OldLines:
            j = Line.find("//")
            if (j != -1) and (Line != "/*#define SHOW_NUM 1*//* Uncomment for debugging.  */\n"):
                Changed = True
                Line = Line[:j]
            NewLines += Line
        if Changed:
            print("RemoveCplusplusComments: updating " + File)
            file(File, "w").writelines(NewLines)
        else:
            print("RemoveCplusplusComments: already up to date " + File)

RemoveCplusplusComments(
    ["gas/bfin-parse.c", "gas/config/obj-coff.c", "gas/config/tc-bfin.c", "gas/config/tc-cr16.c",
    "gas/config/tc-m68k.c", "gas/config/tc-mips.c", "gas/config/tc-ns32k.c"])

def PatchOutLibIConv(Obj):
#
# libiconv is often present on the build machine, but not the later host of the same architecture,
# for example on Solaris; it would be nice to have -disable-libiconv or -without-libiconv.
#
# This is not really needed, but nice to have.
#
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
                print("PatchOutLibIConv: updating " + FilePath)
                file(FilePath, "w").writelines(NewLines)
            else:
                print("PatchOutLibIConv: already up to date " + FilePath)

def PatchOutOptimizer(Target, Obj):
#
# This is not really needed, but should provide a nice
# speed boost to building the compiler.
#
    PatchName = "CFLAGS=-g"

    T = Target

    for a in [
            ".",
            "binutils",
            "gcc", "gcc/ada",
            "gmp", "gmp/cxx",
            "gmp/demos", "gmp/demos/calc", "gmp/demos/expr",
            "gmp/doc",
            "gmp/mpbsd", "gmp/mpf", "gmp/mpn",
            "gmp/mpq", "gmp/mpz", "gmp/printf", "gmp/scanf",
            "gmp/tests", "gmp/tests/cxx", "gmp/tests/devel",
            "gmp/tests/misc", "gmp/tests/mpbsd", "gmp/tests/mpf",
            "gmp/tests/mpn", "gmp/tests/mpq", "gmp/tests/mpz",
            "gmp/tests/rand", "gmp/tune",
            "libcpp", "libdecnumber", "libiberty",
            "libstdc++-v3/doc", "libstdc++-v3/include",
            "libstdc++-v3/libmath", "libstdc++-v3/libsupc++",
            "libstdc++-v3/po", "libstdc++-v3/src",
            "libstdc++-v3/testsuite",
            "mpfr", "mpfr/tests",
            T + "/libgcc", T + "/libgfortran", T + "/libiberty",
            T + "/libiberty/testsuite", T + "/libstdc++-v3",
            T + "/libstdc++-v3/doc", T + "/libstdc++-v3/include",
            T + "/libstdc++-v3/libmath", T + "/libstdc++-v3/libsupc++",
            T + "/libstdc++-v3/po", T + "/libstdc++-v3/src",
            T + "/libstdc++-v3/testsuite", T + "/newlib",
            T + "/newlib/doc", T + "/newlib/libc",
            T + "/newlib/libc/argz", T + "/newlib/libc/ctype",
            T + "/newlib/libc/errno", T + "/newlib/libc/iconv",
            T + "/newlib/libc/iconv/ccs", T + "/newlib/libc/iconv/ccs/binary",
            T + "/newlib/libc/iconv/ces", T + "/newlib/libc/iconv/lib",
            T + "/newlib/libc/locale", T + "/newlib/libc/machine",
            T + "/newlib/libc/machine/i386", T + "/newlib/libc/misc",
            T + "/newlib/libc/posix", T + "/newlib/libc/reent",
            T + "/newlib/libc/search", T + "/newlib/libc/signal",
            T + "/newlib/libc/stdio", T + "/newlib/libc/stdio64",
            T + "/newlib/libc/stdlib", T + "/newlib/libc/string",
            T + "/newlib/libc/sys", T + "/newlib/libc/syscalls",
            T + "/newlib/libc/time", T + "/newlib/libc/unix",
            T + "/newlib/libm", T + "/newlib/libm/common",
            T + "/newlib/libm/machine", T + "/newlib/libm/machine/i386",
            T + "/newlib/libm/math", T + "/newlib/libm/mathfp",
            T + "/winsup/lsaauth", T + "/winsup/mingw",
            T + "/winsup/w32api", T + "/winsup/w32api/lib",
            T + "/winsup/w32api/lib/ddk", T + "/winsup/w32api/lib/directx",
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
                print("PatchOutOptimizer: updating " + FilePath)
                file(FilePath, "w").writelines(NewLines)
            else:
                print("PatchOutOptimizer: already up to date " + FilePath)

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
    # GNU ld does not work for targeting Irix due to not fully
    # investigated reasons. Therefore only Irix native is supported,
    # and don't use GNU ld. There are two problems:
    #  ld does not find libc, even with sys-root
    #  If you point ld at libc directly, there are assertion failures in ld.
    #  This has been seen in both Cygwin and GNU/Linux/x86.
    #

    if Target.find("irix") != -1:
        if Build == Host and Host == Target:
            ExtraConfig += " -without-gnu-ld "
            ExtraConfig += " CC='/usr/WorkShop/usr/bin/ncc -w' "
            ExtraConfig += " -disable-dependency-tracking "
            ExtraConfig += " -enable-languages=c "
        else:
            print("ERROR: non-native Irix builds will not work due to problems with ld")
            sys.exit(1)
    else:
        #
        # just to speed it up
        # works without and supports more languages, such as Fortran and Java
        #
        ExtraConfig += " -enable-languages=c,c++ "

    #
    # in particular, avoiding -O2 to speed up the build, and to aid debugging
    # also set MAKEINFO to a null command for the sake of systems that don't
    # have it installed (on Debian/Ubuntu -- apt-get install texinfo)
    #

    Environ = " "
    Environ += " MAKEINFO=:"
    Environ += " CFLAGS=-g"
    Environ += " CFLAGS_FOR_BUILD=-g"
    Environ += " BOOT_CFLAGS=-g"
    Environ += " CXXFLAGS=-g"
    Environ += " CXXFLAGS_FOR_BUILD=-g"
    Environ += " FCFLAGS=-g"
    Environ += " GNATLIBCFLAGS=-g"
    #Environ += " STAGE_CC_WRAPPER=ccache"
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
        #ExtraConfig += " -disable-shared -enable-static "
        pass

    if Target.find("-cygwin") != -1:
        #
        # default is to disable threads, but threads work
        #
        ExtraConfig += " -enable-threads"

        #
        # errors building shared libgcc for lack of -lc and -lpthread on command line
        #
        #ExtraConfig += " -disable-shared -enable-static "
        pass


    if Target.find("-mingw") != -1:
        #
        # errors building shared libgcc creating symlink that might already exist
        #
        #ExtraConfig += " -disable-shared -enable-static "
        pass

    #
    # This benefits so many, just do it.
    #
    ExtraConfig += " -disable-shared -enable-static "

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

            #ExtraConfig += " -disable-shared -enable-static "

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
            if not "noconfigure" in sys.argv:
                Run(Obj, Make + " configure-" + a + " " + Environ)
            PatchOutLibIConv(Obj)
            PatchOutOptimizer(Target, Obj)
        Run(Obj, Make + " all-" + a + " " + Environ)

    Run(Obj, Make + " all " + Environ)

    if True:
        print("installing " + Host + "/" + Target)
        Date()
        Run(Obj, Make + " install " + ExtraInstall + Environ)

    if DestDir:
        print("Success; copy " + DestDir + " to your " + Host + " machine")

if "nobuild" in sys.argv:
    sys.exit(1)

Platform1 = Build

# native
DoBuild()

Platform2 = "sparc-sun-solaris2.10"
DoBuild(Platform1, Platform2)
DoBuild(Platform2, Platform2)

Platform2 = "sparc64-sun-solaris2.10"
DoBuild(Platform1, Platform2)
DoBuild(Platform2, Platform2)

Platform2 = "i686-pc-mingw32"
DoBuild(Platform1, Platform2)
DoBuild(Platform2, Platform2)

Platform2 = "i586-pc-msdosdjgpp"
DoBuild(Platform1, Platform2)
DoBuild(Platform2, Platform2)

Platform2 = "mips-sgi-irix6.5"
DoBuild(Platform1, Platform2)
DoBuild(Platform2, Platform2)
