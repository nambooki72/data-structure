#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "ordered_list_merge.h"

ListNode* create_node(Element e)
{
    ListNode* newnode;

    newnode = (ListNode*)malloc(sizeof(ListNode));
    if (newnode == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }

    newnode->data = e;
    newnode->link = NULL;

    return newnode;
}

void list_insert_last(ListNode* head, Element e)
{
    ListNode* p;
    ListNode* newnode;

    newnode = create_node(e);

    p = head;
    while (p->link != NULL)
        p = p->link;

    p->link = newnode;
}

void list_show(ListNode* head)
{
    ListNode* p;

    p = head->link;
    while (p != NULL) {
        printf("%c ", p->data);
        p = p->link;
    }
    printf("\n");
}

ListNode* ordered_list_merge(ListNode* head1, ListNode* head2)
{
    ListNode* p1;
    ListNode* p2;
    ListNode* head3;

    head3 = (ListNode*)malloc(sizeof(ListNode));
    if (head3 == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }

    head3->link = NULL;

    p1 = head1->link;
    p2 = head2->link;

    while (p1 != NULL && p2 != NULL) {
        if (p1->data <= p2->data) {
            list_insert_last(head3, p1->data);
            p1 = p1->link;
        }
        else {
            list_insert_last(head3, p2->data);
            p2 = p2->link;
        }
    }

    while (p1 != NULL) {
        list_insert_last(head3, p1->data);
        p1 = p1->link;
    }

    while (p2 != NULL) {
        list_insert_last(head3, p2->data);
        p2 = p2->link;
    }

    return head3;
}

int main(void)
{
    ListNode* head1;
    ListNode* head2;
    ListNode* head3;

    head1 = (ListNode*)malloc(sizeof(ListNode));
    head2 = (ListNode*)malloc(sizeof(ListNode));

    if (head1 == NULL || head2 == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }

    head1->link = NULL;
    head2->link = NULL;

    list_insert_last(head1, 'a');
    list_insert_last(head1, 'c');
    list_insert_last(head1, 'e');

    list_insert_last(head2, 'b');
    list_insert_last(head2, 'd');
    list_insert_last(head2, 'f');

    printf("리스트 1 : ");
    list_show(head1);

    printf("리스트 2 : ");
    list_show(head2);

    head3 = ordered_list_merge(head1, head2);

    printf("합병된 리스트 : ");
    list_show(head3);

    return 0;
}