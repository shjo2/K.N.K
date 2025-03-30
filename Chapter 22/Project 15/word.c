#include <stdio.h>
#include <ctype.h>

int read_char(FILE* stream)
{
    int ch = fgetc(stream);

    if (ch == '\n' || ch == '\t')
        return ' ';
    return ch;
}

int read_word(FILE* stream, char* word, int len)
{
    int ch, pos = 0;

    while ((ch = read_char(stream)) == ' ')
        ;

    while (ch != ' ' && ch != EOF) {
        if (pos < len - 1) {
            word[pos++] = ch;
        }
        else if (pos == len - 1) {
            word[pos++] = ch;
        }

        ch = read_char(stream);
    }


    if (pos >= len)
        pos = len - 1;
    word[pos] = '\0';


    if (pos == 0 && ch == EOF) {
        return 0;
    }

    return pos;
}