#include <stdio.h> 
#include <stdlib.h>
#include <limits.h>

int main()
{
	int hour, minutes;
	int sum = 0;
	int closeTime = 0;
	int departure_times[] = { 8 * 60, 9 * 60 + 43, 11 * 60 + 19, 12 * 60 + 47, 14 * 60, 15 * 60 + 45, 19 * 60, 21 * 60 + 45 };
	int arrival_times[] = { 10 * 60 + 16, 11 * 60 + 52, 13 * 60 + 31, 15 * 60, 16 * 60 + 8, 17 * 60 + 55, 21 * 60 + 20, 23 * 60 + 58 };
	int num_flights = sizeof(departure_times) / sizeof(departure_times[0]);
	int min_difference = INT_MAX; // 비교를 시작할 기준값
	int closest_index = -1;

	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &hour, &minutes);

	sum = hour * 60 + minutes;

	for (int i = 0; i < num_flights; i++) {
		int difference = abs(departure_times[i] - sum);

		// 가장 가까운 출발 시간 찾기
		if (difference < min_difference) {
			min_difference = difference;
			closest_index = i;
		}
	}

	if (closest_index != -1) {
		printf("Closest departure time is: %02d:%02d %s, arriving at %02d:%02d %s\n",
			departure_times[closest_index] / 60, departure_times[closest_index] % 60, departure_times[closest_index] / 60 < 12 ? "a.m." : "p.m.",
			arrival_times[closest_index] / 60, arrival_times[closest_index] % 60, arrival_times[closest_index] / 60 < 12 ? "a.m." : "p.m.");
	}
	else {
		printf("No flights avaible.\n");
	}

	return 0;
}