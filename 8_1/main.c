/*��������� ����������� �������� ������ ����� � �������� ������� ���������
 *����� - ������ �. �.
 */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


/*������� sum ������� ����� s ���� ����� a � ������� ��������� p */
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

/*������� DR ������� �������� ������ a � ������� ��������� p */
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
   int a,p; // a - ��������������� �����,p - ��������� ������� ���������
   printf ("������� ����� � ��������� ������� ���������: ");
   scanf("%i %i",&a,&p);
   printf ("�������� ������ ����� %i",DR(a,p));
    return 0;
}
