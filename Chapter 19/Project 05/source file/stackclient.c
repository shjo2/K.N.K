#include <stdio.h>
#include "queueADT.h"

int main() {
    Queue q1 = create();
    Queue q2 = create();

    enqueue(q1, 10);
    enqueue(q2, 20);

    printf("q1 front: %d\n", peek(q1));
    printf("Dequeue from q1: %d\n", dequeue(q1));
    printf("q2 front: %d\n", peek(q2));
    printf("Dequeue from q2: %d\n", dequeue(q2));

    enqueue(q1, 30);
    enqueue(q1, 40);

    printf("q1 is empty: %s\n", is_empty(q1) ? "true" : "false");
    printf("q2 is empty: %s\n", is_empty(q2) ? "true" : "false");

    destroy(q1);
    destroy(q2);

    return 0;
}