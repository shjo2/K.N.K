#include <stdio.h>
#include <string.h>

#define MESSAGE_SIZE 100

void reverse_string(char* s) {
    if (s == NULL || *s == '\0')
        return;

    char* start = s;
    char* end = s + strlen(s) - 1;
    char* word_start;

    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }

    start = s;
    while (*start) {
        while (*start && *start == ' ') {
            start++;
        }

        if (!*start)
            break;

        word_start = start;

        while (*start && *start != ' ')
            start++;

        end = start - 1;
        while (end > word_start) {
            char temp = *word_start;
            *word_start++ = *end;
            *end-- = temp;
        }
    }
}

int main(void) {
    char message[MESSAGE_SIZE];

    printf("Enter a message: ");
    if (fgets(message, MESSAGE_SIZE, stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    message[strcspn(message, "\n")] = '\0';

    reverse_string(message);
    printf("Reversal is: %s\n", message);

    return 0;
}