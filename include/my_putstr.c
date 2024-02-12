/*
** EPITECH PROJECT, 2023
** Day_04
** File description:
** Placeholder
*/

#include <unistd.h>

int my_putstr(char const *str)
{
    char c;
    int i;

    c = *str;
    while (c != '\0') {
        write(1, &c, 1);
        str++;
        c = *str;
    }
}
