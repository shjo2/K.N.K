#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int roll_dice(void) {
	int dice1, dice2;

	dice1 = rand() % 6 + 1;
	dice2 = rand() % 6 + 1;

	return dice1 + dice2;
}

bool play_game(void) {
	int point = 0;
	int value = 0;
	bool isWin = false;

	point = roll_dice();
	value = roll_dice();
	printf("You rolled: %d\n", point);

	if (value == 7 || value == 11) {
		printf("You win!\n");
		isWin = true;
	}
	else if (value == 2 || value == 3 || value == 12) {
		printf("You lose!\n");
		isWin = false;
	}
	else {
		point = value;
		printf("Your point is %d\n", point);

		while (true) {
			value = roll_dice();
			printf("You rolled: %d\n", value);

			if (value == point) {
				printf("You win!\n");
				isWin = true;
				break;
			}
			else if (value == 7) {
				printf("You lose!\n");
				isWin = false;
				break;
			}
		}
	}

	return isWin;
}

int main()
{
	int dice1, dice2;
	int winCount = 0;
	int loseCount = 0;
	char playAgain;

	srand((unsigned int)time(NULL));

	do {
		if (play_game()) {
			winCount++;
		}
		else {
			loseCount++;
		}
		printf("Play again? ");
		playAgain = getchar();
		while (getchar() != '\n');

	} while (playAgain != 'n' && playAgain != 'N');

	printf("Wins: %d Losses: %d", winCount, loseCount);

	return 0;
}