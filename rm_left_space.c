#include "my_str.h"

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
        temp[y] = '\0';

//        size_t size = lengthStr(s) - x;
//
//        for (size_t z = lengthStr(s); z >= (size); z--) {
//            temp[z] = NULL;
//        }
    }

}