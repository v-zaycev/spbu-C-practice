/*Программа показывающая множество значений некоторой функции (в данном случае y=sin(x+x^2))
 *на заданном отрезке с заданной частотой
 *Автор - Зайцев В. А.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE,"Russian");
    double a,b,h;
    printf("Введите границы отрезка и шаг:");
    scanf("%lf %lf %lf",&a,&b,&h);
    printf("Таблица значений на промежутке [%lf;%lf] для функции y=sin(x+x^2)\n",a,b);
    printf("      x          y\n");
    for (;a<=b;a+=h)
    {
        printf("%10.5lf %10.5lf\n",a,sin(a+a*a));
    }
    return 0;
}
