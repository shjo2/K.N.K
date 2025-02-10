#include <stdio.h>
#include <string.h> 

#define MESSAGE_SIZE 100

int main(void) {
    char message[MESSAGE_SIZE];
    int message_length = 0;
    int ch;
    int i = 0;

    printf("Enter a message: ");
    if (fgets(message, MESSAGE_SIZE, stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    message[strcspn(message, '\n')] = '\0';

    message_length = strlen(message);

    printf("Reversal is: ");
    for (int i = message_length - 1; i >= 0; i--) {
        printf("%c", message[i]);
    }

    return 0;
}