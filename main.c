#include <stdio.h>
#include <ctype.h>
#include <memory.h>
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







        int main() {



    return 0;
}







char *repeat(char *s, int x, char sep){

    if(s){
        int i, count = 0;

        while(s[count] != '\0'){
            ++count;
        }
        char *newArray = malloc(count * x + 1);
        if(newArray){
            char *na = newArray;
            for(i = 0; i < x; ++i){
                const char *p = s;
                while(*p){
                    *na++ = *p++;

                }
            }
            *na = '\0';
        }
        return newArray;
    }else{
        return NULL;
    }


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

    if (strlen(s1) >= strlen(s2)) {

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
    if (strlen(s) > new_len) {
        for (int j = new_len; j < strlen(s); j++) {
            s[j] = NULL;
        }
    }
}

int len_diff(char *s1, char *s2) {
    size_t length = strlen(s1) - strlen(s2);

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

        size_t size = strlen(s) - x;

        for (size_t z = strlen(s); z >= (size); z--) {
            temp[z] = NULL;
        }
    }

}

void rm_right_space(char *s) {
    size_t i = strlen(s) - 1;
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
    for (size_t i = 0; i < strlen(s); i++) {
        if (!isspace(s[i])) {
            return 0;


        }
    }
    return 1;
}

char *str_zip(char *s1, char *s2) {
    char *newString = malloc(strlen(s1) + strlen(s2));
    char *big;
    char *small;
    int i = 0, j = 0;

    int differ = (int) (strlen(s1) - strlen(s2));


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
    for (int i = 1; i < strlen(s); i++) {
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

    for (int i = 0; i < strlen(s1); i++) {
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
    size_t rest = strlen(s);
    int difference = (int) strlen(s) - n;
    if (n < (int) strlen(s)) {
        for (int i = difference, j = 0; i < strlen(s); i++, j++) {
            s[j] = s[i];

        }

        //printf("%d", difference);
        for (int x = n; x < strlen(s); x++) {
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
    if (strlen(s) % d == 0) {
        return s;
    }
    for (i = strlen(s); i < 1000; i++) {
        if (i % d == 0) {
            break;
        }

    }

    for (size_t j = strlen(s); j < i; j++) {
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

char *concat(char *source, char *dest){


    char *save = source;

    for(; *source; ++source);
    while(*source++ = *dest++);
    return(save);
}










