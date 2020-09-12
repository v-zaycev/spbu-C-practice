#ifndef OUTPUT_H_INCLUDED
#define OUTPUT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>


void reverse_nmb (const int s,char *str);//функция, выводящая цифры числа в p-ичной системе системе в обратном порядке

void direct_nmb (const int s,char *str); //функция, выводящая цифры числа в p-ичной системе системе в прямом порядке

int nmb_lenth_p (int a,int p); // функция, определяющая длину числа в p-ичной системе счисления

void str_build (int n,int a, int p,char *str); //функция, строящая последовательность цифр числа в p-ичной системе счисления
#endif // OUTPUT_H_INCLUDED
