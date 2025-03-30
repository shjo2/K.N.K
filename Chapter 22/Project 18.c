#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 10000

int compare(const void* a, const void* b);

int main(int argc, char* argv[]) {
    FILE* fp;
    int numbers[MAX_SIZE] = { 0 };
    int number;
    int max_value;
    int min_value;
    int middle_value;
    int count = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }

    while (count < MAX_SIZE && fscanf(fp, "%d", &number) == 1) {
        numbers[count++] = number;
    }

    qsort(numbers, count, sizeof(const int), compare);

    min_value = numbers[0];
    max_value = numbers[count - 1];

    if (count % 2 == 1)
        middle_value = numbers[count / 2];
    else if (count % 2 == 0)
        middle_value = (numbers[count / 2] + numbers[count / 2 - 1]) / 2;

    printf("Max value: %d\n", max_value);
    printf("Min value: %d\n", min_value);
    printf("Middle value: %d\n", middle_value);

    fclose(fp);
    return EXIT_SUCCESS;
}

int compare(const void* a, const void* b) {
    int int_a = *(const int*)a;
    int int_b = *(const int*)b;

    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;

}