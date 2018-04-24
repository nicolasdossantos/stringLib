#include "my_str.h"

int find(char *h, char *n) {

    size_t i = 0;
    int found = 0;
    while (h[i] != '\0') {

        if (h[i] == n[0]) {
            int j = 0;
            found = 1;
            while (n[j] != '\0') {
                if (h[i + j] != n[j]) {
                    found = 0;
                    break;
                }
                j++;

            }
        }
        if (found == 1) {
            return i;

        } else {
            i++;
        }

    }
    return -1;
}