#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
	dclist ls=NULL, cp=NULL;
	int a;
	char* str = malloc(30);

	setlocale(LC_CTYPE, "RUS");
	printf("/to_next - ������� � ���������� ��������\n/to_prev - ������� ������������ ��������\n/del_current - �������� �������� ��������\n/print_list - ����� ������\n/add_next - ���������� �������� ����� ��������\n/add_prev - �������� ������� ����� �������\n/copy_list - ����������� ������\n/end - ���������� ���������\n\n");
	while (1)
	{
		scanf("%29s", str);
		fflush(stdin);
			if (!strcmp(str, "/to_next"))
				to_next(&ls);
			else
				if (!strcmp(str, "/to_prev"))
					to_prev(&ls);
				else
					if (!strcmp(str, "/del_current"))
						del_current(&ls);
					else
						if (!strcmp(str, "/print_list"))
							print_list(ls);
						else
							if (!strcmp(str, "/end"))
								break;
							else
								if (!strcmp(str, "/add_next"))
								{
									printf("������� ������� ");
									scanf("%i", &a);
									add_next(&ls,a);
								}
								else
									if (!strcmp(str, "/add_prev"))
									{
										printf("������� ������� ");
										scanf("%i", &a);
										add_prev(&ls, a);
									}
									else
										if (!strcmp(str, "/copy_list"))
										{
											copy_list(ls, &cp);
											print_list(cp);
										}
										else
											printf("������ �����\n");
	}

	return 0;
}
