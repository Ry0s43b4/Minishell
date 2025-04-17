/*
** EPITECH PROJECT, 2024
** My str cat
** File description:
** Function that will concatenate 2 strings into 1
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int len = my_strlen(dest) + my_strlen(src);
    char *res = NULL;
    int j = 0;

    res = malloc(sizeof(char) * len + 1);
    if (res == NULL)
        return NULL;
    for (int i = 0; dest[i] != '\0'; ++i) {
        res[j] = dest[i];
        ++j;
    }
    for (int i = 0; src[i] != '\0'; ++i) {
        res[j] = src[i];
        ++j;
    }
    res[len] = '\0';
    return res;
}
