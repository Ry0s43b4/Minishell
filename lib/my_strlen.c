/*
** EPITECH PROJECT, 2024
** My strlen
** File description:
** Function that will counts and returns the number of characters in a string
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    for (; str[i] != '\0'; ++i);
    return i;
}
