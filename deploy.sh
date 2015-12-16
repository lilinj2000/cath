#! /bin/sh

home_app=~/app

if test -d /llj/app ; then
   home_app=/llj/app
fi

home_cath=${home_app}/cath

./configure --prefix=${home_cath}

if test -d ${home_cath}; then
    rm -rf ${home_cath}
fi

make install

make distclean
