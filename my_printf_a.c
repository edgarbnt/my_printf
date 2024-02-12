/*
** EPITECH PROJECT, 2023
** printf_a
** File description:
** Placeholder
*/

#include "include/my.h"
#include <stdlib.h>

int get_exponent(union union_nb nb)
{
    nb.l = nb.l >> 52;
    nb.l = nb.l - (nb.l >> 11) * 2048;
    return nb.l - 1023;
}

void my_printf_ac2(char **ret, int exponent)
{
    my_strcat(*ret, "p\0");
    if (exponent >= 0)
        my_strcat(*ret, "+\0");
    my_strcat(*ret, my_putnbr_str(exponent));
    return;
}

char *my_printf_ac(va_list list, params_t *params, to_print_t *to_print)
{
    union union_nb nb;
    char *base = "0123456789abcdef";
    char *ret;
    int precision = (params->precision == 0) ? 13 : *params->precision;
    int exponent;

    nb.d = va_arg(list, double);
    to_print->sign = (nb.d < 0) ? '-' : 0;
    exponent = get_exponent(nb);
    nb.l = nb.l << 12;
    ret = malloc(sizeof(char) * (precision + len_nbr(exponent) + 7));
    my_strcat(ret, "0x1.\0");
    for (int i = 0; i < precision; i++) {
        ret[i + 4] = base[(nb.l >> (60 - 4 * i)) % 16];
        nb.l -= (nb.l >> (60 - 4 * i)) * my_compute_power_rec(2, 60 - 4 * i);
    }
    for (; ret[precision + 3] == '0' || ret[precision + 3] == '.'; precision--)
        ret[precision + 3] = '\0';
    my_printf_ac2(&ret, exponent);
    return ret;
}

int my_printf_a(va_list list, params_t *params)
{
    int count = 0;
    to_print_t to_print = initialize_to_print();

    to_print.arg = my_printf_ac(list, params, &to_print);
    do_flags(&to_print, *params);
    count += write_struct(to_print);
    return count;
}
