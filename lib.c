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

void genData(char *dataIn, float *dataOut, double baseFreq, double binSize, double duration, long sampleSize, unsigned int binCountExp, unsigned int dataSize) {
    unsigned int startBit = ;
    unsigned int endBit = 
