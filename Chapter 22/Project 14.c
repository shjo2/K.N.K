#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 256
#define ALPHABET_SIZE 26

char encrypt_char(char ch, int shift);

int main(void) {
    FILE* input_fp = NULL;
    FILE* output_fp = NULL;
    char filename[MAX_MESSAGE_LENGTH] = { 0 };
    char outfile_name[MAX_MESSAGE_LENGTH] = { 0 };
    int shift = 0;
    int ch;
    char encrypted_ch;

    printf("Enter name of file to be encrypted: ");
    if (fgets(filename, sizeof(filename), stdin) == NULL) {
        fprintf(stderr, "Error reading file\n");
        exit(EXIT_FAILURE);
    }
    filename[strcspn(filename, "\n")] = '\0';

    snprintf(outfile_name, sizeof(outfile_name), "%s.enc", filename);

    input_fp = fopen(filename, "r");
    if (input_fp == NULL) {
        fprintf(stderr, "Error: Can`t open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    output_fp = fopen(outfile_name, "w");
    if (output_fp == NULL) {
        fprintf(stderr, "Error: Can`t open file %s\n", outfile_name);
        fclose(input_fp);
        exit(EXIT_FAILURE);
    }

    printf("Enter shift amount (1-25): ");
    if (scanf("%d", &shift) != 1) {
        fprintf(stderr, "Error: Invalid input for shift amount. Please enter a number.\n");
        fclose(input_fp);
        fclose(output_fp);
        exit(EXIT_FAILURE);
    }
    if (shift < 1 || shift > 25) {
        fprintf(stderr, "Error: Shift amount must be between 1 and 25.\n");
        fclose(input_fp);
        fclose(output_fp);
        exit(EXIT_FAILURE);
    }
    while (getchar() != '\n');

    while ((ch = fgetc(input_fp)) != EOF) {
        encrypted_ch = encrypt_char((char)ch, shift);
        if (fputc(encrypted_ch, output_fp) == EOF) {
            fclose(input_fp);
            fclose(output_fp);
            exit(EXIT_FAILURE);
        }
    }

    fclose(input_fp);
    fclose(output_fp);
    return 0;
}

char encrypt_char(char ch, int shift) {

    if (isupper(ch)) {
        return ((ch - 'A') + shift) % ALPHABET_SIZE + 'A';
    }
    else if (islower(ch)) {
        return ((ch - 'a') + shift) % ALPHABET_SIZE + 'a';
    }
    else {
        return ch;
    }
}