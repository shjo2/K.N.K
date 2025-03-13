#include <stdio.h>
#include "queueADT.h"

int main() {
    Queue q = create(5);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printf("Dequeue from q: %d\n", dequeue(q));
    printf("Peek: %d\n", peek(q));

    printf("Dequeue from q: %d\n", dequeue(q));
    printf("Peek: %d\n", peek(q));

    printf("Dequeue from q: %d\n", dequeue(q));
    printf("Peek: %d\n", peek(q));

    destroy(q);

    return 0;
}