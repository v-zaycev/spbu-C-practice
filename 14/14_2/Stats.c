#include "Stats.h"

double math_exp(const double *x, size_t sz)
{
	double sum = 0;
	const double *i = x;
	for (; i < x + sz; i++)
		sum += *i;

	return sum / (double)sz;
}

double stand_dev(const double *x, size_t sz, double ex)
{
	double sum = 0;
	const double *i = x;

	for (; i < x + sz; i++)
	{
		sum += pow(*i - ex, 2);
	}
	return sqrt(1 / ((double)sz - 1)*sum);
}

void print_miss(const double *x, size_t sz, double sg,double ex)
{
	const double *i=x;
	
	for (; i < x + sz; i++)
	{
		if (fabs(*i - ex) > sg)
			printf("%i ", 1 + (i - x));
	}
	printf("\n");
	return;
}