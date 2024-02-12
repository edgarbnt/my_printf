/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** Placeholder
*/

#include <unistd.h>
#include <stdio.h>

long is_negative(long nb)
{
    if (nb < 0) {
        write(1, "-", 1);
        nb = nb * -1;
    }
    return nb;
}

long reverse_nb(long nb)
{
    long nb_rev;

    nb_rev = 0;
    while (nb > 9) {
        nb_rev += nb % 10;
        nb /= 10;
        nb_rev *= 10;
    }
    nb_rev += nb;
    return nb_rev;
}

int my_putnbr(int nb)
{
    int c = 0;
    int neg = 0;

    if (nb < 0){
        write(1, "-", 1);
        my_putnbr(-nb);
        neg++;
    }
    if (nb > 10){
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    }
    if (nb < 10 && nb >= 0){
        c = nb + 48;
        write(1, &c, 1);
    }
    return neg;
}
