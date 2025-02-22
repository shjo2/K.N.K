#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

double compute_average_word_length(const char* sentence) {
    int word_int = 0;
    int word_length = 0;
    int total_length = 0;
    double avg_length = 0;
    char* token;
    char* str = strdup(sentence);

    token = strtok(str, " ");

    while (token != NULL) {
        word_int++;
        word_length = strlen(token);

        for (int i = 0; i < word_length; i++) {
            if (isalpha(token[i]))
                total_length++;
        }

        token = strtok(NULL, " ");
    }

    avg_length = (double)total_length / word_int;

    free(str);

    return avg_length;
}

int main() {
    char sentence[100];
    double length = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    sentence[strcspn(sentence, "\n")] = 0;

    length = compute_average_word_length(sentence);

    printf("Average word length is: %.2lf\n", length);

    return 0;
}