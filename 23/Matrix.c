#include "Matrix.h"

matrix *mx_init(size_t h, size_t w)
{
	matrix *mx = malloc(sizeof(matrix));
	if (!mx)
		return NULL;
	mx->data = malloc(sizeof(double)*h*w);
	if (!mx->data)
		return NULL;
	mx->h = h;
	mx->w = w;

	return	 mx;
}

matrix *mx_zero_init(size_t h, size_t w)
{
	matrix *mx = mx_init(h, w);
	if (!mx)
		return NULL;
	mx->h = h;
	mx->w = w;
	double *i = mx->data;
	while (i < mx->data + mx->h*mx->w)
	{
		*i = 0;
		i++;
	}
	return	 mx;
}

matrix *mx_e_init(size_t n)
{
	matrix *x = mx_zero_init(n, n);
	if (!x)
		return NULL;
	size_t i;

	for (i = 0; i < n; i++)
	{
		*(x->data + n * i + i) = 1;
	}

	return x;
}

void mx_free(matrix *mx)
{
	if (!mx)
		return;
	if (mx->data)
		free(mx->data);
	free(mx);
	mx = NULL;
	return;
}

void mx_scan(matrix *mx)
{
	if (!mx)
		return;
	double *x=mx->data;

	while (x != mx->data + mx->h*mx->w)
	{
		scanf("%lf", x);
		x++;
	}
	return;
}

void mx_print(const matrix *mx)
{
	if (!mx)
		return;

	double *x = mx->data;

	while (x != mx->data + mx->h*mx->w)
	{
		printf("%lg ", *x);
		x++;
		if ((x - mx->data) % mx->w == 0)
			printf("\n");
	}
	return;
}

matrix *mx_sum_out(const matrix *a, const matrix *b)
{
	if (!a||!b||a->h != b->h || a->w != b->w)
		return NULL;

	matrix *x = mx_init(a->h, a->w);
	if (!x)
		return NULL;
	double *i = x->data, *j = a->data, *k = b->data;

	while (i != x->data + x->h*x->w)
	{
		*i = *j + *k;
		i++; j++; k++;
	}
	return x;
}

matrix *mx_sum_in(matrix *a, const matrix *b)
{
	if (!a || !b || a->h != b->h || a->w != b->w)
		return NULL;

	double *j = a->data, *k = b->data;

	while (j != a->data + a->h*a->w)
	{
		*j +=*k;
		j++; k++;
	}
	return a;
}

matrix  *mx_copy (const matrix *src)
{
	if (!src)
		return 0;
	matrix *dest = mx_init(src->h, src->w);
	if (!dest)
		return NULL;
	if (!dest->data)
		return NULL;
	memcpy(dest->data, src->data, src->h*src->w * sizeof(double));
	return dest;
}

double *mx_get(matrix *mx, size_t i, size_t j)
{
	if (!mx)
		return 0;
	return mx->data + mx->w*i + j;
}

const double *mx_cget(const matrix *mx, size_t i, size_t j)
{
	if (!mx)
		return 0;
	return (mx->data + mx->w*i + j);
}

void mx_const_mult_in(matrix *mx, double x)
{
	if (!mx)
		return;
	double *i = mx->data;
	for (;i<mx->data+mx->w*mx->h;i++)
		*i *= x;
	return;
}

matrix *mx_const_mult_out(const matrix *mx, double x)
{
	if (!mx)
		return NULL;
	matrix *out = mx_copy(mx);
	if (!out)
		return NULL;
	double *i;
	for (i=out->data; i < out->data + out->w*out->h; i++)
		*i *= x;
	return out;
}

matrix *mx_mult(const matrix *a,const matrix *b)
{
	if (!a||!b||a->w != b->h)
		return NULL;
	matrix *x = mx_zero_init(a->h, b->w);
	if (!x)
		return NULL;

	size_t ii,jj,kk;

	for (ii = 0; ii < x->h; ii++)
		for (jj = 0; jj < x->w; jj++)
			for (kk = 0; kk < a->w; kk++)
				*(x->data + x->w*ii + jj) += (*(a->data + a->w*ii + kk))*(*(b->data + b->w*kk + jj));

	return x;
}

