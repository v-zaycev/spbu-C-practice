#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "DB_mod.h"
#include "Graphics_mod.h"

int main()
{
	setlocale(LC_CTYPE, "RUS");
	char *path_in = "input.txt",*path_out= "output.txt";
	db *b = scan_table(path_in);
	if (!b)
		return 0;
	db_cell x;
	char* in_str = malloc(25), *in_val = malloc(15), *in_k = malloc(9),put;
	int str_i = 0, k_i = 0, val_i = 0, top = 0, low = 18, srt = 1, bt_am = 16, mbt_pressed = 0,i, pt = 0,per=0;
	in_str[0] = '\0';
	in_val[0] = '\0';
	in_k[0] = '\0';
	
	sfFont *ft = sfFont_createFromFile("SegoeUIRegular.ttf");
	graph *g = graph_init(b->used, b);
	circular_graph_init(g, srt, ft);
	bar_graph_init(g, srt, ft);
	g->table = table_graph_init(b->used, b,ft);	

	sfVideoMode mode = { 1024, 600, 32 }; //+
	sfRenderWindow* window;
	sfContextSettings set;
	set.antialiasingLevel = 8;
	set.majorVersion = 4;
	set.minorVersion = 5;
	set.depthBits = 24;
	set.stencilBits = 8;
	sfEvent event;
	window = sfRenderWindow_create(mode, "DB", sfResize | sfClose, &set);
	sfRectangleShape *xx = sfRectangleShape_create();
	sfVector2f v;
	v.x = 0;
	v.y = 0;
	sfRectangleShape_setOrigin(xx, v);
	sfRectangleShape_setFillColor(xx, sfColor_fromRGB(180, 180,180));
	sfRectangleShape_setOutlineColor(xx, sfColor_fromRGB(250, 150, 0));
	sfRectangleShape_setOutlineThickness(xx, 3);
	v.x = 750;
	v.y = 500;
	sfRectangleShape_setSize(xx, v);
	v.x = 250;
	v.y = 75;
	sfRectangleShape_move(xx, v);

	sfColor cl_bt_down = sfColor_fromRGB(250, 150, 0), cl_txt = sfColor_fromRGB(255, 255, 255), cl_bt_up = sfColor_fromRGB(100, 100, 100),cl_bt_in= sfColor_fromRGB(150, 150, 150),cl_blc=sfBlack;
	
	
	button **bt_arr = malloc(bt_am * sizeof(button*)),**p=bt_arr;
	button *circular = button_init_gr("Circular", ft, 250, 72, 65, 25, &cl_txt, 15, &cl_bt_up, &cl_bt_down,&cl_bt_in);
	button *bar = button_init_gr("Bar", ft, 250+65, 72, 40, 25, &cl_txt, 15, &cl_bt_up, &cl_bt_down, &cl_bt_in);
	button *table = button_init_gr("Table", ft, 250 + 65+40, 72, 50, 25, &cl_txt, 15, &cl_bt_up, &cl_bt_down, &cl_bt_in);

	button *use_val = button_init_gr("Rating", ft, 250+750-65-56 , 72, 50, 25, &cl_txt, 15, &cl_bt_up, &cl_bt_down, &cl_bt_in);
	button *use_k = button_init_gr("Year", ft, 250+750-65, 72, 65, 25, &cl_txt, 15, &cl_bt_up, &cl_bt_down, &cl_bt_in);


	button *str = button_init_grc("Film", ft, 250+30, 75, 350, 25, &cl_txt, 20, &cl_bt_up, &cl_bt_down, &cl_bt_in);
	button *val = button_init_grc("Rating", ft, 250 + 30+350, 75, 250, 25, &cl_txt, 20, &cl_bt_up, &cl_bt_down, &cl_bt_in);
	button *k = button_init_grc("Year", ft, 250 + 30+400+200, 75, 120, 25, &cl_txt, 20, &cl_bt_up, &cl_bt_down, &cl_bt_in);
	button *add = button_init_grc("+", ft, 250, 75, 30, 25, &cl_txt, 20, &cl_bt_up, &cl_bt_down, &cl_bt_in);

	button *str_pt = button_init_grc(in_str, ft, 250 + 30+3, 75+3, 350-6, 19, &cl_blc, 15, &cl_bt_up, &cl_bt_down, &cl_bt_in);
	button *val_pt = button_init_grc(in_val, ft, 250 + 30 + 350+3, 75+3, 250-6, 19, &cl_blc, 15, &cl_bt_up, &cl_bt_down, &cl_bt_in);
	button *k_pt = button_init_grc(in_k, ft, 250 + 30 + 400 + 200+3, 75+3, 100-6, 19, &cl_blc, 15, &cl_bt_up, &cl_bt_down, &cl_bt_in);
	button *x_pt = button_init_grc("X", ft, 250 + 30 + 400 + 150+150, 75, 20, 25, &cl_txt, 20, &cl_bt_up, &cl_bt_down, &cl_bt_in);
	sfRectangleShape_setOutlineThickness(val_pt->body, 3);
	sfRectangleShape_setOutlineThickness(str_pt->body, 3);
	sfRectangleShape_setOutlineThickness(k_pt->body, 3);


	button *del_pt = button_init_grc("X", ft, 250 + 30 + 400 + 150 + 150, 75, 20, 25, &cl_txt, 20, &cl_bt_up, &cl_bt_down, &cl_bt_in);

	//255 154 154

	button *exit = button_init_cm("Exit", ft, 20, 550, 50, 30, &cl_txt, 25, &cl_bt_up, &cl_bt_down, &cl_bt_in);
	button *unload = button_init_cm("Save", ft, 20, 20, 60, 30, &cl_txt, 25, &cl_bt_up, &cl_bt_down, &cl_bt_in);


	*p = circular;p++;
	*p = bar; p++;
	*p = table; p++;
	*p = use_val;; p++;
	*p = use_k; p++;
	*p = str; p++;
	*p = val; p++;
	*p = k; p++;
	*p = add; p++;
	*p = str_pt; p++;
	*p = val_pt; p++;
	*p = k_pt; p++;
	*p = x_pt; p++;
	*p = del_pt; p++;
	*p = unload; p++;
	*p = exit;
	
	sfRectangleShape_setFillColor(use_val->body, cl_bt_down);
	sfRectangleShape_setOutlineColor(use_val->body, cl_bt_down);
	use_val->pressed = 1;

	while (sfRenderWindow_isOpen(window))
	{
		if (!sfMouse_isButtonPressed(sfMouseLeft)&&mbt_pressed)
		{
			if (in_rect(sfMouse_getPositionRenderWindow(window),bar->body)&&!bar->pressed)
			{
				bar->pressed = 1;
				circular->pressed = 0;
				table->pressed = 0;
				sfRectangleShape_setFillColor(bar->body, cl_bt_down);
				sfRectangleShape_setOutlineColor(bar->body, cl_bt_down);

				sfRectangleShape_setFillColor(table->body, cl_bt_up);
				sfRectangleShape_setOutlineColor(table->body, cl_bt_up);

				sfRectangleShape_setFillColor(circular->body, cl_bt_up);
				sfRectangleShape_setOutlineColor(circular->body, cl_bt_up);
			}
			if (in_rect(sfMouse_getPositionRenderWindow(window), circular->body)&&!circular->pressed)
			{
				bar->pressed = 0;
				circular->pressed = 1;
				table->pressed = 0;
				sfRectangleShape_setFillColor(bar->body, cl_bt_up);
				sfRectangleShape_setOutlineColor(bar->body, cl_bt_up);

				sfRectangleShape_setFillColor(table->body, cl_bt_up);
				sfRectangleShape_setOutlineColor(table->body, cl_bt_up);

				sfRectangleShape_setFillColor(circular->body, cl_bt_down);
				sfRectangleShape_setOutlineColor(circular->body, cl_bt_down);
			}
			if (in_rect(sfMouse_getPositionRenderWindow(window), table->body)&&!table->pressed)
			{
				bar->pressed = 0;
				circular->pressed = 0;
				table->pressed = 1;
				sfRectangleShape_setFillColor(bar->body, cl_bt_up);
				sfRectangleShape_setOutlineColor(bar->body, cl_bt_up);

				sfRectangleShape_setFillColor(table->body, cl_bt_down);
				sfRectangleShape_setOutlineColor(table->body, cl_bt_down);

				sfRectangleShape_setFillColor(circular->body, cl_bt_up);
				sfRectangleShape_setOutlineColor(circular->body, cl_bt_up);
			}
			if (in_rect(sfMouse_getPositionRenderWindow(window), exit->body))
				sfRenderWindow_close(window);
			if (in_rect(sfMouse_getPositionRenderWindow(window), unload->body))
				table_fprint(b, path_out);
			if (table->pressed)
			{
				if (!pt)
				{
					if (in_rect(sfMouse_getPositionRenderWindow(window), str->body) && !str->pressed)
					{
						val->pressed = 0;
						str->pressed = 1;
						k->pressed = 0;
						db_sort(b, 3, 0, b->used);
						graph_free(g);
						g = graph_init(b->used, b);
						circular_graph_init(g, srt, ft);
						bar_graph_init(g, srt, ft);
						g->table = table_graph_init(b->used, b, ft);
				//		sfSleep(sfSeconds((float)0.2));
					}
					if (in_rect(sfMouse_getPositionRenderWindow(window), val->body) && !val->pressed)
					{
						val->pressed = 1;
						str->pressed = 0;
						k->pressed = 0;
						db_sort(b, 1, 0, b->used);
						graph_free(g);
						g = graph_init(b->used, b);
						circular_graph_init(g, srt, ft);
						bar_graph_init(g, srt, ft);
						g->table = table_graph_init(b->used, b, ft);
			//			sfSleep(sfSeconds((float)0.2));
					}
					if (in_rect(sfMouse_getPositionRenderWindow(window), k->body) && !k->pressed)
					{
						val->pressed = 0;
						str->pressed = 0;
						k->pressed = 1;
						db_sort(b, 2, 0, b->used);
						graph_free(g);
						g = graph_init(b->used, b);
						circular_graph_init(g, srt, ft);
						bar_graph_init(g, srt, ft);
						g->table = table_graph_init(b->used, b, ft);
			//			sfSleep(sfSeconds((float)0.2));
					}
					if ((in_rect(sfMouse_getPositionRenderWindow(window), str->body) && str->pressed) || (in_rect(sfMouse_getPositionRenderWindow(window), val->body) && val->pressed) || (in_rect(sfMouse_getPositionRenderWindow(window), k->body) && k->pressed))
					{
						db_back(b);
						table_free(g);
						g->table = table_graph_init(b->used, b, ft);
						mbt_pressed = 0;
		//				sfSleep(sfSeconds((float)0.2));

					}
					if (in_rect(sfMouse_getPositionRenderWindow(window), add->body) && !add->pressed)
					{
						val->pressed = 0;
						str->pressed = 0;
						k->pressed = 0;
						pt = 1;
			//			sfSleep(sfSeconds((float)0.1));
					}
					for (i = 0; i < g->size; i++)
					{
						sfVector2i vv;
						vv.x = sfMouse_getPositionRenderWindow(window).x;
						vv.y = sfMouse_getPositionRenderWindow(window).y;
						vv.y += 25 * top;
						if (in_rect(vv, (*(g->table + i))->body))
						{
							if (!(*(g->ln_pressed + i)))
							{
								*(g->ln_pressed + i) = 1;
								sfRectangleShape_setFillColor((*(g->table + i))->body, (*(g->table + i))->down);
							}
							else
							{
								*(g->ln_pressed + i) = 0;
								sfRectangleShape_setFillColor((*(g->table + i))->body, (*(g->table + i))->up);
							}
							//		sfSleep(sfSeconds((float)0.1));
						}
						else
						{
							*(g->ln_pressed + i) = 0;
							sfRectangleShape_setFillColor((*(g->table + i))->body, (*(g->table + i))->up);
						}
					}
						
				}
				else
				{
					if (in_rect(sfMouse_getPositionRenderWindow(window), add->body) && !add->pressed)
					{
						if (in_str[0] != 0 && in_val[0] != 0 && in_k[0] != 0)
						{
							x.k = (int)strtod(in_k, NULL);
							x.val = strtod(in_val, NULL);
							x.str = in_str;
							add_cell(b, &x);
							per = 0;
							in_k[0] = 0;
							in_val[0] = 0;
							in_str[0] = 0;
							sfText_setString(k_pt->txt, in_k);
							sfText_setString(val_pt->txt, in_val);
							sfText_setString(str_pt->txt, in_str);
							graph_free(g);
							g = graph_init(b->used, b);
							circular_graph_init(g, srt, ft);
							bar_graph_init(g, srt, ft);
							g->table = table_graph_init(b->used, b, ft);
							pt = 0;
							k_pt->pressed = 0;
							str_pt->pressed = 0;
							val_pt->pressed = 0;
							str_i = 0;
							val_i = 0;
							k_i = 0;
						}
					}
					if (in_rect(sfMouse_getPositionRenderWindow(window), x_pt->body) && !x_pt->pressed)
					{
						pt = 0;
						str_pt->pressed = 0;
						val_pt->pressed = 0;
						k_pt->pressed = 0;
					}
					if (in_rect(sfMouse_getPositionRenderWindow(window), k_pt->body) && !k_pt->pressed)
					{
						str_pt->pressed = 0;
						val_pt->pressed = 0;
						k_pt->pressed = 1;
					}
					if (in_rect(sfMouse_getPositionRenderWindow(window), val_pt->body) && !val_pt->pressed)
					{
						str_pt->pressed = 0;
						val_pt->pressed = 1;
						k_pt->pressed = 0;
					}
					if (in_rect(sfMouse_getPositionRenderWindow(window), str_pt->body) && !str_pt->pressed)
					{
						str_pt->pressed = 1;
						val_pt->pressed = 0;
						k_pt->pressed = 0;
					}
				}
			
				//////
				if (str->pressed)
					sfRectangleShape_setFillColor(str->body, cl_bt_down);
				else
					sfRectangleShape_setFillColor(str->body, cl_bt_up);
				if (val->pressed)
					sfRectangleShape_setFillColor(val->body, cl_bt_down);
				else
					sfRectangleShape_setFillColor(val->body, cl_bt_up);
				if (k->pressed)
					sfRectangleShape_setFillColor(k->body, cl_bt_down);
				else
					sfRectangleShape_setFillColor(k->body, cl_bt_up);

				if (str_pt->pressed)
					sfRectangleShape_setOutlineColor(str_pt->body, cl_bt_down);
				else
					sfRectangleShape_setOutlineColor(str_pt->body, cl_bt_up);
				if (val_pt->pressed)
					sfRectangleShape_setOutlineColor(val_pt->body, cl_bt_down);
				else
					sfRectangleShape_setOutlineColor(val_pt->body, cl_bt_up);
				if (k_pt->pressed)
					sfRectangleShape_setOutlineColor(k_pt->body, cl_bt_down);
				else
					sfRectangleShape_setOutlineColor(k_pt->body, cl_bt_up);
			}
			if (bar->pressed || circular->pressed)
			{
				if (in_rect(sfMouse_getPositionRenderWindow(window), use_k->body) && !use_k->pressed)
				{
					use_k->pressed = 1;
					srt = 2;
					use_val->pressed = 0;
					sfRectangleShape_setFillColor(use_k->body, cl_bt_down);
					sfRectangleShape_setOutlineColor(use_k->body, cl_bt_down);

					sfRectangleShape_setFillColor(use_val->body, cl_bt_up);
					sfRectangleShape_setOutlineColor(use_val->body, cl_bt_up);
					bar_free(g);
					circular_free(g);
					bar_graph_init(g, srt, ft);
					circular_graph_init(g, srt, ft);
				}
				if (in_rect(sfMouse_getPositionRenderWindow(window), use_val->body) && !use_val->pressed)
				{
					use_k->pressed = 0;
					srt = 1;
					use_val->pressed = 1;
					sfRectangleShape_setFillColor(use_k->body, cl_bt_up);
					sfRectangleShape_setOutlineColor(use_k->body, cl_bt_up);

					sfRectangleShape_setFillColor(use_val->body, cl_bt_down);
					sfRectangleShape_setOutlineColor(use_val->body, cl_bt_down);
					bar_free(g);
					circular_free(g);
					bar_graph_init(g, srt, ft);
					circular_graph_init(g, srt, ft);
				}
			}
			mbt_pressed = 0;
		}
		
		if (sfMouse_isButtonPressed(sfMouseLeft))
			mbt_pressed = 1;

		if (!sfMouse_isButtonPressed(sfMouseLeft))
			for (p = bt_arr; p < bt_arr + bt_am; p++)
			{
				if (in_rect(sfMouse_getPositionRenderWindow(window), (*p)->body) && !(*p)->pressed)
				{
					sfRectangleShape_setFillColor((*p)->body, (*p)->in);
					sfRectangleShape_setOutlineColor((*p)->body, (*p)->in);
				}
				if (!in_rect(sfMouse_getPositionRenderWindow(window), (*p)->body) && !(*p)->pressed)
				{
					sfRectangleShape_setFillColor((*p)->body, (*p)->up);
					sfRectangleShape_setOutlineColor((*p)->body, (*p)->up);
				}
			}
		
	    ///////кнопочки
		put = 0;
		if (sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyA))
		{
			put = 'A';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyB))
		{
			put = 'B';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyC))
		{
			put = 'C';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyD))
		{
			put = 'D';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyE))
		{
			put = 'E';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyF))
		{
			put = 'F';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyG))
		{
			put = 'G';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyH))
		{
			put = 'H';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyI))
		{
			put = 'I';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyJ))
		{
			put = 'J';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyK))
		{
			put = 'K';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyL))
		{
			put = 'L';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyM))
		{
			put = 'M';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyN))
		{
			put = 'N';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyO))
		{
			put = 'O';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyP))
		{
			put = 'P';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyQ))
		{
			put = 'Q';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyR))
		{
			put = 'R';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyS))
		{
			put = 'S';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyT))
		{
			put = 'T';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyU))
		{
			put = 'U';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyV))
		{
			put = 'V';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyW))
		{
			put = 'W';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyX))
		{
			put = 'X';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyY))
		{
			put = 'Y';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyZ))
		{
			put = 'Z';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyDown))
		{
			put = 2;
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyUp))
		{
			put = 3;
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyDelete))
		{
			put = 4;
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyNum0))
		{
			put = '0';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyNum1))
		{
			put = '1';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyNum2))
		{
			put = '2';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyNum3))
		{
			put = '3';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyNum4))
		{
			put = '4';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyNum5))
		{
			put = '5';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyNum6))
		{
			put = '6';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyNum7))
		{
			put = '7';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyNum8))
		{
			put = '8';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyNum9))
		{
			put = '9';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyBackspace))
		{
			put = 1;
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeySpace))
		{
			put = ' ';
			sfSleep(sfSeconds((float)0.1));
		}
		if (sfKeyboard_isKeyPressed(sfKeyPeriod))
		{
			put = '.';
			sfSleep(sfSeconds((float)0.1));
		}
		if (!sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyA))
		{
			put = 'a';
			sfSleep(sfSeconds((float)0.1));
		}
		if (!sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyB))
		{
			put = 'b';
			sfSleep(sfSeconds((float)0.1));
		}
		if (!sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyC))
		{
			put = 'c';
			sfSleep(sfSeconds((float)0.1));
		}
		if (!sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyD))
		{
			put = 'd';
			sfSleep(sfSeconds((float)0.1));
		}
		if (!sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyE))
		{
			put = 'e';
			sfSleep(sfSeconds((float)0.1));
		}
		if (!sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyF))
		{
			put = 'f';
			sfSleep(sfSeconds((float)0.1));
		}
		if (!sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyG))
		{
			put = 'g';
			sfSleep(sfSeconds((float)0.1));
		}
		if (!sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyH))
		{
			put = 'h';
			sfSleep(sfSeconds((float)0.1));
		}
		if (!sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyI))
		{
			put = 'i';
			sfSleep(sfSeconds((float)0.1));
		}
		if (!sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyJ))
		{
			put = 'j';
			sfSleep(sfSeconds((float)0.1));
		}
		if (!sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyK))
		{
			put = 'k';
			sfSleep(sfSeconds((float)0.1));
		}
		if (!sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyL))
		{
			put = 'l';
			sfSleep(sfSeconds((float)0.1));
		}
		if (!sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyM))
		{
			put = 'm';
			sfSleep(sfSeconds((float)0.1));
		}
		if (!sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyN))
		{
			put = 'n';
			sfSleep(sfSeconds((float)0.1));
		}
		if (!sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyO))
		{
			put = 'o';
			sfSleep(sfSeconds((float)0.1));
		}
		if (!sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyP))
		{
			put = 'p';
			sfSleep(sfSeconds((float)0.1));
		}
		if (!sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyQ))
		{
			put = 'q';
			sfSleep(sfSeconds((float)0.1));
		}
		if (!sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyR))
		{
			put = 'r';
			sfSleep(sfSeconds((float)0.1));
		}
		if (!sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyS))
		{
			put = 's';
			sfSleep(sfSeconds((float)0.1));
		}
		if (!sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyT))
		{
			put = 't';
			sfSleep(sfSeconds((float)0.1));
		}
		if (!sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyU))
		{
			put = 'u';
			sfSleep(sfSeconds((float)0.1));
		}
		if (!sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyV))
		{
			put = 'v';
			sfSleep(sfSeconds((float)0.1));
		}
		if (!sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyW))
		{
			put = 'w';
			sfSleep(sfSeconds((float)0.1));
		}
		if (!sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyX))
		{
			put = 'x';
			sfSleep(sfSeconds((float)0.1));
		}
		if (!sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyY))
		{
			put = 'y';
			sfSleep(sfSeconds((float)0.1));
		}
		if (!sfKeyboard_isKeyPressed(sfKeyLShift) && sfKeyboard_isKeyPressed(sfKeyZ))
		{
			put = 'z';
			sfSleep(sfSeconds((float)0.1));
		}
		//////////

		//ввод новых элементов
		if (k_pt->pressed)
			if (put != 0)
			{
				if (put == 1 && k_i > 0)
				{
					in_k[k_i - 1] = 0;
					sfText_setString(k_pt->txt, in_k);
					k_i--;
				}
				if (put > 1&& put >= '0'&&put <= '9'&&k_i<8)
				{
					in_k[k_i] = put;
					in_k[k_i + 1] = 0;
					k_i++;
					sfText_setString(k_pt->txt, in_k);
				}
			}

		if (val_pt->pressed)
			if (put != 0 )
			{
				if (put == 1 && val_i > 0)
				{
					in_val[val_i - 1] = 0;
					sfText_setString(val_pt->txt, in_val);
					val_i--;
				}
				if (put > 1 &&(put>='0'&&put<='9'||put=='.'&&per==0)&& val_i < 14)
				{
					if (put == '.')
						per++;
					in_val[val_i] = put;
					in_val[val_i + 1] = 0;
					val_i++;
					sfText_setString(val_pt->txt, in_val);
				}
			}

		if (str_pt->pressed)
		{

			if (put != 0)
			{
				if (put == 1 && str_i > 0)
				{
					in_str[str_i - 1] = 0;
					sfText_setString(str_pt->txt, in_str);
					str_i--;
				}
				if (put > 1 && str_i < 24)
				{
					in_str[str_i] = put;
					in_str[str_i + 1] = 0;
					str_i++;
					sfText_setString(str_pt->txt, in_str);
				}
			}

		}
		//////////

		//двигаем строки таблицы
		//вниз
		if (table->pressed&&put == 2 && low < g->size-1)
		{
			sfSleep(sfSeconds((float)0.1));
			top++;
			low++;
		}
		//вверх
		if (table->pressed&&put == 3 && top >0)
		{
			sfSleep(sfSeconds((float)0.1));
			top--;
			low--;
		}
		//////////

		if (put == 4)
		{
			for (i = 0; i < g->size; i++)
				if (*(g->ln_pressed + i))
				{
					del_cell(b, i);
					graph_free(g);
					g = graph_init(b->used, b);
					circular_graph_init(g, srt, ft);
					bar_graph_init(g, srt, ft);
					g->table = table_graph_init(b->used, b, ft);
				}
		}

		while (sfRenderWindow_pollEvent(window, &event))
		{
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
		}
		
		sfRenderWindow_clear(window, sfColor_fromRGB(35, 40, 45));
		sfRenderWindow_drawRectangleShape(window, circular->body, NULL);
		sfRenderWindow_drawRectangleShape(window, bar->body, NULL);
		sfRenderWindow_drawRectangleShape(window, table->body, NULL);

		sfRenderWindow_drawText(window, circular->txt, NULL);
		sfRenderWindow_drawText(window, bar->txt, NULL);
		sfRenderWindow_drawText(window, table->txt, NULL);

		if (bar->pressed || circular->pressed)
		{
			sfRenderWindow_drawRectangleShape(window, use_k->body, NULL);
			sfRenderWindow_drawRectangleShape(window, use_val->body, NULL);

			sfRenderWindow_drawText(window, use_k->txt, NULL);
			sfRenderWindow_drawText(window, use_val->txt, NULL);
		}

		sfRenderWindow_drawRectangleShape(window, xx, NULL);

		if (table->pressed)
		{
			sfRenderWindow_drawRectangleShape(window, add->body, NULL);
			sfRenderWindow_drawText(window, add->txt, NULL);
			if (!pt)
			{
				sfRenderWindow_drawRectangleShape(window, str->body, NULL);
				sfRenderWindow_drawText(window, str->txt, NULL);
				sfRenderWindow_drawRectangleShape(window, val->body, NULL);
				sfRenderWindow_drawText(window, val->txt, NULL);
				sfRenderWindow_drawRectangleShape(window, k->body, NULL);
				sfRenderWindow_drawText(window, k->txt, NULL);
			}
			else
			{
				sfRenderWindow_drawRectangleShape(window, str_pt->body, NULL);
				sfRenderWindow_drawText(window, str_pt->txt, NULL);
				sfRenderWindow_drawRectangleShape(window, val_pt->body, NULL);
				sfRenderWindow_drawText(window, val_pt->txt, NULL);
				sfRenderWindow_drawRectangleShape(window, k_pt->body, NULL);
				sfRenderWindow_drawText(window, k_pt->txt, NULL);
				sfRenderWindow_drawRectangleShape(window, x_pt->body, NULL);
				sfRenderWindow_drawText(window, x_pt->txt, NULL);
			}
		}

		sfRenderWindow_drawRectangleShape(window, exit->body, NULL);
		sfRenderWindow_drawText(window, exit->txt, NULL);
		sfRenderWindow_drawRectangleShape(window, unload->body, NULL);
		sfRenderWindow_drawText(window, unload->txt, NULL);

	

		if (bar->pressed)
			for (i = 0; i < b->used; i++)
			{
				sfRenderWindow_drawRectangleShape(window, *(g->bar + i), NULL);
				sfRenderWindow_drawText(window, *(g->bar_txt + i), NULL);
			}

		if (circular->pressed)
		{
			for (i = 0; i < b->used; i++)
				sfRenderWindow_drawText(window, *(g->cr_txt + i), NULL);

			for (i = 0; i < b->used; i++)
				sfRenderWindow_drawRectangleShape(window, *(g->cr_ln + i), NULL);

			for (i = 0; i < b->used; i++)
				sfRenderWindow_drawConvexShape(window, *(g->circular + i), NULL);
		}

		if (table->pressed)
		{
			for (i = 0; i < g->size; i++)
				line_move(*(g->table + i), (float)0, (float)(-top*25));

			for (i = top; i < min(b->used, low + 1); i++)
			{
				*(g->ln_vs + i) = 1;
				sfRenderWindow_drawRectangleShape(window, (*(g->table + i))->body, NULL);
				sfRenderWindow_drawText(window, (*(g->table + i))->nmb, NULL);
				sfRenderWindow_drawText(window, (*(g->table + i))->str, NULL);
				sfRenderWindow_drawText(window, (*(g->table + i))->val, NULL);
				sfRenderWindow_drawText(window, (*(g->table + i))->k, NULL);
			}
		}
		sfRenderWindow_display(window);

		if (table->pressed)
			for (i = 0; i < g->size; i++)
				line_move(*(g->table + i), (float)0, (float)(-top *(-25)));
	}

	free(in_str);
	free(in_val);
	free(in_k);
	for (i = 0; i < bt_am; i++)
		button_free(*(bt_arr + i));
	free(bt_arr);
	sfRectangleShape_destroy(xx);
	graph_free(g);
	db_free(b);
	sfFont_destroy(ft);
	sfRenderWindow_destroy(window);

	return 0;
}