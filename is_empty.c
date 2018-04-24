#include "my_str.h"

int is_empty(char *s) {
    for (size_t i = 0; i < lengthStr(s); i++) {
        if (!isspace(s[i])) {
            return 0;


        }
    }
    return 1;
}