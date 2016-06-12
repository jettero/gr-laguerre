#ifndef ___SLIST__
#define ___SLIST__

#include <list>
using namespace std;

#define siter list<double>::iterator

class slist {
    private:
        list<double>members;
        size_t _size;
        double _mean, _variance;
        bool recalc_needed;

        void recalc() {
            siter i = members.begin();
            siter e = members.end();
            double sum = 0;
            while(i != e) { sum += *i; ++i; }

            _mean = sum / members.size();

            i = members.begin();
            e = members.end();
            sum = 0;
            while(i != e) { sum += pow( *i - _mean, 2 ); ++i; }

            _variance = sum / members.size();

            recalc_needed = false;
        }

    public:
        slist(size_t s) { recalc_needed = false; _size = s; }
        void insert(double x) { recalc_needed = true; members.push_back(x); while(members.size()>_size) members.erase( members.begin() ); }
        siter begin() { return members.begin(); }
        siter end()   { return members.end(); }
        size_t size() { return members.size(); }
        bool   full() { return members.size() == _size; }

        double mean()     { if(recalc_needed) recalc(); return _mean; }
        double variance() { if(recalc_needed) recalc(); return _variance; }

        void clear() { members.clear(); }
};

#endif
