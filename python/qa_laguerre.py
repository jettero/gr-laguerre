#!/usr/bin/env python2
# coding: utf8

from gnuradio import gr, gr_unittest
from gnuradio import blocks
from gnuradio import analog

import laguerre, os

class qa_root_sync(gr_unittest.TestCase):
    def setUp(self):
        pass

    def tearDown(self):
        pass

    def _get_output(self, laglen=3, samp_rate=10000, Hz=60, output=2000):
        inps = analog.sig_source_f(samp_rate, analog.GR_COS_WAVE, Hz, 1, 0)
        head = blocks.head(gr.sizeof_float*1, output)
        outs = blocks.vector_sink_f(1)

        mini = gr.top_block()
        mini.connect( (inps,0), (head,0) )
        mini.connect( (head,0), (outs,0) )

        mini.run()

        mini = gr.top_block()
        srcv = blocks.vector_source_f( outs.data() )
        lagf = laguerre.laguerre(laglen)
        outv = blocks.vector_sink_f(1)

        mini.connect( (srcv,0), (lagf,0) )
        mini.connect( (lagf,0), (outv,0) )

        mini.run()

        return (outs.data(), outv.data(),)

    def test_000(self, delta=5, output=100, Hz=60, samp_rate=10000, required_correctness_percent=80):
        data = zip( *self._get_output(Hz=Hz, samp_rate=samp_rate, output=output) )
        right = 0

        for i,j in [ (i,i+delta) for i in range( len(data)-delta ) ]:
            s = (data[i][0], data[j][0])
            l = (data[i][1], data[j][1])

            if s[0]<s[1]:
                if l[0]<l[1]:
                    right += 1

            elif s[0]>s[1]:
                if l[0]>l[1]:
                    right += 1

        right *= 1.0
        right /= output
        right *= 100

        self.assertGreater( right, required_correctness_percent, 'correctness %0.2f%%' % right )

if __name__ == '__main__':
    x = os.getenv("TEST_PREFIX")

    if not x:
        x = "test_"

    gr_unittest.TestLoader.testMethodPrefix = x
    gr_unittest.main ()
