#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"

void to_next(dclist *list)
{
	if (*list != NULL)
		*list = (*list)->next;
	return;
}

void to_prev(dclist *list)
{
	if (*list != NULL)
		*list = (*list)->prev;
	return;
}

void print_list(const dclist list)
{
	if (list == NULL)
	{
		printf("\n");
		return;
	}
	cell *i = list;
	do
	{
		printf("%i\n", i->data);
		i = i->next;
	} while (i != list);
	return;
}

void del_current(dclist *list)
{
	if (*list == NULL)
		return;
	cell *x;
	if ((*list)->next == *list)
		x = NULL;
	else
		x = (*list)->next;
	(*list)->next->prev = (*list)->prev;
	(*list)->prev->next = (*list)->next;
	free(*list);
	*list = x;
	return;
}

int add_prev(dclist *list,int a)
{
	cell *x=malloc(sizeof(cell));
	if (x == NULL)
		return 1;
	if (*list != NULL)
	{
		(*list)->prev->next = x;
		x->prev = (*list)->prev;
		(*list)->prev = x;
		x->data = a;
		x->next = *list;
		*list = x;
	}
	else
	{
		*list = x;
		x->data = a;
		x->next = x;
		x->prev = x;
	}
	return 0;
}

int add_next(dclist *list,int a)
{
	cell *x = malloc(sizeof(cell));
	if (x == NULL)
		return 1;
	if (*list != NULL)
	{
		x->next = (*list)->next;
		(*list)->next->prev = x;
		(*list)->next = x;
		x->data = a;
		x->prev = (*list);
		*list = x;
	}
	else
	{
		*list = x;
		x->data = a;
		x->next = x;
		x->prev = x;
	}
	return 0;
}

int copy_list(const dclist list, dclist *copy)
{
	if (list == NULL)
	{
		*copy = NULL;
		return 0;
	}
	const cell *i=list;
	cell *z,*y,*x=malloc(sizeof(cell));
	if (x == NULL)
		return 1;
	x->data = i->data;
	y = x;
	z = x;
	i=i->next;
	while (i != list)
	{
		x = malloc(sizeof(cell));
		if (x == NULL)
			return 1;
		x->data = i->data;
		x->prev = y;
		y->next = x;
		y = x;
		i = i->next;
	}
	z->prev = y;
	y->next = z;
	*copy = z;
	return 0;
}
