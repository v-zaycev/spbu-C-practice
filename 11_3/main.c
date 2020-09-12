#include "output.h"

int main()
{
   setlocale(LC_CTYPE,"Russian");

   int a,p;

   printf("Введите число и основание системы счисления\n");
   scanf("%i %i",&a,&p);

   const int s=nmb_lenth_p(a,p);
   char str[s];

   str_build(0,a,p,str);

   printf("Цифры числа %i в заданной системе счисления выведенные в обратном порядке - ",a);
   reverse_nmb(s,str);

   printf("Цифры числа %i в заданной системе счисления выведенные в прямом порядке - ",a);
   direct_nmb(s,str);

   return 0;

}
