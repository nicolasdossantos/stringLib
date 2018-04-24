#include "my_str.h"

int diff(char *s1, char *s2) {
    int i = 0;
    int counter = 0;

    if (lengthStr(s1) >= lengthStr(s2)) {

        while (s1[i] != '\0') {
            if (s1[i] != s2[i]) {
                counter++;
            }
            i++;
        }
    } else {
        while (s2[i] != '\0') {
            if (s2[i] != s1[i]) {
                counter++;
            }
            i++;
        }
    }


    return counter;
}