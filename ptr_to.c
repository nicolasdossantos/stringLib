#include "my_str.h"

char *ptr_to(char *h, char *n) {

    register char *a, *b;


    b = n;
    if (*b == 0) {
        return h;
    }
    for (; *h != 0; h += 1) {
        if (*h != *b) {
            continue;
        }
        a = h;
        while (1) {
            if (*b == 0) {
                return h;
            }
            if (*a++ != *b++) {
                break;
            }
        }
        b = n;
    }
    return NULL;
}