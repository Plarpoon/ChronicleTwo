extern "C" {
int printf(const char*, ...);
int rand();
unsigned int strlen(const char*);
char* strcpy(char*, const char*);
float sinf(float);
}

class mgCMemory {
public:
    char m0; int m4; int m8; int mc;
    int m10; void* m14; int m18; int m1c;
    void* m20; int m24; int m28; mgCMemory* m2c;
    void Init();
    void SetHeapMem(void*, int);
    void ClearHeapMem();
    void EndStackMode();
    void* stAlloc64(int);
    void* stAllocTest(int);
    void* stAlloc(int);
    void* Alloc(int);
    void stAlign64();
    void stSetBuffer(void*, int);
};

void* MG_ADDRESS_CHECK(void* p, char* name) {
    if (p == 0) {
        printf("address error\n");
        return 0;
    }
    return p;
}

void mgCMemory::Init() {
    m10 = 0; m14 = 0; m18 = 0; m0 = 0; m20 = 0; m24 = 0; m28 = 0; m1c = 0;
}

void mgCMemory::ClearHeapMem() {
    void* p = m14;
    int n = m10;
    Init();
    SetHeapMem(p, n);
}

void mgCMemory::EndStackMode() {
    if (m2c != 0) {
        m2c->m4 += m24;
        m2c = 0; m20 = 0; m28 = 0; m24 = 0;
    }
}

void* mgCMemory::stAlloc64(int n) {
    stAlign64();
    return stAlloc(n);
}

void* mgCMemory::stAllocTest(int n) {
    if (m1c != 0) return 0;
    int top = m24;
    if (top + n >= m28) {
        printf("stack over\n");
        return 0;
    }
    return (char*)m20 + top * 16;
}

void mgCMemory::stSetBuffer(void* p, int n) {
    m20 = p; m24 = 0; m28 = n;
}

char* mgCopyString(char* s, mgCMemory* mem) {
    if (s == 0 || mem == 0) return 0;
    unsigned int len = strlen(s) + 1;
    int n = len >> 4;
    if (len & 0xf) n = (len >> 4) + 1;
    char* d = (char*)mem->Alloc(n);
    if (d == 0) return 0;
    strcpy(d, s);
    return d;
}

static float sin_table_num;
static float sin_table_unit_1;
static float SinTable[1024];

int mgAngleCmp(float a, float b, float c) {
    float d = a - b;
    if (d == 0.0f) return 0;
    if (d > 3.1415927f) d -= 6.2831855f;
    if (d < -3.1415927f) d += 6.2831855f;
    if (d > c) return 1;
    if (d < -c) return -1;
    return 0;
}

float mgAngleLimit(float a) {
    if (a < 3.1415927f && a > -3.1415927f) return a;
    a -= (float)(int)(a / 6.2831855f) * 6.2831855f;
    if (a > 3.1415927f) a -= 6.2831855f;
    if (a < -3.1415927f) a += 6.2831855f;
    return a;
}

float mgRnd() {
    return (float)rand() / 2147483648.0f;
}

float mgNRnd() {
    return mgRnd() + mgRnd() + mgRnd() + mgRnd() + mgRnd() + mgRnd() + mgRnd() + mgRnd() + mgRnd() + mgRnd() + mgRnd() + mgRnd() - 6.0f;
}

void mgCreateSinTable() {
    sin_table_num = 1024.0f;
    sin_table_unit_1 = 162.97466f;
    for (int i = 0; i < 1024; i++) {
        SinTable[i] = sinf(3.1415927f * (2.0f * (float)i) / sin_table_num);
    }
}

float mgSinf(float a) {
    if (a < 0.0f) {
        return -SinTable[(int)(-a * sin_table_unit_1) % 1024];
    }
    return SinTable[(int)(a * sin_table_unit_1) % 1024];
}

float mgCosf(float a) {
    return mgSinf(1.5707964f + a);
}

float abs(float f) {
    if (f < 0.0f) f = -f;
    return f;
}

static char txt_table[0x3a];
static unsigned int seed;

static int search_txt(char c) {
    for (int i = 0; i < 0x3a; i++) {
        if (c == txt_table[i]) return i;
    }
    return -1;
}

static unsigned short GetCRC(unsigned char* p, int n) {
    unsigned int crc = 0xffff;
    for (unsigned int i = 0; i < n; i++) {
        crc ^= p[i] << 8;
        for (unsigned int j = 0; j < 8; j++) {
            if (crc & 0x8000) crc = (crc << 1) ^ 0x1021;
            else crc <<= 1;
        }
    }
    return ~crc;
}

static unsigned int random() {
    seed = seed * 0x21FC436 + 1;
    return seed;
}

static int jrand;
static int ia[56];
void irn55();

int irnd() {
    if (++jrand > 55) {
        irn55();
        jrand = 1;
    }
    return ia[jrand];
}

float rnd() {
    return (float)irnd() / 1.0e9f;
}

int use_statics(unsigned char* p) { return search_txt(p[0]) + GetCRC(p, 4) + random(); }
