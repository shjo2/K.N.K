#include <stdio.h>
#include <string.h>
#include <ctype.h>

int compute_vowel_count(const char* sentence) {
    int i;
    int vowel_count = 0;

    for (i = 0; sentence[i] != '\0'; i++) {
        char lower_char = tolower(sentence[i]);
        switch (lower_char) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            vowel_count++;
            break;
        }
    }

    return vowel_count;
}

int main() {
    char sentence[200];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    printf("Number of vowels in the sentence: %d\n", compute_vowel_count(sentence));

    return 0;
}