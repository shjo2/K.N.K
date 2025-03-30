#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    FILE* fp;
    int file_open_failure = 0;

    if (argc < 2) {
        printf("usage: canopen filename\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++) {
        if ((fp = fopen(argv[i], "r")) == NULL) {
            printf("%s can't be opened\n", argv[i]);
            file_open_failure = 1;
        }
        else {
            printf("%s can be opened\n", argv[i]);
            fclose(fp);
        }
    }

    if (file_open_failure)
        exit(EXIT_FAILURE);

    return 0;
}
