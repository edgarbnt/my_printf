/*
** EPITECH PROJECT, 2023
** printf e
** File description:
** printf e
*/

#include <stdio.h>
#include "include/my.h"
#include <stdlib.h>
#include <unistd.h>

char *my_printf_e_exponent(double nb, int count, char *str, int neg_e)
{
    int nb_after_pt = len_nbr(nb) - 1;
    int i = 0;

    my_strcat(str, "/");
    if (neg_e == 0){
        for (; str[i] != '/'; i++);
        str[i] = 'e';
        str[i + 1] = '+';
    }
    if (neg_e != 0){
        for (; str[i] != '/'; i++);
        str[i] = 'e';
        str[i + 1] = '-';
    }
    if (nb_after_pt < 10){
        str[i + 2] = '0';
        str[i + 3] = nb_after_pt + count + 48 + neg_e;
        str[i + 4] = '\0';
    }
    return str;
}

static char *my_printf_e_0(double nb, params_t *params)
{
    char *str = my_printf_e_str(nb, params);
    int count = 0;

    if (str[2] >= '5'){
        str[0] += 1;
        str[1] = '/';
    }
    if (str[2] < '5')
        str[1] = '/';
    if (str[0] == ':'){
        str[0] = '1';
        str[1] = '/';
        count++;
    }
    return str;
}

static char *my_printf_e_arrondi(double nb, params_t *params)
{
    char *str = my_printf_e_str(nb, params);
    int count = 0;
    int index = 0;
    int precision = (params->precision == 0) ? 6 : *params->precision;

    if (str[precision + 2] >= '5' && str[precision + 1] != '9'){
        str[precision + 1] += 1;
    }
    for (int i = 2; i < precision + 2; i++){
        if (str[i + 1] == '9' && str[i] == '9' && str[2] == '9'){
            index++;
        }
    }
    if (index >= precision - 1 && index != 0){
        for (int j = 0; j < precision; j++)
            str[2 + j] = '0';
        str[0] += 1;
    }
    str[precision + 2] = '/';
    return str;
}

char *my_printf_e_precision(double nb, params_t *params, int neg_e)
{
    char *str = my_printf_e_str(nb, params);
    int precision = (params->precision == 0) ? 6 : *params->precision;
    int count = 0;
    int j = 0;

    for (j = 0; str[j] != '\0'; j++);
    if (precision > j - 2){
        for (int i = 0; i < precision - (j - 2); i++){
            str[(j - 2) + i + 2] = '0';
        }
    }
    if (precision <= (j - 2) && precision != 0)
        str = my_printf_e_arrondi(nb, params);
    if (precision == 0)
        str = my_printf_e_0(nb, params);
    str = my_printf_e_exponent(nb, count, str, neg_e);
    return str;
}

char *my_printf_e_str(double nb, params_t *params)
{
    to_print_t to_print = initialize_to_print();
    char *strcpy = my_putnbr_str_float(nb, params);
    char *str;
    int precision = (params->precision == 0) ? 6 : *params->precision;
    int i = 0;
    int k = 0;

    for (k = 0; strcpy[k] != '/'; k++);
    str = malloc(sizeof(char) * (k + precision + 4));
    for (int j = 0; strcpy[j] != '/'; j++){
        if (strcpy[j] == '.')
            return my_putnbr_str_float_final(nb, params);
    }
    str[0] = strcpy[0];
    str[1] = '.';
    for (i = 2; i < len_nbr(nb) + 1; i++)
        str[i] = strcpy[i - 1];
    str[i + 1] = '\0';
    return str;
}

to_print_t my_printf_e(double nb, params_t *params)
{
    to_print_t to_print = initialize_to_print();
    int count = 0;
    int neg_e = 0;

    if (nb < 0){
        nb *= -1;
        to_print.sign = '-';
    }
    for (; (long int)nb % 10 == 0; nb *= 10)
        neg_e++;
    to_print.arg = my_printf_e_precision(nb, params, neg_e);
    return to_print;
}

int my_printf_ee(va_list list, params_t *params)
{
    double nb = va_arg(list, double);
    to_print_t to_print = my_printf_e(nb, params);
    int count = 0;

    do_flags(&to_print, *params);
    count += write_struct(to_print);
    return count;
}
