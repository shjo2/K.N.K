#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	FILE* infile;
	FILE* outfile;
	int ch;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s <file name>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((infile = fopen(argv[1], "rb")) == NULL) {
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((outfile = fopen(argv[2], "wb")) == NULL) {
		perror(argv[2]);
		exit(EXIT_FAILURE);
	}

	while ((ch = fgetc(infile)) != EOF) {
		if (ch == '\r')
			continue;

		if (fputc(ch, outfile) == EOF) {
			perror("Error writing character");
			fclose(infile);
			fclose(outfile);
			exit(EXIT_FAILURE);
		}
	}

	fclose(infile);
	fclose(outfile);
	return EXIT_SUCCESS;
}