#!/bin/bash

# local test (for the debug output)

fakeroot=/tmp/$(id -u)/usr

if [ -z "$FAKEROOT" ]; then
    FAKEROOT=$fakeroot
fi

if [ ! -d $FAKEROOT ]; then
    read -ep "FAKEROOT=" -i $FAKEROOT FAKEROOT
    [ -z "$FAKEROOT" ] && FAKEROOT=$fakeroot
fi

unset NO_INSTALL
export NO_TEST=1 PREFIX="$FAKEROOT"

./build.sh ; x=$?
echo exit=$x
[ $x -gt 1 ] && exit $x

export LD_LIBRARY_PATH="$( find $FAKEROOT -type f -name \*.so -exec dirname {} \; | paste -s -d : - )"
echo LD_LIBRARY_PATH=$LD_LIBRARY_PATH

PYTHONPATH="$FAKEROOT/lib/python2.7/dist-packages/" python python/qa_phase_comparator.py
