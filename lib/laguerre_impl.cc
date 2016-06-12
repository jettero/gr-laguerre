
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "phase_comparator_impl.h"
#include <gnuradio/math.h>

namespace gr { namespace phase_comparator {

/* ********************* OUTER */

phase_comparator::sptr phase_comparator::make(float wrap_window) {
    return gnuradio::get_initial_sptr (new phase_comparator_impl(wrap_window));
}

phase_comparator_impl::phase_comparator_impl(float wrap_window) :
    gr::hier_block2("phase_comparator",
        gr::io_signature::make(2, 2, sizeof(gr_complex)),
        gr::io_signature::make(1, 1, sizeof(float))
    )
{

    // ~/dlds/gnuradio/gnuradio-3.7.2.1/gr-digital/lib/ofdm_sync_sc_cfb_impl.h
    // ~/dlds/gnuradio/gnuradio-3.7.2.1/gr-digital/lib/ofdm_sync_sc_cfb_impl.cc

    gr::blocks::multiply_conjugate_cc::sptr conj( gr::blocks::multiply_conjugate_cc::make() );
    gr::blocks::complex_to_arg::sptr        carg( gr::blocks::complex_to_arg::make()        );
    phase_comparator_inner::sptr            work( phase_comparator_inner::make(wrap_window) );

    connect(self(), 0, conj, 0);
    connect(self(), 1, conj, 1);

    connect(conj, 0, carg, 0);
    connect(carg, 0, work, 0);
    connect(work, 0, self(), 0);
}

phase_comparator_impl::~phase_comparator_impl() {
    /* important code here */
}

/* ********************* INNER */

phase_comparator_inner::sptr phase_comparator_inner::make(float wrap_window) {
    return gnuradio::get_initial_sptr (new phase_comparator_inner_impl(wrap_window));
}

phase_comparator_inner_impl::phase_comparator_inner_impl(float wrap_window) :
    gr::sync_block("phase_comparator_inner",
        gr::io_signature::make(1, 1, sizeof(float)),
        gr::io_signature::make(1, 1, sizeof(float))
    )
{
    last = 0;
    roll = 0;
    rw[0] = -M_PI + wrap_window;
    rw[1] =  M_PI - wrap_window;
}

phase_comparator_inner_impl::~phase_comparator_inner_impl() {
    /* important code here */
}

int phase_comparator_inner_impl::work(int noutput_items, gr_vector_const_void_star &input_items,
          gr_vector_void_star &output_items) {

    assert( input_items.size() == output_items.size() );

    const float *in = (const float *) input_items[0];
    float *out = (float *) output_items[0];

    for(int i=0; i<noutput_items; i++) {
        if( last > rw[1] && in[i] < rw[0] )
            roll ++;

        if( last < rw[0] && in[i] > rw[1] )
            roll --;

        out[i] = in[i] + 2*M_PI*roll;

        last = in[i];
    }

    return noutput_items;
}


} }

