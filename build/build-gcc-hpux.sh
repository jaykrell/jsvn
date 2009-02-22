#!/bin/sh

#
# Building gcc 3.3.6 libstdc++ requires an ld patch on HPUX 11.11.
# Without it, ld crashes.
# Once I installed it, I stopped testing without it.
#

set -e
set -x

PREFIX=/usr/local
OBJ=/obj
SOURCE=/src

PATH=${PREFIX}/bin:${PREFIX}/32/bin:${PREFIX}/64/bin:$PATH
export PATH

#MAKE=${PREFIX}/bin/gmake
MAKE=gmake

#CC=${PREFIX}/32/bin/gcc
CC=gcc
export CC

#
# cleanup previous attempts
#

# rm -rf ${OBJ}/* || true
# rm -rf ${SOURCE}/*[0-9] || true

# rm -rf ${PREFIX}/* || true

# rm -f ${PREFIX}/bin/*gcc* || true
# rm -f ${PREFIX}/bin/*gcj* || true
# rm -f ${PREFIX}/bin/*as || true
# rm -f ${PREFIX}/bin/*g++ || true
# rm -f ${PREFIX}/bin/*c++ || true
# rm -f ${PREFIX}/bin/hppa* || true
# rm -f ${PREFIX}/bin/cpp || true
# rm -f ${PREFIX}/bin/jv-* || true
# rm -f ${PREFIX}/bin/jcf-* || true

# rm -rf ${PREFIX}/hppa* || true
# rm -rf ${PREFIX}/lib/gcc-lib || true

# rm -rf ${OBJ}/binut* || true
# rm -rf ${OBJ}/gcc* || true
# rm -rf ${OBJ}/* || true

#
# Bundled cc is K&R.
# It cannot build gcc 4.3.3 nor binutils 2.19.1.
# It can build gcc 3.3.6.
# Bundled cc does not support -g.
#  => and lots of warnings about it
# gcc using bundled as does not support -g.
#  => and lots of warnings about it
#

function RemoveDebug {
#
# The warnings are partly just annoying, but they also cause build
# errors when some packages use -Werror (binutils).
#
    sed -e 's/^CFLAGS_FOR_BUILD = -g -O2$/CFLAGS_FOR_BUILD = -O2 /' < Makefile > Makefile.2
    mv Makefile.2 Makefile

    sed -e 's/^CFLAGS_FOR_TARGET = -g -O2$/CFLAGS_FOR_TARGET = -O2 /' < Makefile > Makefile.2
    mv Makefile.2 Makefile

    sed -e 's/^CXXFLAGS_FOR_TARGET = -g $/CXXFLAGS_FOR_TARGET = /' < Makefile > Makefile.2
    mv Makefile.2 Makefile

    sed -e 's/^BOOT_CFLAGS= -g -O2$/BOOT_CFLAGS = -O2 /' < Makefile > Makefile.2
    mv Makefile.2 Makefile

    sed -e 's/^CFLAGS = -g -O2$/CFLAGS = -O2 /' < Makefile > Makefile.2
    mv Makefile.2 Makefile
}

function RemoveOptimization {
#
# The warnings are partly just annoying, but they also cause build
# errors when some packages use -Werror (binutils).
#
    sed -e 's/^CFLAGS_FOR_BUILD = -O2 /CFLAGS_FOR_BUILD = /' < Makefile > Makefile.2
    mv Makefile.2 Makefile

    sed -e 's/^CFLAGS_FOR_TARGET = -O2 /CFLAGS_FOR_TARGET = /' < Makefile > Makefile.2
    mv Makefile.2 Makefile

    sed -e 's/^BOOT_CFLAGS= -O2 /BOOT_CFLAGS = /' < Makefile > Makefile.2
    mv Makefile.2 Makefile

    sed -e 's/^CFLAGS = -O2 /CFLAGS = /' < Makefile > Makefile.2
    mv Makefile.2 Makefile
}

#
# build GNU make with bundled cc
# It is very much needed.
#

cd ${SOURCE}
rm -rf make-3.81
gzcat make-3.81.tar.gz | tar xf -
cd make-3.81
CC=cc ./configure -prefix=${PREFIX} -disable-nls -verbose -program-prefix=g
make config.h
echo '#include <varargs.h>' >> config.h
make
make install
cd ..
rm -rf make-3.81 || true

#
# build 32bit and 64bit gcc with bundled cc, with bundled as,
# that don't support -g
#

GCC_VERSION=3.3.6

cd ${SOURCE}
rm -rf gcc-${GCC_VERSION} || true
gzcat gcc-core-${GCC_VERSION}.tar.gz | tar xf -
cd gcc-${GCC_VERSION}
rm -rf libmudflap libssp intl libgomp || true

