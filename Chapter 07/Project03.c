#include <stdio.h>
#pragma warning (disable : 4996)

int main(void) {
    double sum = 0.0;
    double input;

    printf("This program sums a series of double values.\n");
    printf("Enter double values (0 to terminate): ");

    while (1) {
        printf("Enter the input: ");
        scanf("%lf", &input);
        sum += input;
        if (input == 0)
            break;
    }

    printf("Sum is: %lf\n", sum);

    return 0;
}