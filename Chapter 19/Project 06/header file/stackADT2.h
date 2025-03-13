#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h>

typedef int Item;
typedef struct queue_type* Queue;

Queue create(int size);
void destroy(Queue q);
void enqueue(Queue q, Item data);
Item dequeue(Queue q);
bool is_empty(const Queue q);
bool is_full(const Queue q);
Item peek(const Queue q);

#endif