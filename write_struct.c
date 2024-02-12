/*
** EPITECH PROJECT, 2023
** write_struct
** File description:
** Placeholder
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "include/my.h"

int write_struct(to_print_t to_print)
{
    int count = 0;

    if (to_print.space == ' ')
        count += write(1, " ", 1);
    if (to_print.left_pad != 0 && to_print.left_pad[0] == ' ')
        count += write(1, to_print.left_pad, my_strlen(to_print.left_pad));
    if (to_print.sign == '+')
        count += write(1, "+", 1);
    if (to_print.sign == '-')
        count += write(1, "-", 1);
    if (to_print.alt_form != 0)
        count += write(1, to_print.alt_form, my_strlen(to_print.alt_form));
    if (to_print.left_pad != 0 && to_print.left_pad[0] == '0')
        count += write(1, to_print.left_pad, my_strlen(to_print.left_pad));
    count += write(1, to_print.arg, my_strlen(to_print.arg));
    if (to_print.right_pad != 0)
        count += write(1, to_print.right_pad, my_strlen(to_print.right_pad));
    return count;
}
