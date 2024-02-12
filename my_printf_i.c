/*
** EPITECH PROJECT, 2023
** printf i
** File description:
** placeholder
*/

#include <inttypes.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"

static char *getargi_tt(va_list list, params_t params, to_print_t *to_print)
{
    ptrdiff_t nb = va_arg(list, long int);

    return my_putnbr_str_double(nb, to_print);
}

static char *getargi_z(va_list list, params_t params, to_print_t *to_print)
{
    size_t nb = va_arg(list, long int);

    return my_putnbr_str_double(nb, to_print);
}

static char *getargi_j(va_list list, params_t params, to_print_t *to_print)
{
    uintmax_t nb = va_arg(list, long int);

    return my_putnbr_str_double(nb, to_print);
}

static char *getargi_ll(va_list list, params_t params, to_print_t *to_print)
{
    long long int nb = va_arg(list, long long int);

    return my_putnbr_str_double(nb, to_print);
}

char *getargi_l(va_list list, params_t params, to_print_t *to_print)
{
    long int nb = va_arg(list, long int);

    return my_putnbr_str_double(nb, to_print);
}

char *getargi_h(va_list list, params_t params, to_print_t *to_print)
{
    short int nb = va_arg(list, int);

    return my_putnbr_str_double(nb, to_print);
}

char *getargi_hh(va_list list, params_t params, to_print_t *to_print)
{
    char nb = va_arg(list, int);

    return my_putnbr_str_double(nb, to_print);
}

static char *getargi_c(va_list list, params_t params, to_print_t *to_print)
{
    int nb = va_arg(list, int);

    return my_putnbr_str_double(nb, to_print);
}

int my_printf_i(va_list list, params_t *params)
{
    int count = 0;
    char *(*getargi[9])(va_list, params_t, to_print_t *) = {&getargi_c,
        &getargi_hh, &getargi_ll, &getargi_h, &getargi_l, &getargi_tt,
        &getargi_c, &getargi_j, &getargi_z};
    to_print_t to_print = initialize_to_print();

    params->length = (params->length == 10) ? 2 : params->length;
    params->length = (params->length == 9) ? 8 : params->length;
    to_print.arg = getargi[params->length](list, *params, &to_print);
    to_print.arg = (to_print.arg[0] == '0' && params->precision != 0)
        ? 0 : to_print.arg;
    if (params->precision != 0)
        min_digits_precision(&to_print.arg, *params->precision);
    do_flags(&to_print, *params);
    count += write_struct(to_print);
    return count;
}
