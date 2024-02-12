/*
** EPITECH PROJECT, 2023
** my_printf_n
** File description:
** Placeholder
*/

#include <inttypes.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"

static void do_nz(va_list list, int count)
{
    size_t *ptr = va_arg(list, size_t *);

    *ptr = count;
}

static void do_nj(va_list list, int count)
{
    intmax_t *ptr = va_arg(list, intmax_t *);

    *ptr = count;
}

static void do_nt(va_list list, int count)
{
    ptrdiff_t *ptr = va_arg(list, ptrdiff_t *);

    *ptr = count;
}

static void do_nl(va_list list, int count)
{
    long *ptr = va_arg(list, long *);

    *ptr = count;
}

static void do_nh(va_list list, int count)
{
    short *ptr = va_arg(list, short *);

    *ptr = count;
}

void do_nll(va_list list, int count)
{
    long long *ptr = va_arg(list, long long *);

    *ptr = count;
}

void do_nhh(va_list list, int count)
{
    signed char *ptr = va_arg(list, signed char *);

    *ptr = count;
}

void do_nc(va_list list, int count)
{
    int *ptr = va_arg(list, int *);

    *ptr = count;
}

void my_printf_n(va_list list, params_t *params, int count)
{
    void (*do_n[9])(va_list, int) = {&do_nc, &do_nhh, &do_nll,
        &do_nh, &do_nl, &do_nt, &do_nc, &do_nj, &do_nz};

    params->length = (params->length == 10) ? 2 : params->length;
    params->length = (params->length == 9) ? 8 : params->length;
    do_n[params->length](list, count);
}
