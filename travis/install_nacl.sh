#!/bin/sh

wget http://hyperelliptic.org/nacl/nacl-20110221.tar.bz2
tar jxvf nacl-20110221.tar.bz2
rm -rf nacl-20110221/crypto_onetimeauth/poly1305/amd64
sed -i -e 's,$, -fPIC,' nacl-20110221/okcompilers/c nacl-20110221/okcompilers/cpp
sed -i -e 's,$, -fPIC,' nacl-20110221/okcompilers/c nacl-20110221/okcompilers/cpp
sed -i -e '1,3d' nacl-20110221/okcompilers/c nacl-20110221/okcompilers/cpp
sed -i -e 's, -m32,,' nacl-20110221/okcompilers/c nacl-20110221/okcompilers/cpp
sed -i -e 's,\(shorthostname=\).*,\1"travis",' nacl-20110221/do
cd nacl-20110221/
./do
arch=`build/travis/bin/okabi`
ar -r build/travis/lib/$arch/libnacl.a build/travis/lib/$arch/randombytes.o
