#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MESSAGE_SIZE 100

int main(void) {
	char message[MESSAGE_SIZE];

	printf("Enter message: ");
	fgets(message, MESSAGE_SIZE, stdin);

	message[strcspn(message, "\n")] = 0;

	int i = 0;
	while (message[i] != '\0') {
		message[i] = toupper(message[i]);

		switch (message[i]) {
		case 'A':
			message[i] = '4';
			break;
		case 'B':
			message[i] = '8';
			break;
		case 'E':
			message[i] = '3';
			break;
		case 'I':
			message[i] = '1';
			break;
		case 'O':
			message[i] = '0';
			break;
		case 'S':
			message[i] = '5';
			break;
		}
		printf("%c", message[i]);
		i++;
	}

	printf("!!!!!!!!!!\n");

	return 0;
}