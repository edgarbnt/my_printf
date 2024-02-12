/*
** EPITECH PROJECT, 2023
** get_flags
** File description:
** Placeholder
*/

#include <stdio.h>
#include "include/my.h"

int is_flag(char c)
{
    return (c == ' ' || c == '#' || c == '0' || c == '-' || c == '+');
}

static int contains_hashtag(const char *restrict str)
{
    for (int i = 0; is_flag(str[i]); i++) {
        if (str[i] == '#')
            return 1;
    }
    return 0;
}

static int contains_space(const char *restrict str)
{
    for (int i = 0; is_flag(str[i]); i++) {
        if (str[i] == ' ')
            return 1;
    }
    return 0;
}

static int contains_plus(const char *restrict str)
{
    for (int i = 0; is_flag(str[i]); i++) {
        if (str[i] == '+')
            return 1;
    }
    return 0;
}

static int contains_minus(const char *restrict str)
{
    for (int i = 0; is_flag(str[i]); i++) {
        if (str[i] == '-')
            return 1;
    }
    return 0;
}

static int contains_zero(const char *restrict str)
{
    for (int i = 0; is_flag(str[i]); i++) {
        if (str[i] == '0')
            return 1;
    }
    return 0;
}

int get_flags(const char *restrict str)
{
    int ret = 0;
    int (*contains_char[5])(const char *restrict) = {&contains_minus,
        &contains_zero,
        &contains_hashtag, &contains_space, &contains_plus};

    for (int i = 0; i < 5; i++) {
        ret = ret << 1;
        ret += contains_char[i](str);
    }
    return ret;
}
