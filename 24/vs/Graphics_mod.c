#define _CRT_SECURE_NO_WARNINGS
#include"Graphics_mod.h"

graph *graph_init(int size,const db *base)
{
	graph *g = malloc(sizeof(graph));
	g->size = size;
	g->base = base;
	g->ln_vs = malloc(size * sizeof(int));
	g->ln_pressed = malloc(size * sizeof(int));
	int i = 0;
	for (i = 0; i < size; i++)
	{
		*(g->ln_pressed + i) = 0;
		*(g->ln_vs + i) = 0;

	}
	return g;
}

void graph_free(graph*g)
{
	if (!g)
		return;

	bar_free(g);
	circular_free(g);
	table_free(g);

	if (g->ln_vs)
		free(g->ln_vs);
	if(g->ln_pressed)
		free(g->ln_pressed);
	free(g);
	return;
}

void line_free(line *ln)
{
	if (!ln)
		return;
	if (ln->nmb)
		sfText_destroy(ln->nmb);
	if (ln->str)
		sfText_destroy(ln->str);
	if (ln->k)
		sfText_destroy(ln->k);
	if (ln->val)
		sfText_destroy(ln->val);
	if (ln->body)
		sfRectangleShape_destroy(ln->body);
	free(ln);
	return;
}

void circular_free(graph *g)
{
	if (!g)
		return;
	sfConvexShape **i;
	sfText **j;
	sfRectangleShape **k;
	if (g->circular)
	{
		for (i = g->circular; i < g->circular + g->size; i++)
			if (*i)
				sfConvexShape_destroy(*i);
		free(g->circular);
	}

	if (g->cr_txt)
	{
		for (j = g->cr_txt; j < g->cr_txt + g->size; j++)
			if (*j)
				sfText_destroy(*j);
		free(g->cr_txt);
	}
	

	if (g->cr_ln)
	{
		for (k = g->cr_ln; k < g->cr_ln + g->size; k++)
			if (*k)
				sfRectangleShape_destroy(*k);
		free(g->cr_ln);
	}


	return;
}

void bar_free(graph *g)
{
	if (!g)
		return;
	sfRectangleShape **i;
	sfText **j;

	if (g->bar)
	{
		for (i = g->bar; i < g->bar + g->size; i++)
			if (*i)
				sfRectangleShape_destroy(*i);
		free(g->bar);
	}

	if (g->bar_txt)
	{
		for (j = g->bar_txt; j < g->bar_txt + g->size; j++)
			if (*j)
				sfText_destroy(*j);
		free(g->bar_txt);
	}

	return;

}

void table_free(graph *g)
{
	line **i;
	if (!g||!g->table)
		return;
	for (i = g->table; i < g->table + g->size; i++)
		line_free(*i);

	free(g->table);
	return;
}

void button_free(button *b)
{
	if (!b)
		return;
	if (b->body)
		sfRectangleShape_destroy(b->body);
	if (b->txt)
		sfText_destroy(b->txt);
	free(b);
	return;
}

