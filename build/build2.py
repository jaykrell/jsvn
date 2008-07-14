#! /usr/bin/env python

import sys
import os
import shutil
import re
import os.path
from os.path import dirname, isdir, isfile, splitext, getsize, getmtime
import stat
from shutil import copy2

#
# more later
#
RecognizedPlatforms = [
    "i686-pc-cygwin",
    "sparc-sun-solaris2.10"
    ]

Prefix0 = "/usr/local"
# Prefix0 = "/usr"

Build = ""
Host = ""
Target = ""

Platform_Build = 0
Platform_Host = 1
Platform_Target = 2
Platforms = [ Platform_Build, Platform_Host, Platform_Target ]


def Run(Directory, Command):
    if Directory != ".":
        print("cd " + Directory + " && " + Command)
    else:
        print(Command)
    PreviousDirectory = os.getcwd()
    os.chdir(Directory)

    IgnoreError = False
    if Command[0] == "-":
        IgnoreError = True
        Command = Command[1:]

    ExitCode = 0
    if os.name == "nt":
        Command = "sh -c \"" + Command + "\""
    ExitCode = os.system(Command)
    os.chdir(PreviousDirectory)

    if not IgnoreError:
        if ExitCode != 0:
            print("exiting")
            sys.exit(ExitCode)

    return True

def Configure_default(Package, Platform, Build, Host, Target, Config):
    return Config


def PatchAfterConfigure_default(Package, SourceDir, ObjDir):
    pass


def IsAlreadyBuilt(Package, ObjDir):
    for Export in Package.Exports:
        if not FileExists(ObjDir  + "/" + Export):
            #print(Package.Name + " is not already built because " + ObjDir  + "/" + Export + " does not exist")
            return False
    return True


def CreateDirectories(a):
    if not isdir(a):
        print("mkdir " + a)
        os.makedirs(a)


def CheckCygwinLink(a):
#
# This is for handling Cygwin links from Win32 Python.
# Strictly speaking, a symlink could have .lnk in its visibile name.
#
    if isfile(a):
        return False
    if splitext(a)[1] == ".lnk":
        return False
    if not isfile(a + ".lnk"):
        return False
    st = os.stat(a + ".lnk")
    if not stat.S_ISREG(st.st_mode):
        return False
    if (st.st_mode & stat.S_IWRITE):
        return False
    return True

def unused_FixPath2(a, b):
#
# This function handles varying path conventions.
# Win32 foo.exe vs. Posix foo
# MS-DOS _libs/ vs. everything else .libs/
# The first parameter must be an existant file.
#   FUTURE: allow directories
# The second parameter can be None or a path to an existing or nonexisting file.
# For this function to do anything, if b is not None, it must "allow" the same changes
#   as a. That is, if ends in .exe, but b does not, or vice versa, no change.
#   If a contains .libs/, but b does not, also no change.
# Cygwin symlinks are also handled.
#
    if isfile(a):
        return [a, b]

    if (((a.find(".libs/") != -1) or (a.find(".libs\\") != -1))
            and ((b == None) or (b.find(".libs/") != -1) or (b.find(".libs\\") != -1))
            and (not isdir(dirname(a)))
            and (isdir(dirname(a).replace(".libs/", "_libs")) or isdir(dirname(a).replace(".libs\\", "_libs")))):
        a = a.replace(".libs/", "_libs/")
        a = a.replace(".libs\\", "_libs\\")
        if b:
            b = b.replace(".libs/", "_libs/")
            b = b.replace(".libs\\", "_libs\\")
    TryExe = ((splitext(a)[1] == "") and ((b == None) or splitext(b)[1] == ""))
    TryLink = ((splitext(a)[1] != ".lnk") and ((b == None) or splitext(b)[1] != ".lnk"))
    for Exe in [False, TryExe]:
        for Link in [False, TryLink]:
            if (not Exe) and (not Link):
                continue
            Trya = a
            Tryb = b
            if Exe:
                Trya += ".exe"
                if Tryb:
                    Tryb += ".exe"
            if Link and CheckCygwinLink(Trya):
                Trya += ".lnk"
                if Tryb:
                    Tryb += ".lnk"
            if isfile(Trya):
                return [Trya, Tryb]
    return [a, b]