for BITS in 32 64; do

    mkdir -p ${OBJ}/gcc-${GCC_VERSION}/cc${BITS}
    cd ${OBJ}/gcc-${GCC_VERSION}/cc${BITS}
    rm -rf * || true
    if [ x$BITS = x32 ]; then
        DD64=""
    else
        DD64="+DD64"
    fi
    CC="cc ${DD64} -Wp,-H16376 -D_CLASSIC_TYPES -D_HPUX_SOURCE" ${SOURCE}/gcc-${GCC_VERSION}/configure -prefix=${PREFIX}/${BITS} -disable-nls -verbose -with-as=/usr/ccs/bin/as -without-gnu-as
    RemoveDebug # quash warnings, build faster
    RemoveOptimization # build faster
    ${MAKE}
    ${MAKE} install

done

#
# build 32bit and 64bit gas with gcc
#

BINUTILS_VERSION=2.19.1

cd ${SOURCE}
rm -rf binutils-${BINUTILS_VERSION} || true
gzcat binutils-${BINUTILS_VERSION}.tar.gz | tar xf -
cd binutils-${BINUTILS_VERSION}
rm -rf gold elfcpp binutils ld intl gprof || true

for BITS in 32 64; do

    mkdir -p ${OBJ}/binut/gcc${BITS}
    cd ${OBJ}/binut/gcc${BITS}
    rm -rf * || true

    CC=${PREFIX}/${BITS}/bin/gcc ${SOURCE}/binutils-${BINUTILS_VERSION}/configure -disable-nls -verbose -program-prefix=g -prefix=${PREFIX}/${BITS}
    RemoveDebug # quash warnings, build faster
    RemoveOptimization # build faster
    ${MAKE}
    ${MAKE} install

done


#
# build 32bit and 64bit gcc with gcc, with gas, that do support -g
#

GCC_VERSION=3.3.6

cd ${SOURCE}
rm -rf gcc-${GCC_VERSION} || true
gzcat gcc-core-${GCC_VERSION}.tar.gz | tar xf -
cd gcc-${GCC_VERSION}
rm -rf libmudflap libssp intl libgomp || true

for BITS in 32 64; do

    mkdir -p ${OBJ}/gcc-${GCC_VERSION}/gcc${BITS}
    cd ${OBJ}/gcc-${GCC_VERSION}/gcc${BITS}
    rm -rf * || true
    CC=${PREFIX}/${BITS}/bin/gcc ${SOURCE}/gcc-${GCC_VERSION}/configure -disable-nls -verbose -prefix=${PREFIX}/${BITS} -with-as=${PREFIX}/${BITS}/bin/gas -with-gnu-as
    RemoveDebug # quash warnings, build faster
    RemoveOptimization # build faster
    ${MAKE}
    ${MAKE} install

done


#
# build GNU tar, needed to extract g++
#

PACKAGE=tar-1.21

cd ${SOURCE}
rm -rf ${PACKAGE} || true
gzcat ${PACKAGE}.tar.gz | tar xf -

mkdir -p ${OBJ}/${PACKAGE}
cd ${OBJ}/${PACKAGE}
rm -rf * || true
${SOURCE}/${PACKAGE}/configure -disable-nls -verbose -prefix=${PREFIX} -program-prefix=g
RemoveDebug # quash warnings, build faster
RemoveOptimization # build faster
${MAKE}
${MAKE} install


# Now move up to gcc 4.3.3 and include C++

GCC_VERSION=4.3.3

cd ${SOURCE}
rm -rf gcc-${GCC_VERSION} || true
gtar xf gcc-core-${GCC_VERSION}.tar.gz
gtar xf gcc-g++-${GCC_VERSION}.tar.gz
cd gcc-${GCC_VERSION}
rm -rf libmudflap libssp intl libgomp || true

for BITS in 32 64; do

    mkdir -p ${OBJ}/gcc-${GCC_VERSION}/gcc${BITS}
    cd ${OBJ}/gcc-${GCC_VERSION}/gcc${BITS}
    rm -rf * || true
    PATH=${PREFIX}/${BITS}/bin:$PATH CC=gcc ${SOURCE}/gcc-${GCC_VERSION}/configure -disable-nls -verbose -prefix=${PREFIX}/${BITS}
    RemoveDebug # quash warnings, build faster
    RemoveOptimization # build faster
    ${MAKE}
    ${MAKE} install

done


#
# proceed..
# if we are to run the gcc tests, we need tcl and expect
# if we are to work on our source, we need cvs, and (open)ssh
# ssh requires ssl and zlib
# our scripts require python
#