void circular_graph_init(graph *g, int column, sfFont *ft)
{
	g->circular = malloc(g->size * sizeof(sfConvexShape*));
	sfConvexShape **p = g->circular;
	g->cr_txt = malloc(g->size * sizeof(sfText*));
	sfText **q = g->cr_txt;
	g->cr_ln = malloc(g->size * sizeof(sfRectangleShape*));
	sfRectangleShape **r = g->cr_ln;
	sfColor cl[6] = { sfRed,sfGreen,sfBlue,sfYellow,sfMagenta,sfCyan };
	sfVector2f v;
	char *text = malloc(100);
	int i = 0,k=0,n,rd;
	float j = -90, stp = (float)0.2, sum = 0, sum_a = 0;
	for (i = 0; i < g->size; i++)
		if (column == 1)
			sum += (float)(*(g->base->data + i))->val;
		else
			sum += (float)(*(g->base->data + i))->k;
	for (i = 0; i < g->size; i++,p++, r++, q++)
	{
		strcpy(text, (*(g->base->data + i))->str);
		text[14] = 0;
		for (k = 1; k < 4; k++)
			if (text[14 - k] != 0)
				text[14 - k] = '.';
			else
				break;
		*q = sfText_create();
		sfText_setCharacterSize(*q, 18);
		sfText_setColor(*q, sfBlack);
		sfText_setString(*q, text);
		sfText_setFont(*q, ft);

		v.x = 230;
		v.y = 2;
		*r = sfRectangleShape_create();
		sfRectangleShape_setSize(*r, v);
		sfRectangleShape_setFillColor(*r, sfBlack);

		*p = sfConvexShape_create();
		sfConvexShape_setFillColor(*p,cl[i%6]);
		v.x = 0;
		v.y = 0;
		sfConvexShape_setOrigin(*p, v);
		sfRectangleShape_setOrigin(*r, v);
		sfText_setOrigin(*q, v);
		if (column == 1)
			n = (int)roundf(1800 * (float)((*(g->base->data + i))->val) / sum);
		else
			n = (int)roundf(1800 * (float)((*(g->base->data + i))->k) / sum);

		sfRectangleShape_rotate(*r, j + (float)n*stp / 2);
		v.x = (float)(230 * cos((float)((j + (float)n*stp / 2)*0.0174532925)));
		v.y = (float)(230 * sin((float)((j + (float)n*stp / 2)*0.0174532925)));
		sfText_move(*q, v);
		if (j + (float)n*stp / 2 < 90)
		{
			v.x = 3;
			v.y = 0;
			sfText_move(*q, v);
		}
		else
		{
			v.x =-sfText_getLocalBounds(*q).width -3;
			v.y = 0;
			sfText_move(*q, v);
		}

		if (j + (float)n*stp / 2 < 0|| j + (float)n*stp / 2 > 180)
		{
			v.x = 0;
			v.y = -sfText_getLocalBounds(*q).height;
			sfText_move(*q, v);
		}


		v.x = 0;
		v.y = 0;
		sfConvexShape_setPointCount(*p, 2 + n);
		sfConvexShape_setPoint(*p,0, v);

		for (rd = 0; rd < n + 1; rd++)
		{
			v.x = sfConvexShape_getOrigin(*p).x + (float)(150 * cos((float)((j)*0.0174532925)));
			v.y = sfConvexShape_getOrigin(*p).y + (float)(150 * sin((float)((j)*0.0174532925)));
			j += stp;
			if (i + 1 == g->size&&rd + 1 == n)
			{
				j = 270;
			}
			sfConvexShape_setPoint(*p, rd + 1, v);
		}
		v.x = 625;
		v.y = 325;
		sfConvexShape_move(*p, v);
		sfRectangleShape_move(*r, v);
		sfText_move(*q, v);
		j -= stp;
		if (column == 1)
			sum_a += (float)(*(g->base->data + i))->val;
		else
			sum_a += (float)(*(g->base->data + i))->k;
	}
	free(text);
	return;
}

void bar_graph_init(graph *g, int column, sfFont *ft)
{
	g->bar = malloc(g->size * sizeof(sfRectangleShape*));
	sfRectangleShape **p = g->bar;
	g->bar_txt = malloc(g->size * sizeof(sfText*));
	sfText **q = g->bar_txt;
	sfVector2f v;
	sfColor cl[6] = { sfRed,sfGreen,sfBlue,sfYellow,sfMagenta,sfCyan };
	char *text = malloc(100);
	int i,j;
	float mx = -INFINITY,h=300,w=700/((float)(2* g->size -1));
	for (i = 0; i < g->size; i++)
	{
		if (column == 1)
			if ((float)(*(g->base->data + i))->val > mx)
				mx = (float)(*(g->base->data + i))->val;
		if (column == 2)
			if ((float)(*(g->base->data + i))->k > mx)
				mx = (float)(*(g->base->data + i))->k;
	}

	for (i = 0; i < g->size; i++)
	{
		strcpy(text, (*(g->base->data + i))->str);
		text[14] = 0;
		for (j = 1; j < 4; j++)
			if (text[14 - j] != 0)
				text[14 - j] = '.';
			else
				break;
		*p = sfRectangleShape_create();
		*q = sfText_create();
		sfRectangleShape_setFillColor(*p, cl[i % 6]);
		sfText_setColor(*q, sfBlack);
		sfText_setFont(*q, ft);
		sfText_setCharacterSize(*q, 18);
		sfText_setString(*q, text);
		v.x = 0;
		v.y = 0;
		sfRectangleShape_setOrigin(*p, v);
		sfText_setOrigin(*q, v);
		if (column == 1)
		{
			v.y = -h * (float)(*(g->base->data + i))->val / mx;
		}
		else
			v.y = -h * (float)(*(g->base->data + i))->k / mx;

		v.x = w;
		sfRectangleShape_setSize(*p, v);

		v.y = 0;
		v.x = 2 * i*w;
		sfRectangleShape_move(*p, v);
		sfText_move(*q, v);

		v.x = 250 + 25;
		v.y = 75 + 300 + 25;
		sfRectangleShape_move(*p, v);
		v.x = 250 + 50;
		v.y = 75 + 300 + 25+5;
		sfText_move(*q, v);
		sfText_rotate(*q, 80);
		p++;
		q++;
	}
	free(text);
	return;
}

