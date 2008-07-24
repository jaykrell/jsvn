#! /usr/bin/env python

#
# This is a wrapper for building gcc, ld, gas, etc.
# It's goals include:
#   minimizing rebuilds
#   minimizing rebuilds when building multiple toolsets
#   maximizing autoconf's cache
#   build multiple toolsets in one go, or in multiple
#     runs, mostly incrementally, while preserving
#     earlier goals of minimizing compiling anything
#     more than necessary.
#
# It duplicates parts of the topleve configure and makefile.
#

import sys
import os
import re
import os.path
from os.path import dirname, isdir, isfile, splitext, getsize, getmtime, islink
import stat
from shutil import copy2
from os import symlink

#
# more later
#
RecognizedPlatforms = [
    "i686-pc-cygwin",
    "sparc-sun-solaris2.10",
    "i586-pc-msdosdjgpp"
    ]

Prefix0 = "/usr/local"
# Prefix0 = "/usr"


# order is important
Platform_Build = 0
Platform_Host = 1
Platform_Target = 2
# order is important
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

def Configure_default(State, Package, Platform, Build, Host, Target, ObjDir, Config):
    return Config


def PatchAfterConfigure_default(State, Package, Platform, Build, Host, Target, ObjDir):
    pass


def Report(State, Package, Platform, Build, Host, Target, ObjDir):
    PackageName = ""
    if Package:
        PackageName = Package.Name + ":"
    return (
        PackageName + "[" + Build + "/" + Host + "/" + Target + "]:" + ["build", "host", "target"][Platform] + ":"
        + [Build, Host, Target][Platform] + ":"
        + ObjDir)

def IsAlreadyBuilt(State, Package, Platform, Build, Host, Target, ObjDir):
    for Export in Package.Exports:
        if not FileExists(ObjDir  + "/" + Export):
            #print(State, Package.Name + " is not already built because " + ObjDir  + "/" + Export + " does not exist")
            return False
    return True


def CreateDirectories(a):
    if not isdir(a):
        if os.name == "nt":
            print("mkdir " + a)
        else:
            print("mkdir -pv -- " + a)
        os.makedirs(a)


def CheckCygwinLink(a):
#
# This is for handling Cygwin links from Win32 Python.
# Strictly speaking, a symlink could have .lnk in its visibile name.
#
    if isfile(a) or islink(a) or (splitext(a)[1] == ".lnk") or (not isfile(a + ".lnk")):
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
# The first parameter must be an existant file or directory.
# The second parameter can be None or a path to an existing or nonexisting file or directory.
# For this function to do anything, if b is not None, it must "allow" the same changes
#   as a. That is, if ends in .exe, but b does not, or vice versa, no change.
#   If a contains .libs/, but b does not, also no change.
# Cygwin symlinks are also handled.
#
    aext = splitext(a)[1].lower()
    if aext == ".exe" or aext == ".lnk":
        return [a, b]
    if b:
        bext = splitext(b)[1]
        if bext == ".exe" or bext == ".lnk":
            return [a, b]

    #if isfile(a) or isdir(a) or ((b != None) and (isfile(b) or isdir(b))):
    #    return [a, b]

    if a.find(".libs") != -1:
        #
        # needs work
        # if a does not exist, iterate through a, replacing .libs elements with _libs
        # if a does not exist, iterate through b, replacing .libs elements with _libs
        # and then later, if a did not have .libs, but b does, and we can't create the directory,
        # then iterate through b replacing .libs with _libs
        #
        pass

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
#
# needs work
# use FixPath and common CopyFile code
#
    if From == To:
        return
    CreatedDir = False
    for Ext in ["", ".exe", ".lnk"]:
        FromExt = From + Ext
        ToExt = To + Ext
        if isfile(FromExt):
            #print(FromExt + " exists")
            if not CreatedDir:
                CreateDirectories(dirname(To))
                CreatedDir = True
            if os.name == "nt":
                #print("copy " + FromExt + " " + ToExt)
                pass
            else:
                #print("cp " + FromExt + " " + ToExt)
                pass
            try: # Cygwin vagaries -- isfile and copy2 doesn't agree on FromExt existing
                copy2(FromExt, ToExt)
                break
            except:
                pass

