#include <stdio.h>
#include <ctype.h>

#define MESSAGE_SIZE 100

int main(void) {
    char message[MESSAGE_SIZE];
    char* start;
    char* end = 0;

    start = message;

    printf("Enter a message: ");
    if (fgets(message, MESSAGE_SIZE, stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    end = start - 1;

    printf("Reversal is: ");
    while (end >= start) {
        while (end >= start && !isalpha(*end)) {
            end--;
        }
        if (end >= start) {
            printf("%c", *end);
        }

        end--;
    }
    printf("\n");

    return 0;
}