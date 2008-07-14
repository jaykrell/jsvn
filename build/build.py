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

DoCleanSource = True

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
# However the combined tree reduces the obvious need for loops, at least for gcc/binutils/gmp/mpfr.
#  (We should really still build gmp/mpfr independently so we can install them independently/shared).
#


#
# a fully combined tree builds much more than necessary
#
# D:\obj\gcc>for %a in ( libiberty.a libgmp.a libmpfr.a ) do dir /s/b %a
#
#
# We only need two of these (first two are the same? but much different in size, I think I know why.).
#
#
#   --build=i686-pc-cygwin
#   --host=none-pc-cygwin
#   --target=none-pc-cygwin
# D:\obj\gcc\i686-pc-cygwin\i686-pc-cygwin\gmp\.libs\libgmp.a
#
#   --build=i686-pc-cygwin
#   --host=none-pc-cygwin
#   --target=none-pc-cygwin
# D:\obj\gcc\i686-pc-cygwin\sparc-sun-solaris2.10\gmp\.libs\libgmp.a
#
#   --build=i686-pc-cygwin
#   --host=none-sun-solaris2.10
#   --target=none-sun-solaris2.10
# D:\obj\gcc\sparc-sun-solaris2.10\sparc-sun-solaris2.10\gmp\.libs\libgmp.a
#
# D:\obj\gcc\i686-pc-cygwin\i686-pc-cygwin\mpfr\.libs\libmpfr.a
# D:\obj\gcc\i686-pc-cygwin\sparc-sun-solaris2.10\mpfr\.libs\libmpfr.a
# D:\obj\gcc\sparc-sun-solaris2.10\sparc-sun-solaris2.10\mpfr\.libs\libmpfr.a
#
# And two of these (ok, multilibs showing here too, three of these if you allow that,
# and this is still building, might build more?):
#
#
# These are all build=host=target=i686-pc-cygwin
#   D:\obj\gcc\i686-pc-cygwin\i686-pc-cygwin\build-i686-pc-cygwin\libiberty\libiberty.a
#   D:\obj\gcc\i686-pc-cygwin\i686-pc-cygwin\i686-pc-cygwin\libiberty\libiberty.a
#   D:\obj\gcc\i686-pc-cygwin\i686-pc-cygwin\libiberty\libiberty.a
#
#    --build=i686-pc-cygwin
#    --host=i686-pc-cygwin
#    --target=sparc-sun-solaris2.10
# D:\obj\gcc\i686-pc-cygwin\sparc-sun-solaris2.10\build-i686-pc-cygwin\libiberty\libiberty.a
#

#
#    --build=i686-pc-cygwin
#    --host=i686-pc-cygwin
#    --target=sparc-sun-solaris2.10
# D:\obj\gcc\i686-pc-cygwin\sparc-sun-solaris2.10\libiberty\libiberty.a
#

#   --build=i686-pc-cygwin
#   --host=sparc-sun-solaris2.10
#   --target=sparc-sun-solaris2.10
# D:\obj\gcc\i686-pc-cygwin\sparc-sun-solaris2.10\sparc-sun-solaris2.10\libiberty\libiberty.a

# D:\obj\gcc\i686-pc-cygwin\sparc-sun-solaris2.10\sparc-sun-solaris2.10\sparcv9\libiberty\libiberty.a
#
# D:\obj\gcc\sparc-sun-solaris2.10\sparc-sun-solaris2.10\build-i686-pc-cygwin\libiberty\libiberty.a

