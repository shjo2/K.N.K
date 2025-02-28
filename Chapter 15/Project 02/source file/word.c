#include <stdio.h>
#include <stdbool.h>
#include "word.h"

int read_char(void)
{
	int ch = getchar();

	if (ch == '\n' || ch == '\t')
		return ' ';

	return ch;
}

int read_word(char* word, int len)
{
	int ch, pos = 0;
	bool isTruncated = false;

	// 선행 공백 무시
	while ((ch = read_char()) == ' ');

	if (ch == EOF) {
		return 0;
	}

	// 단어 읽기
	while (ch != ' ' && ch != EOF) {
		if (pos < len - 1)
			word[pos++] = ch;

		else if (!isTruncated) {
			word[pos++] = "*";
			isTruncated = true;
		}

		ch = read_char();
	}

	word[pos] = '\0';

	return pos;
}