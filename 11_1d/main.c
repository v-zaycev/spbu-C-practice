#include "NOK.h"

int main()
{
    setlocale(LC_CTYPE,"Russian");

    int a,b;

    printf("������� ���� �����, ��� ������� ��������� ����� ��� ");
    scanf("%i %i",&a,&b);

    if (nok(a,b)!=0)
        printf("��� ����� %i � %i ����� %i ",a,b,nok(a,b));
    else
        printf("��� �� ��������");

    return 0;
}
