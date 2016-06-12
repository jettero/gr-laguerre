
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "laguerre_impl.h"
#include <gnuradio/math.h>

namespace gr { namespace laguerre {

laguerre::sptr laguerre::make(int laglen) {
    return gnuradio::get_initial_sptr (new laguerre_impl(laglen));
}

laguerre_impl::laguerre_impl(int laglen) : gr::sync_block("laguerre", gr::io_signature::make(1, 1, sizeof(float)), gr::io_signature::make(1, 1, sizeof(float)) ) {
    lag = new Laguerre(laglen);
}


laguerre_impl::~laguerre_impl() {
    delete lag;
}

int laguerre_impl::work(int noutput_items, gr_vector_const_void_star &input_items, gr_vector_void_star &output_items) {
    assert( input_items.size() == output_items.size() );

    const float *in = (const float *) input_items[0];
    float *out = (float *) output_items[0];

    for(int i=0; i<noutput_items; i++) {
        lag->insert(in[i]);
        out[i] = lag->F;
    }

    return noutput_items;
}


} } // close namespace gr::laguerre

