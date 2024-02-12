/*
** EPITECH PROJECT, 2023
** day06
** File description:
** Placeholder
*/

int str_len(char const *str)
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

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    i = 0;
    while (i < str_len(src) && i < n) {
        dest[i] = src[i];
        i++;
    }
    if (n > str_len(src))
        dest[i] = '\0';
    return dest;
}
