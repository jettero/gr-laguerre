/* -*- c++ -*- */

#define PHASE_COMPARATOR_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
//%include "phase_comparator_swig_doc.i"

%{
#include "phase_comparator/phase_comparator.h"
%}


%include "phase_comparator/phase_comparator.h"
GR_SWIG_BLOCK_MAGIC2(phase_comparator, phase_comparator);