#def FixPath1(a):
#    return FixPath2(a, None)[0]

def FileExists(a):
    return isfile(a) or isfile(a + ".exe") or isfile(a + ".lnk")

def MyCopyFile_IfExists(From, To):
    if From == To:
        return
    CreatedDir = False
    for Ext in ["", ".exe", ".lnk"]:
        FromExt = From + Ext
        if isfile(FromExt):
            #print(FromExt + " exists")
            ToExt = To + Ext
            if not CreatedDir:
                CreateDirectories(dirname(To))
                CreatedDir = True
            print("copy " + FromExt + " " + ToExt)
            try: # Cygwin vagaries -- isfile and copy2 doesn't agree on FromExt existing
                copy2(FromExt, ToExt)
            except:
                pass

def MyCopyFile_IncrementalByTime(From, To):
    if From == To:
        return
    CreatedDir = False
    for Ext in ["", ".exe", ".lnk"]:
        FromExt = From + Ext
        if isfile(FromExt):
            #print(FromExt + " exists")
            ToExt = To + Ext
            if not isfile(ToExt):
                #print(ToExt + " does not exist")
                pass
            elif (getmtime(FromExt) - getmtime(ToExt)) > 4.76837158204e-7:
                #print(FromExt + " newer than " + ToExt + " ( " + str(getmtime(FromExt)) + ", " + str(getmtime(ToExt)) + ", " + str(getmtime(FromExt) - getmtime(ToExt)) + ")")
                pass
            else:
                continue
            if not CreatedDir:
                CreateDirectories(dirname(ToExt))
                CreatedDir = True
            print("copy " + FromExt + " " + ToExt)
            try: # Cygwin vagaries -- isfile and copy2 doesn't agree on FromExt existing
                copy2(FromExt, ToExt)
            except:
                pass

def MyCopyFile_IncrementalByTimeAndSize(From, To):
    if From == To:
        return
    CreatedDir = False
    for Ext in ["", ".exe", ".lnk"]:
        FromExt = From + Ext
        if isfile(FromExt):
            #print(FromExt + " exists")
            ToExt = To + Ext
            if not isfile(ToExt):
                #print(To + " does not exist")
                pass
            elif (getmtime(FromExt) - getmtime(ToExt)) > 4.76837158204e-7:
                #print(FromExt + " newer than " + ToExt + " ( " + str(getmtime(FromExt)) + ", " + str(getmtime(ToExt)) + ", " + str(getmtime(FromExt) - getmtime(ToExt)) + ")")
                pass
            elif getsize(FromExt) != getsize(ToExt):
                #print(FromExt + " different size than than " + ToExt)
                pass
            else:
                continue
            if not CreatedDir:
                CreateDirectories(dirname(To))
                CreatedDir = True
            print("copy " + FromExt + " " + ToExt)
            try: # Cygwin vagaries -- isfile and copy2 doesn't agree on FromExt existing
                copy2(FromExt, ToExt)
            except:
                pass

def Make_default(Package, Platform, Build, Host, Target):
    ObjDir = GetReducedObjectDirectory(Package, Platform, Build, Host, Target)
    if not IsAlreadyBuilt(Package, ObjDir):
        print("building " + Package.Name + " in " + ObjDir)
        CreateDirectories(ObjDir)
        Run(ObjDir, "make")


