#include "my_str.h"

int len_diff(char *s1, char *s2) {
    size_t length = lengthStr(s1) - lengthStr(s2);

    return (int) length;
}