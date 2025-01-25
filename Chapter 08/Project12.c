#include <stdio.h> 
#include <ctype.h>
#define ALPHABET_SIZE 30 

int main(void) {
    int scrabble_values[26] = { 1, 3, 3, 2, 1, 4,
                                2, 4, 1, 8, 5, 1,
                                3, 1, 1, 3, 10, 1,
                                1, 1, 1, 4, 4, 8, 4, 10 };

    char alphbet[ALPHABET_SIZE] = { 0, };
    char upper_alphabet[ALPHABET_SIZE] = { 0, };
    int scrabble_value = 0;
    int alphabet_size = 0;
    int upper_alphabet_size = 0;

    printf("Enter a word: ");
    if (fgets(alphbet, ALPHABET_SIZE, stdin) == NULL) {
        printf("error reading input.");
        return 1;
    }

    alphabet_size = strlen(alphbet);

    for (int i = 0; i < alphabet_size; i++) {
        upper_alphabet[i] = toupper(alphbet[i]);
    }

    upper_alphabet_size = strlen(upper_alphabet);

    for (int i = 0; i < upper_alphabet_size; i++) {
        if (isalpha(upper_alphabet[i]))
            scrabble_value += scrabble_values[(upper_alphabet[i]) - 'A'];
    }

    printf("Scrabble value: %d", scrabble_value);

    return 0;
}