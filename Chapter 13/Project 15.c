#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define STACK_SIZE 100
#define EXPRESSION_SIZE 100

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
int evaluate_RPN_expression(const char* expression);

int main(void) {
    char expression[EXPRESSION_SIZE] = { 0 };

    printf("Input: ");
    if (fgets(expression, EXPRESSION_SIZE, stdin) == NULL)
        return 1;

    if (expression[0] == '\n') {
        printf("Empty input\n");
        return 1;
    }

    printf("Value of expression: %d", evaluate_RPN_expression(expression));

    return 0;
}

int evaluate_RPN_expression(const char* expression) {
    Stack operandStack;
    make_empty(&operandStack);
    double operand1, operand2;
    char* token;

    token = strtok(expression, " \t\n");

    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&operandStack, atof(token));
        }
        else if (strchr("+-*/", token[0]) != NULL && strlen(token) == 1) {
            if (operandStack.top < 2) {
                printf("Not enough operands\n");
                return 1;
            }
            operand2 = pop(&operandStack);
            operand1 = pop(&operandStack);
            switch (token[0]) {
            case '+': push(&operandStack, operand1 + operand2); break;
            case '-': push(&operandStack, operand1 - operand2); break;
            case '*': push(&operandStack, operand1 * operand2); break;
            case '/':
                if (operand2 == 0) {
                    printf("Division by zero\n");
                    return 1;
                }
                push(&operandStack, operand1 / operand2);
                break;
            }
        }
        else if (strcmp(token, "=") == 0) {
            if (operandStack.top != 1) {
                printf("Invalid Expression\n");
                return 1;
            }
            return (int)operandStack.contents[0];
        }
        else {
            printf("Invalid token: %s\n", token);
            return 1;
        }
        token = strtok(NULL, " \t\n");
    }

    if (!is_empty(&operandStack))
        return (int)pop(&operandStack);
    else {
        printf("not enough operands in expression\n");
        return 1;
    }
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