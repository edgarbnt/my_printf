/*
** EPITECH PROJECT, 2023
** my_printf_p
** File description:
** Placeholder
*/

#include <stdlib.h>
#include <stdarg.h>
#include "include/my.h"
#include <unistd.h>

int write_pointer(char *str, params_t params)
{
    int count = 0;
    int padding = params.width - my_strlen(str) - 2;

    if ((params.flags & 16) == 0) {
        for (; count < padding; count += write(1, " ", 1));
        count += write(1, "0x", 2);
        my_putstr(str);
    } else {
        count += write(1, "0x", 2);
        my_putstr(str);
        for (; count <= padding; count += write(1, " ", 1));
    }
    return count;
}

int my_printf_p(va_list list, params_t *params)
{
    unsigned long int nb = (unsigned long int)va_arg(list, void *);
    char base[16] = "0123456789abcdef";
    char *str;
    int i = 0;
    unsigned int nb2 = nb;

    for (; nb2 > 0; nb2 /= 16)
        i++;
    i += (nb == 0) ? 1 : 0;
    str = malloc(sizeof(char) * (i + 1));
    for (i = 0; nb > 0; nb /= 16) {
        str[i] = base[nb % 16];
        i++;
    }
    str[0] = (i == 0) ? '0' : str[0];
    i += (nb == 0) ? 1 : 0;
    str[i] = '\0';
    my_revstr(str);
    return write_pointer(str, *params);
}
