#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "stackADT2.h"

int main() {
    Stack s;
    char ch;
    int operand1, operand2, result;

    s.contents = (int*)malloc(100 * sizeof(int));
    s.top = -1;
    s.size = 100;

    printf("Enter an RPN expression: ");

    while ((ch = getchar()) != '\n') {
        if (isdigit(ch)) {
            ungetc(ch, stdin);
            int num;
            scanf("%d", &num);
            push(&s, num);
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (is_empty(&s)) {
                stack_underflow();
            }
            operand2 = pop(&s);

            if (is_empty(&s)) {
                stack_underflow();
            }
            operand1 = pop(&s);

            switch (ch) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                if (operand2 == 0) {
                    printf("Division by zero error.\n");
                    exit(EXIT_FAILURE);
                }
                result = operand1 / operand2;
                break;
            }
            push(&s, result);

        }
        else if (ch == '=') {
            if (!is_empty(&s)) {
                result = pop(&s);
                if (is_empty(&s)) {
                    printf("Value of expression: %d\n", result);
                }
                else {
                    printf("Invalid expression.\n");
                }
            }
            else {
                printf("Invalid expression.\n");
            }
            break;

        }
        else if (ch != ' ') {
            printf("Invalid character in expression: %c\n", ch);
            exit(EXIT_FAILURE);
        }
    }

    free(s.contents);
    return 0;
}