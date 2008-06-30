#! /usr/bin/env python

#
# Given a working system <platform1>, <platform2> sysroot:
#   - build current native tools
#   - build current cross tools
#   - cross build native tools
#
# sysroot is actually copying the file system from one machine to
# another, though heavily subsetted. -- /usr/include, /lib, /usr/lib
# being the important parts, and these heavily subsettable.
#
# Almost everything below is editable. One size doesn't fit all.
#

import os
import sys
from subprocess import Popen
from threading import Thread

DoAllClean = False
DoAllClean = True
DoClean1 = False or DoAllClean
DoClean2 = False or DoAllClean
DoClean12 = False or DoAllClean
DoClean2 = True or DoAllClean
DoClean12 = True or DoAllClean
DoConfigure1 = False or DoClean1 or DoAllClean
DoConfigure2 = False or DoClean2 or DoAllClean
DoConfigure12 = False or DoClean12 or DoAllClean
DoExtractSource = False or DoAllClean

VersionGcc = "4.3.1"
VersionMpfr = "2.3.1"
VersionGmp = "4.2.2"
VersionBinutils = "2.18"

#
# use canonical names including version
#  - sometimes they get further canonicalized, sometimes not
#  - libgcc wants a version in Platform2
#
Platform1 = "i686-pc-cygwin"
Platform2 = "sparc-sun-solaris2.10"

Local = "/local"
Local = ""

#
# Check for some basic utilities.
# file
# make; GNU probably required?
# sed
# gcc; can another cc work?
# sh
# bash?
# mkdir (Python builtin doesn't work)
# rm (could use Python builtin?)
#


#
# Consider shortening these paths to like /<Platform>/sys-root or /sys-root/<Platform>.
#
# /usr/local/<Platform2>/sys-root must be prepared ahead of time
# with a /usr/include and /usr/local or a subset thereof from Platform2.
# Resulting in /usr/local/<Platform2>/sys-root/usr/include, /usr/local/<Platform2>/sys-root/usr/lib
#
DefaultSysroot = ("/usr" + Local + "/" + Platform2 + "/sys-root")
DefaultSysinclude = ("/usr" + Local + "/" + Platform2 + "/sys-include")

if os.path.isdir(DefaultSysroot):
    GccSysroot = " -with-sysroot=" + DefaultSysroot + " -with-build-sysroot=" + DefaultSysroot + " "
    BinutilsSysroot = GccSysroot
else:
    if os.path.isdir(DefaultSysinclude):
        GccSysroot = " "
        BinutilsSysroot = " "
    else:
        #        
        # should pause here and let user confirm
        # Should also try to get the files via NFS or ftp.
        # e.g. for some targets, the files are freely and easily downloadable (varying "free")
        #        
        # print("WARNING: neither " + DefaultSysroot + " nor " + DefaultSysinclude + " exist, will TRY -without-headers, this might not work");
        GccSysroot = " -without-headers "
        BinutilsSysroot = " "

#
# Replace previous.
# Note that binutils allowance of -with-sysroot is not documented clearly.
# Note that the meaning of -with-build-sysroot and -with-sysroot is unclear.
# Is it read only? Is it installed to? Is it copied from? What is
# the difference between the sysroot and build-sysroot? Does the setting
# persist in the tools when copied to the new host?
#
GccSysroot = " -with-sysroot=/" + Platform2 + "/sys-root -with-build-sysroot=/" + Platform2 + "/sys-root "
BinutilsSysroot = GccSysroot

#
# There seems to be no convention around Prefix2 so we make one up.
# People use stuff like /usr/compiler/cross/<platform2>, etc.
#
Prefix1 = "/usr" + Local
Prefix2 = "/usr" + Local + "/" + Platform2 + "/install"
Prefix2 = "/" + Platform2 + "/install"

Prefix = " -prefix " + Prefix1 + " "
WithGmp = " "
WithMpfr = " "

ConfigCommon = " "
ConfigCommon += " -verbose "
ConfigCommon += " -disable-nls "
ConfigCommon += " -with-gnu-as "
ConfigCommon += " -with-gnu-ld "
ConfigCommon += " -disable-bootstrap "
ConfigCommon += " -enable-threads "
ConfigCommon += " -enable-cld "
ConfigCommon += " -enable-__cxa_atexit "
ConfigCommon += " -enable-version-specific-runtime-libs "
ConfigCommon += " -disable-checking "
ConfigCommon += " -enable-all-targets " # gcc
ConfigCommon += " -enable-languages=all " # gcc
ConfigCommon += " -disable-win32-registry " # gcc
ConfigCommon += " -enable-64-bit-bfd " # binutils

ConfigGmp = ConfigCommon
ConfigMpfr = ConfigCommon
ConfigBinutils = ConfigCommon
ConfigGcc = ConfigCommon

