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

DoCleanSource = False

#
# steps per package
#   clean-source extract-source
#
# steps per package * configuration
#   clean-obj configure make make-check install
#
# most packages are only target specific (gmp, mpfr), some are host and target specific (binutils, gcc)
#
# We need some loops here.
#

DoClean1Gmp = False
DoClean1Mpfr = False
DoClean1Binutils = False
DoClean1Gcc = False
DoClean12Binutils = True
DoClean12Gcc = True
DoClean2Gmp = True
DoClean2Mpfr = True
DoClean2Binutils = True
DoClean2Gcc = True

DoConfigure1Gmp = False
DoConfigure1Mpfr = False
DoConfigure1Binutils = False
DoConfigure1Gcc = False
DoConfigure12Gcc = True
DoConfigure12Binutils = True
DoConfigure2Gmp = True
DoConfigure2Mpfr = True
DoConfigure2Binutils = True
DoConfigure2Gcc = True

DoMake1Gmp = False
DoMake1Mpfr = False
DoMake1Binutils = False
DoMake1Gcc = False
DoMake12Binutils = True
DoMake12Gcc = True
DoMake2Gmp = True
DoMake2Mpfr = True
DoMake2Binutils = True
DoMake2Gcc = True

DoInstall1Gmp = False
DoInstall1Mpfr = False
DoInstall1Binutils = False
DoInstall1Gcc = False
DoInstall12Binutils = True
DoInstall12Gcc = True
DoInstall2Gmp = True
DoInstall2Mpfr = True
DoInstall2Binutils = True
DoInstall2Gcc = True

VersionGcc = "gcc-4.3.1"
VersionMpfr = "mpfr-2.3.1"
VersionGmp = "gmp-4.2.2"
VersionBinutils = "binutils-2.18"

ObjRoot = "/obj"

#
# use canonical names including version
#  - sometimes they get further canonicalized, sometimes not
#  - libgcc wants a version in Platform2
#
Platform1 = "i686-pc-cygwin"
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
# DefaultSysinclude = (Prefix0 + "/" + Platform2 + "/sys-include")

if not os.path.isdir(DefaultSysroot):
    print("ERROR: Please put appropriate subset of " + Platform2 + " file system at " + DefaultSysroot + " (such as /lib, /usr/lib, /usr/include)")
    exit(1)

DestDir1 = ""
DestDir12 = ""

#
# There seems to be no convention here.
#
DestDir2 = Prefix0 + "/" + Platform2 + "/install"

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
#
ConfigCommon += " -enable-all-targets "

#
# Cygwin uses this. It sounds good.
#
ConfigCommon += " -disable-win32-registry "

#
# Similar to -enable-all-targets, for 32bit binutils.
#
ConfigCommon += " -enable-64-bit-bfd "

#
# Multilib takes a lot longer to build and is popular for people to disable.
#
# ConfigCommon += " -disable-multilib "

#
# This is probably a losing battle, but for now we use identical
# configure command for each package. At some point, there are probably
# clashing options or perhaps rejection of invalid options, however
# the second seems unlikely, given that most options just set
# sh variables that later configure code can either use or ignore,
# usually ignore.
#

#
# native
#

Host = " "
Target = " "
Prefix = " -prefix " + Prefix0 + " "
Prefix = " "
Sysroot = " "
WithGmp = " -with-gmp=" + DestDir1 + Prefix0 + " "
WithMpfr = " -with-mpfr=" + DestDir1 + Prefix0 + " "
Config1 = ConfigCommon + Host + Target + Sysroot + WithGmp + WithMpfr + Prefix + " -enable-languages=all  "
Config1 = re.sub(" +", " ", Config1)

#
# hosted on Platform1, targeting Platform2 ("cross")
#

Host = " -host " + Platform1
Target = " -target " + Platform2
Prefix = " -prefix " + Prefix0 + " "
Prefix = " "
WithGmp = " "
WithMpfr = " "
WithGmp = " -with-gmp=" + DestDir12 + Prefix0 + " "
WithMpfr = " -with-mpfr=" + DestDir12 + Prefix0 + " "
Sysroot = " -with-sysroot "
Config12 = ConfigCommon + Host + Target + Sysroot + WithGmp + WithMpfr + Prefix + " -enable-languages=c,c++  "
Config12 = re.sub(" +", " ", Config12)

