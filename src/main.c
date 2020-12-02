#include <stdio.h>
#include <string.h>

#include "md5.h"

const int MAX_LEN = 1000;

int main(int argc, char const *argv[]) {
    char message[MAX_LEN];
    scanf("%s", message);
    CompVec cv;
    md5(cv, message);
    char msgDigest[129];
    cv2Str(msgDigest, cv);
    printf("%s\n", msgDigest);
    return 0;
}
