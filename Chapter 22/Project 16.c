#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define BLOCK_SIZE 512

int main(int argc, char* argv[]) {
    FILE* source_fp, * dest_fp;
    char buffer[BLOCK_SIZE] = { 0 };
    size_t read_bytes;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source file> <destination file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((source_fp = fopen(argv[1], "rb")) == NULL) {
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((dest_fp = fopen(argv[2], "wb")) == NULL) {
        perror(argv[2]);
        fclose(source_fp);
        exit(EXIT_FAILURE);
    }

    while ((read_bytes = fread(buffer, 1, BLOCK_SIZE, source_fp)) > 0) {
        if (fwrite(buffer, 1, read_bytes, dest_fp) != read_bytes) {
            fprintf(stderr, "Error writing to destination file\n");
            fclose(source_fp);
            fclose(dest_fp);
            exit(EXIT_FAILURE);
        }
    }

    fclose(source_fp);
    fclose(dest_fp);

    printf("File copy potentially completed from %s to %s.\n", argv[1], argv[2]);

    return EXIT_SUCCESS;
}