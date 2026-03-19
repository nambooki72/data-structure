#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"

int main(void)
{
	char	c;

	printf("******************** Command *******************\n");
	printf("+<c>: Insert c, -<c>: Delete c, \n");
	printf("E: ListEmpty, F: ListFull, S: ListShow, Q: Quit \n");
	printf("************************************************\n");

	while (1) {
		printf("\nCommand> ");
		c = getchar();
		c = toupper(c);
		printf("\n");

		switch (c) {
		case '+':
			c = getchar();
			list_insert(c);
			break;
		case '-':
			c = getchar();
			list_delete(c);
			break;
		case 'E':
			if (list_empty()) printf("\nTRUE \n");
			else printf("\nFALSE \n");
			break;
		case 'F':
			if (list_full()) printf("\nTRUE \n");
			else printf("\nFALSE \n");
			break;
		case 'S':
			list_show();
			break;
		case 'Q':
			printf("\n");
			exit(1);
		default:
			break;
		}
		while (getchar() != '\n');
	}
	return 0;
}



boolean list_full()
{
	if (size == MaxSize)
		return true;      // 리스트가 가득 차 있으면 true 
	else
		return false;
}


void list_insert(Element e)
{
	if (list_full())
	{
		printf("List is Full\n");
		return;
	}

	List[size] = e;
	size++;
}


void list_delete(Element e)
{
	int i, j;

	if (list_empty())
	{
		printf("List is Empty\n");
		return;
	}

	for (i = 0; i < size; i++)
	{
		if (List[i] == e)
		{
			for (j = i; j < size - 1; j++)
			{
				List[j] = List[j + 1];
			}

			size--;
			return;
		}
		else
		{
			printf("Data does not exist!!! \n");
		}
		break;
	}
}


boolean list_empty()
{
	if (size == 0)
		return true;
	else
		return false;
}


void list_show()
{
	int i;

	if (list_empty())
	{
		printf("List is Empty\n");
		return;
	}

	printf("List : ");

	for (i = 0; i < size; i++)
	{
		printf("%c ", List[i]);
	}

	printf("\n");
}