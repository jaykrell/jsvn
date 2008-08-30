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
Source = "/src/gcc"
GccVersion = "4.3.1"

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
ConfigCommon += " -enable-threads "

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
# to target each other.
#
ConfigCommon += " -disable-multilib "

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


#
# Some of this could be multithreaded/overlapped, but I get a lot of:
#   "error: can't allocate lock", when I try to use threads in Python (Cygwin?)
#

TargetDjgppEnv = "ac_cv_func_shl_load=no"
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
# binutils must precede gcc so that gcc replaces common files
#
Extract(Source, Source + "/binutils", "/net/distfiles/" + "binutils-2.18")
Extract(Source, Source + "/gcc", "/net/distfiles/" + "gcc-4.3.2")
Extract(Source + "/gmp", Source + "/gmp", "/net/distfiles/" + "gmp-4.2.3")
Extract(Source + "/mpfr", Source + "/mpfr", "/net/distfiles/" + "mpfr-2.3.1")


def PatchBigStack():
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
    FilePath = Source + "/config/mh-cygwin"
    PatchName = "gcc needs very large stack"
    print("patching " + PatchName + " in " + FilePath)
    Lines = file(FilePath).readlines()
    HasLineAlready = False
    LineToAdd = "LDFLAGS = -Wl,--stack,8388608\n"
    for Line in Lines:
        if Line == LineToAdd:
            HasLineAlready = True
            break
    if not HasLineAlready:
        Lines += LineToAdd
        file(FilePath, "w").writelines(Lines)
    print("done patching " + PatchName + " in " + FilePath)

PatchBigStack()

def PatchGmp():
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
    FilePath = Source + "/gmp/configure"
    PatchName = "M4=m4-not-needed"
    print("patching " + PatchName + " in " + FilePath)
    OldLines = file(FilePath).readlines()
    NewLines = [ ]
    Changed = False
    for OldLine in OldLines:
        NewLine = OldLine
        if not Changed:
            if NewLine == "  M4=m4-not-needed\n":
                NewLine = "  : # " + NewLine
                Changed = True
        NewLines += NewLine
    if Changed:
        file(FilePath, "w").writelines(NewLines)
    print("done patching " + PatchName + " in " + FilePath)

PatchGmp()

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


def PatchOutOptimizer(Obj):
#
# This is not really needed, but should provide a nice
# speed boost to building the compiler.
#
    PatchName = "CFLAGS=-g"

    for a in ["binutils", "gcc", "libcpp", "libdecnumber", ".", "libiberty",
            "libstdc++-v3/include",
            "libstdc++-v3/libmath", "libstdc++-v3/libsupc++", "libstdc++-v3/doc",
            "libstdc++-v3/po", "libstdc++-v3/src", "libstdc++-v3/testsuite" ]:
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
                if NewLine.find("-O2") != -1:
                    if (   (NewLine == "CFLAGS = -g -O2\n")
                            or (NewLine == "CFLAGS = -O2 -g -g\n")
                            or (NewLine == "CXXFLAGS = -O2 -g -g -O2\n")
                            or (NewLine == "BOOT_CFLAGS= -g -O2\n")
                            or (NewLine == "CFLAGS_FOR_TARGET = -O2 -g $(CFLAGS) $(SYSROOT_CFLAGS_FOR_TARGET) \\\n")
                            or (NewLine == "CXXFLAGS_FOR_TARGET = -O2 -g $(CXXFLAGS) $(SYSROOT_CFLAGS_FOR_TARGET) \\\n")
                            or (NewLine == "LIBGCC2_CFLAGS = -O2 $(LIBGCC2_INCLUDES) $(GCC_CFLAGS) $(TARGET_LIBGCC2_CFLAGS) \\\n")
                            or (NewLine == "CRTSTUFF_CFLAGS = -O2 $(GCC_CFLAGS) $(INCLUDES) $(MULTILIB_CFLAGS) -g0 \\\n")
                            # next line has a tab
                            or (NewLine == "	$(CC) -c $(ALL_ADAFLAGS) $(FORCE_DEBUG_ADAFLAGS) -O2 $(ADA_INCLUDES) \\\n")):
                        NewLine = NewLine.replace(" -O2\n", "\n")
                        NewLine = NewLine.replace(" -O2 ", " ")
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
    PatchName = "inability to find sparc64 libgcc.so"
    print("patching install " + PatchName)
    Directory = Prefix + "/lib/gcc/sparc64-sun-solaris2.10/" + GccVersion
    Run(".", "mkdir -p " + Directory)
    Run(Directory, "-ln -s sparcv9/libgcc_s.so libgcc_s.so")
    Run(Directory, "-ln -s sparcv9/libgcc_s.so.1 libgcc_s.so.1")
    print("done patching " + PatchName)

