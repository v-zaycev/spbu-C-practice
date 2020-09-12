/*��������� ������������ ��������� �������� ��������� ������� f(x)=(x^2-p^2)/(x-p)-p
 *��� �������� ��������� p �� �������� ���������� � �������� ��������
 *����� - ������ �. �.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE,"Russian");
    double a,b,h,p;
    printf("������� ������� �������, ��� � �����:");
    scanf("%lf %lf %lf %lf",&a,&b,&h,&p);
    printf("������� �������� �� ���������� [%lf;%lf] ��� ������� f(x)=(x^2-p^2)/(x-p)-p\n",a,b);
    printf("       x               f(x)\n");
    for (;a<=b;a+=h)
    {
        printf("%e     %e\n",a,(a*a-p*p)/(a-p)-p);
    }
    return 0;
}