#
#   --build=i686-pc-cygwin
#   --host=sparc-sun-solaris2.10
#   --target=sparc-sun-solaris2.10
# D:\obj\gcc\sparc-sun-solaris2.10\sparc-sun-solaris2.10\libiberty\libiberty.a
#
# D:\obj\gcc\sparc-sun-solaris2.10\sparc-sun-solaris2.10\sparc-sun-solaris2.10\libiberty\libiberty.a
# D:\obj\gcc\sparc-sun-solaris2.10\sparc-sun-solaris2.10\sparc-sun-solaris2.10\sparcv9\libiberty\libiberty.a
#
# D:\obj\gcc\i686-pc-cygwin\i686-pc-cygwin\opcodes\libopcodes.a
# D:\obj\gcc\i686-pc-cygwin\i686-pc-cygwin\opcodes\.libs\libopcodes.a
# D:\obj\gcc\i686-pc-cygwin\sparc-sun-solaris2.10\opcodes\libopcodes.a
# D:\obj\gcc\i686-pc-cygwin\sparc-sun-solaris2.10\opcodes\.libs\libopcodes.a
# D:\obj\gcc\sparc-sun-solaris2.10\sparc-sun-solaris2.10\opcodes\libopcodes.a
# D:\obj\gcc\sparc-sun-solaris2.10\sparc-sun-solaris2.10\opcodes\.libs\libopcodes.a
#
#
#   --build=i686-pc-cygwin
#   --host=i686-pc-cygwin
#   --target=i686-pc-cygwin
#
# D:\obj\gcc\i686-pc-cygwin\i686-pc-cygwin\bfd\libbfd.a
# D:\obj\gcc\i686-pc-cygwin\i686-pc-cygwin\bfd\.libs\libbfd.a
#
#   --build=i686-pc-cygwin
#   --host=i686-pc-cygwin
#   --target=sparc-sun-solaris2.10
# D:\obj\gcc\i686-pc-cygwin\sparc-sun-solaris2.10\bfd\libbfd.a
# D:\obj\gcc\i686-pc-cygwin\sparc-sun-solaris2.10\bfd\.libs\libbfd.a
#
# D:\obj\gcc\sparc-sun-solaris2.10\sparc-sun-solaris2.10\bfd\libbfd.a
# D:\obj\gcc\sparc-sun-solaris2.10\sparc-sun-solaris2.10\bfd\.libs\libbfd.a
#
DoClean1 = True
DoClean1Gmp = True
DoClean1Mpfr = True
DoClean1Libiberty = True
DoClean1Ld = True
DoClean1Gas = True
DoClean1LibBfd = True
DoClean1LibOpcodes = True

DoClean12 = True
DoClean2 = True

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

#
# reading configure.ac, what we are most interested in is
# build_libs
#   libiberty
# build_tools
#   fixincludes
# host_tools
#   binutils
#   gas
#   ld
#   fixincludes
#   gcc
# host_libs (needed by host_tools)
#   libiberty
#   opcodes
#   bfd
#   libcpp
#   libdecnumber
#   gmp
#   mpfr
# target_libraries
#   libgcc
#   libiberty
#   libstdc++-v3
#
# In future we will want to add more.
#
#
# opcodes to bfd dependencies:
#   Makefile:BFD_H = ../bfd/bfd.h
#   Makefile:  ../bfd/bfd_stdint.h
#   Makefile:  ../bfd/bfd_stdint.h
#   Makefile:  ../bfd/bfd_stdint.h
#   Makefile:  ../bfd/bfd_stdint.h
#   Makefile:  ../bfd/bfd_stdint.h
#
# $ mkdir ../bfd
#
# jay@jay-win9 /obj/opcodes/1
# $ cp /obj/bfd/1/*.h ../bfd
#
# Remove some from targets.c and archures.c that don't compile.
#
#	&tic30_aout_vec,
#	&tic30_coff_vec,
#	&tic54x_coff0_beh_vec,
#	&tic54x_coff0_vec,
#	&tic54x_coff1_beh_vec,
#	&tic54x_coff1_vec,
#	&tic54x_coff2_beh_vec,
#	&tic54x_coff2_vec,
#	&tic80coff_vec,
#
#   &bfd_tic30_arch,
#   &bfd_tic4x_arch,
#   &bfd_tic54x_arch,
#   &bfd_tic80_arch,
#
Package_gmp = {
    "name" : "gmp",
    "target-dependent" : False,
    "runs-on-target" : False,
    }
Package_mpfr = {
    "name" : "mpfr",
    "dependencies" : [ Package_gmp ],
    "target-dependent" : False,
    "runs-on-target" : False,
    }
Package_libdecnumber = {
    "name" : "libdecnumber",
    "target-dependent" : False,
    "runs-on-target" : False,
    }
Package_libiberty = {
    "name" : "libiberty",
    "target-dependent" : False,
    "runs-on-target" : False,
    }
Package_bfd = {
    "name" : "bfd",
    "target-dependent" : False,
    "runs-on-target" : False,
    }
