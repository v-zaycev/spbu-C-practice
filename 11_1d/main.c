#include "NOK.h"

int main()
{
    setlocale(LC_CTYPE,"Russian");

    int a,b;

    printf("Введите пару чисел, для которых требуется найти НОК ");
    scanf("%i %i",&a,&b);

    if (nok(a,b)!=0)
        printf("НОК чисел %i и %i равен %i ",a,b,nok(a,b));
    else
        printf("НОК не определён");

    return 0;
}
