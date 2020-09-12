#define _CRT_SECURE_NO_WARNINGS
#include "DB_mod.h"

db *scan_table(const char *path)
{
	FILE *fl=fopen(path, "r");
	char *buff = malloc(100),*w;
	if (!buff)
		return NULL;
	buff[0] = 0;
	db *ret = malloc(sizeof(db));
	if (!ret)
		return NULL;
	ret->data = malloc(100 * sizeof(db_cell*));
	if (!ret->data)
		return NULL;
	ret->used = 0;
	ret->aval = 100;
	db_cell **i = ret->data,*j;
	while (fl&& !feof(fl))
	{	
		if (ret->aval == ret->used)
			break;
		fgets(buff, 99, fl);
		j = malloc(sizeof(db_cell));
		if (!j)
			break;
		if (buff[0] == 0)
			break;
		j->k = (int)strtod(strtok(buff, " \n\0"),NULL);
		j->val = strtod(strtok(NULL, " \n\0"), NULL);
		w = strtok(NULL, "\n\0");
		j->str = malloc(100);
			if (!j->str)
				break;
		strcpy(j->str, w);
		*i = j;
		i++;
		ret->used++;
	}
	if (fl)
		fclose(fl);
	free(buff);
	return ret;
}

int add_cell(db *arr, db_cell *x)
{
	if (!arr || !x||arr->used==arr->aval)
		return 0;
	if (!x->str)
		return 0;
	
	db_cell *n = malloc(sizeof(db_cell));
	if (!n)
		return 0;
	n->str = malloc(100);
	if (!n->str)
		return 0;
	*(arr->data + arr->used) = n;
	(*(arr->data + arr->used))->k = x->k;
	(*(arr->data + arr->used))->val = x->val;
	strcpy((*(arr->data + arr->used))->str, x->str);
	arr->used++;
	return 1;
}

void del_cell(db *arr, int n)
{
	if (!arr || !arr->data || n < 0 || n >= arr->used)
		return;
	arr->used--;
	free((*(arr->data + n))->str);
	free(*(arr->data + n));
	db_cell **i = arr->data+n;
	for (; i < arr->used+arr->data; i++)
	{
		*i = *(i+1);
	}
	return;
}

void table_cprint(db *arr)
{
	if (!arr || !arr->data)
		return;
	db_cell **i;
	printf("Тип, значение, количество\n");
	for (i = arr->data; i < arr->data + arr->used; i++)
	{
		printf("%s ", (*i)->str);
		printf("%lf ", (*i)->val);
		printf("%i\n", (*i)->k);
	}
	return;
}

void table_fprint(db *arr, const char *path)
{
	FILE *fl = fopen(path, "w");
	if (!fl)
		return;
	db_cell **i;
	for (i = arr->data; i < arr->data + arr->used; i++)
	{
		fprintf(fl,"%i ", (*i)->k);
		fprintf(fl,"%lf ", (*i)->val);
		fprintf(fl,"%s\n", (*i)->str);
	}
	fclose(fl);
	return;
}

void db_sort(db *arr, int n,int l,int r)
{
	if (!arr||n>3||n<1||!arr->data)
		return;
	if (l < 0)
		l = 0;
	if (r >= arr->used)
		r = arr->used - 1;
	if (l >= arr->used || r < 0||r<=l)
		return;
	db_cell **i=arr->data+l-1,**j=arr->data+r,*k;
	int cp, ls = -1;;
	while (i < j)
	{
		do
		{
			i++;
			if (i < j)
				ls++;
			else
				break;
			switch (n)
			{
			case 1: 
			{
				if ((*i)->val > (*(arr->data + r))->val)
					cp = 1;
				else
					if ((*i)->val < (*(arr->data + r))->val)
						cp = 2;
					else
						cp = 0;
				break; 
			}
			case 2:
			{
				if ((*i)->k > (*(arr->data + r))->k)
					cp = 1;
				else
					if ((*i)->k < (*(arr->data + r))->k)
						cp = 2;
					else
						cp = 0;
				break;
			}
			case 3: {cp = str_comp((*i)->str, (*(arr->data + r))->str); break; }
			}
		} while (cp != 1);

		do
			{
				j--;
				if (i >= j)
					break;
				switch (n)
				{
				case 1:
				{
					if ((*j)->val > (*(arr->data + r))->val)
						cp = 1;
					else
						if ((*j)->val < (*(arr->data + r))->val)
							cp = 2;
						else
							cp = 0;
					break;
				}
				case 2:
				{
					if ((*j)->k > (*(arr->data + r))->k)
						cp = 1;
					else
						if ((*j)->k < (*(arr->data + r))->k)
							cp = 2;
						else
							cp = 0;
					break;
				}
				case 3: {cp = str_comp((*j)->str, (*(arr->data + r))->str); break; }
				}
		} while (cp != 2&&cp != 0);

		if (i < j)
		{
			k = *i;
			*i = *j;
			*j = k;
		}
	}

	k = *i;
	*i = *(arr->data + r);
	*(arr->data + r) = k;
	db_sort(arr, n, l, l + ls);
	db_sort(arr, n, l + ls+1, r);
	return;
}

void db_back(db *arr)
{
	if (!arr)
		return;
	if (!arr->data)
		return;
	db_cell **i = arr->data, **j = arr->data + arr->used - 1, *k;
	while (i < j)
	{
		k = *i;
		*i = *j;
		*j = k;
		i++;
		j--;
	}
	return;
}

void db_free(db *base)
{
	if (!base)
		return;
	db_cell **i;
	if (base->data)
	{
		for (i = base->data; i < base->data + base->used; i++)
			if (*i)
			{
				if ((*i)->str)
					free((*i)->str);
				free(*i);
			}
		free(base->data);
	}
	free(base);
	return;
}

int str_comp(char*a, char*b)
{
	if (!a || !b)
		return 0;
	char *i = a, *j = b;
	while (*i != '\0' || *j != '\0')
	{
		if (*i != '\0'&&*j != '\0')
		{
			if (*i > *j)
				return 1;
			else
				if (*i < *j)
					return 2;
		}
		if (*i != '\0'&&*j == '\0')
			return 2;
		if (*i == '\0'&&*j != '\0')
			return 1;
		i++;
		j++;
	}
	return 0;
}