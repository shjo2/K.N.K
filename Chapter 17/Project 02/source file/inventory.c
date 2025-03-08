#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

int find_part(struct part* inventory, int num_parts, int number);
void insert(struct part* inventory, int* num_parts);
void search(struct part* inventory, int num_parts);
void update(struct part* inventory, int num_parts);
void print(struct part* inventory, int num_parts);

int main(void)
{
    struct part* inventory = NULL;
    int num_parts = 0;
    int capacity = 10;
    char code;

    inventory = (struct part*)malloc(capacity * sizeof(struct part));
    if (inventory == NULL) {
        printf("Failed to create inventory. \n");
        exit(EXIT_FAILURE);
    }

    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')
            ;
        switch (code) {
        case 'i': insert(&inventory, &num_parts, &capacity);
            break;
        case 's': search(&inventory, num_parts);
            break;
        case 'u': update(&inventory, num_parts);
            break;
        case 'p': print(&inventory, num_parts);
            break;
        case 'q': return 0;
        default:  printf("Illegal code\n");
        }
        printf("\n");
    }
}

int find_part(struct part* inventory, int num_parts, int number)
{
    int i;

    for (i = 0; i < num_parts; i++)
        if (inventory[i].number == number)
            return i;
    return -1;
}

void insert(struct part** inventory, int* num_parts, int* capacity)
{
    int part_number;

    if (*num_parts == capacity) {
        *capacity *= 2;

        struct part* temp = (struct part*)realloc(inventory, (*capacity) * sizeof(struct part));
        if (inventory == NULL) {
            printf("Failed to expand inventory. \n");
            exit(EXIT_FAILURE);
        }
        *inventory = temp;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);
    if (find_part(inventory, *num_parts, part_number) >= 0) {
        printf("Part already exists.\n");
        return;
    }

    (*inventory)[*num_parts].number = part_number;
    printf("Enter part name: ");
    read_line((*inventory)[*num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", (*inventory)[*num_parts].on_hand);
    (*num_parts)++;
}

void search(struct part* inventory, int num_parts)
{
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(inventory, num_parts, number);
    if (i >= 0) {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
    }
    else {
        printf("Part not found.\n");
    }
}

void update(struct part* inventory, int num_parts)
{
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(inventory, num_parts, number);
    if (i >= 0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    }
    else {
        printf("Part not found.\n");
    }
}

void compare(const void* p, const void* q) {
    int a = ((struct part*)p)->number;
    int b = ((struct part*)q)->number;
    return a - b;
}

void print(struct part* inventory, int num_parts)
{
    int i;

    qsort(inventory, num_parts, sizeof(struct part), compare);

    printf("Part Number   Part Name                  "
        "Quantity on Hand\n");
    for (i = 0; i < num_parts; i++)
        printf("%7d       %-25s%11d\n", inventory[i].number,
            inventory[i].name, inventory[i].on_hand);
}