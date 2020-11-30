#if !defined(UTILS_H)
#define UTILS_H

#include "md5.h"

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
typedef unsigned long long int uint64_t;

typedef uint32_t CompVec[4];
extern const CompVec initVec;

extern uint32_t (*rndFunc[4])(uint32_t b, uint32_t c, uint32_t d);
uint32_t F(uint32_t b, uint32_t c, uint32_t d);
uint32_t G(uint32_t b, uint32_t c, uint32_t d);
uint32_t H(uint32_t b, uint32_t c, uint32_t d);
uint32_t I(uint32_t b, uint32_t c, uint32_t d);

uint32_t cirLeftShift(uint32_t num, int s);
uint32_t getTVal(int i);
uint32_t getXVal(const uint32_t *blk, int i, int j);
extern const int s[64];

extern const uint8_t paddingBlk[64];
int blk2Idx(int blkIdx);

#endif  // UTILS_H
