#include "type.h"

#include <stdio.h>

int blkBits = 512;

int blk2Idx(int blkIdx) { return blkIdx * blkBits / 8; }

char *mem2Str(char *str, const uint8_t *mem) {
    for (int i = 0; i < 16; i++) {
        sprintf(&str[i << 1], "%02x", mem[i]);
    }
    return str;
}
