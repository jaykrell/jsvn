#!/bin/sh

#
# pass 0:
#
# prereqs:
# tar, make, sh, gzip, bash
# somewhat working C compiler
# not done yet:
#  use uncompressed tar-1.20 and build gzip
#
# vendor tar often can't extract gcc
# vendor make often can't build gcc
# Python is used for scripting hereafter
# bash has nice command line history
#  and is recommended for AIX gcc configure
#
# Then switch to build.py (or build2.py)
#
# pass 1:
#  build binutils, gcc
#
# pass 2:
#  rebuild tar, make, sh, gzip, bash, add perl 5.10
#  rebuild gcc
#

#
# pass 0 -- build up to date
#   bash
#   make
#   tar
#   python
#   gzip (not yet)
#

set -e
set -x

packages='bash-3.2 tar-1.20 make-3.81 Python-2.5.2'

# same as uname -s
# IRIX
# AIX
unameS=`uname -s`

# Irix: mips
# AIX: powerpc
unameP=`uname -p`

# revision
# Irix: 6.5
# AIX: 3
unameR=`uname -r`

# version
# Irix: gibberish
# AIX: 5
unameV=`uname -v`

platform=$unameP-$unameS

#
# -disable-dependency-tracking is for speed and more importantly
# problems with Irix /usr/WorkShop/usr/bin/ncc
#
# -disable-nls: I'm an arrogant American.
#

case "${unameS}" in
AIX)
    # For Python, do not use xlC (I don't have it.)
    configure_python="-with-gcc -disable-ipv6"
    ;;
IRIX*)
    CC='/usr/WorkShop/usr/bin/ncc -w'
    export CC
    ;;
esac

#
# extract (gzip | tar)
#

cd $HOME/src
for a in $packages
do
    test -d $a || gzip -d < $a.tar.gz | tar -xf -
done

GMAKE=$HOME/src/make-3.81/make

P=make-3.81
cd $HOME/src/${P}
test -f Makefile || $HOME/src/${P}/configure -program-prefix=g
make
./make install
rehash || true

P=bash-3.2
mkdir -p $HOME/obj/${P} || true
cd $HOME/obj/${P}
test -f Makefile || $HOME/src/${P}/configure
gmake
gmake install
rehash || true


P=Python-2.5.2
mkdir -p $HOME/obj/${P} || true
cd $HOME/obj/${P}
test -f Makefile || $HOME/src/${P}/configure ${configure_python}
cd $HOME/src/${P}/Modules
test -f _sre.c.orig || cp _sre.c _sre.c.orig
sed -e 's/#include "_sre.c"/#include "_sre.c.orig"/' < _sre.c.orig > _sre.c
cd $HOME/obj/${P}
gmake
gmake install
rehash || true
