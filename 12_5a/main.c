#include "string_sum.h"

int main()
{
    setlocale(LC_CTYPE,"Russian");
    int a,b;
    printf("Введите количество строк и количество столбцов в матрице ");
    scanf("%i %i",&a,&b);
    double m[a][b];
    double_scan_matrix(m[0],a,b);
    printf("Номер строки с наибольшей суммой элементов - %i",1+str_mx_sum(m[0],a,b));

    return 0;
}