def Export_default(Package, Platform, Build, Host, Target):
    #
    # Really the only files that need to be exported are ones used by target-dependent
    # packages -- i.e. files used by gcc.
    #
    ObjDir1 = GetReducedObjectDirectory(Package, Platform, Build, Host, Target)
    ObjDir2 = GetExpectedObjectDirectory(Package, Platform, Build, Host, Target)
    print("copying exports from " + ObjDir1 + " to " + ObjDir2)
    CreateDirectories(ObjDir2)
    for Export in Package.Exports:
        MyCopyFile_IncrementalByTimeAndSize(ObjDir1  + "/" + Export, ObjDir2  + "/" + Export)
    for Export in Package.OptionalExports:
        if FileExists(ObjDir1  + "/" + Export):
            MyCopyFile_IncrementalByTimeAndSize(ObjDir1  + "/" + Export, ObjDir2  + "/" + Export)

    
class Package():
    def __init__(self):
        self.Host = False
        self.Target = False
        self.Build = False
        self.PatchAfterConfigure = PatchAfterConfigure_default
        self.Install = False
        self.Dependencies = [ ]
        self.OptionalDependencies = [ ]
        self.Configure = Configure_default
        self.Make = Make_default
        self.Export = Export_default
        self.Exports = [ ]
        self.OptionalExports = [ ]
        self.TargetDependent = False


class SourcePackage():
    def __init__(self):
        self.Extracted = False
        self.Directory = None
        self.Dependencies = [ ]

    
SourceRoot = "/src/gcc"
ObjRoot = "/obj/3"
CreateDirectories(ObjRoot)


p = SourcePackage()
SourcePackage_gcc = p
p.Name = "gcc"
p.Version = "4.3.1"


p = SourcePackage()
SourcePackage_gmp = p
p.Name = "gmp"
p.Version = "4.2.2"
p.Directory = "gmp"
p.Dependencies = [ SourcePackage_gcc ]


def Configure_mpfr(Package, Platform, Build, Host, Target, Config):
    #
    # duplicate the logic of toplevel configure for gmp/mpfr in the combined tree
    #
    gmpsrc = GetSourceDirectory(Package_gmp)
    gmpobj = GetReducedObjectDirectory(Package_gmp, Platform, Build, Host, Target)
    if isdir(gmpobj) and isdir(gmpsrc):
        Config += " -with-gmp-build=" + gmpobj
    return Config


p = SourcePackage()
SourcePackage_mpfr = p
p.Name = "mpfr"
p.Version = "2.3.1"
p.Directory = "mpfr"
p.Dependencies = [ SourcePackage_gcc ]
p.Configure = Configure_mpfr


p = SourcePackage()
SourcePackage_binutils = p
p.Name = "binutils"
p.Version = "2.18"
p.Dependencies = [ SourcePackage_gcc ]


SourcePackages = [
    SourcePackage_binutils,
    SourcePackage_gmp,
    SourcePackage_mpfr,
    SourcePackage_gcc,
    ]


#
# Needs work:
#   Exports: if these all exist, the package has been built
#       Should just use our own marker file.
#   OptionalExports: copy all of these
#

p = Package()
Package_gmp = p
p.Name = "gmp"
p.Exports = [ "libgmp.la", ".libs/libgmp.a", ".libs/libgmp.la" ]
p.SourcePackage = SourcePackage_gmp
p.Host = True


p = Package()
Package_libiberty = p
p.Name = "libiberty"
p.Exports = [ "libiberty.a" ]
p.SourcePackage = SourcePackage_gcc # also binutils
p.Host = True
p.Target = True
p.Build = True

p = Package()
Package_fixincludes = p
p.Name = "fixincludes"
p.Dependencies = [ Package_libiberty ]
p.Exports = [ "fixincl", "fixinc.sh" ]
p.SourcePackage = SourcePackage_gcc
p.Build = True


