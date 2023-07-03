#!/bin/python3

# install the hvpqedk module before running the test!

import hvpqedk as k
import unittest
from sys import argv

thisdir = '/'.join(argv[0].split('/')[:-1])
if thisdir == '':
    thisdir = '.'
exec(open('{}/../rratio.py'.format(thisdir)).read())

class TestRRatio(unittest.TestCase):

    def setUp(self):
        self.slist = [ s/100 for s in range(20,200) ]

    def test_compare_to_module(self):
        for s in self.slist:
            self.assertAlmostEqual( k.Rratio(s), Rratio(s) )

if __name__ == '__main__':
    unittest.main()
    
