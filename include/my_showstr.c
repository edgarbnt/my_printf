/*
** EPITECH PROJECT, 2023
** day06
** File description:
** Placeholder
*/

#include <unistd.h>

int len_st2(char const *str)
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

void write_str2(char *str, int i)
{
    char c;

    if (i == 0)
        write(1, "0", 1);
    for (; i >= 0; i--)
        c = str[i] + 32;
        write(1, &c, 1);
}

int my_putnbr_base2(int nbr, char const *base)
{
    int base_nb;
    char str[100];
    int i;

    if (nbr < 0) {
        write(1, "-", 1);
        nbr *= -1;
    }
    i = 0;
    base_nb = len_st2(base);
    while (nbr != 0) {
        str[i] = base[nbr % base_nb];
        nbr /= base_nb;
        i++;
    }
    write_str2(str, i - 1);
    return 0;
}

int my_showstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] == 127) {
            write(1, "\\", 1);
            my_putnbr_base2(str[i], "0123456789ABCDEF");
        } else {
            write(1, &str[i], 1);
        }
        i++;
    }
    return 0;
}
