#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>


void int_scan (int *a,size_t sz); //ввод массива заданной длины с переменными типа int

void int_print (const int *a, size_t sz); //вывод массива заданной длины с переменными типа int

void double_scan(double *a, size_t sz); //ввод массива заданной длины с переменными типа double

void double_print(const double *a, size_t sz); //вывод массива заданной длины с переменными типа double

void del_odd(int *a, size_t *sz); // удаление нечётных элементов (не оптимальна по памяти)

void del_even(int *a, size_t *sz); // удаление чётных элементов (не оптимальна по памяти)

void del_odd_t(int *a, size_t *sz); // удаление нечётных элементов (не оптимальна по времени)

void del_even_t(int *a, size_t *sz); // удаление чётных элементов (не оптимальна по времени)