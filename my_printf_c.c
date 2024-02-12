/*
** EPITECH PROJECT, 2023
** my_printf_c
** File description:
** Placeholder
*/

#include <stdlib.h>
#include <stdarg.h>
#include "include/my.h"
#include <unistd.h>

int write_char(unsigned char c, params_t params)
{
    int count = 0;
    int padding = params.width - 1;

    if ((params.flags & 16) == 0) {
        for (; count < padding; count += write(1, " ", 1));
        count += write(1, &c, 1);
    } else {
        count += write(1, &c, 1);
        for (; count <= padding; count += write(1, " ", 1));
    }
    return count;
}

unsigned char getargc_l(va_list list, params_t params)
{
    return 0;
}

unsigned char getargc_c(va_list list, params_t params)
{
    unsigned char c = va_arg(list, int);

    return c;
}

int my_printf_c(va_list list, params_t *params)
{
    int count = 0;
    unsigned char (*getargc[2])(va_list, params_t) = {&getargc_c, &getargc_l};

    count += write_char(getargc[params->length](list, *params), *params);
    return count;
}
