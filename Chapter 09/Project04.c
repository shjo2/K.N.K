#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS_LENGTH 80
#define ALPHABET_SIZE 26

void read_word(char word[], int counts[26]) {
	int index = 0;

	for (int i = 0; word[i] != '\0'; i++) {
		if (isalpha(word[i])) {
			index = tolower(word[i]) - 'a';
			counts[index]++;
		}
	}
}

bool equal_array(int counts1[26], int count2[26]) {
	bool isEqual = true;

	for (int i = 0; i < ALPHABET_SIZE; i++) {
		if (counts1[i] != count2[i]) {
			isEqual = false;
			break;
		}
	}

	return isEqual;
}

int main()
{
	char firstWord[MAX_WORDS_LENGTH] = { 0 };
	char secondWord[MAX_WORDS_LENGTH] = { 0 };
	int firstAlphabetCount[ALPHABET_SIZE] = { 0 };
	int secondAlphabetCount[ALPHABET_SIZE] = { 0 };
	bool isEqual = true;

	printf("Enter first word: ");
	fgets(firstWord, MAX_WORDS_LENGTH, stdin);
	printf("Enter second word: ");
	fgets(secondWord, MAX_WORDS_LENGTH, stdin);

	read_word(firstWord, firstAlphabetCount);
	read_word(secondWord, secondAlphabetCount);
	isEqual = equal_array(firstAlphabetCount, secondAlphabetCount);


	if (isEqual) {
		printf("The words are anagrams.\n");
	}
	else {
		printf("The words are not anagrams.\n");
	}

	return 0;
}