#
# Platform2 ("Canadian cross, er.. cross native?")
#

Host = " -host " + Platform2
Target = " -target " + Platform2 + " "
Prefix = " -prefix " + Prefix0 + " "
Prefix = " "
WithGmp = " -with-gmp=" + DestDir2 + Prefix0 + " "
WithMpfr = " -with-mpfr=" + DestDir2 + Prefix0 + " "
Sysroot = " "
Config2 = ConfigCommon + Host + Target + Sysroot + WithGmp + WithMpfr + Prefix + " -enable-languages=c,c++ "
Config2 = re.sub(" +", " ", Config2)


#
# due to frequent occurences of "error: can't allocate lock", all this
# threading, which often works, is not used, alas
#
if False:

    def _ThreadMain(Dependents, Directory, Command):
        for Dependent in Dependents:
            Wait(Dependent)
        if Directory != ".":
            print("cd " + Directory + " && " + Command)
        else:
            print(Command)

        IgnoreError = False
        if Command[0] == '-':
            IgnoreError = True
            Command = Command[1:]

        if os.name == "nt":
            Command = "sh -c \"" + Command + "\""
        Proces = Popen(Command, cwd = Directory, shell = True)
        ExitCode = Proces.wait()

        if not IgnoreError:
            if ExitCode != 0:
                sys.exit(ExitCode) # Why doesn't this work?

    def Run(Dependents, Directory, Command):
        t = Thread(target = _ThreadMain, args = (Dependents, Directory, Command))
        t.start()
        return t

    def Wait(a):
        if a is None:
            return
        a.join()

else:

    def Run(Dependents, Directory, Command):
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

    def Wait(a):
        return a


def DeleteRoot(a):
    if False and os.name == "nt":
        print("rmdir /q/s " + a)
        if os.path.isdir(a):
            shutil.rmtree(a)
        CreateDirectory(a)
    else:
        #
        # workaround Win32 Python + Cygwin symlinks?
        #
        Wait(Run([None], ".", "rm -rf " + a + "/*"))

def DeleteDir(a):
    if False and os.name == "nt":
        DeleteRoot(a)
    else:
        #
        # workaround Win32 Python + Cygwin symlinks?
        #
        Wait(Run([None], ".", "rm -rf " + a))

def CreateDirectory(a):
    if False and os.name == "nt":
        print("mkdir " + a)
        if not os.path.isdir(a):
            os.makedirs(a)
    else:
        #
        # workaround Win32 Python + Cygwin symlinks?
        #
        Wait(Run([None], ".", "-mkdir " + a))
        Wait(Run([None], ".", "-mkdir -pv " + a))

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
    for ext in ["", ".tar", ".tar.gz", ".tgz", ".tar.bz2", ".tbz"]:
        if os.path.exists(File + ext):
            return Run([None], Directory, "tar xf " + File + ext)

    for ext in [".tlz", ".tar.lzma"]:
        if os.path.exists(File + ext):
            return Run([None], Directory, "tar --lzma -xf " + File + ext)

    return Run([None], Directory, "tar xf " + File)

#
# These represent processes, that can be waited on.
# Default everything to "None", which is considered immediately finished,
# for the case of not running something.
#

ExtractGmp = None
ExtractMpfr = None
ExtractBinutils = None
ExtractGcc = None

ConfigureGmp = None
ConfigureMpfr = None
ConfigureBinutils = None
ConfigureGcc = None

MakeGmp = None
MakeMpfr = None
MakeBinutils = None
MakeGcc = None

InstallGmp = None
InstallMpfr = None
InstallBinutils = None
InstallGcc = None

print("set -e")
print("set -x")

#
# /obj and /src are actually symlinks to /d/obj, /d/src
# /d => /cygdrive/d
# Thus we do not want to rm -rf /obj /src.
#

#
# extract source
#

if DoCleanSource:
    DeleteRoot("/src")
    CreateDirectory("/src")
    ExtractGmp = Extract("/src", "/net/distfiles/" + VersionGmp)
    ExtractMpfr = Extract("/src", "/net/distfiles/" + VersionMpfr)
    ExtractBinutils = Extract("/src", "/net/distfiles/" + VersionBinutils)
    ExtractGcc = Extract("/src", "/net/distfiles/" + VersionGcc)

