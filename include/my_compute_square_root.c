/*
** EPITECH PROJECT, 2023
** Day05
** File description:
** Placeholder
*/

int my_compute_square_root(int nb)
{
    int i;

    if (nb > 2147483647)
        return 0;
    for (i = nb; i >= 0; i--) {
        if (i * i == nb)
            return i;
    }
    return 0;
}
