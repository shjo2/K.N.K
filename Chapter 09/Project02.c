#include <stdio.h>
#include <stdlib.h>

// �ҵ漼 ��� �Լ�
double calculate_tax(double taxable_income) {
    double tax_due = 0.0;

    if (taxable_income <= 1000) {
        tax_due = taxable_income * 0.10;
    }
    else if (taxable_income <= 4000) {
        tax_due = 1000 * 0.10 + (taxable_income - 1000) * 0.15;
    }
    else if (taxable_income <= 8000) {
        tax_due = 1000 * 0.10 + +(4000 - 1000) * 0.15 + (taxable_income - 4000) * 0.25;
    }
    else {
        tax_due = 1000 * 0.10 + (4000 - 1000) * 0.15 + (8000 - 4000) * 0.25 + (taxable_income - 8000) * 0.35;
    }

    return tax_due;
}

int main() {
    double income;

    printf("���� �ҵ� �ݾ��� �Է��ϼ���: ");
    scanf("%lf", &income);

    double tax = calculate_tax(income);

    printf("���� ������: %.2f��\n", tax);

    return 0;
}