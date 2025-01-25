#include <stdio.h> 
#include <string.h>
#define NUM_SIZE 30

int main(void) {
    char phoneNumber[NUM_SIZE];
    int numberSize;

    printf("Enter phone number: ");
    if (fgets(phoneNumber, NUM_SIZE, stdin) == NULL) {
        printf("Error reading input.");
        return 1;
    }

    numberSize = strlen(phoneNumber);

    for (int i = 0; i < numberSize; i++) {
        if (phoneNumber[i] == 'A' || phoneNumber[i] == 'B' || phoneNumber[i] == 'C')
            phoneNumber[i] = '2';
        else if (phoneNumber[i] == 'D' || phoneNumber[i] == 'E' || phoneNumber[i] == 'F')
            phoneNumber[i] = '3';
        else if (phoneNumber[i] == 'G' || phoneNumber[i] == 'H' || phoneNumber[i] == 'I')
            phoneNumber[i] = '4';
        else if (phoneNumber[i] == 'J' || phoneNumber[i] == 'K' || phoneNumber[i] == 'L')
            phoneNumber[i] = '5';
        else if (phoneNumber[i] == 'M' || phoneNumber[i] == 'N' || phoneNumber[i] == 'O')
            phoneNumber[i] = '6';
        else if (phoneNumber[i] == 'P' || phoneNumber[i] == 'R' || phoneNumber[i] == 'S')
            phoneNumber[i] = '7';
        else if (phoneNumber[i] == 'T' || phoneNumber[i] == 'U' || phoneNumber[i] == 'V')
            phoneNumber[i] = '8';
        else if (phoneNumber[i] == 'W' || phoneNumber[i] == 'X' || phoneNumber[i] == 'Y')
            phoneNumber[i] = '9';
    }

    for (int i = 0; i < numberSize; i++) {
        printf("%c", phoneNumber[i]);
    }

    return 0;
}