#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


int all_letters(char *s);

int num_in_range(char *s1, char b, char t);

int diff(char *s1, char *s2);

void shorten(char *s, int new_len);

int len_diff(char *s1, char *s2);

void rm_left_space(char *s);

void rm_right_space(char *s);

void rm_space(char *s);

int find(char *h, char *n);

char *ptr_to(char *h, char *n);

int is_empty(char *s);

char *str_zip(char *s1, char *s2);

void capitalize(char *s);

int strcmp_ign_case(char *s1, char *s2);

void take_last(char *s, int n);

char *dedup(char *s);

char *pad(char *s, int d);

int ends_with_ignore_case(char *s, char *suff);

//TODO: Concat works
char *concat(char *source, char *dest);

char *repeat(char *s, int x, char sep);

char *replace(char *s, char *pat, char *rep); //TODO: This.

char *str_connect(char **strs, int n, char c);

void rm_empties(char **words);

char **str_chop_all(char *s, char c);

int lengthStr(char *s);


int main() {


    return 0;
}

int lengthStr(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }

    return i;
}


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


int all_letters(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        if (!isalpha(s[i])) {
            return 1;
        }
        i++;
    }

    return 0;
}

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

int diff(char *s1, char *s2) {
    int i = 0;
    int counter = 0;

    if (lengthStr(s1) >= lengthStr(s2)) {

        while (s1[i] != '\0') {
            if (s1[i] != s2[i]) {
                counter++;
            }
            i++;
        }
    } else {
        while (s2[i] != '\0') {
            if (s2[i] != s1[i]) {
                counter++;
            }
            i++;
        }
    }


    return counter;
}

void shorten(char *s, int new_len) {
    if (lengthStr(s) > new_len) {
        for (int j = new_len; j < lengthStr(s); j++) {
            s[j] = NULL;
        }
    }

}

int len_diff(char *s1, char *s2) {
    size_t length = lengthStr(s1) - lengthStr(s2);

    return (int) length;
}

void rm_left_space(char *s) {
    if (isspace(s[0])) {
        char *temp = s;

        int p = 0; //counter1
        int counter = 0; //counter 2
        int y = 0; //counter 3
        int x; //holder
        //Verifies where non space characters  start
        while (isspace(s[p])) {
            counter++;
            p++;
        }

        x = counter;

        while (temp[counter] != '\0') {
            temp[y] = temp[counter];
            y++;
            counter++;
        }

        size_t size = lengthStr(s) - x;

        for (size_t z = lengthStr(s); z >= (size); z--) {
            temp[z] = NULL;
        }
    }

}

void rm_right_space(char *s) {
    size_t i = lengthStr(s) - 1;
    if (isspace(s[i])) {
        while (isspace(s[i])) {

            s[i] = NULL;
            i--;
        }
    }
}

void rm_space(char *s) {
    rm_left_space(s);
    rm_right_space(s);

}

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

char *ptr_to(char *h, char *n) {

    register char *a, *b;


    b = n;
    if (*b == 0) {
        return h;
    }
    for (; *h != 0; h += 1) {
        if (*h != *b) {
            continue;
        }
        a = h;
        while (1) {
            if (*b == 0) {
                return h;
            }
            if (*a++ != *b++) {
                break;
            }
        }
        b = n;
    }
    return NULL;
}

int is_empty(char *s) {
    for (size_t i = 0; i < lengthStr(s); i++) {
        if (!isspace(s[i])) {
            return 0;


        }
    }
    return 1;
}

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

void capitalize(char *s) {
    s[0] = toupper(s[0]);
    for (int i = 1; i < lengthStr(s); i++) {
        if (isspace(s[i - 1])) {
            s[i] = toupper(s[i]);
        } else {
            s[i] = tolower(s[i]);
        }
    }
}

int strcmp_ign_case(char *s1, char *s2) {
    char *copy1 = s1;
    char *copy2 = s2;

    for (int i = 0; i < lengthStr(s1); i++) {
        if (tolower(s1[i] > tolower(s2[i]))) {
            return 1;
        } else if (tolower(s2[i] > tolower(s1[i]))) {
            return -1;
        } else {


        }
    }
    return 0;
}

void take_last(char *s, int n) {
    size_t rest = lengthStr(s);
    int difference = (int) lengthStr(s) - n;
    if (n < (int) lengthStr(s)) {
        for (int i = difference, j = 0; i < lengthStr(s); i++, j++) {
            s[j] = s[i];

        }

        //printf("%d", difference);
        for (int x = n; x < lengthStr(s); x++) {
            s[x] = NULL;
        }
    }
}

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

char *pad(char *s, int d) {
    char *new = s;

    size_t i = 0;
    if (lengthStr(s) % d == 0) {
        return s;
    }
    for (i = lengthStr(s); i < 1000; i++) {
        if (i % d == 0) {
            break;
        }

    }

    for (size_t j = lengthStr(s); j < i; j++) {
        new[j] = ' ';

    }


    return new;
}

int ends_with_ignore_case(char *s, char *suff) {
    const char *init = suff;

    while (*s) {
        while (*s == *suff) {
            if (!(*s)) {
                return 1;
            }
            s++;
            suff++;
        }
        s++;
        suff = init;
    }
    return 0;
}

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

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

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

char *concat(char *source, char *dest) {


    char *save = source;

    for (; *source; ++source);
    while (*source++ = *dest++);
    return (save);
}











