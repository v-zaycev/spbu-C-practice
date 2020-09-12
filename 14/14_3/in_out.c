#define _CRT_SECURE_NO_WARNINGS
#include "in_out.h"

void int_scan(int *a,size_t sz)
{
	int *i,*m;

	for (i=a,m=a+sz; i < m; ++i)
	{
		scanf("%i", i);
	}
	return;
}

void double_scan(double *a, size_t sz)
{
	double *i, *m;

	for (i = a, m = a + sz; i < m; ++i)
	{
		scanf("%lf", i);
	}
	return;
}

void int_print(const int *a,size_t sz)
{
	int *i = a, *m = a + sz;

	for (; i < m; ++i)
	{
		printf("%i ", *i);
	}
	printf("\n");
	return;
}

void double_print(const double *a, size_t sz)
{
	double *i = a, *m = a + sz;

	for (; i < m; ++i)
	{
		printf("%lf ", *i);
	}
	printf("\n");
	return;
}

void del_even(int *a, size_t *sz)
{
	int *mod = calloc(*sz * sizeof(int),*sz * sizeof(int));
	int *i = a, *m = a + *sz,*j=mod;
	int k = 0;

	for (; i < m; i++, j++)
	{
		if (*i % 2 == 0)
			k++;
		else
			*j = k;
	}
	i = a;
	j = mod;
	for (; i < m; i++, j++)
	{
		*(i - *j) = *(i);
	}
	realloc(a, (*sz - k) * sizeof(int));
	*sz -= k;
	return;
}

void del_odd(int *a, size_t *sz)
{
	int *mod = calloc(*sz * sizeof(int), *sz * sizeof(int));
	int *i = a, *m = a + *sz, *j = mod;
	int k = 0;

	for (; i < m; i++, j++)
	{
		if (*i % 2 == 1)
			k++;
		else
			*j = k;
	}
	i = a;
	j = mod;
	for (; i < m; i++, j++)
	{
		*(i - *j) = *(i);
	}
	realloc(a, (*sz - k) * sizeof(int));
	*sz -= k;
	return;
}

void del_odd_t(int *a, size_t *sz)
{
	int *i, *j;
	int k=0;
	for (i = a + *sz-1; i >=a; i--)
	{
		if (*i % 2 == 1)
		{
			k++;
			for (j = i; j < a + *sz -k; j++)
				*j = *(j + 1);

		}
	}
	*sz -= k;
	realloc(a, *sz*sizeof(int));
	return;
}

void del_even_t(int *a, size_t *sz)
{
	int *i, *j;
	int k = 0;
	for (i = a + *sz - 1; i >= a; i--)
	{
		if (*i % 2 == 0)
		{
			k++;
			for (j = i; j < a + *sz - k; j++)
				*j = *(j + 1);

		}
	}
	*sz -= k;
	realloc(a, *sz * sizeof(int));
	return;
}