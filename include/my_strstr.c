/*
** EPITECH PROJECT, 2023
** day06
** File description:
** Placeholder
*/

#include <string.h>

int my_strncmp2(char const *s1, char const *s2, int n)
{
    int i;

    i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i != n - 1)
        i++;
    if (s1[i] == s2[i])
        return 0;
    if (s1[i] < s2[i])
        return -1;
    return 1;
}

int len_str(char const *str)
{
    int count;
    char c;

    count = 0;
    c = *str;
    while (c != '\0') {
        str++;
        c = *str;
        count ++;
    }
    return count;
}

char *my_strstr(char *str, char const *to_find)
{
    if (*to_find == '\0')
        return (char *)str;
    for (int i = 0; i < len_str(str); i++) {
        if (my_strncmp2(&str[i], to_find, len_str(to_find)) == 0)
            return &str[i];
    }
    return 0;
}
