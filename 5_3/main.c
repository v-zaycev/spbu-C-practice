#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void one(int x)
{
    switch (x%10)
    {
        case 0: {printf("рублей");break;}
        case 1: {printf("один рубль");break;}
        case 2: {printf("два рубля");break;}
        case 3: {printf("три рубля");break;}
        case 4: {printf("четыре рубля");break;}
        case 5: {printf("пять рублей");break;}
        case 6: {printf("шесть рублей");break;}
        case 7: {printf("семь рублей");break;}
        case 8: {printf("восемь рублей");break;}
        case 9: {printf("девять рублей");break;}
    }
}

int main()
{
    int a;
    setlocale(0,"");
    printf("Введите сумму: ");
    scanf("%i",&a);
  // for ( a=1;a<100;a++)
  // {
    if (a>9&&a<20)
    {
        switch (a)
        {
            case 10: {printf("десять "); break;}
            case 11: {printf("одиннацдать "); break;}
            case 12: {printf("двенадцать "); break;}
            case 13: {printf("тринадцать "); break;}
            case 14: {printf("четырнадцать "); break;}
            case 15: {printf("пятнадцать "); break;}
            case 16: {printf("шестнадцать "); break;}
            case 17: {printf("семнадцать "); break;}
            case 18: {printf("восемнадцать "); break;}
            case 19: {printf("девятнадцать "); break;}
        }
        printf("рублей");
    }
    else
    {
        switch (a/10)
        {
            case 0: {one(a);  break;}
            case 2: {printf("двадцать ");one(a);  break;}
            case 3: {printf("тридцать "); one(a);break;}
            case 4: {printf("сорок ");one(a); break;}
            case 5: {printf("пятьдесят "); one(a);break;}
            case 6: {printf("шестьдесят ");one(a); break;}
            case 7: {printf("семсемьдесят "); one(a);break;}
            case 8: {printf("воседесят "); one(a);break;}
            case 9: {printf("девяносто ");one(a);break;}
        }
    }
  //  printf("\n");
  // }
    return 0;
}
