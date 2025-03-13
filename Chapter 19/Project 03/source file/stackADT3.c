#include <stdio.h>
#include <stdlib.h>
#include "stackADT3.h"

struct stack_type {
    struct node* top;
    int len;
};

Stack create(void) {
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL) {
        printf("Error: malloc failed in create\n");
        exit(EXIT_FAILURE);
    }
    s->top = NULL;
    s->len = 0;
    return s;
}

void destroy(Stack s) {
    make_empty(s);
    free(s);
}

void make_empty(Stack s) {
    while (!is_empty(s)) {
        pop(s);
    }
    s->len = 0;
}

bool is_empty(const Stack s) {
    return s->top == NULL;
}

bool is_full(const Stack s) {
    return false;
}

void push(Stack s, Item i) {
    struct node* new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: malloc failed in push\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = i;
    new_node->next = s->top;
    s->top = new_node;
    s->len++;
}

Item pop(Stack s) {
    struct node* old_top;
    Item i;

    if (is_empty(s)) {
        printf("Error: stack underflow in pop\n");
        exit(EXIT_FAILURE);
    }

    old_top = s->top;
    i = old_top->data;
    s->top = old_top->next;
    s->len--;
    free(old_top);
    return i;
}

int length(const Stack s) {
    return s->len;
}