
#ifndef INCLUDED_PHASE_COMPARATOR_PHASE_COMPARATOR_H
#define INCLUDED_PHASE_COMPARATOR_PHASE_COMPARATOR_H

#include <phase_comparator/api.h>
#include <gnuradio/hier_block2.h>
#include <gnuradio/sync_block.h>

namespace gr { namespace phase_comparator {


class PHASE_COMPARATOR_API phase_comparator : virtual public gr::hier_block2 {
    public:
        typedef boost::shared_ptr<phase_comparator> sptr;
        static sptr make(float wrap_window);
};

class PHASE_COMPARATOR_API phase_comparator_inner : virtual public gr::sync_block {
    public:
        typedef boost::shared_ptr<phase_comparator_inner> sptr;
        static sptr make(float wrap_window);
};


} }

#endif 

