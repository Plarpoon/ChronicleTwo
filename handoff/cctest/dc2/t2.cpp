extern "C" {
int printf(const char*, ...);
unsigned int strlen(const char*);
char* strcpy(char*, const char*);
}
class mgCMemory {
public:
    char m0; int m4; int m8; int mc;
    int m10; void* m14; int m18; int m1c;
    void* m20; int m24; int m28; mgCMemory* m2c;
    void EndStackMode();
    void* stAllocTest(int);
    void* Alloc(int);
};

void mgCMemory::EndStackMode() {
    if (m2c != 0) {
        int n = m24;
        m2c->m4 += n;
        m2c = 0; m20 = 0; m28 = 0; m24 = 0;
    }
}

void* mgCMemory::stAllocTest(int n) {
    if (m1c != 0) return 0;
    int top = m24;
    int max = m28;
    n += top;
    if (n >= max) {
        printf("stack over\n");
        return 0;
    }
    return (char*)m20 + top * 16;
}

char* mgCopyString(char* s, mgCMemory* mem) {
    if (s == 0 || mem == 0) return 0;
    unsigned int len = strlen(s) + 1;
    int n;
    if (len & 0xf) n = (len >> 4) + 1;
    else n = len >> 4;
    char* d = (char*)mem->Alloc(n);
    if (d == 0) return 0;
    strcpy(d, s);
    return d;
}

static float sin_table_unit_1;
static float SinTable[1024];
void setunit(float f) { sin_table_unit_1 = f; SinTable[0] = f; }

float mgSinf(float a) {
    if (!(a < 0.0f)) {
        return SinTable[(int)(a * sin_table_unit_1) % 1024];
    }
    return -SinTable[(int)(-a * sin_table_unit_1) % 1024];
}

float abs(float f) {
    if (f < 0.0f) return -f;
    return f;
}

static int GetCRC(unsigned char* p, int n) {
    unsigned int crc = 0xffff;
    for (unsigned int i = 0; i < n; i++) {
        crc ^= p[i] << 8;
        for (unsigned int j = 0; j < 8; j++) {
            if (crc & 0x8000) crc = (crc << 1) ^ 0x1021;
            else crc <<= 1;
        }
    }
    return ~crc & 0xffff;
}
int use2(unsigned char* p) { return GetCRC(p, 4); }
