
#ifndef INCLUDED_LAGUERRE_LAGUERRE_IMPL_H
#define INCLUDED_LAGUERRE_LAGUERRE_IMPL_H

#include <laguerre/laguerre.h>

namespace gr { namespace laguerre {


class laguerre_impl : public laguerre {
    private:

    public:
        laguerre_impl(int laglen);
        ~laguerre_impl();
};

class laguerre_inner_impl : public laguerre_inner {
    private:
        Laguerre lag;

    public:
        laguerre_inner_impl(int laglen);
        ~laguerre_inner_impl();

        int work(int noutput_items,
            gr_vector_const_void_star &input_items,
            gr_vector_void_star &output_items);
};


} }

#endif

