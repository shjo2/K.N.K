#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int digit;
	long n;
	int digitCount[10] = { 0 };

	printf("Enter a number: ");
	scanf("%ld", &n);

	while (n > 0) {
		digit = n % 10;
		digitCount[digit]++;
		n /= 10;
	}

	printf("Digit:       ");
	for (int i = 0; i < 10; i++)
		printf("%3d", i);

	printf("\n");

	printf("Occurrences: ");
	for (int i = 0; i < 10; i++) {
		printf("%3d", digitCount[i]);
	}

	return 0;
}