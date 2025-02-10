#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MESSAGE_SIZE 100

int main(void) {
	char message[MESSAGE_SIZE];
	int message_length = 0;
	bool isPalindrome = true;

	printf("Enter a message: ");
	if (fgets(message, MESSAGE_SIZE, stdin) == NULL) {
		printf("Error reading input.\n");
	}

	message_length = strlen(message);

	int left = 0;
	int right = message_length - 1;

	while (left < right) {
		while (!isalpha(message[left]) && left < right) {
			left++;
		}

		while (!isalpha(message[right]) && left < right) {
			right--;
		}

		if (tolower(message[left]) != tolower(message[right])) {
			isPalindrome = false;
			break;
		}

		left++;
		right--;
	}

	if (isPalindrome)
		printf("Palindrome\n");
	else
		printf("Not a Palindrome");

	return 0;
}