# ConfigGmp += " -disable-shared "
# ConfigMpfr += " -disable-shared "
# ConfigBinutils += " -disable-checking "
# ConfigGcc += " -disable-checking "
# ConfigGcc += " -disable-libgomp -disable-libssp "

#
# otherwise:
# /usr/sparc-sun-solaris2.10/bin/ld: skipping incompatible /sparc-sun-solaris2.10/sys-root/usr/lib/libc.so when searching for -lc
# /usr/sparc-sun-solaris2.10/bin/ld: cannot find -lc
# collect2: ld returned 1 exit status
# make[4]: *** [libgcc_s.so] Error 1
# make[4]: Leaving directory `/cygdrive/d/obj/gcc12/sparc-sun-solaris2.10/sparcv9/libgcc'
#
# Try more combinations?
#
Config12 = " -disable-multilib -disable-shared "
Config2 = " -disable-multilib -disable-shared "
Config12 = " -disable-multilib "
Config2 = " -disable-multilib "

#
# TBD: workup ConfigGmp1, ConfigGmp2, ConfigGcc1, ConfigGcc12, ConfigGcc2, etc.
#

# ConfigGmp1 = ConfigCommon
# ConfigMpfr1 = ConfigCommon
# ConfigBinutils1 = ConfigCommon
# ConfigGcc1 = ConfigCommon

# ConfigBinutils12 = ConfigCommon
# ConfigGcc12 = ConfigCommon

# Host = " -host " + Platform2
# Prefix = " -prefix=" + Prefix2 + " "
# Target = " -target " + Platform2 + " "
# WithGmp = " -with-gmp=" + Prefix2 + " "
# WithMpfr = " -with-mpfr=" + Prefix2 + " "

# ConfigGmp2 = ConfigCommon + Host + Prefix + Config2
# ConfigMpfr2 = ConfigCommon
# ConfigBinutils2 = ConfigCommon
# ConfigGcc2 = ConfigCommon

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
        Proces = Popen(Command, cwd = Directory, shell = True)
        ExitCode = Proces.wait()
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
        ExitCode = os.system(Command)
        os.chdir(PreviousDirectory)
        if ExitCode != 0:
            sys.exit(ExitCode)
        return True

    def Wait(a):
        return a


def DeleteAll(a):
    Wait(Run([None], ".", "rm -rf " + a))

def Extract(Directory, File):
    return Run([None], Directory, "tar xf " + File)

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

#
# /obj and /src are actually symlinks to /d/obj, /d/src
# /d => /cygdrive/d
# Thus we do not want to rm -rf /obj /src.
#

#
# extract source
#

if DoExtractSource:
    DeleteAll("/src/*")
    # other forms of mkdir such as os.mkdir, os.makedirs aren't working
    os.system("mkdir /src")
    ExtractGmp = Extract("/src", "/net/distfiles/gmp-" + VersionGmp + ".tar.gz")
    ExtractMpfr = Extract("/src", "/net/distfiles/mpfr-" + VersionMpfr + ".tar.bz2")
    ExtractBinutils = Extract("/src", "/net/distfiles/binutils-" + VersionBinutils + ".tar.bz2")
    ExtractGcc = Extract("/src", "/net/distfiles/gcc-" + VersionGcc + ".tar.bz2")

#
# bring native libs/tools up to date
#

if DoAllClean:
    DeleteAll("/obj/*")

if DoClean1:
    DeleteAll("/obj/gmp1")
    DeleteAll("/obj/mpfr1")
    DeleteAll("/obj/gcc1")
    DeleteAll("/obj/binutils1")

if DoClean12:
    DeleteAll("/obj/gcc12")
    DeleteAll("/obj/binutils12")

if DoClean2:
    DeleteAll("/obj/gmp2")
    DeleteAll("/obj/mpfr2")
    DeleteAll("/obj/gcc2")
    DeleteAll("/obj/binutils2")

# other forms of mkdir such as os.mkdir, os.makedirs aren't working
os.system("mkdir /obj")
os.system("mkdir /obj/gmp1 /obj/mpfr1 /obj/binutils1 /obj/gcc1")
os.system("mkdir /obj/binutils12 /obj/gcc12")
os.system("mkdir /obj/gmp2 /obj/mpfr2 /obj/binutils2 /obj/gcc2")


# gmp

if DoConfigure1 or not os.path.exists("/obj/gmp1/config.log"):
    ConfigureGmp = Run([ExtractGmp], "/obj/gmp1", "/src/gmp-" + VersionGmp + "/configure " + ConfigGmp + Prefix)
MakeGmp = Run([ConfigureGmp], "/obj/gmp1", "make")
InstallGmp = Run([MakeGmp], "/obj/gmp1", "make install")

# mfpr

if DoConfigure1 or not os.path.exists("/obj/mpfr1/config.log"):
    ConfigureMpfr = Run([ExtractMpfr, InstallGmp], "/obj/mpfr1", "/src/mpfr-" + VersionMpfr + "/configure " + ConfigMpfr + WithGmp + Prefix)
