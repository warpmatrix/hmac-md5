#if !defined(HMAC_H)
#define HMAC_H

#include "type.h"

extern int hashBits;

uint32_t *hmac(const char *msg, const char *key, uint32_t *crypt,
    uint32_t *hashFunc(uint32_t *crypt, const char *msg));

#endif // HMAC_H
