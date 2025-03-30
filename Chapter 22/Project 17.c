#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LINE_SIZE 256
#define PHONE_NUMBER_SIZE 10

int main(int argc, char* argv[]) {
    FILE* fp;
    char buffer[LINE_SIZE] = { 0 };
    char digits[PHONE_NUMBER_SIZE] = { 0 };
    int count;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        count = 0;
        for (int i = 0; buffer[i] != '\0' && count < PHONE_NUMBER_SIZE; i++)
            if (isdigit(buffer[i]))
                digits[count++] = buffer[i];

        if (count == PHONE_NUMBER_SIZE) {
            for (int i = 0; i < PHONE_NUMBER_SIZE; i++) {
                if (i == 0) {
                    putchar('(');
                }
                else if (i == 3) {
                    printf(") ");
                }
                else if (i == 6) {
                    putchar('-');
                }
                printf("%c", digits[i]);
            }
            putchar('\n');
        }
    }

    fclose(fp);
    return EXIT_SUCCESS;
}