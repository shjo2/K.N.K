#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	char* teen_names[] = {
	"ten",
	"eleven",
	"twelve",
	"thirteen",
	"fourteen",
	"fifteen",
	"sixteen",
	"seventeen",
	"eighteen",
	"nineteen"
	};

	char* tens_names[] = {
		"",
		"",
		"twenty",
		"thirty",
		"forty",
		"fifty",
		"sixty",
		"seventy",
		"eighty",
		"ninety"
	};

	char* units_names[] = {
		"",
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine"
	};

	if (argc != 2) {
		fprintf(stderr, "Usage: program <two-digit-number>\n");
		return 1;
	}

	int number = atoi(argv[1]);

	if (number < 10 || number > 99) {
		fprintf(stderr, "Please enter a two-digit number between 10 and 99.\n");
		return 1;
	}

	int tens_digit = number / 10;
	int units_digit = number % 10;

	if (number >= 10 && number <= 19) {
		printf("%s", teen_names[units_digit]);
	}
	else {
		printf("%s", tens_names[tens_digit]);
		if (units_digit != 0)
			printf("-%s", units_names[units_digit]);
	}

	printf("\n");
	return 0;
}