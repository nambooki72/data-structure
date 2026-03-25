#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "eval_postfix.h"

int main(void)
{
    char exp[100];
    int result;

    while (1) {
        printf("\nInput postfix expression: ");
        scanf("%s", exp);

        result = eval_postfix(exp);

        if (err_check == false)
            printf("Result = %d\n\n", result);
    }

    return 0;
}

void push(int e)
{
    if (top >= MAX_SIZE - 1) {
        err_check = true;
        printf("Stack is full.\n");
        return;
    }

    stack[++top] = e;
}

int pop()
{
    if (top < 0) {
        err_check = true;
        printf("Stack is empty.\n");
        return 0;
    }

    return stack[top--];
}

int eval_postfix(char* exp)
{
    int i = 0;
    char token;
    int op1, op2;
    int value = 0;

    top = -1;
    err_check = false;

    while (exp[i] != '\0') {
        token = exp[i];

        if (is_number(token)) {
            push(token - '0');
        }
        else if (is_op(token)) {
            op2 = pop();
            op1 = pop();

            if (err_check == true)
                return 0;

            switch (token) {
            case '+':
                push(op1 + op2);
                break;

            case '-':
                push(op1 - op2);
                break;

            case '*':
                push(op1 * op2);
                break;

            case '/':
                if (op2 == 0) {
                    err_check = true;
                    printf("Error: divide by 0.\n");
                    return 0;
                }
                push(op1 / op2);
                break;
            }
        }

        i++;
    }

    value = pop();
    return value;
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
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    else
        return false;
}