#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
	setlocale(LC_CTYPE, "RUS");
	double x = 0;
	int err = 0;
	char *s = malloc(200);
	printf("������ ������\n/end - ��������� ����������\n+,-,*,/,^ - ��������� �������� ��������\nopposite, inverse, sin, cos, tg, ctg - ��������� ������� ��������\n\n");
	while (1)
	{
		fflush(stdin);
		gets(s);
		if (!strcmp(s, "/end"))
			break;
		else
		{
			x = calc_expr(s, &err);
			if (err == 0)
				printf("Result: %lf\n", x);
			else
			{
				error_type(err);
			}
			err = 0;
		}
	}
	return 0;
}
