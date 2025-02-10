#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MESSAGE_SIZE 100

int main(void) {
	char message[MESSAGE_SIZE];
	char *p, *q;
	bool isPalindrome = true;

	printf("Enter a message: ");
	if (fgets(message, MESSAGE_SIZE, stdin) == NULL) {
		printf("Error reading input.\n");
		return 1;
	}

	p = message;
	q = strlen(message) - 1;

	while (p < q) {
		while (p < q && isalpha(*p)) {
			p++;
		}
		while (p < q && isalpha(*q)) {
			q--;
		}

		if (tolower(*p) != tolower(*q) {
			isPalindrome = false;
			break;
		}

		p++;
		q--;
	}

	if (isPalindrome)
		printf("Palindrome\n");
	else
		printf("Not a Palindrome");

	return 0;
}