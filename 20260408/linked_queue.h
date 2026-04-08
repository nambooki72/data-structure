#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#define boolean unsigned char
#define true 1
#define false 0

typedef char Element;

typedef struct QueueNode {
    Element item;
    struct QueueNode* link;
} QueueNode;

extern QueueNode* front;
extern QueueNode* rear;

void addq(Element e);
Element deleteq();
void queue_show();
boolean is_queue_empty();

#endif