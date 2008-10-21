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

packages=bash-3.2 tar-1.20 make-3.81 Python-2.5.2

# same as uname -s
# IRIX
# AIX
unameS=`uname -s`

# IRIX: mips
# AIX: powerpc
unameP=`uname -p`

# revision
# IRIX: 6.5
# AIX: 3
unameR=`uname -r`

# version
# IRIX: gibberish
# AIX: 5
unameV=`uname -v`

platform=$unameP-$unameS

configure=-disable-dependency-tracking -disable-nls

case "${uname}" in

  AIX)
    # Do not use xlC (I don't have it.)
    configure_python=-with-gcc
  ;;

  IRIX)
    CC='/usr/WorkShop/usr/bin/ncc -w'
  ;;

esac

#
# clean
#

rm -rf ~/pkg
cd ~/src
for a in $packages
do
    rm -rf $a
done
rm -rf perl-5.10.0
rm -rf /usr/local

#
# extract (gzip | tar)
#

cd ~/src
for a in $packages
do
    gzip -d < $a.tar.gz | tar -xf -
done

#
# configure and make
#

#
# -disable-dependency-tracking is for speed and more importantly
# problems with Irix /usr/WorkShop/usr/bin/ncc
#
# -disable-nls: I'm an arrogant American.
#

cd ~/src/bash-3.2
./configure ${configure}
make

for a in tar-1.20 make-3.81
do
    cd ~/src/$a
    ./configure ${configure} -program-prefix=g
    make
done

cd ~/src/Python-2.5.2
./configure ${configure} ${configure_python} -disable-ipv6
make

#
# install fakeroot (make install DESTDIR)
# make packages (.tar.gz)
#

for a in $packages
do
    cd ~/src/$a
    make install DESTDIR=$HOME/pkg/$a
    cd ~/pkg/$a
    rm ../$a.tar.gz
    tar -cf - . | gzip > ../$a-$platform.tar.gz
    cd ..
    rm -rf $a
done

#
# install packages (untar)
#

cd /
for a in $packages
do
    gzip -d < $HOME/pkg/$a-$platform.tar.gz | tar -xf -
done
