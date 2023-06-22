
# This is the pure python implementation of the functions Ktilde, mu2_ft, mu2_ft_small, and mu2_ft_large
# which are also implemented in C (src/kernel.c)

import math

# Calculate Ktilde according to arXiv:1705.01775 using expansions of ftilde, see eqs (58), (60)
def Ktilde(t,m_mu):
    return mu2_ft(t,m_mu) / (m_mu*m_mu)

# Calculate f tilde according to arXiv:1705.01775 using expansions (58) or (60)
def mu2_ft(t,m_mu):
    thresh = 1.05
    that = t * m_mu
    if that == 0:
        return 0
    elif that < thresh:
        return mu2_ft_small(that)
    else:
        return mu2_ft_large(that)

# Calculate expansion of ftilde according to arXiv:1705.01775, eq (60)
def mu2_ft_small(th):
    GAMMA_E = 0.57721566490153286061
    pi2 = math.pi*math.pi
    th2 = th*th
    th4 = th2*th2
    th6 = th4*th2
    th8 = th6*th2
    th10 = th8*th2
    th12 = th10*th2
    lnthg = math.log(th) + GAMMA_E

    x4 = th4/9.
    x6 = th6 * (120.*lnthg - 169.)/5400.
    x8 = th8 * (210.*lnthg - 401.)/88200.
    x10 = th10 * (360.*lnthg - 787.)/2916000.
    x12 = th12 * (3080.*lnthg - 7353.)/768398400.

    return pi2 * (x4 + x6 + x8 + x10 + x12)

# Calculate expansion of ftilde according to arXiv:1705.01775, eq (58)
def mu2_ft_large(th):
    GAMMA_E = 0.57721566490153286061
    pi2 = math.pi*math.pi
    th2 = th*th
    lnthg = math.log(th) + GAMMA_E
    thx1 = (1./th - 0.7)
    thx2 = thx1*thx1
    thx3 = thx2*thx1
    thx4 = thx3*thx1
    thx5 = thx4*thx1
    thx6 = thx5*thx1

    a = th2 - 2.*PI*th + 2.*(4.*lnthg-1.) + 4./th2
    b = 0.0197159*thx6 - 0.0284086*thx5 + 0.0470604*thx4 - 0.107632*thx3 + 0.688813*thx2 + 4.71371*thx1 + 3.90388

    return 2*pi2*( a - pre*b )
    
