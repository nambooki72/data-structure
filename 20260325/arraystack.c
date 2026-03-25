#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "arraystack.h"

int main(void)
{
    char c, e;

    printf("********** Command **********\n");
    printf("+<c> : push c, ");
    printf("- : pop,\n");
    printf(" S : show, ");
    printf("Q : quit\n");
    printf("*****************************\n");

    while (1) {
        printf("\nCommand > ");

        c = getchar();
        c = toupper(c);

        switch (c) {
        case '+':
            e = getchar();
            push(e);
            break;

        case '-':
            e = pop();
            if (e != 0)
                printf("%c\n", e);
            break;

        case 'S':
            stack_show();
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

void push(Element e)
{
    if (top >= MAX_SIZE - 1) {
        printf("Stack is full.\n");
        return;
    }

    top++;
    stack[top] = e;
}

Element pop()
{
    Element e;

    if (top < 0) {
        printf("Stack is empty.\n");
        return 0;
    }

    e = stack[top];
    top--;
    return e;
}

void stack_show()
{
    int i;

    if (top < 0) {
        printf("Stack is empty.\n");
        return;
    }

    for (i = 0; i <= top; i++) {
        printf("%c ", stack[i]);
    }
    printf("\n");
}