def MyCopyFile_IncrementalByTime(From, To):
#
# needs work
# use FixPath and common CopyFile code
#
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
            if os.name == "nt":
                #print("copy " + FromExt + " " + ToExt)
                pass
            else:
                print("cp " + FromExt + " " + ToExt)
            try: # Cygwin vagaries -- isfile and copy2 doesn't agree on FromExt existing
                copy2(FromExt, ToExt)
                break
            except:
                pass

def MyCopyFile_IncrementalByTimeAndSize(From, To):
#
# needs work
# use FixPath and common CopyFile code
#
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
            # The times are never actually equal. :(
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
            if os.name == "nt":
                #print("copy " + FromExt + " " + ToExt)
                pass
            else:
                print("cp " + FromExt + " " + ToExt)
            try: # Cygwin vagaries -- isfile and copy2 doesn't agree on FromExt existing
                copy2(FromExt, ToExt)
                break
            except:
                print("did not copy " + FromExt + " " + ToExt)

def Make_default(State, Package, Platform, Build, Host, Target, ObjDir):

    if IsAlreadyBuilt(State, Package, Platform, Build, Host, Target, ObjDir):
        return

    print("making " + Package.Name + " in " + ObjDir)
    CreateDirectories(ObjDir)
    Run(ObjDir, "make")


def Export_default(State, Package, Platform, Build, Host, Target, ObjDir):
    #
    # Really the only files that need to be exported are ones used by target-dependent
    # packages -- i.e. files used by gcc.
    #
    ExpectedObjDir = GetExpectedObjectDirectory(State, Package, Platform, Build, Host, Target, ObjDir)
    print("exporting " + Report(State, Package, Platform, Build, Host, Target, ObjDir))
    CreateDirectories(ExpectedObjDir)
    for Export in Package.Exports:
        MyCopyFile_IncrementalByTimeAndSize(ObjDir  + "/" + Export, ExpectedObjDir  + "/" + Export)
    for Export in Package.OptionalExports:
        if FileExists(ObjDir  + "/" + Export):
            MyCopyFile_IncrementalByTimeAndSize(ObjDir  + "/" + Export, ExpectedObjDir  + "/" + Export)


def GetReducedObjectDirectory(State, Package, Platform, Build, Host, Target):
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
    Path = ObjRoot
    if Package.HostTarget:
        Path += "/" + Host + "/" + Target
        if Platform == Platform_Target:
            # This is inefficient. It caters to libgcc reaching into gcc, and
            # contributes to building libgcc more than necessary.
            Path += "/" + Target
    else:
        # Voila: This is the point. Just list one platform, that which
        # the code will run on.
        Path += "/" + [Build, Host, Target][Platform]
    Path += "/" + Package.Name
    return Path

    
class Package():
    def __init__(self):
        self.Host = False
        self.Target = False
        self.Build = False
        self.PatchAfterConfigure = PatchAfterConfigure_default
        self.Install = False

        # really needs like:
        # self.BuildDependencies = [ ]
        # self.HostDependencies = [ ]
        # self.TargetDependencies = [ ]
        self.Dependencies = [ ]
        self.OptionalDependencies = [ ]

        self.Configure = Configure_default
        self.Make = Make_default
        self.Export = Export_default
        self.Exports = [ ]
        self.OptionalExports = [ ]
        self.HostTarget = False

class BuildStep():
    def __init__(self):
        self.Name = None
        self.Code = None

class SourcePackage():
    def __init__(self):
        self.Extracted = False
        self.Directory = "."
        self.SourceDependencies = [ ]

    
