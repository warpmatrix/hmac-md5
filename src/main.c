#include <stdio.h>

#include "md5.h"
#include "hmac.h"

const int MAX_LEN = 1000;

int main(int argc, char const *argv[]) {
    CompVec crypt;
    char msg[MAX_LEN];
    printf("input message:\n");
    scanf("%s", msg);
    char key[blkBits << 3];
    printf("input key:\n");
    scanf("%s", key);
    hmac(msg, key, crypt, md5);
    char str[129];
    mem2Str(str, (uint8_t *)crypt);
    printf("%s\n", str);
    return 0;
}
