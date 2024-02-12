/*
** EPITECH PROJECT, 2023
** my_printf_f
** File description:
** Placeholder
*/

#include "include/my.h"
#include <unistd.h>
#include <stdlib.h>

int get_double_sign(double nb, to_print_t *to_print)
{
    nb = *(unsigned long long int *)&nb >> 63;
    if (nb == 0)
        return 1;
    to_print->sign = '-';
    return -1;
}

char *my_printf_fl(va_list list, params_t *params, to_print_t *to_print)
{
    to_print_t to_print2 = initialize_to_print();
    long double nb = va_arg(list, long double);
    char *nb_i = my_putnbr_str_double((long long int)nb, &to_print2);
    char *nb_d;
    int precision = (params->precision == 0) ? 6 : *params->precision;
    char *result;

    nb *= get_double_sign(nb, to_print);
    nb = nb - (long long int)nb;
    for (int i = 0; i < precision; i++)
        nb = nb * 10;
    nb += ((long long int)nb % 10 != 0) ? 0.5 : 0;
    nb_d = my_putnbr_str_double((long long int)nb, &to_print2);
    result = malloc(sizeof(char) * (my_strlen(nb_i) + precision) + 2);
    my_strcat(result, nb_i);
    my_strcat(result, ".");
    for (int i = 0; i < (precision - my_strlen(nb_d)); i++)
        my_strcat(result, "0");
    my_strcat(result, nb_d);
    return result;
}

char *my_printf_fc(va_list list, params_t *params, to_print_t *to_print)
{
    to_print_t to_print2 = initialize_to_print();
    double nb = va_arg(list, double);
    char *nb_i = my_putnbr_str_double((long int)nb, &to_print2);
    char *nb_d;
    int precision = (params->precision == 0) ? 6 : *params->precision;
    char *result;

    nb *= get_double_sign(nb, to_print);
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

int my_printf_f(va_list list, params_t *params)
{
    int count = 0;
    to_print_t to_print = initialize_to_print();
    char *(*getarg_f[7])(va_list list, params_t *params,
        to_print_t *to_print) = {&my_printf_fc, &my_printf_fc,
        &my_printf_fc, &my_printf_fc, &my_printf_fc, &my_printf_fl};

    to_print.arg = getarg_f[params->length](list, params, &to_print);
    do_flags(&to_print, *params);
    count += write_struct(to_print);
    return count;
}
