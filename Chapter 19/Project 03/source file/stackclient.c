#include <stdio.h>
#include "stackADT3.h"

int main() {
	Stack stack = create();

	printf("Initial length: %d\n", length(stack));

	push(stack, 10);
	printf("Length after push(10): %d\n", length(stack));
	push(stack, 20);
	printf("Length after push(20): %d\n", length(stack));
	push(stack, 30);
	printf("Length after push(30): %d\n", length(stack));

	Item value = pop(stack);
	printf("Popped value: %d, Length after pop(): %d\n", value, length(stack));

	make_empty(stack);
	printf("Length after make_empty(): %d\n", length(stack));

	destroy(stack);
}