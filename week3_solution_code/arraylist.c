#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"

void main()
{
	char	c;

	printf("******************** Command *******************\n");
	printf("+<c>: Insert c, -<c>: Delete c, \n");
	printf("E: ListEmpty, F: ListFull, S: ListShow, Q: Quit \n");
	printf("************************************************\n");

	while (1) {
		printf("\nCommand> ");
		c = getch();
		getch();
		putch(c);
		c = toupper(c);

		switch (c) {
		case '+':
			c = getch();
			getch();
			putch(c);
			list_insert(c);
			break;
		case '-':
			c = getch();
			getch();
			putch(c);
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
	}
}

void list_insert(Element e)
{
	if (list_full()) {	// list full 
		printf("\nList is full !!! \n");
		return;
	}

	List[size] = e;    // 새로운 element를 마지막에 삽입
	size++;            // 크기 값을 1 증가
}

void list_delete(Element e)
{
	int	i;

	if (list_empty()) {	  // list empty 
		printf("\nList is empty !!! \n");
		return;
	}

	i = 0;
	while ((List[i] != e) && (i<size)) i++;  	// 지울 자료 찾기 
	if (i == size) {
		printf("\nData doea not exist !!! \n ");
		return;
	}

	while (i<(size - 1)) {
		List[i] = List[i + 1];   // 자료 이동
		i++;
	}
	size--;                    // 크기 값을 1 감소
}

boolean list_empty()
{
	if (size == 0)
		return true;      // 리스트가 비어 있으면 true 
	else
		return false;
}

boolean list_full()
{
	if (size == MaxSize)
		return true;      // 리스트가 가득차 있으면 true 
	else
		return false;
}

void list_show()
{
	int	i;

	if (list_empty()) {
		printf("\nList is Empty !!! \n");
		return;
	}
	printf("\n");
	for (i = 0; i<size; i++)
		printf("%c ", List[i]);	    // 리스트에 있는 값 출력
	printf("\n");
}


