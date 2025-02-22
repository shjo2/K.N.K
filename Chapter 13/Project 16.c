#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define MESSAGE_SIZE 100

void reverse(char* message) {
    char* start = message;
    char* end = message + strlen(message) - 1;
    char temp;

    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main(void) {
    char message[MESSAGE_SIZE];

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0;

    reverse(message);
    printf("Reverse string: %s\n", message);

    return 0;
}