/*Программа вычисляющая цифровой корень числа в заданной системе счисления
 *Автор - Зайцев В. А.
 */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


/*Функция sum считает сумму s цифр числа a в системе счисления p */
int sum (int a,int p)
{
    int s=0;
    while (a>0)
    {
        s+=a%p;
        a/=p;
    }
    return s;
}

/*Функция DR считает цифровой корень a в системе счисления p */
int DR (int a,int p)
{
    while (a>=p)
    {
       a=sum(a,p);
    }
    return a;
}


int main()
{
   setlocale(LC_CTYPE,"Russian");
   int a,p; // a - рассматриваемое число,p - основание системы счисления
   printf ("Введите число и основание системы счисления: ");
   scanf("%i %i",&a,&p);
   printf ("Цифровой корень равен %i",DR(a,p));
    return 0;
}
