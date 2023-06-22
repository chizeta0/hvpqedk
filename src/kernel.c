
#include <math.h>

#include "kernel.h"

#define GAMMA_E 0.57721566490153286061
#define PI 3.141592653589793

#define EXPANSION_THRESHOLD 1.05

double Ktilde(const double t, const double m_mu)
{
    return mu2_ft(t,m_mu) / (m_mu*m_mu);
}

double mu2_ft(const double t, const double m_mu)
{
    const double that = t * m_mu;
    if(that == 0){
	return 0.;
    }
    if(that < EXPANSION_THRESHOLD){
	return mu2_ft_small(that);
    }
    else {
	return mu2_ft_large(that);
    }
}

double mu2_ft_small(const double th)
{
    const double pi2 = PI*PI;
    const double th2 = th*th;
    const double th4 = th2*th2;
    const double th6 = th4*th2;
    const double th8 = th6*th2;
    const double th10 = th8*th2;
    const double th12 = th10*th2;
    const double lnthg = log(th) + GAMMA_E;

    const double x4 = th4/9.;
    const double x6 = th6 * (120.*lnthg - 169.)/5400.;
    const double x8 = th8 * (210.*lnthg - 401.)/88200.;
    const double x10 = th10 * (360.*lnthg - 787.)/2916000.;
    const double x12 = th12 * (3080.*lnthg - 7353.)/768398400.;

    return pi2 * (x4 + x6 + x8 + x10 + x12);
}

double mu2_ft_large(const double th)
{
    const double pi2 = PI*PI;
    const double th2 = th*th;
    const double lnthg = log(th) + GAMMA_E;
    const double pre = sqrt(PI/th) * exp(-2.*th);
    const double thx1 = (1./th - 0.7);
    const double thx2 = thx1*thx1;
    const double thx3 = thx2*thx1;
    const double thx4 = thx3*thx1;
    const double thx5 = thx4*thx1;
    const double thx6 = thx5*thx1;
    
    const double a = th2 - 2.*PI*th + 2.*(4.*lnthg-1.) + 4./th2;
    const double b = 0.0197159*thx6 - 0.0284086*thx5 + 0.0470604*thx4 - 0.107632*thx3
	+ 0.688813*thx2 + 4.71371*thx1 + 3.90388;

    return 2*pi2*( a - pre*b );
}
