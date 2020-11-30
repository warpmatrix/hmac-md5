#if !defined(MD5_H)
#define MD5_H

// length of input block (512 or 1024 bits)
extern int blkBits;

char *md5(char *msgDigest, const char *str);

#endif  // MD5_H
