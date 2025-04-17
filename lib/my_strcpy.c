/*
** EPITECH PROJECT, 2024
** My strcpy
** File description:
** Function that will copy a string into another
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = src[i];
    return dest;
}
