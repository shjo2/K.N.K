#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    double price;
};

int find_part(int number, int num_parts, struct part inventory[]);
void insert(int* num_parts, struct part inventory[]);
void search(int num_parts, struct part inventory[]);
void update(int num_parts, struct part inventory[]);
void print(int num_parts, struct part inventory[]);
void change_price(int num_parts, struct part inventory[]);
int read_line(char str[], int n);
int compare_parts(const void* p, const void* q);

int main(void) {
    struct part inventory[MAX_PARTS];
    int num_parts = 0;
    char code;

    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n');

        switch (code) {
        case 'i': insert(&num_parts, inventory);
            break;
        case 's': search(num_parts, inventory);
            break;
        case 'u': update(num_parts, inventory);
            break;
        case 'p': print(num_parts, inventory);
            break;
        case 'c': change_price(num_parts, inventory);
        case 'q': return 0;
        default: printf("Illegal code\n");
        }
        printf("\n");
    }
}

int find_part(int number, int num_parts, struct part inventory[]) {
    int i;

    for (i = 0; i < num_parts; i++) {
        if (inventory[i].number == number) {
            return i;
        }
    }
    return -1;
}

void insert(int* num_parts, struct part inventory[])
{
    struct part new_part;

    if (num_parts == MAX_PARTS) {
        printf("Database is full; can't add more parts. \n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &new_part.number);

    if (find_part(new_part.number, *num_parts, inventory) >= 0) {
        printf("Part already exists. \n");
        return;
    }

    inventory[*num_parts].number = new_part.number;
    printf("Enter part name: ");
    read_line(new_part.name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &new_part.on_hand);
    printf("Enter part price: ");
    scanf("%lf", &inventory[*num_parts].price);

    (*num_parts)++;
}

void search(int num_parts, struct part inventory[])
{
    int i, number;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number, num_parts, inventory);

    if (i >= 0) {
        printf("Part number: %s \n", inventory[i].name);
        printf("Quantity on hand: %d \n", inventory[i].on_hand);
        printf("Price: %.2f \n", inventory[i].price);
    }
    else {
        printf("Part not found. \n");
    }
}

void update(int num_parts, struct part inventory[])
{
    int i, number, change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number, num_parts, inventory);
    if (i >= 0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    }
    else {
        printf("Part not found. \n");
    }
}

int compare_parts(const void* p, const void* q) {
    struct part* p1 = (const struct part*)p;
    struct part* p2 = (const struct part*)p;

    return p1->number - p2->number;
}

void print(int num_parts, struct part inventory[])
{
    int i;

    printf("Part Number   Part Name                  "
        "Quantity on Hand\n");

    qsort(inventory, num_parts, sizeof(struct part), compare_parts);

    for (i = 0; i < num_parts; i++)
        printf("%7d       %-25s%11d\n", inventory[i].number,
            inventory[i].name, inventory[i].on_hand);
}

void change_price(int num_parts, struct part inventory[])
{
    int number, i;
    double new_price;

    printf("Enter part number: ");
    scanf("%d", &number);

    i = find_part(number, num_parts, inventory);

    if (i >= 0) {
        printf("Enter new price: ");
        scanf("%lf", &new_price);
        inventory[i].price = new_price;
        printf("Price updated.\n");
    }
    else {
        printf("Part not found.\n");
    }
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while (isspace(ch = getchar()));

    while ((ch = getchar()) != '\n') {
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';

    return i;
}