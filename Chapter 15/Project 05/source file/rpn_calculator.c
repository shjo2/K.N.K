#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "stack.h"

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