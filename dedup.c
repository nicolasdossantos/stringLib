#include "my_str.h"

char *dedup(char *s) {
#define NO_OF_CHARS 256
#define bool int

    char *newString = s;

    bool bin_hash[NO_OF_CHARS] = {0};
    int ip_ind = 0, res_ind = 0;
    char temp;

    while (*(newString + ip_ind)) {
        temp = *(newString + ip_ind);
        if (bin_hash[temp] == 0) {
            bin_hash[temp] = 1;
            *(newString + res_ind) = *(newString + ip_ind);
            res_ind++;
        }
        ip_ind++;
    }

    *(newString + res_ind) = '\0';

    return newString;
}