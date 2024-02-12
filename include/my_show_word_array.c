/*
** EPITECH PROJECT, 2023
** day08
** File description:
** Placeholder
*/

#include "my.h"
#include <unistd.h>

int my_show_word_array(char const **tab)
{
    int i = 0;

    while (tab[i] != 0) {
        for (int j = 0; j < my_strlen(tab[i]); j++)
            write(1, &tab[i][j], 1);
        write(1, "\n", 1);
        i++;
    }
    return 0;
}
