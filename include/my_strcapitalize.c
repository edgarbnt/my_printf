/*
** EPITECH PROJECT, 2023
** day06
** File description:
** Placeholder
*/

#include <stdio.h>

int is_number(char c)
{
    return (c > 47 && c < 58);
}

int is_upper_case(char c)
{
    return (c > 64 && c < 91);
}

int is_lower_case(char c)
{
    return (c > 96 && c < 123);
}

int is_letter_number(char c)
{
    return (is_number(c) || is_lower_case(c) || is_upper_case(c));
}

char *my_strcapitalize(char *str)
{
    if (str[0] > 96 && str[0] < 123)
        str[0] -= 32;
    for (int i = 1; str[i] != '\0'; i++) {
        if (!(is_letter_number(str[i - 1])) && is_lower_case(str[i])) {
            str[i] -= 32;
        }
        if (is_letter_number(str[i - 1]) && is_upper_case(str[i])) {
            str[i] += 32;
        }
    }
    return str;
}
