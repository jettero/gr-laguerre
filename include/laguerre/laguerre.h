
#ifndef INCLUDED_LAGUERRE_LAGUERRE_H
#define INCLUDED_LAGUERRE_LAGUERRE_H

#include <laguerre/api.h>
#include <gnuradio/sync_block.h>

namespace gr { namespace laguerre {

class LAGUERRE_API laguerre : virtual public gr::sync_block {
    public:
        typedef boost::shared_ptr<laguerre> sptr;
        static sptr make(int laglen);
};

} }

#endif 

