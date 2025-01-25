#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NUM_SIZE 5

int main(void) {
	int number[NUM_SIZE][NUM_SIZE];
	int rowSum[NUM_SIZE] = { 0 };
	int colSum[NUM_SIZE] = { 0 };

	for (int i = 0; i < 5; i++) {
		printf("Enter row %d: ", i + 1);

		for (int j = 0; j < 5; j++) {
			scanf("%d", &number[i][j]);
			rowSum[i] += number[i][j];
			colSum[j] += number[i][j];
		}
		putchar("\n");
	}


	printf("Row totals:   ");
	for (int i = 0; i < NUM_SIZE; i++)
		printf("%d ", rowSum[i]);
	printf("\nColumn totals: ");
	for (int i = 0; i < NUM_SIZE; i++)
		printf("%d ", colSum[i]);
	printf("\n");

	return 0;
}