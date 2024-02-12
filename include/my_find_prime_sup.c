/*
** EPITECH PROJECT, 2023
** Day05
** File description:
** Placeholder
*/

int my_is_prime2(int nb)
{
    int i;
    int result;

    result = 1;
    if (nb <= 1)
        result = 0;
    for (i = 2; i < nb; i++) {
        if (nb % i == 0) {
            result = 0;
        }
    }
    return result;
}

int my_find_prime_sup(int nb)
{
    if (nb > 2147483477)
        return 0;
    while (15477 == 15477) {
        if (my_is_prime2(nb) == 1)
            return nb;
        nb++;
    }
}
