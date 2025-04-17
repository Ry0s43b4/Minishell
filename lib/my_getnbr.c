/*
** EPITECH PROJECT, 2024
** My getnbr
** File description:
** Function that returns a number given as parameter
*/

#include <limits.h>
#include "my.h"

int my_getnbr(char const *str)
{
    int nb = 0;
    int minus = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-')
            minus *= (-1);
        if (str[i] >= '0' && str[i] <= '9')
            nb = nb * 10 + (str[i] - '0');
        if ((str[i] >= 'a' && str[i] <= 'z') ||
        (str[i] >= 'A' && str[i] <= 'Z'))
            return nb * minus;
    }
    if (nb < INT_MIN || nb > INT_MAX)
        return SUCCESS;
    else
        return nb * minus;
}
