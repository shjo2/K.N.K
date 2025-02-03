#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

typedef struct {
    char contents[STACK_SIZE];
    int top;
} Stack;

void make_empty(Stack* s);
bool is_empty(const Stack* s);
bool is_full(const Stack* s);
char push(Stack* s, int i);
char pop(Stack* s);
void stack_overflow(void);
void stack_underflow(void);

int main(void) {
    char input[STACK_SIZE];
    Stack parentheses;
    Stack braces;

    printf("Enter parentheses and/or braces: ");
    fgets(input, STACK_SIZE, stdin);

    make_empty(&parentheses);
    make_empty(&braces);

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '(') {
            if (is_full(&parentheses)) {
                stack_overflow();
                break;
            }
            push(&parentheses, input[i]);
        }
        else if (input[i] == '{') {
            if (is_full(&braces)) {
                stack_overflow();
                break;
            }
            push(&braces, input[i]);
        }

        if (input[i] == ')') {
            if (is_empty(&parentheses)) {
                stack_underflow();
                break;
            }
            pop(&parentheses);
        }
        else if (input[i] == '}') {
            if (is_empty(&braces)) {
                stack_underflow();
                break;
            }
            pop(&braces);
        }
    }

    if (is_empty(&parentheses) && is_empty(&braces)) {
        printf("Parentheses/braces are nested properly");
    }
    else {
        printf("Parentheses/braces are not nested properly");
    }

    return 0;
}

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

char push(Stack* s, char i)
{
    if (is_full(s))
        stack_overflow();
    else
        return s->contents[s->top++] = i;
    return 0;
}

char pop(Stack* s)
{
    if (is_empty(s))
        stack_underflow();
    else
        return s->contents[--s->top];
    return 0;
}

void stack_overflow(void)
{
    printf("Stack overflow\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
    printf("Stack underflow\n");
    exit(EXIT_FAILURE);
}