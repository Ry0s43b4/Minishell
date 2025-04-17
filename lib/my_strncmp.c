/*
** EPITECH PROJECT, 2024
** My strncmp
** File description:
** Function that will compare n characters from 2 strings given
*/

#include "my.h"

int my_strncmp(char const *str1, char const *str2, int n)
{
    int i = 0;

    if ((my_strlen(str1) < n) != (my_strlen(str2) < n))
        return ERROR;
    for (; i < n; ++i) {
        if (str1[i] != str2[i])
            return str1[i] - str2[i];
    }
    return SUCCESS;
}
