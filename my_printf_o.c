/*
** EPITECH PROJECT, 2023
** printf_o
** File description:
** Placeholder
*/

#include <inttypes.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"

static char *getargo_tt(va_list list, params_t params)
{
    ptrdiff_t nb = va_arg(list, unsigned long int);
    char base[8] = "01234567";
    char *str;
    int i = 0;
    ptrdiff_t nb2 = nb;

    for (; nb2 > 0; nb2 /= 8)
        i++;
    i += (nb == 0) ? 1 : 0;
    str = malloc(sizeof(char) * (i + 1));
    for (i = 0; nb > 0; nb /= 8) {
        str[i] = base[nb % 8];
        i++;
    }
    str[0] = (i == 0) ? '0' : str[0];
    i += (nb == 0) ? 1 : 0;
    str[i] = '\0';
    my_revstr(str);
    return str;
}

static char *getargo_z(va_list list, params_t params)
{
    size_t nb = va_arg(list, unsigned long int);
    char base[8] = "01234567";
    char *str;
    int i = 0;
    size_t nb2 = nb;

    for (; nb2 > 0; nb2 /= 8)
        i++;
    i += (nb == 0) ? 1 : 0;
    str = malloc(sizeof(char) * (i + 1));
    for (i = 0; nb > 0; nb /= 8) {
        str[i] = base[nb % 8];
        i++;
    }
    str[0] = (i == 0) ? '0' : str[0];
    i += (nb == 0) ? 1 : 0;
    str[i] = '\0';
    my_revstr(str);
    return str;
}

static char *getargo_j(va_list list, params_t params)
{
    uintmax_t nb = va_arg(list, unsigned long int);
    char base[8] = "01234567";
    char *str;
    int i = 0;
    uintmax_t nb2 = nb;

    for (; nb2 > 0; nb2 /= 8)
        i++;
    i += (nb == 0) ? 1 : 0;
    str = malloc(sizeof(char) * (i + 1));
    for (i = 0; nb > 0; nb /= 8) {
        str[i] = base[nb % 8];
        i++;
    }
    str[0] = (i == 0) ? '0' : str[0];
    i += (nb == 0) ? 1 : 0;
    str[i] = '\0';
    my_revstr(str);
    return str;
}

static char *getargo_ll(va_list list, params_t params)
{
    unsigned long long int nb = va_arg(list, unsigned long long int);
    char base[8] = "01234567";
    char *str;
    int i = 0;
    unsigned long long int nb2 = nb;

    for (; nb2 > 0; nb2 /= 8)
        i++;
    i += (nb == 0) ? 1 : 0;
    str = malloc(sizeof(char) * (i + 1));
    for (i = 0; nb > 0; nb /= 8) {
        str[i] = base[nb % 8];
        i++;
    }
    str[0] = (i == 0) ? '0' : str[0];
    i += (nb == 0) ? 1 : 0;
    str[i] = '\0';
    my_revstr(str);
    return str;
}

char *getargo_l(va_list list, params_t params)
{
    unsigned long int nb = va_arg(list, unsigned long int);
    char base[8] = "01234567";
    char *str;
    int i = 0;
    unsigned long int nb2 = nb;

    for (; nb2 > 0; nb2 /= 8)
        i++;
    i += (nb == 0) ? 1 : 0;
    str = malloc(sizeof(char) * (i + 1));
    for (i = 0; nb > 0; nb /= 8) {
        str[i] = base[nb % 8];
        i++;
    }
    str[0] = (i == 0) ? '0' : str[0];
    i += (nb == 0) ? 1 : 0;
    str[i] = '\0';
    my_revstr(str);
    return str;
}

char *getargo_h(va_list list, params_t params)
{
    unsigned short int nb = va_arg(list, unsigned int);
    char base[8] = "01234567";
    char *str;
    int i = 0;
    unsigned short int nb2 = nb;

    for (; nb2 > 0; nb2 /= 8)
        i++;
    i += (nb == 0) ? 1 : 0;
    str = malloc(sizeof(char) * (i + 1));
    for (i = 0; nb > 0; nb /= 8) {
        str[i] = base[nb % 8];
        i++;
    }
    str[0] = (i == 0) ? '0' : str[0];
    i += (nb == 0) ? 1 : 0;
    str[i] = '\0';
    my_revstr(str);
    return str;
}

char *getargo_hh(va_list list, params_t params)
{
    unsigned char nb = va_arg(list, unsigned int);
    char base[8] = "01234567";
    char *str;
    int i = 0;
    unsigned char nb2 = nb;

    for (; nb2 > 0; nb2 /= 8)
        i++;
    i += (nb == 0) ? 1 : 0;
    str = malloc(sizeof(char) * (i + 1));
    for (i = 0; nb > 0; nb /= 8) {
        str[i] = base[nb % 8];
        i++;
    }
    str[0] = (i == 0) ? '0' : str[0];
    i += (nb == 0) ? 1 : 0;
    str[i] = '\0';
    my_revstr(str);
    return str;
}

static char *getargo_c(va_list list, params_t params)
{
    unsigned int nb = va_arg(list, unsigned int);
    char base[8] = "01234567";
    char *str;
    int i = 0;
    unsigned int nb2 = nb;

    for (; nb2 > 0; nb2 /= 8)
        i++;
    i += (nb == 0) ? 1 : 0;
    str = malloc(sizeof(char) * (i + 1));
    for (i = 0; nb > 0; nb /= 8) {
        str[i] = base[nb % 8];
        i++;
    }
    str[0] = (i == 0) ? '0' : str[0];
    i += (nb == 0) ? 1 : 0;
    str[i] = '\0';
    my_revstr(str);
    return str;
}

to_print_t initialize_to_print(void)
{
    to_print_t to_print;

    to_print.space = 0;
    to_print.left_pad = 0;
    to_print.sign = 0;
    to_print.alt_form = 0;
    to_print.arg = 0;
    to_print.right_pad = 0;
    return to_print;
}

int my_printf_o(va_list list, params_t *params)
{
    int count = 0;
    char *(*getargo[9])(va_list, params_t) = {&getargo_c, &getargo_hh,
        &getargo_ll, &getargo_h, &getargo_l, &getargo_tt, &getargo_c,
        &getargo_j, &getargo_z};
    to_print_t to_print = initialize_to_print();

    params->length = (params->length == 10) ? 2 : params->length;
    params->length = (params->length == 9) ? 8 : params->length;
    to_print.arg = getargo[params->length](list, *params);
    to_print.arg = (to_print.arg[0] == '0' && params->precision != 0)
        ? 0 : to_print.arg;
    if (params->precision != 0)
        min_digits_precision(&to_print.arg, *params->precision);
    do_flags(&to_print, *params);
    count += write_struct(to_print);
    return count;
}
