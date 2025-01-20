#include <stdio.h>
#include <ctype.h>
#pragma warning (disable : 4996)

int main()
{
	int hour, minutes;
	char am_pm;
	int sum = 0;

	printf("Enter a 12-hour time(am or pm): ");
	scanf("%d:%d %c", &hour, &minutes, &am_pm);

	while (isspace(am_pm)) {
		scanf("%c", &am_pm);
	}

	if (am_pm == 'am' || am_pm == 'AM')
		sum = hour * 60 + minutes;
	else if (am_pm == 'pm' || am_pm == 'PM')
		sum = 12 * 60 + hour * 60 + minutes;

	printf("Equivalent 24-hour time: %.2d:%.2d %c", sum / 60, sum % 60, sum / 60 < 12 ? "a.m" : "p.m");

	return 0;