def GetReducedObjectDirectory(Package, Platform, Build, Host, Target):
    #
    # Generally, ObjRoot/Host/Target/Build/Package, but that is overkill,
    # and when building for multiple hosts/targets, code gets built redundantly.
    #
    # Roughly speaking:
    #
    # If package is target dependent, then
    #  ObjRoot/Host/Target/Package
    #
    # If package is not target dependent, then
    #  ObjRoot/Host/Package
    #
    # If package runs on target, then
    #  ObjRoot/Target/Package
    #
    # If package runs in build, and build != host and build != target, then
    #  ObjRoot/Build or ObjRoot/build-Build
    #
    if Package.TargetDependent:
        if Platform == Platform_Host:
            return ObjRoot + "/" + Host + "/" + Target + "/" + Package.Name
        else:
            return ObjRoot + "/" + Host + "/" + Target + "/" + Target + "/" + Package.Name
    elif Platform == Platform_Build:
        return ObjRoot + "/" + Build + "/" + Package.Name
    elif Platform == Platform_Host:
        return ObjRoot + "/" + Host + "/" + Package.Name
    else:
        return ObjRoot + "/" + Target + "/" + Package.Name


p = Package()
Package_mpfr = p
p.Name = "mpfr"
p.Dependencies = [ Package_gmp ]
p.Exports = [ "libmpfr.la", ".libs/libmpfr.a", ".libs/libmpfr.la" ]
p.SourcePackage = SourcePackage_mpfr
p.Host = True


def PatchAfterConfigure_bfd(Package, SourceDir, ObjDir):
    #
    # Given that we -enable-targets=all, remove the "tic" targets
    # that fail to build.
    #

    if IsAlreadyBuilt(Package, ObjDir):
        return

    #
    # targmatch.h is a build output, and easier to patch it
    # during build than something before
    #

    for FileName in ["Makefile"]:
        FilePath = ObjDir + "/" + FileName
        OldLines = file(FilePath).readlines()
        NewLines = [ ]
        Changed = False
        for OldLine in OldLines:
            NewLine = OldLine
            if NewLine.find("tic") != -1:
                OldLine = OldLine.replace("\n", " \n")
                NewLine = OldLine
                for r in [
                        re.compile(x) for x in [
                            "^\s+cpu-tic.+\.[loc]+ \\ \n$",
                            "^\s+aout-tic.+\.[loc]+ \\ \n$",
                            "^\s+coff-tic.+\.[loc]+ \\ \n$" ]]:
                    if r.match(NewLine):
                        # print("matched " + NewLine)
                        NewLine = ""
                NewLine = NewLine.replace(" $(srcdir)/archures.c ", " archures.c ")
                NewLine = NewLine.replace(" $(srcdir)/targets.c ", " targets.c ")
                if NewLine != OldLine:
                    Changed = True
            NewLines += NewLine
        if Changed:
            print("patching " + FilePath)
            file(FilePath, "w").writelines(NewLines)

    Run(ObjDir, "make targmatch.h")

    for a in ["archures.c", "targets.c"]:
        MyCopyFile_IncrementalByTime(SourceDir + "/" + a, ObjDir + "/" + a)

    for FileName in ["archures.c", "targets.c", "targmatch.h"]:
        FilePath = ObjDir + "/" + FileName
        OldLines = file(FilePath).readlines()
        NewLines = [ ]
        Changed = False
        for OldLine in OldLines:
            NewLine = OldLine
            if NewLine.find("tic") != -1:
                for r in [
                        re.compile(x) for x in [
                            "^extern const bfd_target tic.+_vec;\n$",
                            "^extern const bfd_arch_info_type bfd_tic.+_arch;\n$",
                            "^\s+&tic.+_vec,\n$",
                            "^\s+&bfd_tic.+_arch,\n$" ]]:
                    if r.match(NewLine):
                        # print("matched " + NewLine)
                        NewLine = " /* " + NewLine + " */ "
                    NewLine = re.sub("#if !defined \(SELECT_VECS\) \|\| defined \(HAVE_tic.+", "#if 0\n", NewLine)
                if NewLine != OldLine:
                    Changed = True
            NewLines += NewLine
        if Changed:
            print("patching " + FilePath)
            file(FilePath, "w").writelines(NewLines)


