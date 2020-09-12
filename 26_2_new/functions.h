#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct cell cell;

// €чейка списка, состо€ща€ из целого чисда и указателей на соседние €чейки 
struct cell
{
	int data;
	cell *prev, *next;
};

// структура списка, котора€ может динамически расшир€тьс€ 
typedef cell* dclist;

// вз€тие следующего элемента в списке 
void to_next(dclist *list);

// вз€тие предыдущего элемента в списке 
void to_prev(dclist *list);

// вывод списка 
void print_list(const dclist list);

// удаление текущего элемента
void del_current(dclist *list);

// добавление элемента перед текущим 
int add_prev(dclist *list,int a);

// добавление элемента перед текущим 
int add_next(dclist *list, int a);

//копирует список в list в copy
int copy_list(const dclist list, dclist *copy);