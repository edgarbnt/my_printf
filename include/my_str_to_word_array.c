/*
** EPITECH PROJECT, 2023
** day08
** File description:
** Placeholder
*/

#include "my.h"
#include <stdlib.h>

int is_anum(char c)
{
    return (is_lcase(c) || is_ucase(c) || is_num(c));
}

int count_words(char const *str)
{
    int count = 0;
    int i = 0;

    if (is_anum(str[i]))
        count++;
    while (str[i + 1] != '\0' && str[i] != '\0') {
        while (!(is_anum(str[i + 1])) && str[i + 1] != '\0')
            i++;
        if (!(is_anum(str[i])) && str[i + 1] != '\0')
            count++;
        i++;
    }
    return count;
}

void modify_str(char const *str, char **str2)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;
    int j = 0;
    int found_letter = 0;

    my_strcpy(new_str, str);
    for (; i < my_strlen(str); i++)
        new_str[i] -= new_str[i] * !(is_anum(str[i]));
    i = 0;
    while (str[i] != '\0') {
        if (new_str[i] != '\0' && found_letter == 0) {
            str2[j] = malloc(sizeof(char) * my_strlen(&new_str[i]));
            my_strcpy(str2[j], &new_str[i]);
            j++;
            found_letter = 1;
        }
        if (new_str[i] == '\0')
            found_letter = 0;
        i++;
    }
}

char **my_str_to_word_array(char const *str)
{
    char **str2 = malloc(sizeof(char *) * (count_words(str) + 1));
    int j = 0;
    int count;

    modify_str(str, str2);
    str2[count_words(str)] = 0;
    return str2;
}
