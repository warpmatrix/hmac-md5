#include <stdio.h>
#include <string.h>

#include "md5.h"

const int MAX_LEN = 1000;

int main(int argc, char const *argv[]) {
    char message[MAX_LEN];
    scanf("%s", message);
    char hashStr[129];
    printf("%s\n", md5(hashStr, message));
    return 0;
}
