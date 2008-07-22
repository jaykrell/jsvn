set -e
set -x

  export target=i586-pc-msdosdjgpp
  export prefix=/usr/$target
  export PATH=$PATH:$prefix/bin
  export CC=/usr/bin/gcc

  mkdir -p $prefix/$target

  mkdir -p packages/cross

  cd packages

  gcc423s.zip
  bnu217s.zip
  djcrx203.zip
  gcc423s2.zip

  cd cross

  unzip -a ../djcrx203.zip
  unzip -a ../gcc423s2.zip
  chmod 744 unpack-gcc.sh
  ./unpack-gcc.sh ../gcc-4.23.tar.gz

  cd gnu
  tar xzvf ../../binutils-2.13.1.tar.gz
  mkdir binut.obj gcc.obj

  cd ..
  mkdir $prefix/$target/bin
  cp -r lib $prefix/$target
  cp -r include $prefix/$target

  cd src/stub
  $CC -O2 stubify.c -o $prefix/$target/bin/stubify

  cd ../../gnu/binut.obj

  ../binutils-2.13.1/configure --prefix=$prefix -target=$target >& configure.log

  make >& make.log
  make install >& install.log

  cd ../gcc.obj

  ../gcc-4.23/configure --prefix=$prefix -target=$target -with-headers=$prefix/$target/include >& configure.log

  make >& make.log
  make install >& install.log

  cd $prefix/$target/lib

  ln -s libstdc++.a $prefix/$target/lib/libstdcxx.a
  ln -s libsupc++.a $prefix/$target/lib/libsupcxx.a
  ln -s $prefix/bin/$target-gcc /usr/local/bin/djgcc
  ln -s $prefix/bin/$target-g++ /usr/local/bin/djgpp
