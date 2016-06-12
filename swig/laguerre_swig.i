/* -*- c++ -*- */

#define LAGUERRE_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
//%include "laguerre_swig_doc.i"

%{
#include "laguerre/laguerre.h"
%}


%include "laguerre/laguerre.h"
GR_SWIG_BLOCK_MAGIC2(laguerre, laguerre);
