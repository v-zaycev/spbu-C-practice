#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>


void int_scan (int *a,size_t sz); //���� ������� �������� �����

void int_print (const int *a, size_t sz); //����� ������� �������� �����

void del_odd(int *a, size_t *sz); // �������� �������� ��������� (�� ���������� �� ������)

void del_even(int *a, size_t *sz); // �������� ������ ��������� (�� ���������� �� ������)

void del_odd_t(int *a, size_t *sz); // �������� �������� ��������� (�� ���������� �� �������)

void del_even_t(int *a, size_t *sz); // �������� ������ ��������� (�� ���������� �� �������)