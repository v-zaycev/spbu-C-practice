#ifndef OUTPUT_H_INCLUDED
#define OUTPUT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>


void reverse_nmb (int a, int p);//функция, выводящая цифры числа в p-ичной системе системе в обратном порядке

void direct_nmb (int a, int p); //функция, выводящая цифры числа в p-ичной системе системе в прямом порядке

char nmb (int a); // функция, определяющая длину числа в p-ичной системе счисления

#endif // OUTPUT_H_INCLUDED
