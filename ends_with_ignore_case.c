#include "my_str.h"

int ends_with_ignore_case(char *s, char *suff) {
    const char *init = suff;

    while (*s) {
        while (*s == *suff) {
            if (!(*s)) {
                return 1;
            }
            s++;
            suff++;
        }
        s++;
        suff = init;
    }
    return 0;
}