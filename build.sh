#!/bin/bash

umask 022

src_dir=$(dirname $(readlink -m $0))
buildtmp="/tmp/$(id -u)/$(basename $src_dir)/"

if [ -z "$BUILD_TMP" ]; then
    BUILD_TMP="$buildtmp"
fi

if [ -z "$PREFIX" ]; then
    read -ep "PREFIX=" -i /usr/local PREFIX
fi

if [ ! -d "${BUILD_TMP:-$buildtmp}" ]; then
    read -ep "BUILD_TMP=" -i "${BUILD_TMP:-$buildtmp}" BUILD_TMP
    [ -z "$BUILD_TMP" ] && BUILD_TMP="$buildtmp"
fi

if ! mkdir -vp "$BUILD_TMP" || ! cd "$BUILD_TMP"; then
    echo "couldn't create or chdir into BUILD_TMP=\"$BUILD_TMP\""
    exit 1
fi

if [ ! -n "$src_dir" -o ! -d "$src_dir" ]; then
    echo "couldn't figure out where $0 is"
    exit 1
fi

set -e

PREFIX="${PREFIX:-/usr/local}"

cmake -Wno-dev "-DCMAKE_INSTALL_PREFIX=$PREFIX" "$src_dir"
make -j 1

if [ -z "$NO_INSTALL" ]; then
    if touch $PREFIX/.touch 2>/dev/null
        then      make -j 1 install
        else sudo make -j 1 install
    fi
fi

if [ -z "$NO_TEST" ]
    then make test
fi
