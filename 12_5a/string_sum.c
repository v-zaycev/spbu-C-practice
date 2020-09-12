#include "string_sum.h"

double str_sum (double *a, int s2)
{
    double sum=0;
    int i=0;

    for (;i<s2;i++)
        sum+=*(a+i);

    return sum;
}


int str_mx_sum (double *a, int s1, int s2)
{
    double sum_mx=-INFINITY,sum;
    int i=0,n=0;

    for (;i<s1;i++)
    {
        sum=str_sum(a+s2*i,s2);
        if (sum>=sum_mx)
        {
            sum_mx=sum;
            n=i;
        }
    }
    return n;
}
