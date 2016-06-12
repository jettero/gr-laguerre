
#ifndef INCLUDED_LAGUERRE_LAGUERRE_IMPL_H
#define INCLUDED_LAGUERRE_LAGUERRE_IMPL_H

#include <laguerre/laguerre.h>
#include <gnuradio/blocks/multiply_conjugate_cc.h>
#include <gnuradio/blocks/complex_to_arg.h>

namespace gr { namespace laguerre {


class laguerre_impl : public laguerre {
    private:

    public:
        laguerre_impl(float wrap_window);
        ~laguerre_impl();
};

class laguerre_inner_impl : public laguerre_inner {
    private:
        float last;
          int roll;
        float rw[2];

    public:
        laguerre_inner_impl(float wrap_window);
        ~laguerre_inner_impl();

        // Where all the action really happens
        int work(int noutput_items,
            gr_vector_const_void_star &input_items,
            gr_vector_void_star &output_items);
};


} }

#endif

