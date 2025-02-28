#include <stdio.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN + 1];
size_t line_len = 0;
int num_words = 0;

void clear_line(void)
{
	line[0] = '\0';
	line_len = 0;
	num_words = 0;
}

void add_word(const char* word)
{
	if (num_words > 0) {
		line[line_len++] = ' ';
		line[line_len] = '\0';
	}

	strcat(line, word);
	line_len += strlen(word);
	num_words++;
}

int space_remaining(void)
{
	return MAX_LINE_LEN - line_len;
}

void write_line(void) {
	int extra_spaces, spaces_to_insert, remainder, i, j;

	extra_spaces = space_remaining();
	if (num_words <= 1) {
		puts(line);
		return;
	}

	spaces_to_insert = extra_spaces / (num_words - 1);
	remainder = extra_spaces % (num_words - 1);

	for (i = 0; i < line_len; i++) {
		if (line[i] == ' ') {
			putchar(line[i]);

			int spaces = spaces_to_insert;
			if (remainder > 0) {
				spaces++;
				remainder--;
			}
			for (j = 0; j < spaces; j++) {
				putchar(' ');
			}
		}
		else {
			putchar(line[i]);
		}
	}
	putchar('\n');
}


void flush_line(void)
{
	if (line_len > 0)
		puts(line);

	clear_line();
}