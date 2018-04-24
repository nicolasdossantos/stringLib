#include "my_str.h"

int strcmp_ign_case(char *s1, char *s2) {
    char *copy1 = s1;
    char *copy2 = s2;

    for (int i = 0; i < lengthStr(s1); i++) {
        if (tolower(s1[i] > tolower(s2[i]))) {
            return 1;
        } else if (tolower(s2[i] > tolower(s1[i]))) {
            return -1;
        } else {


        }
    }
    return 0;
}