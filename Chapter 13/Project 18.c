#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATE_SIZE 100

int main(void) {
	char date[DATE_SIZE];
	const char* month_names[] = {
	"January", "February", "March", "April", "May", "June",
	"July", "August", "September", "October", "November", "December"
	};
	int month;
	int day;
	int year;
	char* token;
	const char* delimiter = "/";

	printf("Enter a date (mm/dd/yyyy): ");
	if (fgets(date, DATE_SIZE, stdin) == NULL) {
		printf("Error reading input\n");
		return 1;
	};

	date[strcspn(date, "\n")] = 0;

	token = strtok(date, delimiter);
	if (token == NULL) {
		printf("Error Invalid date");
		return 1;
	}
	month = atoi(token);
	if (month < 1 || month > 12) {
		printf("Error Invalid month");
		return 1;
	}

	token = strtok(NULL, delimiter);
	if (token == NULL) {
		printf("Error Invalid date");
		return 1;
	}
	day = atoi(token);
	if (day < 1 || day > 31) {
		printf("Error Invalid day");
		return 1;
	}

	token = strtok(NULL, delimiter);
	if (token == NULL) {
		printf("Error Invalid date");
		return 1;
	}
	year = atoi(token);

	printf("You entered the date %s %d, %d\n", month_names[month - 1], day, year);

	return 0;
}