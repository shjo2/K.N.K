#include <stdio.h>
#include <stdlib.h>

int* split(int* low, int* high) {
    int pivot_element = *low;

    for (;;) {
        while (low < high && pivot_element <= *high)
            high--;

        if (low >= high) break;

        *low++ = *high;

        while (low < high && *low <= pivot_element)
            low++;

        if (low >= high) break;

        *high-- = *low;
    }

    *high = pivot_element;
    return high;
}

void quicksort(int* low, int* high) {
    if (low >= high) return;

    int* middle = split(low, high);
    quicksort(low, middle - 1);
    quicksort(middle + 1, high);
}

int main(void) {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int* a = (int*)malloc(n * sizeof(int));

    printf("Enter %d elements: ", n);
    for (int* p = a; p < a + n; p++) {
        scanf("%d", p);
    }

    quicksort(a, a + n - 1);

    printf("Sorted array: ");
    for (int* p = a; p < a + n; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    free(a);
    return 0;
}