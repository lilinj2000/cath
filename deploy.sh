#! /bin/sh

home_app=~/app

home_cath=${home_app}/cath

./configure --prefix=${home_cath}

if test -d ${home_cath}; then
    rm -rf ${home_cath}
fi

make install

make distclean
