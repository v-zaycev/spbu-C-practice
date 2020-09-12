#define pi 3.1415926
#define eps 1e-6
#include "functions.h"

double calc_expr(char *str, int *err)
{
	stack vars=NULL;
	char* word;
	word = strtok(str, " ");
	while (word != NULL)
	{
		if (!strcmp(word, "+"))
		{
			if (vars!=NULL&&vars->next!=NULL)
			{
				stack pos = vars->next;
				vars->next->data = vars->next->data + vars->data;
				free(vars);
				vars = pos;
			}
			else
			{
				*err = 1;
				free_stack(vars); return 0;
			}
		}
		else if (!strcmp(word, "-"))
		{
			if (vars != NULL && vars->next != NULL)
			{
				stack pos = vars->next;
				vars->next->data = vars->next->data - vars->data;
				free(vars);
				vars = pos;
			}
			else
			{
				*err = 1;
				free_stack(vars); return 0;
			}
		}
		else if (!strcmp(word, "*"))
		{
			if (vars != NULL && vars->next != NULL)
			{
				stack pos = vars->next;
				vars->next->data = vars->next->data * vars->data;
				free(vars);
				vars = pos;
			}
			else
			{
				*err = 1;
				free_stack(vars); return 0;

			}
		}
		else if (!strcmp(word, "/"))
		{
			if (vars != NULL && vars->next != NULL)
			{
				if (vars->data == 0)
				{
					*err = 2;
					free_stack(vars); return 0;

				}
				stack pos = vars->next;
				vars->next->data = vars->next->data / vars->data;
				free(vars);
				vars = pos;
			}
			else
			{
				*err = 1;
				free_stack(vars); return 0;

			}
		}
		else if (!strcmp(word, "^"))
		{
			if (vars != NULL && vars->next != NULL)
			{
				if (vars->next->data == 0 && vars->data < 0)
				{
					*err = 3;
					free_stack(vars); return 0;
				}
				vars->next->data = pow(vars->next->data, vars->data);
				stack pos = vars->next;
				free(vars);
				vars = pos;
			}
			else
			{
				*err = 1;
				free_stack(vars); return 0;
			}
		}
		else if (!strcmp(word, "opposite"))
		{
			if (vars != NULL)
			{
				vars->data*=-1;
			}
			else
			{
				*err = 1;
				free_stack(vars); return 0;
			}
		}
		else if (!strcmp(word, "inverse"))
		{
			if (vars != NULL)
			{
				if (vars->data == 0)
				{
					*err = 4;
					free_stack(vars); return 0;

				}
				vars->data = 1 / vars->data;
			}
			else
			{
				*err = 1;
				free_stack(vars); return 0;
			}
		}
		else if (!strcmp(word, "sin"))
		{
		if (vars != NULL)
			{
				vars->data = sin(vars->data);
			}
			else
			{
				*err = 1;
				free_stack(vars); return 0;
			}
		}
		else if (!strcmp(word, "cos"))
		{
			if (vars != NULL)
			{
				vars->data = cos(vars->data);
			}
			else
			{
				*err = 1;
				free_stack(vars); return 0;
			}
		}
		else if (!strcmp(word, "tg"))
		{
			if (vars != NULL)
			{
				if (fabs(round(vars->data / pi)*pi / 2 - vars->data) < eps)
				{
					*err = 5;
					free_stack(vars); return 0;
				}

				vars->data = tan(vars->data);
			}
			else
			{
				*err = 1;
				free_stack(vars); return 0;
			}
		}
		else if (!strcmp(word, "ctg"))
		{
			if (vars != NULL)
			{
				if (fabs(round(vars->data / pi)*pi - vars->data) < eps)
				{
					*err = 5;
					free_stack(vars); return 0;
				}
				vars->data = 1 / tan(vars->data);
			}
			else
			{
				*err = 1;
				free_stack(vars); return 0;
			}
		}
		else
		{
			int p = 0, e = 0, m = 0;
			char *i = word;
			while (*i != '\0')
			{
				if (*i == 'e' || *i == 'E')
					e++;
				else if (*i == '.')
					p++;
				else if (*i == '-')
					m++;
				else if (*i < '0' || *i > '9')
				{
					*err = 6;
					free_stack(vars); return 0;
				}
				i++;
			}

			if (p > 1 || e > 1 || m > 1)
			{
				*err = 6;
				free_stack(vars); return 0;
			}

			*err=add_slot(&vars, strtod(word, NULL));
			if (*err != 0)
			{
				free_stack(vars);
				return 0;
			}
		}

		word = strtok(NULL, " ");
	}

	if (vars->next!=NULL)
	{
		*err = 7;
		free_stack(vars); return 0;
	}
	double ret = vars->data;
	free_stack(vars);
	return ret;
}

void del_slot(stack *x)
{
	stack d=(*x)->next;
	free(x);
	*x = d;
	return;
}

int add_slot(stack *st,const double x)
{
	stack nxt = malloc(sizeof(stack_slot));
	if (nxt != NULL)
	{
		nxt->data = x;
		nxt->next = *st;
		*st = nxt;
		return 0;
	}
	else
		return 8;
}

void free_stack(stack x)
{
	stack i = x, j;
	while (i != NULL)
	{
		j = i->next;
		free(i);
		i = j;
	}
	return;
}

void error_type(const int x)
{
	switch (x)
	{
	case 1: { printf("Недостаточно переменных\n"); break; }
	case 2: { printf("Возникает деление на 0\n"); break; }
	case 3: { printf("Возведение 0 в отрицальную степень\n"); break; }
	case 4: { printf("Обращение 0 невозможно\n"); break; }
	case 5: { printf("Существует значение, стремящееся к бесконечности\n"); break; }
	case 6: { printf("Ошибка ввода\n"); break; }
	case 7: { printf("Недостаток операций\n"); break; }
	case 8: { printf("Не удалось выделить память\n"); break; }
	}
	return;
}
