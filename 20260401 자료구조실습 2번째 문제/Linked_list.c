#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "linked_list.h"

void list_insert(ListNode* head, Element e)
{
    ListNode* newnode;

    newnode = (ListNode*)malloc(sizeof(ListNode));
    if (newnode == NULL) {
        printf("Memory allocation error\n");
        return;
    }

    newnode->data = e;
    newnode->link = head->link;
    head->link = newnode;
}

ListNode* list_search(ListNode* head, Element e)
{
    ListNode* p;

    p = head->link;
    while (p != NULL) {
        if (p->data == e)
            return p;
        p = p->link;
    }

    return NULL;
}

void list_delete(ListNode* head, Element e)
{
    ListNode* p, * temp;

    p = head;
    while (p->link != NULL) {
        if (p->link->data == e) {
            temp = p->link;
            p->link = temp->link;
            free(temp);
            return;
        }
        p = p->link;
    }

    printf("\n%c is not in the list \n", e);
}

bool list_empty(ListNode* head)
{
    if (head->link == NULL)
        return true;
    else
        return false;
}

void list_show(ListNode* head)
{
    ListNode* p;

    if (list_empty(head)) {
        printf("\nList is empty.\n");
        return;
    }

    p = head->link;
    printf("\n");
    while (p != NULL) {
        printf("%c ", p->data);
        p = p->link;
    }
    printf("\n");
}

void main()
{
    char c, e;
    ListNode* head, * p;

    /* dummy head node */
    head = (ListNode*)malloc(sizeof(ListNode));
    head->data = NULL;
    head->link = NULL;

    printf("******************** Command ********************\n");
    printf("+<c> : Insert c, -<c> : Delete c\n");
    printf("?<c> : Search c, S : Show, Q : Quit\n");
    printf("*************************************************\n");

    while (1) {
        printf("\nCommand > ");
        c = getchar();
        c = toupper(c);
        printf("\n");

        switch (c) {
        case '+':
            e = getchar();
            list_insert(head, e);
            break;

        case '-':
            e = getchar();
            list_delete(head, e);
            break;

        case '?':
            e = getchar();
            p = list_search(head, e);
            if (p) {
                printf("\n%c is in the list. \n", e);
                printf("Node address = %p, data = %c, link = %p \n",
                    p, p->data, p->link);
            }
            else
                printf("\n%c is not in the list \n", e);
            break;

        case 'S':
            list_show(head);
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