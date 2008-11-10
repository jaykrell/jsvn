#! /bin/sh

#
# inputs:
#  sh, make, tar, gzip
#  Irix: /usr/WorkShop/usr/bin/ncc
#  AIX: gcc (4.0)
#  source archives
#
# outputs:
#  up to date gcc, g++, Python, GNU make, GNU tar
#  Irix: GNU ld
#
# Notes:
#  build GNU make first, since vendor make generally inadequate
#  build g++ after GNU tar, since vendor tar generally can't extract it
#  must rebuild GNU make after gcc, and then gcc again, as Irix ncc
#    miscompiles make, leading to an empty libgcc, and then gcc can't build itself
#  Tar and make are configured with program-prefix=g -- gtar and gmake.
#  Irix builds GNU as, and not ld.
#  AIX builds neither GNU as nor ld.
#

set -e
set -x


# same as uname -s
# IRIX
# AIX
UnameS=`uname -s`

# Irix: mips
# AIX: powerpc
UnameP=`uname -p`

# revision
# Irix: 6.5
# AIX: 3
# UnameR=`uname -r`

# version
# Irix: gibberish
# AIX: 5
# UnameV=`uname -v`

platform=$UnameP-$UnameS

SOURCE=${HOME}/src
OBJ=${HOME}/obj
DONE=${HOME}/done

# rm -rf /usr/local/*
# rm -rf ${OBJ}/*
# rm -rf ${SOURCE}/gccrel ${SOURCE}/*0 ${SOURCE}/*1 ${SOURCE}/*2 ${SOURCE}/*3 ${SOURCE}/*4 ${SOURCE}/*5 ${SOURCE}/*6 ${SOURCE}/*7 ${SOURCE}/*8 ${SOURCE}/*9
mkdir -p ${DONE}

TAR=tar
MAKE="make MAKEINFO=:"

Prefix="/usr/local"
# Prefix="/usr"

ConfigCommon=" "
ConfigCommon0=" "
ConfigGcc=" "
ConfigGcc0=" "


ConfigCommon=" ${ConfigCommon} -disable-nls "
ConfigCommon=" ${ConfigCommon} -disable-intl "
ConfigCommon=" ${ConfigCommon} -enable-version-specific-runtime-libs "
ConfigCommon=" ${ConfigCommon} -disable-checking "
ConfigCommon=" ${ConfigCommon} -enable-64-bit-bfd "
ConfigCommon=" ${ConfigCommon} -enable-cld "
ConfigCommon=" ${ConfigCommon} -disable-win32-registry "
ConfigCommon=" ${ConfigCommon} -disable-dependency-tracking "

# ConfigCommon=" ${ConfigCommon} -verbose "
# ConfigCommon=" ${ConfigCommon} -prefix=${Prefix} "
# ConfigCommon=" ${ConfigCommon} -exec-prefix=${Prefix} "
# ConfigCommon=" ${ConfigCommon} -libdir=${Prefix}/lib "
# ConfigCommon=" ${ConfigCommon} -libexecdir=${Prefix}/lib "
# ConfigCommon=" ${ConfigCommon} -mandir=${Prefix}/share/man "
# ConfigCommon=" ${ConfigCommon} -infodir=${Prefix}/share/info "

ConfigCommon="${ConfigCommon}"

ConfigCommon0="${ConfigCommon}"
ConfigCommon0=" ${ConfigCommon0} -disable-shared "
ConfigCommon0=" ${ConfigCommon0} -enable-static "
ConfigCommon0="${ConfigCommon0}"


ConfigDisableBinutils=" "
ConfigDisableBinutils="${ConfigDisableBinutils} -disable-cpu "
ConfigDisableBinutils="${ConfigDisableBinutils} -disable-bfd "
ConfigDisableBinutils="${ConfigDisableBinutils} -disable-binutils "
ConfigDisableBinutils="${ConfigDisableBinutils} -disable-gas "
ConfigDisableBinutils="${ConfigDisableBinutils} -disable-gprof "
ConfigDisableBinutils="${ConfigDisableBinutils} -disable-ld "
ConfigDisableBinutils="${ConfigDisableBinutils} -disable-opcode "

ConfigGcc="${ConfigGcc} ${ConfigCommon0}"

#
# We build gcc ourselves twice, and on Irix the third build doesn't equal the second build,
# which is an error. Investigate that later.
#

# ConfigGcc="${ConfigGcc} -disable-bootstrap"


