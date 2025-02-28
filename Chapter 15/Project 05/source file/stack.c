#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void make_empty(Stack* s)
{
    s->top = 0;
}

bool is_empty(const Stack* s)
{
    return s->top == 0;
}

bool is_full(const Stack* s)
{
    return s->top == STACK_SIZE;
}

void push(Stack* s, double i)
{
    if (is_full(s))
        stack_overflow();
    else
        s->contents[s->top++] = i;
}

double pop(Stack* s)
{
    if (is_empty(s))
        stack_underflow();
    else
        return s->contents[--s->top];
}

void stack_overflow(void)
{
    printf("Expression is too complex\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
    printf("Not enough operands in expression\n");
    exit(EXIT_FAILURE);
}