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

//считывание массива из файла
db *scan_table(const char *path);

//добавление и удаление €чейки таблицы
int add_cell(db *arr, db_cell *x);

void del_cell(db *arr, int n);

//вывод массива в консоль
void table_cprint(db *arr);

//вывод массива в файл
void table_fprint(db *arr, const char *path);

//быстра€ сортировка по n-ому столбцу
void db_sort(db *arr, int n, int l, int r);

//мен€ет пор€док строк на обратный
void db_back(db *arr);

//удаление массива
void db_free(db *base);

int str_comp(char*a, char*b);