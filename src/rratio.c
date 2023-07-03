
#include "rratio.h"
#include <stdio.h>
#include <math.h>

double f_BW(const double s, const double C, const double M, const double Gamma)
{
    const double G2 = Gamma * Gamma;
    const double sm = sqrt(s)-M;
    const double ret = C*G2 / (4.*sm*sm + G2);
    return ret;
}

double Rratio(const double s)
{
    const double Mpi = 0.13957039; // GeV

    // values from table 1 in 1107.4388
    const double C[] = { 655.5,8.5,11.5,50.0 };
    const double M[] = { 0.7819,0.7650,0.7820,1.0195 }; //GeV
    const double Gamma[] = { 0.0358,0.130,0.00829,0.00426 };//GeV
   
    double R = f_BW(s,C[3],M[3],Gamma[3]);
    const double sqs = sqrt(s);
    
    if (sqs >= M[3] ){
        R += 3. * ((4./9.) + (1./9.) + (1./9.));
    }
   
    if (sqs > 2*Mpi && sqs < 4.4*Mpi){
	const double a = 1.-4.*Mpi*Mpi/s;
	const double a3 = a*a*a;
        R += 0.25 * sqrt(a3) * (0.6473 + f_BW(s,C[0],M[0],Gamma[0]));
    }
   
    if (sqs >= 4.4*Mpi && sqs < M[3]){
        R += f_BW(s,C[1],M[1],Gamma[1]);
        R += f_BW(s,C[2],M[2],Gamma[2]);
    }
    
    return R;
}

    
