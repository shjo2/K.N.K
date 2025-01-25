#include <stdio.h>
#include <stdbool.h>

#define DIRECTION_SIZE 4
#define WALK_SIZE 10

int main(void)
{
	int row = 0;
	int col = 0;
	int next_row = 0;
	int next_col = 0;
	int randomDirection = 0;
	char randomWalk[WALK_SIZE][WALK_SIZE] = { 0 };
	int position[DIRECTION_SIZE] = { 'A' };
	bool usedPosition[WALK_SIZE][WALK_SIZE] = { false };

	srand((unsigned)time(NULL));

	for (int i = 0; i < WALK_SIZE; i++) {
		for (int j = 0; j < WALK_SIZE; j++) {
			randomWalk[i][j] = '.';
		}
	}

	randomWalk[0][0] = 'A';
	char current_char = 'B';
	usedPosition[0][0] = true;

	while (current_char <= 'Z') {
		randomDirection = rand() % DIRECTION_SIZE;

		switch (randomDirection) {
		case 0:
			next_row = row - 1;
			next_col = col;
			break;
		case 1:
			next_row = row + 1;
			next_col = col;
			break;
		case 2:
			next_row = row;
			next_col = col + 1;
			break;
		case 3:
			next_row = row;
			next_col = col - 1;
			break;
		}

		if (next_row >= 0 && next_row < 10 && next_col >= 0 && next_col < 10 && !usedPosition[next_row][next_col]) {
			row = next_row;
			col = next_col;
			randomWalk[row][col] = current_char;
			usedPosition[row][col] = true;
			current_char++;
		}
		else {
			bool blocked = true;

			// 경계 검사
			for (int i = 0; i < DIRECTION_SIZE; i++) {
				switch (i) {
				case 0:
					next_row = row - 1;
					next_col = col;
					break;
				case 1:
					next_row = row + 1;
					next_col = col;
					break;
				case 2:
					next_row = row;
					next_col = col + 1;
					break;
				case 3:
					next_row = row;
					next_col = col - 1;
					break;
				}

				if (next_row >= 0 && next_row < 10 && next_col >= 0 && next_col < 10 && !usedPosition[next_row][next_col]) {
					blocked = false;
					break;
				}
			}

			if (blocked)
				break;
		}
	}


	for (int i = 0; i < WALK_SIZE; i++) {
		for (int j = 0; j < WALK_SIZE; j++) {
			printf("%c ", randomWalk[i][j]);
		}
		printf("\n");
	}

	return 0;
}