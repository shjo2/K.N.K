#include <stdio.h>
#include "float_union.h"

int main() {
    FloatConverter converter;

    converter.bits.sign = 1;
    converter.bits.exponent = 128;
    converter.bits.fraction = 0;

    printf("Float value: %f\n", converter.f);
    return 0;
}
