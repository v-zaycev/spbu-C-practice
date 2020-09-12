#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void *bin_search(void *a, int(*comp)(void*, void*), size_t tp_sz, size_t arr_sz, void* var);
// бинарный поиск заданного элемента var в массиве a, состоящем из arr_sz элементов, имеющих размер tp_sz байт

int int_comp(int *a, int *b); // сравнение целочисленных элементов

int double_comp(double *a, double *b); // сравнение вещественных элементов

int bin_place(void *a, int(*comp)(void*, void*), size_t tp_sz, size_t arr_sz, void* var);
// поиск позиции в упорядченном массиве, в которую должен быть поставлен заданный элемент



