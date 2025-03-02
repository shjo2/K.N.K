#include <stdio.h>

typedef struct Date {
	int month;
	int day;
	int year;
}Date;

int compare_dates(Date d1, Date d2) {
	if (d1.year < d2.year) return -1;
	if (d1.year > d2.year) return 1;

	if (d1.month < d2.month) return -1;
	if (d1.month > d2.month) return 1;

	if (d1.day < d2.day) return -1;
	if (d1.day > d2.day) return 1;

	return 0;
}

int main()
{
	Date date1, date2;

	printf("Enter first date: ");
	scanf("%d/%d/%d", &date1.month, &date1.day, &date1.year);
	printf("Enter second date: ");
	scanf("%d/%d/%d", &date2.month, &date2.day, &date2.year);

	int result = compare_dates(date1, date2);

	if (result < 0) {
		printf("%.2d/%.2d/%d is earlier than %.2d/%.2d/%d\n", date1.month, date1.day, date1.year, date2.month, date2.day, date2.year);
	}
	else if (result > 0) {
		printf("%.2d/%.2d/%d is earlier than %.2d/%.2d/%d\n", date2.month, date2.day, date2.year, date1.month, date1.day, date1.year);
	}
	else {
		printf("The two dates are equal.\n");
	}

	return 0;
}