SourceRoot = "/src/gcc"
DistFiles = "/net/distfiles"
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
p.SourceDependencies = [ SourcePackage_gcc ]


p = SourcePackage()
SourcePackage_mpfr = p
p.Name = "mpfr"
p.Version = "2.3.1"
p.Directory = "mpfr"
p.SourceDependencies = [ SourcePackage_gcc ]


p = SourcePackage()
SourcePackage_binutils = p
p.Name = "binutils"
p.Version = "2.18"
p.SourceDependencies = [ SourcePackage_gcc ]


SourcePackages = [
    SourcePackage_binutils,
    SourcePackage_gmp,
    SourcePackage_mpfr,
    SourcePackage_gcc,
    ]


Package_gcc = Package()

Package_libdecnumber = Package()
Package_libcpp = Package()
Package_libstdcpp = Package()
Package_libgcc = Package()
Package_fixincludes = Package()

Package_bfd = Package()
Package_opcodes = Package()
Package_binutils = Package()
Package_gas = Package()
Package_ld = Package()

Package_libiberty = Package()
Package_gmp = Package()
Package_mpfr = Package()

#
# We really need to parse Makefile.def for the dependencies, and run toplevel configure
# for sniffing what languages to build.
#
# OptionalDependencies is really currently just how we get the merged binutils + gcc tree to build.
#
OptionalDependencies = [ Package_binutils, Package_gas, Package_ld ]

#
# Needs work:
#   Exports: if these all exist, the package has been built
#       Should just use our own marker file.
#   OptionalExports: copy all of these
#


def Configure_Force_EnableStatic_DisableShared(Config):
    for enable in ["enable", "disable"]:
        for shared in ["shared", "static"]:
            for dash in ["-", "--"]:
                Config = Config.replace(" " + dash + enable + shared + " ", " ")
    Config += " -enable-static -disable-shared "
    return Config

def Configure_gmp(State, Package, Platform, Build, Host, Target, ObjDir, Config):
    return Configure_Force_EnableStatic_DisableShared(Config)

p = Package_gmp
p.Name = "gmp"
p.OptionalDependencies = OptionalDependencies
p.Exports = [ "libgmp.la", ".libs/libgmp.a", ".libs/libgmp.la" ]
p.SourcePackage = SourcePackage_gmp
p.Host = True
p.Configure = Configure_gmp


p = Package_libiberty
p.Name = "libiberty"
p.Dependencies = [ Package_libgcc ]
p.OptionalDependencies = OptionalDependencies
p.Exports = [ "libiberty.a" ]
p.SourcePackage = SourcePackage_gcc # also binutils
p.Host = True
p.Target = True
p.Build = True


p = Package_fixincludes
p.Name = "fixincludes"
p.OptionalDependencies = OptionalDependencies
p.Dependencies = [ Package_libiberty ]
p.Exports = [ "fixincl", "fixinc.sh" ]
p.SourcePackage = SourcePackage_gcc
p.Build = True


def Configure_mpfr(State, Package, Platform, Build, Host, Target, ObjDir, Config):
    #
    # duplicate the logic of toplevel configure for gmp/mpfr in the combined tree
    #
    gmpsrc = GetSourceDirectory(State, Package_gmp)
    gmpobj = GetReducedObjectDirectory(State, Package_gmp, Platform, Build, Host, Target)
    if isdir(gmpobj) and isdir(gmpsrc):
        Config += " -with-gmp-build=" + gmpobj

    Config = Configure_Force_EnableStatic_DisableShared(Config)

    return Config


p = Package_mpfr
p.Name = "mpfr"
p.OptionalDependencies = OptionalDependencies
p.Dependencies = [ Package_gmp ]
p.Exports = [ "libmpfr.la", ".libs/libmpfr.a", ".libs/libmpfr.la" ]
p.SourcePackage = SourcePackage_mpfr
p.Configure = Configure_mpfr
p.Host = True


