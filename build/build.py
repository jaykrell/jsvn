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

#
# use canonical names including version
#  - sometimes they get further canonicalized, sometimes not
#  - libgcc wants a version in Platform2
#
Build = "i686-pc-cygwin"
Platform2 = "sparc-sun-solaris2.10"

Prefix0 = "/usr/local"
# Prefix0 = "/usr"

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

DefaultSysroot = (Prefix0 + "/" + Platform2 + "/sys-root")

if not os.path.isdir(DefaultSysroot):
    print("ERROR: Please put appropriate subset of " + Platform2 + " file system at " + DefaultSysroot + " (such as /lib, /usr/lib, /usr/include)")
    exit(1)

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
# Not disabling this breaks sparc64/sparc64 -- libgcc_s.so placed incorrectly.
# Perhaps an environment variable is needed.
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
    # Make these more portable by running bzcat, gzcat, etc. directly.
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

Source = "/src/gcc"

#
# binutils must precede gcc so that gcc replaces common files
#
Extract(Source, Source + "/binutils", "/net/distfiles/" + "binutils-2.18")
Extract(Source, Source + "/gcc", "/net/distfiles/" + "gcc-4.3.1")
Extract(Source + "/gmp", Source + "/gmp", "/net/distfiles/" + "gmp-4.2.2")
Extract(Source + "/mpfr", Source + "/mpfr", "/net/distfiles/" + "mpfr-2.3.1")


def PatchGmp():
    #
    # workaround problem with gmp/configure detecting flex output file
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

def Configure(Obj, Options):
    if not os.path.isfile(Obj + "/Makefile"):
        CreateDirectories(Obj)
        Run(Obj, Source + "/configure " + Options)

#
# libiconv is often present on the build machine, but not the later host of the same architecture,
# for example on Solaris; it would be nice to have -disable-libiconv or -without-libiconv.
#
def PatchOutLibIConv(Obj):

    PatchName = "libiconv dependency"

    for a in ["binutils", "gcc", "libcpp", "libdecnumber"]:
        FilePath = Obj + "/" + a
        if not os.path.isdir(FilePath):
            continue
        for b in ["Makefile", "auto-host.h", "config.h"]:
            FilePath += "/" + b
            if not os.path.isfile(FilePath):
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


def Make(Obj):
    Run(Obj, "make configure-host")    
    PatchOutLibIConv(Obj)
    Run(Obj, "make")


def Install(Obj, Options = ""):
    Run(Obj, "make install " + Options)


def DoBuild(Host = None, Target = None, ExtraConfig = " "):

    if Host == None:
        Host = Build
    if Target == None:
        Target = Build

    #if Host != Build or Host != Target:
    ExtraConfig += " -enable-languages=c,c++ "

    print("starting " + Host + "/" + Target)
    Run(".", "@sh -c date")

    ExtraInstall = " "
    DestDir = None
    if Host != Build:
        #
        # There seems to be no convention here.
        #
        DestDir = Prefix0 + "/" + Host + "/install"
        ExtraInstall = " DESTDIR=" + DestDir

    # Obj = ObjRoot + "/" + Build + "/" + Host + "/" + Target
    Obj = ObjRoot + "/" + Host + "/" + Target

    print("configuring " + Host + "/" + Target)
    Run(".", "@sh -c date")
    Configure(Obj, " -host " + Host + " -target " + Target + " " + ConfigCommon + " " + ExtraConfig)

    print("making " + Host + "/" + Target)
    Run(".", "@sh -c date")
    Make(Obj)

    print("installing " + Host + "/" + Target)
    Run(".", "@sh -c date")
    Install(Obj, ExtraInstall)

    if DestDir:
        print("Success; copy " + DestDir + " to your " + Host + " machine")

Platform1 = Build
DoBuild() # native
sys.exit(1)
DoBuild(Platform1, Platform2, " -with-sysroot ")
DoBuild(Platform2, Platform2, " -with-build-sysroot=" + Prefix0 + "/" + Platform2 + "/sys-root")

Platform2 = "sparc64-sun-solaris2.10"

DoBuild(Platform1, Platform2, " -with-sysroot ")
DoBuild(Platform2, Platform2, " -with-build-sysroot=" + Prefix0 + "/" + Platform2 + "/sys-root")

Platform2 = "i586-pc-msdosdjgpp"

DoBuild(Platform1, Platform2, " -disable-shared -enable-static -with-headers=" + Prefix0 + "/" + Platform2 + "/include ")
DoBuild(Platform2, Platform2, " -disable-shared -enable-static -with-headers=" + Prefix0 + "/" + Platform2 + "/include ")

#
# working tools
#
# i586-pc-msdosdjgpp
# sparc64-sun-solaris2.10
# i686-pc-linux
# i686-pc-cygwin
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
# i686-pc-mingwin
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
# why not build all languages:
#
# /bin/sh ./libtool --tag=GCJ --mode=compile /cygdrive/d/obj/gcc12/gcc/gcj -B/cygd
# rive/d/obj/gcc12/sparc-sun-solaris2.10/libjava/ -B/cygdrive/d/obj/gcc12/gcc/ -Us
# un -fclasspath= -fbootclasspath=/src/gcc-4.3.1/libjava/classpath/lib --encoding=
# UTF-8 -Wno-deprecated -fbootstrap-classes -g -O2 -c -o gnu/javax/swing/text/html
# /parser/HTML_401F.lo -fsource-filename=/cygdrive/d/obj/gcc12/sparc-sun-solaris2.
# 10/libjava/classpath/lib/classes -MT gnu/javax/swing/text/html/parser/HTML_401F.
# lo -MD -MP -MF gnu/javax/swing/text/html/parser/HTML_401F.deps @gnu/javax/swing/
# text/html/parser/HTML_401F.list
# libtool: compile:  /cygdrive/d/obj/gcc12/gcc/gcj -B/cygdrive/d/obj/gcc12/sparc-s
# un-solaris2.10/libjava/ -B/cygdrive/d/obj/gcc12/gcc/ -Usun -fclasspath= -fbootcl
# asspath=/src/gcc-4.3.1/libjava/classpath/lib --encoding=UTF-8 -Wno-deprecated -f
# bootstrap-classes -g -O2 -c -fsource-filename=/cygdrive/d/obj/gcc12/sparc-sun-so
# laris2.10/libjava/classpath/lib/classes -MT gnu/javax/swing/text/html/parser/HTM
# L_401F.lo -MD -MP -MF gnu/javax/swing/text/html/parser/HTML_401F.deps @gnu/javax
# /swing/text/html/parser/HTML_401F.list  -fPIC -o gnu/javax/swing/text/html/parse
# r/.libs/HTML_401F.o
# libtool: compile:  /cygdrive/d/obj/gcc12/gcc/gcj -B/cygdrive/d/obj/gcc12/sparc-s
# un-solaris2.10/libjava/ -B/cygdrive/d/obj/gcc12/gcc/ -Usun -fclasspath= -fbootcl
# asspath=/src/gcc-4.3.1/libjava/classpath/lib --encoding=UTF-8 -Wno-deprecated -f
# bootstrap-classes -g -O2 -c -fsource-filename=/cygdrive/d/obj/gcc12/sparc-sun-so
# laris2.10/libjava/classpath/lib/classes -MT gnu/javax/swing/text/html/parser/HTM
# L_401F.lo -MD -MP -MF gnu/javax/swing/text/html/parser/HTML_401F.deps @gnu/javax
# /swing/text/html/parser/HTML_401F.list -o gnu/javax/swing/text/html/parser/HTML_
# 401F.o >/dev/null 2>&1
#
# This fails.
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
