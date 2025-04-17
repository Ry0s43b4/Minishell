/*
** EPITECH PROJECT, 2024
** My strcmp
** File description:
** Function that will compare 2 strings given
*/

#include "my.h"

int my_strcmp(char const *str1, char const *str2)
{
    size_t i = 0;

    if (my_strlen(str1) != my_strlen(str2))
        return ERROR;
    for (; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] != str2[i])
            return str1[i] - str2[i];
    }
    return SUCCESS;
}