void square_transpose(matrix *x)
{
	if (!x || x->h != x->w)
		return;
	double a;
	size_t i, j;
	for (i=0;i<x->h;i++)
		for (j = i + 1; j < x->w; j++)
		{
			a = *(x->data + x->w*i + j);
			*(x->data + x->w*i + j) = *(x->data + x->w*j + i);
			*(x->data + x->w*j + i) = a;
		}
	return;
}

matrix *transpose(matrix *x)
{
	if (!x)
		return NULL;
	matrix *xt=mx_init(x->w,x->h);
	if (!xt)
		return NULL;
	size_t i, j;

	for (i = 0; i < x->h; i++)
		for (j = 0; j < x->w; j++)
			*(xt->data + xt->w*j + i) = *(x->data + x->w*i + j);

	return xt;
}

void mx_str_swap(matrix *x, size_t a, size_t b)
{
	if (!x || a >= x->h || b >= x->h||a==b)
		return;
	double d;
	size_t i;
	for (i = 0; i < x->w; i++)
	{
		d = *(x->data + x->w*a + i);
		*(x->data + x->w*a + i) = *(x->data + x->w*b + i);
		*(x->data + x->w*b + i) = d;
	}
	return;
}

void mx_str_sum(matrix *x, size_t a, size_t b, double c)
{
	if (!x || a >= x->h || b >= x->h || c==0)
		return;
	size_t i;
	for (i = 0; i < x->w; i++)
		*(x->data + x->w*a + i) += c*(*(x->data + x->w*b + i));
	return;
}

void mx_str_mult(matrix *x, size_t a, double c)
{
	if (!x || a >= x->h)
		return;

	size_t i;

	for (i = 0; i < x->w; i++)
		(*(x->data + x->w*a + i)) *= c;

	return;
}

double det(const matrix *x)
{
	if (!x || x->h != x->w)
		return 0;
	matrix *xc = mx_copy(x);
	if (!xc)
		return 0;
	size_t i,j;
	double amount = 1;
	for (i = 0; i < xc->h; i++)
	{
		if (*(xc->data + xc->w*i + i) == 0)
			for (j = i + 1; j < x->h; j++)
				if (*(xc->data + xc->w*j + i) != 0)
				{
					mx_str_swap(xc, i, j);
					break;
				}
		for (j = i + 1; j < xc->h; j++)
			mx_str_sum(xc, j, i, -(*(xc->data + xc->h*j + i)) / (*(xc->data + xc->h*i + i)));
	}
	for (i = 0; i < xc->h; i++)
		amount *= (*(xc->data + xc->h*i + i));
	mx_free(xc);
	return amount;
}

matrix *mx_inverse(matrix *x)
{
	if (!x || x->h != x->w || det(x) == 0)
		return NULL;

	matrix *y = mx_e_init(x->h);
	matrix *xc = mx_copy(x);
	if (!y || !xc)
		return NULL;
	size_t i, j;
	for (i = 0; i < xc->h; i++)
	{
		if (*(xc->data + xc->w*i + i) == 0)
			for (j = i + 1; j < xc->h; j++)
				if (*(xc->data + xc->w*j + i) != 0)
				{
					mx_str_swap(xc, i, j);
					mx_str_swap(y, i, j);
					break;
				}
		for (j = 0; j < xc->h; j++)
			if (j != i)
			{
				mx_str_sum(y, j, i, -(*(xc->data + xc->h*j + i)) / (*(xc->data + xc->h*i + i)));
				mx_str_sum(xc, j, i, -(*(xc->data + xc->h*j + i)) / (*(xc->data + xc->h*i + i)));
			}
	}
	for (i = 0; i < xc->w; i++)
	{
		mx_str_mult(y, i, 1 / (*(xc->data + xc->w*i + i)));
		mx_str_mult(xc, i, 1 / (*(xc->data + xc->w*i + i)));
	}

	mx_free(xc);
	return y;
}

