#include <stdio.h>
#include <stdlib.h>

void max_min(const int* a, int n, int* max, int* min) {
    if (n <= 0) {
        return;
    }

    *max = *min = *a;

    for (const int* p = a + 1; p < a + n; p++) {
        if (*p > *max) {
            *max = *p;
        }
        else if (*p < *min) {
            *min = *p;
        }
    }
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error:  The number of elements must be a positive integer.\n");
        return 1;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Error:  Failed to read integer input.\n");
            free(arr);
            return 1;
        }
    }

    int max_value, min_value;
    max_min(arr, n, &max_value, &min_value);

    printf("Largest: %d\n", max_value);
    printf("Smallest: %d\n", min_value);

    free(arr);
    return 0;
}