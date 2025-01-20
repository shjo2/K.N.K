#include <stdio.h>
#include <ctype.h>
#include <string.h>
#pragma warning (disable : 4996)

int main()
{
	const int WORD_SIZE = 100;
	char sentence[WORD_SIZE];
	int count = 0;

	printf("Enter a sentence: ");
	fgets(sentence, sizeof(sentence), stdin);

	for (int i = 0; i < strlen(sentence); i++) {
		char ch = towlower(sentence[i]);
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
			count++;
	}

	printf("Your sentence contains %d vowels.", count);

	return 0;
}