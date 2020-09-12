#pragma once

#include<SFML/Graphics.h>
#include<SFML/Window.h>
#include<SFML/System.h>
#include"DB_mod.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct
{
	sfRectangleShape *body;
	sfText *nmb, *str, *val, *k;
	sfColor up, down, in;
	int pressed;
}line;

typedef struct
{
	int size;
	sfConvexShape **circular;
	sfText **cr_txt;
	sfRectangleShape **cr_ln;
	sfRectangleShape **bar;
	sfText **bar_txt;
	line **table;
	int *ln_pressed;
	int *ln_vs;
	const db *base;
}graph;

typedef struct
{
	sfRectangleShape *body;
	sfText *txt;
	sfColor up, down,in;
	int pressed;
}button;

//�������� ��������� �������
graph *graph_init(int size, const db *base);

//������������ ������ ��� ��������� �������� 
void graph_free(graph*g);

void line_free(line *ln);

void circular_free(graph *g);

void bar_free(graph *g);

void table_free(graph *g);

void button_free(button *b);

//������������� �������� � �������
void circular_graph_init(graph *g, int column, sfFont *ft);

void bar_graph_init(graph *g, int column, sfFont *ft);

line **table_graph_init(int size, const db *base, sfFont *ft);

//������������� ������ � ������� �����������
button *button_init_gr(char *text, sfFont *ft, float x, float y, float sz_x, float sz_y, sfColor *cl_txt, int font, sfColor *cl_up, sfColor *cl_down, sfColor *cl_in);

button *button_init_grc(char *text, sfFont *ft, float x, float y, float sz_x, float sz_y, sfColor *cl_txt, int font, sfColor *cl_up, sfColor *cl_down, sfColor *cl_in);

button *button_init_cm(char *text, sfFont *ft, float x, float y, float sz_x, float sz_y, sfColor *cl_txt, int font, sfColor *cl_up, sfColor *cl_down, sfColor *cl_in);

//�������� �� ��������� ������� � ������
int in_rect(sfVector2i xy, sfRectangleShape *bt);

//����� ������ ��������� ���� 
void line_move(line *ln, float x, float y);