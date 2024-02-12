/*
** EPITECH PROJECT, 2023
** putnbr str float
** File description:
** placholder
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

char *my_printf_float_arr(double nb, params_t *params)
{
    to_print_t to_print2 = initialize_to_print();
    char *nb_i = my_putnbr_str_double((long int)nb, &to_print2);
    char *nb_d;
    int precision = (params->precision == 0) ? 6 : *params->precision;
    char *result;

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
    my_strcat(result, "/");
    return result;
}

static int strlen_float(char *str)
{
    int count = 0;
    int j = 0;

    for (j = 0; str[j] != '/'; j++);
    return j;
}

int identification_float(double nb)
{
    int nb_entier = (int)nb;

    if (nb > 0)
        if (nb_entier < nb)
            return 1;
        else
            return 0;
    if (nb < 0)
        if (nb_entier > nb)
            return 1;
        else
            return 0;
}

char *my_putnbr_str_float(double nb, params_t *params)
{
    char *nb_final_entier;
    char *nb_final_float;
    char *nb_final;
    int nb_entier = (int)nb;
    double multiplier = 10.000000000000000000000000000000000001;
    to_print_t *to_print;
    int precision = (params->precision == 0) ? 6 : *params->precision;

    if (identification_float(nb) == 0){
        nb_final = my_putnbr_str_double(nb, to_print);
        nb_final[len_nbr(nb) + 1] = '/';
        return nb_final;
    }
    nb_final = my_printf_float_arr(nb, params);
    return nb_final;
}

char *my_putnbr_str_float_final(double nb, params_t *params)
{
    char *strcpy = my_putnbr_str_float(nb, params);
    char *str;
    int i = 0;
    int count = 0;
    int precision = (params->precision == 0) ? 6 : *params->precision;

    str = malloc(sizeof(char) * (strlen_float(strcpy)) + precision + 1);
    str[0] = strcpy[0];
    str[1] = '.';
    for (int j = 1; j < my_strlen(strcpy); j++) {
        if (strcpy[j] == '.') {
            i++;
            str[j + 1] = strcpy[j + i];
        } else{
            str[j + 1] = strcpy[j + i];
        }
    }
    my_strcat(str, "/");
    return str;
}