case "${UnameS}" in
AIX)
    # For Python, do not use xlC (I don't have it.)
    ConfigPython="-with-gcc -disable-ipv6"

    # AIX requires native ld and native as in all but very few configurations
    ConfigGcc="${ConfigGcc} -without-gnu-ld  -with-ld=/usr/bin/ld -without-gnu-as -with-as=/usr/bin/as ${ConfigDisableBinutils}"
    ;;
IRIX|IRIX64)
    # Irix requires GNU as.
    # GNU ld has problems to be debugged and native ld works.
    ConfigGcc="${ConfigGcc} -without-gnu-ld -with-ld=/usr/bin/ld -with-gnu-as -disable-ld"
    ;;
esac

ConfigGcc0="${ConfigGcc}"
ConfigGcc0=" ${ConfigGcc0} -disable-multilib "
ConfigGcc0=" ${ConfigGcc0} -disable-libgomp "
ConfigGcc0=" ${ConfigGcc0} -disable-libssp "
ConfigGcc0=" ${ConfigGcc0} -disable-bootstrap "
ConfigGcc0=" ${ConfigGcc0}"

SetCC0() {
    case "${UnameS}" in
    IRIX|IRIX64)
        CC="/usr/WorkShop/usr/bin/ncc -w"
        export CC
        ;;
    esac
}

SetCC1() {
    CC="${Prefix}/bin/gcc"
    export CC
}

UnsetCC() {
# ??
    CC=
    export CC
    unset CC
}

UnsetCC
SetCC0

build_make0() {
#
# Vendor make (AIX) can't build out of tree, so the first
# thing we build is GNU make using vendor make, with output
# in the source tree.
#
# Thereafter, we use gmake.
#
    set -e
    set -x

    P=make-3.81
    Q=make0

    cd ${SOURCE}
    test -f ${SOURCE}/${P}/Makefile.in || gzip -d < ${SOURCE}/${P}.tar.gz | ${TAR} -xf -
    cd ${SOURCE}/${P}
    test -f ${SOURCE}/${P}/Makefile || ${SOURCE}/${P}/configure -program-prefix=g ${ConfigCommon0}
    ${MAKE}
    ./make install
    rehash || true

    cd ${HOME}
    # rm -rf ${OBJ}/${Q}
    rm -rf ${SOURCE}/${P}
}

test -f ${DONE}/make0 || build_make0
touch -f ${DONE}/make0
MAKE="gmake MAKEINFO=:"


build_python0() {
#
# Build Python with bootstrap compiler
# Python is important as it is our preferred scripting language.
# We have written patches to gcc in it.
# We should escape from sh to Python ASAP.
#
    set -e
    set -x

    P=Python-2.5.2
    Q=python0

    cd ${SOURCE}
    test -f ${SOURCE}/${P}/Makefile.in || gzip -d < ${SOURCE}/${P}.tar.gz | ${TAR} -xf -
    mkdir -p ${OBJ}/${Q}
    cd ${OBJ}/${Q}
    test -f ${SOURCE}/${P}/Makefile || ${SOURCE}/${P}/configure ${ConfigPython} ${ConfigCommon0}

    # Irix ncc doesn't like files that #include themselves, so make it include a copy of itself.
    cd ${SOURCE}/${P}/Modules
    test -f _sre.c.orig || cp _sre.c _sre.c.orig
    sed -e 's/#include "_sre.c"/#include "_sre.c.orig"/' < _sre.c.orig > _sre.c

    cd ${OBJ}/${Q}
    ${MAKE} -k install || true
    rehash || true

    cd ${HOME}
    # rm -rf ${OBJ}/${Q}
    rm -rf ${SOURCE}/${P}
}

test -f ${DONE}/python0 || build_python0
touch -f ${DONE}/python0


extract_gcc_core() {
    set -e
    set -x

    P=gcc-4.3.2

    if test ! -f ${SOURCE}/${P}/binutils/Makefile.in; then
      cd ${SOURCE}
      # 2.18 works
      Q=binutils-2.19
      gzip -d < ${SOURCE}/${Q}.tar.gz | ${TAR} -xf -
      mv ${Q} ${P}
    fi

    if test ! -f ${SOURCE}/${P}/gcc/Makefile.in; then
      cd ${SOURCE}
      gzip -d < ${SOURCE}/gcc-core-4.3.2.tar.gz | ${TAR} -xf -
    fi

    if test ! -f ${SOURCE}/${P}/gmp/Makefile.in; then
      cd ${SOURCE}/${P}
      Q=gmp-4.2.3
      gzip -d < ${SOURCE}/${Q}.tar.gz | ${TAR} -xf -
      mv ${Q} gmp
    fi

    if test ! -f ${SOURCE}/${P}/mpfr/Makefile.in; then
      cd ${SOURCE}/${P}
      Q=mpfr-2.3.2
      gzip -d < ${SOURCE}/${Q}.tar.gz | ${TAR} -xf -
      mv ${Q} mpfr
    fi
}


