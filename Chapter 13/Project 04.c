#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        return 0;
    }

    for (int i = argc - 1; i >= 1; i--) {
        printf("%s", argv[i]);
        if (i > 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}