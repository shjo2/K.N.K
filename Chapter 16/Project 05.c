#include <stdio.h>
#include <stdlib.h>

typedef struct Time {
	int departure_time;
	int arrival_time;
}Time;

int main()
{
	Time flights[] = {
		{8 * 60, 10 * 60 + 16},
		{9 * 60 + 43, 11 * 60 + 52},
		{11 * 60 + 19, 13 * 60 + 31},
		{12 * 60 + 47, 15 * 60},
		{14 * 60, 16 * 60 + 8},
		{15 * 60 + 45, 17 * 60 + 55},
		{19 * 60, 21 * 60 + 20},
		{21 * 60 + 45, 23 * 60 + 58}
	};
	int num_flights = sizeof(flights) / sizeof(flights[0]);

	int hour, minutes;
	int time_minutes = 0;
	int minutes_diff = 24 * 60;
	int closest_flight_index = -1;

	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &hour, &minutes);

	time_minutes = hour * 60 + minutes;

	for (int i = 0; i < num_flights; i++)
	{
		int time_diff = flights[i].departure_time - time_minutes;
		time_diff = abs(time_diff);

		if (time_diff < minutes_diff) {
			minutes_diff = time_diff;
			closest_flight_index = i;
		}
	}

	if (closest_flight_index != -1) {
		Time closest_flight = flights[closest_flight_index];

		int departure_hour = closest_flight.departure_time / 60;
		int departure_minute = closest_flight.departure_time % 60;

		int arrive_hour = closest_flight.arrival_time / 60;
		int arrive_minute = closest_flight.arrival_time % 60;

		printf("Closest departure time is : %.2d:%.2d %s, arriving at %.2d:%.2d %s\n",
			departure_hour, departure_minute, departure_hour < 12 ? "am" : "pm", arrive_hour, arrive_minute, arrive_hour < 12 ? "am" : "pm");
	}
	else {
		printf("No flights found.\n");
	}

	return 0;
}