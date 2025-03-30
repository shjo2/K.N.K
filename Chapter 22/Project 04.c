#include <stdio.h>
#include <stdlib.h>

int count_char(FILE* fp);
int count_word(FILE* fp);
int count_line(FILE* fp);

int main(int argc, char* argv[])
{
	FILE* fp = NULL;
	int opcode;

	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "Error: Cant`t open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if (argc != 3) {
		fprintf(stderr, "usage: fcat <filename> ...\n");
		exit(EXIT_FAILURE);
	}

	opcode = atoi(argv[2]);

	switch (opcode) {
	case 1:
		printf("문자의 수: %d", count_char(fp));
		break;
	case 2:
		printf("단어의 수: %d", count_word(fp));
		break;
	case 3:
		printf("문단의 수: %d", count_line(fp));
		break;
	}

	fclose(fp);
	return 0;
}

// 글자 수
int count_char(FILE* fp) {
	char buffer[BUFSIZ];
	size_t bytes_read = 0;
	int count = 0;


	while (bytes_read = fread(buffer, 1, BUFSIZ, fp) > 0) {
		count += bytes_read;
	}

	return count;
}

// 단어 수
int count_word(FILE* fp) {
	char buffer[BUFSIZ];
	size_t bytes_read = 0;
	int count = 0;
	int i = 0;

	while (bytes_read = fread(buffer, 1, BUFSIZ, fp) > 0) {
		for (int i = 0; i < bytes_read; i++) {
			if (buffer[i] == ' ')
				count++;
		}
	}

	return count;
}

// 문단 수
int count_line(FILE* fp) {
	char buffer[BUFSIZ];
	size_t bytes_read = 0;
	int count = 0;
	int i = 0;

	while (bytes_read = fread(buffer, 1, BUFSIZ, fp) > 0) {
		for (int i = 0; i < bytes_read; i++) {
			if (buffer[i] == '\n')
				count++;
		}
	}

	return count;
}