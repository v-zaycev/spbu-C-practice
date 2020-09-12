/*Программа рисующая рамку с заданными сторонами и толщиной
 *Автор - Зайцев В. А.
 */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*Функция draw рисует рамку с длиной m, шириной n и толщиной d*/

void draw (int m, int n, int d)
{
    int i=0,j=0;
    for (;i<n;i++)
    {
        if (i<d||i>=n-d)  // рисование горизонтальных граней
            for (j=0;j<m;j++)
                printf("*");
        else   // рисование боковых граней
            for (j=0;j<m;j++)
                if (j<d||j>=m-d)
                    printf("*");
                else
                    printf(" ");
        printf("\n");
    }
}

int main()
{
    setlocale (LC_CTYPE,"Russian");
    int m,n,d; // m - длина рамки, n - ширина рамки, d - толщина рамки
    printf("Введите стороны рамки и её толщину: ");
    scanf("%i %i %i", &m, &n, &d);
    draw (m,n,d);
    return 0;
}
