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

#
# need to fiddle with uname
#


#
# clean
#

rm -rf ~/pkg
cd ~/src
rm -rf bash-3.2
rm -rf tar-1.20
rm -rf make-3.81
rm -rf perl-5.10.0
rm -rf Python-2.5.2
rm -rf /usr/local

#
# extract (gzip | tar)
#

cd ~/src
gzip -d < bash-3.2.tar.gz | tar -xf -
gzip -d < tar-1.20.tar.gz | tar -xf -
gzip -d < make-3.81.tar.gz | tar -xf -
gzip -d < Python-2.5.2.tar.gz | tar -xf -

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
./configure -disable-dependency-tracking -disable-nls
make

cd ~/src/tar-1.20
./configure -disable-dependency-tracking -disable-nls -program-prefix=g
make

cd ~/src/make-3.81
./configure -disable-dependency-tracking -disable-nls -program-prefix=g
make

#
# -with-gcc needed on AIX to avoid trying cc/xlc
# Something else will be needed on Irix, like CC='/usr/WorkShop/usr/bin/ncc -w'.
# -disable-ipv6 needed on AIX; sounds reasonable.
#

cd ~/src/Python-2.5.2
./configure -disable-dependency-tracking -disable-nls -with-gcc -disable-ipv6
make

#
# install fakeroot (make install DESTDIR)
#

cd ~/src/bash-3.2
make install DESTDIR=$HOME/pkg/bash-3.2

cd ~/src/tar-1.20
make install DESTDIR=$HOME/pkg/tar-1.20

cd ~/src/make-3.81
make install DESTDIR=$HOME/pkg/make-3.81

cd ~/src/Python-2.5.2
make install DESTDIR=$HOME/pkg/Python-2.5.2

#
# make packages (.tar.gz)
#

cd ~/pkg
tar -cf - bash-3.2 | gzip > bash-3.2.tar.gz

cd ~/src/tar-1.20
tar -cf - tar-1.20 | gzip > tar-1.20.tar.gz

cd ~/src/make-3.81
tar -cf - make-3.81 | gzip > make-3.81.tar.gz

cd ~/src/Python-2.5.2
tar -cf - Python-2.5.2 | gzip > Python-2.5.2.tar.gz

#
# install packages (untar)
#

cd ~/src
gzip -d < bash-3.2.tar.gz | tar -xf - -C /
gzip -d < make-3.81.tar.gz | tar -xf - -C /
gzip -d < tar-1.20.tar.gz | tar -xf - -C /
gzip -d < Python-2.5.2.tar.gz | tar -xf - -C /
