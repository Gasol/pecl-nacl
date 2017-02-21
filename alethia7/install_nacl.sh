#!/bin/bash
set -xv

f=nacl-20110221.tar.bz2
short_name=${f%%.tar.bz2}
no_dash=`hostname | sed -e 's/-//'`

cleanup() {

	[ -f $f ] && rm $f
}

trap cleanup INT TERM EXIT

wget http://hyperelliptic.org/nacl/$f
tar jxf $f 
printf "Build takes ~30 minutes\nBegin: %s\n" "`date +%r`"

time (cd $short_name ; ./do)
arch=$($short_name/build/$no_dash/bin/okabi)
ar -r $short_name/build/$no_dash/lib/$arch/libnacl.a $short_name/build/$no_dash/lib/$arch/randombytes.o

printf "End: %s\n" "`date +%r`"
