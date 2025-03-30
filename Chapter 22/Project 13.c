#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256
#define MAX_FLIGHTS 100

int main(int argc, char* argv[])
{
	FILE* fp;
	char buffer[BUFFER_SIZE];
	int dep_h, dep_m;
	int arr_h, arr_m;
	int user_hour, user_minutes;
	int departure_times[MAX_FLIGHTS] = { 0 };
	int arrival_times[MAX_FLIGHTS] = { 0 };
	int total_minutes = 0;
	int closeTime = 0;
	int flight_count = 0;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "Error: Can`t open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &user_hour, &user_minutes);

	total_minutes = user_hour * 60 + user_minutes;

	while (fgets(buffer, sizeof(buffer), fp) != NULL) {
		if (sscanf(buffer, "%d:%d %d:%d", &dep_h, &dep_m, &arr_h, &arr_m) == 4) {
			departure_times[flight_count] = dep_h * 60 + dep_m;
			arrival_times[flight_count] = arr_h * 60 + arr_m;
			flight_count++;
		}
	}
	int closest_departure_index = 0;
	int min_diff = abs(total_minutes - departure_times[0]);

	for (int i = 0; i < flight_count; i++)
	{
		closeTime = abs(total_minutes - departure_times[i]);

		if (closeTime < min_diff) {
			min_diff = closeTime;
			closest_departure_index = i;
		}
	}

	int dep_hour = departure_times[closest_departure_index] / 60;
	int dep_min = departure_times[closest_departure_index] % 60;
	int arr_hour = arrival_times[closest_departure_index] / 60;
	int arr_min = arrival_times[closest_departure_index] % 60;

	printf("Closest departure time is %.2d:%.2d %s, arriving at %.2d:%.2d %s\n",
		(dep_hour == 0 || dep_hour > 12) ? (dep_hour == 0 || dep_hour == 12 ? 12 : dep_hour - 12) : dep_hour,
		dep_min,
		(dep_hour < 12 || dep_hour == 24) ? "a.m" : "p.m",
		(arr_hour == 0 || arr_hour > 12) ? (arr_hour == 0 || arr_hour == 12 ? 12 : arr_hour - 12) : arr_hour,
		arr_min,
		(arr_hour < 12 || arr_hour == 24) ? "a.m" : "p.m");

	fclose(fp);
	return 0;
}