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

//добавление элемента в стек
int add_slot(stack* st,double x);

// удаление верхнего элемента стека
void del_slot(stack* x);

// обработка строки выражений
// возвращает значение если оно вычислимо/конечно, возращает 0 в обратном случае и выводит тип ошибки
double calc_expr(char *str, int *err);

// освобождение стека +
void free_stack(stack x);

// вывод ошибки
void error_type(const int x);
