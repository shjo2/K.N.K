#include <stdio.h>
#include <string.h>

int main() {
    char word[21] = "";
    char smallest_word[21] = "";
    char largest_word[21] = "";

    while (1) {
        printf("Enter word: ");
        scanf("%20s", word);

        int length = strlen(word);

        if (strcmp(smallest_word, "") == 0) {
            strcpy(smallest_word, word);
            strcpy(largest_word, word);
        }
        else {
            if (length == 4) {
                if (strncmp(word, smallest_word, 21) < 0) {
                    strcpy(smallest_word, word);
                }
                if (strncmp(word, largest_word, 21) > 0) {
                    strcpy(largest_word, word);
                }

                break;
            }

            if (strncmp(word, smallest_word, 21) < 0) {
                strcpy(smallest_word, word);
            }
            if (strncmp(word, largest_word, 21) > 0) {
                strcpy(largest_word, word);
            }
        }
    }


    printf("Smallest word: %s\n", smallest_word);
    printf("Largest word: %s\n", largest_word);

    return 0;
}