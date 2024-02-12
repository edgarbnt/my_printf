/*
** EPITECH PROJECT, 2023
** get_length
** File description:
** Placeholder
*/

#include <stdarg.h>
#include <stdlib.h>
#include "include/my.h"

int get_length(const char *restrict str)
{
    char two_char_length[2][2] = {"hh", "ll"};
    char one_char_length[8][1] = {"h", "l", "t", "L", "j", "z", "Z", "q"};

    for (int i = 0; i < 2; i++) {
        if (my_strncmp(two_char_length[i], str, 2) == 0)
            return i + 1;
    }
    for (int j = 0; j < 8; j++) {
        if (my_strncmp(one_char_length[j], str, 1) == 0)
            return j + 3;
    }
    return 0;
}