line **table_graph_init(int size, const db *base, sfFont *ft)
{
	line **g = malloc(size * sizeof(line*)), **p;
	sfColor cl[2] = { sfColor_fromRGB(132,250,160),sfColor_fromRGB(132,223,250)};
	sfVector2f v;
	char *str = malloc(100), *val = malloc(100), *k = malloc(100),*nmb=malloc(100);


	int i,j;
	for (i=0,p=g; p < g+size; p++,i++)
	{
		*p = malloc(sizeof(line));
		(*p)->nmb = sfText_create();
		(*p)->str = sfText_create();
		(*p)->val = sfText_create();
		(*p)->k = sfText_create();
		sfText_setCharacterSize((*p)->nmb, 20);
		sfText_setCharacterSize((*p)->str, 20);
		sfText_setCharacterSize((*p)->val, 20);
		sfText_setCharacterSize((*p)->k, 20);
		sfText_setColor((*p)->nmb, sfBlack);
		sfText_setColor((*p)->str, sfBlack);
		sfText_setColor((*p)->val, sfBlack);
		sfText_setColor((*p)->k, sfBlack);
		sfText_setFont((*p)->nmb, ft);
		sfText_setFont((*p)->str, ft);
		sfText_setFont((*p)->val, ft);
		sfText_setFont((*p)->k, ft);
		strcpy(str, (*(base->data+i))->str);
		sprintf(val, "%lf", (*(base->data+i))->val);
		sprintf(k, "%i", (*(base->data + i))->k);
		sprintf(nmb, "%i", i+1);
		str[37] = 0;
		for (j = 36; j > 33; j--)
			if (str[j] != 0)
				str[j] = '.';
			else
				break;
		sfText_setString((*p)->nmb, nmb);
		sfText_setString((*p)->str, str);
		sfText_setString((*p)->val, val);
		sfText_setString((*p)->k, k);
		v.x = 250+5;
		v.y = 100 + 25 * (float)i;
		sfText_setPosition((*p)->nmb, v);
		v.x = 250 + 30+5;
		v.y = 100 + 25 * (float)i;
		sfText_setPosition((*p)->str, v);
		v.x = 250 + 30 + 350+5;
		v.y = 100 + 25 * (float)i;
		sfText_setPosition((*p)->val, v);
		v.x = 250 + 30 + 350 + 250+5;
		v.y = 100 + 25 * (float)i;
		sfText_setPosition((*p)->k, v);

		(*p)->body = sfRectangleShape_create();
		v.x = 0;
		v.y = 0;
		sfRectangleShape_setOrigin((*p)->body, v);
		v.x = 750;
		v.y = 25;
		sfRectangleShape_setSize((*p)->body, v);
		v.x = 250;
		v.y = 100+25*(float)i;
		sfRectangleShape_move((*p)->body, v);
		sfRectangleShape_setFillColor((*p)->body, cl[i % 2]);
		(*p)->up = cl[i % 2];
		(*p)->down = sfColor_fromRGB(255,154,154);
	}
	free(str);
	free(val);
	free(k);
	free(nmb);
	return g;
}

