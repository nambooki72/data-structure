#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void list_insert(ListNode* head, Element e) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = e;
	newNode->link = head->link;
	head->link = newNode;
}

ListNode* list_search(ListNode* head, Element e) {
	ListNode* p = head->link; 

	while (p != NULL) {
		if (p->data == e)
			return p;
		p = p->link;
	}
	return NULL;
}

void list_delete(ListNode* head, Element e) {
	ListNode* p = head->link;
	ListNode* prev = head;

	while (p != NULL) {
		if (p->data == e) {
			prev->link = p->link;
			free(p);
			return;
		}
		prev = p;
		p = p->link;
	}
}

bool list_empty(ListNode* head) {
	return (head->link == NULL);
}

void list_show(ListNode* head)
{
	ListNode* p = head->link;

	printf("List: ");
	while (p != NULL) {
		printf("%c -> ", p->data);
		p = p->link;
	}
	printf("NULL\n");
}


void main()
{
	char	c, e;
	ListNode* head, * p;

	// dummy head ³ëµå 
	head = (ListNode*)malloc(sizeof(ListNode));
	head->data = NULL;
	head->link = NULL;

	while (1) {
		printf("\nCommand> ");
		c = getchar();
		c = toupper(c);
		switch (c) {
		case '+':
			e = getchar();
			list_insert(head, e); break;
		case '-':
			e = getchar();
			list_delete(head, e); break;
		case '?':
			e = getchar();
			p = list_search(head, e);
			if (p) {
				printf("\n %c is in the list. \n", e);
				printf(" Node address = %p, data = %c, link = %p \n",
					p, p->data, p->link);
			}
			else printf("\n %c is not in the list \n", e);
			break;
		case 'S':
			list_show(head); break;
		case 'Q':
			printf(¡°\n¡±);
			exit(1);
		default:  break;
		}
		while (getchar() != ¡®\n¡¯);
	}
}
