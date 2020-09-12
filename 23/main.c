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
	printf("Введите 1 для поиска матричного ряда\nВведите 2 для решения системы линейных уравнений\nВведите 0 для выхода из программы\n");

	while (x != 0)
	{
		printf("Введите запрос ");
		scanf("%i", &x);
		switch (x)
		{
		case 1:
		{
			matrix *a,*b;
			printf("Введите количество строк и столбцов матрицы ");
			scanf("%i %i", &h,&w);
			a = mx_init(h,w);
			printf("Введите матрицу\n");
			mx_scan(a);
			printf("Введите значение, при переходе через которое нормы очередного члена вычисление прекращается\n");
			scanf("%lf", &eps);
			b=exp_M(a, eps);
			if (b)
			{
				printf("Сумма матричного ряда имеет вид\n");
				mx_print(b);
			}
			else
				printf("Вычислить значение не удалось\n");

			mx_free(a);
			mx_free(b);

			break;
		}
		case 2:
		{
			matrix *a, *b,*c;
			printf("Введите количество строк и столбцов матрицы коэффициентов ");
			scanf("%i %i", &h, &w);
			a = mx_init(h, w);
			printf("Введите матрицу\n");
			mx_scan(a);
			printf("Введите количество строк и столбцов матрицы свободных членов ");
			scanf("%i %i", &h, &w);
			b = mx_init(h, w);
			printf("Введите матрицу\n");
			mx_scan(b);
			printf("Введите допустимую погрешность решения\n");
			scanf("%lf", &eps);
			c = LES_solution(a,b);
			if (c)
			{
				printf("Решение имеет вид\n");
				mx_print(c);
				if (solution_check(a, b, c, eps))
					printf("Решение удовлетворяет точности\n");
				else
					printf("Решение не удовлетворяет точности\n");

			}
			else
				printf("Вычислить решение не удалось\n");
			mx_free(a);
			mx_free(b);
			mx_free(c);

			break;
		}
		case 0:
		{
			return 0;
		}
		default: {printf("Ошибка ввода\n"); break;}
		};
	}
	return 0;
}
