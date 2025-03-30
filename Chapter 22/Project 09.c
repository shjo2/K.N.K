#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

int main(int argc, char* argv[]) {
    struct part part1, part2;
    FILE* src1, * src2;
    FILE* dest;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <src1> <src2> <dest>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    src1 = fopen(argv[1], "rb");
    src2 = fopen(argv[2], "rb");
    dest = fopen(argv[3], "wb");
    if (!src1 || !src2 || !dest) {
        fprintf(stderr, "file open error\n");
        if (src1)
            fclose(src1);
        if (src2)
            fclose(src2);
        if (dest)
            fclose(dest);
        exit(EXIT_FAILURE);
    }

    struct part inventory1[MAX_PARTS], inventory2[MAX_PARTS];
    int num_part1 = 0, num_part2 = 0;
    while (fread(&inventory1[num_part1], sizeof(struct part), 1, src1) == 1)
        num_part1++;
    while (fread(&inventory2[num_part2], sizeof(struct part), 1, src2) == 1)
        num_part2++;

    int i = 0, j = 0;
    while (i < num_part1 && j < num_part2) {
        if (inventory1[i].number < inventory2[j].number) {
            fwrite(&inventory1[i++], sizeof(struct part), 1, dest);
        }
        else if (inventory1[i].number > inventory2[j].number) {
            fwrite(&inventory2[j++], sizeof(struct part), 1, dest);
        }
        else {
            if (strcmp(inventory1[i].name, inventory2[j].name)) {
                fprintf(stderr, "Error: part %d mismatched",
                    inventory1[i].number);
            }
            else {
                inventory1[i].on_hand += inventory2[j].on_hand;
                fwrite(&inventory1[i], sizeof(struct part), 1, dest);
            }
        }
        i++;
        j++;
    }

    while (i < num_part1) {
        fwrite(&inventory1[i++], sizeof(struct part), 1, dest);
    }
    while (j < num_part2) {
        fwrite(&inventory2[j++], sizeof(struct part), 1, dest);
    }

    fclose(src1);
    fclose(src2);
    fclose(dest);
}