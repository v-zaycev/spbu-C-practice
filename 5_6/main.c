/* Программа, определяющая вид треугольника по длинам его сторон
 * Автор - Зайцев В. А.
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void swap(double l[], int a,int b)
{
    double k=l[a];
    l[a]=l[b];
    l[b]=k;
}

int main()
{
    double l[3];
    setlocale(0,"");
    printf("Введите стороны треугольника: ");
    scanf("%lf %lf %lf",&l[0],&l[1],&l[2]);

    //сортируем в порядке убывания a>=b>=c
    if (l[1]>l[0])
        swap(l, 0, 1);
     if (l[2]>l[0])
        swap(l, 0, 2);


    if (l[2]+l[1]<l[0])
        printf("треугольник не существует");
    else
        if (l[2]+l[1]==l[0])
            printf("треугольник вырожден в отрезок");
        else
        {
            //заменяем длины сторон на их квадраты
            l[0]*=l[0];
            l[1]*=l[1];
            l[2]*=l[2];
            if (l[2]+l[1]>l[0]) //  cos>0
                printf("треугольник остроугольный");
            else
                if (l[2]+l[1]==l[0]) //  cos=0
                    printf("треугольник прямоугольный");
                else                                    //  cos<0
                    printf("треугольник тупоугольный");
        }

    return 0;
}
