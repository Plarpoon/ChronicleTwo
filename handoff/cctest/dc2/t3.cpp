extern "C" int printf(const char*, ...);
class mgCMemory {
public:
    char m0; int m4; int m8; int mc;
    int m10; void* m14; int m18; int m1c;
    void* m20; int m24; int m28; mgCMemory* m2c;
    void EndStackMode();
    void* stAllocTest(int);
};
void mgCMemory::EndStackMode() {
    if (m2c != 0) {
        m2c->m4 = m24 + m2c->m4;
        m2c = 0; m20 = 0; m28 = 0; m24 = 0;
    }
}
void* mgCMemory::stAllocTest(int n) {
    if (m1c == 0) {
        int top = m24;
        if (top + n < m28) {
            return (char*)m20 + top * 16;
        }
        printf("stack over\n");
        return 0;
    }
    return 0;
}
float abs(float f) {
    float r = f;
    if (r < 0.0f) r = -r;
    return r;
}
static unsigned short GetCRC(unsigned char* p, int n) {
    unsigned short crc = 0xffff;
    for (unsigned int i = 0; i < n; i++) {
        crc ^= p[i] << 8;
        for (unsigned int j = 0; j < 8; j++) {
            if (crc & 0x8000) crc = (crc << 1) ^ 0x1021;
            else crc <<= 1;
        }
    }
    return ~crc;
}
int use3(unsigned char* p) { return GetCRC(p, 4); }
