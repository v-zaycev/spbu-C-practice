#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void one(int x)
{
    switch (x%10)
    {
        case 0: {printf("������");break;}
        case 1: {printf("���� �����");break;}
        case 2: {printf("��� �����");break;}
        case 3: {printf("��� �����");break;}
        case 4: {printf("������ �����");break;}
        case 5: {printf("���� ������");break;}
        case 6: {printf("����� ������");break;}
        case 7: {printf("���� ������");break;}
        case 8: {printf("������ ������");break;}
        case 9: {printf("������ ������");break;}
    }
}

int main()
{
    int a;
    setlocale(0,"");
    printf("������� �����: ");
    scanf("%i",&a);
  // for ( a=1;a<100;a++)
  // {
    if (a>9&&a<20)
    {
        switch (a)
        {
            case 10: {printf("������ "); break;}
            case 11: {printf("����������� "); break;}
            case 12: {printf("���������� "); break;}
            case 13: {printf("���������� "); break;}
            case 14: {printf("������������ "); break;}
            case 15: {printf("���������� "); break;}
            case 16: {printf("����������� "); break;}
            case 17: {printf("���������� "); break;}
            case 18: {printf("������������ "); break;}
            case 19: {printf("������������ "); break;}
        }
        printf("������");
    }
    else
    {
        switch (a/10)
        {
            case 0: {one(a);  break;}
            case 2: {printf("�������� ");one(a);  break;}
            case 3: {printf("�������� "); one(a);break;}
            case 4: {printf("����� ");one(a); break;}
            case 5: {printf("��������� "); one(a);break;}
            case 6: {printf("���������� ");one(a); break;}
            case 7: {printf("������������ "); one(a);break;}
            case 8: {printf("��������� "); one(a);break;}
            case 9: {printf("��������� ");one(a);break;}
        }
    }
  //  printf("\n");
  // }
    return 0;
}
