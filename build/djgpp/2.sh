#!/bin/sh

#
# read carefully and modify to suit
#

set -e
set -x

# rm -rf /src/gcc
# rm -rf /obj/gcc
# rm -rf /usr/local


export source=/src/gcc.dj

# mkdir -pv $source/gmp || true
# mkdir -pv $source/mpfr || true


# cd /src/gcc
# tar --strip-components=1 -xf /net/distf/binut218.tgz
# tar --strip-components=1 -xf /net/distf/gcc431.tgz
# cd $source/gmp
# tar --strip-components=1 -xf /net/distf/gmp422.tgz
# cd $source/mpfr
# tar --strip-components=1 -xf /net/distf/mpfr231.tgz


# exit 1

export config="\
    -disable-bootstrap \
    -disable-nls \
    -enable-languages=c,c++"

#
# first build and install native
#

export host=i686-pc-cygwin
export target=i686-pc-cygwin
rm -rf /usr/local/$target
mkdir -pv /usr/local/$target/bin || true
mkdir -pv /obj/gcc/$host/$target || true

cd /obj/gcc/$host/$target
$source/configure \
    -host $host \
    -target $target \
    $config \
&& make \
&& make install


#
# now cross
#

export target=i586-pc-msdosdjgpp
mkdir -pv /obj/gcc/$host/$target || true
rm -rf /usr/local/$target
mkdir -pv /usr/local/$target/bin || true
mkdir -pv /obj/gcc/$host/$target || true

cd /usr/local/$target
# unzip /net/djgpp/beta/v2/djcrx204.zip
unzip /net/djgpp/current/v2/djcrx203.zip
cd src/stub
gcc stubify.c -o /usr/local/$target/bin/stubify

mkdir -pv /obj/gcc/$host/$target/gcc || true


cd /obj/gcc/$host/$target
$source/configure \
    $config \
    -disable-werror \
    -host $host \
    -target $target \
    -with-headers=/usr/local/$target/include \
&& make \
&& make install

#
# now cross to native
#

export host=i586-pc-msdosdjgpp
export target=i586-pc-msdosdjgpp
rm -rf /usr/local/fake-root/$target
mkdir -pv /obj/gcc/$host/$target || true
rm -rf /usr/local/$target
mkdir -pv /usr/local/$target/bin || true
mkdir -pv /obj/gcc/$host/$target || true

cd /usr/local/$target
# unzip /net/djgpp/beta/v2/djcrx204.zip
unzip /net/djgpp/current/v2/djcrx203.zip
cd src/stub
gcc stubify.c -o /usr/local/$target/bin/stubify

mkdir -pv /obj/gcc/$host/$target/gcc || true

cd /obj/gcc/$host/$target
$source/configure \
    $config \
    -disable-werror \
    -target $target \
    -host $host \
    -target $target \
    -with-headers=/usr/local/$target/include \
&& make \
&& make install DESTDIR=/usr/local/$target/install
