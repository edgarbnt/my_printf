/*
** EPITECH PROJECT, 2023
** max_digits_precision
** File description:
** Placeholder
*/

#include <inttypes.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include "include/my.h"

void min_digits_precision(char **arg, int precision)
{
    int zero_pad = precision - my_strlen(*arg);
    char *str;
    int i = 0;
    int j = 0;

    if (zero_pad <= 0)
        return;
    str = malloc(sizeof(char) * (zero_pad + my_strlen(*arg) + 1));
    for (; i < zero_pad; i++)
        str[i] = '0';
    for (; (*arg)[j] != '\0'; j++) {
        str[i + j] = (*arg)[j];
    }
    str[i + j + 1] = '\0';
    *arg = str;
}
