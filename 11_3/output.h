#ifndef OUTPUT_H_INCLUDED
#define OUTPUT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>


void reverse_nmb (const int s,char *str);//�������, ��������� ����� ����� � p-����� ������� ������� � �������� �������

void direct_nmb (const int s,char *str); //�������, ��������� ����� ����� � p-����� ������� ������� � ������ �������

int nmb_lenth_p (int a,int p); // �������, ������������ ����� ����� � p-����� ������� ���������

void str_build (int n,int a, int p,char *str); //�������, �������� ������������������ ���� ����� � p-����� ������� ���������
#endif // OUTPUT_H_INCLUDED
