/*
** EPITECH PROJECT, 2023
** my_putnbr_str_double
** File description:
** placeholder
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

double modulo_floating(double nb1, int nb2)
{
    double modulo = 0;

    if (nb1 < 0)
        nb1 = -nb1;
    if (nb2 < 0)
        nb2 = -nb2;
    for (modulo = nb1; modulo >= nb2; modulo -= nb2);
    if (nb1 < 0)
        return -modulo;
    return modulo;
}

void my_putnbr_str_double_i(double nb, int *i,
    char **str, to_print_t *to_print)
{
    int nb2 = 10;

    if (nb < 0){
        to_print->sign = '-';
        nb *= -1;
    }
    if (nb >= 10){
        my_putnbr_str_double_i(nb / 10, i, str, to_print);
        my_putnbr_str_double_i(modulo_floating(nb, nb2), i, str, to_print);
    }
    if (nb < 10 && nb >= 0){
        (*str)[(*i)] = nb + 48;
        *i = *i + 1;
    }
    return;
}

char *my_putnbr_str_double(double nb, to_print_t *to_print)
{
    int i = 0;
    char *str;

    str = malloc(sizeof(char) * (len_nbr(nb) + 3));
    my_putnbr_str_double_i(nb, &i, &str, to_print);
    str[(i) + 1] = '\0';
    return str;
}
