#include "my_str.h"

void shorten(char *s, int new_len) {
    if (lengthStr(s) > new_len) {
        for (int j = new_len; j < lengthStr(s); j++) {
            *(s+j) = '\0';
        }
    }

}