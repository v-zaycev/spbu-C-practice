#include "exclude_rep.h"

int main()
{
    setlocale(LC_CTYPE,"Russian");
    int a,k;
    scanf("%i",&a);
    int a_nmb[a];
    int_scan(a_nmb,a);
    k=exclude_rep(a_nmb,a);
    int_print(a_nmb,k);
    return 0;
}
