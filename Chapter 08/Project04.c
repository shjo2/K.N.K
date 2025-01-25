#include <stdio.h>

#define ARRAY_LENGTH (sizeof(a) / sizeof(a[0]))

int main(void) {
    int a[10], i;

    printf("Enter 10 numbers: ");
    for (i = 0; i < ARRAY_LENGTH; i++) {
        scanf("%d", &a[i]);
    }

    printf("In reverse order:");
    for (i = ARRAY_LENGTH; i >= 0; i--) {
        printf(" %d", a[i]);
    }
    printf("\n");

    return 0;
}