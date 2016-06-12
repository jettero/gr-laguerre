#!/usr/bin/env python2
# coding: utf8

from gnuradio import gr, gr_unittest
from gnuradio import blocks
from gnuradio import analog

import phase_comparator, os

class qa_root_sync(gr_unittest.TestCase):
    def setUp(self):
        self.tb = gr.top_block()

    def tearDown(self):
        self.tb = None

    def _get_output(self, samp_rate=10000, f2=1000, f1=1100, output=2000):
        i1 = analog.sig_source_c(samp_rate, analog.GR_COS_WAVE, f1, 1, 0)
        i2 = analog.sig_source_c(samp_rate, analog.GR_COS_WAVE, f2, 1, 0)
        pc = phase_comparator.phase_comparator(0.3415)

        head = blocks.head(gr.sizeof_float*1, output)
        outs = blocks.vector_sink_f(1)

        self.tb.connect( (i1,0), (pc,0) )
        self.tb.connect( (i2,0), (pc,1) )
        self.tb.connect( (pc,0), (head,0) )
        self.tb.connect( (head,0), (outs,0) )

        self.tb.run()

        return outs.data()

    def test_000(self):
        data = self._get_output()

        for i in range( len(data)-1 ):
            j = i + 1
            self.assertLess(data[i], data[j], "%f < %f" % (data[i],data[j]) )

    def test_001(self):
        data = self._get_output(f2=1100, f1=1000)

        for i in range( len(data)-1 ):
            j = i + 1
            self.assertGreater(data[i], data[j], "%f > %f" % (data[i],data[j]) )

if __name__ == '__main__':
    x = os.getenv("TEST_PREFIX")

    if not x:
        x = "test_"

    gr_unittest.TestLoader.testMethodPrefix = x
    gr_unittest.main ()
