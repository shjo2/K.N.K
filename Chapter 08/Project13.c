#include <stdio.h>
#include <ctype.h>

#define WORD_SIZE 100

int main()
{
	char name[WORD_SIZE];
	int nameSize = 0;
	int firstSize = 0;
	char firstName[WORD_SIZE] = { 0, };
	char lastName[WORD_SIZE] = { 0, };
	char firstWord;
	int lastNameSize = 0;

	printf("Enter a sentence: ");
	fgets(name, WORD_SIZE, stdin);

	nameSize = strlen(name);

	int i = 0;
	while (name[i] == ' ') {
		i++;
	}

	firstWord = name[i];

	int j = 0;
	while (name[i] != ' ' && name[i] != '\0' && name[i] != '\n')
	{
		firstName[j] = name[i];
		j++;
		i++;
	}
	name[j] = '\0';

	while (name[i] == ' ') {
		i++;
	}

	int k = 0;
	while (name[i] != '\0' && name[i] != '\n') {
		lastName[k] = name[i];
		k++;
		i++;
	}
	lastName[k] = '\0';

	printf("Reversal of sentence: \n", lastName, firstWord);

	return 0;
}