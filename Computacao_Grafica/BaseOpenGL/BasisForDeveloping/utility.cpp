#include "utility.h"

double BaseDeveloping::Utility::fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

int BaseDeveloping::Utility::randomNumPossion(double lambida, double fminRand, double fmaxRand)
{
    double y = exp(lambida);
    double x = 1;
    int k = -1;
    do{
        x *= fRand(fminRand,fmaxRand);
        k++;
    }
    while(x<=y);
    return k;
}
