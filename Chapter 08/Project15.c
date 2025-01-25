#include <stdio.h>
#include <ctype.h>

#define MESSAGELENGTH 80

int main()
{
	char ch;
	char message[MESSAGELENGTH] = { 0 };
	char encryptedMessage[MESSAGELENGTH] = { 0 };
	int shift = 0;

	printf("Enter message to be encrypted: ");
	fgets(message, MESSAGELENGTH, stdin);
	printf("Enter shift amount (1-25): ");
	scanf("%d", &shift);
	printf("Encrypted message: ");
	for (int i = 0; i < MESSAGELENGTH; i++) {
		if ((ch = message[i]) == '\n')
			break;

		if (ch >= 'A' && ch <= 'Z') {
			encryptedMessage[i] = ((ch - 'A') + shift) % 26 + 'A';
		}
		else if (ch >= 'a' && ch <= 'z') {
			encryptedMessage[i] = ((ch - 'a') + shift) % 26 + 'a';
		}
		else {
			encryptedMessage[i] = ch;
		}
	}
	for (int i = 0; i < MESSAGELENGTH; i++) {
		printf("%c", encryptedMessage[i]);
	}

	return 0;
}