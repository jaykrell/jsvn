#!/bin/sh


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

rm -rf /usr/local/*
rm -rf ${OBJ}/*
rm -rf ${SOURCE}/gccrel ${SOURCE}/*0 ${SOURCE}/*1 ${SOURCE}/*2 ${SOURCE}/*3 ${SOURCE}/*4 ${SOURCE}/*5 ${SOURCE}/*6 ${SOURCE}/*7 ${SOURCE}/*8 ${SOURCE}/*9

TAR=tar
MAKE="make MAKEINFO=:"

Prefix = "/usr/local"
# Prefix = "/usr"

ConfigCommon=" "
ConfigCommon0=" "
ConfigGcc=" "
ConfigGcc0=" "

#
# -disable-dependency-tracking is for speed and more importantly
# problems with Irix /usr/WorkShop/usr/bin/ncc
#
# -disable-nls: I'm an arrogant American.
#

ConfigCommon=" ${ConfigCommon} -disable-nls "
ConfigCommon=" ${ConfigCommon} -disable-intl "
# ConfigCommon=" ${ConfigCommon} -disable-po "
# ConfigCommon=" ${ConfigCommon} -disable-doc "
ConfigCommon=" ${ConfigCommon} -verbose "
ConfigCommon=" ${ConfigCommon} -prefix=${Prefix} "
ConfigCommon=" ${ConfigCommon} -exec-prefix=${Prefix} "
ConfigCommon=" ${ConfigCommon} -libdir=${Prefix}/lib "
ConfigCommon=" ${ConfigCommon} -libexecdir=${Prefix}/lib "
ConfigCommon=" ${ConfigCommon} -mandir=${Prefix}/share/man "
ConfigCommon=" ${ConfigCommon} -infodir=${Prefix}/share/info "
ConfigCommon="${ConfigCommon}"

ConfigCommon0="${ConfigCommon}"
ConfigCommon0=" ${ConfigCommon0} -disable-dependency-tracking "
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

ConfigGcc="${ConfigGcc} -disable-bootstrap"


case "${UnameS}" in
AIX)
    # For Python, do not use xlC (I don't have it.)
    ConfigPython="-with-gcc -disable-ipv6"
    ConfigGcc="${ConfigGcc} -without-gnu-ld -without-gnu-as -with-as=/usr/bin/as -with-ld=/usr/bin/ld ${ConfigDisableBinutils}"
    ;;
IRIX|IRIX64)
    CC="/usr/WorkShop/usr/bin/ncc -w"
    export CC
    ConfigGcc="${ConfigGcc} -without-gnu-ld -with-gnu-as -disable-ld"
    ;;
esac


ConfigGcc0="${ConfigGcc}"
ConfigGcc0=" ${ConfigGcc0} -disable-multilib "
ConfigGcc0=" ${ConfigGcc0} -disable-libgomp "
ConfigGcc0=" ${ConfigGcc0} -disable-libssp "
ConfigGcc0=" ${ConfigGcc0}"

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
    cd ${SOURCE}
    gzip -d < ${SOURCE}/${P}.tar.gz | ${TAR} -xf -
    cd ${SOURCE}/${P}
    test -f ${SOURCE}/${P}/Makefile || ${SOURCE}/${P}/configure -program-prefix=g ${ConfigCommon0}
    ${MAKE}
    ./make install
    rehash || true
    cd $HOME
    rm -rf ${SOURCE}/${P} ${OBJ}/${P}
}


build_make0
MAKE="gmake MAKEINFO=:"


build_python0() {
#
# Python with bootstrap compiler
#
    set -e
    set -x

    P=Python-2.5.2
    cd ${SOURCE}
    gzip -d < ${SOURCE}/${P}.tar.gz | ${TAR} -xf -
    mkdir -p ${OBJ}/${P} || true
    cd ${OBJ}/${P}
    test -f ${SOURCE}/${P}/Makefile || ${SOURCE}/${P}/configure ${ConfigPython} ${ConfigCommon0}
    cd ${SOURCE}/${P}/Modules
    cp _sre.c _sre.c.orig
    sed -e 's/#include "_sre.c"/#include "_sre.c.orig"/' < _sre.c.orig > _sre.c
    cd ${OBJ}/${P}
    ${MAKE}
    ${MAKE} -k install || true
    rehash || true
    cd $HOME
    rm -rf ${SOURCE}/${P} ${OBJ}/${P}
}

build_python0

extract_gcc_core() {
    set -e
    set -x

    P=gcc-4.3.2
    rm -rf ${SOURCE}/${P}
    rm -rf ${OBJ}/${P}

    cd ${SOURCE}
    Q=binutils-2.18
    gzip -d < ${SOURCE}/${Q}.tar.gz | ${TAR} -xf -
    mv ${Q} ${P}

    cd ${SOURCE}
    gzip -d < ${SOURCE}/gcc-core-4.3.2.tar.gz | ${TAR} -xf -

    cd ${SOURCE}/${P}
    Q=gmp-4.2.3
    gzip -d < ${SOURCE}/${Q}.tar.gz | ${TAR} -xf -
    mv ${Q} gmp

    cd ${SOURCE}/${P}
    Q=mpfr-2.3.2
    gzip -d < ${SOURCE}/${Q}.tar.gz | ${TAR} -xf -
    mv ${Q} mpfr
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
# Vendor tar (Solaris) can't extract the full source.
#
    set -e
    set -x

    P=gcc-4.3.2
    extract_gcc_core

    python ${HOME}/build.py patchonly source ${SOURCE}/${P} binutils gcc gmp mpfr

    mkdir -p ${OBJ}/${P} || true
    cd ${OBJ}/${P}
    test -f ${SOURCE}/${P}/Makefile || ${SOURCE}/${P}/configure ${ConfigCommon0} ${ConfigGcc0}

    cd ${OBJ}/${P}
    ${MAKE}
    ${MAKE} install
    rehash || true
    cd $HOME
    rm -rf ${SOURCE}/${P} ${OBJ}/${P}
}

build_gcc0

#
# gcc from here on out
# 
# ??

CC=
unset CC

build_tar1() {
#
# tar with first build of gcc
# Vendor tar (Solaris) can't extract the full gcc tree, due to the "LongLink"
# in libstdcxx, so now make GNU tar, and use it to extract from here on out.
#
    set -e
    set -x

    P=tar-1.20
    cd ${SOURCE}
    gzip -d < ${SOURCE}/${P}.tar.gz | ${TAR} -xf -
    mkdir -p ${OBJ}/${P} || true
    cd ${OBJ}/${P}
    test -f ${SOURCE}/${P}/Makefile || ${SOURCE}/${P}/configure ${ConfigCommon} -program-prefix=g
    ${MAKE}
    ${MAKE} install
    rehash || true
    cd $HOME
    rm -rf ${SOURCE}/${P} ${OBJ}/${P}
}

build_tar1
TAR=gtar


#
# make with first build of gcc
#
# We now have a reasonably well working gcc, but it can't build itself
# due to a miscompilation of make, so rebuild make.
# In particular, libgcc is empty.
# This will be a bit painful to track down.
#

build_make1() {
    set -e
    set -x

    P=make-3.81
    cd ${SOURCE}
    gzip -d < ${SOURCE}/${P}.tar.gz | ${TAR} -xf -
    cd ${SOURCE}/${P}
    test -f ${SOURCE}/${P}/Makefile || ${SOURCE}/${P}/configure -program-prefix=g ${ConfigCommon}
    ${MAKE}
    ./make install
    rehash || true
    cd $HOME
    rm -rf ${SOURCE}/${P} ${OBJ}/${P}
}

build_make1

build_gcc() {
#
# Now build gcc with itself.
#
    set -e
    set -x

    P=gcc-4.3.2
    extract_gcc

    # python ${HOME}/build.py patchonly source ${SOURCE}/${P} binutils gcc gmp mpfr

    mkdir -p ${OBJ}/${P} || true
    cd ${OBJ}/${P}
    test -f ${SOURCE}/${P}/Makefile || ${SOURCE}/${P}/configure ${ConfigCommon} ${ConfigGcc}
    ${MAKE}
    ${MAKE} install
    rehash || true
    cd $HOME
    rm -rf ${SOURCE}/${P} ${OBJ}/${P}
}

build_gcc

build_bash() {
#
# bash with second and final gcc
#
    set -e
    set -x

    P=bash-3.2
    cd ${SOURCE}
    gzip -d < ${SOURCE}/${P}.tar.gz | ${TAR} -xf -
    mkdir -p ${OBJ}/${P} || true
    cd ${OBJ}/${P}
    test -f ${SOURCE}/${P}/Makefile || ${SOURCE}/${P}/configure ${ConfigCommon}
    ${MAKE}
    ${MAKE} install
    rehash || true
    cd $HOME
    rm -rf ${SOURCE}/${P} ${OBJ}/${P}
}

build_bash

build_python() {
#
# Python with second and final gcc
#
    set -e
    set -x

    P=Python-2.5.2
    cd ${SOURCE}
    gzip -d < ${SOURCE}/${P}.tar.gz | ${TAR} -xf -
    mkdir -p ${OBJ}/${P} || true
    cd ${OBJ}/${P}
    test -f ${SOURCE}/${P}/Makefile || ${SOURCE}/${P}/configure ${ConfigPython} ${ConfigCommon}
    # cd ${SOURCE}/${P}/Modules
    # cp _sre.c _sre.c.orig
    # sed -e 's/#include "_sre.c"/#include "_sre.c.orig"/' < _sre.c.orig > _sre.c
    cd ${OBJ}/${P}
    ${MAKE}
    ${MAKE} install
    rehash || true
    cd $HOME
    rm -rf ${SOURCE}/${P} ${OBJ}/${P}
}

build_python

build_tar() {
#
# tar with second and final gcc
#
    set -e
    set -x

    P=tar-1.20
    cd ${SOURCE}
    gzip -d < ${SOURCE}/${P}.tar.gz | ${TAR} -xf -

    mkdir -p ${OBJ}/${P} || true
    cd ${OBJ}/${P}
    test -f ${SOURCE}/${P}/Makefile || ${SOURCE}/${P}/configure ${ConfigCommon} -program-prefix=g
    ${MAKE}
    ${MAKE} install
    rehash || true
    cd $HOME
    rm -rf ${SOURCE}/${P} ${OBJ}/${P}
}

build_tar

build_make() {
#
# make with second and final gcc
#
    set -e
    set -x

    P=make-3.81
    cd ${SOURCE}
    gzip -d < ${SOURCE}/${P}.tar.gz | ${TAR} -xf -
    cd ${SOURCE}/${P}
    test -f ${SOURCE}/${P}/Makefile || ${SOURCE}/${P}/configure -program-prefix=g ${ConfigCommon}
    ${MAKE}
    ./make install
    rehash || true
    cd $HOME
    rm -rf ${SOURCE}/${P} ${OBJ}/${P}
}

build_make

build_gcc4() {
#
# on Irix, stage 2 and 3 compare differently
# go ahead and try a 4 stage build
#
    set -e
    set -x

    P=gcc-4.3.2
    extract_gcc

    # python ${HOME}/build.py patchonly source ${SOURCE}/${P} binutils gcc gmp mpfr

    mkdir -p ${OBJ}/${P} || true
    cd ${OBJ}/${P}
    test -f ${SOURCE}/${P}/Makefile || ${SOURCE}/${P}/configure ${ConfigCommon} ${ConfigGcc}
    ${MAKE} bootstrap4-lean
    ${MAKE} install
    rehash || true
    cd $HOME
    rm -rf ${SOURCE}/${P} ${OBJ}/${P}
}

build_gcc4


#
# more packages here (or in the Python)
# and cross tools
# gzip
# bzip2
# lzma
# sed
# tcl
# expect
# perl 5.10
# automake
# autoconf
# autogen
# gawk
#
