/*
** EPITECH PROJECT, 2023
** day06
** File description:
** Placeholder
*/

int is_ucase(char c)
{
    return (c > 64 && c < 91);
}

int is_lcase(char c)
{
    return (c > 96 && c < 123);
}

int my_str_isalpha(char const *str)
{
    int isalpha;
    int i;

    i = 0;
    isalpha = 1;
    while (str[i] != '\0') {
        if (!(is_lcase(str[i]) || is_ucase(str[i])))
            isalpha = 0;
        i++;
    }
    return isalpha;
}
