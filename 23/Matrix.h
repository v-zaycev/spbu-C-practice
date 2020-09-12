#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>


typedef struct 
{
	size_t h, w;
	double *data;
}matrix;

//функция, инициализирующая матрицу
matrix *mx_init(size_t h, size_t w);

//функция, создающая нулевую матрицу
matrix *mx_zero_init(size_t h, size_t w);

//функция, создающая единичную матрицу порядка n 
matrix *mx_e_init(size_t n);

//функция консольного заполнения матрицы mx
void mx_scan(matrix *mx);

//функция, выводящая матрицу mx
void mx_print(const matrix *mx);

//функция, создающая копию матрицы src
matrix *mx_copy(const matrix *src);

//функция, освобождающая память матрицы
void mx_free(matrix *mx);

//функция, производящая суммирование матриц a и b в новую матрицу
matrix *mx_sum_out(const matrix *a, const matrix *b);

//функция, производящая суммирование матриц a и b в матрицу a
matrix *mx_sum_in(matrix *a, const matrix *b);

//функция доступа к ячейке a_ij, с возможностью изменения
double *mx_get(matrix *mx, size_t i, size_t j);

//функция доступа к ячейке a_ij, без возможности изменения
const double *mx_cget(const matrix *mx, size_t i, size_t j);

//функция, домножающая матрицу mx на константу x
void mx_const_mult_in(matrix *mx, double x);

//функция, возвращающая новую матрицу, равную домножению матрицы mx на константу x 
matrix *mx_const_mult_out(const matrix *mx, double x);

//функция, возвращающая матрицу, равную произведению матрицы a на b
matrix *mx_mult(const matrix *a, const matrix *b);

//функция, транспонирующая заданную квадратную матрицу x 
void square_transpose(matrix *x);

//функция, возвращающая транспонированную матрицу для любой матрицы
matrix *transpose(matrix *x);

//функция, меняющая местами строки a и b матрицы x
void mx_str_swap(matrix *x, size_t a, size_t b);

//функция, прибавляющая к строке a, матрицы x строку b с коэффициентом c
void mx_str_sum(matrix *x, size_t a, size_t b,double c);

//функция, домножающая строку a матрицы x на константу c
void mx_str_mult(matrix *x, size_t a, double c);

//функция, вычисляющая определитель квадратной матрицы
double det(const matrix *x);

//функция, возвращающая обратную к x матрицу
matrix *mx_inverse(matrix *x);

//функция, вычисляющая норму матрицы x, равную максимуму из абсолютных значений элементов матрицы
double norm_max_item(const matrix *x);

//функция, вычисляющая норму матрицы x, равную максимуму по суммам абсолютных значений по строкам
double norm_max_str_sum(const matrix *x);

//функция, вычисляющая норму матрицы x, равную максимуму по суммам абсолютных значений по столбцам
double norm_max_col_sum(const matrix *x);

//функция, вычисляющая норму матрицы x, равную квадратному корню из суммы квадратов элементов матрицы
double norm_square_sum(const matrix *x);

//функция вычисляющая матричный ряд квадратной матрицы x, до тех пор, пока норма последнего слагаемого больше eps
matrix *exp_M(const matrix *x, double eps);

//функция, в которую передаётся квадратная матрица коэффициентов a и матрица свободных членов b, а возвращается вектор значений
//если система не является определённой, возвращается NULL
matrix *LES_solution(const matrix *a, const matrix*b);

//функция, в которую передаётся квадратная матрица коэффициентов a,матрица свободных членов b и матрица решения x
// функция возвращает 1, если решение удовлетворяет погрешности eps и 0 в противном случае
int solution_check(matrix*a, matrix *b, matrix *x, double eps);