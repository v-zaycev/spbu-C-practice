/*Программа показывающая множество значений некоторой функции f(x)=(x^2-p^2)/(x-p)-p
 *для заданной константы p на заданном промежутке с заданной частотой
 *Автор - Зайцев В. А.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE,"Russian");
    double a,b,h,p;
    printf("Введите границы отрезка, шаг и число:");
    scanf("%lf %lf %lf %lf",&a,&b,&h,&p);
    printf("Таблица значений на промежутке [%lf;%lf] для функции f(x)=(x^2-p^2)/(x-p)-p\n",a,b);
    printf("       x               f(x)\n");
    for (;a<=b;a+=h)
    {
        printf("%e     %e\n",a,(a*a-p*p)/(a-p)-p);
    }
    return 0;
}
