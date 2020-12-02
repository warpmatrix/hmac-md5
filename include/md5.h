#if !defined(MD5_H)
#define MD5_H

#include "type.h"

typedef uint32_t CompVec[4];

uint32_t *md5(CompVec cv, const char *msg);

#endif  // MD5_H
