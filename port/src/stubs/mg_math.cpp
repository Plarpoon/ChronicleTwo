#include "mg_math.hpp"

void mgFotI4(int *out, float *in) {
    for (int i = 0; i < 4; ++i) {
        out[i] = static_cast<int>(in[i] * 16.0f);
    }
}

void mgZeroVectorW(float *vector) {
    vector[0] = 0.0f;
    vector[1] = 0.0f;
    vector[2] = 0.0f;
    vector[3] = 1.0f;
}
