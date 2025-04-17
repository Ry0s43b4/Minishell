/*
** EPITECH PROJECT, 2024
** My revstr
** File description:
** Function that will reverse a string
*/

#include "my.h"

char *my_revstr(char *str)
{
    int j = 0;
    int i = my_strlen(str) - 1;
    char *changes = my_strdup(str);

    while (str[j] != '\0') {
        str[j] = changes[i];
        j++;
        i--;
    }
    str[j] = '\0';
    return str;
}
