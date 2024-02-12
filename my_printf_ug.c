/*
** EPITECH PROJECT, 2023
** my_printf_g
** File description:
** Placeholder
*/

#include "include/my.h"
#include <stdlib.h>
#include <unistd.h>

int get_ug_sign(double nb, to_print_t *to_print)
{
    nb = *(unsigned long long int *)&nb >> 63;
    if (nb == 0)
        return 1;
    to_print->sign = '-';
    return -1;
}

char *my_printf_ug_f(double nb, params_t *params, to_print_t *to_print)
{
    to_print_t to_print2 = initialize_to_print();
    char *nb_i = my_putnbr_str_double((long int)nb, &to_print2);
    char *nb_d;
    int precision = (params->precision == 0) ? 6 : *params->precision;
    char *result;

    nb *= get_ug_sign(nb, to_print);
    nb = nb - (long int)nb;
    for (int i = 0; i < precision; i++)
        nb = nb * 10;
    nb += ((long int)nb % 10 != 0) ? 0.5 : 0;
    nb_d = my_putnbr_str_double((long int)nb, &to_print2);
    result = malloc(sizeof(char) * (my_strlen(nb_i) + precision) + 2);
    my_strcat(result, nb_i);
    my_strcat(result, ".");
    for (int i = 0; i < (precision - my_strlen(nb_d)); i++)
        my_strcat(result, "0");
    my_strcat(result, nb_d);
    return result;
}

char *my_printf_ug_e(va_list list, params_t *params, to_print_t *to_print)
{
    int neg_e = 0;
    int i = 0;
    int b = (params->precision == 0) ? 1 : 0;
    double nb = va_arg(list, double);
    char *str_exponent;
    double nb2 = nb;

    params->precision = (b) ? malloc(sizeof(int)) : params->precision;
    *params->precision = (b) ? 5 : *params->precision - 1;
    if (nb < 0)
        to_print->sign = '-';
    nb *= (nb < 0) ? -1 : 1;
    for (; (long int)nb2 % 10 == 0; nb2 *= 10)
        neg_e++;
    str_exponent = my_printf_ue_precision(nb2, params, neg_e);
    for (; str_exponent[i + 1] != '\0'; i++);
    if ((str_exponent[i] > '4' && nb > 0 && nb < 1) ||
        str_exponent[i] >= (char)(*params->precision + 48))
        return str_exponent;
    return my_printf_ug_f(nb, params, to_print);
}

int my_printf_ug(va_list list, params_t *params)
{
    int i;
    int count = 0;
    to_print_t to_print = initialize_to_print();

    to_print.arg = my_printf_ug_e(list, params, &to_print);
    for (i = my_strlen(to_print.arg) - 1;
        to_print.arg[i] == '0'; i--);
    to_print.arg[i + 1] = '\0';
    do_flags(&to_print, *params);
    count += write_struct(to_print);
    return count;
}
