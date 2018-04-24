#include "my_str.h"

char *pad(char *s, int d) {
    char *newS = s;

    size_t i = 0;
    if (lengthStr(s) % d == 0) {
        return s;
    }
    for (i = lengthStr(s); i < 1000; i++) {
        if (i % d == 0) {
            break;
        }

    }

    for (size_t j = lengthStr(s); j < i; j++) {
        newS[j] = ' ';

    }


    return newS;
}
