#include "in_out.h"

void int_scan (int *a_nmb,int s)
{
    int i=0;
    for (;i<s;i++)
        scanf("%i",(a_nmb+i));
    return;
}

void int_print (int *a_nmb,int s)
{
    int i=0;
    for (;i<s;i++)
        printf("%i ",*(a_nmb+i));
    return;
}

void double_scan (double *a_nmb,int s)
{
    int i=0;
    for (;i<s;i++)
        scanf("%lf",(a_nmb+i));
    return;
}

void double_print (double *a_nmb,int s)
{
    int i=0;
    for (;i<s;i++)
        printf("%lf ",*(a_nmb+i));
    return;
}

void double_scan_matrix (double *a_nmb,int s1,int s2)
{
    int i=0;

    for (;i<s1;i++)
    {
        double_scan(a_nmb+s2*i,s2);
    }
    return;
}
