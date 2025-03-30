#ifndef LINE_H
#define LINE_H

#define MAX_LINE_LEN 60

void clear_line(void);

void add_word(const char* word);

int space_remaining(void);

void write_line(void);

void flush_line(void);

int line_len(void);

#endif