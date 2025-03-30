#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256
#define DATE_BUFFER_SIZE 11

int main(int argc, char* argv[]) {
    FILE* fp = NULL;
    char buffer[BUFFER_SIZE];
    int item_number = 0;
    double unit_price = 0.0;
    char purchase_date[DATE_BUFFER_SIZE] = { 0 };
    int read_bytes = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Can`t open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf(stdout, "Item     Unit      Purchase\n");
    printf(stdout, "         Price     Date\n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (sscanf(buffer, "%d,%lf,%s", &item_number, &unit_price, purchase_date) == 3) {
            printf("%-8d $ %7.2f  %-10s\n",
                item_number,
                unit_price,
                purchase_date);
        }
    }

    fclose(fp);
    return 0;
}