#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define STACK_SIZE 100

typedef struct {
    double contents[STACK_SIZE];
    int top;
} Stack;

void make_empty(Stack* s);
bool is_empty(const Stack* s);
bool is_full(const Stack* s);
void push(Stack* s, double i);
double pop(Stack* s);
void stack_overflow(void);
void stack_underflow(void);

#endif