def PatchAfterConfigure_RemoveLibIconv(Package, SourceDir, ObjDir):

    #
    # More variations need testing here likely.
    #

    return

    #
    # also need to patch config.h
    #

    for FileName in ["Makefile"]:
        FilePath = ObjDir + "/" + FileName
        OldLines = file(FilePath).readlines()
        NewLines = [ ]
        Changed = False
        for OldLine in OldLines:
            NewLine = OldLine
            if NewLine == "LIBICONV = -liconv\n":
                NewLine = "LIBICONV = \n"
                Changed = True
            NewLines += NewLine
        if Changed:
            print("patching libiconv out of " + FilePath)
            file(FilePath, "w").writelines(NewLines)

def PatchAfterConfigure_binutils(Package, SourceDir, ObjDir):
    #
    # -enable-targets=all bites again
    # /src/gcc/binutils/bin2c.c: In function `main":
    # /src/gcc/binutils/bin2c.c:89: warning: implicit declaration of function `_fileno"
    # /src/gcc/binutils/bin2c.c:89: warning: implicit declaration of function `_setmode"
    #

    if IsAlreadyBuilt(Package, ObjDir):
        return

    for FileName in ["Makefile"]:
        FilePath = ObjDir + "/" + FileName
        OldLines = file(FilePath).readlines()
        NewLines = [ ]
        Changed = False
        for OldLine in OldLines:
            NewLine = OldLine
            if NewLine.startswith("BUILD_MISC = ") or NewLine.startswith("noinst_PROGRAMS = "):
                OldLine = OldLine.replace("\n", " \n")
                NewLine = OldLine
                NewLine = NewLine.replace(" bin2c$(EXEEXT_FOR_BUILD) ", " ")
                if NewLine != OldLine:
                    Changed = True
            NewLines += NewLine
        if Changed:
            print("patching " + FilePath)
            file(FilePath, "w").writelines(NewLines)

p = Package()
Package_bfd = p
p.Name = "bfd"
p.Exports = [ "bfdver.h", "bfd.h", "libbfd.a", "libbfd.la", ".libs/libbfd.a", ".libs/libbfd.la" ]
p.PatchAfterConfigure = PatchAfterConfigure_bfd
p.SourcePackage = SourcePackage_binutils
p.Host = True


p = Package()
Package_opcodes = p
p.Name = "opcodes"
p.Dependencies = [ Package_bfd, Package_libiberty ]
p.Exports = [ "libopcodes.a", "libopcodes.la", ".libs/libopcodes.a", ".libs/libopcodes.la" ]
p.SourcePackage = SourcePackage_binutils
p.Host = True


p = Package()
Package_binutils = p
p.Dependencies = [ Package_bfd, Package_opcodes ]
p.Name = "binutils"
# NOTE binutils exports sh scripts AND .exes
p.Exports = ["addr2line", "ar", "nm-new", "objcopy", "objdump", "ranlib", "size", "strip-new"]
p.Exports += [".libs/" + a for a in p.Exports]
p.OptionalExports = ["coffdump", "cxxfilt", "dlltool", "dllwrap", "nlmconv", "readelf", "srconv", "strings", "sysdump", "sysinfo", "windmc", "windres"]
p.OptionalExports += [".libs/" + a for a in p.OptionalExports]
p.PatchAfterConfigure = PatchAfterConfigure_binutils
p.SourcePackage = SourcePackage_binutils
p.Host = True
p.Install = True


def Configure_gas(Package, Platform, Build, Host, Target, Config):
    Config = Config.replace(" --enable-targets=all ", " ")
    Config = Config.replace(" -enable-targets=all ", " ")
    return Config


p = Package()
Package_gas = p
p.Name = "gas"
p.SourcePackage = SourcePackage_binutils
p.Dependencies = [ Package_bfd ]
p.Exports = [ "as-new"  ]
p.Host = True
p.TargetDependent = True # seems like a bug
p.Configure = Configure_gas
p.Install = True


p = Package()
Package_ld = p
p.Name = "ld"
p.SourcePackage = SourcePackage_binutils
p.Exports = ["ld-new"]
p.Host = True
p.Install = True


p = Package()
Package_libdecnumber = p
p.Name = "libdecnumber"
p.SourcePackage = SourcePackage_gcc
p.Host = True
p.Exports = [ "libdecnumber.a", "gstdint.h"  ]
p.Target = True # not always, need to fix this


