/*
** EPITECH PROJECT, 2023
** percent
** File description:
** Placeholder
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "include/my.h"

int my_printf_percent(va_list list, params_t *params)
{
    write(1, "%", 1);
    return 2;
}
