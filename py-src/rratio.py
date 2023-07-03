#!/bin/python3
import numpy as np

#########################################
# Breit-Wigner
#########################################
def __f_BW(s, C, M, Gamma):
    f = C*Gamma**2 / (4*(np.sqrt(s)-M)**2 + Gamma**2)
    return f


###############################################
# eq (18) in 1107.4388
###############################################
def Rratio(s):
    Mpi = 0.13957039#GeV
   
    # values from table 1 in 1107.4388
    C = [655.5,8.5,11.5,50.0]
    M = [0.7819,0.7650,0.7820,1.0195]#GeV
    Gamma = [0.0358,0.130,0.00829,0.00426]#GeV
   
    R = __f_BW(s,C[3],M[3],Gamma[3])
   
    if np.sqrt(s)>=M[3]:
        R += 3 * ((2/3)**2 + (1/3)**2 + (1/3)**2)
   
    if np.sqrt(s) > 2*Mpi and np.sqrt(s) < 4.4*Mpi:
        R += 0.25 * (1-4*Mpi**2/s)**(3/2) * (0.6473 + __f_BW(s,C[0],M[0],Gamma[0]))
   
    if np.sqrt(s) >= 4.4*Mpi and np.sqrt(s)<M[3]:
        R += __f_BW(s,C[1],M[1],Gamma[1])
        R += __f_BW(s,C[2],M[2],Gamma[2])
       
    return R
