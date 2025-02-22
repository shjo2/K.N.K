#include <stdio.h>
#include <string.h>
#include <ctype.h>

int compute_scrabble_value(const char* word) {
    int i;
    int scrabble_value = 0;

    for (i = 0; word[i] != '\0'; i++) {
        char upper_char = toupper(word[i]);
        switch (upper_char) {
        case 'A': case 'E': case 'I': case 'O': case 'U': case 'L': case 'N': case 'S': case 'T': case 'R':
            scrabble_value += 1;
            break;
        case 'D': case 'G':
            scrabble_value += 2;
            break;
        case 'B': case 'C': case 'M': case 'P':
            scrabble_value += 3;
            break;
        case 'F': case 'H': case 'V': case 'W': case 'Y':
            scrabble_value += 4;
            break;
        case 'K':
            scrabble_value += 5;
            break;
        case 'J': case 'X':
            scrabble_value += 8;
            break;
        case 'Q': case 'Z':
            scrabble_value += 10;
            break;
        default:
            scrabble_value += 0;
            break;
        }
    }

    return scrabble_value;
}

int main() {
    char word[100];

    printf("Enter a word: ");
    scanf("%s", word);

    printf("Scrabble value: %d\n", compute_scrabble_value(word));

    return 0;
}