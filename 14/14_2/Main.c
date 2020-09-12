#define _CRT_SECURE_NO_WARNINGS
#include "Stats.h"
#include "in_out.h"

int main()
{
	setlocale(LC_CTYPE, "RUS");
	int sz;
	double *x,ex,sg;
	printf("Введите число элементов массива\n");
	scanf("%i", &sz);
	x = malloc(sz * sizeof(double));
	if (!x)
	{
		printf("Ошибка выделения памяти");
		return 0;
	}
	double_scan(x, sz);
	ex = math_exp(x, sz);
	sg = stand_dev(x, sz, ex);
	printf("%lf %lf\n", ex, sg);	
	print_miss(x, sz, sg, ex);
	free(x);
	system("pause");
	return 0;
}