MakeMpfr = Run([ConfigureMpfr], "/obj/mpfr1", "make")
InstallMpfr = Run([MakeMpfr], "/obj/mpfr1", "make install")

# binutils

if DoConfigure1 or not os.path.exists("/obj/binutils1/config.log"):
    ConfigureBinutils = Run([ExtractBinutils], "/obj/binutils1", "/src/binutils-" + VersionBinutils + "/configure " + ConfigBinutils + Prefix)
MakeBinutils = Run([ConfigureBinutils], "/obj/binutils1", "make")
InstallBinutils = Run([MakeGcc, MakeBinutils], "/obj/binutils1", "make install")

# gcc
# must wait for gmp and mpfr to install

if DoConfigure1 or not os.path.exists("/obj/gcc1/config.log"):
    ConfigureGcc = Run([ExtractGcc, InstallGmp, InstallMpfr, InstallBinutils], "/obj/gcc1", "/src/gcc-" + VersionGcc + "/configure " + ConfigGcc + WithGmp + WithMpfr + Prefix)
MakeGcc = Run([ConfigureGcc], "/obj/gcc1", "make")
InstallGcc = Run([MakeGcc, MakeBinutils], "/obj/gcc1",      "make install")
Wait(InstallGcc)


#
# hosted on Platform1, targeting Platform2
#

Host = " -host " + Platform1
Target = " -target " + Platform2

# binutils

if DoConfigure12 or not os.path.exists("/obj/binutils12/config.log"):
    ConfigureBinutils = Run([ExtractBinutils], "/obj/binutils12", "/src/binutils-" + VersionBinutils + "/configure " + ConfigBinutils + Host + Target + BinutilsSysroot + Prefix + Config12)
MakeBinutils = Run([ConfigureBinutils], "/obj/binutils12", "make")
InstallBinutils = Run([MakeGcc, MakeBinutils], "/obj/binutils12", "make install")

# gcc

if DoConfigure12 or not os.path.exists("/obj/gcc12/config.log"):
    ConfigureGcc = Run([ExtractGcc, InstallGmp, InstallMpfr, InstallBinutils], "/obj/gcc12", "/src/gcc-" + VersionGcc + "/configure " + ConfigGcc + Host + Target + GccSysroot + WithGmp + WithMpfr + Prefix + Config12)
MakeGcc = Run([ConfigureGcc], "/obj/gcc12", "make")
InstallGcc = Run([MakeGcc], "/obj/gcc12", "make install")
Wait(InstallGcc)


#
# Platform2
#

Host = " -host " + Platform2
Prefix = " -prefix=" + Prefix2 + " "

Target = " -target " + Platform2 + " "
WithGmp = " -with-gmp=" + Prefix2 + " "
WithMpfr = " -with-mpfr=" + Prefix2 + " "

# gmp

if DoConfigure2 or not os.path.exists("/obj/gmp2/config.log"):
    ConfigureGmp = Run([ExtractGmp], "/obj/gmp2", "/src/gmp-" + VersionGmp + "/configure " + ConfigGmp + Host + Prefix + Config2)
MakeGmp = Run([ConfigureGmp], "/obj/gmp2", "make")
InstallGmp = Run([MakeGmp], "/obj/gmp2", "make install")

# mpfr

if DoConfigure2 or not os.path.exists("/obj/mpfr2/config.log"):
    ConfigureMpfr = Run([ExtractMpfr, InstallGmp], "/obj/mpfr2", "/src/mpfr-" + VersionMpfr + "/configure " + ConfigMpfr + Host + Prefix + WithGmp + Config2)
MakeMpfr = Run([ConfigureMpfr], "/obj/mpfr2", "make")
InstallMpfr = Run([MakeMpfr], "/obj/mpfr2", "make install")

# binutils

if DoConfigure2 or not os.path.exists("/obj/binutils2/config.log"):
    ConfigureBinutils = Run([ExtractBinutils], "/obj/binutils2", "/src/binutils-" + VersionBinutils + "/configure " + ConfigBinutils + Host + Target + Prefix + Config2)
MakeBinutils = Run([ConfigureBinutils], "/obj/binutils2", "make install")
InstallBinutils = Run([MakeBinutils], "/obj/binutils2", "make install")

# gcc

if DoConfigure2 or not os.path.exists("/obj/gcc2/config.log"):
    ConfigureGcc = Run([ExtractGcc, InstallGmp, InstallMpfr, InstallBinutils], "/obj/gcc2", "/src/gcc-" + VersionGcc + "/configure " + ConfigGcc + Host + Target + Prefix + GccSysroot + WithGmp + WithMpfr + Config2)
MakeGcc = Run([ConfigureGcc], "/obj/gcc2", "make")
InstallGcc = Run([MakeGcc], "/obj/gcc2",      "make install")
Wait(InstallGcc)


print("Success; copy /usr" + Local + "/<Platform2>/install to Platform2")
