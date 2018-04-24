#include "my_str.h"

void capitalize(char *s) {
    s[0] = toupper(s[0]);
    for (int i = 1; i < lengthStr(s); i++) {
        if (isspace(s[i - 1])) {
            s[i] = toupper(s[i]);
        } else {
            s[i] = tolower(s[i]);
        }
    }
}