def PatchAfterConfigure_bfd(State, Package, Platform, Build, Host, Target, ObjDir):
    #
    # Given that we -enable-targets=all, remove the "tic" targets
    # that fail to build.
    #

    if IsAlreadyBuilt(State, Package, Platform, Build, Host, Target, ObjDir):
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


def PatchAfterConfigure_RemoveLibIconv(State, Package, Platform, Build, Host, Target, ObjDir):

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

def PatchAfterConfigure_binutils(State, Package, Platform, Build, Host, Target, ObjDir):
    #
    # -enable-targets=all bites again
    # /src/gcc/binutils/bin2c.c: In function `main":
    # /src/gcc/binutils/bin2c.c:89: warning: implicit declaration of function `_fileno"
    # /src/gcc/binutils/bin2c.c:89: warning: implicit declaration of function `_setmode"
    #

    if IsAlreadyBuilt(State, Package, Platform, Build, Host, Target, ObjDir):
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

p = Package_bfd
p.Name = "bfd"
p.OptionalDependencies = OptionalDependencies
p.Exports = [ "bfdver.h", "bfd.h", "bfd_stdint.h", "libbfd.a", "libbfd.la", ".libs/libbfd.a", ".libs/libbfd.la" ]
p.PatchAfterConfigure = PatchAfterConfigure_bfd
p.SourcePackage = SourcePackage_binutils
p.Host = True


p = Package_opcodes
p.Name = "opcodes"
p.OptionalDependencies = OptionalDependencies
p.Dependencies = [ Package_bfd ]
p.Exports = [ "libopcodes.a", "libopcodes.la", ".libs/libopcodes.a", ".libs/libopcodes.la" ]
p.SourcePackage = SourcePackage_binutils
p.Host = True


p = Package_binutils
p.Name = "binutils"
p.Dependencies = [ Package_bfd, Package_opcodes ]
p.OptionalDependencies = OptionalDependencies
# NOTE binutils exports sh scripts AND executables, with
# the same names, except on NT where the names vary (foo vs. foo.exe)
p.Exports = ["addr2line", "ar", "nm-new", "objcopy", "objdump", "ranlib", "size", "strip-new"]
p.Exports += [".libs/" + a for a in p.Exports]
p.OptionalExports = ["coffdump", "cxxfilt", "dlltool", "dllwrap", "nlmconv", "readelf", "srconv", "strings", "sysdump", "sysinfo", "windmc", "windres"]
p.OptionalExports += [".libs/" + a for a in p.OptionalExports]
p.PatchAfterConfigure = PatchAfterConfigure_binutils
p.SourcePackage = SourcePackage_binutils
p.Host = True
p.Install = True


def Configure_gas(State, Package, Platform, Build, Host, Target, ObjDir, Config):
    # temporary?
    Config = Config.replace(" --enable-targets=all ", " ")
    Config = Config.replace(" -enable-targets=all ", " ")
    return Config

def Configure_ld(State, Package, Platform, Build, Host, Target, ObjDir, Config):
    # temporary?
    Config = Config.replace(" --enable-targets=all ", " ")
    Config = Config.replace(" -enable-targets=all ", " ")
    return Config

p = Package_gas
p.Name = "gas"
p.SourcePackage = SourcePackage_binutils
p.Dependencies = [ Package_bfd, Package_opcodes ]
p.OptionalDependencies = OptionalDependencies
p.Exports = [ "as-new"  ]
p.Host = True
p.HostTarget = True # seems like a bug
p.Configure = Configure_gas
p.Install = True


p = Package_ld
p.Name = "ld"
p.SourcePackage = SourcePackage_binutils
p.Dependencies = [ Package_bfd, Package_opcodes ]
p.OptionalDependencies = OptionalDependencies
p.Exports = ["ld-new"]
p.Host = True
p.Install = True
p.HostTarget = True # just barely..seems like a bug
p.Configure = Configure_ld # temporary?


