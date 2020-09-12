    #include "NOD.h"

int main()
{
    setlocale(LC_CTYPE,"Russian");

    int a,b;

    printf("Введите числа ");
    scanf("%i %i",&a,&b);

    if (nod_rec(a,b)!=0)
        printf("НОД чисел %i и %i\nВычисленный рекурсивно - %i\nВычисленный итеративно - %i",a,b,nod_rec(a,b),nod_it(a,b));
    else
        printf("НОД не определён");

    return 0;
}
