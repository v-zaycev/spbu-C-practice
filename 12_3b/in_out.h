#ifndef IN_OUT_H_INCLUDED
#define IN_OUT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

void int_scan (int *a_nmb,int s); // ���������� �������������� ������� ������� s ����������, ��������� � ����������

void int_print (int *a_nmb,int s); // ����� �������������� ������� ������� s

void double_scan (double *a_nmb,int s);  // ���������� ������� ������������ ����� ������� s ����������, ��������� � ����������

void double_print (double *a_nmb,int s); // ����� ������� ������������ ����� ������� s

#endif // IN_OUT_H_INCLUDED
