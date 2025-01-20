#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ALPHABET_SIZE 30 

int main(void) {
    char alphbet[ALPHABET_SIZE] = { 0, };
    char upper_alphabet[ALPHABET_SIZE] = { 0, };
    int value = 0;

    printf("Enter a word: ");
    if (fgets(alphbet, ALPHABET_SIZE, stdin) == NULL) {
        printf("error reading input.");
        return 1;
    }

    for (int i = 0; i < strlen(alphbet); i++) {
        upper_alphabet[i] = toupper(alphbet[i]);
    }

    for (int i = 0; i < strlen(upper_alphabet); i++) {
        if (upper_alphabet[i] == 'A' || upper_alphabet[i] == 'E' || upper_alphabet[i] == 'I' || upper_alphabet[i] == 'L' || upper_alphabet[i] == 'N' || upper_alphabet[i] == 'O' || upper_alphabet[i] == 'R' || upper_alphabet[i] == 'S' || upper_alphabet[i] == 'T' || upper_alphabet[i] == 'U')
            value += 1;
        else if (upper_alphabet[i] == 'D' || upper_alphabet[i] == 'G')
            value += 2;
        else if (upper_alphabet[i] == 'B' || upper_alphabet[i] == 'C' || upper_alphabet[i] == 'M' || upper_alphabet[i] == 'P')
            value += 3;
        else if (upper_alphabet[i] == 'F' || alphbet[i] == 'H' || upper_alphabet[i] == 'V' || upper_alphabet[i] == 'W' || upper_alphabet[i] == 'Y')
            value += 4;
        else if (upper_alphabet[i] == 'K')
            value += 5;
        else if (upper_alphabet[i] == 'J' || upper_alphabet[i] == 'X')
            value += 8;
        else if (upper_alphabet[i] == 'Q' || upper_alphabet[i] == 'Z')
            value += 10;
    }

    printf("Scrabble value: %d", value);
    return 0;
}