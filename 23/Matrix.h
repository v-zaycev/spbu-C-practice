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

//�������, ���������������� �������
matrix *mx_init(size_t h, size_t w);

//�������, ��������� ������� �������
matrix *mx_zero_init(size_t h, size_t w);

//�������, ��������� ��������� ������� ������� n 
matrix *mx_e_init(size_t n);

//������� ����������� ���������� ������� mx
void mx_scan(matrix *mx);

//�������, ��������� ������� mx
void mx_print(const matrix *mx);

//�������, ��������� ����� ������� src
matrix *mx_copy(const matrix *src);

//�������, ������������� ������ �������
void mx_free(matrix *mx);

//�������, ������������ ������������ ������ a � b � ����� �������
matrix *mx_sum_out(const matrix *a, const matrix *b);

//�������, ������������ ������������ ������ a � b � ������� a
matrix *mx_sum_in(matrix *a, const matrix *b);

//������� ������� � ������ a_ij, � ������������ ���������
double *mx_get(matrix *mx, size_t i, size_t j);

//������� ������� � ������ a_ij, ��� ����������� ���������
const double *mx_cget(const matrix *mx, size_t i, size_t j);

//�������, ����������� ������� mx �� ��������� x
void mx_const_mult_in(matrix *mx, double x);

//�������, ������������ ����� �������, ������ ���������� ������� mx �� ��������� x 
matrix *mx_const_mult_out(const matrix *mx, double x);

//�������, ������������ �������, ������ ������������ ������� a �� b
matrix *mx_mult(const matrix *a, const matrix *b);

//�������, ��������������� �������� ���������� ������� x 
void square_transpose(matrix *x);

//�������, ������������ ����������������� ������� ��� ����� �������
matrix *transpose(matrix *x);

//�������, �������� ������� ������ a � b ������� x
void mx_str_swap(matrix *x, size_t a, size_t b);

//�������, ������������ � ������ a, ������� x ������ b � ������������� c
void mx_str_sum(matrix *x, size_t a, size_t b,double c);

//�������, ����������� ������ a ������� x �� ��������� c
void mx_str_mult(matrix *x, size_t a, double c);

//�������, ����������� ������������ ���������� �������
double det(const matrix *x);

//�������, ������������ �������� � x �������
matrix *mx_inverse(matrix *x);

//�������, ����������� ����� ������� x, ������ ��������� �� ���������� �������� ��������� �������
double norm_max_item(const matrix *x);

//�������, ����������� ����� ������� x, ������ ��������� �� ������ ���������� �������� �� �������
double norm_max_str_sum(const matrix *x);

//�������, ����������� ����� ������� x, ������ ��������� �� ������ ���������� �������� �� ��������
double norm_max_col_sum(const matrix *x);

//�������, ����������� ����� ������� x, ������ ����������� ����� �� ����� ��������� ��������� �������
double norm_square_sum(const matrix *x);

//������� ����������� ��������� ��� ���������� ������� x, �� ��� ���, ���� ����� ���������� ���������� ������ eps
matrix *exp_M(const matrix *x, double eps);

//�������, � ������� ��������� ���������� ������� ������������� a � ������� ��������� ������ b, � ������������ ������ ��������
//���� ������� �� �������� �����������, ������������ NULL
matrix *LES_solution(const matrix *a, const matrix*b);

//�������, � ������� ��������� ���������� ������� ������������� a,������� ��������� ������ b � ������� ������� x
// ������� ���������� 1, ���� ������� ������������� ����������� eps � 0 � ��������� ������
int solution_check(matrix*a, matrix *b, matrix *x, double eps);