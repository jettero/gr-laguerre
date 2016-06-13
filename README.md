gr-laguerre
===========

Laguerre filters are meant to be a bit more adaptive than I have this set up. I
built the trivial parts and just never got around to the rest. I've you're
familiar with them, just look at the source to see what I mean.

If you're not, then this is basically a cool super fast moving average. I built
an example with a PLL. The loop output oscillates around the detected frequency
(indicating the phase) and I set 3 Lags to match it at different sample lengths.

This documentation is pretty thin, feel free to email me or contact me through
Github if by some quirk of common interest, you're trying to use this and wonder
what the hell I'm trying to say.

*Requirements*

* GNU Radio 3.7
* python 

Installing GNU Radio
====================

maybe just run:
sudo apt-get install gnuradio

or maybe see this page:
http://gnuradio.org/redmine/projects/gnuradio/wiki/InstallingGR

Installing the Filter
===============================

*using my build script*

    PREFIX=/usr ./build.sh

*building by hand*

    buildname=gr-laguerre
    buildloc=/tmp/$buildname

    git clone http://github.com/jettero/$buildname.git
    cd $buildname
    src="$(pwd)"
    mkdir $buildloc
    cd $buildloc

    # skip the -DMAKE_INSTALL_PREFIX if you want /usr/local
    cmake -DCMAKE_INSTALL_PREFIX=/usr "$src"
    sudo make install