#
# create output directories
#

Platforms = Platform1 + "/" + Platform1

if DoClean1Gmp:
    DeleteDir(ObjRoot + "/" + Platforms + "/" + VersionGmp)
if DoClean1Mpfr:
    DeleteDir(ObjRoot + "/" + Platforms + "/" + VersionMpfr)
if DoClean1Binutils:
    DeleteDir(ObjRoot + "/" + Platforms + "/" + VersionBinutils)
if DoClean1Gcc:
    DeleteDir(ObjRoot + "/" + Platforms + "/" + VersionGcc)

Platforms = Platform1 + "/" + Platform2

if DoClean12Binutils:
    DeleteDir(ObjRoot + "/" + Platforms + "/" + VersionBinutils)
if DoClean12Gcc:
    DeleteDir(ObjRoot + "/" + Platforms + "/" + VersionGcc)

Platforms = Platform2 + "/" + Platform2

if DoClean2Gmp:
    DeleteDir(ObjRoot + "/" + Platforms + "/" + VersionGmp)
if DoClean2Mpfr:
    DeleteDir(ObjRoot + "/" + Platforms + "/" + VersionMpfr)
if DoClean2Binutils:
    DeleteDir(ObjRoot + "/" + Platforms + "/" + VersionBinutils)
if DoClean2Gcc:
    DeleteDir(ObjRoot + "/" + Platforms + "/" + VersionGcc)

for a in ["/src",
          ObjRoot + "/" + Platform1 + "/" + Platform1 + "/" + VersionGmp,
          ObjRoot + "/" + Platform1 + "/" + Platform1 + "/" + VersionMpfr,
          ObjRoot + "/" + Platform1 + "/" + Platform1 + "/" + VersionBinutils,
          ObjRoot + "/" + Platform1 + "/" + Platform1 + "/" + VersionGcc,

          ObjRoot + "/" + Platform1 + "/" + Platform2 + "/" + VersionBinutils,
          ObjRoot + "/" + Platform1 + "/" + Platform2 + "/" + VersionGcc,

          ObjRoot + "/" + Platform2 + "/" + Platform2 + "/" + VersionGmp,
          ObjRoot + "/" + Platform2 + "/" + Platform2 + "/" + VersionMpfr,
          ObjRoot + "/" + Platform2 + "/" + Platform2 + "/" + VersionBinutils,
          ObjRoot + "/" + Platform2 + "/" + Platform2 + "/" + VersionGcc]:
    CreateDirectory(a)

#
# bring native libs/tools up to date
#

# gmp

Platforms = Platform1 + "/" + Platform1

Obj = ObjRoot + "/" + Platforms + "/" + VersionGmp
if DoConfigure1Gmp:
    ConfigureGmp = Run([ExtractGmp], Obj, "/src/" + VersionGmp + "/configure " + Config1)
if DoMake1Gmp:
    MakeGmp = Run([ConfigureGmp], Obj, "make")
    Wait(Run([MakeGmp], Obj, "make check"))
if DoInstall1Gmp:
    InstallGmp = Run([MakeGmp], Obj, "make install")

# mfpr

Obj = ObjRoot + "/" + Platforms + "/" + VersionMpfr
if DoConfigure1Mpfr:
    ConfigureMpfr = Run([ExtractMpfr, InstallGmp], Obj, "/src/" + VersionMpfr + "/configure " + Config1)
if DoMake1Mpfr:
    MakeMpfr = Run([ConfigureMpfr], Obj, "make")
if DoInstall1Mpfr:
    InstallMpfr = Run([MakeMpfr], Obj, "make install")

# binutils

Obj = ObjRoot + "/" + Platforms + "/" + VersionBinutils
if DoConfigure1Binutils:
    ConfigureBinutils = Run([ExtractBinutils], Obj, "/src/" + VersionBinutils + "/configure " + Config1)
if DoMake1Binutils:
    MakeBinutils = Run([ConfigureBinutils], Obj, "make")
if DoInstall1Binutils:
    InstallBinutils = Run([MakeGcc, MakeBinutils], Obj, "make install")

# gcc
# must wait for gmp and mpfr to install

Obj = ObjRoot + "/" + Platforms + "/" + VersionGcc
if DoConfigure1Gcc:
    ConfigureGcc = Run([ExtractGcc, InstallGmp, InstallMpfr, InstallBinutils], Obj, "/src/" + VersionGcc + "/configure " + Config1)
