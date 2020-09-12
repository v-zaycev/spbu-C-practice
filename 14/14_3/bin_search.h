#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void *bin_search(void *a, int(*comp)(void*, void*), size_t tp_sz, size_t arr_sz, void* var);
// �������� ����� ��������� �������� var � ������� a, ��������� �� arr_sz ���������, ������� ������ tp_sz ����

int int_comp(int *a, int *b); // ��������� ������������� ���������

int double_comp(double *a, double *b); // ��������� ������������ ���������

int bin_place(void *a, int(*comp)(void*, void*), size_t tp_sz, size_t arr_sz, void* var);
// ����� ������� � ������������ �������, � ������� ������ ���� ��������� �������� �������



