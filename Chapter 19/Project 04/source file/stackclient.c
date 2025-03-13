#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackADT3.h"

int main() {
    Stack s1 = create();
    Stack s2 = create();

    char* str1 = malloc(strlen("Hello") + 1);
    char* str2 = malloc(strlen("World") + 1);
    strcpy(str1, "Hello");
    strcpy(str2, "World");

    push(s1, str1);
    push(s2, str2);

    printf("s1 length: %d\n", length(s1));
    printf("s2 length: %d\n", length(s2));

    char* popped_str = (char*)pop(s1);
    printf("%s\n", popped_str);
    free(popped_str);

    destroy(s1);
    destroy(s2);
    free(str1);
    free(str2);

    return 0;
}