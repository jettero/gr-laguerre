
#ifndef INCLUDED_PHASE_COMPARATOR_PHASE_COMPARATOR_IMPL_H
#define INCLUDED_PHASE_COMPARATOR_PHASE_COMPARATOR_IMPL_H

#include <phase_comparator/phase_comparator.h>
#include <gnuradio/blocks/multiply_conjugate_cc.h>
#include <gnuradio/blocks/complex_to_arg.h>

namespace gr { namespace phase_comparator {


class phase_comparator_impl : public phase_comparator {
    private:

    public:
        phase_comparator_impl(float wrap_window);
        ~phase_comparator_impl();
};

class phase_comparator_inner_impl : public phase_comparator_inner {
    private:
        float last;
          int roll;
        float rw[2];

    public:
        phase_comparator_inner_impl(float wrap_window);
        ~phase_comparator_inner_impl();

        // Where all the action really happens
        int work(int noutput_items,
            gr_vector_const_void_star &input_items,
            gr_vector_void_star &output_items);
};


} }

#endif

