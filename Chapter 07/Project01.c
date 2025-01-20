#include <stdio.h>
#include <math.h>
#include <limits.h>

int main(void) {
    int i = 1;
    short s = 1;
    long l = 1;

    int intOverflowPoint = 0;
    short shortOverflowPoint = 0;
    long longOverflowPoint = 0;

    while (1)
    {
        if (i > INT_MAX / i)
            break;

        intOverflowPoint++;
        i++;
    }
    while (1)
    {
        if (s > SHRT_MAX / s)
            break;

        shortOverflowPoint++;
        s++;
    }
    while (1)
    {
        if (l > LONG_MAX / l)
            break;

        longOverflowPoint++;
        l++;
    }

    printf("Int Overflow Point: %d\n", intOverflowPoint);
    printf("Short Overflow Point: %d\n", shortOverflowPoint);
    printf("Long Overflow Point: %ld\n", longOverflowPoint);

    double int_bits = log2(((double)intOverflowPoint * intOverflowPoint + 1) + 1);
    double short_bits = log2(((double)shortOverflowPoint * shortOverflowPoint + 1) + 1);
    double long_bits = log2(((double)longOverflowPoint * longOverflowPoint + 1) + 1);

    printf("Estimated bit size of int: %.2f\n", int_bits);
    printf("Estimated bit size of short: %.2f\n", short_bits);
    printf("Estimated bit size of long: %.2f\n", long_bits);

    return 0;
}