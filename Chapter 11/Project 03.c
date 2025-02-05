#include <stdio.h> 

int gcd(int numerator, int denominator) {
    if (denominator == 0)
        return numerator;

    return gcd(denominator, numerator % denominator);
}

void reduce(int numerator, int denominator, int* reduced_numerator, int* reduced_denominator) {
    int greatest_divisor;
    int reduced_num;
    int reduced_deno;

    greatest_divisor = gcd(numerator, denominator);
    reduced_num = numerator / greatest_divisor;
    reduced_deno = denominator / greatest_divisor;

    *reduced_numerator = reduced_num;
    *reduced_denominator = reduced_deno;
}

int main(void) {
    int numerator, denominator;
    int reduced_numerator;
    int reduced_denominator;

    printf("분자와 분모를 입력하세요: ");
    scanf("%d %d", &numerator, &denominator);

    reduce(numerator, denominator, &reduced_numerator, &reduced_denominator);

    printf("기약 분수: %d/%d\n", reduced_numerator, reduced_denominator);

    return 0;
}