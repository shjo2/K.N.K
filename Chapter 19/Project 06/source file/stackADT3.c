#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct queue_type {
    Item* data;
    int front;
    int rear;
    int size;
    int capacity;
};

Queue create(int size) {
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL) {
        printf("Error: malloc failed in create\n");
        exit(EXIT_FAILURE);
    }

    q->data = malloc(size * sizeof(Item));
    if (q->data == NULL) {
        printf("Error: malloc failed for data\n");
        free(q);
        exit(EXIT_FAILURE);
    }
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    q->capacity = size;
    return q;
}

void destroy(Queue q) {
    free(q->data);
    free(q);
}

void enqueue(Queue q, Item data) {
    if (is_full(q)) {
        printf("Error: Queue is full\n");
        exit(EXIT_FAILURE);
    }

    q->data[q->rear] = data;
    q->rear = (q->rear + 1) % q->capacity;
    q->size++;
}

Item dequeue(Queue q) {
    if (is_empty(q)) {
        printf("Error: Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    Item data = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return data;
}

bool is_empty(const Queue q) {
    return q->size == 0;
}

bool is_full(const Queue q) {
    return q->size == q->capacity;
}

Item peek(const Queue q) {
    if (is_empty(q)) {
        printf("Error: Queue is emtpy\n");
        exit(EXIT_FAILURE);
    }

    return q->data[q->front];
}