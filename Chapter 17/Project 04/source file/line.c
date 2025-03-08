#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

struct line_node {
    char* line;
    struct line_node* next;
};

struct line_node* first_line = NULL;
struct line_node* last_line = NULL;
int line_len = 0;
int num_words = 0;

void clear_line(void) {
    struct line_node* current = first_line;
    struct line_node* temp;

    while (current != NULL) {
        free(current->line);
        temp = current;
        current = current->next;
        free(temp);
    }

    first_line = NULL;
    last_line = NULL;
    line_len = 0;
    num_words = 0;
}

void add_word(const char* word) {
    struct line_node* new_node = (struct line_node*)malloc(sizeof(struct line_node));

    if (new_node == NULL) {
        printf("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    new_node->line = (char*)malloc(strlen(word) + 1 + (num_words > 0 ? 1 : 0));
    if (new_node->line == NULL) {
        printf("Failed to create new line!\n");
        free(new_node);
        exit(EXIT_FAILURE);
    }

    if (num_words > 0) {
        strcpy(new_node->line, " ");
        strcat(new_node->line, word);
    }
    else {
        strcpy(new_node->line, word);
    }

    if (first_line == NULL) {
        first_line = new_node;
        last_line = new_node;
    }
    else {
        last_line->next = new_node;
        last_line = new_node;
    }
    new_node->next = NULL;

    line_len += strlen(word) + (num_words > 0 ? 1 : 0);
    num_words++;
}

int space_remaining(void) {
    return MAX_LINE_LEN - line_len;
}

void write_line(void) {
    int extra_spaces, spaces_to_insert, i, j;

    struct line_node* current = first_line;
    extra_spaces = MAX_LINE_LEN - line_len;

    if (current == NULL) {
        putchar('\n');
        return;
    }

    while (current != NULL) {
        printf("%s", current->line);

        if (current->next != NULL && num_words > 1) {
            spaces_to_insert = extra_spaces / (num_words - 1);
            for (j = 1; j <= spaces_to_insert; j++)
                putchar(' ');
            extra_spaces -= spaces_to_insert;
        }
        else {
            spaces_to_insert = 0;
        }

        num_words--;
        current = current->next;
    }
    putchar('\n');
}

void flush_line(void) {
    struct line_node* current = first_line;

    while (current != NULL) {
        puts(current->line);
        current = current->next;
    }

    clear_line();
}