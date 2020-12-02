#include "md5-impl.h"

#include <math.h>

const CompVec initVec = {
    0x67452301,
    0xEFCDAB89,
    0x98BADCFE,
    0x10325476,
};

uint32_t (*rndFunc[4])(uint32_t b, uint32_t c, uint32_t d) = {F, G, H, I};
inline uint32_t F(uint32_t b, uint32_t c, uint32_t d) { return b & c | ~b & d; }
inline uint32_t G(uint32_t b, uint32_t c, uint32_t d) { return b & d | c & ~d; }
inline uint32_t H(uint32_t b, uint32_t c, uint32_t d) { return b ^ c ^ d; }
inline uint32_t I(uint32_t b, uint32_t c, uint32_t d) { return c ^ (b | ~d); }

inline uint32_t cirLeftShift(uint32_t num, int s) {
    return num << s | num >> 32 - s;
}

inline uint32_t getTVal(int i) {
    return (uint32_t)(fabs(sin(i + 1)) * pow(2, 32));
}

uint32_t getXVal(const uint32_t *blk, int loopIdx, int i) {
    switch (loopIdx) {
        case 0:
            return blk[i];
        case 1:
            return blk[(1 + 5 * i) & 0xf];
        case 2:
            return blk[(5 + 3 * i) & 0xf];
        case 3:
            return blk[(7 * i) & 0xf];
    }
}

const int s[64] = {
    7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
    5, 9,  14, 20, 5, 9,  14, 20, 5, 9,  14, 20, 5, 9,  14, 20,
    4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
    6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21,
};

const uint8_t paddingBlk[64] = {0x80};
