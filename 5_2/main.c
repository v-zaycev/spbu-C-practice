#include <stdio.h>
#include <stdlib.h>

int main()
{
    int d1,d2,m1,m2,y1,y2,v1,v2;
    setlocale(0,"");
    printf("������� ���� �������� � ���� DD MM YYYY\n");
    printf("������ �������:");
    scanf("%i %i %i",&d1,&m1,&y1);
    printf("������ �������:");
    scanf("%i %i %i",&d2,&m2,&y2);
    v1=d1+35*(m1-1)+500*y1;
    v2=d2+35*(m2-1)+500*y2;
    if (v1<v2)
         printf("������ ������� ������");
    else if (v1>v2)
         printf("������ ������� ������");
    else /*if (v1==v2)*/
         printf("������� ���� ����� ����������");
    return 0;
}
