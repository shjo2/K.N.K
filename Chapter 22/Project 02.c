#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    FILE* fp = NULL;
    int ch;

    if (argc < 2) {
        fprintf("usage: canopen filename\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Error: Cant`t open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(fp)) != EOF) {
        if(isalpha(ch))
            fputc(toupper(ch));
    }

    fclose(fp);

    return 0;
}