extract_gcc() {
    set -e
    set -x

    extract_gcc_core
    cd ${SOURCE}
    gzip -d < ${SOURCE}/gcc-g++-4.3.2.tar.gz | ${TAR} -xf -
}


build_gcc0() {
#
# gcc/binutils/gmp/mpfr with bootstrap compiler
# Only "gcc core" -- just the C compiler.
# Vendor tar (Solaris, Irix) can't extract the full source.
#
    set -e
    set -x

    extract_gcc_core

    P=gcc-4.3.2
    Q=gcc0

    python ${HOME}/build.py patchonly source ${SOURCE}/${P} binutils gcc gmp mpfr

    mkdir -p ${OBJ}/${Q}
    cd ${OBJ}/${Q}
    test -f ${SOURCE}/${P}/Makefile || ${SOURCE}/${P}/configure ${ConfigCommon0} ${ConfigGcc0}

    cd ${OBJ}/${Q}
    ${MAKE}
    ${MAKE} install
    rehash || true

    cd ${HOME}
    # rm -rf ${OBJ}/${Q}
    rm -rf ${SOURCE}/${P}
}

#
# Now that we have python, to apply patches to gcc,
# build our first version of gcc.
# Note that this version is flawed, but it is a useful step.
# The flaw is induced by a miscompilation of make, which
# we should really debug and patch, to make this all simpler and faster.
#

test -f ${DONE}/gcc0 || build_gcc0
touch -f ${DONE}/gcc0

#
# make with first build of gcc
#
# We now have a reasonably well working gcc, but it can't build itself or tar
# due to a miscompilation of make, so rebuild make.
# In particular, libgcc is empty.
# This will be a bit painful to track down.
#

build_make1() {
    set -e
    set -x

    P=make-3.81
    Q=make1

    cd ${SOURCE}
    test -f ${SOURCE}/${P}/Makefile.in || gzip -d < ${SOURCE}/${P}.tar.gz | ${TAR} -xf -
    mkdir -p ${OBJ}/${Q}

    cd ${OBJ}/${Q}
    test -f ${SOURCE}/${P}/Makefile || ${SOURCE}/${P}/configure ${ConfigCommon} -program-prefix=g
    ./make install
    rehash || true

    cd ${HOME}
    # rm -rf ${OBJ}/${Q}
    # rm -rf ${SOURCE}/${P}
}

UnsetCC
SetCC1

test -f ${DONE}/make1 || build_make1
touch -f ${DONE}/make1


build_gcc1() {
#
# Now build gcc again with the bootstrap compiler, but a more working version of make.
# Again note that we cannot yet extract g++ because we don't have GNU tar, and we
# can't yet build GNU tar because gcc doesn't work well enough.
#
    set -e
    set -x

    extract_gcc_core

    P=gcc-4.3.2
    Q=gcc1

    python ${HOME}/build.py patchonly source ${SOURCE}/${P} binutils gcc gmp mpfr

    mkdir -p ${OBJ}/${Q}
    cd ${OBJ}/${Q}
    test -f ${SOURCE}/${P}/Makefile || ${SOURCE}/${P}/configure ${ConfigCommon} ${ConfigGcc0}
    ${MAKE}
    ${MAKE} install
    rehash || true

    cd ${HOME}
    # rm -rf ${OBJ}/${Q}
    # rm -rf ${SOURCE}/${P}
}

UnsetCC
SetCC0

test -f ${DONE}/gcc1 || build_gcc1
touch -f ${DONE}/gcc1

#
# gcc from here on out, but let configure find it.
# 

UnsetCC

