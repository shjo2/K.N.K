#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    struct part* next;
};

struct part* inventory = NULL;

struct part* find_part(int number);
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
        while (getchar() != '\n')
            ;
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

struct part* find_part(int number) {
    struct part* p;
    for (p = inventory; p != NULL && number > p->number; p = p->next)
        ;
    if (p != NULL && number == p->number)
        return p;
    return NULL;
}

void insert(void) {
    struct part* cur, * prev, * new_node;

    new_node = malloc(sizeof(struct part));
    if (new_node == NULL) {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &new_node->number);

    for (cur = inventory, prev = NULL;
        cur != NULL && new_node->number > cur->number;
        prev = cur, cur = cur->next)
        ;

    if (cur != NULL && new_node->number == cur->number) {
        printf("Part already exists.\n");
        free(new_node);
        return;
    }

    printf("Enter part name: ");
    scanf("%s", new_node->name);
    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->on_hand);

    new_node->next = cur;
    if (prev == NULL)
        inventory = new_node;
    else
        prev->next = new_node;
}

void search(void) {
    int number;
    struct part* p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL) {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->on_hand);
    }
    else {
        printf("Part not found.\n");
    }
}

void update(void) {
    int number;
    struct part* p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &number);
        p->on_hand += number;
    }
    else {
        printf("Part not found.\n");
    }
}

void print(void) {
    struct part* p;
    printf("Part Number   Part Name                  Quantity on Hand\n");
    for (p = inventory; p != NULL; p = p->next)
        printf("%7d       %-25s%11d\n", p->number, p->name, p->on_hand);
}

void dump(void) {
    struct part* p;
    char filename[255];
    FILE* fp;

    printf("Enter name of output file: ");
    scanf("%s", filename);

    if ((fp = fopen(filename, "wb")) == NULL) {
        printf("Error: cannot open file %s\n", filename);
        return;
    }

    for (p = inventory; p != NULL; p = p->next) {
        fwrite(p->number, sizeof(int), 1, fp);
        fwrite(p->name, sizeof(char), NAME_LEN + 1, fp);
        fwrite(p->on_hand, sizeof(int), 1, fp);
    }

    fclose(fp);
    printf("Database saved to %s\n", filename);
}

void restore(void) {
    struct part* new_node, * prev, * cur;
    char filename[255];
    FILE* fp;

    printf("Enter name of input file: ");
    scanf("%s", filename);

    if ((fp = fopen(filename, "rb")) == NULL) {
        printf("Error: cannot open file %s\n", filename);
        return;
    }

    while (inventory != NULL) {
        struct part* temp = inventory;
        inventory = inventory->next;
        free(temp);
    }

    while (1) {
        new_node = malloc(sizeof(struct part));
        if (new_node == NULL) {
            printf("Database is full; can't add more parts.\n");
            return;
        }

        if (fread(&new_node->number, sizeof(int), 1, fp) != 1 ||
            fread(new_node->name, sizeof(char), NAME_LEN + 1, fp) != 1 ||
            fread(&new_node->on_hand, sizeof(int), 1, fp) != 1) {
            free(new_node);
            break;
        }

        for (cur = inventory, prev = NULL;
            cur != NULL && new_node->number > cur->number;
            prev = cur, cur = cur->next)
            ;

        new_node->next = cur;
        if (prev == NULL)
            inventory = new_node;
        else
            prev->next = new_node;
    }

    fclose(fp);
    printf("Database loaded from %s\n", filename);
}