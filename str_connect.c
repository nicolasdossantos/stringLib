#include "my_str.h"

char *str_connect(char **strs, int n, char c) {
    int i = 0;
    int size = 1;
    char *cache = calloc(1, sizeof(char));
    int counter = 0;
    for (i = 0; i < n; i++) {
        int j = 0;
        while (*(strs[i] + j) != '\0') { //copies word
            *(cache + counter) = *(strs[i] + j);
            cache = realloc(cache, ++size * sizeof(char));
            counter++;
            j++;
        }

        if (i != n - 1) { //copies letter
            *(cache + counter) = c;
            counter++;
            cache = realloc(cache, ++size * sizeof(char));
        }
    }
    *(cache + counter) = '\0';
    return cache;
}