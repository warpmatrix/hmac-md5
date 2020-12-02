#include "hmac.h"

#include "memory.h"

int hashBits = 128;

uint32_t *hmac(const char *msg, const char *key, uint32_t *crypt,
    uint32_t *hashFunc(uint32_t *crypt, const char *msg)) {
    int msgLen = strlen(msg);
    int keyLen = strlen(key);
    const int blkLen = blkBits >> 3;
    if (keyLen > blkLen) return NULL;

    uint8_t kplus[blkLen];
    memset(kplus, 0, sizeof(kplus));
    memcpy(kplus, key, keyLen);

    uint8_t ipad[blkLen];
    uint8_t opad[blkLen];
    // 0b00110110 = 0x36
    memset(ipad, 0x36, sizeof(ipad));
    // 0b01011100 = 0x5C
    memset(opad, 0x5C, sizeof(opad));

    uint8_t si[blkLen];
    uint8_t so[blkLen];
    for (int i = 0; i < blkLen; i++) {
        si[i] = ipad[i] ^ kplus[i];
        so[i] = opad[i] ^ kplus[i];
    }
    
    uint8_t iBuf[blkLen + msgLen + 1];
    memcpy(iBuf, si, sizeof(si));
    strcpy(&iBuf[blkLen], msg);
    uint32_t hashBuf[hashBits >> 5];
    hashFunc(hashBuf, iBuf);

    uint8_t oBuf[blkLen + (hashBits >> 3) + 1];
    memcpy(oBuf, so, sizeof(so));
    memcpy(&oBuf[blkLen], hashBuf, sizeof(hashBuf));
    oBuf[blkLen + (hashBits >> 3)] = '\0';
    hashFunc(crypt, oBuf);
    return crypt;
}
