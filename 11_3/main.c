#include "output.h"

int main()
{
   setlocale(LC_CTYPE,"Russian");

   int a,p;

   printf("������� ����� � ��������� ������� ���������\n");
   scanf("%i %i",&a,&p);

   const int s=nmb_lenth_p(a,p);
   char str[s];

   str_build(0,a,p,str);

   printf("����� ����� %i � �������� ������� ��������� ���������� � �������� ������� - ",a);
   reverse_nmb(s,str);

   printf("����� ����� %i � �������� ������� ��������� ���������� � ������ ������� - ",a);
   direct_nmb(s,str);

   return 0;

}
