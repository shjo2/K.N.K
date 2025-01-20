#include <stdio.h>
#pragma warning (disable : 4996)

int main() {
	int number;
	int factorialNumber;
	unsigned long long factorial = 1;

	printf("Enter a positive integer: ");
	scanf("%d", &number);

	factorialNumber = number;

	while (number > 0) {
		factorial *= number;
		number--;
	}

	printf("Factorial of %d: %llu\n", factorialNumber, factorial);

	return 0;
}