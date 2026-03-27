#include"maze_search.h"

void init_stack(Stack* s) {
	s->top = -1;
}

int is_empty(Stack* s) {
	return s->top == -1;
}

void push(Stack* s, Element item) {
	if (s->top < MAX_SIZE * MAX_SIZE - 1)
		s->data[++s->top] = item;
}

Element pop(Stack* s) {
	if (!is_empty(s))
		return s->data[s->top--];
	Element error = { -1, -1 };
	return error;
}

void push_loc(Stack* s, int r, int c) {
	if (r >= 0 && r < MAX_SIZE && c >= 0 && c < MAX_SIZE && (maze[r][c] == '0' || maze[r][c] == 'x')) {
		Element item = { r, c };
		push(s, item);
	}
}

void maze_print(char maze[][MAX_SIZE]) {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			printf("%c ", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void stack_print(Stack* s) {
	printf("Stack: ");
	for (int i = 0; i <= s->top; i++) {
		printf("(%d, %d) ", s->data[i].r, s->data[i].c);
	}
	printf("\n");
}


int main(void) {
	int r, c;
	Stack s;
	Element here, entry = { 1, 0 };
	here = entry;

	init_stack(&s);
	while (maze[here.r][here.c] != 'x') {
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		maze_print(maze);

		push_loc(&s, r - 1, c); push_loc(&s, r + 1, c);
		push_loc(&s, r, c - 1);	push_loc(&s, r, c + 1);
		stack_print(&s);
		printf("\n\n");
		if (is_empty(&s)) {
			printf("실패\n");
			return;
		}
		else
			here = pop(&s);
	}
	printf("성공\n");
}