double norm_max_item(const matrix *x)
{
	if (!x)
		return -1;
	double n = 0;
	double *i;
	for (i = x->data; i < x->data + x->w*x->h; i++)
		if (fabs(*i) > n)
			n = fabs(*i);

	return n;
}

double norm_max_str_sum(const matrix *x)
{
	if (!x)
		return -1;
	double *mx = malloc(sizeof(double)*x->h),*j,*i,n=0;
	if (!mx)
		return -1;
	for (j = mx; j < mx + x->h; j++)
		*j = 0;

	for (j = mx-1, i = x->data; i < x->data + x->w*x->h; i++)
	{
		if ((i - x->data) % x->w == 0)
			j++;
		*j += fabs(*i);
	}
	for (j = mx; j < mx + x->h; j++)
		if (*j > n)
			n = (*j);
	return n;
}

double norm_max_col_sum(const matrix *x)
{
	if (!x)
		return -1;
	double *mx = malloc(sizeof(double)*x->w), *j, n = 0;
	if (!mx)
		return -1;
	for (j = mx; j < mx + x->w; j++)
		*j = 0;

	for (j = x->data; j < x->data + x->w*x->h; j++)
		mx[(j - x->data) % x->w] += fabs(*j);

	for (j = mx; j < mx + x->w; j++)
		if (*j > n)
			n = (*j);
	return n;
}

double norm_square_sum(const matrix *x)
{
	if (!x)
		return -1;
	double n = 0,*i;

	for (i = x->data; i < x->data + x->w*x->h; i++)
		n += (*i)*(*i);

	return sqrt(n);
}

matrix *exp_M(const matrix *x,double eps)
{
	if (!x || x->h != x->w)
		return NULL;
	matrix *exp=mx_e_init(x->h),*iter = mx_e_init(x->h),*bin;
	if (!exp||!iter)
		return NULL;
	double fact = 1,n=INFINITY,i=1;
	n = norm_square_sum(exp) / fact;

	while (n > eps)
	{
		bin = iter;
		iter = mx_mult(iter, x);
		mx_free(bin);
		fact *= i;
		i++;
		n = norm_square_sum(exp)/fact;
		bin = mx_const_mult_out(iter, 1 / fact);
		mx_sum_in(exp,bin);
		mx_free(bin);
	}
	mx_free(iter);
	return exp;
}

matrix *LES_solution(const matrix *a,const matrix*b)
{
	if (!a || !b || a->h != a->w||det(a)==0||a->h!=b->h||b->w!=1)
		return NULL;

	matrix *ab = mx_init(a->h, a->h + 1),*res=mx_init(ab->h,1);
	if (!ab||!res)
		return NULL;
	size_t i,j;
	for (i = 0; i < ab->h; i++)
		memcpy(ab->data + i * ab->w, a->data + i * a->w, a->w*sizeof(double));
	for (i = 1; i < ab->h + 1; i++)
		*(ab->data + i * ab->w - 1) = *(b->data + i - 1);


	for (i = 0; i < ab->h; i++)
	{
		if (*(ab->data + ab->w*i + i) == 0)
			for (j = i + 1; j < ab->h; j++)
				if (*(ab->data + ab->w*j + i) != 0)
				{
					mx_str_swap(ab, i, j);
					break;
				}
		for (j = 0; j < ab->h; j++)
			if (j != i)
				mx_str_sum(ab, j, i, -(*(ab->data + ab->w*j + i)) / (*(ab->data + ab->w*i + i)));
	}
	for (i = 0; i < ab->h; i++)
	{
		mx_str_mult(ab, i, 1 / (*(ab->data + ab->w*i + i)));
		res->data[i] = *(ab->data + ab->w*(i + 1) - 1);
	}
	mx_free(ab);
	return res;
}

int solution_check(matrix*a, matrix *b, matrix *x,double eps)
{
	if (!a || !b || !x)
		return 0;
	matrix *mb = mx_const_mult_out(b, -1), *mn = mx_sum_in(mx_mult(a, x), mb);
	if (!mb || !mn)
		return 0;
	double n = norm_square_sum(mn);
	mx_free(mb);
	mx_free(mn);
	if (n < eps)
		return 1;
	else
		return 0;
}
