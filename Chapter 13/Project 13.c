#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void encrypt(char* message, int shift) {
	char* ptr = message;
	shift = (shift % 26 + 26) % 26;

	while (*ptr != '\0')
	{
		if (isalpha(*ptr))
		{
			if (isupper(*ptr))
			{
				*ptr = 'A' + (*ptr - 'A' + shift) % 26;
			}
			else
			{
				*ptr = 'a' + (*ptr - 'a' + shift) % 26;
			}
		}
		ptr++;
	}
}

int main() {
	char message[100];
	int shift = 0;

	printf("Enter message to be encrypted: ");
	fgets(message, sizeof(message) - 1, stdin);

	message[strcspn(message, "\n")] = 0;

	printf("Enter shift amount: ");
	scanf("%d", &shift);

	while (getchar() != '\n');

	encrypt(message, shift);
	printf("Encrypted message: %s\n", message);

	return 0;
}