Package_opcodes = {
    "name" : "opcodes",
    "target-dependent" : False,
    "runs-on-target" : False,
    "dependencies" : [ Package_bfd ],
    }
Package_zlib = {
    "name" : "zlib",
    "target-dependent" : False,
    "runs-on-target" : False,
    }
Package_binutils = {
    "name" : "binutils",
    "target-dependent" : False,
    "runs-on-target" : False,
    "dependencies" : [ Package_bfd, Package_opcodes ],
    }
Package_ld = {
    "name" : "ld",
    "target-dependent" : False,
    "runs-on-target" : False,
    "dependencies" : [ Package_bfd, Package_opcodes ],
    }
Package_gas = {
    "name" : "gas",
    "target-dependent" : False,
    "runs-on-target" : False,
    "dependencies" : [ Package_bfd, Package_opcodes ],
    }
Package_libcpp = {
    "name" : "libcpp",
    "target-dependent" : False,
    "runs-on-target" : False,
    }
Package_gcc = {
    "name" : "gcc",
    "target-dependent" : True,
    "runs-on-target" : False,
    "dependencies" : [ Package_gmp, Package_mpfr, Package_libcpp, Package_libiberty, Package_libdecnumber ],
    }
Package_libjava = {
    "name" : "gcc",
    "target-dependent" : True,
    "runs-on-target" : True,
    "dependencies" : [ Package_zlib ],
    }
Package_gprof = {
    "name" : "gprof",
    "target-dependent" : False,
    "runs-on-target" : False,
    }
Package_libobjc = {
    "name" : "libobjc",
    "target-dependent" : False,
    "runs-on-target" : True,
    }
Package_libada = {
    "name" : "libada",
    "target-dependent" : False,
    "runs-on-target" : True,
    "language" : "ada",
    }
Package_libssp = {
    "name" : "libssp",
    "target-dependent" : False,
    "runs-on-target" : True,
    }
Package_libstdcppv3 = {
    "name" : "libstd++-v3",
    "target-dependent" : False,
    "runs-on-target" : True,
    "language" : "c++",
    }
Package_boehmgc = {
    "name" : "boehm-gc",
    "target-dependent" : False,
    "runs-on-target" : True,
    }
Package_gnattools = {
    "name" : "boehm-gc",
    "target-dependent" : False,
    "runs-on-target" : True,
    "language" : "ada",
    }

Packages = [
    Package_gmp,
    Package_mpfr,
    Package_libdecnumber
    Package_libiberty,
    Package_bfd
    Package_opcodes
    Package_zlib
    Package_mpfr
    Package_binutils
    Package_ld
    Package_gas
    Package_gcc
    ];

ObjRoot = "/obj/gcc"

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

ConfigCommon += " -build " + Platform1 + " "
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
# This also appears to enable gas/ld to support "everthing".
#
ConfigCommon += " -enable-targets=all "

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
WithGmp = " "
WithMpfr = " "
Config1 = ConfigCommon + Host + Target + Sysroot + WithGmp + WithMpfr + Prefix + " -enable-languages=all "
Config1 = re.sub(" +", " ", Config1)

#
# Future: Languages should be configurable
#

#
# hosted on Platform1, targeting Platform2 ("cross")
#

Host = " -host " + Platform1
Target = " -target " + Platform2
# Prefix = " -prefix " + Prefix0 + " "
Prefix = " "
# WithGmp = " -with-gmp=" + DestDir12 + Prefix0 + " "
# WithMpfr = " -with-mpfr=" + DestDir12 + Prefix0 + " "
WithGmp = " "
WithMpfr = " "
Sysroot = " -with-sysroot "
Config12 = ConfigCommon + Host + Target + Sysroot + WithGmp + WithMpfr + Prefix + " -enable-languages=c,c++ "
Config12 = re.sub(" +", " ", Config12)

#
# Platform2 ("Canadian cross, er.. cross native?")
#

Host = " -host " + Platform2
Target = " -target " + Platform2 + " "
# Prefix = " -prefix " + Prefix0 + " "
Prefix = " "
# WithGmp = " -with-gmp=" + DestDir2 + Prefix0 + " "
# WithMpfr = " -with-mpfr=" + DestDir2 + Prefix0 + " "
WithGmp = " "
WithMpfr = " "
Sysroot = " "
Config2 = ConfigCommon + Host + Target + Sysroot + WithGmp + WithMpfr + Prefix + " -enable-languages=c,c++ "
Config2 = re.sub(" +", " ", Config2)


