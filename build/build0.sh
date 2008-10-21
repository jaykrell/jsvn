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

configure="./configure -disable-dependency-tracking -disable-nls"

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
# clean
#

rm -rf $HOME/pkg
cd $HOME/src
for a in $packages
do
    : # rm -rf $a
done
rm -rf perl-5.10.0
rm -rf /usr/local/* || true

#
# extract (gzip | tar)
#

cd $HOME/src
for a in $packages
do
    test -d $a || gzip -d < $a.tar.gz | tar -xf -
done

#
# Irix doesn't like tar's verify.h
#

case "${unameS}" in
IRIX*)
    cd $HOME/src/tar-1.20/lib
    test -f verify.h.orig || cp verify.h verify.h.orig
    cat <<EOF > verify.h
#if defined(__GNUC__) || !defined(_ABIO32)
/* Irix /usr/WorkShop/usr/bin/ncc has trouble here */
EOF
    cat verify.h.orig >> verify.h
    cat <<EOF >> verify.h
#else
#define verify(x) /* nothing */
#endif
EOF
    ;;
esac

#
# configure and make
#


case "${unameS}" in
IRIX*)
    ;;

*)

cd $HOME/src/tar-1.20

test -f Makefile || ${configure} -program-prefix=g

case "${unameS}" in
IRIX*)
    cd $HOME/src/tar-1.20

    cat <<EOF >> config.h
#if !defined(__GNUC__) && defined(_ABIO32)
/* Irix /usr/WorkShop/usr/bin/ncc has trouble in malloca.c. */
#undef HAVE_ALLOCA
#endif
#define S_IXUGO         (S_IXUSR|S_IXGRP|S_IXOTH)
EOF
    cd lib
    test -f malloca.h.orig || cp malloca.h malloca.h.orig
    cat <<EOF > malloca.h
#if defined(__GNUC__) || !defined(_ABIO32)
/* Irix /usr/WorkShop/usr/bin/ncc has trouble here. */
EOF
    cat malloca.h.orig >> malloca.h
    cat <<EOF >> malloca.h
#else

#ifndef _MALLOCA_H
#define _MALLOCA_H

#include <alloca.h>
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#define safe_alloca(N) ((void) (N), NULL)
void* mmalloca(size_t n);
#define malloca(N) mmalloca (N)
void* mmalloca(size_t n);
#define freea free
void* nmalloca(size_t n, size_t s);

#ifdef __cplusplus
}
#endif
#endif /* _MALLOCA_H */
#endif /* defined(__GNUC__) || !defined(_ABIO32) */
EOF

    test -f obstack.c.orig || cp obstack.c obstack.c.orig
    sed -e "s/DEFAULT_ALIGNMENT = offsetof (struct fooalign, u)/DEFAULT_ALIGNMENT = sizeof (union fooround)/" < obstack.c.orig > obstack.c

    cat <<EOF > stdbool.h
typedef int bool;
#define false 0
#define true 1
EOF
    cat <<EOF > stdint.h
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned uint32_t;
/*typedef unsigned uintmax_t;*/
#define PRIuMAX "%u"
EOF

    cd ../src

    cat <<EOF > configmake.h
#define DEFAULT_RMT_COMMAND
#define FNM_CASEFOLD 0
#define FNM_FILE_NAME 0
#define FNM_LEADING_DIR 0
#define LOCALEDIR 0
#define DECL_SHOW_DEFAULT_SETTINGS(a, b) { /* nothing */ }
EOF
    echo "" > rmt-command.h

    test -f xheader.c.orig || cp xheader.c xheader.c.orig
    sed -e "s/ = stpcpy / = (char\*) stpcpy /; s/code_time (mtime \? \*mtime : st->mtime, keyword, xhdr);/if (mtime) { code_time (*mtime, keyword, xhdr); } else { code_time(st->mtime, keyword, xhdr); }/" < xheader.c.orig > xheader.c

    test -f incremen.c.orig || cp incremen.c incremen.c.orig
    sed -e "s/dump->elv\[i\+\+\] = p \+ 1/dump->elv\[i\+\+] = (char\*) p + 1/" < incremen.c.orig > incremen.c

    test -f checkpoint.c.orig || cp checkpoint.c checkpoint.c.orig
    sed -e "s/ = stpcpy / = (char\*) stpcpy /" < checkpoint.c.orig > checkpoint.c

    test -f tar.c.orig || cp tar.c tar.c.orig
    sed -e "s/# define DECL_SHOW_DEFAULT_SETTINGS/# define xDECL_SHOW_DEFAULT_SETTINGS/" < tar.c.orig > tar.c
    ;;
esac


make

esac


cd $HOME/src/make-3.81
test -f Makefile || ${configure} -program-prefix=g
make

cd $HOME/src/Python-2.5.2
test -f Makefile || ${configure} ${configure_python}
make

#
# Irix make cannot build bash.
#

cd $HOME/src/make-3.81
make install

cd $HOME/src/bash-3.2
test -f Makefile || ${configure}
gmake


#
# install fakeroot (make install DESTDIR)
# make packages (.tar.gz)
#

for a in $packages
do
    cd $HOME/src/$a
    gmake install DESTDIR=$HOME/pkg/$a
    cd $HOME/pkg/$a
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
