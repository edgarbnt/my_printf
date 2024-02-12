/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Placeholder
*/

#include <inttypes.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "include/my.h"

int is_good_char(char c)
{
    return (c == 'd' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'x' || c == 'X' || c == 'e' || c == 'E' ||
        c == 'g' || c == 'G' || c == 'f' || c == 'F' ||
        c == 'g' || c == 'G' || c == 'a' || c == 'A' ||
        c == 'c' || c == 's' || c == 'p' || c == 'n' ||
        c == '%' || c == 'b' || c == 'B' || c == '-' ||
        c == ' ' || c == '#' || c == '+' || c == '0' ||
        (c >= 48 && c <= 57) || c == 'h' || c == 'l' ||
        c == 'z' || c == '.' || c == 't' || c == 'Z' ||
        c == 'j' || c == 'q' || c == 'L');
}

int is_specifier(char c)
{
    return (c == 'd' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'x' || c == 'X' || c == 'e' || c == 'E' ||
        c == 'g' || c == 'G' || c == 'f' || c == 'F' ||
        c == 'g' || c == 'G' || c == 'a' || c == 'A' ||
        c == 'c' || c == 's' || c == 'p' || c == 'n' ||
        c == '%' || c == 'b' || c == 'B');
}

int go_to_specifier(const char *restrict format)
{
    int count = 0;

    for (int i = 0; format[i] != '\0' && count == 0; i++)
        count = (is_specifier(format[i])) ? i + 1 : 0;
    return count;
}

int found_percent(va_list list, const char *restrict format, int total)
{
    int count = 0;
    params_t *params = malloc(sizeof(params_t));
    int (*my_printf_specifier[20])(va_list, params_t *) = {&my_printf_o,
        &my_printf_u, &my_printf_percent, &my_printf_x, &my_printf_ux,
        &my_printf_d, &my_printf_i, &my_printf_s, &my_printf_c,
        &my_printf_p, &my_printf_b, &my_printf_b, &my_printf_f,
        &my_printf_f, &my_printf_a, &my_printf_ua, &my_printf_ee,
        &my_printf_uee, &my_printf_g, &my_printf_ug};

    get_params(params, format);
    if (params->specifier != 20)
        count += my_printf_specifier[params->specifier](list, params);
    if (params->specifier == 20)
        my_printf_n(list, params, total);
    free(params);
    return count;
}

static int is_good_syntax(const char *str)
{
    for (int i = 1; !is_specifier(str[i]); i++) {
        if (!is_good_char(str[i]))
            return 0;
    }
    return 1;
}

int my_printf(const char *restrict format, ...)
{
    int count = 0;
    va_list list;

    va_start(list, format);
    for (int i = 0; i < my_strlen(format); i++) {
        if (format[i] != '%')
            count += write(1, &format[i], 1);
        if (format[i] == '%' && format[i + 1] != '\0' &&
            is_good_syntax(&format[i])) {
            count += found_percent(list, format + i + 1, count);
            i += go_to_specifier(format + i + 1);
        }
        if (format[i] == '%' && format[i + 1] != '\0' &&
            !is_good_syntax(&format[i]))
            count += write(1, &format[i], 1);
    }
    va_end(list);
    return count;
}
