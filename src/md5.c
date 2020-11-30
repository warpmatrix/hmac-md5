#include "md5.h"

#include <stdio.h>
#include <string.h>

#include "utils.h"

int blkBits = 512;

void md5CompFunc(CompVec cv, const uint8_t *blk);
void md5LastBlk(CompVec cv, const char *msg, size_t blkCnt);
char *cv2Str(char *msgDigest, const CompVec cv);

char *md5(char *msgDigest, const char *message) {
    int len = strlen(message);
    CompVec cv;
    memcpy(cv, initVec, sizeof(cv));
    size_t blkCnt;
    for (blkCnt = 0; blk2Idx(blkCnt + 1) < len; blkCnt++) {
        md5CompFunc(cv, &message[blk2Idx(blkCnt)]);
    }
    md5LastBlk(cv, message, blkCnt);
    return cv2Str(msgDigest, cv);
}

void md5CompFunc(CompVec cv, const uint8_t *blk) {
    CompVec cv0;
    memcpy(cv0, cv, sizeof(cv0));
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 16; j++) {
            uint32_t a = cv[0], b = cv[1], c = cv[2], d = cv[3];
            uint32_t x = getXVal((const uint32_t *)blk, i, j);
            uint32_t t = getTVal(i * 16 + j);
            a += rndFunc[i](b, c, d) + x + t;
            a = b + cirLeftShift(a, s[i * 16 + j]);
            cv[0] = d, cv[1] = a, cv[2] = b, cv[3] = c;
        }
    }
    cv[0] += cv0[0], cv[1] += cv0[1], cv[2] += cv0[2], cv[3] += cv0[3];
}

void md5LastBlk(CompVec cv, const char *msg, size_t blkCnt) {
    int finBlkLen = strlen(&msg[blkCnt]);
    // blkBits / 8 * 2
    uint8_t blk[blkBits << 2];
    strcpy(blk, msg);
    // msgBits = (blkCnt * 512 + finBlkLen * 8) % 2^64
    uint64_t msgBits = (blkCnt << 9) + finBlkLen << 3;
    // if (512 - finBlkLen * 8 > 64)
    if (56 > finBlkLen) {
        // memcpy(blk, msg, (512 - 64 - finBlkLen * 8) / 8);
        memcpy(&blk[finBlkLen], paddingBlk, 56 - finBlkLen);
        uint64_t *ptr = (uint64_t *)&blk[56];
        *ptr = msgBits;
        md5CompFunc(cv, blk);
    } else {
        // memcpy(blk, paddingBlk, (512 - finBlkLen * 8 + 512 - 64) / 8);
        memcpy(&blk[finBlkLen], paddingBlk, 120 - finBlkLen);
        md5CompFunc(cv, blk);
        uint64_t *ptr = (uint64_t *)&blk[120];
        *ptr = msgBits;
        md5CompFunc(cv, &blk[64]);
    }
}

char *cv2Str(char *msgDigest, const CompVec cv) {
    msgDigest[0] = '\0';
    const uint8_t *base = (const uint8_t *)cv;
    for (int i = 0; i < 16; i++) {
        char tmp[3];
        sprintf(tmp, "%02x", base[i]);
        strcat(msgDigest, tmp);
    }
    return msgDigest;
}
