#if !defined(TYPE_H)
#define TYPE_H

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
typedef unsigned long long int uint64_t;

// length of input block (512 or 1024 bits)
extern int blkBits;
char *mem2Str(char *str, const uint8_t *mem);

#endif // TYPE_H
