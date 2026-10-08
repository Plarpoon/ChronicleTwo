#include "mg_drawprim.hpp"

void mgCDrawPrim::Data0(float *data) {
    int *destination = reinterpret_cast<int *>(write);
    write++;
    destination[0] = static_cast<int>(data[0]);
    destination[1] = static_cast<int>(data[1]);
    destination[2] = static_cast<int>(data[2]);
    destination[3] = static_cast<int>(data[3]);
}

void mgCDrawPrim::Data4(float *data) {
    int *destination = reinterpret_cast<int *>(write);
    write++;
    destination[0] = static_cast<int>(data[0] * 16.0f);
    destination[1] = static_cast<int>(data[1] * 16.0f);
    destination[2] = static_cast<int>(data[2] * 16.0f);
    destination[3] = static_cast<int>(data[3] * 16.0f);
}
