/*��������� ������������ ��������� �������� ��������� ������� (� ������ ������ y=sin(x+x^2))
 *�� �������� ������� � �������� ��������
 *����� - ������ �. �.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main()
{
    setlocale(LC_CTYPE,"Russian");
    double a,b,h;
    printf("������� ������� ������� � ���:");
    scanf("%lf %lf %lf",&a,&b,&h);
    printf("������� �������� �� ���������� [%lf;%lf] ��� ������� y=sin(x+x^2)\n",a,b);
    printf("      x          y\n");
    for (;a<=b;a+=h)
    {
        printf("%10.5lf %10.5lf\n",a,sin(a+a*a));
    }
    return 0;
}
