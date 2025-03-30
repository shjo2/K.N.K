#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void dump(void);
void restore(void);

int main(void) {
    char code;
    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n');

        switch (code) {
        case 'i': insert(); break;
        case 's': search(); break;
        case 'u': update(); break;
        case 'p': print(); break;
        case 'd': dump(); break;
        case 'r': restore(); break;
        case 'q': return 0;
        default: printf("Illegal code\n");
        }
        printf("\n");
    }
}

int find_part(int number) {
    for (int i = 0; i < num_parts; i++)
        if (inventory[i].number == number)
            return i;
    return -1;
}

void insert(void) {
    int part_number;

    if (num_parts == MAX_PARTS) {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);

    if (find_part(part_number) >= 0) {
        printf("Part already exists.\n");
        return;
    }

    inventory[num_parts].number = part_number;
    printf("Enter part name: ");
    scanf("%s", inventory[num_parts].name);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);
    num_parts++;
    printf("Part added successfully.\n");
}

void search(void) {
    int part_number, i;

    printf("Enter part number: ");
    scanf("%d", &part_number);

    i = find_part(part_number);
    if (i >= 0) {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
    }
    else {
        printf("Part not found.\n");
    }
}

void update(void) {
    int part_number, i, change;

    printf("Enter part number: ");
    scanf("%d", &part_number);

    i = find_part(part_number);
    if (i >= 0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
        printf("Quantity updated.\n");
    }
    else {
        printf("Part not found.\n");
    }
}

void print(void) {
    printf("Part Number   Part Name                  Quantity on Hand\n");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < num_parts; i++) {
        printf("%7d       %-25s%11d\n",
            inventory[i].number,
            inventory[i].name,
            inventory[i].on_hand);
    }
}

void dump(void) {
    char filename[255];
    FILE* fp;

    printf("Enter name of output file: ");
    scanf("%s", filename);

    if ((fp = fopen(filename, "wb")) == NULL) {
        printf("Error: cannot open file %s\n", filename);
        return;
    }

    fwrite(&num_parts, sizeof(int), 1, fp);
    fwrite(inventory, sizeof(struct part), num_parts, fp);
    fclose(fp);
    printf("Database saved to %s\n", filename);
}

void restore(void) {
    char filename[255];
    FILE* fp;

    printf("Enter name of input file: ");
    scanf("%s", filename);

    if ((fp = fopen(filename, "rb")) == NULL) {
        printf("Error: cannot open file %s\n", filename);
        return;
    }

    fread(&num_parts, sizeof(int), 1, fp);
    fread(inventory, sizeof(struct part), num_parts, fp);
    fclose(fp);
    printf("Database loaded from %s\n", filename);
}