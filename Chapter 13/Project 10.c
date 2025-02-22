#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverse_name(char* name) {
    char first_name[50];
    char last_name[50];
    int i, j, name_start = 0, name_end = -1;

    while (isspace(name[name_start])) {
        name_start++;
    }
    name_end = strlen(name) - 1;
    while (name_end > name_start && isspace(name[name_end])) {
        name_end--;
    }
    name[name_end + 1] = '\0';

    int space_index = -1;
    for (i = name_start; i <= name_end; i++) {
        if (isspace(name[i])) {
            space_index = i;
            break;
        }
    }

    if (space_index != -1) {
        for (i = name_start, j = 0; i < space_index; i++, j++) {
            first_name[j] = name[i];
        }
        first_name[j] = '\0';

        for (i = space_index + 1, j = 0; i <= name_end; i++, j++) {
            last_name[j] = name[i];
        }
        last_name[j] = '\0';

        sprintf(name, "%s, %c", last_name, first_name[0]);
    }
    else {
        printf("Invalid name format. Please enter first and last name separated by space.\n");
    }
}

int main() {
    char name[100];

    printf("Enter a name (first and last name): ");
    fgets(name, sizeof(name), stdin);

    reverse_name(name);

    printf("reverse name: %s\n", name);

    return 0;
}