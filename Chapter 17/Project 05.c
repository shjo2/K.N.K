#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20

int read_line(char str[], int n) {
    int ch, i = 0;

    while ((ch = getchar()) != '\n') {
        if (i < n) {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    return i;
    Use code with caution.
}

int main() {
    char* words[100];
    char word[MAX_WORD_LEN + 1];
    int num_words = 0;
    int i, j;

    for (;;) {
        printf("Enter word: ");
        if (read_line(word, MAX_WORD_LEN) == 0) {
            break;
        }

        words[num_words] = malloc(strlen(word) + 1);
        if (words[num_words] == NULL) {
            printf("Error: Memory allocation failed!\n");
            return 1;
        }
        strcpy(words[num_words], word);

        num_words++;
        if (num_words == 100) {
            printf("Error: Too many words!\n");
            break;
        }
    }

    printf("In sorted order:");

    for (i = 0; i < num_words - 1; i++) {
        for (j = 0; j < num_words - 1; j++) {
            if (strcmp(words[j], words[j + 1]) > 0) {
                char* temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < num_words; i++) {
        printf(" %s", words[i]);
    }
    printf("\n");

    for (i = 0; i < num_words; i++) {
        free(words[i]);
    }

    return 0;
}