/* ���������, ������������ ��� ������������ �� ������ ��� ������
 * ����� - ������ �. �.
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void swap(double l[], int a,int b)
{
    double k=l[a];
    l[a]=l[b];
    l[b]=k;
}

int main()
{
    double l[3];
    setlocale(0,"");
    printf("������� ������� ������������: ");
    scanf("%lf %lf %lf",&l[0],&l[1],&l[2]);

    //��������� � ������� �������� a>=b>=c
    if (l[1]>l[0])
        swap(l, 0, 1);
     if (l[2]>l[0])
        swap(l, 0, 2);


    if (l[2]+l[1]<l[0])
        printf("����������� �� ����������");
    else
        if (l[2]+l[1]==l[0])
            printf("����������� �������� � �������");
        else
        {
            //�������� ����� ������ �� �� ��������
            l[0]*=l[0];
            l[1]*=l[1];
            l[2]*=l[2];
            if (l[2]+l[1]>l[0]) //  cos>0
                printf("����������� �������������");
            else
                if (l[2]+l[1]==l[0]) //  cos=0
                    printf("����������� �������������");
                else                                    //  cos<0
                    printf("����������� ������������");
        }

    return 0;
}
