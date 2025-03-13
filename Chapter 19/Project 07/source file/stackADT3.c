#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

Queue create(void) {
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL) {
        printf("Error: malloc failed in create\n");
        exit(EXIT_FAILURE);
    }
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

void destroy(Queue q) {
    while (!is_empty(q)) {
        dequeue(q);
    }
    free(q);
}

// 큐에 데이터 추가
void enqueue(Queue q, Item data) {
    Node new_node = malloc(sizeof(struct node));

    if (new_node == NULL) {
        printf("Error: malloc failed in enqueue\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = data;
    new_node->next = NULL;

    if (is_empty(q)) {
        q->front = new_node;
        q->rear = new_node;
    }
    else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
    q->size++;
}

Item dequeue(Queue q) {
    if (is_empty(q)) {
        printf("Error: Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    Node temp = q->front;
    Item value = temp->data;
    q->front = q->front->next;
    q->size--;
    free(temp);

    if (q->front == NULL) {
        q->rear = NULL;
    }

    return value;
}

bool is_empty(const Queue q) {
    return q->front == NULL;
}

bool is_full(const Queue q) {
    return false;
}

Item peek(const Queue q) {
    if (is_empty(q)) {
        printf("Error: Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    return q->front->data;
}