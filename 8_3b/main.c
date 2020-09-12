/*��������� �������� ����� � ��������� ��������� � ��������
 *����� - ������ �. �.
 */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*������� draw ������ ����� � ������ m, ������� n � �������� d*/

void draw (int m, int n, int d)
{
    int i=0,j=0;
    for (;i<n;i++)
    {
        if (i<d||i>=n-d)  // ��������� �������������� ������
            for (j=0;j<m;j++)
                printf("*");
        else   // ��������� ������� ������
            for (j=0;j<m;j++)
                if (j<d||j>=m-d)
                    printf("*");
                else
                    printf(" ");
        printf("\n");
    }
}

int main()
{
    setlocale (LC_CTYPE,"Russian");
    int m,n,d; // m - ����� �����, n - ������ �����, d - ������� �����
    printf("������� ������� ����� � � �������: ");
    scanf("%i %i %i", &m, &n, &d);
    draw (m,n,d);
    return 0;
}
