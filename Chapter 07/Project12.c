#pragma warning (disable : 4996)
#include <stdio.h>

#define MAX_OPERANDS 5
#define MAX_OPERATORS 4

int main()
{
	double operands[MAX_OPERANDS] = { 0, };
	char operators[MAX_OPERATORS] = { 0, };
	double result = 0;


	printf("Enter an expression: ");
	scanf("%lf %c %lf %c %lf", &operands[0], &operators[0], &operands[1], &operators[1], &operands[2]);

	result = operands[0];
	for (int i = 0; i < MAX_OPERANDS; i++) {
		switch (operators[i]) {
		case '+':
			result += operands[i + 1];
			break;
		case '-':
			result -= operands[i + 1];
			break;
		case '*':
			result *= operands[i + 1];
			break;
		case '/':
			result /= operands[i + 1];
			break;
		}
	}

	printf("Value of expression: %.1f\n", result);

	return 0;
}