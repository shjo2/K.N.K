#include <stdio.h>
#include <math.h>
#pragma warning (disable : 4996)

int main() {
	int x;
	double y = 1;

	printf("Enter a positive number: ");
	scanf("%d", &x);

	double new_y = (y + x / y) / 2.0;
	while (fabs(y - new_y) > 0.00001 * y) {
		y = new_y;
		new_y = (y + x / y) / 2.0;
	}

	printf("Square root: %.5lf", new_y);

	return 0;
}