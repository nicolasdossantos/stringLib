#include "my_str.h"

void rm_right_space(char *s) {
    size_t i = lengthStr(s) - 1;
    if (isspace(s[i])) {
        while (isspace(s[i])) {

            s[i] = NULL;
            i--;
        }
    }
}