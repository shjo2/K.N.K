#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h> 

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

int main(void) {
    Stack operandStack;
    double operand1, operand2;
    double result = 0;
    char ch;

    printf("Input: ");

    make_empty(&operandStack);

    while (scanf("%c", &ch) == 1 && ch != 'q') {
        if (isdigit(ch)) {
            push(&operandStack, (double)(ch - '0'));
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (is_empty(&operandStack)) {
                stack_underflow();
                break;
            }

            operand2 = pop(&operandStack);
            operand1 = pop(&operandStack);

            switch (ch) {
            case '+':
                push(&operandStack, operand1 + operand2);
                break;
            case '-':
                push(&operandStack, operand1 - operand2);
                break;
            case '*':
                push(&operandStack, operand1 * operand2);
                break;
            case '/':
                if (operand2 != 0)
                    push(&operandStack, operand1 / operand2);
                break;
            }
        }
        else if (ch == '=') {
            if (is_empty(&operandStack)) {
                stack_underflow();
                break;
            }
        }
        else if (!isspace(ch)) {
            printf("Error: Invalid input %c\n", ch);
            break;
        }
    }

    if (!is_empty(&operandStack)) {
        result = pop(&operandStack);
    }

    printf("Value of expression: %.f", result);


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