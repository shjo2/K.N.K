#include <stdio.h>
#include <ctype.h>
#pragma warning (disable : 4996)

int main()
{
	int hour, minutes;
	char am_pm;
	int sum = 0;
	int closeTime = 0;
	int departure_times[] = { 8 * 60, 9 * 60 + 43, 11 * 60 + 19, 12 * 60 + 47, 14 * 60, 15 * 60 + 45, 19 * 60, 21 * 60 + 45 };
	int arrival_times[] = { 10 * 60 + 16, 11 * 60 + 52, 13 * 60 + 31, 15 * 60, 16 * 60 + 8, 17 * 60 + 55, 21 * 60 + 20, 23 * 60 + 58 };

	printf("Enter a 12-hour time(am or pm): ");
	scanf("%d:%d %c", &hour, &minutes, &am_pm);

	while (isspace(am_pm)) {
		scanf("%c", &am_pm);
	}

	if (hour == 12)
		hour = 0;

	if (am_pm == 'am' || am_pm == 'AM' || am_pm == 'a')
		sum = hour * 60 + minutes;
	else if (am_pm == 'pm' || am_pm == 'PM' || am_pm == 'p')
		sum = 12 * 60 + hour * 60 + minutes;


	for (int i = 0; i < 8; i++)
	{
		closeTime = sum - departure_times[i];

		if (departure_times[i] < sum + closeTime && arrival_times[i] > sum + closeTime)
			printf("Closest departure time is : %.2d:%.2d %s, arriving at %.2d:%.2d %s\n", departure_times[i] / 60, departure_times[i] % 60, departure_times[i] / 60 < 12 ? "a.m" : "p.m",
				arrival_times[i] / 60, arrival_times[i] % 60, arrival_times[i] / 60 < 12 ? "a.m" : "p.m");
	}

	return 0;
}