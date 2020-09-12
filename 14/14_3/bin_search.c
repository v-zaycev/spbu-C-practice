#include "bin_search.h"

void *bin_search(void *a, int(*comp)(void*, void*), size_t tp_sz, size_t arr_sz,void* var)
{
	char *l = (char*)a-tp_sz, *r = (char*)a+ tp_sz* arr_sz,*m=NULL;

	while (r - tp_sz != l)
	{
		m = l + tp_sz * (((r - l) / tp_sz) / 2);
		switch (comp(m , var))
		{
		case -1: {r = m; break; }

		case 1: {l = m;	break; }

		case 0: {return m; }
		};
	}
	return NULL;
}

int int_comp(int *a, int *b)
{
	if (*a > *b)
		return -1;
	else
	{
		if (*a < *b)
			return 1;
		else
			return 0;
	}
}

int double_comp(double *a, double *b)
{
	if (*a > *b)
		return -1;
	else
	{
		if (*a < *b)
			return 1;
		else
			return 0;
	}
}

int bin_place(void *a, int(*comp)(void*, void*), size_t tp_sz, size_t arr_sz, void* var)
{
	char *l = (char*)a - tp_sz, *r = (char*)a + tp_sz * arr_sz, *m = NULL;
	int fl = 0;

	while (r - tp_sz != l&&!fl)
	{
		m = l + tp_sz * (((r - l) / tp_sz) / 2);
		switch (comp(m, var))
		{
		case -1: {r = m; break; }

		case 1: {l = m;	break; }

		case 0: {l = m; fl = 1; break; }
		};
	}
	
	if (l < (char*)a)
		return 0;
	else
	{
		if (l == (char*)a + tp_sz * (arr_sz - 1))
			return (int)arr_sz;
		else
		{
			int i = 1;
			while (comp(l + i * tp_sz, var) == 0)
			{
				i++;
			}
			return (int)((l - (char*)a) / tp_sz + i);
		}
	}
}
