#include <stdio.h>
#include <stdlib.h>

#define Element char

typedef struct ListNode {
	Element data;
	struct ListNode* link;
} ListNode;

// 리스트 출력 함수
void list_show(ListNode* head) {
	ListNode* p = head->link;  // dummy head 다음부터 출력
	while (p != NULL) {
		printf("%c ", p->data);
		p = p->link;
	}
}

// 리스트 끝에 노드 삽입
void list_insert_last(ListNode* head, Element e) {
	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
	new_node->data = e;
	new_node->link = NULL;

	ListNode* p = head;
	while (p->link != NULL)
		p = p->link;

	p->link = new_node;
}

// 정렬된 두 리스트를 합병
ListNode* ordered_list_merge(ListNode* head1, ListNode* head2) {
	ListNode* p1 = head1->link;
	ListNode* p2 = head2->link;
	ListNode* merged = (ListNode*)malloc(sizeof(ListNode));
	merged->link = NULL;
	ListNode* p = merged;

	while (p1 != NULL && p2 != NULL) {
		if (p1->data < p2->data) {
			p->link = p1;
			p1 = p1->link;
		}
		else {
			p->link = p2;
			p2 = p2->link;
		}
		p = p->link;
	}
	// 남은 노드 연결
	if (p1 != NULL) p->link = p1;
	else if (p2 != NULL) p->link = p2;

	return merged;
}
int main(void) {
	ListNode* head1 = (ListNode*)malloc(sizeof(ListNode));
	head1->data = NULL;
	head1->link = NULL;

	ListNode* head2 = (ListNode*)malloc(sizeof(ListNode));
	head2->data = NULL;
	head2->link = NULL;

	list_insert_last(head1, 'a');
	list_insert_last(head1, 'c');
	list_insert_last(head1, 'e');

	list_insert_last(head2, 'b');
	list_insert_last(head2, 'd');
	list_insert_last(head2, 'f');

	printf("리스트 1 : ");
	list_show(head1);
	printf("\n");

	printf("리스트 2 : ");
	list_show(head2);
	printf("\n");

	ListNode* merged_list = ordered_list_merge(head1, head2);

	printf("합병된 리스트 : ");
	list_show(merged_list);
	printf("\n");

	return 0;
}
