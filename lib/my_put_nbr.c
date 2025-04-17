/*
** EPITECH PROJECT, 2024
** My put nbr
** File description:
** Function that will write a number
*/

#include "my.h"

int my_put_nbr(int nb)
{
    char nbr[10];

    if (nb < 0) {
        my_putchar('-');
        nb *= (-1);
    }
    for (int i = 0; nb != 0; ++i) {
        nbr[i] = nb % 10 + '0';
        nb = nb / 10;
    }
    my_revstr(nbr);
    my_putstr(nbr);
    return SUCCESS;
}
