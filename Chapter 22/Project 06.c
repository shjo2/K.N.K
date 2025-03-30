#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
	FILE* fp;
	int ch;
	int offset = 0;
	int bytes_read;

	if (argc != 2) {
		fprintf(stderr, "usage: fcat <filename> ...\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "rb");
	if (fp == NULL) {
		fprintf(stderr, "Error: Cant`t open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	printf("%6s" "  " "%*s%s%*s" "  " "%10s" "\n",
		"offset",
		12, "", "bytes", 12, "",
		"characters");

	printf("%6s" "  " "%29s" "  " "%10s" "\n",
		"------", "-----------------------------", "----------");
	for (;;) {
		printf("%6d  ", offset);
		char charBuffer[10];
		int bytes_read = 0;

		for (int i = 0; i < 10; i++) {
			ch = fgetc(fp);

			if (ch == EOF)
				break;

			printf("%02X ", ch);
			charBuffer[bytes_read++] = isprint(ch) ? ch : '.';

		}
		printf("  ");

		for (int i = 0; i < bytes_read; i++) {
			printf("%c", charBuffer[i]);
		}

		printf("\n");

		if (bytes_read < 10) {
			for (int i = 0; i < (10 - bytes_read); i++)
				printf("   ");

			printf("  ");
			for (int i = 0; i < bytes_read; i++)
				printf("%c", charBuffer[i]);
		}

		charBuffer[bytes_read] = '\0';
		offset += 10;

		if (ch == EOF)
			break;
	}

	fclose(fp);
	return 0;
}