#
# Some of this could be multithreaded/overlapped, but I get a lot of:
#   "error: can't allocate lock", when I try to use threads in Python (Cygwin?)
#

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
    else:
        #
        # workaround Win32 Python + Cygwin symlinks?
        #
        Wait(Run([None], ".", "rm -rf " + a + "/*"))

def EmptyDir(clean, a):
    if clean:
        if False and os.name == "nt":
            DeleteRoot(a)
        else:
            #
            # workaround Win32 Python + Cygwin symlinks?
            #
            Wait(Run([None], ".", "rm -rf " + a))
    CreateDirectories(a)


def CreateDirectories(a):
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
    CreateDirectories(Directory);
    for ext in [".tar.gz", ".tgz"]:
        if os.path.exists(File + ext):
            return Run([None], Directory, "tar --strip-components=1 -zxf " + File + ext)

    for ext in [".tar.bz2", ".tbz"]:
        if os.path.exists(File + ext):
            return Run([None], Directory, "tar --strip-components=1 -jxf " + File + ext)

    for ext in [".tlz", ".tar.lzma"]:
        if os.path.exists(File + ext):
            return Run([None], Directory, "tar --strip-components=1 --lzma -xf " + File + ext)

    return Run([None], Directory, "tar tar --strip-components=1 -xf " + File)

#
# These represent processes, that can be waited on.
# Default everything to "None", which is considered immediately finished,
# for the case of not running something.
#

ExtractGmp = None
ExtractMpfr = None
ExtractBinutils = None
ExtractGcc = None
Configure = None
Make = None
Install = None

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

EmptyDir(DoCleanSource, "/src/gcc")
if DoCleanSource:
    #
    # binutils must precede gcc so that gcc replaces common files
    #
    ExtractBinutils = Extract("/src/gcc", "/net/distfiles/" + VersionBinutils)
    ExtractGcc = Extract("/src/gcc", "/net/distfiles/" + VersionGcc)
    ExtractGmp = Extract("/src/gcc/gmp", "/net/distfiles/" + VersionGmp)
    ExtractMpfr = Extract("/src/gcc/mpfr", "/net/distfiles/" + VersionMpfr)

#
# create output directories
#

EmptyDir(DoClean1, ObjRoot + "/" + Platform1 + "/" + Platform1)
EmptyDir(DoClean12, ObjRoot + "/" + Platform1 + "/" + Platform2)
EmptyDir(DoClean2, ObjRoot + "/" + Platform2 + "/" + Platform2)

#
# bring native libs/tools up to date
#

Obj = ObjRoot + "/" + Platform1 + "/" + Platform1
if DoConfigure1:
    Configure = Run([ExtractGcc, ExtractGmp, ExtractMpfr, ExtractBinutils], Obj, "/src/gcc/configure " + Config1)
if DoMake1:
    Make = Run([Configure], Obj, "make")
if DoInstall1:
    Install = Run([Make], Obj, "make install")
Wait(Install)


#
# hosted on Platform1, targeting Platform2
#

Configure = None
Make = None
Install = None
Obj = ObjRoot + "/" + Platform1 + "/" + Platform2

if DoConfigure12:
    Configure = Run([ExtractGcc, ExtractGmp, ExtractMpfr, ExtractBinutils], Obj, "/src/gcc/configure " + Config12)
if DoMake12:
    Make = Run([Configure], Obj, "make")
if DoInstall12:
    Install = Run([Make], Obj, "make install")
Wait(Install)


#
# Platform2
#

Configure = None
Make = None
Install = None
Obj = ObjRoot + "/" + Platform2 + "/" + Platform2

if DoConfigure2:
    Configure = Run([ExtractGcc, ExtractGmp, ExtractMpfr, ExtractBinutils], Obj, "/src/gcc/configure " + Config2)
if DoMake2:
    Make = Run([Configure], Obj, "make")
if DoInstall2:
    Install = Run([Make], Obj, "make install DESTDIR=" + DestDir2)
Wait(Install)


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
