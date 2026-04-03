#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define Element char

typedef struct ListNode {
	Element	data;
	struct ListNode* link;
} ListNode;

ListNode* ordered_list_merge(ListNode* head1, ListNode* head2);
void list_insert_last(ListNode* head, Element e);