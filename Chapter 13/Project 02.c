#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char str[], int n);

int main(void) {
	char reminders[MAX_REMIND][MSG_LEN + 15];
	char daytime_str[9], msg_str[MSG_LEN + 1];
	int day, month, time, i, j, num_remind = 0;

	for (;;) {
		if (num_remind == MAX_REMIND) {
			printf("-- No space left --\n");
			break;
		}

		printf("Enter month/day time and reminder: ");
		scanf("%d/%2d", &month, &day);
		scanf("%d", &time);
		if (month == 0 && day == 0 && time == 0)
			break;
		else if (day < 1 || day > 31 || month < 1 || month > 12) {
			printf("Error: Invalid month/day.\n");
			fflush(stdout);
			while (getchar() != '\n');
			continue;
		}
		else if
			(time < 0 || time > 23) {
			printf("Error: Invalid time.\n");
			while (getchar() != '\n');
			continue;
		}

		sprintf(daytime_str, "%02d/%02d %02d", month, day, time);
		read_line(msg_str, MSG_LEN);

		for (i = 0; i < num_remind; i++) {
			if (strcmp(daytime_str, reminders[i]) < 0)
				break;
		}
		for (j = num_remind; j > i; j--)
			strcpy(reminders[j], reminders[j - 1]);

		strcpy(reminders[i], daytime_str);
		strcat(reminders[i], msg_str);

		num_remind++;
	}

	printf("\nMonth/Day Time Reminder\n");
	for (i = 0; i < num_remind; i++)
		printf(" %s\n", reminders[i]);

	return 0;
}

int read_line(char str[], int n) {
	int ch, i = 0;

	while ((ch = getchar()) != '\n' && ch != EOF)
		if (i < n)
			str[i++] = ch;
	str[i] = '\0';
	return i;
}