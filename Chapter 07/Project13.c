#include <stdio.h>
#include <string.h>
#include <ctype.h>
#pragma warning (disable : 4996)
#define MAX_SENTENCE 100

int main() {
	char sentence[MAX_SENTENCE];
	int word_count = 0;
	int totalLength = 0;
	double average = 0;

	printf("Enter an expression: ");
	fgets(sentence, MAX_SENTENCE, stdin);

	int sentence_len = strlen(sentence);

	if (sentence_len > 0 && sentence[sentence_len - 1] == '\n') {
		sentence[sentence_len - 1] = '\0';
		sentence_len--;
	}

	int i = 0;
	while (sentence[i] != '\0') {
		if (isspace(sentence[i])) {
			word_count++;
		}
		i++;
	}
	word_count++;

	int j = 0;
	while (sentence_len > j) {
		if (!isspace(sentence[j])) {
			totalLength++;
		}
		j++;
	}

	average = (double)totalLength / word_count;

	printf("Average word length: %.1f", average);
	return 0;
}