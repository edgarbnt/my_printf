/*
** EPITECH PROJECT, 2023
** Day05
** File description:
** Placeholder
*/

int my_is_prime(int nb)
{
    int i;
    int result;

    result = 1;
    if (nb <= 1 || nb > 2147483648)
        result = 0;
    for (i = 2; i < nb; i++) {
        if (nb % i == 0) {
            result = 0;
        }
    }
    if (nb > 2147483648)
        return 0;
    return result;
}
