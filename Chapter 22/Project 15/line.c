#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"
#include "word.h"

#ifndef MAX_WORD_LEN
#define MAX_WORD_LEN 20
#endif

struct node {
    char word[MAX_WORD_LEN + 1];
    struct node* next;
};

static struct node* line = NULL;
static struct node* line_tail = NULL;
static int current_line_len = 0;
static int num_words = 0;

void clear_line(void) {
    struct node* temp;
    while (line != NULL) {
        temp = line;
        line = line->next;
        free(temp);
    }
    line_tail = NULL;
    current_line_len = 0;
    num_words = 0;
}

void add_word(const char* word) {
    struct node* new_node;

    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed in add_word\n");
        exit(EXIT_FAILURE);
    }

    strcpy(new_node->word, word);
    new_node->next = NULL;

    if (line == NULL) {
        line = new_node;
        line_tail = new_node;
    }
    else {
        line_tail->next = new_node;
        line_tail = new_node;
    }

    current_line_len += strlen(word);
    num_words++;
}

int space_remaining(void) {
    return MAX_LINE_LEN - current_line_len;
}

int line_len(void) {
    return current_line_len;
}


void write_line(FILE* stream) {
    int extra_spaces, spaces_to_insert, spaces_per_gap, i;
    struct node* p = line;

    if (p == NULL) {
        fputc('\n', stream);
        return;
    }

    extra_spaces = space_remaining();
    spaces_to_insert = extra_spaces;

    while (p != NULL) {
        fprintf(stream, "%s", p->word);
        int gaps = num_words - 1;

        if (gaps > 0) {
            spaces_per_gap = spaces_to_insert / gaps;
            int current_extra = spaces_to_insert % gaps;

            int spaces_this_gap = spaces_per_gap + (current_extra > 0 ? 1 : 0);


            for (i = 1; i <= spaces_this_gap + 1; i++) {
                fputc(' ', stream);
            }

            spaces_to_insert -= (spaces_this_gap + 1);
            num_words--;
        }
        p = p->next;
    }
    fputc('\n', stream);
}

void flush_line(FILE* stream) {
    struct node* p = line;

    if (p == NULL) return;

    while (p != NULL) {
        fprintf(stream, "%s", p->word);
        if (p->next != NULL) {
            fputc(' ', stream);
        }
        p = p->next;
    }
    fputc('\n', stream);
}