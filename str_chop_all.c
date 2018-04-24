#include "my_str.h"

char **str_chop_all(char *s, char c) {
    int cacheSize = 1;
    char **cache = malloc(cacheSize * sizeof(*s));
    char **pos = cache;
    int wordSize = 1;
    char *wordCache;
    int wordCachePos = 0;
    char *charPos = s;

    while (*charPos != '\0') {
        wordSize = 1;
        wordCache = malloc(wordSize * sizeof(char));
        wordCachePos = 0;

        while (*charPos != c && *charPos != '\0') {
            *(wordCache + wordCachePos) = *charPos;
            wordCache = realloc(wordCache, ++wordSize * sizeof(char));
            wordCachePos++;
            charPos++;
        }
        while (*charPos == c) {
            charPos++;
        }
        *(wordCache + wordCachePos) = '\0';
        cache = realloc(cache, ++cacheSize * sizeof(*s));
        *pos = wordCache;
        pos++;
    }

    return cache;
}