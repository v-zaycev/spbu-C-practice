    #include "NOD.h"

int main()
{
    setlocale(LC_CTYPE,"Russian");

    int a,b;

    printf("������� ����� ");
    scanf("%i %i",&a,&b);

    if (nod_rec(a,b)!=0)
        printf("��� ����� %i � %i\n����������� ���������� - %i\n����������� ���������� - %i",a,b,nod_rec(a,b),nod_it(a,b));
    else
        printf("��� �� ��������");

    return 0;
}
