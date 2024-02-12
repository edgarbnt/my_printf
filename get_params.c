/*
** EPITECH PROJECT, 2023
** get_params
** File description:
** Placeholder
*/

#include <stdarg.h>
#include <stdlib.h>
#include "include/my.h"

int len_nbr2(int nbr)
{
    int ret = 0;

    if (nbr == 0)
        return 1;
    while (nbr != 0) {
        ret++;
        nbr /= 10;
    }
    return ret;
}

void get_params(params_t *params, const char *restrict str)
{
    int j = 0;
    int *preci = malloc(sizeof(int));

    params->flags = get_flags(str);
    for (int i = 0; is_flag(str[i]); i++)
        j++;
    params->width = (str[j] >= 48 && str[j] <= 57) ? my_getnbr(&str[j]) : 0;
    j += (str[j] >= 48 && str[j] <= 57) ? len_nbr(my_getnbr(&str[j])) : 0;
    if (str[j] == '.' && str[j + 1] >= 48 && str[j + 1] <= 57) {
        *preci = my_getnbr(str + j + 1);
        params->precision = preci;
        j += len_nbr(my_getnbr(str + j + 1)) + 1;
    } else {
        j += (str[j] == '.') ? 1 : 0;
        params->precision = 0;
    }
    params->length = get_length(&str[j]);
    if (get_length(&str[j]) != 0)
        j += (get_length(&str[j]) > 2) ? 1 : 2;
    params->specifier = get_specifier(str[j]);
}