button *button_init_gr(char *text, sfFont *ft, float x, float y, float sz_x, float sz_y, sfColor *cl_txt, int font, sfColor *cl_up, sfColor *cl_down, sfColor *cl_in)
{
	button *bt = malloc(sizeof(button));
	sfVector2f v;
	bt->body = sfRectangleShape_create();
	bt->txt = sfText_create();
	bt->pressed = 0;
	bt->up = *cl_up;
	bt->down = *cl_down;
	bt->in = *cl_in;

	sfText_setFont(bt->txt, ft);
	sfText_setString(bt->txt, text);
	sfText_setCharacterSize(bt->txt, font);
	sfText_setColor(bt->txt, *cl_txt);
	v.x = x+5;
	v.y = y - 20;
	sfText_setPosition(bt->txt, v);
	v.x = x;
	v.y = y - sz_y;
	sfRectangleShape_setPosition(bt->body, v);
	v.x = sz_x;
	v.y = sz_y;
	sfRectangleShape_setSize(bt->body, v);
	sfRectangleShape_setFillColor(bt->body, *cl_up);
	sfRectangleShape_setOutlineColor(bt->body, *cl_up);
	sfRectangleShape_setOutlineThickness(bt->body, 3);
	return bt;
}

button *button_init_grc(char *text, sfFont *ft, float x, float y, float sz_x, float sz_y, sfColor *cl_txt, int font, sfColor *cl_up, sfColor *cl_down, sfColor *cl_in)
{
	button *bt = malloc(sizeof(button));
	sfVector2f v;
	bt->body = sfRectangleShape_create();
	bt->txt = sfText_create();
	bt->pressed = 0;
	bt->up = *cl_up;
	bt->down = *cl_down;
	bt->in = *cl_in;

	sfText_setFont(bt->txt, ft);
	sfText_setString(bt->txt, text);
	sfText_setCharacterSize(bt->txt, font);
	sfText_setColor(bt->txt, *cl_txt);
	v.x = x+5;
	v.y = y;
	sfText_setPosition(bt->txt, v);
	v.x = x;
	v.y = y;
	sfRectangleShape_setPosition(bt->body, v);
	v.x = sz_x;
	v.y = sz_y;
	sfRectangleShape_setSize(bt->body, v);
	sfRectangleShape_setFillColor(bt->body, *cl_up);
	return bt;
}

button *button_init_cm(char *text, sfFont *ft, float x, float y, float sz_x, float sz_y, sfColor *cl_txt, int font, sfColor *cl_up, sfColor *cl_down, sfColor *cl_in)
{
	button *bt = malloc(sizeof(button));
	sfVector2f v;
	bt->body = sfRectangleShape_create();
	bt->txt = sfText_create();
	bt->pressed = 0;
	bt->up = *cl_up;
	bt->down = *cl_down;
	bt->in = *cl_in;


	sfText_setFont(bt->txt, ft);
	sfText_setString(bt->txt, text);
	sfText_setCharacterSize(bt->txt, font);
	sfText_setColor(bt->txt, *cl_txt);
	v.x = x + 5;
	v.y = y ;
	sfText_setPosition(bt->txt, v);
	v.x = x;
	v.y = y;
	sfRectangleShape_setPosition(bt->body, v);
	v.x = sz_x;
	v.y = sz_y;
	sfRectangleShape_setSize(bt->body, v);
	sfRectangleShape_setFillColor(bt->body, *cl_up);
	sfRectangleShape_setOutlineColor(bt->body, *cl_up);
	sfRectangleShape_setOutlineThickness(bt->body, 3);
	return bt;
}

int in_rect(sfVector2i xy, sfRectangleShape *bt)
{
	if (xy.x > sfRectangleShape_getPosition(bt).x&&xy.y > sfRectangleShape_getPosition(bt).y&&xy.x < sfRectangleShape_getPosition(bt).x + sfRectangleShape_getSize(bt).x&&xy.y < sfRectangleShape_getPosition(bt).y + sfRectangleShape_getSize(bt).y)
		return 1;
	else
		return 0;
}

void line_move(line *ln, float x, float y)
{
	sfVector2f v;
	v.x = x;
	v.y = y;
	sfRectangleShape_move(ln->body, v);
	sfText_move(ln->str, v);
	sfText_move(ln->val, v);
	sfText_move(ln->k, v);
	sfText_move(ln->nmb, v);
	return;
}