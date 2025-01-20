#include <stdio.h>
#pragma warning (disable : 4996)

int main(void) {
	int n, i;

	printf("This program prints a table of squares. \n");
	printf("Enter number of entries in table: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		printf("%d¹øÂ°: %d\n", i, i * i);


		if (i % 24 == 0) {
			printf("Press Enter to continue...\n");
			while (getchar() != '\n');
		}
	}

	return 0;
}