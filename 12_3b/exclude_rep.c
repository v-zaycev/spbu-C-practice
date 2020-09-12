#include "exclude_rep.h"

int exclude_rep (int arr[],int arr_size)
{
 int i=0,j=0,k=0,d=0;
    for (;i<arr_size;i++)
    {
        d=0;
        for (j=0;j<k;j++)
        {
            if (arr[i]==arr[j])
            {
                d=1;
            }

        }
        if (!d)
        {
            arr[k]=arr[i];
            k++;
        }
    }
    return k;
}
