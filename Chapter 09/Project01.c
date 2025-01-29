#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

#define MAX_SIZE 5


void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selection_sort(int* arr, int size) {
	int j;
	int maxIndex = 0;

	if (size <= 1)
		return;

	for (j = 0; j < size; j++) {
		if (arr[maxIndex] < arr[j])
			maxIndex = j;
	}

	if (maxIndex != size - 1) {
		swap(&arr[maxIndex], &arr[size - 1]);
	}

	selection_sort(arr, size - 1);
}


void display(int* numbers, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", numbers[i]);
	}

	printf("\n");
}

int main() {
	int numbers[MAX_SIZE] = { 0 };
	int i = 0;

	printf("Enter %d integers: ", MAX_SIZE);
	for (i = 0; i < MAX_SIZE; i++)
		scanf("%d", &numbers[i]);

	selection_sort(numbers, MAX_SIZE);

	printf("Sorted array (Selection Sort): ");
	display(numbers, MAX_SIZE);

	return 0;
}