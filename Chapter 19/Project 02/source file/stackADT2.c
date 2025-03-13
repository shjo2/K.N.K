#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stackADT2.h"

void make_empty(Stack* s)
{
    s->top = -1;
}

bool is_empty(const Stack* s)
{
    return s->top == -1;
}

bool is_full(const Stack* s)
{
    return s->top == s->size - 1;
}
void push(Stack* s, int value)
{
    if (is_full(s))
        stack_overflow();
    else
        s->contents[++s->top] = value;
}
int pop(Stack* s)
{
    int value;
    if (is_empty(s))
        stack_underflow();
    else {
        value = s->contents[s->top--];
        return value;
    }
}

void stack_overflow() {
    printf("stack overflow\n");
    exit(1);
}

void stack_underflow() {
    printf("stack underflow\n");
    exit(1);
}