build_tar() {
#
# tar with gcc
# tar won't build with ncc for a few reasons, give up on patching it for now.
# Vendor tar (Solaris, Irix) can't extract the full gcc tree, due to the "LongLink"
# in libstdcxx, so now make GNU tar, and use it to extract from here on out.
#
    set -e
    set -x

    P=tar-1.20
    Q=tar

    cd ${SOURCE}
    test -f ${SOURCE}/${P}/Makefile.in || gzip -d < ${SOURCE}/${P}.tar.gz | ${TAR} -xf -
    mkdir -p ${OBJ}/${Q}
    cd ${OBJ}/${Q}
    test -f ${SOURCE}/${P}/Makefile || ${SOURCE}/${P}/configure ${ConfigCommon} -program-prefix=g
    ${MAKE} install
    rehash || true

    cd ${HOME}
    # rm -rf ${OBJ}/${Q}
    # rm -rf ${SOURCE}/${P}
}

test -f ${DONE}/tar || build_tar
touch -f ${DONE}/tar
TAR=gtar


build_gcc() {
#
# Now build gcc with itself, including g++
#
    set -e
    set -x

    extract_gcc
    # extract_all

    P=gcc-4.3.2
    Q=gcc

    mkdir -p ${OBJ}/${Q}
    cd ${OBJ}/${Q}
    test -f ${SOURCE}/${P}/Makefile || ${SOURCE}/${P}/configure ${ConfigCommon} ${ConfigGcc}
    ${MAKE}
    ${MAKE} install
    rehash || true

    cd ${HOME}
    # rm -rf ${OBJ}/${Q}
    # rm -rf ${SOURCE}/${P}
}

test -f ${DONE}/gcc || build_gcc
touch -f ${DONE}/gcc


build_bash() {
#
# bash with self-built gcc
#
    set -e
    set -x

    P=bash-3.2
    Q=bash

    cd ${SOURCE}
    test -f ${SOURCE}/${P}/Makefile.in || gzip -d < ${SOURCE}/${P}.tar.gz | ${TAR} -xf -
    mkdir -p ${OBJ}/${Q}
    cd ${OBJ}/${Q}
    test -f ./Makefile || ${SOURCE}/${P}/configure ${ConfigCommon}
    ${MAKE} install
    rehash || true

    cd ${HOME}
    # rm -rf ${OBJ}/${Q}
    # rm -rf ${SOURCE}/${P}
}

test -f ${DONE}/bash || build_bash
touch -f ${DONE}/bash


build_make() {
#
# make with self-built gcc
#
    set -e
    set -x

    P=make-3.81
    Q=make

    cd ${SOURCE}
    test -f ${SOURCE}/${P}/Makefile.in || gzip -d < ${SOURCE}/${P}.tar.gz | ${TAR} -xf -
    cd ${SOURCE}/${P}
    test -f ${SOURCE}/${P}/Makefile || ${SOURCE}/${P}/configure -program-prefix=g ${ConfigCommon}
    ${MAKE}
    ./make install
    rehash || true

    cd ${HOME}
    # rm -rf ${OBJ}/${Q}
    # rm -rf ${SOURCE}/${P}
}

test -f ${DONE}/make || build_make
touch -f ${DONE}/make


build_gcc() {
    set -e
    set -x

    extract_gcc
    # extract_all

    P=gcc-4.3.2
    Q=gcc

    mkdir -p ${OBJ}/${Q}
    cd ${OBJ}/${Q}
    test -f ${SOURCE}/${P}/Makefile || ${SOURCE}/${P}/configure ${ConfigCommon} ${ConfigGcc}
    ${MAKE}
    ${MAKE} install
    rehash || true

    cd ${HOME}
    # rm -rf ${OBJ}/${Q}
    # rm -rf ${SOURCE}/${P}
}

test -f ${DONE}/gcc || build_gcc
touch -f ${DONE}/gcc

build() {
    set -e
    set -x

    cd ${SOURCE}
    test -f ${SOURCE}/$1-$2/Makefile.in || gzip -d < ${SOURCE}/$1-$2.tar.gz | ${TAR} -xf -
    mkdir -p ${OBJ}/$1
    cd -p ${OBJ}/$1
    test -f ./${P}/Makefile || ${SOURCE}/${P}/configure -disable-nls -disable-intl -disable-dependency-tracking

    ${MAKE}
    rehash || true

    cd ${HOME}
    touch -f ${DONE}/${Q}
}

build bash-3.2 bash
build tar-1.20 tar
build make-3.81 make
build m4-1.4.11 m4
build texinfo-4.12 texinfo
build gettext-0.17 gettext
build flex-2.5.35 flex
build bison-2.3 bison
build sed 4.1.5
build gawk 3.1.6
build gdb 6.8
# build bzip2 1.0.5
# build lzma
# build tcl
# build tk
# build perl 5.10
# build autoconf
# build autogen
# build automake
# build guile
# build expect
