#ifndef STACK_ADT_2_H__
#define STACK_ADT_2_H__

#include <stdbool.h>

#define STACK_SIZE 100

typedef struct {
    int* contents;
    int top;
    int size;
} Stack;

void make_empty(Stack* s);
bool is_empty(const Stack* s);
bool is_full(const Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
void stack_overflow();
void stack_underflow();

#endif