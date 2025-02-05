#include <stdio.h> 
#include <stdlib.h>
#include <limits.h>

int departure_times[] = { 8 * 60, 9 * 60 + 43, 11 * 60 + 19, 12 * 60 + 47, 14 * 60, 15 * 60 + 45, 19 * 60, 21 * 60 + 45 };
int arrival_times[] = { 10 * 60 + 16, 11 * 60 + 52, 13 * 60 + 31, 15 * 60, 16 * 60 + 8, 17 * 60 + 55, 21 * 60 + 20, 23 * 60 + 58 };

void find_closest_flight(int desired_time, int* departure_time, int* arrival_time) {
	int num_flight = sizeof(departure_times) / sizeof(departure_times[0]);
	int min_difference = INT_MAX;
	int closest_departure = -1;
	int closest_arrival = -1;

	for (int i = 0; i < num_flight; i++) {
		int time_difference = abs(desired_time - departure_times[i]);

		if (time_difference < min_difference) {
			min_difference = time_difference;
			closest_departure = departure_times[i];
			closest_arrival = arrival_times[i];
		}
	}

	*departure_time = closest_departure;
	*arrival_time = closest_arrival;
}

int main()
{
	int hour, minutes;
	int sum = 0;

	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &hour, &minutes);

	sum = hour * 60 + minutes;

	int closest_departure = 0;
	int closest_arrival = 0;

	find_closest_flight(sum, &closest_departure, &closest_arrival);

	int departure_hour = closest_departure / 60;
	int departure_minute = closest_departure % 60;
	int arrival_hour = closest_arrival / 60;
	int arrival_minute = closest_arrival % 60;

	printf("Closest departure time: %d:%02d\n", departure_hour, departure_minute);
	printf("Closest arrival time: %d:%02d\n", arrival_hour, arrival_minute);

	return 0;
}