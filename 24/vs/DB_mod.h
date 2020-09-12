#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

typedef struct
{
	int k;
	double val;
	char *str;
}db_cell;

typedef struct
{
	db_cell **data;
	int used;
	int aval;
}db;

//���������� ������� �� �����
db *scan_table(const char *path);

//���������� � �������� ������ �������
int add_cell(db *arr, db_cell *x);

void del_cell(db *arr, int n);

//����� ������� � �������
void table_cprint(db *arr);

//����� ������� � ����
void table_fprint(db *arr, const char *path);

//������� ���������� �� n-��� �������
void db_sort(db *arr, int n, int l, int r);

//������ ������� ����� �� ��������
void db_back(db *arr);

//�������� �������
void db_free(db *base);

int str_comp(char*a, char*b);