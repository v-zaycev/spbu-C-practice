#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double math_exp(const double *x, size_t sz); // вычисление матожидания 

double stand_dev(const double *x, size_t sz, double ex); // вычисление среднеквадратичного отклонения

void print_miss(const double *x, size_t sz, double sg, double ex); 
// вывод номеров точек, отклонения которых превышают среднее квадратичное