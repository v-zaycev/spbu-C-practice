#define _CRT_SECURE_NO_WARNINGS
#include "in_out.h"
#include "bin_search.h"
#include <locale.h>

int main()
{
	setlocale(LC_CTYPE, "RUS");
	int sz,k,i,tp;
	double *a, x;
	printf("������� ����� ��������� �������\n");
	scanf("%i", &sz);
	a = malloc(sz * sizeof(double));
	if (!a)
	{
		printf("������ ��������� ������");
		return 0;
	}
	double_scan(a, sz);
	printf("������� ����� ����������� ���������\n");
	scanf("%i", &k);
	for (i = 0; i < k; i++)
	{
		printf("������� ����������� ������� � ��� ������\n  1 ��� ������ ��� � �������\n 2 ��� ������ ��� ��������� �����\n");
		scanf("%lf %i", &x,&tp);
		switch (tp)
		{
		case 1:
		{
			printf("%p\n", bin_search(a, &double_comp, sizeof(double), sz, &x)); 
			break; 
	    }
		case 2: 
		{
			printf("%i\n", bin_place(a, &double_comp, sizeof(double), sz, &x)); 
			break; 
		}
		default: {printf("������ �����\n"); i--; break;}
		};
	}
	system("pause");

	return 0;
}