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
UnameR=`uname -r`

# version
# Irix: gibberish
# AIX: 5
UnameV=`uname -v`

platform=$UnameP-$UnameS

#
# -disable-dependency-tracking is for speed and more importantly
# problems with Irix /usr/WorkShop/usr/bin/ncc
#
# -disable-nls: I'm an arrogant American.
#

rm -rf /usr/local/*
rm -rf $HOME/obj/*
rm -rf $HOME/src/gccrel $HOME/src/*0 $HOME/src/*1 $HOME/src/*2 $HOME/src/*3 $HOME/src/*4 $HOME/src/*5 $HOME/src/*6 $HOME/src/*7 $HOME/src/*8 $HOME/src/*9

TAR=tar
MAKE=make MAKEINFO=:

ConfigCommon=" "
ConfigCommon0=" "
ConfigGcc=" "
ConfigGcc0=" "

ConfigCommon=" ${ConfigCommon} -disable-nls "
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


ConfigGcc="${ConfigGcc} -disable-bootstrap"


case "${UnameS}" in
AIX)
    # For Python, do not use xlC (I don't have it.)
    ConfigPython="-with-gcc -disable-ipv6"
    ConfigGcc="${ConfigGcc} -without-gnu-ld -without-gnu-as -with-as=/usr/bin/as -with-ld=/usr/bin/ld ${ConfigDisableBinutils}"
    ;;
IRIX|IRIX64)
    CC='/usr/WorkShop/usr/bin/ncc -w'
    export CC
    ConfigGcc="${ConfigGcc} -without-gnu-ld -with-gnu-as -disable-ld"
    ;;
esac


ConfigGcc0="${ConfigGcc}"
ConfigGcc0=" ${ConfigGcc0} -disable-multilib "
ConfigGcc0=" ${ConfigGcc0} -disable-libgomp "
ConfigGcc0=" ${ConfigGcc0} -disable-libssp "
ConfigGcc0=" ${ConfigGcc0}"


#
# Vendor make (AIX) can't build out of tree, so the first
# thing we build is GNU make using vendor make, with output
# in the source tree.
#
# Thereafter, we use gmake.
#

P=make-3.81
cd $HOME/src
gzip -d < ${P}.tar.gz | ${TAR} -xf -
cd $HOME/src/${P}
$HOME/src/${P}/configure -program-prefix=g ${ConfigCommon0}
${MAKE}
./make install
rehash || true
cd $HOME
rm -rf $HOME/src/${P} $HOME/obj/${P}


MAKE=gmake MAKEINFO=:


#
# Python with bootstrap compiler
#

P=Python-2.5.2
cd $HOME/src
gzip -d < ${P}.tar.gz | ${TAR} -xf -
mkdir -p $HOME/obj/${P} || true
cd $HOME/obj/${P}
$HOME/src/${P}/configure ${ConfigPython} ${ConfigCommon0}
cd $HOME/src/${P}/Modules
cp _sre.c _sre.c.orig
sed -e 's/#include "_sre.c"/#include "_sre.c.orig"/' < _sre.c.orig > _sre.c
cd $HOME/obj/${P}
${MAKE}
${MAKE} -k install || true
rehash || true
cd $HOME
rm -rf $HOME/src/${P} $HOME/obj/${P}


#
# gcc/binutils/gmp/mpfr with bootstrap compiler
# Only "gcc core" -- just the C compiler.
# Vendor tar (Solaris) can't extract the full source.
#

P=gcc-4.3.2
rm -rf $HOME/src/${P}

cd $HOME/src
Q=binutils-2.18
gzip -d < ${Q}.tar.gz | ${TAR} -xf -
mv ${Q} ${P}

cd $HOME/src
gzip -d < gcc-core-4.3.2.tar.gz | ${TAR} -xf -

cd $HOME/src/${P}
Q=gmp-4.2.3
gzip -d < ${Q}.tar.gz | ${TAR} -xf -
mv ${Q} gmp

cd $HOME/src/${P}
Q=mpfr-2.3.2
gzip -d < ${Q}.tar.gz | ${TAR} -xf -
mv ${Q} mpfr

python $HOME/build.py patchonly source $HOME/src/${P}
mkdir -p $HOME/obj/${P} || true
cd $HOME/obj/${P}
$HOME/src/${P}/configure ${ConfigCommon0} ${ConfigGcc0}
${MAKE}
${MAKE} install
rehash || true
cd $HOME
rm -rf $HOME/src/${P} $HOME/obj/${P}

#
# gcc from here on out
# 
# ??

CC=
unset CC

#
# tar with first build of gcc
# Vendor tar (Solaris) can't extract the full gcc tree, due to the "LongLink"
# in libstdcxx, so now make GNU tar, and use it to extract from here on out.
#

P=tar-1.20
cd $HOME/src
gzip -d < ${P}.tar.gz | ${TAR} -xf -
mkdir -p $HOME/obj/${P} || true
cd $HOME/obj/${P}
$HOME/src/${P}/configure
${MAKE}
${MAKE} install
rehash || true
cd $HOME
rm -rf $HOME/src/${P} $HOME/obj/${P}


TAR=gtar


#
# make with first build of gcc
#
# We now have a reasonably well working gcc, but it can't build itself
# due to a miscompilation of make, so rebuild make.
# In particular, libgcc is empty.
#

P=make-3.81
cd $HOME/src
gzip -d < ${P}.tar.gz | ${TAR} -xf -
cd $HOME/src/${P}
$HOME/src/${P}/configure -program-prefix=g ${ConfigCommon}
${MAKE}
./make install
rehash || true
cd $HOME
rm -rf $HOME/src/${P} $HOME/obj/${P}


#
# Now build gcc with itself.
#

P=gcc-4.3.2
rm -rf $HOME/src/${P}

cd $HOME/src
Q=binutils-2.18
gzip -d < ${Q}.tar.gz | ${TAR} -xf -
mv ${Q} ${P}

cd $HOME/src
gzip -d < gcc-core-4.3.2.tar.gz | ${TAR} -xf -
gzip -d < gcc-g++-4.3.2.tar.gz | ${TAR} -xf -

cd $HOME/src/${P}
Q=gmp-4.2.3
gzip -d < ${Q}.tar.gz | ${TAR} -xf -
mv ${Q} gmp

cd $HOME/src/${P}
Q=mpfr-2.3.2
gzip -d < ${Q}.tar.gz | ${TAR} -xf -
mv ${Q} mpfr


python $HOME/build.py patchonly source $HOME/src/${P}
mkdir -p $HOME/obj/${P} || true
cd $HOME/obj/${P}
$HOME/src/${P}/configure ${ConfigCommon} ${ConfigGcc}
${MAKE}
${MAKE} install
rehash || true
cd $HOME
rm -rf $HOME/src/${P} $HOME/obj/${P}


#
# bash with second and final gcc
#

P=bash-3.2
cd $HOME/src
gzip -d < ${P}.tar.gz | ${TAR} -xf -
mkdir -p $HOME/obj/${P} || true
cd $HOME/obj/${P}
$HOME/src/${P}/configure ${ConfigCommon}
${MAKE}
${MAKE} install
rehash || true
cd $HOME
rm -rf $HOME/src/${P} $HOME/obj/${P}

#
# Python with second and final gcc
#

P=Python-2.5.2
cd $HOME/src
gzip -d < ${P}.tar.gz | ${TAR} -xf -
mkdir -p $HOME/obj/${P} || true
cd $HOME/obj/${P}
$HOME/src/${P}/configure ${ConfigPython} ${ConfigCommon}
cd $HOME/src/${P}/Modules
cp _sre.c _sre.c.orig
sed -e 's/#include "_sre.c"/#include "_sre.c.orig"/' < _sre.c.orig > _sre.c
cd $HOME/obj/${P}
${MAKE}
${MAKE} install
rehash || true
cd $HOME
rm -rf $HOME/src/${P} $HOME/obj/${P}



#
# tar with second and final gcc
#


P=tar-1.20
cd $HOME/src
gzip -d < ${P}.tar.gz | ${TAR} -xf -
mkdir -p $HOME/obj/${P} || true
cd $HOME/obj/${P}
$HOME/src/${P}/configure
${MAKE}
${MAKE} install
rehash || true
cd $HOME
rm -rf $HOME/src/${P} $HOME/obj/${P}


#
# make with second and final gcc
#


P=make-3.81
cd $HOME/src
gzip -d < ${P}.tar.gz | ${TAR} -xf -
cd $HOME/src/${P}
$HOME/src/${P}/configure -program-prefix=g ${ConfigCommon}
${MAKE}
./make install
rehash || true
cd $HOME
rm -rf $HOME/src/${P} $HOME/obj/${P}


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
