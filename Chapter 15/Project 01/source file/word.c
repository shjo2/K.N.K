#include <stdio.h>
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

	// 선행 공백 무시
	while ((ch = read_char()) == ' ');

	if (ch == EOF) {
		return 0;
	}

	if (ch == '\n') {
		return 0;
	}

	// 단어 읽기 부분
	while (ch != ' ' && ch != EOF && ch != '\n') {
		if (pos < len)
			word[pos++] = ch;
		ch = read_char();
	}

	word[pos] = '\0';

	return pos;
}