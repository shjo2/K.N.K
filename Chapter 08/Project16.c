#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS_LENGTH 80
#define ALPHABET_SIZE 26

int main()
{
	char firstWord[MAX_WORDS_LENGTH] = { 0 };
	char secondWord[MAX_WORDS_LENGTH] = { 0 };
	int firstAlphabetCount[ALPHABET_SIZE] = { 0 };
	int secondAlphabetCount[ALPHABET_SIZE] = { 0 };
	int index = 0;
	bool isEqual = true;

	printf("Enter first word: ");
	fgets(firstWord, MAX_WORDS_LENGTH, stdin);
	printf("Enter second word: ");
	fgets(secondWord, MAX_WORDS_LENGTH, stdin);

	for (int i = 0; firstWord[i] != '\0'; i++) {
		if (isalpha(firstWord[i])) {
			index = tolower(firstWord[i]) - 'a';
			firstAlphabetCount[index]++;
		}
	}

	for (int i = 0; secondWord[i] != '\0'; i++) {
		if (isalpha(secondWord[i])) {
			index = tolower(secondWord[i]) - 'a';
			secondAlphabetCount[index]++;
		}
	}

	for (int i = 0; i < ALPHABET_SIZE; i++) {
		if (firstAlphabetCount[i] != secondAlphabetCount[i])
			isEqual = false;
	}

	if (isEqual) {
		printf("The words are anagrams.\n");
	}
	else {
		printf("The words are not anagrams.\n");
	}

	return 0;
}