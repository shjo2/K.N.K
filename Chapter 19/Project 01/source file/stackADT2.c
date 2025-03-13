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
    return s->top == STACK_SIZE - 1;
}

void push(Stack* s, char ch)
{
    if (is_full(s)) {
        stack_overflow();
        return;
    }
    s->contents[++s->top] = ch;
}

char pop(Stack* s)
{
    if (is_empty(s)) {
        stack_underflow();
        return '\0';
    }
    return s->contents[s->top--];

}

char peek(const Stack* s) {
    if (is_empty(s)) {
        return '\0';
    }
    return s->contents[s->top];
}

void stack_overflow(void)
{
    fprintf(stderr, "Stack overflow\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
    fprintf(stderr, "Stack underflow\n");
    exit(EXIT_FAILURE);
}