#include <stdio.h>

double power(double base, int exp) {
	if (exp == 0)
		return 1;
	else if (exp % 2 == 0) {
		double power_value = power(base, exp / 2);
		return power_value * power_value;
	}
	else {
		return base * power(base, exp - 1);
	}
}

int main()
{
	double x;
	int n;
	double result = 0;

	printf("밑(x) 값을 입력하세요: ");
	scanf("%lf", &x);
	printf("지수(n) 값을 입력하세요: ");
	scanf("%d", &n);

	result = power(x, n);

	printf("power value: %.2f", result);

	return 0;
}