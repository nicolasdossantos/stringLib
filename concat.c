#include "my_str.h"

char *concat(char *source, char *dest) {


    char *save = source;

    for (; *source; ++source);
    while (*source++ = *dest++);
    return (save);
}