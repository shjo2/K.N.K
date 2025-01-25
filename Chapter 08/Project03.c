#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	long n;

	while (1) {
		printf("Enter a number: ");
		scanf("%ld", &n);

		if (n <= 0)
			break;

		bool digit_seen[10] = { false };
		bool repeated = false;
		bool repeated_digits[10] = { false };
		int digit;

		while (n > 0) {
			digit = n % 10;
			if (digit_seen[digit]) {
				repeated_digits[digit] = true;
				repeated = true;
			}
			digit_seen[digit] = true;
			n /= 10;
		}

		if (repeated) {
			printf("Repeated digit: ");
			for (int i = 0; i < 10; i++) {
				if (repeated_digits[i]) {
					printf("%d ", i);
					repeated_digits[i] = false;
				}
			}
			printf("\n");
		}
		else {
			printf("No repeated digit\n");
		}
	}
	return 0;
}