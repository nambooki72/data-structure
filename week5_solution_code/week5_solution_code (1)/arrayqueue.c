#include <stdio.h>
#include "arrayqueue.h"

void addq(Element e) {
	if ((rear + 1) % MAX_SIZE == front) {
		printf("\nQueue is full.\n");
		return;
	}
	rear = (rear + 1) % MAX_SIZE;
	queue[rear] = e;
}

Element deleteq() {
	if (front == rear) {
		printf("\nQueue is empty.\n");
		return '\0'; // 공백 문자 반환
	}
	front = (front + 1) % MAX_SIZE;
	return queue[front];
}

void queue_show() {
	int i = (front + 1) % MAX_SIZE;
	printf("  ");
	while (i != (rear + 1) % MAX_SIZE) {
		printf("%c ", queue[i]);
		i = (i + 1) % MAX_SIZE;
	}
	printf("\n");
}

void main() {

	char	c, e;
	printf("************Command************\n");
	printf("+<c> : AddQ c,  - : DeleteQ,\n");
	printf("S : Show, Q : Quit\n");
	printf("*******************************\n\n");
	while (1) {
		printf("Command> ");
		c = getchar();
		c = toupper(c);
		switch (c) {
		case '+':
			e = getchar();
			addq(e);
			break;
		case '-':
			e = deleteq();
			if (e != NULL)
				printf("%c\n", e);
			break;
		case 'S':
			queue_show();
			break;
		case 'Q':
			printf("\n");
			exit(1);
		default: break;
		}
		while (getchar() != '\n');
	}
}