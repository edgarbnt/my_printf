/*
** EPITECH PROJECT, 2023
** do_flags
** File description:
** Placeholder
*/

#include <stdlib.h>
#include <stdarg.h>
#include "include/my.h"

static void do_hashtag2(to_print_t *to_print, params_t params)
{
    if (params.specifier == 10) {
        to_print->alt_form = malloc(sizeof(char) * 3);
        my_strcpy(to_print->alt_form, "0b");
    }
    if (params.specifier == 11) {
        to_print->alt_form = malloc(sizeof(char) * 3);
        my_strcpy(to_print->alt_form, "0B");
    }
    return;
}

void do_hashtag(to_print_t *to_print, params_t params)
{
    if (params.specifier == 0 && to_print->arg[0] != '0') {
        to_print->alt_form = malloc(sizeof(char) * 2);
        my_strcpy(to_print->alt_form, "0");
    }
    if (params.specifier == 3) {
        to_print->alt_form = malloc(sizeof(char) * 3);
        my_strcpy(to_print->alt_form, "0x");
    }
    if (params.specifier == 4) {
        to_print->alt_form = malloc(sizeof(char) * 3);
        my_strcpy(to_print->alt_form, "0X");
    }
    do_hashtag2(to_print, params);
}

void do_space(to_print_t *to_print, params_t params)
{
    if (to_print->sign != '-' && params.specifier != 0
        && params.specifier != 1 && params.specifier != 3
        && params.specifier != 4)
        to_print->space = ' ';
}

void do_plus(to_print_t *to_print, params_t params)
{
    if (to_print->sign != '-' && params.specifier != 0
        && params.specifier != 1 && params.specifier != 3
        && params.specifier != 4)
        to_print->sign = '+';
}

int get_padding(to_print_t *to_print, params_t params)
{
    int padding = params.width;

    padding -= (to_print->space == ' ') ? 1 : 0;
    padding -= (to_print->sign == '+' || to_print->sign == '-') ? 1 : 0;
    if (to_print->alt_form != 0)
        padding -= my_strlen(to_print->alt_form);
    if (to_print->arg != 0)
        padding -= my_strlen(to_print->arg);
    return padding;
}

static void do_zero(to_print_t *to_print, params_t params)
{
    int padding = get_padding(to_print, params);
    int i = 0;

    if (padding < 0) {
        to_print->left_pad = 0;
        return;
    }
    to_print->left_pad = malloc(sizeof(char) * (padding + 1));
    for (; i < padding; i++)
        to_print->left_pad[i] = '0';
    to_print->left_pad[i + 1] = '\0';
}

static void do_padding(to_print_t *to_print, params_t params)
{
    int padding = get_padding(to_print, params);
    int i = 0;

    if (padding < 0) {
        to_print->left_pad = 0;
        return;
    }
    to_print->left_pad = malloc(sizeof(char) * (padding + 1));
    for (; i < padding; i++)
        to_print->left_pad[i] = ' ';
    to_print->left_pad[i + 1] = '\0';
}

static void do_inverse_padding(to_print_t *to_print, params_t params)
{
    int padding = get_padding(to_print, params);
    int i = 0;

    if (padding < 0) {
        to_print->left_pad = 0;
        return;
    }
    to_print->right_pad = malloc(sizeof(char) * (padding + 1));
    for (; i < padding; i++)
        to_print->right_pad[i] = ' ';
    to_print->right_pad[i + 1] = '\0';
}

void do_flags(to_print_t *to_print, params_t params)
{
    int i = 0;

    if ((params.flags & 2) != 0 && (params.flags & 1) == 0)
        do_space(to_print, params);
    if ((params.flags & 1) != 0)
        do_plus(to_print, params);
    if ((params.flags & 4) != 0)
        do_hashtag(to_print, params);
    if ((params.flags & 8) != 0 && (params.flags & 16) == 0 &&
            params.precision == 0) {
        do_zero(to_print, params);
        i++;
    }
    if ((params.flags & 16) != 0)
        do_inverse_padding(to_print, params);
    if ((params.flags & 16) == 0 && i == 0)
        do_padding(to_print, params);
    return;
}