WorkaroundUnableToFindSparc64LibGcc()

def Date():
    Run(".", "@sh -c date")

def DoBuild(Host = None, Target = None, ExtraConfig = " "):

    if Host == None:
        Host = Build

    if Target == None:
        Target = Build

    CFLAGS = "-g"
    CC = "gcc"

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
        ExtraConfig += " -enable-languages=all,ada "

    if Target.find("msdosdjgpp") != -1:
        ExtraConfig += " -enable-languages=c,c++,fortran,java,objc "

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
                    b = DefaultSysroot + "/mingw/" + a
                    if not os.path.isdir(b):
                        print("ERROR: Please create " + b + ", such as by a link (or NTFS junction) to /mingw/" + a)
                        print("")
                        print("Such as like so (on Windows):")
                        print("  install mingw, such as to c:\mingw")
                        print("  mkdir c:\cygwin\usr\local\i686-pc-mingw32\sys-root\mingw")
                        print("  \\\\live.sysinternals.com\\tools\\junction c:\\cygwin\\usr\\local\\i686-pc-mingw32\\sys-root\\mingw\\include c:\\mingw\\include")
                        print("  \\\\live.sysinternals.com\\tools\\junction c:\\cygwin\\usr\\local\\i686-pc-mingw32\\sys-root\\mingw\\lib c:\\mingw\\lib")
                        exit(1)

            #
            # normal sys-root
            #
                    
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

    Environ = " "
    Environ += " CFLAGS=\"" + CFLAGS + "\" "
    Environ += " BOOT_CFLAGS=\"" + CFLAGS + "\" "
    Environ += " CC=\"" + CC + "\" "

    print("configuring " + Host + "/" + Target)
    Date()
    if not os.path.isfile(Obj + "/Makefile"):
        CreateDirectories(Obj)
        Run(Obj, Source + "/configure -host " + Host + " -target " + Target + " " + ConfigCommon + " " + ExtraConfig + Environ)

    print("making " + Host + "/" + Target)
    Date()

    for a in ["build", "host", "target"]:
        Run(Obj, "make configure-" + a + " " + Environ)
        PatchOutLibIConv(Obj)
        PatchOutOptimizer(Obj)
        Run(Obj, "make all-" + a + " " + Environ)

    Run(Obj, "make all " + Environ)

    print("installing " + Host + "/" + Target)
    Date()
    Run(Obj, "make install " + ExtraInstall + Environ)

    if DestDir:
        print("Success; copy " + DestDir + " to your " + Host + " machine")

# native
DoBuild()

Platform1 = Build

Platform2 = "i686-pc-mingw32"
DoBuild(Platform1, Platform2)

Platform2 = "sparc64-sun-solaris2.10"
DoBuild(Platform1, Platform2)
DoBuild(Platform2, Platform2)

Platform2 = "sparc-sun-solaris2.10"
DoBuild(Platform1, Platform2)
DoBuild(Platform2, Platform2)

Platform2 = "i686-pc-mingw32"
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
