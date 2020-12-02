#if !defined(MD5_H)
#define MD5_H

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
typedef unsigned long long int uint64_t;

typedef uint32_t CompVec[4];

// length of input block (512 or 1024 bits)
extern int blkBits;

uint32_t *md5(CompVec cv, const char *str);
char *cv2Str(char *msgDigest, const CompVec cv);

#endif  // MD5_H
