#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "arrayqueue.h"

void addq(Element e)
{
    if ((rear + 1) % MAX_SIZE == front && is_empty == false) {
        printf("Queue is full.\n");
        return;
    }

    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = e;
    is_empty = false;
}

Element deleteq()
{
    Element e;

    if (is_empty == true) {
        printf("Queue is empty.\n");
        return '\0';
    }

    front = (front + 1) % MAX_SIZE;
    e = queue[front];

    if (front == rear)
        is_empty = true;

    return e;
}

void queue_show()
{
    int i;

    if (is_empty == true) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue : ");

    i = (front + 1) % MAX_SIZE;
    while (1) {
        printf("%c ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

void main()
{
    char c, e;

    is_empty = true;

    printf("*************** Command ***************\n");
    printf("+<c> : AddQ c,  - : DeleteQ\n");
    printf("S : Show, Q : Quit\n");
    printf("****************************************\n");

    while (1) {
        printf("\nCommand > ");
        c = getchar();
        c = toupper(c);
        printf("\n");

        switch (c) {
        case '+':
            e = getchar();
            addq(e);
            break;

        case '-':
            e = deleteq();
            if (e != '\0')
                printf("%c\n", e);
            break;

        case 'S':
            queue_show();
            break;

        case 'Q':
            printf("\n");
            exit(1);

        default:
            break;
        }

        while (getchar() != '\n');
    }
}