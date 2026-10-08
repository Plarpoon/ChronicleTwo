#include "mg_drawprim.hpp"

void mgCDrawPrim::Data0(float *data) {
    int *destination = reinterpret_cast<int *>(write);
    write++;
    destination[0] = static_cast<int>(data[0]);
    destination[1] = static_cast<int>(data[1]);
    destination[2] = static_cast<int>(data[2]);
    destination[3] = static_cast<int>(data[3]);
}
