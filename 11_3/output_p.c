#include "output.h"

int nmb_lenth_p (int a,int p)
{
    int x=1;
    while (a>p-1)
    {
        a/=p;
        x++;
    }
    return x;
}


void str_build (int n,int a,int p,char *str)
{
    if (a==0&&n==0)
    {
        *(str+n*sizeof(char))='0';
    }
    else
        if (a!=0)
        {
            if (a%p<10)
            {
               *(str+n*sizeof(char))=(char)('0'+a%p);
            }
            else
            {
                *(str+n*sizeof(char))=(char)('A'+a%p%10);
            }
            str_build(n+1,a/p,p,str);
        }
    return ;
}


void reverse_nmb (const int s,char *str)
{
    int i=0;
    for (;i<s;i++)
        printf("%c",*(str+i*sizeof(char)));
    printf("\n");
}

void direct_nmb (const int s,char *str)
{
    int i=s;
    for (;i>-1;i--)
        printf("%c",*(str+i*sizeof(char)));
    printf("\n");
}
