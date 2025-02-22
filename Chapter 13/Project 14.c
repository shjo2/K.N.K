#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 80
#define ALPHABET_SIZE 26

bool are_anagrams(const char* word1, const char* word2) {
	int word1AlphabetCount[ALPHABET_SIZE] = { 0 };
	int word2AlphabetCount[ALPHABET_SIZE] = { 0 };
	int index = 0;

	for (int i = 0; word1[i] != '\0'; i++) {
		if (isalpha(word1[i])) {
			index = tolower(word1[i]) - 'a';
			word1AlphabetCount[index]++;
		}
	}

	for (int i = 0; word2[i] != '\0'; i++) {
		if (isalpha(word2[i])) {
			index = tolower(word2[i]) - 'a';
			word2AlphabetCount[index]++;
		}
	}

	for (int i = 0; i < ALPHABET_SIZE; i++) {
		if (word1AlphabetCount[i] != word2AlphabetCount[i])
			return false;
	}

	return true;
}

int main() {
	char word1[MAX_WORD_LENGTH] = { 0 };
	char word2[MAX_WORD_LENGTH] = { 0 };

	printf("Enter first word: ");
	fgets(word1, MAX_WORD_LENGTH, stdin);
	word1[strcspn(word1, "\n")] = 0;

	printf("Enter second word: ");
	fgets(word2, MAX_WORD_LENGTH, stdin);
	word2[strcspn(word2, "\n")] = 0;

	if (are_anagrams(word1, word2))
		printf("The words are anagrams.\n");
	else
		printf("The words are not anagrams.\n");

	return 0;
}