/*
** EPITECH PROJECT, 2023
** getnbr str
** File description:
** getnbr str
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void my_putnbr_str_i(int nb, int *i, char **str)
{
    if (nb < 0){
        (*str)[0] = '-';
        (*i)++;
        nb *= -1;
    }
    if (nb > 10){
        my_putnbr_str_i(nb / 10, i, str);
        my_putnbr_str_i(nb % 10, i, str);
    }
    if (nb < 10 && nb >= 0){
        (*str)[(*i)] = nb + 48;
        *i = *i + 1;
    }
    return;
}

char *my_putnbr_str(int nb)
{
    int i = 0;
    char *str;

    str = malloc(sizeof(char) * (len_nbr(nb) + 3));
    my_putnbr_str_i(nb, &i, &str);
    str[(i) + 1] = '\0';
    return str;
}
