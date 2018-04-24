#include "my_str.h"

void rm_empties(char **words) {
    int counter = 0;
    int size = 0;
    char **pos = words;
    char **copyPos = words;
    char *n = *words;
    while (*pos != NULL) {
        if (**pos == '\0') {
            pos++;
            n = *pos;
        } else {
            *copyPos = n;
            copyPos++;
            pos++;
            n = *pos;
            counter++;
        }
        size++;
    }
    int i;
    //sets rest of value to null since realloc gives a SIGBART error and we haven't learned what that is
    for (i = counter; i < size; i++) {
        words[i] = NULL;
    }

}