#
# BUG: This is probably only needed depending on how gcc is configured.
#
p = Package_libdecnumber
p.Name = "libdecnumber"
p.SourcePackage = SourcePackage_gcc
p.Host = True
p.Exports = [ "libdecnumber.a", "gstdint.h"  ]
p.Target = True


p = Package_libcpp
p.Name = "libcpp"
p.SourcePackage = SourcePackage_gcc
p.Exports = [ "libcpp.a"  ]
p.Host = True


p = Package_libgcc
p.Name = "libgcc"
p.SourcePackage = SourcePackage_gcc
p.Exports = [ "libgcc.a"  ]
p.OptionalExports = [ "libgcc_eh.a", "libgcc_s.so"  ]
p.Target = True
p.HostTarget = True # seems like a bug, because it uses gcc's libgcc.mvars.
p.Install = True


def Configure_gcc(State, Package, Platform, Build, Host, Target, ObjDir, Config):
#
# We really need to somehow use the toplevel configure, since it knows what
# platforms support what libraries.
#
    #
    # duplicate the logic of toplevel configure for gmp/mpfr in the combined tree
    #
    gmpsrc = GetSourceDirectory(State, Package_gmp)
    gmpobj = GetReducedObjectDirectory(State, Package_gmp, Platform, Build, Host, Target)
    mpfrsrc = GetSourceDirectory(State, Package_mpfr)
    mpfrobj = GetReducedObjectDirectory(State, Package_mpfr, Platform, Build, Host, Target)
    if isdir(gmpobj) and isdir(gmpsrc) and isdir(mpfrobj) and isdir(mpfrsrc):
        gmplibs = " -L" + gmpobj + "/.libs -L" + gmpobj + "/_libs -L" + mpfrobj + "/.libs -L" + mpfrobj + "/_libs -lmpfr -lgmp"
        gmpinc = " -I" + gmpobj + " -I" + gmpsrc + " -I" + mpfrobj + " -I" + mpfrsrc
        Config += " GMPLIBS='" + gmplibs + "' GMPINC='" + gmpinc + "' "

    return Config


p = Package_gcc
p.Name = "gcc"
p.Dependencies = [ Package_gmp, Package_mpfr, Package_libiberty, Package_libdecnumber, Package_libcpp ]
p.OptionalDependencies = OptionalDependencies
p.SourcePackage = SourcePackage_gcc
p.Host = True
p.Exports = [ "xgcc", "cc1"  ]
p.OptionalExports = [ "gcc-cross", "g++-cross", "libgcov.a", "gnat1", "cc1obj", "cc1objplus", "tree1",
    "cc1obj", "cc1plus", "collect2", "cpp", "f951", "g++", "gcj", "gcov-dump",
    "gcov", "gfortran", "jc1", "jcf-dump", "jvgenmain" ]


p.HostTarget = True
p.Configure = Configure_gcc
p.Install = True


p = Package_libstdcpp
p.Name = "libstdc++-v3"
p.Dependencies = [ Package_libgcc, Package_libiberty ]
p.OptionalDependencies = OptionalDependencies
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
    ]


def Extract(Directory, File):
    #
    # Make these more portable by running bzcat, gzcat, etc. directly.
    #

    if os.path.isdir(Directory):
        return

    CreateDirectories(Directory)
    for ext in [".tar.gz", ".tgz"]:
        if isfile(File + ext):
            return Run(Directory, "tar --strip-components=1 -zxf " + File + ext)

    for ext in [".tar.bz2", ".tbz"]:
        if isfile(File + ext):
            return Run(Directory, "tar --strip-components=1 -jxf " + File + ext)

    for ext in [".tlz", ".tar.lzma"]:
        if isfile(File + ext):
            return Run(Directory, "tar --strip-components=1 --lzma -xf " + File + ext)

    return Run(Directory, "tar tar --strip-components=1 -xf " + File)

