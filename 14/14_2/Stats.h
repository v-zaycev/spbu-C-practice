#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double math_exp(const double *x, size_t sz); // ���������� ����������� 

double stand_dev(const double *x, size_t sz, double ex); // ���������� ������������������� ����������

void print_miss(const double *x, size_t sz, double sg, double ex); 
// ����� ������� �����, ���������� ������� ��������� ������� ������������