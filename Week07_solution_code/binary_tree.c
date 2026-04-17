#include<stdio.h>
#include<stdlib.h>
#include "binary_tree.h"

void main()
{
	char		c;
	int		n;
	tree_pointer	t;

	t = build_simple_tree();

	printf("************* Command ************\n");
	printf("C: Count tree, A:  Sum tree data    \n");
	printf("H: Height of tree, S: Show preorder \n");
	printf("F: Free tree, Q: Quit              \n");
	printf("**********************************\n");

	while (1) {
		printf("\nCommand> ");
		c = getch();
		putch(c);
		c = toupper(c);
		switch (c) {
		case 'C':
			n = bt_count(t);
			printf("\n Total number of node = %d \n", n);
			break;
		case 'A':
			n = bt_sum(t);
			printf("\n Sum of tree data = %d \n", n);
			break;
		case 'H':
			n = bt_height(t);
			printf("\n Height of tree = %d \n", n);
			break;
		case 'S':
			printf("\n");
			bt_show_preorder(t);
			printf("\n");
			break;
		case 'F':
			printf("\n");
			bt_free(t);
		case 'Q':
			printf("\n");
			exit(1);
		default: break;
		}
	}
}

// 앞에 정의된 9개의 노드를 갖는 binary tree를 생성
tree_pointer build_simple_tree() {
	tree_pointer n1, n2, n3, n4, n5, n6, n7, n8, n9;

	n1 = (tree_pointer)malloc(sizeof(tree_node));
	n2 = (tree_pointer)malloc(sizeof(tree_node));
	n3 = (tree_pointer)malloc(sizeof(tree_node));
	n4 = (tree_pointer)malloc(sizeof(tree_node));
	n5 = (tree_pointer)malloc(sizeof(tree_node));
	n6 = (tree_pointer)malloc(sizeof(tree_node));
	n7 = (tree_pointer)malloc(sizeof(tree_node));
	n8 = (tree_pointer)malloc(sizeof(tree_node));
	n9 = (tree_pointer)malloc(sizeof(tree_node));

	n1->data = 10;
	n1->left = n2;
	n1->right = n3;

	n2->data = 20;
	n2->left = n4;
	n2->right = n5;

	n3->data = 30;
	n3->left = n6;
	n3->right = n7;

	n4->data = 40;
	n4->left = NULL;
	n4->right = n9;

	n5->data = 50;
	n5->left = NULL;
	n5->right = NULL;

	n6->data = 60;
	n6->left = n8;
	n6->right = NULL;

	n7->data = 70;
	n7->left = NULL;
	n7->right = NULL;

	n8->data = 80;
	n8->left = NULL;
	n8->right = NULL;

	n9->data = 90;
	n9->left = NULL;
	n9->right = NULL;

	return n1;
}

// 트리의 노드수를 계산
int bt_count(tree_pointer ptr) {
	int count;

	if (ptr == NULL) return 0;
	count = 1 + bt_count(ptr->left) + bt_count(ptr->right);
	return count;

}
// 트리의 데이터 합을 계산
int bt_sum(tree_pointer ptr) {
	int sum;

	if (ptr == NULL) return 0;
	sum = ptr->data + bt_sum(ptr->left) + bt_sum(ptr->right);
	return sum;

}
// 트리의 높이를 계산
int bt_height(tree_pointer ptr) {
	int height = 1;

	if (ptr == NULL) return 0;
	height = 1 + max(bt_height(ptr->left), bt_height(ptr->right));
	return height;
}
// 트리의 내용을 preorder로 출력
void bt_show_preorder(tree_pointer ptr) {
	if (ptr == NULL) return;
	printf("%3d", ptr->data);
	bt_show_preorder(ptr->left);
	bt_show_preorder(ptr->right);

}
// 트리의 모든 노드를 시스템에 반환(free)
void bt_free(tree_pointer ptr) {
	if (ptr == NULL) return;
	bt_free(ptr->left);
	bt_free(ptr->right);
	printf("free node with item %d\n", ptr->data);
	free(ptr);
}
