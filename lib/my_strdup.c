/*
** EPITECH PROJECT, 2024
** My str dup
** File description:
** Function that will duplicate a string into another string allocated
*/

#include "my.h"

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i = 0;

    if (dest == NULL)
        return NULL;
    for (; src[i] != '\0'; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
