#include "my_str.h"

char *repeat(char *s, int x, char sep) {
    int count = 0;
    while (s[count] != '\0') {
        ++count;
    }
    int size = (count * x) + (count * (x - 1)) + 1;
    char *cache = calloc(size, sizeof(char));
    char *charPointer = cache;

    int i = 0;
    for (i = 0; i < x; i++) {
        if (i != 0) {
            *charPointer = sep; //copies letter
            charPointer++;
        }

        int j = 0;
        for (j = 0; j < count; j++) { //copies word
            *charPointer = s[j];
            charPointer++;
        }
    }

    *charPointer = '\0';

    return cache;

}