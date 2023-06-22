#!/bin/python3

# install the hvpqedk module before running the test!

import hvpqedk as k
import unittest
from sys import argv

thisdir = '/'.join(argv[0].split('/')[:-1])
if thisdir == '':
    thisdir = '.'
exec(open('{}/../kernel.py'.format(thisdir)).read())

class TestKernel(unittest.TestCase):

    def setUp(self):
        self.m_mu_MeV = 105.658374
        self.a = 0.0818551850
        self.unit_MeV_fm = 197.327
        self.m_mu = self.m_mu_MeV * self.a / self.unit_MeV_fm
    
    def test_compare_to_module(self):
        for i in range(128):
            self.assertAlmostEqual( k.Ktilde( i, self.m_mu ), Ktilde( i, self.m_mu ) )

if __name__ == '__main__':
    unittest.main()

