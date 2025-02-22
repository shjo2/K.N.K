#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 30
#define MAX_WORD_LENGTH 20

int main()
{
	char name[MAX_WORDS * MAX_WORD_LENGTH];
	char words[MAX_WORDS][MAX_WORD_LENGTH];
	int wordCount = 0;
	int i = 0;
	char ch = '\0';
	bool found_char = false;

	printf("Enter a sentence: ");
	fgets(name, MAX_WORDS * MAX_WORD_LENGTH, stdin);

	name[strcspn(name, "\n")] = 0;

	// 초기 공백 처리
	while (isspace(name[i]))
		i++;

	// 공백을 기준으로 단어 분리
	while (name[i] != '\0') {
		char word[MAX_WORD_LENGTH] = { 0 };
		int j = 0;

		while (!isspace(name[i]) && name[i] != '.' && name[i] != '?' && name[i] != '!' && name[i] != '\0') {
			word[j++] = name[i++];
		}
		word[j] = '\0';

		if (wordCount < MAX_WORDS) {
			strcpy(words[wordCount], word);
			wordCount++;
		}

		if (name[i] == '.' || name[i] == '?' || name[i] == '!') {
			ch = name[i];
			found_char = true;
			i++;
			break;
		}

		while (isspace(name[i])) {
			i++;
		}
	}

	// 분리된 단어를 역순으로 출력
	printf("Reversal of sentence: ");
	for (int i = wordCount - 1; i >= 0; i--) {
		printf("%s", words[i]);
		if (i > 0)
			printf(" ");
	}

	if (found_char)
		printf("%c\n", ch);
	else
		printf("\n");

	return 0;
}