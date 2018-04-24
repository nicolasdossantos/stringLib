#include "my_str.h"

int all_letters(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        if (!isalpha(s[i])) {
            return 1;
        }
        i++;
    }

    return 0;
}