#include "my_str.h"

char *str_zip(char *s1, char *s2) {
    char *newString = malloc(lengthStr(s1) + lengthStr(s2));
    char *big;
    char *small;
    int i = 0, j = 0;

    int differ = (int) (lengthStr(s1) - lengthStr(s2));


    if (differ >= 0) {
        big = s1;
        small = s2;
    } else {
        big = s2;
        small = s1;
    }

    while (small[j] != '\0') {
        newString[i] = big[j];
        newString[i + 1] = small[j];
        i += 2;
        j++;
    }

    while (big[j] != '\0') {

        newString[i] = big[j];
        i++;
        j++;
    }

    newString[i] = '\0';
    return newString;
}