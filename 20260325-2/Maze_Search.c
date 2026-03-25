#include "maze_search.h"

int main(void)
{
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

        push_loc(&s, r - 1, c);
        push_loc(&s, r + 1, c);
        push_loc(&s, r, c - 1);
        push_loc(&s, r, c + 1);

        stack_print(&s);
        printf("\n\n");

        if (is_empty(&s)) {
            printf("실패\n");
            return 0;
        }
        else {
            here = pop(&s);
        }
    }

    printf("성공\n");
    return 0;
}

void init_stack(Stack* s)
{
    s->top = -1;
}

int is_empty(Stack* s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

void push(Stack* s, Element item)
{
    if (s->top >= MAX_SIZE - 1) {
        printf("Stack is full.\n");
        return;
    }

    s->data[++(s->top)] = item;
}

Element pop(Stack* s)
{
    Element e = { -1, -1 };

    if (is_empty(s)) {
        printf("Stack is empty.\n");
        return e;
    }

    return s->data[(s->top)--];
}

void push_loc(Stack* s, int r, int c)
{
    Element temp;

    if (r < 0 || r >= MAX_SIZE || c < 0 || c >= MAX_SIZE)
        return;

    if (maze[r][c] == '0' || maze[r][c] == 'x') {
        temp.r = r;
        temp.c = c;
        push(s, temp);
    }
}

void maze_print(char maze[][MAX_SIZE])
{
    int i, j;

    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

void stack_print(Stack* s)
{
    int i;

    printf("Current Stack: ");
    if (is_empty(s)) {
        printf("(empty)");
        return;
    }

    for (i = 0; i <= s->top; i++) {
        printf("(%d,%d) ", s->data[i].r, s->data[i].c);
    }
}