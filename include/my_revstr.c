/*
** EPITECH PROJECT, 2023
** day06
** File description:
** Placeholder
*/

int my_strlen2(char const *str)
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

char *my_revstr(char *str)
{
    int len;
    char c;
    int i;
    int j;

    j = 0;
    len = my_strlen2(str);
    for (i = len / 2; i > 0 ; i--) {
        c = str[j];
        str[j] = str[len - j - 1];
        str[len - j - 1] = c;
        j++;
    }
    return &str[0];
}
