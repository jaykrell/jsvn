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
from subprocess import Popen
from threading import Thread
import shutil

#
# 1 is native
# 12 is cross
# 2 is cross-to-native
#
# These variables let you manually control incrementality after failed runs.
#

DoConfigure1 = True
DoConfigure12 = True
DoConfigure2 = True

DoMake1 = True
DoMake12 = True
DoMake2 = True

DoInstall1 = True
DoInstall12 = True
DoInstall2 = True

# -enable-static=gmp,mpfr,libgcc -disable-shared=gmp,mpfr -enable-shared=libgcc
# -enable-static=gmp,mpfr -disable-shared=gmp,mpfr

#
# FUTURE need to split notion of "package name" from "package version"
#
VersionGcc = "gcc-4.3.1"
VersionMpfr = "mpfr-2.3.1"
VersionGmp = "gmp-4.2.2"
VersionBinutils = "binutils-2.18"

ObjRoot = "/obj/gcc.5"

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

ConfigCommon = ""

#
# Sometimes it helps to specify -build explicitly, but currently we don't hit these.
# In particular, if you use a more central config.cache, -build is sniffed varyingly
# as i686-pc-cygwin and athlon64-pc-cygwin. Specifying it prevents the sniffing
# and it varying.
#

# ConfigCommon += " -build " + Platform1 + " "
ConfigCommon += " -verbose "

#
# libiconv is often present on the build machine, but not the later host of the same architecture,
# for example on Solaris; this should be called -disable-libiconv or -without-libiconv?, but is it not.
#
ConfigCommon += " -without-libiconv-prefix "

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
#ConfigCommon += " -disable-bootstrap "

#
# Cygwin defaults -enable-threads to off, but -enable-threads works, so enable it explicitly.
# However we'll probably have to remove this for DJGPP.
#
ConfigCommon += " -enable-threads "

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
# breaks bfd and binutils
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
# ConfigCommon += " -disable-multilib "

#
# random speeds ups, some people will want these
#
# ConfigCommon += " -disable-libgomp "
# ConfigCommon += " -disable-libssp "

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
    if Directory != ".":
        print("cd " + Directory + " && " + Command)
    else:
        print(Command)
    PreviousDirectory = os.getcwd()
    os.chdir(Directory)

    IgnoreError = False
    if Command[0] == '-':
        IgnoreError = True
        Command = Command[1:]

    ExitCode = 0
    if os.name == "nt":
        Command = "sh -c \"" + Command + "\""
    ExitCode = os.system(Command)
    os.chdir(PreviousDirectory)

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
def Extract(Directory, File):
    #
    # Make these more portable by running bzcat, gzcat, etc. directly.
    #
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

    Run(Directory, "tar tar --strip-components=1 -xf " + File)

#
# These represent processes, that can be waited on.
# Default everything to "None", which is considered immediately finished,
# for the case of not running something.
#

print("set -e")
print("set -x")

#
# /obj and /src are actually symlinks to /d/obj, /d/src
# /d => /cygdrive/d
# Thus we do not want to rm -rf /obj /src.
#

#
# extract source -- note we carefully extract into a "combined" tree
#

Source = "/src/gcc"

if not os.path.isdir(Source):
    #
    # binutils must precede gcc so that gcc replaces common files
    #
    Extract(Source, "/net/distfiles/" + VersionBinutils)
    Extract(Source, "/net/distfiles/" + VersionGcc)
    Extract(Source + "/gmp", "/net/distfiles/" + VersionGmp)
    Extract(Source + "/mpfr", "/net/distfiles/" + VersionMpfr)


def Configure(Obj, Options):
    if not os.path.isfile(Obj + "/Makefile"):
        CreateDirectories(Obj)
        Run(Obj, Source + "/configure " + Options)


def Make(Obj):
    Run(Obj, "make")


def Install(Obj, Options = ""):
    Run(Obj, "make install " + Options)

#
# bring native libs/tools up to date
#

def DoBuild(Host = None, Target = None, ExtraConfig = " "):

    if Host == None:
        Host = Build
    if Target == None:
        Target = Build

    #if Host != Build or Host != Target:
    ExtraConfig += " -enable-languages=c,c++ "

    print("starting " + Host + "/" + Target)
    Run(".", "sh -c date")

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
    Run(".", "sh -c date")
    Configure(Obj, ConfigCommon + ExtraConfig)

    print("making " + Host + "/" + Target)
    Run(".", "sh -c date")
    Make(Obj)

    print("installing " + Host + "/" + Target)
    Run(".", "sh -c date")
    Install(Obj, ExtraInstall)

    if DestDir:
        print("Success; copy " + DestDir + " to your " + Host + " machine")

Platform1 = Build

DoBuild()
DoBuild(Platform1, Platform2, " -with-sysroot ")
DoBuild(Platform2, Platform2)

Platform2 = "i586-pc-djgpp"

DoBuild(Platform1, Platform2)
DoBuild(Platform2, Platform2)

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
