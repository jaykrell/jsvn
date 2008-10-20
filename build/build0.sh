#!/bin/sh

#
# prereqs:
# tar, make, sh, gzip, gcc
# not done yet:
#  use uncompressed tar-1.20 and build gzip
#  bzip2
#
# vendor tar often can't extract gcc
# vendor make often can't build gcc
# Python is used for scripting hereafter
#

#
# pass 0 -- build up to date
#   bash
#   make
#   tar
#   python
#   gzip (not yet)
#   bzip2 (not yet)
#

set -e
set -x

# clean

cd ~/src
rm -rf bash-3.2
rm -rf tar-1.20
rm -rf make-3.81
rm -rf perl-5.10.0
rm -rf Python-2.5.2
rm -rf /usr/local

# extract

cd ~/src
gzip -d bash-3.2.tar.gz | tar -xf -
gzip -d tar-1.20.tar.gz | tar -xf -
gzip -d make-3.81.tar.gz | tar -xf -
gzip -d Python-2.5.2.tar.gz | tar -xf -

# configure and make

cd ~/src/bash-3.2
./configure -disable-dependency-tracking -disable-nls
make

cd ~/src/tar-1.20
./configure -disable-dependency-tracking -disable-nls -program-prefix=g
make

cd ~/src/make-3.81
./configure -disable-dependency-tracking -disable-nls -program-prefix=g
make

cd ~/src/Python-2.5.2
./configure -disable-dependency-tracking -disable-nls -with-gcc -disable-ipv6
make

# install

cd  ~/src/bash-3.2
make install

cd  cd ~/src/tar-1.20
make install

cd ~/src/make-3.81
make install
