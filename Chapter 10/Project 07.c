#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_DIGITS 10
#define DIGITS_HEIGHT 4
#define DIGITS_WIDTH 4

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

char digits[DIGITS_HEIGHT][MAX_DIGITS * DIGITS_WIDTH];

const unsigned char segments[] = {
    0x77, // 숫자 0
    0x24, // 숫자 1
    0x5D, // 숫자 2
    0x6D, // 숫자 3
    0x2E, // 숫자 4
    0x6B, // 숫자 5
    0x7B, // 숫자 6
    0x25, // 숫자 7
    0x7F, // 숫자 8
    0x6F  // 숫자 9
};

void clear_digits_array() {
    for (int i = 0; i < DIGITS_HEIGHT; i++) {
        for (int j = 0; j < MAX_DIGITS * DIGITS_WIDTH; j++) {
            digits[i][j] = ' ';
        }
    }
}

void process_digit(int digit, int position) {
    if (digit < 0 || digit > 9) {
        printf("잘못된 숫자: %d\n", digit);
        return;
    }

    unsigned char segment_pattern = segments[digit];
    int offset = position * DIGITS_WIDTH;

    // 세그먼트 a (상단 가로선)
    if (segment_pattern & 0x01) {
        digits[0][offset + 1] = '_';
    }

    // 세그먼트 f (좌측 상단 세로선)
    if (segment_pattern & 0x02) {
        digits[1][offset + 0] = '|';
    }
    // 세그먼트 b (우측 상단 세로선)
    if (segment_pattern & 0x04) {
        digits[1][offset + 2] = '|';
    }

    // 세그먼트 g (중앙 가로선)
    if (segment_pattern & 0x08) {
        digits[2][offset + 1] = '_';
    }

    // 세그먼트 e (좌측 하단 세로선)
    if (segment_pattern & 0x10) {
        digits[3][offset + 0] = '|';
    }

    // 세그먼트 c (우측 하단 세로선)
    if (segment_pattern & 0x20) {
        digits[3][offset + 2] = '|';
    }

    // 세그먼트 d (하단 가로선)
    if (segment_pattern & 0x40) {
        digits[3][offset + 1] = '_';
    }
}

void print_digits_array(void) {
    for (int i = 0; i < DIGITS_HEIGHT; i++) {
        for (int k = 0; k < MAX_DIGITS; k++) {
            int offset = k * DIGITS_WIDTH;
            for (int j = 0; j < DIGITS_WIDTH; j++) {
                printf("%c", digits[i][offset + j]);
            }
            if (k < MAX_DIGITS - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    char input[100];
    int position = 0;

    printf("Enter a number: ");
    fgets(input, sizeof(input), stdin);

    clear_digits_array();

    for (int i = 0; input[i] != '\0' && input[i] != '\n'; i++) {
        if (isdigit(input[i])) {
            process_digit(input[i] - '0', position++);
        }
        if (position >= MAX_DIGITS) 
            break;
    }

    print_digits_array();

    return 0;
}
