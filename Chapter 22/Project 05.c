#include <stdio.h>
#include <stdlib.h>

#define KEY '&'

int main(int argc, char* argv[])
{
	FILE* input_fp = NULL;
	FILE* ouput_fp = NULL;
	int orig_char, new_char;

	input_fp = fopen(argv[1], "rb");
	ouput_fp = fopen(argv[2], "wb");

	if (input_fp == NULL) {
		fprintf(stderr, "Error: Cant`t open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if (ouput_fp == NULL) {
		fprintf(stderr, "Error: Cant`t open file %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	if (argc != 3) {
		fprintf(stderr, "usage: fcat <filename> ...\n");
		exit(EXIT_FAILURE);
	}

	while ((orig_char = fgetc(input_fp)) != EOF) {
		new_char = orig_char ^ KEY;
		fputc(new_char, ouput_fp);
	}

	fclose(input_fp);
	fclose(ouput_fp);
	return 0;
}