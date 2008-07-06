#
#
# convert.tgz, .tar.gz, .tbz, .tar.bz2 files to .tlz (.tar.lzma)
# reprocess .tlz files to make sure the files are all world-readable
#
#

import os
import os.path
import sys
from os.path import join
import re
from tempfile import mkdtemp
import shutil

ReZip = re.compile("(^.+)(\.zip)$")
ReCompressedTar = re.compile("(^.+)(\.(:?tgz|tbz|tar\.gz|tar\.bz2))$")

#
# Disfavor Cygwin so that foo and foo.exe don't clash, by favoring
# %windir%\unzip.exe if it exists over a regular %path% search.
#
UnzipExe = "unzip"
if os.name == "nt" and os.path.isfile(os.path.join(os.environ["windir"], "unzip.exe")):
    UnzipExe = os.path.join(os.environ["windir"], "unzip.exe")

ChdirCommand = "cd "
if os.name == "nt":
    ChdirCommand = "cd /d "

DeleteDirectoryRecursiveCommand = "rm -rf -- "
if os.name == "nt":
    DeleteDirectoryRecursiveCommand = "rmdir /q/s "

CreateDirectoryCommand = "mkdir -pv -- "
if os.name == "nt":
    CreateDirectoryCommand = "mkdir "

DeleteFileCommand = "rm -- "
if os.name == "nt":
    DeleteFileCommand = "del "

def Unzip(File):

    TemporaryDirectory = mkdtemp()
    TemporaryDirectory2 = os.path.join(TemporaryDirectory, "a")
    print(CreateDirectoryCommand + TemporaryDirectory2)
    os.mkdir(TemporaryDirectory2)
    PreviousDirectory = os.getcwd()
    print(ChdirCommand + TemporaryDirectory2)
    os.chdir(TemporaryDirectory2)
    Command = UnzipExe + " " + File
    print(Command)
    ExitCode = os.system(Command)
    if ExitCode != 0:
        sys.exit(ExitCode)
    #
    # Extracting some archives, at least with Cygwin unzip, was leaving us unable to delete the files.
    #
    if os.name == "nt":
        Command = "cacls . /t /e /g " + os.environ["USERDOMAIN"] + "\\" + os.environ["USERNAME"] + ":F"
        print(Command)
        os.system(Command)
        Command = "cacls . /t /e /g Everyone:R"
        print(Command)
        os.system(Command)
    print(ChdirCommand + PreviousDirectory)
    os.chdir(PreviousDirectory)
    return TemporaryDirectory

def ArchiveDirectory(ArchiveDirectory, Directory):

    Directory2 = os.path.join(Directory, "a")
    PreviousDirectory = os.getcwd()
    print(ChdirCommand + Directory2)
    os.chdir(Directory2)
    #
    # Cygwin has trouble with
    # cd c:...\temp
    # tar -cf d:\foo.tar .
    # so cd into the temp space
    #
    TemporaryArchive = os.path.join(os.pardir, os.path.basename(ArchiveDirectory))
    # This should work, but doesn't.
    #TemporaryArchive = os.path.join(Directory, os.path.basename(ArchiveDirectory))
    Command = "tar --lzma -vcf " + TemporaryArchive + " ."
    print(Command)
    ExitCode = os.system(Command)
    if ExitCode != 0:
        sys.exit(ExitCode)
    print("move " + TemporaryArchive + " " + ArchiveDirectory)
    if os.path.isfile(ArchiveDirectory):
        os.unlink(ArchiveDirectory)
    os.rename(TemporaryArchive, ArchiveDirectory)
    print(ChdirCommand + PreviousDirectory)
    os.chdir(PreviousDirectory)


def CheckOutput(Base):

    #
    # I am not sure we reliably know what the output (or intermediate) file is.
    # Pick among the two obvious guesses, with an order preference,
    # and fail if either pre-exist. This is overly conservative.
    #
    for a in ["", ".tlz", ".tar"]:
        b = Base + a
        if os.path.isfile(b):
            print("WARNING: " + b + " already exists")
            return True
    return False

def ConvertZipToTlz(CurrentDirectory, Root, BaseName, Extension):

    Path = join(CurrentDirectory, Root, BaseName + Extension)

    if CheckOutput(join(CurrentDirectory, Root, BaseName)):
        print(DeleteFileCommand + Path)
        os.unlink(Path)
        return

    TemporaryDirectory = Unzip(Path)
    ArchiveDirectory(join(CurrentDirectory, Root, BaseName + ".tlz"), TemporaryDirectory)
    #
    # shutil.rmtree was failing sometimes.
    #
    Command = DeleteDirectoryRecursiveCommand + TemporaryDirectory
    print(Command)
    os.system(Command)
    print(DeleteFileCommand + Path)
    os.unlink(Path)

def ConvertCompressedTarToTlz(CurrentDirectory, Root, BaseName, Extension):

    if CheckOutput(join(CurrentDirectory, Root, BaseName)):
        print(DeleteFileCommand + Path)
        os.unlink(Path)
        return

    Directory = join(CurrentDirectory, Root)
    PreviousDirectory = os.getcwd()
    print(ChdirCommand + Directory)
    os.chdir(Directory)

    TarFiles = ["", ""]

    if Extension == ".tar.gz" or Extension == ".tar.bz2":
        TarFiles[0] = BaseName + ".tar"
        TarFiles[1] = BaseName
    if Extension == ".tgz" or Extension == ".tbz":
        TarFiles[1] = BaseName + ".tar"
        TarFiles[0] = BaseName

    if Extension == ".tbz" or Extension == ".tar.bz2":
        Decompress = "bzip2 -d "
    if Extension == ".tgz" or Extension == ".tar.gz":
        Decompress = "gzip -d "

    Command = Decompress + BaseName + Extension
    print(Command)
    ExitCode = os.system(Command)
    if ExitCode != 0:
        sys.exit(ExitCode)

    TarFile = None
    if os.path.isfile(TarFiles[1]):
        TarFile = TarFiles[1]
    if os.path.isfile(TarFiles[0]):
        TarFile = TarFiles[0]

    if not TarFile:
        print("ERROR: no tar file after decompression")
        sys.exit(1)

    Command = "lzma " + TarFile
    print(Command)
    ExitCode = os.system(Command)
    if ExitCode != 0:
        sys.exit(ExitCode)

    os.rename(TarFile + ".lzma", BaseName + ".tlz")
    os.chdir(PreviousDirectory)


CurrentDirectory = os.getcwd()
for Root, Dirs, Files in os.walk(CurrentDirectory):
    for Name in Files:
        if True: # Cygwin Unzip doesn't like having hello and hello.exe (Name != "hello13.zip"):
            Match = ReZip.search(Name)
            if Match:
                ConvertZipToTlz(CurrentDirectory, Root, Match.group(1), Match.group(2))
            Match = ReCompressedTar.search(Name)
            if Match:
                ConvertCompressedTarToTlz(CurrentDirectory, Root, Match.group(1), Match.group(2))
