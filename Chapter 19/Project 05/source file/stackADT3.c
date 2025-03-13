#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct queue_type {
    Item contents[QUEUE_SIZE];
    int front;
    int rear;
    int size;
};

Queue create(void) {
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL) {
        printf("Error: malloc failed in create\n");
        exit(EXIT_FAILURE);
    }

    q->front = 0;
    q->rear = 0;
    q->size = 0;
    return q;
}

void destroy(Queue q) {
    free(q);
}

void enqueue(Queue q, Item data) {
    if (is_full(q)) {
        printf("Error: Queue is full\n");
        exit(EXIT_FAILURE);
    }

    q->contents[q->rear] = data;
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    q->size++;
}

Item dequeue(Queue q) {
    if (is_empty(q)) {
        printf("Error: Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    Item data = q->contents[q->front];
    q->front = (q->front + 1) % QUEUE_SIZE;
    q->size--;
    return data;
}

bool is_empty(const Queue q) {
    return q->size == 0;
}

bool is_full(const Queue q) {
    return q->size == QUEUE_SIZE;
}

Item peek(const Queue q) {
    if (is_empty(q)) {
        printf("Error: Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    return q->contents[q->front];
}