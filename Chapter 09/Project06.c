#include <stdio.h>
#include <math.h>

// 3x⁵ + 2x⁴ – 5x³ – x² + 7x – 6
double polynomial_compute(int x) {
	double result = 0.0;

	result += 3.0 * pow(x, 5);
	result += 2.0 * pow(x, 4);
	result -= 5.0 * pow(x, 3);
	result -= 1.0 * pow(x, 2);
	result += 7.0 * pow(x, 1);
	result -= 6.0;

	return result;
}

int main()
{
	double x;
	double polynomial_value = 0;

	printf("Enter the x: ");
	scanf("%lf", &x);

	polynomial_value = polynomial_compute(x);

	printf("result: %lf", polynomial_value);

	return 0;
}