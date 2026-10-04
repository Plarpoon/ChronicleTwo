extern "C" int printf(const char*, ...);
class mgCMemory { public: char m0; int m4; int m8; int mc; int m10; void* m14; int m18; int m1c; void* m20; int m24; int m28; mgCMemory* m2c; void EndStackMode(); void* stAllocTest(int); };
static float sin_table_unit_1; static float SinTable[1024]; void setunit(float f) { sin_table_unit_1 = f; SinTable[0] = f; }

void mgCMemory::EndStackMode() {
    mgCMemory* p = m2c;
    if (p != 0) {
        int n = m24;
        p->m4 = p->m4 + n;
        m2c = 0; m20 = 0; m28 = 0; m24 = 0;
    }
}
void* mgCMemory::stAllocTest(int n) {
    if (m1c != 0) return 0;
    int top = m24;
    if (top + n >= m28) {
        printf("stack over %d %d\n", top + n, m28);
        return 0;
    }
    return (void*)((int)m20 + (top << 4));
}
float mgSinf(float a) {
    if (a >= 0.0f) {
        return SinTable[(int)(a * sin_table_unit_1) % 1024];
    } else {
        return -SinTable[(int)(-a * sin_table_unit_1) % 1024];
    }
}
