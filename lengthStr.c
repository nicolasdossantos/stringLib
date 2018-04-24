#include "my_str.h"

int lengthStr(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }

    return i;
}