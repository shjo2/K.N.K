#include <stdio.h>
#include <string.h> 
#include <stdbool.h>
#include <ctype.h>

#define MESSAGE_SIZE 100

bool is_palindrome(const char* message) {
	bool isPalindrome = true;
	char* left = message;
	char* right = message + strlen(message) - 1;

	int i = 0;
	while (left < right) {
		while (!isalpha(*left) && left < right) {
			left++;
		}

		while (!isalpha(*right) && left < right) {
			right--;
		}

		if (tolower(*left) != tolower(*right)) {
			isPalindrome = false;
			break;
		}

		left++;
		right--;
	}

	return isPalindrome;
}

int main(void) {
	char message[MESSAGE_SIZE];

	printf("Enter a message: ");
	if (fgets(message, MESSAGE_SIZE, stdin) == NULL) {
		printf("Error reading input.\n");
		return 1;
	}

	message[strcspn(message, "\n")] = 0;

	if (is_palindrome(message))
		printf("Palindrome\n");
	else
		printf("Not a Palindrome");

	return 0;
}