extern "C" int printf(const char*, ...);
class mgCMemory { public: char m0; int m4; int m8; int mc; int m10; void* m14; int m18; int m1c; void* m20; int m24; int m28; mgCMemory* m2c; void EndStackMode(); void* stAllocTest(int); };
static float sin_table_unit_1; static float SinTable[1024]; void setunit(float f) { sin_table_unit_1 = f; SinTable[0] = f; }

void mgCMemory::EndStackMode() {
    if (m2c != 0) {
        m2c->m4 -= -m24;
        m2c = 0; m20 = 0; m28 = 0; m24 = 0;
    }
}
struct blk { int a[4]; };
void* mgCMemory::stAllocTest(int n) {
    if (m1c != 0) return 0;
    int top = m24;
    int max = m28;
    n += top;
    if (n >= max) {
        printf("stack over %d %d\n", n, max);
        return 0;
    }
    return &((blk*)m20)[top];
}
float mgSinf(float a) {
    return (a < 0.0f) ? -SinTable[(int)(-a * sin_table_unit_1) % 1024] : SinTable[(int)(a * sin_table_unit_1) % 1024];
}
