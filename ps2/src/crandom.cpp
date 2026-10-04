#include "common.h"
#include "crandom.hpp"

// Code (.text)
float CRandom::nget() {
    float sum = 0.0f;
    for (int i = 0; i < 12; i++) {
        seed = seed * 0x5D588B65 + 1;
        sum += seed / 4294967296.0f;
    }
    return sum - 6.0f;
}

#ifdef UNMATCHING
float abs(float value) {
    if (value < 0.0f) {
        value = -value;
    }
    return value;
}
#else
INCLUDE_ASM("ps2/asm/pal/nonmatchings/crandom", abs__Ff);
#endif
