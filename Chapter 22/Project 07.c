#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void compress_file(char* input_file) {
	FILE* input_fp;
	FILE* output_fp;
	char output_file[BUFSIZ];
	char current_bytes;
	char previous_bytes;
	int count = 0;

	snprintf(output_file, sizeof(output_file), "%s.rle", input_file);

	input_fp = fopen(input_file, "rb");
	if (input_fp == NULL) {
		fprintf(stderr, "Error: Can`t open file %s\n", input_file);
		exit(EXIT_FAILURE);
	}

	output_fp = fopen(output_file, "wb");
	if (output_fp == NULL) {
		fprintf(stderr, "Error: Can`t open file %s\n", output_file);
		exit(EXIT_FAILURE);
	}

	if (fread(&previous_bytes, 1, 1, input_fp) == 1) {
		count = 1;

		while ((fread(&current_bytes, 1, 1, input_fp)) == 1) {
			if (previous_bytes == current_bytes) {
				if (count < INT_MAX) {
					count++;
				}
				else {
					fwrite(&count, sizeof(int), 1, output_fp);
					fwrite(&previous_bytes, sizeof(char), 1, output_fp);
					previous_bytes = current_bytes;
					count = 1;
				}
			}
			else {
				fwrite(&count, sizeof(int), 1, output_fp);
				fwrite(&previous_bytes, sizeof(char), 1, output_fp);
				previous_bytes = current_bytes;
				count = 1;
			}
		}
	}
	fwrite(&count, sizeof(int), 1, output_fp);
	fwrite(&previous_bytes, sizeof(char), 1, output_fp);

	fclose(input_fp);
	fclose(output_fp);
}

void uncompress_file(char* input_file) {
	FILE* input_fp;
	FILE* output_fp;
	char output_file[BUFSIZ];
	char byte;
	int count;

	snprintf(output_file, sizeof(output_file), "%s", input_file);
	char* ext = strstr(output_file, ".rle");
	if (ext != NULL)
		*ext = '\0';

	input_fp = fopen(input_file, "rb");
	if (input_fp == NULL) {
		fprintf(stderr, "Error: Can`t open file %s\n", input_file);
		exit(EXIT_FAILURE);
	}

	output_fp = fopen(output_file, "wb");
	if (output_fp == NULL) {
		fprintf(stderr, "Error: Can`t open file %s\n", output_file);
		exit(EXIT_FAILURE);
	}

	while ((fread(&count, sizeof(int), 1, input_fp)) == 1) {
		if (fread(&byte, sizeof(char), 1, input_fp) != 1) {
			fclose(input_fp);
			fclose(output_fp);
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i < count; i++)
			fwrite(&byte, sizeof(char), 1, output_fp);
	}

	fclose(input_fp);
	fclose(output_fp);
}

int main(int argc, char* argv[]) {

	if (argc != 3) {
		fprintf(stderr, "usage: <filename> ...\n");
		exit(EXIT_FAILURE);
	}

	if (strcmp(argv[1], "compress_file") == 0) {
		compress_file(argv[2]);
	}
	else if (strcmp(argv[1], "uncompress_file") == 0) {
		uncompress_file(argv[2]);
	}
	else {
		fprintf(stderr, "Invalid: %s\n", argv[1]);
	}

	return 0;
}