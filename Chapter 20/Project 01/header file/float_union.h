#ifndef FLOT_UNION_H
#define FLOT_UNION_H

typedef struct {
    unsigned int fraction : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
} FloatBits;

typedef union {
    float f;
    FloatBits bits;
} FloatConverter;

#endif