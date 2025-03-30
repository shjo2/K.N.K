#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	char buffer[BUFSIZ];
	FILE* fp;
	size_t bytes_read;

	if (argc < 2) {
		fprintf(stderr, "usage: fcat <filename> ...\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 1; argv[i] != NULL; i++) {
		fp = fopen(argv[i], "rb");
		if (fp == NULL) {
			fprintf(stderr, "%s can't be opened \n", argv[i]);
			continue;
		}

		while (bytes_read = fread(buffer, 1, BUFSIZ, fp) > 0) {
			if (fwrite(buffer, 1, bytes_read, stdout) != bytes_read) {
				fprintf(stderr, "fcat: write error\n");
				break;
			};
		}

		if (ferror(fp))
			fprintf(stderr, "fcat: read error\n");

		fclose(fp);
	}

	return 0;
}