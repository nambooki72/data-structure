#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "eval_postfix.h"

void main()
{
	char exp[100];  // postfix expression
	int result;

	while (1) {
		printf("\n Input postfix expression: ");
		scanf("%s", exp);

		result = eval_postfix(exp);
		printf("\n result = %d \n\n", result);
	}
}

int eval_postfix(char* exp)
{
	char c;
	int i, length, num1, num2;

	length = strlen(exp);

	for (i = 0; i < length; i++) {
		c = exp[i];

		if (is_number(c)) {
			num1 = c - '0';
			push(num1);
		}
		else if (is_op(c)) {
			num2 = pop();
			num1 = pop();
			switch (c) {
			case '+':
				push(num1 + num2); break;
			case '-':
				push(num1 - num2); break;
			case '*':
				push(num1 * num2); break;
			case '/':
				if (num2 == 0) {
					printf(" \n devided by 0 error\n");
					exit(1);
				}
				else {
					push(num1 / num2);
				}
				break;
			}
		}
		else {
			printf("\n Illegal character !!! \n");
			exit(1);
		}
	}

	if (top != 0) {
		printf("\n Illegal expression !!! \n");
		exit(1);
	}
	else {
		return pop();
	}
}

boolean is_number(char c)
{
	if (('0' <= c) && (c <= '9'))
		return true;
	else
		return false;
}

boolean is_op(char c)
{
	if ((c == '+') || (c == '-') || (c == '*') || (c == '/'))
		return true;
	else
		return false;
}

void push(int e)
{
	if (top >= MAX_SIZE - 1) {
		printf("\n Stack is full !!! \n");
		return;
	}
	stack[++top] = e;
}

int pop()
{
	if (top == -1) {
		printf("\n Stack is empty !!! \n");
		return NULL;
	}
	return stack[top--];
}



