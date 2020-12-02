#if !defined(MD5_IMPL_H)
#define MD5_IMPL_H

#include "md5.h"
#include "type.h"

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

#endif  // MD5_IMPL_H
