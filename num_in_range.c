#include "my_str.h"

int num_in_range(char *s1, char b, char t) {
    int counter = 0, i = 0;

    while (s1[i] != '\0') {
        if (tolower(s1[i]) >= b && tolower(s1[i]) <= t) {
            counter++;
        }
        i++;
    }
    return counter;
}