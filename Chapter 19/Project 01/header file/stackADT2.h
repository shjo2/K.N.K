#ifndef STACK_ADT_2_H__
#define STACK_ADT_2_H__

#include <stdbool.h>

#define STACK_SIZE 100

typedef struct {
    char contents[STACK_SIZE];
    int top;
} Stack;

void make_empty(Stack* s);
bool is_empty(const Stack* s);
bool is_full(const Stack* s);
void push(Stack* s, char ch);
char pop(Stack* s);
char peek(const Stack* s);
void stack_overflow(void);
void stack_underflow(void);

#endif