#include <stdlib.h>
#include <math.h>

#define PI 3.141592654

size_t getDataSize(double duration, long sampleSize) {
    return duration * sampleSize / 1000;
}

void genFreq(float *data, double freq, double duration, long sampleSize) {
    size_t dataSize = getDataSize(duration, sampleSize);
    double samplePerCycle = sampleSize / freq;
    for (size_t i = 0; i < dataSize; i++) {
        data[i] = sin((i % samplePerCycle) / (samplePerCycle - 1) * 2 * PI);
    }
}

unsigned int gcd(unsigned int a, unsigned int b) {
    unsigned int t;
    if (b > a) {
        t = a;
        a = b;
        b = t;
    }
    while ((t = a % b) != 0) {
        a = b;
        b = t;
    }
    return a / b;
}

unsigned int lcm(unsigned int a, unsigned int b) {
    unsigned int d = gcd(a, b);
    return a * b / d;
}

#define MAX_BIN_EXP 8

int genData(char *dataIn, float *dataOut, double baseFreq, double binSize, double duration, long sampleSize, unsigned int binCountExp, unsigned int dataSize) {
    if (binCountExp > MAX_BIN_EXP) {
        return -1;
    }
    unsigned char cycle;
    unsigned int value = binSize;
    unsigned int maxValue = binSize * (2 ^ (binCountExp - 1));
    double outFreq = baseFreq;
    for (unsigned int i = 0; i < dataSize; i++) {
        cycle = 1;
        for (unsigned int j = 0; j < 8; j++) {
            if (dataIn[i] & cycle) {
                outFreq += value;
            }
            if (value == maxValue) value = binSize;
            else value *= 2;
            cycle = cycle << 2;
        }
    }
