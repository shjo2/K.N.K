#include <stdio.h>

#define SQUARE_SIZE 100

int main()
{
	int square[SQUARE_SIZE][SQUARE_SIZE] = { 0 };
	int row = 0, col = 0;
	int next_row, next_col;
	int size = 0;

	printf("Enter size of magic square: ");
	scanf("%d", &size);

	row = 0;
	col = size / 2;

	for (int i = 1; i <= size * size; i++) {
		next_row = row - 1;
		next_col = col + 1;

		if (next_row < 0)
			next_row = size - 1;

		if (next_col == size)
			next_col = 0;

		if (square[next_row][next_col] != 0) {
			next_row = row + 1;
			next_col = col;
		}

		square[row][col] = i;

		row = next_row;
		col = next_col;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%3d ", square[i][j]);

			if ((j + 1) % size == 0)
				printf("\n");
		}
	}

	return 0;
}