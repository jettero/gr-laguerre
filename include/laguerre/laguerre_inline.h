
// Based on Math::Business::LaguerreFilter
// https://github.com/jettero/stockmonkey/blob/master/Business/LaguerreFilter.pm

// int main() {
//     Laguerre lag(10);

//     for(int i=1; i<=20; i++)
//         lag.insert(7 + i*2.1);

//     printf("F = %0.13f\n", lag.F);

//     return 0;
// }

#ifndef ___LAGUERRE__
#define ___LAGUERRE__

#include <stdio.h>
#include <math.h>

#include "slist.h"

class Laguerre {
    private:
        double l[4];
        int stage; // counter to see where we are in the polynomial filter
        int full;  // counter to see if F is ready
        double alpha;
        size_t current_length;

    public:
        double F; // filter output

        Laguerre(size_t length) {
            reset(length);
            current_length = length;
        }

        bool is_full() { return full<1; }

        void reset(size_t length) {
            alpha = 2.0/(1.0+length);
            stage = 0;
            full  = length;

            F = -1;
        }

        void reset_to(double x) {
            reset(current_length);

            for(int i=0; i<current_length/2; i++)
                insert(x);
        }

        void insert(double x) {
            if( full > 0 )
                full --;

            if( stage ) {
                double o[4];
                int i;

                for(i=0; i<4; i++)
                    o[i] = l[i];

                l[0] = alpha*x + (1-alpha)*o[0];

                for(i=1; i<stage && i<4; i++)
                    l[i] = (1-alpha)*o[i] - (1-alpha)*l[i-1] + o[i-1];

                if( stage == 4 )
                    F = (l[0] + l[1]*2 + l[2]*2 + l[3]) / 6.0;

                for(i=stage; i<4; i++)
                    l[i] = o[i-1];

                if( stage < 4 )
                    stage ++;

            } else {
                l[0] = x;
                stage = 1;
            }

        }

};

#endif
