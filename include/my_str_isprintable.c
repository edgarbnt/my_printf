/*
** EPITECH PROJECT, 2023
** day06
** File description:
** Placeholder
*/

int my_str_isprintable(char const *str)
{
    int isprintable;
    int i;

    i = 0;
    isprintable = 1;
    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] == 127)
            isprintable = 0;
        i++;
    }
    return isprintable;
}
