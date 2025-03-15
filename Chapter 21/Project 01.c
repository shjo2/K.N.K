#include <stdio.h>
#include <stddef.h>

typedef struct s {
    char a;
    int b;
    float c;
} s;

int main() {
    s s1;

    printf("size of structure: %d\n", sizeof(s1));
    printf("Size of a: %zu\n", sizeof(s1.a));
    printf("Size of b: %zu\n", sizeof(s1.b));
    printf("Size of c: %zu\n", sizeof(s1.c));

    printf(".a : %zu \n", offsetof(struct s, a));
    printf(".b : %zu \n", offsetof(struct s, b));
    printf(".c : %zu \n", offsetof(struct s, c));


    int hole1_start = offsetof(s, a) + sizeof(s1.a);
    int hole1_size = offsetof(struct s, b) - offsetof(struct s, a) - sizeof(s1.a);
    int hole2_start = offsetof(s, b) + sizeof(s1.b);
    int hole2_size = offsetof(struct s, c) - offsetof(struct s, b) - sizeof(s1.b);


    if (hole1_size > 0) {
        printf("Hole 1 Start: %zu, Size: %zu\n", hole1_start, hole1_size);
    }
    if (hole2_size > 0) {
        printf("Hole 2 Start: %zu, Size: %zu\n", hole2_start, hole2_size);

    }

    return 0;
}