p = Package()
Package_libcpp = p
p.Name = "libcpp"
p.SourcePackage = SourcePackage_gcc
p.Exports = [ "libcpp.a"  ]
p.Host = True


p = Package()
Package_libgcc = p
p.Name = "libgcc"
p.SourcePackage = SourcePackage_gcc
p.Exports = [ "libgcc.a"  ]
p.OptionalExports = [ "libgcc_eh.a", "libgcc_s.so"  ]
p.Target = True
p.TargetDependent = True # seems like a bug, because it uses gcc's libgcc.mvars.
p.Install = True


def Configure_gcc(Package, Platform, Build, Host, Target, Config):
    gmpsrc = GetSourceDirectory(Package_gmp)
    gmpobj = GetReducedObjectDirectory(Package_gmp, Platform, Build, Host, Target)
    mpfrsrc = GetSourceDirectory(Package_mpfr)
    mpfrobj = GetReducedObjectDirectory(Package_mpfr, Platform, Build, Host, Target)
    if isdir(gmpobj) and isdir(gmpsrc) and isdir(mpfrobj) and isdir(mpfrsrc):
        gmplibs = " -L" + gmpobj + "/.libs -L" + gmpobj + "/_libs -L" + mpfrobj + "/.libs -L" + mpfrobj + "/_libs -lmpfr -lgmp"
        gmpinc = " -I" + gmpobj + " -I" + gmpsrc + " -I" + mpfrobj + " -I" + mpfrsrc
        Config = " GMPLIBS='" + gmplibs + "' GMPINC='" + gmpinc + "' "
    return Config


p = Package()
Package_gcc = p
p.Name = "gcc"
p.Dependencies = [ Package_gmp, Package_mpfr, Package_libiberty, Package_libdecnumber, Package_libcpp, Package_fixincludes ]
p.OptionalDependencies = [ Package_gas, Package_ld ]
p.SourcePackage = SourcePackage_gcc
p.Host = True
p.Exports = [ "xgcc"  ]
p.OptionalExports = [ "gcc-cross" ]
p.TargetDependent = True
p.Configure = Configure_gcc
p.Install = True

p = Package()
Package_libstdcpp = p
p.Name = "libstdc++-v3"
p.OptionalDependencies = [ Package_gcc, Package_libgcc ]
p.SourcePackage = SourcePackage_gcc
p.Exports = [ "src/libstdc++.la", "src/.libs/libstdc++.a", "src/.libs/libstdc++.la" ]
p.OptionalExports = [ "src/.libs/libstdc++.so", "src/.libs/libstdc++.so.6","src/.libs/libstdc++.so.6.0.10" ]
p.Target = True
p.Languages = [ "c++" ] # not yet handled
p.Install = True

Packages = [
    Package_libiberty,
    Package_bfd,
    Package_opcodes,
    Package_binutils,
    Package_gas,
    Package_ld,
    Package_gmp,
    Package_mpfr,
    Package_libdecnumber,
    Package_libcpp,
    Package_gcc,
    Package_libstdcpp,
    Package_libgcc,
    #
    # TBD
    # zlib, libfortran, libgomp, libssp, libjava, libada, gnattools
    #
    ];


def Extract(Directory, File):
    #
    # Make these more portable by running bzcat, gzcat, etc. directly.
    #
    CreateDirectories(Directory);
    for ext in [".tar.gz", ".tgz"]:
        if isfile(File + ext):
            return Run([None], Directory, "tar --strip-components=1 -zxf " + File + ext)

    for ext in [".tar.bz2", ".tbz"]:
        if isfile(File + ext):
            return Run([None], Directory, "tar --strip-components=1 -jxf " + File + ext)

    for ext in [".tlz", ".tar.lzma"]:
        if isfile(File + ext):
            return Run([None], Directory, "tar --strip-components=1 --lzma -xf " + File + ext)

    return Run([None], Directory, "tar tar --strip-components=1 -xf " + File)

