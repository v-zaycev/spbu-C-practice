#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<math.h>



typedef struct stack_slot
{
	double data;
	struct stack_slot *next;

}stack_slot;

typedef stack_slot* stack;

//���������� �������� � ����
int add_slot(stack* st,double x);

// �������� �������� �������� �����
void del_slot(stack* x);

// ��������� ������ ���������
// ���������� �������� ���� ��� ���������/�������, ��������� 0 � �������� ������ � ������� ��� ������
double calc_expr(char *str, int *err);

// ������������ ����� +
void free_stack(stack x);

// ����� ������
void error_type(const int x);
