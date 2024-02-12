/*
** EPITECH PROJECT, 2023
** day06
** File description:
** Placeholder
*/

#include <unistd.h>

int len_st(char const *str)
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

void write_str(char *str, int i)
{
    for (; i >= 0; i--)
        write(1, &str[i], 1);
}

int my_putnbr_base(int nbr, char const *base)
{
    int base_nb;
    char str[100];
    int i = 0;

    if (nbr == 0) {
        write(1, "0", 1);
        return 0;
    }
    if (nbr < 0) {
        write(1, "-", 1);
        nbr *= -1;
    }
    base_nb = len_st(base);
    while (nbr != 0) {
        str[i] = base[nbr % base_nb];
        nbr /= base_nb;
        i++;
    }
    write_str(str, i - 1);
    return 0;
}
