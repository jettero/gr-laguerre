gr-phase-comparator
===========

It irks me that there's no built in GRC block for comparing phases and
considering wrap-around.  Just how close is the phase exactly?  So here is a way
to do it.  It may not be very good, but it works.

*Requirements*

* GNU Radio 3.7
* python 

Installing GNU Radio
====================

maybe just run:
sudo apt-get install gnuradio

or maybe see this page:
http://gnuradio.org/redmine/projects/gnuradio/wiki/InstallingGR

Installing the Phase Comparator
===============================

*using my build script*

    PREFIX=/usr ./build.sh

*building by hand*

    buildname=gr-phase-comparator
    buildloc=/tmp/$buildname

    git clone http://github.com/jettero/$buildname.git
    cd $buildname
    src="$(pwd)"
    mkdir $buildloc
    cd $buildloc

    # skip the -DMAKE_INSTALL_PREFIX if you want /usr/local
    cmake -DCMAKE_INSTALL_PREFIX=/usr "$src"
    sudo make install