def ExtractSource(Package):
    if not Package.Extracted:
        for p in Package.SourceDependencies:
            ExtractSource(p)
        #
        # FUTURE: Probe for more file names.
        #
        Extract(SourceRoot + "/" + Package.Directory, DistFiles + "/" + Package.Name + "-" + Package.Version)
        Package.Extracted = True


def GetExpectedObjectDirectory(State, Package, Platform, Build, Host, Target, ObjDir):
    Path = ObjRoot + "/" + Host + "/" + Target
    Path += ["/build-" + Build, "", "/" + Target][Platform]
    Path += "/" + Package.Name
    return Path


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
ConfigCommon += " -enable-languages=c,c++ "
ConfigCommon = re.sub("  +", " ", ConfigCommon)


def GetSourceDirectory(State, Package):
    return SourceRoot + "/" + Package.Name


BuildStep_BuildDependencies = BuildStep()
BuildStep_Configure = BuildStep()
BuildStep_PatchAfterConfigure = BuildStep()
BuildStep_Make = BuildStep()
BuildStep_Install = BuildStep()


def Configure(State, Package, Platform, Build, Host, Target, ObjDir):

    if FileExists(ObjDir + "/" + "Makefile"):
        #print("already configured " + Package.Name)
        return

    print("configuring " + Report(State, Package, Platform, Build, Host, Target, ObjDir))
    CreateDirectories(ObjDir)

    Config = ConfigCommon
    Config += " -host " + [Build, Host, Target][Platform]
    if Package.HostTarget:
        Config += " -target " + Target
    if Host != Target:
        Config += " -with-sysroot " # most directories don't care

    Config += " -cache-file " + dirname(ObjDir) + "/config.cache "
    Config = Package.Configure(State, Package, Platform, Build, Host, Target, ObjDir, Config)

    Run(ObjDir, GetSourceDirectory(State, Package) + "/" + "configure " + Config)


def PatchAfterConfigure_RemoveSubDir(State, Package, Platform, Build, Host, Target, ObjDir, SubDir):

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


def PatchAfterConfigure(State, Package, Platform, Build, Host, Target, ObjDir):

    if IsAlreadyBuilt(State, Package, Platform, Build, Host, Target, ObjDir):
        return

    print("patching " + Report(State, Package, Platform, Build, Host, Target, ObjDir))
    SourceDir = GetSourceDirectory(State, Package)
    Package.PatchAfterConfigure(State, Package, Platform, Build, Host, Target, ObjDir)

    for SubDir in ["doc", "po", "testsuite"]:
        PatchAfterConfigure_RemoveSubDir(State, Package, Platform, Build, Host, Target, ObjDir, SubDir)

    PatchAfterConfigure_RemoveLibIconv(State, Package, Platform, Build, Host, Target, ObjDir)

def Make(State, Package, Platform, Build, Host, Target, ObjDir):

    if IsAlreadyBuilt(State, Package, Platform, Build, Host, Target, ObjDir):
        return

    Package.Make(State, Package, Platform, Build, Host, Target, ObjDir)

    if not IsAlreadyBuilt(State, Package, Platform, Build, Host, Target, ObjDir):
        print("error building " + Package.Name)
        sys.exit(1)

    Package.Export(State, Package, Platform, Build, Host, Target, ObjDir)


def Install(State, Package, Platform, Build, Host, Target, ObjDir):

    if Package.Install:
        print("installing " + Report(State, Package, Platform, Build, Host, Target, ObjDir))
        #return

        if Build == Host:
            Run(ObjDir, "make install")
        else:
            Run(ObjDir, "make install DESTDIR=" + Prefix0 + "/" + Host + "/install")

