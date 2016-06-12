
#ifndef INCLUDED_LAGUERRE_LAGUERRE_H
#define INCLUDED_LAGUERRE_LAGUERRE_H

#include <laguerre/api.h>
#include <laguerre/laguerre_inline.h>
#include <gnuradio/hier_block2.h>
#include <gnuradio/sync_block.h>

namespace gr { namespace laguerre {


class LAGUERRE_API laguerre : virtual public gr::hier_block2 {
    public:
        typedef boost::shared_ptr<laguerre> sptr;
        static sptr make(float wrap_window);
};

class LAGUERRE_API laguerre_inner : virtual public gr::sync_block {
    public:
        typedef boost::shared_ptr<laguerre_inner> sptr;
        static sptr make(float wrap_window);
};


} }

#endif 