if DoMake1Gcc:
    MakeGcc = Run([ConfigureGcc], Obj, "make")
if DoInstall1Gcc:
    InstallGcc = Run([MakeGcc, MakeBinutils], Obj, "make install")
Wait(InstallGcc)


#
# hosted on Platform1, targeting Platform2
#

ConfigureBinutils = None
ConfigureGcc = None
MakeBinutils = None
MakeGcc = None
InstallGmp = None
InstallMpfr = None
InstallBinutils = None
InstallGcc = None
Platforms = Platform1 + "/" + Platform2

# binutils

Obj = ObjRoot + "/" + Platforms + "/" + VersionBinutils
if DoConfigure12Binutils:
    ConfigureBinutils = Run([ExtractBinutils], Obj, "/src/" + VersionBinutils + "/configure " + Config12)
if DoMake12Binutils:
    MakeBinutils = Run([ConfigureBinutils], Obj, "make")
if DoInstall12Binutils:
    InstallBinutils = Run([MakeGcc, MakeBinutils], Obj, "make install")

# gcc

Obj = ObjRoot + "/" + Platforms + "/" + VersionGcc
if DoConfigure12Gcc:
    ConfigureGcc = Run([ExtractGcc, InstallGmp, InstallMpfr, InstallBinutils], Obj, "/src/" + VersionGcc + "/configure " + Config12)
if DoMake12Gcc:
    MakeGcc = Run([ConfigureGcc], Obj, "make")
if DoInstall12Gcc:
    InstallGcc = Run([MakeGcc], Obj, "make install")
Wait(InstallGcc)


#
# Platform2
#

ConfigureGmp = None
ConfigureMpfr = None
ConfigureBinutils = None
ConfigureGcc = None
MakeGmp = None
MakeMpfr = None
MakeBinutils = None
MakeGcc = None
InstallGmp = None
InstallMpfr = None
InstallBinutils = None
InstallGcc = None
Platforms = Platform2 + "/" + Platform2

# gmp

Obj = ObjRoot + "/" + Platforms + "/" + VersionGmp
if DoConfigure2Gmp:
    ConfigureGmp = Run([ExtractGmp], Obj, "/src/" + VersionGmp + "/configure " + Config2)
if DoMake2Gmp:
    MakeGmp = Run([ConfigureGmp], Obj, "make")
if DoInstall2Gmp:
    InstallGmp = Run([MakeGmp], Obj, "make install DESTDIR=" + DestDir2)

# mpfr

Obj = ObjRoot + "/" + Platforms + "/" + VersionMpfr
if DoConfigure2Mpfr:
    ConfigureMpfr = Run([ExtractMpfr, InstallGmp], Obj, "/src/" + VersionMpfr + "/configure " + Config2)
if DoMake2Mpfr:
    MakeMpfr = Run([ConfigureMpfr], Obj, "make")
if DoInstall2Mpfr:
    InstallMpfr = Run([MakeMpfr], Obj, "make install DESTDIR=" + DestDir2)

# binutils

Obj = ObjRoot + "/" + Platforms + "/" + VersionBinutils
if DoConfigureBinutils2:
    ConfigureBinutils = Run([ExtractBinutils], Obj, "/src/" + VersionBinutils + "/configure " + Config2)
if DoMakeBinutils2:
    MakeBinutils = Run([ConfigureBinutils], Obj, "make")
if DoInstallBinutils2:
    InstallBinutils = Run([MakeBinutils], Obj, "make install DESTDIR=" + DestDir2)

# gcc

Obj = ObjRoot + "/" + Platforms + "/" + VersionGcc
if DoConfigure2Gcc:
    ConfigureGcc = Run([ExtractGcc, InstallGmp, InstallMpfr, InstallBinutils], Obj, "/src/" + VersionGcc + "/configure " + Config2)
if DoMake2Gcc:
    MakeGcc = Run([ConfigureGcc], Obj, "make")
if DoInstall2Gcc:
    InstallGcc = Run([MakeGcc], Obj, "make install DESTDIR=" + DestDir2)
Wait(InstallGcc)


print("Success; copy " + DestDir2 + " to your " + Platform2 + " machine")


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