def ShouldBuild(State, Package, Platform):
    Result = (
        (Platform == Platform_Build and Package.Build)
        or (Platform == Platform_Host and Package.Host)
        or (Platform == Platform_Target and Package.Target))
    # print("ShouldBuild " + Package.Name + " " + str(Platform) + " => " + str(Result))
    return Result

p = BuildStep_BuildDependencies
p.Name = "BuildDependencies"

p = BuildStep_Configure
p.__call__ = Configure
p.Name = "Configure"

p = BuildStep_PatchAfterConfigure
p.__call__ = PatchAfterConfigure
p.Name = "PatchAfterConfigure"

p = BuildStep_Make
p.__call__ = Make
p.Name = "Make"

p = BuildStep_Install
p.__call__ = Install
p.Name = "Install"

BuildSteps = [
    BuildStep_BuildDependencies,
    BuildStep_Configure,
    BuildStep_PatchAfterConfigure,
    BuildStep_Make,
    BuildStep_Install,
    ]


PackagesToBuild = [ ]
NameToPackage = { }


for Package in Packages:
    NameToPackage[Package.Name] = Package
 
for p in sys.argv:
    if p in NameToPackage:
        PackagesToBuild += [ NameToPackage[p] ]

if not PackagesToBuild:
    PackagesToBuild = Packages

for Package in PackagesToBuild:
    ExtractSource(Package.SourcePackage)

Cygwin = "i686-pc-cygwin"
SparcSolaris = "sparc-sun-solaris2.10"
MsdosDjgpp = "i586-pc-msdosdjgpp"

#
# should sniff this
#
Build = Cygwin

def _BuildUpTo(State, Packages, Platform, Build, Host, Target):

    for Step in BuildSteps:
        StepState = State.get(Step.Name)
        if not StepState:
            State[Step.Name] = dict()

    for plat in Platforms:
        if plat <= Platform:
            for pkg in Packages:
                if ShouldBuild(State, pkg, plat):
                    if isdir(GetSourceDirectory(State, pkg)):
                        ObjDir = GetReducedObjectDirectory(State, pkg, plat, Build, Host, Target)
                        for Step in BuildSteps:
                            StepState = State.get(Step.Name)
                            if StepState.get(ObjDir):
                                #print("skipping " + Step.Name + " " + ObjDir)
                                continue
                            if Step == BuildSteps[0]:
                                print("building " + Report(State, pkg, plat, Build, Host, Target, ObjDir))
                            StepState[ObjDir] = True
                            # print("> " + Step.Name + " in " + Report(State, pkg, plat, Build, Host, Target, ObjDir))
                            Step(State, pkg, plat, Build, Host, Target, ObjDir)
                            # print("< " + Step.Name + " in " + Report(State, pkg, plat, Build, Host, Target, ObjDir))


def BuildDependencies(State, Package, Platform, Build, Host, Target, ObjDir):
    _BuildUpTo(State, Package.OptionalDependencies + Package.Dependencies, Platform, Build, Host, Target)

BuildStep_BuildDependencies.__call__ = BuildDependencies

def BuildTools(State, Host, Target, Packages):

    if Host == None and Target == None:
        Host = Build
        Target = Build

    print("building " + Build + "/" + Host + "/" + Target)

    for Platform in Platforms:
        _BuildUpTo(State, PackagesToBuild, Platform, Build, Host, Target)

State = dict()

# native

BuildTools(State, Cygwin, Cygwin, PackagesToBuild)

# cross

BuildTools(State, Cygwin, SparcSolaris, PackagesToBuild)

# cross to native

BuildTools(State, SparcSolaris, SparcSolaris, PackagesToBuild)

# cross to cross (back)
# need not yet made sysroot for this
#
# BuildTools(State, SparcSolaris, Cygwin, PackagesToBuild)

# cross

BuildTools(State, Cygwin, MsdosDjgpp, PackagesToBuild)

# cross to native

BuildTools(State, MsdosDjgpp, MsdosDjgpp, PackagesToBuild)
