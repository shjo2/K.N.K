#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(int argc, char* argv[])
{
    FILE* input_fp = NULL;
    FILE* output_fp = NULL;
    char word[MAX_WORD_LEN + 1];
    int word_len;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    input_fp = fopen(argv[1], "r");
    if (input_fp == NULL) {
        fprintf(stderr, "Error: Can`t open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    output_fp = fopen(argv[2], "w");
    if (output_fp == NULL) {
        fprintf(stderr, "Error: Can`t open file %s\n", argv[2]);
        fclose(input_fp);
        exit(EXIT_FAILURE);
    }

    clear_line();

    for (;;) {
        if (read_word(input_fp, word, MAX_WORD_LEN + 1) == 0) {
            flush_line(output_fp);
            break;
        }

        word_len = strlen(word);

        if (word_len > MAX_LINE_LEN) {
            if (line_len() > 0) {
                write_line(output_fp);
                clear_line();
            }
            add_word(word);
            flush_line(output_fp);
            continue;
        }

        if (word_len + (line_len() > 0 ? 1 : 0) > space_remaining()) {
            write_line(output_fp);
            clear_line();
        }

        add_word(word);
    }

    fclose(input_fp);
    fclose(output_fp);
    return 0;
}