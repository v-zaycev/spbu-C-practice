#include "Matrix.h"
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main()
{
	setlocale(LC_CTYPE, "RUS");
	int x=3;
	double eps = 10;
	size_t h, w;
	printf("������� 1 ��� ������ ���������� ����\n������� 2 ��� ������� ������� �������� ���������\n������� 0 ��� ������ �� ���������\n");

	while (x != 0)
	{
		printf("������� ������ ");
		scanf("%i", &x);
		switch (x)
		{
		case 1:
		{
			matrix *a,*b;
			printf("������� ���������� ����� � �������� ������� ");
			scanf("%i %i", &h,&w);
			a = mx_init(h,w);
			printf("������� �������\n");
			mx_scan(a);
			printf("������� ��������, ��� �������� ����� ������� ����� ���������� ����� ���������� ������������\n");
			scanf("%lf", &eps);
			b=exp_M(a, eps);
			if (b)
			{
				printf("����� ���������� ���� ����� ���\n");
				mx_print(b);
			}
			else
				printf("��������� �������� �� �������\n");

			mx_free(a);
			mx_free(b);

			break;
		}
		case 2:
		{
			matrix *a, *b,*c;
			printf("������� ���������� ����� � �������� ������� ������������� ");
			scanf("%i %i", &h, &w);
			a = mx_init(h, w);
			printf("������� �������\n");
			mx_scan(a);
			printf("������� ���������� ����� � �������� ������� ��������� ������ ");
			scanf("%i %i", &h, &w);
			b = mx_init(h, w);
			printf("������� �������\n");
			mx_scan(b);
			printf("������� ���������� ����������� �������\n");
			scanf("%lf", &eps);
			c = LES_solution(a,b);
			if (c)
			{
				printf("������� ����� ���\n");
				mx_print(c);
				if (solution_check(a, b, c, eps))
					printf("������� ������������� ��������\n");
				else
					printf("������� �� ������������� ��������\n");

			}
			else
				printf("��������� ������� �� �������\n");
			mx_free(a);
			mx_free(b);
			mx_free(c);

			break;
		}
		case 0:
		{
			return 0;
		}
		default: {printf("������ �����\n"); break;}
		};
	}
	return 0;
}
