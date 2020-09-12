#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct cell cell;

// ������ ������, ��������� �� ������ ����� � ���������� �� �������� ������ 
struct cell
{
	int data;
	cell *prev, *next;
};

// ��������� ������, ������� ����� ����������� ����������� 
typedef cell* dclist;

// ������ ���������� �������� � ������ 
void to_next(dclist *list);

// ������ ����������� �������� � ������ 
void to_prev(dclist *list);

// ����� ������ 
void print_list(const dclist list);

// �������� �������� ��������
void del_current(dclist *list);

// ���������� �������� ����� ������� 
int add_prev(dclist *list,int a);

// ���������� �������� ����� ������� 
int add_next(dclist *list, int a);

//�������� ������ � list � copy
int copy_list(const dclist list, dclist *copy);