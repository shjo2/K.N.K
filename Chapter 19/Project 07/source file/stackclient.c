#include <stdio.h>
#include "queueADT.h"

int main() {
    Queue q = create();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printf("Dequeued: %d\n", dequeue(q));
    printf("Peek: %d\n", peek(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));

    destroy(q);

    return 0;
}
