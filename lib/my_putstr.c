/*
** EPITECH PROJECT, 2024
** My putstr
** File description:
** Function that will displays a string
*/

#include "my.h"

int my_putstr(char const *str)
{
    if (str == NULL)
        return ERROR;
    write(1, str, my_strlen(str));
    return SUCCESS;
}
