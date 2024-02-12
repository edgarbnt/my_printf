/*
** EPITECH PROJECT, 2023
** my_printf_s
** File description:
** Placeholder
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"

char *getargs_l(va_list list, params_t params)
{
    return 0;
}

char *getargs_c(va_list list, params_t params)
{
    char *str = va_arg(list, char *);
    int precision;
    char *arg;

    precision = (params.precision != 0) ? *params.precision : my_strlen(str);
    arg = malloc(sizeof(char) * (precision + 1));
    for (int i = 0; i < precision; i++)
        arg[i] = str[i];
    arg[precision] = '\0';
    return arg;
}

int my_printf_s(va_list list, params_t *params)
{
    int count = 0;
    char *(*getargs[2])(va_list, params_t) = {&getargs_c, &getargs_l};
    to_print_t to_print = initialize_to_print();

    to_print.arg = getargs[params->length](list, *params);
    do_flags(&to_print, *params);
    count += write_struct(to_print);
    return count;
}
