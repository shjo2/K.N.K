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

	// ���� ���� ����
	while ((ch = read_char()) == ' ');

	if (ch == EOF) {
		return 0;
	}

	// �ܾ� �б�
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