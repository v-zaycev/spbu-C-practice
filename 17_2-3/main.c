#define _CRT_SECURE_NO_WARNINGS
#include "substring.h"

int main()
{
	setlocale(LC_CTYPE, "Russian");
	char *str = malloc(100),*s = malloc(100);
	gets(str);
	int n, l;
	while (1)
	{
		printf("Введите номер первого элемента подстроки и её длину ");
		scanf("%i %i", &n, &l);
		substr(str, s, n, l);
		printf("/%s/\n", s);
        free(s);
        s = malloc(100);
	}
	free(str);
	free(s);
	system("pause");
	return 0;
}
