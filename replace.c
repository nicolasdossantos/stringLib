#include "my_str.h"

char *replace(char *s, char *pat, char *rep) {
    int size = 1;
    char *cache = malloc(size * sizeof(char));
    char *cacheWriter = cache;
    char *sIterator = s;
    char *sPatChecker;
    char *patIterator = pat;
    char *repIterator = rep;

    while (*sIterator != '\0') {

        if (*sIterator == *pat) {
            //check to see if the part is equal
            int toggle = 1;
            sPatChecker = sIterator;
            while (*patIterator != '\0') {

                if (*sPatChecker == *patIterator) {
                    sPatChecker++;
                    patIterator++;
                } else {
                    toggle = 0;
                    break;
                }
            }
            patIterator = pat; //reset to beginning position

            if (toggle == 0) { //not equal to pat
                *cacheWriter = *sIterator;
                cache = realloc(cache, ++size * sizeof(char));
                cacheWriter++;
                sIterator++;
            } else { //replace pat with rep
                sIterator = sPatChecker; //pushes iterator to after pat is done
                while (*repIterator != '\0') {
                    //copies rep into cache
                    *cacheWriter = *repIterator;
                    repIterator++;
                    cacheWriter++;
                    cache = realloc(cache, ++size * sizeof(char));
                }
                repIterator = rep; //reset to beginning position
            }

        } else {
            *cacheWriter = *sIterator;
            cache = realloc(cache, ++size * sizeof(char));
            cacheWriter++;
            sIterator++;
        }
    }

    *cacheWriter = '\0';

    return cache;

}