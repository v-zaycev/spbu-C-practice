#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void substr(const char*s,char*sub, int n, int l);
// функция выделяет из строки s подстроку sub, которая начинается с индекса n и имеет длину l
