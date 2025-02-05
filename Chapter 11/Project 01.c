#include <stdio.h>

void pay_amount(int dollars, int* twenties, int* tens,
    int* fives, int* ones) {

    *twenties = dollars / 20;
    dollars %= 20;

    *tens = dollars / 10;
    dollars %= 10;

    *fives = dollars / 5;
    dollars %= 5;

    *ones = dollars;
}

int main(void) {
    int dollars;
    int twenties, tens, fives, ones;

    printf("Enter a dollar amount: ");
    scanf("%d", &dollars);

    pay_amount(dollars, &twenties, &tens, &fives, &ones);

    printf("20달러: %d개\n", twenties);
    printf("10달러: %d개\n", tens);
    printf("5달러: %d개\n", fives);
    printf("1달러: %d개\n", ones);

    return 0;
}