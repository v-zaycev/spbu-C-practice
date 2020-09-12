#ifndef IN_OUT_H_INCLUDED
#define IN_OUT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

void int_scan (int *a_nmb,int s); // заполнение целочисленного массива размера s элементами, вводимыми с клавиатуры

void int_print (int *a_nmb,int s); // вывод целочисленного массива размера s

void double_scan (double *a_nmb,int s);  // заполнение массива вещественных чисел размера s элементами, вводимыми с клавиатуры

void double_print (double *a_nmb,int s); // вывод массива вещественных чисел размера s

#endif // IN_OUT_H_INCLUDED
