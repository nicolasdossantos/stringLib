#include <stdio.h>
#include "my_str.h"

int main(void){
    printf("%s\n", repeat("hello", 3, ','));

    printf("%s\n", replace("Hello Jello", "ll", "rr"));

    char *c[] = {"Wow", "so", "amazing"};
    printf("%s\n", str_connect(c, 2, '!'));

    char *p[] = {"ab", "", "c", "d", "", "e", NULL};
    rm_empties(p);
    int i = 0;
    for (i = 0; i < 4; i++){
        printf("%s\n", p[i]);
    }

    char *s = "Woah there, buddy";
    char **chop = str_chop_all(s, ' ');
}