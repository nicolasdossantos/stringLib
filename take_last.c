#include "my_str.h"

void take_last(char *s, int n) {
    size_t rest = lengthStr(s);
    int difference = (int) lengthStr(s) - n;
    if (n < (int) lengthStr(s)) {
        for (int i = difference, j = 0; i < lengthStr(s); i++, j++) {
            s[j] = s[i];

        }

        //printf("%d", difference);
        for (int x = n; x < lengthStr(s); x++) {
            s[x] = NULL;
        }
    }
}