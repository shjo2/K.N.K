#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h>

#define QUEUE_SIZE 100

typedef int Item;
typedef struct queue_type* Queue;

Queue create(void);
void destroy(Queue q);
void enqueue(Queue q, Item data);
Item dequeue(Queue q);
bool is_empty(const Queue q);
bool is_full(const Queue q);
Item peek(const Queue q);

#endif