def ExtractSource(Package):
    print("extracting " + Package.Name)


def GetExpectedObjectDirectory(Package, Platform, Build, Host, Target):
    if Platform == Platform_Build:
        return ObjRoot + "/" + Host + "/" + Target + "/" + "build-" + Build + "/" + Package.Name
    elif Platform == Platform_Host:
        return ObjRoot + "/" + Host + "/" + Target + "/" + Package.Name
    elif Platform == Platform_Target:
        return ObjRoot + "/" + Host + "/" + Target + "/" + Target + "/" + Package.Name


def IsAlreadyConfigured(Package, ObjDir):
    return FileExists(ObjDir + "/" + "Makefile")


ConfigCommon = " "
ConfigCommon += " -verbose "
ConfigCommon += " -without-libiconv-prefix "
ConfigCommon += " -disable-nls "
ConfigCommon += " -disable-intl "
ConfigCommon += " -disable-po "
ConfigCommon += " -disable-doc "
ConfigCommon += " -with-gnu-as "
ConfigCommon += " -with-gnu-ld "
ConfigCommon += " -disable-bootstrap "
ConfigCommon += " -enable-threads "
ConfigCommon += " -enable-cld "
ConfigCommon += " -enable-version-specific-runtime-libs "
ConfigCommon += " -disable-checking "
ConfigCommon += " -enable-targets=all "
ConfigCommon += " -disable-win32-registry "
ConfigCommon += " -enable-64-bit-bfd "
ConfigCommon += " -disable-multilib "
ConfigCommon += " -disable-libgomp "
ConfigCommon += " -disable-libssp "
ConfigCommon += " -enable-languages=c,c++ " # need to change this to all, at least sometimes
ConfigCommon += " -enable-static "
# ConfigCommon += " -enable-shared=libgcc,libstdc++,libffi,zlib,boehm-gc,ada,libada,libjava,libobjc "
ConfigCommon = re.sub(" +", " ", ConfigCommon)


def GetSourceDirectory(Package):
    return SourceRoot + "/" + Package.Name


def Configure(Package, Platform, Build, Host, Target):
    ObjDir = GetReducedObjectDirectory(Package, Platform, Build, Host, Target)

    if IsAlreadyConfigured(Package, ObjDir):
        print("already configured " + Package.Name)
        return

    print("configuring " + Package.Name + " in " + ObjDir)
    CreateDirectories(ObjDir)

    Config = ConfigCommon
    Config += " -build " + Build
    Config += " -host " + Host
    Config += " -target " + Target
    Config += " -cache-file " + dirname(ObjDir) + "/config.cache "
    Config = Package.Configure(Package, Platform, Build, Host, Target, Config)

    Run(ObjDir, GetSourceDirectory(Package) + "/" + "configure " + Config)


def PatchAfterConfigure_RemoveSubDir(Package, SourceDir, ObjDir, SubDir):
    for FileName in ["Makefile"]:
        FilePath = ObjDir + "/" + FileName
        OldLines = file(FilePath).readlines()
        NewLines = [ ]
        Changed = False
        for OldLine in OldLines:
            NewLine = OldLine
            if NewLine.startswith("SUBDIRS = "):
                OldLine = OldLine.replace("\n", " \n")
                NewLine = OldLine
                NewLine = NewLine.replace(" " + SubDir + " ", " ")
                if NewLine != OldLine:
                    Changed = True
            NewLines += NewLine
        if Changed:
            print("patching subdir " + SubDir + " out of " + FilePath)
            file(FilePath, "w").writelines(NewLines)


def PatchAfterConfigure(Package, Platform, Build, Host, Target):

    ObjDir = GetReducedObjectDirectory(Package, Platform, Build, Host, Target)

    if IsAlreadyBuilt(Package, ObjDir):
        return

    print("patching " + Package.Name)
    SourceDir = GetSourceDirectory(Package)
    Package.PatchAfterConfigure(Package, SourceDir, ObjDir)

    for SubDir in ["doc", "po", "testsuite"]:
        PatchAfterConfigure_RemoveSubDir(Package, SourceDir, ObjDir, SubDir)

    PatchAfterConfigure_RemoveLibIconv(Package, SourceDir, ObjDir)

