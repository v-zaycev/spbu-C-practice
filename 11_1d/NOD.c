#include "NOD.h"


int nod_it (int a,int b)
{
    int x;
    if (a<b)
    {
        x=a;
        a=b;
        b=x;
    }

    while (a%b!=0)
    {
      x=b;
      b=a%b;
      a=x;
    }
    return b;
}

int nod_rec (int a,int b)
{
    int x;
    if (a<b)
    {
        x=a;
        a=b;
        b=x;
    }

    if (a%b!=0)
        return nod_rec(b,a%b);
    else
        return b;
}
