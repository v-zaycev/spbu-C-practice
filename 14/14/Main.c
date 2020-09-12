#define _CRT_SECURE_NO_WARNINGS
#include "in_out.h"

int main()
{
	setlocale(LC_CTYPE, "RUS");
	int *a=NULL,sz;
	printf("Введите размер массива\n");
	scanf("%i", &sz);
	a = malloc(sz * sizeof(int));
	if (!a)
	{
		printf("Ошибка выделения памяти");
		return 0;
	}
	int_scan(a,sz);
	del_even_t(a, &sz);
	a=realloc(a, sz * sizeof(int));
	int_print(a, sz);
	free(a);
	system("pause");
	return 0;
}