def Build(Package, Platform, Build, Host, Target):
    Package.Make(Package, Platform, Build, Host, Target)
    ObjDir = GetReducedObjectDirectory(Package, Platform, Build, Host, Target)
    if not IsAlreadyBuilt(Package, ObjDir):
        print("error building " + Package.Name)
        sys.exit(1)
    Package.Export(Package, Platform, Build, Host, Target)


def Install(Package, Platform, Build, Host, Target):

    if Package.Install:
        print("installing " + Package.Name)
        ObjDir = GetReducedObjectDirectory(Package, Platform, Build, Host, Target)

        if Build == Host:
            Run(ObjDir, "make install")
        else:
            Run(ObjDir, "make install DESTDIR=" + Prefix0 + "/" + Host + "/install")

BuildSteps = [ ]

def ShouldBuild(Package, Platform):
    Result = (
        (Platform == Platform_Build and Package.Build)
        or (Platform == Platform_Host and Package.Host)
        or (Platform == Platform_Target and Package.Target))
    # print("ShouldBuild " + Package.Name + " " + str(Platform) + " => " + str(Result))
    return Result

def BuildDependencies(Package, Platform, Build, Host, Target):

    #
    # optional, formerly "bootstrap" dependencies are optional
    # That is, if you are going to build gcc and ld, build ld first.
    # If you are going to build gcc, you must build libiberty.
    # For now, bootstrap dependencies are fully built (installed)
    # before upper levels.
    #

    # print("BuildDependencies " + Package.Name + " " + str(Platform))

    for p in Package.OptionalDependencies:
        if isdir(GetSourceDirectory(p)):
            for DepPlatform in Platforms:
                if ShouldBuild(p, DepPlatform):
                    for Step in BuildSteps:
                        Step(p, DepPlatform, Build, Host, Target)

    for p in Package.Dependencies:
        for DepPlatform in Platforms:
            if ShouldBuild(p, DepPlatform):
                for Step in BuildSteps:
                    if DepPlatform <= Platform:
                        Step(p, DepPlatform, Build, Host, Target)

BuildSteps = [
    BuildDependencies,
    Configure,
    PatchAfterConfigure,
    Build,
    Install
    ];


PackagesToBuild = [ ]
NameToPackage = { }


for Package in Packages:
    NameToPackage[Package.Name] = Package;
 
for p in sys.argv:
    if p in NameToPackage:
        PackagesToBuild += [ NameToPackage[p] ]

if not PackagesToBuild:
    PackagesToBuild = Packages

for Package in PackagesToBuild:
    ExtractSource(Package)

Build = "i686-pc-cygwin"
Host = "i686-pc-cygwin"
Target = "i686-pc-cygwin"
print("building " + Build + "/" + Host + "/" + Target)

for Platform in Platforms:
    for Package in PackagesToBuild:
        if ShouldBuild(Package, Platform):
            for Step in BuildSteps:
                Step(Package, Platform, Build, Host, Target)

Build = "i686-pc-cygwin"
Host = "i686-pc-cygwin"
Target = "sparc-sun-solaris2.10"
print("building " + Build + "/" + Host + "/" + Target)

for Platform in Platforms:
    for Package in PackagesToBuild:
        if ShouldBuild(Package, Platform):
            for Step in BuildSteps:
                Step(Package, Platform, Build, Host, Target)

Build = "i686-pc-cygwin"
Host = "sparc-sun-solaris2.10"
Target = "sparc-sun-solaris2.10"
print("building " + Build + "/" + Host + "/" + Target)


for Platform in Platforms:
    for Package in PackagesToBuild:
        if ShouldBuild(Package, Platform):
            for Step in BuildSteps:
                Step(Package, Platform, Build, Host, Target)
