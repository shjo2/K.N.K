#ifndef STACKADT3_H
#define STACKADT3_H

#include <stdbool.h>

struct node {
    void* data;
    struct node* next;
};

typedef struct stack_type* Stack;

Stack create(void);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(const Stack s);
bool is_full(const Stack s);
void push(Stack s, void* data);
void* pop(Stack s);
int length(const Stack s);

#endif