#include <stdio.h>
#include <ctype.h>
#pragma warning (disable : 4996)

#define WORD_SIZE 100

int main()
{
	char name[WORD_SIZE];
	char firstName[WORD_SIZE] = { 0, };
	char lastName[WORD_SIZE] = { 0, };
	char firstWord;

	printf("Enter a first and last name: ");
	fgets(name, WORD_SIZE, stdin);

	int i = 0;
	while (name[i] == ' ') {
		i++;
	}

	firstWord = name[0];

	int j = 0;
	while (name[i] != '\0' && name[i] != '\n') {
		if (name[i] != ' ') {
			firstName[j] = name[i];
			j++;
		}
		i++;
	}

	int k = 0;
	while (name[i] != '\0' && name[i] != '\n') {
		if (name[i] != ' ') {
			lastName[k] = name[i];
			k++;
		}
		i++;
	}

	lastName[k] = '\0';


	printf("%s, %c.\n", lastName, firstWord);

	return 0;
}