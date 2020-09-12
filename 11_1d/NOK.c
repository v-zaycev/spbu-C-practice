#include "NOK.h"


int nok (int a,int b)
{
    if (a*b!=0)
        return (a*b/nod_it(a,b));
    else
        return 0;
}

