/*
** EPITECH PROJECT, 2023
** len nbr
** File description:
** len nbr
*/

#include <stdio.h>

int len_nbr(int nb)
{
    int cnt = 0;

    if (nb != 0){
        while (nb != 0){
            nb = nb / 10;
            cnt++;
        }
        return cnt;
    }else
        return 1;
}
