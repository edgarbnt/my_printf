/*
** EPITECH PROJECT, 2023
** get_specifier
** File description:
** Placeholder
*/

#include <stdarg.h>
#include <stdlib.h>
#include "include/my.h"

int get_specifier(char c)
{
    char specifiers[21] = {"ou%xXdiscpbBfFaAeEgGn"};

    for (int i = 0; i < 20; i++) {
        if (c == specifiers[i]) {
            return i;
        }
    }
    return 0;
}
