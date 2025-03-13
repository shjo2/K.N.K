#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackADT2.h"

int main(void) {
    Stack s;
    char ch;
    bool is_match = true;
    char input[STACK_SIZE];

    printf("Enter parentheses and/or braces: ");
    fgets(input, STACK_SIZE, stdin);

    make_empty(&s);

    int input_len = strlen(input);

    for (int i = 0; i < input_len; i++) {
        ch = input[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            if (is_full(&s)) {
                stack_overflow();
                is_match = false;
                break;
            }
            push(&s, ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (is_empty(&s)) {
                is_match = false;
                break;
            }
            else {
                char top_ch = pop(&s);
                if ((ch == ')' && top_ch != '(') ||
                    (ch == '}' && top_ch != '{') ||
                    (ch == ']' && top_ch != '[')) {
                    is_match = false;
                    break;
                }
            }
        }
    }

    if (!is_empty(&s)) {
        is_match = false;
    }

    if (is_match) {
        printf("Parentheses/braces are nested properly\n");
    }
    else {
        printf("Parentheses/braces are NOT nested properly\n");
    }

    return 0;
}