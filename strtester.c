#include <stdio.h>
#include "my_str.h"

int main(void){


    //Test all_Letters
    printf("%d\n", all_letters("hello"));
    printf("%d\n", all_letters("Hello123"));

    //Test num_in_range
    printf("%d\n", num_in_range("hello", 'a', 'g' ));

    //Test diff
    printf("%d\n", diff("hello", "HellRaiser"));

    //Test Shorten
    char test[] = "Hello there";
    shorten(test, 4);
    puts(test);

    //Test len_diff
    printf("%d\n", len_diff("hello", "hello there"));

    //Test rm_left_space
    char spacel[] = "     Howdy";
    rm_left_space(spacel);
    puts(spacel);

    //Test rm_right_space
    char spacer[] = "Howdy     ";
    rm_right_space(spacer);
    puts(spacer);

    //Test rm_space
    char space[] = "     Howdy      ";
    rm_space(space);
    puts(space);

    //Test find
    char *original = "Hello there";
    char *sub = "there";
    printf("%d\n", find(original, sub));

    //Test ptr_to
    printf("%s\n", ptr_to(original, sub));

    //Test is_empty
    char *empty = "";
    printf("%d\n", is_empty(original));
    printf("%d\n", is_empty(empty));

    //Test str_zip
    puts(str_zip("Hello", "howdy"));

    //Test Capitalize
    char lower[] = "hey you, how are you?";
    capitalize(lower);
    puts(lower);

    //Test strcmp_ign_case
    printf("%d\n", strcmp_ign_case("Hello", "Alright"));

    //Test take_last
    char test2[] = "Hello there";
    take_last(test2, 5);
    puts(test2);

    //Test dedup
    char dd[] = "Heeello";
    puts(dedup(dd));

    //Test pad
    char c1[] = "Hi";
    puts(pad(c1, 6));

    //Test ends_with_ignore_case
    printf("%d\n", ends_with_ignore_case("running", "ing"));



    //Test repeat
    printf("%s\n", repeat("hello", 3, ','));


    //Test Replace
    printf("%s\n", replace("Hello Jello", "ll", "rr"));

    //Test str_connect
    char *c[] = {"Wow", "so", "amazing"};
    printf("%s\n", str_connect(c, 2, '!'));


    //Test rm_empties
    char *p[] = {"ab", "", "c", "d", "", "e", NULL};
    rm_empties(p);
    int i = 0;
    for (i = 0; i < 4; i++){
        printf("%s\n", p[i]);
    }

    //Test str_chop_all
    char *s = "Woah there, buddy";
    char **chop = str_chop_all(s, ' ');
    printf("%s", chop[0]);

    return 0;
}
